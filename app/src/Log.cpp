#include "Log.hpp"

/*************************************************************************************************************************************************************************************************************/
void initLog(const std::string_view filename) {

  boost::log::add_common_attributes();

  boost::log::core::get()->add_global_attribute(
      "Scope", boost::log::attributes::named_scope());

  auto fmtTimeStamp{
      boost::log::expressions::format_date_time<boost::posix_time::ptime>(
          "TimeStamp", "%Y-%m-%d %H:%M:%S.%f")};
  auto fmtThreadId{boost::log::expressions::attr<
      boost::log::attributes::current_thread_id::value_type>("ThreadID")};
  auto fmtSeverity{
      boost::log::expressions::attr<boost::log::trivial::severity_level>(
          "Severity")};
  auto fmtScope{boost::log::expressions::format_named_scope(
      "Scope", boost::log::keywords::format = "%n(%f:%l)",
      boost::log::keywords::iteration = boost::log::expressions::reverse,
      boost::log::keywords::depth = 2)};

  boost::log::formatter logFmt{
      boost::log::expressions::format("[%1%]<%2%>[%3%](%4%):  %5%") %
      fmtTimeStamp % fmtThreadId % fmtSeverity % fmtScope %
      boost::log::expressions::smessage};

  auto consoleSink{boost::log::add_console_log(std::clog)};
  consoleSink->set_formatter(logFmt);

  auto fsSink{boost::log::add_file_log(
      boost::log::keywords::file_name = filename.data(),
      boost::log::keywords::rotation_size = 10 * 1024 * 1024,
      boost::log::keywords::min_free_space = 30 * 1024 * 1024,
      boost::log::keywords::open_mode = std::ios_base::app)};

  fsSink->set_formatter(logFmt);
  fsSink->locked_backend()->auto_flush(true);

#ifdef NDEBUG
  boost::log::core::get()->set_filter(boost::log::trivial::severity >=
                                      boost::log::trivial::info);
#endif
}



#if 0
static void init_log() {

  static const std::string COMMON_FMT("[%TimeStamp%][%Severity%]:  %Message%");

  boost::log::register_simple_formatter_factory<
      boost::log::trivial::severity_level, char>("Severity");

  // Output message to console
  boost::log::add_console_log(std::cout,
                              boost::log::keywords::format = COMMON_FMT,
                              boost::log::keywords::auto_flush = true);

  // Output message to file, rotates when file reached 1mb or at midnight every
  // day. Each log file is capped at 1mb and total is 20mb
  boost::log::add_file_log(
      // boost::log::keywords::file_name = "./sample_%3N.log",
      boost::log::keywords::target = "./logs",
      boost::log::keywords::file_name = "%Y-%m-%d_%H:%M:%S-%3N.log",
      boost::log::keywords::rotation_size = 1 * 1024 * 1024,
      boost::log::keywords::max_size = 20 * 1024 * 1024,
      boost::log::keywords::time_based_rotation =
          boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
      //boost::log::keywords::format = COMMON_FMT,
			// boost::log::keywords::format =
      //   (
      //       expr::stream
      //           << expr::attr< unsigned int >("LineID")
      //           //<< ": <" << logging::trivial::severity
      //           << "> " << expr::smessage
      //   ),
				 boost::log::keywords::format =
        (
            expr::stream
                << expr::format_date_time< boost::posix_time::ptime >("TimeStamp", "%Y-%m-%d %H:%M:%S")
                << ": <" << logging::trivial::severity
								<< " line: " << expr::attr< unsigned int >("LineID")
                << "> " << expr::smessage
        ),
      boost::log::keywords::auto_flush = true
			);

  boost::log::add_common_attributes();

  // Only output message with INFO or higher severity in Release
#ifndef _DEBUG
  boost::log::core::get()->set_filter(boost::log::trivial::severity >=
                                      boost::log::trivial::info);
#endif
}
#endif


#if 0

//https://stackoverflow.com/questions/31154429/boost-log-support-file-name-and-line-number/31160870#31160870
void my_formatter(logging::record_view const &rec,
                  logging::formatting_ostream &strm) {
  // Get the LineID attribute value and put it into the stream
  strm << logging::extract<unsigned int>("LineID", rec) << ": ";
  strm << logging::extract<int>("Line", rec) << ": ";
  logging::value_ref<std::string> fullpath =
      logging::extract<std::string>("File", rec);
  strm << boost::filesystem::path(fullpath.get()).filename().string() << ": ";

  // The same for the severity level.
  // The simplified syntax is possible if attribute keywords are used.
  strm << "<" << rec[logging::trivial::severity] << "> ";

  // Finally, put the record message to the stream
  strm << rec[expr::smessage];
}

void init() {
  typedef sinks::synchronous_sink<sinks::text_ostream_backend> text_sink;
  boost::shared_ptr<text_sink> sink = boost::make_shared<text_sink>();

  sink->locked_backend()->add_stream(
      boost::make_shared<std::ofstream>("sample.log"));

  sink->set_formatter(&my_formatter);

  logging::core::get()->add_sink(sink);

  // Output message to console
  // boost::log::add_console_log(std::cout,
  //                             boost::log::keywords::format = &my_formatter,
  //                             boost::log::keywords::auto_flush = true);
}

#define MY_GLOBAL_LOGGER(log_, sv)                                             \
  BOOST_LOG_SEV(log_, sv) << boost::log::add_value("Line", __LINE__)           \
                          << boost::log::add_value("File", __FILE__)           \
                          << boost::log::add_value("Function",                 \
                                                   BOOST_CURRENT_FUNCTION)
int xmain(int, char *[]) {
  init();
  logging::add_common_attributes();

	//boost::shared_ptr< logging::core > core = logging::core::get();
  //core->add_global_attribute("LineID", attrs::counter< unsigned int >(1));

  using namespace logging::trivial;
  src::severity_logger<severity_level> lg;

  MY_GLOBAL_LOGGER(lg, debug) << "Keep";
  MY_GLOBAL_LOGGER(lg, info) << "It";
  MY_GLOBAL_LOGGER(lg, warning) << "Simple";
  MY_GLOBAL_LOGGER(lg, error) << "Stupid";

  return 0;
}

#endif


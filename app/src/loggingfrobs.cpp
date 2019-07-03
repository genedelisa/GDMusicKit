
#include "boost/log/trivial.hpp"
#include "boost/log/utility/setup.hpp"
#include <iostream>

#include <boost/filesystem.hpp>
#include <boost/log/core.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <fstream>
#include <ostream>
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace expr = boost::log::expressions;
namespace sinks = boost::log::sinks;

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
  boost::log::add_console_log(std::cout,
                              boost::log::keywords::format = &my_formatter,
                              boost::log::keywords::auto_flush = true);
}

#define MY_GLOBAL_LOGGER(log_, sv)                                             \
  BOOST_LOG_SEV(log_, sv) << boost::log::add_value("Line", __LINE__)           \
                          << boost::log::add_value("File", __FILE__)           \
                          << boost::log::add_value("Function",                 \
                                                   BOOST_CURRENT_FUNCTION)
int main(int, char *[]) {
  init();
  logging::add_common_attributes();

  using namespace logging::trivial;
  src::severity_logger<severity_level> lg;

  MY_GLOBAL_LOGGER(lg, debug) << "Keep";
  MY_GLOBAL_LOGGER(lg, info) << "It";
  MY_GLOBAL_LOGGER(lg, warning) << "Simple";
  MY_GLOBAL_LOGGER(lg, error) << "Stupid";

  return 0;
}

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
      boost::log::keywords::format = COMMON_FMT,
      boost::log::keywords::auto_flush = true);

  boost::log::add_common_attributes();

  // Only output message with INFO or higher severity in Release
#ifndef _DEBUG
  boost::log::core::get()->set_filter(boost::log::trivial::severity >=
                                      boost::log::trivial::info);
#endif
}

int oldmain(int, char **) {
  init_log();

  // Output some simple log message
  BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
  BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
  BOOST_LOG_TRIVIAL(info) << "An informational severity message";
  BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
  BOOST_LOG_TRIVIAL(error) << "An error severity message";
  BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

  return EXIT_SUCCESS;
}

#if 0

void initLogging()
{
    boost::log::add_common_attributes();
    auto core = boost::log::core::get();

    core->add_global_attribute("UTCTimeStamp",boost::log::attributes::utc_clock());

    auto x = boost::log::add_file_log(
            boost::log::keywords::file_name             = "Log_%3N.log",
            boost::log::keywords::rotation_size         = 1 * 1024, // 1k
            boost::log::keywords::target                = "Logs",
            boost::log::keywords::min_free_space        = 30 * 1024 * 1024,
            boost::log::keywords::max_size              = 20 * 1024,
            boost::log::keywords::time_based_rotation   = boost::log::sinks::file::rotation_at_time_point(boost::gregorian::greg_day(31)),
            boost::log::keywords::scan_method           = boost::log::sinks::file::scan_matching,
            boost::log::keywords::format                = "%UTCTimeStamp% (%TimeStamp%) [%ThreadID%]: %Message%",
            boost::log::keywords::auto_flush            = true
        );

    //auto d = x->locked_backend()->scan_for_files();
}

#include <boost/bind.hpp>
#include <boost/filesystem.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/move/utility.hpp>
#include <boost/thread.hpp>
//#include <boost\log\expressions.hpp>
//#include <boost\log\keywords\filter.hpp>
#include <fstream>
#include <iostream>
#include <signal.h>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger, src::logger_mt)

int main() {
  src::logger_mt &lg = my_logger::get();

  logging::add_file_log(
      keywords::file_name = "SYSLOG_%N.log",
      keywords::rotation_size = 10 * 1024 * 1024,
      keywords::time_based_rotation =
          boost::log::sinks::file::rotation_at_time_point(0, 0, 0),
      keywords::format = "[%TimeStamp%]:[%ThreadID%]:%Message%",
      keywords::auto_flush = true);
  lg.add_attribute("ThreadID", boost::log::attributes::current_thread_id());
  // lg.add_attribute("Class",
  // boost::log::attributes::constant<std::string>(__FUNCTION__));

  logging::add_common_attributes();
  logging::record rec = lg.open_record();

  BOOST_LOG(lg) << "INFO "
                << "Frobs: "
                << "Application started: " << boost::this_thread::get_id();

  return EXIT_SUCCESS;
}
#endif

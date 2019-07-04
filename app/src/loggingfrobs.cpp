
//#include "Log.hpp"
#include "Logging.hpp"

int main(int, char **) {
  // init_log();
  // initLog("flobble_%3N.log");

  // Output some simple log message
  BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
  BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
  BOOST_LOG_TRIVIAL(info) << "An informational severity message";
  BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
  BOOST_LOG_TRIVIAL(error) << "An error severity message";
  BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";

  // boost::log::sources::severity_logger_mt<severity_level> lg = logger::get();
  // LOG(lg, trace) << "A trace severity message";
  // LOG(lg, debug) << "A debug severity message";
  // LOG(lg, info) << "An informational severity message";
  // LOG(lg, warning) << "A warning severity message";
  // LOG(lg, error) << "An error severity message";
  // LOG(lg, fatal) << "A fatal severity message";

  TRACE << "trace";
  DEBUG << "debug";
  WARNING << "warning";
  ERROR << "error";
  FATAL << "fatal";

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

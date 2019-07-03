
#include <iostream>
#include "boost/log/trivial.hpp"
#include "boost/log/utility/setup.hpp"

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
      boost::log::keywords::file_name = "sample_%3N.log",
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

int main(int, char **) {
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

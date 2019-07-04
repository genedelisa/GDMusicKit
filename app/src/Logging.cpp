#include "Logging.hpp"

namespace attrs = boost::log::attributes;
namespace expr = boost::log::expressions;
namespace logging = boost::log;

// Defines a global logger initialization routine
BOOST_LOG_GLOBAL_LOGGER_INIT(my_logger, logger_t) {
  logger_t lg;

  logging::add_common_attributes();

  auto fsSink{logging::add_file_log(
      boost::log::keywords::file_name = SYS_LOGFILE,
      boost::log::keywords::rotation_size = 10 * 1024 * 1024,
      boost::log::keywords::min_free_space = 30 * 1024 * 1024,
      boost::log::keywords::open_mode = std::ios_base::app,
      boost::log::keywords::format =
          (expr::stream << expr::format_date_time<boost::posix_time::ptime>(
                               "TimeStamp", "%Y-%m-%d %H:%M:%S")
                        << " ["
                        << expr::attr<boost::log::trivial::severity_level>(
                               "Severity")
                        << "]: " << expr::smessage))};

  //    fsSink->set_formatter(logFmt);
  fsSink->locked_backend()->auto_flush(true);

  auto consoleSink{logging::add_console_log(
      std::cout,
      boost::log::keywords::format =
          (expr::stream << expr::format_date_time<boost::posix_time::ptime>(
                               "TimeStamp", "%Y-%m-%d %H:%M:%S")
                        << " ["
                        << expr::attr<boost::log::trivial::severity_level>(
                               "Severity")
                        << "]: " << expr::smessage))};

// consoleSink->set_formatter(&my_formatter);

#ifdef NDEBUG
  logging::core::get()->set_filter(logging::trivial::severity >=
                                   logging::trivial::info);
#endif

  return lg;
}

// AM_LDFLAGS += -lboost_system -lboost_thread -lpthread
// AM_LDFLAGS += -DBOOST_LOG_DYN_LINK -lboost_log_setup -lboost_log
// AM_CXXFLAGS += -std=c++11 -DBOOST_LOG_DYN_LINK

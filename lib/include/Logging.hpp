#pragma once

#include <boost/log/expressions.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/log/utility/setup.hpp>

#define LOG_TRACE                                                                  \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::trace)                  \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)

#define LOG_DEBUG                                                                  \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::debug)                  \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)

#define LOG_INFO                                                                   \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::info)                   \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)

#define LOG_WARNING                                                                \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::warning)                \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)

#define LOG_ERROR                                                                  \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::error)                  \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)
	  
#define LOG_FATAL                                                                  \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::fatal)                  \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)

using logger_t=boost::log::sources::severity_logger_mt<
    boost::log::trivial::severity_level>;

BOOST_LOG_GLOBAL_LOGGER(my_logger, logger_t)


// void setLogLevelInfo() {
//     boost::log::core::get()->set_filter(boost::log::trivial::severity >=
//                                      boost::log::trivial::info);
// }

// void setLogLevelDebug() {
//     boost::log::core::get()->set_filter(boost::log::trivial::severity >=
//                                      boost::log::trivial::debug);
// }
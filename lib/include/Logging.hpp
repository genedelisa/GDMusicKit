#pragma once

#include <boost/log/expressions.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/support/date_time.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/log/utility/setup.hpp>

#define TRACE                                                                  \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::trace)                  \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)

#define DEBUG                                                                  \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::debug)                  \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)

#define INFO                                                                   \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::info)                   \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)

#define WARNING                                                                \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::warning)                \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)

#define ERROR                                                                  \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::error)                  \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)
	  
#define FATAL                                                                  \
  BOOST_LOG_SEV(my_logger::get(), boost::log::trivial::fatal)                  \
      << boost::log::add_value("Line", __LINE__)                               \
      << boost::log::add_value("File", __FILE__)                               \
      << boost::log::add_value("Function", BOOST_CURRENT_FUNCTION)

typedef boost::log::sources::severity_logger_mt<
    boost::log::trivial::severity_level>
    logger_t;

BOOST_LOG_GLOBAL_LOGGER(my_logger, logger_t)

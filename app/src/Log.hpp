#pragma once

#include <iostream>
#include <fstream>
#include <ostream>

#include <boost/log/core.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/utility/manipulators/add_value.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include "boost/log/utility/setup.hpp"
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

#include <boost/filesystem.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/log/support/date_time.hpp>

#include <boost/log/expressions.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace sinks = boost::log::sinks;
namespace keywords = boost::log::keywords;
namespace expr = boost::log::expressions;

#define LOGGER(severity) BOOST_LOG_TRIVIAL(severity)

enum severity_level { trace, debug, info, warning, error, fatal };

#include <boost/log/sources/global_logger_storage.hpp>
BOOST_LOG_GLOBAL_LOGGER(logger, boost::log::sources::severity_logger_mt< severity_level >)

#define LOG(log_, sv)                                                          \
  BOOST_LOG_SEV(log_, sv) << boost::log::add_value("Line", __LINE__)           \
                          << boost::log::add_value("File", __FILE__)           \
                          << boost::log::add_value("Function",                 \
                                                   BOOST_CURRENT_FUNCTION)

/**
 * @brief Initializes the logger
 *
 * @param[in]  filename  Formated string for the name of log file
 *
 * @exception
 */
void initLog(const std::string_view filename);



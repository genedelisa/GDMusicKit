# enable_static_analysis
# Enables various static analyzers gloablly
macro(enable_static_analysis)



# Clang-tidy
if(USE_CLANG_TIDY)
find_program(CLANG_TIDY_EXE NAMES "clang-tidy")
if(NOT CLANG_TIDY_EXE)
  message(STATUS "Found clang-tidy: not found")
else()
  message(STATUS "Found clang-tidy: ${CLANG_TIDY_EXE}")
#  set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXE} )
#  set(CMAKE_CXX_CLANG_TIDY ${CLANG_TIDY_EXE} "-checks=*")

set(CMAKE_CXX_CLANG_TIDY
    ${CLANG_TIDY_EXE} -checks=-*,modernize-*,-readability-identifier-naming
    # misc-static-assert,
    # llvm-namespace-coment,
    # clang-diagnostic-*,
    # llvm-*,
    # misc-*,
    # -misc-unused-parameters,
    # readability-identifier-naming
)


endif()
endif(USE_CLANG_TIDY)

# Cppcheck
if(USE_CPPCHECK)
find_program(CPPCHECK_EXE NAMES "cppcheck")
if(NOT CPPCHECK_EXE)
  message(STATUS "Found cppcheck: not found")
else()
  message(STATUS "Found cppcheck: ${CPPCHECK_EXE}")
  set(CMAKE_CXX_CPPCHECK ${CPPCHECK_EXE})
endif()
endif(USE_CPPCHECK)

# Cpplint
if(USE_CPPLINT)

find_program(CPPLINT_EXE NAMES "cpplint")
if(NOT CPPLINT_EXE)
  message(STATUS "Found cpplint: not found")
else()
  message(STATUS "Found cpplint: ${CPPLINT_EXE}")
#  set(CMAKE_CXX_CPPLINT ${CPPLINT_EXE})

set(CMAKE_CXX_CPPLINT ${CPPLINT_EXE}
--filter=-whitespace,-legal,-readability/nolint
)  
endif()
endif(USE_CPPLINT)

# Include-what-you-use
if(USE_INCLUDE_WHAT_YOU_USE)
find_program(IWYU_EXE NAMES "iwyu")
if(NOT IWYU_EXE)
  message(STATUS "Found include-what-you-use: not found")
else()
  message(STATUS "Found include-what-you-use: ${IWYU_EXE}")
  set(CMAKE_CXX_INCLUDE_WHAT_YOU_USE ${IWYU_EXE})
endif()
endif(USE_INCLUDE_WHAT_YOU_USE)


if(USE_LINK_WHAT_YOU_USE)
endif(USE_LINK_WHAT_YOU_USE)
# Link-what-you-use
#message(STATUS "Found link-what-you-use: True")
#set(CMAKE_LINK_WHAT_YOU_USE TRUE)

endmacro()

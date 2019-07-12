# custom targets to runclang-format, clang-tidy, and cppcheck

# Get all c++ files in lib
file(GLOB_RECURSE
     ALL_CXX_SOURCE_FILES
     RELATIVE "${PROJECT_SOURCE_DIR}/src"
     *.[ch]pp 
)

# Add clang-format target if executable is found
find_program(CLANG_FORMAT "clang-format")
if(CLANG_FORMAT)
  add_custom_target(
    clang-format
    COMMAND ${CLANG_FORMAT}
    -i
    -style=file
    ${ALL_CXX_SOURCE_FILES}
    )
endif(CLANG_FORMAT)

# Add clang-tidy target if executable is found
find_program(CLANG_TIDY "clang-tidy")
message("CLANG_TIDY: ${CLANG_TIDY}")
message("ALL_CXX_SOURCE_FILES: ${ALL_CXX_SOURCE_FILES}")

if(CLANG_TIDY)
  add_custom_target(
    clang-tidy
    COMMAND ${CLANG_TIDY}
    -p ../build
    -extra-arg=-std=c++17
    ${ALL_CXX_SOURCE_FILES}
    )
endif(CLANG_TIDY)

# I installed this via homebrew
find_program(CPPCHECK "cppcheck")
message("CPPCHECK: ${CPPCHECK}")
if(CPPCHECK)
add_custom_target(
    cppcheck
    COMMAND ${CPPCHECK}
    --std=c++17 
    --enable=all
    ${ALL_CXX_SOURCE_FILES}
    )
endif(CPPCHECK)


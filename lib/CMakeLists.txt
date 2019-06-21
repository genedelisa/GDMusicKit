cmake_minimum_required(VERSION 3.14.0 FATAL_ERROR)

project(GDMusicKit
    VERSION 1.0.0
    LANGUAGES CXX
    DESCRIPTION "Music classes"
    HOMEPAGE_URL "https://github.com/genedelisa/gdmusickit"
)

# just for testing
#set(CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/libinstall" CACHE PATH "Installation Directory")

# be able to find custom modules
list(INSERT CMAKE_MODULE_PATH 0 ${CMAKE_SOURCE_DIR}/cmake)

##############################################
# dependencies
find_package(Boost REQUIRED COMPONENTS regex)

##############################################
# Create library target

add_library(gdmusickit
    src/Pitch.cpp
)

#Add an alias so that library can be used inside the build tree, e.g. when testing
add_library(GDMusicKit::gdmusickit ALIAS gdmusickit)

# Set library target properties
target_include_directories(gdmusickit
    PUBLIC
        $<INSTALL_INTERFACE:include>
#        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/gdmusic>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include/
#        ${CMAKE_CURRENT_SOURCE_DIR}/include/gdmusic
#        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
#target_include_directories(mylib INTERFACE
#  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/mylib>
#  $<INSTALL_INTERFACE:include/mylib>  # <prefix>/include/mylib
#)

target_compile_features(gdmusickit
	PRIVATE
		cxx_std_17
)

target_compile_options(gdmusickit
	PRIVATE
		$<$<CXX_COMPILER_ID:MSVC>:/W3>
    	$<$<CXX_COMPILER_ID:Clang>:-Wall>
    	$<$<CXX_COMPILER_ID:GNU>:-Wall>
)

target_link_libraries(gdmusickit
    PUBLIC
        Boost::boost
    PRIVATE
        Boost::regex
)

##############################################
# Installation instructions

include(GNUInstallDirs)
set(INSTALL_CONFIGDIR ${CMAKE_INSTALL_LIBDIR}/cmake/GDMusicKit)

install(TARGETS gdmusickit
    EXPORT gdmusickit-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

#This is required so that the exported target has the name GDMusicKit and not gdmusickit
set_target_properties(gdmusickit PROPERTIES EXPORT_NAME GDMusicKit)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

#Export the targets to a script
install(EXPORT gdmusickit-targets
  FILE
    GDMusicKitTargets.cmake
  NAMESPACE
    GDMusicKit::
  DESTINATION
    ${INSTALL_CONFIGDIR}
)

#Create a ConfigVersion.cmake file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/GDMusicKitConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_LIST_DIR}/cmake/GDMusicKitConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/GDMusicKitConfig.cmake
    INSTALL_DESTINATION ${INSTALL_CONFIGDIR}
)

#Install the config, configversion and custom find modules
install(FILES
    #${CMAKE_CURRENT_LIST_DIR}/cmake/FindRapidJSON.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/GDMusicKitConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/GDMusicKitConfigVersion.cmake
    DESTINATION ${INSTALL_CONFIGDIR}
)

##############################################
## Exporting from the build tree

export(EXPORT gdmusickit-targets
	FILE ${CMAKE_CURRENT_BINARY_DIR}/GDMusicKitTargets.cmake
	NAMESPACE GDMusicKit::)

#Register package in user's package registry
export(PACKAGE GDMusicKit)

add_subdirectory(test)

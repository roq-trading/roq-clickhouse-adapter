cmake_minimum_required(VERSION 3.12)

# cmake

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})

# config

include(RoqConfig)

# version (using git tag)

include(GetGitRepoVersion)

message("Using GIT_REPO_VERSION=${GIT_REPO_VERSION}")

# project

project(roq-clickhouse-adapter VERSION ${GIT_REPO_VERSION})

# filesystem

include(GNUInstallDirs)

# dependencies

find_package(absl REQUIRED)
find_package(ClickHouse_CPP REQUIRED)
find_package(fmt REQUIRED)
find_package(roq-adapter REQUIRED)
find_package(roq-api REQUIRED)
find_package(roq-flags REQUIRED)
find_package(roq-io REQUIRED)
find_package(roq-logging REQUIRED)
find_package(unordered_dense REQUIRED)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
endif()

if(BUILD_TESTING)
  find_package(Catch2 REQUIRED)
endif()

# include

include_directories(${CMAKE_SOURCE_DIR}/src)

# sub-projects

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/src/roq/adapter/clickhouse)

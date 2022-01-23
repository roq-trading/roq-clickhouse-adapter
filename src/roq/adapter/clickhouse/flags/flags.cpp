/* Copyright (c) 2017-2022, Hans Erik Thrane */

#include "roq/adapter/clickhouse/flags/flags.hpp"

#include <absl/flags/flag.h>

#include <string>

ABSL_FLAG(  //
    std::string,
    db_host,
    "localhost",
    "database host");

ABSL_FLAG(  //
    uint16_t,
    db_port,
    9000,
    "database port");

ABSL_FLAG(  //
    std::string,
    database,
    "roq",
    "database name");

ABSL_FLAG(  //
    uint32_t,
    max_rows,
    1024,
    "max rows before flush");

namespace roq {
namespace adapter {
namespace clickhouse {
namespace flags {

std::string_view Flags::db_host() {
  static const std::string result = absl::GetFlag(FLAGS_db_host);
  return result;
}

uint16_t Flags::db_port() {
  static const uint16_t result = absl::GetFlag(FLAGS_db_port);
  return result;
}

std::string_view Flags::database() {
  static const std::string result = absl::GetFlag(FLAGS_database);
  return result;
}

uint32_t Flags::max_rows() {
  static const uint32_t result = absl::GetFlag(FLAGS_max_rows);
  return result;
}

}  // namespace flags
}  // namespace clickhouse
}  // namespace adapter
}  // namespace roq

/* Copyright (c) 2017-2022, Hans Erik Thrane */

#pragma once

#include <string>

#include "roq/adapter/clickhouse/table.hpp"

namespace roq {
namespace adapter {
namespace clickhouse {

struct Position final {
  using value_type = roq::PositionUpdate;

  static const constexpr auto table_name = []() {
    using namespace std::literals;
    return "position"sv;
  }();

  Position();

  std::string get_fields() const;
  std::string get_index_fields() const { return {}; }

  size_t operator()(value_type const &);

  void append(third_party::clickhouse::Block &);

  void clear();

 private:
  Column<uint16_t> stream_id_;
  Column<std::string_view, true> account_;
  Column<std::string_view, true> exchange_;
  Column<std::string_view, true> symbol_;
  Column<std::string_view, true> external_account_;
  Column<double> long_quantity_;
  Column<double> short_quantity_;
  Column<double> long_quantity_begin_;
  Column<double> short_quantity_begin_;
};

}  // namespace clickhouse
}  // namespace adapter
}  // namespace roq

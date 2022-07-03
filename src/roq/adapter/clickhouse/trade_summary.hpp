/* Copyright (c) 2017-2022, Hans Erik Thrane */

#pragma once

#include <string>

#include "roq/adapter/clickhouse/table.hpp"

namespace roq {
namespace adapter {
namespace clickhouse {

struct TradeSummary final {
  using value_type = roq::TradeSummary;

  static const constexpr auto table_name = []() {
    using namespace std::literals;
    return "trade_summary"sv;
  }();

  TradeSummary();

  std::string get_fields() const;
  std::string get_index_fields() const;

  size_t operator()(value_type const &);

  void append(third_party::clickhouse::Block &);

  void clear();

 private:
  Column<uint16_t> stream_id_;
  Column<std::string_view, true> exchange_;
  Column<std::string_view, true> symbol_;
  // trades
  Column<std::chrono::nanoseconds> exchange_time_utc_;
};

}  // namespace clickhouse
}  // namespace adapter
}  // namespace roq

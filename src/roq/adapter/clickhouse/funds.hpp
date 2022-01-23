/* Copyright (c) 2017-2022, Hans Erik Thrane */

#pragma once

#include <string>

#include "roq/adapter/clickhouse/table.hpp"

namespace roq {
namespace adapter {
namespace clickhouse {

struct Funds final {
  using value_type = roq::FundsUpdate;

  static const constexpr auto table_name = []() {
    using namespace std::literals;
    return "funds"sv;
  }();

  Funds();

  std::string get_fields() const;
  std::string get_index_fields() const { return {}; }

  void operator()(value_type const &);

  void append(third_party::clickhouse::Block &);

  void clear();

 private:
  Column<uint16_t> stream_id_;
  Column<std::string_view, true> account_;
  Column<std::string_view, true> currency_;
  Column<double> balance_;
  Column<double> hold_;
  Column<std::string_view, true> external_account_;
};

}  // namespace clickhouse
}  // namespace adapter
}  // namespace roq

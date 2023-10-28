/**
 * @file database_json_parser.h
 * @author Bartosz Snieg (snieg45@gmail.com)
 * @brief This file define parser for database
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef ROUTER_APP_JSON_PARSER_DATABASE_JSON_PARSER_H_
#define ROUTER_APP_JSON_PARSER_DATABASE_JSON_PARSER_H_
#include <fstream>
#include <nlohmann/json.hpp>
#include <string>
// using nlojson = nlohmann::json;
namespace simba {
namespace router {
namespace json {
class DatabaseJsonParser {
 private:
  /* data */
 public:
  template <class Database>
  static void LoadJson(Database& db, const std::string& path_to_json) {
    std::ifstream f(path_to_json);
    nlohmann::json data = nlohmann::json::parse(f);
  }

  DatabaseJsonParser(/* args */);
  ~DatabaseJsonParser();
};
}  // namespace json
}  // namespace router
}  // namespace simba

#endif  // ROUTER_APP_JSON_PARSER_DATABASE_JSON_PARSER_H_

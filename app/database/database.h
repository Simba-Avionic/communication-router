/**
 * @file database.h
 * @author Bartosz Snieg (snieg45@gmail.com)
 * @brief This file define database for router
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef ROUTER_APP_DATABASE_DATABASE_H_
#define ROUTER_APP_DATABASE_DATABASE_H_
#include <cstdint>
#include <string>
#include "app/database/database_element.h"

#include "unordered_map"
namespace simba {
namespace router {
class Database {
 private:
  std::unordered_map<std::uint16_t, DatabaseElement> db{};
  public:

};
}  // namespace router
}  // namespace simba
#endif  // ROUTER_APP_DATABASE_DATABASE_H_

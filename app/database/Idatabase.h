/**
 * @file database.h
 * @author Bartosz Snieg (snieg45@gmail.com)
 * @brief This file define interface for database
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef ROUTER_APP_DATABASE_IDATABASE_H_
#define ROUTER_APP_DATABASE_IDATABASE_H_
#include <cstdint>
#include <string>

#include "app/database/database_element.h"

namespace simba {
namespace router {
class IDatabase {
 private:
 public:
  virtual DatabaseElement GetService(const std::uint16_t service_id) = 0;
  virtual bool ServiceExist(const std::uint16_t service_id) = 0;
  virtual void AddService(DatabaseElement& element) = 0;
};
}  // namespace router
}  // namespace simba
#endif  // ROUTER_APP_DATABASE_IDATABASE_H_

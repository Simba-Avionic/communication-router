/**
 * @file database_element.h
 * @author Bartosz Snieg (snieg45@gmail.com)
 * @brief this file define database element
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef ROUTER_APP_DATABASE_DATABASE_ELEMENT_H_
#define ROUTER_APP_DATABASE_DATABASE_ELEMENT_H_
#include <iostream>
#include <string>
namespace simba {
namespace router {
class DatabaseElement {
 private:
  const std::string ip_;
  const uint16_t port_;

 public:
  DatabaseElement(const std::string& ip, const int16_t port)
      : ip_{ip}, port_{port_} {}
  const inline std::string GetIp() { return ip_; }
  const inline uint16_t GetPort() { return port_; }
  ~DatabaseElement() = default;
};
}  // namespace router
}  // namespace simba
#endif  // ROUTER_APP_DATABASE_DATABASE_ELEMENT_H_

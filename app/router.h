/**
 * @file router.h
 * @author Bartosz Snieg (snieg45@gmail.com)
 * @brief This file define main router app
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef ROUTER_APP_ROUTER_H_
#define ROUTER_APP_ROUTER_H_
#include "app/json-parser/database_json_parser.h"
#include "application/application_no_ipc.h"
#include "application/parm.h"
namespace simba {
namespace router {
class Router : public core::ApplicationNoIPC {
 protected:
  void Run(const std::unordered_map<std::string, core::Parm>& parms) override;
  void Stop() override;

 public:
  ~Router() = default;
};

}  // namespace router
}  // namespace simba
#endif  // ROUTER_APP_ROUTER_H_

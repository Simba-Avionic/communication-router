/**
 * @file router.cc
 * @author Bartosz Snieg (snieg45@gmail.com)
 * @brief
 * @version 0.1
 * @date 2023-10-23
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <memory>
#include <utility>
#include <chrono>
#include <thread>
#include "app/router.h"
#include "database/database.h"
#include "json-parser/database_json_parser.h"
#include "sockets/ipc_socket.h"
#include "someip-controller/someip_controller.h"
namespace simba {
namespace router {

void Router::Run(const std::unordered_map<std::string, core::Parm>& parms) {
  Database db{};
  this->logger_->Debug("Router started");
  // com::soc::IpcSocket soc{};
  // soc.Init(com::soc::SocketConfig{"testowy.socket", 0, 0});
  // soc.StartRXThread();
  // this->SleepMainThred();
  //   soc.Transmit("testowy.socket", 0,
  //                std::vector<uint8_t>{'D', 'i', 'a', 'l', 'a'});
  // json::DatabaseJsonParser::LoadJson(db,"/home/bartek/simba/communication-router/app/resource/provide_list.json");
  simba::com::someip::SomeIpController com{
      0x101, std::make_unique<com::soc::IpcSocket>(), logger_,
      com::soc::SocketConfig{"testowy.socket2", 0, 0}};
  com.Init();
  while (true) {
    const auto res = com.Request(0x100, 0x0001, {});
    if (res.HasValue()) {
      logger_->Info("Pass");
      for (auto val : res.Value()) {
        logger_->Error(std::to_string(val));
      }
    }
    std::this_thread::sleep_for(std::chrono::seconds{1});
  }

  this->SleepMainThred();
}
void Router::Stop() { this->logger_->Debug("Router stop"); }
}  // namespace router
}  // namespace simba
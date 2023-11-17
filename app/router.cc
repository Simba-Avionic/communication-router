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
#include "app/router.h"

#include <memory>
#include <utility>

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
      0x100, std::make_unique<com::soc::IpcSocket>(), logger_,
      com::soc::SocketConfig{"testowy.socket", 0, 0}};
  com.AddMethod(0x0001, [&](const std::vector<uint8_t> payload) {
    this->logger_->Info("IPC zadziałało !!!!!");
    return simba::core::Result<
        std::pair<std::vector<uint8_t>, com::core::data::MessageCode>>{
        {{1, 2, 3, 4, 5}, com::core::data::kEOk}};
  });
  com.Init();
  this->SleepMainThred();
}
void Router::Stop() { this->logger_->Debug("Router stop"); }
}  // namespace router
}  // namespace simba
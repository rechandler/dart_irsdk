#include "irsdk_plugin.h"

// This must be included before many other Windows headers.
#include <windows.h>

// For getPlatformVersion; remove unless needed for your plugin implementation.
#include <VersionHelpers.h>

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>
#include <flutter/standard_method_codec.h>

#include <memory>
#include <sstream>

#include "include/irsdk/irsdk_utils.cpp"
#include "include/irsdk/irsdk_client.cpp"
#include "include/irsdk/yaml_parser.cpp"
#include "include/mappings/irsdk_mappings.cpp"

using namespace std;

namespace irsdk {

  // static
  void IrsdkPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarWindows *registrar) {
    auto channel =
        std::make_unique<flutter::MethodChannel<flutter::EncodableValue>>(
            registrar->messenger(), "irsdk",
            &flutter::StandardMethodCodec::GetInstance());

    auto plugin = std::make_unique<IrsdkPlugin>();

    channel->SetMethodCallHandler(
        [plugin_pointer = plugin.get()](const auto &call, auto result) {
          plugin_pointer->HandleMethodCall(call, std::move(result));
        });

    registrar->AddPlugin(std::move(plugin));
  }

  IrsdkPlugin::IrsdkPlugin() {}

  IrsdkPlugin::~IrsdkPlugin() {}

  void IrsdkPlugin::HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result) {

      if(method_call.method_name().compare("irsdkStartup") == 0) {
        bool started = irsdk_startup();
        result->Success(flutter::EncodableValue(started));
      }
      if(method_call.method_name().compare("getTelemetryData") == 0) {
        irsdkClient::instance().waitForData();
        result->Success(flutter::EncodableMap(irsdkCar::getCar()));
      }
      result->NotImplemented();
  }

}  // namespace irsdk

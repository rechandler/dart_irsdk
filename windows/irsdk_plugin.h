#ifndef FLUTTER_PLUGIN_IRSDK_PLUGIN_H_
#define FLUTTER_PLUGIN_IRSDK_PLUGIN_H_

#include <flutter/method_channel.h>
#include <flutter/plugin_registrar_windows.h>

#include <memory>

namespace irsdk {

class IrsdkPlugin : public flutter::Plugin {
 public:
  static void RegisterWithRegistrar(flutter::PluginRegistrarWindows *registrar);

  IrsdkPlugin();

  virtual ~IrsdkPlugin();

  // Disallow copy and assign.
  IrsdkPlugin(const IrsdkPlugin&) = delete;
  IrsdkPlugin& operator=(const IrsdkPlugin&) = delete;

  // Called when a method is called on this plugin's channel from Dart.
  void HandleMethodCall(
      const flutter::MethodCall<flutter::EncodableValue> &method_call,
      std::unique_ptr<flutter::MethodResult<flutter::EncodableValue>> result);
};

}  // namespace irsdk

#endif  // FLUTTER_PLUGIN_IRSDK_PLUGIN_H_

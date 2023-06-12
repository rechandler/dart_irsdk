#include "include/irsdk/irsdk_plugin_c_api.h"

#include <flutter/plugin_registrar_windows.h>

#include "irsdk_plugin.h"

void IrsdkPluginCApiRegisterWithRegistrar(
    FlutterDesktopPluginRegistrarRef registrar) {
  irsdk::IrsdkPlugin::RegisterWithRegistrar(
      flutter::PluginRegistrarManager::GetInstance()
          ->GetRegistrar<flutter::PluginRegistrarWindows>(registrar));
}

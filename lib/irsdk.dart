import 'irsdk_platform_interface.dart';
import 'dart:async';

class Irsdk {
  StreamController irsdkStream = StreamController();

  Future<bool> irsdkStartup() {
    return IrsdkPlatform.instance.irsdkStartup();
  }

  void initializeStream() async {
    while (true) {
      irsdkStream.add(await IrsdkPlatform.instance.getTelemetryData());
    }
  }
}

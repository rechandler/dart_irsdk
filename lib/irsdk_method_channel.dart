import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';

import 'irsdk_platform_interface.dart';

/// An implementation of [IrsdkPlatform] that uses method channels.
class MethodChannelIrsdk extends IrsdkPlatform {
  /// The method channel used to interact with the native platform.
  @visibleForTesting
  final methodChannel = const MethodChannel('irsdk');

  @override
  Future<bool> irsdkStartup() async {
    var result = await methodChannel.invokeMethod<bool>('irsdkStartup');
    return result == true ? true : false;
  }

  @override
  Future<String?> getTelemetryData() async {
    var value = await methodChannel
        .invokeMethod<Map<Object?, Object?>>('getTelemetryData');
    return value.toString();
  }
}

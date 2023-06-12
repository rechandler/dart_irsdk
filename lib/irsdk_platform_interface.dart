import 'package:plugin_platform_interface/plugin_platform_interface.dart';

import 'irsdk_method_channel.dart';

abstract class IrsdkPlatform extends PlatformInterface {
  /// Constructs a IrsdkPlatform.
  IrsdkPlatform() : super(token: _token);

  static final Object _token = Object();

  static IrsdkPlatform _instance = MethodChannelIrsdk();

  /// The default instance of [IrsdkPlatform] to use.
  ///
  /// Defaults to [MethodChannelIrsdk].
  static IrsdkPlatform get instance => _instance;

  /// Platform-specific implementations should set this with their own
  /// platform-specific class that extends [IrsdkPlatform] when
  /// they register themselves.
  static set instance(IrsdkPlatform instance) {
    PlatformInterface.verifyToken(instance, _token);
    _instance = instance;
  }

  Future<bool> irsdkStartup() {
    throw UnimplementedError('irsdkStartup() has not been implemented.');
  }

  Future<String?> getTelemetryData() {
    throw UnimplementedError('telemetryData() has not been implemented.');
  }
}

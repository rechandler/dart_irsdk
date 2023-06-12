import 'package:flutter_test/flutter_test.dart';
import 'package:irsdk/irsdk.dart';
import 'package:irsdk/irsdk_platform_interface.dart';
import 'package:irsdk/irsdk_method_channel.dart';
import 'package:plugin_platform_interface/plugin_platform_interface.dart';

class MockIrsdkPlatform
    with MockPlatformInterfaceMixin
    implements IrsdkPlatform {
  @override
  Future<String?> getPlatformVersion() => Future.value('42');

  @override
  Future<String?> irsdkStartup() => Future.value('42');
}

void main() {
  final IrsdkPlatform initialPlatform = IrsdkPlatform.instance;

  test('$MethodChannelIrsdk is the default instance', () {
    expect(initialPlatform, isInstanceOf<MethodChannelIrsdk>());
  });

  test('getPlatformVersion', () async {
    Irsdk irsdkPlugin = Irsdk();
    MockIrsdkPlatform fakePlatform = MockIrsdkPlatform();
    IrsdkPlatform.instance = fakePlatform;

    expect(await irsdkPlugin.getPlatformVersion(), '42');
  });
}

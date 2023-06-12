import 'package:flutter/material.dart';
import 'dart:async';

import 'package:flutter/services.dart';
import 'package:irsdk/irsdk.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatefulWidget {
  const MyApp({super.key});

  @override
  State<MyApp> createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> {
  final _irsdkPlugin = Irsdk();

  @override
  void initState() {
    super.initState();
    initIrsdk();
  }

  // Platform messages are asynchronous, so we initialize in an async method.
  Future<void> initIrsdk() async {
    bool isConnected = false;

    isConnected = await _irsdkPlugin.irsdkStartup();

    if (!mounted) return;

    if (isConnected) {
      _irsdkPlugin.initializeStream();
    }
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        appBar: AppBar(
          title: const Text('Plugin example app'),
        ),
        body: Center(
            child: StreamBuilder<dynamic>(
                stream: _irsdkPlugin.irsdkStream.stream,
                builder: (BuildContext context, AsyncSnapshot snapshot) {
                  return Text(snapshot.toString());
                })),
      ),
    );
  }
}

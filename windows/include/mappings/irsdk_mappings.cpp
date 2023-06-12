#define MIN_WIN_VER 0x0501

#ifndef WINVER
#	define WINVER			MIN_WIN_VER
#endif

#ifndef _WIN32_WINNT
#	define _WIN32_WINNT		MIN_WIN_VER 
#endif

#include <windows.h>
#include <stdio.h>

#include <map>
#include <string>
using namespace std;

#include "../irsdk/irsdk_client.h"


irsdkCVar g_carThrottle("Throttle");
irsdkCVar g_carThrottleRaw("ThrottleRaw");

irsdkCVar g_carBrake("Brake");
irsdkCVar g_carBrakeRaw("BrakeRaw");

irsdkCVar g_carClutch("Clutch");
irsdkCVar g_carClutchRaw("ClutchRaw");

class irsdkCar {
  public:
    static map<flutter::EncodableValue, flutter::EncodableValue> getCar() {
      map <flutter::EncodableValue, flutter::EncodableValue> car;

      // Pedals
      car.insert(make_pair(flutter::EncodableValue("Throttle"), flutter::EncodableValue(g_carThrottle.getFloat())));
      car.insert(make_pair(flutter::EncodableValue("ThrottleRaw"), flutter::EncodableValue(g_carThrottleRaw.getFloat())));
      car.insert(make_pair(flutter::EncodableValue("Brake"), flutter::EncodableValue(g_carBrake.getFloat())));
      car.insert(make_pair(flutter::EncodableValue("BrakeRaw"), flutter::EncodableValue(g_carBrakeRaw.getFloat())));
      car.insert(make_pair(flutter::EncodableValue("Clutch"), flutter::EncodableValue(g_carClutch.getFloat())));
      car.insert(make_pair(flutter::EncodableValue("ClutchRaw"), flutter::EncodableValue(g_carClutchRaw.getFloat())));
      
      return car;
  }
};


#ifndef OPEN_WEATHER_MAP_SHARED_CLIENT_H
#define OPEN_WEATHER_MAP_SHARED_CLIENT_H

#include <WiFiClientSecure.h>

// One TLS client shared by Current Weather and Forecast.
// This allows HTTPClient to reuse the existing TLS session/connection
// for the second OpenWeather request instead of doing a second handshake.
inline WiFiClientSecure& openWeatherSharedSecureClient() {
  static WiFiClientSecure client;
  static bool initialized = false;
  if (!initialized) {
    client.setInsecure();
    initialized = true;
  }
  return client;
}

#endif

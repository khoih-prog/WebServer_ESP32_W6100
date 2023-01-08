/****************************************************************************************************************************
  WebServer_ESP32_W6100.h

  For Ethernet shields using ESP32_W6100 (ESP32 + W6100)

  WebServer_ESP32_W6100 is a library for the ESP32 with Ethernet W6100 to run WebServer

  Based on and modified from ESP32-IDF https://github.com/espressif/esp-idf
  Built by Khoi Hoang https://github.com/khoih-prog/WebServer_ESP32_W6100
  Licensed under GPLv3 license

  Version: 1.5.2

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.5.2   K Hoang      06/01/2022 Initial coding for ESP32_W6100 (ESP32 + W6100). Sync with WebServer_ESP32_W5500 v1.5.2
 *****************************************************************************************************************************/

#pragma once

#ifndef WEBSERVER_ESP32_W6100_H
#define WEBSERVER_ESP32_W6100_H

//////////////////////////////////////////////////////////////

//#if !defined(USING_CORE_ESP32_CORE_V200_PLUS)
#if ( ( defined(ESP_ARDUINO_VERSION_MAJOR) && (ESP_ARDUINO_VERSION_MAJOR >= 2) ) && ( ARDUINO_ESP32_GIT_VER != 0x46d5afb1 ) )
  #define USING_CORE_ESP32_CORE_V200_PLUS      true

  #if (_ETHERNET_WEBSERVER_LOGLEVEL_ > 3)
    #warning Using code for ESP32 core v2.0.0+ in WebServer_ESP32_W6100.h
  #endif

  #define WEBSERVER_ESP32_W6100_VERSION       "WebServer_ESP32_W6100 v1.5.2 for core v2.0.0+"
#else
  #if (_ETHERNET_WEBSERVER_LOGLEVEL_ > 3)
    #warning Using code for ESP32 core v1.0.6- in WebServer_ESP32_W6100.h
  #endif

  #define WEBSERVER_ESP32_W6100_VERSION       "WebServer_ESP32_W6100 v1.5.2 for core v1.0.6-"
#endif

#define WEBSERVER_ESP32_W6100_VERSION_MAJOR    1
#define WEBSERVER_ESP32_W6100_VERSION_MINOR    5
#define WEBSERVER_ESP32_W6100_VERSION_PATCH    2

#define WEBSERVER_ESP32_W6100_VERSION_INT      1005002

//////////////////////////////////////////////////////////////

#if ( ARDUINO_ESP32S2_DEV || ARDUINO_FEATHERS2 || ARDUINO_ESP32S2_THING_PLUS || ARDUINO_MICROS2 || \
      ARDUINO_METRO_ESP32S2 || ARDUINO_MAGTAG29_ESP32S2 || ARDUINO_FUNHOUSE_ESP32S2 || \
      ARDUINO_ADAFRUIT_FEATHER_ESP32S2_NOPSRAM )

  #error ESP32_S2 not supported. Use WebServer_ESP32_SC_W6100 library

#elif ( ARDUINO_ESP32C3_DEV )

  #error ESP32_C3 not supported. Use WebServer_ESP32_SC_W6100 library

#elif ( defined(ARDUINO_ESP32S3_DEV) || defined(ARDUINO_ESP32_S3_BOX) || defined(ARDUINO_TINYS3) || \
        defined(ARDUINO_PROS3) || defined(ARDUINO_FEATHERS3) )

  #error ESP32_S3 not supported. Use WebServer_ESP32_SC_W6100 library

#elif ESP32

  #if (_ETHERNET_WEBSERVER_LOGLEVEL_ > 3)
    #warning Using ESP32 architecture for WebServer_ESP32_W6100
  #endif

#define BOARD_NAME      ARDUINO_BOARD

#else
  #error This code is designed to run on ESP32 platform! Please check your Tools->Board setting.
#endif

//////////////////////////////////////////////////////////////

#include <Arduino.h>

#include "WebServer_ESP32_W6100_Debug.h"

//////////////////////////////////////////////////////////////

#include "w6100/esp32_w6100.h"

#include "WebServer_ESP32_W6100.hpp"
#include "WebServer_ESP32_W6100_Impl.h"

#endif    // WEBSERVER_ESP32_W6100_H

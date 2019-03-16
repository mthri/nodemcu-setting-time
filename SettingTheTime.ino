#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS3231 rtc;

const char *ssid     = "ssid";
const char *password = "password";

const long utcOffsetInSeconds = 12600; //You need to adjust the UTC offset for your timezone in milliseconds
// for  exampel iran UTC is 3:30 => 3.5 * 60 * 60 = 12600

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

// Define NTP Client to get time
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup(){

  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay (500);
    Serial.print ( "." );
  }
  //time
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  
  timeClient.begin();
  timeClient.update();
  delay(2000);
  Serial.println("Setting the time ....");
  rtc.adjust(DateTime(2019, 3, 15, timeClient.getHours(), timeClient.getMinutes(),timeClient.getSeconds()));
  Serial.println("Successful :D");
}

void loop() {
  DateTime now = rtc.now();
    
    Serial.println("Current Date & Time: ");
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    
    Serial.println();
    delay(1000);
}


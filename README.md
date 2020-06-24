# Automatic setting the time DS3231 by NTP with NodeMCU

  first you need install several library

    1- RTClib by Adafruit
    2- NTPClient by Fabrice Weinberg
    
  Connections:
  
    +         3.3
    D         D2(GPIO4)
    C         D1(GPIO5)
    -         GND
    
**Notic:**<br>
In line [39](https://github.com/mthri/nodemcu-setting-time/blob/master/SettingTheTime.ino#L39) you must set date manually.
   
  

// Date, Time and Alarm functions using a DS3231 RTC connected via I2C and Wire lib

#include "Wire.h"
#include "SPI.h"  // not used here, but needed to prevent a RTClib compile error
#include "RTClib.h"

RTC_DS3231 RTC;

const int mistOne = 4;
const int mistTwo = 6;

void setup () {

  Serial.begin(9600);

  pinMode(mistOne, OUTPUT);
  pinMode(mistTwo, OUTPUT);
  Serial.println("Set default output to LOW");
  digitalWrite(mistOne, LOW);
  digitalWrite(mistTwo, LOW);

  Wire.begin();
  RTC.begin();

//  RTC.adjust(DateTime(__DATE__, __TIME__));

  //  if (! RTC.isrunning()) {
  //    Serial.println("RTC is NOT running!");
  //    // following line sets the RTC to the date & time this sketch was compiled
  //    RTC.adjust(DateTime(__DATE__, __TIME__));
  //  }

  //  DateTime now = RTC.now();
  //  /* ตั้งเวลา ในตัวอย่างนี้ เซตค่าเป็นเวลา 23:09 ถ้าถึงเวลานี้จะให้ทำงานที่ฟังก์ชัน
  //    RTC.setAlarm1Simple(23, 9);
  //    if (RTC.checkIfAlarm(1)) {
  //    Serial.println("Alarm Triggered");
  //    }*/
  //  RTC.setAlarm1Simple(23, 9);
  //
  //  RTC.turnOnAlarm(1);
  //
  //  if (RTC.checkAlarmEnabled(1)) {
  //    Serial.println("Alarm Enabled");
  //  }

}

void loop () {

  DateTime now = RTC.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.print(", ");

  if ((now.hour() >= 8) && (now.hour() <= 18) )
  {
    if ((now.minute() >= 0  && now.minute() < 10) || (now.minute() >= 20 && now.minute() < 30) ||  (now.minute() >= 40 && now.minute() < 50))
    {
      Serial.println("Mode1");
      digitalWrite(mistOne, HIGH);
      digitalWrite(mistTwo, LOW);
    }
    else {
      Serial.println("Mode2");
      digitalWrite(mistOne, LOW);
      digitalWrite(mistTwo, HIGH);
    }
  }
  else {
    Serial.println("Mode offline1");
    digitalWrite(mistOne, LOW);
    digitalWrite(mistTwo, LOW);
  }

  delay(1000);
}

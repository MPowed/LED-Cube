
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include "RTClib.h"
#include "cubeplex.h"
#include "cubeCode.h"

RTC_DS3231 rtc;
#ifndef _BV
#define _BV(bit) (1<<(bit))
#endif


Adafruit_7segment seg;

uint8_t counter = 0;
int hr;
int lastHr;
int lastMin = 61;
int mnit;

void setup() {
  Serial.begin(115200);
  initCube();

  // how many secconds until the animation is told to progress
  animationMax = 10;

  Serial.println("Time module test");
  if (! rtc.begin())
  {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  else{
    Serial.println("Sucess");
  }
  //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  seg.begin(0x70);  // pass in the address
  seg.clear();
  seg.writeDisplay();
}

void loop() {
  setTime();
  delay(50);
  hourChange();
}

void setTime()
{
  DateTime now = rtc.now();
  mnit = now.minute();
  if (lastMin != mnit)
  {
    lastMin = mnit;
    hr = now.hour() * 100;
    if (hr > 1200)
    {
      hr -= 1200;
    } else if (hr == 0)
    {
      hr = 1200;
    }
    seg.print(hr + mnit);
    seg.drawColon(true);
    seg.writeDisplay();
    
  }
}


void hourChange()
{

  if (lastHr != hr)
  {
    Serial.print("Last Hour = "); //print for debugging
    Serial.println(lastHr);
    lastHr = hr; // Set the last hour it ran the animation
    chooseAnimation(random(6)); //Choose one of the Animations
    //chooseAnimation(3); //Debug line for selecting a specific animation
  }
}


void chooseAnimation(int num)
{
  if (num == 0)
  {
    shiftSquares();
    flushBuffer();
    clearBuffer();
  } else if (num == 1)
  {
    planarSpin();
    flushBuffer();
    clearBuffer();
  } else if (num == 2)
  {
    fountian();
    flushBuffer();
    clearBuffer();
  } else if (num == 3)
  {
    trifade();
    flushBuffer();
    clearBuffer();
  } else if (num == 4)
  {
    tunnel();
    flushBuffer();
    clearBuffer();
  } else if (num == 5)
  {
    planarFlop3D();
    flushBuffer();
    clearBuffer();
  }

}

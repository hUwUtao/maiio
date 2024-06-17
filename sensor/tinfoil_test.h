#include "../lib/CapacitiveSensor.cpp"
#include "bootstrap.h"

CapacitiveSensor cs_4_2 = CapacitiveSensor(4, 2);

void tInit() {
  pinMode(11, OUTPUT);

  //   cs_4_2.set_CS_AutocaL_Millis(
  //       0xFFFFFFFF); // turn off autocalibrate on channel 1 - just as an
  //       example
}
void tRset() {}
void tStat() {}

fnTRat {}
fnTSen {}

bool last = false;

unsigned char lerplike = 0;

unsigned char lastSent = LOW;

uint64_t tQuery() {
  //   long start = millis();
  long total1 = cs_4_2.capacitiveSensor(16);

  //   Serial.print(millis() - start); // check on performance in milliseconds
  //   Serial.print("\t");             // tab character for debug windown
  //   spacing

  //   Serial.print(total1); // print sensor output 1
  //   Serial.print("\n");
  bool now = total1 > 512;

  digitalWrite(11, now ? LOW : HIGH);

//   Serial.print(total1);

  if (now) {
    lastSent = now;
    return 17179869183;
  } else {
    return 0;
  }
}
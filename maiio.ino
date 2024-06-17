// Comment this line if whatever I cant change the var on compile
#define TEST_SENSOR 1

uint8_t i = 0, k = 0;

// = Touch section = //
// Parts of the code here slightly modified from
// https://github.com/Sucareto/Mai2Touch, with a bit of refactor I want to.
#if defined(TEST_SENSOR)
#include "sensor/tinfoil_test.h"
// #include "sensor/tset.h"
#else
#include "sensor/mpr121.h"
#endif

uint8_t tCmdBuf[6];
uint64_t tBuf = 0;

bool tHalt = true;

uint8_t cBuf = 0, cLen = 0;
void tEcho() {
  Serial.write('(');
  for (i = 1; i < cLen; i++) {
    Serial.write(tCmdBuf[i]);
  }
  Serial.write(')');
}
void tRecv() {
  while (Serial.available() > 0) {
    cBuf = Serial.read();
    if (cBuf == '{') {
      cLen = 0;
    }
    if (cBuf == '}') {
      break;
    }
    tCmdBuf[cLen++] = cBuf;
  }
  if (cLen == 5) {
    switch (tCmdBuf[3]) {
    case cmdRSET:
      tRset();
    case cmdHALT:
      tHalt = true;
      break;
    case cmdSTAT:
      tHalt = false;
      break;
    case cmdRatio:
      tRat(tCmdBuf[2], tCmdBuf[4]);
      tEcho();
      break;
    case cmdSens:
      tSen(tCmdBuf[2], tCmdBuf[4]);
      tEcho();
      break;
    }
    cLen = 0;
    memset(tCmdBuf, 0, 6);
    // memset(tCmdBuf, 0, 6);
  }
}

uint64_t tDBuf = 0;

void tSend() {
  tBuf = tQuery() & 17179869183;

  Serial.write('(');
  for (i = 0; i < 7; i++) {
    Serial.write((uint8_t)(tBuf & 0x1f));
    tBuf >>= 5;
  }
  Serial.write(')');
}

// = Keyboard Section = //
// Not implemented yet

// = Routine Section = //

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  Serial.setTimeout(0);
  // Wire.setClock(800000);
}

void loop() {
  tRecv();
  digitalWrite(13, tHalt ? LOW : HIGH);
  if (!tHalt)
    tSend();
}
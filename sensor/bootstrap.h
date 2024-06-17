enum {
  cmdRSET = 0x45,  // E
  cmdHALT = 0x4C,  // L
  cmdSTAT = 0x41,  // A
  cmdRatio = 0x72, // r
  cmdSens = 0x6B,  // k
};

void tInit();
void tRset();
void tStat();
void tRat(uint8_t a, uint8_t b);
#define fnTRat void tRat(uint8_t a, uint8_t b)
void tSen(uint8_t a, uint8_t b);
#define fnTSen void tSen(uint8_t a, uint8_t b)
uint64_t tQuery();
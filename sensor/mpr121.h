// again, really taken from
// https://github.com/Sucareto/Mai2Touch

#include "MprCfg.h"
#include "bootstrap.h"

void tInit() {
  mprA.begin(mprA_ADD);
  mprB.begin(mprB_ADD);
  mprC.begin(mprC_ADD);
}

void tRset() {
  MprReset(mprA);
  MprReset(mprB);
  MprReset(mprC);
}

void tHalt() {
  MprStop(mprA);
  MprStop(mprB);
  MprStop(mprC);
  MprConfig(mprA);
  MprConfig(mprB);
  MprConfig(mprC);
}

void tStat() {
  MprRun(mprA);
  MprRun(mprB);
  MprRun(mprC);
}

fnTRat { MprSetTouch(a, b); }
fnTSen { MprSetRelease(a, b); }

uint64_t tBuf = 0;
uint64_t tQuery() {
  // D7 ~ E8
  tBuf = (tBuf | mprC.touched()) << 12;
  // B5 ~ D6
  tBuf = (tBuf | mprB.touched()) << 12;
  // A1 ~ B4
  tBuf = (tBuf | mprA.touched());

  // 高级方法，读取每个触摸点的 baselineData 和
  // filteredData，可以精确控制触发敏感度。因为读取和判断的耗时，延迟可能会变高
  //  #define Threshold 10 //触摸触发阈值
  //  for (uint8_t i = 0; i < 10; i++) {// E8 ~ D7
  //    tBuf = (tBuf | (int)(mprC.baselineData(i) -
  //    mprC.filteredData(i)) > Threshold) << 1;
  //  }
  //  for (uint8_t i = 0; i < 12; i++) {// D6 ~ B5
  //    tBuf = (tBuf | (int)(mprB.baselineData(i) -
  //    mprB.filteredData(i)) > Threshold) << 1;
  //  }
  //  for (uint8_t i = 0; i < 12; i++) {// B4 ~ A1
  //    tBuf = (tBuf | (int)(mprA.baselineData(i) -
  //    mprA.filteredData(i)) > Threshold) << 1;
  //  }
  //  tBuf >>= 1;
}
/*
 * Copyright (C) 2020 Weiping He
 * Author(s): Weiping He
 *
 * License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * Please take look heweiping6.test/LICENSE for whole information.
 *
 * */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


int main(int argc, char **argv) {
  char bTmpTime[100];
  time_t inPut;

  memset(&bTmpTime, 0x00, sizeof(bTmpTime));
  printf("size of time_t=%ld", sizeof(time_t));
  inPut = (time_t) 0x0;
  ctime_r(&inPut, bTmpTime);
  printf("-0f- time: %s", bTmpTime);

  inPut = (time_t) 0xf;
  ctime_r(&inPut, bTmpTime);
  printf("-1f- time: %s", bTmpTime);

  inPut = (time_t) 0xff;
  ctime_r(&inPut, bTmpTime);
  printf("-2f- time: %s", bTmpTime);

  inPut = (time_t) 0xfff;
  ctime_r(&inPut, bTmpTime);
  printf("-3f- time: %s", bTmpTime);

  inPut = (time_t) 0xffff;
  ctime_r(&inPut, bTmpTime);
  printf("-4f- time: %s", bTmpTime);

  inPut = (time_t) 0xfffff;
  ctime_r(&inPut, bTmpTime);
  printf("-5f- time: %s", bTmpTime);

  inPut = (time_t) 0xffffff;
  ctime_r(&inPut, bTmpTime);
  printf("-6f- time: %s", bTmpTime);

  inPut = (time_t) 0xfffffff;
  ctime_r(&inPut, bTmpTime);
  printf("-7f- time: %s", bTmpTime);

  inPut = (time_t) 0x6fffffff;
  ctime_r(&inPut, bTmpTime);
  printf("-6-7f- time: %s", bTmpTime);

  inPut = (time_t) 0x7ffffffe;
  ctime_r(&inPut, bTmpTime);
  printf("-7ffffffe- time: %s", bTmpTime);

  inPut = (time_t) 0x7fffffff;
  ctime_r(&inPut, bTmpTime);
  printf("-7-7f- time: %s", bTmpTime);

  inPut = (time_t) 0xafffffff;
  ctime_r(&inPut, bTmpTime);
  printf("-a-7f- time: %s", bTmpTime);

  inPut = (time_t) 0xffffffff;
  ctime_r(&inPut, bTmpTime);
  printf("-8f- time: %s", bTmpTime);

  return (0);
}


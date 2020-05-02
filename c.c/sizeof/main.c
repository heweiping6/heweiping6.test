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

typedef char INT8T;
typedef short INT16T;
typedef int INT32T;
typedef long long INT64T;
typedef unsigned char UINT8T;
typedef unsigned short UINT16T;
typedef unsigned int UINT32T;
typedef unsigned long long UINT64T;
typedef char CHAR;
typedef float FLOATT;
typedef double DOUBLET;

int condition1() {
  printf("Enter condition1.\n");
  return (1);
}


int condition2() {
  printf("Enter condition2.\n");
  return (2);
}


int test(void) {
  int retVal = 0;
  if (1 != (retVal = condition1())) {
    printf("Condition1 pass.\n");
    return (1);
  } else if (2 != condition2()) {
    printf("Condition2 pass.\n");
    return (2);
  } else {
    printf("Condition3 pass.\n");
    return (3);
  }
  return (4);
}


int main(int argc, char **argv) {
  system("/usr/bin/getconf LONG_BIT");

  printf("INT8T,char = %d\n", sizeof(INT8T));
  printf("INT16T,short = %d\n", sizeof(INT16T));
  printf("INT32T,int = %d\n", sizeof(INT32T));
  printf("INT64T,long long = %d\n", sizeof(INT64T));
  printf("UINT8T,unsigned char = %d\n", sizeof(UINT8T));
  printf("UINT16T,unsigned short  = %d\n", sizeof(UINT16T));
  printf("UINT32T,unsigned int  = %d\n", sizeof(UINT32T));
  printf("UINT64T, unsigned long long = %d\n", sizeof(UINT64T));
  printf("FLOATT,float = %d\n", sizeof(FLOATT));
  printf("DOUBLET,double = %d\n", sizeof(DOUBLET));

  printf("me long,long = %d\n", sizeof(long));
  test();
  return (0);
}


/*
 * Copyright (C) 2020 Weiping He
 * Author(s): Weiping He
 *
 * License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * Please take look heweiping6.test/LICENSE for whole information.
 *
 * */


#include <stdio.h>


void fa(int a1) {
  printf("enter a1-fa=%d\n", a1);
  a1 = 10;
  printf("leave a1-fa=%d\n", a1);
}


void fb(int *b2) {
  printf("enter a1-fa=%d\n", *b2);
  *b2 = 10;
  printf("leave a1-fa=%d\n", *b2);
}


int main(void) {
  int a1 = 0;
  int b1 = 0;
  int *b2 = &b1;

  printf("enter a1-main=%d\n", a1);
  fa(a1);
  printf("leave a1-main=%d\n", a1);

  printf("============\n");

  printf("enter b2-main=%d\n", *b2);
  fb(b2);
  printf("leave b2-main=%d\n", *b2);
}

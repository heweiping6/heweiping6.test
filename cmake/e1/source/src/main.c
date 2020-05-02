/*
 * Copyright (C) 2020 Weiping He
 * Author(s): Weiping He
 *
 * License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * Please take look heweiping6.test/LICENSE for whole information.
 *
 * */


#include <stdio.h>
#include "callslib.h"
#include "calldlib.h"

static void teste1(void);

static void teste1(void) {
  call_d_lib();
  call_s_lib();
}


int main(void) {
  printf("Example 1 Main!\n");
  teste1();
  printf("###Example 1 Main, End !!!\n");
  return (0);
}


/*
 * Copyright (C) 2020 Weiping He
 * Author(s): Weiping He
 *
 * License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * Please take look heweiping6.test/LICENSE for whole information.
 *
 * */


//way 1
/*
extern "C" {
#include "e1.h"
}
 */


//way 2
extern "C" int add(int x, int y);


int main(int argc, char *argv[]) {
  add(2, 3);
  return (0);
}




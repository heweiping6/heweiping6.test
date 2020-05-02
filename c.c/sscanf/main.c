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


int main(int argc, char **argv) {
  int n1 = 0;
  int n2 = 0;

  if (argc < 3) {
    printf("Eg: %s x, x=1, 2, 3 \n", argv[0]);
    return (1);
  }

  if (sscanf(argv[1], "%d", &n1) != 1) {
    printf("Failed get the argv1....\n");
    return (2);
  }

  if (sscanf(argv[2], "%d", &n2) != 1) {
    printf("Failed get the argv2....\n");
    return (3);
  }

  printf("Haha ok!!<%d,%d>!\n", n1, n2);

  return (0);
}


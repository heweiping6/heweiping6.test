/*
 * Copyright (C) 2020 Weiping He
 * Author(s): Weiping He
 *
 * License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * Please take look heweiping6.test/LICENSE for whole information.
 *
 * */


#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>


int main() {
  pid_t p = getpid();
  printf("pid: 0x%x=%d\n", p, p);
}


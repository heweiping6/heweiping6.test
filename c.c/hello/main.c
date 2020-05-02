/*
 * Copyright (C) 2020 Weiping He
 * Author(s): Weiping He
 *
 * License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * Please take look heweiping6.test/LICENSE for whole information.
 *
 * */


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>


int main(int argc, char **argv) {
  int a = 0 ;
  int b = 1;
  printf("a %d\n", a);
  printf("b %d\n", b);

  if(a == b) {
    printf("a=b\n");
  } else if (a ==1) {
    printf("a=1\n");
  }else if(a == 2) {
    printf("a=2\n");
  }else {
    printf("a=%d\n",a);
  }
  int fd =0 ;
  int d = 0x12345678;
  int isize = 0 ;

  fd = open ("./abc", (O_RDWR | O_CREAT) );
  if(fd < 0 ) {
    printf("wrong fd \n");
    printf("wrong fd %d\n", errno);
    return 0;
  }
  isize= write(fd, &d, sizeof(int));
  printf("isize=%d \n", isize);
  close(fd);
  return (0);
}


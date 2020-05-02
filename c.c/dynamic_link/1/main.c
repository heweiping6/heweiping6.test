/*
 * Copyright (C) 2020 Weiping He
 * Author(s): Weiping He
 *
 * License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * Please take look heweiping6.test/LICENSE for whole information.
 *
 * */


/*
 * How to use dlopen and dlsym
 * */


#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <string.h>


int main(int argc, char *argv[]) {
  void (*voidPtr1)(void);
  void (*voidPtr2)(void);

  void *libp1 = dlopen("./libtest_dlib1.so", RTLD_LAZY);
  if (!libp1) {
    fprintf(stderr, "%s\n", dlerror());
    return (1);
  }

  voidPtr1 = (void (*)(void)) dlsym(libp1, "test_dlib1");
  voidPtr1();
  dlclose(libp1);

  void *libp2 = dlopen("./libtest_dlib2.so", RTLD_LAZY);
  if (!libp2) {
    fprintf(stderr, "%s\n", dlerror());
    return (2);
  }
  voidPtr2 = (void (*)(void)) dlsym(libp2, "test_dlib2");
  voidPtr2();
  dlclose(libp2);

  printf("Test main !\n");
  return (0);
}



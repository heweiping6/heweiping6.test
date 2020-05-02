/*
 * Copyright (C) 2020 Weiping He
 * Author(s): Weiping He
 *
 * License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 * Please take look heweiping6.test/LICENSE for whole information.
 *
 * */


/*
 * because C can not parse extern "C", we can not include e1.h, so,
 * must declear this function as extern
 * */

extern int add( int x, int y ); 

int main(int argc, char *argv[]) {
  add( 2, 3 );
  return (0);
}



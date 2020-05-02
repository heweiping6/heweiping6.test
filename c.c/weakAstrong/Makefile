# Copyright (C) 2020 Weiping He
# Author(s): Weiping He
#
# License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
# Please take look heweiping6.test/LICENSE for whole information.
#


#MYGCC = /usr/bin/gcc -Wall  $(CFLAGS)
MYGCC = /usr/bin/gcc -Wall
MYAR = /usr/bin/ar
MYAPP = weakstrong.elf
MFLAG = "-Wall -g"

all: clean pre-build weak.o strong.o
	${MYGCC} ${MFLAG} -o ${MYAPP} main.c bin/strong.o bin/weak.o

pre-build:
	mkdir -p bin

strong.o:  strong.c
	${MYGCC} -c $< -o bin/$@

weak.o:  weak.c
	${MYGCC} -c $< -o bin/$@


clean:
	rm -rf ${MYAPP}
	rm -rf bin

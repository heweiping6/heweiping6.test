# Copyright (C}2020 Weiping he
# Author(s): Weiping he
#
# License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
# Please take look heweiping6.test/LICENSE for whole information.
#


MYAPP = test_app
MFLAG = "-Wall"

all: clean ${MYAPP}

MYSRC = main.c

SHARELIBSRCLIST = test_dlib1.c
SHARELIBSRCLIST2 = test_dlib2.c
SHARELIBS = libtest_dlib1.so
SHARELIBS2 = libtest_dlib2.so

.PHONY: all ${APPS} ${SHARELIBS} ${SHARELIBS2}

${SHARELIBS}: ${SHARELIBSRCLIST}
	gcc ${MFLAG} -shared -o $@ -fPIC ${SHARELIBSRCLIST}

${SHARELIBS2}: ${SHARELIBSRCLIST2}
	gcc ${MFLAG} -shared -o $@ -fPIC ${SHARELIBSRCLIST2}

${MYAPP}: ${SHARELIBS} ${SHARELIBS2} ${MYSRC}
	gcc ${MYSRC} -o $@ -ldl

clean:
	rm -rf ${MYAPP}
	rm -rf ${SHARELIBS}
	rm -rf ${SHARELIBS2}


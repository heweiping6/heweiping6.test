#!/bin/bash -x
# Copyright (C) 2020 Weiping He
# Author(s): Weiping He
#
# License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
# Please take look heweiping6.test/LICENSE for whole information.
#


MYAPP=test_pickFaceByDlib
MYSYSROOT=/native-sysroot

mkdir -p abc

rm -rf $MYAPP

gcc -o $MYAPP \
*.cpp \
-std=gnu++11 \
-I$MYSYSROOT/include \
-Wl,-rpath=$MYSYSROOT/lib \
-L$MYSYSROOT/lib \
-ldlib \
-lstdc++ \
-lm \
-lopencv_core \
-lopencv_imgproc \
-lopencv_imgcodecs \





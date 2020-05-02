#!/bin/bash

# Copyright (C) 2020 Weiping He
# Author(s): Weiping He
#
# License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
# Please take look heweiping6.test/LICENSE for whole information.
#


MYAPP1=test_send
MYAPP2=test_rec
MFLAG="-Wall -g"

MYSRC1=pos.c
MYSRC2=pos-rec.c

rm -rfv $MYAPP1
rm -rfv $MYAPP2

gcc $MFLAG -o $MYAPP1 $MYSRC1 -lrt
gcc $MFLAG -o $MYAPP2 $MYSRC2 -lrt

#!/bin/bash

# Copyright (C) 2020 Weiping He
# Author(s): Weiping He
#
# License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
# Please take look heweiping6.test/LICENSE for whole information.
#

MYAPP=test_time
MFLAG="-Wall -g"

MYSRC=main.c

rm -rfv $MYAPP

gcc $MFLAG -o $MYAPP $MYSRC -lrt

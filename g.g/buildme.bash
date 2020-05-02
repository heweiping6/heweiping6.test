#!/usr/bin/env bash

# Copyright (C}2020 Weiping He
# Author(s): Weiping He
#
# License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
# Please take look heweiping6.test/LICENSE for whole information.
#

setdebug() {
set -e
set -x
}

setenv() {
export MYROOT=`pwd`
export MYOUTPUT=$MYROOT/bin

#go root path is install go path.
#go path project dir
export GOPATH=$MYROOT
}

cleanbuild() {
rm -rf $MYOUTPUT
}

buildone() {
go build -o $MYOUTPUT/one.a ./src/one
}

buildmain() {
go build -o $MYOUTPUT/test_main ./src/main
}

setdebug
setenv
cleanbuild
buildone
buildmain

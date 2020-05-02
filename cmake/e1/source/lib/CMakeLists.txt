# Copyright (C) 2020 Weiping he
# Author(s): Weiping He
#
# License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
# Please take look heweiping6.test/LICENSE for whole information.
#


MESSAGE(STATUS "e1/source/lib")
ADD_DEFINITIONS(-DHWP)

SET(E1SLIB_SRC callslib.c)
SET(E1DLIB_SRC calldlib.c)

INCLUDE_DIRECTORIES(
  ${aa_SOURCE_DIR}/source/include
)

ADD_LIBRARY(callslib STATIC ${E1SLIB_SRC})
ADD_LIBRARY(calldlib SHARED ${E1DLIB_SRC})


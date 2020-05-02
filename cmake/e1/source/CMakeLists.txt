# Copyright (C) 2020 Weiping he
# Author(s): Weiping He
#
# License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
# Please take look heweiping6.test/LICENSE for whole information.
#


MESSAGE(STATUS "source....")

INCLUDE_DIRECTORIES(include)

PROJECT (bbb)

MESSAGE("e1/source bbb PROJECT_NAME=${PROJECT_NAME}")
MESSAGE("e1/source bbb bbb_SOURCE_DIR=${bbb_SOURCE_DIR}")
MESSAGE("e1/source bbb bbb_BINARY_DIR=${bbb_BINARY_DIR}")
MESSAGE("e1/source bbb PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")
MESSAGE("e1/source bbb PROJECT_BINARY_DIR=${PROJECT_BINARY_DIR}")
MESSAGE("e1/source bbb CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")
MESSAGE("e1/source bbb CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")

ADD_SUBDIRECTORY(src)

ADD_SUBDIRECTORY(lib)


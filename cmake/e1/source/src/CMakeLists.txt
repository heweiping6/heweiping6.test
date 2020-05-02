# Copyright (C) 2020 Weiping He
# Author(s): Weiping He
#
# License: GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
# Please take look heweiping6.test/LICENSE for whole information.
#


PROJECT (ccc)

MESSAGE("e1/src/src PROJECT_NAME=${PROJECT_NAME}")
MESSAGE("e1/source/src ccc_SOURCE_DIR=${ccc_SOURCE_DIR}")
MESSAGE("e1/source/src ccc_BINARY_DIR=${ccc_BINARY_DIR}")
MESSAGE("e1/source/src PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")
MESSAGE("e1/source/src PROJECT_BINARY_DIR=${PROJECT_BINARY_DIR}")
MESSAGE("e1/source/src CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")
MESSAGE("e1/source/src CMAKE_BINARY_DIR=${CMAKE_BINARY_DIR}")

SET(SRC_LIST main.c)

INCLUDE_DIRECTORIES(
    ${aa_SOURCE_DIR}/source/include
)

ADD_EXECUTABLE(targettttt ${SRC_LIST})

TARGET_LINK_LIBRARIES(targettttt 
callslib
calldlib
)

MESSAGE(STATUS "e1/source/src")

MESSAGE(STATUS "e1/src cmakelists .b... ${CMAKE_INSTALL_PREFIX}")

MESSAGE(STATUS "e1/src cmakelists .a... ${CMAKE_INSTALL_PREFIX}")



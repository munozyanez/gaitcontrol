# jgvictores @ 2016

IF (NOT GAIT_FOUND)

  SET(GAIT_LIBRARIES "gait")
  SET(GAIT_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/libraries/gait/src/")
  SET(GAIT_LINK_DIRS "${CMAKE_SOURCE_DIR}/build/lib")
  SET(GAIT_DEFINES "")
  SET(GAIT_MODULE_PATH "./gait/cmake")

  SET (GAIT_FOUND TRUE)
ENDIF (NOT GAIT_FOUND)

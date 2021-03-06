
##cmake code start
project(gaitcontrol)
cmake_minimum_required(VERSION 2.8.11)


aux_source_directory(app SRC_LIST)
aux_source_directory(test SRC_LIST)
aux_source_directory(examples SRC_LIST)


# Pick up our cmake modules - they are all in the cmake subdirectory
set(TEMPLATE_NAME_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
# let cmake use them
list(APPEND CMAKE_MODULE_PATH ${TEMPLATE_NAME_MODULE_PATH})

#libraries
set(SRC_LIB_DIR ${CMAKE_SOURCE_DIR}/lib)

#interface kinematics
add_subdirectory(${SRC_LIB_DIR}/i-kinematics)


#gait
FIND_PACKAGE(ROBOTICSLAB_GAIT QUIET)
if(ROBOTICSLAB_GAIT_FOUND)
    message(STATUS "Gait library found.")
else()
    #Use the source code if not installed
    add_subdirectory(${PROJECT_SOURCE_DIR}/lib/gait)
endif()

#teo MiddleWareInterface
message(STATUS "compiling teo MiddleWareInterface form sources")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/teoMWI)
set(teoMWI_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/teoMWI ${teoMWI_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${teoMWI_INCLUDE_DIR})

#Sensor Integration
message(STATUS "compiling SensorIntegration form sources")
add_subdirectory(${PROJECT_SOURCE_DIR}/lib/sensor-integration)
set(SensorIntegration_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/lib/sensor-integration ${SensorIntegration_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${SensorIntegration_INCLUDE_DIR})

foreach( testsourcefile ${SRC_LIST} )
    # I used a simple string replace, to cut off .cpp.
    string( REGEX REPLACE "[A-z]+[/]" "" testname ${testsourcefile} )
    string( REPLACE ".cpp" "" testname ${testname} )

    add_executable( ${testname} ${testsourcefile} )
    message ("Including executable: " ${testname})
    # Make sure YourLib is linked to each app
    target_link_libraries( ${testname} ROBOTICSLAB::Gait teoMWI SensorIntegration ${SUBDIR_LINK_NAMES} )
endforeach( testsourcefile ${APP_SOURCES} )

INCLUDE_DIRECTORIES(${SUBDIR_INCLUDE_DIRECTORIES})

#add_executable(${PROJECT_NAME} ${SRC_LIST})
#link with libs
#target_link_libraries( ${PROJECT_NAME} ROBOTICSLAB::gait teoMWI SensorIntegration)


##functions
function(echo_all_cmake_variable_values)
  message(STATUS "")
  get_cmake_property(vs VARIABLES)
  foreach(v ${vs})
    message(STATUS "${v}='${${v}}'")
  endforeach(v)
  message(STATUS "")
endfunction()



echo_all_cmake_variable_values()



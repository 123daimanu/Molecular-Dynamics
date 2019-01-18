# Top level cmake script for HardSphere.
project(HardSphere CXX)
cmake_minimum_required(VERSION 2.8.11)

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

IF(WIN32)
   ADD_DEFINITIONS(/D_CRT_SECURE_NO_WARNINGS)
ENDIF(WIN32)


include(CheckCXXCompilerFlag)
include(CheckIncludeFileCXX)
include(CheckCXXSymbolExists)

if ( CMAKE_COMPILER_IS_GNUCXX )
    add_definitions("-Wall")
endif ( CMAKE_COMPILER_IS_GNUCXX )
if ( MSVC )
    add_definitions("/W3 /DNOMINMAX")
endif ( MSVC )



# ---------- Setup output Directories -------------------------
SET (CMAKE_LIBRARY_OUTPUT_DIRECTORY
  ${PROJECT_BINARY_DIR}/lib
  CACHE PATH
  "Single directory for all shared libraries"
  )
# --------- Setup the Executable output Directory -------------
SET (CMAKE_RUNTIME_OUTPUT_DIRECTORY
  ${PROJECT_BINARY_DIR}/bin
  CACHE PATH
  "Single directory for all Executables."
  )
# --------- Setup the static library directory -------------
SET (CMAKE_ARCHIVE_OUTPUT_DIRECTORY
  ${PROJECT_BINARY_DIR}/lib
  CACHE PATH
  "Single directory for all static libraries."
  )

#Add executables for build
set (run)

set(SOURCE
src/maths/Vector3.cpp
src/sim/initialize.cpp
src/sim/atom.cpp
src/sim/simulation.cpp
run/md.cpp
)



add_executable(run ${SOURCE})

#INSTALL(TARGETS run)

message( STATUS)
message( STATUS "========== HardSphere Build Information ==========")
message( STATUS "CMAKE_SYSTEM ............... = ${CMAKE_SYSTEM}")
message( STATUS "==============================================")
message( STATUS "CMAKE_BUILD_TYPE ........... = ${CMAKE_BUILD_TYPE}")
message( STATUS "CMAKE_INSTALL_PREFIX ....... = ${CMAKE_INSTALL_PREFIX}")
message( STATUS "Build as SINGLE_PRECISION .. = ${SINGLE_PRECISION}")
message( STATUS "CMAKE_CXX_COMPILER ......... = ${CMAKE_CXX_COMPILER}")
message( STATUS )
message( STATUS "To build and install HardSphere, enter \"make\" and \"make install\"")
message( STATUS )

# build a CPack driven installer package

include (CPack)

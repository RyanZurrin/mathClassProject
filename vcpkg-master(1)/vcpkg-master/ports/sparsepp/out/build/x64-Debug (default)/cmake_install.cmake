# Install script for directory: E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp/out/install/x64-Debug (default)")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/sparsepp" TYPE FILE FILES
    "E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp/sparsepp/spp.h"
    "E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp/sparsepp/spp_config.h"
    "E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp/sparsepp/spp_dlalloc.h"
    "E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp/sparsepp/spp_memory.h"
    "E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp/sparsepp/spp_smartptr.h"
    "E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp/sparsepp/spp_stdint.h"
    "E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp/sparsepp/spp_timer.h"
    "E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp/sparsepp/spp_traits.h"
    "E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp/sparsepp/spp_utils.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "E:/cppTESTing/finalProgram/mathClassProject/mathClassProject/retry/mathClassProject/mathClassProject/vcpkg-master(1)/vcpkg-master/ports/sparsepp/out/build/x64-Debug (default)/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")

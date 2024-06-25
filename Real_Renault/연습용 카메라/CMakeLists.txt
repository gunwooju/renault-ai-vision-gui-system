cmake_minimum_required(VERSION 3.14)
cmake_policy(SET CMP0074 NEW)    # respect <PACKAGE>_ROOT variables in "find_package"
include(CMakePrintHelpers)

project(PylonSamples VERSION 0.0)
find_package(pylon)

add_executable( BaslerCameraSample
  BaslerCameraSample.cpp
  BaslerCameraCameraParams.cpp
  BaslerCameraEventParams.cpp
  BaslerCameraChunkDataParams.cpp
  BaslerCameraTLParams.cpp
  BaslerCameraStreamParams.cpp
)
target_link_libraries( BaslerCameraSample PRIVATE pylon::pylon )
install( TARGETS BaslerCameraSample )
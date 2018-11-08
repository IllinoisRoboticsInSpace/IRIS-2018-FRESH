cmake_minimum_required(VERSION 2.8)
project( OpticalFlow)
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )
add_executable( opticalflow src/kanade.cpp ) #Add more files once you create more files
target_link_libraries( opticalflow ${OpenCV_LIBS} )

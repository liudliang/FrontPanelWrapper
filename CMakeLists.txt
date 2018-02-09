cmake_minimum_required(VERSION 3.9)
project(FrontPanelWrapper)

set(CMAKE_CXX_STANDARD 11)

# Add soruces and headers to appropriate CMAKE paths
set(SOURCES FrontPanelWrapper.cpp)
set(HEADERS FrontPanelWrapper.h)

# Add OpalKelly FrontPanel headers and shared libraries to appropriate CMAKE paths
include_directories(FrontPanel/ubuntu16.04/API)
LINK_DIRECTORIES(FrontPanel/ubuntu16.04/API)

# Create FrontPanelBroker library
# add_library(FrontPanelWrapper SHARED)

# Create an execuatable to test FrontPanelBroker
include_directories(${HEADERS})
add_executable(FrontPanelWrapper testMain.cpp ${SOURCES})
TARGET_LINK_LIBRARIES(FrontPanelWrapper libokFrontPanel.so)
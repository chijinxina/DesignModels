cmake_minimum_required(VERSION 3.8.2)
project(DesignModels)

set(CMAKE_CXX_STANDARD 11)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake_modules)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
#set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
#####################dependenicecs##########################
set(THIRD_PARTY_LIBS
        )

include_directories(${PROJECT_SOURCE_DIR}/include)
####################source and test#########################
add_subdirectory(src)

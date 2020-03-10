cmake_minimum_required(VERSION 3.7)
set(PROJECT_NAME CLionSFML)

project(${PROJECT_NAME})
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -static")

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Bob.cpp Bob.h Engine.cpp Engine.h Input.cpp Update.cpp Draw.cpp FallingObject.cpp FallingObject.h Stone.cpp Stone.h)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

set(SFML_ROOT C:/Libraries/SFML)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML 2 REQUIRED COMPONENTS audio graphics window system)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif ()
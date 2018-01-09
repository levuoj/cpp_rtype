cmake_minimum_required(VERSION 2.6)
project(cpp_rtype)

set(cpp_rtype_VERSION_MAJOR 1)
set(cpp_rtype_VERSION_MINOR 0)

if (NOT WIN32)                                                                                          
set (CMAKE_CXX_FLAGS "-Wall -Wextra")
endif (NOT WIN32)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)

set(SERVER_SOURCE_FILES sources/server/main.cpp
                        sources/server/AManager.cpp
                        sources/server/Mediator.cpp
                        sources/server/ASystem.cpp
                        sources/server/AEntity.cpp
                        sources/server/ETPlayer.cpp)

set(CLIENT_SOURCE_FILES sources/client/main.cpp
                        sources/client/AManager.cpp
                        sources/client/Mediator.cpp)

set(UTILS_SOURCE_FILES sources/utils/Loader.cpp)

set(LIBTEST_SOURCE_FILES sources/external_things/Test/Test.cpp)

FILE (GLOB SERVER_INCLUDE_DIR includes/server/*.hpp)
FILE (GLOB CLIENT_INCLUDE_DIR includes/client/*.hpp)
FILE (GLOB LIBTEST_INCLUDE_DIR includes/external_things/Test/*.hpp)
FILE (GLOB UTILS_INCLUDE_DIR includes/utils/*.hpp)

include_directories("includes")

add_library(Test SHARED ${LIBTEST_INCLUDE_DIR} ${LIBTEST_SOURCE_FILES})

add_executable(rtype_server ${SERVER_INCLUDE_DIR} ${SERVER_SOURCE_FILES} ${UTILS_SOURCE_FILES})
target_link_libraries(rtype_server ${CMAKE_DL_LIBS})

add_executable(rtype_client ${CLIENT_INCLUDE_DIR} ${CLIENT_SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(rtype_client ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

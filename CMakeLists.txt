cmake_minimum_required(VERSION 2.6)
project(cpp_rtype)

set(cpp_rtype_VERSION_MAJOR 1)
set(cpp_rtype_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 17)

set(SERVER_SOURCE_FILES sources/server/main.cpp
                        sources/server/AManager.cpp
                        sources/server/Mediator.cpp)

set(CLIENT_SOURCE_FILES sources/client/main.cpp
                        sources/client/AManager.cpp
                        sources/client/Mediator.cpp)

FILE (GLOB SERVER_INCLUDE_DIR includes/server/*.hpp)
FILE (GLOB CLIENT_INCLUDE_DIR includes/client/*.hpp)
INCLUDE_DIRECTORIES("includes")

add_executable(rtype_server ${SERVER_INCLUDE_DIR} ${SERVER_SOURCE_FILES})

add_executable(rtype_client ${CLIENT_INCLUDE_DIR} ${CLIENT_SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(rtype_client ${SFML_LIBRARIES})
endif()

target_link_libraries(rtype_client ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
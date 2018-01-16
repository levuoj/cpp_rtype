cmake_minimum_required(VERSION 2.6)
project(cpp_rtype)

set(cpp_rtype_VERSION_MAJOR 1)
set(cpp_rtype_VERSION_MINOR 0)

if (NOT WIN32)                                                                                          
set (CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -g3")
endif (NOT WIN32)

## BOOST
SET(Boost_USE_STATIC_LIBS OFF)
SET(Boost_USE_MULTITHREADED ON)
SET(Boost_USE_STATIC_RUNTIME OFF)

# QT COMPILATION

set(CMAKE_PREFIX_PATH ~/Qt5.10.0/5.10.0/gcc_64)

find_package(Qt5 COMPONENTS Core Network REQUIRED)

set(CMAKE_AUTOMOC ON)

# END OF QT COMPILATION

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib/")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

set(SERVER_SOURCE_FILES sources/server/main.cpp
			            sources/server/AManager.cpp
			            sources/server/Mediator.cpp
                        sources/server/UdpServer.cpp
                        sources/server/ASystem.cpp
			            sources/server/AEntity.cpp
			            sources/server/FFEngine.cpp
                        sources/server/GameSession.cpp
                        sources/server/Systems/SMovement.cpp
                        sources/server/Components/CPosition.cpp
                        sources/server/Components/CVelocity.cpp
                        sources/server/Components/CShield.cpp
                        sources/server/Components/CScore.cpp
                        sources/server/Components/CDisplay.cpp
                        sources/server/Components/CSound.cpp
                        sources/server/Components/CMusic.cpp
                        sources/server/Components/CHealth.cpp
                        sources/server/Components/CExplosion.cpp
                        sources/server/Components/CArtificialIntelligence.cpp)

set(CLIENT_SOURCE_FILES sources/client/main.cpp
                        sources/client/AManager.cpp
                        sources/client/Mediator.cpp
                        sources/client/Graphic/SfmlWindow.cpp
                        sources/client/Graphic/GraphicManager.cpp
                        sources/client/Graphic/ManageKeySFML.cpp
                        sources/client/Graphic/Observable.cpp
                        sources/client/Graphic/ObservableKey.cpp
                        sources/client/Graphic/AnimatedSprite.cpp
                        sources/client/Mediator.cpp
                        sources/client/Udp/UdpSocket.cpp
                        sources/client/Udp/UdpManager.cpp)

set(UTILS_SOURCE_FILES sources/utils/Loader.cpp)

set(ETPLAYER_SOURCE_FILES sources/shared_libraries/entities/ETPlayer.cpp)
set(ETMONSTER_SOURCE_FILES sources/shared_libraries/entities/ETMonster.cpp)

FILE (GLOB SERVER_INCLUDE_DIR includes/server/*.hpp)

FILE (GLOB CLIENT_INCLUDE_DIR   includes/client/*.hpp
                                includes/client/Udp/*.hpp
                                includes/client/Graphic/*.hpp)

FILE (GLOB SERVER_COMPONENT_DIR includes/server/Components/*.hpp)
FILE (GLOB SERVER_ENTITIES_INCLUDE_DIR includes/shared_libraries/entities/*.hpp)
FILE (GLOB SERVER_COMPONENTS_INCLUDE_DIR includes/server/Components/*.hpp)
FILE (GLOB SERVER_SYSTEMS_INCLUDE_DIR includes/server/Systems/*.hpp)

FILE (GLOB ETPLAYER_INCLUDE_DIR includes/shared_libraries/entities/ETPlayer.hpp)
FILE (GLOB ETMONSTER_INCLUDE_DIR includes/shared_libraries/entities/ETMonster.hpp)
FILE (GLOB UTILS_INCLUDE_DIR includes/utils/*.hpp)

include_directories("includes")

add_library(ETPlayer SHARED ${ETPLAYER_INCLUDE_DIR} ${SERVER_INCLUDE_DIR} ${ETPLAYER_SOURCE_FILES})
add_library(ETMonster SHARED ${ETMONSTER_INCLUDE_DIR} ${SERVER_INCLUDE_DIR} ${ETMONSTER_SOURCE_FILES})

add_executable(rtype_server ${SERVER_INCLUDE_DIR}
			    			${SERVER_ENTITIES_INCLUDE_DIR}
			    			${SERVER_COMPONENTS_INCLUDE_DIR}
			    			${SERVER_SYSTEMS_INCLUDE_DIR}
			    			${SERVER_SOURCE_FILES}
			    			${UTILS_SOURCE_FILES}
                            ${UTILS_INCLUDE_DIR})

target_link_libraries(rtype_server ${CMAKE_DL_LIBS})

add_executable(rtype_client ${CLIENT_INCLUDE_DIR}
                            ${CLIENT_SOURCE_FILES}
                            ${UTILS_SOURCE_FILES}
                            ${UTILS_INCLUDE_DIR})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(rtype_client ${SFML_LIBRARIES} ${SFML_DEPENDENCIES} Qt5::Core Qt5::Network)
endif()

## BOOST LIB MODULES
if (UNIX AND NOT APPLE)
   FIND_PACKAGE(Boost COMPONENTS system filesystem)
   TARGET_LINK_LIBRARIES(rtype_server ${Boost_LIBRARIES})
endif ()
cmake_minimum_required(VERSION 2.6)
project(cpp_rtype)

set(cpp_rtype_VERSION_MAJOR 1)
set(cpp_rtype_VERSION_MINOR 0)

if (NOT WIN32)                                                                                          
set (CMAKE_CXX_FLAGS "-W -Wall -Wextra -Werror -g3")
endif (NOT WIN32)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/bin)

set(SERVER_SOURCE_FILES sources/server/main.cpp
		sources/server/AManager.cpp
        sources/server/Mediator.cpp
        sources/server/ASystem.cpp
        sources/server/AMap.cpp
        sources/server/AEntity.cpp
        sources/server/FFEngine.cpp
        sources/server/GameSession.cpp
		sources/server/ActionManager.cpp
		sources/server/EventManager.cpp
        sources/server/Systems/SMovement.cpp
        sources/server/Systems/SSpawn.cpp
        sources/server/Components/CPosition.cpp
        sources/server/Components/CVelocity.cpp
        sources/server/Components/CShield.cpp
        sources/server/Components/CScore.cpp
        sources/server/Components/CDisplay.cpp
        sources/server/Components/CSound.cpp
        sources/server/Components/CMusic.cpp
        sources/server/Components/CHealth.cpp
        sources/server/Components/CExplosion.cpp
        sources/server/Components/CArtificialIntelligence.cpp
		sources/server/Systems/SShoot.cpp)

set(CLIENT_SOURCE_FILES sources/client/main.cpp
                        sources/client/AManager.cpp
                        sources/client/Mediator.cpp)

set(UTILS_SOURCE_FILES sources/utils/Loader.cpp sources/utils/Error.cpp sources/server/Systems/SSpawn.cpp)

set(ETPlayer1_SOURCE_FILES sources/shared_libraries/entities/ETPlayer1.cpp)
set(ETPlayer2_SOURCE_FILES sources/shared_libraries/entities/ETPlayer2.cpp)
set(ETPlayer3_SOURCE_FILES sources/shared_libraries/entities/ETPlayer3.cpp)
set(ETPlayer4_SOURCE_FILES sources/shared_libraries/entities/ETPlayer4.cpp)
set(ETBASICMONSTER_SOURCE_FILES sources/shared_libraries/entities/ETBasicMonster.cpp)
set(ETLEVEL1_SOURCE_FILES sources/shared_libraries/entities/ETLevel1.cpp)
set(ETPLAYERMISSILE_SOURCE_FILES sources/shared_libraries/entities/ETPlayerMissile.cpp)
set(ETBASICOBSTACLE_SOURCE_FILES sources/shared_libraries/entities/ETBasicObstacle.cpp)

FILE (GLOB SERVER_INCLUDE_DIR includes/server/*.hpp)
FILE (GLOB SERVER_ENTITIES_INCLUDE_DIR includes/shared_libraries/entities/*.hpp)
FILE (GLOB SERVER_COMPONENTS_INCLUDE_DIR includes/server/Components/*.hpp)
FILE (GLOB SERVER_SYSTEMS_INCLUDE_DIR includes/server/Systems/*.hpp)

FILE (GLOB ETPlayer1_INCLUDE_DIR includes/shared_libraries/entities/ETPlayer1.hpp)
FILE (GLOB ETPlayer2_INCLUDE_DIR includes/shared_libraries/entities/ETPlayer2.hpp)
FILE (GLOB ETPlayer3_INCLUDE_DIR includes/shared_libraries/entities/ETPlayer3.hpp)
FILE (GLOB ETPlayer4_INCLUDE_DIR includes/shared_libraries/entities/ETPlayer4.hpp)
FILE (GLOB ETBASICMONSTER_INCLUDE_DIR includes/shared_libraries/entities/ETBasicMonster.hpp)
FILE (GLOB ETLEVEL1_INCLUDE_DIR include/shared_libraries/entities/ETLevel1.hpp)
FILE (GLOB ETPLAYERMISSILE_INCLUDE_DIR includes/shared_libraries/entities/ETPlayerMissile.hpp)
FILE (GLOB ETBASICOBSTACLE_INCLUDE_DIR includes/shared_libraries/entities/ETBasicObstacle.hpp)

FILE (GLOB UTILS_INCLUDE_DIR includes/utils/*.hpp)

include_directories("includes")

add_library(ETPlayer1 SHARED ${ETPlayer1_INCLUDE_DIR} ${SERVER_INCLUDE_DIR} ${ETPlayer1_SOURCE_FILES})
add_library(ETPlayer2 SHARED ${ETPlayer2_INCLUDE_DIR} ${SERVER_INCLUDE_DIR} ${ETPlayer2_SOURCE_FILES})
add_library(ETPlayer3 SHARED ${ETPlayer3_INCLUDE_DIR} ${SERVER_INCLUDE_DIR} ${ETPlayer3_SOURCE_FILES})
add_library(ETPlayer4 SHARED ${ETPlayer4_INCLUDE_DIR} ${SERVER_INCLUDE_DIR} ${ETPlayer4_SOURCE_FILES})
add_library(ETBasicMonster SHARED ${ETBASICMONSTER_INCLUDE_DIR} ${SERVER_INCLUDE_DIR} ${ETBASICMONSTER_SOURCE_FILES})
add_library(ETLevel1 SHARED ${ETLEVEL1_INCLUDE_DIR} ${SERVER_INCLUDE_DIR} ${ETLEVEL1_SOURCE_FILES})
add_library(ETPlayerMissile SHARED ${ETPLAYERMISSILE_INCLUDE_DIR} ${SERVER_INCLUDE_DIR} ${ETPLAYERMISSILE_SOURCE_FILES})
add_library(ETBasicObstacle SHARED ${ETBASICOBSTACLE_INCLUDE_DIR} ${SERVER_INCLUDE_DIR} ${ETBASICOBSTACLE_SOURCE_FILES})

add_executable(rtype_server ${SERVER_INCLUDE_DIR}
			    			${SERVER_ENTITIES_INCLUDE_DIR}
			    			${SERVER_COMPONENTS_INCLUDE_DIR}
			    			${SERVER_SYSTEMS_INCLUDE_DIR}
			    			${SERVER_SOURCE_FILES}
			    			${UTILS_SOURCE_FILES})
			    
target_link_libraries(rtype_server ${CMAKE_DL_LIBS})

add_executable(rtype_client ${CLIENT_INCLUDE_DIR} ${CLIENT_SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system window graphics network audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(rtype_client ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

project(clepsydrad)
cmake_minimum_required(VERSION 2.8)

#-----------
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
#-----------

SET(SRC_LIST
    main.c
    config.h
    readconf.c
    pamcheck.c
    c_socket.h
)

if(NOT NO_PAM)
    find_package(PAM REQUIRED)
    if(PAM_FOUND)
        add_definitions(-DUSE_PAM)
    endif()
endif()

find_library(JSON_LIBRARY NAMES json-c2)

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(LIBS ${LIBS} ${PAM_LIBRARIES})

target_link_libraries(${PROJECT_NAME} ${JSON_LIBRARIES} ${PAM_LIBRARIES})




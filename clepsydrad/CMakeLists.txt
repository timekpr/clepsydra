project(clepsydrad)
cmake_minimum_required(VERSION 2.8)

#-----------
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
#-----------

# Set version
set(CLEPSYDRAD_VERSION_MAJOR 0)
set(CLEPSYDRAD_VERSION_MINOR 1)
set(CLEPSYDRAD_VERSION_PATCH 0)
set(CLEPSYDRAD_VERSION_STRING "${CLEPSYDRAD_VERSION_MAJOR}.${CLEPSYDRAD_VERSION_MINOR}.${CLEPSYDRAD_VERSION_PATCH}")

SET(SRC_LIST
    main.c
    config.h
    readconf.c
    pamcheck.c
    c_socket.h
)

if(NOT NO_PAM)
    MESSAGE(STATUS "PAM LIB REQUIRED ")
    find_package(PAM REQUIRED)
    if(PAM_FOUND)
        add_definitions(-DUSE_PAM)
    endif()
endif()

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(LIBS ${LIBS} ${PAM_LIBRARIES})
set(LIBS ${LIBS})

target_link_libraries(${PROJECT_NAME} ${PAM_LIBRARIES})
target_link_libraries(${PROJECT_NAME})


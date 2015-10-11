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

if (NOT NO_JSON)
   #find_package(JSON REQUIRED)
   if(JSON_FOUND)
       add_definitions(-DUSE_JSON)
   endif()
endif()          

add_executable(${PROJECT_NAME} ${SRC_LIST})

set(LIBS ${LIBS} ${PAM_LIBRARIES} ${JSON_LIBRARY})
set(LIBS ${LIBS})

target_link_libraries(${PROJECT_NAME} ${JSON_LIBRARY} ${PAM_LIBRARIES})
target_link_libraries(${PROJECT_NAME})




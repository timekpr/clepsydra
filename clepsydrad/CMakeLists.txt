project(clepsydrad)
cmake_minimum_required(VERSION 2.8)

SET(SRC_LIST
    main.c
    config.h
    readconf.c
    c_socket.h
)

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(json-c2 ${LIBS})

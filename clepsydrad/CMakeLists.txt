project(clepsydrad)
cmake_minimum_required(VERSION 2.8)

SET(SRC_LIST
    main.c
    config.h
    readconf.c
    pamcheck.c
    c_socket.h
)

find_path(PAM0G_INCLUDE_DIR NAMES security/pam_appl.h security/pam_misc.h)

find_library(JSON_LIBRARY NAMES json-c2)
find_library(PAM0G_LIBRARY NAMES pam0g)

include_directories(${PAM0G_INCLUDE_DIR})
add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} ${JSON_LIBRARIES} ${PAM0G_LIBRARIES})




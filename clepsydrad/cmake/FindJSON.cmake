if (JSON_INCLUDE_DIR AND JSON_LIBRARY)
    # Already in cache, be silent
    set(JSON_FIND_QUIETLY FALSE)
endif (JSON_INCLUDE_DIR AND JSON_LIBRARY)

find_path(JSON_INCLUDE_DIR NAMES json-c/json.h json-c/json-object.h)
find_library(JSON_LIBRARY json-c)

if (JSON_INCLUDE_DIR AND JSON_LIBRARY)
    set(JSON_FOUND TRUE)
    set(JSON_LIBRARIES ${JSON_LIBRARY})
endif (JSON_INCLUDE_DIR AND JSON_LIBRARY)

if (JSON_FOUND)
    if (NOT JSON_FIND_QUIETLY)
        message(STATUS "Found JSON: ${JSON_LIBRARY}")
    endif (NOT JSON_FIND_QUIETLY)
else (JSON_FOUND)
    if (JSON_FIND_REQUIRED)
        message(FATAL_ERROR "JSON was not found :${JSON_LIBRARY}")
    endif(JSON_FIND_REQUIRED)
endif (JSON_FOUND)

mark_as_advanced(JSON_INCLUDE_DIR JSON_LIBRARIES)


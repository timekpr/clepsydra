if (PAM_INCLUDE_DIR AND PAM_LIBRARY)
    # Already in cache, be silent
    set(PAM_FIND_QUIETLY FALSE)
endif (PAM_INCLUDE_DIR AND PAM_LIBRARY)

find_path(PAM_INCLUDE_DIR NAMES security/pam_appl.h security/pam_misc.h)
find_library(PAM_LIBRARY pam)
find_library(PAM_MISC_LIBRARY pam_misc)

if (PAM_INCLUDE_DIR AND PAM_LIBRARIES)
    set(PAM_FOUND TRUE)
    set(PAM_LIBRARIES ${PAM_LIBRARY} ${PAM_MISC_LIBRARY})
endif (PAM_INCLUDE_DIR AND PAM_LIBRARIES)

if (PAM_FOUND)
    if (NOT PAM_FIND_QUIETLY)
        message(STATUS "Found PAM: ${PAM_LIBRARIES}")
    endif (NOT PAM_FIND_QUIETLY)
else (PAM_FOUND)
    if (PAM_FIND_REQUIRED)
        message(FATAL_ERROR "PAM was not found")
    endif(PAM_FIND_REQUIRED)
endif (PAM_FOUND)

mark_as_advanced(PAM_INCLUDE_DIR PAM_LIBRARIES)


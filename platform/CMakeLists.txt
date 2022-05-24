if(CMAKE_HOST_WIN32)
    add_subdirectory(windows)
endif()

if(CMAKE_HOST_UNIX)
    add_subdirectory(linux)
endif()

add_executable(hello_engine hello_engine_win.c)

set_target_properties(hello_engine PROPERTIES WIN32_EXECUTABLE TRUE)
target_link_libraries(hello_engine user32.lib)
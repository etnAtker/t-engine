add_executable(hello_engine_win hello_engine_win.c)

set_target_properties(hello_engine_win PROPERTIES WIN32_EXECUTABLE TRUE)
target_link_libraries(hello_engine_win user32 gdi32)
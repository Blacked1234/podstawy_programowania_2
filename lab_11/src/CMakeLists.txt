add_executable (lab_11 main.cpp)

add_custom_target(run_lab_11 DEPENDS lab_11
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_11
)

add_custom_target(valgrind_lab_11 DEPENDS lab_11
    COMMAND
        valgrind --leak-check=full ${CMAKE_CURRENT_BINARY_DIR}/lab_11
)
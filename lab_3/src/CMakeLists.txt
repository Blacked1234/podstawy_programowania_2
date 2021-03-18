add_executable (lab_3 main.cpp)

add_custom_target(run_lab_1 DEPENDS lab_3
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_3
)

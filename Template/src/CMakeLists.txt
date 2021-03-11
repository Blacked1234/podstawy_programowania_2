add_executable (lab_2 main.cpp)

add_custom_target(run_lab_2 DEPENDS lab_1
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_2
)

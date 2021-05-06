add_executable (lab_8 main.cpp)

add_custom_target(run_lab_8 DEPENDS lab_8
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_8
)

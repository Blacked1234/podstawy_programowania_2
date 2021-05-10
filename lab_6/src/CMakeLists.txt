add_executable (lab_6 main.cpp)

add_custom_target(run_lab_6 DEPENDS lab_6
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_6
)

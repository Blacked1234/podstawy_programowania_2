add_executable (lab_5 main.cpp)

add_custom_target(run_lab_5 DEPENDS lab_5
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_5
)

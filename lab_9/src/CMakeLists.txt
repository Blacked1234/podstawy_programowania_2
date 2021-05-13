add_executable (lab_9 main.cpp)

add_custom_target(run_lab_9 DEPENDS lab_9
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_9
)

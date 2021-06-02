add_executable (lab_7 main.cpp)

add_custom_target(run_lab_7 DEPENDS lab_7
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/lab_7
)

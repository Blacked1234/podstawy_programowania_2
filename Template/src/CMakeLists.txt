add_executable (template main.cpp)

add_custom_target(run_template DEPENDS lab_1
    COMMAND
        ${CMAKE_CURRENT_BINARY_DIR}/template
)

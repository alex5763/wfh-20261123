add_library(utils STATIC
    cli_parse.cpp
    cli_parse.h
)

target_include_directories(utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

cmake_minimum_required(VERSION 3.28)
project(ChatApp)

# Adding static library for shared functions
add_subdirectory(lib) 

# Adding the client and server src files 
add_subdirectory(src/client)
add_subdirectory(src/server)

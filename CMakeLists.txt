cmake_minimum_required(VERSION 3.5) # minimal cmake version
project(controllers) #project name

# c/c++ version
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# compiler options
add_compile_options(-Wall -Wextra -Wpedantic -O2 -lpthread)

# include directories
include_directories(include)

# subdirectories
add_subdirectory(src)
enable_testing()
add_subdirectory(tests)

# install
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin 
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        INCLUDES DESTINATION include
)

install(DIRECTORY include/
        DESTINATION include
        FILES_MATCHING
        PATTERN "*.h"
        PATTERN "*.hpp"
)
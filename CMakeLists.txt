# Verify cmake version
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

# Create project
project (
    "TP1_TuxLab"
    VERSION 1.0.0
    DESCRIPTION "A simple project"
    LANGUAGES C

)

# Enable testing
include(CTest)
enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# Flags for compiling
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_FLAGS_DEBUG "-g -O0 -Wall -Wpedantic -Wextra -Wconversion -Wunused-parameter -Wmissing-prototypes -Wstrict-prototypes")


# Include headers
include_directories(include)

# Find dependencies no se que tan bien funciona esto
find_package(cJSON CONFIG REQUIRED)
find_package(unity CONFIG REQUIRED)

# add_executable --> .exe/binary
# add_library --> .a/ .so/.dll STATIC/SHARED
add_executable(${PROJECT_NAME} 
            src/main.c
            src/profile.c
            )

# Link libraries
target_link_libraries(${PROJECT_NAME} PRIVATE cjson::cjson)


# opcion para activar coverage
option(RUN_COVERAGE "Build tests with coverage instrumentation" OFF)

if(RUN_COVERAGE EQUAL 1)
    add_subdirectory(tests)
endif()


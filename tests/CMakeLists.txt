cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

include_directories(${CMAKE_SOURCE_DIR}/include)

#Ejecutable de test con unity
add_executable(test_profile
            test_profile.c
            ${CMAKE_SOURCE_DIR}/src/profile.c
            )


# Dónde se genera el ejecutable de test
set_target_properties(test_profile PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${TEST_OUTPUT_DIR}"
)

# Includes (los mismos que el proyecto)
target_include_directories(test_profile PRIVATE
    ${CMAKE_SOURCE_DIR}/include
)

target_link_libraries(test_profile PRIVATE unity::unity cjson::cjson) # de esta forma unity solo esta en test

# ---- FLAGS DE COVERAGE (versión target-specific, recomendada) ----
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(test_profile PRIVATE
        -g
        -fprofile-arcs
        -ftest-coverage
    )

    target_link_options(test_profile PRIVATE
        -fprofile-arcs
        -ftest-coverage
        --coverage
    )
endif()

# Registrar el test en CTest
add_test(
    NAME test_profile
    COMMAND test_profile
)


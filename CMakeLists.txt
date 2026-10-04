cmake_minimum_required(VERSION 3.16)
project(arraylib VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Динамическая библиотека
add_library(arraylib SHARED src/arraylib.cpp)
target_include_directories(arraylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_definitions(arraylib PRIVATE ARRAYLIB_BUILD)

if(MSVC)
    target_compile_options(arraylib PRIVATE /W4)
else()
    target_compile_options(arraylib PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Приложение app (использует библиотеку)
add_executable(app main.cpp)
target_link_libraries(app PRIVATE arraylib)
set_target_properties(app PROPERTIES BUILD_RPATH "$ORIGIN")

# Папка для всех артефактов сборки
set_target_properties(arraylib app PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
)

# --- ТЕСТЫ ---
include(CTest)
enable_testing()

if(BUILD_TESTING)
    add_executable(test_unit tests/test_unit.cpp)
    target_link_libraries(test_unit PRIVATE arraylib)
    add_test(NAME UnitTests COMMAND test_unit)

    add_executable(test_integration tests/test_integration.cpp)
    target_link_libraries(test_integration PRIVATE arraylib)
    add_test(NAME IntegrationTests COMMAND test_integration)
    add_executable(variant8 examples/variant_08.cpp)
    target_link_libraries(variant8 PRIVATE arraylib)

endif()

cmake_minimum_required(VERSION 3.16)

project(MyCalculator VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Place the final executable in a separate bin folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find Qt6 components
find_package(Qt6 REQUIRED COMPONENTS Widgets Network)

# Source files
set(SOURCES
    src/main.cpp
    src/CalculatorWindow.cpp
    src/CalculatorWindow.h
)

# Resources
set(RESOURCES resources.qrc)

# For Windows icon (optional but good practice)
if(WIN32)
    # Using CMake's ability to compile resources on Windows
    # Assuming we might want to add a win32.rc later. For now, QIcon is enough.
    add_executable(MyCalculator WIN32 ${SOURCES} ${RESOURCES})
else()
    add_executable(MyCalculator ${SOURCES} ${RESOURCES})
endif()

target_link_libraries(MyCalculator PRIVATE Qt6::Widgets Qt6::Network)

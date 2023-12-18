# CMakeList.txt: проект CMake для lab_2 c++; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("lab_2 c++")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeTarget "lab_2 c++.cpp" "lab_2 c++.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeTarget PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.

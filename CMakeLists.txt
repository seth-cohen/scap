cmake_minimum_required(VERSION 3.1.0)

project(SwatchScanner)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
set (CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/5.12.-1")
find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Find GPhoto2
set(CMAKE_MODULE_PATH "~/cmake")
find_package(GPhoto2 REQUIRED MODULE)

# Populate a CMake variable with the sources
set(SOURCES
  mainwindow.ui
  mainwindow.cpp
  main.cpp
  camera_container.cpp
  )

# Tell CMake to create the helloworld executable
add_executable(SwatchScanner ${SOURCES})
target_link_libraries(SwatchScanner
  PUBLIC
    GPhoto2::GPhoto2
    Qt5::Widgets
  )


get_cmake_property(_variableNames VARIABLES)
list (SORT _variableNames)
foreach (_variableName ${_variableNames})
  message(STATUS "${_variableName}=${${_variableName}}")
endforeach()


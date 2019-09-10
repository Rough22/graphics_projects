cmake_minimum_required(VERSION 3.14)
project(CircleDrawing)

set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES main.cpp)
set(CMAKE_PREFIX_PATH "C:/freeglut")

set(FREEGLUT_INCLUDE_DIRS "C:/freeglut/include")
set(FREEGLUT_LIBRARY_DIRS "C:/freeglut/lib/x64")

set(FREEGLUT_LIBRARIES freeglut)
set(OpenGL_LIBRARIES glu32 opengl32)

include_directories(${FREEGLUT_INCLUDE_DIRS})
link_directories(${FREEGLUT_LIBRARY_DIRS})

add_executable(CircleDrawing ${SOURCE_FILES})
target_link_libraries(CircleDrawing ${FREEGLUT_LIBRARIES} ${OpenGL_LIBRARIES})
cmake_minimum_required(VERSION 3.5.0)
project(glewext 
        VERSION 0.1.0 
        LANGUAGES C CXX
)

find_package(GLEW REQUIRED)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

set(SOURCES
    src/glewextlib.cpp
    src/Shader.cpp
    src/exception.cpp
    src/Texture.cpp
)
    
add_library(${PROJECT_NAME} STATIC ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 23 CXX_STANDARD_REQUIRED On)

target_link_libraries(${PROJECT_NAME} 
    GLEW
    OpenGL
)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
    
export(TARGETS ${PROJECT_NAME} FILE ${CMAKE_BINARY_DIR}/${PROJECT_NAME}.cmake)
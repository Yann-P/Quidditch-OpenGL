cmake_minimum_required(VERSION 2.6)

project(CGILabs)
enable_testing()

###  Settings  ###{{{
set(CMAKE_CXX_FLAGS "-std=c++11 -W -Wno-unused-variable -g -DGL_GLEXT_PROTOTYPES -I/opt/X11/include") # Don't forget to define GL_GLEXT_PROTOTYPES to ensure that the glCreateShader and other prototypes are declared. Note we could do it in the main file via "#define GL_GLEXT_PROTOTYPES" before "#include <GL/glext.h>"
## setting build type to debug
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_BUILD_TYPE DEBUG)
LINK_DIRECTORIES("~/local_install/lib")
LINK_DIRECTORIES("/usr/local/lib")
INCLUDE_DIRECTORIES("/usr/local/include")
INCLUDE_DIRECTORIES("~/local_install/include")
###  Settings  ###}}}i

###  OpenGL  ###{{{
find_package(OpenGL)
if (OPENGL_FOUND)
   include_directories(${OPENGL_INCLUDE_DIR})
else (OPENGL_FOUND)
    message("OpenGL environment missing")
endif (OPENGL_FOUND)
set(GL_LIBRARIES ${OPENGL_LIBRARIES} GLEW)
if(APPLE)
 set(CMAKE_CXX_FLAGS "-stdlib=libc++ ${CMAKE_CXX_FLAGS}")
 SET(APPLE_FRAMEWORKS "-framework Cocoa -framework IOkit -framework CoreVideo")
endif(APPLE)
###  OpenGL  ###}}}

###  GLFW3  ###{{{
set( ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:$ENV{HOME}/local_install/lib/pkgconfig")
FIND_PACKAGE( PkgConfig REQUIRED )
PKG_SEARCH_MODULE( GLFW3 REQUIRED glfw3 ) # sets GLFW3 as prefix for glfw vars
# now ${GLFW3_INCLUDE_DIR}, ${GLFW3_LIBRARIES} and ${GLFW3_STATIC_LIBRARIES} 
# are set
INCLUDE_DIRECTORIES( ${GLFW3_INCLUDE_DIR} )
###  GLFW3  ###}}}

###  ASSIMP  ###{{{
PKG_SEARCH_MODULE( ASSIMP REQUIRED assimp ) 
include_directories(${ASSIMP_INCLUDE_DIRS})
link_directories(${ASSIMP_LIBRARY_DIRS})
###  ASSIMP  ###}}}

find_package(PNG REQUIRED)
include_directories(${PNG_INCLUDE_DIR})


include_directories(./include ./lib)
file (GLOB_RECURSE source_files src/* include/* lib/*)

add_executable(Quidditch ${source_files})

target_link_libraries(Quidditch  ${GL_LIBRARIES} ${APPLE_FRAMEWORKS} ${GLFW3_STATIC_LIBRARIES} ${ASSIMP_LIBRARIES} ${PNG_LIBRARY})



# vim: set foldmethod=marker:

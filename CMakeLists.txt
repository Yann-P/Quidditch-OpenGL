
### Creating an executable
add_executable(myOwnOpenGLProg myOwnOpenGLProg.cpp)
target_link_libraries(myOwnOpenGLProg  ${GL_LIBRARIES} ${APPLE_FRAMEWORKS} ${GLFW3_STATIC_LIBRARIES} ${ASSIMP_LIBRARIES})
add_dependencies(myOwnOpenGLProg resources)

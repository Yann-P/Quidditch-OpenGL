#include <Drawable.h>

Drawable::Drawable(Shader s, Mesh m): _shader(s), _mesh(m) 
{

	GLuint vbo, ibo, vao;

 	glGenBuffers(1, &vbo);
 	glBindBuffer(GL_ARRAY_BUFFER, vbo);
 	glBufferData(GL_ARRAY_BUFFER, _mesh.getPositions().size() * sizeof(float) * 3, _mesh.getPositions().data(), GL_STATIC_DRAW);
 	glBindBuffer(GL_ARRAY_BUFFER, 0);

 	// IBO
 	glGenBuffers(1, &ibo);
 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
 	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _mesh.getIndices().size() * sizeof(int), _mesh.getIndices().data(), GL_STATIC_DRAW);
 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

 	// VAO
 	glGenVertexArrays(1, &vao);
 	glBindVertexArray(vao);
 	glBindBuffer(GL_ARRAY_BUFFER, vbo);

 	GLint positionIndex = glGetAttribLocation(_shader, "position");
 	glEnableVertexAttribArray(positionIndex);
 	glVertexAttribPointer(positionIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

	GLint normalIndex = glGetAttribLocation(_shader, "normal");
 	glEnableVertexAttribArray(normalIndex);
 	glVertexAttribPointer(normalIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
 	glBindVertexArray(0);

 	_ibo = ibo;
 	_vao = vao;
 	_vbo = vbo;
 	_nbIndices = _mesh.getIndices().size();

}


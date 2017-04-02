#include <Drawable.h>

Drawable::Drawable(Shader * s, Mesh * m, Texture * t): _shader(s), _mesh(m) 
{

	//std::cout << "drawable: mesh=" << _mesh-> << std::endl;
	std::cout << "drawable: shader=" << *_shader << std::endl;

	GLuint vbo, ibo, vao;

	glGenVertexArrays(1, &vao);
 	glGenBuffers(1, &vbo);
 	glGenBuffers(1, &ibo);


 	// VBO
 	glBindBuffer(GL_ARRAY_BUFFER, vbo);
 	glBufferData(GL_ARRAY_BUFFER, _mesh->getPositions().size() * sizeof(float) * 3, _mesh->getPositions().data(), GL_STATIC_DRAW);
 	glBindBuffer(GL_ARRAY_BUFFER, 0);

 	// IBO
 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
 	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _mesh->getIndices().size() * sizeof(int), _mesh->getIndices().data(), GL_STATIC_DRAW);
 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


 	glBindVertexArray(vao);
 	glBindBuffer(GL_ARRAY_BUFFER, vbo);


 	GLint positionIndex = glGetAttribLocation(*_shader, "position");
 	glEnableVertexAttribArray(positionIndex);
 	glVertexAttribPointer(positionIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

 	glBindVertexArray(0);

 	_ibo = ibo;
 	_vao = vao;
 	_vbo = vbo;

 	std::cout << "drawable: ibo=" << ibo << std::endl;
	std::cout << "drawable: vao=" << vao << std::endl;
 	std::cout << "drawable: vbo=" << vbo << std::endl;

}


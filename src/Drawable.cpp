/**
  *  @author Yann Pellegrini
  *
  */


#include <Drawable.h>

Drawable::Drawable(Shader * s, Mesh * m, Texture * t): _shader(s), _mesh(m), _texture(t)
{

	//std::cout << "drawable: mesh=" << _mesh-> << std::endl;
	std::cout << "drawable: shader=" << *_shader << std::endl;

	GLuint vbo_positions, vbo_uvs, vbo_normals, ibo, vao;

	glGenVertexArrays(1, &vao);
 	glGenBuffers(1, &vbo_positions);
 	glGenBuffers(1, &vbo_uvs);
 	glGenBuffers(1, &vbo_normals);
 	glGenBuffers(1, &ibo);


 	// vbo_positions
 	glBindBuffer(GL_ARRAY_BUFFER, vbo_positions);
 	glBufferData(GL_ARRAY_BUFFER, _mesh->getPositions().size() * sizeof(float) * 3, _mesh->getPositions().data(), GL_STATIC_DRAW);
 	glBindBuffer(GL_ARRAY_BUFFER, 0);

 	glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
 	glBufferData(GL_ARRAY_BUFFER, _mesh->getNormals().size() * sizeof(float) * 3, _mesh->getNormals().data(), GL_STATIC_DRAW);
 	glBindBuffer(GL_ARRAY_BUFFER, 0);

 	glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
 	glBufferData((GLenum)GL_ARRAY_BUFFER, _mesh->getUvs().size() * sizeof(float) * 2, _mesh->getUvs().data(), (GLenum)GL_STATIC_DRAW);
 	glBindBuffer(GL_ARRAY_BUFFER, 0);


 	glBindVertexArray(vao);

 	glBindBuffer(GL_ARRAY_BUFFER, vbo_positions);
 	GLint positionIndex = glGetAttribLocation(*_shader, "position");
 	glEnableVertexAttribArray(positionIndex);
 	glVertexAttribPointer(positionIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

 	glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
 	GLint normalIndex = glGetAttribLocation(*_shader, "normal");
 	glEnableVertexAttribArray(normalIndex);
 	glVertexAttribPointer(normalIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

 	glBindBuffer(GL_ARRAY_BUFFER, vbo_uvs);
 	GLint uvsIndex = glGetAttribLocation(*_shader, "uv");
    glEnableVertexAttribArray(uvsIndex);
 	glVertexAttribPointer(uvsIndex, 2, GL_FLOAT, GL_FALSE, 0, 0);


 	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

 	// IBO
 	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
 	glBufferData(GL_ELEMENT_ARRAY_BUFFER, _mesh->getIndices().size() * sizeof(int), _mesh->getIndices().data(), GL_STATIC_DRAW);
 	
 	glBindVertexArray(0);

 	_ibo = ibo;
 	_vao = vao;

 	std::cout << "drawable: ibo=" << ibo << std::endl;
	std::cout << "drawable: vao=" << vao << std::endl;

}


#ifndef MESH_H
#define MESH_H

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Shader.h"

class Mesh {
public:
	static Mesh *createMesh(const std::string *filename);
	static Mesh *createMesh(glm::vec3 *vertices, unsigned int numVertices, glm::vec3 *normals, glm::vec2 *textureCoordinates);
	void draw();
	~Mesh();
private:
	glm::vec3 *vertices;
	glm::vec3 *normals;
	glm::vec2 *textureCoordinates;
	unsigned int numVertices;
	GLuint VAO;
	GLuint VBO;
	void setup(void);
};

#endif

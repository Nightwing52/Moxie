#include "Mesh.h"

Mesh *Mesh::createMesh(glm::vec3 *vertices, unsigned int numVertices, glm::vec3 *normals, glm::vec2 *textureCoordinates){
	if(vertices != NULL){
		Mesh *mesh=new Mesh();
		mesh->vertices=vertices;
		mesh->normals=normals;
		mesh->textureCoordinates=textureCoordinates;
		mesh->numVertices=numVertices;
		mesh->setup();
		return mesh;
	}
	return NULL;
}

Mesh *Mesh::createMesh(const std::string *filename){
	/* load data from file */
	Mesh *mesh=new Mesh();
	mesh->setup();
}

void Mesh::setup(void){
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	/* un-textured mesh; use default shader */
	if(normals == NULL && textureCoordinates == NULL){
		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0])*numVertices, vertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0); //vertices
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glBindVertexArray(0);
	}
}

void Mesh::draw() {
	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLES, 0, numVertices);
	glBindVertexArray(0);
}

Mesh::~Mesh() {
	
	delete[] vertices;
	delete[] textureCoordinates;
	delete[] normals;
}

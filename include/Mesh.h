#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

class Mesh {
        public:
                Mesh(const string &filename);
                void Draw(const float x, const float y, const float z);
                ~Mesh();
        private:
                glm::vec3 *m_vertices;
                glm::vec3 *m_normals;
                glm::vec2 *m_texCoords;
};

#endif

#include "Mesh.h"

Mesh::Mesh(const string &filename) {
        ifstream file(filename.c_str(), ios::binary);
        if (!file)
                throw runtime_error("Cannot open model " + filename);

        uint32_t magic;
        uint16_t secHead;
        uint16_t secSize;
        float *data;

        file.read((char*)&magic, 4);
        if (magic != 0x584F4DFE)
                throw runtime_error(filename + " isn't valid Moxie");

        while (!file.eof()) {
                file.read((char*)&secHead, 2);
                file.read((char*)&secSize, 2);
                switch(secHead) {
                        case 0xE54D:
                                // Vertex List
                                m_vertices = new glm::vec3[secSize/3];
                                file.read((char*)m_vertices,
                                                sizeof(float)*secSize);
                                break;
                        case 0xE64D:
                                // Texture Coords
                                m_texCoords = new glm::vec2[secSize/2];
                                file.read((char*)m_texCoords,
                                                sizeof(float)*secSize);
                                break;
                        case 0xE74D:
                                // Normal List
                                m_normals = new glm::vec3[secSize/3];
                                file.read((char*)m_normals,
                                                sizeof(float)*secSize);
                                break;
                        case 0xE84D:
                                // Bone List
                                // Still working on this
                                break;
                        default:
                                break;
                }
        }
        file.close();
}

void Mesh::Draw(const float x, const float y, const float z) {
        glm::vec3 pos(x, y, z);
}

Mesh::~Mesh() {
}

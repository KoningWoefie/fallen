#ifndef MESH_H
#define MESH_H

#include <iostream>
#include <vector>

#include <src/config.h>

#include <GL/glew.h>
#include <glm/glm.hpp>

class Mesh
{
public:
    Mesh(int width, int height);
    virtual ~Mesh();

    //make rectangle and or square mesh
    void generateMesh(glm::vec2 pivot, float uvWidth, float uvHeight);

    //make circle mesh
    void generateCircleMesh(glm::vec2 pivot, float uvWidth, float uvHeight, int segments);

    //generate the buffers for openGL
    void generateBuffers(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs);

    GLuint vertexbuffer() { return _vertexbuffer; };
    GLuint uvbuffer() { return _uvbuffer; };
    int numverts() { return _numverts; };
private:
    int _width;
    int _height;
    int _numverts;
    int _radius;

    GLuint _vertexbuffer;
    GLuint _uvbuffer;

    std::vector<glm::vec2> _uvs;
};

#endif
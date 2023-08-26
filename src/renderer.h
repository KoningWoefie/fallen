#ifndef RENDERER_H
#define RENDERER_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <src/config.h>
#include <src/dynamic.h>
#include <src/scene.h>
#include <src/resourcemanager.h>
#include <src/texture.h>
#include <src/mesh.h>

class Renderer
{
public:
    Renderer();
    virtual ~Renderer();

    void RenderScene(Scene* scene);

    GLFWwindow* window() { return _window; }
private:
    void RenderDynamic(Dynamic* d, glm::mat4 PaMa);

    int init();

	GLFWwindow* _window;
    ResourceManager _resMan;

	GLuint loadShaders(
		const std::string& vertex_file_path,
		const std::string& fragment_file_path
	);

	GLuint _programID;

	Camera* _camera; // reference to scene->camera

	glm::mat4 _viewMatrix;
	glm::mat4 _projectionMatrix;
};

#endif
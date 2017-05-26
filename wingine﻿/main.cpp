#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "src/graphics/window.h"
#include "src/math/engineMath.h"
#include "src/utils/utils.h"
#include "src/graphics/shader.h"


using namespace core;
using namespace graphics;
using namespace math;


int main()
{
	Window window("GLFW Window", 960, 540);
	

	GLfloat verticies[] =
	{
		0,0,0,
		8,0,0,
		0,3,0,
		0,3,0,
		8,3,0,
		8,0,0,
	};

	Shader shader("src/shaders/vertex.vert", "src/shaders/fragment.frag");
	shader.enable();

	GLuint vbo;

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);


	mat4 ortho = mat4::ortho(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
	mat4 translation = mat4::translation(vec3(4, 3, 0));
	vec2 light = vec2(4.0, 1.5);
	vec4 col = vec4(0.2f, 0.4f, 0.7f, 1.0f);

	glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, "pr_matrix"), 1, GL_FALSE, ortho.elements);
	glUniformMatrix4fv(glGetUniformLocation(shader.shaderID, "ml_matrix"), 1, GL_FALSE, translation.elements);
	glUniform2f(glGetUniformLocation(shader.shaderID, "light_pos"), light.x, light.y);
	glUniform4f(glGetUniformLocation(shader.shaderID, "col"), col.x, col.y, col.z, col.w);


	while (!window.closed())
	{
		window.mainLoop();
	}
	return(0);
}
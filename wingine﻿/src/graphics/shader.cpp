#include "shader.h"

namespace core { 
namespace graphics {

	Shader::Shader(const char* vertexPath, const char* fragmentPath)
		: vertexPath(vertexPath), fragmentPath(fragmentPath)
	{
		shaderID = load();
	}

	Shader::~Shader()
	{
		glDeleteProgram(shaderID);
	}

	GLuint Shader::load()
	{
		GLuint program = glCreateProgram();
		GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

		std::string vertexSrcString = read_file(vertexPath);
		std::string fragmentSrcString = read_file(fragmentPath);

		const char* vertexSource = vertexSrcString.c_str();
		const char* fragmentSource = fragmentSrcString.c_str();

		glShaderSource(vertex, 1, &vertexSource, NULL);
		glCompileShader(vertex);

		glShaderSource(fragment, 1, &fragmentSource, NULL);
		glCompileShader(fragment);

		glAttachShader(program, vertex);
		glAttachShader(program, fragment);

		glLinkProgram(program);
		glValidateProgram(program);

		glDeleteShader(vertex);
		glDeleteShader(fragment);

		return program;
	}

	void Shader::enable()
	{
		glUseProgram(shaderID);
	}

	void Shader::disable()
	{
		glUseProgram(0);
	}


}}
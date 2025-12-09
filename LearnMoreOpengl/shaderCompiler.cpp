
#include<glad/glad.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>





class ShaderProgram
{
public:
	
	unsigned int program;
	
	ShaderProgram(const char* vertexShaderFP, const char* fragmentShaderFP) {
		std::ifstream vShaderFile, fShaderFile;
		


		vShaderFile.open(vertexShaderFP);
		fShaderFile.open(fragmentShaderFP);


		std::stringstream vShaderStream, fShaderStream;


		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		std::string vShaderCode, fShaderCode;

		vShaderCode = vShaderStream.str();
		fShaderCode = fShaderStream.str();

		const char* vSource;
		const char* fSource;

		vSource = vShaderCode.c_str();
		fSource = fShaderCode.c_str();


		unsigned int vertex,fragment;

		vertex = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex, 1, &vSource, NULL);
		glCompileShader(vertex);
		checkCompileErrors(vertex, "VERTEX");

		fragment = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment, 1, &fSource, NULL);
		glCompileShader(fragment);
		checkCompileErrors(fragment, "FRAGMENT");
		
		program = glCreateProgram();
		glAttachShader(program, fragment);
		glAttachShader(program, vertex);
		glLinkProgram(program);
		checkCompileErrors(program, "PROGRAM");

		glDeleteShader(vertex);
		glDeleteShader(fragment);
		
		

		


		


	}


	
	void use() {
		glUseProgram(program);
	}
	
	

	

private:
	// utility function for checking shader compilation/linking errors.
	// ------------------------------------------------------------------------
	void checkCompileErrors(unsigned int shader, std::string type)
	{
		int success;
		char infoLog[1024];
		if (type != "PROGRAM")
		{
			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
			if (!success)
			{
				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
		else
		{
			glGetProgramiv(shader, GL_LINK_STATUS, &success);
			if (!success)
			{
				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			}
		}
	}

	


	

};






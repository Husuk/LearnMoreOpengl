#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include<C:\Users\user\source\repos\LearnMoreOpengl\LearnMoreOpengl\shaderCompiler.cpp>
#include<C:\Users\user\source\repos\LearnMoreOpengl\LearnMoreOpengl\texture.cpp>
#define STB_IMAGE_IMPLEMENTATION
#include <stb/stb_image.h>


void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main(){
	
	
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow* window = glfwCreateWindow(800, 600, "learnMoreOpenGL", NULL, NULL);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwMakeContextCurrent(window);

	

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	ShaderProgram myProgram("C:/Users/user/source/repos/LearnMoreOpengl/LearnMoreOpengl/vertexShader.vs", "C:/Users/user/source/repos/LearnMoreOpengl/LearnMoreOpengl/fragmentShader.fs");



	float verticies[] = {
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	

	unsigned int indicies[] = {
		0,1,2
	};
	

	unsigned int VAO,VBO,EBO;
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), &verticies, GL_STATIC_DRAW);

	
	
	glGenBuffers(1, &EBO);
	

	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float)*5, (void*)0);
	glEnableVertexAttribArray(0);


	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float)*5, (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	

	
	
	textureCompiler wallTexture("C:/Users/user/source/repos/LearnMoreOpengl/LearnMoreOpengl/wall.jpg",GL_TEXTURE_2D,GL_RGB);
	

	textureCompiler faceTexture("C:/Users/user/source/repos/LearnMoreOpengl/LearnMoreOpengl/awesomeface.png", GL_TEXTURE_2D,GL_RGBA);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	

	
	myProgram.use();

	glUniform1i(glGetUniformLocation(myProgram.program, "ourTexture"), 0);

	glUniform1i(glGetUniformLocation(myProgram.program, "ourTexture2"), 1);
	
	


	glm::vec4 vec(0.0f, 0.0f, 0.0f, 1.0f);
	glm::mat4 trans = glm::mat4(1.0f);
	glm::mat4 projection;
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 model = glm::mat4(1.0f);
	
	// note that we're translating the scene in the reverse direction of where we want to move
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	
	vec = trans * vec;
	
	
	glEnable(GL_DEPTH_TEST);

	//render loop
	while (!glfwWindowShouldClose(window))

	{
		
		float time = float(glfwGetTime());
		glm::mat4 movement = glm::mat4(1.0f);
		
		
		
		model = glm::rotate(model, glm::radians(0.5f), glm::vec3(0.5f, 1.0f, 0.0f));
		
		unsigned int transformLoc = glGetUniformLocation(myProgram.program, "transform");
		unsigned int modelLoc = glGetUniformLocation(myProgram.program, "model");
		unsigned int viewLoc = glGetUniformLocation(myProgram.program, "view");
		unsigned int perspectiveLoc = glGetUniformLocation(myProgram.program, "perspective");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(perspectiveLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));
		

		
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		wallTexture.activate(GL_TEXTURE0);
		wallTexture.bind();
		faceTexture.activate(GL_TEXTURE1);
		faceTexture.bind();
		myProgram.use();
		
		glBindVertexArray(VAO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glDrawArrays(GL_TRIANGLES, 0,36);

		
		glBindVertexArray(0);
		
		if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) 
		{
			glfwSetWindowShouldClose(window, true);
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
			
	}
	
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glDeleteProgram(myProgram.program);

	glfwTerminate();
	
	
	return 0;

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {

	glViewport(0, 0, 800, 600);//parameters: the left x-cordinate of the viewport, the bottom y-coordinate of the viewport

}



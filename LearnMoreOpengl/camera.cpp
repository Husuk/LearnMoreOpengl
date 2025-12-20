#include <iostream>
#include<glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>



class Camera
{
public:
	glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 cameraRight=glm::vec3(-1.0f,0.0f,0.0f);
	float YAW = -90;
	float PITCH;

	glm::vec3 frontLook;
	glm::vec3 cameraPos = glm::vec3(0.0f,0.0f,3.0f);

	Camera(glm::vec3 camPos) {
		cameraPos = camPos;
		UpdateCamera();
	
	
	}
	
	
	
	void mouseControls(float xoffset, float yoffset,float sensitivity) {
		
		xoffset *= sensitivity;
		yoffset *= sensitivity;
		
		YAW += xoffset;
		PITCH += yoffset;

		if (PITCH > 89.0f) {
			PITCH = 89.0f;
		}

		if (PITCH < -89.0f) {
			PITCH = -89.0f;
		}
		
		UpdateCamera();
		
		
		
	}
	void keyboardControls(float cameraSpeed,GLFWwindow* window) {
		if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
			cameraPos += cameraSpeed * cameraFront;
			std::cout << "cameraPos: " << (float)cameraPos.z<<","<< (float)cameraPos.y<<","<< (float)cameraPos.z << std::endl;

		}
			
		if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
			cameraPos -= cameraSpeed * cameraFront;
			std::cout << "cameraPos: " << (float)cameraPos.z << "," << (float)cameraPos.y << "," << (float)cameraPos.z << std::endl;
		}
			
		if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
			cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
			std::cout << "cameraPos: " << (float)cameraPos.z << "," << (float)cameraPos.y << "," << (float)cameraPos.z << std::endl;
		}
			
		if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
			cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;
			std::cout << "cameraPos: " << (float)cameraPos.z << "," << (float)cameraPos.y << "," << (float)cameraPos.z << std::endl;
		}
			
		if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) {
			frontLook = glm::vec3(0.0f, 0.0f, 0.0f);
			cameraPos = glm::vec3(0.0f, 0.0f, -3.0f);
			std::cout << "cameraPos: " << (float)cameraPos.z << "," << (float)cameraPos.y << "," << (float)cameraPos.z << std::endl;
			UpdateCamera();
		}
		
			

	}
	glm::mat4 GetViewMatrix() {
		frontLook = cameraPos + cameraFront;
		return glm::lookAt(cameraPos,frontLook, cameraUp);

	}

	

private:
	void UpdateCamera() {

		glm::vec3 direction;

		
		direction.x = cos(glm::radians(YAW)) * cos(glm::radians(PITCH));
		direction.y = sin(glm::radians(PITCH));
		direction.z = cos(glm::radians(YAW)) * cos(glm::radians(PITCH));
		cameraFront = glm::normalize(direction);

		cameraRight = glm::normalize(glm::cross(cameraFront, cameraUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		cameraUp = glm::normalize(glm::cross(cameraRight, cameraFront));


	}

};


#include<glad/glad.h>
#include <stb/stb_image.h>
#include<iostream>

class textureCompiler
{
public:
	int textDimension;
	
	unsigned int texture;
	textureCompiler(const char* texturePath,int textureDimension,int colorValues) {
		
		glGenTextures(1, &texture);
		glBindTexture(textureDimension, texture);
		
		
		
		
		textDimension = textureDimension;
		
		
		int width, height, nrChannels;
		unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

		if (data)
		{
			glTexImage2D(textDimension, 0, GL_RGB, width, height, 0, colorValues, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(textDimension);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		
	
		stbi_image_free(data);
	}

	void activate(int textureUnit) {
		glActiveTexture(textureUnit);
	}
	void bind() {
		glBindTexture(textDimension,texture);
	}
	

private:

};


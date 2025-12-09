#include<glad/glad.h>
#include <stb/stb_image.h>
#include<iostream>

class textureCompiler
{
public:
	int textDimension;
	
	unsigned int texture;
	textureCompiler(const char* texturePath,int textureDimension,int textWrapS,int textWrapT,int minMinifying,int minMagnifying,int colorValues) {
		
		glGenTextures(1, &texture);
		glBindTexture(textureDimension, texture);
		
		/*
		glTexParameteri(textureDimension, GL_TEXTURE_WRAP_S, textWrapS);
		glTexParameteri(textureDimension, GL_TEXTURE_WRAP_T, textWrapT);
		glTexParameteri(textureDimension, GL_TEXTURE_MIN_FILTER, minMinifying);
		glTexParameteri(textureDimension, GL_TEXTURE_MAG_FILTER, minMagnifying);
		*/
		
		
		

		
		textDimension = textureDimension;
		
		
		int width, height, nrChannels;
		unsigned char* data = stbi_load(texturePath, &width, &height, &nrChannels, 0);

		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture" << std::endl;
		}
		
	
		stbi_image_free(data);
	}

	void activate(int textureUnit) {
		glActiveTexture(GL_TEXTURE0);
	}
	void bind() {
		glBindTexture(GL_TEXTURE_2D,texture);
	}
	

private:

};


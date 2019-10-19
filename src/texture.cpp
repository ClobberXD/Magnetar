#include "texture.h"

#include <glad/glad.h>
#include "stb_image/stb_image.h"

unsigned int generateTexture(const std::string &path, const std::vector<TextureParam> &tex_params)
{
	// Load image from file
	int w, h, n_channels;
	unsigned char *image = stbi_load(path.c_str(), &w, &h, &n_channels, 0);

	// Create and bind texture object
	unsigned int id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);

	// Set texture parameters
	for (int i = 0; i < tex_params.size(); i++)
	{
		TextureParam param = tex_params.at(i);
		glTexParameteri(GL_TEXTURE_2D, param.attribute, param.value);
	}

	// Generate texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);

	// Free image buffer
	stbi_image_free(image);

	return id;
}

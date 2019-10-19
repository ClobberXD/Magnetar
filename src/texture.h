#pragma once

#include <string>
#include <vector>

struct TextureParam
{
	unsigned int attribute, value;
};

unsigned int generateTexture(const std::string &path, const std::vector<TextureParam> &tex_params);

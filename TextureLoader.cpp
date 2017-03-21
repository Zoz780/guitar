#include "TextureLoader.h"

std::list<std::string> loadNamesFromFile(const std::string& filename)
{
	std::list<std::string> names;
	string name;
	ifstream tex_names;
	tex_names.open(filename);
	int i = 0;
	for (int i = 0; i < 31; ++i) {
		getline(tex_names, name);
		names.push_back(name);
	}
	/*while (tex_names.eof())
	{
		getline(tex_names, name);
		cout << "" << name;
		names.push_back(name);
		i++;
	}*/
	cout << "Lista meret: " << names.size() << endl;
	tex_names.close();
	return names;
}

GLuint TextureLoader::loadImage(const std::string& path)
{
	textureId = SOIL_load_OGL_texture
	(path.c_str(),
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_POWER_OF_TWO);
	if (textureId == 0) {
		cout << "Not found, or corrupt " << path.c_str() << " .....\n";
		return false;
	}
	else cout << "Loading " << path.c_str() << " .....\n";
	return textureId;
}

int TextureLoader::CountTextures()
{
	return m_textureNames.size();
}

void TextureLoader::UseTableTex()
{
	glBindTexture(GL_TEXTURE_2D, textureIdArray[4]);
}

TextureLoader::TextureLoader()
{
}

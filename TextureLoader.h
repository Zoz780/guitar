#pragma once
#include <iostream>
#include <list>
#include <glut.h>
#include <SOIL.h>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

std::list<std::string> loadNamesFromFile(const std::string& filename);

class TextureLoader
{
public:
	TextureLoader();
	void Initialize()
	{
		loadSceneConfig();
		loadResources();
		//cout << "Txture array size: " << m_textureNames.size() << endl;
	}
	int CountTextures();

	void UseTableTex();

protected:
	virtual void loadSceneConfig() = 0;
	std::list<std::string> m_textureNames;
	std::string m_textureDirectory;

private:
	void loadResources()
	{
		loadTextureNames();
		loadTextures();
	}

	void loadTextureNames()
	{
		m_textureNames = loadNamesFromFile("tex_names.txt");
	}

	void loadTextures()
	{
		int i = 0;
		cout << "Innen\n";
		for (const std::string& texture_name : m_textureNames) {
			textureIdArray[i] = loadTexture(m_textureDirectory, texture_name);
			cout << textureIdArray[i] << endl;
			i++;
		}
	}

	GLuint loadTexture(const std::string& directory, const std::string& filename)
	{
		stringstream path;
		path << directory << filename;
		textureId = loadImage(path.str());
		// use as OpenGL texture
		glBindTexture(GL_TEXTURE_2D, textureId);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		return textureId;
	}
	GLuint textureId;
	GLuint textureIdArray[31];
	GLuint loadImage(const std::string& filename);
};


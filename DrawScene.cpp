#include "DrawScene.h"
#include "LowQualityScene.h"
#include "MediumQualityScene.h"
#include "HighQualityScene.h"
#include "TextureLoader.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

ModelDrawer raptor_model;
ModelDrawer house_model;
ModelDrawer weapon_model;
ModelDrawer tree_model;
ModelDrawer rock_model;
ModelDrawer mountain_model_small;
ModelDrawer mountain_model;
ModelDrawer mountain_model_big;
ModelDrawer mountain_model_biggest;

LowQualityScene low;
MediumQualityScene medium;
HighQualityScene high;


void DrawScene::Draw_World_Pub(float guitar_rotateAngle, double left_doorAngle, double right_doorAngle)
{
	SetRotation(guitar_rotateAngle, left_doorAngle, right_doorAngle);
	Draw_World();
}

void DrawScene::LoadTextures(int quality_in)
{
	SetQuality(quality_in);
	LoadWorldTextures();
}

void DrawScene::SetQuality(int quality_in)
{
	quality = quality_in;
}

void DrawScene::SetRotation(float guitar_rotateAngle, double left_doorAngle, double right_doorAngle)
{
	guitar_rotate_angle = guitar_rotateAngle;
	left_door_angle = left_doorAngle;
	right_door_angle = right_doorAngle;
}

void DrawScene::LoadModel()
{
	raptor_model.load("Data/raptor.obj", 0.2f, "Data/raptor.png");
	house_model.load("Data/house.obj", 0.2f, "Data/house.png");
	weapon_model.load("Data/weapon.obj", 0.2f, "Data/weapon.png");
	rock_model.load("Data/Rock1.obj", 0.15f, "Data/Rock1.png");
	mountain_model_small.load("Data/mountain.obj", 1.0f, "Data/mountain.png");
	mountain_model.load("Data/mountain.obj", 1.8f, "Data/mountain.png");
	mountain_model_big.load("Data/mountain.obj", 3.8f, "Data/mountain.png");
	mountain_model_biggest.load("Data/mountain.obj", 6.8f, "Data/mountain.png");
	tree_model.load("Data/lowpolytree.obj", 0.6f, "Data/lowpolytree.png");

}

bool DrawScene::LoadWorldTextures()                                    // Load Bitmaps And Convert To Textures
{
	if (quality == 1)
	{
		low.Initialize();
		return true;
	}
	else if (quality == 2)
	{
		medium.Initialize();
		return true;
	}
	else if (quality == 3)
	{
		high.Initialize();
		return true;
	}
	return true;
}

void DrawScene::Table()
{
	TextureLoader* scene = new LowQualityScene();
	scene->UseTableTex();

	/*if (quality == 1)
	{
		low.UseTableTex();
	}
	else if (quality == 2)
	{
		medium.UseTableTex();
	}
	else if (quality == 3)
	{
		high.UseTableTex();
	}*/
	
	//jobb hátsó láb
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, -1.0f, -29.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.9f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.9f, -1.0f, -29.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.9f, -1.0f, -29.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.9f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f, -1.0f, -29.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.9f, -1.0f, -29.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.9f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.9f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.9f, -1.0f, -29.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, -1.0f, -29.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f, -1.0f, -29.0f);
	glEnd();
	//jobb elsõ láb
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, -1.0f, -27.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.9f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.9f, -1.0f, -27.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.9f, -1.0f, -27.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.9f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f, -1.0f, -27.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.9f, -1.0f, -27.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.9f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(1.9f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(1.9f, -1.0f, -27.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.0f, -1.0f, -27.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.0f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.0f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.0f, -1.0f, -27.0f);
	glEnd();
	//bal elsõ láb
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -27.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -27.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -27.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -27.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -27.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -27.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -27.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -27.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -27.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -27.0f);
	glEnd();
	//bal hátsó láb
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -29.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -29.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -29.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -29.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -29.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.0f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.0f, -1.0f, -29.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -29.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -29.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.9f, -0.4f, -29.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.9f, -1.0f, -29.0f);
	glEnd();
	//asztallap
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.3f, -0.4f, -26.8f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.3f, -0.3f, -26.8f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.3f, -0.3f, -26.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.3f, -0.4f, -26.8f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.3f, -0.4f, -29.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.3f, -0.3f, -29.3f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.3f, -0.3f, -29.3f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.3f, -0.4f, -29.3f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-2.3f, -0.4f, -29.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-2.3f, -0.4f, -26.8f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-2.3f, -0.3f, -26.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-2.3f, -0.3f, -29.3f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.3f, -0.4f, -29.3f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(2.3f, -0.3f, -29.3f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(2.3f, -0.3f, -26.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.3f, -0.4f, -26.8f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(2.3f, -0.3f, -29.3f);
	glTexCoord2f(1.0f, 2.0f); glVertex3f(-2.3f, -0.3f, -29.3f);
	glTexCoord2f(0.0f, 2.0f); glVertex3f(-2.3f, -0.3f, -26.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(2.3f, -0.3f, -26.8f);
	glEnd();
}

void DrawScene::Guitar()
{
	glPushMatrix();
	glTranslatef(0.0f, 1.0f, -28.0f);
	glRotatef(guitar_rotate_angle, 0.0f, 1.0f, 0.0f);
	//front
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.6f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.4f, -0.8f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.4f, -0.8f, 0.0f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[10]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.4f, -0.8f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.4f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.4f, -0.8f, 0.0f);
	glEnd();
	//back
	glBindTexture(GL_TEXTURE_2D, texture[6]);
	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.4f, 0.0f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.6f, -0.2f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.4f, 0.0f, -0.2f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, -0.8f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, -1.0f, -0.2f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, -0.8f, -0.2f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[16]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, -0.8f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.4f, 0.0f, -0.2f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.4f, 0.0f, -0.2f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, -0.8f, -0.2f);
	glEnd();
	//right side
	glBindTexture(GL_TEXTURE_2D, texture[7]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.4f, -0.8f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.4f, 0.0f, -0.2f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.4f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, -0.8f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.4f, -0.8f, -0.2f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.4f, -0.8f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.4f, 0.0f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.6f, -0.2f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.6f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.4f, 0.0f, 0.0f);
	glEnd();
	//left side
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, 0.0f, -0.2f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.4f, -0.8f, -0.2f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.4f, -0.8f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.4f, 0.0f, 0.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.4f, -0.8f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.4f, -0.8f, -0.2f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, -0.2f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.4f, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 0.6f, 0.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.6f, -0.2f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.4f, 0.0f, -0.2f);
	glEnd();
	//neck
	glBindTexture(GL_TEXTURE_2D, texture[9]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, -0.1f, 0.01f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, 2.0f, 0.01f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 2.0f, 0.01f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -0.1f, 0.01f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, 0.3f, -0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.0f, -0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.1f, 2.0f, -0.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, 0.3f, -0.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -0.1f, 0.01f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.0f, 0.01f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 2.0f, -0.1f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -0.1f, -0.1f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, -0.1f, -0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, 2.0f, -0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.1f, 2.0f, 0.01f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, -0.1f, 0.01f);
	glEnd();	//neck end
				//head
	glBindTexture(GL_TEXTURE_2D, texture[12]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.15f, 2.0f, 0.02f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.15f, 2.3f, 0.02f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 2.3f, 0.02f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, 2.0f, 0.02f);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, texture[8]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, 2.0f, -0.15f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.3f, -0.15f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.15f, 2.3f, -0.15f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.15f, 2.0f, -0.15f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, 2.0f, 0.02f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.3f, 0.02f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 2.3f, -0.15f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, 2.0f, -0.15f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.15f, 2.0f, -0.15f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.15f, 2.3f, -0.15f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.15f, 2.3f, 0.02f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.15f, 2.0f, 0.02f);
	glEnd();
	// right bottom
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, 1.7f, -0.15f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.15f, 2.0f, -0.15f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.15f, 2.0f, 0.02f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, 1.7f, 0.02f);
	glEnd();
	// back bottom
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, 1.7f, -0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.0f, -0.15f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.15f, 2.0f, -0.15f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, 1.7f, -0.1f);
	glEnd();
	// front bottom
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, 1.7f, 0.02f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.15f, 2.0f, 0.02f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.1f, 2.0f, 0.02f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, 1.7f, 0.02f);
	glEnd();
	// left bottom
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, 1.7f, -0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 2.0f, -0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 2.0f, -0.15f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, 1.7f, -0.1f);
	glEnd();
	glPopMatrix();	//head end
}

void DrawScene::Door_left()
{
	glPushMatrix();
	glTranslatef(-3.9f, 0.0f, -75.5f);
	glRotatef(left_door_angle, 0.0f, 1.0f, 0.0f);
	// bal ajtó eleje
	glBindTexture(GL_TEXTURE_2D, texture[26]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 4.0f, -3.9f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 4.0f, 0.1f);
	glEnd();

	// bal ajtó háta
	glBindTexture(GL_TEXTURE_2D, texture[27]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 4.0f, 0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 4.0f, -3.9f);
	glEnd();

	// bal ajtó szemben levõ éle
	glBindTexture(GL_TEXTURE_2D, texture[28]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.1f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 4.0f, 0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.1f, 4.0f, 0.1f);
	glEnd();

	// bal ajtó hátsó éle
	glBindTexture(GL_TEXTURE_2D, texture[29]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.1f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.1f, 4.0f, -3.9f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 4.0f, -3.9f);
	glEnd();

	glutPostRedisplay();
	glPopMatrix();

}

void DrawScene::Door_right()
{
	glPushMatrix();
	glTranslatef(3.9f, 0.0f, -75.5f);
	glRotatef(right_door_angle, 0.0f, 1.0f, 0.0f);
	// jobb ajtó eleje
	glBindTexture(GL_TEXTURE_2D, texture[27]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 4.0f, 0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 4.0f, -3.9f);
	glEnd();

	// jobb ajtó háta
	glBindTexture(GL_TEXTURE_2D, texture[26]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, 4.0f, -3.9f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.1f, 4.0f, 0.1f);
	glEnd();

	// jobb ajtó szemben levõ éle
	glBindTexture(GL_TEXTURE_2D, texture[28]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.1f, -1.0f, 0.1f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.1f, 4.0f, 0.1f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 4.0f, 0.1f);
	glEnd();

	// jobb ajtó hátsó éle
	glBindTexture(GL_TEXTURE_2D, texture[29]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(0.1f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -3.9f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0f, 4.0f, -3.9f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(0.1f, 4.0f, -3.9f);
	glEnd();

	glutPostRedisplay();
	glPopMatrix();

}

void DrawScene::Draw_World()
{

	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	//modellek kirajzolása/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	house_model.draw(-30, 2.5, -120);
	//house_model.draw(0, 0, 0);
	raptor_model.draw(100, 0, -80);
	raptor_model.draw(70, 0, -130);
	weapon_model.draw(-15, 1.5, 8.0);
	rock_model.draw(2.5, -1.1, -81);
	rock_model.draw(-2.5, -1.1, -106);
	rock_model.draw(0.5, -1.1, -113);
	rock_model.draw(-0.8, -1.1, -93);
	mountain_model_small.draw(30, -1, -130);
	mountain_model_small.draw(40, 0, -120);
	mountain_model.draw(40, -2, -150);
	mountain_model.draw(-30, -2, -190);
	mountain_model.draw(50, -1.5, -105);
	mountain_model_big.draw(-70, -2, -180);
	mountain_model_big.draw(80, -5, -40);
	mountain_model_big.draw(-50, -16, -90);
	mountain_model_big.draw(-52, -15, -65);
	mountain_model_biggest.draw(-100, -15, -70);
	mountain_model_biggest.draw(-140, -6, -10);
	tree_model.draw(15, -2, -120);
	//modell kirajzolás vége/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	/*string line;
	ifstream coords;
	coords.open("world_coords.txt");

	coords.close();*/
	// floor
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	for (float i = -10.00f; i < 75.00f; i = i + 26.16f)
	{
		for (float j = -18.00f; j < 18.00f; j = j + 11.04f)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-(j + 11.04f), -1.01f, -i);
			glTexCoord2f(15.0f, 0.0f); glVertex3f(-j, -1.01f, -i);
			glTexCoord2f(15.0f, 35.0f); glVertex3f(-j, -1.01f, -(i + 26.16f));
			glTexCoord2f(0.0f, 35.0f); glVertex3f(-(j + 11.04f), -1.01f, -(i + 26.16f));
			glEnd();
		}
	}
	// híd
	glBindTexture(GL_TEXTURE_2D, texture[17]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -75.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, -1.0f, -75.0f);
	glTexCoord2f(1.0f, 3.0f); glVertex3f(4.0f, -1.0f, -115.0f);
	glTexCoord2f(0.0f, 3.0f); glVertex3f(-4.0f, -1.0f, -115.0f);
	glEnd();
	// híd bal fal
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -76.0f);
	glTexCoord2f(5.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -115.0f);
	glTexCoord2f(5.0f, 0.2f); glVertex3f(-4.0f, 0.1f, -115.0f);
	glTexCoord2f(0.0f, 0.2f); glVertex3f(-4.0f, 0.1f, -76.0f);
	glEnd();
	// híd jobb fal
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, -1.0f, -115.0f);
	glTexCoord2f(5.0f, 0.0f); glVertex3f(4.0f, -1.0f, -76.0f);
	glTexCoord2f(5.0f, 0.2f); glVertex3f(4.0f, 0.1f, -76.0f);
	glTexCoord2f(0.0f, 0.2f); glVertex3f(4.0f, 0.1f, -115.0f);
	glEnd();
	// híd elsõ
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -115.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, -1.0f, -115.0f);
	glTexCoord2f(1.0f, 0.145f); glVertex3f(4.0f, -0.3f, -115.0f);
	glTexCoord2f(0.0f, 0.145f); glVertex3f(-4.0f, -0.3f, -115.0f);
	glEnd();
	// híd elsõ teteje
	glBindTexture(GL_TEXTURE_2D, texture[11]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-9.3f, -0.3f, -115.0f);
	glTexCoord2f(11.92f, 0.0f); glVertex3f(10.0f, -0.3f, -115.0f);
	glTexCoord2f(11.92f, 1.0f); glVertex3f(10.0f, -0.3f, -116.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-9.3f, -0.3f, -116.0f);
	glEnd();  //híd vége
			  //plafon
	glBindTexture(GL_TEXTURE_2D, texture[2]);
	for (float i = -10.00f; i < 65.00f; i = i + 26.16f)
	{
		for (float j = -18.00f; j < 18.00f; j = j + 11.04f)
		{
			glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(-(j + 11.04f), 7.0f, -(i + 26.16f));
			glTexCoord2f(8.0f, 0.0f); glVertex3f(-j, 7.0f, -(i + 26.16f));
			glTexCoord2f(8.0f, 8.0f); glVertex3f(-j, 7.0f, -i);
			glTexCoord2f(0.f, 8.0f); glVertex3f(-(j + 11.04f), 7.0f, -i);
			glEnd();
		}
	}
	//plafon ajtó elõtt
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, 4.0f, -75.0f);
	glTexCoord2f(5.0f, 0.0f); glVertex3f(4.0f, 4.0f, -75.0f);
	glTexCoord2f(5.0f, 3.0f); glVertex3f(4.0f, 4.0f, -68.48f);
	glTexCoord2f(0.f, 3.0f); glVertex3f(-4.0f, 4.0f, -68.48);
	glEnd();
	Table();
	//walls //bal
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	for (float i = -10.00f; i < 75.00f; i = i + 21.25f)
	{
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-18.0f, -1.01f, -i);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-18.0f, -1.01f, -(i + 21.25f));
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-18.0f, 7.1f, -(i + 21.25f));
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-18.0f, 7.1f, -i);
		glEnd();
	}
	//jobb
	for (float i = -10.00f; i < 75.00f; i = i + 21.25f)
	{
		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(18.0f, -1.01f, -(i + 21.25f));
		glTexCoord2f(1.0f, 0.0f); glVertex3f(18.0f, -1.01f, -i);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(18.0f, 7.1f, -i);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(18.0f, 7.1f, -(i + 21.25f));
		glEnd();
	}
	//ajtó elõtt jobb fal
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, -1.0f, -75.0f);
	glTexCoord2f(0.25f, 0.0f); glVertex3f(4.0f, -1.0f, -68.48f);
	glTexCoord2f(0.25f, 0.62f); glVertex3f(4.0f, 4.0f, -68.48f);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(4.0f, 4.0f, -75.0f);
	glEnd();
	//ajtó elõtt bal fal
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -68.48f);
	glTexCoord2f(0.25f, 0.0f); glVertex3f(-4.0f, -1.0f, -75.0f);
	glTexCoord2f(0.25f, 0.62f); glVertex3f(-4.0f, 4.0f, -75.0f);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(-4.0f, 4.0f, -68.48f);
	glEnd();
	//elsõ teteje
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-18.0f, 4.0f, -68.48);
	glTexCoord2f(2.0f, 0.0f); glVertex3f(18.0f, 4.0f, -68.48);
	glTexCoord2f(2.0f, 0.37f); glVertex3f(18.0f, 7.1f, -68.48);
	glTexCoord2f(0.0f, 0.37f); glVertex3f(-18.0f, 7.1f, -68.48);
	glEnd();
	//hátsó
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(18.0f, -1.01f, 10.0f);
	glTexCoord2f(3.0f, 0.0f); glVertex3f(-18.0f, -1.01f, 10.0f);
	glTexCoord2f(3.0f, 1.0f); glVertex3f(-18.0f, 7.1f, 10.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(18.0f, 7.1f, 10.0f);
	glEnd();
	// elsõ1
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-18.0f, -1.01f, -68.48);
	glTexCoord2f(0.75f, 0.0f); glVertex3f(-4.0f, -1.01f, -68.48);
	glTexCoord2f(0.75f, 0.62f); glVertex3f(-4.0f, 4.0f, -68.48);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(-18.0f, 4.0f, -68.48);
	glEnd();
	// elsõ2
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, -1.01f, -68.48);
	glTexCoord2f(0.75f, 0.0f); glVertex3f(18.0f, -1.01f, -68.48);
	glTexCoord2f(0.75f, 0.62f); glVertex3f(18.0f, 4.0f, -68.48);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(4.0f, 4.0f, -68.48);
	glEnd();
	//külsõ fal teteje
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(24.0f, 4.0f, -76.0f);
	glTexCoord2f(2.5f, 0.0f); glVertex3f(-24.0f, 4.0f, -76.0f);
	glTexCoord2f(2.5f, 0.37f); glVertex3f(-24.0f, 7.1f, -76.0f);
	glTexCoord2f(0.0f, 0.37f); glVertex3f(24.0f, 7.1f, -76.0f);
	glEnd();
	//exit felirat
	glBindTexture(GL_TEXTURE_2D, texture[30]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.5f, 4.3f, -68.43f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.5f, 4.3f, -68.43f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.5f, 5.3f, -68.43f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.5f, 5.3f, -68.43f);
	glEnd();
	//tetõ(cserép)
	glBindTexture(GL_TEXTURE_2D, texture[20]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(24.0f, 6.8f, -76.5f);
	glTexCoord2f(10.0f, 0.0f); glVertex3f(-24.0f, 6.8f, -76.5f);
	glTexCoord2f(10.0f, 10.0f); glVertex3f(-24.0f, 25.1f, -46.0f);
	glTexCoord2f(0.0f, 10.0f); glVertex3f(24.0f, 25.1f, -46.0f);
	glEnd();
	//külsõ fal bal
	glBindTexture(GL_TEXTURE_2D, texture[1]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(24.0f, -1.0f, -76.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, -1.0f, -76.0f);
	glTexCoord2f(1.0f, 0.62f); glVertex3f(4.0f, 4.0f, -76.0f);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(24.0f, 4.0f, -76.0f);
	glEnd();
	//külsõ fal jobb
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -76.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, -1.0f, -76.0f);
	glTexCoord2f(1.0f, 0.62f); glVertex3f(-24.0f, 4.0f, -76.0f);
	glTexCoord2f(0.0f, 0.62f); glVertex3f(-4.0f, 4.0f, -76.0f);
	glEnd();
	//ajtókeret teteje
	glBindTexture(GL_TEXTURE_2D, texture[4]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, 4.0f, -76.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(4.0f, 4.0f, -76.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(4.0f, 4.0f, -75.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-4.0f, 4.0f, -75.0f);
	glEnd();
	//jobb ajtófélfa
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(4.0f, -1.0f, -76.0f);
	glTexCoord2f(0.5f, 0.0f); glVertex3f(4.0f, -1.0f, -75.0f);
	glTexCoord2f(0.5f, 2.0f); glVertex3f(4.0f, 7.0f, -75.0f);
	glTexCoord2f(0.0f, 2.0f); glVertex3f(4.0f, 7.0f, -76.0f);
	glEnd();
	//bal ajtófélfa
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-4.0f, -1.0f, -75.0f);
	glTexCoord2f(0.5f, 0.0f); glVertex3f(-4.0f, -1.0f, -76.0f);
	glTexCoord2f(0.5f, 2.0f); glVertex3f(-4.0f, 7.0f, -76.0f);
	glTexCoord2f(0.0f, 2.0f); glVertex3f(-4.0f, 7.0f, -75.0f);
	glEnd();
	//mezõ
	glBindTexture(GL_TEXTURE_2D, texture[18]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(18.0f, -1.0f, -175.0f);
	glTexCoord2f(12.0f, 0.0f); glVertex3f(18.0f, -1.0f, -25.0f);
	glTexCoord2f(12.0f, 3.0f); glVertex3f(40.0f, 5.0f, -25.0f);
	glTexCoord2f(0.0f, 3.0f); glVertex3f(40.0f, 5.0f, -175.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-18.0f, -1.0f, -90.0f);
	glTexCoord2f(12.0f, 0.0f); glVertex3f(-18.0f, -1.0f, -175.0f);
	glTexCoord2f(12.0f, 3.0f); glVertex3f(-40.0f, 5.0f, -175.0f);
	glTexCoord2f(0.0f, 3.0f); glVertex3f(-40.0f, 5.1f, -90.0f);
	glEnd();
	// víz alatti föld
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-60.0f, -1.5f, -45.0f);
	glTexCoord2f(5.0f, 0.0f); glVertex3f(60.0f, -1.5f, -45.0f);
	glTexCoord2f(5.0f, 5.0f); glVertex3f(60.0f, -1.5f, -185.0f);
	glTexCoord2f(0.0f, 5.0f); glVertex3f(-60.0f, -1.5f, -185.0f);
	glEnd();
	// víz
	glBindTexture(GL_TEXTURE_2D, texture[19]);
	glColor4f(1.0f, 1.0f, 1.0f, 0.5f);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-180.0f, -1.1f, -75.0f);
	glTexCoord2f(50.0f, 0.0f); glVertex3f(180.0f, -1.1f, -75.0f);
	glTexCoord2f(50.0f, 50.0f); glVertex3f(180.0f, -1.1f, -275.0f);
	glTexCoord2f(0.0f, 50.0f); glVertex3f(-180.0f, -1.1f, -275.0f);
	glEnd();
	//elsõ kinti ház tartó
	glBindTexture(GL_TEXTURE_2D, texture[25]);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -110.8f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -110.8f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.8f, 2.5f, -110.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.8f, 0.5f, -110.8f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.8f, 0.5f, -111.6f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.8f, 2.5f, -111.6f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -111.6f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -111.6f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -111.6f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -111.6f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -110.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -110.8f);
	glEnd();
	//hátsó kinti ház tartó
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -130.8f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -130.8f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.8f, 2.5f, -130.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.8f, 0.5f, -130.8f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -131.6f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -131.6f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -130.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -130.8f);
	glEnd();
	// középsõ kinti ház tartó
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -120.8f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -120.8f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.8f, 2.5f, -120.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.8f, 0.5f, -120.8f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -121.6f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -121.6f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-24.0f, 2.5f, -120.8f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-24.0f, 0.5f, -120.8f);
	glEnd();
	//oszlop1
	glBindTexture(GL_TEXTURE_2D, texture[3]);
	glBegin(GL_QUADS);

	glTexCoord2f(1.0f, 0.0f); glVertex3f(11.9f, -1.0f, -39.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(11.9f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10.1f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(10.1f, -1.0f, -39.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.1f, -1.0f, -41.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.1f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(11.9f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(11.9f, -1.0f, -41.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.1f, -1.0f, -39.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.1f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10.1f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(10.1f, -1.0f, -41.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(11.9f, -1.0f, -41.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(11.9f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(11.9f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(11.9f, -1.0f, -39.0f);
	glEnd();  //oszlop1 vége
			  //oszlop2
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(11.9f, -1.0f, -9.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(11.9f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10.1f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(10.1f, -1.0f, -9.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.1f, -1.0f, -11.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.1f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(11.9f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(11.9f, -1.0f, -11.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.1f, -1.0f, -9.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.1f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(10.1f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(10.1f, -1.0f, -11.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(11.9f, -1.0f, -11.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(11.9f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(11.9f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(11.9f, -1.0f, -9.0f);
	glEnd();  //oszlop2 vége
			  //oszlop3
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -9.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -9.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -11.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -11.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -9.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -11.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -11.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -11.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -9.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -9.0f);
	glEnd();  //oszlop3 vége
			  //oszlop4
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -39.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -39.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -41.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -41.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -39.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-11.9f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-11.9f, -1.0f, -41.0f);
	glEnd();

	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -41.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -41.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.1f, 7.1f, -39.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.1f, -1.0f, -39.0f);
	glEnd();  //oszlop4 vége
			  //pic left
	glBindTexture(GL_TEXTURE_2D, texture[15]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.9f, -0.5f, -40.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-17.9f, -0.5f, -45.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-17.9f, 5.5f, -45.0f);
	glTexCoord2f(0.f, 0.0f); glVertex3f(-17.9f, 5.5f, -40.0f);
	glEnd();
	//pic2 left
	glBindTexture(GL_TEXTURE_2D, texture[13]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-17.9f, 0.5f, 3.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(-17.9f, 0.5f, -3.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(-17.9f, 6.5f, -3.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-17.9f, 6.5f, 3.0f);
	glEnd();
	//pic3 right
	glBindTexture(GL_TEXTURE_2D, texture[21]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(17.9f, 0.5f, -34.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(17.9f, 0.5f, -30.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(17.9f, 6.5f, -30.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(17.9f, 6.5f, -34.0f);
	glEnd();
	//tükör
	glBindTexture(GL_TEXTURE_2D, texture[5]);
	glBegin(GL_QUADS);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(6.0f, 0.0f, 9.9f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-6.0f, 0.0f, 9.9f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-6.0f, 5.8f, 9.9f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(6.0f, 5.8f, 9.9f);
	glEnd();

	Guitar();
	Door_left();
	Door_right();
}

DrawScene::DrawScene()
{
}

DrawScene::~DrawScene()
{
}

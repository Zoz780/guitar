#ifndef DRAWSCENE_H
#define DRAWSCENE_H
#include "Model_drawer.h"
#include <stdio.h>
#include <SOIL.h>
#include <stdlib.h>
#include <glut.h>
#include <string>
#define _USE_MATH_DEFINES
#include <math.h>

class DrawScene
{

public:

	void LoadModel();

	void LoadTextures(int quality_in);

	void Draw_World_Pub(float guitar_rotateAngle, double left_doorAngle, double right_doorAngle);

	DrawScene();
	~DrawScene();

private:
	void SetQuality(int quality_in);
	void SetRotation(float guitar_rotateAngle, double left_doorAngle, double right_doorAngle);
	bool LoadWorldTextures();
	void Guitar();
	void Door_left();
	void Door_right();
	void Table();
	void Draw_World();
	GLuint texture[31];
	int quality;
	float guitar_rotate_angle;
	double left_door_angle = -90.0f;
	double right_door_angle = 90.0f;

};

#endif 

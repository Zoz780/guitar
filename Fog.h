#pragma once
#include <glut.h>
class Fog
{
public:
	void Init(void);

	void IncreaseFogIntensity();
	void DecreaseFogIntensity();

	Fog();

private:
	GLint fogMode;
	float fog_strt = 130.0f; 
	float fog_end = 140.0f;
};


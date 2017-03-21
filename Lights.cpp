#include "Lights.h"

GLfloat light_ambient_menu[] = { 0.8f,0.8f,0.8f,1.0f };
GLfloat light_diffuse[] = { 0.0f,0.1f,0.1f,1.0f };

void Lights::TurnOnLights()
{
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
}

void Lights::TurnONMenuLight()
{
	for (int i = 0; i < 3; i++) {
		light_ambient_menu[i] = 0.8f;
	}
}

void Lights::TurnOFFMenuLight()
{
	for (int i = 0; i < 3; i++) {
		light_ambient_menu[i] = 0.0f;
	}
}

void Lights::IncreaseLightIntensity()
{
	if (light_diffuse[1] < 1.0f) {
		for (int i = 0; i < 3; i++) {
			light_diffuse[i] += 0.1f;
		}
		light_diffuse[0] = 0.1f;
	}
}

void Lights::DecreaseLightIntensity()
{
	if (light_diffuse[1]>0.2) {
		for (int i = 0; i<3; i++) {
			light_diffuse[i] -= 0.1f;
		}
		light_diffuse[0] = 0.1f;
	}
}

void Lights::Light0()
{
	GLfloat light_position_front_left[] = { 101.0f, 120.0f, 90.0f, 1.0f };
	GLfloat light_direction[] = { -1.0f, -1.0f, -1.0f };
	GLfloat cut[] = { 3.2f };
	glLightfv(GL_LIGHT0, GL_POSITION, light_position_front_left);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, light_direction);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPOT_CUTOFF, cut);
}

void Lights::Light1()
{
	glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient_menu);
}

void Lights::Light2()
{
	GLfloat light_position_front_right[] = { 121.0f, 120.0f, 90.0f, 1.0f };
	GLfloat light_direction[] = { -1.0f, -1.0f, -1.0f };
	GLfloat cut[] = { 3.2f };
	glLightfv(GL_LIGHT2, GL_POSITION, light_position_front_right);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, light_direction);
	glLightfv(GL_LIGHT2, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT2, GL_SPOT_CUTOFF, cut);
}

void Lights::Light3()
{
	GLfloat light_position_back_left[] = { 101.0f, 120.0f, 120.0f, 1.0f };
	GLfloat light_direction[] = { -1.0f, -1.0f, -1.0f };
	GLfloat cut[] = { 3.2f };
	glLightfv(GL_LIGHT3, GL_POSITION, light_position_back_left);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, light_direction);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT3, GL_SPOT_CUTOFF, cut);
}

void Lights::Light4()
{
	GLfloat light_position_back_right[] = { 122.0f, 120.0f, 120.0f, 1.0f };
	GLfloat light_direction[] = { -1.0f, -1.0f, -1.0f };
	GLfloat cut[] = { 3.2f };
	glLightfv(GL_LIGHT4, GL_POSITION, light_position_back_right);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light_direction);
	glLightfv(GL_LIGHT4, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT4, GL_SPOT_CUTOFF, cut);
}

void Lights::Light5()
{
	GLfloat light_ambient[] = { 0.1f,0.1f,0.1f,1.0f };
	glLightfv(GL_LIGHT5, GL_AMBIENT, light_ambient);
}


Lights::Lights()
{
}



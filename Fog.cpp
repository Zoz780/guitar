#include "Fog.h"

void Fog::IncreaseFogIntensity()
{
	if (fog_strt < 170.0f)
	{
		fog_strt += 10.0f;
	}
	else {
		fog_strt = 170.0f;
	}
	if (fog_strt >= 140.0f)
		fog_end += 10.0f;
}

void Fog::DecreaseFogIntensity()
{
	if (fog_strt > 0.0f) {
		fog_strt -= 10.0f;
	}
	else {
		fog_strt = 0.0f;
	}
	if (fog_strt >= 140.0f)
		fog_end -= 10.0f;
}


void Fog::Init(void)
{
	GLfloat position[] = { 0.5, 0.5, 3.0, 0.0 };
	float fog_r = 0.7f, fog_g = 0.7f, fog_b = 0.7f;
	glEnable(GL_DEPTH_TEST);
	glHint(GL_LINE_SMOOTH_HINT, GL_DONT_CARE);
	glEnable(GL_FOG);
	{
		GLfloat fogColor[4] = { 0.7f, 0.7f, 0.7f, 0.0000001f };
		fogMode = GL_LINEAR;
		glFogi(GL_FOG_MODE, fogMode);
		glFogfv(GL_FOG_COLOR, fogColor);
		glFogf(GL_FOG_DENSITY, 0.0001);
		glHint(GL_FOG_HINT, GL_DONT_CARE);
		glFogf(GL_FOG_START, fog_strt);
		glFogf(GL_FOG_END, fog_end);
	}
	glClearColor(fog_r, fog_g, fog_b, 0.1);  /* fog color */
}

Fog::Fog()
{
}



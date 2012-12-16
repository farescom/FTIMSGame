#pragma once

#define WIN32_LEAN_AND_MEAN

#include <windows.h>					// standardowy plik nag³ówkowy Windows 
#include <winuser.h>					// Windows constants
#include <gl/gl.h>						// standardowy plik nag³ówkowy OpenGL 
#include <gl/glu.h>						// funkcje pomocnicze OpenGL 

/*******************************************************/
// ENGINE
/*******************************************************/

#include "MemList.h"
#include "MemVector.h"

#include "Input.h"
#include "CTimer.h"

#include "State.h"
#include "StateManager.h"

/*******************************************************/
// SYSTEM
/*******************************************************/

void SetupPixelFormat(HDC hDC);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pScmdline, int iCmdshow);
LRESULT CALLBACK WndProc( HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam );
bool InitializeOpenGL();

extern HDC       g_HDC;					// globalny kontekst urz¹dzenia

namespace Engine
{
	extern int g_height,
				g_width;
	extern bool g_fullScreen;
	extern float g_aspect;

	bool preInitialize();
	bool initialize();
	bool update();
	void shutdown();
	void render();
}

/*******************************************************/
// ENGINE
/*******************************************************/

union SColor
{
	float rgba[4];
	struct
	{
		float r, g, b, a;
	};

	SColor( float rgba[4] )
	{
		rgba[0] = rgba[0];
		rgba[1] = rgba[1];
		rgba[2] = rgba[2];
		rgba[3] = rgba[3];
	}

	SColor( float r, float g, float b, float a=1.0f ) : r(r), g(g), b(b), a(a) {}

	SColor( SColor& color )
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
	}
};

#include "Texture.h"
#include "Camera.h"
#include "TextFont.h"
#include "Draw.h"

using namespace Engine;

/* TODO:
	o Poprawiæ sprawdzanie stanu przycisków i myszy (CInput - Press, Release, Mouse)
	o Dodaæ mo¿liwoœæ wyœwietlania zmiennych na ekranie
	o Dodaæ sprite'y + animacjê + AObject + CObjectDefinition
	o Poprawiæ CTimer
*/
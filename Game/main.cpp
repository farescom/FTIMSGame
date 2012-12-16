#include "gameHeader.h"

float pos[2] = { 0.0f, -0.5f };
float posB[2] = { 2.0f, -0.5f };
float posKulka[2] = { 0.5f, -0.5f };
bool dirKulka[2] = { true, true };
bool start = false;
CTexture wood;

MenuState menuState;

bool Engine::preInitialize()
{
	return true;
}

bool Engine::initialize()
{
	glDisable( GL_CULL_FACE );

	if( wood.Load("../Data/Textures/wood.bmp") == false )
		return false;

	return true;
}

void Engine::shutdown()
{
	wood.Shutdown();
}

bool Engine::update()
{
	if( GInput::KHit( VK_ESCAPE ) )
		return false;

	if( GInput::KHit( 'g' ) )
		start = true;

	if( GInput::KHit( 'n' ) )
		GStateManager::setState( &menuState );

	if( start == false )
	{
		return true;
	}

	static float speed = 0.02f;
	static float paletteSpeed = 0.04f;

	if( GInput::KHit( 'o' ) )
	{
		posB[1] += paletteSpeed;
	}
	if( GInput::KHit( 'l' ) )
	{
		posB[1] -= paletteSpeed;
	}
	if( GInput::KHit( 's' ) )
	{
		pos[1] -= paletteSpeed;
	}
	if( GInput::KHit( 'w' ) )
	{
		pos[1] += paletteSpeed;
	}

	if( dirKulka[0] == true )
	{
		posKulka[0] += speed;
	}
	else
	{
		posKulka[0] -= speed;
	}

	if( dirKulka[1] == true )
	{
		posKulka[1] += speed;
	}
	else
	{
		posKulka[1] -= speed;
	}

	if( posKulka[1] > 0.0f )
	{
		dirKulka[1] = false;
	}
	if( posKulka[1] < -1.9f )
	{
		dirKulka[1] = true;
	}

	if( pos[1] > posKulka[1] && posKulka[1] > pos[1] -0.4f && posKulka[0] < 0.1f )
	{
		dirKulka[0] = true;
	}

	if( posB[1] > posKulka[1] && posKulka[1] > posB[1] -0.4f && posKulka[0] > 2.4f  )
	{
		dirKulka[0] = false;
	}

	if( posKulka[0] < 0.0f || posKulka[0] > 2.7f )
	{
		posKulka[0] = 0.5f;
		start = false;
	}

	return true;
}

void Engine::render()
{
	GCamera::lookAt();

	wood.Render();
	GDraw::rectf( SColor( 1.0f, 1.0f, 1.0f ), 0.0f, pos[1], 0.1f, -0.4f );
	GDraw::rectf( SColor( 1.0f, 1.0f, 1.0f ), 2.5f, posB[1], 0.1f, -0.4f );
	GDraw::rectf( SColor( 1.0f, 1.0f, 1.0f ), posKulka[0], posKulka[1], 0.1f, -0.1f );

	if( start == true )
	{
		GDraw::textf( SColor( 1.0f, 1.0f, 1.0f ), 1.1f, -0.2f, "Press ESC to exit!" );
	}
	else
	{
		GDraw::textf( SColor( 1.0f, 1.0f, 1.0f ), 1.1f, -0.2f, "Press G to start!" );
	}
	//GDraw::textf( SColor( 1.0f, 1.0f, 1.0f ), 1.1f, -1.2f, "Time: " + GTimer.a() );
}
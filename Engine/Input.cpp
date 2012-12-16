// Plik: CInput.cpp
// Opis: Klasa sterowania (klawiatura + myszka)

#include "Engine.h"

bool CInput::keys[256]; // jako static jest inicjalizowane na zero
bool CInput::keysPress[256];
bool CInput::keysRelease[256];
bool CInput::specialKeys[18];
int CInput::mouseMotionBuffer[2];
int CInput::mousePosition[2];
bool CInput::mouseButtons[3];
bool CInput::mouseButtonsPress[3];
bool CInput::mouseButtonsRelease[3];
bool CInput::m_mouseEnabled = true;

CInput::CInput(void)
{
}


CInput::~CInput(void)
{
}


void CInput::Initialize()
{
}

void CInput::Update()
{
	for( int i=0; i<256; i++ )
	{
		if( keysPress[i] )
			keysPress[i] = false;

		if( keysRelease[i] )
			keysRelease[i] = false;
	}

	for( int i=0; i<3; i++ )
	{
		mouseButtonsPress[i] = false;
		mouseButtonsRelease[i] = false;
	}

	#pragma message( __FILE__ ": Poprawiæ Press / Release" )
}

void CInput::KeyDown( unsigned char keycode )
{
	keys[int(keycode)] = true;
	keysPress[keycode] = true;
}

void CInput::KeyUp( unsigned char keycode )
{
	keys[int(keycode)] = false;
	keysRelease[keycode] = true;
}

bool CInput::KHit( unsigned char keycode )
{
	return keys[ int(keycode) ];
}

bool CInput::MHit( int button )
{
	return mouseButtons[button];
}

bool CInput::KPress( char key )
{
	return keysPress[key];
}

bool CInput::KRelease( char key )
{
	return keysRelease[key];
}

bool CInput::MPress( int button )
{
	return mouseButtonsPress[ button ];
}

bool CInput::MRelease( int button )
{
	return mouseButtonsRelease[ button ];
}

//int CInput::Mouse( Eenum direction )
//{
//	if( !m_mouseEnabled )
//		return 0;
//
//	int result = 0;
//
//	switch( direction )
//	{
//	case E_VERTICAL:
//		result = mouseMotionBuffer[1];
//		mouseMotionBuffer[1] = 0;
//		return result;
//
//	case E_HORIZONTAL:
//		result = mouseMotionBuffer[0];
//		mouseMotionBuffer[0] = 0;
//		return result;
//	}
//
//	return 0;
//}

void CInput::MouseGet( int &x, int &y )
{
	x = mousePosition[0];
	y = mousePosition[1];
}

void CInput::MouseOn()
{
	m_mouseEnabled = true;
}

void CInput::MouseOff()
{
	m_mouseEnabled = false;
}

//void CInput::MouseSet( int x, int y )
//{
//	CInput::MouseMotion( x, y );
//	CInput::MouseMotion( x, y );
//}

void CInput::MouseMotion( int x, int y )
{
	mouseMotionBuffer[0] = x - mousePosition[0];
	mouseMotionBuffer[1] = y - mousePosition[1];

	mousePosition[0] = x;
	mousePosition[1] = y;
}

void CInput::MouseButton( int button, bool state )
{
	if( state == true )
	{
		mouseButtons[ button ] = true;
		mouseButtonsPress[ button ] = true;
	}
	else
	{
		mouseButtons[ button ] = false;
		mouseButtonsRelease[ button ] = true;
	}
}
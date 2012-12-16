// Plik: InputClass.h
// Opis: Klasa sterowania (klawiatura + myszka)

#pragma once

// Zmienna globalna, wystêpuj¹ca raz po zadeklarowaniu

// Deklaracja klasy
class CInput
{
public:
	CInput(void);
	~CInput(void);

	static void Initialize();
	static void Update();

	static bool KHit( unsigned char keycode );
	static bool MHit( int button );
	static bool KPress( char key );
	static bool KRelease( char key );
	static bool MPress( int button );
	static bool MRelease( int button );
	//int Mouse( Eenum direction );
	static void MouseGet( int &x, int &y );
	static void MouseOn();
	static void MouseOff();
	/*void MouseSet( int x, int y );*/

private:
	static void KeyDown( unsigned char key );
	static void KeyUp( unsigned char key );
	static void MouseMotion( int x, int y );
	static void MouseButton( int button, bool state );

private:
	static bool m_mouseEnabled;
	static bool keys[256]; // jako static jest inicjalizowane na zero
	static bool keysPress[256];
	static bool keysRelease[256];
	static bool specialKeys[18];
	static int mouseMotionBuffer[2];
	static int mousePosition[2];
	static bool mouseButtons[3];
	static bool mouseButtonsPress[3];
	static bool mouseButtonsRelease[3];

	friend LRESULT CALLBACK WndProc( HWND hwnd, UINT umessage, WPARAM wparam, LPARAM lparam );
};

typedef CInput GInput;
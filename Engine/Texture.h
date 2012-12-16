// Plik: CTexture.h
// Opis: Klasa tekstury, wczytywanie, renderowanie

#pragma once

// Pliki nag³ówkowe
#include <fstream>
#include <iostream>

#define BITMAP_ID 0x4D42		// identyfikator formatu BMP

// Deklaracja klasy
class CTexture
{
public:
	CTexture(void);
	~CTexture(void);

	virtual bool Load( const char* filepath );
	void Shutdown();
	void Render();

protected:
	bool LoadFile( const char* filepath );

protected:
	BITMAPINFOHEADER m_bih;
	unsigned char* m_bitmapData;
	GLuint m_textureID;

};


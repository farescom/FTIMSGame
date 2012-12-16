#include "Engine.h"


CTexture::CTexture(void)
{
}


CTexture::~CTexture(void)
{
}

bool CTexture::Load( const char* filepath )
{
	if( !LoadFile( filepath ) )
		return false;

	glGenTextures( 1, &m_textureID );
	glBindTexture( GL_TEXTURE_2D, m_textureID );

	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR_MIPMAP_LINEAR );
	glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR );

	// Zakomentowane zwyk³e teksturowanie, uruchomione mipmapy
	//glTexImage2D( GL_TEXTURE_2D, 0, GL_RGB, m_bih.biWidth, m_bih.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, m_bitmapData );
	gluBuild2DMipmaps( GL_TEXTURE_2D, 3, m_bih.biWidth, m_bih.biHeight, GL_RGB, GL_UNSIGNED_BYTE, m_bitmapData );

	this->Shutdown();

	return true;
}

bool CTexture::LoadFile( const char* filepath )
{
	BITMAPFILEHEADER bfh;

	// Uchwyt do pliku
	std::ifstream fin;

	// Otwieramy plik w trybie binarnym
	fin.open( filepath, std::ios::binary );
	if( !fin.good() )
		return false;

	// Wczytywanie Bitmap File Header
	fin.read( (char*)&bfh, sizeof( BITMAPFILEHEADER ) );

	// Czy plik jest typu BMP
	if( bfh.bfType != BITMAP_ID )
	{
		fin.close();
		return false;
	}

	// Wczytanie Bitmap Info Header
	fin.read( (char*)&m_bih, sizeof( BITMAPINFOHEADER ) );
	// Przestawienie "szperacza" na dane obrazu
	fin.seekg( bfh.bfOffBits );

	// Zaalokowanie pamiêci na obraz
	m_bitmapData = new unsigned char[ m_bih.biSizeImage ];

	// Wczytanie danych obrazu
	fin.read( (char*)m_bitmapData, m_bih.biSizeImage );

	// Zamiana sk³adowych R i B miejscami
	for( unsigned int i=0; i<m_bih.biSizeImage; i+=3 )
	{
		// XOR Swap - patent Krzysia :D
		m_bitmapData[ i ] = m_bitmapData[ i ] ^ m_bitmapData[ i+2 ];
		m_bitmapData[ i+2 ] = m_bitmapData[ i+2 ] ^ m_bitmapData[ i ];
		m_bitmapData[ i ] = m_bitmapData[ i ] ^ m_bitmapData[ i+2 ];
	}

	// Zamykamy plik
	fin.close();

	return true;
}

void CTexture::Shutdown()
{
	if( m_bitmapData )
	{
		delete [] m_bitmapData;
		m_bitmapData = 0;
	}
}

void CTexture::Render()
{
	glBindTexture( GL_TEXTURE_2D, m_textureID );
}
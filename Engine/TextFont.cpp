#include "Engine.h"

CTextFont::CTextFont(void) : m_base( 0 )
{
}

CTextFont::CTextFont( LPCWSTR fontName, int fontSize )
{
	m_base = 0;
	if( create( fontName, fontSize ) == false )
	{
		shutdown();
	}
}

CTextFont::~CTextFont(void)
{
	shutdown();
}

bool CTextFont::create( LPCWSTR fontName, int fontSize )
{
	if( m_base != 0 )
	{
		return false;
	}

	HFONT hFont;
	
	m_base = glGenLists(96);

	hFont = CreateFont( fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE,
						 ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS,
						 ANTIALIASED_QUALITY, FF_DONTCARE | DEFAULT_PITCH, fontName );

	if( !hFont )
	{
		return false;
	}

	SelectObject( g_HDC, hFont );
	wglUseFontBitmaps( g_HDC, 32, 96, m_base );

	return true;
}

void CTextFont::shutdown()
{
	if( m_base != 0 )
	{
		glDeleteLists( m_base, 96 );
		m_base = 0;
	}
}
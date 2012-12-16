#include "Engine.h"


CDraw::CDraw(void)
{
}

CDraw::~CDraw(void)
{
}

void CDraw::rectf( SColor& color, float x, float y, float width, float height )
{
	glPushMatrix();
	{
		glColor4f( color.r, color.g, color.b, color.a );

		glTranslatef( x, y, 0.0f );

		glBegin( GL_QUADS );
		{
			glTexCoord2f( 0.0f, 0.0f );
			glVertex2f( 0.0f, 0.0f );

			glTexCoord2f( 0.0f, 1.0f );
			glVertex2f( 0.0f, height );

			glTexCoord2f( 1.0f, 1.0f );
			glVertex2f( width, height );

			glTexCoord2f( 1.0f, 0.0f );
			glVertex2f( width, 0.0f );
		}
		glEnd();
	}
	glPopMatrix();
}

void CDraw::recti( SColor& color, short x, short y, short width, short height )
{
	rectf( color, float(x)/float(Engine::g_width), float(y)/float(Engine::g_height), float(width)/float(Engine::g_width), float(height)/float(Engine::g_height) );
}

void CDraw::linef( SColor& color, float x1, float y1, float x2, float y2 )
{
	glDisable( GL_TEXTURE_2D );

	glColor4f( color.r, color.g, color.b, color.a );

	glBegin( GL_LINES );
	{
		glVertex2f( x1, y1 );
		glVertex2f( x2, y2 );
	}
	glEnd();

	glEnable( GL_TEXTURE_2D );
}

void CDraw::linei( SColor& color, short x1, short y1, short x2, short y2 )
{
	linef( color, ( float(x1)/float(Engine::g_width) ) * ( g_aspect * 2.0f ), ( float(y1)/float(Engine::g_height) ) * ( 2.0f ), ( float(x2)/float(Engine::g_width) ) * ( g_aspect * 2.0f ), ( float(y2)/float(Engine::g_height) ) * ( 2.0f ) );
}

void CDraw::textf( SColor& color, float x, float y, char* text, CTextFont& textFont )
{
	glDisable( GL_TEXTURE_2D );
	
	glColor4f( color.r, color.g, color.b, color.a );

	glRasterPos3f( x, y, 0.1f );

	if( textFont.m_base != 0 && text != NULL )
	{
		glPushAttrib( GL_LIST_BIT );
		{
			glListBase( textFont.m_base - 32 );
			glCallLists( strlen(text), GL_UNSIGNED_BYTE, text );
		}
		glPopAttrib();
	}

	glEnable( GL_TEXTURE_2D );
}

void CDraw::texti( SColor& color, short x, short y, char* text, CTextFont& textFont )
{
	CDraw::textf( color, ( float(x)/float(Engine::g_width) ) * ( g_aspect * 2.0f ), ( float(y)/float(Engine::g_height) ) * ( 2.0f ), text, textFont );
}
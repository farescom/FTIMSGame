#pragma once

class CDraw
{
public:
	CDraw(void);
	~CDraw(void);

	static void rectf( SColor& color, float x, float y, float width, float height );
	static void recti( SColor& color, short x, short y, short width, short height );

	static void linef( SColor& color, float x1, float y1, float x2, float y2 );
	static void linei( SColor& color, short x1, short y1, short x2, short y2 );

	static void textf( SColor& color, float x, float y, char* text, CTextFont& textFont = defaultTextFont );
	static void texti( SColor& color, short x, short y, char* text, CTextFont& textFont = defaultTextFont );

};

typedef CDraw GDraw;
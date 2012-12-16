#pragma once
class CTextFont
{
public:
	CTextFont(void);
	CTextFont::CTextFont( LPCWSTR fontName, int fontSize );
	~CTextFont(void);

	bool create( LPCWSTR fontName, int fontSize );
	void shutdown();

private:
	unsigned int m_base;

	friend class CDraw;
};

extern CTextFont defaultTextFont;

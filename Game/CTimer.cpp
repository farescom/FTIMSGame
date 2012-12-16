// Plik: CTimer.cpp
// Opis: Klasa Timera, FPS, czas gry, czas programu itd.

#include "Engine.h"


CTimer::CTimer(void)
{
	m_a = 0.0f;
	m_abuf = 0.0f;
	m_fps = 0.0f;
	m_d = 0.0f;
}


CTimer::~CTimer(void)
{
}

float CTimer::fps()
{
	return m_fps;
}

float CTimer::a()
{
	return m_a;
}

float CTimer::d()
{
	return m_d;
}

bool CTimer::update()
{
	m_abuf = m_a;
	m_a = (float)clock() / (float)CLOCKS_PER_SEC;
	m_d = m_a - m_abuf;
	m_fps = 1.0f / m_d;

	return true;
}

// Plik: TimerClass.h
// Opis: Klasa Timera, FPS, czas gry, czas programu itd.

#pragma once

#include <time.h>

class CTimer
{
public:
	CTimer(void);
	~CTimer(void);

	float fps();	// Frame per second
	float a();		// Application time
	float d();		// Delta time in seconds

	bool update();

private:
	float	m_fps,
			m_a, m_abuf,
			m_d;

};

extern CTimer GTimer;


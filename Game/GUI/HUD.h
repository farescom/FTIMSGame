#ifndef GUI_H_U_D_H
#define GUI_H_U_D_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

//#include "engine/Map.h"
//#include "objects/Player.h"

namespace gui
{
class HUD
{
private:
	//Engine::Map* map;

	//objects::Player player; tego raczej nie bedzie w naszem hudzie. informacje o playerze beda wczytywane na bierzaco z ... chyba silnika albo obiektow ;)
	
	double HUDsize;

private:
	void renderFocus();

	void renderExamDates();

	void renderNotes();

	void renderMinimap();

	void renderBackpack();

public:
	HUD();//engine::Map* map);

	virtual ~HUD()=0;

	void render();

};

}  // namespace gui
#endif

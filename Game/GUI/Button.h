#ifndef GUI_BUTTON_H
#define GUI_BUTTON_H

#include <windows.h>

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

//#include "engine/Sprite.h"
//#include "gui/Component.h"

using namespace std;

namespace gui
{
class Button// : public Component
{
private:
	string caption;

	//Engine::Sprite* pressed;
	//Engine::Sprite* sprite;

	bool wasClicked;

	void (*function)();

public:
	Button(int x, int y, int width, int height,  string caption);//, Engine::Sprite* sprite, Engine::Sprite* pressed, void (*buttonFunction)());

	virtual ~Button()=0;

	virtual void clicked();

	string getCaption();

	void setCaption(string caption);

	virtual void render();

};

}  // namespace gui
#endif

#ifndef GUI_TEXT_FIELD_H
#define GUI_TEXT_FIELD_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

//#include "engine/EngineEnums.h"
//#include "gui/Component.h"

using namespace std;

namespace gui
{
class TextField// : public Component
{
private:
	string text;


public:
	TextField(int x, int y, int width, int height, string text);

	virtual ~TextField()=0;

	string getText();

	void setText(string text);

	virtual void keyPressed(char key);

	virtual void render();

};

}  // namespace gui
#endif

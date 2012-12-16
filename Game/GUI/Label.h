#ifndef GUI_LABEL_H
#define GUI_LABEL_H

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

//#include "glutfonts.c"

//#include "gui/Component.h"

using namespace std;

namespace gui
{
class Label// : public Component
{
protected:
	string caption;


public:
	Label(int x, int y, int width, int height, string caption);

	virtual ~Label()=0;

	string getCaption();

	void setCaption(string caption);

	virtual void render();

};

}  // namespace gui
#endif

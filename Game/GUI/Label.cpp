#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>


//#include "C:\Users\Adam\Dropbox\Projekty Adam Ok³a, Daniel Sobczak\projekt GRA\gui\glutfonts.c"

#include "Label.h"

namespace gui
{

Label::Label(int x, int y, int width, int height, string caption)
{
    //this->x=x;
    //this->y=y;
    //this->width=width;
    //this->height=height;

    Label::caption=caption;
}

string Label::getCaption()
{
	return Label::caption;
}

void Label::setCaption(string caption)
{
    Label::caption=caption;
}

void Label::render()
{
	//Engine::jakisRenderPewnie.Prostokat(x,y,width,height, getCaption(), "moze_jakis_kolor");
}


}  // namespace gui

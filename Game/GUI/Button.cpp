#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "Button.h"

namespace gui
{



Button::Button(int x, int y, int width, int height,  string caption)//, engine::sprite sprite, engin::sprite pressed, void (*buttonFunction)())
    {
	//function=buttonFunction;
	wasClicked=false;

    //this->x=x;
    //this->y=y;
    //this->width=width;
    //this->height=height;

    this->caption=caption;
	//this->sprite=sprite;
	//this->pressed=pressed;
    }

string Button::getCaption()
{
	return Button::caption;
}

void Button::setCaption(string caption)
{
    Button::caption=caption;
}
void Button::clicked()
{
	if(wasClicked==true) wasClicked=false;
    else wasClicked=true;

	function();
}


void Button::render()
{
    

    //rysunek
    if(wasClicked==false)
    {
        //Engine::jakisRenderPewnie.Prostokat(x,y,width,height, getCaption(), sprite);
    }
    else
    {
        //Engine::jakisRenderPewnie.Prostokat(x,y,width,height, getCaption(), pressed);


    }

  
}

}  // namespace gui

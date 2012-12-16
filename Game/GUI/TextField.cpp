#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

#include "TextField.h"

namespace gui
{

TextField::TextField(int x, int y, int width, int height, string text)
{
    //this->x=x;
    //this->y=y;
    //this->width=width;
    //this->height=height;

    TextField::text = text;

}

string TextField::getText()
{
	return TextField::text;
}

void TextField::setText(string text)
{
    TextField::text=text;

}

void TextField::keyPressed(char key)
{
setText(getText()+key);
     // to ma improzwizowaæ jakieœ dopisywanie czegoœ do tekstu. np jak piszemy po literce: M a r e k
														//gada³em o tym z Silnikiem Adamem :D dojdziemy do porozumienia w tej sprawie
														


}

void TextField::render()
{
 //Engine::jakisRenderPewnie.Prostokat(x,y,width,height, getText(), sprite);

}
}  // namespace gui

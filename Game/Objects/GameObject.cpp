#include "GameObject.h"
#include "Collisions.h"
#include <cmath>


GameObject::GameObject()
{
	state=0;
}

GameObject::GameObject(int width,int heigth) //testowy
{
	gravity=1;
	jumpspeed=0;
	speedX=0;
	speedY=0;
	state =0;
	this->width=width;
	this->heigth=heigth;
}

GameObject::GameObject(Script* script)
{
	this->script=script;
}

GameObject::~GameObject(void)
{
}

int GameObject::getState()
{
	return state;
}

void GameObject::setState(int state)
{
	this->state=state;
}

float GameObject::getX()
{
	return x;
}

void GameObject::setX(float x)
{
	this->x = x;
}

float GameObject::getY()
{
	return y;
}

void GameObject::setY(float y)
{
	this->y=y;
}

float GameObject::getoldX()
{
	return old_x;
}

void GameObject::setoldX(float old_x)
{
	this->old_x = old_x;
}

float GameObject::getoldY()
{
	return old_y;
}

void GameObject::setoldY(float old_y)
{
	this->old_y=old_y;
}

float GameObject::getSpeedY()
{
	return speedY;
}

float GameObject::getSpeedX()
{
	return speedX;
}

void GameObject::setSpeedX(float speedX)
{
	this->speedX=speedX;
}

void GameObject::setSpeedY(float speedY)
{
		this->speedY=speedY;
}

void GameObject::jump()
{
        state=1;
        jumpspeed = -20; //to powinno byc speedY
}

void GameObject::move_left()
{
        state=2;
}

void GameObject::move_right()
{
        state=3;
}

void GameObject::render()
{ //tu tez do konca nie pamietam co mialobyc 
	//Obj::render(blabla)
}

//grawitacja , skok, i ruch zrobione sa "prowizorycznie" niezgodnie z prawami fizyki , tzn nie uwzgledniaja czasu. Zrobione jest to na sztywno tak zeby niedociagniecia nie byly zbyt widoczne, bede to poprawiac na finalna wersje .

void GameObject::update()
{	
	cout <<x<<" "<<y<<"\n";

	if (state == 0)
	{
		//render(stand,0,5)? render klatki od 0,5 dla stand, ale skad wie jakiego obiektu sprity?  <--nie pamietam jakto mialo wygladac xd
	}

	//gravity
	if (state != 1)
	{
		//render(blabla)
		y+=gravity;
		gravity+=5;
		if (gravity > 20)
		{
			gravity = 20; 
		}
		
	}

	if (state==1) //tak samo tu speedY
		{
			//render(blabla)
			y += jumpspeed;
			jumpspeed += 5;
			if (jumpspeed >= 0)
				//max jump, start fall
				{
			      state=0;
				}
		}

	if (state==2) //lewo
		{
			//render(blabla)
			speedX+=5; //zamiast 5 speedX .. etc , wazne zeby na ten moment cos dzialalo :P
			x-= speedX;
			if (speedX >=20)
			{
				speedX=0;
				state=0;
			}
		}
	if (state==3) //prawo
		{
			//render(blabla)
			speedX+=5;
			x+= speedX;
			if (speedX >=20)
			{
				speedX=0;
				state=0;
			}
		}
	//script.parseUpdate();

	//tu powinnobyc detectCllisions

}


#include "Person.h"


Person::Person()
{
	helditem = NULL;
}


Person::Person(Script *script)
	:GameObject(script)
{
	
	helditem = NULL;
}


Person::~Person(void)
{
}


void Person::holditem(Throwable* item)
{
		helditem = item;
		helditem->setX(x);
		helditem->setY(y+30);
}


void Person::throwitem()
{
	double g = 9.81;
	helditem->setX(helditem->getSpeedX()*sqrt(2*(helditem->getY())/g)); //leci prosto
	//helditem->setY - spada na ziemie. 
}


/*void Person::moveLeft();
{
}


void Person::moveRight();
{
}


void Person::Jump();
{
}*/


void Person::render()
{
		
}


void Person::update()
{
		GameObject::update();
		//tu state == 4 - throw, jak dorobie rzucanie..
}
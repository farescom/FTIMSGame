#pragma once
#include "GameObject.h"
#include "Throwable.h"
class Person :
	public GameObject
{
protected:
	Throwable* helditem;
public:
	Person();
	Person(Script *script);
	~Person(void);
	void holditem(Throwable* item);
	void throwitem();
	/*void moveLeft();
	void moveRight();
	void Jump();*/
	void render();
	void update();
};


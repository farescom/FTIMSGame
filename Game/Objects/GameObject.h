#pragma once
#include "Script.h"
#include "Obj.h"
#include <iostream>

class GameObject :
	public Obj
{
private:
	Script* script;
protected:
	int state;		// 0- stand , 1 - jump , 2 - move left , 3 - move right (0,2,3 includes gravity);
	float x;
	float y;
	float old_x;
	float old_y;
	float speedX;
	float speedY;
	float gravity;
	float jumpspeed;
public:
	GameObject();
	GameObject(int width, int heigth); //kostruktor testowy potrzebna byla wysokosc i szerokosc obiektu
	GameObject(Script* script);
	virtual ~GameObject();
	int getState();
	void setState(int state);
	float getX();
	void setX(float x);
	float getY();
	void setY(float y);
	float getoldX();
	void setoldX(float x);
	float getoldY();
	void setoldY(float y);
	float getSpeedY();
	float getSpeedX();
	void setSpeedX(float speedX);
	void setSpeedY(float speedY);
	void jump();
	void move_left();
	void move_right();
	void render();
	void update();
	
};


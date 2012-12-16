#include "Player.h"


Player::Player(void)
{
	numNotes = 0;
	examDates = 3;
	focus = 100;
	for (int i = 0 ; i<10 ; i++)
		backpack[i]=NULL;

}


Player::~Player(void)
{

}


void Player::removeItem(Pickable* item)
{
	for (int i = 0 ; i<10 ; i++)
		if (backpack[i] == item) backpack[i]=NULL;
}


void Player::setFocus(float focus)
{
	this->focus=focus;
}


float Player::getFocus()
{
		return focus;
}


void Player::addItem(Pickable* item)
{
		for (int i = 0 ; i<10 ; i++)
			if (backpack[i] == NULL) backpack[i]=item;
}


void Player::setExamDates(int dates)
{
	examDates=dates;
}


int Player::getExamDates()
{
	return examDates;
}


void Player::setNumNotes(int num)
{
		numNotes = num;
}


int Player::getNumNotes()
{
		return numNotes;
}

void Player::update()
{
	setFocus(-0.1); //zmniejszaj focus co obrot petli xd 
	Person::update(); //updatuj cala reszte
}
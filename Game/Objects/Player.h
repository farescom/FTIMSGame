#pragma once
#include "person.h"
#include "Pickable.h"
class Player :
	public Person
{
private:
	Pickable* backpack[10];
	int numNotes;
	int examDates;
	float focus;
public:
	Player(void);
	~Player(void);
	void removeItem(Pickable* item);
	void setFocus(float focus);
	float getFocus();
	void addItem(Pickable* item);
	void setExamDates(int dates);
	int getExamDates();
	void setNumNotes(int num);
	int getNumNotes();
	void update();
		
};


#pragma once
#include "GameObject.h"
#include <vector>
using namespace std;
class Map
{
public:
	Map(void);
	~Map(void);
	vector <GameObject*> objects;
	int heigth;
	int width;
	int getWidth(void);
	int getHeigth(void);
};

//klasa na potrzeby kompilowania.
#include "Map.h"


Map::Map(void)
{
	// testowa mapa i testowe obiekty.
	width = 700;
	heigth = 700;
	objects.push_back(new GameObject(250,50));
	objects.push_back(new GameObject(50,50));
	objects.push_back(new GameObject(250,50));
	objects[0]->setState(5);
	objects[0]->setX(450);
	objects[0]->setY(50);
	objects[0]->setoldX(450);
	objects[0]->setoldY(50);
	objects[0]->id=1;
	objects[1]->setX(450);
	objects[1]->setY(250);
	objects[1]->setoldX(450);
	objects[1]->setoldY(250);
	objects[1]->id=2;
	objects[2]->setX(450);
	objects[2]->setY(450);
	objects[2]->id=3;
	objects[2]->setState(5);
	objects[2]->setoldX(450);
	objects[2]->setoldY(450);

}


Map::~Map(void)
{
}


int Map::getWidth()
{
return width;
}


int Map::getHeigth()
{
	return heigth;
}
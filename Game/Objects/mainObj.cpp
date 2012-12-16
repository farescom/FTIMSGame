#include <iostream>
#include "Collisions.h"
#include "Consumable.h"

int main (){

	Collisions kolizja;
	Map *mapa = new Map();
	kolizja.setMap(mapa);

	mapa->objects[1]->update();
	kolizja.detectCollisions();
	mapa->objects[1]->update();
	kolizja.detectCollisions();
	mapa->objects[1]->update();
	kolizja.detectCollisions();
	mapa->objects[1]->update();
	kolizja.detectCollisions();
	mapa->objects[1]->update();
	kolizja.detectCollisions();
	mapa->objects[1]->update();
	kolizja.detectCollisions();
	mapa->objects[1]->update();
	kolizja.detectCollisions();
	mapa->objects[1]->update();
	kolizja.detectCollisions();
	mapa->objects[1]->update();
	kolizja.detectCollisions();
	mapa->objects[1]->update();
	kolizja.detectCollisions();
	mapa->objects[1]->update();
	kolizja.detectCollisions();
	mapa->objects[1]->update();
	kolizja.detectCollisions();
mapa->objects[1]->update();
kolizja.detectCollisions();
mapa->objects[1]->update();
mapa->objects[1]->move_left();
kolizja.detectCollisions();
mapa->objects[1]->update();
kolizja.detectCollisions();
mapa->objects[1]->update();
kolizja.detectCollisions();
mapa->objects[1]->update();
kolizja.detectCollisions();
mapa->objects[1]->update();
kolizja.detectCollisions();
mapa->objects[1]->update();
kolizja.detectCollisions();
mapa->objects[1]->update();
kolizja.detectCollisions();
mapa->objects[1]->update();
kolizja.detectCollisions();
mapa->objects[1]->update();
kolizja.detectCollisions();
mapa->objects[1]->update();
kolizja.detectCollisions();
mapa->objects[1]->update();
	
	//kolizja.detectCollisions();
	
	system("PAUSE");

	return 0;

}

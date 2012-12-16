#include "MapView.h"

//void MapView::addObject(ObjectDefinition *definition, float x,float y)
//{
//	Objekt obiektTymczasowy=new GameObjekt();
//	obiektTymczasowy.setX(x);
//	obiektTymczasowy.setY(y);
//	map->addObject(&definition,x,y);	//w klasie Map brakuje tablicy, wektora, listy, czy czegos podobnego przechowujacego obiekty GameObject
//}
//void MapView::removeObject(GameObject *object)
//{
//}
//void MapView::setTile(Sprite *sprite,int x,int y)
//{
//	map->addTile(&sprite,x,y); //jako ze tablica tiles jest prywatna zak³adamy ¿e powstanie metoda umozliwiajaca dodanie elementu do niej 
//}
void MapView::removeTile(int x,int y)
{
	//map->removeTile(&sprite,x,y);  //ta sama sytuacja co w funkcji wyzej
}
void MapView::selectObjectAt(int x,int y){}
void MapView::attachScriptToMap(){}
//void MapView::attachScriptToObject(GameObject *object){}
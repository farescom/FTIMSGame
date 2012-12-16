//#include "ScrollableList.h"
#include "../Game/Objects/GameObject.h"

class MapView// : public ScrollableList
{
	private:
		//Map *map;
	public:
		//void addObject(ObjectDefinition *definition, float x,float y);
		void removeObject(GameObject *object);
		//void setTile(Sprite *sprite,int x,int y);
		void removeTile(int x,int y);
		void selectObjectAt(int x,int y);
		void attachScriptToMap();
		void attachScriptToObject(GameObject *object);
};

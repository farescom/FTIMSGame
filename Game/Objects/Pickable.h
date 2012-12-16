#pragma once
#include "gameobject.h"
class Pickable :
	public GameObject
{
public:
	Pickable(Script *script);
	virtual ~Pickable(void);
};


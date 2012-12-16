#pragma once
#include "gameobject.h"
class Consumable :
	public GameObject
{
public:
	Consumable(Script *script);
	virtual ~Consumable(void);
};


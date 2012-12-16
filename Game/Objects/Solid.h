#pragma once
#include "gameobject.h"
class Solid :
	public GameObject
{
public:
	Solid(Script *script);
	virtual ~Solid(void);
};


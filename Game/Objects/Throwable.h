#pragma once
#include "gameobject.h"
class Throwable :
	public GameObject
{
public:
	Throwable(Script *script);
	virtual ~Throwable();
};


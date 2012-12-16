#pragma once
#ifndef FILE_MAP_FILE_H
#define FILE_MAP_FILE_H

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "File2.h"

class MapFile : public File2
{
public:
	MapFile(void);
	~MapFile(void);
};

#endif

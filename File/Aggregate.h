#pragma once
#ifndef FILE_AGGREGATE_H
#define FILE_AGGREGATE_H

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "File2.h"

class Aggregate
{
private:
	File2 file;  // tu miala byc tablica

public:
	Aggregate(void);
	~Aggregate(void);
	string listUsers();
	string listMaps();
	string listObjects();
	string listTiles();
};

#endif

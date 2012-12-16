#pragma once
#ifndef FILE_DATABASE_H
#define FILE_DATABASE_H

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

class Database
{
public:
	Database(void);
	~Database(void);
	bool connect();

};

#endif

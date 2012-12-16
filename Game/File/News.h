#pragma once
#ifndef FILE_NEWS_H
#define FILE_NEWS_H

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "Database.h"

class News
{
private:
	Database database;

public:
	News(void);
	~News(void);
	string checkNews();

};

#endif



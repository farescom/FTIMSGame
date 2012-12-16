#pragma once

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "File2.h"

class UserFile : public File2
{
public:
	UserFile(string user);
	~UserFile(void);
	bool save(int* tab, int count);		// zapis zbioru liczb opisujacych stan gracza: moc, zycia itd.
	bool load(int* tab, int count);		// zapis zbioru liczb opisujacych stan gracza: moc, zycia itd.
};
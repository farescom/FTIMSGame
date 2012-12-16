#pragma once
#ifndef FILE_OBJECT_FILE_H
#define FILE_OBJECT_FILE_H

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "File2.h"

class ObjectFile : public File2
{
public:
	ObjectFile(void);
	~ObjectFile(void);
};

#endif

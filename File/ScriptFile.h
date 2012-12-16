#pragma once
#ifndef FILE_SCRIPT_FILE_H
#define FILE_SCRIPT_FILE_H

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "File2.h"

class ScriptFile : public File2
{
public:
	ScriptFile(void);
	~ScriptFile(void);
};

#endif

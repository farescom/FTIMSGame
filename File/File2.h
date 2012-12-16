#pragma once

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
#include <fstream>
using namespace std;

#include "Encoder2.h"

class File2
{
protected:
	string path;

private:
	bool encrypted;

	Encoder2 encoder;

public:
	File2(string path, bool encrypted = false);

	~File2(void);

	bool change_encrypted(bool encrypted);

	bool create();

	bool open(int mode = 1);

	bool read(string& destination, string new_line = "\n");

	bool write(string source, int mode = 1);

	bool close();

	bool delete2();

};
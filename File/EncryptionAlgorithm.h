#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <assert.h>

class EncryptionAlgorithm
{
private:
	int key;
public:
	EncryptionAlgorithm(int key = 100);
	char shift_forward(char char1);
	char shift_backword(char char1);
	~EncryptionAlgorithm(void);
};


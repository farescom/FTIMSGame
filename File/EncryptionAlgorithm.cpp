#include "StdAfx.h"

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "EncryptionAlgorithm.h"

EncryptionAlgorithm::EncryptionAlgorithm(int key)
{
	this->key = key;
}

char EncryptionAlgorithm::shift_forward(char char1)
{
	if ((int)char1 != 10)
		return (char)((int)char1+key);
	else
		return char1;					// znaku nowej linii nie podmieniamy
}

char EncryptionAlgorithm::shift_backword(char char1)
{
	if ((int)char1 != 10)
		return (char)((int)char1-key);
	else
		return char1;					// znaku nowej linii nie podmieniamy
}

EncryptionAlgorithm::~EncryptionAlgorithm(void)
{
}
#pragma once

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "EncryptionAlgorithm.h"

class Encoder2
{
private:
	EncryptionAlgorithm encryptionAlgorithm;

public:
	Encoder2();

	Encoder2(EncryptionAlgorithm encryptionAlgorithm);

	~Encoder2(void);

	bool encode(string source, string& destination);

	bool decode(string source, string& destination);

	bool setEncryptionAlgorithm(EncryptionAlgorithm encryptionAlgorithm);

};
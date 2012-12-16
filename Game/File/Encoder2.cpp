#include "StdAfx.h"

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "Encoder2.h"

Encoder2::Encoder2()
{
	this->encryptionAlgorithm = EncryptionAlgorithm(100);
}

Encoder2::Encoder2(EncryptionAlgorithm encryptionAlgorithm)
{
	this->encryptionAlgorithm = encryptionAlgorithm;
}

Encoder2::~Encoder2(void)
{
}

bool Encoder2::encode(string source, string& destination)
{
	//cout << source.length() << endl;
	//cout << destination.length() << endl;

	destination = source;

	for (int i = 0; i < source.length(); i++)
	{
		destination[i] = encryptionAlgorithm.shift_forward(source[i]);
	}

	return true;
}

bool Encoder2::decode(string source, string& destination)
{
	destination = source;

	for (int i = 0; i < source.length(); i++)
	{
		destination[i] = encryptionAlgorithm.shift_backword(source[i]);
	}

	return true;
}

bool Encoder2::setEncryptionAlgorithm(EncryptionAlgorithm encryptionAlgorithm)
{
	this->encryptionAlgorithm = encryptionAlgorithm;
	return true;
}

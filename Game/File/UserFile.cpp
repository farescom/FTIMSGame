#include "StdAfx.h"
#include "UserFile.h"

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
#include "sstream"
using namespace std;

UserFile::UserFile(string user) : File2("resources/"+user+".ftg", true)
{
	if (this->open(1))						// user juz jest utworzony
	{
		//cout << "juz taki user jest";
	}
	else									// user zostanie utworzony - nowy user
	{	
		//cout << "tworzymy uzytkownika";
		this->create();
		File2 users = File2("resources/users.ftg", false);   // false: bez szyfrowania
		users.write(user+"\n", 2);							 // dopisanie uzytkownika od listy users
	}
}

UserFile::~UserFile(void)
{
}

bool UserFile::save(int* tab, int count)
{
	this->write("", 1);
	for (int i = 0; i < count; i++)
	{
		ostringstream ss;
		ss << tab[i];
		this->write(ss.str()+"\n", 2);
	}
	return true;
}

bool UserFile::load(int* tab, int count)
{
	string wyniki;
	this->read(wyniki);
	this->change_encrypted(false);
	this->write(wyniki, 1);
	fstream strumien;
    strumien.open( path, std::ios::in );
    if( strumien.good() == true )
    {
		for (int i = 0; i < count; i++)
			strumien >> tab[i];
        strumien.close();
		this->read(wyniki);
		this->change_encrypted(true);
		this->write(wyniki, 1);
		return true;
    }
	else
	{
		this->read(wyniki);
		this->change_encrypted(true);
		this->write(wyniki, 1);
		return false;
	}
}
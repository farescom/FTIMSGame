#include "StdAfx.h"
#include "File2.h"

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
#include <fstream>
using namespace std;

File2::File2(string path, bool encrypted) : encoder(EncryptionAlgorithm())
{
	this->path = path;
	this->encrypted = encrypted;
	this->encoder = Encoder2(EncryptionAlgorithm(100));
}

File2::~File2(void)
{
	// usuwamy jezeli cos stworzylismy dynamicznie
}

bool File2::change_encrypted(bool encrypted)
{
	this->encrypted = encrypted;
	return true;
}

bool File2::create()
{
	fstream file;
	file.open( path, ios::out );

	if (file.good())
	{
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
	
}

/*
   funkcja sprawdza, czy plik moze byc otworzony w podanym przez uzytkownika trybie
   tryby sa ponumerowane od 1. 
*/
bool File2::open(int mode)
{
	fstream file;
	switch (mode)
	{
		case 1:			// Zezwolenie na odczytywanie danych z pliku. 
			file.open( path, ios::in );
			break;		
		case 2:			// Zezwolenie na zapisywanie danych do pliku.
			file.open( path, ios::out );
			break;		
		default:
			cout << endl << endl << "Niepoprawny tryb!";
			return false;
	}

	if( file.good() == true )
	{
		cout << endl << endl << "Uzyskano dostep do pliku!";
		file.close();
		return true;

	}
	else
	{
	    cout << endl << endl << "Dostep do pliku zostal zabroniony!";
		file.close();
		return false;
	}
}

/*
Dla programistow modu³u:
	ios::app	(append - dopisywanie danych do pliku) Ustawia wewnêtrzny wskaŸnik zapisu pliku na jego koniec. Plik otwarty w trybie tylko do zapisu. Dane mog¹ byæ zapisywane tylko i wy³¹cznie na koñcu pliku.
	ios::ate	(at end) Ustawia wewnêtrzny wskaŸnik pliku na jego koniec w chwili otwarcia pliku.
	ios::binary	(binary) Informacja dla kompilatora, aby dane by³y traktowane jako strumieñ danych binarnych, a nie jako strumieñ danych tekstowych.
	ios::in	(input - wejœcie/odczyt) Zezwolenie na odczytywanie danych z pliku.
	ios::out	(output - wyjœcie/zapis) Zezwolenie na zapisywanie danych do pliku.
	ios::trunc
*/



/*
   wczytuje cala zawartosc pliku do zmiennej destination,
   umozliwia rozdzielanie wierszy odpowiednim ciagiem znakow podanych jako drugi parametr
   gdy nie jest on podany, funkcja rozdziela wiersze gwiazdkami *
*/
bool File2::read(string& destination, string new_line) 
{
	fstream file;
	file.open( path, ios::in );
	string tekst;
	if( file.good() == true )
	{
		destination = "";
		while (!file.eof())
		{
			getline( file, tekst);
			if (encrypted) encoder.decode(tekst, tekst); // dekodowanie
			destination.append(tekst);
			destination.append(new_line);
		}
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}

/*
   zapisuje cala zawartosc zmiennej source do pliku,
   mode - 1: zapis od poczatku plik
   mode - 2: zapis na koniec pliku - dopisywanie
*/
bool File2::write(string source, int mode) // 
{
	fstream file;

	switch (mode)
	{
		case 1:				// zapisywanie pliku usuwajac aktualna zawartosc
			file.open( path, ios::out );
			break;
		default:			// dopisywanie do pliku
			file.open( path, ios::out | ios::app);
			break;
	}
	if( file.good() == true )
	{
		if (encrypted) encoder.encode(source, source);		// szyfrowanie
		file << source;
		file.close();
		return true;
	}
	else
	{
		file.close();
		return false;
	}
}

bool File2::close()
{
	// na razie funkcja nie jest potrzebna gdyz plik jest automatycznie zamykany po wykonaniu kazdej operacji.
	return false;
}

bool File2::delete2()
{
	return false;
}
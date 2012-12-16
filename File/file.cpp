// main.cpp : Defines the entry point for the console application.
//			: this file is used during testing the component.

#include "stdafx.h"

#include <iostream>
#include "string"
#include "file2.h"
#include "userfile.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{

 // Przyklad kodowania i dekodowania

 // opcja bez kodowania - plik bedzie zawieral czysty tekst
	cout << "Powitanie" << endl << endl;
	File2 pliczek = File2("resources/plik.ftg", false);
	pliczek.create();
	pliczek.write("Hello kolego!\nWitaj!!");
	string zmienna;
	pliczek.read(zmienna, "\n");
	cout << zmienna;

 // opcja z kodowaniem - plik zawiera zaszyfrowany tekst
	pliczek.change_encrypted(true);
	pliczek.write(zmienna);
	pliczek.read(zmienna, "\n");
	cout << zmienna;

 // przyk³ad wybrania uzytkownika.
	UserFile userFile = UserFile("player65");

 // przyk³ad zapisania uzytkownika
	int tab[3] = {101, 295652, 7};	// tablica z danymi uzytkownika jak zycia itd
	userFile.save(tab, 3);

	system("pause");

 // przyk³ad zaladowania danych uzytkownika
	userFile.load(tab, 3);
	cout << "--" << tab[0] << "--" << tab[1] << "--" << tab[2] << endl << endl;

	system("pause");
	return 0;
}
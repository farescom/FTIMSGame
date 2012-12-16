#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<fstream>
#include<conio.h>

//#include "Key_words.h"
#include "Syntax.h"


using namespace std;

//void otworz_plik(string name, vector<string> &wczytane_slowa)
//{
//	string linia;
//	fstream plik;
//	
//	plik.open(name,ios::in);
//	if(plik.good())
//	{
//		while(!plik.eof()-1)
//		{
//			getline(plik,linia);
//			wczytane_slowa.push_back(linia);
//		}
//		plik.close();
//	}
//	else
//	{
//		cout<<"fail";
//	}
//}
/*
void szukaj_slow(string slowo, string name)
{
	int ile_wystapien=0;
	vector <string> slowa_w_skrypcie;
	string nazwa_pliku = "baza_slow.txt";
	otworz_plik(nazwa_pliku,slowa_w_skrypcie);
	for(int i=0; i<slowa_w_skrypcie.size(); i++)
	{
		if(slowa_w_skrypcie[i] == slowo)
			ile_wystapien++;
	}
	cout<<"Ilosc wystapien slowa : "<<ile_wystapien<<endl;
}*/

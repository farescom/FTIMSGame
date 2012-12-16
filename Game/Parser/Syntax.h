#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

class Zmiena{
private:
	string name;
	int wartosc;
};

class Syntax{
private:
	int id;
	string nazwa;
public:
	vector<Zmiena> zmienne; 
	string slowo;
	void szukaj_slow(string slowo);

};
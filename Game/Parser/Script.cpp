#include <iostream>
#include<cstdlib>
#include<fstream>
#include "Script.h"

using namespace std;

void load_line(string script_name, vector<string> &line)
{
	//string linia;

	//fstream file;

	//file.open(script_name,ios::in);
	//if(file.good())
	//{
	//	while(!file.eof()-1)
	//	{
	//		getline(file,linia);
	//		line.push_back(linia);
	//	}
	//	file.close();
	//}
	//else
	//{
	//	cout<<"Fail"<<endl;
	//}
}

string checkword(string linia)
{
	string word;

	for(int i=0; i<linia.length();i++)
	{
		if(linia != " ")
		{
		word[i]=linia[i];
		}
		else
		{
			break;
		}
	}

	return word;
}
Script::Script()
{
}
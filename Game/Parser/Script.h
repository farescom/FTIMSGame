#include<cstdlib>
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Script
{
public:
	string script_name;
	vector<string> line; 

	Script();
//	Script(string script/*, GameObject *object*/);
//	Script(string script/* Map *map*/);
//	~Script();

	void parseUpdate();
	void parseCollision();
	void parseCreate();
	void parseDelete();

	void loadline(string script_name, vector<string> &line);
	string checkword(string linia);

private:
	//czekam na implementacje innych klas

	//GameObject *object;
	//Map *map;
	

	vector<string> onUpdate;
	vector<string> onCollision;
	vector<string> onCreate;
	vector<string> onDelete;
	
	void parse(string script);

};

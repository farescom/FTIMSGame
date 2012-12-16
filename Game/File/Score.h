#pragma once
#ifndef FILE_SCORE_H
#define FILE_SCORE_H

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

class Score
{
private:
	string userName;
	string mapName;
	int score;

public:
	Score(string userName, string mapName, int score);
	~Score(void);
	string getUserName();
	string getMapName();
	int getScore();

};

#endif
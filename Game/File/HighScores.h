#pragma once
#ifndef FILE_HIGH_SCORES_H
#define FILE_HIGH_SCORES_H

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "Score.h"
#include "Database.h"

class HighScores
{
private:
	Score score;   // tutaj ma byc tablica
	Database database;

public:
	HighScores(void);
	~HighScores(void);
	Score getLocalHighScores();
	Score getGlobalHighScores();
};

#endif

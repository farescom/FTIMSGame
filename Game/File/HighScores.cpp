#include "StdAfx.h"

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "HighScores.h"

HighScores::HighScores(void) : score("userName", "mapName", 0)
{
}

HighScores::~HighScores(void)
{
}

Score HighScores::getLocalHighScores()
{
	return Score("userName", "mapName", 0);
}

Score HighScores::getGlobalHighScores()
{
	return Score("userName", "mapName", 0);
}
#pragma once
#ifndef FILE_AUDIO_FILE_H
#define FILE_AUDIO_FILE_H

#include <vector>
#include <list>
#include <assert.h>

#include <iostream>
#include "string"
using namespace std;

#include "File2.h"

class AudioFile : public File2
{
	AudioFile(void);
	~AudioFile(void);
};

#endif

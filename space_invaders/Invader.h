#pragma once
#include "GameObject.h"

class Invader : public GameObject
{
public:
	Invader(vector<float> pos, char invader_sym);

	bool isAlive;
private:

};


#pragma once
#include "GameObject.h"

class Player : 
	public GameObject
{
public:
	Player(vector<float> pos, vector<vector<char>> draw_data = vector<vector<char>>(1, vector<char>(1, 'A')));

private:

};


#include "Invader.h"

Invader::Invader(vector<float> pos, char invader_sym) : GameObject(pos, vector<vector<char>>(1, vector<char>(1, invader_sym)))
{
	this->isAlive = true;
}

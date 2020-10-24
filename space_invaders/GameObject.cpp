#include "GameObject.h"

GameObject::GameObject(vector<float> pos, vector<vector<char>> draw_data)
{
	this->position = pos;
	this->draw_data = draw_data;
}

void GameObject::move(float x, float y)
{
	this->position[0] += x;
	this->position[1] += y;
}

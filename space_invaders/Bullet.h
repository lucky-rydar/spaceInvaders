#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet(vector<float> pos, vector<float> default_speed, char bullet_sym = '^');

	float speed_x;
	float speed_y;
private:
};


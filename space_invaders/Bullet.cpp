#include "Bullet.h"

Bullet::Bullet(vector<float> pos, vector<float> default_speed, char bullet_sym) : GameObject(pos, vector<vector<char>>(1, vector<char>(1, bullet_sym)))
{
	this->speed_x = default_speed[0];
	this->speed_y = default_speed[1];
}

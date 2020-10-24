#pragma once
#include <vector>
#include <string>

using namespace std;

class GameObject
{
public:
	GameObject(vector<float> pos, vector<vector<char>> draw_data);

	virtual void update() {};
	void move(float x, float y);

	vector<float> position;
	vector<vector<char>> draw_data;
private:
	
};


#pragma once
#include "GameObject.h"

class Score : public GameObject
{
public:
	Score(vector<float> pos, int def_gift = 10);
	void addPoints(int points);
	void addPoints();
	void update();

	int score;
	int def_gift;
private:
	string score_text;
};


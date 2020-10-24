#include "Score.h"

Score::Score(vector<float> pos, int def_gift) : GameObject(pos, vector<vector<char>>(1))
{
	score = 0;
	this->score_text = "Score: ";
	this->def_gift = def_gift;
}

void Score::addPoints(int points)
{
	score += points;
}

void Score::addPoints()
{
	score += def_gift;
}

void Score::update()
{
	this->draw_data[0].clear();
	
	
	for (size_t i = 0; i < this->score_text.length(); i++)
		draw_data[0].push_back(score_text[i]);
	
	string score_str = to_string(score);
	for (size_t i = 0; i < score_str.size(); i++)
		this->draw_data[0].push_back(score_str[i]);
}

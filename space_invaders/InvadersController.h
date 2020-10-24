#pragma once
#include "Invader.h"
#include "MainWindow.h"

class InvadersController
{
public:
	InvadersController(vector<float> pos, MainWindow* win, int height = 4, int width = 4, int x_scale = 1, int y_scale = 1);
	
	void move(float x, float y);
	void update();
	void draw();
	
	void setSpeed(float speed);

	vector<vector<Invader>> invaders;
	int width;
	int height;
private:
	MainWindow* win;
	
	int x_scale;
	int y_scale;
	
	float next_speed;
	float speed;
};


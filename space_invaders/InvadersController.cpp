#include "InvadersController.h"

InvadersController::InvadersController(vector<float> pos, MainWindow* win, int height, int width, int x_scale, int y_scale)
{
	speed = 1;
	next_speed = speed;
	
	this->width = width;
	this->height = height;

	this->x_scale = x_scale;
	this->y_scale = y_scale;
	
	for (int i = 0; i < width; i++)
	{
		this->invaders.push_back(vector<Invader>());
		for (int j = 0; j < height; j++)
		{
			this->invaders[i].push_back(Invader({pos[0] + i * x_scale, pos[1] + j * y_scale}, 'M'));
		}
	}

	this->win = win;
}

void InvadersController::move(float x, float y)
{
	
	for (int i = 0; i < this->invaders.size(); i++)
	{
		for (int j = 0; j < this->invaders[i].size(); j++)
		{
			invaders[i][j].position[0] += x;
			invaders[i][j].position[1] += y;
		}
	}
}

void InvadersController::update()
{
	if (speed > 0)
	{
		if (this->invaders[invaders.size() - 1][invaders[invaders.size() - 1].size() - 1].position[0] < win->width - 1)
		{	
			this->move(speed, 0);
		}
		else
			speed *= (-1);
	}
	else if (speed < 0)
	{
		if (this->invaders[0][0].position[0] > 0)
		{
			this->move(speed, 0);
		}
		else
			speed *= (-1);
	}
		
}

void InvadersController::draw()
{
	for (int i = 0; i < this->invaders.size(); i++)
	{
		for (int j = 0; j < this->invaders[i].size(); j++)
		{
			if (this->invaders[i][j].isAlive)
				win->draw(this->invaders[i][j]);
		}
	}
}

void InvadersController::setSpeed(float speed)
{
	//this->next_speed = speed;
	if((this->speed < 0 && speed < 0) || (this->speed > 0 && speed > 0))
		this->speed = speed;
	else
	{
		this->speed = speed;
		this->speed *= (-1);
	}
	
}

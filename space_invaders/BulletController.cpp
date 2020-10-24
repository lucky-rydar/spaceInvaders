#include "BulletController.h"

BulletController::BulletController(MainWindow* win)
{
	this->win = win;
	this->of_invader = new vector<Bullet>();
	
	this->of_player = new vector<Bullet>();
}

BulletController::~BulletController()
{
	delete this->of_invader;
	delete this->of_player;
}

void BulletController::addBullet(Bullet bullet, Who who)
{
	if (who == Who::PLAYER)
		this->of_player->push_back(bullet);
	else if (who == Who::INVADER)
	{
		this->of_invader->push_back(bullet);
	}
		
}

void BulletController::update()
{
	// player
	for (size_t i = 0; i < this->of_player->size(); i++)
		this->of_player->at(i).move(of_player->at(i).speed_x, of_player->at(i).speed_y);

	for (size_t i = 0; i < this->of_player->size(); i++)
	{
		if (of_player->at(i).position[0] < 0 || of_player->at(i).position[0] > win->width - 1 || of_player->at(i).position[1] < 0 || of_player->at(i).position[1] > win->height - 1)
			this->of_player->erase(of_player->begin() + i);
	}

	//invader
	for (size_t i = 0; i < this->of_invader->size(); i++)
		this->of_invader->at(i).move(of_invader->at(i).speed_x, of_invader->at(i).speed_y);

	for (size_t i = 0; i < this->of_invader->size(); i++)
	{
		if (of_invader->at(i).position[0] < 0 || of_invader->at(i).position[0] > win->width - 1 || of_invader->at(i).position[1] < 0 || of_invader->at(i).position[1] > win->height - 1)
			this->of_invader->erase(of_invader->begin() + i);
	}
}

void BulletController::draw()
{
	for (size_t i = 0; i < this->of_player->size(); i++)
	{
		win->draw(this->of_player->at(i));
	}

	for (size_t i = 0; i < this->of_invader->size(); i++)
	{	
		try{ win->draw(this->of_invader->at(i)); }
		catch (const std::exception& ex){	}
	}
}


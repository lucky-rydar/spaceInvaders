#include "Game.h"

Game::Game(MainWindow* win)
{
	srand((unsigned int)time(NULL));

	int x_invaders = 8;
	int y_invaders = 4;

	this->win = win;

	this->topPanel = new RectangleShape({ 0, 1 }, vector<vector<char>>(1, vector<char>(50, '=')));
	this->score = new Score({ 0, 0 });
	this->player = new Player({ 25, 20 }, vector<vector<char>>(1, vector<char>(1, 'A')));

	this->invaders = new InvadersController({ 0, 4 }, win, y_invaders, x_invaders, 3, 2);
	this->invaders->setSpeed(0.5f);

	this->bullets = new BulletController(win);

	num_of_invaders = x_invaders * y_invaders;

	this->isEndOfGame = false;
}

Game::~Game()
{
	delete topPanel;
	delete score;
	delete player;
	delete invaders;
	delete bullets;
}

void Game::update()
{
	KeyBoard key;
	
	for (size_t y = 0; y < invaders->invaders.size(); y++) // collizion for invaders
	{
		for (size_t x = 0; x < invaders->invaders[y].size(); x++)
		{
			if (bullets->of_player->size() > 0)
			{
				if (Collizion::isCollizion(invaders->invaders[y][x], bullets->of_player->at(0)) && invaders->invaders[y][x].isAlive)
				{
					this->invaders->invaders[y][x].isAlive = false;
					bullets->of_player->clear();
					this->score->addPoints();
				}

			}
		}
	}
	for (size_t i = 0; i < bullets->of_invader->size(); i++) // collizion for player
	{
		if (Collizion::isCollizion(*this->player, this->bullets->of_invader->at(i)))
		{
			this->isEndOfGame = true;
		}
	}
	
	if (score->score == num_of_invaders * score->def_gift)
		isWin = true;
	
	this->invaders->setSpeed(((score->score * 1.3) / (num_of_invaders * score->def_gift)) + 0.2);
	
	this->bullets->update();
	this->invaders->update();
	this->score->update();

	if (key.isPressed(VK_LEFT) && this->player->position[0] > 0)
		this->player->move(-1, 0);
	else if (key.isPressed(VK_RIGHT) && this->player->position[0] < this->win->width - 1)
		this->player->move(1, 0);
	
	if (key.isPressed(VK_SPACE) && !(bullets->of_player->size() > 0))
 		bullets->addBullet(Bullet({ this->player->position[0], this->player->position[1] - 1 }, { 0, -1 }), PLAYER);
		
	float doShoot = float((int)rand() % this->num_of_invaders * score->def_gift + 1);
	if (doShoot*2 <= this->score->score)
	{

		int y = rand() % invaders->invaders.size();
		int x = rand() % invaders->invaders[y].size();
		if (invaders->invaders[y][x].isAlive)
		{
			bullets->addBullet(Bullet({ invaders->invaders.at(y).at(x).position[0], invaders->invaders.at(y).at(x).position[1] + 1 }, { 0, 1 }, 'x'), Who::INVADER);
		}
	}
}

void Game::draw()
{
	win->draw(*topPanel);
	win->draw(*player);
	win->draw(*score);
	invaders->draw();
	bullets->draw();
	
}

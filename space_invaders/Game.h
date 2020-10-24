#pragma once
#include <ctime>
#include <thread>
#include "Player.h"
#include "Score.h"
#include "KeyBoard.h"
#include "Collizion.h"
#include "MainWindow.h"
#include "RectangleShape.h"
#include "BulletController.h"
#include "InvadersController.h"

class Game
{
public:
	Game(MainWindow* win);
	~Game();

	void update();
	void draw();

	bool isEndOfGame;
	bool isWin;
	Score* score;
private:
	MainWindow* win;
	
	Player *player;
	BulletController* bullets; 
	InvadersController *invaders;
	RectangleShape* topPanel;
	
	int num_of_invaders;
};


#pragma once
#include "Bullet.h"
#include "MainWindow.h"
#include <thread>

enum Who
{
	PLAYER,
	INVADER
};

class BulletController
{
public:
	BulletController(MainWindow* win);
	~BulletController();

	void addBullet(Bullet bullet, Who who);
	void update();
	void draw();

	vector<Bullet> *of_player;
	vector<Bullet> *of_invader;
private:
	MainWindow* win;
};


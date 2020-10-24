#pragma once
#include "GameObject.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class MainWindow
{
public:
	MainWindow(uint32_t height, uint32_t width);
	~MainWindow();
	
	void clear(char empty_sym = ' ');
	void draw(GameObject obj);
	void display();

	uint32_t height;
	uint32_t width;
private:
	vector<vector<char>>* scene;

};


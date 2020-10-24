#include "MainWindow.h"

MainWindow::MainWindow(uint32_t height, uint32_t width)
{
	this->height = height;
	this->width = width;

	this->scene = new vector<vector<char>>(height, vector<char>(width, ' '));
}

MainWindow::~MainWindow()
{
	delete this->scene;
}

void MainWindow::clear(char empty_sym)
{
	system("cls");

	for (size_t i = 0; i < this->scene->size(); i++)
	{
		for (size_t j = 0; j < this->scene->at(0).size(); j++)
		{
			this->scene->at(i)[j] = empty_sym;
		}
		
	}
}

void MainWindow::draw(GameObject obj)
{
	for (int i = (int)obj.position[1]; i < (int)obj.position[1] + obj.draw_data.size(); i++)
	{
		for (int j = (int)obj.position[0]; j < (int)obj.position[0] + obj.draw_data[0].size(); j++)
		{
			if(i >= 0 && i <= this->scene->size() && j >= 0 && j <= this->scene->at(i).size())
				this->scene->at(i)[j] = obj.draw_data[i - (int)obj.position[1]][j - (int)obj.position[0]];
		}
	}
}

void MainWindow::display()
{
	for (size_t i = 0; i < this->scene->size(); i++)
	{
		for (size_t j = 0; j < this->scene->at(0).size(); j++)
		{
			cout << this->scene->at(i)[j];
		}
		cout << endl;
	}
}

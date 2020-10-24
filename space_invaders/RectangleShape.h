#pragma once
#include "GameObject.h"
class RectangleShape :
    public GameObject
{
public:
    RectangleShape(vector<float> pos, vector<vector<char>> draw_data);
};


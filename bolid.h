#pragma once
#include <vector>
#include "point.h"
#include "Figure.h"

using namespace std;

class bolid : public Figure
{
private:
	int x = 0;
	int y = 0;
	char sym;
//	vector <point> Bolid;
	direction::Direction Dir = direction::DOWN;
public:
	bolid(int konst_x, int konst_y, char konst_sym);
	void Draw();
	void Move(int offset);
	void Clear();
	void HandleKey();
};
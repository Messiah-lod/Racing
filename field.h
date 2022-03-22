#pragma once

#include <vector>
#include "bolid.h"

class field
{
public:
    field();
	void Draw();
	void Make_cars(int &iter);
	bolid GetNextCar();
	bool IsHit(Figure figure);
private:
	vector <bolid> Field;
};

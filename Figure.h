#pragma once
#include <vector>
#include "point.h"

using namespace std;

class Figure
{
public:
	vector <point> Bolid;
	bool IsHit(Figure figure);
private:
	bool IsHit(point Point);
};


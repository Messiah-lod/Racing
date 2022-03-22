#include "Figure.h"
#include "point.h"
#include <vector>

using namespace std;

//функция отрисовки точки с заданными координатами

bool Figure::IsHit(Figure figure)
{
    for (point p : Bolid)
	{
		if (figure.IsHit(p))
		{
			return true;
		}
	}
	return false;
}

bool Figure::IsHit(point Point)
{
    for (point p : Bolid)
	{
		if (p.IsHit(Point))
		{
			return true;
		}
	}
	return false;
}

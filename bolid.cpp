//#pragma warning(disable : 4996)

#include "bolid.h"
#include "point.h"
#include <vector>
#include "direction.h"
#include <iostream>
#include <Windows.h>

using namespace std;

bolid::bolid(int konst_x, int konst_y, char konst_sym)
{
	x = konst_x;
	y = konst_y;
	sym = konst_sym;

	point p1(x, y, sym);
	point p2(x - 1, y + 1, sym);
	point p3(x + 1, y + 1, sym);
	point p4(x, y + 1, sym);
	point p5(x, y + 2, sym);
	point p6(x - 1, y + 3, sym);
	point p7(x + 1, y + 3, sym);

	Bolid.push_back(p1);
	Bolid.push_back(p2);
	Bolid.push_back(p3);
	Bolid.push_back(p4);
	Bolid.push_back(p5);
	Bolid.push_back(p6);
	Bolid.push_back(p7);
}

void bolid::Draw()
{
	for (unsigned i = 0; i < Bolid.size(); i++)
	{
		if (Bolid[i].get_x() >= 0 && Bolid[i].get_x() < 9 && Bolid[i].get_y()
			>= 0 && Bolid[i].get_y() < 20)
		{
			Bolid[i].Draw();
		}
	}
}

void bolid::Clear()
{
	for (unsigned i = 0; i < Bolid.size(); i++)
	{
		if (Bolid[i].get_x() >= 0 && Bolid[i].get_x() < 9 && Bolid[i].get_y() 
			>= 0 && Bolid[i].get_y() < 20)
		{
			Bolid[i].set_sym(' ');
			Bolid[i].Draw();
		}
	}
}

void bolid::Move(int offset)
{
	for (unsigned i = 0; i < Bolid.size(); i++)
	{
		Bolid[i].set_sym(sym);
	}

	if (Dir == direction::DOWN)
	{
		for (unsigned i = 0; i < Bolid.size(); i++)
		{
			Bolid[i].set_y(Bolid[i].get_y() + offset);
		}
	}
	else if (Dir == direction::UP)
	{
		for (unsigned i = 0; i < Bolid.size(); i++)
		{
			Bolid[i].set_y(Bolid[i].get_y() - offset);
		}
	}
	else if (Dir == direction::RIGHT && Bolid[0].get_x() < 7)
	{
		for (unsigned i = 0; i < Bolid.size(); i++)
		{
			Bolid[i].set_x(Bolid[i].get_x() + offset);
		}
	}
	else if (Dir == direction::LEFT && Bolid[0].get_x() > 1)
	{
		for (unsigned i = 0; i < Bolid.size(); i++)
		{
			Bolid[i].set_x(Bolid[i].get_x() - offset);
		}
	}
}

void bolid::HandleKey()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		Dir = direction::LEFT;
	};
	//if (GetAsyncKeyState(VK_UP))
	//{
	//	Dir = direction::UP;
	//};
	//if (GetAsyncKeyState(VK_DOWN))
	//{
	//	Dir = direction::DOWN;
	//};
	if (GetAsyncKeyState(VK_RIGHT))
	{
		Dir = direction::RIGHT;
	};
}
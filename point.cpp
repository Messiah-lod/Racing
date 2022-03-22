#include <Windows.h>
#include <iostream>
#include "point.h"

using namespace std;

point::point(int konst_x, int konst_y, char konst_sym)
{
	x = konst_x;
	y = konst_y;
	sym = konst_sym;
}

void point::set_x(int set_x)
{
	x = set_x;
}

int point::get_x()
{
	return x;
}

void point::set_y(int set_y)
{
	y = set_y;
}

int point::get_y()
{
	return y;
}

void point::set_sym(char set_sym)
{
	sym = set_sym;
}

char point::get_sym()
{
	return sym;
}
//функция отрисовки точки с заданными координатами по х и у.
void point::Draw()
{
	COORD position;                                     // Объявление необходимой структуры
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получение дескриптора устройства стандартного вывода

	position.X = x;                                    // Установка координаты X-берем из класса
	position.Y = y;                                    // Установка координаты Y-берем из класса

	SetConsoleCursorPosition(hConsole, position);       // Перемещение каретки по заданным координатам

	cout << sym;
}
//Функция движения точки по направлению + длина сдвига
void point::Move(int offset, direction::Direction Dir)
{
	if (Dir == direction::Direction::RIGHT)
	{
		x = x + offset;
	}
	else if (Dir == direction::Direction::LEFT)
	{
		x = x - offset;
	}
	else if (Dir == direction::Direction::UP)
	{
		y = y - offset;
	}
	else if (Dir == direction::Direction::DOWN)
	{
		y = y + offset;
	}
}
//очистка точки
void point::clear()
{
	sym = ' ';
	Draw();
}

//Функция определения пересечения одной точки с другой
bool point::IsHit(point p)
{
//	return x == p.x && y == p.y;   //возможны оба варианты написания метода
	return x == p.get_x() && y == p.get_y();
}

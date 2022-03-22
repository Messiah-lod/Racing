#include "field.h"
#include <vector>
#include "bolid.h"
#include <time.h>
#include <cstdlib>

using namespace std;

field::field()
{
 //   m_l = 1;
}

bolid field::GetNextCar()
{	
    int position = rand() % 3;//рандом от 0 до 2
	//выбираем позицию машинки (лево-центр-право) на поле х= от 0 до 9.
	if (position == 0)
	{
		position = 1;//лево (х=1)
	}
	else if (position == 1)
	{
		position = 4;//центр(х=4)
	}
	else if (position == 2)
	{
		position = 7;//право(х=7)
    }
	bolid nextCars(position, -4, '#');
	return nextCars;
}

void field::Make_cars(int &iter)
{
//	int iter = 0;//переменная итерации для выдерживания интервала между машинами-препятствиями
	int volume = (rand() % 2) + 1;//(рандом от 0 до 1)+1 - итог от 1 до 2
	if (iter >= 8)
	{
		for (int i = 1; i <= volume; i++)
		{
			Field.push_back(GetNextCar());
		}
		iter = 0;
	}
	iter++;

	while (Field.size() > 20)//обрезаем длину вектора с ненужными машинами
	{
		Field.erase(Field.begin());
	}
}

void field::Draw()
{
//	Make_cars();

	for (unsigned i = 0; i < Field.size(); i++)
	{
		Field[i].Clear();
		Field[i].Move(1);
		Field[i].Draw();
	}
}

bool field::IsHit(Figure figure)
{
    for (Figure car : Field)
	{
		if (car.IsHit(figure))
		{
			return true;
		}
	}
	return false;
}

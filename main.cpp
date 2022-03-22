//#pragma warning(disable : 4996)

#include <iostream>
#include "windows.h"
#include "bolid.h"
#include "direction.h"
#include "field.h"
#include <stdio.h>
#include <time.h>

using namespace std;

bolid GetNextCar()
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

void placeKurs(int x, int y)
{
	COORD position;                                     // Объявление необходимой структуры
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Получение дескриптора устройства стандартного вывода

    position.X = static_cast<SHORT>(x);                                    // Установка координаты X-берем из класса
    position.Y = static_cast<SHORT>(y);                                    // Установка координаты Y-берем из класса

	SetConsoleCursorPosition(hConsole, position);       // Перемещение каретки по заданным координатам
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    srand((unsigned)time(nullptr));//для постоянно разного рандома
	//Конструкция для изменения размера окна консоли и ликвидации полос прокрутки на WinApi
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { 20, 20 };
    SMALL_RECT src = { 0, 0, static_cast<SHORT>(crd.X - 1), static_cast<SHORT>(crd.Y - 1) };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);

	for (int i = 0; i < 20; i++)
	{
		placeKurs(9, i);
		cout << "|";
	}

	placeKurs(13, 5);
	cout << "Счет";
	
	bolid player(4, -4, '#');
    field pole;

	int iter = 0;//переменная итерации для отрисовки подъезжающего игорка
	int iter1 = 0;//переменная итерации для выдерживания интервала между машинами-препятствиями
	int Score = 0;//счет
	
	int Speed = 0;//скорость машин-препятствий

	while (true)
	{
        Sleep(static_cast<DWORD>(Speed));
		
		if (iter < 20)//начальное условие для выезда игрока
		{
			player.Clear();
			player.Move(1);
			player.Draw();
			iter++;
		}
		else//после того, как игрок занял свое место появляются машинки-препятствия
		{
			pole.Make_cars(iter1);
			pole.Draw();
			player.Draw();

			if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState(VK_RIGHT))
			{
				player.Clear();
				player.HandleKey();
				player.Move(3);
				player.Draw();
			}
		}


		Score++;
		placeKurs(13, 6);
		cout << Score;
		if (Score < 100) { Speed = 300; }
		else if (Score < 300) { Speed = 250; }
		else if (Score < 500) { Speed = 200; }
		else if (Score < 700) { Speed = 150; }
		else if (Score < 900) { Speed = 100; }
        else if (Score < 1000) { Speed = 50; }

		if (pole.IsHit(player))//Проверка на ДТП на поле
		{
			break;//если врезались - игру закончили
		}
    }

	placeKurs(0, 7);
	cout << "  ИГРА  ";
	placeKurs(0, 8);
	cout << "ОКОНЧЕНА!";
	placeKurs(20, 20);

	cin.get();
	return 0;
}

#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
//#include <iomanip> // setw()
#include <math.h> // abs


#define BSIZE 8
#define BLACKPAWN 1
#define WHITEPAWN -1

using namespace sf;

struct poz
{
	int x, y;
}oldPoz;

int  size = 100, move = 0, x, y;
int board[8][8] =
{ 1, 1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0, 0,
  1, 1, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 0, 0, 0,-1,-1,-1,
  0, 0, 0, 0, 0,-1,-1,-1,
  0, 0, 0, 0, 0,-1,-1,-1, };


int change = 0;
bool right{ 0 };



void StepBlack()
{
	for (int i = 0; i < BSIZE - 1; ++i)
	{
		for (int j = 0; j < BSIZE; ++j)
		{
			if ((board[i][j] == 1) && (board[i + 1][j] == 0) && !right)
			{
				board[i][j] = 0;
				board[i + 1][j] = 1;
				change = 0;
				return;
			}
		}
	}
	right = 1;
	for (int i = 0; i < BSIZE; ++i)
	{
		for (int j = 0; j < BSIZE - 1; ++j)
		{
			if ((board[i][j] == 1) && (board[i][j + 1] == 0))
			{
				board[i][j] = 0;
				board[i][j + 1] = 1;
				change = 0;
				return;
			}
		}
	}

	right = 0;

	for (int i = 0; i < BSIZE; ++i)
	{
		for (int j = 1; j < BSIZE - 1; ++j)
		{
			if ((board[i][j] == 1) && (board[i][j - 1] == 0))
			{
				board[i][j] = 0;
				board[i][j - 1] = 1;
				change = 0;
				return;
			}
		}
	}
	//}

	for (int i = 1; i < BSIZE; ++i)
	{
		for (int j = 0; j < BSIZE - 1; ++j)
		{
			if ((board[i][j] == 1) && (board[i - 1][j] == 0) )
			{
				board[i][j] = 0;
				board[i - 1][j] = 1;
				change = 0;
				return;
			}
		}
	}

}

bool WinWhite()
{
	bool win{ 1 };
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (board[i][j] != -1)
				win = 0;
		}
	}
	return win;
}

bool WinBlack()
{
	bool win{ 1 };
	for (int i = 5; i < 8; ++i)
	{
		for (int j = 5; j < 8; ++j)
		{
			if (board[i][j] != 1)
				win = 0;
		}
	}
	return win;
}

// write matrix to output
//void writeMa()
//{
//	for (int i = 0; i < BSIZE; ++i)
//	{
//		for (int j = 0; j < BSIZE; ++j)
//			std::cout << std::setw(2) << board[i][j];
//		std::cout << '\n';
//	}
//	std::cout << '\n';
//}


int WPawn(int ox, int oy, int nx, int ny)
{
	/*std::cout << "A ox - " << ox
		<< " oy - " << oy
		<< " nx - " << nx
		<< " ny - " << ny
		<< " board - " << board[ox][oy] << std::endl;*/

	if ((ox == nx) && (oy == ny))
	{
		return 0;
	}

	if ((nx < 0) || (ny < 0))
	{
		return 0;
	}

	if ((abs(ox - nx) > 1) || (abs(oy - ny) > 1)) // шаг больше 1 клетки
	{
		return 0;
	}

	if ((abs(ox - nx) >= 1) && (abs(oy - ny) >= 1)) // шаг по диагонали
	{
		return 0;
	}

	if (board[ny][nx] != 0) // запрет кушать
	{
		std::cout << "eat\n";
		return 0;
	}

	return 1;
}

int BPawn(int ox, int oy, int nx, int ny)
{
	/*std::cout << "N ox - " << ox
		<< " oy - " << oy
		<< " nx - " << nx
		<< " ny - " << ny
		<< " board - " << board[ox][oy] << std::endl;*/

	if ((ox == nx) && (oy == ny)) // ход на месте
	{
		return 0;
	}

	if ((nx < 0) || (ny < 0)) // выходит за границу
	{
		return 0;
	}

	if ((abs(ox - nx) > 1) || (abs(oy - ny) > 1)) // шаг больше 1 клетки
	{
		return 0;
	}

	if ((abs(ox - nx) >= 1) && (abs(oy - ny) >= 1)) // шаг по диагонали
	{
		return 0;
	}

	if (board[ny][nx] != 0) // запрет кушать
	{
		//std::cout << "eat\n";
		return 0;
	}

	return 1;
}

#include "Header.h"

int main()
{
	RenderWindow window(VideoMode(800, 800), "Chess like game");
	Texture t1, t2, t3;

	t1.loadFromFile("images/board.png");
	t2.loadFromFile("images/BlackPawn.png");
	t3.loadFromFile("images/WhitePawn.png");

	Sprite table(t1);
	Sprite BlackPawn(t2);
	Sprite WhitePawn(t3);
	Sprite Side;

	float dx = 0, dy = 0;
	int Step = 0;

	while (window.isOpen())
	{
		Vector2i pos = Mouse::getPosition(window);
		x = pos.x / size;
		y = pos.y / size;
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window.close();
			}
			window.clear();
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.key.code == Mouse::Left)
				{
					if (board[y][x] != 0)
					{
						dx = pos.x - x * 100;
						dy = pos.y - y * 100;
						/*if (board[y][x] == BlackPawn && change == 1)
						{
							Step = BlackPawn;
							Side = BlackPawn;
							board[y][x] = 0;
						}*/
						if (board[y][x] == WHITEPAWN && change == 0)
						{
							Step = WHITEPAWN;
							Side = WhitePawn;
							board[y][x] = 0;
						}
						if (board[y][x] == 0)
						{
							move = 1;
							oldPoz.x = x;
							oldPoz.y = y;
						}
					}
				}
			}
			if (e.type == Event::MouseButtonReleased)
			{
				if (e.key.code == Mouse::Left)
				{
					int ok = 2;
					if (Step == WHITEPAWN && move == 1)
					{
						ok = WPawn(oldPoz.x, oldPoz.y, x, y);
					}
					/*if (Step == WHITEPAWN && move == 1)
					{
						ok = BPawn(oldPoz.x, oldPoz.y, x, y);
					}*/
					if (ok == 1)
					{
						board[y][x] = Step;
						if (change == 0) // ход белых
						{
							change = 1;
						}
						//else // ход черных
						//{
						//	//StepBlack();
						//	//change = 0;
						//	//change = 1;
						//}
					}
					else if (ok == 0) // если не поменял клетку
					{
						board[oldPoz.y][oldPoz.x] = Step;
					}
					move = 0;
				}
			}
		}

		if (WinWhite())
		{
			std::cout << "Congrats White WIN!";
			window.close();
		}

		if (WinBlack())
		{
			std::cout << "Congrats Black WIN!";
			window.close();
		}

		if (change) // ход белых
		{
			StepBlack();
			//change = 0;
		}
		/************************************ отрисовка ****************************************/
		window.clear();
		window.draw(table);

		if (move == 1)
		{
			Side.setPosition(pos.x - dx, pos.y - dy);
			window.draw(Side);
		}
		for (int i = 0; i < BSIZE; i++)
		{
			for (int j = 0; j < BSIZE; j++)
			{

				if (board[i][j] != 0)
				{
					if (board[i][j] == BLACKPAWN)
					{
						BlackPawn.setPosition(j * size, i * size);
						window.draw(BlackPawn);
					}
					if (board[i][j] == WHITEPAWN)
					{
						WhitePawn.setPosition(j * size, i * size);
						window.draw(WhitePawn);
					}
				}
			}
		}
		window.display();
	}
	return 0;
}
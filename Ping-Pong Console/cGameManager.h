#pragma once
#include "cBall.h"
#include "cPaddle.h"
#include <time.h>
#include <iostream>
class cGameManager
{
private:
	int width, height;
	int score1, score2;
	char up1, up2, down1, down2;
	bool quit;
	cBall* ball;
	cPaddle* player1;
	cPaddle* player2;
public:
	cGameManager(int w, int h)
	{
		srand(time(NULL));
		width = w;
		height = h;
		quit = false;
		score1 = score2 = 0;
		up1 = 'w'; up2 = 'p';
		down1 = 's'; down2 = 'l';
		ball = new cBall(w / 2, h / 2);
		player1 = new cPaddle(1, h / 2 - 3);
		player2 = new cPaddle(w-2, h / 2 - 3);
	}
	~cGameManager() { delete ball, player1, player2; }
	void ScoreUp(cPaddle* P)
	{
		if (P == player1)
			++score1;
		else if (P == player2)
			++score2;
		ball->Reset();
		player1->Reset();
		player2->Reset();
	}
	void Draw()
	{
		system("cls");
		for (int i = 0; i < width + 2; ++i)
			std::cout << "#";
		std::cout << std::endl;

		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width; ++j)
			{
				int ballX = ball->getX();
				int ballY = ball->getY();
				int player1X = player1->getX();
				int player1Y = player1->getY();
				int player2X = player2->getX();
				int player2Y = player2->getY();

				if (j == 0)
					std::cout << "#";

				if (j == ballX && i == ballY)
					std::cout << "O";
				else if (j == player1X && i == player1Y)
					std::cout << "#";
				else if (j == player2X && i == player2Y)
					std::cout << "#";
				else
					std::cout << " ";

				if (j == width-1)
					std::cout << "#";
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < width + 2; ++i)
			std::cout << "#";
		std::cout << std::endl;

	}
};


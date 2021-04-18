#pragma once
#include "cBall.h"
#include "cPaddle.h"
#include <time.h>
#include <iostream>
#include <conio.h>
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
		up1 = 'a'; up2 = 'k';
		down1 = 'z'; down2 = 'm';
		ball = new cBall(w / 2, h / 2);
		player1 = new cPaddle(1, h / 2 - 3);
		player2 = new cPaddle(w - 2, h / 2 - 3);
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
			std::cout << "\xDB";
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
					std::cout << "\xDB";

				if (j == ballX && i == ballY)
					std::cout << "O";
				else if (j == player1X && i == player1Y)
					std::cout << "\xBA";
				else if (j == player1X && i == player1Y + 1)
					std::cout << "\xBA";
				else if (j == player1X && i == player1Y + 2)
					std::cout << "\xBA";
				else if (j == player1X && i == player1Y + 3)
					std::cout << "\xBA";
				else if (j == player2X && i == player2Y)
					std::cout << "\xBA";
				else if (j == player2X && i == player2Y + 1)
					std::cout << "\xBA";
				else if (j == player2X && i == player2Y + 2)
					std::cout << "\xBA";
				else if (j == player2X && i == player2Y + 3)
					std::cout << "\xBA";
				else
					std::cout << " ";

				if (j == width - 1)
					std::cout << "\xDB";
			}
			std::cout << std::endl;
		}

		for (int i = 0; i < width + 2; ++i)
			std::cout << "\xDB";
		std::cout << std::endl;
		std::cout << "Score 1: " << score1 << std::endl;
		std::cout << "Score 2: " << score2 << std::endl;

	}
	void Input()
	{
		ball->Move();
		int ballX = ball->getX();
		int ballY = ball->getY();
		int player1X = player1->getX();
		int player1Y = player1->getY();
		int player2X = player2->getX();
		int player2Y = player2->getY();

		if (_kbhit())
		{
			char current = _getch();
			if (current == up1 && player1Y > 0)
				player1->moveUp();
			if (current == up2 && player2Y > 0)
				player2->moveUp();
			if (current == down1 && player1Y + 4 < height)
				player1->moveDown();
			if (current == down2 && player2Y + 4 < height)
				player2->moveDown();
			if (ball->getDirection() == STOP)
				ball->SetRandomDirection();
			if (current == 'q')
				quit = true;
		}
	}
	void Logic()
	{
		int ballX = ball->getX();
		int ballY = ball->getY();
		int player1X = player1->getX();
		int player1Y = player1->getY();
		int player2X = player2->getX();
		int player2Y = player2->getY();
		
		//left paddle
		for (int i = 0; i < 4; ++i)
			if (ballX == player1X + 1)
				if (ballY == player1Y + i)
					ball->SetDirection((eDir)(rand() % 3 + 4));
		//right paddle
		for (int i = 0; i < 4; ++i)
			if (ballX == player2X - 1)
				if (ballY == player2Y + i)
					ball->SetDirection((eDir)(rand() % 3 + 1));
		if (ballY == height - 1)
			ball->SetDirection(ball->getDirection() == DOWNRIGHT ? UPRIGHT : UPLEFT);
		if (ballY == 0)
			ball->SetDirection(ball->getDirection() == UPRIGHT ? DOWNRIGHT : DOWNLEFT);
		if (ballX == width - 1)
			ScoreUp(player1);
		if (ballX == 0)
			ScoreUp(player2);
	}
	void Run() 
	{
		while (!quit)
		{
			Draw();
			Input();
			Logic();
		}
	}
};


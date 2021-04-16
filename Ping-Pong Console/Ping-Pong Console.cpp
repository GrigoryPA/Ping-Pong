#include <iostream>
#include "cBall.h"

int main()
{
    cBall ball(0,0);
    std::cout << ball << std::endl;
    ball.SetRandomDirection();
    std::cout << ball << std::endl;
    ball.Move();
    std::cout << ball << std::endl;
    ball.Move();
    std::cout << ball << std::endl;
    ball.SetRandomDirection();
    std::cout << ball << std::endl;
    ball.Move();
    std::cout << ball << std::endl;
    ball.SetRandomDirection();
    std::cout << ball << std::endl;
    ball.Move();
    std::cout << ball << std::endl;
}
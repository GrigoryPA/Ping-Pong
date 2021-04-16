#include <iostream>
#include "cBall.h"
#include "cPaddle.h"

int main()
{
    cPaddle p1(0, 0);
    cPaddle p2(10, 0);
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    p1.moveUp();
    p2.moveDown();
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
}
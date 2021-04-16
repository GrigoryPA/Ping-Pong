#include <iostream>
#include "cBall.h"
#include "cPaddle.h"
#include "cGameManager.h"

int main()
{
    cGameManager scene(40, 20);
    scene.Draw();

    return 0;
}
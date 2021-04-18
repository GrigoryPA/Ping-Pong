#include <iostream>
#include "cBall.h"
#include "cPaddle.h"
#include "cGameManager.h"

int main()
{
    cGameManager scene(40, 20);
    scene.Run();

    return 0;
}
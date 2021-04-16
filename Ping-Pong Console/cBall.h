#pragma once
#include <stdlib.h>
#include <ostream>
enum eDir {STOP=0, LEFT=1, UPLEFT=2, DOWNLEFT=3, RIGHT=4, UPRIGHT=5, DOWNRIGHT=6};
class cBall
{
private:
	int x, y;
	int originalX, originalY;
	eDir direction;
public:
	cBall(int positionX, int positionY) 
	{
		originalX = positionX;
		originalY = positionY;
		x = positionX;
		y = positionY;
		direction = STOP;
	}
	void Reset() 
	{
		x = originalX;
		y = originalY;
		direction = STOP;
	}
	void SetDirection(eDir dir)
	{
		direction = dir;
	}
	void SetRandomDirection() 
	{
		direction = (eDir)((rand() % 6) + 1);
	}
	inline int getX() { return x; }
	inline int getY() { return y; }
	inline eDir getDirection() { return direction; }
	void Move()
	{
		switch (direction) 
		{
		case STOP:
			break;
		case LEFT:
			--x;
			break;
		case UPLEFT:
			--x; --y;
			break;
		case DOWNLEFT:
			--x; ++y;
			break;
		case RIGHT:
			++x;
			break;
		case UPRIGHT:
			++x; --y;
			break;
		case DOWNRIGHT:
			++x; ++y;
			break;
		default:
			break;
		}
	}
	friend std::ostream& operator<<(std::ostream& o, cBall c) 
	{
		o << "Ball [" << c.x << "; " << c.y << "], [" << c.direction << "]";
		return o;
	}
};


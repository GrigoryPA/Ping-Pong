#pragma once
#include <ostream>
class cPaddle
{
private:
	int x, y;
	int originalX, originalY;
public:
	cPaddle() 
	{
		x = y = 0;
	}
	cPaddle(int posX, int posY) 
	{
		originalX = posX;
		originalY = posY;
		x = posX;
		y = posY;
	}
	void Reset() { x = originalX; y = originalY; }
	inline int getX() { return x; }
	inline int getY() { return y; }
	void moveUp() { --y; }
	void moveDown() { ++y; }
	friend std::ostream& operator<<(std::ostream& o, cPaddle c)
	{
		o << "Paddle [" << c.x << "; " << c.y << "]";
		return o;
	}
};


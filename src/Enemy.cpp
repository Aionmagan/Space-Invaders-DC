#include "Enemy.h"
#include <math.h>

float Enemy::x = 85.0f;
float Enemy::y = 100.0f;

/*construcktor*/
Enemy::Enemy(int textureToLoad)
{
	char ch = ' ';
	switch(textureToLoad)
	{
		case 1: ch = '1';
			break;
		case 2: ch = '2';
			break;
		case 3: ch = '3';
			break;
	}
	
	char s[17] = "/rd/Sprite/ .png";
	s[11] = ch;
	
	texture = new Texture(s, false);

	//onBorder = true;
}

/*destructor*/
Enemy::~Enemy()
{
	
}

void Enemy::MoveVertical(const float &direction)
{
	if(y > 240){return;}
	y += direction;
}

float Enemy::GetX() const
{
	return x;
}

float Enemy::GetY() const
{
	return y;
}

void Enemy::MoveHorizontal(const float &direction)
{
	/*if true enemy has passed border of the left 
	 * side of the screen, if false 
	 * enemy has passed border on the right 
	 * side of the screen
	 */
	if(x < 20) 
	{
		onBorder = false;
	}
	else if(x > 170) 
	{
		onBorder = true;
	}
	
	float dir = direction; 
	
	if(onBorder)
	{
		dir *= -1;
	}
	
	x += dir;
	
	
	/*move enemy down if
	 * they are on border
	 */
	 if(x <= 40 || x >= 150)
	 {
		 MoveVertical(direction/6);
	 }
	
}

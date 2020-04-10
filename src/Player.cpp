#include "Player.h"

/*contructor*/
Player::Player()
{
	x = 170.0f;
	y = 440.0f;
	
	texture = new Texture("/rd/Sprite/Player.png", true);
}

/*destructor*/
Player::~Player()
{
	
}

float Player::GetX() const
{
	return x;
}

float Player::GetY() const
{
	return y;
}

void Player::MoveHorizontal(const float &direction)
{
	if(x < 20)
	{
		x = 20;
	}else if(x > 620)
	{
		x = 620;
	}
	
	x += direction / 100;
}

void Player::MoveVertical(const float &direction)
{
	y += direction / 100;
}
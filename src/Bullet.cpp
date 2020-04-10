#include "Bullet.h"

/*constructor*/
Bullet::Bullet()
{
	texture = new Texture("/rd/Sprite/Bullet.png", true);
}

/*destructor*/
Bullet::~Bullet()
{
	
}

bool Bullet::HasBeenShot() const
{
    return isShooting;	
}

bool Bullet::CheckCollision(const float &x, const float &y) const
{
	if(this->y > y && this->y < y + 20)
	{
		if(this->x > x - 20 && this->x < x + 20)
		{
			return true;
		}
	}
	
	return false;
}

void Bullet::StopShootOnCollision()
{
	isShooting = false;
}

float Bullet::GetX() const
{
     return x;	
}

float Bullet::GetY() const
{
	return y;
}

void Bullet::SetPosition(const float &x, const float &y)
{
	 this->x = x;
	 this->y = y;
}

void Bullet::MoveBullet(const float &speed)
{
	if(isShooting)
	{
		if(y < 0){isShooting = false;}
		y -= speed;
	}
}

void Bullet::Shoot()
{
	isShooting = true;
}
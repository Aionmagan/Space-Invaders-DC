#ifndef __BULLET
#define __BULLET

#include<tsu/include/texture.h>

class Bullet
{
private :
	union
	{
	    struct
		{
			float x, y;
		};
	};
	
	bool isShooting = false;
	
public:
	Bullet();
	~Bullet();
	
	RefPtr<Texture> texture;
	
	bool HasBeenShot() const;
	
	//had Enemy &e before but ran out of memory
	bool CheckCollision(const float &x, const float &y) const;
	void StopShootOnCollision();
	
	float GetX() const;
	float GetY() const;
	
	void SetPosition(const float &x, const float &y);
	void MoveBullet(const float &speed);
	void Shoot();
};

#endif __BULLET
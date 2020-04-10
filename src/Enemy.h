#ifndef __ENEMY
#define __ENEMY

#include <tsu/include/texture.h>

class Enemy 
{
private:
	
	/*affects every enemy*/
	bool onBorder = false;
	
   /*this is called by
	*MoveHorizontal()
	*/
	void MoveVertical(const float &direction);

public:

    static float y, x;

	Enemy(int textureToLoad);
	~Enemy();
	
	RefPtr<Texture> texture;
	
	float GetY() const;
	float GetX() const;
	
   /*all logic for enemy movement 
	*goes here
	*/
	void MoveHorizontal(const float &direction);

};

#endif __ENEMY
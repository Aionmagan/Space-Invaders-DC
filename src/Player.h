#ifndef __PLAYER
#define __PLAYER

#include <tsu/include/texture.h>

class Player
{
private:
	union
	{
		struct
		{
	        float x, y;
		};
	};
	
public:
	Player();
	~Player();
	
	RefPtr<Texture> texture;
	
	float GetX() const;
	float GetY() const;
	
	void MoveHorizontal(const float &direction);
	void MoveVertical(const float &direction);
};

#endif //__PLAYER
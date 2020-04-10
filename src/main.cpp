#include <plx/sprite.h>
#include <tsu/include/texture.h>

#include "Controller.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

extern uint8 romdisk[];
KOS_INIT_FLAGS(INIT_DEFAULT);
KOS_INIT_ROMDISK(romdisk);

void DrawSprite(RefPtr<Texture> &texture, float x, float y, float hSize, float wSize)
{
	texture->sendHdr(PVR_LIST_OP_POLY);
	plx_spr_inp(texture->getH() / hSize, 
				texture->getW() / wSize,
				x, y, 20, 0xffffffff);
}

int main(int argc, char **argv)
{
	//init graphics 
	pvr_init_defaults();
	pvr_set_bg_color(0.0f, 0.0f, 0.0f);
	
	//create game objects
	Controller controller;
	Player player;
	Enemy enemies[5] = {3,3,2,2,1};
	Bullet bullet;
	
	bool isDead[5][12];
	
	for(int i = 0; i < 5; ++i)
		    for(int j = 0; j < 12; ++j)
				isDead[i][j] = false;

	while(!controller.Button(START))
	{
		pvr_wait_ready();
		pvr_scene_begin();
		pvr_list_begin(PVR_LIST_OP_POLY);
		
		controller.UpdateControllerState();
		
		if(controller.Button(A) && !bullet.HasBeenShot())
		{
			bullet.SetPosition(player.GetX(), player.GetY());
			bullet.Shoot();
		}
		
		player.MoveHorizontal(controller.JoystickX());
		bullet.MoveBullet(7);
		/*enemies movement to one affect all*/
		enemies[0].MoveHorizontal(0.5f);
		
		/*Draw sprits*/
		
		/*cloning enemy texture instead of
		 * having as many enemy objects on scree
		 * to save vram 
		 */
		for(int i = 0; i < 5; ++i)
		{
		    for(int j = 0; j < 12; ++j)
				{
					if(isDead[i][j]){continue;}
					DrawSprite(enemies[i].texture, enemies[i].GetX() + (j * 40), 
							                       enemies[i].GetY() + (i * 40), 10, 10);
												   
					if(!bullet.HasBeenShot()){continue;}							   
				    if(bullet.CheckCollision(enemies[i].GetX() + (j * 40), 
								             enemies[i].GetY() + (i * 40)))
					{ 
						isDead[i][j] = true;
						bullet.StopShootOnCollision();
					}

				}
		}
				
			

        DrawSprite(player.texture, player.GetX(), player.GetY(), 8, 8);
	
		if(bullet.HasBeenShot())
		{
			DrawSprite(bullet.texture, bullet.GetX(), bullet.GetY(), 17, 15);
		}
		
		pvr_scene_finish();
	}

	pvr_mem_reset();
	pvr_shutdown();
	return 0;
}

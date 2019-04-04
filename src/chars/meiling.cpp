#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "meiling.h"
#include <math.h>

//"Constructor" ?
char_meiling::char_meiling(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_MEILING;
	pgp->load_dat("meiling",pal);
	char_loadsfx("meiling");
	cards_load_cards(&chr_cards,"meiling");
	load_face("meiling");
	load_spells("meiling");
	stand_gfx->init(this,"meiling");
}

//"Generating" bullets
c_bullet *char_meiling::new_bullet() {
	c_bullet *tmp = new meiling_bullets();
	return tmp;
}

//The func10 function
void char_meiling::func10() {

	//Character deltas (?)
	x_delta = 0;
	y_delta = 106;

	if ( controlling_type == CONTROL_PC_STORY ) {
		if (cards_added >= 1) {
			switch ( cards_active[0]->id) {
				case 0:
				case 1:
				case 2:
				case 3:
					field_4AA = 2;
					field_534 = 0.25;
					field_55C = 2.0;
					field_538 = 0.0;
					field_86A = 1;
					if (get_pframe() ->extra1[4] == 1) {
						field_86A = 3;
						field_55C = 4.0;
					}
					if (get_pframe() ->extra1[4] == 2) {
						field_86A = 3;
						field_55C = 7.5;
					}
					break;
					case 4:
					case 5:
					case 6:
					case 7:
						field_4AA = 2;
						field_534 = 0.25;
						field_55C = 1.0;
						field_538 = 0.0;
						field_86A = 1;
						if (get_pframe()->extra1[4] == 1) {
							field_86A = 3;
							field_55C = 3.0;
						}
						if (get_pframe()->extra1[4] == 2) {
							field_86A = 3;
							field_55C = 6.0;
						}
						break;
					default:
						break;
					}
				}
				if (field_882 == 1) {
					if (field_188 >= max_health && field_574 == 0) {
						field_86A = 2;
						field_882 = 2;
						flip_with_force();
						set_seq(149);
						scene_add_effect(this, 53, x, y + 100.0, dir, 1);

						//( 2 if statements in one)
						if (cards_added >= 1 && cards_active[0]->id <= 7 ) {
							field_884 = 300;
							field_886 = 300;
						}
					}
					if ( health <= 0 )
						field_882 = 2;
				}
				if ( field_884 > 0) {
					if (damage_limit > 0 && damage_limit < 100)
						damage_limit = 0;
					if ( field_884 == 1 || health <= 0 ) {
						field_4AA = 0;
						field_884 = 0;
						field_4BA = 0;
						field_188 = 0;
						field_81E = 1;
						field_81A = 0;
						field_81C = 0;
						field_818 = 0;
						field_882 = 1;
					} else {
						field_86A = 2;
						field_4AA = 2;
						field_538 = 1.0;
						field_534 = 1.0;
						field_884--; // --field_884;//field_884 -= 1;
						field_4BA = 6000;
					}
				}

				//Does health need to be here?
				if (health > 0) {
					if (get_seq() > 149 && get_seq() < 159) {
						if ( !bbarrier_show ) {
							bbarrier_show = 1;

							if (get_seq() > 149 && get_seq() < 154) {
								addbullet(this, NULL, 998, x + (57 * dir), y + 94.0, dir, 1 , 0, 0);
							}
							if (get_seq() > 153 && get_seq() < 158 ) {
								addbullet(this, NULL, 998, x + (57 * dir), y + 60.0, dir, 1, 0 , 0);
							}
							if (get_seq() == 158 ) {
								addbullet(this, NULL, 998, x + (57 * dir), y + 100.0, dir, 1, 0, 0);
							}
						}
					if ( field_890 > 0) {
						field_890 -= 1;
						if (health > 0 && field_890 > 0) {//--field_890 > 0 ??
							if (field_190 == 0 || field_190 == 1) {
								if (field_1A2 == 1) {
									skills_1[9];
									if (skills_1[9] >= 2) 
										field_198 *= ((skills_1[9] - 1) * 0.10 + 1.0); //0.1000000014901161 + 1.0;
								}
								if (field_1A2 >= 2) {
									field_54C = 0.0; //??
									field_198 += field_198; //addition instead of multiplication
								}
								if (field_1A2 <= 0)
									field_890 = 0;/*
								if (field_84E <= 0 && field_852 <= 0) {
									if (LODWORD(shader_type) != 1) {
										if (LODWORD(shader_type) == 0)
											LODWORD(shader_type) = 3;
										field_7FC += 8.0;
										//LODWORD(x + ([4] * dir)) //LODWORD(v1440)
										if ( skills_1[3] >= 3 && get_frame_time() >= 5)
											//void (__thiscall *)(char_meiling *))v2->char_c.meta.vtbl->next_frame_func8)(v2);
									}
								} /*else {
									
									LABEL_1645:
            ((void (__thiscall *)(char_meiling *))v2->char_c.meta.vtbl->next_frame_func8)(v2);
									
								} */
							}
					}
					//else
					}
				}
				if ( health <= 0)
					field_86A = 0;
			} 
			if ( field_890 > 0 ) {
				field_890--;
				//field_54C = 0.0;

			//	if ( )
			//}
		}
	}
}

//Initialize some variables
void char_meiling::init_vars()
{
	field_890 = 0;
	field_138 = -6.0;
	char_c::init_vars();
}

/*
void char_meiling::func20()
{

}
*/
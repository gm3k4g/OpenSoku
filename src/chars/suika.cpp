#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "suika.h"
#include <math.h>

//debugging
#include <iostream>

//"Constructor" ?
char_suika::char_suika(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_SUIKA;
	pgp->load_dat("suika",pal);
	char_loadsfx("suika");
	cards_load_cards(&chr_cards,"suika");
	load_face("suika");
	load_spells("suika");
	stand_gfx->init(this,"suika");
}

//Initialize some variables
void char_suika::init_vars()
{
	field_138 = -6.0;
	field_890 = 0;
	field_892 = 0;
	field_894 = 0;
	char_c::init_vars();
}

//Bullet function
/*
c_bullet *char_suika::new_bullet()
{
    c_bullet *tmp = new suika_bullets();
    return tmp;
}
*/

//tons of 
void char_suika::func10()
{
	//pre switch statemet
	x_delta = 0;
	y_delta = 80;

	if ( field_890 > 0)
	{
		field_890 -= 1;
		if ( enemy->health <= 0 || health <= 0)
			field_890 = 0;
		spell_energy_spend(2, 30); //(enemy, 2, 30)?
	}
	
	//big switch statement
	int32_t sq = get_seq();
	switch(sq)
	{
		case 0:
			sub10func();
			if ( h_inerc == 0.0 )
				field_49A = 0;
			stopping(0.5);
			process();
			break;
		case 1:
			sub10func();
			stopping(0.5);
			if (process() && get_frame() == 0)
				set_seq(2);
			break;
		case 2:
			sub10func();
			stopping(0.5);
			process(); //< added from marisa.cpp
			break;
		case 3:
			sub10func();
			stopping(0.5);
			if ( process() && get_frame() == 0 )
				set_seq(0);
			break;
		case 4:
			sub10func();
			char_h_move(5.5);
			process();
			break;
		case 5:
			sub10func();
			char_h_move(-5.5);
			process();
			break;
		case 6:
			if (get_subseq() == 0)
			{
				sub10func();
				if ( field_49A == 0)
					reset_forces();
			}
			if ( get_subseq()>0)
			{
				v_inerc -= v_force;
				if ( char_on_ground_down())
				{
					set_seq(10);
					y = getlvl_height();
					reset_forces();
					break;
				}
			}
			process();
			if ( get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1)
			{
				char_h_move(0.0);
				v_inerc = 16.0;
				v_force = 0.75;
				field_49A = 0;
			}
			break;
		case 7:
			if (get_subseq() == 0)
			{
				sub10func();
				if(!get_subseq())
				{
					if(field_49A == 0)
						reset_forces();
				}
			}
			if (get_subseq()>0)
			{
				v_inerc -= v_force;
				if (char_on_ground_down())
				{
					set_seq(10);
					y = getlvl_height();
					reset_forces();
					break;
				}
			}
			process();
			if ( get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1)
			{
				char_h_move(8.0);
				v_inerc = 16.0;
				v_force = 0.75;
				field_49A = 0;
			}
			break;
		case 8:
			if (get_subseq() == 0)
			{
				sub10func();
				if(get_subseq() == 0)
				{
					if (field_49A == 0)
						reset_forces();
				}
			}
			if (get_subseq()>0)
			{
				v_inerc -= v_force;
				if(char_on_ground_down())
				{
					set_seq(10);
					y = getlvl_height();
					reset_forces();
					break;
				}
			}
			process();
			if ( get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1)
			{
				char_h_move(-8.0);
				v_inerc = 16.0;
				v_force = 0.75;
				field_49A = 0;
			}
			break;
		case 9:
			if ( v_force == 0.0)
				v_force = 0.6;
			v_inerc -= v_force;
			if ( char_on_ground_down())
			{
				set_seq(10);
				y = getlvl_height();
				reset_forces();
				break;
			}
			process();
			break;
		case 10:
			sub10func();
			reset_forces();
			if ( process() )
			{
				if(dY() > 0) //?
					set_seq(2);
				else
					set_seq(0);
			}
			break;
		case 197: //maybe unfinished?
			sub10func();
			if (process() == 0)
			{
				if(get_elaps_frames())
				{
					if ( (get_subseq() != 2) && (get_frame() != 5))
						break;
					if ( get_frame() == 11)
					{
						if ( enemy->x < x)
							dir = -1;
						if ( enemy->x > x)
							dir = 1;
					}
				}
			}
			//break??
			if(controlling_type == 2)
			{
				field_51C = 3;
				field_520 = 3;
			}
			else
			{
				if (dY() > 0)
					set_seq(1);
				/*if ( get_elaps_frames())
				{
					//if ( )
				}*/
				if ( get_frame_time() == 0)
				{
					if ( get_frame() == 11)
					{
						if ( enemy->x < x)
							dir = -1;
						if ( enemy->x > x)
							dir = 1;
					}
				}
			}
			break;
		case 198:
			sub10func();
			if ( process() == 0)
			{
				if(get_elaps_frames() )
				{
					if(get_subseq() == 2 && get_frame() == 5 && get_frame_time() == 0)
					{
						if (enemy->x < x)
							dir = -1;
						if (enemy->x > x)
							dir = 1;
					}
				}
			}
			if ( controlling_type == 2)
			{
				set_seq(700);
				field_51C = 3;
				field_520 = 3;
			}
			else
			{
				if ( dY() > 0)
					set_seq(1);
				if(get_frame_time() == 0)
				{
					if(get_frame() == 11)
					{
						if(enemy->x < x)
							dir = -1;
						if(enemy->x > x)
							dir = 1;
					}
				}
			}
			break;
		case 200:
			sub10func();
			field_49A = 1;
			process();
			if(get_subseq() != 1)
			{
				if(get_subseq() == 0 && get_frame() == 3 && get_frame_time() == 0)
				{
					char_h_move(10.0);
					scene_add_effect(this, 125, (80*dir)+x, y+ 80.0, dir, 1);
					scene_add_effect(this, 126, x, y + 80.0, dir, 1);
					scene_play_sfx(31);
				} 
			}
			if ( (get_elaps_frames() % 5) == 0)
			{
				float xx = x + 50.0 - (scene_rand() % 100);
				float yy = (scene_rand() % 200) + y;
				scene_add_effect(this, 124, xx, yy, dir, 1);
			}
			if (dY() >= 0)
			{
				field_7D0++;
				if(dX(dir) > 0 && field_7D0 <= 60)
				{
					if(get_subseq() == 0 && get_frame() == 3 && get_frame_time() == 0)
					{
						char_h_move(10.0);
						scene_add_effect(this, 125, (80*dir) +x, y + 80.0, dir, 1);
						scene_add_effect(this, 126, x, y + 80.0, dir, 1);
						scene_play_sfx(31);
					}
				}
				else
				{
					set_seq(204);
				}
			}
			else
			{
				if(dX(dir)<0)
					set_seq(211);
				else
					set_seq(212);
			}
			break;
		case 201:
			sub10func();
			field_49A = 1;
			process();
			if (get_subseq() == 1)
			{
				if((get_elaps_frames() % 5) == 0)
				{
					float xx = x + 50.0 - (scene_rand() % 100);
					float yy = (scene_rand() % 200) + y;
					scene_add_effect(this, 124,xx, yy, dir, 1);
				}
				field_7D0++;
				if(dX(dir) >= 0 && field_7D0 >= 10 && field_7D0 >= 10)
					set_seq(205);
				if(get_subseq() == 0 && get_frame() == 3 && get_frame_time() == 0)
				{
					char_h_move(-10.0);
					scene_add_effect(this, 125, (80*dir)+x, y+80.0, dir, 1);
					scene_add_effect(this, 126, x, y + 80.0, dir, 1);
					scene_play_sfx(31);
				}
			}
			break;
		case 202:
			v_inerc -= v_force;
			if ( char_on_ground_down())
			{
				reset_forces();
				y = getlvl_height();
				set_seq(10);
			}
			if ( (get_subseq() == 1 || get_subseq() == 2) && (get_elaps_frames() % 5) == 0)
			{
				float xx = x + 50.0 - (scene_rand() % 100);
				float yy = (scene_rand() % 200) + y;
				scene_add_effect(this, 124, xx, yy, dir, 1);
			}
			if ( get_subseq() == 1 && get_elaps_frames() >= 16)
			{
				next_subseq();
				flip_with_force();
			}
			process();
			if (get_subseq() == 0 && get_frame_time() == 0 && get_frame() == 2)
			{
				field_7D0 = 0;
				char_h_move(11.0);
				v_inerc = 4.0;
				v_force = 0.5;
				scene_add_effect(this, 125, (80*dir) + x, y + 110.0, dir, 1);
				scene_add_effect(this, 126, x, y + 110.0, dir, 1);
				scene_play_sfx(31);
			}
			if ( get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 2)
				flip_with_force();
			break;
		case 203:
			v_inerc -= v_force;
			if ( char_on_ground_down() )
			{
				reset_forces();
				y = getlvl_height();
				set_seq(10);
			}
			if ( get_subseq() < 2 && (get_elaps_frames() % 5) == 0)
			{
				float xx = x + 50.0 - (scene_rand() % 100);
				float yy = (scene_rand() % 200) + y;
				scene_add_effect(this, 124, xx, yy, dir, 1);
			}
			if ( get_subseq() != 1 || get_elaps_frames() < 16 )
			{
				process();
				if( get_subseq() == 0 && get_frame_time() == 0 && get_frame() == 2)
				{
					char_h_move(-11.0);
					v_inerc = 4.0;
					v_force = 0.5;
					scene_add_effect(this, 125, x, y + 120.0, dir, 1);
					scene_add_effect(this, 126, x, y + 120.0, dir, 1);
					scene_play_sfx(31);
				}
				if(get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 3)
					flip_with_force();
			}
			else
			{
				next_subseq();
				flip_with_force();
			}
			break;
		case 204:
			sub10func();
			h_inerc -= 0.5;
			if( h_inerc < 0.0)
			{
				h_inerc = 0.0;
				field_49A = 0;
			}
			if(process())
			{
				set_seq(0);
				field_49A = 0;
			}
			break;
		case 205:
			sub10func();
			h_inerc += 0.5;
			if ( h_inerc > 0.0)
			{
				h_inerc = 0.0;
				field_49A = 0;
			}
			if (process())
			{
				set_seq(0);
				field_49A = 0;
			}
			break;
		case 208:
			if (get_subseq() == 0)
				sub10func();
			if(char_on_ground_down())
			{
				set_seq(10);
				y = getlvl_height();
				reset_forces();
			}
			else
			{
				if(char_on_ground_down() || v_inerc > 0.0)
					field_522 = 2;
				if ( get_subseq() > 0)
					v_inerc -= v_force;
				if (get_subseq() == 1 && v_inerc < 4.0)
					set_subseq(2);
				process();
				if(get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1)
				{
					char_h_move(0.0);
					v_inerc = 21.0;
					v_force = 0.75;
					field_49A = 0;
					scene_add_effect(this, 63, x, y, dir, 1);
				}
			}
			break;
		case 209:
		case 212:
		case 221:
			if (get_subseq() == 0)
				sub10func();
			if ( char_on_ground_down())
			{
				set_seq(10);
				y = getlvl_height();
				reset_forces();
				break;
			}
			else
			{
				if (char_on_ground_down() || v_inerc > 0.0)
					field_522 = 2;
				if (get_subseq() > 0)
					v_inerc -= v_force;
				if(get_subseq() == 1 && v_inerc < 4.0)
					set_subseq(2);
				process();
				if(get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1)	
				{
					char_h_move(10.0);
					v_inerc = 16.0;
					v_force = 0.6;
					field_49A = 0;
					scene_add_effect(this, 63, x, y, dir, 1);
				}
			}
			break;
		case 210:
		case 222:
			if (get_subseq() == 0)
				sub10func();
			if ( char_on_ground_down())
			{
				set_seq(10);
				y = getlvl_height();
				reset_forces();
				break;
			}
			if ( char_on_ground_down() || v_inerc > 0.0)
				field_522 = 2;
			if (get_subseq() > 0)
				v_inerc -= v_force;
			if (get_subseq() == 1 && v_inerc < 4.0)
				set_subseq(2);
			process();
			if ( get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1 )
			{
				char_h_move(-10.0);
				v_inerc = 16.0;
				v_force = 0.6;
				field_49A = 0;
				scene_add_effect(this, 63, x, y, dir, 1);
			}
			break;
		case 211:
			if ( get_subseq() == 0)
				sub10func();
			if ( char_on_ground_down() )
			{
				set_seq(10);
				y = getlvl_height();
				reset_forces();
				break;
			}
			if ( char_on_ground_down() || v_inerc > 0.0)
				field_522 = 2;
			if ( get_subseq() > 0)
				v_inerc -= v_force;
			if ( get_subseq() == 1 && v_inerc < 4.0)
				set_subseq(2);
			process();
			if ( get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1)
			{
				char_h_move(3.0);
				v_inerc = 19.0;
				v_force = 0.75;
				field_49A = 0;
				scene_add_effect(this, 63, x, y, dir, 1);
			}
			break;
		case 214:
			if(process())
			{
				set_seq(9);
				break;
			}

			if( get_elaps_frames() == 0)
			{
				if(get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1 )
					scene_play_sfx(31);
				if(get_elaps_frames() == 0 && get_frame_time() == 0 && get_subseq() == 6)
				{
					set_seq(9);
					break;
				}
			}

			if ( dY()<0)
			{
				if(dX(dir) <= 0)
					field_7D2 = 90 - dX(dir) * 45;
			}
			else if (dY() == 0)
			{
				if (dX(dir) > 0)
					field_7D2 = 0;
				else if ( dX(dir) < 0)
					field_7D2 = 0;
			}
			else if (dY() > 0)
			{
				field_7D2 = -90 - dX(dir) * 45;
			}

			if(get_subseq() == 5 || get_subseq() == 6)
				v_inerc -= v_force;

			if (get_subseq() > 0 && get_subseq() < 5)
			{
				field_7D6++;
				field_7D4 = field_7D2 - dash_angle;
				if ( field_7D4 > 180)
					field_7D4 -= 360;
				if ( field_7D4 < -180)
					field_7D4 += 360;
				if( field_7D4 > 0 )
				{
					if( weather_id == WEATHER_SUNNY )
						dash_angle -= 0.5;
					else
						dash_angle -= 1.5;
				}
				h_inerc = cos_deg(dash_angle) * field_7DC;
				v_inerc = sin_deg(dash_angle) * field_7DC;
				if ( y > 680.0 && v_inerc > 0.0)
					v_inerc = 0.0;
				field_7DC += 0.3;
				if ( field_7DC > 12.0)
					field_7DC = 12.0;
				if ( weather_id == WEATHER_SUNNY)
					spell_energy_spend(10, 1);
				else
					spell_energy_spend(5, 1);
				angZ -= dash_angle;
				if (h_inerc < 0.0)
					angZ -= 180;
				if (h_inerc < 0.0 && get_subseq() == 1)
					set_subseq(3);
				if ( h_inerc >= 0.0 && get_subseq() == 3)
					set_subseq(1);
				if( h_inerc > 0.0 && get_subseq() == 2)
					set_subseq(4);
				if ( h_inerc >= 0.0 && get_subseq() == 4)
					set_subseq(2);
				if ( get_elaps_frames() % 5 == 1)
				{
					float xx = cos_deg(dash_angle) * 100.0 * dir + x;
					float yy = sin_deg(dash_angle) * 100.0 + y + 100.0;
					scene_add_effect(this, 125, xx, yy, dir, 1);
				}
				if ( (keyDown(INP_D) == 0 && field_7D6 > 10) || spell_energy <= 0)
				{
					reset_ofs();
					if(get_subseq() == 1 || get_subseq() == 2)
					{
						if ( dir == 1)
						{
							if ( enemy->x >= x)
								set_subseq(5);
							else
							{
								dir = -1;
								h_inerc = -h_inerc;
								set_subseq(6);
							}
						}
						else if (enemy->x <= x)
						{
							set_subseq(5);
						}
						else
						{
							dir = -dir;
							h_inerc = -h_inerc;
							set_subseq(6);
						}
					}
					if ( get_subseq() == 3 || get_subseq() == 4)
					{
						if ( dir == 1)
						{
							if ( enemy->x >= x)
								set_subseq(6);
						}
						else
						{
							dir = -1;
							h_inerc = -h_inerc;
							set_subseq(5);
						}
					}
					else 
					{
						if (enemy->x <= x)
							set_subseq(6);
						else
						{
						dir = -dir;
						h_inerc = -h_inerc;
						set_subseq(5);
						}
					}
				}

			}
			break;
		//case 215:
			

	}
}

void char_suika::func20()
{

}

void char_suika::set_seq_params() 
{
	//acquire current state
	std::cout << "SUIKA_get_seq() :" << get_seq() << std::endl;
	std::cout << "SUIKA_get_subseq() :" << get_subseq() << std::endl;

	uint32_t sq = get_seq();
	switch(sq)
	{
		//walking
		case 4:

		case 5:
		case 214: //if ( sq == 214) (doesn't have reset_ofs())
		case 217:
			reset_ofs();
			field_7D6 = 0;
			h_inerc = 0.0;
			v_inerc = 0.0;
			v_force = 0.6;
			x_off = 0.0;
			y_off = 72.0;
			field_7DC = 9.0;
			field_7EC = 0.0;
			break;
		case 300:
		case 301:
		case 330:
			not_charge_attack = 1;
			if ( !field_49A)
				reset_forces();
			field_190 = 0;
			field_194 = 1;
			break;
		case 302:
			reset_forces();
			field_190 = 0;
			field_49A = 0;
			field_194 = 1;
			not_charge_attack = 1;
			break;
		case 303:
			if( !field_49A)
				reset_forces();
			field_190 = 0;
			field_194 = 1;
			not_charge_attack = 1;
			break;
		case 304:
			field_49A = 0;
			field_194 = 1;
			field_190 = 0;
			reset_forces();
			not_charge_attack = 1;
			break;
		case 305:
			v_inerc = 0.0;
			field_49A = 0;
			field_190 = 0;
			h_inerc = 9.0;
			field_194 = 2;
			break;
		case 306:
			field_7D0 = 0;
			field_190 = 0;
			field_194 = 1;
			break;
		case 307:
			field_194 = 1;
			field_190 = 0;
			not_charge_attack = 1;
			v_force = 0.0;
			h_inerc *= 0.2;
			v_inerc *= 0.2;
			break;
		case 308:
			field_194 = 1;
			field_190 = 0;
			not_charge_attack = 1;
			break;
		case 309:
			field_194 = 1;
			field_190 = 0;
			if ( h_inerc > 8.0 )
				h_inerc = 8.0;
			if (h_inerc < -8.0)
				h_inerc = -8.0;
			not_charge_attack = 1;
			break;
		case 310:
			h_inerc = 0.0;
			field_7D0 = 0;
			v_inerc = 0.0;
			field_190 = 0;
			field_194 = 99;
			v_force = 0.5;
			break;
		case 320:
			field_49A = 0;
			field_190 = 0;
			field_194 = 1;
			break;
		case 321:
		case 322:
			if (!field_49A)
				reset_forces();
			field_190 = 0;
			field_194 = 1;
			break;
		case 400:
			field_190 = 0;
			reset_forces();
			field_7D0 = 0;
			field_7D2 = 0;
			field_7D4 = 0;
			not_charge_attack = 1;
			break;
		case 401:
			field_190 = 0;
			reset_forces();
			field_7D6 = 0;
			field_7D0 = 0;
			field_7D2 = 0;
			not_charge_attack = 1;
			break;
		case 402:
			field_194 = 1;
			field_190 = 0;
			reset_forces();
			field_7D6 = 0;
			field_7D0 = 0;
			field_7D2 = 0;
			not_charge_attack = 1;
			break;
		case 404:
		case 405:
		case 406:
			field_190 = 0;
			field_7D0 = 0;
			field_7D2 = 0;
			field_7D4 = 0;
			not_charge_attack = 1;
			v_force = 0.0;
			h_inerc *= 0.2;
			v_inerc *= 0.2;
			break;
		case 408:
			h_inerc = 10.0;
			field_49A = 0;
			field_7D0 = 0;
			field_190 = 0;
			v_inerc = 0.0;
			field_194 = 3;
			break;
		case 409:
			field_49A = 0;
			v_force = 0.3;
			field_7D0 = 0;
			field_190 = 0;
			field_194 = 1;
			break;
		case 410:
			field_190 = 0;
			reset_forces();
			field_7D2 = 0;
			not_charge_attack = 1;
			break;
		case 411:
		case 412:
			field_190 = 0;
			reset_forces();
			field_7D0 = 0;
			field_7D2 = 0;
			not_charge_attack = 1;
			break;
		case 414:
			field_190 = 0;
			v_force = 0.0;
			field_7D2 = 0;
			not_charge_attack = 1;
			h_inerc *= 0.2;
			v_inerc *= 0.2;
			break;
		case 415:
		case 416:
			field_7D0 = 0;
			field_190 = 0;
			v_force = 0.0;
			field_7D2 = 0;
			not_charge_attack = 1;
			h_inerc *= 0.2;
			v_inerc *= 0.2;
			break;
		case 418:
			h_inerc = 10.0;
			if ( !field_49A )
				reset_forces();
			field_190 = 0;
			field_194 = 1;
			break;
		case 505:
		case 506:
			field_18C = 4;
			not_charge_attack = 1;
			reset_forces();
			field_190 = 1;
			field_194 = 0;
			field_7D0 = 0;
			field_49A = 0;
			field_7D2 = 0;
			break;
		case 507:
		case 508:
			field_18C = 4;
			not_charge_attack = 1;
			h_inerc *= 0.1;
			v_inerc *= 0.1;
			v_force = 0.025; //?!
			field_190 = 1;
			field_194 = 0;
			field_7D0 = 0;
			field_49A = 0;
			field_7D2 = 0;
			break;
		case 510:
		case 511:
		case 512:
		case 513:
			not_charge_attack = 1;
			field_18C = 8;
			reset_forces();
			field_194 = 1;
			field_190 = 0;
			field_7D0 = 0;
			field_49A = 0;
			field_7D2 = 0;
			break;
		case 520:
		case 521:
			field_18C = 1;
			reset_forces();
			field_194 = 0;
			skills_1[1] -= 2; //?!
			if ( !skills_1[1] < 0 ) //?!
				field_194 = 1;
			field_190 = 0;
			field_49A = 0;
			field_7D0 = 0;
			break;
		case 522:
		case 523:
			field_18C = 1;
			reset_forces();
			field_194 = 1;
			field_190 = 0;
			field_49A = 0;
			field_7D0 = 0;
			break;
		case 525:
		case 526:
			field_18C = 5;
			reset_forces();
			field_194 = 1;
			field_190 = 0;
			field_49A = 0;
			field_7D0 = 0;
			break;
		case 530:
		case 531:
			field_18C = 9;
			reset_forces();
			field_194 = 0;
			field_49A = 0;
			field_190 = 1;
			break;
		case 540:
		case 541:
			field_18C = 2;
			field_190 = 0;
			reset_forces();
			field_7D0 = 0;
			field_7D2 = 0;
			field_7D6 = 0;
			field_7D8 = 0;
			not_charge_attack = 0;
			break;
		case 542:
		case 543:
			v_force = 0.0;
			field_18C = 2;
			field_190 = 0;
			v_inerc *= 0.2;
			h_inerc *= 0.2;
			field_7D0 = 0;
			field_7D2 = 0;
			field_7D6 = 0;
			field_7D8 = 0;
			not_charge_attack = 0;
			break;
		case 545:
		case 546:
		case 547:
		case 548:
			field_7E8 = 0.0;
			field_7EC = 0.0;
			field_7D0 = 0;
			field_7D2 = 0;
			field_18C = 6;
			field_190 = 0;
			reset_forces();
			not_charge_attack = 1;
			break;
		case 550:
		case 551:
			field_7D0 = 0;
			field_7D2 = 0;
			field_18C = 10;
			field_190 = 0;
			reset_forces();
			not_charge_attack = 1;
			break;
		case 560:
		case 561:
			field_18C = 3;
			field_190 = 1;
			reset_forces();
			not_charge_attack = 1;
			break;
		case 565:
		case 566:
			field_18C = 7;
			field_190 = 0;
			field_7D0 = 0;
			field_7D2 = 0;
			field_7D6 = 0;
			not_charge_attack = 1;
			v_force = 0.0;
			h_inerc *= 0.2;
			v_inerc *= 0.2;
			break;
		case 570:
		case 571:
			field_18C = 11;
			field_7D0 = 0;
			field_7D2 = 0;
			field_194 = 0;
			field_190 = 0;
			reset_forces();
			break;
		case 599:
			field_190 = 1;
			reset_forces();
			field_7D0 = 0;
			field_7D2 = 0;
			field_7D6 = 0;
			field_7D8 = 0;
			break;
		case 600:
		case 650:
			field_190 = 1;
			reset_forces();
			field_7D0 = 0;
			break;
		case 601:
		case 604:
			field_194 = 1;
			field_190 = 0;
			reset_forces();
			break;
		case 602:
			field_7D0 = 0;
			field_190 = 0;
			field_7DC = 1.0;
			field_194 = 1;
			reset_forces();
			break;
		case 603:
			field_7D0 = 0;
			field_7D2 = 0;
			field_190 = 0;
			field_194 = 1;
			reset_forces();
			break;
		case 605:
		case 730:
			field_7D0 = 0;
			field_190 = 0;
			field_7DC = 2.0;
			field_194 = 1;
			reset_forces();
			break;
		case 606:
			reset_forces();
			field_190 = 0;
			field_49A = 0;
			break;
		case 607:
			reset_forces();
			field_49A = 0;
			field_7D0 = 0;
			break;
		case 608:
			field_7D0 = 0;
			field_7D2 = 0;
			field_194 = 0;
			field_190 = 0;
			reset_forces();
			break;
		case 612:
			field_7D0 = 0;
			field_7D2 = 0;
			field_190 = 0;
			field_194 = 1;
			reset_forces();
			break;
		case 613:
			field_190 = 0;
			not_charge_attack = 1;
			break;
		case 615:
			field_190 = 1;
			reset_forces();
			field_7D8 = 0;
			field_7D6 = 0;
			field_7D0 = 0;
			field_7D2 = 0;
			not_charge_attack = 1;
			break;
		case 700:
			break;
		case 701:
		case 702:
		case 703:
			if (!field_49A)
				reset_forces();
			break;
		case 704:
		case 707:
		case 710:
		case 711:
		case 720:
			reset_forces();
			break;
		case 705:
			h_inerc = 6.0;
			break;
		case 706:
			h_inerc = -6.0;
			break;
		case 708:
			field_7D0 = 0;
			h_inerc = 0.0;
			break;
		case 709:
			field_7D0 = 0;
			break;
		case 740:
			field_7DC = 0.0;
			field_7D0 = 0;
			dash_angle = 0.0;
			field_7D2 = 0;
			field_7E8 = 0.0;
			field_7D4 = 0;
			field_194 = 0;
			field_190 = 0;
			reset_forces();
			break;
		case 751:
			reset_forces();
			field_7DC = 0.0;
			field_190 = 0;
			field_194 = 0;
			field_7D0 = 0;
			field_49A = 0;
			field_7D2 = 0;
			break;
		default:
			char_c::set_seq_params();
			break;
	}
}
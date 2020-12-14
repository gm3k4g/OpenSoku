#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "youmu.h"
#include <math.h>

//"Constructor" ?
char_youmu::char_youmu(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_YOUMU;
	pgp->load_dat("youmu",pal);
	char_loadsfx("youmu");
	cards_load_cards(&chr_cards,"youmu");
	load_face("youmu");
	load_spells("youmu");
	stand_gfx->init(this,"youmu");
}

//Initialize some variables
void char_youmu::init_vars()
{
	field_138 = -6.0;
	mion_pframe = 0;
	field_8B9 = 0;
	field_8DC = 0.0;
	field_8D0 = 0;
	field_8E0 = 0.0;
	field_8D1 = 0;
	field_8E4 = 0.0;
	field_8D2 = 0;
	field_8D4 = 0;
	field_8D6 = 0;
	field_8D8 = 0;
	field_8E8 = 0;
	char_c::init_vars();
}
/*
c_bullet *char_youmu::new_bullet()
{
    c_bullet *tmp = new youmu_bullets();
    return tmp;
}
*/

void char_youmu::func10()
{
	x_delta = 0;
	y_delta = 90;

	if (field_8D4 >= 1) 
		field_8D4 -= 1;
	if (field_8D6 <= 0)
		field_8D8 = 0;
	else {
		if (field_8D8 > 0) {
			field_54C = 0.0;
			--field_8D6;
			if (health <= 0 || enemy->health <= 0) 
				field_8D6 = 0;
			if (get_seq() >= 600 && get_seq() <= 699) {
				if( get_seq() == 602 || get_seq() == 605) {
					if (!get_subseq()) 
						field_8D6 = 0;
				} else {
					field_8D6 = 0;
				}
			}
		}
		if (hit_stop != 0 && time_stop != 0) {
			if (get_seq() <= 300) {
				if (get_seq() == 300) {
					sub10func();
					/*
	        if ( !get_true(0) )
	        {
	          if ( v1->char_c.field_49A )
	          {
	            v176 = v1->char_c.meta.cEffectSprite.h_inerc - 0.5;
	            v1->char_c.meta.cEffectSprite.h_inerc = v176;
	            if ( v176 < 0.0 )
	            {
	              v1->char_c.meta.cEffectSprite.h_inerc = 0.0;
	              v1->char_c.field_49A = 0;
	            }
	          }
	LABEL_545:
	          if ( viz_process(&v1->char_c) )
	            v1->char_c.meta.vtbl->set_seq_func2(&v1->char_c.meta, 0);
	          if ( !v1->char_c.meta.viz.get_frame_time && v1->char_c.meta.viz.get_frame == 2 )
	          {
	            scene_play_sfx(28);
	LABEL_550:
	            v1->char_c.field_49A = 0;
	          }
	        }
					*/
				}
			}
		}
	}

	// begin switch case
	int32_t sq = get_seq();
	switch(sq) {
		case 0:
			sub10func();
			if (h_inerc == 0.0) 
				field_49A = 0;
			if (field_49A != 0) {
				//label 25
				reset_forces();
				process();
			}
			//label 26
			if (h_inerc == 0.0) {
				h_inerc -= 0.5;
				if (h_inerc < 0.0) {
					reset_forces();
					field_49A = 0;
				}
			}
			if (h_inerc >= 0.0 || h_inerc + 0.5 <= 0.0) 
				process();
			else {
				reset_forces();
				field_49A = 0;
				process();
			}
			break;
		case 1:
			sub10func();
			if (field_49A) 
			{
				if (h_inerc > 0.0) 
				{
					h_inerc -= 0.5;
					if (h_inerc < 0.0) 
					{
						reset_forces();
						field_49A = 0;
					}
				}
				if (h_inerc < 0.0) {
					h_inerc += 0.5;
					if (h_inerc > 0.0) {
						reset_forces();
						field_49A = 0;
					}
				}
			} else {
				reset_forces();
			}
			if (process()) {
				if (get_frame() != 0) {
					set_seq(2);
				}
			}
			break;
		case 2:
			sub10func();
			if (field_49A) {
				if(h_inerc > 0.0) 
				{
					h_inerc -= 0.5;
					if(h_inerc < 0.0) 
					{
						reset_forces();
						field_49A = 0;
					}
				}
				if (h_inerc >= 0.0 || h_inerc + 0.5 <= 0.0) {
					process();
				} else {
					reset_forces();
					field_49A = 0;
					process();
				}
			} else {
				reset_forces();
				process();
			}
			break;
		case 3:
			sub10func();
			if(field_49A) {
				if(h_inerc > 0.0) {
					h_inerc -= 0.5;
					if (h_inerc < 0.0) {
						reset_forces();
						field_49A = 0;
					}
				}
				if (h_inerc < 0.0) {
					h_inerc += 0.5;
					if( h_inerc >0.0) {
						reset_forces();
						field_49A =0;
					}
				}
			} else 
				reset_forces();
			if (process() && get_frame() != 0)
				//label 55
				set_seq(0);
			break;
		case 4:
			sub10func();
			char_h_move(4.0);
			process();
			break;
		case 5:
			sub10func();
			char_h_move(-4.0);
			process();
			break;
		case 6:
			if(get_subseq() != 0) {
				sub10func();
				if (get_subseq() != 0) {
					if (!field_49A)
						reset_forces();
				}
			}
			if (!(get_subseq() < 0) | get_subseq() == 0) {
				v_inerc -= v_force;
				if (char_on_ground()) {
					//label 98
					set_seq(10);
					//label 99
					y = getlvl_height();
					reset_forces();
					break;
				}
			}
			process();

			if (get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1) {
				break;
			}
			//label 70
			char_h_move(0.0);
			v_inerc = 16.0;
			v_force = 0.80000001;
			field_49A = 0;
			break;
		case 7:
			if(!get_subseq()) {
				sub10func();
				if(!get_subseq()) {
					if(!field_49A) 
						reset_forces();
				}
			}
			if(!(get_subseq() < 0) | get_subseq() == 0) {
				v_inerc -= v_force;
				if (char_on_ground_down()) {
					//label 98
					set_seq(10);
					//label 99
					y = getlvl_height();
					reset_forces();
					break;
				}
			}
			process();

			if(get_elaps_frames() || get_frame_time() || get_subseq() != 1) {
				break;
			}
			//label 70
			char_h_move(6.5);
			v_inerc = 16.0;
			v_force = 0.80000001;
			field_49A = 0;
			break;
		case 8:
			if(!(get_subseq())) {
				sub10func();
				if (!get_subseq()) {
					if(!field_49A)
						reset_forces();
				}	
			}
			if (!(get_subseq() < 0) | get_subseq()) {
				v_inerc -= v_force;
				if (char_on_ground_down()) {
					//label 98
					set_seq(10);
					//label 99
					y = getlvl_height();
					reset_forces();
					break;
				}
			}
			process();
			if(!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1) {
				char_h_move(-6.5);
				v_inerc = 16.0;
				v_force = 0.80000001;
				field_49A = 0;
			}
			break;
		case 9:
			if (v_force == 0.0) {
				v_force = 0.60000002;
				v_inerc -= v_force;
				//label 101
				if (!char_on_ground_down()) {
					process();
				} else {
					reset_forces();
					field_49A = 0;
					process();
				}
			} else {
				reset_forces();
				process();
			}
			//
			set_seq(10);
			//label 99
			y = getlvl_height();
			reset_forces();
			break;
			//
		case 10:
			sub10func();
			reset_forces();
			if (process()) {
				if(dY()) {
					set_seq(2);
				} else {
					set_seq(0);
				}
				set_seq(0); //?
			}
			break;
		// landing state?
		case 197:
			if(!(get_subseq()) || get_subseq() == 3)
				sub10func();
			if(get_subseq() < 3) {
				v_inerc -= v_force;
				if(char_on_ground_down()) {
					//label 111
					y = getlvl_height();
					reset_forces();
					set_seq(3);
					break;
				}
			}
			if (!process()) {
				//label 117
				if(get_subseq() == 3 && get_frame() == 2 && !get_frame_time()) {
					if(enemy->x < x)
						dir = -1;
					if(enemy->x > x) {
						dir == 1;
					}
					if (get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1) {
						break;
					}
					v_inerc = 8.0;
					//label 129
					h_inerc = 13.5;
					v_force = 0.5;
					break;
				}
			}
	        if (controlling_type == 2) {
	          set_seq(700);
              field_51C = 3;
              field_520 = 3;
              break;
	        }
	        
	        if(dY() > 0) {
	        	set_seq(1);
	        }
	        //label 117
			if(get_subseq() == 3 && get_frame() == 2 && !get_frame_time()) {
				if(enemy->x < x)
					dir = -1;
				if(enemy->x > x) 
					dir == 1;
				if (get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1) {
					break;
				}
				v_inerc = 8.0;
				//label 129
				h_inerc = 13.5;
				v_force = 0.5;
				break;
			}
			break;
		case 198:
			if(!get_subseq() || get_subseq() == 3){
				sub10func();
				if(get_subseq() < 3) {
					v_inerc -= v_force;
					if(char_on_ground_down()) {
						y = getlvl_height();
						reset_forces();
						set_seq(3);
						break;
					}
				}
				if (!process()) {
					//label 141
					if(get_subseq() == 3 && get_frame() == 2 && !get_frame_time()) {
						if(enemy->x < x) 
							dir = -1;
						if(enemy->x > x) 
							dir = 1;
					}
					if (!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() ==1) {
						v_inerc = 8.0;
						//label 129: v28 = -13.5
						h_inerc = -13.5;
						v_force = 0.5;
					}
				}
				if (controlling_type == 2) {
					set_seq(700);
					field_51C = 3;
					field_520 = 3;
				}
				else {
					set_seq(0);
					if(dY() > 0)
						set_seq(1);
					// label 141
					if(get_subseq() == 3 && get_frame() == 2 && !get_frame_time()) {
						if(enemy->x < x) 
							dir = -1;
						if(enemy->x > x) 
							dir = 1;
					}
					if (!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() ==1) {
						v_inerc = 8.0;
						//label 129: v28 = -13.5
						h_inerc = -13.5;
						v_force = 0.5;
					}
				}

			}
			break;
		case 199:
			sub10func();
			if(!process()) {
				//label 158
				if(!get_subseq() && get_frame() == 6 && !get_frame_time()) {
					if(enemy->x < x) 
						dir = -1;
					if (enemy->x > x) 
						dir = 1;
				}
			}
			if (controlling_type == 2) {
				set_seq(700);
				field_51C = 3;
				field_520 = 3;
			} else {
				set_seq(0);
				if(dY() > 0) {
					set_seq(1);
				}
				//label 158
				if(!get_subseq() && get_frame() == 6 && !get_frame_time()) {
					if(enemy->x < x) 
						dir = -1;
					if (enemy->x > x) 
						dir = 1;
				}
			}
			break;
		case 200:
			sub10func();
			field_49A = 1;
			//sub_469F30(this, 3, 4, 16776960);
			process();
			if(get_subseq() != 1) {
				//label 176
				if( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1) {
					char_h_move(15.0);
					scene_add_effect(this, 125, dir + x, y+80, dir, 1);
					scene_add_effect(this, 126, x, y+80, dir, 1);
					scene_play_sfx(31);
				}
			} else {
				set_seq(204);
			}
			if(dX(dir) < 0 | dX(dir) == 0) {
				set_seq(211);
			} else {
				set_seq(212);
			}
			if(!get_elaps_frames() % 5) {
				//scene_add_effect(this, 124, x+50.0-(MT_getnext() % 0x64u),(MT_getnext()%0xC8u) + y,dir, 1);
			}
			if(dY() >= 0) {
				++field_7D0;
				if ((dX(dir) > 0 || dX(dir) <= 5) && dX(dir) <= 60) {
				//label 176
				if( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1) {
					char_h_move(15.0);
					scene_add_effect(this, 125, dir + x, y+80, dir, 1);
					scene_add_effect(this, 126, x, y+80, dir, 1);
					scene_play_sfx(31);
				}
			} else {
				set_seq(204);
			}
				if(dX(dir) < 0 | dX(dir) == 0) {
					set_seq(211);
				} else {
					set_seq(212);
				}
			}
			break;
		//leftoff: case 201:
		case 201:
			sub10func();
			h_inerc += 1.75;
			if(h_inerc > 0.0) 
				h_inerc = 0.0;
			if(!get_elaps_frames() % 5) {
				//scene_add_effect(this, 124, x+50.0-(MT_getnext() % 0x64u), y, dir, 1);
			}			
			if (process()) {
				//label 186
				set_seq(0);
				h_inerc = 0.0;
			} else if (!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1) {
				char_h_move(-15.0);
				v_inerc = 5.0;
				v_force = 0.75;
				scene_add_effect(this, 125, x, y+80.0, dir, 1);
				scene_add_effect(this, 126, x, y+80.0, dir, 1);
				scene_play_sfx(31);
			}
			//
			if (!get_frame_time() && get_frame() == 1) {
				char_h_move(-25.0);
				scene_add_effect(this, 125, x, y+80.0, dir, 1);
				scene_add_effect(this, 126, x, y+80.0, dir, 1);
				scene_play_sfx(31);
			}
			break;
		case 202: 
			v_inerc -= v_force;
			if(char_on_ground_down()) {
				//label 191
				reset_forces();
				y = getlvl_height();
				set_seq(10);
			} else {
				if((get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5)) {
					//scene_add_effect(this, 124, x+50.0 - (MT_getnext() % 0x64u),(MT_getnext() % 0xC8u) + y, dir, 1);
				}
				if(process()) {
					set_seq(9);
					if(!get_subseq() && !get_frame_time() && get_frame() == 1) {
						field_7D0 = 0;
						char_h_move(10.0);
						v_inerc = 5.0;
						v_force = 0.5;
						scene_add_effect(this, 126, x, y + 110.0, dir, 1);
						scene_play_sfx(31);
					}
					if(!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2) {
						flip_with_force();
					}
					//
					if((get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5)) {
						//scene_add_effect(this, 124, x+50.0 - (MT_getnext() % 0x64u), (MT_getnext() % 0xC8u) + y, dir, 1);
					}
					process();
					if(!get_subseq() && !get_frame_time() && get_frame() == 1) {
						char_h_move(10.0);
						v_inerc = 5.0;
						v_force = 0.5;
						scene_add_effect(this, 125, 80 + x, y + 110.0, dir, 1);
						scene_add_effect(this, 126, x, y+110.0, dir, 1);
						scene_play_sfx(31);
					} 
					if(!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2) {
						flip_with_force();
					}
				}
			}
			break;
		case 203:
			break;
		default:
			char_c::func10();
			break;
	}
}

void char_youmu::func20()
{
    uint16_t cprior = get_cprior();
    uint32_t fflags = get_pframe()->fflags;

    bool cc = (fflags & FF_CANCELLEABLE) != 0;
    bool cu = (fflags & FF_HJC) != 0;
    int32_t sq = get_seq();
  /*
  cprior = this->char_c.meta.current_seq_frames_vector->cprior;
  v3 = this->char_c.meta.current_frame_params->fflags & 0x20;
  v133 = this->char_c.meta.current_frame_params->fflags & 0x20;
  v4 = this->char_c.meta.current_frame_params->fflags & 0x200000;
  */

  if ( !check_AB_pressed() )
  {
    if ( cc || cu )
    {
      /*
      v5 = pres_comb;
      if ( v5 >= 0x2BC && v5 < 0x320 )
      {
        meta.vtbl->set_seq_func2(&meta, LOWORD(pres_comb));
        input_push_pressed_to_buf((Character *)v2);
        return;
      }*/
      if ( cc || cu )
      {
        if ( char_on_ground_flag() && field_4C4 == 0 )
        {
          if ( cu && cprior >= 10 && hi_jump_after_move() || border_escape_ground() || hi_jump(cprior, cu) || fw_bk_dash_ground(cprior, cu) )
            return;
        }
        else
        {
          if ( border_escape_air() )
            return;
          //weather id == 10
          int8_t mx = (weather_id == WEATHER_TEMPEST) + 2;;
          if ( fwd_dash_air(cprior, cu, mx, 2) || bkg_dash_air(cprior, cu, mx, 2) || flying_air(cprior, cu, mx) )
            return;
        	}
        }
      }
    }
}

void char_youmu::set_seq_params()
{
  if ( !field_8D0 )
  {
    //addbullet(this, 899, x - (600 * y + 100.0), y + 100.0, dir, -1, 0.0, 3);
    field_8D0 = 1;
  }
  
  if ( get_seq() <= 501 )
  {
    if ( get_seq() >= 500 )
    {
      field_190 = 0;
      reset_forces();
      not_charge_attack = 1;
      return;
    }
    if ( get_seq() > 214 )
    {
      switch ( get_seq() )
      {
        case 217:
          reset_ofs();
          
        h_inerc = 0.0;
        field_7D6 = 0;
        v_inerc = 0.0;
        v_force = 0.60000002;
        x_off = 0.0;
        y_off = 95.0;
        field_7DC = 14.5;
        field_7EC = 0.0;
        return;
        case 300:
        case 301:
        case 303:
        case 311:
        case 321:
        case 322:
        case 323:
        case 330:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_194 = 1;
          field_8B9 = 1;
          return;
        case 302:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_7D8 = 0;
          not_charge_attack = 1;
          field_194 = 1;
          field_8B9 = 1;
          return;
        case 304:
                  field_49A = 0;
	        field_190 = 0;
	        not_charge_attack = 1;
	        field_194 = 1;
	        field_8B9 = 1;
	        reset_forces();
	        return;
        case 305:
          field_190 = 0;
          field_194 = 1;
          field_8B9 = 1;
          return;
        case 306:
        case 309:
          field_190 = 0;
          field_7D0 = 0;
          field_194 = 1;
          field_8B9 = 1;
          return;
        case 307:
          reset_forces();
          field_190 = 0;
          field_7DC = 0.0;
          field_7D0 = 0;
          field_194 = 1;
          field_8B9 = 1;
          return;
        case 308:
          reset_forces();
          field_190 = 0;
          field_194 = 1;
          field_8B9 = 1;
          return;
        case 310:
          h_inerc = 0.0;
          field_190 = 0;
          v_inerc = 0.0;
          field_7D0 = 0;
          field_194 = 99;
          v_force = 0.5;
          return;
        case 320:
          field_49A = 0;
          field_190 = 0;
          field_194 = 1;
          field_8B9 = 1;
          return;
        case 400:
        case 401:
        case 402:
        case 410:
        case 411:
        case 412:
          field_190 = 1;
          reset_forces();
                    field_7D2 = 0;
          field_7D4 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          field_7D0 = 0;
          not_charge_attack = 1;
          return;
        case 404:
        case 406:
          field_190 = 1;
          field_7D2 = 0;
          field_7D4 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          field_7D0 = 0;
          not_charge_attack = 1;
          return;
        case 408:
          field_49A = 0;
          h_inerc = 14.0;
          field_190 = 0;
          field_7D0 = 0;
          v_inerc = 0.0;
          field_194 = 1;
          v_force = 0.0;
          field_8B9 = 1;
          return;
        case 414:
        case 415:
        case 416:
          v_force = 0.0;
          field_190 = 1;
          h_inerc  = h_inerc;
          field_7D2 = 0;
          
          field_7D4 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
                  field_7D0 = 0;
        not_charge_attack = 1;
        h_inerc = h_inerc * 0.1000000014901161;
        v_inerc = 0.1000000014901161* v_inerc;
        return;
        case 418:
          field_49A = 0;
          h_inerc = 14.0;
          field_190 = 0;
          field_7D0 = 0;
          v_inerc = 0.0;
          field_194 = 1;
          field_8B9 = 1;
          return;
        default:
              set_seq_params();
    return;
      }
    }
    else
    {
      if ( get_seq() == 214 )
      {
        h_inerc = 0.0;
        field_7D6 = 0;
        v_inerc = 0.0;
        v_force = 0.60000002;
        x_off = 0.0;
        y_off = 95.0;
        field_7DC = 14.5;
        field_7EC = 0.0;
        return;
      }
      
      if ( !get_seq() - 4 )
      {
        h_inerc = 4.0;
        return;
      }
      if ( get_seq() - 4 == 1 )
      {
        h_inerc = -4.0;
        return;
      }
    }
        set_seq_params();
    return;
  }
  if ( get_seq() > 797 )
  {
    if ( get_seq() != 798 )
    {
      set_seq_params();
      return;
    }
  }
  else if ( get_seq() != 797 )
  {
    switch ( get_seq() )
    {
      case 505:
      case 506:
      case 560:
      case 561:
      case 565:
      case 566:
      case 570:
      case 571:
        field_190 = 0;
        reset_forces();
        field_7D0 = 0;
        not_charge_attack = 1;
        return;
      case 507:
      case 508:
        field_190 = 0;
        
        field_7D0 = 0;
        not_charge_attack = 1;
        h_inerc = h_inerc * 0.1000000014901161;
        v_inerc = 0.1000000014901161 * v_inerc;
        v_force = 0.050000001;
        return;
      case 510:
      case 511:
          field_190 = 0;
	      reset_forces();
	      not_charge_attack = 1;
	      break;
      case 520:
      case 521:
        field_190 = 0;
        field_194 = 1;
        field_8B9 = 1;
        reset_forces();
        /*
        v13 = __OFSUB__(skills_1[1], 1);
        v12 = (skills_1[1] - 1) < 0;
        */
        not_charge_attack = 1;
        /*
        if ( !(v12 ^ v13) )
          field_51C = 2;
        */
        return;
      case 525:
      case 526:
        field_190 = 0;
        field_194 = 1;
        field_8B9 = 1;
        reset_forces();
        /*
        LOBYTE(v14) = skills_1[5];
        not_charge_attack = 1;
        if ( v14 >= 2 )
        {
          LOWORD(v14) = v14;
          vtbl->set_subseq_func3(&meta, v14);
        }
        */
        return;
      case 529:
        field_49A = 0;
        field_190 = 0;
        not_charge_attack = 1;
        field_194 = 1;
        field_8B9 = 1;
        reset_forces();
        return;
      case 530:
      case 531:
        field_190 = 0;
        field_194 = 0;
        reset_forces();
        not_charge_attack = 1;
        return;
      case 540:
      case 541:
      case 545:
      case 550:
      case 551:
      case 552:
      case 553:
        field_190 = 0;
        field_194 = 1;
        field_8B9 = 1;
        reset_forces();
        not_charge_attack = 1;
        return;
      case 546:
        field_190 = 0;
        field_194 = 3;
        field_8B9 = 3;
        reset_forces();
        field_7D0 = 0;
        not_charge_attack = 1;
        return;
      case 572:
      case 573:
        v_force = 0.0;
        field_190 = 0;
        h_inerc  = h_inerc;
        
        field_7D0 = 0;
        not_charge_attack = 1;
        h_inerc = h_inerc * 0.1000000014901161;
        v_inerc = 0.1000000014901161* v_inerc;
        return;
      case 600:
      case 603:
      case 612:
        field_190 = 0;
        field_194 = 1;
        field_8B9 = 1;
        reset_forces();
        field_7D0 = 0;
        return;
      case 601:
        field_194 = 5;
        field_8B9 = 5;
        field_194 = 5;
        field_8B9 = 5;
      case 602:
      case 605:
      case 606:
      case 607:
      case 710:
        field_190 = 0;
        reset_forces();
        field_7D0 = 0;
        break;
      case 604:
        field_194 = 6;
        field_8B9 = 6;
        field_194 = 6;
        field_8B9 = 6;
        return;
      case 608:
        field_190 = 0;
        reset_forces();
        field_7D0 = 0;
        /*
        sub_469450(this, 0, 0, 60);
        sub_483570();
        */
        weather_forecast_next();
        return;
      case 720:
      case 730:
        field_190 = 0;
        reset_forces();
        field_7D2 = 0;
        field_7D4 = 0;
        field_7D0 = 0;
        return;
      default:
        break;
    }
    set_seq_params();
    return;
  }
  reset_forces();
  scene_play_sfx(31);
  h_inerc = 17.5;
  field_7D0 = 0;
  v_inerc = 0.0;
  v_force = 1.2;
}
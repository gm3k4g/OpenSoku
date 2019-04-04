#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "suika.h"
#include <math.h>

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
/*
c_bullet *char_suika::new_bullet()
{
    c_bullet *tmp = new suika_bullets();
    return tmp;
}
*/

//Find the neutral jump!!
void char_suika::func10()
{
	x_delta = 0;
	y_delta = 80;

		int32_t sq = get_seq();

		//Some things to do with the character's main stuff
		switch (sq) {
			/*
			case 0:
				sub10func();
				if (h_inerc = 0.0)
					field_49A = 0;
				if(field_49A == 0)
					reset_forces();
					process();
					break; //return
					*/
		    case 0:
		        sub10func();
		        if (h_inerc == 0)
		            field_49A = 0;
		        stopping(0.5);
		        process();
		        break;
		        /*
			case 1:
				sub10func();
				if (h_inerc == 0)
					field_49A = 0;
				stopping(0.5);
				process();
				break;
				*/
		    case 1:
        		sub10func();
        		stopping(0.5);
        		if (process() && get_frame() == 0)
            		set_seq(2);
        		break;		
        		/*
			case 2:
				sub10func();
				stopping(0.5);
				if(process() && get_frame() == 0)
					set_seq(2);
				break;
				*/
			case 2:
				sub10func();
				stopping(0.5);
				process();
				break;
				/*
			case 3:
				//crouch?
				sub10func();
				if (field_49A ) {
					if (h_inerc > 0.0) {
						h_inerc -= 0.5;
						if (h_inerc < 0.0) {
							reset_forces();
							h_inerc = 0.0;
							field_49A = 0;
						}
					}
					//if (h_)
				}
				break;
				*/
				//Crouching
			case 3:
				sub10func();
				stopping(0.5);
				if(process() && get_frame() == 0)
					set_seq(0);
				break;
				//Walk forward
			case 4:
				sub10func();
				char_h_move(5.5);
				process();
				break;
				//Walk backwards
			case 5:
				sub10func();
				char_h_move(-5.5);
				process();
				break;
				//Neutral jump?
			case 6:
				if (get_subseq()) {
					sub10func();
					if(field_49A == 0)
						reset_forces();
				}
				if (get_subseq() >0)
				{
					v_inerc -= v_force;

					if (char_on_ground_down()) {
						set_seq(10);
						y = getlvl_height();
						reset_forces();
						break;
					}
				}
				process();

				if (get_subseq()	== 1 &&
						get_frame_time()	== 0 &&
						get_frame() 		== 0 &&
						get_elaps_frames()	== 0) {
					v_inerc = 16.0;
					v_force = 0.1;
					//field_49A = 0;
				}
				break;
				//process();

				//Jumping Forward
			case 7:
				if (get_subseq() == 0) {
					sub10func();
					if(field_49A == 0) {
						reset_forces();
					}
				if (get_subseq() > 0) {
					v_inerc -= v_force;

					if (char_on_ground_down()) {
						set_seq(10);
						y = getlvl_height();
						reset_forces();
						break;
					}
				}
				process();

				if (get_subseq()		== 1 &&
						get_frame_time()	== 0 &&
						get_frame() 		== 0 &&
						get_elaps_frames()	== 0) {
					v_inerc = 16.0;
					v_force = 0.75;
					char_h_move (5.5);
					field_49A = 0;
				}
				break;
				}
				//Jumping backwards
			case 8:
				if (get_subseq() == 0) {
					sub10func();
					if (field_49A == 0)
						reset_forces();
				}

				if (get_subseq()>0) {
					v_inerc -= v_force;

					if (char_on_ground_down()) {
						set_seq(10);
						y = getlvl_height();
						reset_forces();
						break;
					}
				}

				process();

				if (get_subseq()		== 1 &&
						get_frame_time()	== 0 &&
						get_frame()			== 0 &&
						get_elaps_frames()	== 0) {
					v_inerc = 16.0;
					v_force = 0.75;
					char_h_move(-5.5);
				}
				break;
				//What is this?
			case 9:
				if (v_force == 0)
					v_force = 0.6;

				v_inerc -= v_force;

				if (char_on_ground_down()) {
					set_seq(10);
					y = getlvl_height();
					reset_forces();
					break;
				}

				process();
				break;
				//Landing
			case 10:
				sub10func();
				reset_forces();
				if (process()) {
					if (dY() > 0)
						set_seq(2);
					else
						set_seq(0);
				}
				break;
				//?
			case 199:
		        sub10func();
		        if ( process() )
		        {

		            /*if ( LOBYTE(v2->controlling_type) == 2 )
		            {
		                set_seq(700);

		                field_51C = 3;
		                field_520 = 3;
		            }
		            else*/
		            {
		                set_seq(0);
		                if ( dY() > 0)
		                    set_seq(1);
		            }
		        }
		        else if ( get_frame_time() == 0  && get_frame() == 5)
		        {
		            if (enemy->x < x)
		                dir = -1;
		            else
		                dir = 1;
		        }
		        break;
		     //Neutral jumping?
			case 214:
		        if ( process())
		            set_seq(9);
		        else
		        {
		            if ( get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1)
		                scene_play_sfx(31);

		            if (get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 6)
		            {
		                set_seq(9);
		                break;
		            }
		            else
		            {
		                if ( dY() < 0)
		                {
		                    field_7D2 = 90 - dX(dir) * 45;
		                }
		                else if (dY() == 0)
		                {
		                    if (dX(dir) > 0 )
		                        field_7D2 = 0;
		                    else if (dX(dir) < 0 )
		                        field_7D2 = 180;
		                }
		                else if (dY() > 0)
		                {
		                    field_7D2 = -90 - dX(dir) * 45;
		                }

		                if ( get_subseq() == 5 || get_subseq() == 6 )
		                    v_inerc -= v_force;
		                if ( get_subseq() > 0 && get_subseq() < 5 )
		                {
		                    field_7D6 ++;
		                    field_7D4 = field_7D2 - dash_angle;
		                    if ( field_7D4 >180 )
		                        field_7D4 -= 360;
		                    else if (field_7D4 < -180)
		                        field_7D4 += 360;

		                    if ( field_7D4 > 0 )
		                    {
		                        if ( weather_id != WEATHER_SUNNY )
		                            dash_angle += 0.5;
		                        else
		                            dash_angle += 1.5;
		                    }
		                    else if ( field_7D4 < 0 )
		                    {
		                        if ( weather_id != WEATHER_SUNNY )
		                            dash_angle -= 0.5;
		                        else
		                            dash_angle -= 1.5;
		                    }

		                    h_inerc = cos_deg(dash_angle) * field_7DC;
		                    v_inerc = sin_deg(dash_angle) * field_7DC;

		                    if ( y > 680.0 )
		                        if ( v_inerc > 0.0 )
		                            v_inerc = 0.0;

		                    field_7DC += 0.3;
		                    if ( field_7DC > 12.0 )
		                        field_7DC = 12.0;

		                    spell_energy_spend( weather_id != WEATHER_SUNNY ? 10 : 5, 1);
		                    angZ = -dash_angle;


		                    if ( h_inerc < 0.0 )
		                        // angZ = 180 -angZ;
		                        angZ = 180.0 + dash_angle;

		                    if ( h_inerc < 0.0 )
		                        if ( get_subseq() == 1 )
		                            set_subseq(3);

		                    if ( h_inerc >= 0 )
		                        if ( get_subseq() == 3 )
		                            set_subseq(1);

		                    if ( h_inerc < 0.0 )
		                        if ( get_subseq() == 2 )
		                            set_subseq(4);

		                    if ( h_inerc >= 0)
		                        if ( get_subseq() == 4 )
		                            set_subseq(2);

		                    if ( get_elaps_frames() % 5 == 1 )
		                    {
		                        float yy = sin_deg(dash_angle) * 100.0 + y + 100.0;
		                        float xx = cos_deg(dash_angle) * 100.0 * dir + x;
		                        scene_add_effect(this, 125, xx, yy, dir, 1);
		                    }
		                    if ( (keyDown(INP_D) == 0 && field_7D6 > 10) || spell_energy <= 0 )
		                    {
		                        reset_ofs();
		                        angZ = 0;

		                        if ( get_subseq() == 1 || get_subseq() == 2 )
		                        {
		                            if ( dir == 1 )
		                            {
		                                if ( enemy->x >= x )
		                                    set_subseq(5);
		                                else
		                                {
		                                    dir = -dir;
		                                    h_inerc = -h_inerc;
		                                    set_subseq(6);
		                                }
		                            }
		                            else
		                            {
		                                if ( enemy->x <= x )
		                                    set_subseq(5);
		                                else
		                                {
		                                    dir = -dir;
		                                    h_inerc = -h_inerc;
		                                    set_subseq(6);
		                                }
		                            }
		                        }
		                        else if ( get_subseq() == 3 || get_subseq() == 4 )
		                        {
		                            if ( dir == 1 )
		                            {
		                                if ( enemy->x >= x )
		                                    set_subseq(6);
		                                else
		                                {
		                                    dir = -dir;
		                                    h_inerc = -h_inerc;
		                                    set_subseq(5);
		                                }
		                            }
		                            else
		                            {
		                                if ( enemy->x <= x )
		                                    set_subseq(6);
		                                else
		                                {
		                                    dir = -dir;
		                                    h_inerc = -h_inerc;
		                                    set_subseq(5);
		                                }
		                            }
		                        }
		                        break;
		                    }
		                }
		            }
		            if ( char_on_ground_down() )
		            {
		                y = getlvl_height();
		                v_force = 0.0;
		                v_inerc = 0.0;
		                if ( get_subseq() < 5 )
		                {
		                    reset_ofs();
		                    angZ = 0;
		                    set_seq(215);
		                }
		                else
		                {
		                    set_seq(10);
		                    reset_forces();
		                }
		            }
		        }
		        break;

		    default:
		        char_c::func10();
			}
	//}



}
/*
void char_suika::func20()
{

}
*/

void char_suika::set_seq_params() {

	/*
	  v1 = this;
  v2 = this->char_c.meta.playing_seq;
  if ( v2 <= 501 )
  {
    if ( v2 >= 500 )
    {
      this->char_c.not_charge_attack = 1;
      this->char_c.meta.field_18C = 0;
      char_c::reset_forces(&this->char_c);
      v1->char_c.meta.field_190 = 0;
      v1->char_c.field_538 = 0.0;
      v1->char_c.field_49A = 0;
      v1->char_c.field_7D0 = 0;
      v1->char_c.field_7D2 = 0;
      v1->char_c.meta.field_188 = 0;
      v1->char_c.meta.field_194 = 1;
      return;
	*/
	//What are we doing here?
	switch(get_seq()) {
		case 217:
			field_7D6 = 0;
			h_inerc = 0.0;
			v_inerc = 0.0;
			v_force = 0.60;
			x_off = 0.0;
			y_off = 72.0;
			field_7DC = 9.0;
			field_7EC = 0.0;
			break;
		case 300:
		case 301:
		case 330:
			not_charge_attack = 1;
			//field_49A is associated with "forces"
			if (field_49A == 0) {//!field_49A) 
			reset_forces();
			  }
			field_190 = 0;
			field_194 = 1;
			break;
		case 302:
			reset_forces();
			field_190 = 0;
			field_49A = 0;
			field_194 = 1;
			not_charge_attack = 1;
			break; //return
		case 303:
			if( field_49A == 0) {
			reset_forces();
			}
			field_190 = 0;
			field_194 = 1;
			not_charge_attack = 1;
			break; //return
		case 304:
			field_49A = 0;
			field_194 = 1;
			field_190 = 0;
			reset_forces();
			not_charge_attack = 1;
			break; //return
		case 305:
			v_inerc = 0.0;
			field_49A = 0;
			field_190 = 0;
			h_inerc = 9.0;
			field_194 = 2;
			break; //return
		case 306:
			field_7D0 = 0;
			field_190 = 0;
			field_194 = 1;
			break; //return
		case 307:
			field_194 = 1;
			field_190 = 0;
			not_charge_attack = 1;
			v_force = 0.0;
			h_inerc *= 0.20;
			v_inerc *= 0.20;
			break; //return
		case 308:
			field_194 = 1;
			field_190 = 0;
			not_charge_attack = 1;
			break; //return
		case 309:
			field_194 = 1;
			/*v4 = 8.0 < h_inerc;
			if( v4)
				h_inerc = 8.0;
			*/
			if(h_inerc < -8.0)
				h_inerc = -8.0;
			not_charge_attack = 1;
			break; //return
		case 310:
			h_inerc = 0.0;
			field_7D0 = 0;
			v_inerc = 0.0;
			field_190 = 0;
			field_194 = 99;
			v_force = 0.5;
			break; //return
		case 320:
			field_49A = 0;
			field_190 = 0;
			field_194 = 1;
			break; //return
		case 321:
		case 322:
			if (field_49A == 0)
				reset_forces();
			field_190 = 0;
			field_194 = 1;
			break; //return
		case 400:
			field_190 = 0;
			reset_forces();
			field_7D0 = 0;
			field_7D2 = 0;
			field_7D4 = 0;
			not_charge_attack = 1;
			break; //return
		case 401:
			field_190 = 0;
			reset_forces();
			field_7D6 = 0;
			field_7D0 = 0;
			field_7D2 = 0;
			not_charge_attack = 1;
			break; //return
		case 402:
			field_194 = 1;
		case 404:
		case 405:
		case 406:
			field_190 = 0;
			field_7D0 = 0;
			field_7D2 = 0;
			field_7D4 = 0;
			not_charge_attack = 1;
			v_force = 0.0;
			h_inerc *= 0.20;
			v_inerc *= 0.20;
			break; //return
		case 408:
			h_inerc = 10.0;
			field_49A = 0;
			field_7D0 = 0;
			field_190 = 0;
			v_inerc = 0.0;
			field_194 = 3;
			break; //return
		case 409:
			field_49A = 0;
			v_force = 0.34;
			field_7D0 = 0;
			field_190 = 0;
			field_194 = 1;
			break; //return
		case 410:
			field_190 = 0;
			reset_forces();
			field_7D2 = 0;
			not_charge_attack = 1;
			break; //return
		case 411:
		case 412:
			field_190 = 0;
			reset_forces();
			field_7D0 = 0;
			field_7D2 = 0;
			not_charge_attack = 1;
			break; //return
		case 414:
			field_190 = 0;
			v_force = 0.0;
			field_7D2 = 0;
			not_charge_attack = 1;
			h_inerc *= 0.20;
			v_inerc *= 0.20;
			break; //return
		case 415:
		case 416:
		case 418:
			h_inerc = 10.0;
		//case 505:
	}

}
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
void char_suika::func10(){

	x_delta = 0;
	y_delta = 80;

	if ( field_890 > 0 ) {
		field_890 -= 1;
		if ( enemy->health <= 0 || health <= 0 )
			field_890 = 0;
		spell_energy_spend(2,30);
	}

	if ( field_892 > 0 ) {
		field_892 -= 1;
		if ( enemy->health <= 0 || health <= 0 )
			field_892 = 0;
		field_534 *= 0.5;
	}

	if ( field_894 ) { // v1->field_894
		if ( getlvl_height() >= y && 
			!(get_pframe()->fflags & 4) )
			field_894 = 0;
	}

	if ( get_seq() == 501 ) {
		if ( get_subseq() <= 1 || get_subseq() == 2 && get_frame() <= 4 ) {
			float v1387;
			if ( skills_1[0] >= 1 )
				v1387 = 250.0;
			if ( skills_1[0] >= 3 )
				v1387 = 500.0;
			if ( skills_1[0] >= 4 )
				v1387 = 750.0;
			if ( v1387 > field_188 )
				field_538 = 0.0;
		}
	}

	//Continue from line 49 in /edited/func10

	//switch case scenario below
	int32_t sq = get_seq();
	switch ( sq ) {
		case 0:
			sub10func();
			if ( h_inerc == 0.0 )
				field_49A = 0;
			stopping(0.5);
			process();
			return;
		case 1:
			sub10func();
			stopping(0.5);
			process();
			if ( process() && get_frame() == 0 ) {
				set_seq(2);
			}
			return;
		case 2:
			sub10func();
			stopping(0.5);
			process();
			return;
		case 3:	
			sub10func();
			stopping(0.5);
			if ( process() && get_frame() == 0 ) {
				set_seq(0);
			}
			return;
		//Move right?
		case 4:
			sub10func();
			char_h_move(5.5);
			process();
			return;
		//Move left?
		case 5:
			sub10func();
			char_h_move(-5.5);
			process();
		case 6:
			if ( get_subseq() == 0 ) {
				sub10func();
				if ( field_49A == 0 )
					reset_forces();
			}

			if ( (get_subseq() < 0) == 0 | get_subseq() == 0  ) {
				v_inerc -= v_force;
				if ( char_on_ground_down() )
					set_seq(10);
					y = getlvl_height();
					reset_forces();
					return;
			}
			process();

			if ( get_elaps_frames() == 1 ||
			 		get_frame_time() == 1 ||
			 		get_frame() == 1 ||
		 			get_subseq() != 1)
			 	return;

			 char_h_move(0.0);
			 v_inerc = 16.0;
			 v_force = 0.75;
			 field_49A = 0;

			 return;

		case 7:
			if ( get_subseq() == 0)
				sub10func();
				if ( field_49A )
					reset_forces();
			if ( !(get_subseq() < 0) | get_subseq() == 0 ) {
				v_inerc -= v_force;
				if (char_on_ground_down() ) {
					set_seq(10);
				}
					y = getlvl_height();
					reset_forces();
					return;
				}

				process();

				if ( get_elaps_frames() == 1 ||
						get_frame_time() == 1 ||
						get_frame() == 1 ||
						get_subseq() != 1 )
					return;
		case 8: 
			if ( get_subseq() == 0 ) {
				sub10func();
				if ( field_49A == 0 ) {
					reset_forces();
				}

				if ( !(get_subseq() < 0 ) | get_subseq() == 0 )
					v_inerc -= v_force;

				if ( char_on_ground_down() ) {
					set_seq(10);
					}
				y = getlvl_height();
				reset_forces();
				return;
				}
				process();
				if ( get_elaps_frames() == 0 && 
						get_frame_time() == 0 &&
						get_frame() == 0 &&
						get_subseq() == 1) {
					char_h_move(-8.0);
					v_inerc = 16.0;
					v_force = 0.75;
					field_49A = 0;
				}
			return;
		case 9:
			if ( v_force == 0.0 )
				v_force = 0.60000002;
			v_inerc -= v_force;
			if ( char_on_ground_down() ) {
			set_seq(10);
			y = getlvl_height();
			reset_forces();
			//goto label_112
			process();
			}

			return;
		case 10:
			sub10func();
			reset_forces();
			if ( process() ) {
				if ( keyDown(INP_Y_AXIS) )
					set_seq(2);
				else
					set_seq(0);
			}
			return;
		case 197:
			sub10func();
			//if ( process() == 0 )
				//goto label_121
			//if ( controlling_type == PC_STORY_MODE )
				//goto label_158
			if ( y > 0 )
				set_seq(1);
			//if ( get_elaps_frames() )
				//goto label_131;
			if ( get_frame_time() == 0 && 
					get_frame() == 0 &&
					get_subseq() == 1 )
				h_inerc = 15.0;
			/* if ( get_elaps_frames() == 1 ||
					get_frame_time() == 1 ||
					get_frame() == 1 ) */
				//goto LABEL_131
			if ( get_subseq() != 2 )
				return;
			reset_forces();

			if ( get_subseq() != 2 )
				return;
			if ( get_frame() != 5 )
				return;
		//case 198:
		}

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
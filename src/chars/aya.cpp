#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "aya.h"
#include <math.h>

//"Constructor" ?
char_aya::char_aya(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_AYA;
	pgp->load_dat("aya",pal);
	char_loadsfx("aya");
	cards_load_cards(&chr_cards,"aya");
	load_face("aya");
	load_spells("aya");
	stand_gfx->init(this,"aya");
}

//Initialize some variables
void char_aya::init_vars()
{
	field_138 = -6.0;
	field_890 = 0;
	field_892 = 0;
	field_894 = 0;
	field_896 = 0;
	char_c::init_vars();
}

//Bullet function
/*
c_bullet *char_aya::new_bullet()
{
    c_bullet *tmp = new aya_bullets();
    return tmp;
}
*/

//func10
/* Mostly related with how the character reacts to opponent attacks.*/
void char_aya::func10()
{

	//pre-switch statements

	//main: switch statement
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
			process();
			break;
		case 3:
			sub10func();
			stopping(0.5);
			if ( !process() )
				return;
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
			if (!get_subseq() )
			{
				sub10func();
				if (!get_subseq())
				{
					if ( !field_49A )
						reset_forces();
				}
			}
			if ( (get_subseq() < 0) | (get_subseq() == 0) )
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

			if ( get_frame_time() ||
				 get_frame() ||
				 get_subseq() != 1)
			{
				v_inerc = 18.0;
				v_force = 0.75;
				field_49A = 0;
			}
			break;

			//case 7:
	}


}


//contains attacks?
void char_aya::func20()
{

//pre-switch statements

//main: switch statement

}

//also mostly to do with attacks (both func10 and func20)
void char_aya::set_seq_params()
{

//pre-switch statements
//?

//main: switch statement
	switch(get_seq())
	{
	//case 4: movement forward
	//case 5: movement backwards
	case 214:
	case 217:
		reset_ofs();
		h_inerc = 0.0;
		field_7D6 = 0;
		v_inerc = 0.0;
		v_force = 0.60000002;
		x_off = 0.0;
		y_off = 95.0;
		field_7DC = 12.0;
		field_7EC = 0.0;
		break;
	case 300:
	case 301:
	case 303:
	case 320:
	case 321:
	case 330:
		if( !field_49A )
			reset_forces();
		field_190 = 0;
		field_194 = 1;
		break;
	case 302:
		if ( !field_49A )
			reset_forces();
		field_190 = 0;
		field_49A = 0;
		h_inerc = 0.0;
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
		h_inerc = 17.5;
		v_force = 0.0;
		field_49A = 0;
		field_190 = 0;
		field_194 = 1;
		break;
	case 306:
		field_7D0 = 0;
		field_190 = 0;
		field_194 = 1;
		break;
	case 307:
		h_inerc = 0.0;
		field_7D0 = 0;
		v_inerc = 0.0;
		field_190 = 0;
		v_force = 0.0;
		field_194 = 1;
		field_7DC = 25.0;
		break;
	case 308:
		field_194 = 1;
		h_inerc = 0.0;
		field_190 = 0;
		v_inerc = 0.0;
		break;
	case 309:
		field_194 = 1;
		field_190 = 0;
		break;
	case 310:
		h_inerc = 0.0;
		field_7D0 = 0;
		v_inerc = 0.0;
		field_190 = 0;
		field_194 = 99;
		v_force = 0.5f;
		break;
	case 322:
		if ( !field_49A )
			reset_forces();
		field_190 = 0;
		field_49A = 0;
		h_inerc = 0.0;
		field_194 = 1;
		break;
	case 400:
	case 401:
	case 410:
	case 412:
		field_190 = 0;
		reset_forces();
		field_7D0 = 0;
		field_7D2 = 0;
		field_7D6 = 0;
		not_charge_attack = 1;
		break;
	case 402:
		field_190 = 0;
		reset_forces();
		field_7D2 = 0;
		field_7D6 = 0;
		field_7D0 = 0;
		field_7D8 = 0;
		break;
	case 404:
	case 406:
		field_190 = 0;
		h_inerc *= 0.25;
		v_inerc *= 0.25;
		v_force = 0.5;
		field_7D0 = 0;
		field_7D2 = 0;
		field_7D6 = 0;
		not_charge_attack = 1;
		break;
	case 408:
		if ( !get_elaps_frames() &&
			 !get_frame_time() &&
			 !get_frame() &&
			 !get_subseq())
		{
			field_49A = 0;
			h_inerc = 17.5;
			field_7D0 = 0;
			field_194 = 1;
			v_inerc = 0.0;
			field_190 = 0;
		}
		h_inerc -= 0.5;
		if ( (h_inerc - 0.5) < 0.0)
			h_inerc = 0.0;
		if (process())
			set_seq(0);
		if (!get_frame_time() && get_frame() == 6)
			scene_play_sfx(27);
		break;
	case 409:
		field_49A = 0;
		v_force = 0.34999999;
		field_7D0 = 0;
		field_190 = 0;
		field_194 = 1;
		break;
	case 411:
		field_190 = 0;
		reset_forces();
		field_7D0 = 0;
		field_7D2 = 0;
		field_7D6 = 0;
		not_charge_attack = 0;
		break;
	case 414:
	case 416:
		v_force = 0.5;
		field_190 = 0;
		h_inerc *= 0.25;
		v_inerc *= 0.25;
		field_7D0 = 0;
		field_7D2 = 0;
		field_7D6 = 0;
		not_charge_attack = 1;
		break;
	case 415:
		v_force = 0.5;
		field_190 = 0;
		h_inerc *= 0.25;
		v_inerc *= 0.25;
		field_7D0 = 0;
		field_7D2 = 0;
		field_7D6 = 0;
		not_charge_attack = 0;
		break;
	case 418:
		v_inerc = 0.0;
		v_force = 0.0;
		field_7DC = 25.0;
		field_49A = 0;
		field_190 = 0;
		field_194 = 1;
		break;
	//actual beginning?
	case 502:
		field_18C = 0;
		field_190 = 0;
		reset_forces();
		field_7D2 = 0;
		field_7D6 = 0;
		field_7D0 = 0;
		field_7D8 = 0;
		break;
	case 505:
	case 506:
		field_18C = 4;

		field_190 = 0;
		reset_forces();
		field_7D2 = 0;
		field_7D6 = 0;
		field_7D0 = 0;
		field_7D8 = 0;
		break;
	case 507:
	case 508:
		field_18C = 4;
		field_190 = 0;
		h_inerc *= 0.25;
		v_inerc *= 0.25;
		field_7D2 = 0;
		field_7D6 = 0;
		field_7D0 = 0;
		field_7D8 = 0;
		break;
	case 510:
	case 511:
		field_18C = 8;
		field_190 = 0;
		reset_forces();
		field_7D2 = 0;
		field_7D6 = 0;
		field_7D0 = 0;
		field_7D8 = 0;
		break;
	case 520:
	case 521:
	case 522:
	case 523:
		field_18C = 1;
		reset_forces();
		field_190 = 0;
		field_49A = 0;
		field_7D0 = 0;
		field_194 = 1;
		break;
	case 525:
	case 526:
	case 527:
	case 528:
		field_18C = 5;
		reset_forces();
		field_190 = 0;
		field_49A = 0;
		field_7D0 = 0;
		field_7D8 = 0;
		field_194 = 1;
		break;
	case 529:
		field_18C = 5;
		reset_forces();
		field_190 = 0;
		field_49A = 0;
		field_194 = 1;
		break;
	case 530:
	case 531:
	case 532:
	case 533:
		field_18C = 9;
		reset_forces();
		field_190 = 1;
		field_49A = 0;
		break;
	case 540:
		field_18C = 2;
		field_190 = 0;
		reset_forces();
		v_force = 0.0;
		field_7D0 = 0;
		field_7D2 = 0;
		field_7D6 = 0;
		field_7D8 = 0;
		h_inerc *= 0.25;
		v_inerc *= 0.25;
		break;
	case 545:
		field_18C = 6;
		field_194 = 1;
		h_inerc = 0.0;
		field_190 = 0;
		v_inerc = 0.0;
		break;
	case 546:
		h_inerc = 0.0;
		field_194 = 0;
		field_190 = 0;
		v_inerc = 0.0;
		field_18C = 6;
		break;
	case 550:
	case 551:
	case 552:
	case 553:
		field_18C = 10;
		field_7D0 = 0;
		field_194 = 1;
		field_190 = 0;
		reset_forces();
		break;
	case 554:
		field_18C = 10;
		field_194 = 1;
		field_190 = 0;
		break;
	case 560:
	case 561:
		field_18C = 3;
		field_7D0 = 0;
		field_7D2 = 0;
		reset_forces();
		field_190 = 0;
		break;
	case 562:
	case 563:
		v_force = 0.0;
		field_7D0 = 0;
		field_7D2 = 0;
		field_190 = 0;
		field_18C = 3;
		h_inerc *= 0.1000000014901161;
		v_inerc *= 0.1000000014901161;
		break;
	case 565:
	case 567:
		field_18C = 7;
		field_7D0 = 0;
		field_7D2 = 0;
		reset_forces();
		field_190 = 0;
		break;
	case 570:
	case 571:
		field_18C = 11;
		reset_forces();
		field_190 = 0;
		break;
	case 573:
		field_18C = 11;
		v_force = 0.0;
		field_190 = 0;
		h_inerc *= 0.1500000059604645;
		v_inerc *= 0.1500000059604645;
		break;
	case 600:
	case 601:
	case 602:
	case 604:
	case 605:
	case 607:
	case 608:
	case 611:
	case 657:
	case 658:
	case 661:
		field_7D0 = 0;
		field_7D2 = 0;
		field_190 = 1;
		reset_forces();
		break;
	case 603:
		field_190 = 0;
		reset_forces();
		v_force = 0.0;
		field_7D0 = 0;
		field_7D2 = 0;
		field_7D6 = 0;
		field_7D8 = 0;
		h_inerc *= 0.25;
		v_inerc *= 0.25;
		break;
	case 606:
		field_7D0 = 0;
		field_7DC = 0.0;
		field_7D2 = 0;
		field_7D4 = 0;
		field_7D6 = 0;
		field_7D8 = 0;
		field_190 = 0;
		field_194 = 1;
		reset_forces();
		break;
	case 612:
	case 662:
		reset_forces();
		field_190 = 0;
		field_49A = 0;
		field_7D0 = 0;
		field_194 = 1;
		break;
	case 710:
	case 720:
	case 721:
	case 730:
		field_7D0 =0;
		field_7D2 = 0;
		field_7D4 = 0;
		reset_forces();
		break;
	case 740:
		field_7DC = 0.0;
		field_7D0 = 0;
		dash_angle = 0.0;
		field_7D2 = 0;
		field_7E4 = 0.0;
		field_7D4 = 0;
		field_7E8 = 0.0;
		field_7D6 = 0;
		field_7D8 = 0;
		field_7EC = 0.0;
		reset_forces();
		break;
	default:
		char_c::set_seq_params();
		break;
	}
}
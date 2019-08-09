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
	if (get_seq() > 149 && get_seq() < 159 && !bbarrier_show)
	{
		bbarrier_show = 1;
		if (get_seq() > 149 && get_seq() < 154 )
			addbullet(this,NULL, 998, (double)(57 * (char)dir) + x, y + 94.0, dir, 1, 0 ,0);
		if (get_seq() > 153 && get_seq() < 158 )
			addbullet(this,NULL,998, (double)(57 * (char)dir) + x, y + 60.0, dir, 1, 0, 0);
		if (get_seq() == 158)
			addbullet(this,NULL,998, (double)(57*(char)dir) + x, y + 100.0, dir, 1, 0, 0);	
	}

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
		case 3: //crouching
			sub10func();
			stopping(0.5);
			//changed this
			//if ( !process() )
			if (process() && get_frame() == 0)
				set_seq(0);
			break;
		case 4://move forward
			sub10func();
			char_h_move(5.5);
			process();
			break;
		case 5://move backward
			sub10func();
			char_h_move(-5.5);
			process();
			break;
		case 6://jumping upward
			if (get_subseq() == 0)
	        {
	            sub10func();
	            if (field_49A == 0)
	                reset_forces();
	        }

	        if (get_subseq()>0)
	        {
	            v_inerc -=v_force;

	            if (char_on_ground_down())
	            {
	                set_seq(10);
	                y = getlvl_height();
	                reset_forces();
	                break;
	            }
	        }

	        process();

	        if (get_subseq()       == 1 &&
	                get_frame_time()   == 0 &&
	                get_frame()        == 0 &&
	                get_elaps_frames() == 0)
	        {
	            v_inerc = 18.0;
	            v_force = 0.75;
	            field_49A = 0;
	        }
	        break;
		case 7://jumping forward
			    if (get_subseq() == 0)
		        {
		            sub10func();
		            if (field_49A == 0)
		                reset_forces();
		        }

		        if (get_subseq()>0)
		        {
		            v_inerc -=v_force;

		            if (char_on_ground_down())
		            {
		                set_seq(10);
		                y = getlvl_height();
		                reset_forces();
		                break;
		            }
		        }

		        process();

		        if (get_subseq()       == 1 &&
		                get_frame_time()   == 0 &&
		                get_frame()        == 0 &&
		                get_elaps_frames() == 0)
		        {
		            v_inerc = 18.0;
		            v_force = 0.75;
		            char_h_move( 8.0);
		            field_49A = 0;
		        }
	        break;
		case 8://jumping backward
	        if (get_subseq() == 0)
	        {
	            sub10func();
	            if (field_49A == 0)
	                reset_forces();
	        }

	        if (get_subseq()>0)
	        {
	            v_inerc -=v_force;

	            if (char_on_ground_down())
	            {
	                set_seq(10);
	                y = getlvl_height();
	                reset_forces();
	                break;
	            }
	        }

	        process();

	        if (get_subseq()       == 1 &&
	                get_frame_time()   == 0 &&
	                get_frame()        == 0 &&
	                get_elaps_frames() == 0)
	        {
	            v_inerc = 18.0;
	            v_force = 0.75;
	            char_h_move( -8.0);
	        }
	        break;
		case 9://?
	        if (v_force == 0)
	            v_force = 0.6;

	        v_inerc -=v_force;

	        if (char_on_ground_down())
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
	        if (process())
	        {
	            if (dY() > 0)
	                set_seq(2);
	            else
	                set_seq(0);
	        }
	        break;
		case 197://tech forward
	        if ( (get_seq() == 0 && get_frame() <= 4) || get_subseq() == 2 )
	            sub10func();
	        if (!get_frame_time() && get_frame() == 5)
	        	addbullet(this,NULL,990, x, y, dir, 1, 0, 0);
	        if ( get_subseq() < 2 )
	            v_inerc -= v_force;
	        if ( char_on_ground_down() && get_subseq() < 2 )
	        {
	            y = getlvl_height();
	            reset_forces();
	            set_subseq(2);
	        }
	        else
	        {
	            if (process())
	            {
	                if ( controlling_type == 2)
	                {
	                    set_seq(700);
	                    field_51C = 3;
	                    field_520 = 3;
	                }
	                else
	                {
	                    set_seq(0);
	                    if ( dY() > 0 )
	                        set_seq(1);
	                }
	            }
	            else
	            {
	                if ( get_subseq() == 2 && get_frame() == 3 && get_frame_time() == 0)
	                {
	                    if ( enemy->x < x )
	                        dir = -1;
	                    if ( enemy->x > x )
	                        dir = 1;
	                }
	                if ( get_subseq() == 0 && get_frame() == 5 && get_frame_time() == 0)
	                {
	                    v_inerc = 4.8;
	                    h_inerc = 15.0;
	                    v_force = 0.4;
	                }
	            }
	        }
	        break;
		case 198://tech backward

	        if ( (get_subseq() == 0 && get_frame() <= 4) || get_subseq() == 2 )
	            sub10func();
	        if ( !get_frame_time() && get_frame() == 5)
	        	addbullet(this, NULL, 990, x, y, dir, 1, 0, 0);
	        if ( get_subseq() < 2 )
	            v_inerc -= v_force;
	        if ( char_on_ground_down() && get_subseq() < 2 )
	        {
	            y = getlvl_height();
	            reset_forces();
	            set_subseq(2);
	        }
	        else
	        {
	            if (process())
	            {

	                if ( controlling_type == 2)
	                {
	                    set_seq(700);
	                    field_51C = 3;
	                    field_520 = 3;
	                }
	                else
	                {
	                    set_seq(0);
	                    if ( dY() > 0 )
	                        set_seq(1);
	                }
	            }
	            else //if !process()
	            {
	                if ( get_subseq() == 2 && get_frame() == 2 && !get_frame_time())
	                {
	                    if ( enemy->x < x )
	                        dir = -1;
	                    if ( enemy->x > x )
	                        dir = 1;
	                }
	                if ( !get_subseq() && get_frame() == 5 && !get_frame_time())
	                {
	                    v_inerc = 4.8;
	                    h_inerc = -15.0;
	                    v_force = 0.4;
	                }
	            }
	        }
	        break;
	    case 199://neutral tech
	    	sub10func();
	    	if (!get_frame_time() && get_frame() == 5)
	    		addbullet(this,NULL,990, x, y, dir, 1, 0, 0);
	        if ( process() )
	        {

	            if ( controlling_type == 2 )
	            {
	                set_seq(700);
	                field_51C = 3;
	                field_520 = 3;
	            }
	            else
	            {
	                set_seq(0);
	                if ( dY() > 0)
	                    set_seq(1);
	            }
	        }
	        else if ( !get_subseq() && !get_frame_time()  && get_frame() == 17)
	        {
	            if (enemy->x < x)
	                dir = -1;
	            else
	                dir = 1;
	        }
	        break;
	    case 200: // ground dash fwd (NOT WORKING!! TODO)
	        sub10func();
	        field_49A = 1;

	        if ( h_inerc > 10.0 )
	        {
	            h_inerc -= 0.5;
	            if ( h_inerc < 10.0 )
	                h_inerc = 10.0;
	        }

	        process();

	        if ( get_subseq() == 0 && get_frame() == 3 && get_frame_time() == 0 )
	        {
	            char_h_move( 18.5);
	            scene_add_effect(this, 125, 80*dir+x, y+80, dir,1);
	            scene_add_effect(this, 126, x, y+80, dir,1);
	            scene_play_sfx(31);
	        }
	        else if (get_subseq() == 1)
	        {
	            if ( (get_elaps_frames() % 5) == 0 )
	            {
	                float yy = (scene_rand() % 200) + y;
	                float xx = x - (scene_rand() % 100) + 50;
	                scene_add_effect(this, 124,xx,yy,dir,1);
	            }
	            if ( dY() >= 0)
	            {
	                field_7D0++;
	                if ( ! ((dX(dir) > 0 || field_7D0 <= 5 ) && field_7D0 <=45) )
	                    set_seq(204);
	            }
	            else
	            {
	                if (dX(dir) <= 0)
	                    set_seq(211);
	                else
	                    set_seq(212);
	            }
	        }
	        break;
	    case 201: // ground dash back (NOT WORKING!! TODO)

	        if ( !get_subseq() || get_subseq() == 3 )
	            sub10func();

	        if ( get_subseq() == 3 )
	        {
	            h_inerc += 2.0;
	            if ( h_inerc > 0 )
	                h_inerc = 0;
	        }
	        if ( !char_on_ground_flag() && !get_elaps_frames() % 5 )
	        {
	            if ( (get_elaps_frames() % 5) == 0)
	            {
	                float yy = (scene_rand() % 200) + y;
	                float xx = x - (scene_rand() % 100) + 50;
	                scene_add_effect(this, 124,xx,yy,-dir,1);
	            }
	        }
	        if ( get_subseq() < 3 )
	        {
	            v_inerc -= v_force;
	            if ( char_on_ground_down() )
	            {
	                v_inerc = 0.0;
	                v_force = 0.0;
	                y = getlvl_height();
	                set_subseq(3);
	                break;
	            }
	        }
	        if ( process() )
	        {
	            set_seq(0);
	            reset_forces();
	        }
	        else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_7D0 )
	        {
	        	field_7D0 = 1;
	            char_h_move( -17.0);
	            v_inerc = 3.5;
	            v_force = 0.75;
	            scene_add_effect(this, 125, x, y+80, -dir,1);
	            scene_add_effect(this, 126, x, y+80, -dir,1);
	            scene_play_sfx(31);
	        }
	        break;
	    case 202: // airdashing forward
	        v_inerc -= v_force;
	        if ( char_on_ground_down() )
	        {
	            reset_forces();
	            y = getlvl_height();
	            set_seq(10);
	        }
            if ( (get_subseq() == 1) && !(get_elaps_frames() % 5) )
            {
                float yy = (scene_rand() % 200) + y;
                float xx = x - (scene_rand() % 100) + 50;
                scene_add_effect(this, 124,xx,yy,dir,1);
            }

            process();

            if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
            {
                field_7D0 = 0;
                char_h_move( 12.0);
                v_inerc = 4.0;
                v_force = 0.4;
                scene_add_effect(this, 125, x+80*dir, y+110, dir,1);
                scene_add_effect(this, 126, x, y+110, dir,1);
                scene_play_sfx(31);
            }
            //counterhit state (dashing)
            else if (!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                flip_with_force();
        
	        break;
	    case 203:// airdashing backward
	    	v_inerc -= v_force;
	        if ( char_on_ground_down() )
	        {
	            reset_forces();
	            y = getlvl_height();
	            set_seq(10);
	        }
	        else
	        {
	            if ( (get_subseq() == 1) && (!get_elaps_frames() % 5) )
	            {
	                float yy = (scene_rand() % 200) + y;
	                float xx = x - (scene_rand() % 100) + 50;
	                scene_add_effect(this, 124,xx,yy,-dir,1);
	            }

	            process();

	            if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
	            {
	                char_h_move( -12.0);
	                v_inerc = 4.0;
	                v_force = 0.4;
	                scene_add_effect(this, 125, x, y+120, -dir,1);
	                scene_add_effect(this, 126, x, y+120, -dir,1);
	                scene_play_sfx(31);
	            }
	            else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2)
	                flip_with_force();
	        }
	        break;
	    case 204: //?
	    	sub10func();
	        h_inerc -= 1.5;
	        if ( h_inerc < 0.0 )
	        {
	            h_inerc = 0.0;
	            field_49A = 0;
	        }
	        if ( process() )
	        {
	            set_seq(0);
	            field_49A = 0;
	        }
	        break;
	    //redoing the commented code below
	  /* 	case 208:
	   		if ( !get_subseq() )
	   			sub10func();
	   		if ( char_on_ground_down())
	   		{
	   			set_seq(10);
	   			y = getlvl_height();
	   			reset_forces();
	   			return; //break?
	   		}
	   		if ()*/


	    //hi jumps?
	    case 208:
	    case 209:
	    case 210:
	    case 211:
	    case 212:
	    case 220:
	    case 221:
	    case 222:
	        if ( get_subseq() == 0 )
	            sub10func();

	        if ( char_on_ground_down() )
	        {
	            set_seq(10);
	            y = getlvl_height();
	            reset_forces();
	        }
	        else
	        {
	            if ( char_on_ground_flag() || v_inerc > 0.0 )
	                field_522 = 2;
	            if ( get_subseq() > 0 )
	            {
	                v_inerc -= v_force;
	                if ( v_inerc < -20.0 )
	                    v_inerc = -20.0;
	            }

                if ( get_subseq() == 1 && v_inerc < 4.0 )
	                set_subseq(2);

	            process();

	            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
	            {	
	            	//edited by myself. changed if statement to switch case
	            	switch(sq) 
	            	{
	            		case 208://neutral
	            		case 220:
	            			char_h_move(0);
	            			v_inerc = 22.5;
	            			v_force = 0.85;
	            			break;
	            		case 209://forward
	            		case 221:
	            			char_h_move(10.0);
	            			v_inerc = 18.0;
	            			v_force = 0.85;
	            			break;
	            		case 210://backward
	            		case 222:
	            			char_h_move(-10.0);
	            			v_inerc = 18.0;
	            			v_force = 0.85;
	            			break;
	            		case 211://forward(?)
	            			char_h_move(3.0);
	            			v_inerc = 22.5;
	            			v_force = 0.85;
	            			break;
	            		case 212://?
	            			char_h_move(10.0);
	            			v_inerc = 16.0;
	            			v_force = 0.7;
	            			break;
	            	}
	                field_49A = 0;
	                scene_add_effect(this, 63, x, y, dir,1);
	            }
	        }
	        break; 
	    case 214: //UNEDITED!!
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
	                        angZ = 180.0 - dash_angle;
	                    //    angZ = 180 -angZ;

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
	    case 215:
	    	sub10func();
	    	if ( h_inerc > 0.0)
	    	{
	    		h_inerc -= 0.75;
	    		if (h_inerc < 0.0)
	    			h_inerc = 0.0;
	    	}

	    	if (h_inerc < 0.0)
	    	{
	    		h_inerc += 0.75;
	    		if (h_inerc > 0.0)
	    			h_inerc = 0.0;
	    	}
	    	if (process())
	    		set_seq(0);
	    	break;
	   	case 217: //?
	   		if ( process() )
	   			set_seq(9);
	   		if (!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
	   			scene_play_sfx(31);
	   		if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
	   			set_seq(9);
	   		if ( get_subseq() == 5 || get_subseq() == 6)
	   			v_inerc -= v_force;
	   		if ( get_subseq() <= 0)
	   			if (char_on_ground_down() )
	   			{
	   				y = getlvl_height();
	   				v_force = 0.0;
	   				v_inerc = 0.0;
	   				if (get_subseq() < 5)
	   				{
	   					set_seq(215);
	   				} else {
	   					set_seq(10);
	   					reset_forces();
	   				}
	   			}
	   		if ( get_subseq() >= 5)
	   			if (char_on_ground_down() )
	   			{
	   				y = getlvl_height();
	   				v_force = 0.0;
	   				v_inerc = 0.0;
	   				if (get_subseq() < 5)
	   				{
	   					set_seq(215);
	   				} else {
	   					set_seq(10);
	   					reset_forces();
	   				}
	   			}
	   		++field_7D6;
	   		field_7D4 = field_7D2 - dash_angle;
	   		if ( field_7D4 > 180)
	   			field_7D4 -= 360;
	   		if ( field_7D4 < -180)
	   			field_7D4 += 360;

	   		if (field_7D4 > 0)
	   		{
	   			if ( weather_id != WEATHER_SUNNY )
	   				dash_angle += 0.5;
	   			else
	   				dash_angle += 1.0;
	   		}
	   	 	if (field_7D4 < 0)
	   	 	{
	   	 		if ( weather_id != WEATHER_SUNNY )
	   	 			dash_angle -= 0.5;
	   	 		else
	   	 			dash_angle -= 1.0;
	   	 	}
	   	 	//left off here
	   	 	//REST IS UNEDITED (from alice.cpp)

 	        h_inerc = cos_deg(dash_angle) * field_7DC;
	        v_inerc = sin_deg(dash_angle) * field_7DC;

	        if ( y > 680.0 )
	            if ( v_inerc > 0.0 )
	                v_inerc = 0.0;

	        field_7DC += 0.3;
	        if ( field_7DC > 12.0 )
	            field_7DC = 12.0;

	        if (weather_id == WEATHER_SUNNY)
	            spell_energy_spend(10, 1);
	        else
	            spell_energy_spend(15, 60);

	        angZ = -dash_angle;

	        if ( h_inerc < 0.0 )
	        {
	            if ( get_subseq() == 1 )
	                set_subseq(3);
	            else if ( get_subseq() == 2 )
	                set_subseq(4);
	        }

	        if ( h_inerc >= 0 )
	        {
	            if ( get_subseq() == 3 )
	                set_subseq(1);
	            else if ( get_subseq() == 4 )
	                set_subseq(2);
	        }

	        if ( get_elaps_frames() % 5 == 1 )
	        {
	            float yy = sin_deg(dash_angle) * 100.0 + y + 100.0;
	            float xx = cos_deg(dash_angle) * 100.0 * dir + x;
	            scene_add_effect(this, 125, xx, yy, dir, 1);
	        }

	        if ( (keyDown(INP_D) == 0 && field_7D6 > 10) || spell_energy <= 0 )
	        {
	            reset_ofs();

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
	        }
	        break;

	    case 223: //?
	        sub10func();
	        field_49A = 1;
	        process();
	        if ( get_subseq() == 1 )
	        {
	            if ( get_elaps_frames() % 5 == 0 )
	            {
	                float yy = (scene_rand() % 200) + y;
	                float xx = x + 50.0 - (scene_rand() % 100);
	                scene_add_effect(this, 124, xx, yy, dir, 1);
	            }
	            field_7D0++;
	            if ( (dX(dir) <= 0 && field_7D0 >= 13) || field_7D0 > 45 )
	                set_seq( 204);
	        }
	        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
	        {
	            char_h_move( 7.0);
	            scene_add_effect(this, 125, (80 * dir) + x, y + 80.0, dir, 1);
	            scene_add_effect(this, 126, x, y + 80.0, dir, 1);
	            scene_play_sfx(31);
	        }
	        break;
	    case 224:
	        if ( !get_subseq() || get_subseq() == 3 )
	            sub10func();

	        if ( get_subseq() == 3 )
	        {
	            h_inerc += 2.0;
	            if (h_inerc > 0.0)
	                h_inerc = 0.0;
	        }
	        if (!char_on_ground_flag() && get_elaps_frames() % 5 == 0)
	            scene_add_effect(this, 124, x + 50.0 - scene_rand_rngf(100), y + scene_rand_rngf(200), dir, 1);

	        if ( get_subseq() < 3 && char_on_ground_down() )
	        {
	            v_inerc -= v_force;
	            if ( char_on_ground_down() )
	            {
	                v_inerc = 0.0;
	                v_force = 0.0;
	                y = getlvl_height();
	                set_subseq(3);
	                break;
	            }
	        }
	        if ( process() )
	        {
	            set_seq(0);
	            h_inerc = 0.0;
	            v_force = 0.0;
	        }
	        else
	        {
	            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_7D0 )
                {
                    field_7D0 = 1;
                    char_h_move(-14.0);
                    v_inerc = 4.0;
                    v_force = 0.75;

                    scene_add_effect(this, 125, x, y + 80.0, dir, 1);
                    scene_add_effect(this, 126, x, y + 80.0, dir, 1);
                    scene_play_sfx(31);
                }
	        }
	        break;
	    case 225:
	        v_inerc -= v_force;
	        if ( char_on_ground_down() )
	        {
	            reset_forces();
	            y = getlvl_height();
	            set_seq(10);
	        }
	        else
	        {
	            if (get_subseq() >= 2 && get_elaps_frames() % 5 == 0)
	                scene_add_effect(this, 124, x + 50.0 - scene_rand_rngf(100), y + scene_rand_rngf(200), dir, 1);

	            if ( process() )
	                set_seq(9);

	            if (get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1)
	            {
	                char_h_move(-12.0);
	                v_inerc = 4.0;
	                v_force = 0.4;
	                scene_add_effect(this, 125, x, y + 120.0, dir, 1);
	                scene_add_effect(this, 126, x, y + 120.0, dir, 1);
	                scene_play_sfx(31);
	            }
	        }
	    case 226:
	        v_inerc -= v_force;
	        if ( char_on_ground_down() )
	        {
	            reset_forces();
	            y = getlvl_height();
	            set_seq(10);
	        }
	        else
	        {
	            if ( get_subseq() == 1 && get_elaps_frames() % 5 == 0)
	                scene_add_effect(this, 124, x + 50.0 - scene_rand_rngf(100), y + scene_rand_rngf(200), dir, 1);

	            if ( process() )
	                set_seq(9);

	            if (get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0)
	            {
	                if (get_subseq() == 1)
	                {
	                    field_7D0 = 0;
	                    char_h_move(12.0);
	                    v_inerc = 4.0;
	                    v_force = 0.4;

	                    scene_add_effect(this, 125, x + 80.0 * dir, y + 110.0, dir, 1);
	                    scene_add_effect(this, 126, x, y + 110.0, dir, 1);
	                    scene_play_sfx(31);
	                }
	                else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2)
	                    flip_with_force();
	            }
	        }
	        break;
        //end of movement-stuff

	    //beginning of attacks?
	    case 300: //??
	    case 330: //??
	    //taken from alice
            sub10func();
	        //if ( !get_true(0) ) //CHECKME
	        {
	            if ( field_49A )
	            {
	                h_inerc -= 0.5;
	                if ( h_inerc < 0.0 )
	                {
	                    h_inerc = 0.0;
	                    field_49A = 0;
	                }
	            }
	            if ( process() )
	                set_seq( 0);
	            if ( get_frame_time() == 0 && get_frame() == 2 )
	            {
	                scene_play_sfx(27);
	                field_49A = 0;
	            }
	        }
	        break;
	    case 301:
	    	sub10func();
	    	//if ( get_true(0))
	    	if ( field_49A)
	    	{
	    		h_inerc -= 0.5;
	    		if (h_inerc < 0.0)
	    		{
	    			h_inerc = 0.0;
	    			field_49A = 0;
	    		}
	    	}
	    	if(process())
	    		set_seq(0);
	    	if(get_frame_time())
	    		stopping_posit(0.5);

	    	break;
	    case 302:
	    	sub10func();
	    	/*if ( get_true(1))
	    		return;*/
	    	if ( get_frame() < 4 && !keyDown(INP_A))
	    		not_charge_attack = 0;
	    	if ( !get_subseq() ) 
	    	{
	    		if (h_inerc > 0.0)
	    			h_inerc -= 1.5;
	    		if ( h_inerc < 0.0)
	    			h_inerc = 0.0;
	    		if (!get_frame_time() && get_frame() == 4)
	    			h_inerc = 15.5;
	    	}
	    	if ( get_subseq() == 1)
	    	{
	    		if ( h_inerc <= 0.0)
	    			h_inerc -= 1.5;
	    		if ( h_inerc < 0.0)
	    			h_inerc = 0.0;
	    		if( !get_frame_time() && get_frame() == 1)
	    			h_inerc = 17.5;
	    	}

	    	if (process())
	    		set_seq(0);

	    	if (!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
	    		set_seq(0);

	    	if ( get_subseq() || get_frame_time() )
	    	{
	    		if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3)
	    			scene_play_sfx(29);
	    	}
	    	if (get_frame() == 4 && not_charge_attack == 1)
	    	{
	    		scene_add_effect(this, 62, (double)(7 * dir) + x, y + 180.0, dir, 1);
	    	}

	    	if (get_frame() == 6)
	    		scene_play_sfx(29);

	    	if (get_subseq() == 1 && !get_frame_time() && get_frame() == 3)
	    		scene_play_sfx(29);
	    	break;
		default:
			char_c::func10();
			break;
	}


}


//contains attacks?
void char_aya::func20()
{

//main: switch statement
	uint16_t cprior = get_cprior();			   //v133
	uint32_t fflags = get_pframe()->fflags;	   //v134

	bool cc = (fflags & FF_CANCELLEABLE) != 0; //v2
	bool cu = (fflags & FF_HJC) != 0;		   //v3
	int32_t sq = get_seq();

	if ( !check_AB_pressed() )
	{
		if ( cc || cu )
		{
			            /*
             if ( pres_comb >= 700 && pres_comb < 800 )
             {
               //v1->class->func2_set_seq(v1, LOWORD(v1->pressed_combination));
               return;
             }
             else*/
			if ( (char_on_ground_down()) && field_4C4 == 0)
			{
				if ( cu && cprior >= 10 && hi_jump_after_move()
				 		|| border_escape_ground()
				 		|| hi_jump(cprior, cu) 
				 		|| fw_bk_dash_ground(cprior,cu) )
					return;
			} 
			else 
			{
				int8_t mx = (weather_id == WEATHER_TEMPEST) + 2;
				if (border_escape_air()
					    ||fwd_dash_air(cprior,cu, mx, 2)
						|| bkg_dash_air(cprior,cu, mx, 2) 
						|| flying_air(cprior,cu, mx) )
					return;
			}
		}
		if ( field_84C && cc)
		{
			if (field_524)
			{
                if (((keyDown(INP_BC) && keyDown(INP_BC) < 3) || keyHit(INP_BC)) && sub_468660(0) && field_836 == 0)
                {
                    if (char_on_ground_flag())
                    {
                        if ( !sub_489F10(cprior) && seq299_300_field190_0_3()) //HACK
                        {
                            int32_t crd_id = cards_active[0]->id;

                            if (cprior <= 50 && crd_id >= 100 && crd_id <= 199)
                            {
                                switch(crd_id)
                                {
                                case 100:
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(500, cprior);
                                    return;
                                case 101:
                                    if ( field_801 == 0 )
                                    {
                                        field_4C8++;
                                        field_801 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(520, cprior);
                                    return;
                                case 102:
                                    if ( field_802 == 0 )
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(540, cprior);
                                    return;
                                case 103:
                                    if ( field_803 == 0 )
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(560, cprior);
                                    return;
                                case 104:
                                    if ( field_800 == 0 )
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(505, cprior);
                                    return;
                                case 105:
                                    if ( field_801 == 0 )
                                    {
                                        field_4C8++;
                                        field_801 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(525, cprior);
                                    return;
                                case 106:
                                    if ( field_802 == 0 )
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(545, cprior);
                                    return;
                                case 107:
                                    if ( field_803 == 0 )
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(565, cprior);
                                    return;
                                case 108:
                                    if ( field_800 == 0 )
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(510, cprior);
                                    return;
                                case 109:
                                    if ( field_801 == 0 )
                                    {
                                        field_4C8++;
                                        field_801 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(530, cprior);
                                    return;
                                case 110:
                                    if ( field_802 == 0 )
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(550, cprior);
                                    return;
                                case 111:
                                    if ( field_803 == 0 )
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(570, cprior);
                                    return;
                                default:
                                    break;
                                }
                            }
                            else if (cprior <= 100 && crd_id >= 200 && crd_id <= 299 && keyDown(INP_X_AXIS) == 0)
                            {
                                switch(crd_id)
                                {
                                case 200:
                                    sub_487370(600, cprior);
                                    return;
                                case 201:
                                    sub_487370(601, cprior);
                                    return;
                                case 202:
                                    sub_487370(602, cprior);
                                    return;
                                case 203:
                                    sub_487370(603, cprior);
                                    return;
                                case 204:
                                    sub_487370(604, cprior);
                                    return;
                                case 205:
                                    sub_487370(605, cprior);
                                    return;
                                case 206:
                                    sub_487370(606, cprior);
                                    return;
                                case 207:
                                    sub_487370(607, cprior);
                                    return;
                                case 208:
                                    sub_487370(608, cprior);
                                    return;
                                case 209:
                                    sub_487370(609, cprior);
                                    return;
                                case 210:
                                    sub_487370(610, cprior);
                                    return;
                                case 211:
                                    sub_487370(611, cprior);
                                    return;
                                case 212:
                                    sub_487370(612, cprior);
                                    return;
                                case 213:
                                    sub_487370(613, cprior);
                                    return;
                                case 214:
                                    sub_487370(614, cprior);
                                    return;
                                case 215:
                                    if ( field_8A8 == 0 )
                                    {
                                        sub_487370(615, cprior);
                                        return;
                                    }
                                    break;
                                case 216:
                                    sub_487370(616, cprior);
                                    return;
                                case 217:
                                    sub_487370(617, cprior);
                                    return;
                                case 218:
                                    sub_487370(618, cprior);
                                    return;
                                case 219:
                                    sub_487370(619, cprior);
                                    return;
                                default:
                                    break;
                                }
                        	}
                        }
                    }
                    else
                    {
                        if (seq299_300_field190_0_3()) //HACK
                        {
                            int32_t crd_id = cards_active[0]->id;

                            if (cprior <= 50 && crd_id >= 100 && crd_id <= 199)
                            {
                                switch(crd_id)
                                {
                                case 100:
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(500, cprior);
                                    return;
                                case 102:
                                    if ( field_802 == 0 )
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(542, cprior);
                                    return;
                                case 103:
                                    if ( field_803 == 0 )
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(562, cprior);
                                    return;
                                case 104:
                                    if ( field_800 == 0 )
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(505, cprior);
                                    return;
                                case 106:
                                    if ( field_802 == 0 )
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(547, cprior);
                                    return;
                                case 107:
                                    if ( field_803 == 0 )
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(567, cprior);
                                    return;
                                case 108:
                                    if ( field_800 == 0 )
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(512, cprior);
                                    return;
                                case 110:
                                    if ( field_802 == 0 )
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(552, cprior);
                                    return;
                                case 111:
                                    if ( field_803 == 0 )
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(572, cprior);
                                    return;
                                default:
                                    break;
                                }
                            }
                            else if (cprior <= 100 && crd_id >= 200 && crd_id <= 299 && keyDown(INP_X_AXIS) == 0)
                            {
                                switch(crd_id)
                                {
                                case 203:
                                    sub_487370(603, cprior);
                                    return;
                                case 205:
                                    sub_487370(605, cprior);
                                    return;
                                case 207:
                                    sub_487370(607, cprior);
                                    return;
                                case 208:
                                    sub_487370(658, cprior);
                                    return;
                                case 211:
                                    sub_487370(611, cprior);
                                    return;
                                default:
                                    break;
                                }
                            }
                        }
                    }
                }
                if (pres_comb && spell200_seq299_300_field190_0_3() )
                {
                    if (char_on_ground_flag())
                    {
                        if ( pres_comb & PCOMB_623C )
                        {
                            if ( skills_1[9] >= 1 )
                            {
                                if ( cprior <= get_prior(531) || (sq >= 500 && sq <= 599 && field_801 == 0))
                                {
                                    if ( field_801 == 0 )
                                    {
                                        field_4C8++;
                                        field_801 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 531, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[5] >= 1 )
                            {
                                if ( cprior <= get_prior(526) || (sq >= 500 && sq <= 599 && field_801 == 0))
                                {
                                    if ( field_801 == 0)
                                    {
                                        field_4C8++;
                                        field_801 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 526, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(521) || (sq >= 500 && sq <= 599 && field_801 == 0))
                            {
                                if ( field_801 == 0)
                                {
                                    field_4C8++;
                                    field_801 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 521, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_623B )
                        {
                            if ( skills_1[9] >= 1 )
                            {
                                if ( cprior <= get_prior(530) || (sq >= 500 && sq <= 599 && field_801 == 0))
                                {
                                    if ( field_801 == 0)
                                    {
                                        field_4C8++;
                                        field_801 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 530, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[5] >= 1 )
                            {
                                if ( cprior <= get_prior(525) || (sq >= 500 && sq <= 599 && field_801 == 0))
                                {
                                    if ( field_801 == 0)
                                    {
                                        field_4C8++;
                                        field_801 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 525, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(520) || (sq >= 500 && sq <= 599 && field_801 == 0))
                            {
                                if ( field_801 == 0)
                                {
                                    field_4C8++;
                                    field_801 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 520, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_236C )
                        {
                            if ( skills_1[11] >= 1 )
                            {
                                if ( cprior <= get_prior(571) || (sq >= 500 && sq <= 599 && field_803 == 0))
                                {
                                    if ( field_803 == 0)
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 571, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[7] >= 1 )
                            {
                                if ( cprior <= get_prior(566) || (sq >= 500 && sq <= 599 && field_803 == 0))
                                {
                                    if ( field_803 == 0)
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 566, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(561) || (sq >= 500 && sq <= 599 && field_803 == 0))
                            {
                                if ( field_803 == 0)
                                {
                                    field_4C8++;
                                    field_803 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 561, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_236B )
                        {
                            if ( skills_1[11] >= 1 )
                            {
                                if ( cprior <= get_prior(570) || (sq >= 500 && sq <= 599 && field_803 == 0))
                                {
                                    if ( field_803 == 0)
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 570, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[7] >= 1 )
                            {
                                if ( cprior <= get_prior(565) || (sq >= 500 && sq <= 599 && field_803 == 0))
                                {
                                    if ( field_803 == 0)
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 565, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(560) || (sq >= 500 && sq <= 599 && field_803 == 0))
                            {
                                if ( field_803 == 0)
                                {
                                    field_4C8++;
                                    field_803 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 560, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_214C )
                        {
                            if ( skills_1[8] >= 1 )
                            {
                                if ( cprior <= get_prior(511) || (sq >= 500 && sq <= 599 && field_800 == 0))
                                {
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 511, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[4] >= 1 )
                            {
                                if ( cprior <= get_prior(506) || (sq >= 500 && sq <= 599 && field_800 == 0))
                                {
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 506, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(500) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                                if ( field_800 == 0)
                                {
                                    field_4C8++;
                                    field_800 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 500, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_214B )
                        {
                            if ( skills_1[8] >= 1 )
                            {
                                if ( cprior <= get_prior(510) || (sq >= 500 && sq <= 599 && field_800 == 0))
                                {
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 510, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[4] >= 1 )
                            {
                                if ( cprior <= get_prior(505) || (sq >= 500 && sq <= 599 && field_800 == 0))
                                {
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 505, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(500) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                                if ( field_800 == 0)
                                {
                                    field_4C8++;
                                    field_800 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 500, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_2N2C )
                        {
                            if ( skills_1[10] >= 1 )
                            {
                                if ( cprior <= get_prior(551) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                    if ( field_802 == 0)
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 551, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[6] >= 1 )
                            {
                                if ( cprior <= get_prior(546) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                    if ( field_802 == 0)
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 546, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(541) || (sq >= 500 && sq <= 599 && field_802 == 0))
                            {
                                if ( field_802 == 0)
                                {
                                    field_4C8++;
                                    field_802 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 541, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_2N2B )
                        {
                            if ( skills_1[10] >= 1 )
                            {
                                if ( cprior <= get_prior(550) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                    if ( field_802 == 0)
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 550, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[6] >= 1 )
                            {
                                if ( cprior <= get_prior(545) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                    if ( field_802 == 0)
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 545, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(540) || (sq >= 500 && sq <= 599 && field_802 == 0))
                            {
                                if ( field_802 == 0)
                                {
                                    field_4C8++;
                                    field_802 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 540, cprior);
                                return;
                            }
                        }
                    }
                    else // Air specials
                    {
                        if ( pres_comb & PCOMB_236C )
                        {
                            if ( skills_1[11] >= 1 )
                            {
                                if ( cprior <= get_prior(573) || (sq >= 500 && sq <= 599 && field_803 == 0))
                                {
                                    if ( field_803 == 0)
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 573, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[7] >= 1 )
                            {
                                if ( cprior <= get_prior(568) || (sq >= 500 && sq <= 599 && field_803 == 0))
                                {
                                    if ( field_803 == 0)
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 568, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(563) || (sq >= 500 && sq <= 599 && field_803 == 0))
                            {
                                if ( field_803 == 0)
                                {
                                    field_4C8++;
                                    field_803 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 563, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_236B )
                        {
                            if ( skills_1[11] >= 1 )
                            {
                                if ( cprior <= get_prior(572) || (sq >= 500 && sq <= 599 && field_803 == 0))
                                {
                                    if ( field_803 == 0)
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 572, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[7] >= 1 )
                            {
                                if ( cprior <= get_prior(567) || (sq >= 500 && sq <= 599 && field_803 == 0))
                                {
                                    if ( field_803 == 0)
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 567, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(562) || (sq >= 500 && sq <= 599 && field_803 == 0))
                            {
                                if ( field_803 == 0)
                                {
                                    field_4C8++;
                                    field_803 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 562, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_214C )
                        {
                            if ( skills_1[8] >= 1 )
                            {
                                if ( cprior <= get_prior(513) || (sq >= 500 && sq <= 599 && field_800 == 0))
                                {
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 513, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[4] >= 1 )
                            {
                                if ( cprior <= get_prior(506) || (sq >= 500 && sq <= 599 && field_800 == 0))
                                {
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 506, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(500) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                                if ( field_800 == 0)
                                {
                                    field_4C8++;
                                    field_800 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 500, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_214B )
                        {
                            if ( skills_1[8] >= 1 )
                            {
                                if ( cprior <= get_prior(512) || (sq >= 500 && sq <= 599 && field_800 == 0))
                                {
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 512, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[4] >= 1 )
                            {
                                if ( cprior <= get_prior(505) || (sq >= 500 && sq <= 599 && field_800 == 0))
                                {
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 505, cprior);
                                    return;
                                }
                            }
                            if ( cprior <= get_prior(500) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                                if ( field_800 == 0)
                                {
                                    field_4C8++;
                                    field_800 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 500, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_2N2C )
                        {
                            if ( skills_1[10] >= 2 )
                            {
                                if ( cprior <= get_prior(553) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                    if ( field_802 == 0)
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 553, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[6] >= 2 )
                            {
                                if ( cprior <= get_prior(548) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                    if ( field_802 == 0)
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 548, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[10] == 0 && skills_1[6] == 0)
                            {
                                if ( cprior <= get_prior(543) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                    if ( field_802 == 0)
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 543, cprior);
                                    return;
                                }
                            }
                        }
                        if ( pres_comb & PCOMB_2N2B )
                        {
                            if ( skills_1[10] >= 2 )
                            {
                                if ( cprior <= get_prior(552) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                    if ( field_802 == 0)
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 552, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[6] >= 2 )
                            {
                                if ( cprior <= get_prior(547) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                    if ( field_802 == 0)
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 547, cprior);
                                    return;
                                }
                            }
                            if ( skills_1[10] == 0 && skills_1[6] == 0)
                            {
                                if ( cprior <= get_prior(542) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                    if ( field_802 == 0)
                                    {
                                        field_4C8++;
                                        field_802 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 542, cprior);
                                    return;
                                }
                            }
                        }
                    }
                }
            }

            if ((keyUp(INP_A) && keyUp(INP_A) < 3) || keyDown(INP_A) == 2 || keyHit(INP_A))
            {
                if (char_on_ground_flag()) // On Ground
                {
                    if ( sq == 200 && dY() == 0 &&
                            dX(dir) > 0 &&
                            cprior <= get_prior(305) )  // 66A
                    {
                        angZ = 0;
                        set_seq(305);
                        input->zero_keyhit();
                        return;
                    }

                    if ( (sq > 299 && field_190 != 0 && field_190 != 3) || sq < 300 )
                    {
                        if ( dY() > 0 )
                        {
                            if ( ( dX(dir) > 0 || hX(dir) > 0 ) && cprior <= get_prior(304) ) // 3A
                            {
                                angZ = 0;
                                set_seq(304);
                                input->zero_keyhit();
                                return;
                            }
                            else if (cprior <= get_prior(303) ) // 2A
                            {
                                angZ = 0;
                                set_seq(303);
                                input->zero_keyhit();
                                return;
                            }
                        }
                        else if ( dY() >= 0 )
                        {
                            if ( dX(dir) < 0 || hX(dir) < 0 ) // 4a
                                if ( cprior <= get_prior(330) || sq == 330 )
                                {
                                    angZ = 0;
                                    set_seq(330);
                                    input->zero_keyhit();
                                    return;
                                }
                        }

                        if (dY() == 0)
                        {
                            if ( (dX(dir) > 0 || hX(dir) > 0) && cprior <= get_prior(302) ) // 6A
                            {
                                angZ = 0;
                                set_seq(302);
                                input->zero_keyhit();
                                return;
                            }

                            float dst = fabs(x - enemy->x);

                            if ( dst > 90.0 && cprior <= get_prior(301)) //Far A
                            {
                                angZ = 0;
                                set_seq(301);
                                input->zero_keyhit();
                                return;
                            }

                            if(cprior <= get_prior(300)) //near A
                            {
                                angZ = 0;
                                set_seq(300);
                                input->zero_keyhit();
                                return;
                            }
                        }
                    }
                    if ( field_190 != 0 && field_190 != 3 )
                    {
                        if ( sq == 321 ) // AAAA
                        {
                            angZ = 0;
                            set_seq(322);
                            input->zero_keyhit();
                            return;
                        }
                        else if ( sq == 320 ) // AAA
                        {
                            angZ = 0;
                            set_seq(321);
                            input->zero_keyhit();
                            return;
                        }
                        else if ( sq == 300 ) // AA
                        {
                            angZ = 0;
                            set_seq(320);
                            input->zero_keyhit();
                            return;
                        }
                    }
                }
                else if ((sq > 299 && field_190 != 0 && field_190 != 3) || sq < 300 ) // In Air (Melee)
                {

                    if ( (dY() < 0 || hY() < 0 ) && dX(dir) == 0 && cprior <= get_prior(309) ) //j8A
                    {
                        angZ = 0;
                        set_seq(309);
                        input->zero_keyhit();
                        return;
                    }
                    else if ((dY() > 0 || hY() > 0) /*&& gX(dir) >= 0*/ && cprior <= get_prior(308)) //j2A
                    {
                        angZ = 0;
                        set_seq(308);
                        input->zero_keyhit();
                        return;
                    }
                    else if ( dY() == 0 && (dX(dir) > 0 || hX(dir) > 0 ) && cprior <= get_prior(307)) //j6A
                    {
                        angZ = 0;
                        set_seq(307);
                        input->zero_keyhit();
                        return;
                    }
                    else if ( cprior <= get_prior(306) ) //j5A
                    {
                        angZ = 0;
                        set_seq(306);
                        input->zero_keyhit();
                        return;
                    }
                }
            }

            if ((keyUp(INP_B) && keyUp(INP_B) < 3) || keyDown(INP_B) == 2 || keyHit(INP_B))
            {
                if (char_on_ground_flag()) // On Ground
                {
                    if ( sq == 200 && dY() == 0 && (dX(dir) > 0 || hX(dir) > 0) )  // 66B
                    {
                        angZ = 0;
                        set_seq(408);
                        input->zero_keyhit();
                        return;
                    }

                    if ( ((sq > 299 && field_190 != 0 && field_190 != 3) || sq < 300 ) && spell_energy >= 200)
                    {
                        if ( (dY() > 0 || hY() > 0)/*&& gX(dir) > 0*/ && cprior <= get_prior(402) ) // 2B //HACK?
                        {
                            if ( field_892 > 0 && field_890 != 50 )
                            {
                                angZ = 0.0;
                                set_seq(421);
                                input->zero_keyhit();
                                return;
                            }
                            else
                            {
                                angZ = 0.0;
                                set_seq(402);
                                input->zero_keyhit();
                                return;
                            }
                        }
                        else if ( dY() == 0  && (dX(dir) > 0 || hX(dir) > 0) && cprior <= get_prior(401) )
                        {
                            if ( field_892 > 0 && field_890 != 50 )
                            {
                                angZ = 0.0;
                                set_seq(420);
                                input->zero_keyhit();
                                return;
                            }
                            else
                            {
                                angZ = 0.0;
                                set_seq(401);
                                input->zero_keyhit();
                                return;
                            }

                        }
                        else if (cprior <= get_prior(400) )
                        {
                            if ( field_892 > 0 && field_890 != 50 )
                            {
                                angZ = 0.0;
                                set_seq(420);
                                input->zero_keyhit();
                                return;
                            }
                            else
                            {
                                angZ = 0.0;
                                set_seq(400);
                                input->zero_keyhit();
                                return;
                            }
                        }
                    }
                }
                else if ( ((sq > 299 && field_190 != 0 && field_190 != 3) || sq < 300 ) && spell_energy >= 200 ) //In AIR
                {
                    if ( (dY() <= 0 || hY() <= 0) && cprior <= get_prior(404))
                    {
                        if ( field_892 > 0 && field_890 != 50 )
                        {
                            angZ = 0.0;
                            set_seq(422);
                            input->zero_keyhit();
                            return;
                        }
                        else
                        {
                            angZ = 0.0;
                            set_seq(404);
                            input->zero_keyhit();
                            return;
                        }
                    }
                    else if (cprior <= get_prior(406))
                    {
                        if ( field_892 > 0 && field_890 != 50 )
                        {
                            angZ = 0.0;
                            set_seq(422);
                            input->zero_keyhit();
                            return;
                        }
                        else
                        {
                            angZ = 0.0;
                            set_seq(406);
                            input->zero_keyhit();
                            return;
                        }

                    }
                }
            }
            if ((keyUp(INP_C) && keyUp(INP_C) < 3) || keyDown(INP_C) == 2 || keyHit(INP_C))
            {
                if (char_on_ground_flag()) // On Ground
                {
                    if ( sq == 200 && dY() == 0 && (dX(dir) > 0 || hX(dir) > 0) )  // 66B
                    {
                        angZ = 0;
                        set_seq(418);
                        input->zero_keyhit();
                        return;
                    }
                    if ( ((sq > 299 && field_190 != 0 && field_190 != 3) || sq < 300 ) && spell_energy >= 200)
                    {
                        if ( (dY() > 0 || hY() > 0)/*&& gX(dir) > 0*/ && cprior <= get_prior(412) ) // 2C //HACK?
                        {
                            if ( field_892 > 0 && field_890 != 50 )
                            {
                                angZ = 0.0;
                                set_seq(431);
                                input->zero_keyhit();
                                return;
                            }
                            else
                            {
                                angZ = 0.0;
                                set_seq(412);
                                input->zero_keyhit();
                                return;
                            }
                        }
                        else if ( dY() == 0  && (dX(dir) > 0 || hX(dir) > 0) && cprior <= get_prior(411) ) // 6C
                        {
                            if ( field_892 > 0 && field_890 != 50 )
                            {
                                angZ = 0.0;
                                set_seq(430);
                                input->zero_keyhit();
                                return;
                            }
                            else
                            {
                                angZ = 0.0;
                                set_seq(411);
                                input->zero_keyhit();
                                return;
                            }

                        }
                        else if (cprior <= get_prior(410) )
                        {
                            if ( field_892 > 0 && field_890 != 50 )
                            {
                                angZ = 0.0;
                                set_seq(430);
                                input->zero_keyhit();
                                return;
                            }
                            else
                            {
                                angZ = 0.0;
                                set_seq(410);
                                input->zero_keyhit();
                                return;
                            }
                        }
                    }
                }
                else
                {
                    if ( ((sq > 299 && field_190 != 0 && field_190 != 3) || sq < 300 ) && spell_energy >= 200)
                    {
                        if (dY() <= 0 && (dX(dir) > 0 || hX(dir) > 0) && cprior <= get_prior(415))
                        {
                            if ( field_892 > 0 && field_890 != 50 )
                            {
                                angZ = 0.0;
                                set_seq(432);
                                input->zero_keyhit();
                                return;
                            }
                            else
                            {
                                angZ = 0.0;
                                set_seq(415);
                                input->zero_keyhit();
                                return;
                            }
                        }
                        else if ((dY() > 0 || hY() > 0) && cprior <= get_prior(416))
                        {
                            if ( field_892 > 0 && field_890 != 50 )
                            {
                                angZ = 0.0;
                                set_seq(432);
                                input->zero_keyhit();
                                return;
                            }
                            else
                            {
                                angZ = 0.0;
                                set_seq(416);
                                input->zero_keyhit();
                                return;
                            }
                        }
                        else if (cprior <= get_prior(414))
                        {
                            if ( field_892 > 0 && field_890 != 50 )
                            {
                                angZ = 0.0;
                                set_seq(432);
                                input->zero_keyhit();
                                return;
                            }
                            else
                            {
                                angZ = 0.0;
                                set_seq(414);
                                input->zero_keyhit();
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

}

//also mostly to do with attacks (both func10 and func20)?
void char_aya::set_seq_params()
{

//pre-switch statements
//?

//main: switch statement
	switch(get_seq())
	{
	case 4://move forward 
		h_inerc = 5.5;
		break;
	case 5://move backward
		h_inerc = -5.5;
		break;
	case 214:
	case 217:
		reset_ofs();
		h_inerc = 0.0;
		field_7D6 = 0;
		v_inerc = 0.0;
		v_force = 0.6;
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
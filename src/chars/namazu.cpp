#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "namazu.h"
#include <math.h>

#include <iostream>

//"Constructor" ?
char_namazu::char_namazu(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_NAMAZU;
	pgp->load_dat("namazu",pal);
	char_loadsfx("namazu");
	cards_load_cards(&chr_cards,"namazu");
	load_face("namazu");
	load_spells("namazu");
	stand_gfx->init(this,"namazu");
}

//Initialize some variables
void char_namazu::init_vars()
{
	field_138 = -6.0;
	field_890 = 0;
	field_894 = 0;
	field_898 = 0;
	field_89C = 0;
	char_c::init_vars();
}

//Associated with bullets
c_bullet *char_namazu::new_bullet()
{
    c_bullet *tmp = new namazu_bullets();
    return tmp;
}

//sub_5586E0()
/* void sub_5586E0() {
  v1 = this;
  v2 = *(_DWORD **)(this + 340);
  if ( v2 )
  {
    v3 = *(void **)(this + 340);
    *v2 = &IColor::`vftable';
    j__free(v3);
    *(_DWORD *)(v1 + 340) = 0;
  }
}
 */

//Edited..
void char_namazu::func10() 
{
  /* pre-switch statement */
  int32_t sq = get_seq();

  x_delta = 0;
  y_delta = 90;

  if ( controlling_type == 2)
  {
    field_4AA = 2;
    field_534 = 0.25;
    field_55C = 2.0;
    field_538 = 0.0;
    field_86A = 0;
    if ( cards_added >= 1 )
    {
      switch ( cards_active[0]->id)
      {
        case 0:
        case 1:
        case 2:
        case 3:
          field_4AA = 2;
          field_534 = 0.1;
          field_55C = 5.0;
          field_538 = 0.0;
          field_86A = 1;
          if (get_pframe()->extra1[4] == 1)
          {
            field_86A = 3;
            field_55C = 7.5;
          }
          if (get_pframe()->extra1[4] == 2)
          {
            field_86A = 3;
            field_55C = 15.0;
          }
        break;
        case 4:
        case 5:
        case 6:
        case 7:
          field_4AA = 2;
          field_534 = 0.1;
          field_55C = 5.0;
          field_538 = 0.0;
          field_86A = 1;
          if (get_pframe()->extra1[4] == 1)
          {
            field_86A = 3;
            field_55C = 10.0;
          }
          if (get_pframe()->extra1[4] == 2)
          {
            field_86A = 3;
            field_55C = 20.0;
          }
          break;
        case 8:
        case 9:
        case 10:
        case 11:
          field_4AA = 2;
          field_534 = 0.1;
          field_55C = 2.5;
          field_538 = 0.0;
          if (get_pframe()->extra1[4] == 1)
          {
            field_86A = 3;
            field_55C = 5.0;
          }
          if (get_pframe()->extra1[4] == 2)
          {
            field_86A = 3;
            field_55C = 10.0;
          }
          break;
        case 12:
        case 13:
        case 14:
        case 15:
                  field_4AA = 2;
          field_534 = 0.1;
          field_55C = 2.5;
          field_538 = 0.0;
          if (get_pframe()->extra1[4] == 1)
          {
            field_86A = 3;
            field_55C = 5.0;
          }
          if (get_pframe()->extra1[4] == 2)
          {
            field_86A = 3;
            field_55C = 10.0;
          }
          break;
        case 16:
        case 17:
        case 18:
        case 19:
          field_4AA = 2;
          field_534 = 0.1;
          field_55C = 2.5;
          field_538 = 0.0;
          field_86A = 1;
          if (get_pframe()->extra1[4] == 1)
          {
            field_86A = 3;
            field_534 = 0.2;
          }
          if (get_pframe()->extra1[4] == 2)
          {
            field_86A = 3;
            field_534 = 0.3;
          }
          break;
        default:
          break;

      }
    }
    if ( field_882 == 1 )
            {
                if ( field_188 >= max_health && !field_574 )
                {
                    field_86A = 2;
                    field_882 = 2;
                    flip_with_force();
                    set_seq( 149);
                    scene_add_effect(this, 53, x, y + 100.0, dir, 1);
                    if ( cards_added >= 1 && cards_active[0]->id <= 11 )
                    {
                        field_884 = 300;
                        field_886 = 300;
                    }
                }
                if ( health <= 0 )
                    field_882 = 2;
            }
            if ( field_884 > 0 )
            {
                if ( damage_limit > 0 && damage_limit < 100 )
                    damage_limit = 0;

                if ( field_884 == 1 || health <= 0 )
                {
                    field_4AA = 0;
                    field_884 = 0;
                    field_4BA = 0;
                    field_188 = 0;
                    field_81E = 1;
                    field_81A = 0;
                    field_81C = 0;
                    field_818 = 0;
                    field_882 = 1;
                    if (health <= 0 )
                    {
                        field_86A = 0;
                        float tmp[3];
                        tmp[0] = 0.0;
                        tmp[1] = 0.0;
                        tmp[2] = 0.0;
                        addbullet(this, NULL, 1201, 180.0, 130.0, 1, 2, tmp, 3);
                    }
                }
                else
                {
                    field_86A = 2;
                    field_4AA = 2;
                    field_538 = 1.0;
                    field_534 = 1.0;
                    field_884--;
                    field_4BA = 6000;
                }
            }
            if ( health > 0 )
                field_86A = 0;
        }

  if (get_seq() > 149 && get_seq() < 159)
  {
    if (!bbarrier_show)
    {
      bbarrier_show = 1;
      if ( sq > 149 && sq < 154 )
          addbullet(this, NULL, 998, (57 * dir) + x, y + 94.0, dir, 1, 0, 0);
      if ( sq > 153 && sq < 158 )
          addbullet(this, NULL, 998, (57 * dir) + x, y + 60.0, dir, 1, 0, 0);
      if ( sq == 158 )
          addbullet(this, NULL, 998, (57 * dir) + x, y + 100.0, dir, 1, 0, 0);
    }
  }

  if ( hit_stop != 0|| enemy->time_stop != 0 )
    return;

  //RE COMPILE NAMAZU FUNC10!!
  /* main big-switch statement */
  switch(sq)
  {
    case 0: //idle state?
      sub10func();
      if ( h_inerc == 0.0)
        field_49A = 0;
      if(!field_49A)
      {
        reset_forces();
        process();   
      }
      stopping_posit(0.5);
      break;
    case 1: //?
      sub10func();
      stopping(0.5);
      if(process() && !get_frame())
      {
        set_seq(2);
        return; 
      }
      break;
    case 2: //crouch?
      sub10func();
      stopping_posit(0.5);
      if ( h_inerc >= 0.0 || (h_inerc + 0.5) >= 0.0)
      {
        process();
      }
      else
      {
        reset_forces();
        process();
      }
      break;
    case 3:
      sub10func();
      stopping(0.5);
      if(process() && !get_frame())
        set_seq(0);
      break;
    case 4: //walk fwd
      sub10func();
      char_h_move(4.0);
      process();
      break;
    case 5: //walk back
      sub10func();
      char_h_move(-4.0);
      process();
      break;
    case 6: // jump up
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

        if (get_elaps_frames() == 0 &&
              get_frame_time() == 0 &&
              get_frame() == 0 &&
              get_subseq() == 1)
        { 
            h_inerc = 0.0;  //field_85C;
            v_inerc = 12.0; //field_860;
            v_force = 0.4;  //field_864;
        }
        break;
    case 7: // jump fwd
      if (!get_subseq())
      {
        sub10func();
        if( !field_49A)
          reset_forces();
      }

      if (get_subseq()>0)
      {
        v_inerc -= v_force;
        if (char_on_ground_down())
        {
          set_seq(10);
          y = getlvl_height();
          reset_forces();
          break; //return?
        }
      }

      process();

      if (get_subseq()       == 1 &&
            get_frame_time()   == 0 &&
            get_frame()        == 0 &&
            get_elaps_frames() == 0)
      {
        char_h_move(4.0);
        v_inerc = 12.0;
        v_force = 0.4;
        field_49A = 0;   
      }
      break;
    case 8: // jump back
      if (get_subseq() == 0)
      {
          sub10func();
          if (field_49A == 0)
              reset_forces();
      }

      if(get_subseq()>0)
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

      if(!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
      {
        char_h_move(-4.0);
        v_inerc = 12.0;
        v_force = 0.4;
        field_49A = 0;
      }
      break;
    case 9: //?
      if( v_force == 0.0 )
        v_force = 0.6;
      v_inerc -= v_force;
      if ( !char_on_ground_down()) 
        process();
      set_seq(10);
      y = getlvl_height();
      reset_forces();
      break;
    case 10:
      sub10func();
      reset_forces();
      if(process())
        set_seq(0);
      break;
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67: //?
      v_inerc -= 0.3;
      h_inerc += 0.1;
      if ( h_inerc >  -1.0)
        h_inerc = -1.0;
      if (!has_shadow)
        has_shadow = 1;
      if(!char_on_ground_down())
      {
        if ( process() )
          set_seq(0);
      }
      play_sfx(0);
      reset_forces();
      y = getlvl_height();
      //shake_camera(2.0); //HACK

      //edited in myself
      /*float v1489 = 0.0;
      //?!
      float t67[0];
      t67[0] = scene_rand_rngf(10) + v1489 * 24.0;
      float xx67 = cos_deg(-t67[0]) * 100.0 * (double)dir + x;
      float yy67 = sin_deg(-t67[0]) * 20.0 + y;
      do
      {
        addbullet(this,NULL, 971,xx67, yy67, dir, y, t67, 3);
        //timer?
        v1489 += 1.0;
      }
      while( v1489 < 15.0 ); */
      set_seq(10);
      break;
    case 70:
    case 71:
    case 72:
    case 73:
    case 74:
    case 75:
    case 76:
    case 77:
    case 78:
    case 79:
    case 80:
    case 81:
    case 82:
    case 83:
    case 84:
    case 85:
    case 86:
    case 87:
    case 88:
      v_inerc -= 0.3;
      h_inerc += 0.1;
      if ( h_inerc > -1.0)
        h_inerc = -1.0;
      if ( !has_shadow)
        has_shadow = 1;
      if (char_on_ground_down())
      {
        y = getlvl_height();
        play_sfx(0);
        field_7DC = h_inerc;
        dash_angle = v_inerc;
        reset_forces();
        //shake_camera(10.0) //HACK ?
        //edited in myself
        //falling on ground effect <- FIXTHIS

        /*float v1490 = 0.0;

        float t[0];
        t[0] = scene_rand_rngf(10) + v1490 * 24.0;
        float xx = cos_deg(-t[0]) * 100.0 * (double)dir + x;
        float yy = sin_deg(-t[0]) * 20.0 + y;
        do
        {
          addbullet(this,NULL, 971, xx, yy, dir, (1 - 2 * (sin_deg(-t[0])) > 0.0), t, 3);
          v1490 += 1.0;
        }
        while ( v1490 < 15.0);*/
        set_seq(96);  
      }
      else if (process()) //else if or just if only?
        set_seq(199);
      break;
    case 96:
      if ( get_subseq() == 1)
      {
        v_inerc -= 0.2;
        h_inerc += 0.1;
        if (h_inerc > 0.0)
          h_inerc = 0.0;
        if ( char_on_ground_down())
        {
          y = getlvl_height();
          play_sfx(0);
          reset_forces();
          //shake_camera(2.0); //HACK ?
          set_seq(99);
          next_subseq();
        }
      }
      else //else? or just an if?
        sub10func();

      if ( process() )
        set_seq(0);
      if (!get_elaps_frames() &&
            !get_frame_time() &&
            !get_frame() &&
            get_subseq() == 1)
      {
        h_inerc = field_7DC * 0.2;
        v_inerc = 0.2 * -dash_angle;
        v_force = 0.2;
      }
      break;
    case 99:
      sub10func();
      if ( get_subseq() == 3)
      {
        has_shadow = 0;
        /* //what is this?
        if ( color_A <= 3u)
          color_A = 0;
        else
          color_A -= 3; */
      }
      if ( health <= 0)
      {
        field_51C = 3;
        field_520 = 3;
      }
      process();
      if ( !get_elaps_frames() && 
              !get_frame_time() &&
              !get_frame() &&
              get_subseq() == 2)
      {
        if ( !field_576 && !field_880)
        {
          if (cards_added >0 && (controlling_type) == 2 && cards_active[0]->id >= 248 )
          {
            health_to_max();
            field_868;
          }
          field_51C = 3;
          field_520 = 3;
          set_seq(199);
          field_574 = 0;
          field_577 = 1;
        }
        field_880 = 0;
      }
      break;

    case 149:
    //are brackets needed?
    
    if ( v_inerc <= 0.0)
      v_inerc -= v_force * 0.25;
    else
      v_inerc -= v_force;
    if ( !char_on_ground_down() )
      process();
    else
    {
      reset_forces();
      field_49A = 0;
      process();
    }
    play_sfx(0);
    field_7DC = h_inerc;
    dash_angle = v_inerc;
    y = getlvl_height();
    reset_forces();
    //shake_camera(10.0) //HACK ?

    //?!
    /*float v1491 = 0.0;
    float t149[0];
    t[0] = scene_rand_rngf(10) + v1491 * 24.0;
    float xx149 = cos_deg(t149[0]) * 100.0 * (double)dir + x;
    float yy149 = sin_deg(-t149[0]) * 20.0 + y; */
    //this is actually a do statement?
    //for ( float i = 0.0; i < 15.0; i++)
      //addbullet(this, NULL, 971, xx149, yy149, dir, (1 - 2 * (sin_deg(-t149[0])) > 0.0), t149, 3);
    set_seq(96);
    angZ = 0.0;
    //shake_camera(2.0) //HACK ?
    reset_ofs();
    break;
  
  case 199: //getting up (tech?)
    sub10func();
    if ( health <= 0)
    {
      field_51C = 3;
      field_520 = 3;
    }
    if ( process() )
    {
      field_51C = 3;
      field_520 = 3;
      set_seq(0);
      if ( enemy->x < (double)x)
        dir = -1;
      if ( enemy->x > (double)x)
        dir = 1;
    }
    break;

  case 200:
  //TOO: why are hi-jumps malfunctioning? why namazu sprites are missing?
    sub10func();
    field_49A = 1;
    if ( h_inerc > 6.0)
    {
      h_inerc -= 0.5;
      if ( h_inerc < 6.0)
        h_inerc = 6.0;
    }

    process();
    if ( get_subseq() != 1)
    {
      if (!get_elaps_frames() && !get_frame_time() && get_frame() && get_subseq() == 1)
      {
        char_h_move(15.0);
        scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
        scene_play_sfx(31);
      }
    }

    if (!(get_elaps_frames() % 5))
    {
      float yy200 = (scene_rand() % 200) + y;
      float xx200 = x - (scene_rand() % 100) + 50;
      scene_add_effect(this, 124,xx200, yy200, dir, 1);
    }

    if (dY() >= 0)
    {
      ++field_7D0;
      if ( (dX(dir) > 0 || field_7D0 <= 5) && field_7D0 <= 60 )
      {
        if (!get_elaps_frames() && !get_frame_time() && get_frame() && get_subseq() == 1)
        {
          char_h_move(15.0);
          scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
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
      if (dX(dir) <= 0)
        set_seq(200);
      else
        set_seq(201);
    }
    break;
  //TODO: fix broken falling effect
  case 201:
    if ( !get_subseq() || get_subseq() == 4 )
    {
      sub10func();
    }
    if ( !char_on_ground_down() && (get_elaps_frames() % 5) == 0)
    {
      float xx = x + 50.0 - (scene_rand() % 100);
      float yy = (scene_rand() % 200) + y;
      scene_add_effect(this, 124,xx, yy, dir, 1 );
    }

    if ( get_subseq() < 4 )
    {
      v_inerc -= v_force;
      if ( char_on_ground_down() )
      {
        reset_forces();
        y = getlvl_height();
        set_subseq(4);
        break;
      }
    }
    if (process() )
    {
      set_seq(0);
      h_inerc = 0.0;
    }
    else if (!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
    {
      char_h_move(-10.0);
      v_inerc = 2.0;
      v_force = 0.2;
      scene_add_effect(this, 125, x, y + 80.0, dir , 1);
      scene_add_effect(this, 126, x, y + 80.0, dir , 1);
      scene_play_sfx(31);
    }
    break;
  case 202:
    v_inerc -= v_force;
    if ( char_on_ground_down() )
    {
      reset_forces();
      y = getlvl_height();
      set_seq(10);
    }
    else
    {
      if ( (get_subseq() == 1 || get_subseq() == 2) && (get_elaps_frames() % 5) == 0 )
      {
        float xx = x + 50.0 - (scene_rand() % 100);
        float yy = (scene_rand() % 200) + y;
        scene_add_effect(this, 124, xx, yy, dir, 1);
      }
      if ( process() )
        set_seq(9);
      if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
      {
        field_7D0 = 0;
        char_h_move(7.5);
        v_inerc = 3.5;
        v_force = 0.4;
        scene_add_effect(this, 125, (80 * dir) + x, y + 110.0, dir, 1);
        scene_add_effect(this, 126, x, y + 110.0, dir, 1);
        scene_play_sfx(31);
      }
      if ( get_subseq() == 2 &&
            !get_frame_time() &&
            get_frame() == 5)
        flip_with_force();
    }
    break;
  case 203:
    v_inerc -= v_force;
    if(char_on_ground_down())
    {
      reset_forces();
      y = getlvl_height();
      set_seq(10);
    }
    else
    {
      if ( get_subseq() < 2 && !(get_elaps_frames() % 5))
      {
        float xx = x + 50.0 - (scene_rand() % 100);
        float yy = (scene_rand() % 200) + y;
        scene_add_effect(this, 124, xx, yy, dir, 1);
      }
      process();
      if ( !get_subseq() && !get_frame_time() && get_frame() == 1)
      {
        char_h_move(-7.5);
        v_inerc = 3.5;
        v_force = 0.4;
        scene_add_effect(this, 125, x, y + 120.0, dir, 1);
        scene_add_effect(this, 126, x, y + 120.0, dir, 1);
        scene_play_sfx(31);
      }
      if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2)
        flip_with_force();
    }
    break;
  case 204:
    sub10func();
    h_inerc -= 0.5;    
    if ( h_inerc < 0.0)
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
    //things go wack here
  /*case 208:
    sub10func();
    reset_forces();
    set_seq(6);
    break;*/
  case 209:
  case 212:
  case 222:
    if ( !get_subseq())
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
    if ( get_subseq() > 0)
    {
      v_inerc -= v_force;
      if ( v_inerc < -20.0)
        v_inerc = -20.0;
    }
    if ( get_subseq() == 1 && v_inerc < 4.0)
      set_subseq(2);
    process();
    if ( get_elaps_frames() == 0&& 
         get_frame_time()   == 0&&
         get_frame()        == 0&&
         get_subseq() == 1)
    {
      char_h_move(10.0);
      v_inerc = 13.5;
      v_force = 0.5;
      field_49A = 0;
      scene_add_effect(this, 63, x, y, dir, 1);
    }
    break;
  case 211:
    if (!get_subseq())
      sub10func();
    if (char_on_ground_down())
    {
      set_seq(10);
      y = getlvl_height();
      reset_forces();
      break;
    }
    if ( char_on_ground_down() || v_inerc > 0.0)
      field_522 = 2;
    if ( get_subseq() > 0)
    {
      v_inerc -= v_force;
      if ( v_inerc < -20.0)
        v_inerc = -20.0;
    }
    if ( get_subseq() == 1 && v_inerc < 4.0)
      set_subseq(2);
    process();
    if ( get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1 )
    {
      char_h_move(2.0);
      v_inerc = 18.5;
      v_force = 0.5;
      field_49A = 0;
      scene_add_effect(this, 63, x, y, dir, 1);
    }
    break;
  case 214:
  //taken from alice.cpp
        if ( process() )
        {
            set_seq( 9);
            break;
        }
        if ( get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 )
        {
            if ( get_subseq() == 1 )
                scene_play_sfx(31);
            if (get_subseq() == 6 )
            {
                set_seq( 9);
                break;
            }
        }
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

        if ( get_subseq() <= 0 || get_subseq() >= 5 )
        {
            if ( char_on_ground_down() )
            {
                y = getlvl_height();
                v_force = 0.0;
                v_inerc = 0.0;
                if ( get_subseq() >= 5 )
                {
                    set_seq( 10);
                    reset_forces();
                }
                else
                {
                    reset_ofs();
                    set_seq( 215);
                }
            }
            break;
        }
        field_7D6++;
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


        if ( h_inerc < 0.0 )
        {
            if ( get_subseq() == 1 )
                set_subseq(3);
            else if ( get_subseq() == 2 )
                set_subseq(4);
        }
        else
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
        }
        break;
  case 215:
    sub10func();
    if ( h_inerc > 0.0)
    {
      h_inerc -= 0.75;
      if ( h_inerc < 0.0)
        h_inerc = 0.0;
    }
    if ( h_inerc < 0.0)
    {
      h_inerc += 0.75;
      if ( h_inerc > 0.0 )
        h_inerc = 0.0;
    }
    if ( process())
    {
      set_seq(0);
      break;
    }
    break;
  case 217:
  //taken from alice.cpp
        if ( process() )
        {
            set_seq( 9);
            break;
        }
        if ( get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 )
        {
            if ( get_subseq() == 1 )
                scene_play_sfx(31);
            if (get_subseq() == 6 )
            {
                set_seq( 9);
                break;
            }
        }

        field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * dir);

        if ( get_subseq() == 5 || get_subseq() == 6 )
            v_inerc -= v_force;

        if ( get_subseq() <= 0 || get_subseq() >= 5 )
        {
            if ( char_on_ground_down() )
            {
                y = getlvl_height();
                v_force = 0.0;
                v_inerc = 0.0;
                if ( get_subseq() >= 5 )
                {
                    set_seq( 10);
                    reset_forces();
                }
                else
                {
                    reset_ofs();
                    set_seq( 215);
                }
            }
            break;
        }

        field_7D6++;
        field_7D4 = field_7D2 - dash_angle;
        if ( field_7D4 >180 )
            field_7D4 -= 360;
        else if (field_7D4 < -180)
            field_7D4 += 360;

        if ( field_7D4 > 0 )
        {
            if ( weather_id != WEATHER_SUNNY )
                dash_angle += 0.25;
            else
                dash_angle += 0.75;
        }
        else if ( field_7D4 < 0 )
        {
            if ( weather_id != WEATHER_SUNNY )
                dash_angle -= 0.25;
            else
                dash_angle -= 0.75;
        }

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
  case 220:
    if (!get_subseq())
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
    if ( get_subseq() > 0)
    {
      v_inerc -= v_force;
      if ( v_inerc < -20.0)
        v_inerc = -20.0;
    }
    if ( get_subseq() == 1 && v_inerc < 4.0)
      set_subseq(2);
    process();
    if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
    {
      char_h_move(0.0);
      v_inerc = 18.5;
      v_force = 0.5;
      field_49A = 0;
      scene_add_effect(this, 63, x, y, dir, 1);
    }
    break;
  case 223:
    sub10func();
    field_49A = 1;
    if ( h_inerc > 6.0)
    {
      h_inerc -= 0.5;
      if ( h_inerc <  6.0)
        h_inerc = 6.0;
    }
    process();
    if ( get_subseq() != 1)
    {
      if (!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
      {
        char_h_move(7.5);
        scene_add_effect(this, 125, (80 * dir)+x, y + 80.0, dir, 1);
        scene_add_effect(this, 126, x, y + 80.0, dir, 1);
        scene_play_sfx(31);
      }
    }
    else
    {
      set_seq(204);
    }
    if ( !(get_elaps_frames() % 5) )
    {
      float xx = x + 50.0 - (scene_rand() % 100);
      float yy = (scene_rand() % 200) + y;
      scene_add_effect(this, 124, xx, yy, dir, 1);
    }

    ++field_7D0;
    if ( dX(dir) > 0 || field_7D0 <= 15 && field_7D0 <= 60)
    {
        if (!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
        {
          char_h_move(7.5);
          scene_add_effect(this, 125, (80 * dir)+x, y + 80.0, dir, 1);
          scene_add_effect(this, 126, x, y + 80.0, dir, 1);
          scene_play_sfx(31);
        }
    }
    else
    {
      set_seq(204);
    }
    break;
  case 224:
    if ( !get_subseq() || get_subseq() == 4)
      sub10func();
    if ( char_on_ground_down() && !(get_elaps_frames() % 5))
    {
      float xx = x + 50.0 - (scene_rand() % 100);
      float yy = (scene_rand() % 200) + y;
      scene_add_effect(this, 124, xx, yy, dir, 1);
    }
    if (get_subseq() < 4)
    {
      v_inerc -= v_force;
      if ( char_on_ground_down())
      {
        reset_forces();
        y = getlvl_height();
        set_subseq(4);
        break;
      }
    }
    if ( process() )
    {
      set_seq(0);
      h_inerc = 0.0;
    }
    else if (!get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
    {
      char_h_move(-10.0);
      v_inerc = 2.0;
      v_force = 0.2;
      scene_add_effect(this, 125, x, y + 80.0, dir, 1);
      scene_add_effect(this, 126, x, y + 80.0, dir, 1);
      scene_play_sfx(31);
    }
    break;
  case 225:
    v_inerc -= v_force;
    if ( char_on_ground_down())
    {
      reset_forces();
      y = getlvl_height();
      set_seq(10);
    }
    else
    {
      if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5))
      {
        float xx = x + 50.0 - (scene_rand() % 100);
        float yy = (scene_rand() % 200) + y;
        scene_add_effect(this, 124, xx, yy, dir, 1);
      }
    }
    if ( process())
      set_seq(9);

    if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
    {
      field_7D0 = 0;
      char_h_move(-7.5);
      v_inerc = 3.5;
      v_force = 0.4;
      scene_add_effect(this, 125, (80 * dir) + x, y + 110.0, dir, 1);
      scene_add_effect(this, 126, x, y + 110.0, dir, 1);
      scene_play_sfx(31);
    }
    if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 5)
      flip_with_force();
    break;
  case 226:
    v_inerc -= v_force;
    if ( char_on_ground_down())
    {
      reset_forces();
      y = getlvl_height();
      set_seq(10);
    }
    else
    {
      if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5))
      {
        float xx = x + 50.0 - (scene_rand() % 100);
        float yy = (scene_rand() % 200) + y;
        scene_add_effect(this, 124, xx, yy, dir, 1);
      }
    }
    if ( process())
      set_seq(9);

    if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1)
    {
      field_7D0 = 0;
      char_h_move(7.5);
      v_inerc = 3.5;
      v_force = 0.4;
      scene_add_effect(this, 125, (80 * dir) + x, y + 110.0, dir, 1);
      scene_add_effect(this, 126, x, y + 110.0, dir, 1);
      scene_play_sfx(31);
    }
    if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 5)
      flip_with_force();
    break;
  // still can't determine if hi jumps/airdashes/dashes are part of namazu*/


  //?? starts from here onwards
  case 301:
    sub10func();
    //if (get_true(0))
    if ( field_49A)
    {
      h_inerc -= 0.5;
      if ( h_inerc < 0.0)
      {
        h_inerc = 0.0;
        field_49A = 0;
      }
    }
    if (get_frame() >= 5)
    {
      h_inerc -= 0.1;
      if ( h_inerc < 0.0)
        h_inerc = 0.0;
    }
    if ( process())
      set_seq(0);
    if ( get_frame_time() )
      break;
    if ( get_frame() == 2)
    {
      h_inerc = 4.0;
      field_49A = 0;

      float tmp[3];
      tmp[0] = 0.0;
      tmp[1] = 0.0;
      tmp[2] = 3.0;

      addbullet(this,NULL, 848, x, y, dir, 1, tmp, 3);
    }
    if ( !get_frame_time() && get_frame() == 3)
    {
      play_sfx(0);
      field_49A = 0;
    }
    break;
  //case 302: taken from cirno.cpp
  case 302:
            if ( keyDown(INP_A) == 0 )
            not_charge_attack = 0;
        if ( h_inerc > 0.0 )
        {
            h_inerc -= 0.75;
            if ( h_inerc < 0.0 )
                h_inerc = 0.0;
        }
        if ( process() ||
                (get_elaps_frames() == 0 && get_frame_time() == 0 && get_frame() == 0 && get_subseq() == 1) )
        {
            set_seq( 0);
            break;
        }
        if (get_subseq() == 1 && get_frame_time() == 0 && get_frame() == 7)
        {
            h_inerc = 15.0;
            play_sfx( 52);
            float tmp[3];
            tmp[0] = 0.0;
            tmp[1] = 0.0;
            tmp[2] = 0.0;

            CharFrameData *frm = get_pframe();
            addbullet(this, NULL, 990, (frm->extra1[4] * dir) + x, y - frm->extra1[5], dir, 1, tmp, 3);
        }
        if (get_subseq() == 0 && get_frame_time() == 0)
        {
            if (get_frame() == 4 && not_charge_attack)
            {
                scene_add_effect(this, 62, x, y + 205.0, dir, 1);
                next_subseq();
                break;
            }
            if (get_frame() == 6)
            {
                h_inerc = 12.5;
                play_sfx( 52);
                float tmp[3];
                tmp[0] = 0.0;
                tmp[1] = 0.0;
                tmp[2] = 0.0;

                CharFrameData *frm = get_pframe();
                addbullet(this, NULL, 990, (frm->extra1[4] * dir) + x, y - frm->extra1[5], dir, 1, tmp, 3);
            }
        }
        break;
  default:
    char_c::func10();
    break;
  }
}

//Func20
void char_namazu::func20()
{
	//pre switch statements

    //note: taken from marisa.cpp
    //main big switch statement
    uint16_t cprior = get_cprior();
    uint32_t fflags = get_pframe()->fflags;

    bool cc = (fflags & FF_CANCELLEABLE) != 0;
    bool cu = (fflags & FF_HJC) != 0;
    int32_t sq = get_seq();

    if ( !check_AB_pressed() )
    {
        if ( cc || cu )
        {
            /*
             if ( pres_comb >= 700 && pres_comb < 800 ) //HACK?
             {
               //class->func2_set_seq(v1, LOWORD(pres_comb));
               return;
             }
             else*/
            if ( char_on_ground_flag() )
            {
                if ( (cu && cprior >= 10 && hi_jump_after_move())
                        || border_escape_ground()
                        || hi_jump(cprior, cu)
                        || fw_bk_dash_ground(cprior, cu) )
                    return;
            }
            else
            {
                if ( border_escape_air() )
                  return;

                int8_t mx = (weather_id == WEATHER_TEMPEST) + 2;
                if ( fwd_dash_air(cprior, cu, mx, 2)
                        || bkg_dash_air(cprior, cu, mx, 1)
                        || flying_air(cprior, cu, mx) )
                    return;
            }
        }

        if ( field_84C == 0 && cc )
        {
            if (field_524 == 0)
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
                                //namazu has no more cases?
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
                                case 101:
                                    if( field_800 == 0)
                                    {
                                      field_4C8++;
                                      field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(520, cprior);
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
                                    if ( field_800 == 0)
                                    {
                                      field_4C8++;
                                      field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(525, cprior);
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
                            if ( skills_1[7] >= 1 )
                            {
                                if ( cprior <= get_prior(566) || (sq >= 500 && sq <= 599 && field_803 == 0))
                                {
                                    if ( field_803 == 0 )
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 566, cprior);
                                    return;
                                }
                            }
                            if (cprior <= get_prior(561) || (sq >= 500 && sq <= 599 && field_803 == 0) )
                            {
                                if( field_803 == 0)
                                {
                                  field_4C8++;
                                  field_803 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0(561, cprior);
                                return;
                            }
                          }
                          if ( pres_comb & PCOMB_623B )
                          {
                            if( skills_1[7] >= 1)
                            {
                              if ( cprior <= get_prior(565) || (sq >= 500 && sq <= 599 && field_803 == 0))
                              {
                                if ( field_803 == 0)
                                {
                                  field_4C8++;
                                  field_803 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0(565, cprior);
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
                              sub_4873B0(560, cprior);
                              return;
                            }
                          }
                          /*if ( pres_comb & 0x4000 ) //what is 0x4000?
                          {
                              if ( skills_1[6] >= 1)
                              {
                                if ( cprior <= get_prior(546) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                  if ( field_802 == 0)  
                                  {
                                    field_4C8++;
                                    field_802 = 1;
                                  }  
                                sub_4834F0();
                                sub_4873B0(546, cprior);
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
                            sub_4873B0(541, cprior);
                            return;
                          }
                        }*/

                        //if ( pres_comb & 0x2000) //what is 0x2000?

                        if ( pres_comb & PCOMB_214C )
                        {
                          if ( skills_1[8] >= 1)
                          {
                            if ( cprior <= get_prior(511) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                              if ( field_800 == 0)
                              {
                                field_4C8++;
                                field_800 =1;
                              }
                              sub_4834F0();
                              sub_4873B0(511, cprior);
                              return;
                            }
                          }
                          if ( skills_1[4] >= 1)
                          {
                            if ( cprior <= get_prior(506) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                              if ( field_800 == 0)
                              {
                                field_4C8++;
                                field_800 = 1;
                              }
                              sub_4834F0();
                              sub_4873B0(506, cprior);
                              return;
                            }
                          }
                          if ( cprior <= get_prior(501) || (sq >= 500 && sq <= 599 && field_800 == 0))
                          {
                            if ( field_800 == 0)
                            {
                              field_4C8++;
                              field_800 = 1;
                            }
                            sub_4834F0();
                            sub_4873B0(501, cprior);
                            return;
                          }
                        }
                        if ( pres_comb & PCOMB_214B)
                        {
                          if ( skills_1[8] >= 1)
                          {
                            if ( cprior <= get_prior(510) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                              if ( field_800 == 0)
                              {
                                field_4C8++;
                                field_800 = 1;
                              }
                              sub_4834F0();
                              sub_4873B0(510, cprior);
                              return;
                            }
                          }
                          if ( skills_1[4] >= 1)
                          {
                            if ( cprior <= get_prior(505) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                              if ( field_800 == 0)
                              {
                                field_4C8++;
                                field_800 = 1;
                              }
                              sub_4834F0();
                              sub_4873B0(505, cprior);
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
                            sub_4873B0(500, cprior);
                            return;
                          }
                        }
                        if ( pres_comb & PCOMB_236C )
                        {
                          if ( skills_1[5] >= 1)
                          {
                            if ( cprior <= get_prior(525) || (sq >= 500 && sq <= 599 && field_801 == 0))
                            {
                              if ( field_801 == 0)
                              {
                                field_4C8++;
                                field_801 = 1;
                              }
                              sub_4834F0();
                              sub_4873B0(525, cprior);
                              return;
                            }
                          }
                          if ( skills_1[5] == 0 && skills_1[9] == 0)
                          {
                            if ( cprior <= get_prior(521) || (sq >= 500 && sq <= 599 && field_801 == 0))
                            {
                              if ( field_801 == 0)
                              {
                                field_4C8++;
                                field_801 = 1;
                              }
                              sub_4834F0();
                              sub_4873B0(521, cprior);
                              return;
                            }
                          }
                        }

                        if ( pres_comb & PCOMB_236B )
                        {
                          if (skills_1[5] >= 1)
                          {
                            if ( cprior <= get_prior(525) || (sq >= 500 && sq <= 599 && field_801 == 0))
                            {
                              if ( field_801 == 0)
                              {
                                field_4C8++;
                                field_801 =1;
                              }
                              sub_4834F0();
                              sub_4873B0(525, cprior);
                              return;
                            }
                          }
                          if ( skills_1[5] == 0 && skills_1[9] == 0)
                          {
                            if ( cprior <= get_prior(520) || (sq >= 500 && sq <= 599 && field_801 == 0))
                            {
                              if ( field_801 == 0)
                              {
                                field_4C8++;
                                field_801 = 1;
                              }
                              sub_4834F0();
                              sub_4873B0(520, cprior);
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
                          angZ = 0.0;
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

/*
void char_namazu::func24() {
	if (  )
}  */

void char_namazu::set_seq_params() 
{
  //acquire current state!
  std::cout << "NAMAZU_get_seq(): " << get_seq() << std::endl;
  std::cout << "NAMAZU_get_subseq(): " << get_subseq() << std::endl;

  //big switch statement
  uint32_t sq = get_seq();

  switch(sq)
  {
    case 4: //walk fwd
      h_inerc = 4.0;
      break;
    case 5: //walk back
      h_inerc = -4.0;
      break;
    case 50:
    case 51:
    case 52:
    case 53:
    case 54:
    case 55:
    case 56:
    case 57:
    case 58:
    case 59:
    case 60:
    case 61:
    case 62:
    case 63:
    case 64:
    case 65:
    case 66:
    case 67:
      field_1A4 = 0.0;
      field_7D0 = 0;
      field_1A8 = 0.0;
      field_7D2 = 0;
      angZ = 0.0;
      field_571 = 1;
      field_572 = 1;
      h_inerc = -6.0;
      v_inerc = 6.0;
      v_force = 0.2;
      break;
    case 88:
    case 89:
      field_571 = 1;
      field_572 = 1;
      field_7D0 = 0;
      h_inerc = -field_1A4;
      v_inerc *= 0.5;
      v_force = 0.2;
      if(field_1A4 > 0.0)
        field_7D0 = 1;
      if(field_1A4 < 0.0)
        field_7D0 = -1;
      angZ = 0.0;
      break;
    case 214:
      field_7D6 = 0;
      h_inerc = 0.0;
      v_inerc = 0.0;
      v_force = 0.6;
      x_off = 0.0;
      y_off = 95.0;
      field_7DC = 9.0;
      field_7EC = 0.0;
      break;
    case 217:
      reset_ofs();
      field_7D6 = 0;
      h_inerc = 0.0;
      v_inerc = 0.0;
      v_force = 0.6;
      x_off = 0.0;
      y_off = 95.0;
      field_7DC = 9.0;
      field_7EC = 0.0;
      break;
    case 300:
    case 301:
    case 303:
    case 322:
      if( !field_49A )
        reset_forces();
      field_190 = 0;
      field_194 = 1;
      break;
    case 302:
      if( !field_49A )
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
      h_inerc = 12.0;
      field_194 = 1;
      v_force = 0.0;
      break;
    case 306:
      field_7D0 = 0;
      field_190 = 0;
      field_194 = 1;
    case 307:
    case 309:
      field_194 = 1;
      field_190 = 0;
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
      reset_forces();
      field_190 = 0;
      field_194 = 1;
      break;
    case 321:
      reset_forces();
      field_194 = 1;
      field_190 = 0;
      break;
    case 400:
    case 401:
    case 411:
      field_190 = 0;
      reset_forces();
      field_7D0 = 0;
      field_7D2 = 0;
      field_7D6 = 0;
      not_charge_attack = 1;
      break;
    case 402:
    case 410:
    case 412:
      field_190 = 0;
      reset_forces();
      field_7D0 = 0;
      field_7D2 = 0;
      field_7D4 = 0;
      not_charge_attack = 1;
      break;
    case 404:
    case 406:
      field_7D6 = 0;
    case 408:
      h_inerc = 14.5;
      v_inerc = 0.0;
      field_49A = 0;
      field_7D0 =0;
      field_190 = 0;
      field_194 = 1;
      break;
    case 409:
      v_force = 0.3;
      field_49A = 0;
      field_7D0 = 0;
      field_190 = 0;
      field_194 = 1;
      break;
    case 414:
    case 416:
      v_force = 0.0;
      field_190 = 0;
      field_7D0 = 0;
      field_7D2 = 0;
      field_7D4 = 0;
      not_charge_attack = 1;
      h_inerc *= 0.2;
      v_inerc *= 0.2;
      break;
    case 415:
      field_7D4 = 0;
      field_7D2 = 0;
      v_force = 0.0;
      field_7D0 = 0;
      field_190 =0;
      not_charge_attack = 1;
      h_inerc *= 0.2;
      v_inerc *= 0.2;
      break;
    case 418:
      h_inerc = 15.0;
      field_194 = 1;
      field_190 = 0;
      break;
    case 500:
    case 501:
      field_18C = 0;
      reset_forces();
    case 502:
    case 503:
      field_18C = 0;
      h_inerc *= 0.2;
      v_inerc *= 0.2;
      v_force = 0.0;
      field_49A = 0;
      field_7D0 = 0;
      field_190 = 1;
      break;
    case 505:
    case 506:
      field_18C = 4;
      reset_forces();
      field_49A = 0;
      field_7D0 = 0;
      field_190 = 1;
      break;
    case 507:
    case 508:
      field_18C = 4;
      h_inerc *= 0.2;
      v_inerc *= 0.2;
      v_force = 0.0;
      field_49A = 0;
      field_7D0 = 0;
      field_190 = 1;
      break;
    case 510:
    case 511:
      field_18C = 8;
      reset_forces();
      dash_angle = 0.0;
      field_49A = 0;
      field_7D0 = 0;
      field_190 = 1;
      break;
    case 512:
    case 513:
      field_49A = 0;
      field_7D0 = 0;
      field_18C = 8;
      field_190 = 1;
      h_inerc *= 0.2;
      v_inerc *= 0.2;
      v_force = 0.0;
      dash_angle = 0.0;
      break;
    case 520:
    case 521:
      field_18C = 1;
      reset_forces();
      field_190 = 0;
      field_49A = 0;
      break;
    case 522:
    case 523:
      field_190 = 0;
      field_49A = 0;
      field_18C = 1;
      h_inerc *= 0.2;
      v_inerc *= 0.2;
      v_force = 0.0;
      break;
    case 525:
    case 526:
      field_18C = 5;
      reset_forces();
      field_190 = 0;
      field_49A = 0;
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
    case 545:
    case 546:
      field_18C = 6;
      field_190 = 0;
      reset_forces();
      field_7D0 = 0;
      field_7D2 = 0;
      field_7D6 = 0;
      field_7D8 = 0;
      not_charge_attack = 1;
      break;
    case 547:
      field_190 = 0;
      not_charge_attack = 0;
      field_18C = 2;
      field_194 = 1;
      break;
    case 560:
    case 561:
      field_18C = 3;
      field_194 = 1;
      field_190 = 0;
      reset_forces();
      not_charge_attack = 1;
      break;
    case 562:
      field_18C = 3;
      field_7D6 = 0;
      field_7D2 = 0;
      v_force = 0.0;
      field_7D0 = 0;
      field_190 = 0;
      not_charge_attack = 1;
      h_inerc *= 0.2;
      v_inerc *= 0.2;
      break;
    case 565:
    case 566:
    case 567:
      field_18C = 7;
      field_194 = 1;
      field_190 = 0;
      reset_forces();
      not_charge_attack = 1;
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
    case 602:
    case 605:
    case 606:
      field_190 = 1;
      reset_forces();
      break;
    case 601:
    case 604:
    case 608:
    case 610:
    case 611:
      field_7D0 = 0;
      field_7D2 = 0;
      field_190 = 1;
      reset_forces();
      break;
    case 603:
      field_7D0 = 0;
      dash_angle = 0.0;
      field_7D2 = 0;
      field_190 = 1;
      reset_forces();
      break;
    case 607:
      field_190 = 1;
      reset_forces();
      field_7D0 = 0;
      field_7D2 = 0;
      break;
    case 612:
    case 615:
      field_190 = 1;
      reset_forces();
      field_7D0 = 0;
      field_7D2 = 0;
      field_7D6 = 0;
      field_7D8 = 0;
      not_charge_attack = 1;
      break;
    case 613:
      field_190 = 0;
      not_charge_attack = 1;
      break;
    case 651:
      v_force = 0.0;
      field_7D0 = 0;
      field_7D2 = 0;
      field_190 = 1;
      v_inerc *= 0.2;
      h_inerc *= 0.2;
      break;
    case 700:
      break;
    case 701:
    case 702:
    case 703:
      if ( !field_49A )
        reset_forces();
      break;
    case 704:
    case 707:
    case 740:
      reset_forces();
      break;
    case 705:
      h_inerc = 6.0;
      break;
    case 706:
      h_inerc = -6.0;
      break;
    case 708:
      h_inerc = 0.0;
      field_7D0 = 0;
      break;
    case 709:
      field_7D0 = 0;
      break;
    case 710:
    case 720:
      field_190 = 0;
      reset_forces();
      field_7D0 = 0;
      field_7D2 = 0;
      field_7D6 = 0;
      field_7D8 = 0;
      break;
    case 725:
      field_7D0 = 0;
      h_inerc = 4.0;
      break;
    case 726:
      field_7D0 = 0;
      h_inerc = -4.0;
      break;
    case 730:
    case 731:
      field_190 = 0;
      reset_forces();
      break;
    case 797:
    case 798:
      field_7D0 = 0;
      play_sfx(50);
      break;
    default:
      char_c::set_seq_params();
      break;
  }
}
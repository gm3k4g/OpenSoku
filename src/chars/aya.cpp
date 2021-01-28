#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "aya.h"
#include <math.h>

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

void char_aya::init_vars()
{
  field_138 = -6.0;
  field_890 = 0;
  field_892 = 0;
  char_c::init_vars();
  field_894 = 0;
  field_896 = 0;
}

//Bullet function
/*
c_bullet *char_aya::new_bullet()
{
    c_bullet *tmp = new aya_bullets();
    return tmp;
}
*/

void char_aya::func10()
{
  float t[3];
  t[0] = 0.0;
  t[1] = 0.0;
  t[2] = 0.0;

  float tt[4];
  tt[0] = 0.0;
  tt[1] = 0.0;
  tt[2] = 0.0;
  tt[3] = 0.0;

  double move_val = 0.0;

  int v18 = 0;
  double v23 = 0.0;

  bool v30 = false;

  double v33 = 0.0;
  double v44 = 0.0;
  double v90 = 0.0;
  double v95 = 0.0;
  double v92 = 0.0;

  int v227 = 0;

  double v228 = 0.0;
  double v229 = 0.0;

  double a4 = 0.0;
  double v259 = 0.0;

  double v323 = 0.0;

  int v461 = 0;
  int v469 = 0;
  int v477 = 0;
  int v486 = 0;

  bool v484 = false;

  double a4a = 0.0;
  double v614 = 0.0;

  double v658 = 0.0;

  int v1101 = 0;

  bool v706 = false;

  double a4b = 0.0;
  double v710 = 0.0;

  int v1102 = 0;
  bool v714 = false;

  int v1103 = 0;
  bool v720 = false;

  double a4d = 0.0;
  double v736 = 0.0;

  double xg = 0.0;
  double a4e = 0.0;
  double v811 = 0.0;

  double xh = 0.0;
  double a4f = 0.0;
  double v816 = 0.0;

  double xi = 0.0;
  double a4g = 0.0;
  double v822 = 0.0;

  double a4i = 0.0;
  double v872 = 0.0;

  bool v958 = false;

  double v982 = 0.0;

  double a4j = 0.0;
  double v1009 = 0.0;

  double v166 = 0.0;

  double a4c = 0.0;
  double v724 = 0.0;

  int v1104 = 0;

  bool v728 = false;

  int xj = 0;
  double a4h = 0.0;
  double v826 = 0.0;

  x_delta = 0;
  y_delta = 101;
  if ( get_seq() > 149 && get_seq() < 159 && !bbarrier_show )
  {
    bbarrier_show = 1;
    if ( get_seq() > 149 && get_seq() < 154 )
    {
      addbullet(this, NULL, 998, (double)(57 * (char)dir) + x, y + 94.0, dir, 1, 0, 0);
    }
    if ( get_seq() > 153 && get_seq() < 158 )
    {
      addbullet(this, NULL, 998, (double)(57 * (char)dir) + x, y + 60.0, dir, 1, 0, 0);
    }
    if ( get_seq() == 158 )
    {
      addbullet(this, NULL, 998, (double)(57 * (char)dir) + x, y + 100.0, dir, 1, 0, 0);
    }
  }
  if ( field_892 > 0 )
  {
    field_54C = 0.0;
    speed_mult = 2.0;
    --field_892;
  }
  if ( field_894 > 0 )
  {
    field_54C = 0.0;
    --field_894;
    if ( health <= 0 || enemy->health <= 0 )
      field_894 = 0;
  }
  v18 = 4;
  if ( field_896 )
  {
    if ( getlvl_height() >= y && !(get_pframe()->fflags & 4) )
    {
      if ( get_seq() <= 524 || get_seq() >= 530 )
        field_896 = 0;
    }
    
  }
  if ( !hit_stop && !enemy->time_stop )
  {
    if (  get_seq() <= 300 )
    {
      if (  get_seq() == 300 )
      {
LABEL_595:
        sub10func();
        if ( true /*!get_true(0)*/)
        {
          if ( field_49A )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
            {
              h_inerc = 0.0;
              field_49A = 0;
            }
          }
          if ( process() )
            set_seq(0);
LABEL_601:
          if ( !get_frame_time() && get_frame() == 2 )
          {
            scene_play_sfx(27);
            field_49A = 0;
          }
        }
      }
      else
      {
        switch ( get_seq() )
        {
          case 0:
            sub10func();
            
            if ( 0.0 == h_inerc )
              field_49A = 0;
            if ( !field_49A )
              goto LABEL_33;
            goto LABEL_34;
          case 1:
            sub10func();
            if ( field_49A )
            {
              if ( h_inerc > 0.0 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                {
                  reset_forces();
                  field_49A = 0;
                }
              }
              if ( 0.0 > h_inerc )
              {
                h_inerc = h_inerc + 0.5;
                if ( h_inerc > 0.0 )
                {
                  reset_forces();
                  field_49A = 0;
                }
              }
            }
            else
            {
              reset_forces();
            }
            if ( process() && !get_frame() )
              goto LABEL_50;
            return;
          case 2:
            sub10func();
            if ( field_49A )
            {
LABEL_34:
              if ( 0.0 < h_inerc )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                {
                  reset_forces();
                  
                  field_49A = 0;
                }
              }
              if ( 0.0 <= h_inerc || (v23 = h_inerc + 0.5, h_inerc = v23, v23 <= 0.0) )
              {
LABEL_107:
                process();
              }
              else
              {
                reset_forces();
                field_49A = 0;
                process();
              }
            }
            else
            {
LABEL_33:
              reset_forces();
              process();
            }
            return;
          case 3:
            sub10func();
            if ( field_49A )
            {
              if ( h_inerc > 0.0 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                {
                  reset_forces();
                  field_49A = 0;
                }
              }
              if ( 0.0 > h_inerc )
              {
                h_inerc = h_inerc + 0.5;
                if ( h_inerc > 0.0 )
                {
                  reset_forces();
                  field_49A = 0;
                }
              }
            }
            else
            {
              reset_forces();
            }
            if ( !process() )
              return;
            v30 = get_frame() == 0;
            goto LABEL_63;
          case 4:
            sub10func();
            char_h_move(5.5);
            process();
            return;
          case 5:
            sub10func();
            char_h_move(-5.5);
            process();
            return;
          case 6:
            if ( !get_subseq() )
            {
              sub10func();
              if ( !get_subseq() )
              {
                if ( !field_49A )
                  reset_forces();
              }
            }
            if ( !((get_subseq() < 0) | (get_subseq() == 0)) )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_104;
            }
            process();
            if ( get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v33 = 0.0;
            goto LABEL_78;
          case 7:
            if ( !get_subseq() )
            {
              sub10func();
              if ( !get_subseq() )
              {
                if ( !field_49A )
                  reset_forces();
              }
            }
            if ( !((get_subseq() < 0) | (get_subseq() == 0)) )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_104;
            }
            process();
            if ( get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v33 = 8.0;
            goto LABEL_78;
          case 8:
            if ( !get_subseq() )
            {
              sub10func();
              if ( !get_subseq() )
              {
                if ( !field_49A )
                  reset_forces();
              }
            }
            if ( !((get_subseq() < 0) | (get_subseq() == 0)) )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_104;
            }
            process();
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              v33 = -8.0;
LABEL_78:
              char_h_move(v33);
              v_inerc = 18.0;
              v_force = 0.75;
              field_49A = 0;
            }
            return;
          case 9:
            if ( 0.0 == v_force )
              v_force = 0.60000002;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_104;
            goto LABEL_107;
          case 10:
            sub10func();
            reset_forces();
            if ( process() )
            {
              if ( dY() )
                set_seq(2);
              else
                set_seq(0);
            }
            return;
          case 197:
            if ( !get_subseq() && get_frame() <= 4 || get_subseq() == 2 )
              sub10func();
            if ( !get_frame_time() && get_frame() == 5 )
              addbullet(this, NULL, 990, x, y, dir, 1, 0, 0);
            if ( get_subseq() < 2 )
              v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
              goto LABEL_123;
            if ( !process() )
              goto LABEL_129;
            if ( controlling_type == 2 )
              goto LABEL_126;
            set_seq(0);
            if ( dY() > 0 )
              set_seq(1);
LABEL_129:
            if ( get_subseq() == 2 && get_frame() == 2 && !get_frame_time() )
            {
              if ( enemy->x < (double)x )
                dir = -1;
              if ( enemy->x > (double)x )
                dir = 1;
            }
            if ( get_subseq() || get_frame() != 5 || get_frame_time() )
              return;
            v_inerc = 4.8000002;
            v44 = 15.0;
            goto LABEL_140;
          case 198:
            if ( !get_subseq() && get_frame() <= 4 || get_subseq() == 2 )
              sub10func();
            if ( !get_frame_time() && get_frame() == 5 )
              addbullet(this, NULL, 990, x, y, dir, 1, 0, 0);
            if ( get_subseq() < 2 )
              v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
            {
LABEL_123:
              y = getlvl_height();
              reset_forces();
              set_subseq(2);
              return;
            }
            if ( !process() )
              goto LABEL_156;
            if ( controlling_type == 2 )
            {
LABEL_126:
              set_seq(700);
              field_51C = 3;
              field_520 = 3;
            }
            else
            {
              set_seq(0);
              if ( dY() > 0 )
                set_seq(1);
LABEL_156:
              if ( get_subseq() == 2 && get_frame() == 2 && !get_frame_time() )
              {
                if ( enemy->x < (double)x )
                  dir = -1;
                if ( enemy->x > (double)x )
                  dir = 1;
              }
              if ( !get_subseq() && get_frame() == 5 && !get_frame_time() )
              {
                v_inerc = 4.8000002;
                v44 = -15.0;
LABEL_140:
                h_inerc = v44;
                v_force = 0.40000001;
              }
            }
            return;
          case 199:
            sub10func();
            if ( !get_frame_time() && get_frame() == 5 )
              addbullet(this, NULL, 990, x, y, dir, 1, 0, 0);
            if ( !process() )
              goto LABEL_174;
            if ( controlling_type == 2 )
              goto LABEL_126;
            set_seq(0);
            if ( dY() > 0 )
              set_seq(1);
LABEL_174:
            if ( !get_subseq() && get_frame() == 17 && !get_frame_time() )
            {
              if ( enemy->x < (double)x )
                dir = -1;
              if ( enemy->x > (double)x )
                dir = 1;
            }
            return;
          case 200:
            sub10func();
            field_49A = 1;
            if ( h_inerc > 10.0 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 10.0 )
                h_inerc = 10.0;
            }
            process();
            if ( get_subseq() != 1 )
              goto LABEL_195;
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            if ( dY() >= 0 )
            {
              if ( (dX(dir) > 0 || ++field_7D0 <= 5) && ++field_7D0 <= 45 )
              {
LABEL_195:
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  char_h_move(18.5);
                  scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
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
              if ( (dX(dir) < 0) | (dX(dir) == 0) )
                set_seq(211);
              else
                set_seq(212);
            }
            return;
          case 201:
            if ( !get_subseq() || get_subseq() == 3 )
            {
              sub10func();
            }
            if ( get_subseq() == 3 )
            {
              h_inerc = h_inerc + 2.0;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
            }
            if ( !char_on_ground_flag() && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            if ( get_subseq() < 3 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_211;
            }
            if ( process() )
              goto LABEL_213;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_7D0 )
            {
              field_7D0 = 1;
              char_h_move(-17.0);
              v_inerc = 3.5;
              v_force = 0.75;
              scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
              scene_play_sfx(31);
            }
            return;
          case 202:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_221;
            if ( get_subseq() == 1 && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            process();
            if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
            {
              field_7D0 = 0;
              char_h_move(12.0);
              v_inerc = 4.0;
              v_force = 0.44999999;
              scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
              scene_add_effect(this, 126, x, y + 110.0, dir, 1);
              scene_play_sfx(31);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              flip_with_force();
            return;
          case 203:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              reset_forces();
              y = getlvl_height();
              set_seq(10);
            }
            else
            {
              if ( get_subseq() == 1 && !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
              }
              process();
              if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
              {
                char_h_move(-12.0);
                v_inerc = 4.0;
                v_force = 0.44999999;
                scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
                scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
                scene_play_sfx(31);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                flip_with_force();
            }
            return;
          case 204:
            sub10func();
            h_inerc = h_inerc - 1.5;
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
            return;
          case 208:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_255;
            if ( char_on_ground_flag() || v_inerc > 0.0 )
              field_522 = 2;
            if ( get_subseq() > 0 )
            {
              v_inerc = v_inerc - v_force;
              if ( v_inerc < -20.0 )
                v_inerc = -20.0;
            }
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v90 = 0.0;
            goto LABEL_270;
          case 209:
          case 221:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_255;
            if ( char_on_ground_flag() || v_inerc > 0.0 )
              field_522 = 2;
            if ( get_subseq() > 0 )
            {
              v_inerc = v_inerc - v_force;
              if ( v_inerc < -20.0 )
                v_inerc = -20.0;
            }
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v95 = 10.0;
            goto LABEL_290;
          case 210:
          case 222:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_255;
            if ( char_on_ground_flag() || v_inerc > 0.0 )
              field_522 = 2;
            if ( get_subseq() > 0 )
            {
              v_inerc = v_inerc - v_force;
              if ( v_inerc < -20.0 )
                v_inerc = -20.0;
            }
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v95 = -10.0;
            goto LABEL_290;
          case 211:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_255;
            if ( char_on_ground_flag() || v_inerc > 0.0 )
              field_522 = 2;
            if ( get_subseq() > 0 )
            {
              v_inerc = v_inerc - v_force;
              if ( v_inerc < -20.0 )
                v_inerc = -20.0;
            }
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v90 = 3.0;
LABEL_270:
            char_h_move(v90);
            v92 = 22.5;
            goto LABEL_271;
          case 212:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_255;
            if ( char_on_ground_flag() || v_inerc > 0.0 )
              field_522 = 2;
            if ( get_subseq() > 0 )
            {
              v_inerc = v_inerc - v_force;
              if ( v_inerc < -20.0 )
                v_inerc = -20.0;
            }
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
            process();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              v95 = 12.0;
LABEL_290:
              char_h_move(v95);
              v92 = 18.0;
LABEL_271:
              v_inerc = v92;
              v_force = 0.85000002;
              field_49A = 0;
              scene_add_effect(this, 63, x, y, dir, 1);
            }
            return;
          case 214:
            if ( process() )
              goto LABEL_343;
            if ( get_elaps_frames() )
              goto LABEL_352;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 6 )
              goto LABEL_343;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              scene_play_sfx(31);
LABEL_352:
            if ( (dY() < 0) | (dY() == 0) )
            {
              if ( dY() < 0 )
                if ( dX(dir) <= 0 )
                  field_7D2 = dX(dir) >= 0 ? 90 : 135;
                else
                  field_7D2 = 45;
              else
              {
                if ( dX(dir) <= 0 )
                {
                  if ( dX(dir) < 0 )
                    field_7D2 = 180;
                }
                else
                {
                  field_7D2 = 0;
                }
              }
            }
            else
            {
              if ( dX(dir) <= 0 )
                field_7D2 = dX(dir) >= 0 ? -90 : -135;
              else
                field_7D2 = -45;
            }
            if ( get_subseq() == 5 || get_subseq() == 6 )
              v_inerc = v_inerc - v_force;
            if ( get_subseq() <= 0 || get_subseq() >= 5 )
              goto LABEL_2963;
            ++field_7D6;
            field_7D4 = field_7D2 - dash_angle;
            if ( field_7D4 > 180 )
              field_7D4 = field_7D4 - 360;
            if ( field_7D4 < -180 )
              field_7D4 = field_7D4 + 360;
            if ( field_7D4 > 0 )
            {
              if ( weather_id )
                dash_angle = dash_angle + 1.0;
              else
                dash_angle = dash_angle + 2.0;
            }
            if ( field_7D4 < 0 )
            {
              if ( weather_id )
                dash_angle = dash_angle - 1.0;
              else
                dash_angle = dash_angle - 2.0;
            }
            h_inerc = cos_deg(dash_angle) * field_7DC;
            v_inerc = sin_deg(dash_angle) * field_7DC;
            if ( y > 680.0 && v_inerc > 0.0 )
              v_inerc = 0.0;
            field_7DC = field_7DC + 0.300000011920929;
            if ( field_7DC > 12.0 )
              field_7DC = 12.0;
            if ( weather_id )
              spell_energy_spend(10, 1);
            else
              spell_energy_spend(5, 1);
            angZ = -dash_angle;
            if ( h_inerc < 0.0 )
              angZ = 180.0 - dash_angle;
            if ( h_inerc < 0.0 && get_subseq() == 1 )
            {
              set_subseq(3);
            }
            if ( 0.0 <= h_inerc && get_subseq() == 3 )
            {
              set_subseq(1);
            }
            if ( 0.0 > h_inerc && get_subseq() == 2 )
            {
              set_subseq(4);
            }
            if ( 0.0 <= h_inerc && get_subseq() == 4 )
              set_subseq(2);
            if ( get_elaps_frames() % 5 == 1 )
            {
              scene_add_effect(this, 125, cos_deg(dash_angle) * 100.0 * (double)dir + x, sin_deg(dash_angle) * 100.0 + y + 100.0, dir, 1);
            }
            if ( ((keyDown(INP_D)) != 0 || field_7D6 <= 10) && spell_energy > 0 || (keyDown(INP_D) || field_7D6 <= 10) && spell_energy > 0 )
            {
LABEL_2963:
              if ( !char_on_ground_down() )
                return;
              y = getlvl_height();
              v_inerc = 0.0;
              v_force = 0.0;
              if ( get_subseq() >= 5 )
              {
                set_seq(10);
                reset_forces();
                return;
              }
              goto LABEL_431;
            }
            reset_ofs();
            if ( get_subseq() == 1 || get_subseq() == 2 )
            {
              if ( dir == 1 )
              {
                if ( enemy->x >= x )
                {
                  set_subseq(5);
                }
                else
                {
                  dir = -1;
                  h_inerc = -h_inerc;
                  set_subseq(6);
                }
              }
              else if ( enemy->x <= x )
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
            if ( get_subseq() != 3 && get_subseq() != 4 )
              return;
            if ( dir != 1 )
              goto LABEL_512;
            goto LABEL_425;
          case 215:
            sub10func();
            if ( h_inerc > 0.0 )
            {
              h_inerc = h_inerc - 0.75;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( h_inerc < 0.0 )
            {
              h_inerc = h_inerc + 0.75;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
            }
            goto LABEL_439;
          case 217:
            if ( process() )
              goto LABEL_771;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              scene_play_sfx(31);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
              goto LABEL_771;
            field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
            if ( get_subseq() == 5 || get_subseq() == 6 )
              v_inerc = v_inerc - v_force;
            if ( get_subseq() <= 0 || get_subseq() >= 5 )
              goto LABEL_2964;
            ++field_7D6;
            field_7D4 = field_7D2 - dash_angle;
            if ( field_7D4 > 180 )
              field_7D4 = field_7D4 - 360;
            if ( field_7D4 < -180 )
              field_7D4 = field_7D4 + 360;
            if ( field_7D4 > 0 )
            {
              if ( weather_id )
                dash_angle = dash_angle + 0.5;
              else
                dash_angle = dash_angle + 1.0;
            }
            if ( field_7D4 < 0 )
            {
              if ( weather_id )
                dash_angle = dash_angle - 0.5;
              else
                dash_angle = dash_angle - 1.0;
            }
            h_inerc = cos_deg(dash_angle) * field_7DC;
            v_inerc = sin_deg(dash_angle) * field_7DC;
            if ( y > 680.0 && v_inerc > 0.0 )
              v_inerc = 0.0;
            field_7DC = field_7DC + 0.300000011920929;
            if ( field_7DC > 12.0 )
              field_7DC = 12.0;
            if ( weather_id )
              spell_energy_spend(15, 60);
            else
              spell_energy_spend(10, 1);
            angZ = -dash_angle;
            if ( h_inerc < 0.0 )
              angZ = 180.0 - dash_angle;
            if ( h_inerc < 0.0 && get_subseq() == 1 )
            {
              set_subseq(3);
            }
            if ( 0.0 <= h_inerc && get_subseq() == 3 )
            {
              set_subseq(1);
            }
            if ( 0.0 > h_inerc && get_subseq() == 2 )
            {
              set_subseq(4);
            }
            if ( 0.0 <= h_inerc && get_subseq() == 4 )
              set_subseq(2);
            if ( get_elaps_frames() % 5 == 1 )
            {
              scene_add_effect(this, 125, cos_deg(dash_angle) * 100.0 * (double)dir + x, sin_deg(dash_angle) * 100.0 + y + 100.0, dir, 1);
            }
            if ( ((keyDown(INP_D)) != 0 || field_7D6 <= 20) && spell_energy > 0 || (keyDown(INP_D) || field_7D6 <= 20) && spell_energy > 0 )
            {
LABEL_2964:
              if ( char_on_ground_down() )
              {
                y = getlvl_height();
                v_force = 0.0;
                v_inerc = 0.0;
                if ( get_subseq() < 5 )
                {
LABEL_431:
                  reset_ofs();
                  set_seq(215);
                }
                else
                {
                  set_seq(10);
                  reset_forces();
                }
              }
            }
            else
            {
              reset_ofs();
              if ( get_subseq() == 1 || get_subseq() == 2 )
              {
                if ( dir == 1 )
                {
                  if ( enemy->x >= x )
                  {
                    set_subseq(5);
                  }
                  else
                  {
                    dir = -1;
                    h_inerc = -h_inerc;
                    set_subseq(6);
                  }
                }
                else if ( enemy->x <= x )
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
              if ( get_subseq() == 3 || get_subseq() == 4 )
              {
                if ( dir == 1 )
                {
LABEL_425:
                  if ( enemy->x >= x )
                  {
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
LABEL_512:
                  if ( enemy->x <= x )
                  {
                    set_subseq(6);
                  }
                  else
                  {
                    dir = -dir;
                    h_inerc = -h_inerc;
                    set_subseq(5);
                  }
                }
              }
            }
            return;
          case 220:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
            {
              set_seq(10);
              goto LABEL_106;
            }
            if ( char_on_ground_flag() || v_inerc > 0.0 )
              field_522 = 2;
            if ( get_subseq() > 0 )
            {
              v_inerc = v_inerc - v_force;
              if ( v_inerc < -20.0 )
                v_inerc = -20.0;
            }
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
            process();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(0.0);
              v_inerc = 22.5;
              v_force = 0.85000002;
              field_49A = 0;
              scene_add_effect(this, 63, x, y, dir, 1);
            }
            break;
          case 223:
            sub10func();
            field_49A = 1;
            process();
            if ( get_subseq() != 1 )
              goto LABEL_2965;
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            if ( ((++field_7D0, v166 = field_7D0, dX(dir) > 0) || v166 <= 15) && v166 <= 45 )
            {
LABEL_2965:
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                char_h_move(7.0);
                scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
                scene_add_effect(this, 126, x, y + 80.0, dir, 1);
                scene_play_sfx(31);
              }
            }
            else
            {
              set_seq(204);
            }
            return;
          case 224:
            if ( !get_subseq() || get_subseq() == 3 )
            {
              sub10func();
              
            }
            if ( get_subseq() == 3 )
            {
              h_inerc = h_inerc + 2.0;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
            }
            if ( !char_on_ground_flag() && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            if ( get_subseq() < 3 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
            {
LABEL_211:
              v_inerc = 0.0;
              y = getlvl_height();
              set_subseq(3);
            }
            else if ( process() )
            {
LABEL_213:
              set_seq(0);
              h_inerc = 0.0;
            }
            else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_7D0 )
            {
              field_7D0 = 1;
              char_h_move(-17.0);
              v_inerc = 4.0;
              v_force = 0.75;
              scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
              scene_play_sfx(31);
            }
            return;
          case 225:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_221;
            if ( get_subseq() == 2 && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            if ( process() )
              set_seq(9);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(-12.0);
              v_inerc = 4.0;
              v_force = 0.44999999;
              scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
              scene_play_sfx(31);
            }
            return;
          case 226:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_221:
              reset_forces();
              y = getlvl_height();
              set_seq(10);
            }
            else
            {
              if ( get_subseq() == 1 && !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
              }
              if ( process() )
                set_seq(9);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  field_7D0 = 0;
                  char_h_move(12.0);
                  v_inerc = 4.0;
                  v_force = 0.44999999;
                  scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
                  scene_add_effect(this, 126, x, y + 110.0, dir, 1);
                  scene_play_sfx(31);
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                  flip_with_force();
              }
            }
            return;
          default:
            goto LABEL_2960;
        }
      }
      return;
    }
    if ( get_seq() <= 500 )
    {
      if ( get_seq() == 500 )
      {
        sub10func();
        field_18C = 0;
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
        {
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            play_sfx(4);
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            t[0] = 0.0;
            t[1] = 25.0;
            t[2] = 0.0;
            if ( skills_1[0] >= 2 )
              t[2] = 4.0;
            if ( skills_1[0] >= 3 )
              t[2] = 5.0;
            addbullet(this, NULL, 810, (double)(60 * (char)dir) + x, y, dir, 1, t, 3);
          }
        }
        else
        {
LABEL_440:
          set_seq(0);
        }
      }
      else
      {
        switch ( get_seq() )
        {
          case 301:
            sub10func();
            if ( false /*get_true(0)*/)
              return;
            if ( field_49A )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
              {
                h_inerc = 0.0;
                field_49A = 0;
              }
            }
            if ( process() )
              set_seq(0);
            goto LABEL_610;
          case 302:
            sub10func();
            if ( false /*get_true(1)*/)
              return;
            if ( get_frame() < 4 && !keyDown(INP_A) )
              not_charge_attack = 0;
            if ( !get_subseq() )
            {
              if ( h_inerc > 0.0 )
                h_inerc = h_inerc - 1.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
              if ( !get_frame_time() && get_frame() == 4 )
                h_inerc = 15.5;
            }
            if ( get_subseq() == 1 )
            {
              if ( h_inerc > 0.0 ) //condition reversed (old: <= )
              {
                h_inerc = h_inerc - 1.5;
              }
              if ( 0.0 > h_inerc )
                h_inerc = 0.0;
              if ( !get_frame_time() && get_frame() == 1 )
                h_inerc = 17.5;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(0);
            if ( get_subseq() || get_frame_time() )
              goto LABEL_653;
            if ( get_frame() == 4 && not_charge_attack == 1 )
            {
              scene_add_effect(this, 62, (double)(7 * (char)dir) + x, y + 180.0, dir, 1);
              goto LABEL_650;
            }
            if ( get_frame() == 6 )
              scene_play_sfx(29);
LABEL_653:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
              scene_play_sfx(29);
            return;
          case 303:
            sub10func();
            if ( true /*!get_true(0)*/)
            {
              if ( field_49A > 0 )
              {
                h_inerc = h_inerc - 0.6000000238418579;
                if ( h_inerc < 0.0 )
                {
                  h_inerc = 0.0;
                  field_49A = 0;
                }
              }
              if ( process() )
                set_seq(2);
              if ( !get_frame_time() && get_frame() == 2 )
                scene_play_sfx(27);
            }
            return;
          case 304:
            sub10func();
            if ( false /*get_true(1)*/)
              return;
            if ( get_frame() < 4 && !keyDown(INP_A) )
              not_charge_attack = 0;
            if ( process() || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
LABEL_50:
              set_seq(2);
              return;
            }
            if ( get_subseq() )
              goto LABEL_688;
            if ( get_frame_time() || get_frame() != 3 )
              goto LABEL_681;
            if ( not_charge_attack == 1 )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)((char)dir << 6) + x, y + 108.0, dir, 1);
              return;
            }
            h_inerc = 10.0;
            scene_play_sfx(29);
LABEL_681:
            if ( get_frame_time() )
              goto LABEL_684;
            /*
            v216 = __OFSUB__(get_frame(), 5);
            v215 = (get_frame() - 5) < 0;
            */
            if ( get_frame() == 5 )
            {
              h_inerc = 5.0;
            }
            /*
LABEL_684:
              v216 = __OFSUB__(get_frame(), 5);
              v215 = (get_frame() - 5) < 0;
            }////
            if ( v215 ^ v216 )
            {
LABEL_688:
              v218 = 0.0;
            }
            else
            {
              v217 = h_inerc - 0.75;
              h_inerc = v217;
              v218 = 0.0;
              if ( v217 < 0.0 )
                h_inerc = 0.0;
            }
            */
            LABEL_684:// TODO: change
            LABEL_688:// TODO: change
            if ( get_subseq() != 1 )
              return;
            if ( get_frame_time() )
              goto LABEL_696;
            if ( get_frame() == 1 )
            {
              h_inerc = 15.0;
              scene_play_sfx(29);
            }
            if ( get_frame_time() )
              goto LABEL_696;
            /*
            v220 = __OFSUB__(get_frame(), 3);
            v219 = (get_frame() - 3) < 0;
            if ( get_frame() == 3 )
            {
              h_inerc = 10.0;
LABEL_696:
              v220 = __OFSUB__(get_frame(), 3);
              v219 = (get_frame() - 3) < 0;
            }
            if ( !(v219 ^ v220) )
            {
              v221 = h_inerc - 0.75;
              h_inerc = v221;
              if ( v221 < 0.0 )
                h_inerc = 0.0;
            }*/
            LABEL_696://TODO: change
            return;
          case 305:
            sub10func();
            if ( true /*!get_true(1)*/)
            {
              h_inerc = h_inerc - 0.75;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
              if ( process() )
                set_seq(0);
              if ( !get_frame_time() && get_frame() == 3 )
                scene_play_sfx(28);
            }
            return;
          case 306:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_255;
            if ( process() )
              set_seq(9);
            if ( !get_frame_time() && get_frame() == 2 )
              scene_play_sfx(28);
            return;
          case 307:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_255:
              set_seq(10);
              goto LABEL_106;
            }
            if ( process() )
              set_seq(9);
            if ( get_frame() > 2 && get_frame() < 8 )
            {
              set_vec_speed(-20.0, field_7DC);
              field_7DC = field_7DC - 1.5;
              if ( field_7DC < 6.0 )
                field_7EC = 6.0;
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
                scene_play_sfx(29);
              if ( !get_frame_time() && get_frame() == 8 )
                v_force = 0.60000002;
            }
            return;
          case 308:
            v227 = 2;
            if ( get_subseq() == 2 )
              sub10func();
            if ( char_on_ground_down() && get_subseq() < 2 )
              goto LABEL_731;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              play_sfx(14);
              h_inerc = 6.0;
              v_inerc = -18.0;
            }
            return;
          case 309:
            if ( !get_subseq() )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_104:
                move_val = 10;
                set_seq(move_val);
                break;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                scene_play_sfx(29);
                v_inerc = 7.5;
                v_force = 0.75;
              }
              if ( !get_frame_time() && get_frame() == 7 )
                v_force = 0.5;
            }
            return;
          case 310:
            if ( field_190 )
            {
              if ( ++field_7D0 > 5 )
              {
                field_190 = 0;
                field_7D0 = 0;
              }
            }
            if ( get_subseq() == 1 )
            {
              if ( !get_elaps_frames() )
                h_inerc = 15.0;
              if ( !(get_elaps_frames() % 8) )
                scene_play_sfx(27);
              if ( field_190 )
              {
                if ( ++field_7D0 > 5 )
                {
                  field_190 = 0;
                  field_7D0 = 0;
                }
              }
              if ( get_elaps_frames() > 30 )
              {
                next_subseq();
                v_inerc = 6.0;
                h_inerc = h_inerc * 0.5;
              }
            }
            if ( get_subseq() != 2 || (v228 = v_inerc - v_force, v_inerc = v228, v229 = v228 + y, getlvl_height() < v229) || v_inerc >= 0.0 )
            {
              if ( process() )
                set_seq(9);
            }
            else
            {
              v_inerc = 0.0;
              y = getlvl_height();
LABEL_771:
              set_seq(9);
            }
            return;
          case 320:
            sub10func();
            if ( false /*get_true(0)*/)
              return;
            if ( field_49A )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
              {
                h_inerc = 0.0;
                field_49A = 0;
              }
            }
            if ( process() )
              set_seq(0);
            goto LABEL_601;
          case 321:
            sub10func();
            if ( false /*get_true(0)*/)
              return;
            if ( field_49A )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
              {
                h_inerc = 0.0;
                field_49A = 0;
              }
            }
            if ( process() )
              set_seq(0);
LABEL_610:
            if ( get_frame_time() )
              goto LABEL_613;
            /*
            v202 = __OFSUB__(get_frame(), 3);
            v200 = get_frame() == 3;
            v201 = (get_frame() - 3) < 0;
            */
            if ( get_frame() == 3 )
            {
              h_inerc = 10.0;
              scene_play_sfx(28);
              field_49A = 0;
            }
            /*
LABEL_613:
              v202 = __OFSUB__(get_frame(), 3);
              v200 = get_frame() == 3;
              v201 = (get_frame() - 3) < 0;
            }////
            if ( !((v201 ^ v202) | v200) )
            {
              v203 = h_inerc - 1.0;
              h_inerc = v203;
              
              if ( v203 < 0.0 )
                goto LABEL_616;
            }
            */
            LABEL_613://TODO: change
            return;
          case 322:
            sub10func();
            if ( true /*!get_true(1)*/)
            {
              if ( !get_subseq() )
              {
                if ( h_inerc > 0.0 )
                  h_inerc = h_inerc - 1.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 4 )
                    h_inerc = 15.5;
                  if ( !get_frame_time() && get_frame() == 6 )
                    scene_play_sfx(29);
                }
              }
LABEL_439:
              if ( process() )
                goto LABEL_440;
            }
            return;
          case 330:
            goto LABEL_595;
          case 400:
            sub10func();
            if ( get_subseq() < 2 && !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_440;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_818;
            if ( get_frame() == 3 && not_charge_attack == 1 )
            {
              next_subseq();
              scene_add_effect(this, 62, x + 0.0, y + 216.0, dir, 1);
              return;
            }
            if ( get_frame() == 4 )
            {
              add_card_energy(10);
              field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7D4 < -10 )
                field_7D4 = -10;
              if ( field_7D4 > 10 )
                field_7D4 = 10;
              sub_486FD0(20.0, -20.0);
              spell_energy_spend(200, 45);
              field_190 = 1;
              t[0] = field_7F0;
              t[1] = 20.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(83 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
              play_sfx(0);
            }
LABEL_818:
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            add_card_energy(30);
            field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7D4 < -10 )
              field_7D4 = -10;
            if ( field_7D4 > 10 )
              field_7D4 = 10;
            sub_486FD0(20.0, -20.0);
            spell_energy_spend(200, 45);
            field_190 = 1;
            t[0] = field_7F0;
            t[1] = 20.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(83 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
            t[0] = field_7F0 + 15.0;
            t[1] = 20.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(83 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
            t[0] = field_7F0 - 15.0;
            t[1] = 20.0;
            t[2] = 0.0;
            x = dir;
            a4 = y + 126.0;
            v259 = (double)(83 * (char)x) + x;
            goto LABEL_826;
          case 401:
            sub10func();
            if ( get_subseq() < 2 && !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_440;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_847;
            if ( get_frame() == 3 && not_charge_attack == 1 )
            {
              next_subseq();
              scene_add_effect(this, 62, x + 0.0, y + 216.0, dir, 1);
              return;
            }
            if ( get_frame() == 4 )
            {
              field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7D4 < -60 )
                field_7D4 = -60;
              if ( field_7D4 > -30 )
                field_7D4 = -30;
              spell_energy_spend(200, 45);
              field_190 = 1;
              add_card_energy(10);
              t[0] = (double)field_7D4;
              t[1] = 20.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(83 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
              play_sfx(0);
            }
LABEL_847:
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7D4 > -30 )
              field_7D4 = -30;
            if ( field_7D4 < -60 )
              field_7D4 = -60;
            sub_486FD0(-30.0, -70.0);
            spell_energy_spend(200, 45);
            field_190 = 1;
            add_card_energy(30);
            t[0] = field_7F0;
            t[1] = 20.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(83 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
            t[0] = field_7F0 + 15.0;
            t[1] = 20.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(83 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
            t[0] = field_7F0 - 15.0;
            t[1] = 20.0;
            t[2] = 0.0;
            x = dir;
            a4 = y + 126.0;
            v259 = (double)(83 * (char)x) + x;
            goto LABEL_826;
          case 402:
            sub10func();
            if ( process() )
              set_seq(2);
            if ( !get_frame_time() && get_frame() == 4 )
            {
              play_sfx(1);
              add_card_energy(30);
              field_190 = 1;
              spell_energy_spend(200, 45);
              t[0] = 0.0;
              t[1] = 20.0;
              t[2] = 0.0;
              addbullet(this, NULL, 807, (double)(100 * (char)dir) + x, y + 70.0, dir, 1, t, 3);
            }
            return;
          case 404:
          /*
            v293 = __OFSUB__(get_subseq(), 2);
            v292 = (get_subseq() - 2) < 0;
            */
            if ( get_subseq() == 2 )
            {
              sub10func();
              /*
              v293 = __OFSUB__(get_subseq(), 2);
              v292 = (get_subseq() - 2) < 0;
              */
            }
            /*
            if ( v292 ^ v293 && !keyDown(INP_B) )
              not_charge_attack = 0;
              */
            if ( !keyDown(INP_B))
              not_charge_attack = 0;
            if ( !get_subseq() && get_frame() > 6 || get_subseq() == 1 && get_frame() > 4 )
              v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
            {
              set_subseq(2);
              goto LABEL_106;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_954;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_893;
            if ( get_frame() == 3 && not_charge_attack == 1 )
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(14 * (char)dir), y + 226.0, dir, 1);
              return;
            }
            if ( get_frame() == 4 )
            {
              field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7D4 < -10 )
                field_7D4 = -10;
              if ( field_7D4 > 10 )
                field_7D4 = 10;
              sub_486FD0(20.0, -20.0);
              spell_energy_spend(200, 45);
              field_190 = 1;
              add_card_energy(10);
              t[0] = field_7F0;
              t[1] = 20.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
              play_sfx(0);
            }
LABEL_893:
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7D4 < -10 )
              field_7D4 = -10;
            if ( field_7D4 > 10 )
              field_7D4 = 10;
            sub_486FD0(20.0, -20.0);
            spell_energy_spend(200, 45);
            field_190 = 1;
            add_card_energy(30);
            t[0] = field_7F0;
            t[1] = 20.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
            t[0] = field_7F0 + 15.0;
            t[1] = 20.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
            t[0] = field_7F0 - 15.0;
            t[1] = 20.0;
            t[2] = 0.0;
            x = dir;
            a4 = y + 126.0;
            v259 = (double)(70 * (char)x) + x;
            goto LABEL_826;
          case 406:
            v323 = 2;
            /*
            v325 = __OFSUB__(get_subseq(), 2);
            v324 = (get_subseq() - 2) < 0;
            */
            if ( get_subseq() == 2 )
            {
              sub10func();
              /*
              v325 = __OFSUB__(get_subseq(), 2);
              v324 = ;
              */
            }
            /*
            if ( v324 ^ v325 && !keyDown(INP_B) )
              not_charge_attack = 0;
            */
            if ( !keyDown(INP_B))
              not_charge_attack = 0;
            if ( !get_subseq() && get_frame() > 6 || get_subseq() == 1 && get_frame() > 4 )
              v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
              goto LABEL_913;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_954;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_934;
            if ( get_frame() != 3 || not_charge_attack != 1 )
            {
              if ( get_frame() == 4 )
              {
                field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7D4 < 20 )
                  field_7D4 = 20;
                if ( field_7D4 > 40 )
                  field_7D4 = 40;
                sub_486FD0(60.0, 20.0);
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(10);
                t[0] = field_7F0;
                t[1] = 20.0;
                t[2] = 0.0;
                addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
                play_sfx(0);
              }
LABEL_934:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
              {
                field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7D4 < 20 )
                  field_7D4 = 20;
                if ( field_7D4 > 40 )
                  field_7D4 = 40;
                sub_486FD0(60.0, 20.0);
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(30);
                t[0] = field_7F0;
                t[1] = 20.0;
                t[2] = 0.0;
                addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
                t[0] = field_7F0 + 15.0;
                t[1] = 20.0;
                t[2] = 0.0;
                addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 126.0, dir, 1, t, 3);
                t[0] = field_7F0 - 15.0;
                t[1] = 20.0;
                t[2] = 0.0;
                x = dir;
                a4 = y + 126.0;
                v259 = (double)(70 * (char)x) + x;
LABEL_826:
                addbullet(this, NULL, 800, v259, a4, x, 1, t, 3);
                play_sfx(0);
              }
            }
            else
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(14 * (char)dir), y + 226.0, dir, 1);
            }
            return;
          case 408:
            sub10func();
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 6 )
              scene_play_sfx(29);
            return;
          case 409:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_950;
            if ( process() )
              goto LABEL_954;
            return;
          case 410:
            sub10func();
            if ( get_subseq() < 2 && !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            {
              if ( !get_subseq() && !get_frame_time() )
              {
                if ( get_frame() == 2 && not_charge_attack == 1 )
                {
                  next_subseq();
                  scene_add_effect(this, 62, (double)(12 * (char)dir) + x, y + 172.0, dir, 1);
                }
                if ( !get_frame_time() && get_frame() == 4 )
                {
                  spell_energy_spend(200, 60);
                  field_190 = 1;
                  add_card_energy(50);
                  play_sfx(2);
                  t[0] = -40.0;
                  t[1] = 4.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 801, (double)(110 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                }
              }
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
              {
                spell_energy_spend(200, 60);
                field_190 = 1;
                add_card_energy(50);
                field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7D4 < -10 )
                  field_7D4 = -10;
                if ( field_7D4 > 10 )
                  field_7D4 = 10;
                play_sfx(2);
                t[0] = 50.0;
                t[1] = -4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 801, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
                t[0] = -50.0;
                t[1] = 4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 801, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
              }
            }
            else
            {
              set_seq(0);
            }
            return;
          case 411:
            sub10func();
            if ( get_subseq() < 2 && !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            {
              if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
              {
                spell_energy_spend(200, 60);
                field_190 = 1;
                add_card_energy(50);
                play_sfx(3);
                t[0] = 0.0;
                t[1] = 25.0;
                t[2] = 0.0;
                addbullet(this, NULL, 804, (double)(110 * dir) + x, y, dir, 1, t, 3);
              }
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
              {
                spell_energy_spend(200, 60);
                field_190 = 1;
                add_card_energy(50);
                play_sfx(3);
                t[0] = 0.0;
                t[1] = 25.0;
                t[2] = 0.0;
                addbullet(this, NULL, 804, (double)(110 * dir) + x, y, dir, 1, t, 3);
              }
            }
            else
            {
              set_seq(0);
            }
            return;
          case 412:
            sub10func();
            if ( get_subseq() < 2 && !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            {
              if ( !get_subseq() && !get_frame_time() )
              {
                if ( get_frame() == 2 && not_charge_attack == 1 )
                {
                  next_subseq();
                  scene_add_effect(this, 62, (double)(12 * (char)dir) + x, y + 172.0, dir, 1);
                }
                if ( !get_frame_time() && get_frame() == 4 )
                {
                  spell_energy_spend(200, 60);
                  field_190 = 1;
                  add_card_energy(50);
                  play_sfx(2);
                  t[0] = 40.0;
                  t[1] = -4.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 801, (double)(110 * (char)dir) + x, y + 50.0, dir, 1, t, 3);
                }
              }
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
              {
                spell_energy_spend(200, 60);
                field_190 = 1;
                add_card_energy(50);
                field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7D4 < -10 )
                  field_7D4 = -10;
                if ( field_7D4 > 10 )
                  field_7D4 = 10;
                play_sfx(2);
                t[0] = 50.0;
                t[1] = -4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 801, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
                t[0] = -50.0;
                t[1] = 4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 801, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
              }
            }
            else
            {
              set_seq(0);
            }
            return;
          case 414:
            if ( get_subseq() == 2 )
              sub10func();
            if ( get_subseq() < 2 )
            {
              if ( !get_subseq() && get_frame() > 8 || get_subseq() == 1 && get_frame() > 5 )
                v_inerc = v_inerc - v_force;
              if ( !keyDown(INP_C) )
                not_charge_attack = 0;
              if ( char_on_ground_down() )
              {
                set_subseq(2);
                goto LABEL_951;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_954;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 && not_charge_attack == 1 )
              {
                next_subseq();
                scene_add_effect(this, 62, (double)(7 * (char)dir) + x, y + 187.0, dir, 1);
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                spell_energy_spend(200, 60);
                field_190 = 1;
                add_card_energy(50);
                play_sfx(2);
                t[0] = -50.0;
                t[1] = 4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 801, (double)(110 * (char)dir) + x, y + 156.0, dir, 1, t, 3);
              }
            }
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
            {
              spell_energy_spend(200, 60);
              field_190 = 1;
              add_card_energy(50);
              field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7D4 < -10 )
                field_7D4 = -10;
              if ( field_7D4 > 10 )
                field_7D4 = 10;
              play_sfx(2);
              t[0] = 50.0;
              t[1] = -4.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
              t[0] = -50.0;
              t[1] = 4.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
            }
            return;
          case 415:
            if ( get_subseq() == 2 )
              sub10func();
            if ( get_subseq() < 2 )
            {
              if ( !get_subseq() && get_frame() > 8 || get_subseq() == 1 && get_frame() > 5 )
                v_inerc = v_inerc - v_force;
              if ( !keyDown(INP_C) )
                not_charge_attack = 0;
              if ( char_on_ground_down() )
              {
                set_subseq(2);
                goto LABEL_951;
              }
            }
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_1083;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_954;
            if ( get_frame_time() )
              return;
            if ( !get_frame() && get_subseq() == 2 )
              goto LABEL_954;
LABEL_1083:
            if ( !get_frame_time() && get_frame() == 6 )
            {
              spell_energy_spend(200, 60);
              field_190 = 1;
              add_card_energy(50);
              play_sfx(3);
              t[0] = 0.0;
              t[1] = 25.0;
              t[2] = 0.0;
              addbullet(this, NULL, 804, (double)(110 * dir) + x, y, dir, 1, t, 3);
            }
            return;
          case 416:
            if ( get_subseq() == 2 )
              sub10func();
            if ( get_subseq() < 2 )
            {
              if ( !get_subseq() && get_frame() > 8 || get_subseq() == 1 && get_frame() > 5 )
                v_inerc = v_inerc - v_force;
              if ( !keyDown(INP_C) )
                not_charge_attack = 0;
              if ( char_on_ground_down() )
              {
                set_subseq(2);
                goto LABEL_951;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_954;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 && not_charge_attack == 1 )
              {
                next_subseq();
                scene_add_effect(this, 62, (double)(7 * (char)dir) + x, y + 187.0, dir, 1);
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                spell_energy_spend(200, 60);
                field_190 = 1;
                add_card_energy(50);
                play_sfx(2);
                t[0] = 50.0;
                t[1] = -4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 801, (double)(110 * (char)dir) + x, y + 50.0, dir, 1, t, 3);
              }
            }
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
            {
              spell_energy_spend(200, 60);
              field_190 = 1;
              add_card_energy(50);
              field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7D4 < -10 )
                field_7D4 = -10;
              if ( field_7D4 > 10 )
                field_7D4 = 10;
              play_sfx(2);
              t[0] = 50.0;
              t[1] = -4.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
              t[0] = -50.0;
              t[1] = 4.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
            }
            break;
          case 418:
            if ( !get_subseq() && get_frame() <= 2 || get_subseq() == 2 )
              sub10func();
            if ( process() )
              set_seq(0);
            if ( get_subseq() >= 2 )
              goto LABEL_2966;
            if ( !get_subseq() )
            {
              if ( get_frame() < 3 )
              {
                h_inerc = h_inerc - 1.0;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( get_frame() > 2 && get_frame() < 9 )
              {
                set_vec_speed(-20.0, field_7DC);
                field_7DC = field_7DC - 1.5;
                if ( field_7DC < 6.0 )
                  field_7EC = 6.0;
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 4 )
                  scene_play_sfx(29);
                if ( !get_frame_time() && get_frame() == 9 )
                  v_force = 0.5;
              }
            }
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_subseq(2);
              y = getlvl_height();
              
              v_inerc = 0.0;
            }
LABEL_2966:            
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 2.0;
              if ( h_inerc < 0.0 )
LABEL_616:
                h_inerc = 0.0;
            }
            return;
          default:
            goto LABEL_2960;
        }
      }
      return;
    }
    if ( get_seq() > 770 )
    {
      switch ( get_seq() )
      {
        case 791:
          process();
          if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
            addbullet(this, NULL, 990, x, y, dir, 1, 0, 0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              dir = enemy->dir;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 997, x, y, dir, 1, t, 3);
              /*
              v1047 = 0;
              v1127 = 0;
              do
              {
                *(float *)&v1202 = (double)v1127 + 30.0;
                v1203 = 15.0;
                v1204 = 1.0;
                if ( *(float *)&v1202 < 0.0 || *(float *)&v1202 > 180.0 )
                  addbullet(this, NULL, 821, x, y, dir, -1, (int)&v1202, 3);
                else
                  addbullet(this, NULL, 821, x, y, dir, 1, (int)&v1202, 3);
                v1047 += 60;
                v1127 = v1047;
              }
              while ( v1047 < 360 );
              */
              play_sfx(5);
            }
          }
          return;
        case 795:
          if ( get_subseq() )
            goto LABEL_2938;
          v_inerc = v_inerc - 0.300000011920929;
          if ( !char_on_ground_down() )
            goto LABEL_2938;
          scene_play_sfx(30);
          move_val = 1;
          set_subseq(move_val);
          break;
        case 797:
          if ( char_on_ground_down() && get_subseq() < 2 )
          {
            x = 480.0;
            //shake_camera(5.0);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 821, x, y, dir, 1, t, 3);
            play_sfx(15);
            /*
            v1048 = 0;
            v1128 = 0;
            do
            {
              *(float *)&v1199 = (double)v1128 + 30.0;
              v1200 = 15.0;
              v1201 = 1.0;
              if ( *(float *)&v1199 < 0.0 || *(float *)&v1199 > 180.0 )
              {
                yd = -1;
                xn = dir;
              }
              else
              {
                yd = 1;
                xn = dir;
              }
              addbullet(this, NULL, 821, x, y, xn, yd, (int)&v1199, 3);
              v1048 += 60;
              v1128 = v1048;
            }
            while ( v1048 < 360 );
            */
            move_val = 2;
            set_subseq(move_val);
            break;
          }
          if ( process() )
            set_seq(0);
          return;
        case 798:
          if ( !char_on_ground_down() || get_subseq() >= 2 )
          {
LABEL_2938:
            if ( process() )
LABEL_2939:
              set_seq(700);
            return;
          }
          x = 800.0;
          //shake_camera(5.0);
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 821, x, y, dir, 1, t, 3);
          play_sfx(15);
          /*
          v1049 = 0;
          v1129 = 0;
          do
          {
            *(float *)&v1205 = (double)v1129 + 30.0;
            v1206 = 15.0;
            v1207 = 1.0;
            if ( *(float *)&v1205 < 0.0 || *(float *)&v1205 > 180.0 )
            {
              ye = -1;
              xo = dir;
            }
            else
            {
              ye = 1;
              xo = dir;
            }
            addbullet(this, NULL, 821, x, y, xo, ye, (int)&v1205, 3);
            v1049 += 60;
            v1129 = v1049;
          }
          while ( v1049 < 360 );
          */
          move_val = 2;
          set_subseq(move_val);
          break;
        default:
LABEL_2960:
          char_c::func10();
          return;
      }
LABEL_106:
      y = getlvl_height();
      reset_forces();
      return;
    }
    if ( get_seq() == 770 )
    {
      if ( process() )
        set_seq(700);
      if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
      {
        field_6F5 = 1;
        sub_4685C0(-1);
        sub_46AB50(2, -1);
        health_to_max();
        field_820 = 0;
        field_81E = 1;
        field_81A = 0;
        field_81C = 0;
        field_818 = 0;
        scene_play_sfx(23);
      }
    }
    else
    {
      switch ( get_seq() )
      {
        case 502:
          if ( get_subseq() == 1 )
            sub10func();
          field_18C = 0;
          if ( !get_subseq() )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1171;
          }
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          {
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              play_sfx(4);
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              h_inerc = -4.0;
              v_inerc = 6.0;
              v_force = 0.5;
              t[0] = 60.0;
              t[1] = 20.0;
              t[2] = 1.0;
              addbullet(this, NULL, 810, (double)(53 * (char)dir) + x, y + 76.0, dir, 1, t, 3);
            }
          }
          else
          {
LABEL_343:
            set_seq(9);
          }
          return;
        case 505:
          sub10func();
          field_18C = 4;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_440;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            play_sfx(14);
            spell_energy_spend(200, 120);
            field_190 = 1;
            add_card_energy(50);
            v461 = 4;
            if ( skills_1[4] < 4 )
              v461 = y;
            if ( skills_1[4] <= 3 )
              v461 = 3;
            if ( skills_1[4] <= 1 )
              v461 = 2;
            /*
            if ( v461 > 0 )
            {
              v1094 = 0;
              do
              {
                *(float *)&v1290 = (double)v1094 + 20.0;
                v1291 = 25.0;
                v1292 = 0.0;
                v462 = dir;
                v463 = -*(float *)&v1290;
                v464 = sin_deg(v463) * 100.0 + y + 100.0;
                v465 = v464;
                v466 = -*(float *)&v1290;
                v467 = (cos_deg(v466) * 100.0 + 100.0) * (double)dir + x;
                addbullet(this, NULL, 811, v467, v465, v462, 1, (int)&v1290, 3);
                v1094 -= 20;
                --v461;
              }
              while ( v461 );
            }*/
          }
          return;
        case 506:
          sub10func();
          field_18C = 4;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_440;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            play_sfx(14);
            spell_energy_spend(200, 120);
            field_190 = 1;
            add_card_energy(50);
            v469 = 4;
            if ( skills_1[4] < 4 )
              v469 = y;
            if ( skills_1[4] <= 3 )
              v469 = 3;
            if ( skills_1[4] <= 1 )
              v469 = 2;
            /*
            if ( v469 > 0 )
            {
              v1095 = 0;
              do
              {
                *(float *)&v1268 = (double)v1095 - 30.0;
                v1269 = 25.0;
                v1270 = 0.0;
                v470 = dir;
                v471 = -*(float *)&v1268;
                v472 = sin_deg(v471) * 100.0 + y + 100.0;
                v473 = v472;
                v474 = -*(float *)&v1268;
                v475 = (cos_deg(v474) * 100.0 + 100.0) * (double)dir + x;
                addbullet(this, NULL, 811, v475, v473, v470, 1, (int)&v1268, 3);
                v1095 -= 20;
                --v469;
              }
              while ( v469 );
            }*/
          }
          return;
        case 507:
          v323 = 2;
          if ( get_subseq() == 2 )
            sub10func();
          field_18C = 4;
          if ( !get_subseq() )
          {
            if ( get_frame() >= 8 )
              v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_913;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_954;
          if ( get_subseq() || get_frame_time() )
            return;
          if ( get_frame() == 4 )
          {
            play_sfx(14);
            spell_energy_spend(200, 120);
            field_190 = 1;
            add_card_energy(50);
            v477 = 4;
            if ( skills_1[4] < 4 )
              v477 = y;
            if ( skills_1[4] <= 3 )
              v477 = 3;
            if ( skills_1[4] <= 1 )
              v477 = 2;
            /*
            if ( v477 > 0 )
            {
              v1096 = 0;
              do
              {
                *(float *)&v1283 = (double)v1096 + 20.0;
                v1284 = 25.0;
                v1285 = 0.0;
                v478 = dir;
                v479 = -*(float *)&v1283;
                v480 = sin_deg(v479) * 100.0 + y + 121.0;
                v481 = v480;
                v482 = -*(float *)&v1283;
                v483 = (cos_deg(v482) * 100.0 + 47.0) * (double)dir + x;
                addbullet(this, NULL, 811, v483, v481, v478, 1, (int)&v1283, 3);
                v1096 -= 20;
                --v477;
              }
              while ( v477 );
            }*/
          }
          goto LABEL_1247;
        case 508:
          v323 = 2;
          if ( get_subseq() == 2 )
            sub10func();
          field_18C = 4;
          if ( !get_subseq() )
          {
            if ( get_frame() >= 8 )
              v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_913;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_954;
          if ( get_subseq() || get_frame_time() )
            return;
          if ( get_frame() == 4 )
          {
            play_sfx(14);
            spell_energy_spend(200, 120);
            field_190 = 1;
            add_card_energy(50);
            v486 = 4;
            if ( skills_1[4] < 4 )
              v486 = y;
            if ( skills_1[4] <= 3 )
              v486 = 3;
            if ( skills_1[4] <= 1 )
              v486 = 2;
            /*
            if ( v486 > 0 )
            {
              v1097 = 0;
              do
              {
                *(float *)&v1274 = (double)v1097 + 30.0;
                v1275 = 25.0;
                v1276 = 0.0;
                v487 = dir;
                v488 = -*(float *)&v1274;
                v489 = sin_deg(v488) * 100.0 + y + 121.0;
                v490 = v489;
                v491 = -*(float *)&v1274;
                v492 = (cos_deg(v491) * 100.0 + 47.0) * (double)dir + x;
                addbullet(this, NULL, 811, v492, v490, v487, 1, (int)&v1274, 3);
                v1097 += 20;
                --v486;
              }
              while ( v486 );
            }*/
          }
LABEL_1247:
          if ( get_frame_time() )
            return;
          v484 = get_frame() == 8;
          goto LABEL_1249;
        case 510:
          sub10func();
          field_18C = 8;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_440;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
          {
            play_sfx(16);
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            tt[0] = 0.0;
            tt[1] = 0.0;
            tt[2] = 0.0;
            tt[3] = (double)(char)skills_1[8] + 3.0;
            addbullet(this, NULL, 812, (double)(275 * dir) + x, y, dir, 1, tt, 4);
            /*
            v1132 = 0.0;
            do
            {
              *(float *)&v1247 = (double)scene_rand_rng(10) + v1132 * 36.0 + 30.0;
              v1248 = 15.0;
              v1249 = 2.0;
              v494 = -*(float *)&v1247;
              v495 = sin_deg(v494) > 0.0;
              v496 = dir;
              v497 = (double)(375 * (char)v496) + x;
              addbullet(this, NULL, 812, v497, y, v496, (1 - 2 * v495), (int)&v1247, 3);
              v1132 = v1132 + 1.0;
            }
            while ( v1132 < 10.0 );*/
          }
          return;
        case 511:
          sub10func();
          field_18C = 8;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_64;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
          {
            play_sfx(16);
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            tt[0] = 0.0;
            tt[1] = 0.0;
            tt[2] = 0.0;
            tt[3] = (double)(char)skills_1[8] + 5.0;
            addbullet(this, NULL, 812, (double)(650 * (char)dir) + x, y, dir, 1, tt, 4);
            /*
            v1133 = 0.0;
            do
            {
              *(float *)&v1183 = (double)scene_rand_rng(10) + v1133 * 36.0 + 30.0;
              v1184 = 15.0;
              v1185 = 2.0;
              v500 = -*(float *)&v1183;
              v501 = sin_deg(v500) > 0.0;
              v502 = dir;
              v503 = (double)(650 * (char)v502) + x;
              addbullet(this, NULL, 812, v503, y, v502, (1 - 2 * v501), (int)&v1183, 3);
              v1133 = v1133 + 1.0;
            }
            while ( v1133 < 10.0 );
            v1134 = 0.0;
            do
            {
              *(float *)&v1183 = (double)scene_rand_rng(10) + v1134 * 36.0 + 30.0;
              v1184 = 15.0;
              v1185 = 2.0;
              v504 = -*(float *)&v1183;
              v505 = sin_deg(v504) > 0.0;
              addbullet(this, NULL, 812, x, y, dir, (1 - 2 * v505), (int)&v1183, 3);
              v1134 = v1134 + 1.0;
            }
            while ( v1134 < 10.0 );*/
          }
          return;
        case 520:
          if ( !get_subseq() || get_subseq() == 4 || get_subseq() == 5 )
          {
            sub10func();
            
          }
          field_18C = 1;
          if ( get_subseq() == 1 )
          {
            if ( field_190 == 2 || field_190 == 7 )
              goto LABEL_1312;
          }
          if ( get_subseq() != 2 && get_subseq() != 3 )
            goto LABEL_1321;
          h_inerc = h_inerc + 0.1500000059604645;
          if ( h_inerc > 0.0 )
            h_inerc = 0.0;
          v_inerc = v_inerc - 0.5;
          if ( char_on_ground_down() )
            goto LABEL_1319;
          
LABEL_1321:
          if ( get_subseq() == 4 )
          {
            h_inerc = h_inerc - 1.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 && skills_1[1] >= 1 )
            goto LABEL_1330;
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            goto LABEL_1337;
          //(NOTE: only the first index was there!)
          t[0] = 0.0; //only this, i added the other 2
          t[1] = 0.0; 
          t[2] = 0.0;
          addbullet(this, NULL, 815, x, y + 45.0, dir, 1, t, 1);
          scene_add_effect(this, 127, x, y, dir, -1);
          set_vec_speed(0.0, 25.0);
          spell_energy_spend(200, 120);
          add_card_energy(50);
          goto LABEL_1336;
        case 521:
          if ( !get_subseq() || get_subseq() == 6 )
          {
            sub10func();
          }
          field_18C = 1;
          if ( get_subseq() == 1 )
          {
            if ( field_190 == 2 || field_190 == 7 )
              goto LABEL_1312;
          }
          if ( get_subseq() == 2 )
            goto LABEL_1356;
          if ( get_subseq() == 3 || get_subseq() == 4 || get_subseq() == 5 )
          {
            if ( get_subseq() == 2 || get_subseq() == 3 )
            {
LABEL_1356:
              h_inerc = h_inerc + 0.1500000059604645;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
            }
            v_inerc = v_inerc - 0.5;
            if ( char_on_ground_down() )
            {
              set_subseq(6);
              goto LABEL_951;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 && skills_1[1] >= 1 )
            goto LABEL_1330;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            // NOTE: only first index was there!
            t[0] = -45.0; //i added the other 2
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 815, x, y + 45.0, dir, 1, t, 1);
            scene_add_effect(this, 127, x, y, dir, -1);
            set_vec_speed(-45.0, 25.0);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(5);
          }
          if ( get_subseq() == 1 && get_elaps_frames() > 20 )
          {
            set_subseq(4);
            v_force = 0.60000002;
            v_inerc = v_inerc * 0.5;
            h_inerc = h_inerc * 0.25;
          }
          return;
        case 522:
          if ( get_subseq() == 6 )
          {
            sub10func();
            
          }
          field_18C = 1;
          if ( get_subseq() == 1 )
          {
            if ( field_190 == 2 || field_190 == 7 )
            {
LABEL_1312:
              next_subseq();
              goto LABEL_1313;
            }
          }
          if ( get_subseq() == 2 )
            goto LABEL_1385;
          if ( get_subseq() == 3 || get_subseq() == 4 || get_subseq() == 5 )
          {
            if ( get_subseq() == 2 || get_subseq() == 3 )
            {
LABEL_1385:
              h_inerc = h_inerc + 0.1500000059604645;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
            }
            v_inerc = v_inerc - 0.5;
            if ( char_on_ground_down() )
            {
              set_subseq(6);
              goto LABEL_951;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 && skills_1[1] >= 1 )
            goto LABEL_1330;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            // NOTE: only the first index was there!
            t[0] = 0.0; // i added the other 2
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 815, x, y + 45.0, dir, 1, t, 1);
            set_vec_speed(0.0, 25.0);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(5);
          }
          if ( get_subseq() == 1 && get_elaps_frames() > 20 )
          {
            field_190 = 1;
            set_subseq(4);
            h_inerc = h_inerc * 0.5;
          }
          return;
        case 523:
          if ( get_subseq() == 6 )
          {
            sub10func();
            
          }
          field_18C = 1;
          switch ( get_subseq() )
          {
            case 1:
              if ( field_190 == 2 || field_190 == 7 )
              {
                next_subseq();
LABEL_1313:
                h_inerc = -8.0;
                v_inerc = 12.5;
                return;
              }
              break;
            case 2:
              goto LABEL_1416;
            case 3:
            case 4:
            case 5:
              break;
            default:
              goto LABEL_1424;
          }
          if ( get_subseq() != 2 && get_subseq() != 3 )
            goto LABEL_1418;
LABEL_1416:
          h_inerc = h_inerc + 0.1500000059604645;
          if ( h_inerc > 0.0 )
            h_inerc = 0.0;
LABEL_1418:
          if ( get_subseq() > 1 )
            v_inerc = v_inerc - 0.5;
          
          if ( char_on_ground_down() )
          {
            v_inerc = 0.0;
            if ( get_subseq() > 1 )
              reset_forces();
            set_subseq(6);
            goto LABEL_952;
          }
LABEL_1424:
          if ( get_subseq() == 6 )
          {
            h_inerc = h_inerc - 1.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( get_subseq() || get_frame_time() || get_frame() != 4 || skills_1[1] < 1 )
          {
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              // NOTE: only the first index was here
              t[0] = 45.0; // i added those 2
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 815, x, y + 45.0, dir, 1, t, 1);
              set_vec_speed(45.0, 25.0);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(5);
            }
            if ( get_subseq() == 1 && get_elaps_frames() > 20 )
            {
              set_subseq(4);
              v_force = 0.60000002;
              v_inerc = v_inerc * 0.5;
              h_inerc = h_inerc * 0.25;
            }
            return;
          }
          goto LABEL_1433;
        case 525:
          if ( !get_subseq() || get_subseq() == 3 || get_subseq() == 4 )
          {
            sub10func();
            
          }
          field_18C = 5;
          if ( get_subseq() != 1 )
            goto LABEL_1478;
          if ( field_190 && field_190 != 3 )
            goto LABEL_1449;
          if ( get_elaps_frames() >= 30 )
          {
            set_subseq(3);
            goto LABEL_1452;
          }
          if ( get_elaps_frames() >= 20 && (keyDown(INP_A) > 0u/*i64*/ || keyDown(INP_C) > 0u) )
            goto LABEL_1456;
LABEL_1478:
          if ( get_subseq() != 2 )
            goto LABEL_2967;
          if ( get_elaps_frames() >= 20 )
          {
LABEL_1449:
            next_subseq();
            return;
          }
          if ( keyDown(INP_A) <= 0u/*i64*/ && keyDown(INP_C) <= 0u )
          {
LABEL_2967:
            if ( get_subseq() == 3 || get_subseq() == 4 )
            {
              h_inerc = h_inerc - 0.3499999940395355;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              goto LABEL_1493;
            }
            return;
          }
LABEL_1456:
          if ( dX(dir) > 0 )
          {
            if ( dY() < 0 )
            {
              field_7D0 = 1;
            }
            if ( !((dY() < 0) | (dY() == 0)) )
              field_7D0 = 0;
            if ( !dY() )
              field_7D0 = 0;
          }
          if ( !dX(dir)/*down_X*/ )
          {
            if ( dY() < 0 )
            {
              field_7D0 = 2;
            }
            if ( !((dY() < 0) | (dY() == 0)) )
              field_7D0 = 0;
            if ( !dY() )
              field_7D0 = 0;
          }
          if ( dX(dir) < 0 )
          {
            dir = -dir;
            if ( dY() < 0 )
            {
              field_7D0 = 1;
            }
            if ( !((dY() < 0) | (dY() == 0)) )
              field_7D0 = 0;
            goto LABEL_1475;
          }
          goto LABEL_1477;
        case 526:
          if ( !get_subseq() || get_subseq() == 5 )
            sub10func();
          field_18C = 5;
          if ( get_subseq() != 1 )
            goto LABEL_1525;
          if ( field_190 && field_190 != 3 )
            goto LABEL_650;
          if ( get_elaps_frames() >= 30 )
            goto LABEL_1501;
          if ( get_elaps_frames() >= 20 && (keyDown(INP_A) > 0u/*i64*/ || keyDown(INP_C) > 0u) )
            goto LABEL_1506;
LABEL_1525:
          if ( get_subseq() != 2 )
            goto LABEL_1531;
          if ( get_elaps_frames() >= 20 )
            goto LABEL_1527;
          if ( get_elaps_frames() >= 0 && (keyDown(INP_A) > 0u/*i64*/ || keyDown(INP_C) > 0u) )
            goto LABEL_1506;
LABEL_1531:
          if ( get_subseq() == 3 || get_subseq() == 4 )
          {
            v_inerc = v_inerc - 0.5;
            if ( char_on_ground_down() )
              goto LABEL_1534;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            t[0] = -45.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 816, x, y + 45.0, dir, 1, t, 3);
            scene_add_effect(this, 127, x, y, dir, -1);
            set_vec_speed(-45.0, 15.0);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(5);
          }
          return;
        case 527:
          if ( get_subseq() == 5 )
            sub10func();
          field_18C = 5;
          if ( get_subseq() != 1 )
            goto LABEL_1551;
          if ( field_190 && field_190 != 3 )
            goto LABEL_650;
          if ( get_elaps_frames() >= 30 )
            goto LABEL_1501;
          if ( get_elaps_frames() >= 20 && (keyDown(INP_A) > 0u/*i64*/ || keyDown(INP_C) > 0u) )
            goto LABEL_1506;
LABEL_1551:
          if ( get_subseq() != 2 )
            goto LABEL_1556;
          if ( get_elaps_frames() >= 20 )
          {
LABEL_1527:
            next_subseq();
            goto LABEL_1502;
          }
          if ( get_elaps_frames() >= 0 && (keyDown(INP_A) > 0u/*i64*/ || keyDown(INP_C) > 0u) )
          {
LABEL_1506:
            if ( dX(dir) > 0 )
            {
              if ( dY() < 0 )
              {
                field_7D0 = 1;
              }
              if ( !((dY() < 0) | (dY() == 0)) )
                field_7D0 = -1;
              if ( !dY() )
                field_7D0 = 0;
            }
            if ( !dX(dir)/*down_X*/ )
            {
              if ( dY() < 0 )
              {
                field_7D0 = 2;
              }
              if ( !((dY() < 0) | (dY() == 0)) )
                field_7D0 = -2;
              if ( !dY() )
                field_7D0 = 0;
            }
            if ( dX(dir) < 0 )
            {
              dir = -dir;
              if ( dY() < 0 )
              {
                field_7D0 = 1;
              }
              if ( !((dY() < 0) | (dY() == 0)) )
                field_7D0 = -1;
LABEL_1475:
              if ( !dY() )
                field_7D0 = 0;
            }
            goto LABEL_1477;
          }
LABEL_1556:
          if ( get_subseq() == 3 || get_subseq() == 4 )
          {
            v_inerc = v_inerc - 0.5;
            if ( char_on_ground_down() )
            {
LABEL_1534:
              move_val = 5;
              set_subseq(move_val);
              break;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
LABEL_1493:
            addbullet(this, NULL, 816, x, y + 45.0, dir, 1, t, 3);
            scene_add_effect(this, 127, x, y, dir, -1);
            set_vec_speed(0.0, 15.0);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(5);
          }
          return;
        case 528:
          v18 = 5;
          if ( get_subseq() == 5 )
          {
            sub10func();
            
          }
          field_18C = 5;
          if ( get_subseq() != 1 )
            goto LABEL_1600;
          if ( field_190 && field_190 != 3 )
            goto LABEL_650;
          if ( char_on_ground_down() )
          {
            v_inerc = 0.0;
            set_subseq(5);
LABEL_952:
            y = getlvl_height();
            return;
          }
          if ( get_elaps_frames() >= 30 )
          {
LABEL_1501:
            set_subseq(3);
LABEL_1502:
            h_inerc = h_inerc * 0.5;
            v_inerc = 0.5 * v_inerc;
            return;
          }
          if ( get_elaps_frames() >= 20 && (keyDown(INP_A) > 0u/*i64*/ || keyDown(INP_C) > 0u) )
          {
            if ( dX(dir) > 0 )
            {
              if ( dY() < 0 )
              {
                field_7D0 = 1;
              }
              if ( !((dY() < 0) | (dY() == 0)) )
                field_7D0 = -1;
              if ( !dY() )
                field_7D0 = 0;
            }
            if ( !dX(dir)/*down_X*/ )
            {
              if ( dY() < 0 )
              {
                field_7D0 = 2;
              }
              if ( !((dY() < 0) | (dY() == 0)) )
                field_7D0 = -2;
              if ( !dY() )
                field_7D0 = 0;
            }
            if ( dX(dir) < 0 )
            {
              dir = -dir;
              if ( dY() < 0 )
              {
                field_7D0 = 1;
              }
              if ( !((dY() < 0) | (dY() == 0)) )
                field_7D0 = -1;
              if ( !dY() )
                field_7D0 = 0;
            }
            set_seq(529);
            return;
          }
          
LABEL_1600:
          if ( get_subseq() == 2 )
          {
            if ( char_on_ground_down() )
            {
              v_inerc = 0.0;
              set_subseq(5);
              goto LABEL_952;
            }
            if ( get_elaps_frames() >= 20 )
            {
              next_subseq();
              goto LABEL_1502;
            }
            if ( get_elaps_frames() >= 0 && (keyDown(INP_A) > 0u/*i64*/ || keyDown(INP_C) > 0u) )
            {
              if ( dX(dir) > 0 )
              {
                if ( dY() < 0 )
                {
                  field_7D0 = 1;
                }
                if ( !((dY() < 0) | (dY() == 0)) )
                  field_7D0 = -1;
                if ( !dY() )
                  field_7D0 = 0;
              }
              if ( !dX(dir)/*down_X*/ )
              {
                if ( dY() < 0 )
                {
                  field_7D0 = 2;
                }
                if ( !((dY() < 0) | (dY() == 0)) )
                  field_7D0 = -2;
                if ( !dY() )
                  field_7D0 = 0;
              }
              if ( dX(dir) < 0 )
              {
                dir = -dir;
                if ( dY() < 0 )
                {
                  field_7D0 = 1;
                }
                if ( !((dY() < 0) | (dY() == 0)) )
                  field_7D0 = -1;
                if ( !dY() )
                  field_7D0 = 0;
              }
              set_seq(529);
              return;
            }
            
          }
          if ( get_subseq() != 3 && get_subseq() != 4 )
            goto LABEL_1636;
          v_inerc = v_inerc - 0.5;
          if ( !char_on_ground_down() )
          {
            
LABEL_1636:
            if ( get_subseq() == 5 && 0.0 < h_inerc )
            {
              h_inerc = h_inerc - 0.75;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              t[0] = 45.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 816, x, y + 45.0, dir, 1, t, 3);
              scene_add_effect(this, 127, x, y, dir, -1);
              set_vec_speed(45.0, 15.0);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(5);
            }
            return;
          }
LABEL_1634:
          set_subseq(v18);
          goto LABEL_106;
        case 529:
          if ( get_subseq() == 16 || get_subseq() == 19 )
          {
            sub10func();
            
          }
          field_18C = 5;
          if ( get_subseq() != 2 && get_subseq() != 5 && get_subseq() != 8 && get_subseq() != 11 && get_subseq() != 14 )
            goto LABEL_1687;
          if ( get_elaps_frames() >= 20 )
            goto LABEL_1656;
          if ( get_elaps_frames() >= 10 )
          {
            if ( (field_7D8) == 0 && skills_1[5] >= 2 || field_7D8 == 1 && skills_1[5] >= 4 )
            {
              if ( keyDown(INP_A) > 0u/*i64*/ || keyDown(INP_C) > 0u )
              {
                goto LABEL_1665;
              }
            }
          }
LABEL_1687:
          if ( get_subseq() == 3 || get_subseq() == 6 || get_subseq() == 9 || get_subseq() == 12 || (/*v602 = __OFSUB__(get_subseq(), 15),*/ get_subseq() == 15, (get_subseq() - 15) < 0, get_subseq() == 15) )
          {
            if ( get_elaps_frames() >= 5 )
            {
              v30 = char_on_ground_flag() == 0;
              if ( v30 )
                set_subseq(17);
              else
                set_subseq(16);
              h_inerc = h_inerc * 0.5;
              if ( v_inerc > 0.0 )
                v_inerc = v_inerc * 0.25;
              return;
            }
            if ( (!field_7D8 && skills_1[5] >= 2 || field_7D8 == 1 && skills_1[5] >= 4) && (keyDown(INP_A) > 0u/*i64*/ || keyDown(INP_C) > 0u) )
            {
LABEL_1665:
              if ( !((dX(dir) < 0) | (dX(dir) == 0)) )
              {
                if ( dY() < 0 )
                {
                  field_7D0 = 1;
                }
                if ( !((dY() < 0) | (dY() == 0)) )
                  field_7D0 = -1;
                if ( !dY() )
                  field_7D0 = 0;
              }
              if ( !dX(dir)/*down_X*/ )
              {
                if ( dY() < 0 )
                {
                  field_7D0 = 2;
                }
                if ( !((dY() < 0) | (dY() == 0)) )
                  field_7D0 = -2;
                if ( !dY() )
                  field_7D0 = 0;
              }
              if ( dX(dir) < 0 )
              {
                dir = -dir;
                if ( dY() < 0 )
                {
                  field_7D0 = 1;
                }
                if ( !((dY() < 0) | (dY() == 0)) )
                  field_7D0 = -1;
                if ( !dY() )
                  field_7D0 = 0;
              }
              ++field_7D8;
LABEL_1477:
              set_seq(529);
              return;
            }
            /*
            v602 = __OFSUB__(v587, 15);
            v600 = v587 == 15;
            v601 = (v587 - 15) < 0;
            */
          }
          /*
          if ( !((v601 ^ v602) | v600) )
            goto LABEL_1710;
          */
          if ( char_on_ground_down() )
            goto LABEL_1708;
          
LABEL_1710:
          if ( get_subseq() == 16 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( get_subseq() == 17 || get_subseq() == 18 )
          {
            v_force = 0.5;
            v_inerc = v_inerc - 0.5;
            if ( char_on_ground_down() )
            {
LABEL_1708:
              set_subseq(19);
              y = getlvl_height();
              v_inerc = 0.0;
              return;
            }
            
          }
          if ( get_subseq() == 19 )
          {
            h_inerc = h_inerc - 1.0;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              if ( !field_7D0 )
              {
                t[0] = 0.0;
                t[1] = 80.0;
                t[2] = 0.0;
                set_subseq(1);
                set_vec_speed(0.0, 15.0);
              }
              if ( field_7D0 == 1 )
              {
                t[0] = -45.0;
                t[1] = 100.0;
                t[2] = 0.0;
                set_subseq(4);
                set_vec_speed(-45.0, 15.0);
              }
              if ( field_7D0 == 2 )
              {
                t[0] = -90.0;
                t[1] = 120.0;
                t[2] = 0.0;
                set_subseq(10);
                set_vec_speed(-90.0, 15.0);
              }
              if ( field_7D0 == -1 )
              {
                t[0] = 45.0;
                t[1] = 100.0;
                t[2] = 0.0;
                set_subseq(7);
                set_vec_speed(45.0, 15.0);
              }
              if ( field_7D0 == -2 )
              {
                t[0] = 90.0;
                t[1] = 100.0;
                t[2] = 0.0;
                set_subseq(13);
                set_vec_speed(90.0, 15.0);
              }
              addbullet(this, NULL, 816, x, t[2] + y, dir, 1, t, 3);
              if ( char_on_ground_flag() )
                scene_add_effect(this, 127, x, y, dir, -1);
              play_sfx(5);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 17 )
            {
              set_seq(0);
              reset_forces();
            }
          }
          return;
        case 530:
          if ( get_subseq() == 4 )
            sub10func();
          field_18C = 9;
          if ( get_subseq() == 2 || get_subseq() == 3 )
          {
            h_inerc = h_inerc - 3.0;
            if ( h_inerc < 3.0 )
              h_inerc = 3.0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              move_val = 4;
              set_subseq(move_val);
              break;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            v_force = 0.5;
          if ( get_subseq() || get_frame_time() )
            goto LABEL_1765;
          if ( get_frame() == 3 && skills_1[9] >= 2 )
            goto LABEL_1330;
          if ( get_frame() == 5 )
          {
            h_inerc = 25.0;
            v_inerc = 8.0;
            scene_add_effect(this, 127, x, y, dir, -1);
          }
LABEL_1765:
          if ( get_subseq() != 2 || get_frame_time() || get_frame() != 5 )
            return;
          t[0] = 15.0;
          t[1] = 30.0;
          t[2] = 0.0;
          a4a = y + 50.0;
          v614 = x - (double)(130 * dir);
          goto LABEL_1769;
        case 531:
          if ( get_subseq() == 4 )
            sub10func();
          field_18C = 9;
          if ( get_subseq() == 2 || get_subseq() == 3 )
          {
            h_inerc = h_inerc - 3.0;
            if ( h_inerc < 3.0 )
              h_inerc = 3.0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_subseq(4);
              goto LABEL_106;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
          {
            v_inerc = v_inerc * 0.75;
            v_force = 0.5;
          }
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 3 && skills_1[9] >= 2 )
            {
LABEL_1433:
              next_frame();
              return;
            }
            if ( get_frame() == 5 )
            {
              h_inerc = 40.0;
              v_inerc = 13.0;
              scene_add_effect(this, 127, x, y, dir, -1);
            }
          }
          if ( get_subseq() != 2 || get_frame_time() || get_frame() != 5 )
            return;
          t[0] = 45.0;
          t[1] = 30.0;
          t[2] = 0.0;
          a4a = y + 50.0;
          v614 = x - (double)(130 * dir);
          goto LABEL_1769;
        case 532:
          if ( get_subseq() == 4 )
            sub10func();
          field_18C = 9;
          if ( get_subseq() == 2 || get_subseq() == 3 )
          {
            h_inerc = h_inerc - 3.0;
            if ( h_inerc < 3.0 )
              h_inerc = 3.0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              move_val = 4;
              set_subseq(move_val);
              break;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            v_force = 0.5;
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 3 && skills_1[9] >= 2 )
            {
LABEL_1330:
              next_frame();
              return;
            }
            if ( get_frame() == 6 )
            {
              h_inerc = 25.0;
              v_inerc = 8.0;
              scene_add_effect(this, 127, x, y, dir, -1);
            }
          }
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 5 )
          {
            t[0] = 15.0;
            t[1] = 30.0;
            t[2] = 0.0;
            a4a = y + 50.0;
            v614 = x - (double)(130 * dir);
LABEL_1769:
            addbullet(this, NULL, 817, v614, a4a, -dir, 1, t, 3);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(19);
          }
          return;
        case 533:
          if ( get_subseq() == 4 )
            sub10func();
          field_18C = 9;
          if ( get_subseq() == 2 || get_subseq() == 3 )
          {
            h_inerc = h_inerc - 3.0;
            if ( h_inerc < 3.0 )
              h_inerc = 3.0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1634;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
          {
            v_inerc = v_inerc * 0.75;
            v_force = 0.5;
          }
          if ( get_subseq() || get_frame_time() )
            goto LABEL_1840;
          if ( get_frame() == 3 && skills_1[9] >= 2 )
            goto LABEL_1433;
          if ( get_frame() == 6 )
          {
            h_inerc = 40.0;
            v_inerc = 13.0;
            scene_add_effect(this, 127, x, y, dir, -1);
          }
LABEL_1840:
          if ( get_subseq() != 2 || get_frame_time() || get_frame() != 5 )
            return;
          t[0] = 45.0;
          t[1] = 30.0;
          t[2] = 0.0;
          a4a = y + 50.0;
          v614 = x - (double)(130 * dir);
          goto LABEL_1769;
        case 540:
          field_18C = 2;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            play_sfx(6);
            spell_energy_spend(200, 120);
            field_190 = 1;
            add_card_energy(50);
            addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
          }
          //v628 = get_subseq();
          //v631 = __OFSUB__(v628, 1);
          //v629 = v628 == 1;
          //v630 = (v628 - 1) < 0;
          if ( get_subseq() != 1 )
            goto LABEL_1864;
          if ( get_elaps_frames() > 60 )
          {
            set_subseq(5);
            v_force = 0.5;
            return;
          }
          if ( get_elaps_frames() >= 0 && dY() < 0 )
          {
            if ( dX(dir) <= 0 )
            {
              if ( dX(dir) < 0 )
              {
                play_sfx(7);
                set_subseq(4);
                h_inerc = -12.0;
                v_inerc = 12.0;
                v_force = 0.75;
                t[0] = 45.0;
                t[1] = 20.0;
                t[2] = 4.0;
                addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
                t[2] = 5.0;
                addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
                if ( skills_1[2] >= 4 )
                {
                  t[2] = 6.0;
                  t[0] = 30.0;
                  addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
                  t[0] = 60.0;
                  addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
                }
                return;
              }
              play_sfx(7);
              set_subseq(3);
              h_inerc = 0.0;
              v_inerc = 16.0;
              v_force = 0.75;
              t[0] = 90.0;
              t[1] = 20.0;
              t[2] = 4.0;
              addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
              t[2] = 5.0;
              addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
              if ( skills_1[2] < 4 )
                return;
              t[2] = 6.0;
              t[0] = 105.0;
              addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
              t[0] = 75.0;
            }
            else
            {
              set_subseq(2);
              play_sfx(7);
              h_inerc = 12.0;
              v_inerc = 12.0;
              v_force = 0.75;
              t[0] = 135.0;
              t[1] = 20.0;
              t[2] = 4.0;
              addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
              t[2] = 5.0;
              addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
              if ( skills_1[2] < 4 )
                return;
              t[2] = 6.0;
              t[0] = 150.0;
              addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
              t[0] = 120.0;
            }
            addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
            return;
          }
          //v631 = 0;
          //v629 = 1;
          //v630 = 0;
LABEL_1864:
          if ( /*(v630 ^ v631) | v629*/get_subseq() == 1 || (v_inerc = v_inerc - v_force, !char_on_ground_down()) )
          {
            if ( process() )
              set_seq(9);
            if ( !get_elaps_frames() )
            {
              if ( (get_frame_time() || get_frame() || get_subseq() != 3) && (get_frame_time() || get_frame() || get_subseq() != 4) )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 5 )
                  set_seq(9);
              }
              else
              {
LABEL_954:
                set_seq(9);
              }
            }
            return;
          }
LABEL_950:
          set_seq(10);
LABEL_951:
          reset_forces();
          goto LABEL_952;
        case 545:
          if ( get_subseq() == 2 )
            sub10func();
          field_18C = 6;
          if ( char_on_ground_down() && get_subseq() < 2 )
          {
            play_sfx(23);
            //shake_camera(5.0);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            if ( skills_1[6] >= 2 )
              t[2] = 7.0;
            addbullet(this, NULL, 821, x, y, dir, 1, t, 3);
            /*
            v635 = 0;
            v1098 = 0;
            do
            {
              *(float *)&v1187 = (double)v1098 + 30.0;
              v1188 = 15.0;
              v1189 = 1.0;
              if ( *(float *)&v1187 < 0.0 || *(float *)&v1187 > 180.0 )
              {
                y = -1;
                xb = dir;
              }
              else
              {
                y = 1;
                xb = dir;
              }
              addbullet(this, NULL, 821, x, y, xb, y, (int)&v1187, 3);
              v635 += 60;
              v1098 = v635;
            }
            while ( v635 < 360 );*/
            set_subseq(2);
            goto LABEL_106;
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(15);
            set_vec_speed(70.0, 25.0);
            t[0] = 70.0;
            t[1] = 0.0;
            t[2] = 2.0;
            addbullet(this, NULL, 821, (double)(20 * (char)dir) + x, y, dir, 1, t, 3);
          }
          return;
        case 546:
          if ( get_subseq() == 2 )
            sub10func();
          field_18C = 6;
          if ( char_on_ground_down() && get_subseq() < 2 )
          {
            play_sfx(23);
            //shake_camera(5.0);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 5.0;
            addbullet(this, NULL, 821, x, y, dir, -1, t, 3);
            t[2] = 6.0;
            addbullet(this, NULL, 821, x, y, dir, -1, t, 3);
            /*
            v638 = 0;
            v1099 = 0;
            do
            {
              *(float *)&v1159 = (double)v1099 + 30.0;
              v1160 = 15.0;
              v1161 = 1.0;
              if ( *(float *)&v1159 < 0.0 || *(float *)&v1159 > 180.0 )
                addbullet(this, NULL, 821, x, y, dir, -1, (int)&v1159, 3);
              else
                addbullet(this, NULL, 821, x, y, dir, 1, (int)&v1159, 3);
              v638 += 60;
              v1099 = v638;
            }
            while ( v638 < 360 );*/
            t[0] = 0.0;
            t[1] = 17.5;
            t[2] = 3.0;
            addbullet(this, NULL, 821, x, 0.0, dir, 1, t, 3);
            addbullet(this, NULL, 821, x, 0.0, -dir, 1, t, 3);
            if ( skills_1[6] >= 4 )
            {
              t[1] = 30.0;
              addbullet(this, NULL, 821, x, 0.0, dir, 1, t, 3);
              addbullet(this, NULL, 821, x, 0.0, -dir, 1, t, 3);
            }
            set_subseq(2);
            y = getlvl_height();
            reset_forces();
            field_190 = 1;
          }
          else
          {
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(15);
              set_vec_speed(70.0, 25.0);
              t[0] = 70.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL, 821, (double)(20 * (char)dir) + x, y, dir, 1, t, 3);
            }
          }
          return;
        case 550:
          field_18C = 10;
          v323 = 7;
          if ( !get_subseq() || get_subseq() == 7 )
            sub10func();
          if ( get_subseq() <= 2 && field_190 )
            goto LABEL_1923;
          if ( get_subseq() > 0 && get_subseq() < 7 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 7 )
            goto LABEL_913;
          if ( get_subseq() == 1 || get_subseq() == 2 )
          {
            if ( fabs(x - enemy->x) <= 100.0 )
              field_7D0 = 1;
            if ( field_7D0 == 1 )
              h_inerc = h_inerc * 0.9200000166893005;
            if ( dX(dir) > 0 ) //condition reversed ( <= )
            {
              h_inerc = (double)(char)skills_1[10] * 0.1000000014901161 + 0.25 + h_inerc;
            }
            if ( dX(dir) < 0 ) // condition reversed ( >= )
            {
              h_inerc = h_inerc - (0.1000000014901161 * (double)(char)skills_1[10] + 0.25);
            }
            if ( h_inerc > 10.0 )
              h_inerc = 10.0;
            if ( h_inerc < -12.0 )
              h_inerc = -12.0;
          }
          if ( get_subseq() == 4 && field_190 == 2 && get_elaps_frames() >= 7 )
            goto LABEL_1949;
          if ( get_subseq() != 5 && get_subseq() != 6 )
            goto LABEL_1974;
          if ( dX(dir) > 0 )
            h_inerc = h_inerc + 0.25;
          if ( dX(dir) < 0 ) // condition reversed ( old: >= )
          {
            h_inerc = h_inerc - 0.25;
          }
          if ( 10.0 < h_inerc )
            h_inerc = 10.0;
          if ( -6.0 > h_inerc )
            h_inerc = -6.0;
          if ( skills_1[10] < 1 )
            goto LABEL_1974;
          if ( get_subseq() != 6 && (get_subseq() != 5 || get_frame() < 2) )
            goto LABEL_1974;
          if ( keyDown(INP_C) && skills_1[10] >= 3 )
            goto LABEL_1968;
          if ( keyDown(INP_B) && skills_1[10] >= 2 )
            goto LABEL_1971;
          if ( keyDown(INP_A) )
            goto LABEL_1973;
LABEL_1974:
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() )
            return;
          if ( get_frame_time() || get_frame() || get_subseq() != 1 )
            goto LABEL_1982;
          spell_energy_spend(200, 120);
          add_card_energy(50);
          play_sfx(15);
          h_inerc = 10.0;
          v_inerc = 25.0;
          v_force = 1.25;
          addbullet(this, NULL, 990, x, y, dir, 1, 0, 0);
          v658 = (double)(200 * (char)dir) + x;
          goto LABEL_1981;
        case 551:
          field_18C = 10;
          v227 = 7;
          if ( !get_subseq() || get_subseq() == 7 )
            sub10func();
          if ( get_subseq() <= 2 && field_190 )
            goto LABEL_1992;
          if ( get_subseq() > 0 && get_subseq() < 7 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 7 )
            goto LABEL_731;
          if ( get_subseq() == 1 || get_subseq() == 2 )
          {
            if ( fabs(x - enemy->x) <= 300.0 )
              field_7D0 = 1;
            if ( field_7D0 == 1 )
              h_inerc = h_inerc * 0.9200000166893005;
            if ( dX(dir) > 0 ) //condition reversed (old: <= )
            {
              h_inerc = (double)(char)skills_1[10] * 0.1000000014901161 + 0.25 + h_inerc;
            }
            if ( dX(dir) < 0 ) //condition reversed (old: >= )
            {
              h_inerc = h_inerc - (0.1000000014901161 * (double)(char)skills_1[10] + 0.25);
            }
            if ( h_inerc > 25.0 )
              h_inerc = 25.0;
            if ( h_inerc < -12.0 )
              h_inerc = -12.0;
          }
          if ( get_subseq() == 4 && field_190 == 2 && get_elaps_frames() >= 7 )
            goto LABEL_2017;
          if ( get_subseq() != 5 && get_subseq() != 6 )
            goto LABEL_2041;
          if ( dX(dir) > 0 )
            h_inerc = h_inerc + 0.25;
          if ( dX(dir) < 0 ) //condition reversed (old: >= )
          {
            h_inerc = h_inerc - 0.25;
          }
          if ( h_inerc > 10.0 )
            h_inerc = 10.0;
          if ( -6.0 > h_inerc )
            h_inerc = -6.0;
          if ( skills_1[10] < 1 )
            goto LABEL_2041;
          if ( get_subseq() != 6 && (get_subseq() != 5 || get_frame() < 2) )
            goto LABEL_2041;
          if ( keyDown(INP_C) && skills_1[10] >= 3 )
            goto LABEL_2035;
          if ( keyDown(INP_B) && skills_1[10] >= 2 )
            goto LABEL_2038;
          if ( keyDown(INP_A) )
            goto LABEL_2040;
LABEL_2041:
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() )
            return;
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(15);
            h_inerc = 25.0;
            v_inerc = 25.0;
            v_force = 1.0;
            addbullet(this, NULL, 990, x, y, dir, 1, 0, 0);
            v658 = (double)(200 * (char)dir) + x;
LABEL_1981:
            scene_add_effect(this, 128, v658, y, dir, -1);
          }
          goto LABEL_1982;
        case 552:
          v323 = 7;
          field_18C = 10;
          if ( get_subseq() == 7 )
            sub10func();
          if ( get_subseq() <= 2 && field_190 )
          {
LABEL_1923:
            next_subseq();
            reset_forces();
            return;
          }
          if ( get_subseq() > 0 && get_subseq() < 7 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 7 )
          {
LABEL_913:
            set_subseq(v323);
            goto LABEL_106;
          }
          if ( get_subseq() == 1 || get_subseq() == 2 )
          {
            if ( fabs(x - enemy->x) <= 100.0 )
              field_7D0 = 1;
            if ( field_7D0 == 1 )
              h_inerc = h_inerc * 0.9200000166893005;
            if ( dX(dir) > 0 ) //condition reversed (old: <= )
            {
              h_inerc = (double)(char)skills_1[10] * 0.1000000014901161 + 0.25 + h_inerc;
            }
            if ( dX(dir) < 0 ) //condition reversed (old: >= )
            {
              h_inerc = h_inerc - (0.1000000014901161 * (double)(char)skills_1[10] + 0.25);
            }
            if ( h_inerc > 25.0 )
              h_inerc = 25.0;
            if ( h_inerc < -12.0 )
              h_inerc = -12.0;
          }
          if ( get_subseq() == 4 && field_190 == 2 && get_elaps_frames() >= 7 )
          {
LABEL_1949:
            next_subseq();
            goto LABEL_1950;
          }
          if ( get_subseq() != 5 && get_subseq() != 6 )
            goto LABEL_2096;
          if ( dX(dir) > 0 )
            h_inerc = h_inerc + 0.25;
          if ( dX(dir) < 0 ) //condition reversed (old: >= )
          {
            h_inerc = h_inerc - 0.25;
          }
          if ( h_inerc > 10.0 )
            h_inerc = 10.0;
          if ( -6.0 > h_inerc )
            h_inerc = -6.0;
          if ( skills_1[10] < 1 )
            goto LABEL_2096;
          if ( get_subseq() != 6 && (get_subseq() != 5 || get_frame() < 2) )
            goto LABEL_2096;
          if ( keyDown(INP_C) && skills_1[10] >= 3 )
          {
LABEL_1968:
            //((void (__thiscall *)(char_aya *, signed int, signed int))set_seq_subseq_func1)(v1, 554, 6);
            set_seq(554);
            set_subseq(6);
            return;
          }
          if ( keyDown(INP_B) && skills_1[10] >= 2 )
          {
LABEL_1971:
            set_seq(554);
            return;
          }
          if ( keyDown(INP_A) )
          {
LABEL_1973:
            //((void (__thiscall *)(char_aya *, signed int, signed int))set_seq_subseq_func1)(v1, 554, 3);
            set_seq(554);
            set_subseq(3);
            return;
          }
LABEL_2096:
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() )
            return;
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(15);
            h_inerc = 10.0;
            v_inerc = 12.5;
            v_force = 0.75;
            addbullet(this, NULL, 990, x, y, dir, 1, 0, 0);
          }
          goto LABEL_1982;
        case 553:
          v227 = 7;
          field_18C = 10;
          if ( get_subseq() == 7 )
            sub10func();
          if ( get_subseq() <= 2 && field_190 )
          {
LABEL_1992:
            next_subseq();
            reset_forces();
            return;
          }
          if ( get_subseq() > 0 && get_subseq() < 7 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 7 )
          {
LABEL_731:
            move_val = v227;
            set_subseq(move_val);
            break;
          }
          if ( get_subseq() == 1 || get_subseq() == 2 )
          {
            if ( fabs(x - enemy->x) <= 300.0 )
              field_7D0 = 1;
            if ( field_7D0 == 1 )
              h_inerc = h_inerc * 0.9200000166893005;
            if ( dX(dir) > 0 ) //condition reversed (old: <= )
            {
              h_inerc = (double)(char)skills_1[10] * 0.1000000014901161 + 0.25 + h_inerc;
            }
            if ( dX(dir) < 0 ) //condition reversed (old: >= )
            {
              h_inerc = h_inerc - (0.1000000014901161 * (double)(char)skills_1[10] + 0.25);
            }
            if ( h_inerc > 25.0 )
              h_inerc = 25.0;
            if ( h_inerc < -12.0 )
              h_inerc = -12.0;
          }
          if ( get_subseq() == 4 && field_190 == 2 && get_elaps_frames() >= 7 )
          {
LABEL_2017:
            next_subseq();
            goto LABEL_1950;
          }
          if ( get_subseq() == 5 || get_subseq() == 6 )
          {
            if ( dX(dir) > 0 )
              h_inerc = h_inerc + 0.25;
            if ( dX(dir) < 0 ) //condition reversed (old: >= )
            {
              h_inerc = h_inerc - 0.25;
            }
            if ( h_inerc > 10.0 )
              h_inerc = 10.0;
            if ( -6.0 > h_inerc )
              h_inerc = -6.0;
            if ( skills_1[10] >= 1 )
            {
              if ( get_subseq() == 6 || get_subseq() == 5 && get_frame() >= 2 )
              {
                if ( keyDown(INP_C) && skills_1[10] >= 3 )
                {
LABEL_2035:
                  //((void (__thiscall *)(char_aya *, signed int, signed int))set_seq_subseq_func1)(v1, 554, 6);
                  set_seq(554);
                  set_subseq(6);
                  return;
                }
                if ( keyDown(INP_B) && skills_1[10] >= 2 )
                {
LABEL_2038:
                  set_seq(554);
                  return;
                }
                if ( keyDown(INP_A) )
                {
LABEL_2040:
                  //((void (__thiscall *)(char_aya *, signed int, signed int))set_seq_subseq_func1)(v1, 554, 3);
                  set_seq(554);
                  set_subseq(3);
                  return;
                }
              }
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(15);
              h_inerc = 25.0;
              v_inerc = 12.5;
              v_force = 0.75;
              addbullet(this, NULL, 990, x, y, dir, 1, 0, 0);
            }
LABEL_1982:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            {
LABEL_1950:
              h_inerc = -6.0;
              v_inerc = 6.0;
              v_force = 0.40000001;
              return;
            }
          }
          return;
        case 554:
          if ( get_subseq() == 2 || get_subseq() == 5 )
          {
            sub10func();
            
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
          {
            reset_forces();
            
            field_49A = 0;
            field_7D0 = 0;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
          {
            field_49A = 0;
            field_7D0 = 0;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
          {
            h_inerc = h_inerc * 0.25;
            v_inerc = 0.25 * v_inerc;
            v_force = 0.0;
          }
          field_18C = 10;
          if ( char_on_ground_down() && get_subseq() < 2 )
          {
            //shake_camera(5.0);
            /*
            v693 = 0;
            v1100 = 0;
            do
            {
              *(float *)&v1287 = (double)v1100 + 30.0;
              v1288 = 15.0;
              v1289 = 1.0;
              if ( *(float *)&v1287 < 0.0 || *(float *)&v1287 > 180.0 )
              {
                yb = -1;
                xc = dir;
              }
              else
              {
                yb = 1;
                xc = dir;
              }
              addbullet(this, NULL, 821, x, y, xc, yb, (int)&v1287, 3);
              v693 += 60;
              v1100 = v693;
            }
            while ( v693 < 360 );
            */
            set_subseq(2);
            goto LABEL_106;
          }
          if ( (get_subseq() == 3 || get_subseq() == 4) && (v_inerc = v_inerc - v_force, char_on_ground_down()) || get_subseq() == 6 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
          {
            set_subseq(5);
            goto LABEL_106;
          }
          if ( process() )
            goto LABEL_2727;
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 3 || !get_frame_time() && !get_frame() && get_subseq() == 6) )
            goto LABEL_440;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            play_sfx(15);
            set_vec_speed(70.0, 25.0);
            add_card_energy(25);
          }
          if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 4 )
          {
            play_sfx(15);
            add_card_energy(25);
          }
          if ( get_subseq() == 6 && !get_frame_time() && get_frame() == 3 )
          {
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 > 75.0 )
              field_7E4 = 75.0;
            if ( field_7E4 < -30.0 )
              field_7E4 = -30.0;
            t[0] = field_7E4;
            t[1] = 15.0;
            t[2] = 0.0;
            addbullet(this, NULL, 822, (double)(47 * (char)dir) + x, y + 106.0, dir, 1, t, 3);
            set_vec_speed(0.0, 25.0);
            spell_energy_spend(200, 120);
            add_card_energy(25);
            play_sfx(19);
            field_190 = 1;
            v_inerc = 7.5;
            h_inerc = -7.5;
            v_force = 0.5;
          }
          return;
        case 560:
          sub10func();
          field_18C = 3;
          if ( field_7D0 != 1 )
            goto LABEL_2230;
          v1101 = 5;
          if ( skills_1[3] == 2 )
            v1101 = 7;
          if ( skills_1[3] == 3 )
            v1101 = 9;
          if ( skills_1[3] == 4 )
            v1101 = 11;
          v706 = field_7D2 & 0x80000003 == 0;
          if ( field_7D2 & 0x80000003 < 0 )
            v706 = (((field_7D2 & 0x80000003) - 1) | 0xFFFFFFFC) == -1;
          if ( !v706 || (double)v1101 < (double)field_7D2 * 0.25 )
            goto LABEL_2229;
          t[0] = (double)scene_rand_rng(400) + x - 200.0;
          t[1] = y + 175.0 + 175.0;
          t[2] = 0.0;
          a4b = (double)scene_rand_rng(300) + y + 300.0;
          v710 = 1380.0 - (double)(1480 * (dir == 1));
          goto LABEL_2228;
        case 561:
          sub10func();
          field_18C = 3;
          if ( field_7D0 == 1 )
          {
            v1102 = 5;
            if ( skills_1[3] == 2 )
              v1102 = 7;
            if ( skills_1[3] == 3 )
              v1102 = 9;
            if ( skills_1[3] == 4 )
              v1102 = 11;
            v714 = (field_7D2 & 0x80000003) == 0;
            if ( field_7D2 & 0x80000003 < 0 )
              v714 = (((field_7D2 & 0x80000003) - 1) | 0xFFFFFFFC) == -1;
            if ( v714 && (double)v1102 >= (double)field_7D2 * 0.25 )
            {
              t[0] = ((double)scene_rand_rng(400) - 400.0) * (double)dir + enemy->x;
              t[1] = enemy->y + 175.0 + 175.0;
              t[2] = 0.0;
              a4b = (double)scene_rand_rng(300) + y + 300.0;
              v710 = 1380.0 - (double)(1480 * (dir == 1));
LABEL_2228:
              addbullet(this, NULL, 825, v710, a4b, dir, 1, t, 3);
            }
LABEL_2229:
            ++field_7D2;
          }
LABEL_2230:
          if ( process() )
            set_seq(0);
          if ( get_subseq() || get_frame_time() || get_frame() != 1 )
            return;
          play_sfx(17);
          field_7D0 = 1;
          field_190 = 1;
          goto LABEL_2236;
        case 562:
          if ( get_subseq() == 1 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_2280;
          }
          field_18C = 3;
          if ( field_7D0 != 1 )
            goto LABEL_2266;
          v1103 = 5;
          if ( skills_1[3] == 2 )
            v1103 = 7;
          if ( skills_1[3] == 3 )
            v1103 = 9;
          if ( skills_1[3] == 4 )
            v1103 = 11;
          v720 = (field_7D2 & 0x80000003) == 0;
          if ( field_7D2 & 0x80000003 < 0 )
            v720 = (((field_7D2 & 0x80000003) - 1) | 0xFFFFFFFC) == -1;
          if ( v720 && (double)v1103 >= (double)field_7D2 * 0.25 )
          {
            t[0] = (double)scene_rand_rng(400) + x - 200.0;
            t[1] = y + 175.0 + 175.0;
            t[2] = 0.0;
            a4c = (double)scene_rand_rng(300) + y + 300.0;
            v724 = 1380.0 - (double)(1480 * (dir == 1));
            goto LABEL_2264;
          }
          goto LABEL_2265;
        case 563:
          if ( get_subseq() == 1 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_2280:
              y = getlvl_height();
              reset_forces();
              next_subseq();
              return;
            }
          }
          field_18C = 3;
          if ( field_7D0 == 1 )
          {
            v1104 = 5;
            if ( skills_1[3] == 2 )
              v1104 = 7;
            if ( skills_1[3] == 3 )
              v1104 = 9;
            if ( skills_1[3] == 4 )
              v1104 = 11;
            //v729 = field_7D2 & 0x80000003;
            v728 = (field_7D2 & 0x80000003) == 0;
            if ( (field_7D2 & 0x80000003) < 0 )
              v728 = (((field_7D2 & 0x80000003) - 1) | 0xFFFFFFFC) == -1;
            if ( v728 && (double)v1104 >= (double)field_7D2 * 0.25 )
            {
              t[0] = ((double)scene_rand_rng(400) - 400.0) * (double)dir + enemy->x;
              t[1] = enemy->y + 175.0 + 175.0;
              t[2] = 0.0;
              a4c = (double)scene_rand_rng(300) + y + 300.0;
              v724 = 1380.0 - (double)(1480 * (dir == 1));
LABEL_2264:
              addbullet(this, NULL, 825, v724, a4c, dir, 1, t, 3);
            }
LABEL_2265:
            ++field_7D2;
          }
LABEL_2266:
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 1 )
            {
              play_sfx(17);
              field_7D0 = 1;
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( !get_frame_time() )
            {
              v484 = get_frame() == 14;
              goto LABEL_1249;
            }
          }
          return;
        case 565:
          sub10func();
          if ( process() )
            set_seq(0);
          if ( get_subseq() || get_frame_time() || get_frame() != 8 )
            return;
          if ( getlvl_height() < y )
          {
            t[0] = 1.0;
          }
          else
          {
            t[0] = 0.0;
          }
          t[1] = 0.0;
          t[2] = 0.0;
          a4d = y + 100.0;
          v736 = x + 0.0;
          goto LABEL_2305;
        case 567:
          if ( process() )
          {
            set_seq(9);
            v_force = 0.60000002;
          }
          if ( get_subseq() || get_frame_time() || get_frame() != 8 )
            return;
          if ( getlvl_height() < y )
          {
            t[0] = 1.0;
          }
          else
          {
            t[0] = 0.0;
          }
          t[1] = 0.0;
          t[2] = 0.0;
          a4d = y + 100.0;
          v736 = x + 0.0;
LABEL_2305:
          addbullet(this, NULL, 826, v736, a4d, dir, 1, t, 3);
          play_sfx(13);
          goto LABEL_2236;
        case 570:
          sub10func();
          if ( process() )
            set_seq(0);
          if ( get_subseq() || get_frame_time() || get_frame() != 6 )
            return;
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 827, x + 0.0, y, dir, 1, t, 3);
          if ( (char)skills_1[11] + 3 > 0 )
          {
            /*
            v743 = (char)skills_1[11] + 3;
            do
            {
              *(float *)&v1220 = -85.0 - (double)scene_rand_rng(10);
              v1221 = (double)scene_rand_rng(10) + 35.0;
              v1222 = 1.0;
              v744 = y;
              v745 = dir;
              v746 = x + 100.0;
              *(float *)&v744 = v744 - (double)scene_rand_rng(20);
              v747 = *(float *)&v744;
              *(float *)&v744 = v746 - (double)scene_rand_rng(200);
              addbullet(this, NULL, 827, *(float *)&v744, v747, v745, 1, (int)&v1220, 3);
              --v743;
            }
            while ( v743 );*/
          }
          field_190 = 1;
          play_sfx(7);
          spell_energy_spend(200, 60);
          goto LABEL_2237;
        case 571:
          sub10func();
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 5.0;
            addbullet(this, NULL, 827, enemy->x, 0.0, dir, 1, t, 3);
            /*
            v1105 = 0.0;
            do
            {
              *(float *)&v1235 = (double)scene_rand_rng(10) + v1105 * 36.0;
              v1236 = (double)scene_rand_rng(10) + 35.0;
              v1237 = 2.0;
              addbullet(this, NULL, 827, x, y, dir, 1, (int)&v1235, 3);
              v1105 = v1105 + 1.0;
            }
            while ( v1105 < 10.0 );
            */
            field_190 = 1;
            if ( field_890 )
              play_sfx(25);
LABEL_2236:
            spell_energy_spend(200, 120);
LABEL_2237:
            add_card_energy(50);
          }
          return;
        case 573:
          if ( get_subseq() == 1 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              reset_forces();
              y = getlvl_height();
              set_subseq(1);
              return;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 4 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 5.0;
              addbullet(this, NULL, 827, enemy->x, 0.0, dir, 1, t, 3);
              /*
              v1106 = 0.0;
              do
              {
                *(float *)&v1229 = (double)scene_rand_rng(10) + v1106 * 36.0;
                v1230 = (double)scene_rand_rng(10) + 35.0;
                v1231 = 2.0;
                addbullet(this, NULL, 827, x, y, dir, 1, (int)&v1229, 3);
                v1106 = v1106 + 1.0;
              }
              while ( v1106 < 10.0 );
              */
              field_190 = 1;
              if ( field_890 )
                play_sfx(25);
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( !get_frame_time() )
            {
              v484 = get_frame() == 10;
              goto LABEL_1249;
            }
          }
          return;
        case 600:
          sub10func();
          sub_46AB50(2, 2);
          if ( get_subseq() == 1 && get_elaps_frames() > 60 )
            goto LABEL_650;
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 3 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(44 * (char)dir) + x, y + 138.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() && get_frame() == 6 )
            {
              addbullet(this, NULL, 850, (double)(80 * (char)dir) + x, y, dir, 1, 0, 0);
              play_sfx(9);
            }
          }
          return;
        case 601:
          sub10func();
          sub_46AB50(2, 2);
          if ( get_subseq() == 1 && (/*shake_camera(5.0),*/ get_elaps_frames() > 90) || get_subseq() == 2 && get_elaps_frames() > 90 )
          {
LABEL_1656:
            next_subseq();
          }
          else
          {
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(44 * (char)dir) + x, y + 138.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                addbullet(this, NULL, 851, x, y, dir, 1, 0, 0);
                play_sfx(10);
              }
            }
          }
          return;
        case 602:
          sub10func();
          sub_46AB50(2, 2);
          if ( get_subseq() == 1 )
          {
            //shake_camera(2.0);
            if ( get_elaps_frames() > 30 )
              goto LABEL_650;
          }
          if ( process() )
          {
            set_seq(0);
            sub_46AB50(2, 360);
          }
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 3 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(44 * (char)dir) + x, y + 138.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() && get_frame() == 6 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 852, x, y, dir, 1, t, 3);
              play_sfx(11);
              field_894 = 300;
            }
          }
          return;
        case 603:
          sub_46AB50(2, 2);
          //v762 = get_subseq();
          //v765 = __OFSUB__(v762, 1);
          //v763 = v762 == 1;
          //v764 = (v762 - 1) < 0;
          if ( get_subseq() != 1 )
            goto LABEL_2392;
          if ( get_elaps_frames() >= 40 )
            goto LABEL_650;
          //v765 = 0;
          //v763 = 1;
          //v764 = 0;
LABEL_2392:
          if ( !(/*(v764 ^ v765) | v763*/get_subseq() == 1) )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_seq(10);
              goto LABEL_951;
            }
          }
          if ( process() )
            set_seq(9);
          if ( get_elaps_frames() )
            goto LABEL_2968;
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, x, y + 120.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_elaps_frames() || !get_frame_time() || !get_frame() || get_subseq() == 3 )
            // condition reversed (old: () || () || () || () != 3)
          {
LABEL_2968:
            play_sfx(24);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 8.0;
            addbullet(this, NULL, 853, x, y, dir, 1, t, 3);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 9.0;
            addbullet(this, NULL, 853, x, y, dir, 1, t, 3);
            h_inerc = 0.0;
            v_inerc = 17.5;
            v_force = 0.75;
          }
          if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            play_sfx(6);
            addbullet(this, NULL, 853, x, y, dir, 1, t, 3);
          }
          return;
        case 604:
          sub10func();
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          {
            if ( field_7D0 > 0 )
            {
              if ( field_7D0 == 1 )
              {
                play_sfx(2);
                t[0] = 30.0;
                t[1] = -4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 854, (double)(116 * (char)dir) + x, y + 105.0, dir, 1,t, 3);
                t[0] = -30.0;
                t[1] = 4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 854, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
              }
              if ( field_7D0 == 6 )
              {
                play_sfx(2);
                t[0] = 45.0;
                t[1] = -4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 854, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
                t[0] = -45.0;
                t[1] = 4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 854, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
              }
              if ( field_7D0 == 11 )
              {
                play_sfx(2);
                t[0] = 60.0;
                t[1] = -4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 854, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
                t[0] = -60.0;
                t[1] = 4.0;
                t[2] = 0.0;
                addbullet(this, NULL, 854, (double)(116 * (char)dir) + x, y + 105.0, dir, 1, t, 3);
              }
              ++field_7D0;
            }
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(8 * (char)dir) + x, y + 176.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 5 )
                field_7D0 = 1;
            }
          }
          else
          {
            set_seq(0);
          }
          return;
        case 605:
          sub10func();
          sub_46AB50(2, 2);
          if ( process() )
          {
            set_seq(0);
            sub_46AB50(2, 60);
          }
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 3 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(44 * (char)dir) + x, y + 138.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() && get_frame() == 6 )
            {
              addbullet(this, NULL, 855, x + 0.0, y + 100.0, dir, 1, 0, 0);
              play_sfx(12);
            }
          }
          return;
        case 606:
          if ( !get_subseq() || get_subseq() == 4 || get_subseq() == 9 )
            sub10func();
          sub_46AB50(2, 2);
          if ( get_subseq() == 1 && field_190 == 1 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 856, x, y, dir, 1, t, 3);
            set_subseq(5);
            reset_forces();
            //sub_4867D0(1, enemy->x);
            //sub_4867F0(1, y);
            //sub_486810(1, 0.5);
            x = enemy->x;
            y = enemy->y;
            return;
          }
          if ( get_subseq() == 2 || get_subseq() == 3 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 5.0 )
              h_inerc = 5.0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_subseq(4);
              reset_forces();
              y = getlvl_height();
              scene_play_sfx(30);
              return;
            }
          }
          if ( get_subseq() == 5 )
          {
            //sub_4867D0(1, enemy->x);
            //sub_4867F0(1, enemy->y);
            x = enemy->x;
            y = enemy->y;
            if ( get_elaps_frames() >= 60 )
            {
              y = enemy->y;
              next_subseq();
              return;
            }
          }
          if ( get_subseq() == 6 )
          {
            if ( 0.0 == field_7DC && dX(dir)/*down_X*/ )
            {
              field_7DC = (double)dX(dir)/*down_X*/;
              v_inerc = v_inerc + 1.0;
            }
            if ( field_7DC > 0.0 && dX(dir)/*down_X*/ < 0 )
            {
              field_7DC = (double)dX(dir)/*down_X*/;
              v_inerc = v_inerc + 1.0;
            }
            if ( field_7DC < 0.0 && dX(dir)/*down_X*/ > 0 )
            {
              field_7DC = (double)dX(dir)/*down_X*/;
              v_inerc = v_inerc + 1.0;
            }
            if ( v_inerc > 15.0 )
              v_inerc = 15.0;
            v_inerc = v_inerc - 0.1000000014901161;
            if ( h_inerc < -6.0 )
              h_inerc = -6.0;
            if ( char_on_ground_down() )
              v_inerc = 0.0;
            //sub_4867D0(1, enemy->x);
            //sub_4867F0(1, enemy->y);
            x = enemy->x;
            if ( --field_7D0 <= 0 )
            {
              if ( !field_7D2 && enemy->x < 640.0 )
              {
                field_7D2 = 1;
                field_7D6 = 1;
                field_7D8 = 1;
              }
              if ( y < 1280.0 )
              {
                play_sfx(22);
                v30 = field_7D2 % 2 == 0;
                t[0] = 0.0;
                t[1] = 180.0;
                t[2] = 1.0;
                if ( v30 )
                {
                  xg = -1;
                  a4e = (double)scene_rand_rng(200) + y - 100.0;
                  v811 = 1380.0;
                }
                else
                {
                  xg = 1;
                  a4e = (double)scene_rand_rng(200) + y - 100.0;
                  v811 = -100.0;
                }
                addbullet(this, NULL, 856, v811, a4e, xg, 1, t, 3);
                field_7D0 = 45 - (4 * ++field_7D2);
                if ( (45 - field_7D0) < 9 )
                  field_7D0 = 9;
              }
            }
            if ( get_elaps_frames() >= 30 && --field_7D4 <= 0 && y < 960.0 )
            {
              if ( field_7D6 % 2 )
              {
                t[0] = 4.0 - (double)scene_rand_rng(8);
                xh = 1;
                t[1] = (double)field_7D6 + 150.0;
                t[2] = 3.0;
                a4f = (double)scene_rand_rng(300) + y - 150.0;
                v816 = -100.0;
              }
              else
              {
                t[0] = 4.0 - (double)scene_rand_rng(8);
                xh = -1;
                t[1] = (double)field_7D6 + 150.0;
                t[2] = 3.0;
                a4f = (double)scene_rand_rng(300) + y - 150.0;
                v816 = 1380.0;
              }
              addbullet(this, NULL, 856, v816, a4f, xh, 1, t, 3);
              field_7D4 = 25 - (2 * ++field_7D6);
              if ( (25 - field_7D4) < 10 )
                field_7D4 = 10;
            }
            if ( get_elaps_frames() >= 60 )
            {
              if ( !(get_elaps_frames() % 14) && y < 1280.0 )
              {
                if ( field_7D8 % 2 )
                {
                  t[0] = 4.0 - (double)scene_rand_rng(8);
                  t[1] = (double)scene_rand_rng(50) + 180.0;
                  xi = 1;
                  t[2] = 2.0;
                  a4g = (double)scene_rand_rng(500) + y - 250.0;
                  v822 = -100.0;
                }
                else
                {
                  t[0] = 4.0 - (double)scene_rand_rng(8);
                  t[1] = (double)scene_rand_rng(50) + 180.0;
                  xi = -1;
                  t[2] = 2.0;
                  a4g = (double)scene_rand_rng(500) + y - 250.0;
                  v822 = 1380.0;
                }
                addbullet(this, NULL, 856, v822, a4g, xi, 1, t, 3);
                ++field_7D8;
              }
              if ( !(get_elaps_frames() % 16) && get_elaps_frames() >= 90 && y < 1280.0 )
              {
                if ( field_7D8 % 2 )
                {
                  t[0] = 4.0 - (double)scene_rand_rng(8);
                  t[1] = (double)scene_rand_rng(50) + 200.0;
                  xj = 1;
                  t[2] = 2.0;
                  a4h = (double)scene_rand_rng(800) + y - 400.0;
                  v826 = -100.0;
                }
                else
                {
                  t[0] = 4.0 - (double)scene_rand_rng(8);
                  t[1] = (double)scene_rand_rng(50) + 200.0;
                  xj = -1;
                  t[2] = 2.0;
                  a4h = (double)scene_rand_rng(800) + y - 400.0;
                  v826 = 1380.0;
                }
                addbullet(this, NULL, 856, v826, a4h, xj, 1, t, 3);
                ++field_7D8;
              }
            }
            if ( get_elaps_frames() >= 300 )
            {
              t[0] = 90.0;
              t[1] = 30.0;
              t[2] = 5.0;
              addbullet(this, NULL, 856, 640.0, y + 100.0, 1, 1, t, 3);
              t[0] = -90.0;
              addbullet(this, NULL, 856, 640.0, y + 100.0, 1, 1, t, 3);
              t[2] = 4.0;
              addbullet(this, NULL, 856, enemy->x, y + 100.0, 1, 1, t, 3);
              next_subseq();
              return;
            }
          }
          if ( get_subseq() == 7 )
          {
            x = enemy->x;
            v_inerc = 40.0;
            if ( y > 1280.0 )
              y = 1280.0;
            if ( get_elaps_frames() >= 40 )
            {
              v_inerc = -30.0;
              v_force = 0.5;
              next_subseq();
              //sub_4867D0(0, enemy->x);
              //sub_4867F0(0, y);
              //sub_486810(0, 0.5);
              return;
            }
          }
          if ( get_subseq() == 8 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_1171:
              next_subseq();
              goto LABEL_106;
            }
          }
          if ( process() )
          {
            set_seq(0);
            sub_46AB50(2, 60);
          }
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(21);
              h_inerc = 60.0;
              /*
              v833 = 0;
              v1107 = 0;
              v_inerc = 16.0;
              v_force = 0.15000001;
              do
              {
                *(float *)&v1280 = (double)v1107 + 30.0;
                v1281 = 15.0;
                v1282 = 1.0;
                if ( *(float *)&v1280 < 0.0 || *(float *)&v1280 > 180.0 )
                {
                  yc = -1;
                  xk = dir;
                }
                else
                {
                  yc = 1;
                  xk = dir;
                }
                addbullet(this, NULL, 821, x, y, xk, yc, (int)&v1280, 3);
                v833 += 36;
                v1107 = v833;
              }
              while ( v833 < 360 );
              */
            }
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
              {
                h_inerc = h_inerc * 0.25;
                v_inerc = 2.0;
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
                goto LABEL_64;
            }
          }
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              play_sfx(22);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 6.0;
              addbullet(this, NULL, 856, x, y, dir, 1, t, 3);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() && get_frame() == 4 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(80 * (char)dir), y + 130.0, dir, 1);
            }
          }
          return;
        case 607:
          sub10func();
          sub_46AB50(2, 2);
          if ( process() )
          {
            set_seq(0);
            sub_46AB50(2, 60);
          }
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(32 * (char)dir) + x, y + 144.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() && get_frame() == 8 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 857, x, y, dir, 1, t, 3);
              field_892 = 360;
              play_sfx(13);
            }
          }
          return;
        case 608:
          sub10func();
          sub_46AB50(2, 2);
          if ( field_7D0 != 1 )
            goto LABEL_2571;
          if ( !(field_7D2 % 3) && field_7D2 <= 180 )
          {
            t[0] = 45.0;
            t[1] = (double)scene_rand_rng(8) + 40.0;
            t[2] = 1.0;
            addbullet(this, NULL, 858, ((double)scene_rand_rng(400) - 1000.0) * (double)dir + enemy->x, (double)scene_rand_rng(100) + 900.0, dir, 1, t, 3);
          }
          if ( !(field_7D2 % 40) )
            play_sfx(17);
          if ( field_7D2 >= 180 )
            goto LABEL_2569;
          field_7D2 = field_7D2 + 1;
LABEL_2571:
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, (double)(21 * (char)dir) + x, y + 142.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
            field_7D0 = 1;
          }
          return;
        case 611:
          sub10func();
          sub_46AB50(2, 2);
          if ( process() )
          {
            set_seq(0);
            sub_46AB50(2, 60);
          }
          if ( get_subseq() || get_frame_time() )
            return;
          if ( get_frame() == 2 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, (double)(32 * (char)dir) + x, y + 144.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( get_frame_time() || get_frame() != 8 )
            return;
          if ( 0.0 == y )
            t[0] = 0.0;
          else
            t[0] = 1.0;
          t[1] = 0.0;
          t[2] = 0.0;
          a4i = y + 100.0;
          v872 = x + 0.0;
          goto LABEL_2615;
        case 612:
          if ( !get_subseq() || get_subseq() == 4 || get_subseq() == 5 )
          {
            sub10func();
            
          }
          if ( get_subseq() < 2 )
          {
            sub_46AB50(2, 2);
            
          }
          if ( get_subseq() != 1 )
            goto LABEL_2630;
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 127, x, 0.0, dir, -1);
          }
          if ( field_190 == 2 || field_190 == 7 || get_border_near() )
            goto LABEL_2628;
          
LABEL_2630:
          if ( get_subseq() != 2 && get_subseq() != 3 )
            goto LABEL_2637;
          h_inerc = h_inerc + 0.1500000059604645;
          if ( h_inerc > 0.0 )
            h_inerc = 0.0;
          v_inerc = v_inerc - 0.5;
          if ( char_on_ground_down() )
          {
            set_subseq(5);
            goto LABEL_951;
          }
          
LABEL_2637:
          if ( get_subseq() == 4 )
          {
            h_inerc = h_inerc - 2.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, x - (double)(77 * (char)dir), y + 144.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
            goto LABEL_1337;
          if ( get_subseq() == 1 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0; //(added here by me)
            addbullet(this, NULL, 862, x, y + 45.0, dir, 1, t, 2);
            scene_add_effect(this, 127, x, y, dir, -1);
            set_vec_speed(0.0, 40.0);
LABEL_1336:
            play_sfx(5);
LABEL_1337:
            if ( get_subseq() == 1 && get_elaps_frames() > 20 )
              set_subseq(4);
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() )
          {
            v30 = get_subseq() == 5;
LABEL_63:
            if ( v30 )
LABEL_64:
              set_seq(0);
          }
          return;
        case 657:
          sub_46AB50(2, 2);
          if ( process() )
          {
            set_seq(9);
            sub_46AB50(2, 60);
            v_force = 0.60000002;
          }
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(32 * (char)dir) + x, y + 144.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() && get_frame() == 8 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 857, x, y, dir, 1, t, 3);
              field_892 = 450;
              play_sfx(13);
            }
          }
          return;
        case 658:
          sub_46AB50(2, 2);
          if ( get_subseq() == 3 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              y = getlvl_height();
              reset_forces();
              set_subseq(3);
              return;
            }
          }
          if ( field_7D0 == 1 )
          {
            if ( !(field_7D2 % 3) && field_7D2 <= 180 )
            {
              t[0] = 45.0;
              t[1] = (double)scene_rand_rng(8) + 40.0;
              t[2] = 1.0;
              addbullet(this, NULL, 858, ((double)scene_rand_rng(400) - 1000.0) * (double)dir + enemy->x, (double)scene_rand_rng(100) + 900.0, dir, 1, t, 3);
            }
            if ( !(field_7D2 % 40) )
              play_sfx(17);
            if ( field_7D2 >= 180 )
            {
LABEL_2569:
              set_subseq(2);
              field_7D0 = 2;
              return;
            }
            field_7D2 = field_7D2 + 1;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, (double)(21 * (char)dir) + x, y + 142.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
            field_7D0 = 1;
          }
          if ( get_subseq() == 2 && !get_frame_time() )
          {
            v484 = get_frame() == 4;
            goto LABEL_1249;
          }
          return;
        case 661:
          sub_46AB50(2, 2);
          if ( process() )
          {
            set_seq(9);
            sub_46AB50(2, 60);
            v_force = 0.60000002;
          }
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(32 * (char)dir) + x, y + 144.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() && get_frame() == 8 )
            {
              if ( 0.0 == y )
                t[0] = 0.0;
              else
                t[0] = 1.0;
              t[1] = 0.0;
              t[2] = 0.0;
              a4i = y + 100.0;
              v872 = x + 0.0;
LABEL_2615:
              addbullet(this, NULL, 861, v872, a4i, dir, 1, t, 3);
              play_sfx(13);
            }
          }
          return;
        case 662:
          if ( get_subseq() == 6 )
          {
            sub10func();
            
          }
          if ( get_subseq() < 2 )
          {
            sub_46AB50(2, 2);
            
          }
          if ( get_subseq() != 1 )
            goto LABEL_2674;
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 127, x, 0.0, dir, -1);
          }
          if ( field_190 == 2 || field_190 == 7 || get_border_near() )
          {
LABEL_2628:
            next_subseq();
            h_inerc = -10.0;
            v_inerc = 14.0;
            return;
          }
          
LABEL_2674:
          if ( get_subseq() == 2 )
            goto LABEL_2680;
          if ( get_subseq() == 3 || get_subseq() == 4 || get_subseq() == 5 )
          {
            if ( get_subseq() == 2 || get_subseq() == 3 )
            {
LABEL_2680:
              h_inerc = h_inerc + 0.1500000059604645;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
            }
            v_inerc = v_inerc - 0.5;
            if ( char_on_ground_down() )
            {
              set_subseq(6);
              goto LABEL_951;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, x, y + 115.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
            goto LABEL_2697;
          if ( get_subseq() == 1 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0; //added by me
            addbullet(this, NULL, 862, x, y + 45.0, dir, 1, t, 2);
            if ( y - getlvl_height() <= 150.0 )
            {
              scene_add_effect(this, 127, x, getlvl_height(), dir, -1);
            }
            set_vec_speed(0.0, 40.0);
            play_sfx(5);
LABEL_2697:
            if ( get_subseq() == 1 && get_elaps_frames() > 20 )
            {
              set_subseq(4);
LABEL_1452:
              h_inerc = h_inerc * 0.5;
            }
          }
          return;
        case 695:
          sub10func();
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
          {
            scene_play_sfx(55);
            scene_add_effect(this, 140, x, y + 100.0, dir, 1);
            scene_add_effect(this, 140, x, y + 100.0, dir, 1);
            scene_add_effect(this, 140, x, y + 100.0, dir, 1);
            scene_add_effect(this, 141, x, y + 100.0, dir, -1);
            scene_add_effect(this, 142, x, y, dir, -1);
          }
          return;
        case 696:
          sub10func();
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            scene_play_sfx(29);
          return;
        case 710:
          if ( !get_subseq() || get_subseq() == 6 )
          {
            sub10func();
            
          }
          if ( get_subseq() == 1 || get_subseq() == 2 )
          {
            if ( field_7D0 == 1 )
            {
              if ( field_7D4 > 60 )
              {
                y = enemy->y;
                dir = -dir;
                t[0] = 0.0;
                t[1] = 35.0;
                t[2] = 0.0;
                addbullet(this, NULL, 900, (double)(640 - 960 * (char)dir), y, dir, 1, t, 3);
                play_sfx(5);
                field_7D0 = 2;
              }
              else
              {
                field_7D4 = field_7D4 + 1;
              }
            }
            if ( field_7D0 == 3 )
            {
              h_inerc = -60.0;
              if ( get_border_near() == dir )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 5.0;
                addbullet(this, NULL, 900, x - (double)(300 * (char)dir), y + 150.0, dir, 1, t, 3);
                field_7D0 = 0;
                set_subseq(3);
                return;
              }
            }
          }
          if ( get_subseq() != 3 || field_7D0 != 1 )
          {
            if ( get_subseq() == 4 || get_subseq() == 5 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_subseq(6);
                goto LABEL_106;
              }
            }
            if ( process() )
            {
              set_seq(700);
            }
            else
            {
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                play_sfx(5);
                t[0] = 0.0;
                t[1] = 35.0;
                t[2] = 0.0;
                addbullet(this, NULL, 900, x, y, dir, 1, t, 3);
              }
              if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 5.0;
                addbullet(this, NULL, 821, x, y, dir, -1, t, 3);
                t[2] = 6.0;
                addbullet(this, NULL, 821, x, y, dir, -1, t, 3);
                /*
                v914 = 0;
                v1108 = 0;
                do
                {
                  *(float *)&v1171 = (double)v1108 + 45.0;
                  v1172 = 15.0;
                  v1173 = 1.0;
                  if ( *(float *)&v1171 < 0.0 || *(float *)&v1171 > 180.0 )
                    addbullet(this, NULL, 821, x, y, dir, -1, (int)&v1171, 3);
                  else
                    addbullet(this, NULL, 821, x, y, dir, 1, (int)&v1171, 3);
                  v914 += 60;
                  v1108 = v914;
                }
                while ( v914 < 480 );
                */
              }
            }
          }
          else
          {
            h_inerc = 10.0;
            v_inerc = -2.0;
            v_force = 0.44999999;
LABEL_2727:
            set_subseq(4);
          }
          return;
        case 720:
          sub10func();
          if ( process() )
            goto LABEL_2939;
          if ( !get_frame_time() && get_frame() == 8 )
          {
            switch ( settings_get()->get_difficulty() )
            {
              case 0:
              /*
                v1142 = (double)scene_rand_rng(360);
                v1116 = 0.0;
                v930 = (float)0.0;
                do
                {
                  *(float *)&v1153 = v930 * 120.0 + v1142;
                  v1154 = 10.0;
                  v1155 = 0.0;
                  v931 = y + 100.0;
                  addbullet(this, NULL, 901, x, v931, dir, 1, (int)&v1153, 3);
                  v1116 = v1116 + 1.0;
                  v930 = v1116;
                }
                while ( v1116 < 3.0 );
                v1117 = 0.0;
                v932 = (float)0.0;
                do
                {
                  *(float *)&v1153 = v932 * 120.0 + 60.0 + v1142;
                  v1154 = 6.0;
                  v1155 = 0.0;
                  v933 = y + 100.0;
                  addbullet(this, NULL, 901, x, v933, -dir, 1, (int)&v1153, 3);
                  v1117 = v1117 + 1.0;
                  v932 = v1117;
                }
                while ( v1117 < 3.0 );*/
                goto LABEL_2775;
              case 1:
              /*
                v1141 = (double)scene_rand_rng(360);
                v1114 = 0.0;
                v926 = (float)0.0;
                do
                {
                  *(float *)&v1153 = v926 * 90.0 + v1141;
                  v1154 = 10.0;
                  v1155 = 0.0;
                  v927 = y + 100.0;
                  addbullet(this, NULL, 901, x, v927, dir, 1, (int)&v1153, 3);
                  v1114 = v1114 + 1.0;
                  v926 = v1114;
                }
                while ( v1114 < 4.0 );
                v1115 = 0.0;
                v928 = (float)0.0;
                do
                {
                  *(float *)&v1153 = v928 * 90.0 + 45.0 + v1141;
                  v1154 = 6.0;
                  v1155 = 0.0;
                  v929 = y + 100.0;
                  addbullet(this, NULL, 901, x, v929, -dir, 1, (int)&v1153, 3);
                  v1115 = v1115 + 1.0;
                  v928 = v1115;
                }
                while ( v1115 < 4.0 );*/
                play_sfx(20);
                break;
              case 2:
              /*
                v1140 = (double)scene_rand_rng(360);
                v1112 = 0.0;
                v922 = (float)0.0;
                do
                {
                  *(float *)&v1153 = v922 * 72.0 + v1140;
                  v1154 = 10.0;
                  v1155 = 0.0;
                  v923 = y + 100.0;
                  addbullet(this, NULL, 901, x, v923, dir, 1, (int)&v1153, 3);
                  v1112 = v1112 + 1.0;
                  v922 = v1112;
                }
                while ( v1112 < 5.0 );
                v1113 = 0.0;
                v924 = (float)0.0;
                do
                {
                  *(float *)&v1153 = v924 * 72.0 + 36.0 + v1140;
                  v1154 = 6.0;
                  v1155 = 0.0;
                  v925 = y + 100.0;
                  addbullet(this, NULL, 901, x, v925, -dir, 1, (int)&v1153, 3);
                  v1113 = v1113 + 1.0;
                  v924 = v1113;
                }
                while ( v1113 < 5.0 );*/
                play_sfx(20);
                break;
              case 3:
              /*
                v1139 = (double)scene_rand_rng(360);
                v1109 = 0.0;
                v915 = (float)0.0;
                do
                {
                  *(float *)&v1153 = v915 * 60.0 + v1139;
                  v1154 = 10.0;
                  v1155 = 3.0;
                  v916 = y + 100.0;
                  addbullet(this, NULL, 901, x, v916, dir, 1, (int)&v1153, 3);
                  v1109 = v1109 + 1.0;
                  v915 = v1109;
                }
                while ( v1109 < 6.0 );
                v1110 = 0.0;
                for ( i = (float)0.0; ; i = v1110 )
                {
                  *(float *)&v1153 = i * 60.0 + v1139;
                  v1154 = 10.0;
                  v1155 = 0.0;
                  v918 = y + 100.0;
                  addbullet(this, NULL, 901, x, v918, dir, 1, (int)&v1153, 3);
                  v1110 = v1110 + 1.0;
                  v919 = 6.0;
                  if ( v1110 >= 6.0 )
                    break;
                }
                v1111 = 0.0;
                v920 = (float)0.0;
                do
                {
                  *(float *)&v1153 = v920 * 60.0 + 30.0 + v1139;
                  v1154 = v919;
                  v1155 = 0.0;
                  v921 = y + 100.0;
                  addbullet(this, NULL, 901, x, v921, -dir, 1, (int)&v1153, 3);
                  v1111 = v1111 + 1.0;
                  v919 = 6.0;
                  v920 = v1111;
                }
                while ( v1111 < 6.0 );*/
                play_sfx(20);
                break;
              default:
LABEL_2775:
                play_sfx(20);
                break;
            }
          }
          return;
        case 721:
          if ( !get_subseq() || get_subseq() == 5 )
          {
            sub10func();
            
          }
          if ( get_subseq() == 1 || get_subseq() == 2 )
          {
            v_inerc = v_inerc - v_force;
            h_inerc = h_inerc * 0.9800000190734863;
            if ( 0.0 > v_inerc )
              v_inerc = 0.0;
          }
          if ( get_subseq() == 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_1319:
              set_subseq(5);
              goto LABEL_951;
            }
          }
          if ( process() )
            goto LABEL_2939;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v_inerc = 17.5;
            h_inerc = (double)scene_rand_rng(10) - 5.0;
            v_force = 0.5;
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
            goto LABEL_2796;
          if ( get_subseq() == 3 )
          {
            reset_forces();
LABEL_2796:
            if ( get_subseq() == 3 && !get_frame_time() )
            {
              if ( get_frame() == 8 )
              {
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                  /*
                    v1146 = (double)scene_rand_rng(360);
                    v1125 = 0.0;
                    v951 = (float)0.0;
                    do
                    {
                      *(float *)&v1150 = v951 * 120.0 + v1146;
                      v1151 = 10.0;
                      v1152 = 0.0;
                      v952 = y + 100.0;
                      addbullet(this, NULL, 901, x, v952, dir, 1, (int)&v1150, 3);
                      v1125 = v1125 + 1.0;
                      v951 = v1125;
                    }
                    while ( v1125 < 3.0 );
                    v1126 = 0.0;
                    v953 = (float)0.0;
                    do
                    {
                      *(float *)&v1150 = v953 * 120.0 + 60.0 + v1146;
                      v1151 = 6.0;
                      v1152 = 0.0;
                      v954 = y + 100.0;
                      addbullet(this, NULL, 901, x, v954, -dir, 1, (int)&v1150, 3);
                      v1126 = v1126 + 1.0;
                      v953 = v1126;
                    }
                    while ( v1126 < 3.0 );*/
                    break;
                  case 1:
                  /*
                    v1145 = (double)scene_rand_rng(360);
                    v1123 = 0.0;
                    v947 = (float)0.0;
                    do
                    {
                      *(float *)&v1150 = v947 * 90.0 + v1145;
                      v1151 = 10.0;
                      v1152 = 0.0;
                      v948 = y + 100.0;
                      addbullet(this, NULL, 901, x, v948, dir, 1, (int)&v1150, 3);
                      v1123 = v1123 + 1.0;
                      v947 = v1123;
                    }
                    while ( v1123 < 4.0 );
                    v1124 = 0.0;
                    v949 = (float)0.0;
                    do
                    {
                      *(float *)&v1150 = v949 * 90.0 + 45.0 + v1145;
                      v1151 = 6.0;
                      v1152 = 0.0;
                      v950 = y + 100.0;
                      addbullet(this, NULL, 901, x, v950, -dir, 1, (int)&v1150, 3);
                      v1124 = v1124 + 1.0;
                      v949 = v1124;
                    }
                    while ( v1124 < 4.0 );*/
                    break;
                  case 2:
                  /*
                    v1144 = (double)scene_rand_rng(360);
                    v1121 = 0.0;
                    v943 = (float)0.0;
                    do
                    {
                      *(float *)&v1150 = v943 * 72.0 + v1144;
                      v1151 = 10.0;
                      v1152 = 0.0;
                      v944 = y + 100.0;
                      addbullet(this, NULL, 901, x, v944, dir, 1, (int)&v1150, 3);
                      v1121 = v1121 + 1.0;
                      v943 = v1121;
                    }
                    while ( v1121 < 5.0 );
                    v1122 = 0.0;
                    v945 = (float)0.0;
                    do
                    {
                      *(float *)&v1150 = v945 * 72.0 + 36.0 + v1144;
                      v1151 = 6.0;
                      v1152 = 0.0;
                      v946 = y + 100.0;
                      addbullet(this, NULL, 901, x, v946, -dir, 1, (int)&v1150, 3);
                      v1122 = v1122 + 1.0;
                      v945 = v1122;
                    }
                    while ( v1122 < 5.0 );*/
                    break;
                  case 3:
                  /*
                    v1143 = (double)scene_rand_rng(360);
                    v1118 = 0.0;
                    v936 = (float)0.0;
                    do
                    {
                      *(float *)&v1150 = v936 * 60.0 + v1143;
                      v1151 = 10.0;
                      v1152 = 3.0;
                      v937 = y + 100.0;
                      addbullet(this, NULL, 901, x, v937, dir, 1, (int)&v1150, 3);
                      v1118 = v1118 + 1.0;
                      v936 = v1118;
                    }
                    while ( v1118 < 6.0 );
                    v1119 = 0.0;
                    for ( j = (float)0.0; ; j = v1119 )
                    {
                      *(float *)&v1150 = j * 60.0 + v1143;
                      v1151 = 10.0;
                      v1152 = 0.0;
                      v939 = y + 100.0;
                      addbullet(this, NULL, 901, x, v939, dir, 1, (int)&v1150, 3);
                      v1119 = v1119 + 1.0;
                      v940 = 6.0;
                      if ( v1119 >= 6.0 )
                        break;
                    }
                    v1120 = 0.0;
                    v941 = (float)0.0;
                    do
                    {
                      *(float *)&v1150 = v941 * 60.0 + 30.0 + v1143;
                      v1151 = v940;
                      v1152 = 0.0;
                      v942 = y + 100.0;
                      addbullet(this, NULL, 901, x, v942, -dir, 1, (int)&v1150, 3);
                      v1120 = v1120 + 1.0;
                      v940 = 6.0;
                      v941 = v1120;
                    }
                    while ( v1120 < 6.0 );*/
                    break;
                  default:
                    break;
                }
                play_sfx(20);
              }
              if ( !get_frame_time() )
              {
                v484 = get_frame() == 15;
LABEL_1249:
                if ( v484 )
                  v_force = 0.5;
              }
            }
          }
          return;
        case 730:
          sub10func();
          if ( get_subseq() == 1 && get_elaps_frames() > 60 )
          {
LABEL_650:
            next_subseq();
          }
          else
          {
            if ( process() )
              set_seq(700);
            if ( !get_subseq() )
            {
              if ( get_frame() <= 4 && !(get_elaps_frames() % 3) )
              {
                field_7DC = field_7DC - 16.0;
                if ( field_7DC <= -180.0 )
                  field_7DC = field_7DC + 360.0;
                t[0] = field_7DC;
                t[1] = 15.0;
                t[2] = 1.0;
                if ( t[0] < 0.0 || t[0] > 180.0 )
                  addbullet(this, NULL, 821, x, y, dir, -1, t, 3);
                else
                  addbullet(this, NULL, 821, x, y, dir, 1, t, 3);
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                t[0] = 0.0;
                t[1] = 15.0;
                t[2] = 0.0;
                addbullet(this, NULL, 902, (double)(80 * (char)dir) + x, y, dir, 1, t, 3);
                play_sfx(10);
              }
            }
          }
          return;
        case 740:
          if ( !get_subseq() || get_subseq() == 5 )
            sub10func();
          if ( get_subseq() == 1 )
          {
            ++field_7D2;
            if ( --field_7D4 <= 0 )
            {
              field_7D8 -= 5;
              if ( field_7D8 < 10 )
                field_7D8 = 10;
              field_7D4 = field_7D8;
              t[1] = (double)scene_rand_rng(30) + 60.0;
              if ( t[1] >= 90.0 )
                t[1] = 90.0;
              t[2] = 1.0;
              play_sfx(22);
              v958 = (++field_7D6 & 0x80000001) == 0;
              if ( ++field_7D6 & 0x80000001 < 0 )
                v958 = (((++field_7D6 & 0x80000001) - 1) | 0xFFFFFFFE) == -1;
              if ( v958 )
                t[0] = (double)scene_rand_rng(40) * 0.1000000014901161 + dash_angle - 2.0;
              else
                t[0] = dash_angle + 180.0 + (double)scene_rand_rng(40) * 0.1000000014901161 - 2.0;
              addbullet(this, NULL, 903, 
                (double)scene_rand_rng(100) + ((cos_deg(180.0 - t[0])) * 1680.0 * (double)dir + x) - 50.0, 
                (double)scene_rand_rng(100) + (sin_deg(180.0 - t[0]) * 1680.0 + y + 100.0) - 50.0,
                dir, 1, t, 3);
              if ( !(field_7D6 % 3) )
              {
                t[1] = (double)field_7D8 + (double)field_7D8 + 100.0;
                if ( t[1] >= 100.0 )
                  t[1] = 100.0;
                t[2] = 2.0;
                if ( scene_rand_rng(100) >= 0x32 )
                  t[0] = dash_angle + 180.0 + (double)scene_rand_rng(40) * 0.1000000014901161 - 2.0;
                else
                  t[0] = (double)scene_rand_rng(40) * 0.1000000014901161 + dash_angle - 2.0;

                addbullet(this, NULL, 903,
                  (double)scene_rand_rng(300) + ((cos_deg(180.0 - t[0])) * 1680.0 * (double)dir + x) - 150.0, 
                  (double)scene_rand_rng(300) + (sin_deg(180.0 - t[0]) * 1680.0 + y + 100.0) - 150.0,
                dir, 1, t, 3);
              }
            }
            if ( !field_7D0 )
            {
              h_inerc = (640.0 - x) * 0.2000000029802322 * (double)dir;
              v_inerc = 0.2000000029802322 * (250.0 - y);
            }
            if ( field_7D8 == 10 )
            {
              next_subseq();
              field_7D6 = 0;
              field_7D8 = 60;
              return;
            }
          }
          if ( get_subseq() != 2 )
            goto LABEL_2901;
          if ( !(field_7D2 % 60) )
            play_sfx(/*chrt, */10);
          ++field_7D2;
          --field_7D4;
          --field_7D6;
          field_7DC = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          dash_angle = dash_angle + 1.0;
          switch ( settings_get()->get_difficulty() )
          {
            case 0:
            case 1:
              v982 = 0.75;
              goto LABEL_2873;
            case 2:
              v982 = 1.0;
              goto LABEL_2873;
            case 3:
              v982 = 1.5;
LABEL_2873:
              set_vec_speed(field_7DC, v982);
              break;
            default:
              break;
          }
          if ( !(field_7D2 % 20) )
          {
            t[0] = (double)scene_rand_rng(40) * 0.1000000014901161 + dash_angle - 2.0;
            t[1] = (double)scene_rand_rng(30) + 60.0;
            t[2] = 6.0;
            addbullet(this, NULL, 903, 
              (double)scene_rand_rng(100) + ((cos_deg(180.0 - t[0])) * 1680.0 * (double)dir + x) - 50.0,
              (double)scene_rand_rng(100) + (sin_deg(180.0 - t[0]) * 1680.0 + y + 100.0) - 50.0,
            dir, 1, t, 3);
          }
          if ( settings_get()->get_difficulty() == 2 )
          {
            if ( !(field_7D2 % 360) )
            {
              play_sfx(0);
              t[0] = (double)scene_rand_rng(30) + dash_angle - 15.0;
              t[1] = 30.0;
              t[2] = 9.0;
              addbullet(this, NULL, 903, 
                (double)scene_rand_rng(100) + ((cos_deg(180.0 - t[0])) * 600.0 * (double)dir + x) - 50.0,
                (double)scene_rand_rng(100) + (sin_deg(180.0 - t[0]) * 600.0 + y + 100.0) - 50.0,
              dir, 1, t, 3);
            }
            if ( field_7D2 % 360 == 180 )
            {
              play_sfx(0);
              t[0] = dash_angle + 180.0 + (double)scene_rand_rng(30) - 15.0;
              t[1] = 30.0;
              t[2] = 9.0;
              a4j = (double)scene_rand_rng(100) + (sin_deg(180.0 - t[0]) * 600.0 + y + 100.0) - 50.0;
              v1009 = (double)scene_rand_rng(100) + ((cos_deg(180.0 - t[0])) * 600.0 * (double)dir + x) - 50.0;
              goto LABEL_2886;
            }
          }
          else if ( settings_get()->get_difficulty() == 3 )
          {
            if ( !(field_7D2 % 180) )
            {
              play_sfx(0);
              t[0] = (double)scene_rand_rng(30) + dash_angle - 15.0;
              t[1] = 30.0;
              t[2] = 9.0;
              addbullet(this, NULL, 903, 
                (double)scene_rand_rng(100) + ((cos_deg(180.0 - t[0])) * 600.0 * (double)dir + x) - 50.0, 
                (double)scene_rand_rng(100) + (sin_deg(180.0 - t[0]) * 600.0 + y + 100.0) - 50.0, 
              dir, 1, t, 3);
            }
            if ( field_7D2 % 180 == 90 )
            {
              play_sfx(0);
              t[0] = dash_angle + 180.0 + (double)scene_rand_rng(30) - 15.0;
              t[1] = 30.0;
              t[2] = 9.0;
              a4j = (double)scene_rand_rng(100) + (sin_deg(180.0 - t[0]) * 600.0 + y + 100.0) - 50.0;
              v1009 = (double)scene_rand_rng(100) + ((cos_deg(180.0 - t[0])) * 600.0 * (double)dir + x) - 50.0;
LABEL_2886:
              addbullet(this, NULL, 903, v1009, a4j, dir, 1, t, 3);
              goto LABEL_2887;
            }
          }
LABEL_2887:
          if ( field_7D4 <= 0 )
          {
            field_7D4 = 10;
            play_sfx(22);
            t[1] = (double)scene_rand_rng(30) + 120.0;
            t[2] = 3.0;
            if ( scene_rand_rng(100) >= 0x32 )
              t[0] = dash_angle + 180.0 + (double)scene_rand_rng(40) * 0.1000000014901161 - 2.0;
            else
              t[0] = (double)scene_rand_rng(40) * 0.1000000014901161 + dash_angle - 2.0;
            addbullet(this, NULL, 903, 
              (double)scene_rand_rng(300) + ((cos_deg(180.0 - t[0])) * 1680.0 * (double)dir + x) - 150.0, 
              (double)scene_rand_rng(300) + (sin_deg(180.0 - t[0]) * 1680.0 + y + 100.0) - 150.0, 
            dir, 1, t, 3);
          }
          if ( !field_7D6 )
          {
            field_7D8 -= 10;
            if ( field_7D8 < 5 )
              field_7D8 = 5;
            field_7D6 = field_7D8;
            t[1] = (double)field_7D8 + (double)field_7D8 + 100.0;
            if ( t[1] >= 180.0 )
              t[1] = 180.0;
            t[2] = 2.0;
            if ( scene_rand_rng(100) >= 0x32 )
              t[0] = dash_angle + 180.0 + (double)scene_rand_rng(40) * 0.1000000014901161 - 2.0;
            else
              t[0] = (double)scene_rand_rng(40) * 0.1000000014901161 + dash_angle - 2.0;
            addbullet(this, NULL, 903, 
              (double)scene_rand_rng(300) + ((cos_deg(180.0 - t[0])) * 1680.0 * (double)dir + x) - 150.0, 
              (double)scene_rand_rng(300) + (sin_deg(180.0 - t[0]) * 1680.0 + y + 100.0) - 150.0, 
            dir, 1, t, 3);
          }
LABEL_2901:
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            field_7D4 = 60;
            field_7D6 = 60;
            field_7D8 = 60;
            dash_angle = 0.0;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 903, x, y, dir, 1, t, 3);
            t[2] = 4.0;
            addbullet(this, NULL, 903, x, y + 100.0, dir, 1, t, 3);
            t[2] = 5.0;
            addbullet(this, NULL, 903, x, y + 100.0, dir, 1, t, 3);
            dir = -1;
            play_sfx(21);
          }
          break;
        default:
          goto LABEL_2960;
      }
    }
  }
}




// NOTE: taken from marisa.cpp
void char_aya::func20()
{
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
                int8_t mx = (weather_id == WEATHER_TEMPEST) + 2;
                if ( border_escape_air()
                        || fwd_dash_air(cprior, cu, mx, 2)
                        || bkg_dash_air(cprior, cu, mx, 2)
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

void char_aya::set_seq_params()
{
  if ( get_seq() > 500 )
  {
    if ( get_seq() <= 791 )
    {
      if ( get_seq() == 791 )
      {
LABEL_68:
        reset_forces();
        return;
      }
      switch ( get_seq() )
      {
        case 502:
          field_18C = 0;
          goto LABEL_28;
        case 505:
        case 506:
          field_18C = 4;
          goto LABEL_28;
        case 507:
        case 508:
          field_18C = 4;
          field_190 = 0;
          h_inerc = h_inerc * 0.25;
          v_inerc = 0.25 * v_inerc;
          goto LABEL_29;
        case 510:
        case 511:
          field_18C = 8;
          goto LABEL_28;
        case 520:
        case 521:
        case 522:
        case 523:
          field_18C = 1;
          goto LABEL_58;
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
          return;
        case 529:
          field_18C = 5;
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_194 = 1;
          return;
        case 530:
        case 531:
        case 532:
        case 533:
          field_18C = 9;
          reset_forces();
          field_190 = 1;
          field_49A = 0;
          return;
        case 540:
          field_18C = 2;
          goto LABEL_63;
        case 545:
          field_18C = 6;
LABEL_65:
          field_194 = 1;
          h_inerc = 0.0;
          field_190 = 0;
          v_inerc = 0.0;
          return;
        case 546:
          h_inerc = 0.0;
          field_194 = 0;
          field_190 = 0;
          v_inerc = 0.0;
          field_18C = 6;
          return;
        case 550:
        case 551:
        case 552:
        case 553:
          field_18C = 10;
          field_7D0 = 0;
          field_194 = 1;
          field_190 = 0;
          goto LABEL_68;
        case 554:
          field_18C = 10;
LABEL_70:
          field_194 = 1;
          field_190 = 0;
          return;
        case 560:
        case 561:
          field_18C = 3;
          goto LABEL_72;
        case 562:
        case 563:
          v_force = 0.0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 0;
          field_18C = 3;
          h_inerc = h_inerc * 0.1000000014901161;
          v_inerc = 0.1000000014901161 * v_inerc;
          return;
        case 565:
        case 567:
          field_18C = 7;
LABEL_72:
          field_7D0 = 0;
          field_7D2 = 0;
          reset_forces();
          field_190 = 0;
          return;
        case 570:
        case 571:
          field_18C = 11;
          reset_forces();
          field_190 = 0;
          return;
        case 573:
          field_18C = 11;
          v_force = 0.0;
          field_190 = 0;
          h_inerc = h_inerc * 0.1500000059604645;
          v_inerc = 0.1500000059604645 * v_inerc;
          return;
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
          return;
        case 603:
LABEL_63:
          field_190 = 0;
          reset_forces();
          v_force = 0.0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          h_inerc = h_inerc * 0.25;
          v_inerc = 0.25 * v_inerc;
          return;
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
          return;
        case 612:
        case 662:
LABEL_58:
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_7D0 = 0;
          field_194 = 1;
          return;
        case 710:
        case 720:
        case 721:
        case 730:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          reset_forces();
          return;
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
          return;
        default:
          goto LABEL_83;
      }
      goto LABEL_83;
    }
    if ( (get_seq() - 797) && (get_seq() - 797) != 1 )
    {
LABEL_83:
      char_c::set_seq_params();
      return;
    }
    reset_forces();
    h_inerc = 6.0;
    v_inerc = -30.0;
    field_7D0 = 0;
    play_sfx(14);
  }
  else
  {
    if ( get_seq() != 500 )
    {
      if ( get_seq() > 214 )
      {
        switch ( get_seq() )
        {
          case 217:
            goto LABEL_10;
          case 300:
          case 301:
          case 303:
          case 320:
          case 321:
          case 330:
            if ( !field_49A )
              reset_forces();
            field_190 = 0;
            field_194 = 1;
            return;
          case 302:
            if ( !field_49A )
              reset_forces();
            field_190 = 0;
            field_49A = 0;
            h_inerc = 0.0;
            field_194 = 1;
            not_charge_attack = 1;
            return;
          case 304:
            field_49A = 0;
            field_194 = 1;
            field_190 = 0;
            reset_forces();
            not_charge_attack = 1;
            return;
          case 305:
            v_inerc = 0.0;
            h_inerc = 17.5;
            v_force = 0.0;
            goto LABEL_19;
          case 306:
            field_7D0 = 0;
            field_190 = 0;
            field_194 = 1;
            return;
          case 307:
            h_inerc = 0.0;
            field_7D0 = 0;
            v_inerc = 0.0;
            field_190 = 0;
            v_force = 0.0;
            field_194 = 1;
            field_7DC = 25.0;
            return;
          case 308:
            goto LABEL_65;
          case 309:
            goto LABEL_70;
          case 310:
            h_inerc = 0.0;
            field_7D0 = 0;
            v_inerc = 0.0;
            field_190 = 0;
            field_194 = 99;
            v_force = 0.5;
            return;
          case 322:
            if ( !field_49A )
              reset_forces();
            field_190 = 0;
            field_49A = 0;
            h_inerc = 0.0;
            field_194 = 1;
            return;
          case 400:
          case 401:
          case 410:
          case 412:
            field_190 = 0;
            reset_forces();
            goto LABEL_27;
          case 402:
            goto LABEL_28;
          case 404:
          case 406:
            field_190 = 0;
            h_inerc = h_inerc * 0.25;
            v_inerc = 0.25 * v_inerc;
            v_force = 0.5;
            goto LABEL_27;
          case 408:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
            {
              field_49A = 0;
              h_inerc = 17.5;
              field_7D0 = 0;
              field_194 = 1;
              v_inerc = 0.0;
              field_190 = 0;
            }
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 6 )
              play_sfx(27);
            return;
          case 409:
            field_49A = 0;
            v_force = 0.34999999;
            field_7D0 = 0;
            field_190 = 0;
            field_194 = 1;
            return;
          case 411:
            field_190 = 0;
            reset_forces();
            goto LABEL_45;
          case 414:
          case 416:
            v_force = 0.5;
            field_190 = 0;
            h_inerc = h_inerc * 0.25;
            v_inerc = 0.25 * v_inerc;
LABEL_27:
            field_7D0 = 0;
            field_7D2 = 0;
            field_7D6 = 0;
            not_charge_attack = 1;
            return;
          case 415:
            v_force = 0.5;
            field_190 = 0;
            h_inerc = h_inerc * 0.25;
            v_inerc = 0.25 * v_inerc;
LABEL_45:
            field_7D0 = 0;
            field_7D2 = 0;
            field_7D6 = 0;
            not_charge_attack = 0;
            return;
          case 418:
            v_inerc = 0.0;
            v_force = 0.0;
            field_7DC = 25.0;
LABEL_19:
            field_49A = 0;
            field_190 = 0;
            field_194 = 1;
            return;
          default:
            goto LABEL_83;
        }
      }
      else
      {
        if ( get_seq() == 214 )
        {
LABEL_10:
          reset_ofs();
          h_inerc = 0.0;
          field_7D6 = 0;
          v_inerc = 0.0;
          v_force = 0.60000002;
          x_off = 0.0;
          y_off = 95.0;
          field_7DC = 12.0;
          field_7EC = 0.0;
          return;
        }
        if ( !(get_seq() - 4) )
        {
          h_inerc = 5.5;
          return;
        }
        if ( (get_seq() - 4) == 1 )
        {
          h_inerc = -5.5;
          return;
        }
      }
      goto LABEL_83;
    }
    field_18C = 0;
LABEL_28:
    field_190 = 0;
    reset_forces();
LABEL_29:
    field_7D2 = 0;
    field_7D6 = 0;
    field_7D0 = 0;
    field_7D8 = 0;
  }
}
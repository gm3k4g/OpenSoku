#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "sakuya.h"
#include <math.h>

char_sakuya::char_sakuya(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_SAKUYA;
	pgp->load_dat("sakuya",pal);
	char_loadsfx("sakuya");
	cards_load_cards(&chr_cards,"sakuya");
	load_face("sakuya");
	load_spells("sakuya");
	stand_gfx->init(this,"sakuya");
}

void char_sakuya::init_vars()
{
  char_c::init_vars();
  field_138 = -6.0;
  field_892 = 0;
  field_890 = 0;
  field_894 = 0;
  field_896 = 0;
  field_898 = 0;
  field_89A = 0;
  field_89C = 0;
}
/*
c_bullet *char_sakuya::new_bullet()
{
    c_bullet *tmp = new sakuya_bullets();
    return tmp;
}
*/
void char_sakuya::func10()
{
  x_delta = 0;
  y_delta = 94;

  double move_val = 0.0;

  float t[3];
  t[0] = 0.0;
  t[1] = 0.0;
  t[2] = 0.0;

  float tt[4];
  tt[0] = 0.0;
  tt[1] = 0.0;
  tt[2] = 0.0;
  tt[3] = 0.0;

  int v17 = 0;
  double v31 = 0.0;
  double v91 = 0.0;
  double v94 = 0.0;
  double v98 = 0.0;
  bool v503 = false;
  bool v490 = false;
  double v1650 = 0.0;

  double v1581 = 0.0;
  double v603 = 0.0;

  double v1582 = 0.0;
  double v1067 = 0.0;
  double v1093 = 0.0;

  int v1565 = 0;
  double v1566 = 0.0;

  double v289 = 0.0;
  bool v458 = false;

  if ( get_seq() > 149 && get_seq() < 159 && !bbarrier_show )
  {
    bbarrier_show = 1;
    if ( get_seq() > 149 && get_seq() < 154 )
    {
      addbullet(this, NULL, 998, (double)(57 * (char)dir) + x, y + 94., dir, 1, 0, 0);
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
    if ( enemy->shader_type == 1 && !field_84C )
      enemy->shader_type = 0.0;
    if ( field_890 || field_894 )
      field_892 = 0;
    if ( enemy->health <= 0 || health <= 0 || (char_is_shock()) )
      field_892 = 0;
    if ( get_seq() >= 600 && get_seq() <= 689 && (get_seq() != 601 || get_subseq() < 4) )
      field_892 = 0;
    if ( !(field_892 % 2) )
      field_4A6 = 1;
    --field_892;
  }
  v17 = 2;
  if ( field_890 > 0 )
  {
    spell_energy = max_spell_energy;
    field_54C = 0.0;
    field_51C = 2;
    field_520 = 2;
    field_4A6 = 2;
    enemy->shader_type = 1;
    --field_890;
    if ( field_892 || field_894 )
      field_890 = 0;
    if ( get_seq() >= 600 && get_seq() <= 689 && !get_subseq() && !get_frame() )
      field_890 = 0;
    if ( enemy->health <= 0 || health <= 0 )
      field_890 = 0;
    if ( field_890 <= 0 )
      enemy->shader_type = 0.0;
  }
  if ( field_894 > 0 )
  {
    enemy->hit_stop = 2;
    enemy->shader_type = 1;
    --field_894;
    if ( field_892 || field_890 )
      field_894 = 0;
    if ( enemy->health <= 0 || health <= 0 )
      field_894 = 0;
    if ( field_894 <= 0 )
      enemy->shader_type = 0.0;
  }
  if ( field_898 > 0 )
  {
    limit_multiply = 0.0;
    field_540 = 0.25;
    if ( --field_898 < 0 )
      field_898 = 0;
    if ( enemy->health <= 0 || health <= 0 )
      field_898 = 0;
  }
  if ( hit_stop || enemy->time_stop )
    return;
  if ( get_seq() <= 300 )
  {
    if ( get_seq() == 300 )
    {
LABEL_623:
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
        if ( !get_frame_time() && get_frame() == 3 )
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
            goto LABEL_68;
          goto LABEL_69;
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
            set_seq(2);
          return;
        case 2:
          sub10func();
          if ( field_49A )
          {
LABEL_69:
            if ( 0.0 < h_inerc )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
              {
                reset_forces();
                field_49A = 0;
              }
            }
            if ( 0.0 <= h_inerc || (h_inerc = h_inerc + 0.5, h_inerc <= 0.0) )
            {
LABEL_142:
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
LABEL_68:
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
          if ( process() && !get_frame() )
            set_seq(0);
          return;
        case 4:
          sub10func();
          char_h_move(6.0);
          process();
          return;
        case 5:
          sub10func();
          char_h_move(-6.0);
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
          if ( !(get_subseq() < 0 | get_subseq() == 0) )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_141;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v31 = 0.0;
          goto LABEL_137;
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
          if ( !(get_subseq() < 0 | get_subseq() == 0) )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_141;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v31 = 5.0;
          goto LABEL_137;
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
          if ( !(get_subseq() < 0 | get_subseq() == 0) )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_141;
          }
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v31 = -5.0;
LABEL_137:
            char_h_move(v31);
            v_inerc = 15.0;
            v_force = 0.69999999;
            field_49A = 0;
          }
          return;
        case 9:
          if ( 0.0 == v_force )
            v_force = 0.60000002;
          v_inerc = v_inerc - v_force;
          if ( !char_on_ground_down() )
            goto LABEL_142;
LABEL_141:
          move_val = 10;
          goto LABEL_2913;
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
          if ( !get_subseq() && get_frame() <= 3 || get_subseq() == 2 )
            sub10func();
          if ( get_subseq() < 2 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_648;
          }
          if ( !process() )
            goto LABEL_158;
          if ( controlling_type == 2 )
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
LABEL_158:
            if ( get_subseq() == 2 && get_frame() == 1 && !get_frame_time() )
            {
              if ( enemy->x < (double)x )
                dir = -1;
              if ( enemy->x > (double)x )
                dir = 1;
            }
            if ( !get_subseq() && get_frame() == 4 && !get_frame_time() )
            {
              v_inerc = 8.0;
              h_inerc = 12.5;
              v_force = 0.69999999;
            }
          }
          return;
        case 198:
          if ( !get_subseq() && get_frame() <= 3 || get_subseq() == 2 )
            sub10func();
          if ( get_subseq() < 2 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              y = getlvl_height();
              reset_forces();
              set_subseq(2);
              return;
            }
          }
          if ( !process() )
            goto LABEL_181;
          if ( controlling_type == 2 )
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
LABEL_181:
            if ( get_subseq() == 2 && get_frame() == 3 && !get_frame_time() )
            {
              if ( enemy->x < (double)x )
                dir = -1;
              if ( enemy->x > (double)x )
                dir = 1;
            }
            if ( !get_subseq() && get_frame() == 4 && !get_frame_time() )
            {
              v_inerc = 8.0;
              h_inerc = -12.5;
              v_force = 0.69999999;
            }
          }
          return;
        case 199:
          sub10func();
          if ( !process() )
            goto LABEL_197;
          if ( controlling_type == 2 )
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
LABEL_197:
            if ( !get_subseq() && get_frame() == 9 && !get_frame_time() )
            {
              if ( enemy->x < (double)x )
                dir = -1;
              if ( enemy->x > (double)x )
                dir = 1;
            }
          }
          return;
        case 200:
          sub10func();
          field_49A = 1;
          if ( h_inerc > 11.0 )
          {
            h_inerc = h_inerc - 0.75;
            if ( h_inerc < 11.0 )
              h_inerc = 11.0;
          }
          process();
          if ( get_subseq() != 1 )
            goto LABEL_218;
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          if ( dY() >= 0 )
          {
            if ( (dX(dir) > 0 || ++field_7D0 <= 5) && ++field_7D0 <= 45 )
            {
LABEL_218:
              if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
              {
                char_h_move(15.0);
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
          if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
          {
            char_h_move(0.0);
          }
          if ( !char_on_ground_flag() )
          {
            h_inerc = h_inerc + 10.0;
            if ( h_inerc > -10.0 )
              h_inerc = -10.0;
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
          }
          if ( get_subseq() < 3 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_239;
          }
          if ( process() )
            goto LABEL_578;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            char_h_move(-50.0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v_inerc = 4.0;
            v_force = 0.60000002;
            char_h_move(-30.0);
            scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
            scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
            scene_play_sfx(31);
          }
          return;
        case 202:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_251;
          if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          process();
          if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
          {
            field_7D0 = 0;
            char_h_move(11.0);
            v_inerc = 5.0;
            v_force = 0.60000002;
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
            if ( get_subseq() < 3 && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            process();
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                char_h_move(-11.0);
                v_inerc = 5.0;
                v_force = 0.60000002;
                scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
                scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
                scene_play_sfx(31);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                flip_with_force();
            }
          }
          return;
        case 204:
          sub10func();
          h_inerc = h_inerc - 0.5;
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
            goto LABEL_803;
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
          v91 = 0.0;
          goto LABEL_335;
        case 209:
        case 212:
        case 221:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_803;
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
          v94 = 10.0;
          goto LABEL_546;
        case 210:
        case 222:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_803;
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
          v94 = -10.0;
LABEL_546:
          char_h_move(v94);
          v98 = 15.0;
          goto LABEL_547;
        case 211:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_803;
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
            v91 = 2.5;
LABEL_335:
            char_h_move(v91);
            v98 = 20.0;
LABEL_547:
            v_inerc = v98;
            v_force = 0.69999999;
            field_49A = 0;
            scene_add_effect(this, 63, x, y, dir, 1);
          }
          return;
        case 214:
          if ( process() )
            goto LABEL_842;
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              scene_play_sfx(31);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
              goto LABEL_842;
          }
          if ( (dY() < 0) | (dY() == 0) )
          {
            if ( dY() < 0 )
            {
              if ( dX(dir) <= 0 )
                field_7D2 = dX(dir) >= 0 ? 90 : 135;
              else
                field_7D2 = 45;
            }
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
            goto LABEL_2917;
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
LABEL_2917:
            if ( !char_on_ground_down() )
              return;
            y = getlvl_height();
            v_force = 0.0;
            v_inerc = 0.0;
            if ( get_subseq() >= 5 )
            {
              set_seq(10);
              reset_forces();
              return;
            }
            goto LABEL_427;
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
            goto LABEL_422;
          goto LABEL_419;
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
          if ( process() )
            set_seq(0);
          return;
        case 217:
          if ( process() )
            goto LABEL_1304;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            scene_play_sfx(31);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
            goto LABEL_1304;
          field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
          if ( get_subseq() == 5 || get_subseq() == 6 )
            v_inerc = v_inerc - v_force;
          if ( get_subseq() <= 0 || get_subseq() >= 5 )
            goto LABEL_2918;
          ++field_7D6;
          field_7D4 = field_7D2 - dash_angle;
          if ( field_7D4 > 180 )
            field_7D4 = field_7D4 - 360;
          if ( field_7D4 < -180 )
            field_7D4 = field_7D4 + 360;
          if ( field_7D4 > 0 )
          {
            if ( weather_id )
              dash_angle = dash_angle + 0.25;
            else
              dash_angle = dash_angle + 0.75;
          }
          if ( field_7D4 < 0 )
          {
            if ( weather_id )
              dash_angle = dash_angle - 0.25;
            else
              dash_angle = dash_angle - 0.75;
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
LABEL_2918:
            if ( char_on_ground_down() )
            {
              y = getlvl_height();
              v_force = 0.0;
              v_inerc = 0.0;
              if ( get_subseq() < 5 )
              {
LABEL_427:
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
LABEL_419:
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
LABEL_422:
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
          break;
        case 220:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_779;
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
            v_inerc = 20.0;
            v_force = 0.69999999;
            field_49A = 0;
            scene_add_effect(this, 63, x, y, dir, 1);
          }
          return;
        case 223:
          sub10func();
          field_49A = 1;
          process();
          if ( get_subseq() != 1 )
            goto LABEL_2919;
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          if ( ((++field_7D0, dX(dir) > 0) || field_7D0 <= 13) && field_7D0 <= 45 )
          {
LABEL_2919:
            if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
            {
              char_h_move(7.5);
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
          if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            h_inerc = 0.0;
          if ( !char_on_ground_flag() )
          {
            h_inerc = h_inerc + 10.0;
            if ( h_inerc > -10.0 )
              h_inerc = -10.0;
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
          }
          if ( get_subseq() < 3 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
          {
LABEL_239:
            v_inerc = 0.0;
            v_force = 0.0;
            y = getlvl_height();
            set_subseq(3);
          }
          else if ( process() )
          {
LABEL_578:
            set_seq(0);
            h_inerc = 0.0;
          }
          else
          {
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
              char_h_move(-50.0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              v_inerc = 4.0;
              v_force = 0.60000002;
              char_h_move(-30.0);
              scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
              scene_play_sfx(31);
            }
          }
          return;
        case 225:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_251;
          if ( get_subseq() < 3 && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124,  x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
          }
          if ( process() )
            set_seq(9);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(-11.0);
              v_inerc = 5.0;
              v_force = 0.60000002;
              scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
              scene_play_sfx(31);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              flip_with_force();
          }
          return;
        case 226:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_251:
            reset_forces();
            y = getlvl_height();
            set_seq(10);
          }
          else
          {
            if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            if ( process() )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              field_7D0 = 0;
              char_h_move(11.0);
              v_inerc = 5.0;
              v_force = 0.60000002;
              scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
              scene_add_effect(this, 126, x, y + 110.0, dir, 1);
              scene_play_sfx(31);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              flip_with_force();
          }
          return;
        default:
          goto LABEL_2904;
      }
    }
    return;
  }
  if ( get_seq() > 500 )
  {
    if ( get_seq() > 770 )
    {
      if ( (get_seq() - 795) )
      {
        if ( !(get_seq()  - 2) )
        {
          if ( get_subseq() < 3 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              scene_play_sfx(30);
              set_subseq(3);
              x = 480.0;
              y = getlvl_height();
              reset_forces();
              return;
            }
          }
          if ( process() )
            goto LABEL_2909;
          return;
        }
        if ( (get_seq()  - 2) != 1 )
        {
LABEL_2904:
          char_c::func10();
          return;
        }
        if ( get_subseq() == 1 && get_elaps_frames() >= 60 )
        {
LABEL_2741:
          next_subseq();
          return;
        }
        if ( !process() )
        {
          if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
          {
            t[0] = 10.0;
            t[1] = 0.0;
            t[2] = 6.0;
            addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
            t[0] = -10.0;
            t[2] = 7.0;
            addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
            play_sfx(13);
          }
          return;
        }
      }
      else
      {
        if ( !get_subseq() )
        {
          v_inerc = v_inerc - 0.300000011920929;
          if ( char_on_ground_down() )
          {
            scene_play_sfx(30);
            move_val = 1;
LABEL_2913:
            set_subseq(move_val);
LABEL_2914:
            y = getlvl_height();
            reset_forces();
            return;
          }
        }
LABEL_2886:
        if ( !process() )
          return;
      }
LABEL_2887:
      set_seq(700);
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
      return;
    }
    switch ( get_seq() )
    {
      case 501:
        if ( !get_subseq() || get_subseq() == 5 )
          sub10func();
        field_18C = 0;
        if ( get_subseq() == 1 || get_subseq() == 2 )
        {
          field_7DC = field_7DC - 1.5;
          if ( field_7DC < 2.0 )
            field_7DC = 2.0;
          //WHATIS?
          //set_vec_speed((render_class *)&cEffectSprite, -50.0, field_7DC);
          if ( get_subseq() == 2 )
          {
            if ( field_190 )
            {
              if ( field_194 > 0 && ++field_7D0 >= 8 )
              {
                field_7D0 = 0;
                field_190 = 0;
              }
            }
            if ( get_elaps_frames() >= 35 )
              next_subseq();
          }
        }
        if ( get_subseq() == 3 || get_subseq() == 4 )
        {
          field_190 = 1;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_1482;
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          /*
          v1647 = 0.0;
          v495 = (float)0.0;
          do
          {
            *(float *)&v1854 = v495 * 60.0;
            v1855 = 200.0;
            v1856 = 2.0;
            v496 = y + 118.0;
            addbullet(this, NULL, 810, x, v496, dir, 1, (int)&v1854, 3);
            v1856 = 3.0;
            v497 = y + 118.0;
            addbullet(this, NULL, 810, x, v497, dir, 1, (int)&v1854, 3);
            v1647 = v1647 + 1.0;
            v495 = v1647;
          }
          while ( v1647 < 6.0 );
          */
          scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
          spell_energy_spend(200, 120);
          add_card_energy(50);
          play_sfx(10);
          field_7DC = 30.0;
          v_force = 0.60000002;
          if ( skills_1[0] >= 1 )
            v_force = 0.75;
          if ( skills_1[0] >= 3 )
            v_force = 0.89999998;
          //WHATIS?
          //set_vec_speed((render_class *)&cEffectSprite, -50.0, field_7DC);
        }
        if ( get_subseq() != 5 )
          return;
        if ( !get_frame() )
        {
          if ( get_frame_time() == 6 && skills_1[0] >= 1 )
            goto LABEL_1921;
          if ( get_frame_time() == 4 && skills_1[0] >= 3 )
            goto LABEL_1921;
        }
        if ( get_frame() != 1 )
          return;
        if ( get_frame_time() == 7 && skills_1[0] >= 1 )
          goto LABEL_1975;
        v503 = get_frame_time() == 5;
        goto LABEL_1506;
      case 502:
        if ( get_subseq() == 5 )
          sub10func();
        field_18C = 0;
        if ( (get_subseq() == 1 || get_subseq() == 2) && get_subseq() == 2 )
        {
          if ( field_190 )
          {
            if ( field_194 > 0 && ++field_7D0 >= 8 )
            {
              field_7D0 = 0;
              field_190 = 0;
            }
          }
          if ( get_elaps_frames() >= 25 )
            next_subseq();
        }
        if ( get_subseq() != 3 && get_subseq() != 4 )
          goto LABEL_1444;
        field_190 = 1;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
        {
          y = getlvl_height();
          reset_forces();
          set_subseq(5);
          return;
        }
        if ( get_subseq() == 4 && get_elaps_frames() >= 20 )
          goto LABEL_1304;
LABEL_1444:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          /*
          v1648 = 0.0;
          v506 = (float)0.0;
          do
          {
            *(float *)&v1902 = v506 * 60.0;
            v1903 = 150.0;
            v1904 = 2.0;
            v507 = y + 118.0;
            addbullet(this, NULL, 810, x, v507, dir, 1, (int)&v1902, 3);
            v1904 = 3.0;
            v508 = y + 118.0;
            addbullet(this, NULL, 810, x, v508, dir, 1, (int)&v1902, 3);
            v1648 = v1648 + 1.0;
            v506 = v1648;
          }
          while ( v1648 < 6.0 );
          */
          if ( char_on_ground_down() )
          {
            scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
          }
          spell_energy_spend(200, 120);
          add_card_energy(50);
          play_sfx(10);
          v_force = 0.60000002;
        }
        if ( get_subseq() != 5 )
          return;
        if ( !get_frame() )
        {
          if (  get_frame_time() == 7 && skills_1[0] >= 1 )
            goto LABEL_2341;
          if (  get_frame_time() == 6 && skills_1[0] >= 3 )
            goto LABEL_2341;
        }
        if ( get_frame() != 1 )
          return;
        if ( get_frame_time() == 8 && skills_1[0] >= 1 )
          goto LABEL_2909;
        v490 = get_frame_time() == 7;
        goto LABEL_1465;
      case 503:
        if ( get_subseq() == 5 )
          sub10func();
        field_18C = 0;
        if ( (get_subseq() == 1 || get_subseq() == 2) && get_subseq() == 2 )
        {
          if ( field_190 )
          {
            if ( field_194 > 0 && ++field_7D0 >= 8 )
            {
              field_7D0 = 0;
              field_190 = 0;
            }
          }
          if ( get_elaps_frames() >= 45 )
            next_subseq();
        }
        if ( get_subseq() != 3 && get_subseq() != 4 )
          goto LABEL_1485;
        field_190 = 1;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
        {
LABEL_1482:
          y = getlvl_height();
          reset_forces();
          set_subseq(5);
          return;
        }
        if ( get_subseq() == 4 && get_elaps_frames() >= 30 )
          goto LABEL_845;
LABEL_1485:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          /*
          v1649 = 0.0;
          v516 = (float)0.0;
          do
          {
            *(float *)&v1860 = v516 * 60.0;
            v1861 = 150.0;
            v1862 = 2.0;
            v517 = y + 118.0;
            addbullet(this, NULL, 810, x, v517, dir, 1, (int)&v1860, 3);
            v1862 = 3.0;
            v518 = y + 118.0;
            addbullet(this, NULL, 810, x, v518, dir, 1, (int)&v1860, 3);
            v1649 = v1649 + 1.0;
            v516 = v1649;
          }
          while ( v1649 < 6.0 );
          */
          if ( char_on_ground_down() )
          {
            scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
          }
          spell_energy_spend(200, 120);
          add_card_energy(50);
          play_sfx(10);
          v_force = 0.60000002;
        }
        if ( get_subseq() != 5 )
          return;
        if ( !get_frame() )
        {
          if ( get_frame_time() == 7 && skills_1[0] >= 1 )
            goto LABEL_1921;
          if ( get_frame_time() == 6 && skills_1[0] >= 3 )
            goto LABEL_1921;
        }
        if ( get_frame() != 1 )
          return;
        if ( get_frame_time() == 8 && skills_1[0] >= 1 )
          goto LABEL_1975;
        v503 = get_frame_time() == 7;
LABEL_1506:
        if ( v503 && skills_1[0] >= 3 )
          set_seq(0);
        return;
      case 505:
        sub10func();
        field_18C = 4;
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          return;
        tt[0] = 0.0;
        tt[1] = 14.0;
        tt[2] = 0.0;
        tt[3] = 120.0;
        addbullet(this, NULL, 815, x, y + 118.0, 1, 1, tt, 4);
        tt[0] = /*(double)(unsigned int)get_MT_range(360)*/360.0;
        tt[1] = 15.0;
        tt[2] = 2.0;
        addbullet(this, NULL, 815, x, y + 118.0, dir, 1, tt, 4);
        tt[1] = 15.0;
        tt[2] = 3.0;
        addbullet(this, NULL, 815, x, y + 118.0, dir, 1, tt, 3);
        tt[1] = -15.0;
        tt[2] = 4.0;
        addbullet(this, NULL, 815, x, y + 118.0, dir, 1, tt, 4);
        y = y;
        goto LABEL_1540;
      case 506:
        sub10func();
        field_18C = 4;
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          return;
        tt[0] = 0.0;
        tt[1] = 20.0;
        tt[2] = 0.0;
        tt[3] = 60.0;
        addbullet(this, NULL, 815, x, y + 118.0, 1, 1, tt, 4);
        tt[0] = /*(double)(unsigned int)get_MT_range(360)*/360.0;
        tt[1] = 20.0;
        tt[2] = 2.0;
        addbullet(this, NULL, 815, x, y + 118.0, dir, 1, tt, 4);
        tt[1] = 20.0;
        tt[2] = 3.0;
        addbullet(this, NULL, 815, x, y + 118.0, dir, 1, tt, 4);
        tt[1] = -20.0;
        tt[2] = 4.0;
        addbullet(this, NULL, 815, x, y + 118.0, dir, 1, tt, 4);
        y = y;
        goto LABEL_1540;
      case 510:
        sub10func();
        field_18C = 8;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          v1650 = 4.0;
          if ( skills_1[8] >= 2 )
            v1650 = 5.0;
          if ( skills_1[8] >= 3 )
            v1650 = 6.0;
          if ( skills_1[8] >= 4 )
            v1650 = 8.0;
          /*
          v536 = v1650;
          v1762 = v1650;
          if ( v1650 > 0.0 )
          {
            v2083 = 360.0 / v536;
            v537 = (float)0.0;
            do
            {
              *(float *)&v2067 = v2083 * v537;
              v2068 = 50.0;
              v2069 = 0.0;
              v538 = v537 + 1.0;
              v2070 = v538;
              v539 = y + 100.0;
              addbullet(this, NULL, 820, x, v539, dir, 1, (int)&v2067, 4);
              v537 = v538;
            }
            while ( v538 < v1762 );
          }*/
          field_89A = v1650;
          field_190 = 1;
          y = y;
LABEL_1540:
          scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
          spell_energy_spend(200, 120);
          add_card_energy(50);
          play_sfx(14);
        }
        return;
      case 511:
        sub10func();
        field_18C = 8;
        if ( process() )
          set_seq(0);
        if ( get_frame_time() || get_frame() != 3 )
          return;
        field_190 = 1;
        scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
        goto LABEL_1675;
      case 520:
        sub10func();
        field_18C = 1;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( field_7D0 == 1 )
        {
          if ( !skills_1[1] )
            v1650 = 3.0;
          if ( skills_1[1] >= 1 )
            v1650 = 4.0;
          if ( skills_1[1] >= 4 )
            v1650 = 5.0;
          if ( !(field_7D2 % 2) && v1650 > (double)field_7DC )
          {
            /*
            v1909 = 14.0 - field_7DC;
            v1910 = 0.0;
            v1651 = 0.0;
            for ( i = (float)0.0; ; i = v1651 )
            {
              *(float *)&v1908 = i * 5.0 - 5.0 - 45.0 - field_7DC * 3.0;
              v547 = dir;
              v548 = -*(float *)&v1908;
              v549 = sin_deg(v548) * 70.0 + y + 100.0;
              v550 = v549;
              v551 = -*(float *)&v1908;
              v552 = (cos_deg(v551) * 70.0 + 15.0) * (double)dir + x;
              addbullet(this, NULL, 811, v552, v550, v547, 1, (int)&v1908, 3);
              v1651 = v1651 + 1.0;
              if ( v1651 >= 3.0 )
                break;
            }
            */
            field_7DC = field_7DC + 1.0;
          }
          ++field_7D2;
        }
        if ( field_7D0 == 2 )
        {
          if ( !skills_1[1] )
            v1650 = 3.0;
          if ( skills_1[1] >= 1 )
            v1650 = 4.0;
          if ( skills_1[1] >= 4 )
            v1650 = 5.0;
          if ( !(field_7D2 % 2) && v1650 > (double)field_7DC )
          {
            /*
            v1652 = 0.0;
            for ( j = (float)0.0; ; j = v1652 )
            {
              *(float *)&v1887 = -45.0 - field_7DC * 3.0 - j * 5.0;
              v1888 = 14.0 - field_7DC;
              v1889 = 0.0;
              v555 = dir;
              v556 = -*(float *)&v1887;
              v557 = sin_deg(v556) * 70.0 + y + 100.0;
              v558 = v557;
              v559 = -*(float *)&v1887;
              v560 = (cos_deg(v559) * 70.0 + 15.0) * (double)dir + x;
              addbullet(this, NULL, 811, v560, v558, v555, 1, (int)&v1887, 3);
              v1652 = v1652 + 1.0;
              if ( v1652 >= 4.0 )
                break;
            }
            LOWORD(v17) = 2;
            */
            field_7DC = field_7DC + 1.0;
          }
          ++field_7D2;
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1975;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1631;
        if ( get_frame() != 4 || !not_charge_attack )
          goto LABEL_1629;
        next_subseq();
        scene_add_effect(this, 62, (double)(15 * (char)dir) + x, y + 90.0, dir, 1);
        return;
      case 521:
        sub10func();
        field_18C = 1;
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( field_7D0 == 1 )
        {
          if ( !skills_1[1] )
            v1650 = 3.0;
          if ( skills_1[1] >= 1 )
            v1650 = 4.0;
          if ( skills_1[1] >= 4 )
            v1650 = 5.0;
          if ( !(field_7D2 % 2) && v1650 > (double)field_7DC )
          {
            /*
            v568 = 5.0;
            v1870 = 14.0 - field_7DC;
            v1871 = 0.0;
            v1653 = 0.0;
            v569 = (float)0.0;
            while ( 1 )
            {
              *(float *)&v1869 = v569 * v568 - v568 - 135.0 - field_7DC * 3.0;
              v570 = dir;
              v571 = -*(float *)&v1869;
              v572 = sin_deg(v571) * 70.0 + y + 100.0;
              v573 = v572;
              v574 = -*(float *)&v1869;
              v575 = (cos_deg(v574) * 70.0 - 20.0) * (double)dir + x;
              addbullet(this, NULL, 811, v575, v573, v570, 1, (int)&v1869, 3);
              v1653 = v1653 + 1.0;
              if ( v1653 >= 3.0 )
                break;
              v569 = v1653;
              v568 = 5.0;
            }
            */
            field_7DC = field_7DC + 1.0;
          }
          ++field_7D2;
        }
        if ( field_7D0 == 2 )
        {
          if ( !skills_1[1] ) //revesed condition
          {
            //v579 = 5.0;
            v1650 = 3.0;
          }
          if ( skills_1[1] >= 1 )
            v1650 = 4.0;
          if ( skills_1[1] >= 4 )
            v1650 = 5.0;
          if ( field_7D2 % 2 || v1650 <= (double)field_7DC )
          {
            ++field_7D2;
          }
          else
          {
            /*
            v1900 = 14.0 - field_7DC;
            v1901 = 0.0;
            v1654 = 0.0;
            v580 = (float)0.0;
            while ( 1 )
            {
              a1 = v580 * v579 - v579 - 135.0 - field_7DC * 3.0;
              v581 = dir;
              v582 = -a1;
              v583 = sin_deg(v582) * 70.0 + y + 100.0;
              v584 = v583;
              v585 = -a1;
              v586 = (cos_deg(v585) * 70.0 - 20.0) * (double)dir + x;
              addbullet(this, NULL, 811, v586, v584, v581, 1, (int)&a1, 3);
              v1654 = v1654 + 1.0;
              v580 = v1654;
              if ( v1654 >= 4.0 )
                break;
              v579 = 5.0;
            }
            LOWORD(v17) = 2;
            */
            field_7DC = field_7DC + 1.0;
            ++field_7D2;
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_2909;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1631;
        if ( get_frame() == 4 && not_charge_attack )
        {
          next_subseq();
          scene_add_effect(this, 62, (double)(15 * (char)dir) + x, y + 90.0, dir, 1);
          return;
        }
LABEL_1629:
        if ( get_frame() == 5 )
        {
          field_7D0 = 1;
          play_sfx(11);
          spell_energy_spend(200, 120);
          add_card_energy(50);
        }
LABEL_1631:
        if ( get_subseq() != 1 || get_frame_time() || get_frame() != v17 )
          return;
        field_7D0 = v17;
        goto LABEL_1674;
      case 525:
        sub10func();
        field_18C = 5;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_2909;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1650;
        if ( get_frame() == 4 && not_charge_attack )
        {
          next_subseq();
          scene_add_effect(this, 62, (double)(15 * (char)dir) + x, y + 90.0, dir, 1);
          return;
        }
        if ( get_frame() == 5 )
        {
          tt[0] = -45.0;
          tt[1] = 15.0;
          tt[2] = 4.0;
          tt[3] = 0.0;
          addbullet(this, NULL, 816, (cos_deg(-t[0]) * 70.0 - 20.0) * (double)dir + x, sin_deg(45.0) * 70.0 + y + 100.0, dir, 1, tt, 4);
          play_sfx(11);
          spell_energy_spend(200, 120);
          add_card_energy(50);
        }
LABEL_1650:
        if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
          return;
        tt[0] = -45.0;
        //a2a = (int *)&v1928;
        tt[1] = 15.0;
        tt[2] = 4.0;
        tt[3] = 1.0;
        x = dir;
        v1581 = sin_deg(45.0) * 70.0 + y + 100.0;
        v603 = (cos_deg(-tt[0]) * 70.0 - 20.0) * (double)dir + x;
        goto LABEL_1673;
      case 526:
        sub10func();
        field_18C = 5;
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_2909;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1669;
        if ( get_frame() == 4 && not_charge_attack )
        {
          next_subseq();
          scene_add_effect(this, 62, (double)(15 * (char)dir) + x, y + 90.0, dir, 1);
        }
        else
        {
          if ( get_frame() == 5 )
          {
            tt[0] = -135.0;
            tt[1] = 15.0;
            tt[2] = 4.0;
            tt[3] = 0.0;
            addbullet(this, NULL, 816, (cos_deg(-tt[0]) * 70.0 + 15.0) * (double)dir + x, sin_deg(135.0) * 70.0 + y + 100.0, dir, 1, tt, 4);
            play_sfx(11);
            spell_energy_spend(200, 120);
            add_card_energy(50);
          }
LABEL_1669:
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
          {
            tt[0] = -135.0;
            //a2a = &v1935;
            tt[1] = 15.0;
            tt[2] = 4.0;
            tt[3] = 1.0;
            x = dir;
            v1581 = sin_deg(135.0) * 70.0 + y + 100.0;
            v603 = (cos_deg(-tt[0]) * 70.0 + 15.0) * (double)dir + x;
LABEL_1673:
            addbullet(this, NULL, 816, v603, v1581, x, 1, tt, 4);
LABEL_1674:
            play_sfx(11);
LABEL_1675:
            spell_energy_spend(200, 120);
            add_card_energy(50);
          }
        }
        return;
      case 530:
        sub10func();
        field_18C = 9;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_2909;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1691;
        if ( get_frame() == 4 && not_charge_attack )
        {
          next_subseq();
          scene_add_effect(this, 62, (double)(15 * (char)dir) + x, y + 90.0, dir, 1);
        }
        else
        {
          if ( get_frame() == 5 )
          {
            play_sfx(11);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            tt[0] = -90.0;
            tt[1] = 15.0;
            tt[2] = 0.0;
            tt[3] = 0.0;
            addbullet(this, NULL, 821, (double)(90 * (char)dir) + x, y + 160.0, dir, 1, tt, 4);
          }
LABEL_1691:
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
          {
            play_sfx(11);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            tt[0] = -90.0;
            tt[1] = 15.0;
            tt[2] = 0.0;
            tt[3] = 1.0;
            addbullet(this, NULL, 821, (double)(90 * (char)dir) + x, y + 160.0, dir, 1, tt, 4);
          }
        }
        return;
      case 531:
        sub10func();
        field_18C = 9;
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1975;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1710;
        if ( get_frame() == 4 && not_charge_attack )
        {
          next_subseq();
          scene_add_effect(this, 62, (double)(15 * (char)dir) + x, y + 90.0, dir, 1);
        }
        else
        {
          if ( get_frame() == 5 )
          {
            play_sfx(11);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            tt[0] = -70.0;
            tt[1] = 20.0;
            tt[2] = 0.0;
            tt[3] = 0.0;
            addbullet(this, NULL, 821, (double)(90 * (char)dir) + x, y + 160.0, dir, 1, tt, 4);
          }
LABEL_1710:
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
          {
            play_sfx(11);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            tt[0] = -70.0;
            tt[1] = 20.0;
            tt[2] = 0.0;
            tt[3] = 1.0;
            addbullet(this, NULL, 821, (double)(90 * (char)dir) + x, y + 160.0, dir, 1, tt, 4);
          }
        }
        return;
      case 540:
        sub10func();
        field_18C = 2;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          set_seq(0);
          return;
        }
        if ( get_subseq() || get_frame_time() || get_frame() != 7 )
          goto LABEL_1982;
        add_card_energy(50);
        spell_energy_spend(200, 120);
        field_190 = 1;
        //v1724 = 0.0; (moved down?)
        field_7DC = 1.0;
        if ( skills_1[2] >= 2 )
          field_7DC = 1.15;
        if ( skills_1[2] >= 4 )
          field_7DC = 1.3;
        t[0] = 2.0;
        t[1] = field_7DC * 30.0;
        t[2] = 0.0; //here
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-2.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 5.0;
        t[1] = field_7DC * 27.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-5.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 5.5;
        t[1] = field_7DC * 24.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-5.5) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 4.0;
        t[1] = field_7DC * 21.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-4.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -2.0;
        t[1] = field_7DC * 30.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(2.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -5.0;
        t[1] = field_7DC * 27.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(5.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -5.5;
        t[1] = field_7DC * 24.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(5.5) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -4.0;
        t[1] = field_7DC * 21.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(4.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        goto LABEL_1981;
      case 541:
        sub10func();
        field_18C = 2;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          set_seq(0);
          return;
        }
        if ( get_subseq() || get_frame_time() || get_frame() != 7 )
          goto LABEL_1982;
        add_card_energy(50);
        spell_energy_spend(200, 120);
        field_190 = 1;
        //v1715 = 0.0; moved down?
        field_7DC = 1.0;
        if ( skills_1[2] >= 2 )
          field_7DC = 1.15;
        if ( skills_1[2] >= 4 )
          field_7DC = 1.3;
        t[0] = 3.0;
        t[1] = field_7DC * 30.0;
        t[2] = 0.0;// here
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-3.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 8.0;
        t[1] = field_7DC * 27.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-8.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 10.0;
        t[1] = field_7DC * 24.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-10.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 11.0;
        t[1] = field_7DC * 21.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-11.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -3.0;
        t[1] = field_7DC * 30.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(3.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -8.0;
        t[1] = field_7DC * 27.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(8.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -10.0;
        t[1] = field_7DC * 24.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(10.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -11.0;
        t[1] = field_7DC * 21.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(11.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        goto LABEL_1981;
      case 542:
        if ( get_subseq() == 1 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 1 )
          goto LABEL_2006;
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1304;
        if ( get_subseq() || get_frame_time() )
          return;
        if ( get_frame() != 5 )
          goto LABEL_2022;
        add_card_energy(50);
        spell_energy_spend(200, 120);
        field_190 = 1;
        //v1721 = 0.0; // moved down
        field_7DC = 1.0;
        if ( skills_1[2] >= 2 )
          field_7DC = 1.15;
        if ( skills_1[2] >= 4 )
          field_7DC = 1.3;
        t[0] = 2.0;
        t[1] = field_7DC * 30.0;
        t[2] = 0.0;//here
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-2.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 5.0;
        t[1] = field_7DC * 27.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-5.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 5.5;
        t[1] = field_7DC * 24.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-5.5) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 4.0;
        t[1] = field_7DC * 21.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-4.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -2.0;
        t[1] = field_7DC * 30.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(2.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -5.0;
        t[1] = field_7DC * 27.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(5.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -5.5;
        t[1] = field_7DC * 24.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(5.5) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -4.0;
        t[1] = field_7DC * 21.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(4.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        goto LABEL_2021;
      case 543:
        if ( get_subseq() == 1 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 1 )
          goto LABEL_2006;
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1304;
        if ( get_subseq() || get_frame_time() )
          return;
        if ( get_frame() != 5 )
          goto LABEL_2022;
        add_card_energy(50);
        spell_energy_spend(200, 120);
        field_190 = 1;
        //v1718 = 0.0;//moved down
        field_7DC = 1.0;
        if ( skills_1[2] >= 2 )
          field_7DC = 1.15;
        if ( skills_1[2] >= 4 )
          field_7DC = 1.3;
        t[0] = 3.0;
        t[1] = field_7DC * 30.0;
        t[2] = 0.0;//here
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-3.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 8.0;
        t[1] = field_7DC * 27.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-8.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 10.0;
        t[1] = field_7DC * 24.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-10.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = 11.0;
        t[1] = field_7DC * 21.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-11.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -3.0;
        t[1] = field_7DC * 30.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(3.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -8.0;
        t[1] = field_7DC * 27.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(8.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -10.0;
        t[1] = field_7DC * 24.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(10.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        t[0] = -11.0;
        t[1] = field_7DC * 21.0;
        addbullet(this, NULL, 812, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(11.0) * 200.0 + y + 100.0, dir, 1, t, 3);
        goto LABEL_2021;
      case 545:
        sub10func();
        field_18C = 6;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && get_frame() == 1 && skills_1[6] >= 2 && get_frame_time() >= 2 )
          goto LABEL_1921;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          add_card_energy(50);
          if ( skills_1[6] < 3 )
            spell_energy_spend(200, 120);
          else
            spell_energy_spend(200, 60);
          field_190 = 1;
          t[0] = 0.0;
          t[1] = 15.0;
          t[2] = 0.0;
          switch ( skills_1[6] )
          {
            case 1u:
              /*v1655 = 0.0;
              v802 = 45.0;
              v803 = (float)0.0;
              while ( 1 )
              {
                v804 = dir;
                v805 = 40.0 * v803 + y + 60.0;
                v806 = v805;
                v807 = v802 + v803 * v802;
                v808 = (sin_deg(v807) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v808, v806, v804, 1, (int)&v1774, 3);
                v1655 = v1655 + 1.0;
                if ( v1655 >= 3.0 )
                  break;
                v803 = v1655;
                v802 = 45.0;
              }
              v1612 = 0.0;
              do
              {
                v809 = dir;
                v810 = (double)(unsigned int)get_MT_range(250) + y;
                v811 = v810;
                v812 = ((double)(unsigned int)get_MT_range(100) + 50.0 + 0.0) * (double)dir + x;
                addbullet(this, NULL, 817, v812, v811, v809, 1, (int)&v1774, 3);
                v1612 = v1612 + 1.0;
              }
              while ( v1612 < 2.0 );
              */
              play_sfx(15);
              break;
            case 2u:
              /*v1656 = 0.0;
              v813 = 40.0;
              v814 = (float)0.0;
              while ( 1 )
              {
                v815 = dir;
                v816 = v813 + v814 * v813 + y;
                v817 = v816;
                v818 = v814 * 45.0 + 22.5;
                v819 = (sin_deg(v818) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v819, v817, v815, 1, (int)&v1774, 3);
                v1656 = v1656 + 1.0;
                if ( v1656 >= 4.0 )
                  break;
                v814 = v1656;
                v813 = 40.0;
              }
              v1613 = 0.0;
              do
              {
                v820 = dir;
                v821 = (double)(unsigned int)get_MT_range(250) + y;
                v822 = v821;
                v823 = ((double)(unsigned int)get_MT_range(100) + 50.0 + 0.0) * (double)dir + x;
                addbullet(this, NULL, 817, v823, v822, v820, 1, (int)&v1774, 3);
                v1613 = v1613 + 1.0;
              }
              while ( v1613 < 3.0 );
              */
              play_sfx(15);
              break;
            case 3u:
              /*v1657 = 0.0;
              v824 = (float)0.0;
              do
              {
                v825 = dir;
                v826 = 40.0 * v824 + y;
                v827 = v826;
                v828 = v824 * 45.0;
                v829 = (sin_deg(v828) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v829, v827, v825, 1, (int)&v1774, 3);
                v1657 = v1657 + 1.0;
                v824 = v1657;
              }
              while ( v1657 < 5.0 );
              v1614 = 0.0;
              do
              {
                v830 = dir;
                v831 = (double)(unsigned int)get_MT_range(250) + y;
                v832 = v831;
                v833 = ((double)(unsigned int)get_MT_range(100) + 50.0 + 0.0) * (double)dir + x;
                addbullet(this, NULL, 817, v833, v832, v830, 1, (int)&v1774, 3);
                v1614 = v1614 + 1.0;
              }
              while ( v1614 < 4.0 );
              */
              play_sfx(15);
              break;
            case 4u:
              /*v1658 = 0.0;
              v834 = (float)0.0;
              do
              {
                v835 = dir;
                v836 = 40.0 * v834 + y - 20.0;
                v837 = v836;
                v838 = v834 * 30.0;
                v839 = (sin_deg(v838) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v839, v837, v835, 1, (int)&v1774, 3);
                v1658 = v1658 + 1.0;
                v834 = v1658;
              }
              while ( v1658 < 6.0 );
              v1615 = 0.0;
              do
              {
                v840 = dir;
                v841 = (double)(unsigned int)get_MT_range(250) + y;
                v842 = v841;
                v843 = ((double)(unsigned int)get_MT_range(100) + 50.0 + 0.0) * (double)dir + x;
                addbullet(this, NULL, 817, v843, v842, v840, 1, (int)&v1774, 3);
                v1615 = v1615 + 1.0;
              }
              while ( v1615 < 5.0 );
              */
              play_sfx(15);
              break;
            default:
              goto LABEL_1953;
          }
        }
        return;
      case 546:
        sub10func();
        field_18C = 6;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && get_frame() == 1 && skills_1[6] >= 2 && get_frame_time() >= 2 )
          goto LABEL_1921;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          add_card_energy(50);
          if ( skills_1[6] < 3 )
            spell_energy_spend(200, 120);
          else
            spell_energy_spend(200, 60);
          field_190 = 1;
          t[0] = 0.0;
          t[1] = 15.0;
          t[2] = 0.0;
          switch ( skills_1[6] )
          {
            case 1u:
            /*
              v1659 = 0.0;
              v845 = 40.0;
              v846 = 45.0;
              v847 = (float)0.0;
              while ( 1 )
              {
                *(float *)&v1734 = v846 - 30.0 * v847;
                v848 = dir;
                v849 = v845 + v847 * v845 + y;
                v850 = v849;
                v851 = v847 * v846 + 22.5;
                v852 = (sin_deg(v851) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v852, v850, v848, 1, (int)&v1734, 3);
                v1659 = v1659 + 1.0;
                if ( v1659 >= 4.0 )
                  break;
                v846 = 45.0;
                v847 = v1659;
                v845 = 40.0;
              }
              v1660 = 0.0;
              v853 = (float)0.0;
              do
              {
                *(float *)&v1734 = 30.0 - v853 * 30.0;
                v854 = dir;
                v855 = v853 * 40.0 + y + 60.0;
                v856 = v855;
                v857 = v853 * 60.0 + 30.0;
                v858 = (sin_deg(v857) * 120.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v858, v856, v854, 1, (int)&v1734, 3);
                v1660 = v1660 + 1.0;
                v853 = v1660;
              }
              while ( v1660 < 3.0 );
              */
              play_sfx(15);
              break;
            case 2u:
            /*
              v1661 = 0.0;
              v859 = (float)0.0;
              do
              {
                *(float *)&v1734 = 60.0 - 30.0 * v859;
                v860 = dir;
                v861 = 40.0 * v859 + y + 20.0;
                v862 = v861;
                v863 = v859 * 45.0;
                v864 = (sin_deg(v863) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v864, v862, v860, 1, (int)&v1734, 3);
                v1661 = v1661 + 1.0;
                v859 = v1661;
              }
              while ( v1661 < 5.0 );
              v1662 = 0.0;
              v865 = (float)0.0;
              do
              {
                *(float *)&v1734 = 45.0 - 30.0 * v865;
                v866 = dir;
                v867 = v865 * 40.0 + y + 40.0;
                v868 = v867;
                v869 = v865 * 60.0;
                v870 = (sin_deg(v869) * 120.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v870, v868, v866, 1, (int)&v1734, 3);
                v1662 = v1662 + 1.0;
                v865 = v1662;
              }
              while ( v1662 < 4.0 );
              */
              play_sfx(15);
              break;
            case 3u:
            /*
              v1663 = 0.0;
              v871 = (float)0.0;
              do
              {
                *(float *)&v1734 = 75.0 - 30.0 * v871;
                v872 = dir;
                v873 = 40.0 * v871 + y;
                v874 = v873;
                v875 = v871 * 36.0;
                v876 = (sin_deg(v875) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v876, v874, v872, 1, (int)&v1734, 3);
                v1663 = v1663 + 1.0;
                v871 = v1663;
              }
              while ( v1663 < 6.0 );
              v1664 = 0.0;
              v877 = (float)0.0;
              do
              {
                *(float *)&v1734 = 60.0 - 30.0 * v877;
                v878 = dir;
                v879 = 40.0 * v877 + y + 20.0;
                v880 = v879;
                v881 = v877 * 45.0;
                v882 = (sin_deg(v881) * 120.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v882, v880, v878, 1, (int)&v1734, 3);
                v1664 = v1664 + 1.0;
                v877 = v1664;
              }
              while ( v1664 < 5.0 );
              */
              play_sfx(15);
              break;
            case 4u:
            /*
              v1665 = 0.0;
              v883 = (float)0.0;
              do
              {
                *(float *)&v1734 = 90.0 - 30.0 * v883;
                v884 = dir;
                v885 = v883 * 40.0 + y - 20.0;
                v886 = v885;
                v887 = 30.0 * v883;
                v888 = (sin_deg(v887) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v888, v886, v884, 1, (int)&v1734, 3);
                v1665 = v1665 + 1.0;
                v883 = v1665;
              }
              while ( v1665 < 7.0 );
              v1666 = 0.0;
              v889 = (float)0.0;
              do
              {
                *(float *)&v1734 = 75.0 - 30.0 * v889;
                v890 = dir;
                v891 = 40.0 * v889 + y;
                v892 = v891;
                v893 = v889 * 36.0;
                v894 = (sin_deg(v893) * 120.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v894, v892, v890, 1, (int)&v1734, 3);
                v1666 = v1666 + 1.0;
                v889 = v1666;
              }
              while ( v1666 < 6.0 );
              */
              goto LABEL_1862;
            default:
LABEL_1862:
              play_sfx(15);
              break;
          }
        }
        return;
      case 547:
        if ( get_subseq() == 4 )
          sub10func();
        field_18C = 6;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 4 )
          goto LABEL_1914;
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && get_frame() == 1 && skills_1[6] >= 2 && get_frame_time() >= 2 )
          goto LABEL_1921;
        if ( get_elaps_frames() )
          return;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
          goto LABEL_1304;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          h_inerc = -10.0;
          v_inerc = 5.0;
          v_force = 0.5;
          add_card_energy(50);
          if ( skills_1[6] < 3 )
            spell_energy_spend(200, 120);
          else
            spell_energy_spend(200, 60);
          field_190 = 1;
          t[0] = 0.0;
          t[1] = 15.0;
          t[2] = 0.0;
          switch ( skills_1[6] )
          {
            case 1u:
            /*
              v1667 = 0.0;
              v896 = 45.0;
              v897 = (float)0.0;
              while ( 1 )
              {
                v898 = dir;
                v899 = 40.0 * v897 + y + 60.0;
                v900 = v899;
                v901 = v896 + v897 * v896;
                v902 = (sin_deg(v901) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v902, v900, v898, 1, (int)&v1771, 3);
                v1667 = v1667 + 1.0;
                if ( v1667 >= 3.0 )
                  break;
                v897 = v1667;
                v896 = 45.0;
              }
              v1616 = 0.0;
              do
              {
                v903 = dir;
                v904 = (double)(unsigned int)get_MT_range(250) + y;
                v905 = v904;
                v906 = ((double)(unsigned int)get_MT_range(100) + 50.0 + 0.0) * (double)dir + x;
                addbullet(this, NULL, 817, v906, v905, v903, 1, (int)&v1771, 3);
                v1616 = v1616 + 1.0;
              }
              while ( v1616 < 2.0 );
              */
              play_sfx(15);
              break;
            case 2u:
            /*
              v1668 = 0.0;
              v907 = 40.0;
              v908 = (float)0.0;
              while ( 1 )
              {
                v909 = dir;
                v910 = v907 + v908 * v907 + y;
                v911 = v910;
                v912 = v908 * 45.0 + 22.5;
                v913 = (sin_deg(v912) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v913, v911, v909, 1, (int)&v1771, 3);
                v1668 = v1668 + 1.0;
                if ( v1668 >= 4.0 )
                  break;
                v908 = v1668;
                v907 = 40.0;
              }
              v1617 = 0.0;
              do
              {
                v914 = dir;
                v915 = (double)(unsigned int)get_MT_range(250) + y;
                v916 = v915;
                v917 = ((double)(unsigned int)get_MT_range(100) + 50.0 + 0.0) * (double)dir + x;
                addbullet(this, NULL, 817, v917, v916, v914, 1, (int)&v1771, 3);
                v1617 = v1617 + 1.0;
              }
              while ( v1617 < 3.0 );
              */
              play_sfx(15);
              break;
            case 3u:
            /*
              v1669 = 0.0;
              v918 = (float)0.0;
              do
              {
                v919 = dir;
                v920 = 40.0 * v918 + y;
                v921 = v920;
                v922 = v918 * 45.0;
                v923 = (sin_deg(v922) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v923, v921, v919, 1, (int)&v1771, 3);
                v1669 = v1669 + 1.0;
                v918 = v1669;
              }
              while ( v1669 < 5.0 );
              v1618 = 0.0;
              do
              {
                v924 = dir;
                v925 = (double)(unsigned int)get_MT_range(250) + y;
                v926 = v925;
                v927 = ((double)(unsigned int)get_MT_range(100) + 50.0 + 0.0) * (double)dir + x;
                addbullet(this, NULL, 817, v927, v926, v924, 1, (int)&v1771, 3);
                v1618 = v1618 + 1.0;
              }
              while ( v1618 < 4.0 );
              */
              play_sfx(15);
              break;
            case 4u:
            /*
              v1670 = 0.0;
              v928 = (float)0.0;
              do
              {
                v929 = dir;
                v930 = 40.0 * v928 + y - 20.0;
                v931 = v930;
                v932 = v928 * 30.0;
                v933 = (sin_deg(v932) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v933, v931, v929, 1, (int)&v1771, 3);
                v1670 = v1670 + 1.0;
                v928 = v1670;
              }
              while ( v1670 < 6.0 );
              v1619 = 0.0;
              do
              {
                v934 = dir;
                v935 = (double)(unsigned int)get_MT_range(250) + y;
                v936 = v935;
                v937 = ((double)(unsigned int)get_MT_range(100) + 50.0 + 0.0) * (double)dir + x;
                addbullet(this, NULL, 817, v937, v936, v934, 1, (int)&v1771, 3);
                v1619 = v1619 + 1.0;
              }
              while ( v1619 < 5.0 );
              */
              play_sfx(15);
              break;
            default:
              goto LABEL_1953;
          }
        }
        return;
      case 548:
        if ( get_subseq() == 4 )
          sub10func();
        field_18C = 6;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 4 )
        {
LABEL_1914:
          air_dash_cnt = 0;
          reset_forces();
          y = getlvl_height();
          set_subseq(4);
          return;
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && get_frame() == 1 && skills_1[6] >= 2 && get_frame_time() >= 2 )
        {
LABEL_1921:
          next_frame();
          return;
        }
        if ( get_elaps_frames() )
          return;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
          goto LABEL_1304;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          h_inerc = -10.0;
          v_inerc = 5.0;
          v_force = 0.5;
          add_card_energy(50);
          if ( skills_1[6] < 3 )
            spell_energy_spend(200, 120);
          else
            spell_energy_spend(200, 60);
          field_190 = 1;
          t[0] = 0.0;
          t[1] = 15.0;
          t[2] = 0.0;
          switch ( skills_1[6] )
          {
            case 1u:
            /*
              v1671 = 0.0;
              v939 = 40.0;
              v940 = 45.0;
              v941 = (float)0.0;
              while ( 1 )
              {
                *(float *)&v1737 = v940 - 30.0 * v941;
                v942 = dir;
                v943 = v939 + v941 * v939 + y;
                v944 = v943;
                v945 = v941 * v940 + 22.5;
                v946 = (sin_deg(v945) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v946, v944, v942, 1, (int)&v1737, 3);
                v1671 = v1671 + 1.0;
                if ( v1671 >= 4.0 )
                  break;
                v940 = 45.0;
                v941 = v1671;
                v939 = 40.0;
              }
              v1672 = 0.0;
              v947 = (float)0.0;
              do
              {
                *(float *)&v1737 = 30.0 - v947 * 30.0;
                v948 = dir;
                v949 = v947 * 40.0 + y + 60.0;
                v950 = v949;
                v951 = v947 * 60.0 + 30.0;
                v952 = (sin_deg(v951) * 120.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v952, v950, v948, 1, (int)&v1737, 3);
                v1672 = v1672 + 1.0;
                v947 = v1672;
              }
              while ( v1672 < 3.0 );
              */
              play_sfx(15);
              break;
            case 2u:
            /*
              v1673 = 0.0;
              v953 = (float)0.0;
              do
              {
                *(float *)&v1737 = 60.0 - 30.0 * v953;
                v954 = dir;
                v955 = 40.0 * v953 + y + 20.0;
                v956 = v955;
                v957 = v953 * 45.0;
                v958 = (sin_deg(v957) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v958, v956, v954, 1, (int)&v1737, 3);
                v1673 = v1673 + 1.0;
                v953 = v1673;
              }
              while ( v1673 < 5.0 );
              v1674 = 0.0;
              v959 = (float)0.0;
              do
              {
                *(float *)&v1737 = 45.0 - 30.0 * v959;
                v960 = dir;
                v961 = v959 * 40.0 + y + 40.0;
                v962 = v961;
                v963 = v959 * 60.0;
                v964 = (sin_deg(v963) * 120.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v964, v962, v960, 1, (int)&v1737, 3);
                v1674 = v1674 + 1.0;
                v959 = v1674;
              }
              while ( v1674 < 4.0 );
              */
              play_sfx(15);
              break;
            case 3u:
            /*
              v1675 = 0.0;
              v965 = (float)0.0;
              do
              {
                *(float *)&v1737 = 75.0 - 30.0 * v965;
                v966 = dir;
                v967 = 40.0 * v965 + y;
                v968 = v967;
                v969 = v965 * 36.0;
                v970 = (sin_deg(v969) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v970, v968, v966, 1, (int)&v1737, 3);
                v1675 = v1675 + 1.0;
                v965 = v1675;
              }
              while ( v1675 < 6.0 );
              v1676 = 0.0;
              v971 = (float)0.0;
              do
              {
                *(float *)&v1737 = 60.0 - 30.0 * v971;
                v972 = dir;
                v973 = 40.0 * v971 + y + 20.0;
                v974 = v973;
                v975 = v971 * 45.0;
                v976 = (sin_deg(v975) * 120.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v976, v974, v972, 1, (int)&v1737, 3);
                v1676 = v1676 + 1.0;
                v971 = v1676;
              }
              while ( v1676 < 5.0 );
              */
              play_sfx(15);
              break;
            case 4u:
            /*
              v1677 = 0.0;
              v977 = (float)0.0;
              do
              {
                *(float *)&v1737 = 90.0 - 30.0 * v977;
                v978 = dir;
                v979 = v977 * 40.0 + y - 20.0;
                v980 = v979;
                v981 = 30.0 * v977;
                v982 = (sin_deg(v981) * 150.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v982, v980, v978, 1, (int)&v1737, 3);
                v1677 = v1677 + 1.0;
                v977 = v1677;
              }
              while ( v1677 < 7.0 );
              v1678 = 0.0;
              v983 = (float)0.0;
              do
              {
                *(float *)&v1737 = 75.0 - 30.0 * v983;
                v984 = dir;
                v985 = 40.0 * v983 + y;
                v986 = v985;
                v987 = v983 * 36.0;
                v988 = (sin_deg(v987) * 120.0 - 50.0) * (double)dir + x;
                addbullet(this, NULL, 817, v988, v986, v984, 1, (int)&v1737, 3);
                v1678 = v1678 + 1.0;
                v983 = v1678;
              }
              while ( v1678 < 6.0 );
              */
              goto LABEL_1953;
            default:
LABEL_1953:
              play_sfx(15);
              break;
          }
        }
        return;
      case 550:
        sub10func();
        field_18C = 10;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
        {
          if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
          {
            add_card_energy(50);
            spell_energy_spend(200, 120);
            field_190 = 1;
            //v1749 = 0.0;//moved down
            tt[0] = 3.0;
            tt[1] = 25.0;
            tt[2] = 0.0;//here
            tt[3] = 0.80000001;
            addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(-3.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
            tt[0] = 1.0;
            tt[3] = 0.40000001;
            addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(-1.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
            tt[0] = -1.0;
            tt[3] = -0.40000001;
            addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(1.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
            tt[0] = -3.0;
            tt[3] = -0.80000001;
            v1582 = sin_deg(3.0) * 100.0 + y + 100.0;
LABEL_1980:
            addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, v1582, dir, 1, tt, 4);
LABEL_1981:
            play_sfx(12);
          }
LABEL_1982:
          if ( get_subseq() == 1 && !get_frame() && !not_charge_attack )
          {
            set_subseq(0);
            //get_frame() = 7;
          }
        }
        else
        {
          set_seq(0);
        }
        return;
      case 551:
        sub10func();
        field_18C = 10;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1975;
        if ( get_subseq() || get_frame_time() || get_frame() != 7 )
          goto LABEL_1982;
        add_card_energy(50);
        spell_energy_spend(200, 120);
        field_190 = 1;
        tt[0] = 45.0;
        tt[1] = 25.0;
        tt[2] = 0.0;
        tt[3] = -1.8;
        addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(-45.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
        tt[0] = 25.0;
        tt[3] = -0.89999998;
        addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(-25.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
        tt[0] = -25.0;
        tt[3] = 0.89999998;
        addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(25.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
        tt[0] = -45.0;
        tt[3] = 1.8;
        v1582 = sin_deg(45.0) * 100.0 + y + 100.0;
        goto LABEL_1980;
      case 552:
        if ( get_subseq() == 1 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 1 )
          goto LABEL_2006;
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1304;
        if ( get_subseq() || get_frame_time() )
          return;
        if ( get_frame() != 5 )
          goto LABEL_2022;
        add_card_energy(50);
        spell_energy_spend(200, 120);
        field_190 = 1;
        tt[0] = 3.0;
        tt[1] = 25.0;
        tt[2] = 0.0;
        tt[3] = 0.80000001;
        addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(-3.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
        tt[0] = 1.0;
        tt[3] = 0.40000001;
        addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(-1.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
        tt[0] = -1.0;
        tt[3] = -0.40000001;
        addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(1.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
        tt[0] = -3.0;
        tt[3] = -0.80000001;
        v1582 = sin_deg(3.0) * 100.0 + y + 100.0;
        goto LABEL_2020;
      case 553:
        if ( get_subseq() == 1 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 1 )
        {
LABEL_2006:
          set_subseq(1);
LABEL_2007:
          air_dash_cnt = 0;
          y = getlvl_height();
          reset_forces();
          return;
        }
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1304;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 5 )
          {
            add_card_energy(50);
            spell_energy_spend(200, 120);
            field_190 = 1;
            tt[0] = 45.0;
            tt[1] = 25.0;
            tt[2] = 0.0;
            tt[3] = -1.2;
            addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(-45.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
            tt[0] = 25.0;
            tt[3] = -0.60000002;
            addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(-25.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
            tt[0] = -25.0;
            tt[3] = 0.60000002;
            addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, sin_deg(25.0) * 100.0 + y + 100.0, dir, 1, tt, 4);
            tt[0] = -45.0;
            tt[3] = 1.2;
            v1582 = sin_deg(45.0) * 100.0 + y + 100.0;
LABEL_2020:
            addbullet(this, NULL, 822, (cos_deg(-tt[0]) * 100.0 - 100.0) * (double)dir + x, v1582, dir, 1, tt, 4);
LABEL_2021:
            play_sfx(12);
          }
LABEL_2022:
          if ( !get_frame_time() )
          {
            v458 = get_frame() == 7;
LABEL_2024:
            if ( v458 )
              v_force = 0.5;
          }
        }
        return;
      case 560:
        if ( !get_subseq() || get_subseq() == 4 )
        {
          sub10func();
          
        }
        field_18C = 3;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          h_inerc = 0.0;
          v_inerc = 0.0;
        }
        if ( get_subseq() == 1 && get_elaps_frames() >= 10 )
        {
          t[0] = 10.0;
          t[1] = 0.0;
          t[2] = 6.0;
          addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
          t[0] = -10.0;
          t[2] = 7.0;
          addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
          next_subseq();
          v1067 = 450.0;
          goto LABEL_2065;
        }
        if ( get_subseq() == 3 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_2812;
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 8.0;
            addbullet(this, NULL, 813, x, y + 100.0, dir, 1, t, 3);
            t[0] = 10.0;
            t[2] = 9.0;
            addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
            t[0] = -10.0;
            t[2] = 10.0;
            addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            add_card_energy(50);
            spell_energy_spend(200, 120);
            /*
            v1069 = 0.0;
            v1679 = 0.0;
            v1070 = (float)0.0;
            while ( 1 )
            {
              *(float *)&v2017 = v1069;
              v2018 = v1069;
              v2019 = v1070;
              v1071 = dir;
              v1072 = y + 115.0;
              v1073 = v1072;
              v1074 = x - (double)(8 * (char)v1071);
              addbullet(this, NULL, 813, v1074, v1073, v1071, 1, (int)&v2017, 3);
              v1679 = v1679 + 1.0;
              if ( v1679 >= 6.0 )
                break;
              v1070 = v1679;
              v1069 = 0.0;
            }
            */
          }
        }
        goto LABEL_2143;
      case 561:
        if ( !get_subseq() || get_subseq() == 4 )
        {
          sub10func();
          
        }
        field_18C = 3;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          h_inerc = 0.0;
          v_inerc = 0.0;
        }
        if ( get_subseq() == 1 && get_elaps_frames() >= 10 )
        {
          t[0] = 10.0;
          t[1] = 0.0;
          t[2] = 6.0;
          addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
          t[0] = -10.0;
          t[2] = 7.0;
          addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
          next_subseq();
          v1067 = -450.0;
LABEL_2065:
          h_inerc = v1067;
          v_inerc = 30.0;
          if ( skills_1[3] >= 4 )
            v_inerc = 15.0;
          v_force = 0.25;
          play_sfx(13);
          return;
        }
        if ( get_subseq() == 3 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_2812;
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 8.0;
            addbullet(this, NULL, 813, x, y + 100.0, dir, 1, t, 3);
            t[0] = 10.0;
            t[2] = 9.0;
            addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
            t[0] = -10.0;
            t[2] = 10.0;
            addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            add_card_energy(50);
            spell_energy_spend(200, 120);
            /*
            v1078 = 0.0;
            v1680 = 0.0;
            v1079 = (float)0.0;
            while ( 1 )
            {
              *(float *)&v2047 = v1078;
              v2048 = v1078;
              v2049 = v1079;
              v1080 = dir;
              v1081 = y + 115.0;
              v1082 = v1081;
              v1083 = x - (double)(8 * (char)v1080);
              addbullet(this, NULL, 813, v1083, v1082, v1080, 1, (int)&v2047, 3);
              v1680 = v1680 + 1.0;
              if ( v1680 >= 6.0 )
                break;
              v1079 = v1680;
              v1078 = 0.0;
            }
            */
          }
        }
        goto LABEL_2143;
      case 562:
        field_18C = 3;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          h_inerc = 0.0;
          v_inerc = 0.0;
        }
        if ( get_subseq() == 1 && get_elaps_frames() >= 10 )
        {
          t[0] = 10.0;
          t[1] = 0.0;
          t[2] = 6.0;
          addbullet(this, NULL, 813, (double)(22 * (char)dir) + x, y + 6.0, dir, 1, t, 3);
          t[0] = -10.0;
          t[2] = 7.0;
          addbullet(this, NULL, 813, (double)(22 * (char)dir) + x, y + 6.0, dir, 1, t, 3);
          next_subseq();
          v1093 = 350.0;
          goto LABEL_2118;
        }
        if ( get_subseq() == 3 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_2123;
        }
        if ( process() )
          set_seq(9);
        if ( get_elaps_frames() )
          goto LABEL_2143;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
        {
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 8.0;
          addbullet(this, NULL, 813, x, y + 100.0, dir, 1, t, 3);
          t[0] = 10.0;
          t[2] = 9.0;
          addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
          t[0] = -10.0;
          t[2] = 10.0;
          addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
        }
        if ( get_elaps_frames() )
          goto LABEL_2143;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          add_card_energy(50);
          spell_energy_spend(200, 120);
          /*
          v1095 = 0.0;
          v1681 = 0.0;
          v1096 = (float)0.0;
          while ( 1 )
          {
            *(float *)&v1987 = v1095;
            v1988 = v1095;
            v1989 = v1096;
            v1097 = dir;
            v1098 = y + 115.0;
            v1099 = v1098;
            v1100 = x - (double)(8 * (char)v1097);
            addbullet(this, NULL, 813, v1100, v1099, v1097, 1, (int)&v1987, 3);
            v1681 = v1681 + 1.0;
            if ( v1681 >= 6.0 )
              break;
            v1096 = v1681;
            v1095 = 0.0;
          }
          */
        }
        goto LABEL_2138;
      case 563:
        field_18C = 3;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          h_inerc = 0.0;
          v_inerc = 0.0;
        }
        if ( get_subseq() != 1 || get_elaps_frames() < 10 )
        {
          if ( get_subseq() == 3 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
          {
LABEL_2123:
            next_subseq();
            reset_forces();
            y = getlvl_height();
          }
          else
          {
            if ( process() )
              set_seq(9);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 8.0;
                addbullet(this, NULL, 813, x, y + 100.0, dir, 1, t, 3);
                t[0] = 10.0;
                t[2] = 9.0;
                addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
                t[0] = -10.0;
                t[2] = 10.0;
                addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
              }
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  add_card_energy(50);
                  spell_energy_spend(200, 120);
                  /*
                  v1111 = 0.0;
                  v1682 = 0.0;
                  v1112 = (float)0.0;
                  while ( 1 )
                  {
                    *(float *)&v1990 = v1111;
                    v1991 = v1111;
                    v1992 = v1112;
                    v1113 = dir;
                    v1114 = y + 115.0;
                    v1115 = v1114;
                    v1116 = x - (double)(8 * (char)v1113);
                    addbullet(this, NULL, 813, v1116, v1115, v1113, 1, (int)&v1990, 3);
                    v1682 = v1682 + 1.0;
                    if ( v1682 >= 6.0 )
                      break;
                    v1112 = v1682;
                    v1111 = 0.0;
                  }
                  */
                }
LABEL_2138:
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
                  flip_with_force();
              }
            }
LABEL_2143:
            if ( get_subseq() >= 3 && skills_1[3] >= 4 )
              field_51C = 2;
          }
        }
        else
        {
          t[0] = 10.0;
          t[1] = 0.0;
          t[2] = 6.0;
          addbullet(this, NULL, 813, (double)(22 * (char)dir) + x, y + 6.0, dir, 1, t, 3);
          t[0] = -10.0;
          t[2] = 7.0;
          addbullet(this, NULL, 813, (double)(22 * (char)dir) + x, y + 6.0, dir, 1, t, 3);
          next_subseq();
          v1093 = -350.0;
LABEL_2118:
          h_inerc = v1093;
          v_inerc = 30.0;
          if ( skills_1[3] >= 4 )
            v_inerc = 15.0;
          v_force = 0.5;
          play_sfx(13);
        }
        return;
      case 565:
        if ( !get_subseq() || get_subseq() == 2 )
        {
          sub10func();
          
        }
        field_18C = 7;
        if ( !get_subseq() && field_190 == 3 )
        {
          t[0] = 0.0;
          t[1] = 20.0;
          t[2] = 2.0;
          addbullet(this, NULL, 818, x, y + 200.0, 1, 1, t, 3);
          sub_4834E0(60);
          next_subseq();
          play_sfx(16);
        }
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() )
          goto LABEL_2167;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_2909;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          /*
          v1876 = 20.0;
          v1877 = 0.0;
          v1683 = 0.0;
          v1119 = 18.0;
          v1120 = (float)0.0;
          while ( 1 )
          {
            *(float *)&v1875 = v1120 * v1119 + 176.0;
            v1121 = dir;
            v1122 = v1119 * -v1120;
            v1123 = sin_deg(v1122) * 300.0 + enemy->y + 100.0;
            v1124 = v1123;
            v1125 = cos_deg(v1122) * 300.0 * (double)dir + enemy->x;
            addbullet(this, NULL, 818, v1125, v1124, v1121, 1, (int)&v1875, 3);
            v1683 = v1683 + 1.0;
            if ( v1683 >= 20.0 )
              break;
            v1120 = v1683;
            v1119 = 18.0;
          }
          v1684 = 0.0;
          v1126 = (float)0.0;
          do
          {
            *(float *)&v1875 = v1126 * 18.0 + 184.0;
            v1127 = dir;
            v1128 = 18.0 * -v1126;
            v1129 = sin_deg(v1128) * 400.0 + enemy->y + 100.0;
            v1130 = v1129;
            v1131 = cos_deg(v1128) * 400.0 * (double)dir + enemy->x;
            addbullet(this, NULL, 818, v1131, v1130, v1127, 1, (int)&v1875, 3);
            v1684 = v1684 + 1.0;
            v1126 = v1684;
          }
          while ( v1684 < 20.0 );
          */
          play_sfx(2);
          x = (double)(150 * dir) + enemy->x;
          y = getlvl_height();
        }
LABEL_2167:
        if ( get_subseq() || get_frame_time() )
          return;
        if ( get_frame() != 1 || skills_1[7] < 3 )
          goto LABEL_2197;
        next_frame();
        return;
      case 566:
        if ( !get_subseq() || get_subseq() == 2 )
        {
          sub10func();
          
        }
        field_18C = 7;
        if ( !get_subseq() && field_190 == 3 )
        {
          t[0] = 0.0;
          t[1] = 20.0;
          t[2] = 2.0;
          addbullet(this, NULL, 818, x, y + 200.0, 1, 1, t, 3);
          sub_4834E0(60);
          next_subseq();
          play_sfx(16);
        }
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() )
          goto LABEL_2193;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_2909;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          /*
          v1894 = 20.0;
          v1895 = 0.0;
          v1685 = 0.0;
          v1134 = 18.0;
          v1135 = (float)0.0;
          while ( 1 )
          {
            *(float *)&v1893 = v1135 * v1134 + 176.0;
            v1136 = dir;
            v1137 = v1134 * -v1135;
            v1138 = sin_deg(v1137) * 300.0 + enemy->y + 100.0;
            v1139 = v1138;
            v1140 = cos_deg(v1137) * 300.0 * (double)dir + enemy->x;
            addbullet(this, NULL, 818, v1140, v1139, v1136, 1, (int)&v1893, 3);
            v1685 = v1685 + 1.0;
            if ( v1685 >= 20.0 )
              break;
            v1135 = v1685;
            v1134 = 18.0;
          }
          v1686 = 0.0;
          v1141 = (float)0.0;
          do
          {
            *(float *)&v1893 = v1141 * 18.0 + 184.0;
            v1142 = dir;
            v1143 = 18.0 * -v1141;
            v1144 = sin_deg(v1143) * 400.0 + enemy->y + 100.0;
            v1145 = v1144;
            v1146 = cos_deg(v1143) * 400.0 * (double)dir + enemy->x;
            addbullet(this, NULL, 818, v1146, v1145, v1142, 1, (int)&v1893, 3);
            v1686 = v1686 + 1.0;
            v1141 = v1686;
          }
          while ( v1686 < 20.0 );
          */
          play_sfx(2);
          x = (double)(150 * dir) + enemy->x;
          y = getlvl_height();
        }
LABEL_2193:
        if ( get_subseq() || get_frame_time() )
          return;
        if ( get_frame() == 1 && skills_1[7] >= 3 )
          goto LABEL_2341;
LABEL_2197:
        if ( get_frame() == 4 )
        {
          add_card_energy(50);
          spell_energy_spend(200, 120);
        }
        return;
      case 567:
        if ( get_subseq() >= 2 )
        {
          sub10func();
          
        }
        field_18C = 7;
        if ( !get_subseq() )
        {
          if ( field_190 == 3 )
          {
            t[0] = 0.0;
            t[1] = 20.0;
            t[2] = 2.0;
            addbullet(this, NULL, 818, x, y + 200.0, 1, 1, t, 3);
            sub_4834E0(60);
            next_subseq();
            play_sfx(16);
          }
          if ( get_frame() >= 9 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              reset_forces();
              y = getlvl_height();
              set_subseq(3);
              return;
            }
          }
        }
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() )
          goto LABEL_2223;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
LABEL_2213:
          set_seq(9);
          return;
        }
        if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          /*
          v1882 = 20.0;
          v1883 = 0.0;
          v1687 = 0.0;
          v1148 = 18.0;
          v1149 = (float)0.0;
          while ( 1 )
          {
            *(float *)&v1881 = v1149 * v1148 + 176.0;
            v1150 = dir;
            v1151 = v1148 * -v1149;
            v1152 = sin_deg(v1151) * 300.0 + enemy->y + 100.0;
            v1153 = v1152;
            v1154 = cos_deg(v1151) * 300.0 * (double)dir + enemy->x;
            addbullet(this, NULL, 818, v1154, v1153, v1150, 1, (int)&v1881, 3);
            v1687 = v1687 + 1.0;
            if ( v1687 >= 20.0 )
              break;
            v1149 = v1687;
            v1148 = 18.0;
          }
          v1688 = 0.0;
          v1155 = (float)0.0;
          do
          {
            *(float *)&v1881 = v1155 * 18.0 + 184.0;
            v1156 = dir;
            v1157 = 18.0 * -v1155;
            v1158 = sin_deg(v1157) * 400.0 + enemy->y + 100.0;
            v1159 = v1158;
            v1160 = cos_deg(v1157) * 400.0 * (double)dir + enemy->x;
            addbullet(this, NULL, 818, v1160, v1159, v1156, 1, (int)&v1881, 3);
            v1688 = v1688 + 1.0;
            v1155 = v1688;
          }
          while ( v1688 < 20.0 );
          */
          play_sfx(2);
          x = (double)(150 * dir) + enemy->x;
          y = getlvl_height();
        }
LABEL_2223:
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
          goto LABEL_2909;
        if ( get_subseq() )
          return;
        if ( get_frame_time() )
          goto LABEL_2233;
        if ( get_frame() == 1 && skills_1[7] >= 3 )
          goto LABEL_2341;
        if ( get_frame() == 4 )
        {
          add_card_energy(50);
          spell_energy_spend(200, 120);
        }
LABEL_2233:
        if ( !get_frame_time() && get_frame() == 9 )
          v_force = 0.5;
        return;
      case 568:
        if ( get_subseq() >= 2 )
        {
          sub10func();
          
        }
        field_18C = 7;
        if ( !get_subseq() )
        {
          if ( field_190 == 3 )
          {
            t[0] = 0.0;
            t[1] = 20.0;
            t[2] = 2.0;
            addbullet(this, NULL, 818, x, y + 200.0, 1, 1, t, 3);
            sub_4834E0(60);
            next_subseq();
            play_sfx(16);
          }
          if ( get_frame() >= 11 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_2243;
          }
        }
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() )
          goto LABEL_2259;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_845;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          /*
          v1906 = 20.0;
          v1907 = 0.0;
          v1689 = 0.0;
          v1162 = 18.0;
          v1163 = (float)0.0;
          while ( 1 )
          {
            *(float *)&v1905 = v1163 * v1162 + 176.0;
            v1164 = dir;
            v1165 = v1162 * -v1163;
            v1166 = sin_deg(v1165) * 300.0 + enemy->y + 100.0;
            v1167 = v1166;
            v1168 = cos_deg(v1165) * 300.0 * (double)dir + enemy->x;
            addbullet(this, NULL, 818, v1168, v1167, v1164, 1, (int)&v1905, 3);
            v1689 = v1689 + 1.0;
            if ( v1689 >= 20.0 )
              break;
            v1163 = v1689;
            v1162 = 18.0;
          }
          v1690 = 0.0;
          v1169 = (float)0.0;
          do
          {
            *(float *)&v1905 = v1169 * 18.0 + 184.0;
            v1170 = dir;
            v1171 = 18.0 * -v1169;
            v1172 = sin_deg(v1171) * 400.0 + enemy->y + 100.0;
            v1173 = v1172;
            v1174 = cos_deg(v1171) * 400.0 * (double)dir + enemy->x;
            addbullet(this, NULL, 818, v1174, v1173, v1170, 1, (int)&v1905, 3);
            v1690 = v1690 + 1.0;
            v1169 = v1690;
          }
          while ( v1690 < 20.0 );
          */
          play_sfx(2);
          x = (double)(150 * dir) + enemy->x;
          y = getlvl_height();
        }
LABEL_2259:
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
          goto LABEL_845;
        if ( get_subseq() )
          return;
        if ( get_frame_time() )
          goto LABEL_2269;
        if ( get_frame() == 1 && skills_1[7] >= 3 )
          goto LABEL_2341;
        if ( get_frame() == 4 )
        {
          add_card_energy(50);
          spell_energy_spend(200, 120);
        }
LABEL_2269:
        if ( !get_frame_time() && get_frame() == 11 )
          v_force = 0.5;
        return;
      case 570:
        sub10func();
        field_18C = 11;
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 2 )
          {
            add_card_energy(50);
            spell_energy_spend(200, 120);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 823, x, y, dir, 1, t, 3);
            play_sfx(18);
          }
          if ( !get_frame_time() && get_frame() == 4 )
          {
            scene_add_effect(this, 127, x, y, dir, -1);
            h_inerc = 17.5;
          }
        }
        if ( get_subseq() != 1 )
          goto LABEL_2290;
        if ( get_elaps_frames() >= 15 )
          goto LABEL_2741;
        if ( enemy->x < (double)x && dir == -1 && x - enemy->x <= 200.0 )
          goto LABEL_2741;
        if ( enemy->x > (double)x && dir == 1 && enemy->x - x <= 200.0 )
        {
          next_subseq();
          return;
        }
LABEL_2290:
        if ( get_subseq() != 2 )
          return;
        if ( get_frame() >= 0 )
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( field_190 )
          field_7D0 = 1;
        if ( !get_frame_time() && get_frame() == 4 )
          play_sfx(55);
        if ( get_frame() != 7 )
          return;
        if ( get_frame_time() >= 32 && skills_1[11] >= 2 )
          goto LABEL_2341;
        /*
        v1180 = __OFSUB__(get_frame_time(), 29);
        v1179 = (signed __int16)(get_frame_time() - 29) < 0;
        */
        //goto LABEL_2339;
      	return; //TODO: change
      case 571:
        sub10func();
        field_18C = 11;
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() )
          goto LABEL_2920;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          add_card_energy(50);
          spell_energy_spend(200, 120);
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 6.0;
          addbullet(this, NULL, 823, x, y, dir, 1, t, 3);
          play_sfx(18);
          scene_add_effect(this, 127, x, y, dir, -1);
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
        {
LABEL_2920:
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
          {
            h_inerc = 17.5;
            scene_add_effect(this, 127, x, y, dir, -1);
          }
        }
        else if ( get_subseq() == 2 )
        {
          set_seq(0);
          return;
        }
        if ( get_subseq() != 3 )
          goto LABEL_2328;
        if ( get_elaps_frames() >= 15 )
          goto LABEL_2741;
        if ( enemy->x < (double)x && dir == -1 && x - enemy->x <= 200.0 )
          goto LABEL_2741;
        if ( enemy->x > (double)x && dir == 1 && enemy->x - x <= 200.0 )
        {
          next_subseq();
          return;
        }
LABEL_2328:
        if ( get_subseq() == 4 )
        {
          if ( get_frame() >= 0 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( !get_frame_time() && get_frame() == 4 )
            play_sfx(55);
          if ( get_frame() == 7 )
          {
            if ( get_frame_time() >= 8 && skills_1[11] >= 2 )
              goto LABEL_2341;
            /*
            v1180 = __OFSUB__(get_frame_time(), 7);
            v1179 = (signed __int16)(get_frame_time() - 7) < 0;
LABEL_2339:
            if ( !(v1179 ^ v1180) && skills_1[11] >= 4 )
              goto LABEL_2341;
              */
          }
        }
        return;
      case 599:
        if ( field_7D0 > 0 && get_frame() < 7 && field_7D0 < 12 )
        {
          /*
          v1186 = MT_getnext() % 0x23u;
          field_7D4 = v1186;
          *(float *)&v1806 = (double)(-20 - v1186);
          v1807 = (double)(signed __int16)(MT_getnext() % 5u + 10);
          v1808 = 0.0;
          v1187 = dir;
          v1188 = (double)(20 * (char)v1187 * (field_7D0 + 1)) + x;
          addbullet(this, NULL, 807, v1188, y, v1187, 1, (int)&v1806, 3);
          *(float *)&v1806 = (double)(MT_getnext() % 0x168u);
          v1807 = 0.0;
          v1808 = 1.0;
          v1189 = dir;
          v1190 = (double)(20 * (char)v1189 * (field_7D0 + 1)) + x;
          addbullet(this, NULL, 801, v1190, y, v1189, 1, (int)&v1806, 3);
          */
          if ( field_7D0 == 1 )
          {
            play_sfx(0);
            spell_energy_spend(200, 120);
          }
          ++field_7D0;
        }
        if ( process() )
          set_seq(0);
        if ( !get_frame_time() && get_frame() == 5 )
          field_7D0 = 1;
        return;
      case 600:
        sub10func();
        sub_46AB50(5, 2);
        if ( get_subseq() != 1 )
          goto LABEL_2358;
        if ( get_elaps_frames() >= 32 )
          goto LABEL_2680;
        if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= 30 )
        {
          tt[0] = (double)(12 * get_elaps_frames()) + 90.0;
          tt[1] = 15.0;
          tt[2] = 0.0;
          tt[3] = 90.0;
          addbullet(this, NULL, 850, cos_deg(-tt[0]) * 100.0 * (double)dir + x, sin_deg(-tt[0]) * 100.0 + y + 150.0, dir, 1, tt, 4);
          tt[0] = (double)(12 * get_elaps_frames()) + 270.0;
          addbullet(this, NULL, 850, cos_deg(-tt[0]) * 100.0 * (double)dir + x, sin_deg(-tt[0]) * 100.0 + y + 150.0, dir, 1, tt, 4);
        }
LABEL_2358:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          play_sfx(50);
        if ( get_subseq() || get_frame_time() || get_frame() != 3 )
          return;
        sub_4834E0(40);
        field_890 = 0;
        field_892 = 0;
        scene_play_sfx(23);
        scene_add_effect(this, 115, x - (double)(23 * (char)dir), y + 158.0, dir, 1);
        sub_469450(0, 0, 60);
        goto LABEL_2449;
      case 601:
        sub10func();
        sub_46AB50(5, 2);
        if ( get_subseq() == 4 && get_elaps_frames() >= 45 )
          next_subseq();
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
          {
            sub_4834E0(40);
            field_890 = 0;
            field_892 = 0;
            scene_play_sfx(23);
            scene_add_effect(this, 115, (double)(26 * (char)dir) + x, y + 88.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 851, 640.0, 480.0, 1, -2, t, 3);
            play_sfx(52);
            field_892 = 300;
          }
        }
        return;
      case 602:
        if ( !get_subseq() || get_subseq() == 4 )
          sub10func();
        sub_46AB50(5, 2);
        if ( get_subseq() == 1 )
        {
          if ( !(get_elaps_frames() % 4) )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 852, (double)(60 * (char)dir) + x, y + 130.0, dir, 1, t, 3);
            t[2] = 1.0;
            addbullet(this, NULL, 852, (double)(60 * (char)dir) + x, y + 130.0, dir, 1, t, 3);
            play_sfx(54);
          }
          if ( get_elaps_frames() > 90 )
            goto LABEL_2680;
        }
        if ( get_subseq() == 2 || get_subseq() == 3 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_2473;
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
        {
          sub_4834E0(40);
          field_890 = 0;
          field_892 = 0;
          scene_play_sfx(23);
          scene_add_effect(this, 115, (double)(30 * (char)dir) + x, y + 85.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          field_51C = 12;
          h_inerc = 0.5;
          v_inerc = 1.0;
          v_force = 0.5;
        }
        return;
      case 603:
        sub10func();
        sub_46AB50(5, 2);
        if ( get_subseq() == 1 )
        {
          if ( !(get_elaps_frames() % 3) && get_elaps_frames() <= 60 )
          {
            /*
            v1912 = 2.0;
            v1913 = 8.0;
            v1691 = 0.0;
            v1226 = 3.0;
            v1227 = (float)0.0;
            do
            {
              v1228 = v1227 * 120.0;
              *(float *)&v1911 = v1228 + field_7DC;
              v1914 = v1226;
              v1229 = dir;
              v1230 = -*(float *)&v1911;
              v1231 = sin_deg(v1230) * 60.0 + y + 150.0;
              v1232 = v1231;
              v1233 = -*(float *)&v1911;
              v1234 = cos_deg(v1233) * 60.0 * (double)dir + x;
              addbullet(this, NULL, 853, v1234, v1232, v1229, 1, (int)&v1911, 4);
              v1691 = v1691 + 1.0;
              v1226 = 3.0;
              v1227 = v1691;
            }
            while ( v1691 < 3.0 );
            */
            field_7DC = field_7DC + 8.0;
          }
          if ( get_elaps_frames() > 135 )
            goto LABEL_2741;
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          play_sfx(51);
        if ( get_subseq() || get_frame_time() || get_frame() != 3 )
          return;
        sub_4834E0(40);
        field_890 = 0;
        field_892 = 0;
        scene_play_sfx(23);
        goto LABEL_2448;
      case 604:
        sub10func();
        sub_46AB50(5, 2);
        if ( get_subseq() == 1 && get_elaps_frames() >= 60 )
        {
          next_subseq();
          sub_4834E0(40);
          field_890 = 0;
          field_892 = 0;
          scene_play_sfx(23);
          scene_add_effect(this, 115, (double)(26 * (char)dir) + x, y + 88.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        if ( get_subseq() == 4 && get_elaps_frames() >= 45 )
          next_subseq();
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
        {
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 854, 640.0, 480.0, 1, -2, t, 3);
          play_sfx(53);
          sub_4834E0(40);
          field_890 = 300;
          field_898 = 300;
        }
        return;
      case 605:
        if ( !get_subseq() || get_subseq() == 4 )
          sub10func();
        sub_46AB50(5, 2);
        if ( get_subseq() == 1 )
        {
          if ( !(get_elaps_frames() % 4) )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 855, (double)(60 * (char)dir) + x, y + 130.0, dir, 1, t, 3);
            t[2] = 1.0;
            addbullet(this, NULL, 855, x - (double)(640 * dir), y + 300.0 - /*(double)(unsigned int)get_MT_range(400)*/400.0, dir, 1, t, 3);
            t[2] = 2.0;
            addbullet(this, NULL, 855, (double)(60 * (char)dir) + x, y + 130.0, dir, 1, t, 3);
            play_sfx(54);
          }
          if ( get_elaps_frames() > 90 )
            goto LABEL_2680;
        }
        if ( get_subseq() == 2 || get_subseq() == 3 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_2473:
            y = getlvl_height();
            set_subseq(4);
            reset_forces();
            return;
          }
        }
        if ( process() )
          set_seq(0);
        if ( get_subseq() || get_frame_time() || get_frame() != 4 )
          goto LABEL_2514;
        sub_4834E0(40);
        field_890 = 0;
        field_892 = 0;
        scene_play_sfx(23);
        goto LABEL_2513;
      case 606:
        sub10func();
        sub_46AB50(5, 2);
        if ( get_subseq() == 1 && get_elaps_frames() > 36 )
          goto LABEL_2741;
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 3 )
          {
            sub_4834E0(40);
            field_890 = 0;
            field_892 = 0;
            scene_play_sfx(23);
            scene_add_effect(this, 115, x - (double)(23 * (char)dir), y + 158.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_frame_time() && get_frame() == 8 )
          {
            play_sfx(15);
            /*
            v1693 = 0.0;
            v1275 = (float)0.0;
            do
            {
              *(float *)&v1956 = v1275 * 12.0;
              v1957 = 6.0;
              v1958 = 0.0;
              v1276 = dir;
              v1277 = -*(float *)&v1956;
              v1278 = sin_deg(v1277) * 100.0 + y + 150.0;
              v1279 = v1278;
              v1280 = -*(float *)&v1956;
              v1281 = cos_deg(v1280) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 856, v1281, v1279, v1276, 1, (int)&v1956, 3);
              v1693 = v1693 + 1.0;
              v1275 = v1693;
            }
            while ( v1693 < 30.0 );
            */
          }
        }
        return;
      case 607:
        if ( !get_subseq() || get_subseq() == 4 )
          sub10func();
        sub_46AB50(5, 2);
        if ( get_subseq() == 1 )
        {
          if ( !(get_elaps_frames() % 2) )
          {
            t[0] = /*(double)(unsigned int)get_MT_range(60)*/60.0 - 30.0;
            if ( get_elaps_frames() % 10 )
            {
              t[1] = /*(double)(unsigned int)get_MT_range(50)*/50.0 * 0.1000000014901161 + 10.0;
              t[2] = 0.0;
            }
            else
            {
              t[1] = /*(double)(unsigned int)get_MT_range(50)*/50.0 * 0.1000000014901161 + 15.0;
              t[2] = 1.0;
              play_sfx(2);
            }
            addbullet(this, NULL, 857, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-t[0]) * 200.0 + y + 110.0, dir, 1, t, 3);
          }
          if ( get_elaps_frames() > 90 )
            goto LABEL_2741;
        }
        if ( (get_subseq() == 2 || get_subseq() == 3) && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
        {
          y = getlvl_height();
          set_subseq(4);
          reset_forces();
        }
        else
        {
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            sub_4834E0(40);
            field_890 = 0;
            field_892 = 0;
            scene_play_sfx(23);
LABEL_2513:
            scene_add_effect(this, 115, (double)(30 * (char)dir) + x, y + 85.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
LABEL_2514:
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            h_inerc = 0.5;
            v_inerc = 0.89999998;
            v_force = 0.5;
          }
        }
        return;
      case 608:
        sub10func();
        sub_46AB50(5, 2);
        if ( process() )
          set_seq(0);
        if ( get_subseq() || get_frame_time() )
          return;
        if ( get_frame() == 3 )
        {
          sub_4834E0(40);
          field_890 = 0;
          field_892 = 0;
          scene_play_sfx(23);
          scene_add_effect(this, 115, x - (double)(35 * (char)dir), y + 155.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        if ( get_frame_time() || get_frame() != 6 )
          return;
        tt[0] = 2.0;
        if ( dY() )
          tt[0] = 88.0;
        tt[1] = 100.0;
        tt[2] = 0.0;
        tt[3] = 14.0;
        addbullet(this, NULL, 858, (double)(100 * (char)dir) + x, y + 110.0, dir, 1, tt, 4);
        goto LABEL_2589;
      case 609:
        sub10func();
        sub_46AB50(5, 2);
        if ( get_subseq() == 1 && get_elaps_frames() >= 40 )
          next_subseq();
        if ( get_subseq() == 4 && get_elaps_frames() >= 45 )
          next_subseq();
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, (double)(26 * (char)dir) + x, y + 88.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            field_890 = 0;
            field_892 = 0;
            weather_forecast_next();
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
          {
            /*
            v1741 = 25.0;
            v1742 = 0.0;
            v1694 = 0.0;
            for ( k = (float)0.0; ; k = v1694 )
            {
              *(float *)&v1740 = k * 36.0;
              v1306 = y + 130.0;
              addbullet(this, NULL, 859, x, v1306, 1, -1, (int)&v1740, 3);
              v1694 = v1694 + 1.0;
              if ( v1694 >= 10.0 )
                break;
            }
            v1741 = 10.0;
            v1695 = 0.0;
            v1307 = (float)0.0;
            do
            {
              *(float *)&v1740 = v1307 * 36.0 + 18.0;
              v1308 = y + 130.0;
              addbullet(this, NULL, 859, x, v1308, 1, -1, (int)&v1740, 3);
              v1695 = v1695 + 1.0;
              v1307 = v1695;
            }
            while ( v1695 < 10.0 );
            *(float *)&v1740 = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
            v1741 = 15.0;
            v1742 = 4.0;
            v1309 = y + 130.0;
            addbullet(this, NULL, 859, x, v1309, dir, 1, (int)&v1740, 3);
            v1741 = 15.0;
            v1742 = 5.0;
            v1310 = y + 130.0;
            addbullet(this, NULL, 859, x, v1310, dir, 1, (int)&v1740, 3);
            v1741 = -15.0;
            v1742 = 6.0;
            v1311 = y + 130.0;
            addbullet(this, NULL, 859, x, v1311, dir, 1, (int)&v1740, 3);
            */
            scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
            play_sfx(53);
          }
        }
        return;
      case 610:
        sub10func();
        sub_46AB50(5, 2);
        if ( process() )
          set_seq(0);
        if ( get_subseq() || get_frame_time() )
          return;
        if ( get_frame() == 3 )
        {
          sub_4834E0(40);
          field_890 = 0;
          field_892 = 0;
          scene_play_sfx(23);
          scene_add_effect(this, 115, x - (double)(35 * (char)dir), y + 155.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        if ( get_frame_time() || get_frame() != 6 )
          return;
        tt[0] = 2.0;
        tt[1] = 150.0;
        tt[2] = 0.0;
        tt[3] = 0.0;
        addbullet(this, NULL, 860, (double)(100 * (char)dir) + x, y + 110.0, dir, 1, tt, 4);
        goto LABEL_2589;
      case 611:
        sub10func();
        sub_46AB50(5, 2);
        if ( get_subseq() == 4 )
        {
          if ( !(get_elaps_frames() % 2) && field_7DC < 7.0 )
          {
            tt[0] = field_7DC * 25.0 - 80.0;
            tt[1] = 10.0;
            tt[2] = 3.0;
            tt[3] = 2.0;
            addbullet(this, NULL, 861, (cos_deg(-tt[0]) * 100.0 - 200.0) * (double)dir + x, sin_deg(-tt[0]) * 100.0 + y + 100.0, dir, 1, tt, 4);
            tt[0] = 80.0 - field_7DC * 25.0;
            tt[3] = -2.0;
            addbullet(this, NULL, 861, (cos_deg(-tt[0]) * 100.0 - 200.0) * (double)dir + x, sin_deg(-tt[0]) * 100.0 + y + 100.0, dir, 1, tt, 4);
            field_7DC = field_7DC + 1.0;
          }
          if ( get_elaps_frames() >= 60 )
            next_subseq();
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
          {
            sub_4834E0(40);
            field_890 = 0;
            field_892 = 0;
            scene_play_sfx(23);
            scene_add_effect(this, 115, (double)(26 * (char)dir) + x, y + 88.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 854, 640.0, 480.0, 1, -2, t, 3);
            play_sfx(53);
            sub_4834E0(60);
            field_890 = 60;
          }
        }
        return;
      case 612:
        sub10func();
        sub_46AB50(5, 2);
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 6 )
          {
            sub_4834E0(40);
            field_890 = 0;
            field_892 = 0;
            scene_play_sfx(23);
            scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_frame_time() && get_frame() == 12 )
          {
            t[0] = 0.0;
            t[1] = 40.0;
            t[2] = 7.0;
            addbullet(this, NULL, 862, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
LABEL_2589:
            play_sfx(15);
          }
        }
        return;
      case 653:
        if ( get_subseq() == 4 )
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
            set_subseq(4);
            return;
          }
        }
        if ( get_subseq() <= 2 )
          sub_46AB50(5, 2);
        if ( get_subseq() != 1 )
          goto LABEL_2921;
        if ( !(get_elaps_frames() % 3) && get_elaps_frames() <= 60 )
        {
          /*
          v1916 = 2.0;
          v1917 = 8.0;
          v1692 = 0.0;
          v1238 = 3.0;
          v1239 = (float)0.0;
          do
          {
            v1240 = v1239 * 120.0;
            *(float *)&v1915 = v1240 + field_7DC;
            v1918 = v1238;
            v1241 = dir;
            v1242 = -*(float *)&v1915;
            v1243 = sin_deg(v1242) * 60.0 + y + 150.0;
            v1244 = v1243;
            v1245 = -*(float *)&v1915;
            v1246 = cos_deg(v1245) * 60.0 * (double)dir + x;
            addbullet(this, NULL, 853, v1246, v1244, v1241, 1, (int)&v1915, 4);
            v1692 = v1692 + 1.0;
            v1238 = 3.0;
            v1239 = v1692;
          }
          while ( v1692 < 3.0 );
          */
          field_7DC = field_7DC + 8.0;
        }
        if ( get_elaps_frames() <= 135 )
        {
LABEL_2921:
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            play_sfx(51);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
          {
            sub_4834E0(40);
            field_890 = 0;
            field_892 = 0;
            scene_play_sfx(23);
LABEL_2448:
            scene_add_effect(this, 115, x - (double)(23 * (char)dir), y + 158.0, dir, 1);
            sub_469450(0, 0, 60);
LABEL_2449:
            sub_483570();
            weather_forecast_next();
          }
        }
        else
        {
          next_subseq();
          v_force = 0.34999999;
        }
        return;
      case 656:
        sub_46AB50(5, 2);
        if ( get_subseq() == 1 && get_elaps_frames() > 36 )
          goto LABEL_2741;
        if ( get_subseq() < 3 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
        {
LABEL_2243:
          reset_forces();
          y = getlvl_height();
          set_subseq(3);
        }
        else
        {
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 3 )
          {
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                sub_4834E0(40);
                field_890 = 0;
                field_892 = 0;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(23 * (char)dir), y + 158.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 8 )
              {
                play_sfx(15);
                /*
                v1696 = 0.0;
                v1353 = (float)0.0;
                do
                {
                  *(float *)&v1919 = v1353 * 12.0;
                  v1920 = 6.0;
                  v1921 = 0.0;
                  v1354 = dir;
                  v1355 = -*(float *)&v1919;
                  v1356 = sin_deg(v1355) * 100.0 + y + 150.0;
                  v1357 = v1356;
                  v1358 = -*(float *)&v1919;
                  v1359 = cos_deg(v1358) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 856, v1359, v1357, v1354, 1, (int)&v1919, 3);
                  v1696 = v1696 + 1.0;
                  v1353 = v1696;
                }
                while ( v1696 < 30.0 );
                */
              }
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
              v_force = 0.5;
          }
          else
          {
LABEL_845:
            set_seq(9);
          }
        }
        return;
      case 695:
        sub10func();
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 8 )
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
        h_inerc = h_inerc - 0.5;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
        if ( process() )
          set_seq(0);
        if ( !get_frame_time() && get_frame() == 3 )
        {
          scene_play_sfx(29);
          field_49A = 0;
        }
        return;
      case 707:
        if ( h_inerc > 12.0 )
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 12.0 )
            h_inerc = 12.0;
        }
        if ( process() )
        {
          set_seq(700);
          return;
        }
        if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
        {
          h_inerc = 15.0;
          scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
          scene_add_effect(this, 126, x, y + 80.0, dir, 1);
          scene_play_sfx(31);
        }
        if ( get_subseq() == 1 )
        {
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          if ( get_elaps_frames() > 30 )
            goto LABEL_2741;
        }
        if ( get_subseq() == 2 )
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        return;
      case 708:
        if ( get_subseq() == 2 )
        {
          sub10func();
          h_inerc = h_inerc + 2.0;
          if ( h_inerc > 0.0 )
            h_inerc = 0.0;
        }
        if ( !char_on_ground_flag() && !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
        }
        if ( get_subseq() < 2 )
        {
          v_inerc = v_inerc - 0.5;
          if ( char_on_ground_down() )
          {
            v_inerc = 0.0;
            v_force = 0.0;
            y = getlvl_height();
            set_subseq(2);
            return;
          }
        }
        if ( process() )
          goto LABEL_2887;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          h_inerc = -14.0;
          v_inerc = 4.0;
          scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
          scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
          scene_play_sfx(31);
        }
        return;
      case 710:
        sub10func();
        if ( get_subseq() == 1 && get_elaps_frames() > 90 )
          goto LABEL_2680;
        if ( process() )
          set_seq(700);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
        {
          play_sfx(15);
          switch ( settings_get()->get_difficulty() )
          {
            case 0:
            /*
              v1701 = 0.0;
              v1412 = (float)0.0;
              do
              {
                *(float *)&v1946 = v1412 * 24.0;
                v1947 = 6.0;
                v1948 = 0.0;
                v1413 = dir;
                v1414 = -*(float *)&v1946;
                v1415 = sin_deg(v1414) * 100.0 + y + 150.0;
                v1416 = v1415;
                v1417 = -*(float *)&v1946;
                v1418 = cos_deg(v1417) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 900, v1418, v1416, v1413, 1, (int)&v1946, 3);
                v1701 = v1701 + 1.0;
                v1412 = v1701;
              }
              while ( v1701 < 15.0 );
              */
              break;
            case 1:
            /*
              v1700 = 0.0;
              v1405 = (float)0.0;
              do
              {
                *(float *)&v1939 = v1405 * 18.0;
                v1940 = 8.0;
                v1941 = 0.0;
                v1406 = dir;
                v1407 = -*(float *)&v1939;
                v1408 = sin_deg(v1407) * 100.0 + y + 150.0;
                v1409 = v1408;
                v1410 = -*(float *)&v1939;
                v1411 = cos_deg(v1410) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 900, v1411, v1409, v1406, 1, (int)&v1939, 3);
                v1700 = v1700 + 1.0;
                v1405 = v1700;
              }
              while ( v1700 < 20.0 );
              */
              break;
            case 2:/*
              v1699 = 0.0;
              v1398 = (float)0.0;
              do
              {
                *(float *)&v1932 = v1398 * 12.0;
                v1933 = 8.0;
                v1934 = 0.0;
                v1399 = dir;
                v1400 = -*(float *)&v1932;
                v1401 = sin_deg(v1400) * 100.0 + y + 150.0;
                v1402 = v1401;
                v1403 = -*(float *)&v1932;
                v1404 = cos_deg(v1403) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 900, v1404, v1402, v1399, 1, (int)&v1932, 3);
                v1699 = v1699 + 1.0;
                v1398 = v1699;
              }
              while ( v1699 < 30.0 );
              */
              break;
            case 3:/*
              v1697 = 0.0;
              v1384 = (float)0.0;
              do
              {
                *(float *)&v1922 = v1384 * 12.0;
                v1923 = 8.0;
                v1924 = 0.0;
                v1385 = dir;
                v1386 = -*(float *)&v1922;
                v1387 = sin_deg(v1386) * 100.0 + y + 150.0;
                v1388 = v1387;
                v1389 = -*(float *)&v1922;
                v1390 = cos_deg(v1389) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 900, v1390, v1388, v1385, 1, (int)&v1922, 3);
                v1697 = v1697 + 1.0;
                v1384 = v1697;
              }
              while ( v1697 < 30.0 );
              v1698 = 0.0;
              v1391 = (float)0.0;
              do
              {
                *(float *)&v1925 = v1391 * 12.0;
                v1926 = 6.0;
                v1927 = 0.0;
                v1392 = dir;
                v1393 = -*(float *)&v1925;
                v1394 = sin_deg(v1393) * 100.0 + y + 150.0;
                v1395 = v1394;
                v1396 = -*(float *)&v1925;
                v1397 = cos_deg(v1396) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 900, v1397, v1395, v1392, 1, (int)&v1925, 3);
                v1698 = v1698 + 1.0;
                v1391 = v1698;
              }
              while ( v1698 < 10.0 );
              */
              break;
            default:
              return;
          }
        }
        return;
      case 711:
        if ( get_subseq() == 4 && get_elaps_frames() > 90 )
        {
LABEL_2680:
          next_subseq();
          return;
        }
        if ( get_subseq() > 0 )
        {
          v_inerc = v_inerc - v_force;
          if ( get_subseq() < 5 && v_inerc < 0.0 )
          {
            v_inerc = 0.0;
            h_inerc = 0.0;
          }
          if ( char_on_ground_down() )
          {
            reset_forces();
            y = getlvl_height();
            set_seq(709);
            return;
          }
        }
        if ( process() )
        {
          set_seq(704);
          v_force = 0.25;
          return;
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          h_inerc = field_85C;
          v_inerc = field_860;
          v_force = field_864;
        }
        if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 7 )
        {
          v_force = 0.0;
          play_sfx(15);
          switch ( settings_get()->get_difficulty() )
          {
            case 0:
            /*
              v1707 = 0.0;
              v1448 = (float)0.0;
              do
              {
                *(float *)&v1969 = v1448 * 24.0;
                v1970 = 6.0;
                v1971 = 0.0;
                v1449 = dir;
                v1450 = -*(float *)&v1969;
                v1451 = sin_deg(v1450) * 100.0 + y + 150.0;
                v1452 = v1451;
                v1453 = -*(float *)&v1969;
                v1454 = cos_deg(v1453) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 900, v1454, v1452, v1449, 1, (int)&v1969, 3);
                v1707 = v1707 + 1.0;
                v1448 = v1707;
              }
              while ( v1707 < 15.0 );*/
              break;
            case 1:/*
              v1706 = 0.0;
              v1441 = (float)0.0;
              do
              {
                *(float *)&v1972 = v1441 * 18.0;
                v1973 = 8.0;
                v1974 = 0.0;
                v1442 = dir;
                v1443 = -*(float *)&v1972;
                v1444 = sin_deg(v1443) * 100.0 + y + 150.0;
                v1445 = v1444;
                v1446 = -*(float *)&v1972;
                v1447 = cos_deg(v1446) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 900, v1447, v1445, v1442, 1, (int)&v1972, 3);
                v1706 = v1706 + 1.0;
                v1441 = v1706;
              }
              while ( v1706 < 20.0 );*/
              break;
            case 2:/*
              v1705 = 0.0;
              v1434 = (float)0.0;
              do
              {
                *(float *)&v1966 = v1434 * 12.0;
                v1967 = 8.0;
                v1968 = 0.0;
                v1435 = dir;
                v1436 = -*(float *)&v1966;
                v1437 = sin_deg(v1436) * 100.0 + y + 150.0;
                v1438 = v1437;
                v1439 = -*(float *)&v1966;
                v1440 = cos_deg(v1439) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 900, v1440, v1438, v1435, 1, (int)&v1966, 3);
                v1705 = v1705 + 1.0;
                v1434 = v1705;
              }
              while ( v1705 < 30.0 );*/
              break;
            case 3:/*
              v1703 = 0.0;
              v1420 = (float)0.0;
              do
              {
                *(float *)&v1953 = v1420 * 12.0;
                v1954 = 8.0;
                v1955 = 0.0;
                v1421 = dir;
                v1422 = -*(float *)&v1953;
                v1423 = sin_deg(v1422) * 100.0 + y + 150.0;
                v1424 = v1423;
                v1425 = -*(float *)&v1953;
                v1426 = cos_deg(v1425) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 900, v1426, v1424, v1421, 1, (int)&v1953, 3);
                v1703 = v1703 + 1.0;
                v1420 = v1703;
              }
              while ( v1703 < 30.0 );
              v1704 = 0.0;
              v1427 = (float)0.0;
              do
              {
                *(float *)&v1959 = v1427 * 12.0;
                v1960 = 6.0;
                v1961 = 0.0;
                v1428 = dir;
                v1429 = -*(float *)&v1959;
                v1430 = sin_deg(v1429) * 100.0 + y + 150.0;
                v1431 = v1430;
                v1432 = -*(float *)&v1959;
                v1433 = cos_deg(v1432) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 900, v1433, v1431, v1428, 1, (int)&v1959, 3);
                v1704 = v1704 + 1.0;
                v1427 = v1704;
              }
              while ( v1704 < 10.0 );*/
              break;
            default:
              break;
          }
        }
        if ( get_subseq() != 5 || get_frame_time() )
          return;
        goto LABEL_2785;
      case 720:
        sub10func();
        if ( get_subseq() == 1 && get_elaps_frames() >= 40 )
          next_subseq();
        if ( get_subseq() == 3 && get_elaps_frames() >= 45 )
          next_subseq();
        if ( process() )
          set_seq(700);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
        {
          play_sfx(53);
          t[0] = /*(double)(unsigned int)get_MT_range(360)*/360.0;
          t[1] = 15.0;
          t[2] = 4.0;
          addbullet(this, NULL, 901, x, y + 130.0, dir, 1, t, 3);
          t[1] = 15.0;
          t[2] = 5.0;
          addbullet(this, NULL, 901, x, y + 130.0, dir, 1, t, 3);
          t[1] = -15.0;
          t[2] = 6.0;
          addbullet(this, NULL, 901, x, y + 130.0, dir, 1, t, 3);
          switch ( settings_get()->get_difficulty() )
          {
            case 0:/*
              v1726 = 15.0;
              v1727 = 0.0;
              v1711 = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
              v1623 = 0.0;
              v1465 = (float)0.0;
              do
              {
                *(float *)&v1725 = v1465 * 90.0 + v1711;
                v1466 = y + 130.0;
                addbullet(this, NULL, 901, x, v1466, 1, -1, (int)&v1725, 3);
                v1623 = v1623 + 1.0;
                v1465 = v1623;
              }
              while ( v1623 < 4.0 );u*/
              break;
            case 1:/*
              v1726 = 15.0;
              v1727 = 0.0;
              v1710 = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
              v1622 = 0.0;
              v1463 = (float)0.0;
              do
              {
                *(float *)&v1725 = v1463 * 72.0 + v1710;
                v1464 = y + 130.0;
                addbullet(this, NULL, 901, x, v1464, 1, -1, (int)&v1725, 3);
                v1622 = v1622 + 1.0;
                v1463 = v1622;
              }
              while ( v1622 < 5.0 );*/
              break;
            case 2:/*
              v1726 = 15.0;
              v1727 = 0.0;
              v1709 = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
              v1621 = 0.0;
              v1461 = (float)0.0;
              do
              {
                *(float *)&v1725 = v1461 * 60.0 + v1709;
                v1462 = y + 130.0;
                addbullet(this, NULL, 901, x, v1462, 1, -1, (int)&v1725, 3);
                v1621 = v1621 + 1.0;
                v1461 = v1621;
              }
              while ( v1621 < 6.0 );*/
              break;
            case 3:/*
              v1726 = 15.0;
              v1727 = 0.0;
              v1708 = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
              v1620 = 0.0;
              v1459 = (float)0.0;
              do
              {
                *(float *)&v1725 = v1459 * 45.0 + v1708;
                v1460 = y + 130.0;
                addbullet(this, NULL, 901, x, v1460, 1, -1, (int)&v1725, 3);
                v1620 = v1620 + 1.0;
                v1459 = v1620;
              }
              while ( v1620 < 8.0 );*/
              break;
            default:
              return;
          }
        }
        return;
      case 721:
        if ( get_subseq() == 4 && get_elaps_frames() > 60 )
          goto LABEL_2741;
        if ( get_subseq() <= 0 )
          goto LABEL_2922;
        v_inerc = v_inerc - v_force;
        if ( get_subseq() < 5 && v_inerc < 0.0 )
        {
          v_inerc = 0.0;
          h_inerc = 0.0;
        }
        if ( char_on_ground_down() )
        {
          reset_forces();
          y = getlvl_height();
          set_seq(709);
        }
        else
        {
LABEL_2922:
          if ( field_7D0 == 1 && !(get_elaps_frames() % 4) )
          {
            switch ( settings_get()->get_difficulty() )
            {
              case 0:
                if ( dash_angle < 4.0 )
                {
                  field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                  /*
                  v1627 = 0.0;
                  v1509 = 15.0;
                  v1510 = (float)0.0;
                  while ( 1 )
                  {
                    *(float *)&v1728 = v1510 * v1509 + field_7E4 - v1509;
                    v1729 = v1509 - dash_angle;
                    v1730 = 7.0;
                    v1511 = dir;
                    v1512 = -*(float *)&v1728;
                    v1513 = sin_deg(v1512) * 100.0 + y + 150.0;
                    v1514 = v1513;
                    v1515 = -*(float *)&v1728;
                    v1516 = cos_deg(v1515) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 901, v1516, v1514, v1511, 1, (int)&v1728, 3);
                    v1480 = 1.0;
                    v1627 = v1627 + 1.0;
                    v1510 = v1627;
                    if ( v1627 >= 3.0 )
                      break;
                    v1509 = 15.0;
                  }*/
                  goto LABEL_2770;
                }
                break;
              case 1:
                if ( dash_angle < 6.0 )
                {
                  field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                  /*
                  v1626 = 0.0;
                  v1497 = 15.0;
                  v1498 = (float)0.0;
                  while ( 1 )
                  {
                    *(float *)&v1728 = v1498 * v1497 + field_7E4 - v1497;
                    v1729 = v1497 - dash_angle;
                    v1730 = 7.0;
                    v1499 = dir;
                    v1500 = -*(float *)&v1728;
                    v1501 = sin_deg(v1500) * 100.0 + y + 150.0;
                    v1502 = v1501;
                    v1503 = -*(float *)&v1728;
                    v1504 = cos_deg(v1503) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 901, v1504, v1502, v1499, 1, (int)&v1728, 3);
                    v1480 = 1.0;
                    v1626 = v1626 + 1.0;
                    v1498 = v1626;
                    if ( v1626 >= 3.0 )
                      break;
                    v1497 = 15.0;
                  }*/
                  goto LABEL_2770;
                }
                break;
              case 2:
                if ( dash_angle < 8.0 )
                {
                  field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                  /*
                  v1625 = 0.0;
                  v1485 = 15.0;
                  v1486 = (float)0.0;
                  while ( 1 )
                  {
                    *(float *)&v1728 = v1486 * v1485 + field_7E4 - v1485;
                    v1729 = v1485 - dash_angle;
                    v1730 = 7.0;
                    v1487 = dir;
                    v1488 = -*(float *)&v1728;
                    v1489 = sin_deg(v1488) * 100.0 + y + 150.0;
                    v1490 = v1489;
                    v1491 = -*(float *)&v1728;
                    v1492 = cos_deg(v1491) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 901, v1492, v1490, v1487, 1, (int)&v1728, 3);
                    v1480 = 1.0;
                    v1625 = v1625 + 1.0;
                    v1486 = v1625;
                    if ( v1625 >= 3.0 )
                      break;
                    v1485 = 15.0;
                  }*/
                  goto LABEL_2770;
                }
                break;
              case 3:
                if ( dash_angle < 10.0 )
                {
                  field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                  /*
                  v1624 = 0.0;
                  v1472 = 15.0;
                  v1473 = (float)0.0;
                  while ( 1 )
                  {
                    *(float *)&v1728 = v1473 * v1472 + field_7E4 - v1472;
                    v1729 = v1472 - dash_angle;
                    v1730 = 7.0;
                    v1474 = dir;
                    v1475 = -*(float *)&v1728;
                    v1476 = sin_deg(v1475) * 100.0 + y + 150.0;
                    v1477 = v1476;
                    v1478 = -*(float *)&v1728;
                    v1479 = cos_deg(v1478) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 901, v1479, v1477, v1474, 1, (int)&v1728, 3);
                    v1480 = 1.0;
                    v1624 = v1624 + 1.0;
                    v1473 = v1624;
                    if ( v1624 >= 3.0 )
                      break;
                    v1472 = 15.0;
                  }*/
LABEL_2770:
                  dash_angle = 1.0 + dash_angle;
                }
                break;
              default:
                break;
            }
          }
          if ( process() )
          {
            set_seq(704);
            v_force = 0.25;
          }
          else
          {
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              h_inerc = field_85C;
              v_inerc = field_860;
              v_force = field_864;
            }
            if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 7 )
            {
              v_force = 0.0;
              play_sfx(1);
              field_7D0 = 1;
            }
            if ( get_subseq() == 5 && !get_frame_time() )
            {
LABEL_2785:
              if ( get_frame() == 1 )
                v_force = 0.25;
            }
          }
        }
        return;
      case 722:
        if ( !get_subseq() || get_subseq() == 4 )
        {
          sub10func();
          
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          h_inerc = 0.0;
          v_inerc = 0.0;
        }
        if ( get_subseq() != 1 || get_elaps_frames() < 10 )
        {
          if ( get_subseq() == 3 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
          {
LABEL_2812:
            next_subseq();
            reset_forces();
            y = getlvl_height();
          }
          else
          {
            if ( process() )
              set_seq(700);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 8.0;
                addbullet(this, NULL, 813, x, y + 100.0, dir, 1, t, 3);
                t[0] = 10.0;
                t[2] = 9.0;
                addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
                t[0] = -10.0;
                t[2] = 10.0;
                addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                /*
                v1525 = 0.0;
                v1628 = 0.0;
                v1526 = (float)0.0;
                while ( 1 )
                {
                  *(float *)&v2056 = v1525;
                  v2057 = v1525;
                  v2058 = v1526;
                  v1527 = dir;
                  v1528 = y + 115.0;
                  v1529 = v1528;
                  v1530 = x - (double)(8 * (char)v1527);
                  addbullet(this, NULL, 813, v1530, v1529, v1527, 1, (int)&v2056, 3);
                  v1628 = v1628 + 1.0;
                  if ( v1628 >= 6.0 )
                    break;
                  v1526 = v1628;
                  v1525 = 0.0;
                }*/
              }
            }
          }
          return;
        }
        t[0] = 10.0;
        t[1] = 0.0;
        t[2] = 6.0;
        addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
        t[0] = -10.0;
        t[2] = 7.0;
        addbullet(this, NULL, 813, x, y, dir, 1, t, 3);
        next_subseq();
        if ( dir == 1 )
        {
          if ( x > 640.0 )
          {
LABEL_2806:
            if ( /*get_MT_range(450)*/450.0 < 0 )
              h_inerc = (double)/*get_MT_range(450)*/450.0 + 4294967300.0;
            else 
              h_inerc = -250.0 - (double)/*get_MT_range(450)*/450.0;
            goto LABEL_2809;
          }
        }
        else
        {
          if ( x <= 640.0 )
          {
            goto LABEL_2806;
          }
          if ( /*get_MT_range(450)*/450.0 < 0 )
          {
            h_inerc = (double)/*get_MT_range(450)*/450.0 + 4294967300.0 + 250.0;
            goto LABEL_2809;
          }
        }
        h_inerc = (double)/*get_MT_range(450)*/450.0 + 250.0;
LABEL_2809:
        v_inerc = 30.0;
        v_force = 0.25;
        play_sfx(13);
        return;
      case 730:
        sub10func();
        if ( get_subseq() == 1 )
        {
          if ( get_elaps_frames() == 40 )
          {
            play_sfx(53);
            field_890 = 60;
            enemy->shader_type = 1;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 854, 640.0, 480.0, 1, -2, t, 3);
          }
          if ( get_elaps_frames() >= 100 )
            goto LABEL_2741;
        }
        if ( get_subseq() == 4 && get_elaps_frames() >= 75 )
          next_subseq();
        if ( process() )
          set_seq(700);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
        {
          //*(float *)&v1731 = 0.0;
          switch ( settings_get()->get_difficulty() )
          {
            case 0:/*
              v1733 = 1.0;
              v1635 = 0.0;
              do
              {
                v1732 = (double)(unsigned int)get_MT_range(30) * 0.1000000014901161 + 3.0;
                v1555 = dir;
                v1556 = y + 10.0 + v1635 * 30.0 + (double)(unsigned int)get_MT_range(20) - 10.0;
                v1557 = v1556;
                v1558 = (double)(unsigned int)get_MT_range(200) + x - 100.0;
                addbullet(this, NULL, 920, v1558, v1557, v1555, 1, (int)&v1731, 3);
                v1635 = v1635 + 1.0;
              }
              while ( v1635 < 6.0 );
              v1636 = 0.0;
              do
              {
                v1732 = (double)(unsigned int)get_MT_range(30) * 0.1000000014901161 + 3.0;
                v1559 = dir;
                v1560 = (double)(unsigned int)get_MT_range(20) + y + 25.0 + v1636 * 30.0 - 10.0;
                v1561 = v1560;
                v1562 = (double)(unsigned int)get_MT_range(200) + x - 50.0;
                addbullet(this, NULL, 920, v1562, v1561, v1559, 1, (int)&v1731, 3);
                v1636 = v1636 + 1.0;
              }
              while ( v1636 < 5.0 );*/
              play_sfx(55);
              break;
            case 1:/*
              v1733 = 1.0;
              v1633 = 0.0;
              do
              {
                v1732 = (double)(unsigned int)get_MT_range(30) * 0.1000000014901161 + 3.0;
                v1547 = dir;
                v1548 = y + 10.0 + v1633 * 30.0 + (double)(unsigned int)get_MT_range(20) - 10.0;
                v1549 = v1548;
                v1550 = (double)(unsigned int)get_MT_range(200) + x - 100.0;
                addbullet(this, NULL, 920, v1550, v1549, v1547, 1, (int)&v1731, 3);
                v1633 = v1633 + 1.0;
              }
              while ( v1633 < 6.0 );
              v1634 = 0.0;
              do
              {
                v1732 = (double)(unsigned int)get_MT_range(30) * 0.1000000014901161 + 3.0;
                v1551 = dir;
                v1552 = (double)(unsigned int)get_MT_range(20) + y + 25.0 + v1634 * 30.0 - 10.0;
                v1553 = v1552;
                v1554 = (double)(unsigned int)get_MT_range(200) + x - 50.0;
                addbullet(this, NULL, 920, v1554, v1553, v1551, 1, (int)&v1731, 3);
                v1634 = v1634 + 1.0;
              }
              while ( v1634 < 5.0 );*/
              play_sfx(55);
              break;
            case 2:/*
              v1733 = 1.0;
              v1631 = 0.0;
              do
              {
                v1732 = (double)(unsigned int)get_MT_range(30) * 0.1000000014901161 + 3.0;
                v1539 = dir;
                v1540 = (double)(unsigned int)get_MT_range(20) + y - 20.0 + v1631 * 30.0 - 10.0;
                v1541 = v1540;
                v1542 = (double)(unsigned int)get_MT_range(200) + x - 100.0;
                addbullet(this, NULL, 920, v1542, v1541, v1539, 1, (int)&v1731, 3);
                v1631 = v1631 + 1.0;
              }
              while ( v1631 < 8.0 );
              v1632 = 0.0;
              do
              {
                v1732 = (double)(unsigned int)get_MT_range(30) * 0.1000000014901161 + 3.0;
                v1543 = dir;
                v1544 = (double)(unsigned int)get_MT_range(20) + y - 5.0 + v1632 * 30.0 - 10.0;
                v1545 = v1544;
                v1546 = (double)(unsigned int)get_MT_range(200) + x - 50.0;
                addbullet(this, NULL, 920, v1546, v1545, v1543, 1, (int)&v1731, 3);
                v1632 = v1632 + 1.0;
              }
              while ( v1632 < 7.0 );*/
              play_sfx(55);
              break;
            case 3:/*
              v1733 = 0.0;
              v1629 = 0.0;
              do
              {
                v1732 = (double)(unsigned int)get_MT_range(30) * 0.1000000014901161 + 3.0;
                v1531 = dir;
                v1532 = (double)(unsigned int)get_MT_range(20) + y - 20.0 + v1629 * 30.0 - 10.0;
                v1533 = v1532;
                v1534 = (double)(unsigned int)get_MT_range(200) + x - 100.0;
                addbullet(this, NULL, 920, v1534, v1533, v1531, 1, (int)&v1731, 3);
                v1629 = v1629 + 1.0;
              }
              while ( v1629 < 8.0 );
              v1630 = 0.0;
              do
              {
                v1732 = (double)(unsigned int)get_MT_range(30) * 0.1000000014901161 + 3.0;
                v1535 = dir;
                v1536 = (double)(unsigned int)get_MT_range(20) + y - 5.0 + v1630 * 30.0 - 10.0;
                v1537 = v1536;
                v1538 = (double)(unsigned int)get_MT_range(200) + x - 50.0;
                addbullet(this, NULL, 920, v1538, v1537, v1535, 1, (int)&v1731, 3);
                v1630 = v1630 + 1.0;
              }
              while ( v1630 < 7.0 );*/
              play_sfx(55);
              break;
            default:
              play_sfx(55);
              break;
          }
        }
        return;
      case 740:
        sub10func();
        if ( get_subseq() == 1 )
        {
          switch ( settings_get()->get_difficulty() )
          {
            case 0:
            case 1:
            case 2:
              v1565 = 70;
              break;
            case 3:
              v1565 = 60;
              break;
            default:
              //v1565 = v1597;
              break;
          }
          if ( get_elaps_frames() >= v1565 )
          {
            next_subseq();
            play_sfx(53);
            field_890 = 60;
            enemy->shader_type = 1;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 854, 640.0, 480.0, 1, -2, t, 3);
            return;
          }
        }
        if ( get_subseq() == 3 )
        {
          if ( get_elaps_frames() >= 60 )
          {
            next_subseq();
          }
          if ( !(get_elaps_frames() % 2) && field_7DC < 20.0 )
          {
            switch ( settings_get()->get_difficulty() )
            {
              case 0:
                v1565 = 2.0;
                goto LABEL_2879;
              case 1:
              case 2:
                v1566 = 1.0;
                goto LABEL_2879;
              case 3:
                v1566 = 0.0;
LABEL_2879:
                break;
              default:
                break;
            }
            t[0] = field_7DC * 18.0;
            t[1] = 3.0;
            t[2] = v1566;
            addbullet(this, NULL, 930, cos_deg(180.0 - t[0]) * 350.0 * (double)dir + enemy->x, sin_deg(180.0 - t[0]) * 350.0 + enemy->y + 100.0, dir, 1, t, 3);
            play_sfx(0);
            if ( (settings_get()->get_difficulty() - 2) <= 1 )
            {
              t[0] = field_7DC * 18.0 + 9.0;
              t[1] = 3.0;
              t[2] = v1566;
              addbullet(this, NULL, 930, cos_deg(180.0 - t[0]) * 400.0 * (double)dir + enemy->x, sin_deg(180.0 - t[0]) * 400.0 + enemy->y + 100.0, dir, 1, t, 3);
            }
            field_7DC = field_7DC + 1.0;
          }
        }
        if ( get_subseq() == 4 && get_elaps_frames() >= 8 )
          next_subseq();
        goto LABEL_2886;
      default:
        goto LABEL_2904;
    }
  }
  if ( get_seq() != 500 )
  {
    switch ( get_seq() )
    {
      case 301:
      case 321:
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
          if ( get_frame() >= 4 )
          {
            h_inerc = h_inerc - 1.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 3 )
            {
              h_inerc = 20.0;
              field_49A = 0;
            }
            if ( !get_frame_time() && get_frame() == 4 )
            {
              h_inerc = 5.0;
              scene_play_sfx(28);
            }
          }
        }
        return;
      case 302:
        if ( false /*get_true(1)*/ )
          return;
        if ( !get_subseq() || get_subseq() == 2 || get_subseq() == 4 )
          sub10func();
        if ( get_subseq() == 1 )
        {
          v_inerc = v_inerc - v_force;
          if ( get_elaps_frames() >= 25 )
            sub10func();
        }
        if ( get_subseq() == 3 )
        {
          v_inerc = v_inerc - v_force;
          h_inerc = h_inerc - 0.75;
          if ( h_inerc < 3.0 )
            h_inerc = 3.0;
          if ( get_elaps_frames() >= 24 )
          {
            h_inerc = 5.0;
            v_inerc = -25.0;
          }
        }
        if ( get_subseq() >= 2 )
        {
          if ( get_subseq() == 3 && char_on_ground_down() )
          {
            scene_play_sfx(29);
            y = getlvl_height();
            reset_forces();
            set_subseq(4);
            scene_play_sfx(22);
            //shake_camera(2.0);
            scene_add_effect(this, 58, (double)(135 * (char)dir) + x, y, dir, -1);
            return;
          }
        }
        else if ( char_on_ground_down() )
        {
          scene_play_sfx(29);
LABEL_648:
          y = getlvl_height();
          reset_forces();
          set_subseq(v17);
          return;
        }
        if ( !keyDown(INP_A) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            h_inerc = 15.0;
            v_inerc = 4.0;
            v_force = 0.85000002;
          }
        }
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
          if ( !get_frame_time() && get_frame() == 4 )
            scene_play_sfx(28);
        }
        return;
      case 304:
        v17 = 3;
        if ( !get_subseq() || get_subseq() == 2 && get_elaps_frames() >= 30 || get_subseq() == 3 || get_subseq() == 4 || get_subseq() == 6 && get_elaps_frames() >= 30 || get_subseq() == 7 )
          sub10func();
        if ( get_subseq() == 1 || get_subseq() == 2 )
        {
          v_inerc = v_inerc - v_force;
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 5.0 )
            h_inerc = 5.0;
          if ( char_on_ground_down() )
            goto LABEL_648;
        }
        if ( get_subseq() != 5 && get_subseq() != 6 )
          goto LABEL_2923;
        v_inerc = v_inerc - v_force;
        h_inerc = h_inerc - 0.5;
        if ( h_inerc < 7.0 )
          h_inerc = 7.0;
        if ( char_on_ground_down() )
        {
          y = getlvl_height();
          reset_forces();
          set_subseq(7);
        }
        else
        {
LABEL_2923:
          if ( !keyDown(INP_A) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            h_inerc = 13.5;
            v_inerc = 12.5;
            v_force = 1.0;
          }
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
            {
              set_seq(0);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            {
              h_inerc = 15.5;
              v_inerc = 13.5;
              v_force = 1.0;
            }
          }
          if ( get_subseq() || get_frame_time() || get_frame() != 4 || !not_charge_attack )
          {
            if ( get_subseq() == 1 && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                t[0] = 0.0;
                t[1] = 1.0;
                t[2] = 1.0;
                addbullet(this, NULL, 849, x, y, dir, 1, t, 3);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 2 )
                {
                  scene_play_sfx(29);
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 3 )
                    field_89C = 1;
                  if ( !get_frame_time() && get_frame() == 4 )
                    field_190 = 0;
                }
              }
            }
            if ( get_subseq() == 5 )
            {
              if ( !get_frame_time() && get_frame() == 1 )
              {
                t[0] = 0.0;
                t[1] = 1.0;
                t[2] = 1.0;
                addbullet(this, NULL, 849, x, y, dir, 1, t, 3);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 2 )
                  scene_play_sfx(29);
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 3 )
                    field_89C = 1;
                  if ( !get_frame_time() && get_frame() == 4 )
                    field_190 = 0;
                }
              }
            }
          }
          else
          {
            set_subseq(4);
            scene_add_effect(this, 62, x - (double)(17 * (char)dir), y + 72.0, dir, 1);
          }
        }
        return;
      case 305:
        sub10func();
        if ( true /*!get_true(1)*/ )
        {
          if ( get_frame() > 4 )
          {
            h_inerc = h_inerc - 1.0;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() && get_frame() == 3 )
            scene_play_sfx(28);
        }
        return;
      case 306:
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_779;
        if ( process() )
          set_seq(9);
        if ( !get_frame_time() && get_frame() == 5 )
          scene_play_sfx(28);
        return;
      case 307:
        if ( get_subseq() )
        {
          sub10func();
        }
        else
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            next_subseq();
            goto LABEL_2914;
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1304;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 2 )
            scene_play_sfx(29);
          if ( !get_frame_time() )
          {
LABEL_1338:
            if ( get_frame() == 4 )
              field_89C = 1;
            if ( !get_frame_time() && get_frame() == 5 )
              field_89C = 1;
          }
        }
        return;
      case 308:
        if ( !keyDown(INP_A) )
          not_charge_attack = 0;
        v_inerc = v_inerc - v_force;
        if (  char_on_ground_down() )
        {
LABEL_779:
          set_seq(10);
          goto LABEL_2914;
        }
        if ( process() )
          set_seq(9);
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
        {
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 6 )
            {
              scene_play_sfx(28);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 849, x, y, dir, 1, t, 3);
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 8 )
                field_89C = 1;
              if ( !get_frame_time() )
              {
                if ( get_frame() == 9 )
                  field_89C = 1;
                if ( !get_frame_time() && get_frame() == 9 )
                  v_force = 0.60000002;
              }
            }
          }
        }
        else
        {
          set_seq(9);
        }
        return;
      case 309:
        if ( !keyDown(INP_A) )
          not_charge_attack = 0;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
        {
LABEL_803:
          set_seq(10);
          goto LABEL_2914;
        }
        if ( process() )
          set_seq(9);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_2213;
        if ( !get_subseq() )
        {
          if ( !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              v_force = 0.80000001;
              v_inerc = 12.0;
            }
            if ( !get_frame_time() && get_frame() == 4 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 849, x, y, dir, 1, t, 3);
            }
          }
          if ( !get_frame_time() )
          {
            if ( get_frame() == 5 )
              scene_play_sfx(29);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 5 )
                field_89C = 1;
              if ( !get_frame_time() && get_frame() == 6 )
                field_89C = 1;
            }
          }
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
        if ( get_subseq() == 2 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            v_inerc = 0.0;
            y = getlvl_height();
LABEL_842:
            set_seq(9);
            return;
          }
        }
LABEL_844:
        if ( process() )
          goto LABEL_845;
        return;
      case 320:
        sub10func();
        if ( true /*!get_true(0)*/)
        {
          if ( get_frame() > 1 )
          {
            h_inerc = h_inerc - 2.0;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() && get_frame() == 2 )
          {
            scene_play_sfx(28);
            field_49A = 0;
          }
        }
        return;
      case 322:
        sub10func();
        if ( true /*!get_true(1)*/ )
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 3 )
            {
              scene_play_sfx(29);
              field_49A = 0;
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
                field_89C = 1;
              if ( !get_frame_time() && get_frame() == 4 )
                field_89C = 1;
            }
          }
        }
        return;
      case 330:
        goto LABEL_623;
      case 400:
        sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( field_7D0 != 1 )
          goto LABEL_900;
        if ( get_subseq() )
        {
          if ( !(field_7D2 % 3) && field_7D4 < 7 )
          {
            field_190 = 1;/*
            v238 = 0;
            v1602 = 0;
            do
            {
              *(float *)&v1872 = (double)(2 * field_7D4) + field_7E4 - 4.0 + (double)v1602 - 5.0;
              v1873 = 5.0;
              v1874 = 0.0;
              v239 = dir;
              v240 = -*(float *)&v1872;
              v241 = sin_deg(v240) * 40.0 + y + 125.0;
              v242 = v241;
              v243 = -*(float *)&v1872;
              v244 = cos_deg(v243) * 40.0 * (double)dir + x;
              addbullet(this, NULL, 800, v244, v242, v239, 1, (int)&v1872, 3);
              v238 += 5;
              v1602 = v238;
            }
            while ( v238 < 15 );
            */
            goto LABEL_898;
          }
        }
        else if ( !(field_7D2 % 3) && field_7D4 < 5 )
        {
          field_190 = 1;/*
          v231 = 0;
          v1601 = 0;
          do
          {
            *(float *)&v1866 = (double)(2 * field_7D4) + field_7E4 - 4.0 + (double)v1601 - 5.0;
            v1867 = 5.0;
            v1868 = 0.0;
            v232 = dir;
            v233 = -*(float *)&v1866;
            v234 = sin_deg(v233) * 40.0 + y + 125.0;
            v235 = v234;
            a3 = -*(float *)&v1866;
            v237 = cos_deg(a3) * 40.0 * (double)dir + x;
            addbullet(this, NULL, 800, v237, v235, v232, 1, (int)&v1866, 3);
            v231 += 5;
            v1601 = v231;
          }
          while ( v231 < 15 );*/
LABEL_898:
          add_card_energy(10);
          play_sfx(0);
          ++field_7D4;
          goto LABEL_899;
        }
LABEL_899:
        ++field_7D2;
LABEL_900:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1975;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 4 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(40 * (char)dir), y + 136.0, dir, 1);
          }
          if ( !get_frame_time() && get_frame() == 6 )
          {
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -20.0 )
              field_7E4 = -20.0;
            if ( field_7E4 > 20.0 )
              field_7E4 = 20.0;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
          }
        }
        if ( get_subseq() != 1 || get_frame_time() || get_frame() != 3 )
          return;
        goto LABEL_1034;
      case 401:
        sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( field_7D0 != 1 )
          goto LABEL_937;
        if ( get_subseq() )
        {
          if ( !(field_7D2 % 3) && field_7D4 < 7 )
          {
            /*
            field_190 = 1;
            v268 = 0;
            v1604 = 0;
            do
            {
              *(float *)&v1830 = (double)(2 * field_7D4) + field_7E4 - 4.0 + (double)v1604 - 5.0;
              v1831 = 5.0;
              v1832 = 0.0;
              v269 = dir;
              v270 = -*(float *)&v1830;
              v271 = sin_deg(v270) * 40.0 + y + 125.0;
              v272 = v271;
              v273 = -*(float *)&v1830;
              v274 = cos_deg(v273) * 40.0 * (double)dir + x;
              addbullet(this, NULL, 800, v274, v272, v269, 1, (int)&v1830, 3);
              v268 += 5;
              v1604 = v268;
            }
            while ( v268 < 15 );*/
            goto LABEL_935;
          }
        }
        else if ( !(field_7D2 % 3) && field_7D4 < 5 )
        {
          field_190 = 1;
          /*
          v261 = 0;
          v1603 = 0;
          do
          {
            *(float *)&v1878 = (double)(2 * field_7D4) + field_7E4 - 4.0 + (double)v1603 - 5.0;
            v1879 = 5.0;
            v1880 = 0.0;
            v262 = dir;
            v263 = -*(float *)&v1878;
            v264 = sin_deg(v263) * 40.0 + y + 125.0;
            v265 = v264;
            v266 = -*(float *)&v1878;
            v267 = cos_deg(v266) * 40.0 * (double)dir + x;
            addbullet(this, NULL, 800, v267, v265, v262, 1, (int)&v1878, 3);
            v261 += 5;
            v1603 = v261;
          }
          while ( v261 < 15 );*/
LABEL_935:
          add_card_energy(10);
          play_sfx(0);
          ++field_7D4;
          goto LABEL_936;
        }
LABEL_936:
        ++field_7D2;
LABEL_937:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
LABEL_1975:
          set_seq(0);
          return;
        }
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 4 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(40 * (char)dir), y + 136.0, dir, 1);
          }
          if ( !get_frame_time() && get_frame() == 6 )
          {
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -40.0 )
              field_7E4 = -40.0;
            if ( field_7E4 > -20.0 )
              field_7E4 = -20.0;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
          }
        }
        if ( get_subseq() != 1 || get_frame_time() || get_frame() != 3 )
          return;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -40.0 )
          field_7E4 = -40.0;
        v289 = -20.0;
        goto LABEL_1084;
      case 402:
        sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( field_7D0 != 1 )
          goto LABEL_977;
        if ( get_subseq() )
        {
          if ( !(field_7D2 % 3) && field_7D4 < 5 )
          {
            field_190 = 1;/*
            v298 = 0;
            v1605 = 0;
            do
            {
              *(float *)&v1839 = (double)(2 * field_7D4) + field_7E4 - 4.0 + (double)v1605 - 5.0;
              v1840 = 5.0;
              v1841 = 0.0;
              v299 = dir;
              v300 = -*(float *)&v1839;
              v301 = sin_deg(v300) * 40.0 + y + 125.0;
              v302 = v301;
              v303 = -*(float *)&v1839;
              v304 = cos_deg(v303) * 40.0 * (double)dir + x;
              addbullet(this, NULL, 800, v304, v302, v299, 1, (int)&v1839, 3);
              v298 += 5;
              v1605 = v298;
            }
            while ( v298 < 15 );*/
            goto LABEL_975;
          }
        }
        else if ( !(field_7D2 % 3) && field_7D4 < 5 )
        {
          field_190 = 1;/*
          v291 = -50;
          do
          {
            a4 = (double)(v291 - 6 * field_7D4);
            v1834 = 5.0;
            v1835 = 0.0;
            v292 = dir;
            v293 = -a4;
            v294 = sin_deg(v293) * 70.0 + y + 75.0;
            v295 = v294;
            v296 = -a4;
            v297 = (cos_deg(v296) * 70.0 + 50.0) * (double)dir + x;
            addbullet(this, NULL, 800, v297, v295, v292, 1, (int)&a4, 3);
            v291 += 5;
          }
          while ( v291 < -35 );*/
LABEL_975:
          add_card_energy(10);
          play_sfx(0);
          ++field_7D4;
          goto LABEL_976;
        }
LABEL_976:
        ++field_7D2;
LABEL_977:
        if ( process() )
          set_seq(2);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          set_seq(2);
          return;
        }
        if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
          goto LABEL_1135;
        return;
      case 404:
        if ( get_subseq() == 2 )
          sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 2 )
          goto LABEL_994;
        if ( field_7D0 != 1 )
          goto LABEL_1009;
        if ( get_subseq() )
        {
          if ( get_subseq() == 1 && !(field_7D2 % 3) && field_7D4 < 7 )
          {
            field_190 = 1;/*
            v313 = 0;
            v1607 = 0;
            do
            {
              *(float *)&v1851 = field_7E4 + 4.0 - (double)(2 * field_7D4) + (double)v1607 - 5.0;
              v1852 = 5.0;
              v1853 = 0.0;
              v314 = dir;
              v315 = -*(float *)&v1851;
              v316 = sin_deg(v315) * 80.0 + y + 100.0;
              v317 = v316;
              v318 = -*(float *)&v1851;
              v319 = cos_deg(v318) * 80.0 * (double)dir + x;
              addbullet(this, NULL, 800, v319, v317, v314, 1, (int)&v1851, 3);
              v313 += 5;
              v1607 = v313;
            }
            while ( v313 < 15 );*/
            goto LABEL_1007;
          }
        }
        else if ( !(field_7D2 % 3) && field_7D4 < 5 )
        {
          field_190 = 1;/*
          v306 = 0;
          v1606 = 0;
          do
          {
            *(float *)&v1845 = field_7E4 + 4.0 - (double)(2 * field_7D4) + (double)v1606 - 5.0;
            v1846 = 5.0;
            v1847 = 0.0;
            v307 = dir;
            v308 = -*(float *)&v1845;
            v309 = sin_deg(v308) * 80.0 + y + 100.0;
            v310 = v309;
            v311 = -*(float *)&v1845;
            v312 = cos_deg(v311) * 80.0 * (double)dir + x;
            addbullet(this, NULL, 800, v312, v310, v307, 1, (int)&v1845, 3);
            v306 += 5;
            v1606 = v306;
          }
          while ( v306 < 15 );*/
LABEL_1007:
          add_card_energy(10);
          play_sfx(0);
          ++field_7D4;
          goto LABEL_1008;
        }
LABEL_1008:
        ++field_7D2;
LABEL_1009:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
          goto LABEL_1304;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 4 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, (double)(30 * (char)dir) + x, y + 130.0, dir, 1);
          }
          if ( !get_frame_time() && get_frame() == 5 )
          {
            h_inerc = -6.0;
            v_inerc = 9.0;
            v_force = 0.69999999;
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -20.0 )
              field_7E4 = -20.0;
            if ( field_7E4 > 20.0 )
              field_7E4 = 20.0;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
          }
        }
        if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
          return;
        h_inerc = -6.0;
        v_inerc = 9.0;
        v_force = 0.69999999;
LABEL_1034:
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -20.0 )
          field_7E4 = -20.0;
        v289 = 20.0;
        goto LABEL_1084;
      case 405:
        if ( get_subseq() == 2 )
          sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 2 )
          goto LABEL_1260;
        if ( field_7D0 != 1 )
          goto LABEL_1057;
        if ( get_subseq() )
        {
          if ( !(field_7D2 % 3) && field_7D4 < 5 )
          {
            field_190 = 1;/*
            v342 = 0;
            v1609 = 0;
            do
            {
              *(float *)&v1884 = field_7E4 + 4.0 - (double)(2 * field_7D4) + (double)v1609 - 5.0;
              v1885 = 5.0;
              v1886 = 0.0;
              v343 = dir;
              v344 = -*(float *)&v1884;
              v345 = sin_deg(v344) * 80.0 + y + 100.0;
              v346 = v345;
              v347 = -*(float *)&v1884;
              v348 = cos_deg(v347) * 80.0 * (double)dir + x;
              addbullet(this, NULL, 800, v348, v346, v343, 1, (int)&v1884, 3);
              v342 += 5;
              v1609 = v342;
            }
            while ( v342 < 15 );*/
            goto LABEL_1055;
          }
        }
        else if ( !(field_7D2 % 3) && field_7D4 < 5 )
        {
          field_190 = 1;/*
          v335 = 0;
          v1608 = 0;
          do
          {
            *(float *)&v1857 = field_7E4 + 4.0 - (double)(2 * field_7D4) + (double)v1608 - 5.0;
            v1858 = 5.0;
            v1859 = 0.0;
            v336 = dir;
            v337 = -*(float *)&v1857;
            v338 = sin_deg(v337) * 80.0 + y + 100.0;
            v339 = v338;
            v340 = -*(float *)&v1857;
            v341 = cos_deg(v340) * 80.0 * (double)dir + x;
            addbullet(this, NULL, 800, v341, v339, v336, 1, (int)&v1857, 3);
            v335 += 5;
            v1608 = v335;
          }
          while ( v335 < 15 );*/
LABEL_1055:
          add_card_energy(10);
          play_sfx(0);
          ++field_7D4;
          goto LABEL_1056;
        }
LABEL_1056:
        ++field_7D2;
LABEL_1057:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
          goto LABEL_1304;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 4 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, (double)(30 * (char)dir) + x, y + 130.0, dir, 1);
          }
          if ( !get_frame_time() && get_frame() == 5 )
          {
            h_inerc = -6.0;
            v_inerc = 9.0;
            v_force = 0.69999999;
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -10.0 )
              field_7E4 = -10.0;
            if ( field_7E4 > 10.0 )
              field_7E4 = 10.0;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
          }
        }
        if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
          return;
        h_inerc = -6.0;
        v_inerc = 9.0;
        v_force = 0.69999999;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -10.0 )
          field_7E4 = -10.0;
        v289 = 10.0;
LABEL_1084:
        if ( v289 >= field_7E4 )
          goto LABEL_1135;
        goto LABEL_1134;
      case 406:
        if ( get_subseq() == 2 )
          sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 2 )
          goto LABEL_1260;
        if ( field_7D0 != 1 )
          goto LABEL_1106;
        if ( get_subseq() )
        {
          if ( get_subseq() == 1 && !(field_7D2 % 3) && field_7D4 < 7 )
          {
            field_190 = 1;/*
            v371 = 0;
            v1611 = 0;
            do
            {
              *(float *)&v1827 = field_7E4 + 4.0 - (double)(2 * field_7D4) + (double)v1611 - 5.0;
              v1828 = 5.0;
              v1829 = 0.0;
              v372 = dir;
              v373 = -*(float *)&v1827;
              v374 = sin_deg(v373) * 80.0 + y + 100.0;
              v375 = v374;
              v376 = -*(float *)&v1827;
              v377 = cos_deg(v376) * 80.0 * (double)dir + x;
              addbullet(this, NULL, 800, v377, v375, v372, 1, (int)&v1827, 3);
              v371 += 5;
              v1611 = v371;
            }
            while ( v371 < 15 );*/
            goto LABEL_1104;
          }
        }
        else if ( !(field_7D2 % 3) && field_7D4 < 5 )
        {
          field_190 = 1;/*
          v364 = 0;
          v1610 = 0;
          do
          {
            *(float *)&v1836 = field_7E4 + 4.0 - (double)(2 * field_7D4) + (double)v1610 - 5.0;
            v1837 = 5.0;
            v1838 = 0.0;
            v365 = dir;
            v366 = -*(float *)&v1836;
            v367 = sin_deg(v366) * 80.0 + y + 100.0;
            v368 = v367;
            v369 = -*(float *)&v1836;
            v370 = cos_deg(v369) * 80.0 * (double)dir + x;
            addbullet(this, NULL, 800, v370, v368, v365, 1, (int)&v1836, 3);
            v364 += 5;
            v1610 = v364;
          }
          while ( v364 < 15 );*/
LABEL_1104:
          add_card_energy(10);
          play_sfx(0);
          ++field_7D4;
          goto LABEL_1105;
        }
LABEL_1105:
        ++field_7D2;
LABEL_1106:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
        {
LABEL_1304:
          set_seq(9);
          return;
        }
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 4 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, (double)(30 * (char)dir) + x, y + 130.0, dir, 1);
          }
          if ( !get_frame_time() && get_frame() == 5 )
          {
            h_inerc = -6.0;
            v_inerc = 9.0;
            v_force = 0.69999999;
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < 40.0 )
              field_7E4 = 40.0;
            if ( field_7E4 > 60.0 )
              field_7E4 = 60.0;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
          }
        }
        if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
          return;
        h_inerc = -4.0;
        v_inerc = 12.0;
        v_force = 0.69999999;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < 40.0 )
          field_7E4 = 40.0;
        if ( field_7E4 > 60.0 )
        {
          v289 = 60.0;
LABEL_1134:
          field_7E4 = v289;
        }
LABEL_1135:
        field_7D0 = 1;
        spell_energy_spend(200, 45);
        return;
      case 408:
        sub10func();
        if ( get_frame() >= 4 )
          h_inerc = h_inerc - 0.5;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
        if ( field_190 )
          field_7D0 = 1;
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 2 )
            scene_play_sfx(29);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 4 )
            {
              field_190 = 0;
              field_89C = 1;
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 5 )
              {
                field_190 = 0;
                field_89C = 1;
              }
              if ( !get_frame_time() && get_frame() == 6 && field_7D0 == 1 )
                field_190 = 1;
            }
          }
        }
        return;
      case 409:
        v_inerc = v_inerc - v_force;
        if ( !char_on_ground_down() )
          goto LABEL_844;
        set_seq(10);
        reset_forces();
        y = getlvl_height();
        return;
      case 410:
        sub10func();
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( !get_subseq() )
        {
          if ( field_7D0 > 0 )
          {
            if ( field_7D0 % 2 == 1 && field_7D0 <= 13 )
            {
              field_7DC = field_7DC + 3.0;
              play_sfx(1);
              t[0] = 30.0 - field_7DC;
              t[1] = 20.0;
              t[2] = 0.0;
              addbullet(this, NULL, 803, (cos_deg(-t[0]) * 80.0 + 20.0) * (double)dir + x, sin_deg(-t[0]) * 80.0 + y + 100.0, dir, 1, t, 3);
            }
            ++field_7D0;
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_2909;
        if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
        {
          field_7D0 = 1;
          spell_energy_spend(200, 60);
          field_190 = 1;
          add_card_energy(50);
        }
        if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 7 )
        {
          play_sfx(1);
          spell_energy_spend(200, 60);
          field_190 = 1;
          add_card_energy(50);/*
          v1638 = 0.0;
          v400 = (float)0.0;
          do
          {
            *(float *)&v2041 = 3.0 - v400;
            v401 = v400 - 3.0;
            v2042 = 35.0 - fabs_(v401);
            v2043 = 0.0;
            v402 = dir;
            v403 = v1638 * 15.0 + y + 25.0;
            v404 = v403;
            v405 = (double)(77 * (char)v402) + x;
            addbullet(this, NULL, 801, v405, v404, v402, 1, (int)&v2041, 3);
            v1638 = v1638 + 1.0;
            v400 = v1638;
          }
          while ( v1638 < 7.0 );*/
        }
        return;
      case 411:
        sub10func();
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1975;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 5 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(6 * (char)dir), y + 203.0, dir, 1);
          }
          if ( !get_frame_time() && get_frame() == 7 )
          {
            play_sfx(2);
            spell_energy_spend(200, 60);
            field_190 = 1;
            add_card_energy(50);/*
            v1639 = 0.0;
            v410 = (float)0.0;
            do
            {
              v411 = 2.0 - v410;
              *(float *)&v1999 = v411;
              v412 = fabs_(v411);
              v2000 = 30.0 - (v412 + v412);
              v2001 = 0.0;
              v413 = dir;
              v414 = v1639 * 20.0 + y + 40.0;
              v415 = v414;
              v416 = (double)(77 * (char)v413) + x;
              addbullet(this, NULL, 801, v416, v415, v413, 1, (int)&v1999, 3);
              v1639 = v1639 + 1.0;
              v410 = v1639;
            }
            while ( v1639 < 5.0 );*/
          }
        }
        if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 7 )
        {
          play_sfx(2);
          spell_energy_spend(200, 60);
          field_190 = 1;
          add_card_energy(50);/*
          v1640 = 0.0;
          v417 = 3.0;
          v418 = (float)0.0;
          while ( 1 )
          {
            *(float *)&v2029 = v417 - v418;
            v419 = v418 - v417;
            v2030 = 35.0 - fabs_(v419);
            v2031 = 0.0;
            v420 = dir;
            v421 = v1640 * 15.0 + y + 25.0;
            v422 = v421;
            v423 = (double)(77 * (char)v420) + x;
            addbullet(this, NULL, 801, v423, v422, v420, 1, (int)&v2029, 3);
            v1640 = v1640 + 1.0;
            if ( v1640 >= 7.0 )
              break;
            v418 = v1640;
            v417 = 3.0;
          }*/
        }
        return;
      case 412:
        sub10func();
        if ( get_subseq() < 2 && !keyDown(INP_C) )
          field_7D8 = 1;
        if ( process() )
          set_seq(2);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(2);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
        {
          play_sfx(2);
          field_190 = 1;
          spell_energy_spend(200, 60);
          add_card_energy(50);/*
          v1641 = 0.0;
          v424 = (float)0.0;
          do
          {
            *(float *)&v1890 = -25.0 - 3.0 * v424;
            v425 = 2.0 - v424;
            v426 = fabs_(v425);
            v1891 = 30.0 - (v426 + v426);
            v1892 = 0.0;
            v427 = dir;
            v428 = -*(float *)&v1890;
            v429 = sin_deg(v428) * 100.0 + y + 35.0;
            v430 = v429;
            v431 = -*(float *)&v1890;
            v432 = (cos_deg(v431) * 100.0 - 37.0) * (double)dir + x;
            addbullet(this, NULL, 801, v432, v430, v427, 1, (int)&v1890, 3);
            v1641 = v1641 + 1.0;
            v424 = v1641;
          }
          while ( v1641 < 5.0 );*/
        }
        return;
      case 414:
        if ( get_subseq() == 2 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 2 )
          goto LABEL_994;
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( !get_subseq() )
        {
          if ( field_7D0 > 0 )
          {
            if ( field_7D0 % 2 == 1 && field_7D0 <= 13 )
            {
              field_7DC = field_7DC + 3.0;
              play_sfx(1);
              t[0] = field_7DC + 5.0;
              t[1] = 20.0;
              t[2] = 3.0;
              addbullet(this, NULL, 803, cos_deg(-t[0]) * 80.0 * (double)dir + x, sin_deg(-t[0]) * 80.0 + y + 100.0, dir, 1, t, 3);
            }
            ++field_7D0;
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
          goto LABEL_845;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 5 )
          {
            field_7D0 = 1;
            spell_energy_spend(200, 60);
            field_190 = 1;
            add_card_energy(50);
          }
          if ( !get_frame_time() && get_frame() == 7 )
            v_force = 0.5;
        }
        if ( get_subseq() != 1 || get_frame_time() )
          return;
        if ( get_frame() == 2 )
        {
          field_7D0 = 1;
          spell_energy_spend(200, 60);
          field_190 = 1;
          add_card_energy(50);
        }
        goto LABEL_1290;
      case 415:
        if ( get_subseq() == 2 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 2 )
        {
LABEL_1260:
          set_subseq(2);
          goto LABEL_2007;
        }
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
          goto LABEL_845;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 4 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(6 * (char)dir), y + 203.0, dir, 1);
          }
          if ( !get_frame_time() )
          {
            if ( get_frame() == 5 )
            {
              play_sfx(2);
              spell_energy_spend(200, 60);
              field_190 = 1;
              add_card_energy(50);/*
              v1642 = 0.0;
              v444 = (float)0.0;
              do
              {
                v445 = 2.0 - v444;
                *(float *)&v2005 = v445;
                v446 = fabs_(v445);
                v2006 = 30.0 - (v446 + v446);
                v2007 = 0.0;
                v447 = dir;
                v448 = v1642 * 20.0 + y + 60.0;
                v449 = v448;
                v450 = (double)(80 * (char)v447) + x;
                addbullet(this, NULL, 801, v450, v449, v447, 1, (int)&v2005, 3);
                v1642 = v1642 + 1.0;
                v444 = v1642;
              }
              while ( v1642 < 5.0 );*/
            }
            if ( !get_frame_time() && get_frame() == 7 )
              v_force = 0.5;
          }
        }
        if ( get_subseq() != 1 || get_frame_time() )
          return;
        if ( get_frame() == 2 )
        {
          play_sfx(2);
          spell_energy_spend(200, 60);
          field_190 = 1;
          add_card_energy(50);/*
          v1643 = 0.0;
          v451 = 3.0;
          v452 = (float)0.0;
          while ( 1 )
          {
            *(float *)&v2053 = v451 - v452;
            v453 = v452 - v451;
            v2054 = 35.0 - fabs_(v453);
            v2055 = 0.0;
            v454 = dir;
            v455 = v1643 * 20.0 + y + 60.0;
            v456 = v455;
            v457 = (double)(80 * (char)v454) + x;
            addbullet(this, NULL, 801, v457, v456, v454, 1, (int)&v2053, 3);
            v1643 = v1643 + 1.0;
            if ( v1643 >= 7.0 )
              break;
            v452 = v1643;
            v451 = 3.0;
          }*/
        }
LABEL_1290:
        if ( get_frame_time() )
          return;
        v458 = get_frame() == 4;
        goto LABEL_2024;
      case 416:
        if ( get_subseq() == 2 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 2 )
        {
LABEL_994:
          set_subseq(2);
          goto LABEL_2007;
        }
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
          goto LABEL_1304;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 4 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(6 * (char)dir), y + 203.0, dir, 1);
          }
          if ( !get_frame_time() && get_frame() == 6 )
          {
            play_sfx(2);
            spell_energy_spend(200, 60);
            field_190 = 1;
            add_card_energy(50);/*
            v1644 = 0.0;
            v464 = (float)0.0;
            do
            {
              *(float *)&v2011 = 60.0 - v464 * 2.0;
              v465 = 2.0 - v464;
              v466 = fabs_(v465);
              v2012 = 30.0 - (v466 + v466);
              v2013 = 0.0;
              v467 = dir;
              v468 = y + 30.0 + 6.0 * v1644;
              v469 = v468;
              v470 = (v1644 * 20.0 + 10.0) * (double)(char)v467 + x;
              addbullet(this, NULL, 801, v470, v469, v467, 1, (int)&v2011, 3);
              v1644 = v1644 + 1.0;
              v464 = v1644;
            }
            while ( v1644 < 5.0 );*/
            h_inerc = -5.0;
            v_inerc = 10.0;
            v_force = 0.5;
          }
        }
        if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
        {
          play_sfx(2);
          spell_energy_spend(200, 60);
          field_190 = 1;
          add_card_energy(50);/*
          v1645 = 0.0;
          v471 = (float)0.0;
          do
          {
            *(float *)&v2035 = 60.0 - v471 * 2.0;
            v472 = 2.0 - v471;
            v473 = fabs_(v472);
            v2036 = 30.0 - (v473 + v473);
            v2037 = 0.0;
            v474 = dir;
            v475 = y + 30.0 + 6.0 * v1645;
            v476 = v475;
            v477 = (v1645 * 20.0 + 10.0) * (double)(char)v474 + x;
            addbullet(this, NULL, 801, v477, v476, v474, 1, (int)&v2035, 3);
            v1645 = v1645 + 1.0;
            v471 = v1645;
          }
          while ( v1645 < 7.0 );*/
          h_inerc = -5.0;
          v_inerc = 10.0;
          v_force = 0.5;
        }
        return;
      case 418:
        sub10func();
        if ( get_frame() <= 4 )
          h_inerc = h_inerc - 0.5;
        if ( get_frame() >= 7 )
          h_inerc = h_inerc - 0.75;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
        if ( process() )
          set_seq(0);
        if ( get_frame_time() )
          return;
        if ( get_frame() == 4 )
        {
          scene_play_sfx(29);
          h_inerc = 20.0;
          field_49A = 0;
        }
        if ( get_frame_time() )
          return;
        goto LABEL_1338;
      default:
        goto LABEL_2904;
    }
  }
  if ( !get_subseq() || get_subseq() == 5 )
    sub10func();
  field_18C = 0;
  if ( get_subseq() == 1 || get_subseq() == 2 )
  {
    field_7DC = field_7DC - 1.5;
    if ( field_7DC < 2.0 )
      field_7DC = 2.0;
    //WHATIS?
          //set_vec_speed((render_class *)&cEffectSprite, -50.0, field_7DC);
    if ( get_subseq() == 2 )
    {
      if ( field_190 )
      {
        if ( field_194 > 0 && ++field_7D0 >= 8 )
        {
          field_7D0 = 0;
          field_190 = 0;
        }
      }
      if ( get_elaps_frames() >= 25 )
        next_subseq();
    }
  }
  if ( get_subseq() == 3 || get_subseq() == 4 )
  {
    field_190 = 1;
    v_inerc = v_inerc - v_force;
    if ( char_on_ground_down() )
    {
      y = getlvl_height();
      reset_forces();
      set_subseq(5);
      return;
    }
  }
  if ( process() )
    set_seq(0);
  if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
  {
    /*
    v1646 = 0.0;
    v482 = (float)0.0;
    do
    {
      *(float *)&v1896 = v482 * 60.0;
      v1897 = 150.0;
      v1898 = 2.0;
      v483 = y + 118.0;
      addbullet(this, NULL, 810, x, v483, dir, 1, (int)&v1896, 3);
      v1898 = 3.0;
      v484 = y + 118.0;
      addbullet(this, NULL, 810, x, v484, dir, 1, (int)&v1896, 3);
      v1646 = v1646 + 1.0;
      v482 = v1646;
    }
    while ( v1646 < 6.0 );*/
    scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
    spell_energy_spend(200, 120);
    play_sfx(10);
    add_card_energy(50);
    field_7DC = 22.0;
    v_force = 0.60000002;
    if ( skills_1[0] >= 1 )
      v_force = 0.75;
    if ( skills_1[0] >= 3 )
      v_force = 0.89999998;
    //WHATIS?
          //set_vec_speed((render_class *)&cEffectSprite, -50.0, field_7DC);
  }
  if ( get_subseq() == 5 )
  {
    if ( !get_frame() )
    {
      if ( (get_frame_time() == 6) && skills_1[0] >= 1 || get_frame_time() == 4 && skills_1[0] >= 3 )
      {
LABEL_2341:
        next_frame();
        return;
      }
    }
    if ( get_frame() == 1 )
    {
      if ( get_frame_time() != 7 || skills_1[0] < 1 )
      {
        v490 = get_frame_time() == 5;
LABEL_1465:
        if ( v490 && skills_1[0] >= 3 )
          set_seq(0);
        return;
      }
LABEL_2909:
      set_seq(0);
      return;
    }
  }
}

//note: taken from marisa.cpp

void char_sakuya::func20()
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

void char_sakuya::set_seq_params()
{
  int32_t sq = get_seq();
  if ( sq > 500 )
  {
    if ( sq <= 797 )
    {
      if ( sq == 797 )
      {
        reset_forces();
        h_inerc = 12.0;
        field_7D0 = 0;
        v_inerc = 0.0;
        v_force = 0.5;
        return;
      }
      switch ( sq )
      {
        case 501:
          field_18C = 0;
          reset_forces();
          field_194 = 5;
          goto LABEL_42;
        case 502:
          field_18C = 0;
          h_inerc = h_inerc * 0.25;
          v_inerc = 0.25 * v_inerc;
          goto LABEL_41;
        case 503:
          field_18C = 0;
          field_194 = 5;
          h_inerc = h_inerc * 0.25;
          v_inerc = 0.25 * v_inerc;
          goto LABEL_42;
        case 504:
          field_18C = 0;
          reset_forces();
          h_inerc = 10.0;
          field_49A = 0;
          v_inerc = 10.0;
          field_7D0 = 0;
          field_194 = 1;
          v_force = 0.55000001;
          field_190 = 1;
          return;
        case 505:
        case 506:
          field_18C = 4;
          reset_forces();
          field_194 = 0;
          field_49A = 0;
          field_190 = 1;
          return;
        case 510:
        case 511:
          field_18C = 8;
          reset_forces();
          field_194 = 0;
          field_190 = 0;
          field_49A = 0;
          return;
        case 520:
        case 521:
          field_18C = 1;
          goto LABEL_53;
        case 525:
        case 526:
          field_18C = 5;
LABEL_53:
          reset_forces();
          field_7DC = 0.0;
          field_49A = 0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 1;
          not_charge_attack = 1;
          return;
        case 530:
        case 531:
          field_18C = 9;
          reset_forces();
          field_190 = 1;
          field_49A = 0;
          not_charge_attack = 1;
          return;
        case 540:
        case 541:
          field_18C = 2;
          goto LABEL_57;
        case 542:
        case 543:
          field_18C = 2;
          goto LABEL_60;
        case 545:
        case 546:
          field_18C = 6;
          goto LABEL_57;
        case 547:
        case 548:
          v_force = 0.0;
          field_18C = 6;
          field_190 = 0;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          goto LABEL_58;
        case 550:
        case 551:
          field_18C = 10;
LABEL_57:
          field_190 = 0;
          reset_forces();
LABEL_58:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          not_charge_attack = 0;
          return;
        case 552:
        case 553:
          field_18C = 10;
LABEL_60:
          v_force = 0.0;
          field_190 = 0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          not_charge_attack = 0;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 560:
        case 561:
        case 562:
        case 563:
          field_18C = 3;
          goto LABEL_33;
        case 565:
        case 566:
        case 567:
        case 568:
          field_18C = 7;
LABEL_33:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          not_charge_attack = 1;
          return;
        case 570:
        case 571:
        case 572:
        case 573:
          field_7D0 = 0;
          field_18C = 11;
          field_190 = 0;
          field_194 = 1;
          goto LABEL_68;
        case 599:
          field_190 = 1;
          reset_forces();
LABEL_35:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          return;
        case 600:
          goto LABEL_72;
        case 601:
        case 602:
        case 605:
        case 607:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 0;
          reset_forces();
          return;
        case 603:
        case 653:
          field_7DC = 90.0;
          field_7D0 = 0;
          field_7D2 = 0;
LABEL_72:
          field_190 = 1;
          reset_forces();
          return;
        case 604:
        case 608:
        case 609:
        case 610:
        case 720:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 1;
          reset_forces();
          return;
        case 606:
        case 656:
        case 710:
        case 711:
          reset_forces();
          field_49A = 0;
          return;
        case 611:
          field_7D2 = 0;
          field_7DC = 0.0;
          field_190 = 1;
          reset_forces();
          return;
        case 612:
          field_190 = 1;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 613:
LABEL_24:
          field_190 = 0;
          not_charge_attack = 1;
          return;
        case 615:
          field_190 = 1;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          not_charge_attack = 1;
          return;
        case 707:
LABEL_68:
          reset_forces();
          return;
        case 708:
          field_7D0 = 0;
          h_inerc = 0.0;
          return;
        case 721:
          dash_angle = 0.0;
          field_7D0 = 0;
          reset_forces();
          field_49A = 0;
          return;
        case 722:
        case 730:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          return;
        case 740:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7DC = 0.0;
          field_7D2 = 0;
          field_7D6 = 0;
          return;
        default:
          goto LABEL_84;
      }
      goto LABEL_84;
    }
    if ( sq != 798 )
    {
LABEL_84:
      char_c::set_seq_params();
      return;
    }
    reset_forces();
    field_7D0 = 0;
  }
  else
  {
    if ( sq != 500 )
    {
      if ( sq > 214 )
      {
        switch ( sq )
        {
          case 217:
            reset_ofs();
            goto LABEL_11;
          case 300:
          case 301:
          case 303:
          case 321:
          case 322:
          case 330:
            field_89C = 1;
            goto LABEL_13;
          case 302:
            field_89C = 1;
            reset_forces();
            field_190 = 0;
            field_49A = 0;
            field_194 = 1;
            not_charge_attack = 1;
            return;
          case 304:
            field_89C = 1;
            field_49A = 0;
            field_194 = 2;
            field_190 = 0;
            reset_forces();
            not_charge_attack = 1;
            return;
          case 305:
            field_89C = 1;
            v_inerc = 0.0;
            if ( h_inerc < 12.5 )
              h_inerc = 12.5;
            v_force = 0.0;
            goto LABEL_21;
          case 306:
            field_7D0 = 0;
            field_190 = 0;
            field_89C = 1;
            field_194 = 1;
            return;
          case 307:
          case 309:
            goto LABEL_23;
          case 308:
            h_inerc = h_inerc * 0.2000000029802322;
            v_inerc = 0.2000000029802322 * v_inerc;
            v_force = 0.0;
LABEL_23:
            field_89C = 1;
            field_194 = 1;
            goto LABEL_24;
          case 310:
            h_inerc = 0.0;
            field_7D0 = 0;
            v_inerc = 0.0;
            field_190 = 0;
            field_89C = 1;
            v_force = 0.5;
            field_194 = 99;
            return;
          case 320:
            field_89C = 1;
            goto LABEL_21;
          case 400:
          case 401:
          case 402:
            field_190 = 0;
            reset_forces();
            field_7D0 = 0;
            field_7D2 = 0;
            field_7D4 = 0;
            not_charge_attack = 1;
            return;
          case 404:
          case 405:
          case 406:
            v_force = 0.0;
            field_190 = 0;
            field_7D0 = 0;
            field_7D2 = 0;
            field_7D4 = 0;
            not_charge_attack = 1;
            h_inerc = h_inerc * 0.2000000029802322;
            v_inerc = 0.2000000029802322 * v_inerc;
            return;
          case 408:
            h_inerc = 12.5;
            field_7D0 = 0;
            field_49A = 0;
            field_190 = 0;
            v_inerc = 0.0;
            field_89C = 1;
            field_194 = 3;
            return;
          case 409:
            v_force = 0.34999999;
            field_7D0 = 0;
LABEL_21:
            field_49A = 0;
            field_190 = 0;
            field_194 = 1;
            return;
          case 410:
            field_190 = 0;
            reset_forces();
            field_7D0 = 0;
            field_7DC = 0.0;
            field_7D2 = 0;
            field_7D4 = 0;
            not_charge_attack = 1;
            return;
          case 411:
            goto LABEL_33;
          case 412:
            field_190 = 0;
            reset_forces();
            goto LABEL_35;
          case 414:
            field_7DC = 0.0;
            field_190 = 0;
            v_force = 0.0;
            field_7D0 = 0;
            field_7D2 = 0;
            field_7D4 = 0;
            not_charge_attack = 1;
            h_inerc = h_inerc * 0.2000000029802322;
            v_inerc = 0.2000000029802322 * v_inerc;
            return;
          case 415:
          case 416:
            v_force = 0.0;
            field_190 = 0;
            field_7D0 = 0;
            field_7D2 = 0;
            field_7D4 = 0;
            not_charge_attack = 1;
            h_inerc = h_inerc * 0.2000000029802322;
            v_inerc = 0.2000000029802322 * v_inerc;
            return;
          case 418:
            field_89C = 1;
            if ( h_inerc < 12.5 )
              h_inerc = 12.5;
LABEL_13:
            if ( !field_49A )
              reset_forces();
            field_190 = 0;
            field_194 = 1;
            return;
          default:
            goto LABEL_84;
        }
      }
      else
      {
        if ( sq == 214 )
        {
LABEL_11:
          field_7D6 = 0;
          h_inerc = 0.0;
          v_inerc = 0.0;
          v_force = 0.60000002;
          x_off = 0.0;
          y_off = 75.0;
          field_7DC = 10.5;
          field_7EC = 0.0;
          return;
        }
        if ( !(sq - 4) )
        {
          h_inerc = 6.0;
          return;
        }
        if ( (sq - 4) == 1 )
        {
          h_inerc = -6.0;
          return;
        }
      }
      goto LABEL_84;
    }
    field_18C = 0;
    reset_forces();
LABEL_41:
    field_194 = 4;
LABEL_42:
    field_190 = 0;
    field_49A = 0;
    field_7D0 = 0;
  }
}
#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "suika.h"
#include <math.h>

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

void char_suika::init_vars()
{
  field_138 = -6.0;
  char_c::init_vars();
  field_890 = 0;
  field_892 = 0;
  field_894 = 0;
}

//Bullet function
/*
c_bullet *char_suika::new_bullet()
{
    c_bullet *tmp = new suika_bullets();
    return tmp;
}
*/

void char_suika::func10()
{
  int v3 = 2;
  double v21 = 0.0;
  bool v32 = false;
  double v79 = 0.0;
  double v81 = 0.0;
  bool v183 = false;
  double v221 = 0.0;
  double v_loop = 0;

  double v287 = 0.0;

  bool v479 = false;

  double v549 = 0.0;
  double v1451 = 0.0;
  double v646 = 0.0;

  double v747 = 0.0;
  double v754 = 0.0;

  double v807 = 0.0;

  double v876 = 0.0;

  double v945 = 0.0;

  double xe = 0.0;
  double v1162 = 0.0;

  double v1177 = 0.0;
  double v1188 = 0.0;

  double v1329 = 0.0;

  double move_val = 0.0;
  double move_vala = 0.0;
  double move_valb = 0.0;
  double move_valc = 0.0;

  x_delta = 0;
  y_delta = 80;

  if ( field_890 > 0 )
  {
    field_890 = field_890 - 1;
    if ( enemy->health <= 0 || health <= 0 )
      field_890 = 0;
    enemy->spell_energy_spend(2, 30);
  }
  if ( field_892 > 0 )
  {
    field_892 = field_892 - 1;
    if ( enemy->health <= 0 || health <= 0 )
      field_892 = 0;
    field_534 = field_534 * 0.5;
  }
  if ( field_894 )
  {
    if ( getlvl_height() >= y && !(get_pframe()->fflags & 4) )
      field_894 = 0;
  }
  if ( get_seq() == 501 )
  {
    if ( get_subseq() <= 1 || get_subseq() == 2 && get_frame() <= 4 )
    {
      //v1387 = ;
      // are the last 3 just v1387?
      if ( skills_1[0] >= 1 )
        field_538 = 250.0;
      if ( skills_1[0] >= 3 )
        field_538 = 500.0;
      if ( skills_1[0] >= 4 )
        field_538 = 750.0;
      if ( 0.0 > (double)field_188 )
        field_538 = 0.0;
    }
  }
  if ( !hit_stop && !enemy->time_stop )
  {
    if ( get_seq() <= 300 )
    {
      if ( get_seq() == 300 )
      {
LABEL_523:
        sub10func();
        if ( true /*!get_true(0)*/)
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
          {
            h_inerc = 0.0;
            field_49A = 0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 3 )
              h_inerc = 4.0;
            if ( !get_frame_time() && get_frame() == 4 )
            {
              scene_play_sfx(28);
              field_49A = 0;
            }
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
              goto LABEL_35;
            goto LABEL_36;
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
LABEL_36:
              if ( 0.0 < h_inerc )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                {
                  reset_forces();
                  field_49A = 0;
                }
              }
              if ( 0.0 <= h_inerc || (h_inerc + 0.5, h_inerc <= 0.0) )
              {
LABEL_112:
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
LABEL_35:
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
            if ( !(get_subseq() < 0 | get_subseq() == 0) )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_108;
            }
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v21 = 0.0;
            goto LABEL_104;
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
                goto LABEL_108;
            }
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v21 = 8.0;
            goto LABEL_104;
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
                goto LABEL_108;
            }
            process();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              v21 = -8.0;
LABEL_104:
              char_h_move(v21);
              v_inerc = 16.0;
              v_force = 0.75;
              field_49A = 0;
            }
            return;
          case 9:
            if ( 0.0 == v_force )
              v_force = 0.60000002;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_108;
            goto LABEL_112;
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
            sub10func();
            if ( !process() )
              goto LABEL_121;
            if ( controlling_type == 2 )
              goto LABEL_158;
            set_seq(0);
            if ( dY() > 0 )
              set_seq(1);
LABEL_121:
            if ( get_elaps_frames() )
              goto LABEL_131;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              h_inerc = 15.0;
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_131;
            if ( get_subseq() != 2 )
              return;
            reset_forces();
LABEL_131:
            if ( get_subseq() != 2 )
              return;
            if ( get_frame() != 5 )
              return;
            v32 = get_frame_time() == 0;
            goto LABEL_164;
          case 198:
            sub10func();
            if ( !process() )
              goto LABEL_139;
            if ( controlling_type == 2 )
            {
              set_seq(700);
              goto LABEL_159;
            }
            set_seq(0);
            if ( dY() > 0 )
              set_seq(1);
LABEL_139:
            if ( get_elaps_frames() )
              goto LABEL_149;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              h_inerc = -15.0;
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_149;
            if ( get_subseq() == 2 )
            {
              reset_forces();
LABEL_149:
              if ( get_subseq() == 2 && get_frame() == 5 && !get_frame_time() )
              {
                if ( enemy->x < (double)x )
                  dir = -1;
                if ( enemy->x > (double)x )
                  dir = 1;
              }
            }
            return;
          case 199:
            sub10func();
            if ( !process() )
              goto LABEL_162;
            if ( controlling_type == 2 )
            {
LABEL_158:
              set_seq(700);
LABEL_159:
              field_51C = 3;
              field_520 = 3;
            }
            else
            {
              set_seq(0);
              if ( dY() > 0 )
                set_seq(1);
LABEL_162:
              if ( !get_frame_time() )
              {
                v32 = get_frame() == 11;
LABEL_164:
                if ( v32 )
                {
                  if ( enemy->x < (double)x )
                    dir = -1;
                  if ( enemy->x > (double)x )
                    dir = 1;
                }
              }
            }
            return;
          case 200:
            sub10func();
            field_49A = 1;
            process();
            if ( get_subseq() != 1 )
              goto LABEL_179;
            if ( !(get_elaps_frames() % 5) )
            {

              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            if ( dY() >= 0 )
            {
              ++field_7D0;
              if ( dX(dir) > 0 && field_7D0 <= 60 )
              {
LABEL_179:
                if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
                {
                  char_h_move(10.0);
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
              if ( dX(dir) < 0 | dX(dir) == 0 )
                set_seq(211);
              else
                set_seq(212);
            }
            return;
          case 201:
            sub10func();
            field_49A = 1;
            process();
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
              }
              if ( dX(dir) >= 0 && ++field_7D0 >= 10 )
                goto LABEL_482;
              if ( ++field_7D0 > 60 )
                goto LABEL_482;
            }
            if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
            {
              char_h_move(-10.0);
              scene_add_effect(this, 125, (double)(80 * dir) + x, y + 80.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
              scene_play_sfx(31);
            }
            return;
          case 202:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_488;
            if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 16 )
              goto LABEL_215;
            process();
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              field_7D0 = 0;
              char_h_move(11.0);
              v_inerc = 4.0;
              v_force = 0.5;
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
              goto LABEL_504;
            if ( get_subseq() < 2 && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            if ( get_subseq() != 1 || get_elaps_frames() < 16 )
            {
              process();
              if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
              {
                char_h_move(-11.0);
                v_inerc = 4.0;
                v_force = 0.5;
                scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
                scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
                scene_play_sfx(31);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                flip_with_force();
            }
            else
            {
LABEL_215:
              next_subseq();
              flip_with_force();
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
            goto LABEL_229;
          case 205:
            sub10func();
            h_inerc = h_inerc + 0.5;
            if ( h_inerc > 0.0 )
            {
              h_inerc = 0.0;
              field_49A = 0;
            }
LABEL_229:
            if ( process() )
            {
              set_seq(0);
              field_49A = 0;
            }
            return;
          case 208:
            if ( !get_subseq() )
              sub10func();
            if ( !char_on_ground_down() )
              goto LABEL_234;
            goto LABEL_445;
          case 209:
          case 212:
          case 221:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_109;
            if ( char_on_ground_flag() || v_inerc > 0.0 )
              field_522 = 2;
            if ( get_subseq() > 0 )
              v_inerc = v_inerc - v_force;
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v79 = 10.0;
            goto LABEL_462;
          case 210:
          case 222:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_109;
            if ( char_on_ground_flag() || v_inerc > 0.0 )
              field_522 = 2;
            if ( get_subseq() > 0 )
              v_inerc = v_inerc - v_force;
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v79 = -10.0;
LABEL_462:
            char_h_move(v79);
            v_inerc = 16.0;
            v81 = 0.69999999;
            goto LABEL_463;
          case 211:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_109;
            if ( char_on_ground_flag() || v_inerc > 0.0 )
              field_522 = 2;
            if ( get_subseq() > 0 )
              v_inerc = v_inerc - v_force;
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
            process();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(3.0);
              v_inerc = 19.0;
              v81 = 0.75;
LABEL_463:
              v_force = v81;
              field_49A = 0;
              scene_add_effect(this, 63, x, y, dir, 1);
            }
            return;
          case 214:
            if ( process() )
              goto LABEL_728;
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                scene_play_sfx(31);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
                goto LABEL_728;
            }
            if ( dY() < 0 | dY() == 0 )
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
            if ( get_subseq() > 0 && get_subseq() < 5 )
            {
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
                  dash_angle = dash_angle + 1.5;
              }
              if ( field_7D4 < 0 )
              {
                if ( weather_id )
                  dash_angle = dash_angle - 0.5;
                else
                  dash_angle = dash_angle - 1.5;
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
              if ( (keyDown(INP_D)) == 0 && field_7D6 > 10 || spell_energy <= 0 )
              {
                if ( !keyDown(INP_D) && field_7D6 > 10 || spell_energy <= 0 )
                  goto LABEL_350;
              }
            }
            if ( !char_on_ground_down() )
              return;
            y = getlvl_height();
            goto LABEL_438;
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
              goto LABEL_1110;
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                scene_play_sfx(31);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
                goto LABEL_1110;
            }
            field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
            if ( get_subseq() == 5 || get_subseq() == 6 )
              v_inerc = v_inerc - v_force;
            if ( get_subseq() <= 0 || get_subseq() >= 5 )
              goto LABEL_3297;
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
LABEL_3297:
              if ( char_on_ground_down() )
              {
                y = getlvl_height();
                v_force = 0.0;
LABEL_438:
                v_inerc = 0.0;
                if ( get_subseq() >= 5 )
                {
                  set_seq(10);
                  reset_forces();
                }
                else
                {
                  reset_ofs();
                  set_seq(215);
                }
              }
            }
            else
            {
LABEL_350:
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
                else if ( enemy->x <= x )
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
            return;
          case 220:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
            {
LABEL_445:
              set_seq(10);
              goto LABEL_111;
            }
LABEL_234:
            if ( char_on_ground_flag() || v_inerc > 0.0 )
              field_522 = 2;
            if ( get_subseq() > 0 )
              v_inerc = v_inerc - v_force;
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
            process();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(0.0);
              v_inerc = 21.0;
              v_force = 0.75;
              field_49A = 0;
              scene_add_effect(this, 63, x, y, dir, 1);
            }
            break;
          case 223:
            sub10func();
            field_49A = 1;
            process();
            if ( get_subseq() != 1 )
              goto LABEL_3298;
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            if ( ((++field_7D0, dX(dir) > 0) || field_7D0 <= 9) && field_7D0 <= 60 )
            {
LABEL_3298:
              if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
              {
                char_h_move(5.0);
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
            sub10func();
            field_49A = 1;
            process();
            if ( get_subseq() != 1 )
              goto LABEL_3299;
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            if ( ((++field_7D0,dX(dir) < 0) || field_7D0 < 10) && field_7D0 <= 60 )
            {
LABEL_3299:
              if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
              {
                char_h_move(-10.0);
                scene_add_effect(this, 125, (double)(80 * dir) + x, y + 80.0, -dir, 1);
                scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
                scene_play_sfx(31);
              }
            }
            else
            {
LABEL_482:
              set_seq(205);
            }
            return;
          case 225:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_488:
              reset_forces();
              y = getlvl_height();
              set_seq(10);
            }
            else
            {
              if ( get_subseq() < 2 && !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
              }
              if ( process() )
                set_seq(9);
              if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
              {
                char_h_move(-11.0);
                v_inerc = 4.0;
                v_force = 0.5;
                scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
                scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
                scene_play_sfx(31);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                flip_with_force();
            }
            return;
          case 226:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_504:
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
                v_inerc = 4.0;
                v_force = 0.5;
                scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
                scene_add_effect(this, 126, x, y + 110.0, dir, 1);
                scene_play_sfx(31);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                flip_with_force();
            }
            return;
          default:
            goto LABEL_3248;
        }
      }
      return;
    }
    if ( get_seq() <= 500 )
    {
      if ( get_seq() != 500 )
      {
        switch ( get_seq() )
        {
          case 301:
            sub10func();
            if ( false /*get_true(0)*/)
              return;
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
            {
              h_inerc = 0.0;
              field_49A = 0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_3278;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_552;
            if ( get_frame() == 3 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(43 * (char)dir), y + 150.0, dir, 1);
              return;
            }
            if ( get_frame() == 6 )
            {
              scene_play_sfx(29);
              field_49A = 0;
            }
LABEL_552:
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() == 2 )
              h_inerc = 10.0;
            if ( get_frame_time() )
              return;
            v183 = get_frame() == 4;
            goto LABEL_2811;
          case 302:
            sub10func();
            if ( false /*get_true(1)*/)
              return;
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_3278;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_574;
            if ( get_frame() == 3 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(16 * (char)dir), y + 135.0, dir, 1);
            }
            else
            {
              if ( get_frame() == 6 )
              {
                play_sfx(0);
                float t[3];
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL,848, x, y, dir, 1, t, 3);
              }
LABEL_574:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 4 )
              {
                play_sfx(0);
                float t[3];
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 3.0;
                addbullet(this, NULL,848, x, y, dir, 1, t, 3);
              }
            }
            return;
          case 303:
            sub10func();
            if ( false /*get_true(0)*/)
              return;
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
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
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1032;
            /*if ( get_subseq() )
              goto LABEL_598;
            if ( get_frame_time() )
              goto LABEL_594;
            //v190 = __OFSUB__(get_frame(), 3);
            //v189 = (get_frame() - 3) < 0;
            */
            if ( get_frame() == 3 )
            {
              scene_play_sfx(28);
              h_inerc = 8.0;
              field_49A = 0;}/*
LABEL_594:
              v190 = __OFSUB__(get_frame(), 3);
              v189 = (get_frame() - 3) < 0;
            }
            if ( v189 ^ v190 )
            {
LABEL_598:
            }
            else
            {
              h_inerc = h_inerc - 0.800000011920929;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }*/
            if ( get_subseq() != 1 )
              return;
            if ( get_frame_time() )
              goto LABEL_603;
            //v194 = __OFSUB__(get_frame(), 2);
            //v193 = (get_frame() - 2) < 0;
            if ( get_frame() == 2 )
            {
              play_sfx(1);
              //shake_camera(5.0);
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 4.0;
              addbullet(this, NULL,848, (double)(175 * (char)dir) + x, y + 85.0, dir, 1, t, 3);
              t[0] = -10.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL,848, (double)(175 * (char)dir) + x, y + 85.0, dir, 1, t, 3);
              h_inerc = 9.5;
              field_49A = 0;
//LABEL_603:
              //v194 = __OFSUB__(get_frame(), 2);
              //v193 = (get_frame() - 2) < 0;
            }
            LABEL_603://TODO: change
            //if ( v193 ^ v194 )
            //  return;
            h_inerc = h_inerc - 0.5;
            if ( h_inerc >= 0.0 )
              return;
            goto LABEL_2828;
          case 304:
            sub10func();
            if ( false /*get_true(1)*/)
              return;
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
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
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1032;
            if ( get_subseq() )
              goto LABEL_628;
            if ( get_frame() >= 6 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( get_frame_time() || get_frame() != 4 )
              goto LABEL_628;
            if ( not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(34 * (char)dir) + x, y + 40.0, dir, 1);
            }
            else
            {
              h_inerc = 15.0;
              field_49A = 0;
              scene_play_sfx(29);
LABEL_628:
              if ( get_subseq() == 1 )
              {
                if ( get_frame() >= 3 )
                {
                  h_inerc = h_inerc - 0.5;
                  if ( h_inerc < 0.0 )
                    h_inerc = 0.0;
                }
                if ( !get_frame_time() && get_frame() == 1 )
                {
                  h_inerc = 22.5;
                  field_49A = 0;
                  scene_play_sfx(29);
                }
              }
            }
            return;
          case 305:
            sub10func();
            if ( true /*!get_true(0)*/)
            {
              if ( get_frame() > 16 )
              {
                h_inerc = h_inerc - 0.6000000238418579;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                set_seq(0);
              if ( !get_frame_time() )
              {
                if ( get_frame() == 5 )
                  scene_play_sfx(28);
                if ( !get_frame_time() && get_frame() == 16 )
                {
                  scene_play_sfx(29);
                  field_190 = 0;
                }
              }
            }
            return;
          case 306:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_seq(10);
              goto LABEL_692;
            }
            if ( process() )
              set_seq(9);
            if ( !get_frame_time() && get_frame() == 5 )
              scene_play_sfx(28);
            return;
          case 307:
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                if ( field_190 )
                  goto LABEL_110;
                set_subseq(1);
                goto LABEL_111;
              }
              if ( get_frame() >= 3 )
              {
                h_inerc = h_inerc + 0.2000000029802322;
                if ( h_inerc > -2.0 )
                  h_inerc = -2.0;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              play_sfx(1);
              //shake_camera(5.0);
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL,848, (double)(154 * (char)dir) + x, y + 62.0, dir, 1, t, 3);
              t[0] = 10.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL,848, (double)(154 * (char)dir) + x, y + 62.0, dir, 1, t, 3);
              h_inerc = -12.5;
              v221 = 6.0;
              break;
            }
            return;
          case 308:
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_seq(10);
              y = getlvl_height();
              v_inerc = 0.0;
              v_force = 0.0;
              return;
            }
            if ( process() )
              set_seq(9);
            if ( get_elaps_frames() )
              goto LABEL_685;
            if ( get_frame_time() )
              return;
            if ( !get_frame() && get_subseq() == 1 )
              goto LABEL_1110;
LABEL_685:
            if ( !get_frame_time() && get_frame() == 6 )
            {
              field_190 = 0;
              field_194 = 1;
              h_inerc = -4.0;
              v_inerc = 7.0;
              v_force = 0.5;
              scene_play_sfx(29);
              play_sfx(1);
              //shake_camera(5.0);
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL,848, (double)(145 * (char)dir) + x, y - 55.0, dir, 1, t, 3);
              t[0] = 45.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL,848, (double)(145 * (char)dir) + x, y - 55.0, dir, 1, t, 3);
            }
            return;
          case 309:
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_seq(10);
LABEL_692:
              y = getlvl_height();
              v_force = 0.0;
              v_inerc = 0.0;
            }
            else
            {
              if ( process() )
                set_seq(9);
              if ( !get_subseq() )
              {
                if ( !get_frame_time() && get_frame() == 5 )
                {
                  if ( v_inerc < 0.0 )
                    v_inerc = 0.0;
                  v_force = -0.2;
                }
                if ( !get_subseq() )
                {
                  if ( get_frame_time() )
                    return;
                  if ( get_frame() == 5 || get_frame() == 7 || get_frame() == 9 || get_frame() == 11 )
                  {
                    scene_play_sfx(27);
                    field_190 = 0;
                    field_194 = 1;
                  }
                }
                if ( !get_frame_time() && get_frame() == 13 )
                  v_force = 0.5;
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
                set_seq(9);
                return;
              }
            }
            if ( process() )
              goto LABEL_728;
            return;
          case 320:
            sub10func();
            if ( false /*get_true(0)*/)
              return;
            if ( get_frame() >= 5 )
            {
              h_inerc = h_inerc - 2.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( get_frame_time() )
              return;
            v183 = get_frame() == 5;
            goto LABEL_2811;
          case 321:
            sub10func();
            if ( true /*!get_true(1)*/)
            {
              if ( get_frame() > 3 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                set_seq(0);
              if ( !get_frame_time() && get_frame() == 3 )
              {
                field_49A = 0;
                h_inerc = 16.5;
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 6 )
                  h_inerc = 0.0;
                if ( !get_frame_time() && get_frame() == 6 )
                  scene_play_sfx(29);
              }
            }
            return;
          case 322:
            if ( !get_subseq() || get_subseq() == 3 )
            {
              sub10func();
              
            }
            if ( get_subseq() < 3 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_subseq(3);
                v_inerc = 0.0;
                v_force = 0.0;
                y = getlvl_height();
              }
              
            }
            if ( get_subseq() == 3 )
            {
              h_inerc = h_inerc - 0.800000011920929;
              if ( h_inerc < 0.0 )
              {
                h_inerc = 0.0;
                field_49A = 0;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              scene_play_sfx(29);
              h_inerc = 15.0;
              v_inerc = 6.0;
              v_force = 0.89999998;
            }
            return;
          case 330:
            goto LABEL_523;
          case 400:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_3278;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_784;
            if ( get_frame() == 4 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(40 * (char)dir), y + 70.0, dir, 1);
              return;
            }
            if ( get_frame() == 6 )
            {
              float t[3];
              t[0] = 15.0;
              t[1] = 10.0;
              t[2] = 0.0;
              addbullet(this, NULL,800, (double)(85 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
              spell_energy_spend(200, 45);
              add_card_energy(30);
              field_190 = 1;
              play_sfx(2);
            }
LABEL_784:
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() == 3 )
              goto LABEL_790;
            if ( get_frame() != 8 && get_frame() != 13 )
              return;
            if ( get_frame() == 3 )
            {
LABEL_790:
              spell_energy_spend(200, 45);
              add_card_energy(30);
            }
            float t[3];
            t[0] = 15.0;
            t[1] = 10.0;
            t[2] = 0.0;
            addbullet(this, NULL,800, (double)(85 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
            goto LABEL_1037;
          case 401:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            {
              if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
              {
                spell_energy_spend(200, 45);
                add_card_energy(30);
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7E4 < -20.0 )
                  field_7E4 = -20.0;
                if ( field_7E4 > 20.0 )
                  field_7E4 = 20.0;
                float t[3];
                t[0] = field_7E4;
                t[1] = 30.0;
                t[2] = 3.0;
                addbullet(this, NULL,800, (double)(85 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                field_190 = 1;
                play_sfx(3);
              }
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
              {
                spell_energy_spend(200, 45);
                add_card_energy(30);
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7E4 < -20.0 )
                  field_7E4 = -20.0;
                if ( field_7E4 > 20.0 )
                  field_7E4 = 20.0;
                float t[3];
                t[0] = field_7E4;
                t[1] = 30.0;
                t[2] = 3.0;
                addbullet(this, NULL,800, (double)(85 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                t[0] = field_7E4 + 10.0;
                addbullet(this, NULL,800, (double)(85 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                t[0] = field_7E4 - 10.0;
                addbullet(this, NULL,800, (double)(85 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                field_190 = 1;
                play_sfx(3);
              }
            }
            else
            {
              set_seq(0);
            }
            return;
          case 402:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
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
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1032;
            if ( get_subseq() )
              goto LABEL_838;
            if ( get_frame_time() )
              goto LABEL_835;
            if ( get_frame() == 2 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(28 * (char)dir) + x, y + 57.0, dir, 1);
              return;
            }
            if ( get_frame() == 3 )
            {
              scene_play_sfx(29);
              field_49A = 0;
            }
LABEL_835:
            if ( !get_frame_time() && get_frame() == 4 )
            {
              spell_energy_spend(200, 45);
              add_card_energy(30);
              play_sfx(1);
              scene_add_effect(this, 58, (double)(198 * (char)dir) + x, 0.0, dir, -2);
              //shake_camera(4.0);
            }
LABEL_838:
            if ( get_subseq() != 1 )
              return;
            if ( !get_frame_time() )
            {
              if ( get_frame() == 1 )
                h_inerc = 10.0;
              if ( !get_frame_time() )
              {
                if ( get_frame() == 2 )
                {
                  scene_play_sfx(29);
                  field_49A = 0;
                }
                if ( !get_frame_time() && get_frame() == 3 )
                {
                  h_inerc = 0.0;
                  play_sfx(1);
                  spell_energy_spend(200, 45);
                  add_card_energy(30);
                  scene_add_effect(this, 58, (double)(198 * (char)dir) + x, 0.0, dir, -2);
                  //shake_camera(7.0);
                  float t[3];
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 7.0;
                  addbullet(this, NULL,800, (double)(210 * dir) + x, y, dir, 1, t, 3);
                  v_loop = 0.0;
                  do
                  {
                    float t[3];
                    t[0] = /*(double)(unsigned int)get_MT_range(40)*/40.0 + v_loop * 60.0 - 20.0;
                    t[1] = /*(double)(unsigned int)get_MT_range(8)*/8.0 + 30.0;
                    t[2] = 1.0;
                    if ( t[0] < 0.0 || t[0] > 180.0 )
                      field_7D0 = -1;
                    else
                      field_7D0 = 1;
                    addbullet(this, NULL,811, (double)(40 * (char)dir) + x, y, dir, field_7D0, t, 3);
                    v_loop = v_loop + 1.0;
                  }
                  while ( v_loop < 6.0 );
                }
              }
            }
            v287 = h_inerc - 0.699999988079071;
            goto LABEL_2827;
          case 404:
            /*
            v289 = __OFSUB__(get_subseq(), 2);
            v288 = (get_subseq() - 2) < 0;
            if ( get_subseq() == 2 )
            {
              sub10func();
              v289 = __OFSUB__(get_subseq(), 2);
              v288 = (get_subseq() - 2) < 0;
            }
            if ( v288 ^ v289 && !keyDown(INP_B) )
              not_charge_attack = 0;
            */
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
            {
              set_subseq(2);
              air_dash_cnt = 0;
              goto LABEL_111;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            {
LABEL_728:
              set_seq(9);
              return;
            }
            if ( get_subseq() )
              goto LABEL_881;
            if ( get_frame_time() )
              goto LABEL_878;
            if ( get_frame() == 4 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(35 * (char)dir), y + 80.0, dir, 1);
              return;
            }
            if ( get_frame() == 6 )
            {
              spell_energy_spend(200, 45);
              add_card_energy(30);
              float t[3];
              t[0] = 15.0;
              t[1] = 10.0;
              t[2] = 0.0;
              addbullet(this, NULL,800, (double)(50 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
              field_190 = 1;
              play_sfx(2);
            }
LABEL_878:
            if ( !get_frame_time() && get_frame() == 9 )
              v_force = 0.5;
LABEL_881:
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() == 3 )
              goto LABEL_887;
            if ( get_frame() == 8 || get_frame() == 13 )
            {
              if ( get_frame() == 3 )
              {
LABEL_887:
                spell_energy_spend(200, 45);
                add_card_energy(30);
              }
              float t[3];
              t[0] = 15.0;
              t[1] = 10.0;
              t[2] = 0.0;
              addbullet(this, NULL,800, (double)(50 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
              field_190 = 1;
              play_sfx(2);
            }
            if ( !get_frame_time() && get_frame() == 16 )
              v_force = 0.5;
            return;
          case 405:
            /*
            v304 = __OFSUB__(get_subseq(), 2);
            v303 = (get_subseq() - 2) < 0;
            if ( get_subseq() == 2 )
            {
              sub10func();
              v304 = __OFSUB__(get_subseq(), 2);
              v303 = (get_subseq() - 2) < 0;
            }
            if ( v303 ^ v304 && !keyDown(INP_B) )
              not_charge_attack = 0;
            */
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
              goto LABEL_1103;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_1110;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                spell_energy_spend(200, 45);
                add_card_energy(30);
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7E4 < -20.0 )
                  field_7E4 = -20.0;
                if ( field_7E4 > 20.0 )
                  field_7E4 = 20.0;
                float t[3];
                t[0] == field_7E4;
                t[1] == 30.0;
                t[2] == 3.0;
                addbullet(this, NULL,800, (double)(50 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                field_190 = 1;
                play_sfx(3);
              }
              if ( !get_frame_time() && get_frame() == 9 )
                v_force = 0.5;
            }
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() != 3 )
              goto LABEL_963;
            spell_energy_spend(200, 45);
            add_card_energy(30);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);;
            if ( field_7E4 < -20.0 )
              field_7E4 = -20.0;
            if ( field_7E4 > 20.0 )
              field_7E4 = 20.0;
            t[0] == field_7E4;
            t[1] == 30.0;
            t[2] == 3.0;
            addbullet(this, NULL,800, (double)(50 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
            t[0] = field_7E4 + 10.0;
            addbullet(this, NULL,800, (double)(50 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
            t[0] = field_7E4 - 10.0;
            x = dir;
            addbullet(this, NULL,800, (double)(50 * (char)x) + x, y + 100.0, x, 1, t, 3);
            field_190 = 1;
            play_sfx(3);
            goto LABEL_963;
          case 406:
            /*
            v331 = __OFSUB__(get_subseq(), 2);
            v330 = (get_subseq() - 2) < 0;
            if ( get_subseq() == 2 )
            {
              sub10func();
              v331 = __OFSUB__(get_subseq(), 2);
              v330 = (get_subseq() - 2) < 0;
            }
            if ( v330 ^ v331 && !keyDown(INP_B) )
              not_charge_attack = 0;
            */
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
              goto LABEL_1103;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_1110;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                spell_energy_spend(200, 45);
                add_card_energy(30);
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);;
                if ( field_7E4 < 30.0 )
                  field_7E4 = 30.0;
                if ( field_7E4 > 45.0 )
                  field_7E4 = 45.0;
                float t[3];
                t[0] = field_7E4;
                t[1] = 30.0;
                t[2] = 3.0;
                addbullet(this, NULL,800, (double)(50 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                field_190 = 1;
                play_sfx(3);
              }
              if ( !get_frame_time() && get_frame() == 9 )
                v_force = 0.5;
            }
            if ( get_subseq() == 1 && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                spell_energy_spend(200, 45);
                add_card_energy(30);
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);;
                if ( field_7E4 < 20.0 )
                  field_7E4 = 20.0;
                if ( field_7E4 > 60.0 )
                  field_7E4 = 60.0;
                float t[3];
                t[0] = field_7E4;
                t[1] = 30.0;
                t[2] = 3.0;
                addbullet(this, NULL,800, (double)(50 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                t[0] = field_7E4 + 10.0;
                addbullet(this, NULL,800, (double)(50 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                t[0] = field_7E4 - 10.0;
                x = dir;
LABEL_962:
                addbullet(this, NULL,800, (double)(50 * (char)x) + x, y + 100.0, x, 1, t, 3);
                field_190 = 1;
                play_sfx(3);
              }
LABEL_963:
              if ( !get_frame_time() && get_frame() == 6 )
                v_force = 0.5;
            }
            return;
          case 408:
            sub10func();
            if ( get_frame() < 9 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 10.0 )
                h_inerc = 10.0;
            }
            else
            {
              h_inerc = h_inerc - 0.699999988079071;
            }
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( get_frame_time() )
              return;
            if ( get_frame() == 4 )
              h_inerc = 15.0;
            if ( get_frame_time() )
              return;
            if ( get_frame() == 6 )
              scene_play_sfx(29);
            if ( get_frame_time() )
              return;
            if ( get_frame() == 7 || get_frame() == 8 )
              goto LABEL_2391;
            if ( get_frame() == 9 )
              field_190 = 0;
            return;
          case 409:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_seq(10);
              goto LABEL_3102;
            }
            if ( process() )
              set_seq(9);
            return;
          case 410:
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            {
              if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
              {
                spell_energy_spend(200, 60);
                add_card_energy(50);
                float t[3];
                t[0] = 10.0;
                t[1] = 8.0;
                t[2] = 0.0;
                addbullet(this, NULL,801, (double)(85 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                field_190 = 1;
                play_sfx(2);
              }
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
              {
                spell_energy_spend(200, 60);
                add_card_energy(50);
LABEL_1023:
                float t[3];
                t[0] = 10.0;
                t[1] = 8.0;
                t[2] = 0.0;
                addbullet(this, NULL,801, (double)(85 * dir) + x, y + 100.0, dir, 1, t, 3);
                field_190 = 1;
                play_sfx(2);
              }
            }
            else
            {
              set_seq(0);
            }
            return;
          case 411:
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1014;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              spell_energy_spend(200, 60);
              add_card_energy(50);
              float t[3];
              t[0] = 30.0;
              t[1] = 8.0;
              t[2] = 0.0;
              addbullet(this, NULL,801, (double)(85 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
              field_190 = 1;
              play_sfx(2);
            }
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 3 )
              return;
            spell_energy_spend(200, 60);
            add_card_energy(50);
            goto LABEL_1023;
          case 412:
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(2);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            {
              if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
              {
                spell_energy_spend(200, 60);
                add_card_energy(50);
                float t[3];
                t[0] = 10.0;
                t[1] = 17.5;
                t[2] = 0.0;
                addbullet(this, NULL,801, (double)(18 * (char)dir) + x, y + 88.0, dir, 1, t, 3);
LABEL_1037:
                field_190 = 1;
                play_sfx(2);
              }
            }
            else
            {
LABEL_1032:
              set_seq(2);
            }
            return;
          case 414:
            /*
            v379 = __OFSUB__(get_subseq(), 2);
            v378 = (get_subseq() - 2) < 0;
            if ( get_subseq() == 2 )
            {
              sub10func();
              v379 = __OFSUB__(get_subseq(), 2);
              v378 = (get_subseq() - 2) < 0;
            }
            if ( v378 ^ v379 && !keyDown(INP_B) )
              not_charge_attack = 0;
            */
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
              goto LABEL_1103;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(9);
              return;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              goto LABEL_1110;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                spell_energy_spend(200, 60);
                add_card_energy(50);
                float t[3];
                t[0] = 10.0;
                t[1] = 8.0;
                t[2] = 0.0;
                addbullet(this, NULL,801, (double)(50 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                field_190 = 1;
                play_sfx(2);
              }
              if ( !get_frame_time() && get_frame() == 9 )
                v_force = 0.5;
            }
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() != 3 )
              goto LABEL_1127;
            spell_energy_spend(200, 60);
            add_card_energy(50);
            t[0] = 10.0;
            t[1] = 8.0;
            t[2] = 0.0;
            goto LABEL_1126;
          case 415:
          /*
            v389 = __OFSUB__(get_subseq(), 2);
            v388 = (get_subseq() - 2) < 0;
            if ( get_subseq() == 2 )
            {
              sub10func();
              v389 = __OFSUB__(get_subseq(), 2);
              v388 = (get_subseq() - 2) < 0;
            }
            if ( v388 ^ v389 && !keyDown(INP_B) )
              not_charge_attack = 0;
            */
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
              goto LABEL_1103;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(9);
              return;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              goto LABEL_1110;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                spell_energy_spend(200, 60);
                add_card_energy(50);
                float t[3];
                t[0] = 30.0;
                t[1] = 8.0;
                t[2] = 0.0;
                addbullet(this, NULL,801, (double)(50 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                field_190 = 1;
                play_sfx(2);
              }
              if ( !get_frame_time() && get_frame() == 9 )
                v_force = 0.5;
            }
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() != 3 )
              goto LABEL_1127;
            spell_energy_spend(200, 60);
            add_card_energy(50);
            t[0] = 30.0;
            t[1] = 8.0;
            t[2] = 0.0;
            goto LABEL_1126;
          case 416:
          /*
            v398 = __OFSUB__(get_subseq(), 2);
            v397 = (get_subseq() - 2) < 0;
            if ( get_subseq() == 2 )
            {
              sub10func();
              v398 = __OFSUB__(get_subseq(), 2);
              v397 = (get_subseq() - 2) < 0;
            }
            if ( v397 ^ v398 && !keyDown(INP_B) )
              not_charge_attack = 0;
              */
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
            {
LABEL_1103:
              set_subseq(2);
              air_dash_cnt = 0;
              goto LABEL_111;
            }
            if ( process() )
              set_seq(0);
            if ( (get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1) && (get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 2) )
            {
              if ( !get_subseq() && !get_frame_time() )
              {
                if ( get_frame() == 6 )
                {
                  spell_energy_spend(200, 60);
                  add_card_energy(50);
                  float t[3];
                  t[0] = 10.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  addbullet(this, NULL,801, (double)(50 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                  field_190 = 1;
                  play_sfx(2);
                }
                if ( !get_frame_time() && get_frame() == 9 )
                  v_force = 0.5;
              }
              if ( get_subseq() == 1 && !get_frame_time() )
              {
                if ( get_frame() == 3 )
                {
                  spell_energy_spend(200, 60);
                  add_card_energy(50);
                  float t[3];
                  t[0] = 10.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
LABEL_1126:
                  addbullet(this, NULL,801, (double)(50 * dir) + x, y + 100.0, dir, 1, t, 3);
                  field_190 = 1;
                  play_sfx(2);
                }
LABEL_1127:
                if ( !get_frame_time() && get_frame() == 7 )
                  v_force = 0.5;
              }
            }
            else
            {
LABEL_1110:
              set_seq(9);
            }
            return;
          case 418:
            v3 = 5;
            if ( !get_subseq() || get_subseq() == 5 )
            {
              sub10func();
              if ( get_subseq() )
              {
                
              }
              else
              {
                h_inerc = h_inerc - 0.5;
                
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
            }
            if ( get_subseq() == 2 && !(get_elaps_frames() % 15) )
            {
              scene_play_sfx(28);
              
            }
            if ( get_subseq() >= 5 )
              goto LABEL_1148;
            v_inerc = v_inerc - v_force;
            if ( get_subseq() == 1 || get_subseq() == 2 )
            {
              if ( field_190 )
              {
                if ( field_190 != 3 )
                {
                  set_subseq(3);
                  h_inerc = -3.0;
                  v_inerc = 13.0;
                  v_force = 0.75;
                  field_190 = 1;
                  return;
                }
              }
            }
            
            if ( char_on_ground_down() )
            {
              v_inerc = 0.0;
              v_force = 0.0;
              goto LABEL_2838;
            }
LABEL_1148:
            if ( get_subseq() == 5 )
            {
              if ( 0.0 < h_inerc )
              {
                h_inerc = h_inerc - 1.0;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( 0.0 > h_inerc )
              {
                h_inerc = h_inerc + 1.0;
                if ( h_inerc > 0.0 )
                  h_inerc = 0.0;
              }
            }
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            h_inerc = 12.0;
            v221 = 9.0;
            break;
          default:
            goto LABEL_3248;
        }
LABEL_3188:
        v_inerc = v221;
        v_force = 0.5;
        return;
      }
      sub10func();
      field_18C = 0;
      if ( !keyDown(INP_B) )
        not_charge_attack = 0;
      if ( process() )
        set_seq(0);
      if ( get_elaps_frames() || (get_frame_time() || get_frame() || get_subseq() != 3) && (get_frame_time() || get_frame() || get_subseq() != 4) )
      {
        if ( get_subseq() != 1 )
          goto LABEL_1184;
        if ( field_7D0 < 14 || not_charge_attack && field_7D0 < 120 )
        {
LABEL_1181:
          if ( field_7D0 == 30 )
          {
            scene_add_effect(this, 62, x - (double)(5 * (char)dir), y + 90.0, dir, 1);
            field_7D2 = 1;
          }
          ++field_7D0;
LABEL_1184:
          if ( (get_subseq() == 2 || get_subseq() == 3 || get_subseq() == 4) && !get_frame_time() && get_frame() == 2 )
          {
            if ( field_7D2 == 1 )
            {
              float t[4];
              t[0] = 0.0;
              t[1] = 25.0;
              t[2] = 0.0;
              t[3] = 120.0;
              addbullet(this, NULL,810, (double)(140 * (char)dir) + x, y + 70.0, dir, 1, t, 4);
              y = y;
LABEL_1191:
              scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(10);
//LABEL_1436:
              //shake_camera(12.0);
            }
            else
            {
              float t[4];
              t[0] = 0.0;
              t[1] = 8.0;
              t[2] = 0.0;
              t[3] = (double)(char)skills_1[0] * 5.0 + 15.0;
              addbullet(this, NULL,810, (double)(140 * (char)dir) + x, y + 70.0, dir, 1, t, 4);
LABEL_1222:
              scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(10);
              //shake_camera(8.0);
            }
          }
                      LABEL_1436://TODO:change
          return;
        }
        if ( skills_1[0] > 1 )
        {
          if ( skills_1[0] == 2 || skills_1[0] == 3 )
          {
LABEL_2365:
            set_subseq(3);
            return;
          }
          if ( skills_1[0] >= 4 )
          {
LABEL_3230:
            set_subseq(4);
            return;
          }
          goto LABEL_1181;
        }
LABEL_2868:
        next_subseq();
        return;
      }
LABEL_3278:
      set_seq(0);
      return;
    }
    if ( get_seq() > 770 )
    {
      //v1334 = get_seq() - 795;
      if ( get_seq() - 795 )
      {
        if ( !get_seq() - 2 )
        {
          if ( !get_subseq() && get_elaps_frames() >= 0 )
            goto LABEL_2868;
          if ( get_subseq() == 1 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_subseq(2);
              y = getlvl_height();
              reset_forces();
              v_loop = 0.0;
              do
              {
                float t[3];
                t[0] = /*(double)(unsigned int)get_MT_range(40)*/40.0 + v_loop * 36.0 - 20.0;
                t[1] = /*(double)(unsigned int)get_MT_range(8)*/8.0 + 30.0;
                t[2] = 1.0;
                if ( t[0] < 0.0 || t[0] > 180.0 )
                  field_7D0 = -1;
                else
                  field_7D0 = 1;
                addbullet(this, NULL,811, (double)(40 * (char)dir) + x, y, dir, field_7D0, t, 3);
                v_loop = v_loop + 1.0;
              }
              while ( v_loop < 10.0 );
              return;
            }
          }
          if ( (!get_subseq() || get_subseq() == 1) && !(get_elaps_frames() % 5) )
          {
            float t[3];
            /*v1766*/t[0] = /*(double)(unsigned int)get_MT_range(360)*/360.0;
            /*v1767*/t[1] = (/*(double)(unsigned int)get_MT_range(50)*/50.0 * 0.1000000014901161) + 6.0;
            /*v1768*/t[2] = 1.0;
            addbullet(this, NULL,999, x, y + 100.0, dir, 1, t, 3);
          }
          if ( get_subseq() == 3 && field_7D4 == 1 )
            goto LABEL_2868;
          if ( !process() )
            return;
          goto LABEL_3278;
        }
        if ( (get_seq() - 2) != 1 )
        {
LABEL_3248:
          char_c::func10();
          return;
        }
        if ( !get_subseq() && get_elaps_frames() >= 0 )
          goto LABEL_2868;
        if ( get_subseq() == 1 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            scene_play_sfx(30);
            set_subseq(2);
            y = getlvl_height();
            reset_forces();
            /*
            v_loop = 0.0;
            do
            {
              *(float *)&v1631 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v_loop * 36.0 - 20.0;
              v1632 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
              v1633 = 1.0;
              if ( *(float *)&v1631 < 0.0 || *(float *)&v1631 > 180.0 )
                field_7D0 = -1;
              else
                field_7D0 = 1;
              v1337 = dir;
              v1338 = (double)(40 * (char)v1337) + x;
              addbullet(this, NULL,811, v1338, y, v1337, LOBYTE(field_7D0), (int)&v1631, 3);
              v_loop = v_loop + 1.0;
            }
            while ( v_loop < 10.0 );
            */
            return;
          }
        }
        if ( (!get_subseq() || get_subseq() == 1) && !(get_elaps_frames() % 4) )
        {
          /*
          *(float *)&v1760 = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
          v1340 = /*(double)(unsigned int)get_MT_range(50)*//*50.0 * 0.1000000014901161;
          v1761 = v1340 + 6.0;
          v1762 = 1.0;
          v1341 = y + 100.0
          addbullet(this, NULL,999, x, v1341, dir, 1, (int)&v1760, 3);
          */
        }
        if ( get_subseq() == 3 && field_7D4 == 1 )
          goto LABEL_2868;
        if ( process() )
LABEL_3259:
          set_seq(700);
      }
      else
      {
        if ( !get_subseq() )
        {
          if ( !(get_elaps_frames() % 4) )
          {
            /*
            *(float *)&v1772 = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
            v1348 = /*(double)(unsigned int)get_MT_range(50)*//*50.0 * 0.1000000014901161;
            v1773 = v1348 + 6.0;
            v1774 = 1.0;
            v1349 = y + 100.0
            addbullet(this, NULL,999, x, v1349, dir, 1, (int)&v1772, 3);
            */
          }
          v_inerc = -y * 0.1000000014901161;
          if ( v_inerc < -12.0 )
            v_inerc = -12.0;
          if ( v_inerc > -2.0 )
            v_inerc = -2.0;
          v_inerc = -4.0;
          x = sin_deg(3 * get_elaps_frames()) * field_7DC + dash_angle;
          field_7DC = field_7DC * 0.8999999761581421;
          if ( getlvl_height() >= y )
          {
            y = getlvl_height();
            next_subseq();
            v_inerc = 0.0;
            x = dash_angle;
            /*
            v1459 = 0.0;
            do
            {
              *(float *)&v1778 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1459 * 45.0 - 20.0;
              v1779 = (double)(unsigned int)get_MT_range(13) + 12.0;
              v1780 = 0.0;
              v1352 = y + 100.0
              addbullet(this, NULL,999, x, v1352, dir, 1, (int)&v1778, 3);
              v1459 = v1459 + 1.0;
            }
            while ( v1459 < 8.0 );
            */
          }
        }
        if ( get_subseq() == 1 && get_elaps_frames() >= 120 || get_subseq() == 2 && field_7D4 == 1 )
        {
LABEL_3151:
          next_subseq();
        }
        else if ( process() )
        {
LABEL_3294:
          set_seq(700);
        }
      }
    }
    else
    {
      if ( get_seq() != 770 )
      {
        switch ( get_seq() )
        {
          case 501:
            sub10func();
            field_18C = 0;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 3 || !get_frame_time() && !get_frame() && get_subseq() == 4) )
              goto LABEL_3278;
            if ( get_subseq() != 1 )
              goto LABEL_1214;
            if ( field_7D0 >= 20 && (!not_charge_attack || field_7D0 >= 120) )
              goto LABEL_2868;
            if ( field_7D0 == 30 )
            {
              scene_add_effect(this, 62, (double)(13 * (char)dir) + x, y + 142.0, dir, 1);
              field_7D2 = 1;
            }
            ++field_7D0;
LABEL_1214:
            if ( get_subseq() != 2 && get_subseq() != 3 && get_subseq() != 4 || get_frame_time() || get_frame() != 4 )
              return;
            if ( field_7D2 == 1 )
            {
              float t[4];
              t[0] = -60.0;
              t[1] = 25.0;
              t[2] = 4.0;
              t[3] = 120.0;
              addbullet(this, NULL,810, (double)(80 * (char)dir) + x, y + 166.0, dir, 1, t, 4);
              y = y;
              goto LABEL_1191;
            }
            float t[4];
            t[0] = -60.0;
            t[1] = 8.0;
            t[2] = 4.0;
            t[3] = (double)(char)skills_1[0] * 5.0 + 15.0;
            addbullet(this, NULL,810, (double)(80 * (char)dir) + x, y + 166.0, dir, 1, t, 4);
            goto LABEL_1222;
          case 505:
            sub10func();
            field_18C = 4;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              float t[4];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 7.0;
              t[3] = 0.0;
              addbullet(this, NULL,815, x - (double)(10 * (char)dir),  y + 250.0, dir, 1, t, 4);
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( get_subseq() != 1 )
              goto LABEL_1236;
            if ( field_7D0 >= 0 && (!not_charge_attack || field_7D0 >= 180) )
              goto LABEL_3151;
            field_7D0 = field_7D0 + 1;
LABEL_1236:
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
            {
              field_7D2 = 1;
              /*
              v1612 = 1.0;
              v1389 = 0.0;
              do
              {
                *(float *)&v1610 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1389 * 60.0 - 20.0;
                v1611 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
                if ( *(float *)&v1610 < 0.0 || *(float *)&v1610 > 180.0 )
                  field_7D0 = -1;
                else
                  field_7D0 = 1;
                v456 = dir;
                v457 = (double)(40 * (char)v456) + x;
                addbullet(this, NULL,811, v457, y, v456, LOBYTE(field_7D0), (int)&v1610, 3);
                v1389 = v1389 + 1.0;
              }
              while ( v1389 < 6.0 );
              */
            }
            return;
          case 506:
            sub10func();
            field_18C = 4;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              float t[4];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 7.0;
              t[3] = 1.0;
              addbullet(this, NULL,815, x - (double)(10 * (char)dir), y + 250.0, dir, 1, t, 4);
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( get_subseq() != 1 )
              goto LABEL_1259;
            if ( field_7D0 >= 0 && (!not_charge_attack || field_7D0 >= 180) )
              goto LABEL_3151;
            field_7D0 = field_7D0; + 1;
LABEL_1259:
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
            {
              field_7D2 = 1;
              /*
              v1645 = 1.0;
              v1390 = 0.0;
              do
              {
                *(float *)&v1643 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1390 * 60.0 - 20.0;
                v1644 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
                if ( *(float *)&v1643 < 0.0 || *(float *)&v1643 > 180.0 )
                  field_7D0 = -1;
                else
                  field_7D0 = 1;
                v463 = dir;
                v464 = (double)(40 * (char)v463) + x;
                addbullet(this, NULL,811, v464, y, v463, LOBYTE(field_7D0), (int)&v1643, 3);
                v1390 = v1390 + 1.0;
              }
              while ( v1390 < 6.0 );
              */
            }
            return;
          case 507:
            if ( get_subseq() == 3 )
              sub10func();
            field_18C = 4;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() <= 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
                set_subseq(3);
              }
            }
            if ( process() )
              goto LABEL_3278;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              goto LABEL_1873;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              float t[4];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 7.0;
              t[3] = 0.0;
              addbullet(this, NULL,815, x - (double)(10 * (char)dir), y + 250.0, dir, 1, t, 4);
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( get_subseq() != 1 )
              goto LABEL_1290;
            if ( field_7D0 >= 0 && (!not_charge_attack || field_7D0 >= 180) )
              goto LABEL_3151;
            field_7D0 = field_7D0 + 1;
LABEL_1290:
            if ( get_subseq() != 2 || get_frame_time() )
              return;
            if ( get_frame() != 2 )
              goto LABEL_1331;
            field_7D2 = 1;
            /*
            v1651 = 1.0;
            v1391 = 0.0;
            do
            {
              *(float *)&v1649 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1391 * 60.0 - 20.0;
              v1650 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
              if ( *(float *)&v1649 < 0.0 || *(float *)&v1649 > 180.0 )
                field_7D0 = -1;
              else
                field_7D0 = 1;
              v470 = dir;
              v471 = (double)(40 * (char)v470) + x;
              addbullet(this, NULL,811, v471, y, v470, LOBYTE(field_7D0), (int)&v1649, 3);
              v1391 = v1391 + 1.0;
            }
            while ( v1391 < 6.0 );
            */
            goto LABEL_1330;
          case 508:
            if ( get_subseq() == 3 )
              sub10func();
            field_18C = 4;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() <= 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
                set_subseq(3);
              }
            }
            if ( process() )
              goto LABEL_3278;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              goto LABEL_1873;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              float t[4];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 7.0;
              t[3] = 1.0;
              addbullet(this, NULL,815, x - (double)(10 * (char)dir), y + 250.0, dir, 1, t, 4);
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( get_subseq() != 1 )
              goto LABEL_1321;
            if ( field_7D0 >= 0 && (!not_charge_attack || field_7D0 >= 180) )
              goto LABEL_3151;
            field_7D0 = field_7D0 + 1;
LABEL_1321:
            if ( get_subseq() != 2 || get_frame_time() )
              return;
            if ( get_frame() == 2 )
            {
              field_7D2 = 1;
              /*
              v1657 = 1.0;
              v1392 = 0.0;
              do
              {
                *(float *)&v1655 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1392 * 60.0 - 20.0;
                v1656 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
                if ( *(float *)&v1655 < 0.0 || *(float *)&v1655 > 180.0 )
                  field_7D0 = -1;
                else
                  field_7D0 = 1;
                v477 = dir;
                v478 = (double)(40 * (char)v477) + x;
                addbullet(this, NULL,811, v478, y, v477, LOBYTE(field_7D0), (int)&v1655, 3);
                v1392 = v1392 + 1.0;
              }
              while ( v1392 < 6.0 );
              */
LABEL_1330:
              v_force = 0.5;
              h_inerc = -6.0;
              v_inerc = 7.5;
            }
LABEL_1331:
            if ( get_frame_time() )
              return;
            v479 = get_frame() == 8;
            goto LABEL_1682;
          case 510:
            field_18C = 8;
            if ( !get_subseq() || get_subseq() >= 3 )
              sub10func();
            if ( get_subseq() != 1 && get_subseq() != 2 )
              goto LABEL_1407;
            v_inerc = v_inerc - v_force;
            if ( !char_on_ground_down() )
              goto LABEL_1407;
            reset_forces();
            y = getlvl_height();
            //v1393 = 0.0;
            if ( skills_1[8] <= 1 )
            {
              /*
              do
              {
                *(float *)&v1507 = (double)(unsigned int)get_MT_range(20) + v1393 * 36.0;
                v1508 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                v1509 = 1.0;
                v483 = -*(float *)&v1507;
                v484 = sin_deg(v483) > 0.0;
                addbullet(this, NULL,820, x, y, dir, (1 - 2 * v484), (int)&v1507, 3);
                v1393 = v1393 + 1.0;
              }
              while ( v1393 < 10.0 );
              v1437 = 0.0;
              do
              {
                *(float *)&v1507 = (double)(unsigned int)get_MT_range(160) + 10.0;
                v1508 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                v1509 = 3.0;
                v485 = -*(float *)&v1507;
                v486 = sin_deg(v485) > 0.0;
                addbullet(this, NULL,820, x, y, dir, (1 - 2 * v486), (int)&v1507, 3);
                v1437 = v1437 + 1.0;
              }
              while ( v1437 < 6.0 );
              v1508 = 1.0;
              v1509 = 0.0;
              addbullet(this, NULL,820, x, y, dir, 1, (int)&v1507, 3);
              */
              set_subseq(3);
              play_sfx(12);
              //shake_camera(10.0);
              return;
            }
            if ( skills_1[8] <= 3 )
            {
              /*
              do
              {
                *(float *)&v1504 = (double)(unsigned int)get_MT_range(20) + v1393 * 24.0;
                v1505 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 15.0;
                v1506 = 1.0;
                v487 = -*(float *)&v1504;
                v488 = sin_deg(v487) > 0.0;
                addbullet(this, NULL,820, x, y, dir, (1 - 2 * v488), (int)&v1504, 3);
                v1393 = v1393 + 1.0;
              }
              while ( v1393 < 15.0 );
              v1438 = 0.0;
              do
              {
                *(float *)&v1504 = (double)(unsigned int)get_MT_range(160) + 10.0;
                v1505 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                v1506 = 3.0;
                v489 = -*(float *)&v1504;
                v490 = sin_deg(v489) > 0.0;
                addbullet(this, NULL,820, x, y, dir, (1 - 2 * v490), (int)&v1504, 3);
                v1438 = v1438 + 1.0;
              }
              while ( v1438 < 6.0 );
              v1505 = 1.5;
              v1506 = 0.0;
              addbullet(this, NULL,820, x, y, dir, 1, (int)&v1504, 3);
              */
              set_subseq(4);
              play_sfx(12);
              //shake_camera(12.0);
              return;
            }
            /*
            do
            {
              *(float *)&v1474 = (double)(unsigned int)get_MT_range(20) + v1393 * 24.0;
              v1475 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 15.0;
              v1476 = 1.0;
              v491 = -*(float *)&v1474;
              v492 = sin_deg(v491) > 0.0;
              addbullet(this, NULL,820, x, y, dir, (1 - 2 * v492), (int)&v1474, 3);
              v1393 = v1393 + 1.0;
            }
            while ( v1393 < 15.0 );
            v1439 = 0.0;
            do
            {
              *(float *)&v1474 = (double)(unsigned int)get_MT_range(160) + 10.0;
              v1475 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
              v1476 = 3.0;
              v493 = -*(float *)&v1474;
              v494 = sin_deg(v493) > 0.0;
              addbullet(this, NULL,820, x, y, dir, (1 - 2 * v494), (int)&v1474, 3);
              v1439 = v1439 + 1.0;
            }
            while ( v1439 < 6.0 );
            v1475 = 2.0;
            v1476 = 0.0;
            addbullet(this, NULL,820, x, y, dir, 1, (int)&v1474, 3);
            v1475 = 0.5;
            v495 = &v1474;
            v1476 = 2.0;
            */
            goto LABEL_1406;
          case 511:
            field_18C = 8;
            if ( !get_subseq() || get_subseq() >= 3 )
              sub10func();
            if ( get_subseq() == 1 || get_subseq() == 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
                //v1394 = 0.0;
                if ( skills_1[8] > 1 )
                {
                  if ( skills_1[8] > 3 )
                  {
                    /*
                    do
                    {
                      *(float *)&v1477 = (double)(unsigned int)get_MT_range(20) + v1394 * 24.0;
                      v1478 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 15.0;
                      v1479 = 1.0;
                      v507 = -*(float *)&v1477;
                      v508 = sin_deg(v507) > 0.0;
                      addbullet(this, NULL,820, x, y, dir, (1 - 2 * v508), (int)&v1477, 3);
                      v1394 = v1394 + 1.0;
                    }
                    while ( v1394 < 15.0 );
                    v1442 = 0.0;
                    do
                    {
                      *(float *)&v1477 = (double)(unsigned int)get_MT_range(160) + 10.0;
                      v1478 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                      v1479 = 3.0;
                      v509 = -*(float *)&v1477;
                      v510 = sin_deg(v509) > 0.0;
                      addbullet(this, NULL,820, x, y, dir, (1 - 2 * v510), (int)&v1477, 3);
                      v1442 = v1442 + 1.0;
                    }
                    while ( v1442 < 6.0 );
                    v1478 = 2.0;
                    v1479 = 0.0;
                    addbullet(this, NULL,820, x, y, dir, 1, (int)&v1477, 3);
                    v1478 = 0.5;
                    v1479 = 2.0;
                    addbullet(this, NULL,820, x, y, dir, -1, (int)&v1477, 3);
                    */
                    play_sfx(12);
                    set_subseq(5);
                    //shake_camera(15.0);
                  }
                  else
                  {
                    /*
                    do
                    {
                      *(float *)&v1513 = (double)(unsigned int)get_MT_range(20) + v1394 * 24.0;
                      v1514 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 15.0;
                      v1515 = 1.0;
                      v503 = -*(float *)&v1513;
                      v504 = sin_deg(v503) > 0.0;
                      addbullet(this, NULL,820, x, y, dir, (1 - 2 * v504), (int)&v1513, 3);
                      v1394 = v1394 + 1.0;
                    }
                    while ( v1394 < 15.0 );
                    v1441 = 0.0;
                    do
                    {
                      *(float *)&v1513 = (double)(unsigned int)get_MT_range(160) + 10.0;
                      v1514 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                      v1515 = 3.0;
                      v505 = -*(float *)&v1513;
                      v506 = sin_deg(v505) > 0.0;
                      addbullet(this, NULL,820, x, y, dir, (1 - 2 * v506), (int)&v1513, 3);
                      v1441 = v1441 + 1.0;
                    }
                    while ( v1441 < 6.0 );
                    v1514 = 1.5;
                    v1515 = 0.0;
                    addbullet(this, NULL,820, x, y, dir, 1, (int)&v1513, 3);
                    */
                    set_subseq(4);
                    play_sfx(12);
                    //shake_camera(12.0);
                  }
                }
                else
                {
                  /*
                  do
                  {
                    *(float *)&v1492 = (double)(unsigned int)get_MT_range(20) + v1394 * 36.0;
                    v1493 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                    v1494 = 1.0;
                    v499 = -*(float *)&v1492;
                    v500 = sin_deg(v499) > 0.0;
                    addbullet(this, NULL,820, x, y, dir, (1 - 2 * v500), (int)&v1492, 3);
                    v1394 = v1394 + 1.0;
                  }
                  while ( v1394 < 10.0 );
                  v1440 = 0.0;
                  do
                  {
                    *(float *)&v1492 = (double)(unsigned int)get_MT_range(160) + 10.0;
                    v1493 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                    v1494 = 3.0;
                    v501 = -*(float *)&v1492;
                    v502 = sin_deg(v501) > 0.0;
                    addbullet(this, NULL,820, x, y, dir, (1 - 2 * v502), (int)&v1492, 3);
                    v1440 = v1440 + 1.0;
                  }
                  while ( v1440 < 6.0 );
                  v1493 = 1.0;
                  v1494 = 0.0;
                  addbullet(this, NULL,820, x, y, dir, 1, (int)&v1492, 3);
                  */
                  set_subseq(3);
                  play_sfx(12);
                  //shake_camera(10.0);
                }
                return;
              }
            }
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              h_inerc = 12.5;
              v_inerc = 15.0;
              v_force = 1.25;
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( get_elaps_frames() )
              return;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
            {
              set_seq(get_elaps_frames());
              return;
            }
            goto LABEL_1454;
          case 512:
            field_18C = 8;
            if ( get_subseq() >= 3 )
              sub10func();
            if ( get_subseq() == 1 || get_subseq() == 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
                //v1395 = 0.0;
                if ( skills_1[8] > 1 )
                {
                  if ( skills_1[8] > 3 )
                  {
                    /*
                    do
                    {
                      *(float *)&v1483 = (double)(unsigned int)get_MT_range(20) + v1395 * 24.0;
                      v1484 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 15.0;
                      v1485 = 1.0;
                      v521 = -*(float *)&v1483;
                      v522 = sin_deg(v521) > 0.0;
                      addbullet(this, NULL,820, x, y, dir, (1 - 2 * v522), (int)&v1483, 3);
                      v1395 = v1395 + 1.0;
                    }
                    while ( v1395 < 15.0 );
                    v1445 = 0.0;
                    do
                    {
                      *(float *)&v1483 = (double)(unsigned int)get_MT_range(160) + 10.0;
                      v1484 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                      v1485 = 3.0;
                      v523 = -*(float *)&v1483;
                      v524 = sin_deg(v523) > 0.0;
                      addbullet(this, NULL,820, x, y, dir, (1 - 2 * v524), (int)&v1483, 3);
                      v1445 = v1445 + 1.0;
                    }
                    while ( v1445 < 6.0 );
                    v1484 = 2.0;
                    v1485 = 0.0;
                    addbullet(this, NULL,820, x, y, dir, 1, (int)&v1483, 3);
                    v1484 = 0.5;
                    v495 = &v1483;
                    v1485 = 2.0;
LABEL_1406:
                    addbullet(this, NULL,820, x, y, dir, -1, (int)v495, 3);
                    */
                    LABEL_1406://TODO: change
                    play_sfx(12);
                    set_subseq(5);
                    //shake_camera(15.0);
                  }
                  else
                  {
                    /*
                    do
                    {
                      *(float *)&v1498 = (double)(unsigned int)get_MT_range(20) + v1395 * 24.0;
                      v1499 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 15.0;
                      v1500 = 1.0;
                      v517 = -*(float *)&v1498;
                      v518 = sin_deg(v517) > 0.0;
                      addbullet(this, NULL,820, x, y, dir, (1 - 2 * v518), (int)&v1498, 3);
                      v1395 = v1395 + 1.0;
                    }
                    while ( v1395 < 15.0 );
                    v1444 = 0.0;
                    do
                    {
                      *(float *)&v1498 = (double)(unsigned int)get_MT_range(160) + 10.0;
                      v1499 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                      v1500 = 3.0;
                      v519 = -*(float *)&v1498;
                      v520 = sin_deg(v519) > 0.0;
                      addbullet(this, NULL,820, x, y, dir, (1 - 2 * v520), (int)&v1498, 3);
                      v1444 = v1444 + 1.0;
                    }
                    while ( v1444 < 6.0 );
                    v1499 = 1.5;
                    v1500 = 0.0;
                    addbullet(this, NULL,820, x, y, dir, 1, (int)&v1498, 3);
                    */
                    set_subseq(4);
                    play_sfx(12);
                    //shake_camera(12.0);
                  }
                }
                else
                {
                  /*
                  do
                  {
                    *(float *)&v1510 = (double)(unsigned int)get_MT_range(20) + v1395 * 36.0;
                    v1511 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                    v1512 = 1.0;
                    v513 = -*(float *)&v1510;
                    v514 = sin_deg(v513) > 0.0;
                    addbullet(this, NULL,820, x, y, dir, (1 - 2 * v514), (int)&v1510, 3);
                    v1395 = v1395 + 1.0;
                  }
                  while ( v1395 < 10.0 );
                  v1443 = 0.0;
                  do
                  {
                    *(float *)&v1510 = (double)(unsigned int)get_MT_range(160) + 10.0;
                    v1511 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                    v1512 = 3.0;
                    v515 = -*(float *)&v1510;
                    v516 = sin_deg(v515) > 0.0;
                    addbullet(this, NULL,820, x, y, dir, (1 - 2 * v516), (int)&v1510, 3);
                    v1443 = v1443 + 1.0;
                  }
                  while ( v1443 < 6.0 );
                  v1511 = 1.0;
                  v1512 = 0.0;
                  addbullet(this, NULL,820, x, y, dir, 1, (int)&v1510, 3);
                  */
                  set_subseq(3);
                  play_sfx(12);
                  //shake_camera(10.0);
                }
                return;
              }
            }
LABEL_1407:
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              h_inerc = 7.5;
              v_inerc = 13.5;
              v_force = 1.25;
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( get_elaps_frames() )
              return;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
            {
              set_seq(get_elaps_frames());
              return;
            }
            goto LABEL_1454;
          case 513:
            field_18C = 8;
            if ( get_subseq() >= 3 )
              sub10func();
            if ( (get_subseq() == 1 || get_subseq() == 2) && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
            {
              reset_forces();
              y = getlvl_height();
              //v1396 = 0.0;
              if ( skills_1[8] <= 1 )
              {
                /*
                do
                {
                  *(float *)&v1501 = (double)(unsigned int)get_MT_range(20) + v1396 * 36.0;
                  v1502 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                  v1503 = 1.0;
                  v527 = -*(float *)&v1501;
                  v528 = sin_deg(v527) > 0.0;
                  addbullet(this, NULL,820, x, y, dir, (1 - 2 * v528), (int)&v1501, 3);
                  v1396 = v1396 + 1.0;
                }
                while ( v1396 < 10.0 );
                v1446 = 0.0;
                do
                {
                  *(float *)&v1501 = (double)(unsigned int)get_MT_range(160) + 10.0;
                  v1502 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                  v1503 = 3.0;
                  v529 = -*(float *)&v1501;
                  v530 = sin_deg(v529) > 0.0;
                  addbullet(this, NULL,820, x, y, dir, (1 - 2 * v530), (int)&v1501, 3);
                  v1446 = v1446 + 1.0;
                }
                while ( v1446 < 6.0 );
                v1502 = 1.0;
                v1503 = 0.0;
                addbullet(this, NULL,820, x, y, dir, 1, (int)&v1501, 3);
                */
                set_subseq(3);
                play_sfx(12);
                //shake_camera(10.0);
                return;
              }
              if ( skills_1[8] <= 3 )
              {
                /*
                do
                {
                  *(float *)&v1486 = (double)(unsigned int)get_MT_range(20) + v1396 * 24.0;
                  v1487 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 15.0;
                  v1488 = 1.0;
                  v531 = -*(float *)&v1486;
                  v532 = sin_deg(v531) > 0.0;
                  addbullet(this, NULL,820, x, y, dir, (1 - 2 * v532), (int)&v1486, 3);
                  v1396 = v1396 + 1.0;
                }
                while ( v1396 < 15.0 );
                v1447 = 0.0;
                do
                {
                  *(float *)&v1486 = (double)(unsigned int)get_MT_range(160) + 10.0;
                  v1487 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                  v1488 = 3.0;
                  v533 = -*(float *)&v1486;
                  v534 = sin_deg(v533) > 0.0;
                  addbullet(this, NULL,820, x, y, dir, (1 - 2 * v534), (int)&v1486, 3);
                  v1447 = v1447 + 1.0;
                }
                while ( v1447 < 6.0 );
                v1487 = 1.5;
                v1488 = 0.0;
                addbullet(this, NULL,820, x, y, dir, 1, (int)&v1486, 3);
                */
                set_subseq(4);
                play_sfx(12);
                goto LABEL_1436;
              }
              /*
              do
              {
                *(float *)&v1480 = (double)(unsigned int)get_MT_range(20) + v1396 * 24.0;
                v1481 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 15.0;
                v1482 = 1.0;
                v535 = -*(float *)&v1480;
                v536 = sin_deg(v535) > 0.0;
                addbullet(this, NULL,820, x, y, dir, (1 - 2 * v536), (int)&v1480, 3);
                v1396 = v1396 + 1.0;
              }
              while ( v1396 < 15.0 );
              v1448 = 0.0;
              do
              {
                *(float *)&v1480 = (double)(unsigned int)get_MT_range(160) + 10.0;
                v1481 = (double)(unsigned int)get_MT_range(25) * 0.1000000014901161 + 10.0;
                v1482 = 3.0;
                v537 = -*(float *)&v1480;
                v538 = sin_deg(v537) > 0.0;
                addbullet(this, NULL,820, x, y, dir, (1 - 2 * v538), (int)&v1480, 3);
                v1448 = v1448 + 1.0;
              }
              while ( v1448 < 6.0 );
              v1481 = 2.0;
              v1482 = 0.0;
              addbullet(this, NULL,820, x, y, dir, 1, (int)&v1480, 3);
              v1481 = 0.5;
              v1482 = 2.0;
              addbullet(this, NULL,820, x, y, dir, -1, (int)&v1480, 3);
              */
              play_sfx(12);
              set_subseq(5);
              //shake_camera(15.0);
            }
            else
            {
              if ( !keyDown(INP_B) )
                not_charge_attack = 0;
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                h_inerc = 12.5;
                v_inerc = 15.0;
                v_force = 1.25;
                spell_energy_spend(200, 120);
                add_card_energy(50);
              }
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                  goto LABEL_3278;
LABEL_1454:
                if ( !get_frame_time() && !get_frame() && get_subseq() == 5 )
                  set_seq(0);
              }
            }
            return;
          case 520:
            if ( !get_subseq() || get_subseq() == 6 )
              sub10func();
            field_18C = 1;
            v_inerc = v_inerc - v_force;
            if ( get_subseq() == 4 || get_subseq() == 5 )
            {
              h_inerc = h_inerc + 0.5;
              if ( h_inerc > -5.0 )
                h_inerc = -5.0;
            }
            if ( !char_on_ground_down() )
              goto LABEL_1476;
            if ( get_subseq() == 3 )
            {
              play_sfx(12);
              //shake_camera(6.0);
              set_subseq(4);
              y = getlvl_height();
              h_inerc = -12.5;
              v_inerc = 5.5;
              v_force = 0.34999999;
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL,811, (double)(40 * (char)dir) + x, y, dir, 1, t, 3);
              t[2] = 2.0;
              addbullet(this, NULL,811, (double)(40 * (char)dir) + x, y, dir, -1, t, 3);
              t[2] = 1.0;
              /*
              v1397 = 0.0;
              do
              {
                *(float *)&v1531 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1397 * 60.0 - 20.0;
                v1532 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
                if ( *(float *)&v1531 < 0.0 || *(float *)&v1531 > 180.0 )
                  field_7D0 = -1;
                else
                  field_7D0 = 1;
                v547 = dir;
                v548 = (double)(40 * (char)v547) + x;
                addbullet(this, NULL,811, v548, y, v547, LOBYTE(field_7D0), (int)&v1531, 3);
                v1397 = v1397 + 1.0;
              }
              while ( v1397 < 6.0 );
              */
              return;
            }
            if ( get_subseq() == 4 || get_subseq() == 5 )
              goto LABEL_1501;
LABEL_1476:
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              return;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              h_inerc = 3.0;
              v549 = 12.5;
              goto LABEL_1509;
            }
            goto LABEL_1510;
          case 521:
            if ( !get_subseq() || get_subseq() == 6 )
              sub10func();
            field_18C = 1;
            v_inerc = v_inerc - v_force;
            if ( get_subseq() == 4 || get_subseq() == 5 )
            {
              h_inerc = h_inerc + 0.5;
              if ( h_inerc > -5.0 )
                h_inerc = -5.0;
            }
            if ( !char_on_ground_down() )
              goto LABEL_1502;
            if ( get_subseq() == 3 )
            {
              play_sfx(12);
              //shake_camera(6.0);
              set_subseq(4);
              y = getlvl_height();
              h_inerc = -12.5;
              v_inerc = 5.5;
              v_force = 0.34999999;
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL,811, (double)(40 * (char)dir) + x, y, dir, 1, t, 3);
              t[2] = 2.0;
              addbullet(this, NULL,811, (double)(40 * (char)dir) + x, y, dir, -1, t, 3);
              t[2] = 1.0;
              /*
              v1398 = 0.0;
              do
              {
                *(float *)&v1522 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1398 * 60.0 - 20.0;
                v1523 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
                if ( *(float *)&v1522 < 0.0 || *(float *)&v1522 > 180.0 )
                  field_7D0 = -1;
                else
                  field_7D0 = 1;
                v558 = dir;
                v559 = (double)(40 * (char)v558) + x;
                addbullet(this, NULL,811, v559, y, v558, LOBYTE(field_7D0), (int)&v1522, 3);
                v1398 = v1398 + 1.0;
              }
              while ( v1398 < 6.0 );
              */
            }
            else
            {
              if ( get_subseq() == 4 || get_subseq() == 5 )
              {
LABEL_1501:
                set_subseq(6);
                goto LABEL_111;
              }
LABEL_1502:
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  h_inerc = 9.0;
                  v549 = 17.5;
LABEL_1509:
                  v_inerc = v549;
                  v_force = 0.25;
                }
LABEL_1510:
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                {
                  h_inerc = 18.0;
                  v_inerc = -18.0;
                  play_sfx(11);
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  field_190 = 0;
                  field_194 = 1;
                }
              }
            }
            return;
          case 522:
            if ( get_subseq() == 5 )
              sub10func();
            field_18C = 1;
            v_inerc = v_inerc - v_force;
            if ( get_subseq() == 3 || get_subseq() == 4 )
            {
              h_inerc = h_inerc + 0.5;
              if ( h_inerc > -5.0 )
                h_inerc = -5.0;
            }
            if ( !char_on_ground_down() )
              goto LABEL_1532;
            if (  get_subseq() == 2 )
            {
              play_sfx(12);
              //shake_camera(6.0);
              set_subseq(3);
              y = getlvl_height();
              h_inerc = -12.5;
              v_inerc = 5.5;
              v_force = 0.34999999;
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL,811, (double)(40 * (char)dir) + x, y, dir, 1, t, 3);
              t[2] = 2.0;
              addbullet(this, NULL,811, (double)(40 * (char)dir) + x, y, dir, -1, t, 3);
              t[2] = 1.0;
              /*
              v1399 = 0.0;
              do
              {
                *(float *)&v1528 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1399 * 60.0 - 20.0;
                v1529 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
                if ( *(float *)&v1528 < 0.0 || *(float *)&v1528 > 180.0 )
                  field_7D0 = -1;
                else
                  field_7D0 = 1;
                v567 = dir;
                v568 = (double)(40 * (char)v567) + x;
                addbullet(this, NULL,811, v568, y, v567, LOBYTE(field_7D0), (int)&v1528, 3);
                v1399 = v1399 + 1.0;
              }
              while ( v1399 < 6.0 );
              */
              return;
            }
            if ( get_subseq() == 3 || get_subseq() == 4 )
              goto LABEL_1556;
            goto LABEL_1532;
          case 523:
            if ( get_subseq() == 5 )
              sub10func();
            field_18C = 1;
            v_inerc = v_inerc - v_force;
            if ( get_subseq() == 3 || get_subseq() == 4 )
            {
              h_inerc = h_inerc + 0.5;
              if ( h_inerc > -5.0 )
                h_inerc = -5.0;
            }
            if ( !char_on_ground_down() )
              goto LABEL_1532;
            if ( get_subseq() == 2 )
            {
              play_sfx(12);
              //shake_camera(6.0);
              set_subseq(3);
              y = getlvl_height();
              h_inerc = -12.5;
              v_inerc = 5.5;
              v_force = 0.34999999;
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL,811, (double)(40 * (char)dir) + x, y, dir, 1, t, 3);
              t[2] = 2.0;
              addbullet(this, NULL,811, (double)(40 * (char)dir) + x, y, dir, -1, t, 3);
              t[2] = 1.0;
              /*
              v1400 = 0.0;
              do
              {
                *(float *)&v1525 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1400 * 60.0 - 20.0;
                v1526 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
                if ( *(float *)&v1525 < 0.0 || *(float *)&v1525 > 180.0 )
                  field_7D0 = -1;
                else
                  field_7D0 = 1;
                v576 = dir;
                v577 = (double)(40 * (char)v576) + x;
                addbullet(this, NULL,811, v577, y, v576, LOBYTE(field_7D0), (int)&v1525, 3);
                v1400 = v1400 + 1.0;
              }
              while ( v1400 < 6.0 );
              */
            }
            else
            {
              if ( get_subseq() == 3 || get_subseq() == 4 )
              {
LABEL_1556:
                set_subseq(5);
                goto LABEL_111;
              }
LABEL_1532:
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              {
                h_inerc = 18.0;
                v_inerc = -18.0;
                play_sfx(11);
LABEL_1616:
                spell_energy_spend(200, 120);
                add_card_energy(50);
              }
            }
            return;
          case 525:
            sub10func();
            field_18C = 5;
            if ( process() )
              set_seq(0);
            if ( get_frame_time() || get_frame() != 6 )
              return;
            //shake_camera(8.0);
            /*v1518 = 2.0;
            v1401 = 0.0;
            do
            {
              *(float *)&v1516 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1401 * 60.0 - 20.0;
              v1517 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
              if ( *(float *)&v1516 < 0.0 || *(float *)&v1516 > 180.0 )
                field_7D0 = -1;
              else
                field_7D0 = 1;
              v578 = dir;
              v579 = (double)(103 * (char)v578) + x;
              addbullet(this, NULL,816, v579, y, v578, LOBYTE(field_7D0), (int)&v1516, 3);
              v1401 = v1401 + 1.0;
            }
            while ( v1401 < 6.0 );
            v1518 = 3.0;
            v580 = dir;
            v581 = (double)(103 * (char)v580) + x;
            addbullet(this, NULL,816, v581, y, v580, -1, (int)&v1516, 3);
            v1518 = 0.0;
            v582 = (double)(char)skills_1[5] + 5.0;
            v1449 = 0.0;
            v1402 = v582;
            if ( v582 > 0.0 )
            {
              do
              {
                *(float *)&v1516 = -(double)(unsigned int)get_MT_range(80) - 20.0;
                v1517 = (double)(unsigned int)get_MT_range(18) + 7.0;
                if ( *(float *)&v1516 < 0.0 || *(float *)&v1516 > 180.0 )
                  field_7D0 = -1;
                else
                  field_7D0 = 1;
                v583 = dir;
                v584 = (double)(103 * (char)v583) + x;
                addbullet(this, NULL,816, v584, y, v583, 1, (int)&v1516, 3);
                v1449 = v1449 + 1.0;
              }
              while ( v1449 < v1402 );
            }
            */
            goto LABEL_1590;
          case 526:
            sub10func();
            field_18C = 5;
            if ( process() )
              set_seq(0);
            if ( get_frame_time() || get_frame() != 6 )
              return;
            //shake_camera(8.0);
            /*
            v1521 = 2.0;
            v1403 = 0.0;
            do
            {
              *(float *)&v1519 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1403 * 60.0 - 20.0;
              v1520 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
              if ( *(float *)&v1519 < 0.0 || *(float *)&v1519 > 180.0 )
                field_7D0 = -1;
              else
                field_7D0 = 1;
              v585 = dir;
              v586 = (double)(103 * (char)v585) + x;
              addbullet(this, NULL,816, v586, y, v585, LOBYTE(field_7D0), (int)&v1519, 3);
              v1403 = v1403 + 1.0;
            }
            while ( v1403 < 6.0 );
            v1521 = 3.0;
            v587 = dir;
            v588 = (double)(103 * (char)v587) + x;
            addbullet(this, NULL,816, v588, y, v587, -1, (int)&v1519, 3);
            v1521 = 0.0;
            v589 = (double)(char)skills_1[5] + 7.0;
            v1450 = 0.0;
            v1404 = v589;
            if ( v589 > 0.0 )
            {
              do
              {
                *(float *)&v1519 = -(double)(unsigned int)get_MT_range(80) - 20.0;
                v1520 = (double)(unsigned int)get_MT_range(20) + 10.0;
                if ( *(float *)&v1519 < 0.0 || *(float *)&v1519 > 180.0 )
                  field_7D0 = -1;
                else
                  field_7D0 = 1;
                v590 = dir;
                v591 = (double)(103 * (char)v590) + x;
                addbullet(this, NULL,816, v591, y, v590, 1, (int)&v1519, 3);
                v1450 = v1450 + 1.0;
              }
              while ( v1450 < v1404 );
            }*/
LABEL_1590:
            scene_add_effect(this, 127, x, y, dir, -1);
            play_sfx(18);
            goto LABEL_1616;
          case 530:
            sub10func();
            field_18C = 9;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_3278;
            if ( get_subseq() || get_frame_time() || get_frame() != 7 )
              return;
            field_190 = 1;
            //shake_camera(8.0);
            /*
            v1820 = -80.0;
            v1821 = 25.0;
            a2e = (int *)&v1820;
            v1822 = 0.0;
            xc = dir;
            a4c = y;
            v592 = (double)(100 * dir) + x;
            v593 = v592;
            goto LABEL_1615;
            */
            return; //TODO: change
          case 531:
            sub10func();
            field_18C = 9;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_3278;
            if ( get_subseq() || get_frame_time() || get_frame() != 7 )
              return;
            field_190 = 1;
            //shake_camera(8.0);
            /*
            *(float *)&v1715 = -70.0;
            v1716 = 35.0;
            a2e = &v1715;
            v1717 = 0.0;
            xc = dir;
            a4c = y;
            v594 = (double)(100 * dir) + x;
            v593 = v594;
LABEL_1615:
            v595 = v593;
            addbullet(this, NULL,821, v595, a4c, xc, 1, (int)a2e, 3);
            */
            LABEL_1615:// TODO: change
            scene_add_effect(this, 127, x, y, dir, -1);
            play_sfx(23);
            goto LABEL_1616;
          case 540:
            sub10func();
            field_18C = 2;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_3278;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              /*
              v1795 = 0.0;
              for ( i = 0; i < (char)skills_1[2] + 6; ++i )
              {
                v597 = /*(double)(unsigned int)get_MT_range(50)*//*50.0 * 0.1000000014901161;
                *(float *)&v1793 = v597 + 5.0;
                v1794 = (double)(unsigned int)get_MT_range(14) - 7.0;
                v598 = dir;
                v599 = y + 116.0;
                v600 = v599;
                v601 = (double)(43 * (char)v598) + x;
                addbullet(this, NULL,812, v601, v600, v598, 1, (int)&v1793, 3);
              }
              */
              play_sfx(13);
            }
            return;
          case 541:
            sub10func();
            field_18C = 2;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_3278;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              /*
              v1723 = 2.0;
              for ( j = 0; j < (char)skills_1[2] + 6; ++j )
              {
                *(float *)&v1721 = -/*(double)(unsigned int)get_MT_range(45)*//*45.0 - 10.0;
                v1722 = (double)(unsigned int)(get_MT_range(6) + 6);
                v603 = dir;
                v604 = y + 116.0;
                v605 = v604;
                v606 = (double)(43 * (char)v603) + x;
                addbullet(this, NULL,812, v606, v605, v603, 1, (int)&v1721, 3);
              }
              */
              play_sfx(13);
            }
            return;
          case 542:
            if ( get_subseq() == 1 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1662;
            }
            field_18C = 2;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1873;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() != 6 )
              goto LABEL_1680;
            add_card_energy(50);
            spell_energy_spend(200, 120);
            field_190 = 1;
            /*
            v1828 = 0.0;
            for ( k = 0; k < (char)skills_1[2] + 2; ++k )
            {
              v608 = (double)(unsigned int)get_MT_range(20) * 0.1000000014901161;
              *(float *)&v1826 = v608 + 8.0;
              v1827 = (double)(unsigned int)get_MT_range(14) - 7.0;
              v609 = dir;
              v610 = y + 116.0;
              v611 = v610;
              v612 = (double)(43 * (char)v609) + x;
              addbullet(this, NULL,812, v612, v611, v609, 1, (int)&v1826, 3);
            }
            */
            goto LABEL_1679;
          case 543:
            if ( get_subseq() == 1 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1662:
                reset_forces();
                y = getlvl_height();
                next_subseq();
                return;
              }
            }
            field_18C = 2;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1873;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                add_card_energy(50);
                spell_energy_spend(200, 120);
                field_190 = 1;
                /*
                v1729 = 2.0;
                for ( l = 0; l < (char)skills_1[2] + 2; ++l )
                {
                  *(float *)&v1727 = -(double)(unsigned int)get_MT_range(15) - 30.0;
                  v1728 = (double)(unsigned int)(get_MT_range(3) + 6);
                  v614 = dir;
                  v615 = y + 116.0;
                  v616 = v615;
                  v617 = (double)(43 * (char)v614) + x;
                  addbullet(this, NULL,812, v617, v616, v614, 1, (int)&v1727, 3);
                }
                */
LABEL_1679:
                play_sfx(13);
              }
LABEL_1680:
              if ( !get_frame_time() )
              {
                v479 = get_frame() == 9;
LABEL_1682:
                if ( v479 )
                  v_force = 0.5;
              }
            }
            return;
          case 545:
          case 547:
            field_894 = 1;
            field_18C = 6;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() >= 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1739;
            }
            if ( process() )
              set_seq(9);
            if ( !get_subseq() )
            {
              if ( get_frame() == 2 && get_frame_time() >= 3 && skills_1[6] >= 3 )
                next_frame();
              if ( !get_frame_time() && get_frame() == 3 )
              {
                add_card_energy(50);
                spell_energy_spend(200, 120);
                field_7E4 = /*(double)(unsigned int)get_MT_range(45)*/45.0;
                field_7DC = 10.0;
                dash_angle = 15.0;
                field_190 = 1;
                play_sfx(19);
              }
              if ( get_frame() >= 2 )
              {
                if ( !(get_elaps_frames() % 2) )
                {
                  /*
                  *(float *)&v1799 = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
                  v1800 = /*(double)(unsigned int)get_MT_range(5)*//*5.0 + 5.0;
                  v1801 = 5.0;
                  v618 = dir;
                  v619 = /*(double)(unsigned int)get_MT_range(60)*//*60.0 + y + 30.0;
                  v620 = v619;
                  v621 = /*(double)(unsigned int)get_MT_range(60)*//*60.0 + x - 30.0;
                  addbullet(this, NULL,817, v621, v620, v618, 1, (int)&v1799, 3);
                  */
                }
                if ( get_frame() == 3 )
                {
                  /*
                  v622 = color_A;
                  if ( v622 < 0xFu )
                    color_A = 0;
                  else
                    color_A = v622 - 15;
                    */
                }
              }
            }
            if ( get_subseq() != 1 )
              goto LABEL_1732;
            if ( !(get_elaps_frames() % 2) )
            {
              /*
              *(float *)&v1733 = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
              v1734 = /*(double)(unsigned int)get_MT_range(3)*//*3.0 + 1.0;
              v1735 = 5.0;
              v623 = dir;
              v624 = /*(double)(unsigned int)get_MT_range(60)*//*60.0 + y + 30.0;
              v625 = v624;
              v626 = /*(double)(unsigned int)get_MT_range(60)*//*60.0 + x - 30.0;
              addbullet(this, NULL,817, v626, v625, v623, 1, (int)&v1733, 3);
              */
            }
            ++field_7D2;
            if ( !field_7D0 ) //reversed condition
            {
              field_7DC = field_7DC + dash_angle;
              dash_angle = dash_angle - 0.75;
              if ( dash_angle <= 0.0 )
              {
                dash_angle = 0.0;
                field_7D0 = 1;
              }
            }
            if ( field_7D0 != 1 || (dash_angle = dash_angle + 0.1500000059604645, field_7DC = field_7DC - dash_angle, not_charge_attack) && get_elaps_frames() < 20 * ((char)skills_1[6] + 2) )
            {
              field_7E8 = (double)dX(dir) * ((double)(char)skills_1[6] * 0.05000000074505806) + field_7E8;
              field_7EC = field_7EC - ((double)(char)skills_1[6] * 0.05000000074505806) * (double)dY();
              if ( field_7E8 > 10.0 )
                field_7E8 = 10.0;
              if ( field_7E8 < -10.0 )
                field_7E8 = -10.0;
              if ( field_7EC > 10.0 )
                field_7EC = 10.0;
              if ( field_7EC < -10.0 )
                field_7EC = -10.0;
              h_inerc = field_7E8;
              if ( y < 300.0 || 0.0 >= field_7EC )
                field_7EC = 0.0;
              v_inerc = 0.0;
LABEL_1732:
              if ( get_subseq() == 2 && get_elaps_frames() >= field_7D2 )
                next_subseq();
            }
            else
            {
              //color_A = -1;
              play_sfx(20);
              field_7DC = 0.0;
              next_subseq();
              h_inerc = h_inerc * 0.300000011920929;
              v_inerc = 10.0;
              v_force = 0.5;
              v1451 = 2.0;
              if ( skills_1[6] >= 3 )
                v1451 = 2.5;
              if ( skills_1[6] >= 4 )
                v1451 = 3.0;
              field_7D2 = ((double)field_7D2 / v1451);
            }
            return;
          case 546:
          case 548:
            field_894 = 1;
            field_18C = 6;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() >= 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1739:
                set_seq(10);
                reset_forces();
                y = getlvl_height();
                return;
              }
            }
            if ( process() )
              set_seq(9);
            if ( !get_subseq() )
            {
              if ( get_frame() == 2 && get_frame_time() >= 13 && skills_1[6] >= 3 )
                next_frame();
              if ( !get_frame_time() && get_frame() == 3 )
              {
                add_card_energy(50);
                spell_energy_spend(200, 120);
                field_7E4 = /*(double)(unsigned int)get_MT_range(45)*/45.0;
                field_7DC = 10.0;
                dash_angle = 15.0;
                field_190 = 1;
                play_sfx(19);
              }
              if ( get_frame() >= 2 )
              {
                if ( !(get_elaps_frames() % 2) )
                {
                  float t[3];
                  t[0] = /*(double)(unsigned int)get_MT_range(360)*/360.0;
                  t[1] = /*(double)(unsigned int)get_MT_range(3)*/3.0 + 1.0;
                  t[2] = 5.0;
                  addbullet(this, NULL,817, /*(double)(unsigned int)get_MT_range(60)*/60.0 + x - 30.0, /*(double)(unsigned int)get_MT_range(60)*/60.0 + y + 30.0, dir, 1, t, 3);
                }
                if ( get_frame() == 3 )
                {
                  /*
                  v637 = color_A;
                  if ( v637 < 0xFu )
                    color_A = 0;
                  else
                    color_A = v637 - 15;
                  */
                }
              }
            }
            if ( get_subseq() != 1 )
              goto LABEL_1784;
            if ( !(get_elaps_frames() % 2) )
            {
              float t[3];
              t[0] = /*(double)(unsigned int)get_MT_range(360)*/360.0;
              t[1] = /*(double)(unsigned int)get_MT_range(5)*/5.0 + 5.0;
              t[2] = 5.0;
              addbullet(this, NULL,817, /*(double)(unsigned int)get_MT_range(60)*/60.0 + x - 30.0, /*(double)(unsigned int)get_MT_range(60)*/60.0 + y + 30.0, dir, 1, t, 3);
            }
            ++field_7D2;
            if ( !field_7D0 ) //reversed condition
            {
              field_7DC = field_7DC + dash_angle;
              dash_angle = dash_angle - 0.75;
              if ( dash_angle <= 0.0 )
              {
                dash_angle = 0.0;
                field_7D0 = 1;
              }
            }
            if ( field_7D0 != 1 || (dash_angle = dash_angle + 0.1500000059604645, field_7DC = field_7DC - dash_angle, not_charge_attack) && get_elaps_frames() < 20 * ((char)skills_1[6] + 2) )
            {
              field_7E8 = (double)dX(dir) * ((double)(char)skills_1[6] * 0.01999999955296516 + 0.02999999932944775) + field_7E8;
              field_7EC = field_7EC - ((double)(char)skills_1[6] * 0.01999999955296516 + 0.02999999932944775) * (double)dY();
              if ( field_7E8 > 10.0 )
                field_7E8 = 10.0;
              if ( field_7E8 < -10.0 )
                field_7E8 = -10.0;
              if ( field_7EC > 10.0 )
                field_7EC = 10.0;
              if ( field_7EC < -10.0 )
                field_7EC = -10.0;
              h_inerc = field_7E8;
              if ( y < 300.0 || 0.0 >= field_7EC )
                field_7EC = 0.0;
              v_inerc = 0.0;
LABEL_1784:
              if ( get_subseq() == 2 && get_elaps_frames() >= field_7D2 )
                next_subseq();
            }
            else
            {
              //color_A = -1;
              play_sfx(20);
              field_7DC = 0.0;
              next_subseq();
              v646 = 2;
              h_inerc = h_inerc * 0.300000011920929;
              v_inerc = 10.0;
              v_force = 0.5;
              if ( skills_1[6] >= 3 )
                v646 = 3;
              if ( skills_1[6] >= 4 )
                v646 = 4;
              field_7D2 /= v646;
            }
            return;
          case 550:
            field_18C = 10;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            sub10func();
            if ( field_7D0 > 0 )
            {
              if ( field_7D2 < (skills_1[10] >= 3) + 2 )
              {
                if ( field_7D0 % 5 == 1 )
                {
                  field_7D2 = field_7D2 + 1;
                  play_sfx(26);
                  float t[3];
                  t[0] = 20.0 - /*(double)(unsigned int)get_MT_range(40)*/40.0;
                  t[1] = 5.0;
                  t[2] = 0.0;
                  addbullet(this, NULL,822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                }
                ++field_7D0;
              }
            }
            if ( process() )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_7E4 = /*(double)(unsigned int)get_MT_range(45)*/45.0;
              field_190 = 1;
              field_7D0 = 1;
            }
            return;
          case 551:
            field_18C = 10;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            sub10func();
            if ( field_7D0 > 0 )
            {
              if ( field_7D2 < (skills_1[10] >= 3) + 4 )
              {
                if ( field_7D0 % 5 == 1 )
                {
                  field_7D2 = field_7D2 + 1;
                  play_sfx(26);
                  float t[3];
                  t[0] = 20.0 - /*(double)(unsigned int)get_MT_range(40)*/40.0;
                  t[1] = 5.0;
                  t[2] = 0.0;
                  addbullet(this, NULL,822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                }
                ++field_7D0;
              }
            }
            if ( process() )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_7E4 = /*(double)(unsigned int)get_MT_range(45)*/45.0;
              field_190 = 1;
              field_7D0 = 1;
            }
            return;
          case 560:
            sub10func();
            field_18C = 3;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_3278;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              float t[3];
              t[0] = 7.0;
              t[1] = 6.0;
              t[2] = 0.0;
              addbullet(this, NULL,813, (double)(100 * (char)dir) + x, y + 85.0, dir, -1, t, 3);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(14);
            }
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 3 )
              return;
            /* v1751*/t[0] = 7.0;
            /* v1752*/t[1] = 6.0;
            /* v1753*/t[2] = 3.0;
            addbullet(this, NULL,813, (double)(100 * (char)dir) + x, y + 85.0, dir, -1, t, 3);
            goto LABEL_1938;
          case 561:
            sub10func();
            field_18C = 3;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1014;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              float t[3];
              t[0] = 15.0;
              t[1] = 6.0;
              t[2] = 0.0;
              addbullet(this, NULL,813, (double)(100 * (char)dir) + x, y + 85.0, dir, -1, t, 3);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(14);
            }
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 3 )
              return;
            /* v1757*/t[0] = 15.0;
            /* v1758*/t[1] = 6.0;
            /* v1759*/t[2] = 3.0;
            addbullet(this, NULL,813, (double)(100 * (char)dir) + x, y + 85.0, dir, -1, t, 3);
            goto LABEL_1938;
          case 562:
            if ( get_subseq() == 5 )
              sub10func();
            field_18C = 3;
            v_inerc = v_inerc - v_force;
            if ( getlvl_height() >= (v_inerc + y) && v_inerc < 0.0 && get_subseq() < 5 )
            {
              set_subseq(5);
              v_force = 0.0;
              air_dash_cnt = 0;
              goto LABEL_111;
            }
            if ( get_subseq() < 2 && !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( field_7D0 > 0 )
            {
              if ( get_subseq() == 2 || get_subseq() == 3 )
              {
                if ( field_7D0 % 4 == 1 )
                {
                  add_card_energy(10);
                  field_190 = 1;
                  field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                  if ( field_7D4 < -10 )
                    field_7D4 = -10;
                  if ( field_7D4 > 10 )
                    field_7D4 = 10;
                  play_sfx(9);
                  if ( field_7D8 == 1 )
                  {
                    /*
                    v688 = (double)field_7D4 + 30.0;
                    v1823 = v688 - (double)(MT_getnext() % 0x3Cu);
                    v1824 = 15.0;
                    v1825 = (double)(unsigned int)get_MT_range(4);
                    a2f = (int *)&v1823;
                    */
                  }
                  else
                  {
                    /*
                    v693 = (double)field_7D4 + 30.0;
                    *(float *)&v1763 = v693 - (double)(MT_getnext() % 0x3Cu);
                    v1764 = 15.0;
                    v1765 = (double)(unsigned int)get_MT_range(4);
                    a2f = &v1763;
                    */
                  }
                  //addbullet(this, NULL,808, (double)(44 * (char)dir) + x, y + 85.0, dir, 1, (int)a2f, 3);
                }
                ++field_7D0;
              }
            }
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 5 )
            {
              if ( get_subseq() == 1 && get_elaps_frames() > 4 && (!not_charge_attack || get_elaps_frames() > 25) )
                next_subseq();
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                if ( not_charge_attack == 1 )
                {
                  scene_add_effect(this, 62, x - (double)(23 * (char)dir), y + 107.0, dir, 1);
                }
                float t[3];
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 4.0;
                addbullet(this, NULL,808, x - (double)(23 * (char)dir), y + 107.0, dir, 1, t, 3);
              }
              if ( get_subseq() == 2 && get_frame() == 2 && !get_frame_time() )
              {
                field_7D0 = 1;
                spell_energy_spend(200, 120);
              }
              if ( get_subseq() == 3 )
              {
                if ( (get_elaps_frames() > 10) && !not_charge_attack || get_elaps_frames() > 25 )
                  next_subseq();
              }
              if ( get_subseq() == 4 && !get_frame_time() && get_frame() == 5 )
                v_force = 0.60000002;
            }
            else
            {
LABEL_1873:
              set_seq(9);
            }
            return;
          case 565:
            sub10func();
            field_18C = 7;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_3278;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1914;
            if ( get_frame() == 4 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(40 * (char)dir), y + 70.0, dir, 1);
              return;
            }
            if ( get_frame() == 6 )
            {
              float t[4];
              t[0] = 7.0;
              t[1] = 10.0;
              t[2] = 0.0;
              t[3] = 0.0;
              addbullet(this, NULL,818, (double)(100 * (char)dir) + x,  y + 85.0, dir, 1, t, 4);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(14);
            }
LABEL_1914:
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 3 )
              return;
            /*
            v1863 = 7.0;
            a2g = (int *)&v1863;
            v1864 = 10.0;
            v1865 = 3.0;
            v1866 = 1.0;
            xd = dir;
            v712 = y + 85.0;
            a4d = v712;
            v713 = (double)(100 * dir) + x;
            v714 = v713;
            goto LABEL_1937;
            */
            return; //TODO: change
          case 566:
            sub10func();
            field_18C = 7;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1014;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1933;
            if ( get_frame() == 4 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(40 * (char)dir),  y + 70.0, dir, 1);
            }
            else
            {
              if ( get_frame() == 6 )
              {
                float t[4];
                t[0] = 15.0;
                t[1] = 10.0;
                t[2] = 0.0;
                t[3] = 0.0;
                addbullet(this, NULL,818, (double)(100 * (char)dir) + x, y + 85.0, dir, 1, t, 4);
                spell_energy_spend(200, 120);
                add_card_energy(50);
                play_sfx(14);
              }
LABEL_1933:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
              {
                /*
                *(float *)&v1879 = 15.0;
                a2g = &v1879;
                v1880 = 10.0;
                v1881 = 3.0;
                v1882 = 1.0;
                xd = dir;
                v723 = y + 85.0;
                a4d = v723;
                v724 = (double)(100 * dir) + x;
                v714 = v724;
LABEL_1937:
                v725 = v714;
                addbullet(this, NULL,818, v725, a4d, xd, 1, (int)a2g, 4);
                */
                LABEL_1937://TODO: change
LABEL_1938:
                spell_energy_spend(200, 120);
                add_card_energy(50);
                play_sfx(14);
              }
            }
            return;
          case 570:
            field_18C = 11;
            switch ( get_subseq() )
            {
              case 1:
                if ( !(get_elaps_frames() % 20) )
                {
                  /*
                  v1405 = 0.0;
                  do
                  {
                    *(float *)&v1546 = (double)(unsigned int)get_MT_range(20) + v1405 * 30.0;
                    v1547 = 250.0;
                    v1548 = 2.0;
                    v726 = -*(float *)&v1546;
                    v727 = (1 - 2 * (sin_deg(v726) > 0.0));
                    v728 = dir;
                    v729 = -*(float *)&v1546;
                    v730 = sin_deg(v729);
                    v731 = v730 * v1547 * 0.2000000029802322 + y;
                    v732 = v731;
                    v733 = -*(float *)&v1546;
                    v734 = cos_deg(v733);
                    v735 = v734 * v1547 * (double)dir + x;
                    addbullet(this, NULL,823, v735, v732, v728, v727, (int)&v1546, 3);
                    v1405 = v1405 + 1.0;
                  }
                  while ( v1405 < 12.0 );
                  */
                }
                if ( field_190 != 1 && field_190 != 7 )
                  goto LABEL_1949;
                reset_forces();
                set_subseq(3);
                enemy->reset_forces();
                enemy->angZ = 0.0;
                enemy->x = (h_inerc + 70.0) * (double)dir + x;
                enemy->y = v_inerc + y;
                enemy->set_seq(100);
                return;
              case 4:
              case 5:
                v_inerc = v_inerc - v_force;
                if ( !char_on_ground_down() )
                  goto LABEL_1949;
                reset_forces();
                set_subseq(6);
                y = getlvl_height();
                enemy->set_seq(107);
                enemy->angZ = 180.0;
                enemy->x = (h_inerc + 21.0) * (double)dir + x;
                enemy->y = y + 140.0 + v_inerc;
                return;
              case 7:
              case 8:
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                  goto LABEL_2001;
                goto LABEL_1949;
              default:
LABEL_1949:
                if ( process() )
                  goto LABEL_3278;
                if ( !get_subseq() && get_frame() == 4 && get_frame_time() >= 2 * (8 - (char)skills_1[11]) )
                  goto LABEL_2789;
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  play_sfx(15);
                  float t[3];
                  t[0] = 0.0;
                  t[1] = 7.0;
                  t[2] = 0.0;
                  addbullet(this, NULL,823, x, y + 100.0, dir, -1, t, 3);
                }
                if ( get_subseq() == 1 )
                {
                  enemy->getlvl_height();
                  field_194 = 1;
                  if ( get_elaps_frames() >= 40 )
                    goto LABEL_2868;
                }
                if ( get_elaps_frames() || get_frame_time() || get_frame() )
                {
                  if ( get_subseq() != 3 )
                    goto LABEL_1971;
                  if ( get_frame() )
                  {
                    if ( get_frame() != 1 )
                      goto LABEL_1971;
                    enemy->angZ = 0.0;
                    move_val = 107;
                    enemy->x = (h_inerc + 48.0) * (double)dir + x;
                    v747 = y + 120.0 + v_inerc;
                  }
                  else
                  {
                    enemy->angZ = 0.0;
                    move_val = 100;
                    enemy->x = (h_inerc + 70.0) * (double)dir + x;
                    v747 = v_inerc + y;
                  }
                  enemy->y = v747;
                  enemy->set_seq(move_val);
                }
                else if ( get_subseq() == 3 )
                {
                  set_seq(0);
                  return;
                }
LABEL_1971:
                if ( get_subseq() == 4 )
                {
                  enemy->dir = dir;
                  //sub_4867D0(1, x);
                  //sub_4867F0(1, y);
                  enemy->x = (h_inerc + 45.0) * (double)dir + x;
                  enemy->y = y + 120.0 + v_inerc;
                  enemy->set_seq(107);
                }
                if ( get_subseq() == 5 )
                {
                  //sub_4867D0(1, x);
                  //sub_4867F0(1, y);
                  switch ( /*(_WORD)v1*/ enemy->get_seq() )
                  {
                    case 0:
                      enemy->angZ = -135.0;
                      enemy->x = (h_inerc + 44.0) * (double)dir + x;
                      v754 = y + 128.0 + v_inerc;
                      goto LABEL_1982;
                    case 1:
                      enemy->angZ = -60.0;
                      enemy->x = (h_inerc + 50.0) * (double)dir + x;
                      enemy->y = y + 85.0 + v_inerc;
                      break;
                    case 2:
                      enemy->angZ = -10.0;
                      enemy->x = (h_inerc + 20.0) * (double)dir + x;
                      enemy->y = y + 60.0 + v_inerc;
                      break;
                    case 3:
                      enemy->angZ = 45.0;
                      enemy->x = (h_inerc - 28.0) * (double)dir + x;
                      v754 = y + 50.0 + v_inerc;
                      goto LABEL_1982;
                    case 4:
                      enemy->angZ = 90.0;
                      enemy->x = (h_inerc - 55.0) * (double)dir + x;
                      enemy->y = y + 100.0 + v_inerc;
                      break;
                    case 5:
                      enemy->angZ = 135.0;
                      enemy->x = (h_inerc - 50.0) * (double)dir + x;
                      enemy->y = y + 140.0 + v_inerc;
                      break;
                    case 6:
                      enemy->angZ = 180.0;
                      enemy->x = (h_inerc - 5.0) * (double)dir + x;
                      v754 = y + 150.0 + v_inerc;
LABEL_1982:
                      enemy->y = v754;
                      break;
                    default:
                      break;
                  }
                }
                if ( get_subseq() != 6 )
                  goto LABEL_2045;
                //sub_4867D0(1, x);
                //sub_4867F0(1, y);
                if ( !get_frame_time() && get_frame() == 2 )
                {
                  enemy->dir = -dir;
                  enemy->h_inerc = 0.0;
                  enemy->v_inerc = 0.0;
                  enemy->set_seq(97);
                  play_sfx(51);
                  //shake_camera(20.0);
                  play_sfx(12);
                  enemy->x = (double)(60 * dir) + x;
                  enemy->y = enemy->getlvl_height();
                  sub_464110(((double)((double)(char)skills_1[11] * 0.1000000014901161 + 1500.0) * field_548), 750, 1, 1);
                  scene_add_effect(this, 4, (double)(37 * (char)dir) + x, y + 10.0, dir, 1);
                  enemy->angZ = 0.0;
                  enemy->hit_stop = 44;
                  float t[3];
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 2.0;
                  addbullet(this, NULL,858, (double)(37 * (char)dir) + x, y, dir, -1, t, 3);
                }
                if ( !get_frame() )
                {
                  enemy->set_seq(107);
                  enemy->angZ = 180.0;
                  enemy->x = (h_inerc + 21.0) * (double)dir + x;
                  goto LABEL_2044;
                }
                if ( get_frame() == 1 )
                {
                  enemy->set_seq(107);
                  enemy->angZ = 120.0;
                  enemy->x = (h_inerc + 85.0) * (double)dir + x;
                  enemy->y = y + 85.0 + v_inerc;
                  enemy->dir = -dir;
                }
                break;
            }
            goto LABEL_2045;
          case 571:
            field_18C = 11;
            switch ( get_subseq() )
            {
              case 1:
                if ( !(get_elaps_frames() % 20) )
                {
                  /*
                  v1406 = 0.0;
                  do
                  {
                    *(float *)&v1552 = (double)(unsigned int)get_MT_range(20) + v1406 * 30.0;
                    v1553 = 250.0;
                    v1554 = 2.0;
                    v779 = -*(float *)&v1552;
                    v780 = (1 - 2 * (sin_deg(v779) > 0.0));
                    v781 = dir;
                    v782 = -*(float *)&v1552;
                    v783 = sin_deg(v782);
                    v784 = v783 * v1553 * 0.2000000029802322 + y;
                    v785 = v784;
                    v786 = -*(float *)&v1552;
                    v787 = cos_deg(v786);
                    v788 = v787 * v1553 * (double)dir + x;
                    addbullet(this, NULL,823, v788, v785, v781, v780, (int)&v1552, 3);
                    v1406 = v1406 + 1.0;
                  }
                  while ( v1406 < 12.0 );
                  */
                }
                if ( field_190 != 1 && field_190 != 7 )
                  goto LABEL_2002;
                reset_forces();
                set_subseq(3);
                enemy->reset_forces();
                enemy->angZ = 0.0;
                enemy->x = (h_inerc + 70.0) * (double)dir + x;
                enemy->y = v_inerc + y;
                enemy->set_seq(100);
                return;
              case 4:
              case 5:
                v_inerc = v_inerc - v_force;
                if ( !char_on_ground_down() )
                  goto LABEL_2002;
                reset_forces();
                set_subseq(6);
                y = getlvl_height();
                enemy->set_seq(107);
                enemy->angZ = 180.0;
                enemy->x = (h_inerc + 21.0) * (double)dir + x;
                enemy->y = y + 140.0 + v_inerc;
                return;
              case 7:
              case 8:
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                  goto LABEL_2001;
                goto LABEL_2002;
              default:
LABEL_2002:
                if ( process() )
                  goto LABEL_3278;
                if ( !get_subseq() && get_frame() == 4 && get_frame_time() >= 27 - 2 * (char)skills_1[11] )
                  goto LABEL_2789;
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  play_sfx(15);
                  float t[3];
                  t[0] = 0.0;
                  t[1] = (double)(char)skills_1[11] * 1.25 + 9.0;
                  t[2] = 0.0;
                  addbullet(this, NULL,823, x, y + 100.0, dir, -1, t, 3);
                }
                if ( get_subseq() == 1 )
                {
                  getlvl_height(enemy->y);
                  field_194 = 1;
                  if ( get_elaps_frames() >= 40 )
                    goto LABEL_2868;
                }
                if ( get_elaps_frames() || get_frame_time() || get_frame() )
                {
                  if ( get_subseq() != 3 )
                    goto LABEL_2024;
                  if ( get_frame() )
                  {
                    if ( get_frame() != 1 )
                      goto LABEL_2024;
                    enemy->angZ = 0.0;
                    move_vala = 107;
                    enemy->x = (h_inerc + 48.0) * (double)dir + x;
                    enemy->y = y + 120.0 + v_inerc;
                  }
                  else
                  {
                    enemy->angZ = 0.0;
                    move_vala = 100;
                    enemy->x = (h_inerc + 70.0) * (double)dir + x;
                    enemy->y = v_inerc + y;
                  }
                  
                  enemy->set_seq(move_vala);
                }
                else if ( get_subseq() == 3 )
                {
                  set_seq(0);
                  return;
                }
LABEL_2024:
                if ( get_subseq() == 4 )
                {
                  enemy->dir = dir;
                  //sub_4867D0(1, x);
                  //sub_4867F0(1, y);
                  enemy->x = (h_inerc + 45.0) * (double)dir + x;
                  enemy->y = y + 120.0 + v_inerc;
                  enemy->set_seq(107);
                }
                if ( get_subseq() == 5 )
                {
                  //sub_4867D0(1, x);
                  //sub_4867F0(1, y);
                  switch ( /*(_WORD)v1*/ enemy->get_seq() )
                  {
                    case 0:
                      enemy->angZ = -135.0;
                      enemy->x = (h_inerc + 44.0) * (double)dir + x;
                      v807 = y + 128.0 + v_inerc;
                      goto LABEL_2035;
                    case 1:
                      enemy->angZ = -60.0;
                      enemy->x = (h_inerc + 50.0) * (double)dir + x;
                      enemy->y = y + 85.0 + v_inerc;
                      break;
                    case 2:
                      enemy->angZ = -10.0;
                      enemy->x = (h_inerc + 20.0) * (double)dir + x;
                      enemy->y = y + 60.0 + v_inerc;
                      break;
                    case 3:
                      enemy->angZ = 45.0;
                      enemy->x = (h_inerc - 28.0) * (double)dir + x;
                      v807 = y + 50.0 + v_inerc;
                      goto LABEL_2035;
                    case 4:
                      enemy->angZ = 90.0;
                      enemy->x = (h_inerc - 55.0) * (double)dir + x;
                      enemy->y = y + 100.0 + v_inerc;
                      break;
                    case 5:
                      enemy->angZ = 135.0;
                      enemy->x = (h_inerc - 50.0) * (double)dir + x;
                      enemy->y = y + 140.0 + v_inerc;
                      break;
                    case 6:
                      enemy->angZ = 180.0;
                      enemy->x = (h_inerc - 5.0) * (double)dir + x;
                      v807 = y + 150.0 + v_inerc;
LABEL_2035:
                      enemy->y = v807;
                      break;
                    default:
                      break;
                  }
                }
                if ( get_subseq() == 6 )
                {
                  //sub_4867D0(1, x);
                  //sub_4867F0(1, y);
                  if ( !get_frame_time() && get_frame() == 2 )
                  {
                    enemy->dir = -dir;
                    enemy->h_inerc = 0.0;
                    enemy->v_inerc = 0.0;
                    enemy->set_seq(97);
                    play_sfx(51);
                    //shake_camera(20.0);
                    play_sfx(12);
                    enemy->x = (double)(60 * dir) + x;
                    enemy->y = enemy->getlvl_height();
                    sub_464110(((double)((double)(char)skills_1[11] * 0.1000000014901161 + 1500.0) * field_548), 750, 1, 1);
                    scene_add_effect(this, 4, (double)(37 * (char)dir) + x, y + 10.0, dir, 1);
                    enemy->angZ = 0.0;
                    enemy->hit_stop = 44;
                    float t[3];
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 2.0;
                    addbullet(this, NULL,858, (double)(37 * (char)dir) + x, y, dir, -1, t, 3);
                  }
                  if ( get_frame() )
                  {
                    if ( get_frame() == 1 )
                    {
                      enemy->set_seq(107);
                      enemy->angZ = 120.0;
                      enemy->x = (h_inerc + 85.0) * (double)dir + x;
                      enemy->y = y + 85.0 + v_inerc;
                      enemy->dir = -dir;
                    }
                  }
                  else
                  {
                    enemy->set_seq(107);
                    enemy->angZ = 180.0;
                    enemy->x = (h_inerc + 21.0) * (double)dir + x;
LABEL_2044:
                    enemy->y = y + 140.0 + v_inerc;
                  }
                }
                break;
            }
LABEL_2045:
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
              {
                h_inerc = 2.0;
                v_inerc = 25.0;
                v_force = 0.85000002;
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 7 )
              {
                h_inerc = -10.0;
                v_inerc = 7.0;
                v_force = 0.5;
                //sub_4867D0(0, x);
                //sub_4867F0(0, y);
                enemy->hit_stop = 0;
              }
            }
            return;
          case 599:
            if ( field_7D0 > 0 && get_frame() < 7 && field_7D0 < 12 )
            {
              /*
              v832 = MT_getnext() % 0x23u;
              field_7D4 = v832;
              *(float *)&v1567 = (double)(-20 - v832);
              v1568 = (double)(MT_getnext() % 5u + 10);
              v1569 = 0.0;
              v833 = dir;
              v834 = (double)(20 * (char)v833 * (field_7D0 + 1)) + x;
              addbullet(this, NULL,807, v834, y, v833, 1, (int)&v1567, 3);
              *(float *)&v1567 = (double)(MT_getnext() % 0x168u);
              v1568 = 0.0;
              v1569 = 1.0;
              v835 = dir;
              v836 = (double)(20 * (char)v835 * (field_7D0 + 1)) + x;
              addbullet(this, NULL,801, v836, y, v835, 1, (int)&v1567, 3);
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
            if ( !get_subseq() || get_subseq() == 5 )
              sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() == 2 )
            {
              v_inerc = v_inerc - 0.4000000059604645;
              if ( v_inerc < 1.0 )
                v_inerc = 1.0;
              if ( ++field_7D0 >= 60 )
                goto LABEL_3151;
            }
            if ( get_subseq() == 3 || get_subseq() == 4 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_subseq(5);
                goto LABEL_111;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 100.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL,850, x, y + 100.0, dir, 1, t, 3);
              play_sfx(50);
              v_inerc = 10.0;
            }
            if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 2 )
            {
              v_inerc = 6.0;
              h_inerc = -8.0;
              v_force = 0.5;
            }
            return;
          case 601:
            if ( get_subseq() <= 2 )
              sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() != 2 )
              goto LABEL_2101;
            if ( field_190 == 1 )
            {
              if ( x > 750.0 && dir == 1 )
                x = 750.0;
              if ( x < 550.0 && dir == -1 )
                x = 550.0;
              next_subseq();
              enemy->set_seq(102);
              enemy->x = (double)(510 * dir) + x;
              enemy->y = y;
              enemy->reset_forces();
            }
            else
            {
              if ( sub10func() )
              {
                enemy->field_1A4 = 0.0;
                enemy->field_1A8 = 0.0;
                enemy->set_seq(53);
              }
LABEL_2101:
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                set_seq(0);
              if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(50 * (char)dir) + x, y + 160.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( get_subseq() == 3 && !get_frame_time() )
              {
                if ( get_frame() == 2 )
                {
                  //shake_camera(5.0);
                  enemy->x = (double)(470 * dir) + x;
                  float t[3];
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  addbullet(this, NULL,851, x, y, dir, 1, t, 3);
                  play_sfx(55);
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 3 )
                  {
                    enemy->x = (double)(450 * dir) + x;
                  }
                  if ( !get_frame_time() )
                  {
                    if ( get_frame() == 4 )
                    {
                      enemy->x = (double)(400 * dir) + x;
                    }
                    if ( !get_frame_time() )
                    {
                      if ( get_frame() == 5 )
                      {
                        enemy->x = (double)(330 * dir) + x;
                      }
                      if ( !get_frame_time() && get_frame() == 6 )
                      {
                        //crash_spell_borders(enemy, 1);
                        if ( enemy->health <= 0 )
                          goto LABEL_2273;
                        enemy->set_seq(53);
                        enemy->dir = dir;
                      }
                    }
                  }
                }
              }
            }
            return;
          case 602:
            if ( get_frame() == 19 )
              sub10func();
            sub_46AB50(5, 2);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(20 * (char)dir) + x, y + 50.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( get_frame() >= 6 && get_frame() <= 17 )
            {
              x_off = 0.0;
              y_off = 0.0;
              scaleX = 2.0 - field_7DC;
              scaleY = 2.0 - field_7DC;
              field_7DC = field_7DC * 0.75;
            }
            if ( get_frame() == 18 )
            {
              scaleX = scaleX - 0.1000000014901161;
              if ( scaleX < 1.0 )
                scaleX = 1.0;
              scaleY = scaleX;
            }
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                float t[3];
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL,852, x, y, dir, -1, t, 3);
                /*
                v1407 = 0.0;
                do
                {
                  *(float *)&v1534 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1407 * 45.0 - 20.0;
                  v1535 = 30.0;
                  v1536 = 1.0;
                  if ( *(float *)&v1534 < 0.0 || *(float *)&v1534 > 180.0 )
                    field_7D0 = -1;
                  else
                    field_7D0 = 1;
                  v859 = dir;
                  v860 = (double)(40 * (char)v859) + x;
                  addbullet(this, NULL,811, v860, y, v859, LOBYTE(field_7D0), (int)&v1534, 3);
                  v1407 = v1407 + 1.0;
                }
                while ( v1407 < 8.0 );
                */
                play_sfx(53);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 18 )
                  play_sfx(54);
                if ( !get_frame_time() && get_frame() == 19 )
                {
                  scaleX = 1.0;
                  scaleY = 1.0;
                }
              }
            }
            return;
          case 603:
            if ( !get_subseq() || get_subseq() == 7 )
              sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() != 1 && get_subseq() != 2 )
              goto LABEL_2172;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_subseq(7);
              y = getlvl_height();
              v_inerc = 0.0;
              v_force = 0.0;
              return;
            }
            if ( get_subseq() == 2 )
            {
              if ( field_190 == 1 || field_190 == 7 )
              {
                reset_forces();
                next_subseq();
                enemy->reset_forces();
                enemy->set_seq(107);
                enemy->x = (h_inerc + 45.0) * (double)dir + x;
                enemy->y = y + 120.0 + v_inerc;
                return;
              }
            }
LABEL_2172:
            if ( get_subseq() == 3 )
            {
              v_inerc = v_inerc - v_force;
              if ( v_inerc < 1.0 )
                v_inerc = 1.0;
              //sub_4867D0(1, x);
              //sub_4867F0(1, y);
              enemy->x = (h_inerc + 45.0) * (double)dir + x;
              enemy->y = y + 120.0 + v_inerc;
            }
            if ( get_subseq() != 4 )
              goto LABEL_2179;
            //sub_4867D0(1, x);
            //sub_4867F0(1, y);
            if ( field_7D0 >= 120 )
              goto LABEL_3151;
            field_7D0 = field_7D0 + 1;
            enemy->dir = dir;
LABEL_2179:
            if ( get_subseq() == 5 && get_frame() >= 4 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
            {
              set_subseq(7);
            }
            else
            {
              if ( get_subseq() != 6 || (v_inerc = v_inerc - v_force, !char_on_ground_down()) )
              {
                if ( get_subseq() == 7 )
                {
                  h_inerc = h_inerc - 0.75;
                  if ( h_inerc < 0.0 )
                    h_inerc = 0.0;
                }
                if ( process() )
                  set_seq(0);
                if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
                {
                  sub_4834E0(40);
                  scene_play_sfx(23);
                  scene_add_effect(this, 115, x, y + 100.0, dir, 1);
                  sub_469450(0, 0, 60);
                  sub_483570();
                  weather_forecast_next();
                }
                if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 2 )
                {
                  v_inerc = 12.5;
                  v_force = 0.5;
                }
                if ( get_subseq() == 4 )
                {
                  switch ( /*(_WORD)v1*/ enemy->get_seq() )
                  {
                    case 0:
                      enemy->angZ = -135.0;
                      enemy->x = (double)(44 * dir) + x;
                      enemy->y = y + 128.0;
                      break;
                    case 1:
                      enemy->angZ = -60.0;
                      enemy->x = (double)(50 * dir) + x;
                      v876 = y + 85.0;
                      goto LABEL_2207;
                    case 2:
                      enemy->angZ = -10.0;
                      enemy->x = (double)(20 * dir) + x;
                      enemy->y = y + 60.0;
                      break;
                    case 3:
                      enemy->angZ = 45.0;
                      enemy->x = x - (double)(28 * dir);
                      v876 = y + 50.0;
                      goto LABEL_2207;
                    case 4:
                      enemy->angZ = 90.0;
                      enemy->x = x - (double)(55 * dir);
                      enemy->y = y + 100.0;
                      break;
                    case 5:
                      enemy->angZ = 135.0;
                      enemy->x = x - (double)(50 * dir);
                      enemy->y = y + 140.0;
                      break;
                    case 6:
                      enemy->angZ = 180.0;
                      enemy->x = x - (double)(5 * dir);
                      v876 = y + 150.0;
LABEL_2207:
                      enemy->y = v876;
                      break;
                    default:
                      break;
                  }
                }
                if ( get_subseq() == 5 )
                {
                  if ( !get_frame_time() )
                  {
                    if ( get_frame() == 2 )
                    {
                      //sub_4867D0(0, x);
                      //sub_4867F0(0, y);
                      enemy->dir = -dir;
                      enemy->field_1A4 = 36.0;
                      enemy->field_1A8 = -18.0;
                      enemy->set_seq(88);
                      v_inerc = 6.0;
                      h_inerc = -6.0;
                      v_force = 0.75;
                      play_sfx(51);
                    }
                    if ( !get_frame_time() && get_frame() == 4 )
                      v_force = 0.5;
                  }
                  if ( get_frame() )
                  {
                    if ( get_frame() == 1 )
                    {
                      enemy->angZ = 120.0;
                      enemy->x = (double)(85 * dir) + x;
                      enemy->y = y + 85.0;
                      enemy->dir = -dir;
                    }
                  }
                  else
                  {
                    enemy->angZ = 180.0;
                    enemy->x = (double)(21 * dir) + x;
                    enemy->y = y + 140.0;
                  }
                }
                if ( !get_elaps_frames() )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  {
                    h_inerc = 10.0;
                    v_inerc = 10.0;
                    v_force = 0.60000002;
                  }
                  if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
                  {
                    play_sfx(50);
                    float t[3];
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 0.0;
                    addbullet(this, NULL,853, (double)(20 * (char)dir) + x, y + 50.0, dir, 1, t, 3);
                  }
                }
                return;
              }
LABEL_108:
LABEL_109:
LABEL_110:
              set_seq(10);
            }
LABEL_111:
            y = getlvl_height();
            reset_forces();
            return;
          case 604:
            if ( get_subseq() <= 2 )
              sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() != 2 )
              goto LABEL_2242;
            if ( field_190 == 1 )
            {
              if ( x > 750.0 && dir == 1 )
                x = 750.0;
              if ( x < 550.0 && dir == -1 )
                x = 550.0;
              next_subseq();
              enemy->x = (double)(510 * dir) + x;
              enemy->y = y;
              enemy->reset_forces();
              enemy->set_seq(102);
              return;
            }
            if ( sub10func() )
            {
              enemy->field_1A4 = 0.0;
              enemy->field_1A8 = 0.0;
              enemy->set_seq(53);
            }
LABEL_2242:
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(50 * (char)dir) + x, y + 160.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( get_subseq() != 3 )
              return;
            if ( get_frame_time() )
              goto LABEL_2257;
            if ( get_frame() == 2 )
            {
              //shake_camera(5.0);
              enemy->x = (double)(470 * dir) + x;
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL,854, x, y, dir, 1, t, 3);
              play_sfx(55);
LABEL_2257:
              if ( get_frame() == 2 && !(get_elaps_frames() % 4) )
              {
                float t[3];
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                addbullet(this, NULL,854, enemy->x,  enemy->y + 100.0, dir, 1, t, 3);
              }
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                enemy->x = (double)(450 * dir) + x;
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 4 )
                {
                  enemy->x = (double)(400 * dir) + x;
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 5 )
                  {
                    enemy->x = (double)(330 * dir) + x;
                  }
                  if ( !get_frame_time() && get_frame() == 6 )
                  {
                    field_890 = 600;
                    if ( enemy->health <= 0 )
                    {
LABEL_2273:
                      enemy->field_1A4 = -5.0;
                      enemy->field_1A8 = 12.0;
                      enemy->set_seq(77);
                      enemy->dir = -dir;
                    }
                    else
                    {
                      enemy->set_seq(53);
                      enemy->dir = dir;
                    }
                  }
                }
              }
            }
            return;
          case 605:
            sub_46AB50(5, 2);
            switch ( get_subseq() )
            {
              case 0:
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
                {
                  sub_4834E0(40);
                  scene_play_sfx(23);
                  scene_add_effect(this, 115, (double)(20 * (char)dir) + x, y + 50.0, dir, 1);
                  weather_forecast_next();
                  sub_469450(0, 0, 60);
                  sub_483570();
                }
                if ( get_frame() >= 6 && get_frame() <= 15 )
                {
                  x_off = 0.0;
                  y_off = 0.0;
                  scaleX = 3.0 - field_7DC;
                  scaleY = 3.0 - field_7DC;
                  field_7DC = field_7DC * 0.75;
                }
                if ( get_frame() == 3 && !get_frame_time() )
                {
                  field_194 = 1;
                  field_190 = 0;
                }
                goto LABEL_2286;
              case 1:
                h_inerc = 0.0;
                if ( getlvl_height() + 10.0 <= y )
                  goto LABEL_2961;
                y = getlvl_height();
                if ( field_892 <= 0 )
                {
                  set_subseq(14);
                  play_sfx(54);
                  return;
                }
                if ( dY() <= 0 )
                {
                  if ( keyUp(INP_A) && keyUp(INP_A) < 3 || keyDown(INP_A) == 2 || keyHit(INP_A) )
                  {
                    field_892 = field_892 - 45;
                    set_subseq(7);
                    return;
                  }
                  if ( keyUp(INP_B) && keyUp(INP_B) < 3 || keyDown(INP_B) == 2 || keyHit(INP_B) )
                  {
                    field_892 = field_892 - 45;
                    set_subseq(8);
                    return;
                  }
                  if ( keyUp(INP_C) && keyUp(INP_C) < 3 || keyDown(INP_C) == 2 || keyHit(INP_C) )
                  {
                    field_892 = field_892 - 45;
                    set_subseq(9);
                    return;
                  }
                }
                else if ( keyUp(INP_A) && keyUp(INP_A) < 3 || keyDown(INP_A) == 2 || keyHit(INP_A) || (keyUp(INP_B)) != 0 && keyUp(INP_B) < 3 || keyDown(INP_B) == 2 || keyHit(INP_B) || (keyUp(INP_C)) != 0 && keyUp(INP_C) < 3 || keyDown(INP_C) == 2 || keyHit(INP_C) )
                {
                  field_892 = field_892 - 45;
                  set_subseq(15);
                  return;
                }
                if ( keyDown(INP_X_AXIS) > 0 )
                {
                  dir = 1;
                  h_inerc = 4.0;
                  set_subseq(2);
                  return;
                }
                if ( keyDown(INP_X_AXIS) < 0 )
                {
                  dir = -1;
                  h_inerc = 4.0;
                  set_subseq(2);
                  return;
                }
                if ( dY() >= 0 )
                  goto LABEL_2286;
                h_inerc = 0.0;
                v_inerc = 0.0;
                field_7DC = 0.0;
                if ( dX(dir) > 0 )
                  field_7DC = 1.0;
                if ( dX(dir) < 0 )
                  field_7DC = -1.0;
                set_subseq(3);
                return;
              case 2:
                h_inerc = 0.0;
                if ( getlvl_height() + 10.0 <= y )
                {
                  v_inerc = 0.0;
                  set_subseq(5);
                  return;
                }
                y = getlvl_height();
                if ( !field_892 )
                {
                  set_subseq(14);
                  play_sfx(54);
                  return;
                }
                if ( !get_frame_time() && get_frame() == 6 )
                {
                  field_190 = 0;
                  field_194 = 1;
                }
                if ( keyUp(INP_A) && keyUp(INP_A) < 3 || keyDown(INP_A) == 2 || keyHit(INP_A) )
                {
                  move_valb = 7;
                  goto LABEL_2390;
                }
                if ( keyUp(INP_B) && keyUp(INP_B) < 3 || keyDown(INP_B) == 2 || keyHit(INP_B) )
                {
                  move_valb = 8;
                  goto LABEL_2390;
                }
                if ( keyUp(INP_C) && keyUp(INP_C) < 3 || keyDown(INP_C) == 2 || keyHit(INP_C) )
                {
                  move_valb = 9;
                  goto LABEL_2390;
                }
                if ( !keyDown(INP_X_AXIS) )
                {
                  h_inerc = 0.0;
                  set_subseq(1);
                  return;
                }
                if ( keyDown(INP_X_AXIS) > 0 )
                {
                  dir = 1;
                  h_inerc = 4.0;
                }
                if ( keyDown(INP_X_AXIS) < 0 )
                {
                  dir = -1;
                  h_inerc = 4.0;
                }
                if ( dY() >= 0 )
                  goto LABEL_2286;
                field_7DC = 0.0;
                h_inerc = 0.0;
                v_inerc = 0.0;
                if ( keyDown(INP_X_AXIS) )
                {
                  field_7DC = 1.0;
                  if ( keyDown(INP_X_AXIS) > 0 )
                  {
                    dir = 1;
                  }
                  if ( keyDown(INP_X_AXIS) < 0 )
                    dir = -1;
                }
                goto LABEL_2365;
              case 4:
              case 5:
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                {
                  reset_forces();
                  y = getlvl_height();
                  set_subseq(6);
                  play_sfx(56);
                  //shake_camera(4.0);
                  /*
                  v1408 = 0.0;
                  do
                  {
                    *(float *)&v1592 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1408 * 45.0 - 20.0;
                    v1593 = 30.0;
                    v1594 = 2.0;
                    if ( *(float *)&v1592 < 0.0 || *(float *)&v1592 > 180.0 )
                      field_7D0 = -1;
                    else
                      field_7D0 = 1;
                    addbullet(this, NULL,855, x, y, dir, LOBYTE(field_7D0), (int)&v1592, 3);
                    v1408 = v1408 + 1.0;
                  }
                  while ( v1408 < 8.0 );
                  */
                  return;
                }
                if ( keyUp(INP_A) && keyUp(INP_A) < 3 || keyDown(INP_A) == 2 || keyHit(INP_A) )
                {
                  move_valb = 10;
LABEL_2390:
                  field_892 -= 45;
                  set_subseq(move_valb);
                  field_194 = 1;
LABEL_2391:
                  field_190 = 0;
                  return;
                }
                if ( keyUp(INP_B) && keyUp(INP_B) < 3 || keyDown(INP_B) == 2 || keyHit(INP_B) )
                {
                  field_892 -= 45;
                  set_subseq(12);
                  field_194 = 1;
                  field_190 = 0;
                  v_inerc = 5.0;
                  v_force = 0.44999999;
                  return;
                }
                if ( keyUp(INP_C) && keyUp(INP_C) < 3 || keyDown(INP_C) == 2 || keyHit(INP_C) )
                {
                  move_valb = 16;
                  goto LABEL_2390;
                }
LABEL_2286:
                if ( process() )
                  goto LABEL_3014;
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  scaleX = 1.0;
                  scaleY = 1.0;
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
                {
                  v_inerc = 10.0;
                  v_force = 0.30000001;
                  h_inerc = field_7DC * 5.0;
                  /*
                  v1410 = 0.0;
                  do
                  {
                    *(float *)&v1598 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1410 * 45.0 - 20.0;
                    v1599 = 30.0;
                    v1600 = 2.0;
                    if ( *(float *)&v1598 < 0.0 || *(float *)&v1598 > 180.0 )
                      field_7D0 = -1;
                    else
                      field_7D0 = 1;
                    addbullet(this, NULL,855, x, y, dir, LOBYTE(field_7D0), (int)&v1598, 3);
                    v1410 = v1410 + 1.0;
                  }
                  while ( v1410 < 8.0 );
                  */
                }
                if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 7 || !get_frame_time() && !get_frame() && get_subseq() == 8 || !get_frame_time() && !get_frame() && get_subseq() == 9) )
                  goto LABEL_3014;
                if ( get_elaps_frames() )
                  goto LABEL_2456;
                if ( (get_frame_time() || get_frame() || get_subseq() != 10) && (get_frame_time() || get_frame() || get_subseq() != 12) && (get_frame_time() || get_frame() || get_subseq() != 14) )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 15 )
                  {
                    set_seq(get_elaps_frames());
                    scaleX = 1.0;
                    scaleY = 1.0;
                  }
LABEL_2456:
                  if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 16 )
                  {
                    switch ( get_subseq() )
                    {
                      case 0:
                        if ( get_frame() >= 6 )
                          field_892 = 480;
                        if ( !get_frame_time() )
                        {
                          if ( get_frame() == 6 )
                          {
                            float t[3];
                            t[0] = 0.0;
                            t[1] = 0.0;
                            t[2] = 0.0;
                            addbullet(this, NULL,855, x, y, dir, -1, t, 3);
                            /*
                            v1411 = 0.0;
                            do
                            {
                              *(float *)&v1543 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1411 * 45.0 - 20.0;
                              v1544 = 30.0;
                              v1545 = 2.0;
                              if ( *(float *)&v1543 < 0.0 || *(float *)&v1543 > 180.0 )
                                field_7D0 = -1;
                              else
                                field_7D0 = 1;
                              v947 = dir;
                              v948 = (double)(40 * (char)v947) + x;
                              addbullet(this, NULL,855, v948, y, v947, LOBYTE(field_7D0), (int)&v1543, 3);
                              v1411 = v1411 + 1.0;
                            }
                            while ( v1411 < 8.0 );
                            */
                            play_sfx(53);
                          }
                          if ( !get_frame_time() )
                          {
                            goto LABEL_2474;
                          }
                        }
                        break;
                      case 1:
                        if ( !get_frame_time() && get_frame() == 3 )
                        {
                          field_194 = 1;
                          field_190 = 0;
                        }
                        break;
                      case 2:
                        if ( !get_frame_time() && get_frame() == 3 )
                        {
                          play_sfx(56);
                          //shake_camera(2.0);
                          /*
                          v1412 = 0.0;
                          do
                          {
                            *(float *)&v1628 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1412 * 60.0 - 20.0;
                            v1629 = 20.0;
                            v1630 = 2.0;
                            if ( *(float *)&v1628 < 0.0 || *(float *)&v1628 > 180.0 )
                              field_7D0 = -1;
                            else
                              field_7D0 = 1;
                            v950 = dir;
                            v951 = (double)(70 * (char)v950) + x;
                            addbullet(this, NULL,855, v951, y, v950, LOBYTE(field_7D0), (int)&v1628, 3);
                            v1412 = v1412 + 1.0;
                          }
                          while ( v1412 < 6.0 );
                          */
                        }
                        if ( !get_frame_time() && get_frame() == 7 )
                        {
                          play_sfx(56);
                          //shake_camera(2.0);
                          /*
                          v1413 = 0.0;
                          do
                          {
                            *(float *)&v1604 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1413 * 60.0 - 20.0;
                            v1605 = 20.0;
                            v1606 = 2.0;
                            if ( *(float *)&v1604 < 0.0 || *(float *)&v1604 > 180.0 )
                              field_7D0 = -1;
                            else
                              field_7D0 = 1;
                            v952 = dir;
                            v953 = (double)(70 * (char)v952) + x;
                            addbullet(this, NULL,855, v953, y, v952, LOBYTE(field_7D0), (int)&v1604, 3);
                            v1413 = v1413 + 1.0;
                          }
                          while ( v1413 < 6.0 );
                          */
                        }
                        break;
                      case 3:
                        if ( !get_frame_time() && get_frame() == 4 )
                        {
                          field_190 = 0;
                          field_194 = 1;
                        }
                        break;
                      case 7:
                        if ( !get_frame_time() && get_frame() == 10 )
                        {
                          field_194 = 1;
                          field_190 = 0;
                          play_sfx(57);
                          //shake_camera(10.0);
                          /*
                          v1414 = 0.0;
                          do
                          {
                            *(float *)&v1652 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1414 * 45.0 - 20.0;
                            v1653 = 30.0;
                            v1654 = 2.0;
                            if ( *(float *)&v1652 < 0.0 || *(float *)&v1652 > 180.0 )
                              field_7D0 = -1;
                            else
                              field_7D0 = 1;
                            v954 = dir;
                            v955 = (double)(420 * (char)v954) + x;
                            addbullet(this, NULL,855, v955, y, v954, LOBYTE(field_7D0), (int)&v1652, 3);
                            v1414 = v1414 + 1.0;
                          }
                          while ( v1414 < 8.0 );
                          */
                        }
                        break;
                      case 8:
                        if ( !get_frame_time() && get_frame() == 6 )
                        {
                          field_194 = 1;
                          field_190 = 0;
                          play_sfx(58);
                          //shake_camera(10.0);
                          /*
                          v1415 = 0.0;
                          do
                          {
                            *(float *)&v1586 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1415 * 45.0 - 20.0;
                            v1587 = 30.0;
                            v1588 = 2.0;
                            if ( *(float *)&v1586 < 0.0 || *(float *)&v1586 > 180.0 )
                              field_7D0 = -1;
                            else
                              field_7D0 = 1;
                            v956 = dir;
                            v957 = (double)(310 * (char)v956) + x;
                            addbullet(this, NULL,855, v957, y, v956, LOBYTE(field_7D0), (int)&v1586, 3);
                            v1415 = v1415 + 1.0;
                          }
                          while ( v1415 < 8.0 );
                          */
                        }
                        break;
                      case 9:
                        if ( !get_frame_time() && get_frame() == 7 )
                        {
                          field_194 = 1;
                          field_190 = 0;
                          play_sfx(57);
                          //shake_camera(10.0);
                          /*
                          v1416 = 0.0;
                          do
                          {
                            *(float *)&v1570 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1416 * 45.0 - 20.0;
                            v1571 = 30.0;
                            v1572 = 2.0;
                            if ( *(float *)&v1570 < 0.0 || *(float *)&v1570 > 180.0 )
                              field_7D0 = -1;
                            else
                              field_7D0 = 1;
                            v958 = dir;
                            v959 = (double)(240 * (char)v958) + x;
                            addbullet(this, NULL,855, v959, y, v958, LOBYTE(field_7D0), (int)&v1570, 3);
                            v1416 = v1416 + 1.0;
                          }
                          while ( v1416 < 8.0 );
                          *(float *)&v1570 = -65.0;
                          v1571 = 20.0;
                          v1572 = 5.0;
                          v1573 = 180.0;
                          v960 = dir;
                          v961 = y + 460.0;
                          v962 = v961;
                          v963 = (double)(250 * (char)v960) + x;
                          addbullet(this, NULL,855, v963, v962, v960, 1, (int)&v1570, 4);
                          */
                        }
                        break;
                      case 10:
                        if ( !get_frame_time() && get_frame() == 4 )
                        {
                          field_194 = 1;
                          field_190 = 0;
                          play_sfx(57);
                        }
                        break;
                      case 15:
                        if ( !get_frame_time() && get_frame() == 7 )
                        {
                          play_sfx(58);
                          //shake_camera(10.0);
                          float t[3];
                          t[0] = 0.0;
                          t[1] = 7.0;
                          t[2] = 3.0;
                          addbullet(this, NULL,855, (double)(210 * dir) + x, y, dir, 1, t, 3);
                        }
                        break;
                      case 16:
                        if ( !get_frame_time() && get_frame() == 3 )
                        {
                          field_194 = 1;
                          field_190 = 0;
                          v_inerc = 12.0;
                          v_force = 0.30000001;
                          h_inerc = h_inerc + 4.0;
                          if ( h_inerc > 5.0 )
                            h_inerc = 5.0;
                          play_sfx(57);
                        }
                        break;
                      default:
                        return;
                    }
                    return;
                  }
                }
LABEL_3014:
                set_subseq(1);
                return;
              case 6:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2286;
                reset_forces();
                set_subseq(5);
                return;
              case 7:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2286;
                reset_forces();
                set_subseq(5);
                return;
              case 8:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2286;
                reset_forces();
                set_subseq(5);
                return;
              case 9:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2286;
                reset_forces();
                set_subseq(5);
                return;
              case 10:
              case 16:
              case 17:
                v_inerc = v_inerc - v_force;
                if ( !char_on_ground_down() )
                  goto LABEL_2286;
                reset_forces();
                y = getlvl_height();
                set_subseq(11);
                return;
              case 11:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2286;
                reset_forces();
                set_subseq(5);
                return;
              case 12:
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                {
                  reset_forces();
                  y = getlvl_height();
                  field_194 = 1;
                  field_190 = 0;
                  play_sfx(58);
                  //shake_camera(10.0);
                  set_subseq(13);
                  /*
                  v1409 = 0.0;
                  do
                  {
                    *(float *)&v1640 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1409 * 45.0 - 20.0;
                    v1641 = 30.0;
                    v1642 = 2.0;
                    if ( *(float *)&v1640 < 0.0 || *(float *)&v1640 > 180.0 )
                      field_7D0 = -1;
                    else
                      field_7D0 = 1;
                    addbullet(this, NULL,855, x, y, dir, LOBYTE(field_7D0), (int)&v1640, 3);
                    v1409 = v1409 + 1.0;
                  }
                  while ( v1409 < 8.0 );
                  */
                }
                goto LABEL_2286;
              case 13:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2286;
                goto LABEL_2414;
              case 14:
                if ( get_frame() )
                  goto LABEL_2286;
                scaleX = scaleX - 0.02999999932944775;
                if ( scaleX < 0.333 )
                {
                  v945 = 0.333;
                  goto LABEL_2788;
                }
                scaleY = scaleX - 0.02999999932944775;
                goto LABEL_2286;
              default:
                goto LABEL_2286;
            }
          case 606:
            sub_46AB50(5, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(20 * (char)dir), y + 135.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 7 )
              {
                float t[3];
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL,856, (double)(140 * (char)dir) + x, y + 70.0, dir, 1, t, 3);
                play_sfx(19);
                t[0] = 0.0;
                t[1] = 2.0;
                t[2] = 1.0;
                addbullet(this, NULL,856, (double)(140 * (char)dir) + x, y + 70.0, dir, 1, t, 3);
                t[2] = 3.0;
                /*
                v1417 = 0.0;
                v978 = (float)0.0;
                do
                {
                  *(float *)&v1489 = v978 * 45.0 - 20.0;
                  v1490 = 30.0;
                  if ( *(float *)&v1489 < 90.0 || *(float *)&v1489 > 270.0 )
                    field_7D0 = -1;
                  else
                    field_7D0 = 1;
                  v979 = dir;
                  v980 = y + 70.0;
                  v981 = v980;
                  v982 = (double)(140 * (char)v979) + x;
                  addbullet(this, NULL,856, v982, v981, v979, LOBYTE(field_7D0), (int)&v1489, 3);
                  v1417 = v1417 + 1.0;
                  v978 = v1417;
                }
                while ( v1417 < 8.0 );
                */
              }
            }
            return;
          case 607:
            sub10func();
            sub_46AB50(5, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(50 * (char)dir), y + 130.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 7 )
              {
                //shake_camera(8.0);
                /*
                *(float *)&v1537 = -82.0;
                v1538 = 30.0;
                v1539 = 0.0;
                v987 = dir;
                v988 = (double)(100 * (char)v987) + x;
                addbullet(this, NULL,857, v988, y, v987, 1, (int)&v1537, 3);
                */
                scene_add_effect(this, 127, x, y, dir, -1);
                play_sfx(59);
                /*
                v1539 = 1.0;
                v1418 = 0.0;
                do
                {
                  *(float *)&v1537 = (double)(unsigned int)get_MT_range(20) + v1418 * 36.0;
                  v1538 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
                  if ( *(float *)&v1537 < 0.0 || *(float *)&v1537 > 180.0 )
                    field_7D0 = -1;
                  else
                    field_7D0 = 1;
                  v989 = dir;
                  v990 = (double)(100 * (char)v989) + x;
                  addbullet(this, NULL,811, v990, y, v989, LOBYTE(field_7D0), (int)&v1537, 3);
                  v1418 = v1418 + 1.0;
                }
                while ( v1418 < 10.0 );
                */
              }
            }
            return;
          case 608:
            if ( !get_subseq() || get_subseq() == 1 )
              sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() >= 3 && get_subseq() <= 11 )
            {
              //sub_4867D0(1, x);
              //sub_4867F0(1, y);
            }
            break;
          case 612:
            sub10func();
            sub_46AB50(5, 2);
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 40 )
            {
              h_inerc = 10.0;
              next_subseq();
              return;
            }
            if ( get_subseq() == 2 )
            {
              if ( !get_frame_time() && get_frame() == 2 )
              {
                play_sfx(10);
                //shake_camera(4.0);
                /*
                v1422 = 0.0;
                v1098 = (float)0.0;
                do
                {
                  *(float *)&v1616 = v1098 * 30.0;
                  v1617 = (double)(unsigned int)get_MT_range(30) * 0.1000000014901161 + 12.0;
                  v1618 = 6.0;
                  v1099 = -*(float *)&v1616;
                  v1100 = sin_deg(v1099) > 0.0;
                  LOBYTE(v1101) = dir;
                  v1102 = get_pframe();
                  v1103 = y - (double)v1102->extra1[5];
                  v1104 = v1103;
                  v1105 = (double)(v1102->extra1[4] * (char)v1101) + x;
                  addbullet(this, NULL,862, v1105, v1104, v1101, (1 - 2 * v1100), (int)&v1616, 3);
                  v1422 = v1422 + 1.0;
                  v1098 = v1422;
                }
                while ( v1422 < 12.0 );
                */
              }
              if ( !get_frame_time() && get_frame() == 6 )
                play_sfx(53);
              if ( get_frame() >= 3 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( get_frame() >= 6 )
              {
                scaleX = scaleX + 0.1000000014901161;
                if ( scaleX > 2.0 )
                  scaleX = 2.0;
                scaleY = scaleX;
              }
            }
            v945 = 1.0;
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2744;
            if ( get_subseq() == 3 )
            {
              scaleX = 1.0;
              scaleY = 1.0;
              field_194 = 1;
              field_190 = 0;
LABEL_2744:
              if ( get_subseq() == 3 )
              {
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 1 )
                    h_inerc = 12.0;
                  if ( !get_frame_time() && get_frame() == 3 )
                  {
                    play_sfx(10);
                    //shake_camera(10.0);
                    /*
                    v1423 = 0.0;
                    v1108 = (float)0.0;
                    do
                    {
                      *(float *)&v1646 = v1108 * 20.0;
                      v1647 = (double)(unsigned int)get_MT_range(30) * 0.1000000014901161 + 18.0;
                      v1648 = 6.0;
                      v1109 = -*(float *)&v1646;
                      v1110 = sin_deg(v1109) > 0.0;
                      LOBYTE(v1111) = dir;
                      v1112 = get_pframe();
                      v1113 = y - (double)v1112->extra1[5];
                      v1114 = v1113;
                      v1115 = (double)(v1112->extra1[4] * (char)v1111) + x;
                      addbullet(this, NULL,862, v1115, v1114, v1111, (1 - 2 * v1110), (int)&v1646, 3);
                      v1423 = v1423 + 1.0;
                      v1108 = v1423;
                    }
                    while ( v1423 < 18.0 );
                    */
                    v945 = 1.0;
                  }
                }
                if ( !get_frame_time() && get_frame() == 7 )
                {
                  play_sfx(53);
                  v945 = 1.0;
                }
                if ( get_frame() >= 4 )
                {
                  h_inerc = h_inerc - 0.5;
                  if ( h_inerc < 0.0 )
                    h_inerc = 0.0;
                }
                if ( get_frame() >= 7 )
                {
                  scaleX = scaleX + 0.05000000074505806;
                  if ( scaleX > 1.5 )
                    scaleX = 1.5;
                  scaleY = scaleX;
                }
              }
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2768;
            if ( get_subseq() == 4 )
            {
              scaleX = v945;
              scaleY = v945;
              field_194 = 1;
              field_190 = 0;
LABEL_2768:
              if ( get_subseq() == 4 )
              {
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 1 )
                    h_inerc = 12.0;
                  if ( !get_frame_time() && get_frame() == 3 )
                  {
                    play_sfx(20);
                    //shake_camera(4.0);
                    /*
                    v1424 = 0.0;
                    v1118 = (float)0.0;
                    do
                    {
                      *(float *)&v1622 = v1118 * 18.0;
                      v1623 = (double)(unsigned int)get_MT_range(30) * 0.1000000014901161 + 20.0;
                      v1624 = 6.0;
                      v1119 = -*(float *)&v1622;
                      v1120 = sin_deg(v1119) > 0.0;
                      LOBYTE(v1121) = dir;
                      v1122 = get_pframe();
                      v1123 = y - (double)v1122->extra1[5];
                      v1124 = v1123;
                      v1125 = (double)(v1122->extra1[4] * (char)v1121) + x;
                      addbullet(this, NULL,862, v1125, v1124, v1121, (1 - 2 * v1120), (int)&v1622, 3);
                      v1424 = v1424 + 1.0;
                      v1118 = v1424;
                    }
                    while ( v1424 < 20.0 );
                    */
                    v945 = 1.0;
                  }
                }
                if ( get_frame() >= 4 )
                {
                  h_inerc = h_inerc - 0.5;
                  if ( h_inerc < 0.0 )
                    h_inerc = 0.0;
                }
              }
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2785;
            if ( get_subseq() == 5 )
            {
              play_sfx(54);
              v945 = 1.0;
LABEL_2785:
              if ( get_subseq() == 5 && !get_frame() )
              {
                scaleX = scaleX - 0.05000000074505806;
                if ( scaleX >= 0.33000001 )
                {
                  scaleY = scaleX;
                }
                else
                {
LABEL_2788:
                  scaleX = v945;
                  scaleY = v945;
LABEL_2789:
                  next_frame();
                }
              }
            }
            return;
          case 650:
            sub_46AB50(5, 2);
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(600);
              set_subseq(1);
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 100.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL,850, x, y + 100.0, dir, 1, t, 3);
              play_sfx(50);
              v_inerc = 10.0;
            }
            return;
          case 695:
            sub10func();
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
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
            {
              h_inerc = 0.0;
              field_49A = 0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              v183 = get_frame() == 6;
LABEL_2811:
              if ( v183 )
              {
                scene_play_sfx(29);
                field_49A = 0;
              }
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
              goto LABEL_3294;
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
                goto LABEL_2868;
            }
            if ( get_subseq() == 2 )
            {
              v287 = h_inerc - 0.5;
LABEL_2827:
              h_inerc = v287;
              if ( !(0.0 < v287 | 0.0 == v287) )
LABEL_2828:
                h_inerc = 0.0;
            }
            return;
          case 708:
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc + 2.0;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
            }
            if ( char_on_ground_flag() )
              goto LABEL_3300;
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            v_inerc = v_inerc - 0.5;
            if ( getlvl_height() < (v_inerc + y) || v_inerc >= 0.0 )
            {
LABEL_3300:
              if ( process() )
                goto LABEL_3259;
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                h_inerc = -14.0;
                v_inerc = 4.0;
                scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
                scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
                scene_play_sfx(31);
              }
            }
            else
            {
              v_inerc = 0.0;
LABEL_2838:
              y = getlvl_height();
              set_subseq(v3);
            }
            return;
          case 710:
            if ( process() )
              goto LABEL_3294;
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 10) )
                //shake_camera(4.0);
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  if ( get_elaps_frames() < 120 )
                    break;
                  goto LABEL_2868;
                case 1:
                  if ( get_elaps_frames() < 180 )
                    break;
                  next_subseq();
                  return;
                case 2:
                case 3:
                  if ( get_elaps_frames() < 240 )
                    break;
                  next_subseq();
                  return;
                default:
                  break;
              }
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(15);
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL,900, x, y + 100.0, dir, -1, t, 3);
            }
            return;
          case 711:
            if ( process() )
              goto LABEL_3294;
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 10) )
                //shake_camera(4.0);
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  if ( get_elaps_frames() < 120 )
                    break;
                  goto LABEL_2868;
                case 1:
                  if ( get_elaps_frames() >= 180 )
                    goto LABEL_2868;
                  break;
                case 2:
                case 3:
                  if ( get_elaps_frames() < 240 )
                    break;
                  next_subseq();
                  return;
                default:
                  break;
              }
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(25);
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL,901, x, y + 100.0, dir, -1, t, 3);
            }
            return;
          case 720:
            sub10func();
            if ( process() )
              set_seq(700);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            {
              if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
              {
                //shake_camera(10.0);
                float t[3];
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                    t[0] = 41.0;
                    t[1] = 8.0;
                    t[2] = 9.0;
                    xe = dir;
                    v1162 = (double)(100 * (char)xe) + x;
                    goto LABEL_2889;
                  case 1:
                    t[0] = 81.0;
                    t[1] = 8.0;
                    t[2] = 9.0;
                    xe = dir;
                    v1162 = (double)(100 * (char)xe) + x;
                    goto LABEL_2889;
                  case 2:
                    t[0] = 121.0;
                    t[1] = 8.0;
                    t[2] = 9.0;
                    addbullet(this, NULL,910, (double)(100 * (char)dir) + x, y, dir, 1, t, 3);
                    xe = -dir;
                    v1162 = (double)(100 * dir) + x;
                    goto LABEL_2889;
                  case 3:
                    t[0] = 200.0;
                    t[1] = 8.0;
                    t[2] = 9.0;
                    addbullet(this, NULL,910, (double)(100 * dir) + x, y, dir, 1, t, 3);
                    xe = -dir;
                    v1162 = (double)(100 * dir) + x;
LABEL_2889:
                    addbullet(this, NULL,910, v1162, y, xe, 1, t, 3);
                    scene_add_effect(this, 127, x, y, dir, -1);
                    break;
                  default:
                    break;
                }
                play_sfx(59);
              }
            }
            else
            {
LABEL_1014:
              set_seq(0);
            }
            return;
          case 730:
            switch ( get_subseq() )
            {
              case 0:
                if ( get_frame() >= 6 && get_frame() <= 15 )
                {
                  x_off = 0.0;
                  y_off = 0.0;
                  scaleX = 3.0 - field_7DC;
                  scaleY = 3.0 - field_7DC;
                  field_7DC = field_7DC * 0.75;
                }
                goto LABEL_2966;
              case 1:
                h_inerc = 0.0;
                if ( getlvl_height() + 10.0 <= y )
                {
LABEL_2414:
                  reset_forces();
                  set_subseq(5);
                  return;
                }
                y = getlvl_height();
                if ( keyUp(INP_A) && keyUp(INP_A) < 3 || keyDown(INP_A) == 2 || keyHit(INP_A) )
                {
                  set_subseq(7);
                  return;
                }
                if ( keyUp(INP_B) && keyUp(INP_B) < 3 || keyDown(INP_B) == 2 || keyHit(INP_B) )
                {
                  set_subseq(8);
                  return;
                }
                if ( keyUp(INP_C) && keyUp(INP_C) < 3 || keyDown(INP_C) == 2 || keyHit(INP_C) )
                {
                  set_subseq(9);
                  return;
                }
                if ( field_820 == 3 )
                {
                  flip_with_force();
                  h_inerc = 4.0;
                  set_subseq(2);
                  return;
                }
                if ( dY() >= 0 )
                  goto LABEL_2966;
                h_inerc = 0.0;
                v_inerc = 0.0;
                field_7DC = 0.0;
                if ( dX(dir) > 0 )
                  field_7DC = 1.0;
                if ( dX(dir) < 0 )
                  field_7DC = -1.0;
                set_subseq(3);
                return;
              case 2:
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                    v1177 = 3.0;
                    goto LABEL_2924;
                  case 1:
                    v1177 = 4.0;
                    goto LABEL_2924;
                  case 2:
                    v1177 = 4.5;
                    goto LABEL_2924;
                  case 3:
                    v1177 = 5.0;
LABEL_2924:
                    h_inerc = v1177;
                    break;
                  default:
                    break;
                }
                if ( get_border_near() == 1 && dir == -1 )
                  dir = 1;
                if ( get_border_near() == -1 && dir == 1 )
                  dir = -1;
                goto LABEL_2966;
              case 4:
              case 5:
                v_inerc = v_inerc - v_force;
                if ( !char_on_ground_down() )
                  goto LABEL_2966;
                reset_forces();
                y = getlvl_height();
                set_subseq(6);
                play_sfx(58);
                //shake_camera(10.0);
                //v1425 = 0.0;
                field_190 = 0;
                field_194 = 1;
                /*
                do
                {
                  *(float *)&v1589 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1425 * 45.0 - 20.0;
                  v1590 = 30.0;
                  v1591 = 2.0;
                  if ( *(float *)&v1589 < 0.0 || *(float *)&v1589 > 180.0 )
                    field_7D0 = -1;
                  else
                    field_7D0 = 1;
                  addbullet(this, NULL,920, x, y, dir, LOBYTE(field_7D0), (int)&v1589, 3);
                  v1425 = v1425 + 1.0;
                }
                while ( v1425 < 8.0 );
                */
                return;
              case 6:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2966;
                reset_forces();
                set_subseq(5);
                return;
              case 7:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2966;
                reset_forces();
                set_subseq(5);
                return;
              case 8:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2966;
                reset_forces();
                set_subseq(5);
                return;
              case 9:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2966;
                reset_forces();
                set_subseq(5);
                return;
              case 10:
                v_inerc = v_inerc - v_force;
                if ( !char_on_ground_down() )
                  goto LABEL_2966;
                reset_forces();
                y = getlvl_height();
                set_subseq(11);
                return;
              case 11:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2966;
                reset_forces();
                set_subseq(5);
                return;
              case 12:
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                {
                  reset_forces();
                  y = getlvl_height();
                  field_194 = 1;
                  field_190 = 0;
                  play_sfx(58);
                  //shake_camera(10.0);
                  set_subseq(13);
                  /*
                  v1426 = 0.0;
                  do
                  {
                    *(float *)&v1595 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1426 * 45.0 - 20.0;
                    v1596 = 30.0;
                    v1597 = 2.0;
                    if ( *(float *)&v1595 < 0.0 || *(float *)&v1595 > 180.0 )
                      field_7D0 = -1;
                    else
                      field_7D0 = 1;
                    addbullet(this, NULL,920, x, y, dir, LOBYTE(field_7D0), (int)&v1595, 3);
                    v1426 = v1426 + 1.0;
                  }
                  while ( v1426 < 8.0 );
                  */
                }
                goto LABEL_2966;
              case 13:
                if ( getlvl_height() + 10.0 > y )
                  goto LABEL_2966;
LABEL_2961:
                reset_forces();
                set_subseq(5);
                return;
              case 14:
                if ( get_frame() )
                  goto LABEL_2966;
                scaleX = scaleX - 0.02999999932944775;
                if ( scaleX < 0.333 )
                {
                  scaleX = 0.333;
                  scaleY = 0.333;
                  next_frame();
                  return;
                }
                scaleY = scaleX;
LABEL_2966:
                if ( process() )
                {
                  set_seq(700);
                  scaleX = 1.0;
                  scaleY = 1.0;
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  scaleX = 1.0;
                  scaleY = 1.0;
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
                {
                  v_inerc = 15.0;
                  v_force = 0.5;
                  h_inerc = (enemy->x - x) * (double)dir / 60.0;
                  if ( h_inerc < 0.0 )
                    h_inerc = 0.0;
                  switch ( settings_get()->get_difficulty() )
                  {
                    case 0:
                      v1188 = 6.0;
                      goto LABEL_2981;
                    case 1:
                      v1188 = 8.0;
                      goto LABEL_2981;
                    case 2:
                      v1188 = 10.0;
                      goto LABEL_2981;
                    case 3:
                      v1188 = 12.0;
LABEL_2981:
                      if ( v1188 <= h_inerc )
                        h_inerc = v1188;
                      break;
                    default:
                      break;
                  }
                  /*
                  v1427 = 0.0;
                  do
                  {
                    *(float *)&v1601 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1427 * 45.0 - 20.0;
                    v1602 = 30.0;
                    v1603 = 2.0;
                    if ( *(float *)&v1601 < 0.0 || *(float *)&v1601 > 180.0 )
                      field_7D0 = -1;
                    else
                      field_7D0 = 1;
                    addbullet(this, NULL,920, x, y, dir, LOBYTE(field_7D0), (int)&v1601, 3);
                    v1427 = v1427 + 1.0;
                  }
                  while ( v1427 < 8.0 );
                  */
                }
                if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 7 || !get_frame_time() && !get_frame() && get_subseq() == 8 || !get_frame_time() && !get_frame() && get_subseq() == 9)
                  || !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 10 || !get_frame_time() && !get_frame() && get_subseq() == 12 || !get_frame_time() && !get_frame() && get_subseq() == 14) )
                {
                  goto LABEL_3014;
                }
                switch ( get_subseq() )
                {
                  case 0:
                    if ( !get_frame_time() )
                    {
                      if ( get_frame() == 6 )
                      {
                        float t[3];
                        t[0] = 0.0;
                        t[1] = 0.0;
                        t[2] = 0.0;
                        addbullet(this, NULL,920, x, y, dir, -1, t, 3);
                        /*
                        v1428 = 0.0;
                        do
                        {
                          *(float *)&v1540 = /*(double)(unsigned int)get_MT_range(40)*//*0.0 + v1428 * 45.0 - 20.0;
                          v1541 = 30.0;
                          v1542 = 2.0;
                          if ( *(float *)&v1540 < 0.0 || *(float *)&v1540 > 180.0 )
                            field_7D0 = -1;
                          else
                            field_7D0 = 1;
                          v1190 = dir;
                          v1191 = (double)(40 * (char)v1190) + x;
                          addbullet(this, NULL,920, v1191, y, v1190, LOBYTE(field_7D0), (int)&v1540, 3);
                          v1428 = v1428 + 1.0;
                        }
                        while ( v1428 < 8.0 );
                        */
                        play_sfx(53);
                      }
                      if ( !get_frame_time() )
                      {
LABEL_2474:
                        if ( get_frame() == 16 )
                        {
                          scaleX = 1.0;
                          scaleY = 1.0;
                        }
                      }
                    }
                    break;
                  case 2:
                    if ( !get_frame_time() )
                    {
                      if ( get_frame() == 2 )
                      {
                        field_190 = 0;
                        field_194 = 1;
                      }
                      if ( !get_frame_time() && get_frame() == 3 )
                      {
                        play_sfx(56);
                        //shake_camera(2.0);
                        /*
                        v1429 = 0.0;
                        do
                        {
                          *(float *)&v1607 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1429 * 60.0 - 20.0;
                          v1608 = 20.0;
                          v1609 = 2.0;
                          if ( *(float *)&v1607 < 0.0 || *(float *)&v1607 > 180.0 )
                            field_7D0 = -1;
                          else
                            field_7D0 = 1;
                          v1192 = dir;
                          v1193 = (double)(70 * (char)v1192) + x;
                          addbullet(this, NULL,920, v1193, y, v1192, LOBYTE(field_7D0), (int)&v1607, 3);
                          v1429 = v1429 + 1.0;
                        }
                        while ( v1429 < 6.0 );
                        */
                      }
                    }
                    if ( !get_frame_time() )
                    {
                      if ( get_frame() == 6 )
                      {
                        field_190 = 0;
                        field_194 = 1;
                      }
                      if ( !get_frame_time() && get_frame() == 7 )
                      {
                        play_sfx(56);
                        //shake_camera(2.0);
                        /*
                        v1430 = 0.0;
                        do
                        {
                          *(float *)&v1613 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1430 * 60.0 - 20.0;
                          v1614 = 20.0;
                          v1615 = 2.0;
                          if ( *(float *)&v1613 < 0.0 || *(float *)&v1613 > 180.0 )
                            field_7D0 = -1;
                          else
                            field_7D0 = 1;
                          v1194 = dir;
                          v1195 = (double)(70 * (char)v1194) + x;
                          addbullet(this, NULL,920, v1195, y, v1194, LOBYTE(field_7D0), (int)&v1613, 3);
                          v1430 = v1430 + 1.0;
                        }
                        while ( v1430 < 6.0 );
                        */
                      }
                    }
                    break;
                  case 7:
                    if ( !get_frame_time() && get_frame() == 10 )
                    {
                      field_194 = 1;
                      field_190 = 0;
                      play_sfx(57);
                      //shake_camera(10.0);
                      /*
                      v1431 = 0.0;
                      do
                      {
                        *(float *)&v1463 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1431 * 45.0 - 20.0;
                        v1464 = 30.0;
                        v1465 = 2.0;
                        if ( *(float *)&v1463 < 0.0 || *(float *)&v1463 > 180.0 )
                          field_7D0 = -1;
                        else
                          field_7D0 = 1;
                        v1196 = dir;
                        v1197 = (double)(420 * (char)v1196) + x;
                        addbullet(this, NULL,920, v1197, y, v1196, LOBYTE(field_7D0), (int)&v1463, 3);
                        v1431 = v1431 + 1.0;
                      }
                      while ( v1431 < 8.0 );
                      */
                      float t[4];
                      switch ( settings_get()->get_difficulty() )
                      {
                        case 1:
                          t[0] = 0.0;
                          t[1] = 20.0;
                          t[2] = 0.0;
                          t[3] = 180.0;
                          addbullet(this, NULL,921, (double)(420 * (char)dir) + x, y + 200.0, dir, 1, t, 4);
                          break;
                        case 2:
                          t[0] = 0.0;
                          t[1] = 20.0;
                          t[2] = 0.0;
                          t[3] = 180.0;
                          addbullet(this, NULL,921, (double)(420 * (char)dir) + x, y + 200.0, dir, 1, t, 4);
                          /*
                          v1211 = 10;
                          do
                          {
                            *(float *)&v1463 = 15.0 - (double)(unsigned int)get_MT_range(30);
                            v1464 = /*(double)(unsigned int)get_MT_range(60)*//*60.0 * 0.1000000014901161 + 6.0;
                            v1465 = 4.0;
                            v1466 = 0.0;
                          float t[4];
                          t[0] = 
                          t[1] = 
                          t[2] = 
                          t[3] = 
                            v1212 = dir;
                            v1213 = y + 200.0;
                            v1214 = v1213;
                            v1215 = (double)(420 * (char)v1212) + x;
                            addbullet(this, NULL,921, v1215, v1214, v1212, 1, (int)&v1463, 4);
                            --v1211;
                          }
                          while ( v1211 );
                          */
                          break;
                        case 3:
                          t[0] = 0.0;
                          t[1] = 20.0;
                          t[2] = 0.0;
                          t[3] = 180.0;
                          addbullet(this, NULL,921, (double)(420 * (char)dir) + x, y + 200.0, dir, 1, t, 4);
                          /*
                          v1202 = 20;
                          do
                          {
                            *(float *)&v1463 = 35.0 - (double)(unsigned int)get_MT_range(70);
                            v1464 = /*(double)(unsigned int)get_MT_range(60)*//*60.0 * 0.1000000014901161 + 6.0;
                            v1465 = 4.0;
                            v1466 = 0.0;
                          float t[4];
                          t[0] = 
                          t[1] = 
                          t[2] = 
                          t[3] = 
                            v1203 = dir;
                            v1204 = y + 200.0;
                            v1205 = v1204;
                            v1206 = (double)(420 * (char)v1203) + x;
                            addbullet(this, NULL,921, v1206, v1205, v1203, 1, (int)&v1463, 4);
                            --v1202;
                          }
                          while ( v1202 );
                          */
                          break;
                      }
                    }
                    break;
                  case 8:
                    if ( !get_frame_time() && get_frame() == 6 )
                    {
                      field_194 = 1;
                      field_190 = 0;
                      play_sfx(58);
                      //shake_camera(10.0);
                      /*
                      v1432 = 0.0;
                      do
                      {
                        *(float *)&v1619 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1432 * 45.0 - 20.0;
                        v1620 = 30.0;
                        v1621 = 2.0;
                        if ( *(float *)&v1619 < 0.0 || *(float *)&v1619 > 180.0 )
                          field_7D0 = -1;
                        else
                          field_7D0 = 1;
                        v1220 = dir;
                        v1221 = (double)(310 * (char)v1220) + x;
                        addbullet(this, NULL,855, v1221, y, v1220, LOBYTE(field_7D0), (int)&v1619, 3);
                        v1432 = v1432 + 1.0;
                      }
                      while ( v1432 < 8.0 );
                      */
                    }
                    break;
                  case 9:
                    if ( !get_frame_time() && get_frame() == 7 )
                    {
                      field_194 = 1;
                      field_190 = 0;
                      play_sfx(57);
                      //shake_camera(10.0);
                      /*
                      v1433 = 0.0;
                      do
                      {
                        *(float *)&v1467 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1433 * 45.0 - 20.0;
                        v1468 = 30.0;
                        v1469 = 2.0;
                        if ( *(float *)&v1467 < 0.0 || *(float *)&v1467 > 180.0 )
                          field_7D0 = -1;
                        else
                          field_7D0 = 1;
                        v1222 = dir;
                        v1223 = (double)(240 * (char)v1222) + x;
                        addbullet(this, NULL,855, v1223, y, v1222, LOBYTE(field_7D0), (int)&v1467, 3);
                        v1433 = v1433 + 1.0;
                      }
                      while ( v1433 < 8.0 );
                      */
                      float t[4];
                      switch ( settings_get()->get_difficulty() )
                      {
                        case 1:
                          
                          t[0] = -65.0;
                          t[1] = 20.0;
                          t[2] = 0.0;
                          t[3] = 180.0;
                          addbullet(this, NULL,921,  (double)(420 * (char)dir) + x, y + 200.0, dir, 1, t, 4);
                          break;
                        case 2:
                          t[0] = -65.0;
                          t[1] = 20.0;
                          t[2] = 0.0;
                          t[3] = 180.0;
                          addbullet(this, NULL,921, (double)(420 * (char)dir) + x,  y + 200.0, dir, 1, t, 4);
                          /*
                          v1237 = 10;
                          do
                          {
                            float t[4];
                            t[0] = (double)(unsigned int)get_next_ranged(30) - 80.0;
                            t[1] = /*(double)(unsigned int)get_MT_range(60)*//*60.0 * 0.1000000014901161 + 6.0;
                            t[2] = 4.0;
                            t[3] = 0.0;
                            v1238 = dir;
                            v1239 = y + 200.0;
                            v1240 = v1239;
                            v1241 = (double)(420 * (char)v1238) + x;
                            addbullet(this, NULL,921, v1241, v1240, v1238, 1, (int)&v1467, 4);
                            --v1237;
                          }
                          while ( v1237 );
                          */
                          break;
                        case 3:
                          t[0] = -65.0;
                          t[1] = 20.0;
                          t[2] = 0.0;
                          t[3] = 180.0;
                          addbullet(this, NULL,921, (double)(420 * (char)dir) + x, y + 200.0, dir, 1, t, 4);
                          /*
                          v1228 = 20;
                          do
                          {
                            *(float *)&v1467 = (double)(unsigned int)get_MT_range(70) - 100.0;
                            v1468 = /*(double)(unsigned int)get_MT_range(60)*//*60.0 * 0.1000000014901161 + 6.0;
                            v1469 = 4.0;
                            v1470 = 0.0;
                            float t[4];
                            t[0] = 0.0;
                            t[1] = 0.0;
                            t[2] = 0.0;
                            t[3] = 0.0;
                            v1229 = dir;
                            v1230 = y + 200.0;
                            v1231 = v1230;
                            v1232 = (double)(420 * (char)v1229) + x;
                            addbullet(this, NULL,921, v1232, v1231, v1229, 1, (int)&v1467, 4);
                            --v1228;
                          }
                          while ( v1228 );
                          */
                          break;
                      }
                    }
                    break;
                  case 10:
                    if ( !get_frame_time() && get_frame() == 4 )
                    {
                      field_194 = 1;
                      field_190 = 0;
                      play_sfx(57);
                    }
                    break;
                  default:
                    return;
                }
                break;
              default:
                goto LABEL_2966;
            }
            return;
          case 740:
            if ( get_subseq() < 2 || get_subseq() > 4 )
              goto LABEL_3104;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_subseq(5);
LABEL_3102:
              reset_forces();
              y = getlvl_height();
            }
            else
            {
              
LABEL_3104:
              if ( get_subseq() == 1 )
              {
                field_534 = 0.2;
                if ( !(get_elaps_frames() % 6) )
                {
                  /*
                  *(float *)&v1561 = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
                  v1562 = (double)(unsigned int)get_MT_range(120);
                  v1563 = 1.0;
                  v1247 = dir;
                  v1248 = -*(float *)&v1561;
                  v1249 = sin_deg(v1248);
                  v1250 = v1249 * v1562 + y;
                  v1251 = v1250;
                  v1252 = -*(float *)&v1561;
                  v1253 = cos_deg(v1252);
                  v1254 = v1253 * v1562 + x;
                  addbullet(this, NULL,930, v1254, v1251, v1247, 1, (int)&v1561, 3);
                  */
                }
                if ( 0.0 < field_7DC )
                {
                  v_inerc = field_7DC;
                  field_7DC = field_7DC * 0.949999988079071;
                  if ( field_7DC <= 0.1000000014901161 )
                  {
                    field_7DC = 0.0;
                    v_inerc = 0.0;
                  }
                }
                if ( 0.0 == field_7DC && ++field_7D0 >= 10 )
                {
                  field_7DC = -1.0;
                  field_194 = 1;
                  field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                  field_7D0 = 0;
                  
                }
                if ( -1.0 == field_7DC )
                {
                  if ( ++field_7D0 > 600 )
                  {
                    field_194 = 0;
                    dash_angle = dash_angle - 0.2000000029802322;
                    field_7E8 = field_7E8 + 0.05000000074505806;
                    if ( 0.0 > dash_angle )
                      dash_angle = 0.0;
                    if ( field_7D0 >= 690 )
                    {
                      /*
                      v1454 = 0.0;
                      do
                      {
                        *(float *)&v1742 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1454 * 45.0 - 20.0;
                        v1743 = (double)(unsigned int)get_MT_range(13) + 12.0;
                        v1744 = 0.0;
                        v1276 = y + 100.0
                        addbullet(this, NULL,999, x, v1276, dir, 1, (int)&v1742, 3);
                        v1454 = v1454 + 1.0;
                      }
                      while ( v1454 < 8.0 );
                      */
                      //color_A = -1;
                      v_inerc = 15.0;
                      v_force = 0.2;
                      goto LABEL_3151;
                    }
                  }
                  else
                  {
                    if ( field_190 == 6 )
                    {
                      field_194 = 1;
                      field_190 = 0;
                    }
                    if ( field_190 )
                    {
                      if ( ++field_7D4 >= 5 )
                      {
                        field_7D4 = 0;
                        field_194 = 1;
                        field_190 = 0;
                      }
                    }
                    if ( cos_deg((-atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir)) - field_7E4) > 0.0 )
                    {
                      dash_angle = dash_angle + 0.25;
                    }
                    else
                    {
                      dash_angle = dash_angle - 0.05000000074505806;
                      if ( dash_angle < 0.0 )
                        dash_angle = 0.0;
                    }
                    switch ( settings_get()->get_difficulty() )
                    {
                      /*
                      case 0:
                        v1264 = 10;
                        v1436 = 0.80000001;
                        v1265 = 6.0;
                        goto LABEL_3126;
                      case 1:
                        v1264 = 7;
                        v1436 = 1.0;
                        if ( dash_angle >= 7.0 )
                          dash_angle = 7.0;
                        break;
                      case 2:
                        v1264 = 5;
                        v1436 = 1.25;
                        v1265 = 8.0;
                        goto LABEL_3126;
                      case 3:
                        v1264 = 4;
                        v1436 = 1.5;
                        v1265 = 10.0;
LABEL_3126:
                        if ( v1265 <= dash_angle )
                          dash_angle = v1265;
                        break;
                      default:
                        v1264 = LODWORD(v1385);
                        break;
                        */
                    }
                    /*
                    v1435 = (double)(((-atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir)) - field_7E4) % 360);
                    v1266 = v1435;
                    if ( v1435 > 180.0 )
                    {
                      v1435 = v1266 - 360.0;
                      v1266 = v1435;
                    }
                    if ( v1266 < -180.0 )
                    {
                      v1435 = v1266 + 360.0;
                      v1266 = v1435;
                    }
                    v1267 = v1266;
                    v1268 = v1436 < fabs_(v1267);
                    v1269 = v1436;
                    if ( v1268 )
                    {
                      if ( v1435 >= 0.0 )
                      {
                        if ( v1435 > 0.0 )
                          field_7E4 = v1269 + field_7E4;
                      }
                      else
                      {
                        field_7E4 = field_7E4 - v1269;
                      }
                    }
                    else
                    {
                      field_7E4 = v1385;
                    }
                    if ( !(get_elaps_frames() % v1264) )
                    {
                      play_sfx(60);
                      float t[3];
                      t[0] = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
                      t[1] = 0.0;
                      t[2] = 4.0;
                      v1270 = (double)(unsigned int)get_next_ranged(120);
                      v1271 = dir;
                      v1272 = -*(float *)&v1583;
                      v1273 = sin_deg(v1272) * v1270 + y;
                      v1274 = -*(float *)&v1583;
                      v1275 = cos_deg(v1274) * v1270 + x;
                      addbullet(this, NULL,930, v1275, v1273, v1271, 1, (int)&v1583, 3);
                    }
                    */
                  }
                  //WHATIS?
                  //set_vec_speed((render_class *)&cEffectSprite, field_7E4, dash_angle);
                  v3 = 2;
                  v_inerc = field_7E8 + v_inerc;
                }
              }
              if ( get_subseq() >= v3 && get_subseq() <= 4 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
              {
                reset_forces();
                set_subseq(5);
                y = getlvl_height();
              }
              else
              {
                if ( process() )
                  set_seq(700);
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  field_7DC = 25.0;
                if ( !get_subseq() )
                {
                  if ( !get_frame_time() && get_frame() == 3 )
                  {
                    /*
                    v1455 = 0.0;
                    do
                    {
                      *(float *)&v1748 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1455 * 45.0 - 20.0;
                      v1749 = (double)(unsigned int)get_MT_range(13) + 12.0;
                      v1750 = 0.0;
                      v1278 = y + 100.0
                      addbullet(this, NULL,999, x, v1278, dir, 1, (int)&v1748, 3);
                      v1455 = v1455 + 1.0;
                    }
                    while ( v1455 < 8.0 );
                    */
                    play_sfx(19);
                  }
                  if ( get_frame() >= v3 )
                  {
                    if ( !(get_elaps_frames() % 2) )
                    {
                      /*
                      *(float *)&v1754 = /*(double)(unsigned int)get_MT_range(360)*//*360.0;
                      v1755 = /*(double)(unsigned int)get_MT_range(5)*//*5.0 + 5.0;
                      v1756 = 5.0;
                      v1279 = dir;
                      v1280 = /*(double)(unsigned int)get_MT_range(60)*//*60.0 + y + 30.0;
                      v1281 = v1280;
                      v1282 = /*(double)(unsigned int)get_MT_range(60)*//*60.0 + x - 30.0;
                      addbullet(this, NULL,817, v1282, v1281, v1279, 1, (int)&v1754, 3);
                      */
                    }
                    if ( get_frame() == 3 )
                    {
                      /*
                      v1283 = color_A;
                      if ( v1283 < 0xFu )
                        color_A = 0;
                      else
                        color_A = v1283 - 15;
                        */
                    }
                  }
                }
              }
            }
            return;
          case 750:
            if ( get_subseq() == 1 )
            {
              v_inerc = v_inerc - v_force;
              if ( v_inerc <= 0.0 )
              {
                v_inerc = 0.0;
                v_force = 0.0;
                set_seq(751);
                return;
              }
            }
            if ( process() )
              set_seq(700);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            h_inerc = 0.0;
            v221 = 15.0;
            goto LABEL_3188;
          case 751:
            if ( process() )
              set_seq(700);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              float t[3];
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 7.0;
                  addbullet(this, NULL,940, x - (double)(10 * (char)dir), y + 250.0, dir, 1, t, 3);
                  t[2] = 3.0;
                  addbullet(this, NULL,940, x - (double)(10 * (char)dir), y + 250.0, dir, 1, t, 3);
                  t[2] = 18.0;
                  goto LABEL_3199;
                case 1:
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 7.0;
                  addbullet(this, NULL,940, x - (double)(10 * (char)dir), y + 250.0, dir, 1,t, 3);
                  t[2] = 3.0;
                  addbullet(this, NULL,940, x - (double)(10 * (char)dir), y + 250.0, dir, 1,t, 3);
                  t[2] = 18.0;
                  goto LABEL_3199;
                case 2:
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 8.0;
                  addbullet(this, NULL,940, x - (double)(10 * (char)dir), y + 250.0, dir, 1, t, 3);
                  t[2] = 3.0;
                  addbullet(this, NULL,940, x - (double)(10 * (char)dir), y + 250.0, dir, 1, t, 3);
                  t[2] = 18.0;
                  goto LABEL_3199;
                case 3:
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 9.0;
                  addbullet(this, NULL,940, x - (double)(10 * (char)dir), y + 250.0, dir, 1, t, 3);
                  t[2] = 3.0;
                  addbullet(this, NULL,940, x - (double)(10 * (char)dir), y + 250.0, dir, 1, t, 3);
                  t[2] = 18.0;
LABEL_3199:
                  addbullet(this, NULL,940, x - (double)(10 * (char)dir), y + 250.0, dir, -1, t, 3);
                  break;
                default:
                  break;
              }
            }
            if ( get_subseq() == 1 )
            {
              //shake_camera(2.0);
              field_7DC = field_7DC + 0.1000000014901161;
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  v1329 = 3.0;
                  goto LABEL_3203;
                case 1:
                  v1329 = 4.0;
                  goto LABEL_3203;
                case 2:
                  v1329 = 5.0;
                  goto LABEL_3203;
                case 3:
                  v1329 = 6.0;
LABEL_3203:
                  if ( v1329 <= field_7DC )
                    field_7DC = v1329;
                  break;
                default:
                  break;
              }
              field_74C = field_7DC;
              if ( x < (double)enemy->x && enemy->dir == 1 || x > (double)enemy->x && enemy->dir == -1 )
                field_74C = -field_7DC;
              if ( get_elaps_frames() >= 300 )
                goto LABEL_3151;
            }
            if ( get_subseq() == 2 && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                flip_with_force();
                field_7D2 = 1;
                /*
                v1627 = 1.0;
                v1456 = 0.0;
                do
                {
                  *(float *)&v1625 = /*(double)(unsigned int)get_MT_range(40)*//*40.0 + v1456 * 60.0 - 20.0;
                  v1626 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
                  if ( *(float *)&v1625 < 0.0 || *(float *)&v1625 > 180.0 )
                    field_7D0 = -1;
                  else
                    field_7D0 = 1;
                  v1331 = dir;
                  v1332 = (double)(40 * (char)v1331) + x;
                  addbullet(this, NULL,811, v1332, y, v1331, LOBYTE(field_7D0), (int)&v1625, 3);
                  v1456 = v1456 + 1.0;
                }
                while ( v1456 < 6.0 );
                */
              }
              if ( !get_frame_time() && get_frame() == 9 )
                v_force = 0.2;
            }
            if ( get_subseq() != 2 && get_subseq() != 3 )
              return;
            v_inerc = v_inerc - v_force;
            if ( !char_on_ground_down() )
              return;
            reset_forces();
            y = getlvl_height();
            goto LABEL_3230;
          default:
            goto LABEL_3248;
        }
        switch ( get_subseq() )
        {
          case 0:
            if ( field_190 != 1 && field_190 != 7 )
              goto LABEL_2585;
            reset_forces();
            set_subseq(2);
            enemy->reset_forces();
            enemy->angZ = 0.0;
            enemy->x = (h_inerc + 70.0) * (double)dir + x;
            enemy->y = v_inerc + y;
            enemy->set_seq(100);
            return;
          case 3:
          case 4:
            v_inerc = v_inerc - v_force;
            if ( !char_on_ground_down() )
              goto LABEL_2585;
            enemy->dir = -dir;
            reset_forces();
            set_subseq(5);
            //shake_camera(10.0);
            y = getlvl_height();
            enemy->angZ = 0.0;
            enemy->x = (h_inerc + 10.0) * (double)dir + x;
            enemy->y = y + 120.0 + v_inerc;
            enemy->set_seq(109);
            return;
          case 6:
          case 7:
            v_inerc = v_inerc - v_force;
            if ( !char_on_ground_down() )
              goto LABEL_2585;
            enemy->dir = -dir;
            reset_forces();
            set_subseq(8);
            //shake_camera(10.0);
            y = getlvl_height();
            enemy->angZ = 0.0;
            enemy->x = (h_inerc + 10.0) * (double)dir + x;
            enemy->y =  y + 120.0 + v_inerc;
            enemy->set_seq(109);
            return;
          case 9:
          case 10:
            v_inerc = v_inerc - v_force;
            if ( !char_on_ground_down() )
              goto LABEL_2585;
            reset_forces();
            set_subseq(11);
            y = getlvl_height();
            enemy->set_seq(107);
            enemy->angZ = 180.0;
            enemy->x = (h_inerc + 21.0) * (double)dir + x;
            enemy->y = y + 140.0 + v_inerc;
            return;
          case 12:
          case 13:
            v_inerc = v_inerc - v_force;
            if ( !char_on_ground_down() )
              goto LABEL_2585;
LABEL_2001:
            y = getlvl_height();
            set_seq(10);
            reset_forces();
            return;
          default:
LABEL_2585:
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              goto LABEL_3278;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 12 )
            {
              h_inerc = -10.0;
              v_inerc = 12.5;
              v_force = 0.5;
            }
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x, y + 100.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 7 )
              {
                field_194 = enemy->getlvl_height() == enemy->y;
              }
            }
            if ( get_subseq() == 2 )
            {
              if ( get_frame() )
              {
                if ( get_frame() == 1 )
                {
                  enemy->angZ = 0.0;
                  enemy->x = (h_inerc + 48.0) * (double)dir + x;
                  enemy->y = y + 120.0 + v_inerc;
                  enemy->set_seq(107);
                }
              }
              else
              {
                enemy->angZ = 0.0;
                enemy->x = (h_inerc + 70.0) * (double)dir + x;
                enemy->y = v_inerc + y;
                enemy->set_seq(100);
              }
            }
            if ( get_subseq() != 3 )
              goto LABEL_2616;
            if ( get_frame() )
            {
              if ( get_frame() != 1 )
              {
LABEL_2616:
                if ( get_subseq() == 4 && !get_frame() )
                {
                  enemy->angZ = 0.0;
                  enemy->x = h_inerc * -30.0 * (double)dir + x;
                  enemy->y = y + 110.0 + v_inerc;
                  enemy->set_seq(107);
                }
                if ( get_subseq() == 5 )
                {
                  switch ( /*(_WORD)v1*/ enemy->get_seq() )
                  {
                    case 0:
                      enemy->angZ = 0.0;
                      enemy->x = (h_inerc + 10.0) * (double)dir + x;
                      enemy->y = y + 120.0 + v_inerc;
                      enemy->set_seq(109);
                      break;
                    case 1:
                      enemy->angZ = -45.0;
                      enemy->x = (h_inerc + 55.0) * (double)dir + x;
                      enemy->y = y + 117.0 + v_inerc;
                      enemy->set_seq(109);
                      break;
                    case 2:
                      enemy->angZ = 0.0;
                      enemy->x = (h_inerc + 83.0) * (double)dir + x;
                      enemy->y = v_inerc + y;
                      enemy->hit_stop = 20;
                      enemy->set_seq(97);
                      set_subseq(3);
                      enemy->reset_forces();
                      if ( !get_frame_time() )
                      {
                        if ( field_526 || weather_id != 1 )
                          sub_464110(500, 980, 1, 1);
                        else
                          sub_464110(625, 980, 1, 1);
                        scene_add_effect(this, 3, (double)(95 * (char)dir) + x, y + 10.0, dir, 1);
                        play_sfx(5);
                      }
                      break;
                    case 4:
                      enemy->angZ = 0.0;
                      enemy->x = (h_inerc + 60.0) * (double)dir + x;
                      enemy->y = y + 55.0 + v_inerc;
                      enemy->set_seq(103);
                      break;
                    case 5:
                      enemy->angZ = 0.0;
                      enemy->x = (h_inerc + 48.0) * (double)dir + x;
                      enemy->y = y + 120.0 + v_inerc;
                      enemy->set_seq(103);
                      break;
                    default:
                      break;
                  }
                }
                if ( get_subseq() != 6 )
                  goto LABEL_2637;
                if ( get_frame() )
                {
                  if ( get_frame() != 1 )
                    goto LABEL_2637;
                  enemy->angZ = 0.0;
                  enemy->x = (h_inerc - 35.0) * (double)dir + x;
                  enemy->y =  y + 140.0 + v_inerc;
                }
                else
                {
                  enemy->angZ = 0.0;
                  enemy->x = (h_inerc - 25.0) * (double)dir + x;
                  enemy->y = y + 143.0 + v_inerc;
                }
                enemy->set_seq(107);
LABEL_2637:
                if ( get_subseq() == 7 && !get_frame() )
                {
                  enemy->angZ = 0.0;
                  enemy->x = h_inerc * -30.0 * (double)dir + x;
                  enemy->y =  y + 110.0 + v_inerc;
                  enemy->set_seq(107);
                }
                if ( get_subseq() == 8 )
                {
                  switch ( /*(_WORD)v1*/ enemy->get_seq() )
                  {
                    case 0:
                      enemy->angZ = 0.0;
                      move_valc = 109;
                      enemy->x = (h_inerc + 10.0) * (double)dir + x;
                      enemy->y = y + 120.0 + v_inerc;
                      goto LABEL_2659;
                    case 1:
                      enemy->angZ = -45.0;
                      move_valc = 109;
                      enemy->x = (h_inerc + 55.0) * (double)dir + x;
                      enemy->y = y + 117.0 + v_inerc;
                      goto LABEL_2659;
                    case 2:
                      enemy->angZ = 0.0;
                      enemy->x = (h_inerc + 83.0) * (double)dir + x;
                      enemy->y =  v_inerc + y;
                      enemy->hit_stop = 20;
                      enemy->set_seq(97);
                      set_subseq(3);
                      enemy->reset_forces();
                      if ( !get_frame_time() )
                      {
                        if ( field_526 || weather_id != 1 )
                          sub_464110(1000, 980, 1, 1);
                        else
                          sub_464110(1250, 980, 1, 1);
                        scene_add_effect(this, 3, (double)(95 * (char)dir) + x, y + 10.0, dir, 1);
                        play_sfx(5);
                        /*
                        v1636 = 1.0;
                        v1419 = 0.0;
                        do
                        {
                          *(float *)&v1634 = (double)(unsigned int)get_MT_range(20) + v1419 * 36.0;
                          v1635 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 30.0;
                          if ( *(float *)&v1634 < 0.0 || *(float *)&v1634 > 180.0 )
                            field_7D0 = -1;
                          else
                            field_7D0 = 1;
                          v1049 = dir;
                          v1050 = (double)(95 * (char)v1049) + x;
                          addbullet(this, NULL,811, v1050, y, v1049, LOBYTE(field_7D0), (int)&v1634, 3);
                          v1419 = v1419 + 1.0;
                        }
                        while ( v1419 < 10.0 );
                        */
                      }
                      break;
                    case 4:
                      enemy->angZ = 0.0;
                      enemy->x = (h_inerc + 60.0) * (double)dir + x;
                      enemy->y = y + 55.0 + v_inerc;
                      goto LABEL_2658;
                    case 5:
                      enemy->angZ = 0.0;
                      enemy->x = (h_inerc + 48.0) * (double)dir + x;
                      enemy->y = y + 120.0 + v_inerc;
LABEL_2658:
                      move_valc = 103;
LABEL_2659:
                      enemy->set_seq(move_valc);
                      break;
                    default:
                      break;
                  }
                }
                if ( get_subseq() == 9 )
                {
                  enemy->dir = dir;
                  //sub_4867D0(1, x);
                  //sub_4867F0(1, y);
                  enemy->x = (h_inerc + 45.0) * (double)dir + x;
                  enemy->y = y + 120.0 + v_inerc;
                  enemy->set_seq(107);
                }
                if ( get_subseq() == 10 )
                {
                  switch ( /*(_WORD)v1*/ enemy->get_seq() )
                  {
                    case 0:
                      enemy->angZ = -135.0;
                      enemy->x = (h_inerc + 44.0) * (double)dir + x;
                      enemy->y = y + 128.0 + v_inerc;
                      goto LABEL_2671;
                    case 1:
                      enemy->angZ = -60.0;
                      enemy->x = (h_inerc + 50.0) * (double)dir + x;
                      enemy->y = y + 85.0 + v_inerc;
                      break;
                    case 2:
                      enemy->angZ = -10.0;
                      enemy->x = (h_inerc + 20.0) * (double)dir + x;
                      enemy->y = y + 60.0 + v_inerc;
                      break;
                    case 3:
                      enemy->angZ = 45.0;
                      enemy->x = (h_inerc - 28.0) * (double)dir + x;
                      enemy->y = y + 50.0 + v_inerc;
                      goto LABEL_2671;
                    case 4:
                      enemy->angZ = 90.0;
                      enemy->x = (h_inerc - 55.0) * (double)dir + x;
                      enemy->y = y + 100.0 + v_inerc;
                      break;
                    case 5:
                      enemy->angZ = 135.0;
                      enemy->x = (h_inerc - 50.0) * (double)dir + x;
                      enemy->y = y + 140.0 + v_inerc;
                      break;
                    case 6:
                      enemy->angZ = 180.0;
                      enemy->x = (h_inerc - 5.0) * (double)dir + x;
                      enemy->y = y + 150.0 + v_inerc;
LABEL_2671:
                      break;
                    default:
                      break;
                  }
                }
                if ( get_subseq() == 11 )
                {
                  if ( !get_frame_time() && get_frame() == 2 )
                  {
                    enemy->dir = -dir;
                    enemy->h_inerc = 0.0;
                    enemy->v_inerc = 0.0;
                    enemy->set_seq(89);
                    play_sfx(51);
                    //shake_camera(20.0);
                    play_sfx(12);
                    enemy->x = (double)(60 * dir) + x;
                    enemy->y = enemy->getlvl_height();
                    if ( field_526 || weather_id != 1 )
                      sub_464110(5500, 980, 1, 1);
                    else
                      sub_464110(6875, 980, 1, 1);
                    scene_add_effect(this, 4, (double)(37 * (char)dir) + x,  y + 10.0, dir, 1);
                    enemy->angZ = 0.0;
                    enemy->hit_stop = 44;
                    /*
                    v1497 = 0.0;
                    v1420 = 0.0;
                    do
                    {
                      *(float *)&v1495 = (double)(unsigned int)get_MT_range(20) + v1420 * 36.0;
                      v1496 = /*(double)(unsigned int)get_MT_range(8)*//*8.0 + 45.0;
                      if ( *(float *)&v1495 < 0.0 || *(float *)&v1495 > 180.0 )
                        field_7D0 = -1;
                      else
                        field_7D0 = 1;
                      v1077 = dir;
                      v1078 = (double)(37 * (char)v1077) + x;
                      addbullet(this, NULL,858, v1078, y, v1077, LOBYTE(field_7D0), (int)&v1495, 3);
                      v1420 = v1420 + 1.0;
                    }
                    while ( v1420 < 10.0 );
                    v1497 = 3.0;
                    v1421 = 0.0;
                    v1079 = (float)0.0;
                    do
                    {
                      *(float *)&v1495 = v1079 * -36.0 - (double)(unsigned int)get_MT_range(20);
                      v1496 = (double)(unsigned int)get_MT_range(25) + 60.0;
                      v1080 = dir;
                      v1081 = (double)(37 * (char)v1080) + x;
                      addbullet(this, NULL,858, v1081, y, v1080, 1, (int)&v1495, 3);
                      v1421 = v1421 + 1.0;
                      v1079 = v1421;
                    }
                    while ( v1421 < 5.0 );
                    v1497 = 1.0;
                    v1082 = dir;
                    v1083 = (double)(37 * (char)v1082) + x;
                    addbullet(this, NULL,858, v1083, y, v1082, 1, (int)&v1495, 3);
                    v1497 = 2.0;
                    v1084 = dir;
                    v1085 = (double)(37 * (char)v1084) + x;
                    addbullet(this, NULL,858, v1085, y, v1084, -1, (int)&v1495, 3);
                    */
                  }
                  if ( get_frame() )
                  {
                    if ( get_frame() == 1 )
                    {
                      enemy->set_seq(107);
                      enemy->angZ = 120.0;
                      enemy->x = (h_inerc + 85.0) * (double)dir + x;
                      enemy->y =  y + 85.0 + v_inerc;
                      enemy->dir = -dir;
                    }
                  }
                  else
                  {
                    enemy->set_seq(107);
                    enemy->angZ = 180.0;
                    enemy->x = (h_inerc + 21.0) * (double)dir + x;
                    enemy->y = y + 140.0 + v_inerc;
                  }
                }
                if ( !get_elaps_frames() || !get_frame_time() || !get_frame() || get_subseq() == 3 ) //reversed conditions
                {
                  h_inerc = 2.0;
                  v_inerc = 11.0;
                  v_force = 0.75;
                }
                if ( !get_elaps_frames() )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 6 )
                  {
                    h_inerc = 2.0;
                    v_inerc = 25.0;
                    v_force = 1.25;
                  }
                  if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 9 )
                  {
                    h_inerc = 2.0;
                    v_inerc = 60.0;
                    v_force = 1.75;
                  }
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 12 )
                {
                  //sub_4867D0(0, x);
                  //sub_4867F0(0, y);
                  enemy->hit_stop = 0;
                }
                return;
              }
              enemy->angZ = 0.0;
              enemy->x = (h_inerc - 35.0) * (double)dir + x;
              enemy->y = y + 140.0 + v_inerc;
            }
            else
            {
              enemy->angZ = 0.0;
              enemy->x =  (h_inerc - 25.0) * (double)dir + x;
              enemy->y = y + 143.0 + v_inerc;
            }
            enemy->set_seq(107);
            goto LABEL_2616;
        }
      }
      if ( process() )
        set_seq(700);
      if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
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
  }
}

//note: taken from alice.cpp
void char_suika::func20()
{
    /*v1 = a1;
      v2 = a1->current_frame_params;
      v3 = v2->fflags;
      v147 = a1->current_seq_frames_vector->cprior;
      v4 = v2->fflags & FF_CANCELLEABLE;
      v148 = v2->fflags & FF_CANCELLEABLE;
      v5 = v3 & FF_UNK200000;*/

    uint16_t cprior = get_cprior();
    uint32_t fflags = get_pframe()->fflags;

    bool cc = (fflags & FF_CANCELLEABLE) != 0;
    bool cu = (fflags & FF_HJC) != 0;
    int32_t sq = get_seq();

    if ( !check_AB_pressed() ) // !sub_4870A0(a1, v2) - AB input check
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
                                    if ( field_891[0] < 3 )
                                        sub_4873B0(568, cprior);
                                    else
                                        sub_4873B0(566, cprior);
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
                                case 101:
                                    if ( field_801 == 0)
                                    {
                                        field_4C8++;
                                        field_801 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(522, cprior);
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
                                case 104:
                                    if ( field_800 == 0 )
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(507, cprior);
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
                                    if ( field_891[0] >= 3 )
                                    {
                                        if ( field_803 == 0 )
                                        {
                                            field_4C8++;
                                            field_803 = 1;
                                        }
                                        sub_4834F0();
                                        sub_488E70();
                                        sub_4873B0( 569, cprior);
                                        return;
                                    }
                                    break;
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
                                default:
                                    break;
                                }
                            }
                            else if (cprior <= 100 && crd_id >= 200 && crd_id <= 299 && keyDown(INP_X_AXIS) == 0)
                            {
                                switch(crd_id)
                                {
                                case 202:
                                    sub_487370( 652, cprior);
                                    return;
                                case 207:
                                    sub_487370( 657, cprior);
                                    return;
                                case 209:
                                    sub_487370( 659, cprior);
                                    return;
                                case 210:
                                    sub_487370( 660, cprior);
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
                                    if ( field_801 == 0)
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


                        if ( pres_comb & PCOMB_214C )
                        {
                            if ( skills_1[10] >= 1 )
                            {
                                if ( cprior <= get_prior(551) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                    if ( field_802 == 0 )
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
                        if ( pres_comb & PCOMB_214B )
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

                        if ( pres_comb & PCOMB_236C )
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
                            if ( cprior <= get_prior(501) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                                if ( field_800 == 0)
                                {
                                    field_4C8++;
                                    field_800 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0( 501, cprior);
                                return;
                            }
                        }
                        if ( pres_comb & PCOMB_236B )
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
                            if ( field_892 >= 1)
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
                            }
                            if ( field_891[0] >= 1)
                            {
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
                            }
                            if ( field_891[0] == 1)
                            {
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
                            }
                            if ( field_892 >= 1)
                            {
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
                        }
                        if ( pres_comb & PCOMB_2N2B )
                        {
                            if ( field_892 >= 1)
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
                            }
                            if ( field_891[0] >= 3)
                            {
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
                            }
                            if ( field_891[0] <= 2)
                            {
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
                            }
                            if ( field_892 >= 1)
                            {
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
                        }
                    }
                    else // Air specials
                    {
                        if ( pres_comb & PCOMB_623C )
                        {
                            if ( skills_1[5] == 0 && skills_1[9] == 0)
                            {
                                if ( cprior <= get_prior(523) || (sq >= 500 && sq <= 599 && field_801 == 0))
                                {
                                    if ( field_801 == 0)
                                    {
                                        field_4C8++;
                                        field_801 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 523, cprior);
                                    return;
                                }
                            }
                        }
                        if ( pres_comb & PCOMB_623B )
                        {
                            if ( skills_1[5] == 0 && skills_1[9] == 0 )
                            {
                                if ( cprior <= get_prior(522) || (sq >= 500 && sq <= 599 && field_801 == 0))
                                {
                                    if ( field_801 == 0)
                                    {
                                        field_4C8++;
                                        field_801 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 522, cprior);
                                    return;
                                }
                            }
                        }
                        if ( pres_comb & PCOMB_236C )
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
                                if ( cprior <= get_prior(508) || (sq >= 500 && sq <= 599 && field_800 == 0))
                                {
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 508, cprior);
                                    return;
                                }
                        }
                        if ( pres_comb & PCOMB_236B )
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
                                if ( cprior <= get_prior(507) || (sq >= 500 && sq <= 599 && field_800 == 0))
                                {
                                    if ( field_800 == 0)
                                    {
                                        field_4C8++;
                                        field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 507, cprior);
                                    return;
                                }
                        }
                        if ( pres_comb & PCOMB_214C )
                        {
                            if ( skills_1[6] >= 1 )
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
                            if ( skills_1[6] == 0 && skills_1[10] == 0 )
                            {
                                if ( cprior <= get_prior(543) || (sq >= 500 && sq <= 599 && field_802 == 0)) //originally get_prior(546)
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
                        if ( pres_comb & PCOMB_214B )
                        {
                            if ( skills_1[6] >= 1 )
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
                            if ( skills_1[6] == 0 && skills_1[10] == 0 )
                            {
                                if ( cprior <= get_prior(542) || (sq >= 500 && sq <= 599 && field_802 == 0)) //originally get_prior(545)
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
                        if ( pres_comb & PCOMB_2N2C )
                        {
                            if ( field_891[0] >= 1 )
                            {
                                if ( skills_1[7] >= 1 )
                                {
                                    if ( cprior <= get_prior(567) || (sq >= 500 && sq <= 599 && field_803 == 0)) //originally get_prior(565)
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
                            }
                        }
                        if ( pres_comb & PCOMB_2N2B )
                        {
                            if ( field_891[0] >= 3 )
                            {
                                if ( skills_1[7] >= 1 )
                                {
                                    if ( cprior <= get_prior(569) || (sq >= 500 && sq <= 599 && field_803 == 0)) //originally get_prior(566)
                                    {
                                        if ( field_803 == 0)
                                        {
                                            field_4C8++;
                                            field_803 = 1;
                                        }
                                        sub_4834F0();
                                        sub_4873B0( 569, cprior);
                                        return;
                                    }
                                }
                            }
                        }
                    }
                }
            }

            if ((keyUp(INP_A) && keyUp(INP_A) < 3) || keyDown(INP_A) == 2 || keyHit(INP_A) )
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
                            if ( dX(dir) < 0 || hX(dir) < 0) // 4a
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

                            if ( dst > 140.0 && cprior <= get_prior(301)) //Far A
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
                            angZ = 0.0;
                            set_seq(402);
                            input->zero_keyhit();
                            return;
                        }
                        else if ( dY() == 0  && (dX(dir) > 0 || hX(dir) > 0) && cprior <= get_prior(401) )
                        {
                            angZ = 0.0;
                            set_seq(401);
                            input->zero_keyhit();
                            return;
                        }
                        else if (cprior <= get_prior(400) )
                        {
                            angZ = 0.0;
                            set_seq(400);
                            input->zero_keyhit();
                            return;
                        }
                    }
                }
                else if ( ((sq > 299 && field_190 != 0 && field_190 != 3) || sq < 300 ) && spell_energy >= 200 ) //In AIR
                {
                    if ( (dY() > 0 || hY() > 0) && cprior <= get_prior(406))
                    {
                        angZ = 0.0;
                        set_seq(406);
                        input->zero_keyhit();
                        return;
                    }
                    else if ( (dX(dir) > 0 || hX(dir) > 0) && cprior <= get_prior(405))
                    {
                        angZ = 0.0;
                        set_seq(405);
                        input->zero_keyhit();
                        return;
                    }
                    else if (cprior <= get_prior(404))
                    {
                        angZ = 0.0;
                        set_seq(404);
                        input->zero_keyhit();
                        return;
                    }
                }
            }
            if ((keyUp(INP_C) && keyUp(INP_C) < 3) || keyDown(INP_C) == 2 || keyHit(INP_C) )
            {
                if (char_on_ground_flag()) // On Ground
                {
                    if ( sq == 200 && dY() == 0 && (dX(dir) > 0 || hX(dir) > 0))  // 66B
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
                            angZ = 0.0;
                            set_seq(412);
                            input->zero_keyhit();
                            return;
                        }
                        else if ( dY() == 0  && (dX(dir) > 0 || hX(dir) > 0) && cprior <= get_prior(411) ) // 6C
                        {
                            angZ = 0.0;
                            set_seq(411);
                            input->zero_keyhit();
                            return;
                        }
                        else if ( dY() == 0  && (dX(dir) < 0 || hX(dir) < 0) && cprior <= get_prior(419) ) // 4C
                        {
                            angZ = 0.0;
                            set_seq(419);
                            input->zero_keyhit();
                            return;
                        }
                        else if (cprior <= get_prior(410) )
                        {
                            angZ = 0.0;
                            set_seq(410);
                            input->zero_keyhit();
                            return;
                        }
                    }
                }
                else
                {
                    if ( ((sq > 299 && field_190 != 0 && field_190 != 3) || sq < 300 ) && spell_energy >= 200)
                    {
                        if (dY() <= 0 && (dX(dir) > 0 || hX(dir) > 0) && cprior <= get_prior(415))
                        {
                            angZ = 0.0;
                            set_seq(415);
                            input->zero_keyhit();
                            return;
                        }
                        else if ((dY() > 0 || hY() > 0) && cprior <= get_prior(416))
                        {
                            angZ = 0.0;
                            set_seq(416);
                            input->zero_keyhit();
                            return;
                        }
                        else if (cprior <= get_prior(414))
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


void char_suika::set_seq_params() 
{

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
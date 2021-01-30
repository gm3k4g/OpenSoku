#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "komachi.h"
#include <math.h>

char_komachi::char_komachi(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_KOMACHI;
	pgp->load_dat("komachi",pal);
	char_loadsfx("komachi");
	cards_load_cards(&chr_cards,"komachi");
	load_face("komachi");
	load_spells("komachi");
	stand_gfx->init(this,"komachi");
}

void char_komachi::init_vars()
{
  char_c::init_vars();
  field_138 = -6.0;
  field_890 = 0;
  field_894 = 0;
}

/*
c_bullet *char_komachi::new_bullet()
{
    c_bullet *tmp = new komachi_bullets();
    return tmp;
}
*/
void char_komachi::func10()
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

  double v24 = 0.0;
  double v80 = 0.0;

  double v86 = 0.0;

  int v97 = 0;

  double v153 = 0.0;

  bool v217 = false;

  double v243 = 0.0;
  int v275 = 0;

  int v543 = 0;

  double v546 = 0.0;
  bool v611 = false;
  bool v629 = false;

  int v643 = 0;
  int v649 = 0;
  int v677 = 0;
  int v683 = 0;
  int v740 = 0;

  double v899 = 0.0;
  int xs = 0;
  double v1182 = 0.0;

  double v15 = 0.0;

  double v82 = 0.0;

  int v548 = 0;

  x_delta = 0;
  y_delta = 106;
  if ( controlling_type == 2 && cards_added > 0 )
  {
    if ( cards_active[0]->id <= 8 )
    {
      switch ( cards_active[0]->id/*byte_6559D4[v2]*/ )
      {
        case 0:
          field_6E4 = field_6E8 - field_188;
          if ( (field_6E4 < 0) | (field_6E8 == field_188) && get_seq() >= 700 && field_7F6 == 1 )
          {
            if ( dir == 1 && enemy->x < (double)x || dir == -1 && enemy->x > (double)x )
              dir = -dir;
            set_seq(149);
            field_7F6 = 0;
            field_6F4 = 0;
            goto LABEL_23;
          }
          break;
        case 1:
          field_6E4 = field_6E8 - field_188;
          if ( (field_6E4 < 0) | (field_6E8 == field_188) && get_seq() >= 700 && field_7F6 == 1 )
          {
            if ( dir == 1 && enemy->x < (double)x || dir == -1 && enemy->x > (double)x )
              dir = -dir;
            set_seq(149);
            field_7F6 = 0;
            field_6F4 = 0;
LABEL_23:
            scene_add_effect(this, 68, x, y + 100.0, dir, 1);
          }
          break;
      }
    }
  }
  if ( field_894 <= 0 )
    field_894 = 0;
  else
    field_894 = field_894 - 1;
  if ( hit_stop || enemy->time_stop )
    return;
  if ( get_seq() <= 300 )
  {
    if ( get_seq() == 300 )
    {
LABEL_578:
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
        if ( h_inerc > 0.0 )
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( process() )
          set_seq(0);
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
            goto LABEL_52;
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
            if ( 0.0 <= h_inerc || (v15 = h_inerc + 0.5, h_inerc = v15, v15 <= 0.0) )
            {
LABEL_109:
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
          char_h_move(4.5);
          process();
          return;
        case 5:
          sub10func();
          char_h_move(-4.5);
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
              goto LABEL_108;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v24 = 0.0;
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
          if ( !((get_subseq() < 0) | (get_subseq() == 0)) )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_108;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v24 = 4.5;
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
          if ( !((get_subseq() < 0) | (get_subseq() == 0)) )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_108;
          }
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v24 = -4.5;
LABEL_104:
            move_val = v24;
            char_h_move(move_val);
            v_inerc = 15.0;
            v_force = 0.60000002;
            field_49A = 0;
          }
          return;
        case 9:
          if ( 0.0 == v_force )
            v_force = 0.60000002;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_108;
          goto LABEL_109;
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
          if ( get_subseq() && get_subseq() != 3 )
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
          else
          {
            sub10func();
          }
          if ( !process() )
            goto LABEL_124;
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
LABEL_124:
            if ( get_subseq() == 3 && get_frame() == 1 && !get_frame_time() )
            {
              if ( enemy->x < (double)x )
                dir = -1;
              if ( enemy->x > (double)x )
                dir = 1;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              v_inerc = 6.0;
              h_inerc = 12.5;
              v_force = 0.34999999;
            }
          }
          return;
        case 198:
          if ( get_subseq() && get_subseq() != 3 )
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
          else
          {
            sub10func();
          }
          if ( !process() )
            goto LABEL_146;
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
LABEL_146:
            if ( get_subseq() == 3 && get_frame() == 1 && !get_frame_time() )
            {
              if ( enemy->x < (double)x )
                dir = -1;
              if ( enemy->x > (double)x )
                dir = 1;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              v_inerc = 6.0;
              h_inerc = -12.5;
              v_force = 0.34999999;
            }
          }
          return;
        case 199:
          sub10func();
          if ( !process() )
            goto LABEL_163;
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
LABEL_163:
            if ( !get_subseq() && get_frame() == 12 && !get_frame_time() )
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
          process();
          if ( get_subseq() != 1 )
            goto LABEL_181;
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          if ( dY() >= 0 )
          {
            if ( (dX(dir) > 0 || (++field_7D0) <= 9) && (++field_7D0) <= 45 )
            {
LABEL_181:
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
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
            if ( (dX(dir) < 0) | (dX(dir) == 0) )
              set_seq(211);
            else
              set_seq(212);
          }
          return;
        case 201:
          if ( !get_subseq() || get_subseq() == 3 )
            sub10func();
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
              goto LABEL_532;
          }
          if ( process() )
            goto LABEL_534;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            char_h_move(-12.0);
            v_inerc = 4.0;
            v_force = 0.40000001;
            scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
            scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
            scene_play_sfx(31);
          }
          return;
        case 202:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_559;
          if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          process();
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(11.0);
              v_inerc = -1.0;
              v_force = 0.5;
              scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
              scene_add_effect(this, 126, x, y + 110.0, dir, 1);
              scene_play_sfx(31);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              flip_with_force();
          }
          return;
        case 203:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            reset_forces();
            y = getlvl_height();
            //get_frame_time() = 0;
            set_seq(10);
          }
          else
          {
            if ( get_subseq() < 3 && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            process();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(-11.0);
              v_inerc = 4.0;
              v_force = 0.5;
              scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
              scene_play_sfx(31);
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 3 )
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
          if ( process() )
          {
            set_seq(0);
            reset_forces();
            field_49A = 0;
          }
          return;
        case 208:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_297;
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
          v80 = 0.0;
          goto LABEL_293;
        case 209:
          if ( !get_subseq() )
            sub10func();
          if ( !char_on_ground_down() )
            goto LABEL_256;
          goto LABEL_297;
        case 210:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_297;
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() > 0 )
            v_inerc = v_inerc - v_force;
          goto LABEL_498;
        case 211:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_297;
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() > 0 )
            v_inerc = v_inerc - v_force;
          if ( get_subseq() == 1 && v_inerc < 4.0 )
            set_subseq(2);
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v80 = 2.0;
LABEL_293:
          char_h_move(v80);
          v_inerc = 20.0;
          v86 = 0.64999998;
          goto LABEL_507;
        case 212:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
          {
LABEL_297:
            set_seq(10);
            goto LABEL_2184;
          }
LABEL_256:
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() > 0 )
            v_inerc = v_inerc - v_force;
LABEL_261:
          if ( get_subseq() == 1 && v_inerc < 4.0 )
            set_subseq(2);
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v82 = 8.0;
            goto LABEL_506;
          }
          return;
        case 214:
          if ( process() )
            goto LABEL_995;
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              scene_play_sfx(31);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
              goto LABEL_995;
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
          v97 = 10;
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
              {
                reset_ofs();
                goto LABEL_370;
              }
            }
          }
          if ( !char_on_ground_down() )
            return;
          y = getlvl_height();
          v_force = 0.0;
          v_inerc = 0.0;
          if ( get_subseq() < 5 )
            goto LABEL_389;
          goto LABEL_2271;
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
            goto LABEL_1607;
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              scene_play_sfx(31);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
              goto LABEL_1607;
          }
          field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
          if ( get_subseq() == 5 || get_subseq() == 6 )
            v_inerc = v_inerc - v_force;
          if ( get_subseq() <= 0 || get_subseq() >= 5 )
            goto LABEL_2673;
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
          //v135 = sin_deg(dash_angle) * field_7DC;
          //v136 = v135;
          v_inerc = sin_deg(dash_angle) * field_7DC;
          if ( y > 680.0 && v_inerc > 0.0 ) //v136 instead of v_inerc
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
LABEL_2673:
            if ( char_on_ground_down() )
            {
              y = getlvl_height();
              v_force = 0.0;
              v_inerc = 0.0;
              if ( get_subseq() < 5 )
              {
LABEL_389:
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
LABEL_370:
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
            set_seq(10);
            goto LABEL_2184;
          }
          if ( get_subseq() > 0 )
          {
            v_inerc = v_inerc - v_force;
            if ( v_inerc < -20.0 )
              v_inerc = -20.0;
          }
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() == 1 && v_inerc < 4.0 )
            set_subseq(2);
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            char_h_move(0.0);
            v_inerc = 20.0;
            v_force = 0.64999998;
            field_49A = 0;
            scene_add_effect(this, 63, x, y, dir, 1);
          }
          return;
        case 221:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_108;
          if ( get_subseq() > 0 )
          {
            v_inerc = v_inerc - v_force;
            if ( v_inerc < -20.0 )
              v_inerc = -20.0;
          }
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          goto LABEL_261;
        case 222:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
          {
LABEL_108:
            set_seq(10);
            goto LABEL_2184;
          }
          if ( get_subseq() > 0 )
          {
            v_inerc = v_inerc - v_force;
            if ( v_inerc < -20.0 )
              v_inerc = -20.0;
          }
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
LABEL_498:
          if ( get_subseq() == 1 && v_inerc < 4.0 )
            set_subseq(2);
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v82 = -8.0;
LABEL_506:
            char_h_move(v82);
            v_inerc = 16.0;
            v86 = 0.60000002;
LABEL_507:
            v_force = v86;
            field_49A = 0;
            scene_add_effect(this, 63, x, y, dir, 1);
          }
          break;
        case 223:
          sub10func();
          field_49A = 1;
          process();
          if ( get_subseq() != 1 )
            goto LABEL_2674;
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          if ( ((++field_7D0, v153 = field_7D0, dX(dir) > 0) || v153 <= 15) && v153 <= 45 )
          {
LABEL_2674:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
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
          if ( !get_subseq() || get_subseq() == 3 )
            sub10func();
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
LABEL_532:
            v_inerc = 0.0;
            y = getlvl_height();
            set_subseq(3);
          }
          else if ( process() )
          {
LABEL_534:
            set_seq(0);
            h_inerc = 0.0;
          }
          else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_7D0 )
          {
            field_7D0 = 1;
            char_h_move(-10.0);
            v_inerc = 4.0;
            v_force = 0.40000001;
            scene_add_effect(this, 125, x, y + 80.0, -dir, 1);

            scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
            scene_play_sfx(31);
          }
          return;
        case 225:
          if ( get_subseq() > 0 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_559;
          }
          if ( get_subseq() >= 2 && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
          }
          if ( process() )
            set_seq(9);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
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
LABEL_559:
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
                char_h_move(11.0);
                v_inerc = -1.0;
                v_force = 0.5;
                scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
                scene_add_effect(this, 126, x, y + 110.0, dir, 1);
                scene_play_sfx(31);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                flip_with_force();
            }
          }
          return;
        default:
          goto LABEL_2646;
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
      if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        set_seq(0);
      if ( !get_subseq() && !get_frame_time() && get_frame() == 9 )
      {
        t[0] = 0.0;
        t[1] = 10.0;
        t[2] = 0.0;
        addbullet(this, NULL, 810, (double)(200 * (char)dir) + x, y, dir, 1, t, 3);
LABEL_1319:
        spell_energy_spend(200, 120);
        add_card_energy(50);
        play_sfx(10);
      }
    }
    else
    {
      switch ( get_seq() )
      {
        case 301:
          sub10func();
          if ( true /*!get_true(0)*/)
            goto LABEL_2496;
          return;
        case 302:
          sub10func();
          if ( false /*get_true(1)*/)
            return;
          if ( !keyDown(INP_A) )
            not_charge_attack = 0;
          if ( process() || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_2667;
          if ( get_subseq() )
            goto LABEL_610;
          if ( get_frame_time() )
            goto LABEL_607;
          if ( get_frame() == 4 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, (double)(246 * (char)dir) + x, y + 90.0, dir, 1);
          }
          else
          {
            if ( get_frame() == 1 )
            {
              scene_play_sfx(29);
              h_inerc = 20.0;
            }
LABEL_607:
            if ( get_frame() >= 2 )
            {
              h_inerc = h_inerc - 5.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
LABEL_610:
            if ( get_subseq() == 1 )
            {
              if ( !get_frame_time() && get_frame() == 1 )
              {
                scene_play_sfx(29);
                /*
                v193 = 0;
                v1158 = 0;
                do
                {
                  *(float *)&a7 = (double)scene_rand_rng(40) + (double)v1158 + 30.0;
                  v1332 = 10.0;
                  v1333 = 2.0;
                  v194 = *(float *)&a7;
                  if ( *(float *)&a7 < 0.0 || v194 > 180.0 )
                  {
                    y = -1;
                    x = dir;
                    a1 = y;
                    v197 = (double)(228 * (char)x) + x;
                    v196 = v197;
                  }
                  else
                  {
                    y = 1;
                    x = dir;
                    a1 = y;
                    v195 = (double)(228 * (char)x) + x;
                    v196 = v195;
                  }
                  a3 = v196;
                  addbullet(this, NULL, 817, a3, a1, x, y, (int)&a7, 3);
                  v193 += 45;
                  v1158 = v193;
                }
                while ( v193 < 360 );
                */
              }
              h_inerc = h_inerc - 5.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
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
            if ( !get_frame_time() && get_frame() == 2 )
              scene_play_sfx(27);
          }
          return;
        case 304:
          sub10func();
          if ( false /*get_true(1)*/)
            return;
          if ( !keyDown(INP_A) )
            not_charge_attack = 0;
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
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_1064;
          if ( get_subseq() || get_frame_time() || get_frame() != 3 )
            goto LABEL_649;
          if ( not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(45 * (char)dir), y + 40.0, dir, 1);
          }
          else
          {
            scene_play_sfx(29);
LABEL_649:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 1 )
            {
              scene_play_sfx(29);
              /*
              v206 = 0;
              v1159 = 0;
              do
              {
                *(float *)&v1313 = (double)scene_rand_rng(40) + (double)v1159 + 30.0;
                v1314 = 10.0;
                v1315 = 2.0;
                v207 = *(float *)&v1313;
                if ( *(float *)&v1313 < 0.0 || v207 > 180.0 )
                {
                  ya = -1;
                  xa = dir;
                  a1a = y;
                  v210 = (double)(228 * (char)xa) + x;
                  v209 = v210;
                }
                else
                {
                  ya = 1;
                  xa = dir;
                  a1a = y;
                  v208 = (double)(228 * (char)xa) + x;
                  v209 = v208;
                }
                v211 = v209;
                addbullet(this, NULL, 817, v211, a1a, xa, ya, (int)&v1313, 3);
                v206 += 45;
                v1159 = v206;
              }
              while ( v206 < 360 );
              */
            }
          }
          return;
        case 305:
          sub10func();
          if ( true /*!get_true(1)*/)
          {
            if ( get_frame() >= 2 )
            {
              h_inerc = h_inerc - 0.75;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 2 )
              scene_play_sfx(28);
          }
          return;
        case 306:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_696;
          if ( process() )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            scene_play_sfx(28);
          return;
        case 307:
          if ( !get_subseq() )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              if ( field_190 )
                /*vtbl->*/set_seq(10);
              else
                /*vtbl->*/set_subseq(1);
              goto LABEL_2184;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            set_seq(9);
          if ( !get_subseq() )
            goto LABEL_988;
          return;
        case 308:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_696;
          if ( process() )
            set_seq(9);
          if ( get_subseq() || get_frame_time() )
            return;
          v217 = get_frame() == 5;
          goto LABEL_990;
        case 309:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_696:
            set_seq(10);
            y = getlvl_height();
            v_force = 0.0;
            v_inerc = 0.0;
            return;
          }
          if ( process() )
            set_seq(9);
          if ( get_subseq() || get_frame_time() )
            return;
          if ( get_frame() == 5 )
          {
            if ( v_inerc < 8.0 )
              v_inerc = 8.0;
            v_force = 0.5;
          }
          if ( get_frame_time() )
            return;
          v217 = get_frame() == 6;
          goto LABEL_990;
        case 310:
          if ( !get_subseq() )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              v_inerc = 0.0;
              y = getlvl_height();
              next_subseq();
              return;
            }
          }
          if ( get_subseq() == 1 )
          {
            sub10func();
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_1607;
          if ( !get_subseq() )
          {
LABEL_988:
            if ( !get_frame_time() )
            {
              v217 = get_frame() == 4;
LABEL_990:
              if ( v217 )
                scene_play_sfx(29);
            }
          }
          return;
        case 320:
          sub10func();
          if ( false /*get_true(0)*/)
            return;
          if ( get_frame() >= 7 )
            h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          if ( process() )
            set_seq(0);
          if ( get_frame_time() )
            return;
          if ( get_frame() == 3 )
            h_inerc = 10.0;
          if ( get_frame_time() )
            return;
          if ( get_frame() == 5 )
          {
            scene_play_sfx(28);
            field_49A = 0;
          }
          goto LABEL_2511;
        case 321:
          sub10func();
          if ( false /*get_true(1)*/)
            return;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_1064;
          if ( !get_subseq() )
            goto LABEL_988;
          return;
        case 322:
          sub10func();
          if ( false /*get_true(1)*/)
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
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_1064;
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 8 )
            {
              scene_play_sfx(29);
              h_inerc = 15.0;
            }
            if ( !get_frame_time() && get_frame() == 10 )
              h_inerc = 0.0;
          }
          return;
        case 330:
          goto LABEL_578;
        case 400:
          sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 == 1 )
          {
            if ( !get_subseq() )
            {
              if ( !(field_7D2 % 2) && field_7D4 < 6 )
              {
                play_sfx(0);
                t[0] = field_7E4 - (double)field_7D4 * 5.0 + 15.0;
                t[1] = (double)field_7D4 + 10.0;
                t[2] = (double)(field_7D4 % 3);
                addbullet(this, NULL, 800, (double)(113 * (char)dir) + x, y + 128.0, dir, 1, t, 3);
                ++field_7D4;
              }
              ++field_7D2;
            }
            if ( get_subseq() == 1 )
            {
              if ( !(field_7D2 % 2) && field_7D4 < 10 )
              {
                play_sfx(0);
                t[0] = field_7E4 - (double)field_7D4 * 5.0 + 25.0;
                t[1] = (double)field_7D4 + 10.0;
                t[2] = (double)(field_7D4 % 3);
                addbullet(this, NULL, 800, (double)(113 * (char)dir) + x, y + 128.0, dir, 1, t, 3);
                ++field_7D4;
              }
              ++field_7D2;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_2667;
          if ( get_subseq() || get_frame_time() )
            goto LABEL_790;
          if ( get_frame() == 3 && not_charge_attack == 1 )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(35 * (char)dir), y + 155.0, dir, 1);
            return;
          }
          if ( get_frame() == 5 )
          {
            add_card_energy(30);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -30.0 )
              field_7E4 = -30.0;
            if ( field_7E4 > 20.0 )
              field_7E4 = 20.0;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
          }
LABEL_790:
          if ( get_subseq() != 1 || get_frame_time() || get_frame() != 3 )
            return;
          add_card_energy(30);
          field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7E4 < -30.0 )
            field_7E4 = -30.0;
          v243 = 20.0;
          goto LABEL_853;
        case 401:
          sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 == 1 )
          {
            if ( !get_subseq() )
            {
              if ( !(field_7D2 % 2) && field_7D4 < 6 )
              {
                play_sfx(0);
                t[0] = field_7E4 - (double)field_7D4 * 5.0 + 15.0;
                t[1] = (double)field_7D4 + 10.0;
                t[2] = (double)(field_7D4 % 3);
                addbullet(this, NULL, 800, (double)(113 * (char)dir) + x, y + 128.0, dir, 1, t, 3);
                ++field_7D4;
              }
              ++field_7D2;
            }
            if ( get_subseq() == 1 )
            {
              if ( !(field_7D2 % 2) && field_7D4 < 10 )
              {
                play_sfx(0);
                t[0] = field_7E4 - (double)field_7D4 * 5.0 + 25.0;
                t[1] = (double)field_7D4 + 10.0;
                t[2] = (double)(field_7D4 % 3);
                addbullet(this, NULL, 800, (double)(113 * (char)dir) + x, y + 128.0, dir, 1, t, 3);
                ++field_7D4;
              }
              ++field_7D2;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_2667;
          if ( get_subseq() || get_frame_time() )
            goto LABEL_826;
          if ( get_frame() == 3 && not_charge_attack == 1 )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(35 * (char)dir), y + 155.0, dir, 1);
            return;
          }
          if ( get_frame() == 5 )
          {
            add_card_energy(30);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -40.0 )
              field_7E4 = -40.0;
            if ( field_7E4 > -20.0 )
              field_7E4 = -20.0;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
          }
LABEL_826:
          if ( get_subseq() != 1 || get_frame_time() || get_frame() != 3 )
            return;
          add_card_energy(30);
          field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7E4 < -40.0 )
            field_7E4 = -40.0;
          v243 = -20.0;
          goto LABEL_853;
        case 402:
          sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 == 1 && !get_subseq() )
          {
            if ( !(field_7D2 % 2) && field_7D4 < 8 )
            {
              play_sfx(0);
              t[0] = (double)field_7D4 * 5.0 + field_7E4 - 20.0;
              t[1] = (double)field_7D4 + 10.0;
              t[2] = (double)(field_7D4 % 3);
              addbullet(this, NULL, 800, x - (double)(5 * (char)dir), y + 160.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( process() )
            set_seq(2);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          {
            if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
            {
              add_card_energy(30);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -80.0 )
                field_7E4 = -80.0;
              v243 = -45.0;
LABEL_853:
              if ( v243 < field_7E4 )
                field_7E4 = v243;
              field_7D0 = 1;
              spell_energy_spend(200, 45);
            }
          }
          else
          {
LABEL_52:
            set_seq(2);
          }
          return;
        case 404:
          if ( get_subseq() == 2 )
            sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          v_inerc = v_inerc - v_force;
          if ( get_subseq() < 2 && char_on_ground_down() )
            goto LABEL_1139;
          v275 = 10;
          if ( field_7D0 == 1 )
          {
            if ( !get_subseq() )
            {
              if ( !(field_7D2 % 2) && field_7D4 < 6 )
              {
                play_sfx(0);
                t[0] = (double)field_7D4 * 5.0 + field_7E4 - 15.0;
                t[1] = (double)field_7D4 + 10.0;
                t[2] = (double)(field_7D4 % 3);
                addbullet(this, NULL, 800, (double)(105 * (char)dir) + x, y + 162.0, dir, 1, t, 3);
                ++field_7D4;
              }
              ++field_7D2;
            }
            if ( get_subseq() == 1 )
            {
              if ( !(field_7D2 % 2) && field_7D4 < 10 )
              {
                play_sfx(0);
                t[0] = (double)field_7D4 * 5.0 + field_7E4 - 25.0;
                t[1] = (double)field_7D4 + 10.0;
                t[2] = (double)(field_7D4 % 3);
                addbullet(this, NULL, 800, (double)(105 * (char)dir) + x, y + 162.0, dir, 1, t, 3);
                ++field_7D4;
              }
              ++field_7D2;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_995;
          if ( get_subseq() )
            goto LABEL_896;
          if ( get_frame_time() )
            goto LABEL_893;
          if ( get_frame() == 3 && not_charge_attack == 1 )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(20 * (char)dir), y + 145.0, dir, 1);
            return;
          }
          if ( get_frame() == 8 )
          {
            add_card_energy(30);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -30.0 )
              field_7E4 = -30.0;
            if ( field_7E4 > 20.0 )
              field_7E4 = 20.0;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
          }
LABEL_893:
          if ( !get_frame_time() && get_frame() == 12 )
            v_force = 0.5;
LABEL_896:
          if ( get_subseq() != 1 || get_frame_time() )
            return;
          if ( get_frame() == 6 )
          {
            add_card_energy(30);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -30.0 )
              field_7E4 = -30.0;
            if ( field_7E4 > 20.0 )
              field_7E4 = 20.0;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
          }
          goto LABEL_1701;
        case 405:
          if ( get_subseq() == 2 )
            sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          v_inerc = v_inerc - v_force;
          if ( get_subseq() < 2 && char_on_ground_down() )
            goto LABEL_1139;
          if ( field_7D0 == 1 && !get_subseq() )
          {
            if ( !(field_7D2 % 2) && field_7D4 < 10 )
            {
              play_sfx(0);
              t[0] = field_7E4 - (double)field_7D4 + 6.0;
              t[1] = (double)field_7D4 * 1.5 + 9.0;
              t[2] = (double)(field_7D4 % 3);
              addbullet(this, NULL, 800, (double)(100 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_995;
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 6 )
            {
              add_card_energy(30);
              field_7E4 = 0.0;
              field_7D0 = 1;
              spell_energy_spend(200, 45);
            }
            if ( !get_frame_time() && get_frame() == 12 )
              v_force = 0.5;
          }
          return;
        case 406:
          if ( get_subseq() == 2 )
            sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          v_inerc = v_inerc - v_force;
          if ( get_subseq() < 2 && char_on_ground_down() )
          {
            set_subseq(2);
            goto LABEL_2182;
          }
          if ( field_7D0 == 1 )
          {
            if ( !get_subseq() )
            {
              if ( !(field_7D2 % 2) && field_7D4 < 6 )
              {
                play_sfx(0);
                t[0] = (double)field_7D4 * 5.0 + field_7E4 - 15.0;
                t[1] = (double)field_7D4 + 10.0;
                t[2] = (double)(field_7D4 % 3);
                addbullet(this, NULL, 800, (double)(75 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
                ++field_7D4;
              }
              ++field_7D2;
            }
            if ( get_subseq() == 1 )
            {
              if ( !(field_7D2 % 2) && field_7D4 < 10 )
              {
                play_sfx(0);
                t[0] = (double)field_7D4 * 5.0 + field_7E4 - 25.0;
                t[1] = (double)field_7D4 + 10.0;
                t[2] = (double)(field_7D4 % 3);
                addbullet(this, NULL, 800, (double)(75 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
                ++field_7D4;
              }
              ++field_7D2;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_995;
          if ( get_subseq() )
            goto LABEL_973;
          if ( get_frame_time() )
            goto LABEL_970;
          if ( get_frame() != 3 || not_charge_attack != 1 )
          {
            if ( get_frame() == 6 )
            {
              add_card_energy(30);
              field_7D0 = 1;
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < 20.0 )
                field_7E4 = 20.0;
              if ( field_7E4 > 60.0 )
                field_7E4 = 60.0;
              field_7D0 = 1;
              spell_energy_spend(200, 45);
            }
LABEL_970:
            if ( !get_frame_time() && get_frame() == 9 )
              v_force = 0.5;
LABEL_973:
            if ( get_subseq() == 1 && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                add_card_energy(30);
                field_7D0 = 1;
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7E4 < 20.0 )
                  field_7E4 = 20.0;
                if ( field_7E4 > 50.0 )
                  field_7E4 = 50.0;
                field_7D0 = 1;
                spell_energy_spend(200, 45);
              }
              if ( !get_frame_time() && get_frame() == 7 )
                v_force = 0.5;
            }
          }
          else
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(20 * (char)dir), y + 190.0, dir, 1);
          }
          return;
        case 408:
          sub10func();
          h_inerc = h_inerc - 0.3499999940395355;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          if ( process() )
            set_seq(2);
          goto LABEL_988;
        case 409:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            set_seq(10);
            reset_forces();
            y = getlvl_height();
            return;
          }
          if ( process() )
            goto LABEL_995;
          return;
        case 410:
          sub10func();
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
          {
            add_card_energy(50);
            spell_energy_spend(200, 60);
            play_sfx(1);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -40.0 )
              field_7E4 = -40.0;
            if ( field_7E4 > 40.0 )
              field_7E4 = 40.0;
            t[0] = field_7E4;
            t[1] = 3.0;
            t[2] = 0.0;
            addbullet(this, NULL, 801, (double)(87 * (char)dir) + x, y + 184.0, dir, 1, t, 3);
          }
          return;
        case 411:
          sub10func();
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            set_seq(0);
          if ( get_subseq() || get_frame_time() )
            goto LABEL_1033;
          if ( get_frame() == 5 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(80 * (char)dir), y + 164.0, dir, 1);
          }
          else
          {
            if ( get_frame() == 8 )
            {
              add_card_energy(50);
              play_sfx(2);
              field_190 = 1;
              spell_energy_spend(200, 60);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -10.0 )
                field_7E4 = -10.0;
              if ( field_7E4 > 10.0 )
                field_7E4 = 10.0;
              t[0] = field_7E4 + 10.0;
              t[1] = 20.0;
              t[2] = 2.0;
              addbullet(this, NULL, 801, 
                (cos_deg(-t[0]) * 150.0 + 35.0) * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 120.0, 
              dir, 1, t, 3);
              t[0] = field_7E4 - 10.0;
              addbullet(this, NULL, 801, 
                (cos_deg(-t[0]) * 150.0 + 35.0) * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 120.0, 
              dir, 1, t, 3);
            }
LABEL_1033:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 8 )
            {
              add_card_energy(50);
              play_sfx(2);
              field_190 = 1;
              spell_energy_spend(200, 60);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -10.0 )
                field_7E4 = -10.0;
              if ( field_7E4 > 10.0 )
                field_7E4 = 10.0;
              t[0] = field_7E4 + 10.0;
              t[1] = 20.0;
              t[2] = 2.0;
              addbullet(this, NULL, 801, 
                (cos_deg(-t[0]) * 150.0 + 35.0) * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 120.0, 
              dir, 1, t, 3);
              t[0] = field_7E4 - 10.0;
              addbullet(this, NULL, 801, 
                (cos_deg(-t[0]) * 150.0 + 35.0) * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 120.0, 
              dir, 1, t, 3);
              t[0] = field_7E4 + 7.0;
              t[1] = 24.0;
              t[2] = 2.0;
              addbullet(this, NULL, 801, 
                (cos_deg(-t[0]) * 150.0 + 35.0) * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 120.0, 
              dir, 1, t, 3);
              t[0] = field_7E4 - 7.0;
              addbullet(this, NULL, 801, 
                (cos_deg(-t[0]) * 150.0 + 35.0) * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 120.0, 
              dir, 1, t, 3);
            }
          }
          return;
        case 412:
          sub10func();
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( get_subseq() != 1 )
            goto LABEL_1056;
          if ( !not_charge_attack && get_elaps_frames() >= 2 )
            goto LABEL_2433;
          if ( get_elaps_frames() >= 120 )
            goto LABEL_2433;
          if ( not_charge_attack )
          {
            if ( get_elaps_frames() >= 10 )
            {
              field_190 = 1;
              if ( keyDown(INP_A) || keyDown(INP_B) )
              {
                set_subseq(3);
                add_card_energy(25);
                spell_energy_spend(200, 60);
                return;
              }
            }
          }
          if ( !(get_elaps_frames() % 3) )
          {
            t[0] = (double)scene_rand_rng(360);
            t[1] = (double)scene_rand_rng(150) + 250.0;
            t[2] = 0.0;
            addbullet(this, NULL, 822, x, y, dir, 1, t, 3);
          }
LABEL_1056:
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 3 )
          {
            field_190 = 1;
            add_card_energy(50);
            scene_play_sfx(55);
            field_894 = 10;
            spell_energy_spend(200, 60);
            play_sfx(15);
            t[0] = 0.0;
            t[1] = 88.0;
            t[2] = 4.0;
            addbullet(this, NULL, 801, (double)(84 * dir) + x, y, dir, -1, t, 3);
            t[0] = (double)scene_rand_rng(80) - 40.0;
            t[1] = (double)scene_rand_rng(80) - 40.0;
            addbullet(this, NULL, 801, (double)(84 * (char)dir) + x, y, dir, 1, t, 3);
            t[0] = (double)scene_rand_rng(80) - 40.0;
            t[1] = (double)scene_rand_rng(80) - 40.0;
            addbullet(this, NULL, 801, (double)(84 * (char)dir) + x, y, dir, 1, t, 3);
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            goto LABEL_1064;
          return;
        case 414:
          if ( get_subseq() == 2 )
            sub10func();
          v_inerc = v_inerc - v_force;
          if ( get_subseq() < 2 && char_on_ground_down() )
          {
            set_subseq(2);
            goto LABEL_2183;
          }
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_1607;
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 5 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 60);
              play_sfx(1);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -40.0 )
                field_7E4 = -40.0;
              if ( field_7E4 > 40.0 )
                field_7E4 = 40.0;
              t[0] = field_7E4;
              t[1] = 3.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(65 * (char)dir) + x, y + 175.0, dir, 1, t, 3);
            }
            if ( !get_frame_time() && get_frame() == 10 )
              v_force = 0.5;
          }
          return;
        case 415:
          if ( get_subseq() == 2 )
            sub10func();
          v_inerc = v_inerc - v_force;
          if ( get_subseq() < 2 && char_on_ground_down() )
            goto LABEL_1139;
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(9);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              set_seq(9);
          }
          if ( get_subseq() )
            goto LABEL_1124;
          if ( get_frame_time() )
            goto LABEL_1121;
          if ( get_frame() == 4 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(62 * (char)dir), y + 180.0, dir, 1);
          }
          else
          {
            if ( get_frame() == 7 )
            {
              add_card_energy(50);
              play_sfx(2);
              field_190 = 1;
              spell_energy_spend(200, 60);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -10.0 )
                field_7E4 = -10.0;
              if ( field_7E4 > 10.0 )
                field_7E4 = 10.0;
              t[0] = field_7E4 + 15.0;
              t[1] = 20.0;
              t[2] = 2.0;
              addbullet(this, NULL, 801, 
                cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 140.0, 
              dir, 1, t, 3);
              t[0] = field_7E4 - 15.0;
              addbullet(this, NULL, 801, 
                cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 140.0, 
              dir, 1, t, 3);
            }
LABEL_1121:
            if ( !get_frame_time() && get_frame() == 12 )
              v_force = 0.5;
LABEL_1124:
            if ( get_subseq() == 1 && !get_frame_time() )
            {
              if ( get_frame() == 7 )
              {
                add_card_energy(50);
                play_sfx(2);
                field_190 = 1;
                spell_energy_spend(200, 60);
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7E4 < -10.0 )
                  field_7E4 = -10.0;
                if ( field_7E4 > 10.0 )
                  field_7E4 = 10.0;
                t[0] = field_7E4 + 15.0;
                t[1] = 20.0;
                t[2] = 2.0;
                addbullet(this, NULL, 801, 
                  cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                  sin_deg(-t[0]) * 150.0 + y + 140.0, 
                dir, 1, t, 3);
                t[0] = field_7E4 - 15.0;
                addbullet(this, NULL, 801, 
                  cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                  sin_deg(-t[0]) * 150.0 + y + 140.0, 
                dir, 1, t, 3);
                t[0] = field_7E4 + 10.0;
                t[1] = 24.0;
                t[2] = 2.0;
                addbullet(this, NULL, 801, 
                  cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                  sin_deg(-t[0]) * 150.0 + y + 140.0, 
                dir, 1, t, 3);
                t[0] = field_7E4 - 10.0;
                addbullet(this, NULL, 801, 
                  cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                  sin_deg(-t[0]) * 150.0 + y + 140.0, 
                dir, 1, t, 3);
              }
              if ( !get_frame_time() && get_frame() == 12 )
                v_force = 0.5;
            }
          }
          return;
        case 416:
          if ( get_subseq() == 2 )
            sub10func();
          v_inerc = v_inerc - v_force;
          if ( get_subseq() < 2 && char_on_ground_down() )
          {
LABEL_1139:
            set_subseq(2);
            goto LABEL_2183;
          }
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            set_seq(9);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            set_seq(9);
          if ( get_subseq() || get_frame_time() )
            goto LABEL_1165;
          if ( get_frame() == 4 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(104 * (char)dir), y + 224.0, dir, 1);
          }
          else
          {
            if ( get_frame() == 9 )
            {
              h_inerc = -5.0;
              v_inerc = 7.5;
              v_force = 0.5;
              add_card_energy(50);
              play_sfx(2);
              field_190 = 1;
              spell_energy_spend(200, 60);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < 40.0 )
                field_7E4 = 40.0;
              if ( field_7E4 > 70.0 )
                field_7E4 = 70.0;
              t[0] = field_7E4 + 10.0;
              t[1] = 20.0;
              t[2] = 2.0;
              addbullet(this, NULL, 801, 
                cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 100.0,
              dir, 1, t, 3);
              t[0] = field_7E4 - 10.0;
              addbullet(this, NULL, 801, 
                cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 100.0,
              dir, 1, t, 3);
            }
LABEL_1165:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 9 )
            {
              h_inerc = -5.0;
              v_inerc = 7.5;
              v_force = 0.5;
              add_card_energy(50);
              play_sfx(2);
              field_190 = 1;
              spell_energy_spend(200, 60);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < 40.0 )
                field_7E4 = 40.0;
              if ( field_7E4 > 70.0 )
                field_7E4 = 70.0;
              t[0] = field_7E4 + 10.0;
              t[1] = 20.0;
              t[2] = 2.0;
              addbullet(this, NULL, 801, 
                cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 100.0, 
              dir, 1, t, 3);
              t[0] = field_7E4 - 10.0;
              addbullet(this, NULL, 801, 
                cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 100.0, 
              dir, 1, t, 3);
              t[0] = field_7E4 + 5.0;
              t[1] = 16.0;
              t[2] = 2.0;
              addbullet(this, NULL, 801, 
                cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 100.0, 
              dir, 1, t, 3);
              t[0] = field_7E4 - 5.0;
              addbullet(this, NULL, 801, 
                cos_deg(-t[0]) * 150.0 * (double)dir + x, 
                sin_deg(-t[0]) * 150.0 + y + 100.0, 
              dir, 1, t, 3);
            }
          }
          break;
        case 418:
          sub10func();
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() && get_frame() == 8 )
          {
            scene_play_sfx(29);
            field_49A = 0;
          }
          return;
        default:
          goto LABEL_2646;
      }
    }
    return;
  }
  if ( get_seq() > 770 )
  {
    if ( (get_seq() - 795) )
    {
      if ( !((get_seq() - 795) - 2) )
      {
        if ( get_subseq() > 2 || (v_inerc = v_inerc - v_force, !char_on_ground_down()) )
        {
          if ( get_subseq() == 3 )
          {
            h_inerc = h_inerc - 0.75;
            if ( h_inerc < 0.0 ) //condition reversed (old >= )
            {
              h_inerc = 0.0;
              x = 480.0;
            }
            if ( x > 480.0 )
              x = 480.0;
          }
          if ( process() )
LABEL_2667:
            set_seq(0);
          return;
        }
LABEL_2649:
        set_subseq(3);
        scene_play_sfx(30);
        y = getlvl_height();
        v_inerc = 0.0;
        return;
      }
      if ( ((get_seq() - 795) - 2) != 1 )
      {
LABEL_2646:
        char_c::func10();
        return;
      }
      if ( get_subseq() <= 2 )
      {
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_2649;
      }
      if ( get_subseq() == 3 )
      {
        h_inerc = h_inerc - 0.75;
        if ( h_inerc < 0.0 ) //condition reversed (old >= )
        {
          h_inerc = 0.0;
          x = 800.0;
        }
        if ( x < 800.0 )
          x = 800.0;
      }
    }
    else if ( !get_subseq() )
    {
      v_inerc = v_inerc - 0.300000011920929;
      if ( char_on_ground_down() )
      {
        set_subseq(1);
        scene_play_sfx(30);
        y = getlvl_height();
        reset_forces();
        return;
      }
    }
    if ( process() )
      set_seq(700);
    return;
  }
  if ( get_seq() == 770 )
  {
    if ( process() )
      set_seq(700);
    if ( !get_subseq() && !get_frame_time() && get_frame() == 8 )
    {
      field_6F5 = 1;
      sub_4685C0(-1);
      sub_46AB50(2, -1);
      health_to_max();
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
      case 501:
        sub10func();
        field_18C = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(0);
        if ( get_subseq() || get_frame_time() || get_frame() != 10 )
          return;
        t[0] = 0.0;
        t[1] = 20.0;
        t[2] = 0.0;
        addbullet(this, NULL, 810, (double)(200 * (char)dir) + x, y, dir, 1, t, 3);
        goto LABEL_1319;
      case 505:
        sub10func();
        field_18C = 4;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1064;
        if ( get_subseq() || get_frame_time() || get_frame() != 7 )
          return;
        t[0] = 0.0;
        t[1] = 0.0;
        t[2] = 0.0;
        addbullet(this, NULL, 811, x, y, dir, 1, t, 3);
        if ( skills_1[4] >= 4 )
        {
          t[2] = 3.0;
          addbullet(this, NULL, 811, x, y, dir, 1, t, 3);
        }
        /*
        v505 = 0;
        v1160 = 0;
        do
        {
          *(float *)&v1238 = (double)scene_rand_rng(30) + (double)v1160 + 30.0;
          v1239 = 10.0;
          v1240 = 2.0;
          v506 = *(float *)&v1238;
          if ( *(float *)&v1238 < 0.0 || v506 > 180.0 )
          {
            yb = -1;
            xb = dir;
            a1b = y;
            v509 = (double)(120 * (char)xb) + x;
            v508 = v509;
          }
          else
          {
            yb = 1;
            xb = dir;
            a1b = y;
            v507 = (double)(120 * (char)xb) + x;
            v508 = v507;
          }
          v510 = v508;
          addbullet(this, NULL, 817, v510, a1b, xb, yb, (int)&v1238, 3);
          v505 += 60;
          v1160 = v505;
        }
        while ( v505 < 360 );*/
        goto LABEL_1240;
      case 506:
        sub10func();
        field_18C = 4;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1064;
        if ( !get_subseq() && !get_frame_time() && get_frame() == 10 )
        {
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 2.0;
          addbullet(this, NULL, 811, x - (double)(175 * (char)dir), y - 75.0, dir, 1, t, 3);
          if ( skills_1[4] >= 4 )
          {
            t[2] = 5.0;
            addbullet(this, NULL, 811, x - (double)(175 * (char)dir), y - 75.0, dir, 1, t, 3);
          }
          /*
          v519 = 0;
          v1161 = 0;
          do
          {
            *(float *)&v1241 = (double)scene_rand_rng(30) + (double)v1161 + 30.0;
            v1242 = 10.0;
            v1243 = 2.0;
            v520 = *(float *)&v1241;
            if ( *(float *)&v1241 < 0.0 || v520 > 180.0 )
            {
              yc = -1;
              xc = dir;
              a1c = y;
              v523 = (double)(120 * (char)xc) + x;
              v522 = v523;
            }
            else
            {
              yc = 1;
              xc = dir;
              a1c = y;
              v521 = (double)(120 * (char)xc) + x;
              v522 = v521;
            }
            v524 = v522;
            addbullet(this, NULL, 817, v524, a1c, xc, yc, (int)&v1241, 3);
            v519 += 60;
            v1161 = v519;
          }
          while ( v519 < 360 );*/
LABEL_1240:
          spell_energy_spend(200, 120);
          add_card_energy(50);
          play_sfx(16);
        }
        return;
      case 507:
        if ( get_subseq() == 2 )
          sub10func();
        if ( get_subseq() <= 1 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_1267;
        }
        field_18C = 4;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
          goto LABEL_1607;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 5 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 811, x - (double)(105 * (char)dir), y - 20.0, dir, 1, t, 3);
            if ( skills_1[4] >= 4 )
            {
              t[2] = 3.0;
              addbullet(this, NULL, 811, x - (double)(105 * (char)dir), y - 20.0, dir, 1, t, 3);
            }
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(16);
          }
          if ( !get_frame_time() && get_frame() == 12 )
            v_force = 0.25;
        }
        return;
      case 508:
        if ( get_subseq() == 2 )
          sub10func();
        if ( get_subseq() <= 1 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_1267:
            set_subseq(2);
            goto LABEL_2184;
          }
        }
        field_18C = 4;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
          goto LABEL_1607;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 5 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 1.0;
            addbullet(this, NULL, 811, x - (double)(75 * dir), y, dir, 1, t, 3);
            if ( skills_1[4] >= 4 )
            {
              t[2] = 4.0;
              addbullet(this, NULL, 811, x - (double)(75 * (char)dir), y, dir, 1, t, 3);
            }
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(16);
          }
          if ( !get_frame_time() && get_frame() == 11 )
            v_force = 0.25;
        }
        return;
      case 510:
        sub10func();
        field_18C = 8;
        if ( process() )
          set_seq(0);//v536 = set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(0);//v536 = set_seq(0);
        if ( get_subseq() || get_frame_time() || get_frame() != 9 )
          return;
        t[0] = 0.0;
        t[1] = 10.0;
        t[2] = 0.0;
        /*
        if ( skills_1[8] >= 4 )
          v1297 = 2.0;
        LOBYTE(v536) = ;
        v537 = ;
        if ( dir == 1 )
        {
          v1151 = t;
          xd = -1;
          a1d = y;
          v1162 = flt_885644 + 100.0;
        }
        else
        {
          dir = -dir;
          v1151 = t;
          xd = dir;
          a1d = y;
          v1162 = flt_88563C - 100.0;
        }*/
        goto LABEL_1318;
      case 511:
        sub10func();
        field_18C = 8;
        if ( process() )
          set_seq(0);//v539 = set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(0);//v539 = set_seq(0);
        if ( get_subseq() || get_frame_time() || get_frame() != 9 )
          return;
        t[0] = 0.0;
        t[1] = 10.0;
        t[2] = 0.0;
        /*
        if ( skills_1[8] >= 4 )
          v1321 = 2.0;
        LOBYTE(v539) = dir;
        v540 = y;
        if ( v539 == -1 )
        {
          xd = -1;
          a1d = v540;
          v1163 = flt_885644 + 100.0;
        }
        else
        {
          xd = v539;
          a1d = v540;
          v1163 = flt_88563C - 100.0;
        }*/
LABEL_1318:
        //addbullet(this, NULL, 812, v1163, a1d, xd, 1, t, 3);
        goto LABEL_1319;
      case 520:
        sub10func();
        field_18C = 1;
        if ( field_7D0 != 1 )
          goto LABEL_1338;
        v543 = 5;
        if ( skills_1[1] >= 2 )
          v543 = 6;
        if ( skills_1[1] >= 4 )
          v543 = 8;
        if ( field_7D2 >= v543 )
          goto LABEL_1338;
        if ( field_7D4 % 3 )
          goto LABEL_1337;
        t[0] = -80.0 - (double)scene_rand_rng(20);
        t[1] = (double)scene_rand_rng(50) * 0.1000000014901161 + 20.0;
        t[2] = 3.0;
        v546 = (double)(113 * (char)dir) + x;
        goto LABEL_1336;
      case 521:
        sub10func();
        field_18C = 1;
        if ( field_7D0 == 1 )
        {
          v548 = 5;
          if ( skills_1[1] >= 2 )
            v548 = 6;
          if ( skills_1[1] >= 4 )
            v548 = 8;
          if ( field_7D2 < v548 )
          {
            if ( !(field_7D4 % 3) )
            {
              t[0] = -80.0 - (double)scene_rand_rng(20);
              t[1] = (double)scene_rand_rng(50) * 0.1000000014901161 + 25.0;
              t[2] = 3.0;
              v546 = (double)(113 * (char)dir) + x;
LABEL_1336:
              addbullet(this, NULL, 815, v546, y, dir, 1, t, 3);
              ++field_7D2;
            }
LABEL_1337:
            ++field_7D4;
          }
        }
LABEL_1338:
        if ( process() )
          set_seq(0);
        if ( get_frame_time() || get_frame() != 10 )
          return;
        field_7D0 = 1;
        play_sfx(12);
        goto LABEL_2175;
      case 525:
        sub10func();
        field_18C = 5;
        if ( get_subseq() == 1 )
        {
          if ( field_194 > 0 )
          {
            if ( field_190 )
            {
              if ( ++field_7D0 >= 5 )
              {
                field_190 = 0;
                field_7D0 = 0;
              }
            }
          }
          if ( !(get_elaps_frames() % 5) )
          {
            play_sfx(29);
            t[0] = 1.0;
            t[1] = (double)scene_rand_rng(5) + 10.0;
            t[2] = 0.0;
            addbullet(this, NULL, 817, (double)(120 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
          }
          if ( !(get_elaps_frames() % 15) )
          {
            /*
            v556 = 0;
            v1164 = 0;
            do
            {
              *(float *)&v1301 = (double)scene_rand_rng(30) + (double)v1164 + 30.0;
              v1302 = 10.0;
              v1303 = 2.0;
              v557 = *(float *)&v1301;
              if ( *(float *)&v1301 < 0.0 || v557 > 180.0 )
              {
                yd = -1;
                xf = dir;
                a1f = y;
                v560 = (double)(120 * (char)xf) + x;
                v559 = v560;
              }
              else
              {
                yd = 1;
                xf = dir;
                a1f = y;
                v558 = (double)(120 * (char)xf) + x;
                v559 = v558;
              }
              v561 = v559;
              addbullet(this, NULL, 817, v561, a1f, xf, yd, (int)&v1301, 3);
              v556 += 60;
              v1164 = v556;
            }
            while ( v556 < 360 );*/
          }
          if ( get_elaps_frames() >= 20 )
            goto LABEL_2433;
        }
        if ( get_subseq() == 3 )
        {
          if ( field_194 > 0 )
          {
            if ( field_190 )
            {
              if ( ++field_7D0 >= 5 )
              {
                field_190 = 0;
                field_7D0 = 0;
              }
            }
          }
          if ( !(get_elaps_frames() % 5) )
          {
            play_sfx(29);
            t[0] = 1.5;
            t[1] = (double)scene_rand_rng(5) + 20.0;
            t[2] = 0.0;
            addbullet(this, NULL, 817, (double)(120 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
          }
          if ( !(get_elaps_frames() % 15) )
          {
            /*
            v566 = 0;
            v1165 = 0;
            do
            {
              *(float *)&v1280 = (double)scene_rand_rng(30) + (double)v1165 + 30.0;
              v1281 = 10.0;
              v1282 = 2.0;
              v567 = *(float *)&v1280;
              if ( *(float *)&v1280 < 0.0 || v567 > 180.0 )
              {
                ye = -1;
                xg = dir;
                a1g = y;
                v570 = (double)(120 * (char)xg) + x;
                v569 = v570;
              }
              else
              {
                ye = 1;
                xg = dir;
                a1g = y;
                v568 = (double)(120 * (char)xg) + x;
                v569 = v568;
              }
              v571 = v569;
              addbullet(this, NULL, 817, v571, a1g, xg, ye, (int)&v1280, 3);
              v566 += 60;
              v1165 = v566;
            }
            while ( v566 < 360 );
            */
          }
          if ( get_elaps_frames() >= 20 )
            goto LABEL_2433;
        }
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() )
          return;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
          goto LABEL_2667;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          scene_add_effect(this, 127, x, y, dir, -1);
          play_sfx(18);
          spell_energy_spend(200, 120);
          add_card_energy(50);
          if ( skills_1[5] >= 4 )
            goto LABEL_1383;
        }
        return;
      case 526:
        sub10func();
        field_18C = 5;
        h_inerc = h_inerc - 0.25;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
        if ( get_subseq() == 1 )
        {
          if ( field_194 > 0 )
          {
            if ( field_190 )
            {
              if ( ++field_7D0 >= 5 )
              {
                field_190 = 0;
                field_7D0 = 0;
              }
            }
          }
          if ( !(get_elaps_frames() % 5) )
          {
            play_sfx(29);
            t[0] = 1.0;
            t[1] = (double)scene_rand_rng(5) + 10.0;
            t[2] = 0.0;
            addbullet(this, NULL, 817, (double)(120 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
          }
          if ( !(get_elaps_frames() % 15) )
          {
            /*
            v577 = 0;
            v1166 = 0;
            do
            {
              *(float *)&v1307 = (double)scene_rand_rng(30) + (double)v1166 + 30.0;
              v1308 = 10.0;
              v1309 = 2.0;
              v578 = *(float *)&v1307;
              if ( *(float *)&v1307 < 0.0 || v578 > 180.0 )
              {
                yf = -1;
                xh = dir;
                a1h = y;
                v581 = (double)(120 * (char)xh) + x;
                v580 = v581;
              }
              else
              {
                yf = 1;
                xh = dir;
                a1h = y;
                v579 = (double)(120 * (char)xh) + x;
                v580 = v579;
              }
              v582 = v580;
              addbullet(this, NULL, 817, v582, a1h, xh, yf, (int)&v1307, 3);
              v577 += 60;
              v1166 = v577;
            }
            while ( v577 < 360 );*/
          }
          if ( get_elaps_frames() >= 65 )
            goto LABEL_2433;
        }
        if ( get_subseq() == 3 )
        {
          if ( field_194 > 0 )
          {
            if ( field_190 )
            {
              if ( ++field_7D0 >= 5 )
              {
                field_190 = 0;
                field_7D0 = 0;
              }
            }
          }
          if ( !(get_elaps_frames() % 5) )
          {
            play_sfx(29);
            t[0] = 1.5;
            t[1] = (double)scene_rand_rng(5) + 20.0;
            t[2] = 0.0;
            addbullet(this, NULL, 817, (double)(120 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
          }
          if ( !(get_elaps_frames() % 15) )
          {
            /*
            v587 = 0;
            v1167 = 0;
            do
            {
              *(float *)&v1325 = (double)scene_rand_rng(30) + (double)v1167 + 30.0;
              v1326 = 10.0;
              v1327 = 2.0;
              v588 = *(float *)&v1325;
              if ( *(float *)&v1325 < 0.0 || v588 > 180.0 )
              {
                yg = -1;
                xi = dir;
                a1i = y;
                v591 = (double)(120 * (char)xi) + x;
                v590 = v591;
              }
              else
              {
                yg = 1;
                xi = dir;
                a1i = y;
                v589 = (double)(120 * (char)xi) + x;
                v590 = v589;
              }
              v592 = v590;
              addbullet(this, NULL, 817, v592, a1i, xi, yg, (int)&v1325, 3);
              v587 += 60;
              v1167 = v587;
            }
            while ( v587 < 360 );*/
          }
          if ( get_elaps_frames() >= 65 )
            goto LABEL_2433;
        }
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() )
          goto LABEL_1426;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
          goto LABEL_2667;
        if ( get_frame_time() || get_frame() || get_subseq() != 1 || (scene_add_effect(this, 127, x, y, dir, -1), play_sfx(18), spell_energy_spend(200, 120), add_card_energy(50), skills_1[5] < 4) )
        {
LABEL_1426:
          if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
            h_inerc = 10.0;
        }
        else
        {
LABEL_1383:
          set_subseq(3);
        }
        return;
      case 530:
        field_18C = 9;
        if ( get_subseq() == 4 )
          sub10func();
        
        if ( !get_subseq() && get_frame() >= 7 )
        {
          h_inerc = field_7F8 /*field_F8*/ + h_inerc;
          if ( h_inerc > 0.0 )
            h_inerc = 0.0;
        }
        if ( get_subseq() != 1 )
          goto LABEL_1454;
        h_inerc = field_7F8 /*field_F8*/ + h_inerc;
        if ( h_inerc > 15.0 )
          h_inerc = 15.0;
        if ( !(get_elaps_frames() % 2) )
        {
          t[0] = -45.0 - (double)scene_rand_rng(90);
          t[1] = (double)scene_rand_rng(5) + 5.0;
          t[2] = 1.0;
          addbullet(this, NULL, 850, (double)(80 * (char)dir) + x, y, dir, 1, t, 3);
          
        }
        if ( field_190 == 1 || field_190 == 7 || field_190 == 2 )
        {
          field_194 = 1;
          field_190 = 0;
          next_subseq();
          
        }
        else
        {
          if ( h_inerc >= 15.0 && keyDown(INP_A) > 0u )
          {
            set_subseq(5);
            field_190 = 0;
            field_194 = 1;
            return;
          }
          if ( h_inerc >= 15.0 && keyDown(INP_B) > 0u/*i64*/ && skills_1[9] >= 2 )
          {
            set_subseq(7);
            field_190 = 0;
            field_194 = 1;
            return;
          }
        }
        if ( get_elaps_frames() >= 50 )
        {
          field_194 = 1;
          field_190 = 0;
          next_subseq();
          return;
        }
LABEL_1454:
        if ( get_subseq() == 2 && get_frame() <= 1 )
        {
          h_inerc = h_inerc - 0.05000000074505806;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          t[0] = -10.0 - (double)scene_rand_rng(60);
          t[1] = (double)scene_rand_rng(5) + 10.0;
          t[2] = 1.0;
          addbullet(this, NULL, 850, (double)(80 * (char)dir) + x, y, dir, 1, t, 3);
          
        }
        if ( get_subseq() != 3 )
          goto LABEL_1462;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_2370;
        
LABEL_1462:
        if ( get_subseq() == 5 && get_frame() <= 1 )
        {
          h_inerc = h_inerc - 0.1000000014901161;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          t[0] = -10.0 - (double)scene_rand_rng(60);
          t[1] = (double)scene_rand_rng(5) + 10.0;
          t[2] = 1.0;
          addbullet(this, NULL, 850, (double)(80 * (char)dir) + x, y, dir, 1, t, 3);
        }
        if ( get_subseq() == 6 || get_subseq() == 8 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_1559;
        }
        if ( process() )
          goto LABEL_1607;
        if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
        {
          h_inerc = -10.0;
          field_7F8 /*field_F8*/ = 1.0;
          play_sfx(50);
          add_card_energy(50);
          spell_energy_spend(200, 120);
        }
        if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 6 )
          play_sfx(16);
        if ( get_subseq() == 6 && !get_frame_time() && get_frame() == 6 )
          play_sfx(16);
        if ( get_subseq() == 8 && !get_frame_time() && get_frame() == 6 )
          play_sfx(16);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            h_inerc = 7.5;
        }
        if ( (get_elaps_frames() == 0) && !get_frame_time() && !get_frame() && get_subseq() == 3 )
        {
          h_inerc = -4.0;
          v_inerc = 7.5;
          v_force = 0.5;
        }
        v611 = get_elaps_frames() == 0;
        if ( get_elaps_frames() )
          goto LABEL_1506;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
          goto LABEL_1592;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 5 )
          goto LABEL_1596;
        v611 = 1;
LABEL_1506:
        if ( v611 && !get_frame_time() && !get_frame() && get_subseq() == 6 )
        {
          h_inerc = 8.0;
          v_inerc = 7.5;
          v_force = 0.5;
        }
        if ( get_elaps_frames() )
          return;
        if ( get_frame_time() || get_frame() || get_subseq() != 7 )
          goto LABEL_1515;
        goto LABEL_1607;
      case 531:
        field_18C = 9;
        if ( get_subseq() == 4 )
          sub10func();
        
        if ( !get_subseq() && get_frame() >= 7 )
        {
          h_inerc = field_7F8 /*field_F8*/ + h_inerc;
          if ( h_inerc > 0.0 )
            h_inerc = 0.0;
        }
        if ( get_subseq() != 1 )
          goto LABEL_1543;
        h_inerc = field_7F8 /*field_F8*/ + h_inerc;
        if ( h_inerc > 15.0 )
          h_inerc = 15.0;
        if ( !(get_elaps_frames() % 2) )
        {
          t[0] = -45.0 - (double)scene_rand_rng(90);
          t[1] = (double)scene_rand_rng(5) + 5.0;
          t[2] = 1.0;
          addbullet(this, NULL, 850, (double)(80 * (char)dir) + x, y, dir, 1, t, 3);
        }
        if ( field_190 == 1 || field_190 == 7 || field_190 == 2 )
        {
          field_194 = 1;
          field_190 = 0;
          next_subseq();
          
        }
        else
        {
          if ( h_inerc >= 15.0 && keyDown(INP_A) > 0u )
          {
            set_subseq(7);
            field_190 = 0;
            field_194 = 1;
            return;
          }
          if ( h_inerc >= 15.0 && keyDown(INP_B) > 0u/*i64*/ && skills_1[9] >= 2 )
          {
            set_subseq(5);
            field_190 = 0;
            field_194 = 1;
            return;
          }
        }
        if ( get_elaps_frames() >= 50 )
        {
          field_194 = 1;
          field_190 = 0;
          next_subseq();
          return;
        }
LABEL_1543:
        if ( get_subseq() == 2 && get_frame() <= 1 )
        {
          h_inerc = h_inerc - 0.05000000074505806;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          t[0] = -10.0 - (double)scene_rand_rng(60);
          t[1] = (double)scene_rand_rng(5) + 10.0;
          t[2] = 1.0;
          addbullet(this, NULL, 850, (double)(80 * (char)dir) + x, y, dir, 1, t, 3);
          
        }
        if ( get_subseq() != 3 )
          goto LABEL_1551;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_2370;
        
LABEL_1551:
        if ( get_subseq() == 5 && get_frame() <= 1 )
        {
          h_inerc = h_inerc - 0.1000000014901161;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          t[0] = -10.0 - (double)scene_rand_rng(60);
          t[1] = (double)scene_rand_rng(5) + 10.0;
          t[2] = 1.0;
          addbullet(this, NULL, 850, (double)(80 * (char)dir) + x, y, dir, 1, t, 3);
        }
        if ( get_subseq() == 6 || get_subseq() == 8 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_1559:
            reset_forces();
            y = getlvl_height();
            set_subseq(4);
            return;
          }
        }
        if ( process() )
          goto LABEL_1607;
        if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
        {
          h_inerc = -10.0;
          field_7F8 /*field_F8*/ = 1.0;
          play_sfx(50);
          add_card_energy(50);
          spell_energy_spend(200, 120);
        }
        if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 6 )
          play_sfx(16);
        if ( get_subseq() == 6 && !get_frame_time() && get_frame() == 6 )
          play_sfx(16);
        if ( get_subseq() == 8 && !get_frame_time() && get_frame() == 6 )
          play_sfx(16);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            h_inerc = 7.5;
        }
        if ( (get_elaps_frames() == 0) && !get_frame_time() && !get_frame() && get_subseq() == 3 )
        {
          h_inerc = -4.0;
          v_inerc = 7.5;
          v_force = 0.5;
        }
        v629 = get_elaps_frames() == 0;
        if ( get_elaps_frames() )
          goto LABEL_1598;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
        {
LABEL_1592:
          set_seq(9);
          return;
        }
        if ( !get_frame_time() && !get_frame() && get_subseq() == 5 )
        {
LABEL_1596:
          set_seq(0);
          reset_forces();
          return;
        }
        v629 = 1;
LABEL_1598:
        if ( v629 && !get_frame_time() && !get_frame() && get_subseq() == 6 )
        {
          h_inerc = 8.0;
          v_inerc = 7.5;
          v_force = 0.5;
        }
        if ( get_elaps_frames() )
          return;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 7 )
          goto LABEL_1607;
LABEL_1515:
        if ( !get_frame_time() && !get_frame() && get_subseq() == 8 )
        {
          h_inerc = 8.0;
          v_inerc = 7.5;
          v_force = 0.5;
        }
        return;
      case 540:
        field_18C = 2;
        if ( get_subseq() == 3 )
          sub10func();
        if ( process() )
          set_seq(9);
        
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1633;
        if ( get_subseq() == 2 )
        {
          if ( enemy->get_seq() <= 599 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 1.0;
            addbullet(this, NULL, 820, x, y + 100.0, dir, 1, t, 3);
            t[1] = 1.0;
            addbullet(this, NULL, 820, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
            t[1] = 0.0;
            t[2] = 2.0;
            addbullet(this, NULL, 820, x, y + 100.0, dir, 1, t, 3);
            t[1] = 1.0;
            addbullet(this, NULL, 820, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
            if ( char_on_ground_flag() )
            {
              /*
              v637 = 0;
              v1168 = 0;
              do
              {
                *(float *)&v1198 = (double)scene_rand_rng(40) + (double)v1168 + 30.0;
                v1199 = 13.0;
                v1200 = 2.0;
                v638 = *(float *)&v1198;
                if ( *(float *)&v1198 < 0.0 || v638 > 180.0 )
                  addbullet(this, NULL, 817, x, y, dir, -1, t, 3);
                else
                  addbullet(this, NULL, 817, x, y, dir, 1, t, 3);
                v637 += 45;
                v1168 = v637;
              }
              while ( v637 < 360 );
              */
            }
            if ( enemy->char_on_ground_flag() )
            {
              /*
              v639 = 0;
              v1169 = 0;
              do
              {
                *(float *)&v1198 = (double)scene_rand_rng(40) + (double)v1169 + 30.0;
                v1199 = 13.0;
                v1200 = 2.0;
                v640 = *(float *)&v1198;
                if ( *(float *)&v1198 < 0.0 || v640 > 180.0 )
                  addbullet(this, NULL, 817, enemy->x, enemy->y, dir, -1, t, 3);
                else
                  addbullet(this, NULL, 817, enemy->x, enemy->y, dir, 1, t, 3);
                v639 += 45;
                v1169 = v639;
              }
              while ( v639 < 360 );
              */
            }
            field_7DC = x;
            dash_angle = y;
            x = enemy->x;
            y = enemy->y;
            enemy->x = field_7DC;
            enemy->y = dash_angle;
            flip_with_force();
          }
          play_sfx(13);
          spell_energy_spend(200, 120);
          add_card_energy(50);
          
          field_7D8 = 1;
LABEL_1633:
          if ( get_subseq() == 2 )
          {
            v643 = 40;
            if ( skills_1[2] >= 1 )
              v643 = 25;
            if ( skills_1[2] >= 4 )
              v643 = 10;
            if ( get_elaps_frames() >= v643 )
            {
              next_subseq();
              
            }
          }
        }
        if ( get_elaps_frames() )
          goto LABEL_1650;
        if ( get_frame_time() || get_frame() || get_subseq() != 3 )
          goto LABEL_1646;
        if ( !char_on_ground_flag() )
          goto LABEL_1793;
        
LABEL_1646:
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
          goto LABEL_1799;
LABEL_1650:
        if ( get_subseq() || get_frame_time() || get_frame() != 2 )
          goto LABEL_1751;
        t[0] = 0.0;
        t[1] = 0.0;
        t[2] = 0.0;
        addbullet(this, NULL, 820, x, y + 100.0, dir, -1, t, 3);
        t[1] = 1.0;
        goto LABEL_1750;
      case 541:
        field_18C = 2;
        if ( get_subseq() == 3 )
          sub10func();
        if ( process() )
          set_seq(9);
        v275 = 1;
        if ( get_subseq() == 1 )
        {
          v649 = 40;
          if ( skills_1[2] >= 1 )
            v649 = 25;
          if ( skills_1[2] >= 4 )
            v649 = 10;
          if ( get_elaps_frames() >= v649 )
            next_subseq();
        }
        
        if ( get_elaps_frames() )
          goto LABEL_1696;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          if ( enemy->get_seq() <= 599 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 1.0;
            addbullet(this, NULL, 820, x, y + 100.0, dir, 1, t, 3);
            t[1] = 1.0;
            addbullet(this, NULL, 820, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
            t[1] = 0.0;
            t[2] = 2.0;
            addbullet(this, NULL, 820, x, y + 100.0, dir, 1, t, 3);
            t[1] = 1.0;
            addbullet(this, NULL, 820, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
            if ( char_on_ground_flag() )
            {
              /*
              v657 = 0;
              v1170 = 0;
              do
              {
                *(float *)&v1204 = (double)scene_rand_rng(40) + (double)v1170 + 30.0;
                v1205 = 13.0;
                v1206 = 2.0;
                v658 = *(float *)&v1204;
                if ( *(float *)&v1204 < 0.0 || v658 > 180.0 )
                  addbullet(this, NULL, 817, x, y, dir, -1, (int)&v1204, 3);
                else
                  addbullet(this, NULL, 817, x, y, dir, 1, (int)&v1204, 3);
                v657 += 45;
                v1170 = v657;
              }
              while ( v657 < 360 );*/
            }
            if ( enemy->char_on_ground_flag() )
            {
              /*
              v659 = 0;
              v1171 = 0;
              do
              {
                *(float *)&v1204 = (double)scene_rand_rng(40) + (double)v1171 + 30.0;
                v1205 = 13.0;
                v1206 = 2.0;
                v660 = *(float *)&v1204;
                if ( *(float *)&v1204 < 0.0 || v660 > 180.0 )
                  addbullet(this, NULL, 817, enemy->x, enemy->y, dir, -1, (int)&v1204, 3);
                else
                  addbullet(this, NULL, 817, enemy->x, enemy->y, dir, 1, (int)&v1204, 3);
                v659 += 45;
                v1171 = v659;
              }
              while ( v659 < 360 );*/
            }
            field_7DC = x;
            dash_angle = y;
            x = enemy->x;
            y = enemy->y;
            enemy->x = field_7DC;
            enemy->y = dash_angle;
            flip_with_force();
          }
          play_sfx(13);
          spell_energy_spend(200, 120);
          add_card_energy(50);
          
          field_7D8 = 1;
        }
        if ( get_elaps_frames() )
          goto LABEL_1696;
        if ( get_frame_time() || get_frame() || get_subseq() != 3 )
          goto LABEL_1692;
        if ( !char_on_ground_flag() )
          goto LABEL_1793;
        
LABEL_1692:
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
          goto LABEL_1799;
LABEL_1696:
        if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
        {
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 820, x, y + 100.0, dir, -1, t, 3);
          t[1] = 1.0;
          addbullet(this, NULL, 820, x, y + 100.0, dir, -1, t, 3);
        }
        if ( get_subseq() == 4 )
        {
LABEL_1701:
          if ( !get_frame_time() && get_frame() == v275 )
            v_force = 0.5;
        }
        return;
      case 542:
        field_18C = 2;
        if ( get_subseq() == 3 )
          sub10func();
        if ( process() )
          set_seq(9);
        
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1729;
        if ( get_subseq() == 2 )
        {
          if ( enemy->get_seq() <= 599 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 1.0;
            addbullet(this, NULL, 820, x, y + 100.0, dir, 1, t, 3);
            t[1] = 1.0;
            addbullet(this, NULL, 820, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
            t[1] = 0.0;
            t[2] = 2.0;
            addbullet(this, NULL, 820, x, y + 100.0, dir, 1, t, 3);
            t[1] = 1.0;
            addbullet(this, NULL, 820, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
            if ( char_on_ground_flag() )
            {
              /*
              v671 = 0;
              v1172 = 0;
              do
              {
                *(float *)&v1210 = (double)scene_rand_rng(40) + (double)v1172 + 30.0;
                v1211 = 13.0;
                v1212 = 2.0;
                v672 = *(float *)&v1210;
                if ( *(float *)&v1210 < 0.0 || v672 > 180.0 )
                  addbullet(this, NULL, 817, x, y, dir, -1, t, 3);
                else
                  addbullet(this, NULL, 817, x, y, dir, 1, t, 3);
                v671 += 45;
                v1172 = v671;
              }
              while ( v671 < 360 );*/
            }
            if ( enemy->char_on_ground_flag() )
            {/*
              v673 = 0;
              v1173 = 0;
              do
              {
                *(float *)&v1210 = (double)scene_rand_rng(40) + (double)v1173 + 30.0;
                v1211 = 13.0;
                v1212 = 2.0;
                v674 = *(float *)&v1210;
                if ( *(float *)&v1210 < 0.0 || v674 > 180.0 )
                  addbullet(this, NULL, 817, enemy->x, enemy->y, dir, -1, t, 3);
                else
                  addbullet(this, NULL, 817, enemy->x, enemy->y, dir, 1, t, 3);
                v673 += 45;
                v1173 = v673;
              }
              while ( v673 < 360 );*/
            }
            field_7DC = x;
            dash_angle = y;
            x = enemy->x;
            y = enemy->y;
            enemy->x = field_7DC;
            enemy->y = dash_angle;
            flip_with_force();
          }
          play_sfx(13);
          spell_energy_spend(200, 120);
          add_card_energy(50);
          
          field_7D8 = 1;
LABEL_1729:
          if ( get_subseq() == 2 )
          {
            v677 = 40;
            if ( skills_1[2] >= 1 )
              v677 = 25;
            if ( skills_1[2] >= 4 )
              v677 = 10;
            if ( get_elaps_frames() >= v677 )
            {
              next_subseq();
              
            }
          }
        }
        if ( get_elaps_frames() )
          goto LABEL_1746;
        if ( get_frame_time() || get_frame() || get_subseq() != 3 )
          goto LABEL_1742;
        if ( !char_on_ground_flag() )
          goto LABEL_1793;
        
LABEL_1742:
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
          goto LABEL_1799;
LABEL_1746:
        if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
        {
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 820, x, y + 100.0, dir, -1, t, 3);
          t[1] = 1.0;
LABEL_1750:
          addbullet(this, NULL, 820, x, y + 100.0, dir, -1, t, 3);
        }
        goto LABEL_1751;
      case 543:
        field_18C = 2;
        if ( get_subseq() == 3 )
          sub10func();
        if ( process() )
          set_seq(9);
        if ( get_subseq() == 1 )
        {
          v683 = 40;
          if ( skills_1[2] >= 1 )
            v683 = 25;
          if ( skills_1[2] >= 4 )
            v683 = 10;
          if ( get_elaps_frames() >= v683 )
            next_subseq();
        }
        
        if ( get_elaps_frames() )
          goto LABEL_1800;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          if ( enemy->get_seq() <= 599 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 1.0;
            addbullet(this, NULL, 820, x, y + 100.0, dir, 1, t, 3);
            t[1] = 1.0;
            addbullet(this, NULL, 820, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
            t[1] = 0.0;
            t[2] = 2.0;
            addbullet(this, NULL, 820, x, y + 100.0, dir, 1, t, 3);
            t[1] = 1.0;
            addbullet(this, NULL, 820, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
            if ( char_on_ground_flag() )
            {
              /*
              v691 = 0;
              v1174 = 0;
              do
              {
                *(float *)&v1201 = (double)scene_rand_rng(40) + (double)v1174 + 30.0;
                v1202 = 13.0;
                v1203 = 2.0;
                v692 = *(float *)&v1201;
                if ( *(float *)&v1201 < 0.0 || v692 > 180.0 )
                  addbullet(this, NULL, 817, x, y, dir, -1, t, 3);
                else
                  addbullet(this, NULL, 817, x, y, dir, 1, t, 3);
                v691 += 45;
                v1174 = v691;
              }
              while ( v691 < 360 );*/
            }
            if ( enemy->char_on_ground_flag() )
            {
              /*
              v693 = 0;
              v1175 = 0;
              do
              {
                *(float *)&v1201 = (double)scene_rand_rng(40) + (double)v1175 + 30.0;
                v1202 = 13.0;
                v1203 = 2.0;
                v694 = *(float *)&v1201;
                if ( *(float *)&v1201 < 0.0 || v694 > 180.0 )
                  addbullet(this, NULL, 817, enemy->x, enemy->y, dir, -1, t, 3);
                else
                  addbullet(this, NULL, 817, enemy->x, enemy->y, dir, 1, t, 3);
                v693 += 45;
                v1175 = v693;
              }
              while ( v693 < 360 );*/
            }
            field_7DC = x;
            dash_angle = y;
            x = enemy->x;
            y = enemy->y;
            enemy->x = field_7DC;
            enemy->y = dash_angle;
            flip_with_force();
          }
          play_sfx(13);
          spell_energy_spend(200, 120);
          add_card_energy(50);
          
          field_7D8 = 1;
        }
        if ( get_elaps_frames() )
          goto LABEL_1800;
        if ( get_frame_time() || get_frame() || get_subseq() != 3 )
          goto LABEL_1795;
        if ( !char_on_ground_flag() )
        {
LABEL_1793:
          set_subseq(4);
          return;
        }
        
LABEL_1795:
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
        {
LABEL_1799:
          set_seq(0);
          return;
        }
LABEL_1800:
        if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
        {
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 820, x, y + 100.0, dir, -1, t, 3);
          t[1] = 1.0;
          addbullet(this, NULL, 820, x, y + 100.0, dir, -1, t, 3);
        }
        if ( get_subseq() != 4 || get_frame_time() )
          return;
        goto LABEL_1754;
      case 545:
        sub10func();
        field_18C = 6;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(0);
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1825;
        if ( get_frame() == 7 && not_charge_attack )
        {
          next_subseq();
          scene_add_effect(this, 62, x - (double)(100 * (char)dir), y + 164.0, dir, 1);
          return;
        }
        if ( get_frame() == 10 )
        {
          t[0] = 1.2;
          if ( skills_1[6] >= 3 )
            t[0] = 1.5;
          t[1] = 10.0;
          t[2] = 0.0;
          addbullet(this, NULL, 821, (double)(200 * (char)dir) + x, y, dir, 1, t, 3);
          t[2] = 4.0;
          addbullet(this, NULL, 821, (double)(200 * (char)dir) + x, y, dir, -1, t, 3);
          spell_energy_spend(200, 120);
          add_card_energy(50);
          play_sfx(19);
        }
LABEL_1825:
        if ( get_subseq() != 1 || get_frame_time() || get_frame() != 4 )
          return;
        t[0] = 2.0;
        if ( skills_1[6] >= 3 )
          t[0] = 2.25;
        t[1] = 10.0;
        t[2] = 0.0;
        addbullet(this, NULL, 821, (double)(200 * dir) + x, y, dir, 1, t, 3);
        t[2] = 4.0;
        goto LABEL_1855;
      case 546:
        sub10func();
        field_18C = 6;
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(0);
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1849;
        if ( get_frame() == 7 && not_charge_attack )
        {
          next_subseq();
          scene_add_effect(this, 62, x - (double)(100 * (char)dir), y + 164.0, dir, 1);
        }
        else
        {
          if ( get_frame() == 10 )
          {
            t[0] = 1.2;
            if ( skills_1[6] >= 3 )
              t[0] = 1.5;
            t[1] = 10.0;
            t[2] = 0.0;
            addbullet(this, NULL, 821, enemy->x, y, dir, 1, t, 3);
            t[2] = 4.0;
            addbullet(this, NULL, 821, enemy->x, y, dir, -1, t, 3);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(19);
          }
LABEL_1849:
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 4 )
          {
            t[0] = 2.0;
            if ( skills_1[6] >= 3 )
              t[0] = 2.25;
            t[1] = 10.0;
            t[2] = 0.0;
            addbullet(this, NULL, 821, (double)(200 * dir) + x, y, dir, 1, t, 3);
            t[2] = 4.0;
LABEL_1855:
            addbullet(this, NULL, 821, (double)(200 * (char)dir) + x, y, dir, -1, t, 3);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(19);
          }
        }
        return;
      case 550:
        sub10func();
        field_18C = 10;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( !get_subseq() && get_frame() >= 4 )
        {
          field_7DC = field_7DC + 0.2000000029802322;
          if ( ((double)(char)skills_1[10] * 1.5 + 4.0) < field_7DC )
            field_7DC = (double)(char)skills_1[10] * 1.5 + 4.0;
          field_74C = field_7DC;
          if ( x < (double)enemy->x && enemy->dir == 1 || x > (double)enemy->x && enemy->dir == -1 )
            field_74C = -field_7DC;
        }
        if ( get_subseq() != 1 )
          goto LABEL_1883;
        field_7DC = field_7DC + 0.2000000029802322;
        if ( (1.5 * (double)(char)skills_1[10] + 4.0) < field_7DC )
          field_7DC = 1.5 * (double)(char)skills_1[10] + 4.0;
        if ( !(get_elaps_frames() % 3) )
        {
          t[0] = (double)scene_rand_rng(360);
          t[1] = (double)scene_rand_rng(150) + 250.0;
          t[2] = 0.0;
          addbullet(this, NULL, 822, x, y, dir, 1, t, 3);
        }
        field_74C = field_7DC;
        if ( x < (double)enemy->x && enemy->dir == 1 || x > (double)enemy->x && enemy->dir == -1 )
          field_74C = -field_7DC;
        if ( get_elaps_frames() < 4 )
          goto LABEL_1883;
        if ( not_charge_attack && get_elaps_frames() < 90 )
        {
          if ( keyDown(INP_C) > 0u )
            goto LABEL_1949;
LABEL_1883:
          if ( get_subseq() == 2 )
          {
            field_7DC = field_7DC - 0.4000000059604645;
            if ( field_7DC < 0.0 )
              field_7DC = 0.0;
            field_74C = field_7DC;
            if ( dir == enemy->dir )
              field_74C = -field_7DC;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
                set_seq(0);
            }
          }
          if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
          {
            spell_energy_spend(200, 120);
            add_card_energy(50);
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            play_sfx(20);
            field_190 = 1;
          }
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 3 )
          {
            play_sfx(16);
            /*
            v726 = 0;
            v1176 = 0;
            do
            {
              *(float *)&v1304 = (double)scene_rand_rng(30) + (double)v1176 + 30.0;
              v1305 = 10.0;
              v1306 = 2.0;
              v727 = *(float *)&v1304;
              if ( *(float *)&v1304 < 0.0 || v727 > 180.0 )
              {
                yh = -1;
                xk = dir;
                a1k = y;
                v730 = (double)(120 * (char)xk) + x;
                v729 = v730;
              }
              else
              {
                yh = 1;
                xk = dir;
                a1k = y;
                v728 = (double)(120 * (char)xk) + x;
                v729 = v728;
              }
              v731 = v729;
              addbullet(this, NULL, 817, v731, a1k, xk, yh, (int)&v1304, 3);
              v726 += 60;
              v1176 = v726;
            }
            while ( v726 < 360 );*/
          }
        }
        else
        {
          next_subseq();
          field_190 = 0;
        }
        return;
      case 551:
        sub10func();
        field_18C = 10;
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( !get_subseq() && get_frame() >= 4 )
        {
          field_7DC = field_7DC + 0.2000000029802322;
          if ( ((double)skills_1[10] * 1.5 + 4.0) < field_7DC )
            field_7DC = (double)skills_1[10] * 1.5 + 4.0;
          field_74C = field_7DC;
          if ( x < (double)enemy->x && enemy->dir == 1 || x > (double)enemy->x && enemy->dir == -1 )
            field_74C = -field_7DC;
        }
        if ( get_subseq() != 1 )
          goto LABEL_1955;
        field_7DC = field_7DC + 0.2000000029802322;
        if ( (1.5 * (double)(char)skills_1[10] + 4.0) < field_7DC )
          field_7DC = 1.5 * (double)(char)skills_1[10] + 4.0;
        if ( !(get_elaps_frames() % 3) )
        {
          t[0] = (double)scene_rand_rng(360);
          t[1] = (double)scene_rand_rng(150) + 250.0;
          t[2] = 0.0;
          addbullet(this, NULL, 822, x, y, dir, 1, t, 3);
        }
        field_74C = field_7DC;
        if ( x < (double)enemy->x && enemy->dir == 1 || x > (double)enemy->x && enemy->dir == -1 )
          field_74C = -field_7DC;
        if ( get_elaps_frames() < 4 )
          goto LABEL_1955;
        if ( not_charge_attack && get_elaps_frames() < 90 )
        {
          if ( keyDown(INP_C) <= 0u )
          {
LABEL_1955:
            if ( get_subseq() == 2 )
            {
              field_7DC = field_7DC - 0.4000000059604645;
              if ( field_7DC < 0.0 )
                field_7DC = 0.0;
              field_74C = field_7DC;
              if ( dir == enemy->dir )
                field_74C = -field_7DC;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
                set_seq(0);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                  set_seq(0);
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
                  set_seq(0);
              }
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(20);
              field_190 = 1;
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 3 )
            {
              play_sfx(16);
              /*
              v743 = 0;
              v1177 = 0;
              do
              {
                *(float *)&v1310 = (double)scene_rand_rng(30) + (double)v1177 + 30.0;
                v1311 = 10.0;
                v1312 = 2.0;
                v744 = *(float *)&v1310;
                if ( *(float *)&v1310 < 0.0 || v744 > 180.0 )
                {
                  yi = -1;
                  xl = dir;
                  a1l = y;
                  v747 = (double)(120 * (char)xl) + x;
                  v746 = v747;
                }
                else
                {
                  yi = 1;
                  xl = dir;
                  a1l = y;
                  v745 = (double)(120 * (char)xl) + x;
                  v746 = v745;
                }
                v748 = v746;
                addbullet(this, NULL, 817, v748, a1l, xl, yi, (int)&v1310, 3);
                v743 += 60;
                v1177 = v743;
              }
              while ( v743 < 360 );*/
            }
          }
          else
          {
LABEL_1949:
            v740 = 3;
            if ( skills_1[10] >= 2 )
              v740 = 4;
            if ( skills_1[10] >= 3 )
              v740 = 5;
            set_subseq(v740);
            field_190 = 0;
          }
        }
        else
        {
          next_subseq();
          field_190 = 0;
        }
        return;
      case 560:
        sub10func();
        field_18C = 3;
        if ( get_subseq() < 2 && !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( field_7D0 != 1 )
          goto LABEL_2011;
        if ( get_subseq() )
        {
          if ( field_7D2 % 6 )
            goto LABEL_2010;
          field_190 = 1;
          if ( field_7D4 < (skills_1[3] >= 4) + 3 )
          {
            play_sfx(14);
            t[0] = field_7E4 - (double)field_7D4 * 25.0 + 25.0;
            t[1] = 7.0;
            t[2] = 0.0;
            goto LABEL_2007;
          }
          if ( field_7D6 < (skills_1[3] >= 4) + 2 )
          {
            play_sfx(14);
            t[0] = field_7E4 - (double)field_7D6 * 25.0 + 12.5;
            t[1] = 7.0;
            t[2] = 0.0;
            addbullet(this, NULL, 825, (double)(90 * (char)dir) + x, y + 180.0, dir, 1, t, 3);
            ++field_7D6;
          }
        }
        else if ( !(field_7D2 % 6) )
        {
          field_190 = 1;
          if ( field_7D4 < (skills_1[3] >= 4) + 3 )
          {
            play_sfx(14);
            t[0] = field_7E4 - (double)field_7D4 * 25.0 + 25.0;
            t[1] = 7.0;
            t[2] = 0.0;
LABEL_2007:
            addbullet(this, NULL, 825, (double)(90 * dir) + x, y + 180.0, dir, 1, t, 3);
            ++field_7D4;
            goto LABEL_2010;
          }
        }
LABEL_2010:
        ++field_7D2;
LABEL_2011:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1064;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 3 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, (double)(10 * (char)dir) + x, y + 135.0, dir, 1);
            return;
          }
          if ( get_frame() == 5 )
          {
            field_7D0 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -20.0 )
              field_7E4 = -20.0;
            if ( field_7E4 > 10.0 )
              field_7E4 = 10.0;
          }
        }
        if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
          return;
        field_7D0 = 1;
        spell_energy_spend(200, 120);
        add_card_energy(50);
        goto LABEL_2066;
      case 561:
        sub10func();
        field_18C = 3;
        if ( get_subseq() < 2 && !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( field_7D0 != 1 )
          goto LABEL_2046;
        if ( get_subseq() )
        {
          if ( field_7D2 % 6 )
            goto LABEL_2045;
          field_190 = 1;
          if ( field_7D4 < (skills_1[3] >= 4) + 3 )
          {
            play_sfx(14);
            t[0] = field_7E4 - (double)field_7D4 * 25.0 - 25.0;
            t[1] = 7.0;
            t[2] = 0.0;
            goto LABEL_2042;
          }
          if ( field_7D6 < (skills_1[3] >= 4) + 2 )
          {
            play_sfx(14);
            t[0] = field_7E4 - (double)field_7D6 * 25.0 - 37.5;
            t[1] = 7.0;
            t[2] = 0.0;
            addbullet(this, NULL, 825, (double)(90 * (char)dir) + x, y + 180.0, dir, 1, t, 3);
            ++field_7D6;
          }
        }
        else if ( !(field_7D2 % 6) )
        {
          field_190 = 1;
          if ( field_7D4 < (skills_1[3] >= 4) + 3 )
          {
            play_sfx(14);
            t[0] = field_7E4 - (double)field_7D4 * 25.0 - 25.0;
            t[1] = 7.0;
            t[2] = 0.0;
LABEL_2042:
            addbullet(this, NULL, 825, (double)(90 * dir) + x, y + 180.0, dir, 1, t, 3);
            ++field_7D4;
            goto LABEL_2045;
          }
        }
LABEL_2045:
        ++field_7D2;
LABEL_2046:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
LABEL_1064:
          set_seq(0);
          return;
        }
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 3 && not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, (double)(10 * (char)dir) + x, y + 135.0, dir, 1);
            return;
          }
          if ( get_frame() == 5 )
          {
            field_7D0 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -20.0 )
              field_7E4 = -20.0;
            if ( field_7E4 > 10.0 )
              field_7E4 = 10.0;
          }
        }
        if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
        {
          field_7D0 = 1;
          spell_energy_spend(200, 120);
          add_card_energy(50);
LABEL_2066:
          field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7E4 < -20.0 )
            field_7E4 = -20.0;
          if ( field_7E4 > 10.0 )
            field_7E4 = 10.0;
          return;
        }
        break;
      case 562:
        if ( get_subseq() == 5 )
          sub10func();
        field_18C = 3;
        v_inerc = v_inerc - v_force;
        if ( getlvl_height() >= (v_inerc + y) && v_inerc < 0.0 && get_subseq() < 5 )
        {
          set_subseq(5);
          goto LABEL_2182;
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
                t[0] = ((double)field_7D4 + 30.0) - scene_rand() % 60 - 30.0;
                t[1] = 15.0;
                t[2] = (double)scene_rand_rng(4);
              }
              else
              {
                t[0] = ((double)field_7D4 + 30.0) - scene_rand() % 60 - 30.0;
                t[1] = 15.0;
                t[2] = (double)scene_rand_rng(4);
              }
              addbullet(this, NULL, 808, (double)(44 * (char)dir) + x, y + 85.0, dir, 1, t, 3);
            }
            ++field_7D0;
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
        {
LABEL_995:
          set_seq(9);
          return;
        }
        if ( get_subseq() == 1 && get_elaps_frames() > 4 && (!not_charge_attack || get_elaps_frames() > 25) )
          next_subseq();
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          if ( not_charge_attack == 1 )
          {
            scene_add_effect(this, 62, x - (double)(23 * (char)dir), y + 107.0, dir, 1);
          }
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 4.0;
          addbullet(this, NULL, 808, x - (double)(23 * (char)dir), y + 107.0, dir, 1, t, 3);
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
        goto LABEL_2215;
      case 565:
        sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( field_7D0 == 1 )
        {
          if ( !get_subseq() )
          {
            if ( !(field_7D2 % 5) && field_7D4 < 1 )
            {
              play_sfx(14);
              t[0] = (double)field_7D4 * -60.0;
              t[1] = 7.0;
              t[2] = 0.0;
              addbullet(this, NULL, 827, (double)(90 * (char)dir) + x, y + 180.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( get_subseq() == 1 )
          {
            if ( !(field_7D2 % 5) && field_7D4 < 2 )
            {
              play_sfx(14);
              t[0] = 45.0 - (double)field_7D4 * 90.0;
              t[1] = 7.0;
              t[2] = 0.0;
              addbullet(this, NULL, 827, (double)(90 * (char)dir) + x, y + 180.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(0);
        if ( get_subseq() || get_frame_time() )
          goto LABEL_2171;
        if ( get_frame() != 3 || !not_charge_attack )
          goto LABEL_2169;
        next_subseq();
        scene_add_effect(this, 62, (double)(10 * (char)dir) + x, y + 135.0, dir, 1);
        return;
      case 566:
        sub10func();
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( field_7D0 == 1 )
        {
          if ( !get_subseq() )
          {
            if ( !(field_7D2 % 5) && field_7D4 < 1 )
            {
              play_sfx(14);
              t[0] = (double)field_7D4 * -60.0;
              t[1] = 7.0;
              t[2] = 0.0;
              addbullet(this, NULL, 827, (double)(90 * (char)dir) + x, y + 180.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( get_subseq() == 1 )
          {
            if ( !(field_7D2 % 5) && field_7D4 < 2 )
            {
              play_sfx(14);
              t[0] = 45.0 - (double)field_7D4 * 90.0;
              t[1] = 7.0;
              t[2] = 0.0;
              addbullet(this, NULL, 827, (double)(90 * (char)dir) + x, y + 180.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(0);
        if ( get_subseq() || get_frame_time() )
          goto LABEL_2171;
        if ( get_frame() == 3 && not_charge_attack )
        {
          next_subseq();
          scene_add_effect(this, 62, (double)(10 * (char)dir) + x, y + 135.0, dir, 1);
        }
        else
        {
LABEL_2169:
          if ( get_frame() == 4 )
          {
            field_7D0 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
          }
LABEL_2171:
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
          {
            field_7D0 = 1;
LABEL_2175:
            spell_energy_spend(200, 120);
            add_card_energy(50);
          }
        }
        return;
      case 567:
        if ( get_subseq() == 5 )
          sub10func();
        field_18C = 7;
        v_inerc = v_inerc - v_force;
        if ( getlvl_height() < (v_inerc + y) || v_inerc >= 0.0 || get_subseq() >= 5 )
        {
          if ( get_subseq() < 2 && !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( get_subseq() == 2 && get_frame() == 2 && !get_frame_time() )
          {
            field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7D4 < -10 )
              field_7D4 = -10;
            if ( field_7D4 > 10 )
              field_7D4 = 10;
            play_sfx(29);
            field_190 = 1;
            spell_energy_spend(200, 60);
            add_card_energy(50);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 824, (double)(48 * (char)dir) + x, y + 104.0, dir, 1, t, 3);
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 4.0;
            addbullet(this, NULL, 824, x - (double)(48 * (char)dir), y + 104.0, dir, 1, t, 3);
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 5 )
          {
            if ( get_subseq() == 1 && get_elaps_frames() > 10 && (!not_charge_attack || get_elaps_frames() > 25) )
              next_subseq();
            if ( get_subseq() == 3 && get_elaps_frames() > 40 )
              next_subseq();
LABEL_2215:
            if ( get_subseq() == 4 && !get_frame_time() && get_frame() == 5 )
              v_force = 0.60000002;
          }
          else
          {
LABEL_1607:
            set_seq(9);
          }
        }
        else
        {
          set_subseq(5);
LABEL_2182:
          v_force = 0.0;
LABEL_2183:
          air_dash_cnt = 0;
LABEL_2184:
          y = getlvl_height();
          reset_forces();
        }
        return;
      case 570:
        sub10func();
        field_18C = 11;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
        {
          spell_energy_spend(200, 120);
          add_card_energy(50);
          field_190 = 1;
          play_sfx(21);
          /*
          v867 = 0;
          v1178 = 0;
          do
          {
            *(float *)&v1219 = (double)scene_rand_rng(30) + (double)v1178 + 30.0;
            v1220 = 10.0;
            v1221 = 2.0;
            v868 = *(float *)&v1219;
            if ( *(float *)&v1219 < 0.0 || v868 > 180.0 )
            {
              yj = -1;
              xo = dir;
              a1o = y;
              v871 = (double)(180 * (char)xo) + x;
              v870 = v871;
            }
            else
            {
              yj = 1;
              xo = dir;
              a1o = y;
              v869 = (double)(180 * (char)xo) + x;
              v870 = v869;
            }
            v872 = v870;
            addbullet(this, NULL, 817, v872, a1o, xo, yj, t, 3);
            v867 += 60;
            v1178 = v867;
          }
          while ( v867 < 360 );
          */
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 830, x, y, dir, 1, t, 3);
          field_894 = 2;
          t[0] = 0.0;
          t[1] = 88.0;
          t[2] = 4.0;
          addbullet(this, NULL, 801, (double)(84 * (char)dir) + x, y, dir, -1, t, 3);
          t[0] = (double)scene_rand_rng(80) - 40.0;
          t[1] = (double)scene_rand_rng(80) - 40.0;
          addbullet(this, NULL, 801, (double)(84 * (char)dir) + x, y, dir, 1, t, 3);
          t[0] = (double)scene_rand_rng(80) - 40.0;
          t[1] = (double)scene_rand_rng(80) - 40.0;
          addbullet(this, NULL, 801, (double)(84 * (char)dir) + x, y, dir, 1, t, 3);
        }
        return;
      case 571:
        sub10func();
        field_18C = 11;
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 11 )
        {
          spell_energy_spend(200, 120);
          add_card_energy(50);
          field_190 = 1;
          play_sfx(21);
          /*
          v879 = 0;
          v1179 = 0;
          do
          {
            t[0] = (double)scene_rand_rng(30) + (double)v1179 + 30.0;
            t[1] = 10.0;
            t[2] = 2.0;
            v880 = t[0];
            if ( t[0] < 0.0 || v880 > 180.0 )
            {
              yk = -1;
              xp = dir;
              a1p = y;
              v883 = (double)(180 * (char)xp) + x;
              v882 = v883;
            }
            else
            {
              yk = 1;
              xp = dir;
              a1p = y;
              v881 = (double)(180 * (char)xp) + x;
              v882 = v881;
            }
            v884 = v882;
            addbullet(this, NULL, 817, v884, a1p, xp, yk, t, 3);
            v879 += 60;
            v1179 = v879;
          }
          while ( v879 < 360 );*/
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 5.0;
          addbullet(this, NULL, 830, x, y, dir, 1, t, 3);
          field_894 = 2;
          t[0] = 0.0;
          t[1] = 88.0;
          t[2] = 4.0;
          addbullet(this, NULL, 801, (double)(84 * (char)dir) + x, y, dir, -1, t, 3);
          t[0] = (double)scene_rand_rng(80) - 40.0;
          t[1] = (double)scene_rand_rng(80) - 40.0;
          addbullet(this, NULL, 801, (double)(84 * (char)dir) + x, y, dir, 1, t, 3);
          t[0] = (double)scene_rand_rng(80) - 40.0;
          t[1] = (double)scene_rand_rng(80) - 40.0;
          addbullet(this, NULL, 801, (double)(84 * (char)dir) + x, y, dir, 1, t, 3);
        }
        return;
      case 600:
        if ( !get_subseq() && get_frame() >= 10 || get_subseq() == 1 || get_subseq() == 4 )
          sub10func();
        sub_46AB50(4, 2);
        if ( get_subseq() == 1 )
        {
          h_inerc = field_7F8 /*field_F8*/ + h_inerc;
          if ( h_inerc > 25.0 )
            h_inerc = 17.5;
          v97 = 0;
          if ( field_190 )
          {
            if ( ++field_7D0 >= 10 )
            {
              field_7D0 = 0;
              field_194 = 1;
              field_190 = 0;
            }
          }
          if ( !(get_elaps_frames() % 2) )
          {
            t[0] = -45.0 - (double)scene_rand_rng(90);
            t[1] = (double)scene_rand_rng(5) + 5.0;
            t[2] = 1.0;
            addbullet(this, NULL, 850, (double)(80 * (char)dir) + x, y, dir, 1, t, 3);
          }
          if ( get_elaps_frames() >= 50 )
          {
            field_194 = 1;
            field_190 = 0;
            next_subseq();
            return;
          }
        }
        else
        {
          v97 = 0;
        }
        if ( get_subseq() == 2 && get_frame() <= 1 )
        {
          h_inerc = h_inerc - 1.0;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          t[0] = -10.0 - (double)scene_rand_rng(60);
          t[1] = (double)scene_rand_rng(5) + 10.0;
          t[2] = 1.0;
          addbullet(this, NULL, 850, (double)(80 * (char)dir) + x, y, dir, 1, t, 3);
        }
        if ( get_subseq() == 3 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
        {
LABEL_2370:
          reset_forces();
          y = getlvl_height();
          next_subseq();
        }
        else if ( process() )
        {
LABEL_2271:
          set_seq(v97);
          reset_forces();
        }
        else
        {
          if ( get_subseq() == v97 && get_frame_time() == v97 )
          {
            if ( get_frame() == 2 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 100.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( get_frame_time() == v97 && get_frame() == 11 )
            {
              h_inerc = 5.0;
              field_7F8 /*field_F8*/ = 1.0;
              play_sfx(50);
            }
          }
          if ( !get_elaps_frames() && get_frame_time() == v97 && get_frame() == v97 && get_subseq() == 3 )
          {
            v899 = -10.0;
LABEL_2382:
            h_inerc = v899;
            v_inerc = 8.0;
            v_force = 0.75;
          }
        }
        return;
      case 601:
        sub_46AB50(4, 2);
        sub10func();
        if ( get_subseq() || field_190 != 1 )
        {
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(71 * (char)dir) + x, y + 73.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 4 )
                h_inerc = 20.0;
              if ( !get_frame_time() )
              {
                if ( get_frame() == 7 )
                {
                  /*
                  v906 = 0;
                  v1180 = 0;
                  do
                  {
                    *(float *)&v1316 = (double)scene_rand_rng(40) + (double)v1180 + 30.0;
                    v1317 = 13.0;
                    v1318 = 2.0;
                    v907 = *(float *)&v1316;
                    if ( *(float *)&v1316 < 0.0 || v907 > 180.0 )
                    {
                      yl = -1;
                      xq = dir;
                      a1q = y;
                      v910 = (double)(120 * (char)xq) + x;
                      v909 = v910;
                    }
                    else
                    {
                      yl = 1;
                      xq = dir;
                      a1q = y;
                      v908 = (double)(120 * (char)xq) + x;
                      v909 = v908;
                    }
                    v911 = v909;
                    addbullet(this, NULL, 817, v911, a1q, xq, yl, (int)&v1316, 3);
                    v906 += 45;
                    v1180 = v906;
                  }
                  while ( v906 < 360 );
                  */
                }
                if ( !get_frame_time() && get_frame() == 8 )
                  h_inerc = 0.0;
              }
            }
          }
          if ( get_subseq() == 1 && !get_frame_time() )
          {
            if ( get_frame() == 3 )
              play_sfx(51);
            if ( !get_frame_time() && get_frame() == 14 )
            {
              field_7DC = (double)enemy->health * 0.5;
              if ( field_7DC <= 1.0 )
                field_7DC = 0.0;
              sub_464110(field_7DC, 850, 1, 0);
              enemy->field_1A4 = 35.0;
              enemy->field_1A8 = 15.0;
              enemy->damage_limit = 100;
              enemy->set_seq(74);
              play_sfx(52);
              //shake_camera(20.0);
              scene_add_effect(this, 12, enemy->x, enemy->y + 100.0, dir, 1);
              /*
              v915 = 0;
              v1181 = 0;
              do
              {
                *(float *)&v1322 = (double)scene_rand_rng(40) + (double)v1181 + 30.0;
                v1323 = 13.0;
                v1324 = 2.0;
                v916 = *(float *)&v1322;
                if ( *(float *)&v1322 < 0.0 || v916 > 180.0 )
                {
                  ym = -1;
                  xr = dir;
                  a1r = y;
                  v919 = (double)(120 * (char)xr) + x;
                  v918 = v919;
                }
                else
                {
                  ym = 1;
                  xr = dir;
                  a1r = y;
                  v917 = (double)(120 * (char)xr) + x;
                  v918 = v917;
                }
                v920 = v918;
                addbullet(this, NULL, 817, v920, a1r, xr, ym, (int)&v1322, 3);
                v915 += 45;
                v1181 = v915;
              }
              while ( v915 < 360 );*/
            }
          }
        }
        else
        {
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 1.0;
          addbullet(this, NULL, 851, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
          enemy->set_seq(102);
          enemy->reset_forces();
          next_subseq();
        }
        return;
      case 602:
        sub_46AB50(4, 2);
        sub10func();
        if ( field_7D0 == 1 && !get_subseq() )
        {
          if ( !(field_7D2 % 5) )
          {
            field_190 = 1;
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -10.0 )
              field_7E4 = -10.0;
            if ( field_7E4 > 10.0 )
              field_7E4 = 10.0;
            play_sfx(14);
            if ( field_7D4 < 5 )
            {
              t[0] = field_7E4 - (double)field_7D4 * 18.0 + 25.0;
              t[1] = 7.0;
              t[2] = 0.0;
              addbullet(this, NULL, 852, (double)(90 * (char)dir) + x, y + 180.0, dir, 1, t, 3);
              ++field_7D4;
            }
          }
          ++field_7D2;
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 2 )
          {
            field_4A6 = 40;
            scene_play_sfx(23);
            scene_add_effect(this, 115, x, y + 140.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_frame_time() && get_frame() == 4 )
            field_7D0 = 1;
        }
        return;
      case 603:
        if ( !get_subseq() && get_frame() >= 10 || get_subseq() == 1 || get_subseq() == 4 )
          sub10func();
        sub_46AB50(4, 2);
        if ( get_subseq() == 1 )
        {
          h_inerc = h_inerc + 0.1000000014901161;
          if ( h_inerc > 4.0 )
            h_inerc = 3.0;
          if ( !(get_elaps_frames() % 2) )
          {
            t[0] = -45.0 - (double)scene_rand_rng(90);
            t[1] = (double)scene_rand_rng(5) + 5.0;
            t[2] = 3.0;
            addbullet(this, NULL, 853, (double)(80 * (char)dir) + x, y, dir, 1, t, 3);
          }
          if ( !(get_elaps_frames() % 4) && get_elaps_frames() <= 120 )
          {
            t[0] = (double)scene_rand_rng(12) + 6.0;
            t[1] = (double)scene_rand_rng(8) + 2.0;
            t[2] = 0.0;
            if ( dir == 1 )
            {
              xs = 1;
              //v1182 = flt_88563C - 50.0;
              v1182 = -50.0;
            }
            else
            {
              xs = dir;
              //v1182 = flt_885644 + 50.0;
              v1182 = 50.0;
            }
            addbullet(this, NULL, 853, v1182, (double)scene_rand_rng(300) + y + 20.0, xs, 1, t, 3);
          }
          if ( get_elaps_frames() >= 150 )
            goto LABEL_2433;
        }
        if ( get_subseq() == 2 && get_frame() <= 1 )
        {
          h_inerc = h_inerc - 0.1000000014901161;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          t[0] = -10.0 - (double)scene_rand_rng(60);
          t[1] = (double)scene_rand_rng(5) + 10.0;
          t[2] = 3.0;
          addbullet(this, NULL, 853, (double)(80 * (char)dir) + x, y, dir, 1, t, 3);
        }
        if ( get_subseq() == 3 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_2370;
        }
        if ( process() )
        {
          set_seq(0);
          reset_forces();
        }
        if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
        {
          field_4A6 = 40;
          scene_play_sfx(23);
          scene_add_effect(this, 115, x, y + 100.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 3 )
          return;
        v899 = -3.0;
        goto LABEL_2382;
      case 604:
        sub_46AB50(4, 2);
        sub10func();
        if ( get_subseq() || field_190 != 1 )
        {
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(71 * (char)dir) + x, y + 73.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() && get_frame() == 6 )
            {
              /*
              v947 = 0;
              v1183 = 0;
              do
              {
                *(float *)&v1328 = (double)scene_rand_rng(40) + (double)v1183 + 30.0;
                v1329 = 13.0;
                v1330 = 2.0;
                v948 = *(float *)&v1328;
                if ( *(float *)&v1328 < 0.0 || v948 > 180.0 )
                {
                  yn = -1;
                  xt = dir;
                  a1t = y;
                  v951 = (double)(120 * (char)xt) + x;
                  v950 = v951;
                }
                else
                {
                  yn = 1;
                  xt = dir;
                  a1t = y;
                  v949 = (double)(120 * (char)xt) + x;
                  v950 = v949;
                }
                v952 = v950;
                addbullet(this, NULL, 817, v952, a1t, xt, yn, (int)&v1328, 3);
                v947 += 45;
                v1183 = v947;
              }
              while ( v947 < 360 );*/
            }
          }
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
            play_sfx(51);
          if ( get_subseq() == 2 )
          {
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() )
            {
              /*
              v1195 = 0.0;
              v953 = (float)0.0;
              do
              {
                *(float *)&v1262 = v953 * 45.0;
                v1263 = 0.0;
                v1264 = 0.0;
                v954 = y + 100.0;
                addbullet(this, NULL, 854, x, v954, dir, 1, (int)&v1262, 3);
                v1195 = v1195 + 1.0;
                v953 = v1195;
              }
              while ( v1195 < 8.0 );
              v1196 = 0.0;
              v955 = (float)0.0;
              do
              {
                *(float *)&v1262 = v955 * 45.0;
                v1263 = 0.0;
                v1264 = 1.0;
                v956 = enemy;
                v957 = v956->y + 100.0;
                addbullet(this, NULL, 854, v956->x, v957, dir, 1, (int)&v1262, 3);
                v1196 = v1196 + 1.0;
                v955 = v1196;
              }
              while ( v1196 < 8.0 );*/
              play_sfx(55);
            }
            if ( field_7D0 == 1 )
            {
              field_7DC = (double)enemy->health;
              dash_angle = (double)health;
              enemy->health = (double)health;
              health = field_7DC;
              //shake_camera(3.0);
              /*
              v960 = 0;
              v1184 = 0;
              do
              {
                *(float *)&v1213 = (double)scene_rand_rng(40) + (double)v1184 + 30.0;
                v1214 = 13.0;
                v1215 = 2.0;
                v961 = *(float *)&v1213;
                if ( *(float *)&v1213 < 0.0 || v961 > 180.0 )
                {
                  yo = -1;
                  xu = dir;
                  a1u = y;
                  v964 = (double)(120 * (char)xu) + x;
                  v963 = v964;
                }
                else
                {
                  yo = 1;
                  xu = dir;
                  a1u = y;
                  v962 = (double)(120 * (char)xu) + x;
                  v963 = v962;
                }
                v965 = v963;
                addbullet(this, NULL, 817, v965, a1u, xu, yo, (int)&v1213, 3);
                v960 += 45;
                v1184 = v960;
              }
              while ( v960 < 360 );*/
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 5.0;
              addbullet(this, NULL, 854, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
              /*
              v968 = 6;
              do
              {
                *(float *)&v1213 = (double)scene_rand_rng(360);
                v1214 = (double)scene_rand_rng(75) * 0.1000000014901161 + 10.0;
                v1215 = 4.0;
                v969 = enemy;
                v970 = v969->y + 100.0;
                addbullet(this, NULL, 854, v969->x, v970, dir, 1, (int)&v1213, 3);
                --v968;
              }
              while ( v968 );*/
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 5.0;
              addbullet(this, NULL, 854, x, y + 100.0, dir, 1, t, 3);
              /*
              v972 = 6;
              do
              {
                *(float *)&v1213 = (double)scene_rand_rng(360);
                v1214 = (double)scene_rand_rng(75) * 0.1000000014901161 + 10.0;
                v1215 = 4.0;
                v973 = y + 100.0;
                addbullet(this, NULL, 854, x, v973, dir, 1, (int)&v1213, 3);
                --v972;
              }
              while ( v972 );*/
              play_sfx(56);
              field_7D0 = 2;
              field_7D2 = 0;
            }
            if ( field_7D0 == 2 && ++field_7D2 >= 30 )
            {
              enemy->field_1A4 = 5.0;
              enemy->field_1A8 = 10.0;
              enemy->set_seq(71);
LABEL_2433:
              next_subseq();
            }
          }
        }
        else
        {
          enemy->set_seq(102);
          enemy->reset_forces();
          next_subseq();
        }
        return;
      case 605:
        sub_46AB50(4, 2);
        sub10func();
        if ( field_7D0 == 1 && !get_subseq() )
        {
          if ( !(field_7D2 % 5) )
          {
            play_sfx(14);
            if ( field_7D4 < 6 )
            {
              t[0] = 15.0 - (double)field_7D4 * 60.0;
              t[1] = 7.0;
              t[2] = 0.0;
              addbullet(this, NULL, 855, (double)(90 * (char)dir) + x, y + 180.0, dir, 1, t, 3);
              ++field_7D4;
            }
          }
          ++field_7D2;
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 2 )
          {
            field_4A6 = 40;
            scene_play_sfx(23);
            scene_add_effect(this, 115, x, y + 140.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_frame_time() && get_frame() == 4 )
            field_7D0 = 1;
        }
        return;
      case 606:
        sub_46AB50(4, 2);
        sub10func();
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 7 )
          {
            field_4A6 = 40;
            scene_play_sfx(23);
            scene_add_effect(this, 115, x - (double)(102 * (char)dir), y + 164.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_frame_time() && get_frame() == 10 )
          {
            t[0] = 0.0;
            t[1] = -80.0;
            t[2] = 0.0;
            addbullet(this, NULL, 856, enemy->x, 1000.0, dir, 1, t, 3);
            play_sfx(53);
          }
        }
        return;
      case 607:
        sub_46AB50(4, 2);
        sub10func();
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          field_4A6 = 40;
          scene_play_sfx(23);
          scene_add_effect(this, 115,  x - (double)(117 * (char)dir), y + 162.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 3 )
        {
          //shake_camera(7.0);
          play_sfx(20);
          /*
          v988 = 0;
          v1185 = 0;
          do
          {
            *(float *)&v1259 = (double)scene_rand_rng(30) + (double)v1185 + 30.0;
            v1260 = 10.0;
            v1261 = 2.0;
            v989 = *(float *)&v1259;
            if ( *(float *)&v1259 < 0.0 || v989 > 180.0 )
            {
              yp = -1;
              xv = dir;
              a1v = y;
              v992 = (double)(180 * (char)xv) + x;
              v991 = v992;
            }
            else
            {
              yp = 1;
              xv = dir;
              a1v = y;
              v990 = (double)(180 * (char)xv) + x;
              v991 = v990;
            }
            v993 = v991;
            addbullet(this, NULL, 817, v993, a1v, xv, yp, (int)&v1259, 3);
            v988 += 30;
            v1185 = v988;
          }
          while ( v988 < 360 );*/
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 857, x, y, dir, 1, t, 3);
        }
        return;
      case 611:
        sub_46AB50(4, 2);
        sub10func();
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 5 )
          {
            field_4A6 = 40;
            scene_play_sfx(23);
            scene_add_effect(this, 115, x - (double)(97 * (char)dir), y + 122.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_frame_time() && get_frame() == 10 )
          {
            t[0] = 0.0;
            t[1] = 10.0;
            t[2] = 0.0;
            addbullet(this, NULL, 861, (double)(200 * (char)dir) + x, y, dir, 1, t, 3);
            t[2] = 4.0;
            addbullet(this, NULL, 861, (double)(200 * (char)dir) + x, y, dir, -1, t, 3);
            play_sfx(10);
          }
        }
        return;
      case 695:
        sub10func();
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
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
LABEL_2496:
        if ( field_49A )
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
          {
            h_inerc = 0.0;
            field_49A = 0;
          }
        }
        if ( h_inerc > 0.0 && get_frame() >= 7 )
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( process() )
          set_seq(0);
        if ( !get_frame_time() )
        {
          if ( get_frame() == 4 )
          {
            scene_play_sfx(29);
            field_49A = 0;
          }
          if ( !get_frame_time() )
          {
            if ( get_frame() == 3 )
              h_inerc = 10.0;
LABEL_2511:
            if ( !get_frame_time() && get_frame() == 7 )
              h_inerc = h_inerc * 0.25;
          }
        }
        return;
      case 710:
        if ( get_subseq() == 1 )
        {
          if ( get_elaps_frames() >= 120 )
            next_subseq();
          if ( !(get_elaps_frames() % field_7D6) )
          {
            play_sfx(1);
            t[0] = 0.0;
            t[1] = (double)field_7D0 + (double)field_7D0;
            t[2] = 0.0;
            field_7E4 = (double)scene_rand_rng(150) + 50.0;
            field_7DC = cos_deg((double)scene_rand_rng(360)) * field_7E4 + enemy->x;
            if ( field_7DC < -50.0 )
              field_7DC = -50.0;
            if ( dash_angle < -150.0 )
              dash_angle = -150.0;
            dash_angle = sin_deg((double)scene_rand_rng(360)) * field_7E4 + enemy->y;
            addbullet(this, NULL, 900, field_7DC, dash_angle, dir, 1, t, 3);
            ++field_7D0;
          }
        }
        if ( process() )
          set_seq(700);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          switch ( settings_get()->get_difficulty() )
          {
            case 0:
              field_7D6 = 20;
              break;
            case 1:
              field_7D6 = 15;
              break;
            case 2:
            case 3:
              field_7D6 = 10;
              break;
            default:
              return;
          }
        }
        return;
      case 711:
        if ( field_7D0 > 0 )
          ++field_7D2;
        if ( process() )
          set_seq(700);
        if ( !get_frame_time() && get_frame() == 10 )
        {
          play_sfx(18);
          field_7D0 = 1;
          /*
          v1012 = 0;
          v1186 = 0;
          do
          {
            *(float *)&v1265 = (double)scene_rand_rng(40) + (double)v1186 + 30.0;
            v1266 = 13.0;
            v1267 = 2.0;
            v1013 = *(float *)&v1265;
            if ( *(float *)&v1265 < 0.0 || v1013 > 180.0 )
            {
              yq = -1;
              xw = dir;
              a1w = y;
              v1016 = (double)(112 * (char)xw) + x;
              v1015 = v1016;
            }
            else
            {
              yq = 1;
              xw = dir;
              a1w = y;
              v1014 = (double)(112 * (char)xw) + x;
              v1015 = v1014;
            }
            v1017 = v1015;
            addbullet(this, NULL, 817, v1017, a1w, xw, yq, (int)&v1265, 3);
            v1012 += 45;
            v1186 = v1012;
          }
          while ( v1012 < 360 );*/
          t[2] = 6.0;
          addbullet(this, NULL, 900,  (double)(112 * (char)dir) + x, y, dir, 1, t, 3);
        }
        return;
      case 720:
        if ( get_subseq() == 1 && get_elaps_frames() >= 120 )
          next_subseq();
        if ( process() )
          set_seq(700);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          play_sfx(19);
          /*
          v1021 = 0;
          v1187 = 0;
          do
          {
            *(float *)&v1244 = (double)scene_rand_rng(40) + (double)v1187 + 30.0;
            v1245 = 13.0;
            v1246 = 2.0;
            v1022 = *(float *)&v1244;
            if ( *(float *)&v1244 < 0.0 || v1022 > 180.0 )
              addbullet(this, NULL, 817, x, y, dir, -1, (int)&v1244, 3);
            else
              addbullet(this, NULL, 817, x, y, dir, 1, (int)&v1244, 3);
            v1021 += 45;
            v1187 = v1021;
          }
          while ( v1021 < 360 );
          */
          t[0] = 0.0;
          t[1] = 10.0;
          t[2] = 0.0;
          addbullet(this, NULL, 901, enemy->x, y, dir, 1, t, 3);
          t[2] = 4.0;
          addbullet(this, NULL, 901, enemy->x, y, dir, -1, t, 3);
        }
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 3 )
        {
          switch ( settings_get()->get_difficulty() )
          {
            case 0:
              t[0] = 0.0;
              t[1] = -50.0;
              t[2] = 10.0;
              goto LABEL_2567;
            case 1:
              t[0] = 0.0;
              t[1] = -60.0;
              t[2] = 11.0;
              goto LABEL_2567;
            case 2:
              t[0] = 0.0;
              t[1] = -70.0;
              t[2] = 12.0;
              goto LABEL_2567;
            case 3:
              t[0] = 0.0;
              t[1] = -80.0;
              t[2] = 13.0;
LABEL_2567:
              addbullet(this, NULL, 901, enemy->x, 1000.0, dir, 1, t, 3);
              play_sfx(53);
              break;
            default:
              play_sfx(53);
              break;
          }
        }
        return;
      case 730:
        if ( get_subseq() == 1 && get_elaps_frames() >= 120 )
          next_subseq();
        if ( process() )
          set_seq(700);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          play_sfx(12);
          /*
          v1234 = (double)scene_rand_rng(360);
          v1197 = (double)scene_rand_rng(20) - 10.0;
          switch ( settings_get()->get_difficulty() )
          {
            case 0:
              v1192 = 0.0;
              v1056 = (float)0.0;
              do
              {
                v1057 = v1056 * 60.0 + v1234;
                v1058 = v1057 + 180.0;
                a4 = v1057 + v1197;
                v1232 = 5.0;
                v1233 = 0.0;
                v1059 = dir;
                v1060 = -v1058;
                v1061 = sin_deg(v1060) * 500.0 + enemy->y + 100.0;
                v1062 = v1061;
                v1063 = cos_deg(v1060) * 500.0 * (double)dir + enemy->x;
                addbullet(this, NULL, 902, v1063, v1062, v1059, 1, (int)&a4, 3);
                v1192 = v1192 + 1.0;
                v1056 = v1192;
              }
              while ( v1192 < 6.0 );
              break;
            case 1:
              v1191 = 0.0;
              v1048 = (float)0.0;
              do
              {
                v1049 = v1048 * 45.0 + v1234;
                v1050 = v1049 + 180.0;
                a4 = v1049 + v1197;
                v1232 = 5.0;
                v1233 = 0.0;
                v1051 = dir;
                v1052 = -v1050;
                v1053 = sin_deg(v1052) * 500.0 + enemy->y + 100.0;
                v1054 = v1053;
                v1055 = cos_deg(v1052) * 500.0 * (double)dir + enemy->x;
                addbullet(this, NULL, 902, v1055, v1054, v1051, 1, (int)&a4, 3);
                v1191 = v1191 + 1.0;
                v1048 = v1191;
              }
              while ( v1191 < 8.0 );
              break;
            case 2:
              v1190 = 0.0;
              v1040 = (float)0.0;
              do
              {
                v1041 = v1040 * 30.0 + v1234;
                v1042 = v1041 + 180.0;
                a4 = v1041 + v1197;
                v1232 = 5.0;
                v1233 = 0.0;
                v1043 = dir;
                v1044 = -v1042;
                v1045 = sin_deg(v1044) * 500.0 + enemy->y + 100.0;
                v1046 = v1045;
                v1047 = cos_deg(v1044) * 500.0 * (double)dir + enemy->x;
                addbullet(this, NULL, 902, v1047, v1046, v1043, 1, (int)&a4, 3);
                v1190 = v1190 + 1.0;
                v1040 = v1190;
              }
              while ( v1190 < 12.0 );
              break;
            case 3:
              v1188 = 0.0;
              v1024 = (float)0.0;
              do
              {
                v1025 = v1024 * 45.0 + v1234;
                v1026 = v1025;
                a4 = v1025 + v1197 + 180.0;
                v1232 = 6.0;
                v1233 = 0.0;
                v1027 = dir;
                v1028 = -v1026;
                v1029 = sin_deg(v1028) * 500.0 + enemy->y + 100.0;
                v1030 = v1029;
                v1031 = cos_deg(v1028) * 500.0 * (double)dir + enemy->x;
                addbullet(this, NULL, 902, v1031, v1030, v1027, 1, (int)&a4, 3);
                v1188 = v1188 + 1.0;
                v1024 = v1188;
              }
              while ( v1188 < 8.0 );
              v1189 = 0.0;
              v1032 = (float)0.0;
              do
              {
                v1033 = v1032 * 45.0 + v1234 + 22.5;
                v1034 = v1033 + 180.0;
                a4 = v1033 + v1197;
                v1232 = 4.0;
                v1233 = 0.0;
                v1035 = dir;
                v1036 = -v1034;
                v1037 = sin_deg(v1036) * 500.0 + enemy->y + 100.0;
                v1038 = v1037;
                v1039 = cos_deg(v1036) * 500.0 * (double)dir + enemy->x;
                addbullet(this, NULL, 902, v1039, v1038, v1035, 1, (int)&a4, 3);
                v1189 = v1189 + 1.0;
                v1032 = v1189;
              }
              while ( v1189 < 8.0 );
              break;
            default:
              return;
          }*/
        }
        return;
      case 732:
        if ( get_subseq() == 3 )
          sub10func();
        if ( process() )
          set_seq(704);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
        {
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 930, x, y + 100.0, dir, -1, t, 3);
          t[1] = 1.0;
          addbullet(this, NULL, 930, x, y + 100.0, dir, -1, t, 3);
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          if ( enemy->get_seq() <= 599 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 1.0;
            addbullet(this, NULL, 930, x, y + 100.0, dir, 1, t, 3);
            t[1] = 1.0;
            addbullet(this, NULL, 930, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
            t[1] = 0.0;
            t[2] = 2.0;
            addbullet(this, NULL, 930, x, y + 100.0, dir, 1, t, 3);
            t[1] = 1.0;
            addbullet(this, NULL, 930, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
            if ( char_on_ground_flag() )
            {
              /*
              v1073 = 0;
              v1193 = 0;
              do
              {
                t[0] = (double)scene_rand_rng(40) + (double)v1193 + 30.0;
                t[1] = 13.0;
                t[2] = 2.0;
                v1074 = t[0];
                if ( t[0] < 0.0 || v1074 > 180.0 )
                  addbullet(this, NULL, 817, x, y, dir, -1, t, 3);
                else
                  addbullet(this, NULL, 817, x, y, dir, 1, t, 3);
                v1073 += 45;
                v1193 = v1073;
              }
              while ( v1073 < 360 );*/
            }
            if ( enemy->char_on_ground_flag() )
            {
              /*
              v1075 = 0;
              v1194 = 0;
              do
              {
                t[0] = (double)scene_rand_rng(40) + (double)v1194 + 30.0;
                t[1] = 13.0;
                t[2] = 2.0;
                v1076 = t[0];
                if ( t[0] < 0.0 || v1076 > 180.0 )
                  addbullet(this, NULL, 817, enemy->x, enemy->y, dir, -1, t, 3);
                else
                  addbullet(this, NULL, 817, enemy->x, enemy->y, dir, 1, t, 3);
                v1075 += 45;
                v1194 = v1075;
              }
              while ( v1075 < 360 );*/
            }
            field_7DC = x;
            dash_angle = y;
            x = enemy->x;
            y = enemy->y;
            enemy->x = field_7DC;
            enemy->y = dash_angle;
          }
          play_sfx(13);
          field_7D8 = 1;
        }
        if ( get_elaps_frames() )
          goto LABEL_1751;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
        {
          if ( char_on_ground_flag() == 0 )
            set_seq(704);
          else
            set_seq(700);
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
        {
LABEL_1751:
          if ( get_subseq() == 4 && !get_frame_time() )
          {
LABEL_1754:
            if ( get_frame() == 1 )
              v_force = 0.5;
          }
        }
        else if ( get_subseq() == 4 )
        {
          set_seq(700);
        }
        return;
      default:
        goto LABEL_2646;
    }
  }
}


// NOTE: taken from marisa.cpp
void char_komachi::func20()
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

void char_komachi::set_seq_params()
{
  double v8 = 0.0;
  
  if ( get_seq() > 501 )
  {
    if ( get_seq() > 797 )
    {
      if ( get_seq() != 798 )
      {
LABEL_71:
        char_c::set_seq_params();
        return;
      }
    }
    else if ( get_seq() != 797 )
    {
      switch ( get_seq() )
      {
        case 505:
        case 506:
          field_18C = 4;
          reset_forces();
          field_194 = 0;
          field_49A = 0;
          field_190 = 1;
          not_charge_attack = 1;
          return;
        case 507:
        case 508:
          field_194 = 0;
          field_49A = 0;
          field_18C = 4;
          field_190 = 1;
          h_inerc = h_inerc * 0.1000000014901161;
          not_charge_attack = 1;
          v_inerc = 0.1000000014901161 * v_inerc;
          v_force = 0.0;
          return;
        case 510:
        case 511:
          field_18C = 8;
          reset_forces();
          goto LABEL_36;
        case 520:
        case 521:
          field_18C = 1;
          reset_forces();
          field_190 = 1;
          field_49A = 0;
          goto LABEL_44;
        case 525:
          field_18C = 5;
          reset_forces();
          field_194 = 8;
          goto LABEL_46;
        case 526:
          field_18C = 5;
          reset_forces();
          field_194 = 12;
          goto LABEL_46;
        case 530:
        case 531:
          field_18C = 9;
          reset_forces();
          field_194 = 1;
LABEL_46:
          field_190 = 0;
          field_49A = 0;
          field_7D0 = 0;
          return;
        case 540:
        case 541:
        case 542:
        case 543:
          field_18C = 2;
          field_7D8 = 0;
          field_190 = 1;
          reset_forces();
          not_charge_attack = 0;
          return;
        case 545:
        case 546:
          field_18C = 6;
          field_190 = 1;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 550:
          v8 = 0.0;
          goto LABEL_52;
        case 551:
          v8 = 1.0;
LABEL_52:
          field_7DC = v8;
          field_194 = 1;
          field_18C = 10;
          goto LABEL_53;
        case 560:
        case 561:
          field_18C = 3;
          field_190 = 0;
          reset_forces();
          goto LABEL_56;
        case 565:
        case 566:
          field_18C = 7;
          field_190 = 1;
          reset_forces();
LABEL_56:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          field_7D6 = 0;
          not_charge_attack = 1;
          return;
        case 570:
        case 571:
          field_18C = 11;
          goto LABEL_53;
        case 599:
          field_190 = 1;
          reset_forces();
LABEL_28:
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D0 = 0;
          field_7D8 = 0;
          return;
        case 600:
          field_7D0 = 0;
          field_190 = 0;
          field_194 = 1;
          reset_forces();
          return;
        case 601:
          field_190 = 0;
          field_194 = 1;
          reset_forces();
          return;
        case 602:
        case 605:
        case 606:
          reset_forces();
LABEL_44:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          return;
        case 603:
          field_7D0 = 0;
          field_194 = 0;
          field_190 = 1;
          reset_forces();
          return;
        case 604:
          field_190 = 0;
          field_194 = 1;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          return;
        case 607:
LABEL_53:
          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 611:
          field_194 = 1;
          field_190 = 0;
          reset_forces();
          return;
        case 612:
        case 615:
LABEL_25:
          field_190 = 1;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          not_charge_attack = 1;
          return;
        case 613:
LABEL_18:
          field_190 = 0;
          not_charge_attack = 1;
          return;
        case 710:
        case 720:
        case 730:
          reset_forces();
          field_7D0 = 0;
          return;
        case 711:
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          return;
        case 732:
          reset_forces();
          field_7D0 = 0;
          field_7D8 = 0;
          return;
        default:
          goto LABEL_71;
      }
      goto LABEL_71;
    }
    reset_forces();
    scene_play_sfx(31);
    h_inerc = 12.0;
    field_7D0 = 0;
    v_inerc = 0.0;
    v_force = 0.5;
    return;
  }
  if ( get_seq() < 500 )
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
        case 321:
        case 322:
        case 330:
          goto LABEL_32;
        case 302:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_49A = 0;
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
          field_49A = 0;
          field_190 = 0;
          h_inerc = 17.5;
          field_194 = 1;
          v_force = 0.0;
          return;
        case 306:
          field_7D0 = 0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 307:
        case 308:
        case 309:
          field_194 = 1;
          goto LABEL_18;
        case 310:
          field_194 = 1;
          v_force = 0.5;
          field_190 = 0;
          return;
        case 320:
          field_49A = 0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 400:
        case 401:
        case 402:
          field_190 = 1;
          reset_forces();
          field_7DC = 0.0;
          dash_angle = 0.0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7E4 = 0.0;
          field_7D4 = 0;
          not_charge_attack = 1;
          return;
        case 404:
        case 405:
        case 406:
          field_7DC = 0.0;
          field_7D0 = 0;
          dash_angle = 0.0;
          field_7D2 = 0;
          field_7E4 = 0.0;
          field_7D4 = 0;
          v_force = 0.0;
          field_190 = 1;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 408:
          h_inerc = 17.5;
          field_49A = 0;
          field_7D0 = 0;
          field_190 = 0;
          v_inerc = 0.0;
          field_194 = 1;
          return;
        case 409:
          field_49A = 0;
          v_force = 0.34999999;
          field_7D0 = 0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 410:
          goto LABEL_25;
        case 411:
          field_190 = 1;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          not_charge_attack = 1;
          return;
        case 412:
          not_charge_attack = 1;
          field_190 = 0;
          reset_forces();
          goto LABEL_28;
        case 414:
          v_force = 0.0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          field_190 = 1;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 415:
        case 416:
          v_force = 0.0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_190 = 1;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 418:
          h_inerc = 17.5;
LABEL_32:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_194 = 1;
          return;
        default:
          goto LABEL_71;
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
        h_inerc = 6.0;
        return;
      }
      if ( (get_seq() - 4) == 1 )
      {
        h_inerc = -5.0;
        return;
      }
    }
    goto LABEL_71;
  }
  field_18C = 0;
  reset_forces();
LABEL_36:
  field_194 = 0;
  field_49A = 0;
  field_190 = 1;
}
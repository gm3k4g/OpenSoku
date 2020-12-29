#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "remilia.h"
#include <math.h>

char_remilia::char_remilia(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_REMI;
	pgp->load_dat("remilia",pal);
	char_loadsfx("remilia");
	cards_load_cards(&chr_cards,"remilia");
	load_face("remilia");
	load_spells("remilia");
	stand_gfx->init(this,"remilia");
}

void char_remilia::init_vars()
{
  field_890 = 0;
  field_138 = -6.0;
  char_c::init_vars();
}
/*
c_bullet *char_remilia::new_bullet()
{
    c_bullet *tmp = new remilia_bullets();
    return tmp;
}
*/
void char_remilia::func10()
{
  x_delta = 0;
  y_delta = 76;

  float t[3];
  t[0] = 0.0;
  t[1] = 0.0;
  t[2] = 0.0;
  float tt[4];
  tt[0] = 0.0;
  tt[1] = 0.0;
  tt[2] = 0.0;
  tt[3] = 0.0;

  bool v29 = false;
  double v32 = 0.0;
  double v35 = 0.0;
  double v43 = 0.0;

  double v83 = 0.0;
  double v91 = 0.0;
  double v87 = 0.0;

  double v1100 = 0.0;
  double v504 = 0.0;
  double v196 = 0.0;
  double v193 = 0.0;

  double v185 = 0.0;

  double move_val = 0.0;

  if ( get_seq() > 149 && get_seq() < 159 && !bbarrier_show )
  {
    bbarrier_show = 1;
    if ( get_seq() > 149 && get_seq() < 154 )
    {
      addbullet(this, NULL, 998, (double)(35 * (char)dir) + x, y + 95.0, dir, 1, 0, 0);
    }
    if ( get_seq() > 153 && get_seq() < 158 )
    {
      addbullet(this, NULL, 998, (double)(55 * (char)dir) + x, y + 55.0, dir, 1, 0, 0);
    }
    if ( get_seq() == 158 )
    {
      addbullet(this, NULL, 998, (double)(85 * (char)dir) + x, y + 90.0, dir, 1, 0, 0);
    }
  }
  if ( field_890 > 0 )
  {
    field_890 = field_890 - 1;
    field_550 = 0.75;
    field_534 = field_534 * 1.200000047683716;
    if ( health <= 0 )
      field_890 = 0;
    if ( get_seq() >= 600 && get_seq() <= 689 && !get_subseq() && !get_frame() )
      field_890 = 0;
  }
  if ( hit_stop || enemy->time_stop )
    return;
  if ( get_seq() <= 300 )
  {
    if ( get_seq() == 300 )
    {
LABEL_557:
      char_c::sub10func();
      if (  true /*!get_true(0)*/ )
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
LABEL_581:
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
            goto LABEL_28;
          goto LABEL_29;
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
LABEL_29:
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
LABEL_102:
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
LABEL_28:
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
          v29 = get_frame() == 0;
          goto LABEL_362;
        case 4:
          sub10func();
          char_h_move(6.5);
          process();
          return;
        case 5:
          sub10func();
          char_h_move(-6.5);
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
              goto LABEL_101;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          char_h_move(0.0);
          v32 = 19.0;
          goto LABEL_97;
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
              goto LABEL_101;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v35 = 7.0;
          goto LABEL_96;
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
              goto LABEL_101;
          }
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v35 = -7.0;
LABEL_96:
            char_h_move(v35);
            v32 = 18.0;
LABEL_97:
            v_inerc = v32;
            v_force = 0.94999999;
            field_49A = 0;
          }
          return;
        case 9:
          if ( 0.0 == v_force )
            v_force = 0.60000002;
          v_inerc = v_inerc - v_force;
          if ( !char_on_ground_down() )
            goto LABEL_102;
LABEL_101:
          set_seq(10);
          goto LABEL_2709;
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
            goto LABEL_116;
          if ( controlling_type == 2 )
            goto LABEL_157;
          set_seq(0);
          if ( dY() > 0 )
            set_seq(1);
LABEL_116:
          if ( get_subseq() == 3 && get_frame() == 2 && !get_frame_time() )
          {
            if ( enemy->x < (double)x )
              dir = -1;
            if ( enemy->x > (double)x )
              dir = 1;
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v_inerc = 8.0;
          v43 = 15.5;
          goto LABEL_2011;
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
            goto LABEL_138;
          if ( controlling_type == 2 )
          {
            set_seq(700);
            field_51C = 3;
            field_520 = 3;
            return;
          }
          set_seq(0);
          if ( dY() > 0 )
            set_seq(1);
LABEL_138:
          if ( get_subseq() == 3 && get_frame() == 2 && !get_frame_time() )
          {
            if ( enemy->x < (double)x )
              dir = -1;
            if ( enemy->x > (double)x )
              dir = 1;
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v_inerc = 8.0;
          v43 = -15.5;
          goto LABEL_2011;
        case 199:
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
            goto LABEL_160;
          if ( controlling_type == 2 )
          {
LABEL_157:
            set_seq(700);
            field_51C = 3;
            field_520 = 3;
            return;
          }
          set_seq(0);
          if ( dY() > 0 )
            set_seq(1);
LABEL_160:
          if ( get_subseq() == 3 && get_frame() == 2 && !get_frame_time() )
          {
            if ( enemy->x < (double)x )
              dir = -1;
            if ( enemy->x > (double)x )
              dir = 1;
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v_inerc = 6.0;
          v43 = 0.0;
          goto LABEL_2011;
        case 200:
          if ( !get_subseq() || get_subseq() == 3 )
            sub10func();
          if ( (get_subseq() == 1 || get_subseq() == 2) && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
          {
            reset_forces();
            set_subseq(3);
            y = getlvl_height();
          }
          else
          {
            if ( get_subseq() == 3 )
            {
              h_inerc = h_inerc - 2.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
            {
              h_inerc = 0.0;
              set_seq(0);
              if ( dY() > 0 )
                set_seq(1);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              field_49A = 0;
              char_h_move(15.0);
              v_inerc = 25.0;
              v_force = 2.5;
              scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, dir, 1);
              scene_play_sfx(31);
            }
          }
          return;
        case 201:
          if ( !get_subseq() || get_subseq() == 3 )
            sub10func();
          if ( (get_subseq() == 1 || get_subseq() == 2) && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
          {
            reset_forces();
            set_subseq(3);
            y = getlvl_height();
          }
          else
          {
            if ( get_subseq() == 3 )
            {
              h_inerc = h_inerc + 4.0;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
            {
              h_inerc = 0.0;
              set_seq(0);
              if ( dY() > 0 )
                set_seq(1);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(-22.0);
              v_inerc = 40.0;
              v_force = 6.0;
              scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, dir, 1);
              scene_play_sfx(31);
            }
          }
          return;
        case 202:
          if ( get_subseq() == 2 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_525;
          if ( process() )
            set_seq(9);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(30.0);
              v_inerc = -4.0;
              scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
              scene_add_effect(this, 126, x, y + 110.0, dir, 1);
              scene_play_sfx(31);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              flip_with_force();
          }
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
          {
            char_h_move(10.0);
            v_inerc = -4.0;
            v_force = 0.5;
          }
          return;
        case 203:
          if ( get_subseq() == 2 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_541;
          if ( process() )
            set_seq(9);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(-30.0);
              v_inerc = 2.0;
              scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
              scene_add_effect(this, 126, x, y + 110.0, dir, 1);
              scene_play_sfx(31);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
              char_h_move(-10.0);
              v_inerc = 2.0;
              v_force = 0.5;
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
            goto LABEL_447;
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
          char_h_move(0.0);
          v_inerc = 23.0;
          v83 = 1.0;
          goto LABEL_462;
        case 209:
          if ( !get_subseq() )
            sub10func();
          if ( !char_on_ground_down() )
            goto LABEL_266;
          goto LABEL_304;
        case 210:
          if ( !get_subseq() )
            sub10func();
          if ( !char_on_ground_down() )
            goto LABEL_470;
          goto LABEL_304;
        case 211:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_304;
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
          char_h_move(3.0);
          v_inerc = 23.0;
          v91 = 1.0;
          goto LABEL_485;
        case 212:
          if ( !get_subseq() )
            sub10func();
          if ( !char_on_ground_down() )
            goto LABEL_266;
LABEL_304:
          set_seq(10);
          goto LABEL_2709;
        case 214:
          if ( get_subseq() == 1 || get_subseq() == 2 )
          {
            if ( y > 680.0 && v_inerc > 0.0 )
              v_inerc = 0.0;
            if ( get_frame() >= 8 )
              v_inerc = v_inerc - v_force;
          }
          if ( get_subseq() == 3 || get_subseq() == 4 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            y = getlvl_height();
            v_inerc = 0.0;
            if ( get_subseq() == 1 || get_subseq() == 2 )
            {
              reset_ofs();
              set_seq(215);
            }
            else
            {
              set_seq(10);
              reset_forces();
            }
          }
          else
          {
            if ( process() )
              goto LABEL_2089;
            if ( get_elaps_frames() )
              goto LABEL_2737;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
              goto LABEL_2089;
            if ( get_frame_time() || get_frame() || get_subseq() != 1 )
            {
LABEL_2737:
              if ( (get_subseq() == 1 || get_subseq() == 2) && !get_frame_time() && get_frame() == 7 )
              {
                reset_ofs();
                h_inerc = cos_deg(dash_angle) * 4.0;
                v_inerc = sin_deg(dash_angle) * 4.0;
                flip_with_force();
              }
              if ( !get_elaps_frames() )
              {
                if ( get_frame_time() || get_frame() || get_subseq() != 2 )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
                    reset_ofs();
                }
                else
                {
                  reset_ofs();
                  set_subseq(3);
                }
              }
            }
            else
            {
              if ( weather_id )
                spell_energy_spend(200, 45);
              else
                spell_energy_spend(100, 45);
              scene_play_sfx(31);
              field_7D4 = field_7D2 - dash_angle;
              h_inerc = cos_deg(dash_angle) * field_7DC;
              v_inerc = sin_deg(dash_angle) * field_7DC;
              angZ = -dash_angle;
              if ( h_inerc < 0.0 )
                angZ = 180.0 - dash_angle;
              if ( h_inerc < 0.0 && get_subseq() == 1 )
                set_subseq(2);
            }
          }
          return;
        case 215:
          sub10func();
          if ( h_inerc > 0.0 )
          {
            h_inerc = h_inerc - 1.25;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( h_inerc < 0.0 )
          {
            h_inerc = h_inerc + 1.25;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() )
          {
            v29 = get_subseq() == 1;
LABEL_362:
            if ( v29 )
              goto LABEL_363;
          }
          return;
        case 217:
          if ( process() )
            goto LABEL_2089;
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              scene_play_sfx(31);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
              goto LABEL_2089;
          }
          field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
          if ( get_subseq() == 5 || get_subseq() == 6 )
            v_inerc = v_inerc - v_force;
          if ( get_subseq() <= 0 || get_subseq() >= 5 )
            goto LABEL_2738;
          ++field_7D6;
          field_7D4 = field_7D2 - dash_angle;
          if ( field_7D4 > 180 )
            field_7D4 = field_7D4 - 360;
          if ( field_7D4 < -180 )
            field_7D4 = field_7D4 + 360;
          if ( field_7D4 > 0 )
          {
            if ( weather_id )
              dash_angle = dash_angle + 0.0;
            else
              dash_angle = dash_angle + 1.0;
          }
          if ( field_7D4 < 0 )
          {
            if ( weather_id )
              dash_angle = dash_angle - 0.0;
            else
              dash_angle = dash_angle - 1.0;
          }
          h_inerc = cos_deg(dash_angle) * field_7DC;
          v_inerc = sin_deg(dash_angle) * field_7DC;
          if ( y > 680.0 && v_inerc > 0.0 )
            v_inerc = 0.0;
          field_7DC = field_7DC + 0.300000011920929;
          if ( field_7DC > 17.5 )
            field_7DC = 17.5;
          if ( weather_id )
            spell_energy_spend(20, 60);
          else
            spell_energy_spend(15, 1);
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
LABEL_2738:
            if ( char_on_ground_down() )
            {
              y = getlvl_height();
              v_force = 0.0;
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
              else
              {
                if ( enemy->x <= x )
                  goto LABEL_2069;
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
LABEL_447:
            set_seq(10);
            goto LABEL_2709;
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
            v83 = 0.85000002;
LABEL_462:
            v_force = v83;
            field_49A = 0;
            scene_add_effect(this, 63, x, y, dir, 1);
          }
          break;
        case 221:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_639;
LABEL_266:
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
          v87 = 14.0;
          goto LABEL_484;
        case 222:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_639;
LABEL_470:
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
            v87 = -14.0;
LABEL_484:
            char_h_move(v87);
            v_inerc = 17.5;
            v91 = 0.89999998;
LABEL_485:
            v_force = v91;
            field_49A = 0;
            scene_add_effect(this, 63, x, y, dir, 1);
          }
          return;
        case 223:
          sub10func();
          field_49A = 1;
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
            goto LABEL_495;
          if ( get_subseq() != 1 )
            goto LABEL_2294;
          if ( !field_7D0 )
          {
            char_h_move(8.0);
            scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
            scene_add_effect(this, 126, x, y + 80.0, dir, 1);
            scene_play_sfx(31);
          }
LABEL_495:
          if ( get_subseq() != 1 )
            goto LABEL_2294;
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          if ( dX(dir) <= 0 && ++field_7D0 > 15 )
            goto LABEL_2388;
          if ( ++field_7D0 <= 45 )
            goto LABEL_2294;
          next_subseq();
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
            v_inerc = 0.0;
            v_force = 0.0;
            y = getlvl_height();
            set_subseq(3);
          }
          else if ( process() )
          {
            set_seq(0);
            h_inerc = 0.0;
            v_force = 0.0;
          }
          else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_7D0 )
          {
            field_7D0 = 1;
            char_h_move(-15.0);
            v_inerc = 4.5;
            v_force = 0.5;
            scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
            scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
            scene_play_sfx(31);
          }
          return;
        case 225:
          if ( get_subseq() == 2 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_525:
            reset_forces();
            y = getlvl_height();
            set_seq(10);
          }
          else
          {
            if ( process() )
              set_seq(9);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                char_h_move(-30.0);
                v_inerc = 2.0;
                scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
                scene_add_effect(this, 126, x, y + 110.0, dir, 1);
                scene_play_sfx(31);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              {
                char_h_move(-10.0);
                v_inerc = 2.0;
                v_force = 0.5;
                flip_with_force();
              }
            }
          }
          return;
        case 226:
          if ( get_subseq() == 2 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_541:
            reset_forces();
            y = getlvl_height();
            set_seq(10);
          }
          else
          {
            if ( process() )
              set_seq(9);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                char_h_move(30.0);
                v_inerc = -4.0;
                scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
                scene_add_effect(this, 126, x, y + 110.0, dir, 1);
                scene_play_sfx(31);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              {
                char_h_move(10.0);
                v_inerc = -4.0;
                v_force = 0.5;
                flip_with_force();
              }
            }
          }
          return;
        default:
          goto LABEL_2712;
      }
    }
    return;
  }
  if ( get_seq() > 520 )
  {
    if ( get_seq() <= 795 )
    {
      if ( get_seq() != 795 )
      {
        switch ( get_seq() )
        {
          case 521:
            sub10func();
            field_18C = 1;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_363;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1455;
            if ( get_frame() == 3 && not_charge_attack )
            {
              y = y + 107.0;
              v196 = x;
              goto LABEL_1607;
            }
            if ( get_frame() == 5 )
            {
              play_sfx(11);
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);/*
              switch ( (_BYTE)v1 )
              {
                case 0:
                  v470 = 3.0;
                  goto LABEL_1450;
                case 1:
                case 2:
                case 3:
                  v470 = 4.0;
                  goto LABEL_1450;
                case 4:
                  v470 = 5.0;
LABEL_1450:
                  dash_angle = v470;
                  break;
                default:
                  break;
              }
              v1147 = 0.0;
              if ( dash_angle > 0.0 )
              {
                v471 = v1147;
                do
                {
                  *(float *)&v1260 = 360.0 * v471 / dash_angle;
                  v1261 = 9.0;
                  v1262 = 0.0;
                  v1263 = v471 * 5.0 + 60.0;
                  v472 = dir;
                  v473 = y + 102.0;
                  v474 = v473;
                  v475 = (double)(40 * (char)v472) + x;
                  addbullet(this, NULL, 815, v475, v474, v472, 1, (int)&v1260, 4);
                  v1147 = v1147 + 1.0;
                  v471 = v1147;
                }
                while ( dash_angle > (double)v1147 );
              }*/
              tt[2] = 2.0;
              addbullet(this, NULL, 815, (double)(40 * (char)dir) + x, y + 102.0, dir, 1, tt, 3);
              tt[2] = 3.0;
              addbullet(this, NULL, 815, (double)(40 * (char)dir) + x, y + 102.0, dir, 1, tt, 3);
            }
LABEL_1455:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
            {
              play_sfx(11);
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);/*
              switch ( (_BYTE)v1 )
              {
                case 0:
                  v484 = 5.0;
                  goto LABEL_1462;
                case 1:
                case 2:
                case 3:
                  v484 = 6.0;
                  goto LABEL_1462;
                case 4:
                  v484 = 7.0;
LABEL_1462:
                  dash_angle = v484;
                  break;
                default:
                  break;
              }
              v1148 = 0.0;
              if ( dash_angle > 0.0 )
              {
                v485 = v1148;
                do
                {
                  *(float *)&v1256 = 360.0 * v485 / dash_angle;
                  v1257 = 9.0;
                  v1258 = 0.0;
                  v1259 = v485 * 5.0 + 60.0;
                  v486 = dir;
                  v487 = y + 102.0;
                  v488 = v487;
                  v489 = (double)(40 * (char)v486) + x;
                  addbullet(this, NULL, 815, v489, v488, v486, 1, (int)&v1256, 4);
                  v1148 = v1148 + 1.0;
                  v485 = v1148;
                }
                while ( dash_angle > (double)v1148 );
              }*/
              tt[2] = 2.0;
              addbullet(this, NULL, 815, (double)(40 * (char)dir) + x, y + 102.0, dir, 1, tt, 3);
              tt[2] = 3.0;
              addbullet(this, NULL, 815, (double)(40 * (char)dir) + x, y + 102.0, dir, 1, tt, 3);
            }
            return;
          case 525:
            sub10func();
            field_18C = 5;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 2 && (get_elaps_frames() >= 10 * ((char)skills_1[5] + 1) || !not_charge_attack) )
              goto LABEL_2474;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            tt[0] = 0.0;
            tt[1] = 0.0;
            tt[2] = 0.0;
            tt[3] = 0.0;
            addbullet(this, NULL, 816, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
            tt[2] = 1.0;
            v1100 = y + 100.0;
            v504 = (double)(20 * (char)dir) + x;
            goto LABEL_1560;
          case 526:
            if ( get_subseq() <= 3 )
              sub10func();
            field_18C = 5;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() == 2 && field_7D0 == 1 )
              goto LABEL_2154;
            if ( process() )
              set_seq(9);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7E4 < -30.0 )
                  field_7E4 = -30.0;
                if ( field_7E4 > 30.0 )
                  field_7E4 = 30.0;
                tt[0] = field_7E4;
                tt[1] = 0.0;
                tt[2] = 0.0;
                tt[3] = 0.0;
                addbullet(this, NULL, 816, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
                t[2] = 5.0;
                addbullet(this, NULL, 816, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
                play_sfx(16);
                spell_energy_spend(200, 120);
                add_card_energy(50);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
                set_seq(0);
            }
            return;
          case 527:
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
            field_18C = 5;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 2 && (get_elaps_frames() >= 10 * ((char)skills_1[5] + 1) || !not_charge_attack) )
            {
              next_subseq();
              v_force = 0.5;
              return;
            }
            if ( process() )
              set_seq(0);
            if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 4 )
              v_force = 0.5;
            if ( get_elaps_frames() )
              return;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
              set_seq(9);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            tt[0] = 0.0;
            tt[1] = 0.0;
            tt[2] = 0.0;
            tt[3] = 0.0;
            addbullet(this, NULL, 816, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
            tt[2] = 1.0;
            v1100 = y + 100.0;
            v504 = (double)(20 * (char)dir) + x;
            goto LABEL_1560;
          case 528:
            if ( get_subseq() == 7 )
            {
              sub10func();
            }
            else if ( get_subseq() <= 3 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_2499;
            }
            field_18C = 5;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() == 2 && field_7D0 == 1 )
              goto LABEL_2154;
            if ( process() )
              set_seq(0);
            if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 5 )
              v_force = 0.5;
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                set_seq(9);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 7 )
                  set_seq(9);
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                  if ( field_7E4 < -30.0 )
                    field_7E4 = -30.0;
                  if ( field_7E4 > 30.0 )
                    field_7E4 = 30.0;
                  tt[0] = field_7E4;
                  tt[1] = 0.0;
                  tt[2] = 0.0;
                  tt[3] = 0.0;
                  addbullet(this, NULL, 816, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
                  tt[2] = 5.0;
                  v1100 = y + 100.0;
                  v504 = (double)(20 * (char)dir) + x;
LABEL_1560:
                  addbullet(this, NULL, 816, v504, v1100, dir, 1, tt, 4);
                  play_sfx(16);
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                }
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
              goto LABEL_2734;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1583;
            if ( get_frame() == 10 && not_charge_attack )
            {
              
              y = y + 160.0;
              v196 = x - (double)(140 * (char)dir);
              goto LABEL_1607;
            }
            if ( get_frame() == 12 )
            {
              field_190 = 1;
              spell_energy_spend(200, 120);
              play_sfx(20);
              add_card_energy(50);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -15.0 )
                field_7E4 = -15.0;
              if ( field_7E4 > 0.0 )
                field_7E4 = 0.0;
              /*
              v1149 = 0.0;
              if ( (double)((char)skills_1[9] + 1) > 0.0 )
              {
                v545 = v1149;
                while ( 1 )
                {
                  *(float *)&v1270 = field_7E4 - v545 * 6.0;
                  v1271 = 42.0;
                  v1272 = 0.0;
                  v546 = dir;
                  v547 = -*(float *)&v1270;
                  v548 = sin_deg(v547) * 200.0 + y + 100.0;
                  v549 = v548;
                  v550 = -*(float *)&v1270;
                  v551 = (cos_deg(v550) * 200.0 - 120.0) * (double)dir + x;
                  addbullet(this, NULL, 817, v551, v549, v546, 1, (int)&v1270, 4);
                  v1149 = v1149 + 1.0;
                  if ( (double)((char)skills_1[9] + 1) <= v1149 )
                    break;
                  v545 = v1149;
                }
              }*/
            }
LABEL_1583:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
            {
              field_190 = 1;
              spell_energy_spend(200, 120);
              play_sfx(20);
              add_card_energy(50);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -15.0 )
                field_7E4 = -15.0;
              if ( field_7E4 > 0.0 )
                field_7E4 = 0.0;
              /*
              v1150 = 0.0;
              v558 = (float)0.0;
              while ( 1 )
              {
                *(float *)&v1276 = field_7E4 - v558 * 6.0;
                v1277 = 42.0;
                v1278 = 0.0;
                v559 = dir;
                v560 = -*(float *)&v1276;
                v561 = sin_deg(v560) * 200.0 + y + 100.0;
                v562 = v561;
                v563 = -*(float *)&v1276;
                v564 = (cos_deg(v563) * 200.0 - 120.0) * (double)dir + x;
                addbullet(this, NULL, 817, v564, v562, v559, 1, (int)&v1276, 4);
                v1150 = v1150 + 1.0;
                if ( v1150 >= 6.0 )
                  break;
                v558 = v1150;
              }*/
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
            {
LABEL_363:
              set_seq(0);
              return;
            }
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1617;
            if ( get_frame() == 10 && not_charge_attack )
            {
              y = y + 160.0;
              v196 = x - (double)(140 * (char)dir);
              goto LABEL_1607;
            }
            if ( get_frame() == 12 )
            {
              field_190 = 1;
              spell_energy_spend(200, 120);
              play_sfx(20);
              add_card_energy(50);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -15.0 )
                field_7E4 = -15.0;
              if ( field_7E4 > 0.0 )
                field_7E4 = 0.0;
              /*
              v1151 = 0.0;
              if ( (double)((char)skills_1[9] + 1) > 0.0 )
              {
                v574 = v1151;
                while ( 1 )
                {
                  *(float *)&v1267 = field_7E4 - v574 * 6.0 - 20.0;
                  v1268 = 42.0;
                  v1269 = 0.0;
                  v575 = dir;
                  v576 = -*(float *)&v1267;
                  v577 = sin_deg(v576) * 200.0 + y + 100.0;
                  v578 = v577;
                  v579 = -*(float *)&v1267;
                  v580 = (cos_deg(v579) * 200.0 - 120.0) * (double)dir + x;
                  addbullet(this, NULL, 817, v580, v578, v575, 1, (int)&v1267, 4);
                  v1151 = v1151 + 1.0;
                  if ( (double)((char)skills_1[9] + 1) <= v1151 )
                    break;
                  v574 = v1151;
                }
              }*/
            }
LABEL_1617:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
            {
              field_190 = 1;
              spell_energy_spend(200, 120);
              play_sfx(20);
              add_card_energy(50);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -15.0 )
                field_7E4 = -15.0;
              if ( field_7E4 > 0.0 )
                field_7E4 = 0.0;
              /*
              v1152 = 0.0;
              v587 = (float)0.0;
              while ( 1 )
              {
                *(float *)&v1264 = field_7E4 - v587 * 6.0 - 20.0;
                v1265 = 42.0;
                v1266 = 0.0;
                v588 = dir;
                v589 = -*(float *)&v1264;
                v590 = sin_deg(v589) * 200.0 + y + 100.0;
                v591 = v590;
                v592 = -*(float *)&v1264;
                v593 = (cos_deg(v592) * 200.0 - 120.0) * (double)dir + x;
                addbullet(this, NULL, 817, v593, v591, v588, 1, (int)&v1264, 4);
                v1152 = v1152 + 1.0;
                if ( v1152 >= 6.0 )
                  break;
                v587 = v1152;
              }*/
            }
            return;
          case 540:
            if ( !get_subseq() || get_subseq() == 6 )
              sub10func();
            field_18C = 2;
            if ( !get_subseq() && skills_1[2] >= 1 )
              field_51C = 2;
            if ( get_subseq() < 6 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_2109;
            }
            if ( (get_subseq() == 2 || get_subseq() == 3) && field_194 > 0 )
            {
              if ( field_190 )
              {
                if ( ++field_7D0 >= 4 )
                {
                  field_7D0 = 0;
                  field_190 = 0;
                }
              }
            }
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              return;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(12);
              h_inerc = 10.0;
              v_inerc = 12.5;
              v_force = 0.40000001;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
            }
            goto LABEL_1671;
          case 541:
            if ( !get_subseq() || get_subseq() == 6 )
              sub10func();
            field_18C = 2;
            if ( !get_subseq() && skills_1[2] >= 1 )
              field_51C = 2;
            if ( get_subseq() < 6 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
            {
              reset_forces();
              set_subseq(6);
              y = getlvl_height();
            }
            else
            {
              if ( (get_subseq() == 2 || get_subseq() == 3) && field_194 > 0 )
              {
                if ( field_190 )
                {
                  if ( ++field_7D0 >= 4 )
                  {
                    field_7D0 = 0;
                    field_190 = 0;
                  }
                }
              }
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  add_card_energy(50);
                  spell_energy_spend(200, 120);
                  play_sfx(12);
                  h_inerc = 15.0;
                  v_inerc = 11.0;
                  v_force = 0.34999999;
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 1.0;
                  addbullet(this, NULL, 820, x, y, dir, 1, t, 3);
                }
LABEL_1671:
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
                  h_inerc = h_inerc * 0.5;
              }
            }
            return;
          case 545:
            sub10func();
            field_18C = 6;
            if ( process() )
              set_seq(0);
            if ( get_subseq() || get_frame_time() || get_frame() != 4 )
              return;
            add_card_energy(50);
            spell_energy_spend(200, 120);
            field_190 = 1;
            t[0] = -70.0;
            t[1] = 20.0;
            t[2] = 4.0;
            if ( skills_1[6] <= 3 )
              t[2] = 3.0;
            if ( skills_1[6] <= 1 )
              t[2] = 0.0;
            addbullet(this, NULL, 821, (double)(110 * (char)dir) + x, y + 227.0, dir, 1, t, 3);
            t[0] = 0.0;
            t[1] = 0.5;
            t[2] = 2.0;
            goto LABEL_1696;
          case 546:
            sub10func();
            field_18C = 6;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              t[0] = -50.0;
              t[1] = 20.0;
              t[2] = 4.0;
              if ( skills_1[6] <= 3 )
                t[2] = 3.0;
              if ( skills_1[6] <= 1 )
                t[2] = 0.0;
              addbullet(this, NULL, 821, (double)(110 * (char)dir) + x, y + 227.0, dir, 1, t, 3);
              t[0] = 0.0;
              t[1] = 0.5;
              t[2] = 2.0;
LABEL_1696:
              addbullet(this, NULL, 821, (double)(80 * (char)dir) + x, y, dir, -1, t, 3);
              play_sfx(23);
            }
            return;
          case 550:
            if ( get_subseq() && get_subseq() != 5 )
            {
              v_inerc = v_inerc - v_force;
              if ( get_subseq() == 4 || get_subseq() == 3 && get_frame() >= 3 )
              {
                h_inerc = h_inerc + 0.1000000014901161;
                if ( h_inerc > -2.0 )
                  h_inerc = -2.0;
              }
              if ( get_subseq() == 4 && char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
                set_subseq(5);
                return;
              }
            }
            else
            {
              sub10func();
            }
            field_18C = 10;
            if ( process() || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
LABEL_1378:
              set_seq(0);
              return;
            }
            if ( !get_subseq() )
            {
              if ( !get_frame_time() && get_frame() == 5 )
              {
                add_card_energy(50);
                spell_energy_spend(200, 120);
                h_inerc = 10.0;
                play_sfx(26);
              }
              if ( get_frame() >= 11 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              field_194 = enemy->char_on_ground_flag() != 0;
              if ( field_190 == 1 || field_190 == 7 )
              {
                reset_forces();
                next_subseq();
                set_seq(100);
                enemy->hit_stop = 600;
                goto LABEL_1773;
              }
            }
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 4 )
            {
              scene_add_effect(this, 6, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              scene_play_sfx(6);
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1732;
            if ( get_subseq() == 2 )
            {
              play_sfx(25);
LABEL_1732:
              if ( get_subseq() == 2 )
              {
                field_550 = 0.5;
                if ( skills_1[10] >= 2 )
                  field_550 = 0.64999998;
                if ( skills_1[10] >= 3 )
                  field_550 = 0.75;
                if ( skills_1[10] >= 4 )
                  field_550 = 0.80000001;
                //sub_464110((((double)(char)skills_1[10] * 0.1000000014901161 + 1.0) * 10.0 * field_548), 1000, 0, 1);
                if ( get_elaps_frames() >= 90 )
                  goto LABEL_2474;
              }
            }
            if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 2 )
            {
              /*
              if ( weather_id == 4 )
                //sub_464110(((double)(((double)(char)skills_1[10] * 0.1000000014901161 + 1.0) * 100.0 * field_548) * 1.25), 850, 1, 1);
              else
                //sub_464110(((double)(char)skills_1[10] * 0.1000000014901161 + 1.0) * 100.0 * field_548, 850, 1, 1);  
                */
              scene_add_effect(this, 2, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              scene_play_sfx(3);
              enemy->field_1A4 = 24.5;
              enemy->field_1A8 = 12.5;
              enemy->damage_limit = 100;
              set_seq(74);
              enemy->hit_stop = 5;
              h_inerc = -12.0;
              v_inerc = 12.5;
              v_force = 0.75;
            }
            return;
          case 551:
            if ( get_subseq() && get_subseq() != 5 )
            {
              v_inerc = v_inerc - v_force;
              if ( get_subseq() == 4 || get_subseq() == 3 && get_frame() >= 3 )
              {
                h_inerc = h_inerc + 0.1000000014901161;
                if ( h_inerc > -2.0 )
                  h_inerc = -2.0;
              }
              if ( get_subseq() == 4 && char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
                set_subseq(5);
                return;
              }
            }
            else
            {
              sub10func();
            }
            field_18C = 10;
            if ( process() || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(0);
              return;
            }
            if ( !get_subseq() )
            {
              if ( !get_frame_time() && get_frame() == 5 )
              {
                add_card_energy(50);
                spell_energy_spend(200, 120);
                h_inerc = 22.5;
                play_sfx(26);
              }
              if ( get_frame() >= 13 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              field_194 = enemy->char_on_ground_flag() != 0;
              if ( field_190 == 1 || field_190 == 7 )
              {
                reset_forces();
                next_subseq();
                set_seq(100);
                enemy->hit_stop = 600;
LABEL_1773:
                x = enemy->x - (double)(50 * dir);
                y = enemy->y;
                return;
              }
            }
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 4 )
            {
              scene_add_effect(this, 6, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              scene_play_sfx(6);
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1783;
            if ( get_subseq() == 2 )
            {
              play_sfx(25);
LABEL_1783:
              if ( get_subseq() == 2 )
              {
                field_550 = 0.5;
                if ( skills_1[10] >= 2 )
                  field_550 = 0.64999998;
                if ( skills_1[10] >= 3 )
                  field_550 = 0.75;
                if ( skills_1[10] >= 4 )
                  field_550 = 0.80000001;
                //sub_464110((((double)(char)skills_1[10] * 0.1000000014901161 + 1.0) * 10.0 * field_548), 1000, 0, 1);
                if ( get_elaps_frames() >= 90 )
                {
LABEL_2474:
                  next_subseq();
                  return;
                }
              }
            }
            if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 2 )
            {
              /*
              if ( weather_id == 4 )
                //sub_464110(375, 850, 1, 1);
              else
                //sub_464110(300, 850, 1, 1);
                */
              scene_add_effect(this, 2, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              scene_play_sfx(3);
              enemy->field_1A4 = 24.5;
              enemy->field_1A8 = 12.5;
              enemy->damage_limit = 100;
              set_seq(74);
              enemy->hit_stop = 5;
              h_inerc = -12.0;
              v_inerc = 12.5;
              v_force = 0.75;
            }
            return;
          case 560:
            if ( get_subseq() == 5 )
              sub10func();
            field_18C = 3;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              field_7D0 = 1;
              spell_energy_spend(200, 120);
              h_inerc = -30.0 - (double)(char)skills_1[3] * 5.0;
              v_inerc = 15.0;
              v_force = 0.30000001;
              play_sfx(13);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
            {
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < 10.0 )
                field_7E4 = 10.0;
              if ( field_7E4 > 70.0 )
                field_7E4 = 70.0;
              //set_vec_speed((render_class *)&cEffectSprite, field_7E4, 50.0);
              add_card_energy(50);
              x_off = 0.0;
              y_off = 80.0;
              angZ = field_7E4;
              play_sfx(14);
              t[0] = angZ;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 825, x, y, dir, -1, t, 3);
              return;
            }
            if ( get_subseq() == 1 || get_subseq() == 2 )
              v_inerc = v_inerc - v_force;
            if ( get_subseq() == 2 )
            {
              if ( get_border_near() )
              {
                h_inerc = 0.0;
                v_inerc = 0.0;
                v_force = 0.0;
                next_subseq();
                return;
              }
              if ( char_on_ground_down() )
              {
LABEL_2368:
                reset_forces();
                set_subseq(5);
                y = getlvl_height();
                return;
              }
            }
            if ( get_subseq() == 3 && get_frame() == 2 && get_frame_time() >= 2 && skills_1[3] >= 1 )
              next_frame();
            if ( get_subseq() != 4 )
              goto LABEL_1881;
            if ( char_on_ground_down() )
            {
              reset_ofs();
              y = getlvl_height();
              v_inerc = 0.0;
              next_subseq();
            }
            if ( get_border_near() || (field_190 == 2) || field_190 == 7 )
            {
              reset_ofs();
              set_seq(564);
              goto LABEL_1879;
            }
            if ( get_elaps_frames() < 45 )
              goto LABEL_1881;
            reset_ofs();
            set_seq(564);
            set_subseq(2);
            return;
          case 561:
            if ( get_subseq() == 5 )
              sub10func();
            field_18C = 3;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              field_7D0 = 1;
              spell_energy_spend(200, 120);
              h_inerc = (double)(char)skills_1[3] * 5.0 + 30.0;
              v_inerc = 15.0;
              v_force = 0.30000001;
              play_sfx(13);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
            {
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < 10.0 )
                field_7E4 = 10.0;
              if ( field_7E4 > 70.0 )
                field_7E4 = 70.0;
              //set_vec_speed((render_class *)&cEffectSprite, field_7E4, 50.0);
              add_card_energy(50);
              x_off = 0.0;
              y_off = 80.0;
              angZ = field_7E4;
              play_sfx(14);
              t[0] = angZ;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 825, x, y, dir, -1, t, 3);
              return;
            }
            if ( get_subseq() == 1 || get_subseq() == 2 )
              v_inerc = v_inerc - v_force;
            if ( get_subseq() == 2 )
            {
              if ( get_border_near() )
              {
                h_inerc = 0.0;
                v_inerc = 0.0;
                v_force = 0.0;
                dir = -dir;
                next_subseq();
                return;
              }
              if ( char_on_ground_down() )
                goto LABEL_2195;
            }
            if ( get_subseq() == 3 && get_frame() == 2 && get_frame_time() >= 16 && skills_1[3] >= 1 )
              next_frame();
            if ( get_subseq() != 4 )
              goto LABEL_1881;
            if ( char_on_ground_down() )
            {
              reset_ofs();
              y = getlvl_height();
              v_inerc = 0.0;
              next_subseq();
            }
            if ( get_border_near() || (field_190 == 2) || field_190 == 7 )
            {
              reset_ofs();
              set_seq(564);
LABEL_1879:
              v185 = -12.5;
LABEL_1880:
              h_inerc = v185;
              v_inerc = 10.0;
              v_force = 0.5;
            }
            else
            {
              if ( get_elaps_frames() >= 45 )
              {
                reset_ofs();
                set_seq(564);
                set_subseq(2);
                return;
              }
LABEL_1881:
              if ( get_subseq() == 5 )
              {
                v193 = h_inerc - 5.0;
LABEL_2296:
                h_inerc = v193;
                if ( v193 < 0.0 )
                  h_inerc = 0.0;
              }
            }
            return;
          case 564:
            if ( get_subseq() == 3 )
              sub10func();
            if ( !char_on_ground_flag() )
            {
              v_inerc = v_inerc - v_force;
              h_inerc = h_inerc + 0.5;
              if ( h_inerc > -2.0 )
                h_inerc = -2.0;
            }
            if ( getlvl_height() < v_inerc + y || v_inerc >= 0.0 )
              goto LABEL_2733;
            set_subseq(3);
            air_dash_cnt = 0;
            y = getlvl_height();
            reset_forces();
            return;
          case 565:
            if ( get_subseq() == 6 )
              sub10func();
            if ( get_subseq() == 3 )
            {
              if ( !(get_elaps_frames() % 2) )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 3.0;
                addbullet(this, NULL, 826, x, y + 100.0, dir, -1, t, 3);
              }
              if ( char_on_ground_down() )
              {
                next_subseq();
                //shake_camera(8.0);
                play_sfx(18);
                y = getlvl_height();
                h_inerc = -15.0;
                v_inerc = 12.5;
                v_force = 0.5;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 826, x, y, dir, -1, t, 3);
                t[1] = 15.0;
                t[2] = 1.0;
                /*
                v1153 = 0.0;
                do
                {
                  *(float *)&v1212 = scene_rand_rng(30) + v1153 * 60.0 + 30.0;
                  v667 = *(float *)&v1212;
                  if ( *(float *)&v1212 < 0.0 || v667 > 180.0 )
                    addbullet(this, NULL, 826, x, y, dir, -1, (int)&v1212, 3);
                  else
                    addbullet(this, NULL, 826, x, y, dir, 1, (int)&v1212, 3);
                  v1153 = v1153 + 1.0;
                }
                while ( v1153 < 6.0 );*/
                t[0] = 0.0;
                t[1] = 50.0;
                t[2] = 6.0;
                if ( skills_1[7] <= 3 )
                {
                  t[1] = 42.5;
                  t[2] = 4.0;
                }
                if ( skills_1[7] <= 1 )
                {
                  t[1] = 35.0;
                  t[2] = 4.0;
                }
                addbullet(this, NULL, 826, (double)(50 * (char)dir) + x, y, dir, 1, t, 3);
                addbullet(this, NULL, 826, (double)(50 * dir) + x, y, -dir, 1, t, 3);
              }
            }
            if ( get_subseq() == 4 || get_subseq() == 5 )
            {
              h_inerc = h_inerc + 0.300000011920929;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
                set_subseq(6);
                return;
              }
            }
            field_18C = 7;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              return;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              spell_energy_spend(200, 120);
              play_sfx(13);
              h_inerc = 20.0;
              v_inerc = (700.0 - y) * 0.05000000074505806;
            }
            if ( get_elaps_frames() )
              return;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
              reset_forces();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 3 )
              return;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 2.0;
            goto LABEL_1973;
          case 566:
            if ( get_subseq() == 6 )
              sub10func();
            if ( get_subseq() == 3 )
            {
              if ( !(get_elaps_frames() % 2) )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 3.0;
                addbullet(this, NULL, 826, x, y + 100.0, dir, -1, t, 3);
              }
              if ( char_on_ground_down() )
              {
                next_subseq();
                //shake_camera(8.0);
                play_sfx(18);
                y = getlvl_height();
                h_inerc = -15.0;
                v_inerc = 12.5;
                v_force = 0.5;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 826, x, y, dir, -1, t, 3);
                t[1] = 15.0;
                t[2] = 1.0;
                /*
                v1154 = 0.0;
                do
                {
                  *(float *)&v1215 = scene_rand_rng(30) + v1154 * 60.0 + 30.0;
                  v677 = *(float *)&v1215;
                  if ( *(float *)&v1215 < 0.0 || v677 > 180.0 )
                    addbullet(this, NULL, 826, x, y, dir, -1, (int)&v1215, 3);
                  else
                    addbullet(this, NULL, 826, x, y, dir, 1, (int)&v1215, 3);
                  v1154 = v1154 + 1.0;
                }
                while ( v1154 < 6.0 );*/
                t[0] = 0.0;
                t[1] = 50.0;
                t[2] = 6.0;
                if ( skills_1[7] <= 3 )
                {
                  t[1] = 42.5;
                  t[2] = 4.0;
                }
                if ( skills_1[7] <= 1 )
                {
                  t[1] = 35.0;
                  t[2] = 4.0;
                }
                addbullet(this, NULL, 826, (double)(50 * (char)dir) + x, y, dir, 1, t, 3);
                addbullet(this, NULL, 826, (double)(50 * dir) + x, y, -dir, 1, t, 3);
              }
            }
            if ( get_subseq() != 4 && get_subseq() != 5 )
              goto LABEL_2739;
            h_inerc = h_inerc + 0.300000011920929;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              reset_forces();
              y = getlvl_height();
              set_subseq(6);
            }
            else
            {
LABEL_2739:
              field_18C = 7;
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  spell_energy_spend(200, 120);
                  play_sfx(13);
                  h_inerc = 40.0;
                  v_inerc = (700.0 - y) * 0.05000000074505806;
                }
                if ( !get_elaps_frames() )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
                    reset_forces();
                  if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                  {
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 2.0;
LABEL_1973:
                    addbullet(this, NULL, 826, x, y, dir, 1, t, 3);
                    v_inerc = -50.0;
                    add_card_energy(50);
                  }
                }
              }
            }
            return;
          case 570:
            if ( get_subseq() && get_subseq() != 3 )
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
            else
            {
              sub10func();
            }
            field_18C = 11;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1986;
            if ( get_subseq() != 1 )
              return;
            play_sfx(13);
            h_inerc = -4.0;
            v_inerc = 17.5;
            v_force = 0.5;
LABEL_1986:
            if ( get_subseq() != 1 )
              return;
            if ( get_frame_time() || get_frame() != 11 )
              return;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            field_190 = 1;
            t[0] = 45.0;
            t[1] = 20.0;
            t[2] = 5.0;
            if ( skills_1[11] >= 3 )
              t[2] = 0.0;
            addbullet(this, NULL, 827, (double)(60 * (char)dir) + x, y + 20.0, dir, 1, t, 3);
            t[1] = 0.30000001;
            t[2] = 4.0;
            goto LABEL_2010;
          case 571:
            if ( get_subseq() && get_subseq() != 3 )
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
            else
            {
              sub10func();
            }
            field_18C = 11;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2004;
            if ( get_subseq() == 1 )
            {
              play_sfx(13);
              h_inerc = -6.0;
              v_inerc = 17.5;
              v_force = 0.5;
LABEL_2004:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 11 )
              {
                spell_energy_spend(200, 120);
                add_card_energy(50);
                field_190 = 1;
                t[0] = 30.0;
                t[1] = 20.0;
                t[2] = 5.0;
                if ( skills_1[11] >= 3 )
                  t[2] = 0.0;
                addbullet(this, NULL, 827, (double)(60 * (char)dir) + x, y + 20.0, dir, 1, t, 3);
                t[1] = 0.30000001;
                t[2] = 4.0;
LABEL_2010:
                addbullet(this, NULL, 827, (double)(60 * (char)dir) + x, y + 20.0, dir, 1, t, 3);
                v_inerc = 10.0;
                v43 = -7.5;
LABEL_2011:
                h_inerc = v43;
                v_force = 0.75;
              }
            }
            return;
          case 600:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 200.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( get_subseq() == 6 )
              sub10func();
            sub_46AB50(6, 2);
            if ( get_subseq() == 3 && get_elaps_frames() > 60 )
              goto LABEL_2364;
            if ( get_subseq() == 1 || get_subseq() == 2 || get_subseq() == 3 )
            {
              y = getlvl_height() + 240.0 - field_7DC;
              if ( 0.0 != field_7DC )
                field_7DC = field_7DC * 0.949999988079071;
              if ( field_7DC <= 1.0 )
                field_7DC = 0.0;
            }
            if ( get_subseq() >= 4 && get_subseq() <= 5 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_2109;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() || !get_frame_time() || !get_frame() || get_subseq() == 1 ) //conditions reversed (except the ORs)
            {
              v_inerc = 0.0;
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 2 )
              return;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            goto LABEL_2381;
          case 601:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(14 * (char)dir), y + 190.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              play_sfx(52);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 851, x, y, dir, 1, t, 3);
            }
            sub10func();
            sub_46AB50(6, 2);
            if ( process() )
              set_seq(0);
            if ( get_frame_time() || get_frame() != 12 )
              return;
            t[0] = 0.0;
            t[1] = 60.0;
            t[2] = 2.0;
            addbullet(this, NULL, 851, (double)(100 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
            t[2] = 4.0;
            addbullet(this, NULL, 851, (double)(100 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
            goto LABEL_2137;
          case 602:
            if ( !get_subseq() || get_subseq() == 6 )
              sub10func();
            if ( get_subseq() <= 3 )
            {
              sub_46AB50(6, 2);
              if ( get_subseq() == 3 && ++field_7D0 >= 20 )
                goto LABEL_2144;
            }
            if ( get_subseq() == 2 || get_subseq() == 3 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = scene_rand_rng(2);
              addbullet(this, NULL, 852, (double)(75 * (char)dir) + x, y + 145.0, dir, 1, t, 3);
            }
            if ( get_subseq() != 4 && get_subseq() != 5 )
              goto LABEL_2740;
            h_inerc = h_inerc - 0.2000000029802322;
            if ( h_inerc < 2.0 )
              h_inerc = 2.0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              reset_forces();
              y = getlvl_height();
LABEL_2069:
              set_subseq(6);
            }
            else
            {
LABEL_2740:
              if ( field_190 )
              {
                if ( field_194 > 0 && ++field_7D2 >= 3 )
                {
                  field_7D2 = 0;
                  field_190 = 0;
                }
              }
              if ( process() )
                set_seq(0);
              if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(53 * (char)dir), y + 76.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  h_inerc = 15.0;
                  v_inerc = 15.0;
                  play_sfx(54);
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
LABEL_2089:
                  set_seq(9);
              }
            }
            return;
          case 603:
            if ( get_subseq() == 6 )
              sub10func();
            sub_46AB50(6, 2);
            if ( get_subseq() != 2 )
              goto LABEL_2741;
            if ( !(get_elaps_frames() % 7) )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 6.0;
              //*(float *)&v728 = (getlvl_height() + 50.0) - scene_rand_rng(100);
              //v731 = *(float *)&v728;
              //*(float *)&v728 = (x + 400.0) - scene_rand_rng(800);
              addbullet(this, NULL, 853, x + 400.0/*v728*/, getlvl_height() + 50.0/*v731*/, dir, 1, t, 3);
            }
            if ( get_elaps_frames() < 120 )
            {
LABEL_2741:
              if ( get_subseq() == 3 && get_elaps_frames() >= 24 )
              {
LABEL_2364:
                next_subseq();
                v_force = 0.40000001;
              }
              else
              {
                if ( get_subseq() == 1 || get_subseq() == 2 || get_subseq() == 3 )
                {
                  y = getlvl_height() + 320.0 - field_7DC;
                  if ( 0.0 != field_7DC )
                    field_7DC = field_7DC * 0.949999988079071;
                  if ( field_7DC <= 1.0 )
                    field_7DC = 0.0;
                }
                if ( get_subseq() >= 4 && get_subseq() <= 5 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
                {
LABEL_2109:
                  reset_forces();
                  set_subseq(6);
                  y = getlvl_height();
                }
                else
                {
                  if ( process() )
                    set_seq(0);
                  if ( !get_elaps_frames() || !get_frame_time() || !get_frame() || get_subseq() == 1 ) //conditions reversed (except ORs)
                  {
                    v_inerc = 0.0;
                  }
                  if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
                  {
                    field_4A6 = 40;
                    scene_play_sfx(23);
                    scene_add_effect(this, 115, x, y + 200.0, dir, 1);
                    sub_469450(0, 0, 60);
                    sub_483570();
                    weather_forecast_next();
                  }
                  if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  {
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 0.0;
                    addbullet(this, NULL, 853, x, getlvl_height(), dir, 1, t, 3);
                    t[2] = 4.0;
                    addbullet(this, NULL, 853, x, getlvl_height(), dir, 1, t, 3);
                    t[2] = 5.0;
                    addbullet(this, NULL, 853, x, y + 200.0, dir, 1, t, 3);
                    play_sfx(51);
                  }
                }
              }
            }
            else
            {
              next_subseq();
            }
            return;
          case 604:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(14 * (char)dir), y + 190.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              play_sfx(52);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 854, x, y, dir, 1, t, 3);
            }
            sub10func();
            sub_46AB50(6, 2);
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 12 )
            {
              t[0] = 0.0;
              t[1] = 100.0;
              t[2] = 2.0;
              addbullet(this, NULL, 854, (double)(100 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
              t[2] = 4.0;
              addbullet(this, NULL, 854, (double)(100 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
              t[2] = 5.0;
              addbullet(this, NULL, 854, (double)(100 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
LABEL_2137:
              play_sfx(53);
            }
            return;
          case 605:
            if ( !get_subseq() || get_subseq() == 4 )
              sub10func();
            if ( get_subseq() > 1 )
              goto LABEL_2146;
            sub_46AB50(6, 2);
            if ( get_subseq() != 1 )
              goto LABEL_2146;
            if ( ++field_7D0 < 45 )
            {
LABEL_2146:
              if ( get_subseq() == 1 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = scene_rand_rng(2);
                addbullet(this, NULL, 855, (double)(90 * (char)dir) + x, y + 125.0, dir, 1, t, 3);
              }
              if ( get_subseq() != 2 && get_subseq() != 3 )
                goto LABEL_2742;
              h_inerc = h_inerc - 0.2000000029802322;
              if ( h_inerc < 2.0 )
                h_inerc = 2.0;
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
LABEL_2154:
                set_subseq(4);
              }
              else
              {
LABEL_2742:
                if ( field_190 )
                {
                  if ( field_194 > 0 && ++field_7D2 >= 3 )
                  {
                    field_7D2 = 0;
                    field_190 = 0;
                  }
                }
                if ( process() )
                  set_seq(0);
                if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
                {
                  field_4A6 = 40;
                  scene_play_sfx(23);
                  scene_add_effect(this, 115, x - (double)(53 * (char)dir), y + 76.0, dir, 1);
                  sub_469450(0, 0, 60);
                  sub_483570();
                  weather_forecast_next();
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  h_inerc = 27.5;
                  v_inerc = 15.0;
                  play_sfx(55);
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 2.0;
                  addbullet(this, NULL, 855, (double)(90 * (char)dir) + x, y + 125.0, dir, 1, t, 3);
                }
              }
            }
            else
            {
LABEL_2144:
              v_force = 0.5;
              next_subseq();
              v_inerc = v_inerc * 0.5;
              h_inerc = 0.5 * h_inerc;
            }
            return;
          case 606:
            if ( get_subseq() > 3 || get_subseq() == 3 && get_frame() >= 3 )
              sub_46AB50(6, 2);
            if ( get_subseq() == 5 )
              sub10func();
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              field_7D0 = 1;
              h_inerc = -25.0;
              v_inerc = 25.0;
              v_force = 0.30000001;
              play_sfx(13);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
            {
              h_inerc = 50.0;
              v_inerc = v_inerc - 25.0;
              play_sfx(56);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL, 856, (double)(90 * (char)dir) + x, y + 25.0, dir, 1, t, 3);
              return;
            }
            if ( get_subseq() == 1 || get_subseq() == 2 )
              v_inerc = v_inerc - v_force;
            if ( get_subseq() != 2 )
              goto LABEL_2196;
            if ( get_border_near() )
            {
              h_inerc = 0.0;
              v_inerc = 0.0;
              v_force = 0.0;
              next_subseq();
            }
            else if ( char_on_ground_down() )
            {
LABEL_2195:
              reset_forces();
              set_subseq(5);
              y = getlvl_height();
            }
            else
            {
LABEL_2196:
              if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 3 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(53 * (char)dir), y + 76.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( get_subseq() == 4 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = scene_rand_rng(2);
                addbullet(this, NULL, 856, (double)(90 * (char)dir) + x, y + 125.0, dir, 1, t, 3);
                if ( char_on_ground_down() )
                {
                  reset_ofs();
                  y = getlvl_height();
                  v_inerc = 0.0;
                  next_subseq();
                }
              }
              if ( get_subseq() == 5 )
              {
                h_inerc = h_inerc - 5.0;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
            }
            return;
          case 607:
            sub_46AB50(6, 2);
            if ( get_subseq() != 1 )
              goto LABEL_2214;
            if ( get_elaps_frames() >= 120 )
              goto LABEL_2388;
            if ( !(get_elaps_frames() % 15) && field_7DC < 4.0 )
            {
              tt[0] = field_7DC * 90.0 + field_7E4;
              tt[1] = 0.0;
              tt[2] = 1.0;
              tt[3] = 0.0;
              addbullet(this, NULL, 857, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
              if ( 0.0 == field_7DC )
              {
                tt[2] = 0.0;
                addbullet(this, NULL, 857, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
              }
              play_sfx(16);
              field_7DC = field_7DC + 1.0;
            }
LABEL_2214:
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 100.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            return;
          case 608:
            sub10func();
            sub_46AB50(6, 2);
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 3 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(5 * (char)dir), y + 112.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            //if ( get_frame_time() )
            //  goto LABEL_2233;
            /*
            v811 = __OFSUB__(get_frame(), 4);
            v810 = (signed __int16)(get_frame() - 4) < 0;
            */
            if ( get_frame() == 4 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 858, x, y, dir, 1, t, 3);
              play_sfx(63);
//LABEL_2233:
              /*
              v811 = __OFSUB__(get_frame(), 4);
              v810 = (signed __int16)(get_frame() - 4) < 0;
              */
            }
            /*
            if ( !(v810 ^ v811) )
              field_890 = 600;
            */
            return;
          case 609:
            sub10func();
            if ( get_subseq() <= 1 )
            {
              sub_46AB50(6, 2);
              if ( get_subseq() == 1 && ++field_7D0 >= 60 )
                goto LABEL_2388;
            }
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 1.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(64);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 859, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, -1, t, 3);
            }
            if ( get_subseq() == 2 && !get_frame_time() )
            {
              if ( get_frame() == 1 )
                h_inerc = 40.0;
              if ( !get_frame_time() && get_frame() == 2 )
              {
                //shake_camera(3.0);
                h_inerc = 20.0;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 859, x, y, dir, 1, t, 3);
                play_sfx(65);
                /*
                v1155 = 0.0;
                do
                {
                  *(float *)&v1233 = scene_rand_rng(10) + v1155 * 18.0;
                  v1234 = scene_rand_rng(40) * 0.1000000014901161 + 18.0;
                  v1235 = 2.0;
                  v823 = -*(float *)&v1233;
                  v824 = sin_deg(v823) > 0.0;
                  addbullet(this, NULL, 859, x, y, dir, (1 - 2 * v824), (int)&v1233, 3);
                  v1155 = v1155 + 1.0;
                }
                while ( v1155 < 20.0 );
                */
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
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 )
                h_inerc = 15.0;
              if ( !get_frame_time() )
              {
                if ( get_frame() == 7 )
                  scene_play_sfx(29);
                if ( !get_frame_time() && get_frame() == 8 )
                  h_inerc = 0.0;
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
              goto LABEL_2724;
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
                goto LABEL_2474;
            }
LABEL_2294:
            if ( get_subseq() != 2 )
              return;
            v193 = h_inerc - 0.5;
            goto LABEL_2296;
          case 708:
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc + 2.0;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
            }
            if ( char_on_ground_flag() )
              goto LABEL_2743;
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            v_inerc = v_inerc - 0.5;
            if ( getlvl_height() < (v_inerc + y) || v_inerc >= 0.0 )
            {
LABEL_2743:
              if ( process() )
              {
                set_seq(700);
              }
              else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
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
              y = getlvl_height();
              set_subseq(2);
            }
            return;
          case 709:
            if ( !get_subseq() )
            {
              v_inerc = v_inerc - v_force;
              if ( getlvl_height() >= (v_inerc + y) && v_inerc < 0.0 )
              {
                next_subseq();
                goto LABEL_2716;
              }
            }
            if ( get_subseq() == 1 )
            {
              h_inerc = h_inerc - 0.75;
              if ( h_inerc <= 0.0 )
              {
                h_inerc = 0.0;
                if ( ++field_7D0 >= 2 )
                {
                  next_subseq();
                  h_inerc = -5.0;
                  v_inerc = 5.0;
                }
              }
            }
            if ( get_subseq() != 2 && get_subseq() != 3 )
              goto LABEL_2723;
            v_inerc = v_inerc - 0.25;
            if ( getlvl_height() < (v_inerc + y) || v_inerc >= 0.0 )
              goto LABEL_2723;
            reset_forces();
            y = getlvl_height();
            next_subseq();
            return;
          case 710:
            if ( get_subseq() != 1 )
              goto LABEL_2351;
            if ( get_elaps_frames() >= 120 )
              goto LABEL_2388;
            if ( !(get_elaps_frames() % 15) )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  if ( field_7E4 >= 90.0 )
                    field_7E4 = 90.0;
                  if ( field_7E4 <= -90.0 )
                    field_7E4 = -90.0;
                  if ( 0.0 == field_7DC )
                  {
                    tt[0] = field_7E4;
                    tt[1] = 0.0;
                    tt[2] = 1.0;
                    tt[3] = 0.0;
                    addbullet(this, NULL, 900, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
                    tt[2] = 0.0;
                    addbullet(this, NULL, 900, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
                    goto LABEL_2334;
                  }
                  break;
                case 1:
                  if ( field_7E4 >= 90.0 )
                    field_7E4 = 90.0;
                  if ( field_7E4 <= -90.0 )
                    field_7E4 = -90.0;
                  if ( field_7DC < 2.0 )
                  {
                    tt[0] = field_7DC * 90.0 + field_7E4 - 45.0;
                    tt[1] = 0.0;
                    tt[2] = 1.0;
                    tt[3] = 0.0;
                    addbullet(this, NULL, 900, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
                    tt[0] = field_7DC * 90.0 + field_7E4;
                    if ( 0.0 == field_7DC )
                    {
                      tt[2] = 0.0;
                      addbullet(this, NULL, 900, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
                    }
                    goto LABEL_2334;
                  }
                  break;
                case 2:
                  if ( field_7DC < 3.0 )
                  {
                    tt[0] = field_7DC * 120.0 + field_7E4;
                    tt[1] = 0.0;
                    tt[2] = 1.0;
                    tt[3] = 0.0;
                    addbullet(this, NULL, 900, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
                    tt[0] = 0.0;
                    if ( 0.0 == field_7DC )
                    {
                      tt[2] = 0.0;
                      addbullet(this, NULL, 900, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
                    }
                    goto LABEL_2334;
                  }
                  break;
                case 3:
                  if ( field_7DC < 4.0 )
                  {
                    tt[0] = field_7DC * 90.0 + field_7E4;
                    tt[1] = 0.0;
                    tt[2] = 1.0;
                    tt[3] = 0.0;
                    addbullet(this, NULL, 900, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
                    if ( 0.0 == field_7DC )
                    {
                      tt[2] = 0.0;
                      addbullet(this, NULL, 900, (double)(20 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
                    }
LABEL_2334:
                    play_sfx(16);
                    field_7DC = field_7DC + 1.0;
                  }
                  break;
                default:
                  break;
              }
            }
LABEL_2351:
            if ( get_subseq() == 2 && get_elaps_frames() >= 60 )
              goto LABEL_2388;
            if ( process() )
              set_seq(700);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            }
            return;
          case 711:
            if ( get_subseq() == 5 )
              sub10func();
            if ( get_subseq() == 2 && get_elaps_frames() > 60 )
              goto LABEL_2364;
            if ( get_subseq() >= 3 && get_subseq() <= 4 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_2368;
            }
            if ( process() )
              set_seq(700);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                v_inerc = 0.0;
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
LABEL_2381:
                addbullet(this, NULL, 850, x, getlvl_height(), dir, 1, t, 3);
                play_sfx(50);
              }
            }
            return;
          case 720:
            if ( !get_subseq() || get_subseq() == 6 )
              sub10func();
            if ( get_subseq() == 1 && y >= 1280.0 )
            {
              y = 1280.0;
              reset_forces();
LABEL_2388:
              next_subseq();
              return;
            }
            if ( get_subseq() == 2 )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  if ( !get_elaps_frames() )
                  {
                    x = enemy->x;
                    field_7DC = enemy->x;
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 6.0;
                    addbullet(this, NULL, 901, x, 0.0, dir, -1, t, 3);
                    
                  }
                  /*
                  v903 = __OFSUB__(get_elaps_frames(), 60);
                  v902 = get_elaps_frames() - 60 < 0;
                  */
                  goto LABEL_2403;
                case 1:
                  if ( get_elaps_frames() == 15 )
                  {
                    x = enemy->x;
                    field_7DC = enemy->x;
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 6.0;
                    addbullet(this, NULL, 901, x, 0.0, dir, -1, t, 3);
                    
                  }
                  /*
                  v903 = __OFSUB__(get_elaps_frames(), 80);
                  v902 = get_elaps_frames() - 80 < 0;
                  */
                  goto LABEL_2403;
                case 2:
                  if ( get_elaps_frames() == 30 )
                  {
                    x = enemy->x;
                    field_7DC = enemy->x;
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 6.0;
                    addbullet(this, NULL, 901, x, 0.0, dir, -1, t, 3);
                    
                  }
                  //v903 = __OFSUB__(get_elaps_frames(), 100);
                  //v902 = get_elaps_frames() - 100 < 0;
                  goto LABEL_2403;
                case 3:
                  if ( get_elaps_frames() == 45 )
                  {
                    x = enemy->x;
                    field_7DC = enemy->x;
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 6.0;
                    addbullet(this, NULL, 901, x, 0.0, dir, -1, t, 3);
                    
                  }
                  //v903 = __OFSUB__(get_elaps_frames(), 120);
                  //v902 = get_elaps_frames() - 120 < 0;
LABEL_2403:
                  //if ( !(v902 ^ v903) )
                  //  x = field_7DC;
                  break;
                default:
                  break;
              }
              if ( get_elaps_frames() >= 60 )
              {
                next_subseq();
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 2.0;
                addbullet(this, NULL, 901, x, y, dir, 1, t, 3);
                v_inerc = -70.0;
                
              }
            }
            if ( get_subseq() != 3 )
              goto LABEL_2427;
            x = field_7DC;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 3.0;
            addbullet(this, NULL, 901, x, y + 100.0, dir, -1, t, 3);
            if ( !char_on_ground_down() )
              goto LABEL_2426;
            next_subseq();
            //shake_camera(8.0);
            play_sfx(57);
            y = getlvl_height();
            h_inerc = -15.0;
            v_inerc = 15.0;
            v_force = 0.40000001;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 901, x, y, dir, -1, t, 3);
            t[1] = 25.0;
            t[2] = 1.0;
            /*
            v1156 = 0.0;
            do
            {
              *(float *)&v1199 = scene_rand_rng(30) + v1156 * 45.0 + 30.0;
              v908 = *(float *)&v1199;
              if ( *(float *)&v1199 < 0.0 || v908 > 180.0 )
                addbullet(this, NULL, 901, x, y, dir, -1, (int)&v1199, 3);
              else
                addbullet(this, NULL, 901, x, y, dir, 1, (int)&v1199, 3);
              v1156 = v1156 + 1.0;
            }
            while ( v1156 < 8.0 );*/
            t[0] = 0.0;
            t[1] = 35.0;
            t[2] = 4.0;
            addbullet(this, NULL, 901, (double)(50 * dir) + x, y, dir, 1, t, 3);
            addbullet(this, NULL, 901, (double)(50 * dir) + x, y, -dir, 1, t, 3);
            
            switch ( settings_get()->get_difficulty() )
            {
              case 1:
              /*
                v1159 = 0.0;
                v914 = (float)0.0;
                do
                {
                  *(float *)&v1199 = -45.0 - v914 * 45.0;
                  v1200 = 10.0;
                  v1201 = 7.0;
                  addbullet(this, NULL, 901, x, y, dir, 1, (int)&v1199, 3);
                  v1159 = v1159 + 1.0;
                  v914 = v1159;
                }
                while ( v1159 < 3.0 );*/
                break;
              case 2:
              /*
                v1158 = 0.0;
                v913 = (float)0.0;
                do
                {
                  *(float *)&v1199 = -30.0 - v913 * 30.0;
                  v1200 = 10.0;
                  v1201 = 7.0;
                  addbullet(this, NULL, 901, x, y, dir, 1, (int)&v1199, 3);
                  v1158 = v1158 + 1.0;
                  v913 = v1158;
                }
                while ( v1158 < 5.0 );*/
                break;
              case 3:/*
                v1157 = 0.0;
                v912 = (float)0.0;
                do
                {
                  *(float *)&v1199 = -30.0 - v912 * 20.0;
                  v1200 = 10.0;
                  v1201 = 7.0;
                  addbullet(this, NULL, 901, x, y, dir, 1, (int)&v1199, 3);
                  v1157 = v1157 + 1.0;
                  v912 = v1157;
                }
                while ( v1157 < 7.0 );*/
                break;
              default:
                goto LABEL_2427;
            }
LABEL_2426:
            
LABEL_2427:
            if ( get_subseq() != 4 && get_subseq() != 5 )
              goto LABEL_2744;
            if ( settings_get()->get_difficulty() == 3 )
            {
              if ( get_border_near() == 1 && dir == 1 || get_border_near() == -1 && dir == -1 )
              {
                h_inerc = 0.0;
                v_inerc = 0.0;
                v_force = 0.0;
                set_seq(721);
                set_subseq(3);
                field_194 = 1;
                return;
              }
              
            }
            h_inerc = h_inerc + 0.1000000014901161;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              reset_forces();
              y = getlvl_height();
              set_subseq(6);
            }
            else
            {
LABEL_2744:
              if ( process() )
                set_seq(700);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                play_sfx(13);
                h_inerc = 0.0;
                v_inerc = 40.0;
              }
            }
            return;
          case 721:
            if ( get_subseq() == 7 )
              sub10func();
            if ( process() )
              set_seq(700);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              field_7D0 = 1;
              h_inerc = -30.0;
              v_inerc = scene_rand_rng(12) + 10.0;
              v_force = 0.30000001;
              play_sfx(13);
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 4 )
            {
              if ( get_subseq() == 1 || get_subseq() == 2 )
                v_inerc = v_inerc - v_force;
              if ( get_subseq() != 2 )
                goto LABEL_2745;
              if ( get_border_near() == 1 && dir == 1 || get_border_near() == -1 && dir == -1 )
              {
                h_inerc = 0.0;
                v_inerc = 0.0;
                v_force = 0.0;
                goto LABEL_2474;
              }
              if ( char_on_ground_down() )
              {
                reset_forces();
                set_subseq(7);
                y = getlvl_height();
              }
              else
              {
LABEL_2745:
                if ( get_subseq() != 4 )
                  goto LABEL_2746;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 10.0;
                addbullet(this, NULL, 901, (double)(50 * (char)dir) + x, y + 80.0, dir, -1, t, 3);
                if ( char_on_ground_down() )
                {
                  reset_ofs();
                  y = getlvl_height();
                  v_inerc = 0.0;
                  set_subseq(7);
                }
                if ( (get_border_near() != 1 || dir != -1) && (get_border_near() != -1 || dir != 1) )
                {
LABEL_2746:
                  if ( get_subseq() == 5 || get_subseq() == 6 )
                  {
                    v_inerc = v_inerc - v_force;
                    if ( char_on_ground_down() )
                    {
LABEL_2499:
                      reset_forces();
                      y = getlvl_height();
                      set_subseq(7);
                    }
                    else
                    {
                      h_inerc = h_inerc + 0.1000000014901161;
                      if ( h_inerc > 0.0 )
                        h_inerc = 0.0;
                    }
                  }
                }
                else
                {
                  reset_ofs();
                  set_subseq(5);
                  h_inerc = -15.0;
                  v_inerc = 12.0;
                  v_force = 0.5;
                  //shake_camera(8.0);
                  play_sfx(57);
                  switch ( settings_get()->get_difficulty() )
                  {
                    case 1:
                    /*
                      v1162 = 0.0;
                      v931 = (float)0.0;
                      do
                      {
                        *(float *)&v1224 = -135.0 - v931 * 45.0;
                        v1225 = 10.0;
                        v1226 = 7.0;
                        addbullet(this, NULL, 901, x, y, dir, 1, (int)&v1224, 3);
                        v1162 = v1162 + 1.0;
                        v931 = v1162;
                      }
                      while ( v1162 < 3.0 );*/
                      break;
                    case 2:/*
                      v1161 = 0.0;
                      v930 = (float)0.0;
                      do
                      {
                        *(float *)&v1224 = -120.0 - v930 * 30.0;
                        v1225 = 10.0;
                        v1226 = 7.0;
                        addbullet(this, NULL, 901, x, y, dir, 1, (int)&v1224, 3);
                        v1161 = v1161 + 1.0;
                        v930 = v1161;
                      }
                      while ( v1161 < 5.0 );*/
                      break;
                    case 3:/*
                      v1160 = 0.0;
                      v929 = (float)0.0;
                      do
                      {
                        *(float *)&v1224 = -120.0 - v929 * 20.0;
                        v1225 = 10.0;
                        v1226 = 7.0;
                        addbullet(this, NULL, 901, x, y, dir, 1, (int)&v1224, 3);
                        v1160 = v1160 + 1.0;
                        v929 = v1160;
                      }
                      while ( v1160 < 7.0 );*/
                      break;
                  }
                }
              }
            }
            else
            {
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < 10.0 )
                field_7E4 = 10.0;
              if ( field_7E4 > 70.0 )
                field_7E4 = 70.0;
              field_7E4 = 0.0;
              //set_vec_speed((render_class *)&cEffectSprite, 0.0, 50.0);
              x_off = 0.0;
              y_off = 80.0;
              angZ = field_7E4;
              play_sfx(14);
              t[0] = angZ;
              t[1] = 0.0;
              t[2] = 9.0;
              addbullet(this, NULL, 901, x, y, dir, 1, t, 3);
            }
            return;
          case 730:
            if ( get_subseq() != 1 && get_subseq() != 2 )
              goto LABEL_2520;
            if ( get_elaps_frames() <= 60 )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  goto LABEL_2514;
                case 1:
                  if ( !(get_elaps_frames() % 6) )
                  {
                    play_sfx(58);
                    t[0] = scene_rand_rng(360);
                    t[1] = scene_rand_rng(60) * 0.1000000014901161 + 4.0;
                    t[2] = 0.0;
                    addbullet(this, NULL, 902, (double)(30 * (char)dir) + x, y + 90.0, dir, 1, t, 3);
                  }
LABEL_2514:
                  if ( get_elaps_frames() % 10 )
                    break;
                  play_sfx(58);
                  t[0] = scene_rand_rng(360);
                  t[1] = scene_rand_rng(40) * 0.1000000014901161 + 4.0;
                  t[2] = 0.0;
                  goto LABEL_2516;
                case 2:
                /*
                  v940 = (get_elaps_frames() & 0x80000003) == 0;
                  if ( get_elaps_frames() < 0 )
                    v940 = ((get_elaps_frames() - 1) | 0xFFFFFFFC) == -1;
                  if ( !v940 )
                    break;
                  */
                  play_sfx(58);
                  t[0] = scene_rand_rng(360);
                  t[1] = scene_rand_rng(80) * 0.1000000014901161 + 4.0;
                  t[2] = 0.0;
                  goto LABEL_2516;
                case 3:
                  if ( !(get_elaps_frames() % 3) )
                  {
                    play_sfx(58);
                    t[0] = scene_rand_rng(360);
                    t[1] = scene_rand_rng(100) * 0.1000000014901161 + 4.0;
                    t[2] = 0.0;
LABEL_2516:
                    addbullet(this, NULL, 902, (double)(30 * (char)dir) + x, y + 90.0, dir, 1, t, 3);
                  }
                  break;
                default:
                  break;
              }
            }
            if ( get_elaps_frames() < 50 )
              goto LABEL_2520;
            /*
            if ( color_A < 0xAu )
              goto LABEL_2579;
            color_A = color_A - 10;*/
LABEL_2520:
            if ( get_subseq() != 3 )
              goto LABEL_2747;
            if ( get_elaps_frames() == 45 )
            {
              x = enemy->x;
              y = enemy->y;
              play_sfx(59);
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                /*
                  v1166 = 0.0;
                  do
                  {
                    a4 = scene_rand_rng(360);
                    v1194 = scene_rand_rng(12) + 18.0;
                    v1195 = 1.0;
                    v979 = dir;
                    v980 = 180.0 - a4;
                    v981 = sin_deg(v980);
                    v982 = v981 * (v1194 * 60.0) + y + 100.0;
                    v983 = v982;
                    v984 = 180.0 - a4;
                    v985 = cos_deg(v984);
                    v986 = v985 * (v1194 * 60.0) * (double)dir + x;
                    addbullet(this, NULL, 902, v986, v983, v979, 1, (int)&a4, 3);
                    v1166 = v1166 + 1.0;
                  }
                  while ( v1166 < 10.0 );*/
                  break;
                case 1:/*
                  v1165 = 0.0;
                  do
                  {
                    a4 = scene_rand_rng(360);
                    v1194 = scene_rand_rng(12) + 18.0;
                    v1195 = 1.0;
                    v971 = dir;
                    v972 = 180.0 - a4;
                    v973 = sin_deg(v972);
                    v974 = v973 * (v1194 * 60.0) + y + 100.0;
                    v975 = v974;
                    v976 = 180.0 - a4;
                    v977 = cos_deg(v976);
                    v978 = v977 * (v1194 * 60.0) * (double)dir + x;
                    addbullet(this, NULL, 902, v978, v975, v971, 1, (int)&a4, 3);
                    v1165 = v1165 + 1.0;
                  }
                  while ( v1165 < 10.0 );*/
                  break;
                case 2:/*
                  v1164 = 0.0;
                  do
                  {
                    a4 = scene_rand_rng(360);
                    v1194 = scene_rand_rng(12) + 18.0;
                    v1195 = 1.0;
                    v963 = dir;
                    v964 = 180.0 - a4;
                    v965 = sin_deg(v964);
                    v966 = v965 * (v1194 * 60.0) + y + 100.0;
                    v967 = v966;
                    v968 = 180.0 - a4;
                    v969 = cos_deg(v968);
                    v970 = v969 * (v1194 * 60.0) * (double)dir + x;
                    addbullet(this, NULL, 902, v970, v967, v963, 1, (int)&a4, 3);
                    v1164 = v1164 + 1.0;
                  }
                  while ( v1164 < 15.0 );*/
                  break;
                case 3:/*
                  v1163 = 0.0;
                  do
                  {
                    a4 = scene_rand_rng(360);
                    v1194 = scene_rand_rng(12) + 18.0;
                    v1195 = 1.0;
                    v955 = dir;
                    v956 = 180.0 - a4;
                    v957 = sin_deg(v956);
                    v958 = v957 * (v1194 * 60.0) + y + 100.0;
                    v959 = v958;
                    v960 = 180.0 - a4;
                    v961 = cos_deg(v960);
                    v962 = v961 * (v1194 * 60.0) * (double)dir + x;
                    addbullet(this, NULL, 902, v962, v959, v955, 1, (int)&a4, 3);
                    v1163 = v1163 + 1.0;
                  }
                  while ( v1163 < 20.0 );*/
                  break;
                default:
                  break;
              }
            }
            if ( get_elaps_frames() != 85 )
            {
LABEL_2747:
              if ( process() )
              {
                if ( char_on_ground_down() == 0 )
                {
                  set_seq(704);
                  v_force = 0.30000001;
                }
                else
                {
                  set_seq(700);
                }
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                h_inerc = 12.0;
                v_inerc = 18.0;
              }
            }
            else
            {
              play_sfx(60);
              switch ( settings_get()->get_difficulty() )
              {
                case 1:/*
                  v1169 = 0.0;
                  do
                  {
                    *(float *)&v1205 = scene_rand_rng(360);
                    v1206 = scene_rand_rng(10) + 2.0;
                    v1207 = 5.0;
                    v989 = y + 100.0;
                    addbullet(this, NULL, 902, x, v989, dir, 1, (int)&v1205, 3);
                    v1169 = v1169 + 1.0;
                  }
                  while ( v1169 < 12.0 );*/
                  break;
                case 2:/*
                  v1168 = 0.0;
                  do
                  {
                    *(float *)&v1205 = scene_rand_rng(360);
                    v1206 = scene_rand_rng(10) + 2.0;
                    v1207 = 5.0;
                    v988 = y + 100.0;
                    addbullet(this, NULL, 902, x, v988, dir, 1, (int)&v1205, 3);
                    v1168 = v1168 + 1.0;
                  }
                  while ( v1168 < 18.0 );*/
                  break;
                case 3:/*
                  v1167 = 0.0;
                  do
                  {
                    *(float *)&v1205 = scene_rand_rng(360);
                    v1206 = scene_rand_rng(10) + 1.0;
                    v1207 = 5.0;
                    v987 = y + 100.0;
                    addbullet(this, NULL, 902, x, v987, dir, 1, (int)&v1205, 3);
                    v1167 = v1167 + 1.0;
                  }
                  while ( v1167 < 25.0 );*/
                  break;
              }
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL, 902, x, y + 100.0, dir, 1, t, 3);
              addbullet(this, NULL, 902, x, y + 100.0, dir, 1, t, 3);
              addbullet(this, NULL, 902, x, y + 100.0, dir, 1, t, 3);
              t[2] = 4.0;
              addbullet(this, NULL, 902, x, y + 100.0, dir, 1, t, 3);
              t[2] = 3.0;
              /*
              v1170 = 0.0;
              do
              {
                *(float *)&v1205 = scene_rand_rng(360);
                v1206 = scene_rand_rng(22) + 8.0;
                v994 = y + 100.0;
                addbullet(this, NULL, 902, x, v994, dir, 1, (int)&v1205, 3);
                v1170 = v1170 + 1.0;
              }
              while ( v1170 < 8.0 );*/
              set_subseq(4);
            }
            return;
          case 731:
            if ( get_subseq() != 1 && get_subseq() != 2 )
              goto LABEL_2576;
            if ( get_elaps_frames() <= 60 )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  goto LABEL_2570;
                case 1:
                  if ( !(get_elaps_frames() % 6) )
                  {
                    play_sfx(58);
                    t[0] = scene_rand_rng(360);
                    t[1] = scene_rand_rng(60) * 0.1000000014901161 + 4.0;
                    t[2] = 0.0;
                    addbullet(this, NULL, 902, (double)(30 * (char)dir) + x, y + 90.0, dir, 1, t, 3);
                  }
LABEL_2570:
                  if ( get_elaps_frames() % 10 )
                    break;
                  play_sfx(58);
                  t[0] = scene_rand_rng(360);
                  t[1] = scene_rand_rng(40) * 0.1000000014901161 + 4.0;
                  t[2] = 0.0;
                  goto LABEL_2572;
                case 2:
                  //v1003 = get_elaps_frames() & 0x80000003;
                  //v1002 = v1003 == 0;
                  //if ( v1003 < 0 )
                  //  v1002 = (((_BYTE)v1003 - 1) | 0xFFFFFFFC) == -1;
                  //if ( !v1002 )
                  //  break;
                  play_sfx(58);
                  t[0] = scene_rand_rng(360);
                  t[1] = scene_rand_rng(80) * 0.1000000014901161 + 4.0;
                  t[2] = 0.0;
                  goto LABEL_2572;
                case 3:
                  if ( !(get_elaps_frames() % 3) )
                  {
                    play_sfx(58);
                    t[0] = scene_rand_rng(360);
                    t[1] = scene_rand_rng(100) * 0.1000000014901161 + 4.0;
                    t[2] = 0.0;
LABEL_2572:
                    addbullet(this, NULL, 902, (double)(30 * (char)dir) + x, y + 90.0, dir, 1, t, 3);
                  }
                  break;
                default:
                  break;
              }
            }
            if ( get_elaps_frames() < 50 )
              goto LABEL_2576;
            if ( true/*color_A < 0xAu*/ )
            {
LABEL_2579:
              set_subseq(3);
              //color_A = -1;
              reset_forces();
            }
            else
            {
              //color_A = color_A - 10;
LABEL_2576:
              if ( get_subseq() != 3 )
                goto LABEL_2748;
              if ( get_elaps_frames() == 45 )
              {
                x = enemy->x;
                y = enemy->y;
                play_sfx(59);
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                  /*
                    v1174 = 0.0;
                    do
                    {
                      a1 = scene_rand_rng(360);
                      v1191 = scene_rand_rng(12) + 18.0;
                      v1192 = 1.0;
                      v1041 = dir;
                      v1042 = 180.0 - a1;
                      v1043 = sin_deg(v1042);
                      v1044 = v1043 * (v1191 * 60.0) + y + 100.0;
                      v1045 = v1044;
                      v1046 = 180.0 - a1;
                      v1047 = cos_deg(v1046);
                      v1048 = v1047 * (v1191 * 60.0) * (double)dir + x;
                      addbullet(this, NULL, 902, v1048, v1045, v1041, 1, (int)&a1, 3);
                      v1174 = v1174 + 1.0;
                    }
                    while ( v1174 < 10.0 );*/
                    break;
                  case 1:/*
                    v1173 = 0.0;
                    do
                    {
                      a1 = scene_rand_rng(360);
                      v1191 = scene_rand_rng(12) + 18.0;
                      v1192 = 1.0;
                      v1033 = dir;
                      v1034 = 180.0 - a1;
                      v1035 = sin_deg(v1034);
                      v1036 = v1035 * (v1191 * 60.0) + y + 100.0;
                      v1037 = v1036;
                      v1038 = 180.0 - a1;
                      v1039 = cos_deg(v1038);
                      v1040 = v1039 * (v1191 * 60.0) * (double)dir + x;
                      addbullet(this, NULL, 902, v1040, v1037, v1033, 1, (int)&a1, 3);
                      v1173 = v1173 + 1.0;
                    }
                    while ( v1173 < 10.0 );*/
                    break;
                  case 2:/*
                    v1172 = 0.0;
                    do
                    {
                      a1 = scene_rand_rng(360);
                      v1191 = scene_rand_rng(12) + 18.0;
                      v1192 = 1.0;
                      v1025 = dir;
                      v1026 = 180.0 - a1;
                      v1027 = sin_deg(v1026);
                      v1028 = v1027 * (v1191 * 60.0) + y + 100.0;
                      v1029 = v1028;
                      v1030 = 180.0 - a1;
                      v1031 = cos_deg(v1030);
                      v1032 = v1031 * (v1191 * 60.0) * (double)dir + x;
                      addbullet(this, NULL, 902, v1032, v1029, v1025, 1, (int)&a1, 3);
                      v1172 = v1172 + 1.0;
                    }
                    while ( v1172 < 15.0 );*/
                    break;
                  case 3:/*
                    v1171 = 0.0;
                    do
                    {
                      a1 = scene_rand_rng(360);
                      v1191 = scene_rand_rng(12) + 18.0;
                      v1192 = 1.0;
                      v1017 = dir;
                      v1018 = 180.0 - a1;
                      v1019 = sin_deg(v1018);
                      v1020 = v1019 * (v1191 * 60.0) + y + 100.0;
                      v1021 = v1020;
                      v1022 = 180.0 - a1;
                      v1023 = cos_deg(v1022);
                      v1024 = v1023 * (v1191 * 60.0) * (double)dir + x;
                      addbullet(this, NULL, 902, v1024, v1021, v1017, 1, (int)&a1, 3);
                      v1171 = v1171 + 1.0;
                    }
                    while ( v1171 < 20.0 );*/
                    break;
                  default:
                    break;
                }
              }
              if ( get_elaps_frames() != 85 )
              {
LABEL_2748:
                if ( process() )
                {
                  if ( char_on_ground_down() == 0 )
                  {
                    set_seq(704);
                    v_force = 0.30000001;
                  }
                  else
                  {
                    set_seq(700);
                  }
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  h_inerc = 20.0;
                  v_inerc = 12.0;
                }
              }
              else
              {
                play_sfx(60);
                switch ( settings_get()->get_difficulty() )
                {
                  case 1:/*
                    v1177 = 0.0;
                    do
                    {
                      *(float *)&v1202 = scene_rand_rng(360);
                      v1203 = scene_rand_rng(10) + 2.0;
                      v1204 = 5.0;
                      v1051 = y + 100.0;
                      addbullet(this, NULL, 902, x, v1051, dir, 1, (int)&v1202, 3);
                      v1177 = v1177 + 1.0;
                    }
                    while ( v1177 < 12.0 );*/
                    break;
                  case 2:/*
                    v1176 = 0.0;
                    do
                    {
                      *(float *)&v1202 = scene_rand_rng(360);
                      v1203 = scene_rand_rng(10) + 2.0;
                      v1204 = 5.0;
                      v1050 = y + 100.0;
                      addbullet(this, NULL, 902, x, v1050, dir, 1, (int)&v1202, 3);
                      v1176 = v1176 + 1.0;
                    }
                    while ( v1176 < 18.0 );*/
                    break;
                  case 3:/*
                    v1175 = 0.0;
                    do
                    {
                      *(float *)&v1202 = scene_rand_rng(360);
                      v1203 = scene_rand_rng(10) + 1.0;
                      v1204 = 5.0;
                      v1049 = y + 100.0;
                      addbullet(this, NULL, 902, x, v1049, dir, 1, (int)&v1202, 3);
                      v1175 = v1175 + 1.0;
                    }
                    while ( v1175 < 25.0 );*/
                    break;
                }
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 2.0;
                addbullet(this, NULL, 902, x, y + 100.0, dir, 1, t, 3);
                addbullet(this, NULL, 902, x, y + 100.0, dir, 1, t, 3);
                addbullet(this, NULL, 902, x, y + 100.0, dir, 1, t, 3);
                t[2] = 4.0;
                addbullet(this, NULL, 902, x, y + 100.0, dir, 1, t, 3);
                t[2] = 3.0;
                /*
                v1178 = 0.0;
                do
                {
                  *(float *)&v1202 = scene_rand_rng(360);
                  v1203 = scene_rand_rng(22) + 8.0;
                  v1056 = y + 100.0;
                  addbullet(this, NULL, 902, x, v1056, dir, 1, (int)&v1202, 3);
                  v1178 = v1178 + 1.0;
                }
                while ( v1178 < 8.0 );*/
                set_subseq(4);
              }
            }
            return;
          case 740:
            if ( get_subseq() >= 1 && get_subseq() <= 3 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_2631;
            }
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              next_subseq();
            if ( process() )
            {
              set_seq(741);
              dir = -1;
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            h_inerc = (640.0 - x) / 30.0 * (double)dir;
            v_inerc = 15.0;
            v_force = 1.0;
            sub_4685C0(-1);
            field_6F5 = 1;
            goto LABEL_2705;
          case 741:
            if ( get_subseq() >= 1 && get_subseq() <= 3 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
            {
LABEL_2631:
              move_val = 4;
LABEL_2632:
              set_subseq(move_val);
LABEL_2633:
              y = getlvl_height();
              reset_forces();
            }
            else
            {
              if ( get_subseq() == 1 || get_subseq() == 2 )
              {
                v_inerc = v_inerc - v_force;
                if ( v_inerc < 0.0 )
                  v_inerc = 0.0;
                h_inerc = (640.0 - x) / 20.0 * (double)dir;
              }
              if ( get_subseq() == 2 )
              {
                if ( !field_7D0 )
                {
                  switch ( settings_get()->get_difficulty() )
                  {
                    case 0:
                    case 1:
                    case 2:
                    case 3:
                      if ( field_7D2 < 60 )
                        field_7D2 = field_7D2 + 1;
                      else
                        field_7D0 = 1;
                      break;
                    default:
                      break;
                  }
                }
                if ( field_7D0 == 1 )
                {
                  if ( !field_7D2 )
                  {
                    play_sfx(61);
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 7.0;
                    addbullet(this, NULL, 903, x, y + 230.0, dir, 1, t, 3);
                  }
                  if ( !(get_elaps_frames() % 6) )
                  {
                    t[0] = scene_rand_rng(360);
                    t[1] = scene_rand_rng(600) + 100.0;
                    t[2] = 5.0;
                    addbullet(this, NULL, 903, cos_deg(-t[0]) * t[1] * (double)dir + x, sin_deg(-t[0]) * t[1] + y + 230.0, dir, 1, t, 3);
                  }
                  switch ( settings_get()->get_difficulty() )
                  {
                    case 0:
                      if ( !field_7D2 )
                      {
                        /*
                        v1189 = scene_rand_rng(360);
                        v1083 = 0.0;
                        v1182 = 0.0;
                        v1084 = (float)0.0;
                        while ( 1 )
                        {
                          *(float *)&v1196 = v1084 * 60.0 + v1189;
                          v1197 = v1083;
                          v1198 = v1083;
                          v1085 = y + 230.0;
                          addbullet(this, NULL, 903, x, v1085, dir, 1, (int)&v1196, 3);
                          v1182 = v1182 + 1.0;
                          if ( v1182 >= 6.0 )
                            break;
                          v1084 = v1182;
                          v1083 = 0.0;
                        }*/
                      }
                      goto LABEL_2655;
                    case 1:
                      if ( !field_7D2 )
                      {/*
                        v1188 = scene_rand_rng(360);
                        v1080 = 0.0;
                        v1181 = 0.0;
                        v1081 = (float)0.0;
                        while ( 1 )
                        {
                          *(float *)&v1196 = v1081 * 45.0 + v1188;
                          v1197 = v1080;
                          v1198 = v1080;
                          v1082 = y + 230.0;
                          addbullet(this, NULL, 903, x, v1082, dir, 1, (int)&v1196, 3);
                          v1181 = v1181 + 1.0;
                          if ( v1181 >= 8.0 )
                            break;
                          v1081 = v1181;
                          v1080 = 0.0;
                        }*/
                      }
                      goto LABEL_2655;
                    case 2:
                      if ( !field_7D2 )
                      {/*
                        v1187 = scene_rand_rng(360);
                        v1076 = 0.0;
                        v1180 = 0.0;
                        v1077 = (float)0.0;
                        while ( 1 )
                        {
                          *(float *)&v1196 = v1077 * 36.0 + v1187;
                          v1197 = v1076;
                          v1198 = v1076;
                          v1078 = y + 230.0;
                          addbullet(this, NULL, 903, x, v1078, dir, 1, (int)&v1196, 3);
                          v1180 = v1180 + 1.0;
                          if ( v1180 >= 10.0 )
                            break;
                          v1077 = v1180;
                          v1076 = 0.0;
                        }*/
                      }
                      if ( field_7D2 < 90 )
                      {
                        field_7D2 = field_7D2 + 1;
                      }
                      else
                      {
                        field_7D2 = 0;
                        field_7D0 = 2;
                      }
                      break;
                    case 3:
                      if ( !field_7D2 )
                      {
                        /*
                        v1121 = scene_rand_rng(360);
                        v1072 = 0.0;
                        v1179 = 0.0;
                        v1073 = (float)0.0;
                        while ( 1 )
                        {
                          *(float *)&v1196 = v1073 * 30.0 + v1121;
                          v1197 = v1072;
                          v1198 = v1072;
                          v1074 = y + 230.0;
                          addbullet(this, NULL, 903, x, v1074, dir, 1, (int)&v1196, 3);
                          v1179 = v1179 + 1.0;
                          if ( v1179 >= 12.0 )
                            break;
                          v1073 = v1179;
                          v1072 = 0.0;
                        }*/
                      }
LABEL_2655:
                      if ( field_7D2 < 90 )
                      {
                        field_7D2 = field_7D2 + 1;
                      }
                      else
                      {
                        field_7D2 = 0;
                        field_7D0 = 2;
                      }
                      break;
                    default:
                      break;
                  }
                }
                if ( field_7D0 == 2 )
                {
                  if ( !field_7D2 )
                  {
                    //shake_camera(10.0);
                    play_sfx(62);
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 6.0;
                    addbullet(this, NULL, 903, x, y + 230.0, dir, 1, t, 3);
                    addbullet(this, NULL, 903, x, y + 230.0, dir, 1, t, 3);
                    addbullet(this, NULL, 903, x, y + 230.0, dir, 1, t, 3);
                    switch ( settings_get()->get_difficulty() )
                    {
                      case 0:/*
                        v1186 = 0.0;
                        do
                        {
                          *(float *)&v1218 = scene_rand_rng(360);
                          v1219 = scene_rand_rng(40) * 0.1000000014901161 + 3.0;
                          v1220 = 3.0;
                          v1092 = y + 230.0;
                          addbullet(this, NULL, 903, x, v1092, dir, 1, (int)&v1218, 3);
                          v1186 = v1186 + 1.0;
                        }
                        while ( v1186 < 8.0 );*/
                        break;
                      case 1:/*
                        v1185 = 0.0;
                        do
                        {
                          *(float *)&v1218 = scene_rand_rng(360);
                          v1219 = scene_rand_rng(40) * 0.1000000014901161 + 3.0;
                          v1220 = 3.0;
                          v1091 = y + 230.0;
                          addbullet(this, NULL, 903, x, v1091, dir, 1, (int)&v1218, 3);
                          v1185 = v1185 + 1.0;
                        }
                        while ( v1185 < 12.0 );*/
                        break;
                      case 2:/*
                        v1184 = 0.0;
                        do
                        {
                          *(float *)&v1218 = scene_rand_rng(360);
                          v1219 = scene_rand_rng(40) * 0.1000000014901161 + 3.0;
                          v1220 = 3.0;
                          v1090 = y + 230.0;
                          addbullet(this, NULL, 903, x, v1090, dir, 1, (int)&v1218, 3);
                          v1184 = v1184 + 1.0;
                        }
                        while ( v1184 < 20.0 );*/
                        break;
                      case 3:/*
                        v1183 = 0.0;
                        do
                        {
                          *(float *)&v1218 = scene_rand_rng(360);
                          v1219 = scene_rand_rng(40) * 0.1000000014901161 + 2.0;
                          v1220 = 3.0;
                          v1089 = y + 230.0;
                          addbullet(this, NULL, 903, x, v1089, dir, 1, (int)&v1218, 3);
                          v1183 = v1183 + 1.0;
                        }
                        while ( v1183 < 30.0 );*/
                        break;
                      default:
                        break;
                    }
                  }
                  if ( field_7D2 < 30 )
                  {
                    field_7D2 = field_7D2 + 1;
                  }
                  else
                  {
                    field_7D2 = 0;
                    field_7D0 = 0;
                  }
                }
              }
              if ( process() )
              {
                set_seq(741);
                flip_with_force();
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                h_inerc = 0.0;
                v_inerc = 15.0;
                v_force = 0.30000001;
              }
            }
            return;
          case 770:
            if ( process() )
              set_seq(700);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
            {
              field_6F5 = 1;
              sub_4685C0(-1);
LABEL_2705:
              sub_46AB50(2, -1);
              health_to_max();
              field_81E = 1;
              field_81A = 0;
              field_81C = 0;
              field_818 = 0;
              scene_play_sfx(23);
            }
            return;
          default:
            goto LABEL_2712;
        }
      }
      if ( !get_subseq() )
      {
        v_inerc = v_inerc - 0.300000011920929;
        if ( char_on_ground_down() )
        {
          scene_play_sfx(30);
          set_subseq(1);
LABEL_2709:
          y = getlvl_height();
          reset_forces();
          return;
        }
      }
LABEL_2723:
      if ( process() )
LABEL_2724:
        set_seq(700);
      return;
    }
    if ( (get_seq() - 797) )
    {
      if ( (get_seq() - 797) != 1 )
      {
LABEL_2712:
        char_c::func10();
        return;
      }
      if ( get_subseq() > 2 || (v_inerc = v_inerc - v_force, !char_on_ground_down()) )
      {
        if ( get_subseq() == 3 )
        {
          h_inerc = h_inerc - 0.75;
          if ( h_inerc < 0.0 ) //condition reversed
          {
            h_inerc = 0.0;
            x = 800.0;
          }
          if ( x < 800.0 )
            x = 800.0;
        }
        goto LABEL_2723;
      }
    }
    else if ( get_subseq() > 2 || (v_inerc = v_inerc - v_force, !char_on_ground_down()) )
    {
      if ( get_subseq() == 3 )
      {
        h_inerc = h_inerc - 0.75;
        if ( h_inerc < 0.0 ) //condition reversed
        {
          h_inerc = 0.0;
          x = 480.0;
        }
        if ( x > 480.0 )
          x = 480.0;
      }
LABEL_2733:
      if ( !process() )
        return;
LABEL_2734:
      set_seq(0);
      return;
    }
    scene_play_sfx(30);
    set_subseq(3);
LABEL_2716:
    y = getlvl_height();
    v_inerc = 0.0;
    return;
  }
  if ( get_seq() == 520 )
  {
    sub10func();
    field_18C = 1;
    if ( !keyDown(INP_B) )
      not_charge_attack = 0;
    if ( process() )
      set_seq(0);
    if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
    {
      if ( !get_subseq() && !get_frame_time() )
      {
        if ( get_frame() == 3 && not_charge_attack )
        {
          y = y + 107.0;
          v196 = x;
LABEL_1607:
          scene_add_effect(this, 62, v196, y, dir, 1);
          next_subseq();
          return;
        }
        if ( get_frame() == 5 )
        {
          play_sfx(11);
          field_190 = 1;
          spell_energy_spend(200, 120);
          add_card_energy(50);
          /*switch ( (_BYTE)v1 )
          {
            case 0:
              v441 = 3.0;
              goto LABEL_1412;
            case 1:
            case 2:
            case 3:
              v441 = 4.0;
              goto LABEL_1412;
            case 4:
              v441 = 5.0;
LABEL_1412:
              dash_angle = v441;
              break;
            default:
              break;
          }
          v1145 = 0.0;
          if ( dash_angle > 0.0 )
          {
            v442 = v1145;
            do
            {
              *(float *)&v1248 = 360.0 * v442 / dash_angle;
              v1249 = 7.0;
              v1250 = 0.0;
              v1251 = v442 * 5.0 + 60.0;
              v443 = dir;
              v444 = y + 102.0;
              v445 = v444;
              v446 = (double)(40 * (char)v443) + x;
              addbullet(this, NULL, 815, v446, v445, v443, 1, (int)&v1248, 4);
              v1145 = v1145 + 1.0;
              v442 = v1145;
            }
            while ( dash_angle > (double)v1145 );
          }*/
          t[2] = 2.0;
          addbullet(this, NULL, 815, (double)(40 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
          t[2] = 3.0;
          addbullet(this, NULL, 815, (double)(40 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
        }
      }
      if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
      {
        play_sfx(11);
        field_190 = 1;
        spell_energy_spend(200, 120);
        add_card_energy(50);
        /*switch ( (_BYTE)v1 )
        {
          case 0:
            v455 = 5.0;
            goto LABEL_1424;
          case 1:
          case 2:
          case 3:
            v455 = 6.0;
            goto LABEL_1424;
          case 4:
            v455 = 7.0;
LABEL_1424:
            dash_angle = v455;
            break;
          default:
            break;
        }
        v1146 = 0.0;
        if ( dash_angle > 0.0 )
        {
          v456 = v1146;
          do
          {
            *(float *)&v1252 = 360.0 * v456 / dash_angle;
            v1253 = 7.0;
            v1254 = 0.0;
            v1255 = v456 * 5.0 + 60.0;
            v457 = dir;
            v458 = y + 102.0;
            v459 = v458;
            v460 = (double)(40 * (char)v457) + x;
            addbullet(this, NULL, 815, v460, v459, v457, 1, (int)&v1252, 4);
            v1146 = v1146 + 1.0;
            v456 = v1146;
          }
          while ( dash_angle > (double)v1146 );
        }*/
        t[2] = 2.0;
        addbullet(this, NULL, 815, (double)(40 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
        t[2] = 3.0;
        addbullet(this, NULL, 815, (double)(40 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
      }
      return;
    }
    goto LABEL_2734;
  }
  switch ( get_seq() )
  {
    case 301:
      sub10func();
      if ( false /*get_true(0)*/ )
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
      if ( get_frame() > 4 )
      {
        h_inerc = h_inerc - 4.0;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
      }
      if ( process() )
        set_seq(0);
      if ( get_frame_time() )
        return;
      if ( get_frame() == 3 )
        h_inerc = 20.0;
      if ( get_frame_time() || get_frame() != 4 )
        return;
      h_inerc = 5.0;
      goto LABEL_581;
    case 302:
      sub10func();
      if ( false /*get_true(1)*/ )
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
      if ( !keyDown(INP_A) )
        not_charge_attack = 0;
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        goto LABEL_363;
      //if ( get_subseq() )
      //  goto LABEL_607;
      if ( get_frame_time() || get_frame() != 5 )
        goto LABEL_600;
      if ( not_charge_attack == 1 )
      {
        next_subseq();
        scene_add_effect(this, 62, x - (double)(28 * (char)dir), y + 160.0, dir, 1);
        return;
      }
      h_inerc = 15.0;
      t[0] = 0.0;
      t[1] = 0.0;
      t[2] = 0.0;
      addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
LABEL_600:
      //if ( get_frame_time() )
      //  goto LABEL_603;
      //v174 = __OFSUB__(get_frame(), 6);
      //v173 = (signed __int16)(get_frame() - 6) < 0;
      if ( get_frame() == 6 )
      {
        h_inerc = 10.0;
        scene_play_sfx(27);
        field_49A = 0;
//LABEL_603:
      //  v174 = __OFSUB__(get_frame(), 6);
      //  v173 = (signed __int16)(get_frame() - 6) < 0;
      }
      /*if ( v173 ^ v174 )
      {
LABEL_607:
        v176 = 0.0;
      }
      else
      {
        v175 = h_inerc - 2.0;
        h_inerc = v175;
        v176 = 0.0;
        if ( v175 < 0.0 )
          h_inerc = 0.0;
      }*/
      if ( get_subseq() != 1 )
        return;
      //if ( get_frame_time() )
      //  goto LABEL_615;
      if ( get_frame() == 1 )
      {
        h_inerc = 15.0;
        t[0] = 0.0;
        t[1] = 0.0;
        t[2] = 0.0;
        addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
      }
      //if ( get_frame_time() )
      //  goto LABEL_615;
      //v178 = __OFSUB__(get_frame(), 3);
      //v177 = (signed __int16)(get_frame() - 3) < 0;
      if ( get_frame() == 3 )
      {
        h_inerc = 10.0;
        scene_play_sfx(27);
        field_49A = 0;
//LABEL_615:
      //  v178 = __OFSUB__(get_frame(), 3);
      //  v177 = (signed __int16)(get_frame() - 3) < 0;
      }
      /*if ( !(v177 ^ v178) )
      {
        v179 = h_inerc - 2.0;
        h_inerc = v179;
        if ( v179 < 0.0 )
          h_inerc = 0.0;
      }*/
      return;
    case 303:
      sub10func();
      if (  true /*!get_true(0)*/ )
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
        {
          scene_play_sfx(28);
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 3.0;
          addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
        }
      }
      return;
    case 304:
      sub10func();
      if (  true /*!get_true(1)*/ )
      {
        if ( h_inerc > 0.0 )
          h_inerc = h_inerc - 0.8999999761581421;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
        if ( process() )
          set_seq(2);
        if ( !get_frame_time() && get_frame() == 4 )
        {
          h_inerc = 25.0;
          scene_play_sfx(29);
        }
      }
      return;
    case 306:
      v_inerc = v_inerc - v_force;
      if ( char_on_ground_down() )
      {
LABEL_639:
        set_seq(10);
        goto LABEL_2633;
      }
      if ( process() )
        set_seq(9);
      if ( !get_frame_time() && get_frame() == 3 )
        scene_play_sfx(28);
      return;
    case 307:
      if ( !keyDown(INP_A) )
        not_charge_attack = 0;
      if ( get_subseq() >= 2 || !get_subseq() && get_frame() >= 6 )
      {
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
        {
          move_val = 10;
          goto LABEL_2632;
        }
      }
      if ( get_subseq() )
        goto LABEL_659;
      if ( field_190 == 7 || field_190 == 2 )
      {
        set_subseq(2);
        v185 = -10.0;
        goto LABEL_1880;
      }
      if ( get_frame() <= 5 && char_on_ground_down() )
      {
        next_subseq();
        goto LABEL_782;
      }
LABEL_659:
      if ( get_subseq() == 1 )
      {
        sub10func();
        h_inerc = h_inerc - 2.5;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
      }
      if ( process() )
        set_seq(9);
      if ( get_elaps_frames() )
        goto LABEL_672;
      if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        goto LABEL_2089;
      if ( get_frame_time() || get_frame() || get_subseq() != 2 )
      {
LABEL_672:
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 3 )
          {
            h_inerc = 30.0;
            v_inerc = -10.0;
            v_force = 0.60000002;
            scene_play_sfx(29);
          }
          if ( !get_frame_time() && get_frame() == 5 )
          {
            h_inerc = 4.0;
            v_inerc = -2.5;
          }
        }
        if ( get_subseq() == 1 && get_frame() == 1 && field_190 && get_frame_time() >= 7 )
          next_frame();
      }
      else
      {
        set_seq(0);
        reset_forces();
      }
      return;
    case 308:
      if ( get_subseq() || (v_inerc = v_inerc - v_force, !char_on_ground_down()) )
      {
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(9);
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 2 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 4.0;
            addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
          }
          if ( !get_frame_time() && get_frame() == 3 )
            scene_play_sfx(29);
        }
      }
      else
      {
        next_subseq();
        y = getlvl_height();
        reset_forces();
      }
      return;
    case 309:
      if ( get_subseq() || (v_inerc = v_inerc - v_force, !char_on_ground_down()) )
      {
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(9);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
        {
          scene_play_sfx(29);
          h_inerc = 5.0;
          v_inerc = 20.0;
          v_force = 1.5;
        }
      }
      else
      {
        next_subseq();
        y = getlvl_height();
        reset_forces();
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
      if ( get_subseq() == 2 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
      {
        v_inerc = 0.0;
        y = getlvl_height();
        set_seq(9);
      }
      else if ( process() )
      {
        set_seq(9);
      }
      return;
    case 320:
      sub10func();
      if (  true /*!get_true(0)*/ )
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
    case 321:
      sub10func();
      if (  true /*!get_true(0)*/ )
      {
        if ( get_frame() > 3 )
        {
          h_inerc = h_inerc - 1.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( process() )
          set_seq(0);
        if ( !get_frame_time() )
        {
          if ( get_frame() == 2 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 1.0;
            addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
          }
          if ( !get_frame_time() )
          {
            if ( get_frame() == 3 )
            {
              scene_play_sfx(28);
              field_49A = 0;
            }
            if ( !get_frame_time() && get_frame() == 7 )
            {
              scene_play_sfx(28);
              field_190 = 0;
              h_inerc = 10.0;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            }
          }
        }
      }
      return;
    case 322:
      sub10func();
      if ( false /*get_true(1)*/ )
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
      if ( !keyDown(INP_A) )
        not_charge_attack = 0;
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        goto LABEL_363;
      if ( get_subseq() )
        return;
      if ( !get_frame_time() && get_frame() == 5 )
      {
        h_inerc = 15.0;
        t[0] = 0.0;
        t[1] = 0.0;
        t[2] = 0.0;
        addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
      }
      //if ( get_frame_time() )
      //  goto LABEL_777;
      //v191 = __OFSUB__(get_frame(), 6);
      //v190 = (signed __int16)(get_frame() - 6) < 0;
      if ( get_frame() == 6 )
      {
        h_inerc = 10.0;
        scene_play_sfx(27);
        field_49A = 0;
//LABEL_777:
      //  v191 = __OFSUB__(get_frame(), 6);
      //  v190 = (signed __int16)(get_frame() - 6) < 0;
      }
      /*
      if ( v190 ^ v191 )
        return;
      v192 = h_inerc - 2.0;
      v193 = v192;
      goto LABEL_2296;
      */
      return; //TODO: change
    case 325:
      v_inerc = v_inerc - v_force;
      if ( char_on_ground_down() )
      {
        set_seq(10);
LABEL_782:
        y = getlvl_height();
        v_force = 0.0;
        v_inerc = 0.0;
      }
      else
      {
        if ( process() )
          set_seq(9);
        if ( !get_frame_time() && get_frame() == 1 )
          scene_play_sfx(29);
      }
      return;
    case 330:
      goto LABEL_557;
    case 400:
      sub10func();
      if ( !keyDown(INP_B) )
        not_charge_attack = 0;
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        goto LABEL_2734;
      if ( get_subseq() || get_frame_time() )
        goto LABEL_808;
      if ( get_frame() == 2 && not_charge_attack == 1 )
      {
        y =  y + 96.0;
        v196 = x - (double)(22 * (char)dir);
        goto LABEL_1607;
      }
      if ( get_frame() == 5 )
      {
        field_190 = 1;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -5.0 )
          field_7E4 = -5.0;
        if ( field_7E4 > 5.0 )
          field_7E4 = 5.0;
        spell_energy_spend(200, 45);
        add_card_energy(30);
        play_sfx(0);
        /*
        v1123 = 0.0;
        do
        {
          *(float *)&v1537 = scene_rand_rng(20) + field_7E4 - 10.0;
          v1538 = v1123 + 15.0;
          v1539 = 0.0;
          v202 = dir;
          v203 = y + 108.0;
          v204 = v203;
          v205 = (double)(70 * (char)v202) + x;
          addbullet(this, NULL, 800, v205, v204, v202, 1, (int)&v1537, 3);
          v1123 = v1123 + 1.0;
        }
        while ( v1123 < 6.0 );*/
      }
LABEL_808:
      if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 4 )
      {
        field_190 = 1;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -5.0 )
          field_7E4 = -5.0;
        if ( field_7E4 > 5.0 )
          field_7E4 = 5.0;
        spell_energy_spend(200, 45);
        add_card_energy(30);
        play_sfx(0);
        /*
        v211 = 0;
        v1124 = 0;
        do
        {
          *(float *)&v1543 = scene_rand_rng(20) + field_7E4 - 10.0;
          v1544 = (double)v1124 + 25.0;
          v1545 = 0.0;
          v212 = dir;
          v213 = y + 108.0;
          v214 = v213;
          v215 = (double)(70 * (char)v212) + x;
          addbullet(this, NULL, 800, v215, v214, v212, 1, (int)&v1543, 3);
          v1124 = ++v211;
        }
        while ( v211 < 10 );*/
      }
      return;
    case 401:
      sub10func();
      if ( !keyDown(INP_B) )
        not_charge_attack = 0;
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        goto LABEL_363;
      if ( get_subseq() || get_frame_time() )
        goto LABEL_838;
      if ( get_frame() == 2 && not_charge_attack == 1 )
      {
        y = y + 96.0;
        v196 = x - (double)(22 * (char)dir);
        goto LABEL_1607;
      }
      if ( get_frame() == 5 )
      {
        field_190 = 1;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -65.0 )
          field_7E4 = -65.0;
        if ( field_7E4 > -25.0 )
          field_7E4 = -25.0;
        spell_energy_spend(200, 45);
        add_card_energy(30);
        play_sfx(0);
        /*
        v223 = 0;
        v1125 = 0;
        do
        {
          *(float *)&v1549 = scene_rand_rng(20) + field_7E4 - 10.0;
          v1550 = (double)v1125 + 15.0;
          v1551 = 0.0;
          v224 = dir;
          v225 = y + 162.0;
          v226 = v225;
          v227 = (double)(60 * (char)v224) + x;
          addbullet(this, NULL, 800, v227, v226, v224, 1, (int)&v1549, 3);
          v1125 = ++v223;
        }
        while ( v223 < 6 );*/
      }
LABEL_838:
      if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 4 )
      {
        field_190 = 1;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -65.0 )
          field_7E4 = -65.0;
        if ( field_7E4 > -25.0 )
          field_7E4 = -25.0;
        spell_energy_spend(200, 45);
        add_card_energy(30);
        play_sfx(0);
        /*
        v233 = 0;
        v1126 = 0;
        do
        {
          *(float *)&v1555 = scene_rand_rng(20) + field_7E4 - 10.0;
          v1556 = (double)v1126 + 25.0;
          v1557 = 0.0;
          v234 = dir;
          v235 = y + 162.0;
          v236 = v235;
          v237 = (double)(60 * (char)v234) + x;
          addbullet(this, NULL, 800, v237, v236, v234, 1, (int)&v1555, 3);
          v1126 = ++v233;
        }
        while ( v233 < 10 );*/
      }
      return;
    case 402:
      sub10func();
      if ( process() )
        set_seq(2);
      if ( !get_frame_time() && get_frame() == 4 )
      {
        field_190 = 1;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -55.0 )
          field_7E4 = -55.0;
        if ( field_7E4 > -45.0 )
          field_7E4 = -45.0;
        spell_energy_spend(200, 45);
        add_card_energy(30);
        play_sfx(0);
        /*
        v243 = 0;
        v1127 = 0;
        do
        {
          *(float *)&v1348 = scene_rand_rng(30) + field_7E4 - 15.0;
          v1349 = (double)v1127 + 10.0;
          v1350 = 0.0;
          v244 = dir;
          v245 = y + 135.0;
          v246 = v245;
          v247 = (double)(30 * (char)v244) + x;
          addbullet(this, NULL, 800, v247, v246, v244, 1, (int)&v1348, 3);
          v1127 = ++v243;
        }
        while ( v243 < 8 );*/
      }
      return;
    case 404:
      if ( get_subseq() == 2 )
        sub10func();
      if ( !keyDown(INP_B) )
        not_charge_attack = 0;
      v_inerc = v_inerc - v_force;
      if ( char_on_ground_down() && get_subseq() < 2 )
        goto LABEL_902;
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
        goto LABEL_2089;
      if ( get_subseq() || get_frame_time() )
        goto LABEL_886;
      if ( get_frame() == 3 && not_charge_attack == 1 )
      {
        y = y + 96.0;
        v196 = x - (double)(22 * (char)dir);
        goto LABEL_1607;
      }
      if ( get_frame() == 4 )
      {
        field_190 = 1;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -5.0 )
          field_7E4 = -5.0;
        if ( field_7E4 > 5.0 )
          field_7E4 = 5.0;
        spell_energy_spend(200, 45);
        h_inerc = -4.0;
        v_inerc = 9.0;
        v_force = 0.64999998;
        add_card_energy(30);
        play_sfx(0);
        /*
        v255 = 0;
        v1128 = 0;
        do
        {
          *(float *)&v1504 = scene_rand_rng(20) + field_7E4 - 10.0;
          v1505 = (double)v1128 + 15.0;
          v1506 = 0.0;
          v256 = dir;
          v257 = y + 112.0;
          v258 = v257;
          v259 = (double)(43 * (char)v256) + x;
          addbullet(this, NULL, 800, v259, v258, v256, 1, (int)&v1504, 3);
          v1128 = ++v255;
        }
        while ( v255 < 6 );*/
      }
LABEL_886:
      if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
      {
        field_190 = 1;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -5.0 )
          field_7E4 = -5.0;
        if ( field_7E4 > 5.0 )
          field_7E4 = 5.0;
        spell_energy_spend(200, 45);
        h_inerc = -4.0;
        v_inerc = 9.0;
        v_force = 0.64999998;
        add_card_energy(30);
        play_sfx(0);
        /*
        v265 = 0;
        v1129 = 0;
        do
        {
          *(float *)&v1354 = scene_rand_rng(20) + field_7E4 - 10.0;
          v1355 = (double)v1129 + 25.0;
          v1356 = 0.0;
          v266 = dir;
          v267 = y + 112.0;
          v268 = v267;
          v269 = (double)(43 * (char)v266) + x;
          addbullet(this, NULL, 800, v269, v268, v266, 1, (int)&v1354, 3);
          v1129 = ++v265;
        }
        while ( v265 < 10 );*/
      }
      return;
    case 406:
      if ( get_subseq() == 2 )
        sub10func();
      if ( !keyDown(INP_B) )
        not_charge_attack = 0;
      v_inerc = v_inerc - v_force;
      if ( char_on_ground_down() && get_subseq() < 2 )
      {
LABEL_902:
        set_subseq(2);
        air_dash_cnt = 0;
        y = getlvl_height();
        reset_forces();
        return;
      }
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
        goto LABEL_2089;
      if ( get_subseq() || get_frame_time() )
        goto LABEL_924;
      if ( get_frame() == 3 && not_charge_attack == 1 )
      {
        y = y + 96.0;
        v196 = x - (double)(22 * (char)dir);
        goto LABEL_1607;
      }
      if ( get_frame() == 4 )
      {
        field_190 = 1;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < 35.0 )
          field_7E4 = 35.0;
        if ( field_7E4 > 45.0 )
          field_7E4 = 45.0;
        spell_energy_spend(200, 45);
        h_inerc = -4.0;
        v_inerc = 9.0;
        v_force = 0.64999998;
        add_card_energy(30);
        play_sfx(0);
        /*
        v277 = 0;
        v1130 = 0;
        do
        {
          *(float *)&v1456 = scene_rand_rng(20) + field_7E4 - 10.0;
          v1457 = (double)v1130 + 15.0;
          v1458 = 0.0;
          v278 = dir;
          v279 = y + 86.0;
          v280 = v279;
          v281 = (double)(37 * (char)v278) + x;
          addbullet(this, NULL, 800, v281, v280, v278, 1, (int)&v1456, 3);
          v1130 = ++v277;
        }
        while ( v277 < 6 );*/
      }
LABEL_924:
      if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
      {
        field_190 = 1;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < 35.0 )
          field_7E4 = 35.0;
        if ( field_7E4 > 45.0 )
          field_7E4 = 45.0;
        spell_energy_spend(200, 45);
        h_inerc = -4.0;
        v_inerc = 9.0;
        v_force = 0.64999998;
        add_card_energy(30);
        play_sfx(0);
        /*
        v287 = 0;
        v1131 = 0;
        do
        {
          *(float *)&v1360 = scene_rand_rng(20) + field_7E4 - 10.0;
          v1361 = (double)v1131 + 25.0;
          v1362 = 0.0;
          v288 = dir;
          v289 = y + 86.0;
          v290 = v289;
          v291 = (double)(37 * (char)v288) + x;
          addbullet(this, NULL, 800, v291, v290, v288, 1, (int)&v1360, 3);
          v1131 = ++v287;
        }
        while ( v287 < 10 );*/
      }
      return;
    case 408:
      sub10func();
      h_inerc = h_inerc - 0.5;
      if ( h_inerc < 0.0 )
        h_inerc = 0.0;
      if ( process() )
        set_seq(0);
      if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
      {
        t[0] = 0.0;
        addbullet(this, NULL, 825, (double)(106 * (char)dir) + x, y + 103.0, dir, 1, t, 3);
      }
      return;
    case 409:
      v_inerc = v_inerc - v_force;
      if ( char_on_ground_down() )
      {
        set_seq(10);
        reset_forces();
        y = getlvl_height();
      }
      else if ( process() )
      {
        set_seq(9);
      }
      return;
    case 410:
      sub10func();
      if ( !keyDown(INP_C) )
        not_charge_attack = 0;
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        goto LABEL_2734;
      if ( get_subseq() || get_frame_time() )
        goto LABEL_961;
      if ( get_frame() == 3 && not_charge_attack == 1 )
      {
        y = y + 107.0;
        v196 = (double)(5 * (char)dir) + x;
        goto LABEL_1607;
      }
      if ( get_frame() == 5 )
      {
        field_190 = 1;
        spell_energy_spend(200, 60);
        add_card_energy(50);
        t[0] = 0.0;
        t[1] = 12.0;
        t[2] = 0.0;
        addbullet(this, NULL, 801, (double)(36 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
        play_sfx(1);
      }
LABEL_961:
      if ( get_subseq() == 1 && !get_frame_time() )
      {
        if ( get_frame() == 3 )
        {
          field_190 = 1;
          spell_energy_spend(200, 60);
          add_card_energy(50);
          t[0] = 0.0;
          t[1] = 12.0;
          t[2] = 2.0;
          addbullet(this, NULL, 801, (double)(36 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
          play_sfx(1);
        }
        if ( !get_frame_time() )
        {
          if ( get_frame() == 5 )
          {
            t[0] = 20.0;
            t[1] = 12.0;
            t[2] = 2.0;
            addbullet(this, NULL, 801,  (double)(36 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
            play_sfx(1);
          }
          if ( !get_frame_time() && get_frame() == 7 )
          {
            t[0] = -20.0;
            t[1] = 12.0;
            t[2] = 2.0;
            addbullet(this, NULL, 801, (double)(36 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
            play_sfx(1);
          }
        }
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
      if ( get_subseq() || get_frame_time() || get_frame() != 7 || !not_charge_attack )
        return;
      y = y + 160.0;
      v196 = x - (double)(140 * (char)dir);
      goto LABEL_1607;
    case 412:
      sub10func();
      if ( process() )
        set_seq(0);
      if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
      {
        field_190 = 1;
        spell_energy_spend(200, 60);
        add_card_energy(50);
        t[0] = -70.0;
        t[1] = 12.0;
        t[2] = 0.0;
        addbullet(this, NULL, 801, (double)(83 * (char)dir) + x, y + 180.0, dir, 1, t, 3);
        play_sfx(1);
      }
      return;
    case 414:
      //v322 = __OFSUB__(get_subseq(), 2);
      //v321 = (signed __int16)(get_subseq() - 2) < 0;
      if ( get_subseq() == 2 )
      {
        sub10func();
        //v322 = __OFSUB__(get_subseq(), 2);
        //v321 = (signed __int16)(get_subseq() - 2) < 0;
      }
      /*if ( v321 ^ v322 )
      {
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_1071;
      }*/
      if ( get_subseq() < 2 && !keyDown(INP_C) )
        not_charge_attack = 0;
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
        goto LABEL_1129;
      if ( get_subseq() )
        goto LABEL_1017;
      if ( get_frame_time() )
        goto LABEL_1014;
      if ( get_frame() == 3 && not_charge_attack == 1 )
      {
        y = y + 107.0;
        v196 = (double)(5 * (char)dir) + x;
        goto LABEL_1607;
      }
      if ( get_frame() == 5 )
      {
        field_190 = 1;
        spell_energy_spend(200, 60);
        add_card_energy(50);
        t[0] = 0.0;
        t[1] = 12.0;
        t[2] = 0.0;
        addbullet(this, NULL, 801, (double)(36 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
        play_sfx(1);
      }
LABEL_1014:
      if ( !get_frame_time() && get_frame() == 12 )
        v_force = 0.5;
LABEL_1017:
      if ( get_subseq() != 1 || get_frame_time() )
        return;
      if ( get_frame() == 3 )
      {
        field_190 = 1;
        spell_energy_spend(200, 60);
        add_card_energy(50);
        t[0] = 0.0;
        t[1] = 12.0;
        t[2] = 2.0;
        addbullet(this, NULL, 801, (double)(36 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
        play_sfx(1);
      }
      if ( get_frame_time() )
        return;
      if ( get_frame() == 5 )
      {
        t[0] = 20.0;
        t[1] = 12.0;
        t[2] = 2.0;
        addbullet(this, NULL, 801, (double)(36 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
        play_sfx(1);
      }
      if ( get_frame_time() )
        return;
      if ( get_frame() != 7 )
        goto LABEL_1064;
      t[0] = -20.0;
      t[1] = 12.0;
      t[2] = 2.0;
      x = dir;
      goto LABEL_1063;
    case 415:
      //v341 = __OFSUB__(get_subseq(), 2);
      //v340 = (signed __int16)(get_subseq() - 2) < 0;
      if ( get_subseq() == 2 )
      {
        sub10func();
        //v341 = __OFSUB__(get_subseq(), 2);
        //v340 = (signed __int16)(get_subseq() - 2) < 0;
      }
      /*if ( v340 ^ v341 )
      {
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_1071;
      }*/
      if ( get_subseq() < 2 && !keyDown(INP_C) )
        not_charge_attack = 0;
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
        goto LABEL_1129;
      if ( get_subseq() )
        goto LABEL_1053;
      if ( get_frame_time() )
        goto LABEL_1050;
      if ( get_frame() == 3 && not_charge_attack == 1 )
      {
        y = y + 107.0;
        v196 = (double)(5 * (char)dir) + x;
        goto LABEL_1607;
      }
      if ( get_frame() == 5 )
      {
        field_190 = 1;
        spell_energy_spend(200, 60);
        add_card_energy(50);
        t[0] = 0.0;
        t[1] = 12.0;
        t[2] = 0.0;
        addbullet(this, NULL, 801, (double)(36 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
        play_sfx(1);
      }
LABEL_1050:
      if ( !get_frame_time() && get_frame() == 12 )
        v_force = 0.5;
LABEL_1053:
      if ( get_subseq() == 1 && !get_frame_time() )
      {
        if ( get_frame() == 3 )
        {
          field_190 = 1;
          spell_energy_spend(200, 60);
          add_card_energy(50);
          t[0] = 0.0;
          t[1] = 12.0;
          t[2] = 0.0;
          addbullet(this, NULL, 801, (double)(36 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
          play_sfx(1);
        }
        if ( !get_frame_time() )
        {
          if ( get_frame() == 5 )
          {
            t[0] = 20.0;
            t[1] = 12.0;
            t[2] = 0.0;
            addbullet(this, NULL, 801, (double)(36 * (char)dir) + x, y + 102.0, dir, 1, t, 3);
            play_sfx(1);
          }
          if ( !get_frame_time() )
          {
            if ( get_frame() == 7 )
            {
              t[0] = -20.0;
              t[1] = 12.0;
              t[2] = 0.0;
              x = dir;
LABEL_1063:
              addbullet(this, NULL, 801, (double)(36 * (char)x) + x, y + 102.0, x, 1,t, 3);
              play_sfx(1);
            }
LABEL_1064:
            if ( !get_frame_time() && get_frame() == 10 )
              v_force = 0.5;
          }
        }
      }
      return;
    case 416:
      //v360 = __OFSUB__(get_subseq(), 2);
      //v359 = (signed __int16)(get_subseq() - 2) < 0;
      if ( get_subseq() == 2 )
      {
        sub10func();
      //  v360 = __OFSUB__(get_subseq(), 2);
      //  v359 = (signed __int16)(get_subseq() - 2) < 0;
      }
      /*if ( v359 ^ v360 )
      {
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
        {
LABEL_1071:
          set_subseq(2);
          y = getlvl_height();
          reset_forces();
          return;
        }
      }*/
      if ( !keyDown(INP_C) )
        not_charge_attack = 0;
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
        goto LABEL_1129;
      if ( get_subseq() || get_frame_time() )
        goto LABEL_1090;
      if ( get_frame() == 2 && not_charge_attack )
      {
        next_subseq();
        scene_add_effect(this, 62, x - (double)(50 * (char)dir), y + 100.0, dir, 1);
      }
      else
      {
        if ( get_frame() == 5 )
        {
          play_sfx(1);
          h_inerc = -4.0;
          v_inerc = 8.0;
          v_force = 0.5;
          t[0] = 60.0;
          t[1] = 17.5;
          t[2] = 0.0;
          field_190 = 1;
          spell_energy_spend(200, 60);
          add_card_energy(50);
          addbullet(this, NULL, 801, (double)(30 * (char)dir) + x, y + 60.0, dir, 1, t, 3);
        }
LABEL_1090:
        if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
        {
          play_sfx(1);
          h_inerc = -4.0;
          v_inerc = 8.0;
          v_force = 0.5;
          t[0] = 60.0;
          t[1] = 12.0;
          t[2] = 2.0;
          field_190 = 1;
          spell_energy_spend(200, 60);
          add_card_energy(50);
          addbullet(this, NULL, 801, (double)(30 * (char)dir) + x, y + 60.0, dir, 1, t, 3);
          t[0] = 80.0;
          t[1] = 12.0;
          t[2] = 2.0;
          addbullet(this, NULL, 801, (double)(30 * (char)dir) + x, y + 60.0, dir, 1, t, 3);
          t[0] = 40.0;
          t[1] = 12.0;
          t[2] = 2.0;
          addbullet(this, NULL, 801, (double)(30 * (char)dir) + x, y + 60.0, dir, 1, t, 3);
        }
      }
      return;
    case 418:
      sub10func();
      h_inerc = h_inerc - 0.5;
      if ( h_inerc < 0.0 )
        h_inerc = 0.0;
      if ( process() )
        set_seq(0);
      if ( !get_frame_time() )
      {
        if ( get_frame() == 4 )
        {
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 819, x, y, dir, 1, t, 3);
        }
        if ( !get_frame_time() && get_frame() == 5 )
        {
          scene_play_sfx(29);
          field_49A = 0;
        }
      }
      return;
    case 500:
      if ( !get_subseq() && get_frame() <= 3 || get_subseq() == 2 )
        sub10func();
      field_18C = 0;
      if ( field_190 )
        field_7D0 = 1;
      v_inerc = v_inerc - v_force;
      if ( char_on_ground_down() )
      {
        y = getlvl_height();
        h_inerc = 20.0;
        v_inerc = 0.0;
        v_force = 0.0;
        set_subseq(2);
      }
      if ( get_subseq() == 1 )
      {
        if ( field_190 == 2 || field_190 == 7 )
        {
          h_inerc = 20.0;
          next_subseq();
          goto LABEL_1195;
        }
      }
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() )
      {
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          t[1] = 0.0;
          t[2] = 30.0;
          /*
          v1132 = 0.0;
          do
          {
            *(float *)&v1339 = scene_rand_rng(25) + v1132 * 45.0;
            v386 = (2 * (sin_deg(*(float *)&v1339) >= 0.0) - 1);
            addbullet(this, NULL, 810, x, y, dir, v386, (int)&v1339, 3);
            v1132 = v1132 + 1.0;
          }
          while ( v1132 < 8.0 );*/
          h_inerc = 30.0;
          v_inerc = 12.0;
          v_force = 2.0;
          spell_energy_spend(200, 120);
          add_card_energy(50);
          play_sfx(10);
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() )
        {
          if ( get_subseq() != 2 )
            return;
          goto LABEL_1129;
        }
      }
      if ( get_subseq() != 2 )
        return;
      h_inerc = h_inerc - 2.0;
      if ( h_inerc < 0.0 )
        h_inerc = 0.0;
      if ( get_frame() != 3 || field_7D0 )
        return;
      if ( (get_frame_time() < 15 || skills_1[0] < 1) && (get_frame_time() < 10 || skills_1[0] < 3) )
      {
      //  v390 = __OFSUB__(v388, 5);
      //  v389 = (signed __int16)(v388 - 5) < 0;
        goto LABEL_1191;
      }
      goto LABEL_1193;
    case 501:
      if ( !get_subseq() && get_frame() <= 3 || get_subseq() == 2 || get_subseq() == 5 )
        sub10func();
      if ( field_190 )
        field_7D0 = 1;
      field_18C = 0;
      v_inerc = v_inerc - v_force;
      if ( char_on_ground_down() )
      {
        y = getlvl_height();
        v_inerc = 0.0;
        v_force = 0.0;
        if ( get_subseq() > 1 )
        {
          if ( get_subseq() <= 4 )
          {
            h_inerc = 20.0;
            set_subseq(5);
          }
        }
        else
        {
          set_subseq(2);
        }
      }
      if ( get_subseq() == 1 || get_subseq() == 4 )
      {
        if ( field_190 == 2 || field_190 == 7 )
        {
          h_inerc = 20.0;
          next_subseq();
LABEL_1195:
          v_inerc = 0.0;
          v_force = 0.0;
          y = getlvl_height();
          return;
        }
      }
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
      {
        /*
        v1338 = 0.0;
        v1337 = 30.0;
        v1133 = 0.0;
        do
        {
          *(float *)&v1336 = scene_rand_rng(25) + v1133 * 45.0;
          v395 = (2 * (sin_deg(*(float *)&v1336) >= 0.0) - 1);
          addbullet(this, NULL, 810, x, y, dir, v395, (int)&v1336, 3);
          v1133 = v1133 + 1.0;
        }
        while ( v1133 < 8.0 );*/
        h_inerc = 17.5;
        v_inerc = 12.0;
        v_force = 2.0;
        spell_energy_spend(200, 120);
        add_card_energy(50);
        play_sfx(10);
      }
      if ( get_elaps_frames() )
        goto LABEL_1175;
      if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
        goto LABEL_1129;
      if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
      {
        field_190 = 0;
        field_194 = 1;
        /*
        v1320 = 0.0;
        v1319 = 30.0;
        v1134 = 0.0;
        do
        {
          *(float *)&v1318 = scene_rand_rng(25) + v1134 * 45.0;
          v396 = (2 * (sin_deg(*(float *)&v1318) >= 0.0) - 1);
          addbullet(this, NULL, 810, x, y, dir, v396, (int)&v1318, 3);
          v1134 = v1134 + 1.0;
        }
        while ( v1134 < 8.0 );*/
        h_inerc = 27.5;
        v_inerc = 15.0;
        v_force = 2.0;
        play_sfx(10);
      }
LABEL_1175:
      if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
      {
LABEL_1129:
        set_seq(9);
        return;
      }
      if ( get_subseq() == 2 || get_subseq() == 5 )
      {
        h_inerc = h_inerc - 2.0;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
        if ( get_subseq() == 5 && get_frame() == 3 && !field_7D0 )
        {
          if ( get_frame_time() >= 15 && skills_1[0] >= 1 )
            goto LABEL_1193;
          if ( get_frame_time() >= 10 && skills_1[0] >= 3 )
            goto LABEL_1193;
          //v390 = __OFSUB__(get_frame_time(), 5);
          //v389 = (signed __int16)(get_frame_time() - 5) < 0;
LABEL_1191:
          //if ( !(v389 ^ v390) && skills_1[0] >= 4 )
LABEL_1193:
            next_frame();
        }
      }
      break;
    case 505:
      sub10func();
      field_18C = 4;
      if ( (!get_subseq() || get_subseq() == 1 || get_subseq() == 2 || get_subseq() == 4) && h_inerc > 0.0 )
      {
        h_inerc = h_inerc - 0.4000000059604645;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
      }
      if ( get_subseq() == 3 && h_inerc > 0.0 && get_frame() >= 9 )
      {
        h_inerc = h_inerc - 0.699999988079071;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
      }
      if ( !keyDown(INP_B) )
        not_charge_attack = 0;
      if ( process() )
        set_seq(0);
      if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2 || !get_frame_time() && !get_frame() && get_subseq() == 3 || !get_frame_time() && !get_frame() && get_subseq() == 4) )
        goto LABEL_1378;
      if ( get_subseq() )
        goto LABEL_1235;
      /*
      if ( get_frame() >= 7 && pres_comb & 6 )
      {
        input_push_pressed_to_buf((Character *)v1);
        field_7D0 = 1;
        ((void (__thiscall *)(char_remilia *, signed int, signed int))set_seq_subseq_func1)(v1, 505, 1);
        return;
      }*/
      if ( !get_frame_time() )
      {
        if ( get_frame() == 4 )
        {
          h_inerc = 10.0;
          scene_add_effect(this, 127, x, y, dir, -1);
        }
        if ( !get_frame_time() && get_frame() == 5 )
        {
          play_sfx(21);
          h_inerc = 4.0;
          spell_energy_spend(200, 120);
          add_card_energy(30);
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 811, x, y, dir, 1, t, 3);
        }
      }
LABEL_1235:
      if ( get_subseq() != 1 )
        goto LABEL_1247;
      if ( get_frame() < 7 )
        goto LABEL_1241;
      if ( pres_comb & 2 )
      {
        //input_push_pressed_to_buf((Character *)v1);
        field_7D0 = 2;
        //((void (__thiscall *)(char_remilia *, signed int, signed int))set_seq_subseq_func1)(v1, 505, 2);
        set_seq(505);
        set_subseq(2);
        return;
      }
      if ( pres_comb & 4 )
      {
        //input_push_pressed_to_buf((Character *)v1);
        field_7D0 = 3;
        //((void (__thiscall *)(char_remilia *, signed int, signed int))set_seq_subseq_func1)(v1, 505, 3);
        set_seq(505);
        set_subseq(3);
        return;
      }
LABEL_1241:
      if ( !get_frame_time() )
      {
        if ( get_frame() == 5 )
        {
          h_inerc = 30.0;
          scene_add_effect(this, 127, x, y, dir, -1);
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 1.0;
          addbullet(this, NULL, 811, x, y, dir, 1, t, 3);
        }
        if ( !get_frame_time() && get_frame() == 6 )
        {
          play_sfx(21);
          h_inerc = 5.0;
          add_card_energy(30);
        }
      }
LABEL_1247:
      if ( get_subseq() != 2 || get_frame_time() )
        goto LABEL_1256;
      if ( get_frame() != 6 )
        goto LABEL_1253;
      if ( not_charge_attack )
      {
        set_subseq(4);
        scene_add_effect(this, 62, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
      }
      else
      {
        h_inerc = 20.0;
        scene_add_effect(this, 127, x, y, dir, -1);
        t[0] = 0.0;
        t[1] = 0.0;
        t[2] = 2.0;
        addbullet(this, NULL, 811, x, y, dir, 1, t, 3);
LABEL_1253:
        if ( !get_frame_time() && get_frame() == 8 )
        {
          play_sfx(22);
          h_inerc = 5.0;
          add_card_energy(30);
        }
LABEL_1256:
        if ( get_subseq() == 3 && !get_frame_time() )
        {
          if ( get_frame() == 7 )
            h_inerc = 20.0;
          if ( !get_frame_time() && get_frame() == 9 )
          {
            play_sfx(22);
            add_card_energy(30);
          }
        }
        if ( get_subseq() == 4 && !get_frame_time() )
        {
          if ( get_frame() == 1 )
          {
            h_inerc = 20.0;
            scene_add_effect(this, 127, x, y, dir, -1);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 2.0;
            addbullet(this, NULL, 811, x, y, dir, 1, t, 3);
          }
          if ( !get_frame_time() && get_frame() == 3 )
          {
            play_sfx(22);
            h_inerc = 5.0;
            add_card_energy(30);
          }
        }
      }
      return;
    case 506:
      sub10func();
      field_18C = 4;
      if ( !get_subseq() && h_inerc > 0.0 )
      {
        h_inerc = h_inerc - 0.4000000059604645;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
      }
      if ( process() )
        set_seq(0);
      if ( !get_subseq() )
      {
        if ( get_frame() >= 7 && pres_comb & 6 )
        {
          //input_push_pressed_to_buf((Character *)v1);
          field_7D0 = 1;
          //((void (__thiscall *)(char_remilia *, signed int, signed int))set_seq_subseq_func1)(v1, 505, 1);
          set_seq(505);
          set_subseq(1);
        }
        else if ( !get_frame_time() )
        {
          if ( get_frame() == 4 )
          {
            h_inerc = 30.0;
            scene_add_effect(this, 127, x, y, dir, -1);
          }
          if ( !get_frame_time() && get_frame() == 5 )
          {
            play_sfx(21);
            h_inerc = 5.0;
            spell_energy_spend(200, 120);
            add_card_energy(30);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 811, x, y, dir, 1, t, 3);
          }
        }
      }
      return;
    case 510:
      sub10func();
      field_18C = 8;
      if ( process() )
      {
        dir = -dir;
        h_inerc = 25.0;
        play_sfx(24);
        /*
        v1332 = 0.0;
        v1331 = 30.0;
        v1135 = 0.0;
        do
        {
          *(float *)&v1330 = scene_rand_rng(25) + v1135 * 45.0;
          v414 = (2 * (sin_deg(*(float *)&v1330) >= 0.0) - 1);
          addbullet(this, NULL, 810, x, y, dir, v414, (int)&v1330, 3);
          v1135 = v1135 + 1.0;
        }
        while ( v1135 < 8.0 );*/
        set_subseq(1);
        return;
      }
      if ( get_subseq() && get_subseq() != 3 && get_subseq() != 4 )
        goto LABEL_1305;
      //if ( get_frame_time() )
      //  goto LABEL_1301;
      if ( get_frame() == 2 )
      {
        h_inerc = 40.0;
        spell_energy_spend(200, 120);
        add_card_energy(50);
        play_sfx(10);
        /*
        v1308 = 0.0;
        v1307 = 30.0;
        v1136 = 0.0;
        do
        {
          *(float *)&v1306 = scene_rand_rng(25) + v1136 * 45.0;
          v418 = (2 * (sin_deg(*(float *)&v1306) >= 0.0) - 1);
          addbullet(this, NULL, 810, x, y, dir, v418, (int)&v1306, 3);
          v1136 = v1136 + 1.0;
        }
        while ( v1136 < 8.0 );*/
      }
      //if ( get_frame_time() )
      //  goto LABEL_1301;
      //v420 = __OFSUB__(get_frame(), 4);
      //v419 = (signed __int16)(get_frame() - 4) < 0;
      if ( get_frame() == 4 )
      {
        h_inerc = h_inerc * 0.5;
//LABEL_1301:
        //v420 = __OFSUB__(get_frame(), 4);
        //v419 = (signed __int16)(get_frame() - 4) < 0;
      }
      /*if ( !(v419 ^ v420) )
      {
        h_inerc = h_inerc - 1.0;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
      }*/
LABEL_1305:
      if ( get_elaps_frames() || get_frame_time() || get_frame() )
        goto LABEL_1312;
      if ( get_subseq() == 1 )
      {
        dir = -dir;
        h_inerc = 25.0;
        play_sfx(24);/*
        v1311 = 0.0;
        v1310 = 30.0;
        v1137 = 0.0;
        do
        {
          *(float *)&v1309 = scene_rand_rng(25) + v1137 * 45.0;
          v422 = (2 * (sin_deg(*(float *)&v1309) >= 0.0) - 1);
          addbullet(this, NULL, 810, x, y, dir, v422, (int)&v1309, 3);
          v1137 = v1137 + 1.0;
        }
        while ( v1137 < 8.0 );*/
LABEL_1312:
        if ( get_subseq() == 1 )
        {
          if ( get_frame() >= 3 )
          {
            h_inerc = h_inerc - 1.0;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( field_190 )
            goto LABEL_1370;
        }
      }
      if ( get_elaps_frames() )
        goto LABEL_1330;
      if ( !get_frame_time() && !get_frame() && get_subseq() == 2 || !get_frame_time() && !get_frame() && get_subseq() == 3 )
        goto LABEL_1378;
      if ( get_frame_time() || get_frame() || get_subseq() != 4 )
      {
LABEL_1330:
        if ( get_subseq() == 2 )
        {
          if ( get_frame() >= 2 )
          {
            h_inerc = h_inerc - 1.0;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( !get_frame_time() && get_frame() == 3 )
          {
            play_sfx(21);/*
            v1323 = 0.0;
            v1322 = 30.0;
            v1139 = 0.0;
            do
            {
              *(float *)&v1321 = scene_rand_rng(25) + v1139 * 45.0;
              v426 = (2 * (sin_deg(*(float *)&v1321) >= 0.0) - 1);
              addbullet(this, NULL, 810, x, y, dir, v426, (int)&v1321, 3);
              v1139 = v1139 + 1.0;
            }
            while ( v1139 < 8.0 );*/
          }
        }
      }
      else
      {
        dir = -dir;
        h_inerc = 25.0;
        play_sfx(24);/*
        v1317 = 0.0;
        v1316 = 30.0;
        v1138 = 0.0;
        do
        {
          *(float *)&v1315 = scene_rand_rng(25) + v1138 * 45.0;
          v424 = (2 * (sin_deg(*(float *)&v1315) >= 0.0) - 1);
          addbullet(this, NULL, 810, x, y, dir, v424, (int)&v1315, 3);
          v1138 = v1138 + 1.0;
        }
        while ( v1138 < 8.0 );*/
        set_subseq(1);
      }
      return;
    case 511:
      sub10func();
      field_18C = 8;
      if ( process() )
      {
        play_sfx(24);
        h_inerc = 25.0;/*
        v1329 = 0.0;
        v1328 = 30.0;
        v1140 = 0.0;
        do
        {
          *(float *)&v1327 = scene_rand_rng(25) + v1140 * 45.0;
          v427 = (2 * (sin_deg(*(float *)&v1327) >= 0.0) - 1);
          addbullet(this, NULL, 810, x, y, dir, v427, (int)&v1327, 3);
          v1140 = v1140 + 1.0;
        }
        while ( v1140 < 8.0 );*/
        set_subseq(1);
        return;
      }
      if ( get_subseq() && get_subseq() != 3 && get_subseq() != 4 )
        goto LABEL_1358;
      //if ( get_frame_time() )
      //  goto LABEL_1354;
      if ( get_frame() == 2 )
      {
        h_inerc = -30.0;
        spell_energy_spend(200, 120);
        add_card_energy(50);
        play_sfx(10);/*
        v1335 = 0.0;
        v1334 = 30.0;
        v1141 = 0.0;
        do
        {
          *(float *)&v1333 = scene_rand_rng(25) + v1141 * 45.0;
          v431 = (2 * (sin_deg(*(float *)&v1333) >= 0.0) - 1);
          addbullet(this, NULL, 810, x, y, dir, v431, (int)&v1333, 3);
          v1141 = v1141 + 1.0;
        }
        while ( v1141 < 8.0 );*/
      }
      //if ( get_frame_time() )
      //  goto LABEL_1354;
      //v433 = __OFSUB__(get_frame(), 4);
      //v432 = (signed __int16)(get_frame() - 4) < 0;
      if ( get_frame() == 4 )
      {
        h_inerc = h_inerc * 0.5;
//LABEL_1354:
      //  v433 = __OFSUB__(get_frame(), 4);
      //  v432 = (signed __int16)(get_frame() - 4) < 0;
      }/*
      if ( !(v432 ^ v433) )
      {
        v434 = h_inerc + 1.0;
        h_inerc = v434;
        if ( v434 > 0.0 )
          h_inerc = 0.0;
      }*/
LABEL_1358:
      if ( get_elaps_frames() || get_frame_time() || get_frame() )
        goto LABEL_1365;
      if ( get_subseq() == 1 )
      {
        play_sfx(24);
        h_inerc = 25.0;/*
        v1305 = 0.0;
        v1304 = 30.0;
        v1142 = 0.0;
        do
        {
          *(float *)&v1303 = scene_rand_rng(25) + v1142 * 45.0;
          v435 = (2 * (sin_deg(*(float *)&v1303) >= 0.0) - 1);
          addbullet(this, NULL, 810, x, y, dir, v435, (int)&v1303, 3);
          v1142 = v1142 + 1.0;
        }
        while ( v1142 < 8.0 );*/
LABEL_1365:
        if ( get_subseq() == 1 )
        {
          if ( get_frame() >= 3 )
          {
            h_inerc = h_inerc - 1.0;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( field_190 )
          {
LABEL_1370:
            next_subseq();
            field_190 = 0;
            field_194 = 1;
            h_inerc = 15.0;
            return;
          }
        }
      }
      if ( get_elaps_frames() )
        goto LABEL_1385;
      if ( !get_frame_time() && !get_frame() && get_subseq() == 2 || !get_frame_time() && !get_frame() && get_subseq() == 3 )
        goto LABEL_1378;
      if ( get_frame_time() || get_frame() || get_subseq() != 4 )
      {
LABEL_1385:
        if ( get_subseq() == 2 )
        {
          if ( get_frame() >= 2 )
          {
            h_inerc = h_inerc - 1.0;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( !get_frame_time() && get_frame() == 3 )
          {
            play_sfx(21);/*
            v1314 = 0.0;
            v1313 = 30.0;
            v1144 = 0.0;
            do
            {
              *(float *)&v1312 = scene_rand_rng(25) + v1144 * 45.0;
              v439 = (2 * (sin_deg(*(float *)&v1312) >= 0.0) - 1);
              addbullet(this, NULL, 810, x, y, dir, v439, (int)&v1312, 3);
              v1144 = v1144 + 1.0;
            }
            while ( v1144 < 8.0 );*/
          }
        }
      }
      else
      {
        play_sfx(24);
        h_inerc = 25.0;/*
        v1326 = 0.0;
        v1325 = 30.0;
        v1143 = 0.0;
        do
        {
          *(float *)&v1324 = scene_rand_rng(25) + v1143 * 45.0;
          v437 = (2 * (sin_deg(*(float *)&v1324) >= 0.0) - 1);
          addbullet(this, NULL, 810, x, y, dir, v437, (int)&v1324, 3);
          v1143 = v1143 + 1.0;
        }
        while ( v1143 < 8.0 );*/
        set_subseq(1);
      }
      return;
    default:
      goto LABEL_2712;
  }
}

// note: taken from marisa.cpp
void char_remilia::func20()
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

void char_remilia::set_seq_params()
{
  double v5 = 0.0;

  if ( get_seq() > 501 )
  {
    if ( get_seq() > 797 )
    {
      if ( get_seq() != 798 )
      {
LABEL_81:
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
LABEL_15:
          field_190 = 0;
          field_49A = 0;
          field_194 = 1;
          not_charge_attack = 1;
          return;
        case 510:
        case 511:
          field_18C = 8;
          reset_forces();
          /*
          v9 = __OFSUB__(skills_1[8], 2);
          v8 = (char)(skills_1[8] - 2) < 0;
          */
          field_194 = 1;
          field_190 = 0;
          field_49A = 0;
          /*
          if ( !((unsigned __int8)v8 ^ v9) )
            vtbl->set_subseq_func3(&meta, 3);
          if ( skills_1[8] >= 4 )
            vtbl->set_subseq_func3(&meta, 4);
            */
          return;
        case 520:
        case 521:
          field_18C = 1;
          not_charge_attack = 1;
          reset_forces();
          field_190 = 1;
          field_49A = 0;
          return;
        case 525:
        case 526:
        case 527:
        case 528:
          field_18C = 5;
          field_7D0 = 0;
          not_charge_attack = 1;
          reset_forces();
          field_49A = 0;
          field_190 = 1;
          return;
        case 530:
        case 531:
          field_18C = 9;
          reset_forces();
          field_194 = 0;
          field_49A = 0;
          field_190 = 1;
          not_charge_attack = 1;
          return;
        case 540:
        case 541:
          field_7D0 = 0;
          field_194 = 4;
          field_18C = 2;
          field_190 = 0;
          reset_forces();/*
          v9 = __OFSUB__(skills_1[2], 1);
          v8 = (char)(skills_1[2] - 1) < 0;*/
          not_charge_attack = 1;/*
          if ( !((unsigned __int8)v8 ^ v9) )
            field_51C = 2;
            */
          return;
        case 542:
        case 547:
          field_190 = 0;
          not_charge_attack = 0;
          field_18C = 2;
          field_194 = 1;
          return;
        case 545:
        case 546:
          field_18C = 6;
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          not_charge_attack = 0;
          return;
        case 550:
        case 551:
          field_18C = 10;
          field_194 = 0;
          field_190 = 0;
          goto LABEL_58;
        case 560:
        case 561:
          field_18C = 3;
          field_194 = 1;
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          not_charge_attack = 1;
          return;
        case 565:
        case 566:
          field_18C = 7;
          field_190 = 0;
          reset_forces();
          field_194 = 1;
          not_charge_attack = 1;
          return;
        case 567:
          field_18C = 7;
          field_190 = 0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
LABEL_28:
          not_charge_attack = 1;
          v_force = 0.0;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 570:
        case 571:
          field_18C = 11;
          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 599:
          field_190 = 1;
          reset_forces();
LABEL_32:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          return;
        case 600:
          field_7DC = 240.0;
          goto LABEL_65;
        case 601:
        case 604:
LABEL_65:
          field_190 = 1;
          reset_forces();
          return;
        case 602:
        case 605:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 0;
          field_194 = 20;
          reset_forces();
          return;
        case 603:
          field_190 = 1;
          field_7DC = 320.0;
          reset_forces();
          return;
        case 606:
          field_7D0 = 0;
          field_7D2 = 0;
          goto LABEL_69;
        case 607:
        case 710:
        case 711:
          field_190 = 1;
          reset_forces();
          field_7DC = 0.0;
          field_7E4 = 0.0;
          return;
        case 608:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 1;
          reset_forces();
          return;
        case 609:
          field_7D0 = 0;
LABEL_69:
          field_190 = 0;
          field_194 = 1;
          reset_forces();
          return;
        case 610:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 1;
          reset_forces();
          return;
        case 612:
        case 615:
          field_190 = 1;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          not_charge_attack = 1;
          return;
        case 613:
          field_190 = 0;
          not_charge_attack = 1;
          return;
        case 707:
LABEL_58:
          reset_forces();
          return;
        case 708:
          h_inerc = 0.0;
          goto LABEL_77;
        case 709:
LABEL_77:
          field_7D0 = 0;
          break;
        case 720:
        case 721:
          field_190 = 0;
          field_194 = 1;
          reset_forces();
          field_7D0 = 0;
          break;
        case 730:
        case 731:
        case 740:
          field_190 = 0;
          field_194 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          break;
        default:
          goto LABEL_81;
      }
      return;
    }
    reset_forces();
    h_inerc = 12.0;
    field_7D0 = 0;
LABEL_83:
    v_inerc = 0.0;
    v_force = 0.5;
    return;
  }
  if ( get_seq() >= 500 )
  {
    field_7D0 = 0;
    field_18C = 0;
    reset_forces();
    field_190 = 0;
    field_49A = 0;
    field_194 = 1;
    return;
  }
  if ( get_seq() > 214 )
  {
    switch ( get_seq() )
    {
      case 217:
        reset_ofs();
        h_inerc = 0.0;
        v_inerc = 0.0;
        v_force = 0.60000002;
        x_off = 0.0;
        y_off = 95.0;
        v5 = 17.5;
        goto LABEL_10;
      case 300:
      case 301:
      case 303:
      case 322:
      case 330:
        goto LABEL_38;
      case 302:
        if ( !field_49A )
          reset_forces();
        goto LABEL_15;
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
      case 325:
        field_7D0 = 0;
        field_190 = 0;
        field_194 = 1;
        return;
      case 307:
        reset_forces();
        goto LABEL_20;
      case 308:
      case 309:
LABEL_20:
        field_194 = 1;
        field_190 = 0;
        not_charge_attack = 1;
        return;
      case 310:
        h_inerc = 0.0;
        field_7D0 = 0;
        field_194 = 99;
        field_190 = 0;
        goto LABEL_83;
      case 320:
        field_49A = 0;
        field_190 = 0;
        field_194 = 1;
        return;
      case 321:
        if ( !field_49A )
          reset_forces();
        field_190 = 0;
        field_194 = 2;
        return;
      case 400:
      case 401:
      case 402:
      case 410:
      case 411:
        field_190 = 0;
        reset_forces();
        not_charge_attack = 1;
        return;
      case 404:
      case 406:
        field_190 = 0;
        goto LABEL_28;
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
      case 412:
        field_190 = 0;
        reset_forces();
        goto LABEL_32;
      case 414:
        v_force = 0.025;
        field_190 = 0;
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        field_7D8 = 0;
        not_charge_attack = 1;
        h_inerc = h_inerc * 0.2000000029802322;
        v_inerc = 0.2000000029802322 * v_inerc;
        return;
      case 415:
        field_190 = 0;
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        goto LABEL_35;
      case 416:
        field_190 = 0;
LABEL_35:
        not_charge_attack = 1;
        v_force = 0.025;
        h_inerc = h_inerc * 0.2000000029802322;
        v_inerc = 0.2000000029802322 * v_inerc;
        return;
      case 418:
        h_inerc = 17.5;
LABEL_38:
        if ( !field_49A )
          reset_forces();
        field_190 = 0;
        field_194 = 1;
        return;
      default:
        goto LABEL_81;
    }
    goto LABEL_81;
  }
  if ( get_seq() != 214 )
  {
    if ( !(get_seq() - 4) )
    {
      h_inerc = 6.5;
      return;
    }
    if ( (get_seq() - 4) == 1 )
    {
      h_inerc = -6.5;
      return;
    }
    goto LABEL_81;
  }
  h_inerc = 0.0;
  v_inerc = 0.0;
  v_force = 0.60000002;
  x_off = 0.0;
  y_off = 75.0;
  v5 = 25.0;
LABEL_10:
  field_7DC = v5;
  field_7D6 = 0;
  field_7EC = 0.0;
}
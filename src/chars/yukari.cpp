#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "yukari.h"
#include <math.h>

char_yukari::char_yukari(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_YUKARI;
	pgp->load_dat("yukari",pal);
	char_loadsfx("yukari");
	cards_load_cards(&chr_cards,"yukari");
	load_face("yukari");
	load_spells("yukari");
	stand_gfx->init(this,"yukari");
}

void char_yukari::init_vars()
{
  char_c::init_vars();
  field_138 = -6.0;
  field_898 = 0.0;
  field_8A0 = 0.0;
  field_89C = 0.0;
  field_8A4 = 0.0;
  field_8A8 = 0;
  field_8AA = 0;
  field_8AC = 0;
  field_8B2 = 0;
  field_8AE = 0;
  field_8B0 = 0;
  field_8D0 = 0;
  field_890 = 0;
  field_892 = 0;
  field_894 = 0;
  field_895 = 0;
  field_8B4 = 0;
  field_8B8 = 0.0;
  field_8C4 = 0.0;
  field_8BC = 0.0;
  field_8C8 = 0.0;
  field_8C0 = 0.0;
  field_8CC = 0.0;
}
/*
c_bullet *char_yukari::new_bullet()
{
    c_bullet *tmp = new yukari_bullets();
    return tmp;
}
*/
void char_yukari::func10()
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

  int v2 = 0;

  double move_val = 0.0;
  double move_vala = 0.0;
  double move_valb = 0.0;

  double v39 = 0.0;
  double v51 = 0.0;
  double v68 = 0.0;
  double v70 = 0.0;

  double v137 = 0.0;
  double v140 = 0.0;

  double v450 = 0.0;
  bool v255 = false;

  double v461 = 0.0;
  double a4d = 0.0;
  double v497 = 0.0;

  double a4e = 0.0;
  double v539 = 0.0;
  double v566 = 0.0;
  double v572 = 0.0;

  double a4f = 0.0;
  double v624 = 0.0;

  double a4g = 0.0;
  double v648 = 0.0;

  double a4h = 0.0;
  double v663 = 0.0;

  double a4i = 0.0;
  double v681 = 0.0;

  double v688 = 0.0;
  int v705 = 0;

  double v776 = 0.0;

  double v980 = 0.0;
  double v1006 = 0.0;

  double a4j = 0.0;
  double v791 = 0.0;

  double v1007 = 0.0;
  double v800 = 0.0;
  double v981 = 0.0;
  double a4k = 0.0;
  double v799 = 0.0;
  
  double v988 = 0.0;
  double v877 = 0.0;
  double xt = 0.0;

  bool v905 = false;
  int v908 = 0;

  double v912 = 0.0;
  double v989 = 0.0;

  double a4l = 0.0;
  double v911 = 0.0;

  bool v251 = false;

  double v346 = 0.0;
  bool v347 = false;

  double v455 = 0.0;
  double a4c = 0.0;

  double v475 = 0.0;
  double v1008 = 0.0;

  x_delta = 0;
  y_delta = 100;
  if ( health <= 0 )
    field_8B4 = 0;
  if ( enemy->health <= 0 )
    field_8B4 = 0;
  v2 = 1;
  if ( char_is_shock() )
  {
    field_572 = 1;
    field_571 = 1;
  }
  if ( get_seq() > 149 && get_seq() < 159 && !bbarrier_show )
  {
    bbarrier_show = 1;
    if ( get_seq() > 149 && get_seq() < 154 )
    {
      t[0] = 10.0;
      t[1] = 0.0;
      t[2] = 0.0;
      addbullet(this, NULL, 998, (double)(80 * (char)dir) + x, y + 130.0, dir, 1, t, 1);
      t[0] = -10.0;
      addbullet(this, NULL, 998, (double)(80 * (char)dir) + x, y + 130.0, dir, 1, t, 1);
    }
    if ( get_seq() > 153 && get_seq() < 158 )
    {
      t[0] = 10.0;
      t[1] = 0.0;
      t[2] = 0.0;
      addbullet(this, NULL, 998, (double)(60 * (char)dir) + x, y + 80.0, dir, 1, t, 1);
      t[0] = -10.0;
      t[1] = 0.0;
      t[2] = 0.0;
      addbullet(this, NULL, 998, (double)(60 * (char)dir) + x, y + 80.0, dir, 1, t, 1);
    }
    if ( get_seq() == 158 )
    {
      t[0] = 10.0;
      t[1] = 0.0;
      t[2] = 0.0;
      addbullet(this, NULL, 998, (double)(75 * (char)dir) + x, y + 140.0, dir, 1, t, 1);
      t[0] = -10.0;
      t[1] = 0.0;
      t[2] = 0.0;
      addbullet(this, NULL, 998, (double)(75 * (char)dir) + x, y + 140.0, dir, 1, t, 1);
    }
  }
  if ( !hit_stop && !enemy->time_stop )
  {
    if ( get_seq() <= 300 )
    {
      if ( get_seq() == 300 )
      {
LABEL_772:
        sub10func();
        if ( true /*!get_true(0)*/ )
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
              goto LABEL_26;
            goto LABEL_27;
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
              goto LABEL_43;
            return;
          case 2:
            sub10func();
            if ( !field_49A )
            {
LABEL_26:
              reset_forces();
              process();
              return;
            }
LABEL_27:
            if ( 0.0 < h_inerc )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
              {
                reset_forces();
                field_49A = 0;
              }
            }
            if ( 0.0 <= h_inerc )
              goto LABEL_102;
            h_inerc = h_inerc + 0.5;
            if ( h_inerc <= 0.0 )
              goto LABEL_102;
            reset_forces();
            field_49A = 0;
            process();
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
              goto LABEL_56;
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
                goto LABEL_99;
            }
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v39 = 0.0;
            goto LABEL_71;
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
                goto LABEL_99;
            }
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v39 = 4.0;
            goto LABEL_71;
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
                goto LABEL_99;
            }
            process();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              v39 = -4.0;
LABEL_71:
              char_h_move(v39);
              v_inerc = 12.5;
              v_force = 0.55000001;
              field_49A = 0;
            }
            return;
          case 9:
            if ( 0.0 == v_force )
              v_force = 0.60000002;
            v_inerc = v_inerc - v_force;
            if ( !char_on_ground_down() )
              goto LABEL_102;
LABEL_99:
            move_val = 10;
            goto LABEL_100;
          case 10:
            sub10func();
            reset_forces();
            if ( !process() )
              return;
            if ( dY() )
              goto LABEL_106;
            set_seq(0);
            return;
          case 71:
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_113;
            if ( get_subseq() == 1 )
            {
              if ( !field_890 )
              {
                field_890 = 1;
                addbullet(this, NULL, 999, x, y, dir, -1, 0, 0);
              }
LABEL_113:
              if ( get_subseq() == 1 && v_inerc < 2.0 )
                goto LABEL_908;
            }
            v_inerc = v_inerc - v_force;
            if ( v_inerc > 0.0 )
              v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              if ( !field_80C )
                goto LABEL_124;
              if ( weather_id == 18 )
              {
                goto LABEL_121;
              }
              goto LABEL_122;
            }
            if ( field_7D0 > 0 )
              field_7D0 = field_7D0 - 1;
            if ( get_border_near() && h_inerc < 0.0 )
            {
              h_inerc = h_inerc + 1.0;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
              if ( field_4AC )
              {
                field_74C = (double)field_7D0 * -2.0;
                process();
                return;
              }
            }
            goto LABEL_102;
          case 72:
            if ( get_subseq() == 1 && v_inerc < 2.0 )
              goto LABEL_908;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_890 )
            {
              field_890 = 1;
              addbullet(this, NULL, 999, x, y, dir, -1, 0, 0);
            }
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              if ( !field_80C )
              {
LABEL_148:
                field_7D0 = 100 * h_inerc;
                field_7D2 = 100 * v_inerc;
                reset_forces();
                y = getlvl_height();
                set_seq(97);
                goto LABEL_125;
              }
              if ( weather_id == 18 )
                // weather_time = ((double)weather_time * 0.75);
LABEL_147:
              field_7D0 = 100 * h_inerc;
              field_7D2 = 100 * v_inerc;
              reset_forces();
              y = getlvl_height();
              set_seq(89);
              v51 = 5.0;
              goto LABEL_126;
            }
            if ( get_border_near() && h_inerc < 0.0 )
            {
              h_inerc = h_inerc + 1.0;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
              if ( field_4AC )
              {
                field_74C = h_inerc;
                process();
                return;
              }
            }
            goto LABEL_102;
          case 73:
            if ( char_on_ground_down() )
            {
              if ( !field_80C )
              {
                field_7D0 = 100 * h_inerc;
                field_7D2 = 100 * v_inerc;
                reset_forces();
                move_vala = 97;
                goto LABEL_123;
              }
              if ( weather_id != 18 )
                goto LABEL_122;
              goto LABEL_121;
            }
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              goto LABEL_2872;
            if ( !field_890 )
            {
              field_890 = 1;
              addbullet(this, NULL, 999, x, y, dir, -1, 0, 0);
            }
            if ( 0.0 == v_inerc )
            {
LABEL_2872:
              if ( --field_7D0 < 0 )
                field_7D0 = 0;
              if ( get_border_near() && h_inerc < 0.0 )
              {
                h_inerc = h_inerc + 2.5;
                if ( h_inerc > 0.0 )
                  h_inerc = 0.0;
                if ( field_4AC )
                  field_74C = (double)field_7D0 * -2.0;
              }
              return;
            }
            goto LABEL_216;
          case 74:
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_181;
            if ( get_subseq() == 1 )
            {
              if ( !field_890 )
              {
                field_890 = 1;
                addbullet(this, NULL, 999, x, y, dir, -1, 0, 0);
              }
LABEL_181:
              if ( get_subseq() == 1 && v_inerc < 2.0 )
                goto LABEL_1273;
            }
            if ( get_border_near() && (h_inerc <= -25.0 || field_80C) )
            {
              if ( weather_id != 18 )
                goto LABEL_189;
              goto LABEL_188;
            }
            if ( get_border_near() && h_inerc <= -15.0 )
            {
              set_seq(78);
              return;
            }
            v_inerc = v_inerc - v_force;
            if ( !char_on_ground_down() )
            {
LABEL_102:
              process();
              return;
            }
            if ( !field_80C )
              goto LABEL_124;
            if ( weather_id != 18 )
              goto LABEL_122;
            goto LABEL_121;
          case 75:
            if ( char_on_ground_down() )
            {
              if ( field_80C )
              {
                /*if ( weather_id == 18 )
                {
LABEL_121:
                  // weather_time = ((double)weather_time * 0.75);
                }*/
                LABEL_121: //TODO: change
LABEL_122:
                field_7D0 = 100 * h_inerc;
                field_7D2 = 100 * v_inerc;
                reset_forces();
                move_vala = 89;
LABEL_123:
                y = getlvl_height();
                set_seq(move_vala);
                v51 = 5.0;
              }
              else
              {
LABEL_124:
                field_7D0 = 100 * h_inerc;
                field_7D2 = 100 * v_inerc;
                reset_forces();
                y = getlvl_height();
                set_seq(97);
LABEL_125:
                v51 = 2.0;
              }
LABEL_126:
              //shake_camera(v51);
              scene_play_sfx(22);
            }
            else if ( get_border_near() && (h_inerc <= -25.0 || field_80C) )
            {
              /*if ( weather_id == 18 )
              {
LABEL_188:
                // weather_time = ((double)weather_time * 0.75);
              }*/
              LABEL_188: //TODO: change
LABEL_189:
              set_seq(76);
            }
            else if ( get_border_near() && h_inerc <= -15.0 )
            {
              set_seq(78);
            }
            else
            {
              process();
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                if ( !field_890 )
                {
                  field_890 = 1;
                  addbullet(this, NULL, 999, x, y, dir, -1, 0, 0);
                }
                if ( 0.0 != v_inerc )
                {
LABEL_216:
                  if ( 0.0 == h_inerc )
                    set_seq(3);
                  else
LABEL_106:
                    set_subseq(2);
                }
              }
            }
            return;
          case 76:
            if ( get_subseq() > 0 )
              angZ = angZ - 30.0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              scene_play_sfx(22);
              field_7D0 = 100 * h_inerc;
              field_7D2 = 100 * v_inerc;
              reset_forces();
              y = getlvl_height();
              set_seq(97);
              angZ = 0.0;
              v68 = 4.0;
              goto LABEL_222;
            }
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            dir = -dir;
            h_inerc = -3.0;
            v70 = 10.0;
            goto LABEL_228;
          case 77:
            angZ = angZ - 30.0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              if ( field_80C )
              {
                if ( weather_id == 18 )
                  // weather_time = ((double)weather_time * 0.75);
                field_7D0 = 100 * h_inerc;
                field_7D2 = 100 * v_inerc;
                reset_forces();
                move_valb = 89;
                goto LABEL_269;
              }
              scene_play_sfx(22);
              field_7D0 = 100 * h_inerc;
              field_7D2 = 100 * v_inerc;
              reset_forces();
              y = getlvl_height();
              set_seq(97);
              angZ = 0.0;
              v68 = 2.0;
LABEL_222:
              //shake_camera(v68);
              reset_ofs();
            }
            else
            {
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_890 )
              {
                field_890 = 1;
                addbullet(this, NULL, 999, x, y, dir, -1, 0, 0);
              }
              process();
            }
            return;
          case 78:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              scene_play_sfx(22);
              field_7D0 = 100 * h_inerc;
              field_7D2 = 100 * v_inerc;
              reset_forces();
              y = getlvl_height();
              set_seq(97);
              //shake_camera(2.0);
            }
            else
            {
              process();
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                dir = -dir;
                h_inerc = -5.0;
                v70 = 3.0;
LABEL_228:
                v_inerc = v70;
                v_force = 0.5;
                if ( !field_890 )
                {
                  field_890 = 1;
                  addbullet(this, NULL, 999, x, y, dir, -1, 0, 0);
                }
              }
            }
            return;
          case 88:
            if ( char_on_ground_down() )
              goto LABEL_147;
            process();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              if ( !field_890 )
              {
                field_890 = 1;
                addbullet(this, NULL, 999, x, y, dir, -1, 0, 0);
              }
              if ( 0.0 != v_inerc )
                goto LABEL_216;
            }
            if ( --field_7D0 < 0 )
              field_7D0 = 0;
            if ( get_border_near() && h_inerc < 0.0 )
            {
              h_inerc = h_inerc + 2.5;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
              if ( field_4AC )
                field_74C = (double)field_7D0 * -2.0;
            }
            return;
          case 89:
            if ( get_subseq() > 0 && (angZ = angZ - 40.0, v_inerc = v_inerc - v_force, char_on_ground_down()) )
            {
              field_7D0 = 100 * h_inerc;
              field_7D2 = 100 * v_inerc;
              reset_forces();
              move_valb = 97;
LABEL_269:
              y = getlvl_height();
              set_seq(move_valb);
              angZ = 0.0;
              //shake_camera(2.0);
              reset_ofs();
              scene_play_sfx(22);
            }
            else
            {
              process();
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                h_inerc = (double)field_7D0 * 0.002499999944120646;
                v_inerc = 0.002499999944120646 * (double)-field_7D2;
                v_force = 0.25;
                x_delta = 0;
                y_delta = 85;
                x_off = (double)x_delta;
                y_off = (double)y_delta;
              }
            }
            return;
          case 145:
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_281;
            if ( get_subseq() == 1 )
            {
              if ( !field_890 )
              {
                field_890 = 1;
                addbullet(this, NULL, 999, x, y, dir, -1, 0, 0);
              }
LABEL_281:
              if ( get_subseq() == 1 && v_inerc < 2.0 )
                goto LABEL_1273;
            }
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_148;
            if ( process() )
              set_subseq(5);
            return;
          case 197:
            if ( !get_frame_time() && !get_frame() )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 981, x, y, dir, -1, t, 3);
              t[2] = 6.0;
              addbullet(this, NULL, 981, x, y, dir, -1, t, 3);
            }
            if ( !(get_frame()) || (get_frame()) >= 22 )
              sub10func();
            if ( !process() )
              goto LABEL_297;
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
LABEL_297:
            if ( get_frame_time() )
              return;
            if ( get_frame() == 9 )
              h_inerc = 30.0;
            if ( get_frame_time() )
              return;
            if ( get_frame() == 10 )
            {
              h_inerc = 0.0;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 3.0;
              addbullet(this, NULL, 981, x, y, dir, -1, t, 3);
            }
            goto LABEL_304;
          case 198:
            if ( !get_frame_time() && !get_frame() )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 981, x, y, dir, -1, t, 3);
              t[2] = 6.0;
              addbullet(this, NULL, 981, x, y, dir, -1, t, 3);
            }
            if ( !(get_frame()) || (get_frame()) >= 22 )
              sub10func();
            if ( !process() )
              goto LABEL_321;
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
LABEL_321:
              if ( !get_frame_time() )
              {
                if ( get_frame() == 9 )
                  h_inerc = -30.0;
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 10 )
                  {
                    h_inerc = 0.0;
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 3.0;
                    addbullet(this, NULL, 981, x, y, dir, -1, t, 3);
                  }
                  if ( !get_frame_time() && get_frame() == 23 )
                  {
                    if ( enemy->x < (double)x )
                      dir = -1;
                    if ( enemy->x > (double)x )
                      dir = 1;
                  }
                }
              }
            }
            return;
          case 199:
            if ( !(get_frame()) || (get_frame()) >= 22 )
              sub10func();
            if ( !get_frame_time() && !get_frame() )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 981, x, y, dir, -1, t, 3);
              t[2] = 6.0;
              addbullet(this, NULL, 981, x, y, dir, -1, t, 3);
            }
            if ( !process() )
              goto LABEL_344;
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
LABEL_344:
            if ( get_frame_time() )
              return;
            if ( get_frame() != 10 || cards_added <= 0 )
              goto LABEL_352;
            if ( controlling_type != 2 || cards_active[0]->id < 16 || cards_active[0]->id > 19 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 3.0;
              addbullet(this, NULL, 981, x, y, dir, -1, t, 3);
LABEL_352:
LABEL_304:
              if ( get_frame_time() == 0 && get_frame() == 23 )
              {
                if ( enemy->x < (double)x )
                  dir = -1;
                if ( enemy->x > (double)x )
                  dir = 1;
              }
            }
            else
            {
              //color_A = 0;
              x = 640.0;
              y = 200.0;
              set_seq(750);
              dir = 1;
            }
            return;
          case 200:
            sub10func();
            field_49A = 1;
            if ( h_inerc > 8.0 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 8.0 )
                h_inerc = 8.0;
            }
            process();
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              char_h_move(11.0);
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
              if ( dY() >= 0 )
              {
                if ( dX(dir) <= 0 && ++field_7D0 > 5 || ++field_7D0 > 60 )
                  set_seq(204);
              }
              else
              {
                if ( (dX(dir) < 0) | (dX(dir) == 0) )
                  set_seq(211);
                else
                  set_seq(212);
              }
            }
            return;
          case 201:
            v2 = 3;
            if ( !(get_subseq()) || (get_subseq()) == 3 )
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
              {
                v_inerc = 0.0;
                v_force = 0.0;
                goto LABEL_383;
              }
            }
            if ( get_subseq() == 5 && get_elaps_frames() >= 10 )
            {
              x = dir == 1 ? 1240.0 : 40.0;
              y = getlvl_height();
              if ( get_elaps_frames() == 70 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                addbullet(this, NULL, 849, (double)(200 * dir) + x, y + 70.0, -dir, -1, t, 3);
              }
            }
            if ( process() )
            {
              set_seq(0);
              h_inerc = 0.0;
            }
            else
            {
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                char_h_move(-10.0);
                v_inerc = 5.0;
                v_force = 0.60000002;
                scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
                scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
                scene_play_sfx(31);
              }
              if ( !get_elaps_frames() )
              {
                if ( get_frame_time() || get_frame() || get_subseq() != 4 )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 5 )
                  {
                    if ( dir == 1 )
                      play_sfx(4);
                    else
                      play_sfx(5);
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 0.0;
                    addbullet(this, NULL, 849, x, y, dir, -1, t, 3);
                  }
                }
                else
                {
                  set_seq(0);
                  h_inerc = 0.0;
                }
              }
            }
            return;
          case 202:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_411;
            if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            process();
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              char_h_move(9.0);
              v_inerc = 5.0;
              v_force = 0.44999999;
              scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
              scene_add_effect(this, 126, x, y + 110.0, dir, 1);
              scene_play_sfx(31);
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 3 )
              flip_with_force();
            return;
          case 203:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_411:
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
              if ( !get_subseq() )
              {
                if ( !get_frame_time() && get_frame() == 1 )
                {
                  char_h_move(-9.0);
                  v_inerc = 5.0;
                  v_force = 0.44999999;
                  scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
                  scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
                  scene_play_sfx(31);
                }
                if ( !get_subseq() && !get_frame_time() && get_frame() == 9 )
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
              goto LABEL_443;
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
            v137 = 20.0;
            goto LABEL_458;
          case 209:
          case 221:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_443;
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
            v140 = 9.0;
            goto LABEL_477;
          case 210:
          case 222:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_443;
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
            v140 = -9.0;
            goto LABEL_477;
          case 211:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_443;
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
            char_h_move(1.0);
            v137 = 18.5;
            goto LABEL_458;
          case 212:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_443;
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
              v140 = 10.0;
LABEL_477:
              char_h_move(v140);
              v137 = 15.0;
LABEL_458:
              v_inerc = v137;
              v_force = 0.64999998;
              field_49A = 0;
              scene_add_effect(this, 63, x, y, dir, 1);
            }
            return;
          case 214:
            if ( process() )
              goto LABEL_530;
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                scene_play_sfx(31);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
                goto LABEL_530;
            }
            if ( (dY() < 0) | (dY() == 0) )
            {
              if ( (dY() < 0) )
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
                  dash_angle = dash_angle + 1.0;
                else
                  dash_angle = dash_angle + 3.0;
              }
              if ( field_7D4 < 0 )
              {
                if ( weather_id )
                  dash_angle = dash_angle - 1.0;
                else
                  dash_angle = dash_angle - 3.0;
              }
              h_inerc = cos_deg(dash_angle) * field_7DC;
              v_inerc = sin_deg(dash_angle) * field_7DC;
              if ( y > 680.0 && v_inerc > 0.0 )
                v_inerc = 0.0;
              field_7DC = field_7DC + 0.300000011920929;
              if ( field_7DC > 10.0 )
                field_7DC = 10.0;
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
                  goto LABEL_601;
              }
            }
            if ( !char_on_ground_down() )
              return;
            y = getlvl_height();
            goto LABEL_621;
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
            goto LABEL_630;
          case 217:
            if ( process() )
              goto LABEL_633;
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                scene_play_sfx(31);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
                goto LABEL_633;
            }
            field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
            if ( (get_subseq()) == 5 || (get_subseq()) == 6 )
              v_inerc = v_inerc - v_force;
            if ( (get_subseq()) <= 0 || (get_subseq()) >= 5 )
              goto LABEL_2873;
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
            if ( field_7DC > 10.0 )
              field_7DC = 10.0;
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
LABEL_2873:
              if ( char_on_ground_down() )
              {
                y = getlvl_height();
                v_force = 0.0;
LABEL_621:
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
LABEL_601:
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
              set_seq(10);
              goto LABEL_101;
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
              v_inerc = 20.0;
              v_force = 0.64999998;
              field_49A = 0;
              scene_add_effect(this, 63, x, y, dir, 1);
            }
            break;
          case 223:
            sub10func();
            field_49A = 1;
            process();
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              char_h_move(5.5);
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
              if ( dX(dir) <= 0 && ++field_7D0 > 13 || ++field_7D0 > 60 )
                set_seq(204);
            }
            return;
          case 224:
            if ( !(get_subseq()) || (get_subseq()) == 3 )
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
            }
            else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(-10.0);
              v_inerc = 5.0;
              v_force = 0.60000002;
              scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
              scene_play_sfx(31);
            }
            return;
          case 225:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_743;
            if ( get_frame() <= 7 && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            if ( process() )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              char_h_move(-9.0);
              v_inerc = 5.0;
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
              if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
              {
                char_h_move(9.0);
                v_inerc = 5.0;
                v_force = 0.44999999;
                scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
                scene_add_effect(this, 126, x, y + 110.0, dir, 1);
                scene_play_sfx(31);
              }
              if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 3 )
                flip_with_force();
            }
            return;
          default:
            goto LABEL_2869;
        }
      }
      return;
    }
    if ( get_seq() > 500 )
    {
      if ( get_seq() > 770 )
      {
        switch ( get_seq() )
        {
          case 771:
            //if ( color_A < 5u )
            //{
              //color_A = 0;
              x = 640.0;
              y = 200.0;
              dir = 1;
              set_seq(750);
            /*}
            else
            {
              //color_A = color_A - 5;
              if ( process() )
                set_seq(700);
            }*/
            break;
          case 794:
            if ( process() )
              set_seq(700);
            if ( !get_subseq() )
            {
              if ( !get_frame_time() )
              {
                if ( get_frame() == 4 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 1.0;
                  addbullet(this, NULL, 899, x, y, dir, -1, t, 3);
                  t[1] = 0.5;
                  t[2] = 4.0;
                  addbullet(this, NULL, 899, x, y, dir, -1, t, 3);
                  t[2] = 4.0;
                  t[1] = 0.25;
                  addbullet(this, NULL, 899, x, y, dir, -1, t, 3);
                  play_sfx(1);
                }
                if ( !get_frame_time() && get_frame() == 6 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 5.0;
                  addbullet(this, NULL, 899, x, y, dir, 1, t, 3);
                  play_sfx(5);
                }
              }
            }
            break;
          case 795:
            if ( get_subseq() )
              goto LABEL_2861;
            v_inerc = v_inerc - 0.300000011920929;
            if ( !char_on_ground_down() )
              goto LABEL_2861;
            set_subseq(1);
            y = getlvl_height();
            reset_forces();
            scene_play_sfx(30);
            break;
          case 797:
            h_inerc = 2.5;
            if ( get_subseq() != 1 || x < 480.0 )
            {
LABEL_630:
              if ( process() )
                goto LABEL_631;
            }
            else
            {
              x = 480.0;
              reset_forces();
              set_seq(0);
            }
            break;
          case 798:
            h_inerc = 2.5;
            if ( get_subseq() != 1 || x > 800.0 )
            {
LABEL_2861:
              if ( process() )
                set_seq(700);
            }
            else
            {
              x = 800.0;
              reset_forces();
              set_seq(700);
            }
            break;
          default:
LABEL_2869:
            char_c::func10();
            break;
        }
      }
      else if ( get_seq() == 770 )
      {
        if ( process() )
          set_seq(700);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
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
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_56;
            if ( get_subseq() || get_frame_time() || get_frame() != 4 )
              return;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            x = dir;
            v450 = (double)(600 * (char)x) + x;
            goto LABEL_1376;
          case 502:
            if ( get_subseq() == 2 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1413;
            }
            field_18C = 0;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_633;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() != 4 )
              goto LABEL_1410;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            v455 = (double)(300 * (char)dir) + x;
            goto LABEL_1409;
          case 503:
            if ( get_subseq() == 2 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1413:
                y = getlvl_height();
                reset_forces();
                set_subseq(2);
                return;
              }
            }
            field_18C = 0;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_633;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                field_190 = 1;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;\
                v455 = (double)(600 * (char)dir) + x;
LABEL_1409:      
                addbullet(this, NULL, 810, v455, 640.0, dir, 1, t, 3);
                play_sfx(10);
              }
LABEL_1410:
              if ( !get_frame_time() )
              {
                v255 = get_frame() == 7;
                goto LABEL_903;
              }
            }
            return;
          case 505:
            sub10func();
            field_18C = 4;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1440;
            if ( get_subseq() )
              return;
            if ( get_frame() == 2 )
            {
              if ( skills_1[4] >= 2 && get_frame_time() >= 4 )
                goto LABEL_1445;
              if ( skills_1[4] >= 4 && get_frame_time() >= 2 )
                goto LABEL_1445;
            }
            if ( get_frame_time() || get_frame() != 5 )
              return;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            v461 = (double)(100 * (char)dir) + x;
            goto LABEL_1451;
          case 506:
            sub10func();
            field_18C = 4;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1440;
            if ( !get_subseq() )
            {
              if ( get_frame() == 2 )
              {
                if ( skills_1[4] >= 2 && get_frame_time() >= 10 )
                  next_frame();
                if ( skills_1[4] >= 4 && get_frame_time() >= 8 )
                  next_frame();
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 3 )
                  h_inerc = 20.0;
                if ( !get_frame_time() && get_frame() == 5 )
                {
                  h_inerc = 0.0;
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  v461 = (double)(100 * (char)dir) + x;
LABEL_1451:
                  addbullet(this, NULL, 811, v461, y + 145.0, dir, 1, t, 3);
                  play_sfx(17);
                }
              }
            }
            return;
          case 510:
            sub10func();
            field_18C = 8;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_631;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1489;
            if ( get_frame() == 4 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(40 * (char)dir), y + 158.0, dir, 1);
              return;
            }
            if ( get_frame() == 5 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 812, (double)(200 * (char)dir) + x, y + 120.0, dir, 1, t, 3);
              play_sfx(21);
            }
LABEL_1489:
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 4.0;
            a4c = y + 120.0;
            v475 = (double)(200 * dir) + x;
            goto LABEL_1493;
          case 511:
            sub10func();
            field_18C = 8;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_631;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1509;
            if ( get_frame() == 4 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(40 * (char)dir), y + 158.0, dir, 1);
            }
            else
            {
              if ( get_frame() == 5 )
              {
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 812, (double)(400 * (char)dir) + x, y + 360.0, dir, 1, t, 3);
                play_sfx(21);
              }
LABEL_1509:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
              {
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 4.0;
                a4c = y + 360.0;
                v475 = (double)(400 * dir) + x;
LABEL_1493:
                addbullet(this, NULL, 812, v475, a4c, dir, 1, t, 3);
                play_sfx(21);
              }
            }
            return;
          case 512:
            if ( get_subseq() == 2 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1532;
            }
            field_18C = 8;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_633;
            if ( !get_subseq() )
            {
              if ( !get_frame_time() )
              {
                if ( get_frame() == 4 && not_charge_attack )
                {
                  next_subseq();
                  scene_add_effect(this, 62, x - (double)(40 * (char)dir), y + 158.0, dir, 1);
                  return;
                }
                if ( get_frame() == 5 )
                {
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 812, (double)(200 * (char)dir) + x, y + 120.0, dir, 1, t, 3);
                  play_sfx(21);
                }
              }
              if ( !get_frame_time() && get_frame() == 8 )
                v_force = 0.5;
            }
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() != 2 )
              goto LABEL_1543;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 4.0;
            a4d = y + 120.0;
            v497 = (double)(200 * dir) + x;
            goto LABEL_1542;
          case 513:
            if ( get_subseq() == 2 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1532:
                reset_forces();
                y = getlvl_height();
                set_subseq(2);
                return;
              }
            }
            field_18C = 8;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_633;
            if ( get_subseq() )
              goto LABEL_1569;
            if ( get_frame_time() )
              goto LABEL_1566;
            if ( get_frame() == 4 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(40 * (char)dir), y + 158.0, dir, 1);
            }
            else
            {
              if ( get_frame() == 5 )
              {
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 812, (double)(400 * (char)dir) + x, y + 360.0, dir, 1, t, 3);
                play_sfx(21);
              }
LABEL_1566:
              if ( !get_frame_time() && get_frame() == 8 )
                v_force = 0.5;
LABEL_1569:
              if ( get_subseq() == 1 && !get_frame_time() )
              {
                if ( get_frame() == 2 )
                {
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 4.0;
                  a4d = y + 360.0;
                  v497 = (double)(400 * dir) + x;
LABEL_1542:
                  addbullet(this, NULL, 812, v497, a4d, dir, 1, t, 3);
                  play_sfx(21);
                }
LABEL_1543:
                if ( !get_frame_time() )
                {
                  v255 = get_frame() == 5;
                  goto LABEL_903;
                }
              }
            }
            return;
          case 520:
            if ( !get_subseq() || get_subseq() == 4 )
              sub10func();
            field_18C = 1;
            if ( get_subseq() >= 1 && get_subseq() <= 3 && 0.0 != v_force )
            {
              v_inerc = v_inerc - v_force;
              if ( get_subseq() == 1 )
              {
                if ( !(get_elaps_frames() % 12) )
                  scene_play_sfx(29);
                angZ = angZ - 40.0;
                if ( v_inerc < 10.0 )
                  v_inerc = 10.0;
                if ( field_190 )
                {
                  if ( ++field_7D0 >= 6 || skills_1[1] >= 3 && ++field_7D0 >= 5 )
                  {
                    field_190 = 0;
                    field_7D0 = 0;
                  }
                }
              }
              if ( char_on_ground_down() )
              {
                reset_ofs();
                y = getlvl_height();
                reset_forces();
                set_subseq(4);
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
                x_off = 0.0;
                y_off = 135.0;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                if ( skills_1[1] >= 3 )
                  t[2] = 2.0;
                addbullet(this, NULL, 815, x, y + 135.0, dir, 1, t, 3);
                v_inerc = 20.0;
                v_force = 0.75;
                play_sfx(12);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                reset_ofs();
            }
            return;
          case 521:
            sub10func();
            field_18C = 1;
            if ( get_subseq() == 1 || get_subseq() == 2 )
            {
              if ( !(get_elaps_frames() % 12) )
                scene_play_sfx(29);
              angZ = angZ - 40.0;
              if ( field_190 )
              {
                if ( get_subseq() == 1 && ++field_7D0 >= 6 )
                {
                  field_190 = 0;
                  field_7D0 = 0;
                }
              }
            }
            h_inerc = h_inerc - 0.75;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 815, x, y + 135.0, dir, 1, t, 3);
              x_off = 0.0;
              y_off = 135.0;
              h_inerc = 20.0;
              play_sfx(12);
            }
            if ( get_subseq() == 2 )
            {
              if ( skills_1[1] >= 1 && get_frame_time() >= 20 - skills_1[1] )
                next_subseq();
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              reset_ofs();
            return;
          case 522:
            if ( get_subseq() == 5 )
              sub10func();
            field_18C = 1;
            if ( get_subseq() < 5 )
            {
              if ( get_subseq() == 4 )
              {
                v_force = 0.60000002;
                v_inerc = v_inerc - 0.6000000238418579;
              }
              if ( getlvl_height() >= v_inerc + y && v_inerc < 0.0 )
                goto LABEL_1638;
            }
            if ( get_subseq() != 3 || get_elaps_frames() )
              goto LABEL_1643;
            spell_energy_spend(200, 120);
            field_190 = 1;
            add_card_energy(50);
            t[0] = 0.0;
            t[1] = 12.0;
            t[2] = 0.0;
            addbullet(this, NULL, 802, (double)(43 * (char)dir) + x, y + 107.0, dir, 1, t, 3);
            t[0] = atan2_deg(135.0, 135.0);
            t[1] = sqrt(37825.0) / 15.0;
            t[2] = 2.0;
            addbullet(this, NULL, 802, (double)(43 * (char)dir) + x, y + 107.0, dir, 1, t, 3);
            t[0] = atan2_deg(-135.0, 135.0);
            t[1] = sqrt(37825.0) / 15.0;
            addbullet(this, NULL, 802, (double)(43 * (char)dir) + x, y + 107.0, dir, 1, t, 3);
            t[0] = atan2_deg(-115.0, 225.0);
            t[1] = sqrt(65025.0) / 15.0;
            addbullet(this, NULL, 802, (double)(43 * (char)dir) + x, y + 107.0, dir, 1, t, 3);
            t[0] = atan2_deg(115.0, 225.0);
            t[1] = sqrt(65025.0) / 15.0;
            a4e = y + 107.0;
            v539 = (double)(43 * (char)dir) + x;
            goto LABEL_1642;
          case 523:
            if ( get_subseq() == 5 )
              sub10func();
            field_18C = 1;
            if ( get_subseq() < 5 )
            {
              if ( get_subseq() == 4 )
              {
                v_force = 0.60000002;
                v_inerc = v_inerc - 0.6000000238418579;
              }
              if ( getlvl_height() >= (v_inerc + y) && v_inerc < 0.0 )
              {
LABEL_1638:
                reset_forces();
                y = getlvl_height();
                set_subseq(5);
                return;
              }
            }
            if ( get_subseq() == 3 && !get_elaps_frames() )
            {
              spell_energy_spend(200, 120);
              field_190 = 1;
              add_card_energy(50);
              t[0] = 0.0;
              t[1] = 25.0;
              t[2] = 0.0;
              addbullet(this, NULL, 802, (double)(43 * (char)dir) + x, y + 107.0, dir, 1, t, 3);
              t[0] = atan2_deg(135.0, 330.0);
              t[1] = sqrt(128500.0) / 15.0;
              t[2] = 2.0;
              addbullet(this, NULL, 802, (double)(43 * (char)dir) + x, y + 107.0, dir, 1, t, 3);
              t[0] = atan2_deg(-135.0, 330.0);
              t[1] = sqrt(128500.0) / 15.0;
              addbullet(this, NULL, 802, (double)(43 * (char)dir) + x, y + 107.0, dir, 1, t, 3);
              t[0] = atan2_deg(-115.0, 420.0);
              t[1] = sqrt(190800.0) / 15.0;
              addbullet(this, NULL, 802, (double)(43 * (char)dir) + x, y + 107.0, dir, 1, t, 3);
              t[0] = atan2_deg(115.0, 420.0);
              t[1] = sqrt(190800.0) / 15.0;
              a4e = y + 107.0;
              v539 = (double)(43 * (char)dir) + x;
LABEL_1642:
              addbullet(this, NULL, 802, v539, a4e, dir, 1, t, 3);
            }
LABEL_1643:
            if ( process() )
              set_seq(0);
            if ( !(get_elaps_frames()) && !get_frame_time() && !get_frame() && get_subseq() == 5 )
              goto LABEL_633;
            if ( get_subseq() == 1 && get_elaps_frames() > 0 )
              next_subseq();
            return;
          case 525:
            sub10func();
            field_18C = 5;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_1670;
            angZ = angZ - 40.0;
            if ( field_7D0 >= 10 && !not_charge_attack || field_7D0 >= 120 )
              goto LABEL_1668;
            field_7D0 = field_7D0 + 1;
LABEL_1670:
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 || field_7D0 )
              goto LABEL_1681;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            t[0] = 0.0;
            t[1] = 15.0;
            t[2] = 0.0;
            if ( skills_1[5] >= 4 )
              t[2] = 2.0;
            v566 = y + 135.0;
            goto LABEL_1680;
          case 526:
            sub10func();
            field_18C = 5;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_1693;
            angZ = angZ - 40.0;
            if ( field_7D0 >= 10 && !not_charge_attack || field_7D0 >= 120 )
              goto LABEL_1691;
            field_7D0 = field_7D0 + 1;
LABEL_1693:
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_7D0 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              t[0] = -30.0;
              t[1] = 15.0;
              t[2] = 0.0;
              if ( skills_1[5] >= 4 )
                t[2] = 2.0;
              v566 = y + 135.0;
LABEL_1680:
              addbullet(this, NULL, 816, x, v566, dir, 1, t, 3);
              x_off = 0.0;
              y_off = 135.0;
              play_sfx(12);
            }
LABEL_1681:
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 8 )
            {
              play_sfx(18);
              field_190 = 1;
            }
            return;
          case 527:
            if ( get_subseq() == 3 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_subseq(3);
                reset_forces();
                y = getlvl_height();
                angZ = 0.0;
                return;
              }
            }
            field_18C = 5;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 )
            {
              angZ = angZ - 40.0;
              if ( field_7D0 >= 10 && !not_charge_attack || field_7D0 >= 120 )
              {
LABEL_1668:
                next_subseq();
                angZ = 0.0;
                return;
              }
              field_7D0 = field_7D0 + 1;
            }
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_1726;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              goto LABEL_633;
            if ( get_frame_time() || get_frame() || get_subseq() != 1 || field_7D0 )
              goto LABEL_1726;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            t[0] = 45.0;
            t[1] = 15.0;
            t[2] = 0.0;
            if ( skills_1[5] >= 4 )
              t[2] = 2.0;
            v572 = y + 135.0;
            goto LABEL_1725;
          case 528:
            if ( get_subseq() == 3 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_subseq(3);
                reset_forces();
                y = getlvl_height();
                angZ = 0.0;
                return;
              }
            }
            field_18C = 5;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 )
            {
              angZ = angZ - 40.0;
              if ( field_7D0 >= 10 && !not_charge_attack || field_7D0 >= 120 )
              {
LABEL_1691:
                next_subseq();
                angZ = 0.0;
                return;
              }
              field_7D0 = field_7D0 + 1;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
LABEL_530:
                set_seq(9);
                return;
              }
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_7D0 )
              {
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = 30.0;
                t[1] = 15.0;
                t[2] = 0.0;
                if ( skills_1[5] >= 4 )
                  t[2] = 2.0;
                v572 = y + 135.0;
LABEL_1725:
                addbullet(this, NULL, 816, x, v572, dir, 1, t, 3);
                x_off = 0.0;
                y_off = 135.0;
                play_sfx(12);
              }
            }
LABEL_1726:
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 7 )
            {
              play_sfx(18);
              field_190 = 1;
              v_force = 0.5;
              v_inerc = 10.0;
              h_inerc = -6.0;
            }
            return;
          case 530:
            sub10func();
            field_18C = 9;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_subseq() )
              return;
            if ( get_frame() == 2 )
            {
              if ( skills_1[9] >= 4 && get_frame_time() >= 10 )
                goto LABEL_1445;
              if ( skills_1[9] >= 3 && get_frame_time() >= 13 || skills_1[9] >= 2 && get_frame_time() >= 15 )
                goto LABEL_1445;
            }
            if ( !get_frame_time() && get_frame() == 5 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 817, (double)(dir == -1) * 1280.0, y + 100.0, dir, 1, t, 3);
              /*
              v1004 = 0.0;
              do
              {
                v1064 = (double)scene_rand_rng(40) + v1004 * 36.0 - 20.0;
                v1065 = (double)scene_rand_rng(8) + 40.0;
                v1066 = 4.0;
                v582 = -v1064;
                v583 = sin_deg(v582) > 0.0;
                addbullet(this, NULL, 810, x, y, dir, (1 - 2 * v583), (int)&v1064, 3);
                v1004 = v1004 + 1.0;
              }
              while ( v1004 < 10.0 );*/
              field_7D0 = 1;
              play_sfx(24);
            }
            return;
          case 531:
            sub10func();
            field_18C = 9;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() )
            {
              if ( !get_frame_time() && get_frame() == 2 )
              {
                scene_play_sfx(72);
                scene_add_effect(this, 138, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              }
              if ( get_frame() == 2 && (((char)skills_1[9] >= 4) && get_frame_time() >= 30 || (char)skills_1[9] >= 3 && get_frame_time() >= 40 || (char)skills_1[9] >= 2 && get_frame_time() >= 50) )
              {
LABEL_1445:
                next_frame();
              }
              else if ( !get_frame_time() && get_frame() == 5 )
              {
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 817, (double)(dir == -1) * 1280.0, y + 100.0, dir, 1, t, 3);
                /*v1005 = 0.0;
                do
                {
                  v1070 = (double)scene_rand_rng(40) + v1005 * 36.0 - 20.0;
                  v1071 = (double)scene_rand_rng(8) + 40.0;
                  v1072 = 4.0;
                  v595 = -v1070;
                  v596 = sin_deg(v595) > 0.0;
                  addbullet(this, NULL, 810, x, y, dir, (1 - 2 * v596), (int)&v1070, 3);
                  v1005 = v1005 + 1.0;
                }
                while ( v1005 < 10.0 );*/
                play_sfx(24);
              }
            }
            return;
          case 540:
            sub10func();
            field_18C = 2;
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 7 )
            {
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(25);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              if ( skills_1[2] >= 2 )
                t[2] = 9.0;
              addbullet(this, NULL, 820, (double)(65 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
              play_sfx(13);
            }
            return;
          case 541:
            sub10func();
            field_18C = 2;
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 7 )
            {
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(25);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 3.0;
              addbullet(this, NULL, 820, (double)(65 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
              play_sfx(14);
            }
            return;
          case 542:
            if ( get_subseq() == 1 )
              sub10func();
            field_18C = 2;
            if ( !get_subseq() )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1809;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_633;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() != 7 )
              goto LABEL_1823;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(25);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            if ( skills_1[2] >= 2 )
              t[2] = 9.0;
            addbullet(this, NULL, 820, (double)(65 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
            goto LABEL_1822;
          case 543:
            if ( get_subseq() == 1 )
              sub10func();
            field_18C = 2;
            if ( !get_subseq() )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1809;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_633;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() == 7 )
            {
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(25);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 3.0;
              addbullet(this, NULL, 820, (double)(65 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
              play_sfx(14);
            }
            if ( get_frame_time() )
              return;
            v255 = get_frame() == 14;
            goto LABEL_903;
          case 545:
            sub10func();
            field_18C = 6;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 && not_charge_attack )
              {
                next_subseq();
                scene_add_effect(this, 62, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              }
              if ( !get_frame_time() && get_frame() == 7 )
              {
                field_190 = 1;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                ++field_8A8;
                t[0] = 0.0;
                t[1] = (double)field_8A8;
                t[2] = 0.0;
                addbullet(this, NULL, 821, (double)(65 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                play_sfx(19);
              }
            }
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            ++field_8A8;
            t[0] = 0.0;
            t[1] = (double)field_8A8;
            t[2] = 0.0;
            a4f = y + 100.0;
            v624 = (double)(215 * dir) + x;
            goto LABEL_1862;
          case 546:
            sub10func();
            field_18C = 6;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 && not_charge_attack )
              {
                next_subseq();
                scene_add_effect(this, 62, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              }
              if ( !get_frame_time() && get_frame() == 7 )
              {
                field_190 = 1;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                ++field_8A8;
                t[0] = 0.0;
                t[1] = (double)field_8A8;
                t[2] = 0.0;
                addbullet(this, NULL, 821, (double)(365 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                play_sfx(19);
              }
            }
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
            {
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              ++field_8A8;
              t[0] = 0.0;
              t[1] = (double)field_8A8;
              t[2] = 0.0;
              a4f = y + 100.0;
              v624 = (double)(515 * (char)dir) + x;
LABEL_1862:
              addbullet(this, NULL, 821, v624, a4f, dir, 1, t, 3);
              play_sfx(19);
            }
            return;
          case 547:
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 6;
            if ( get_subseq() < 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                y = getlvl_height();
                set_subseq(2);
                reset_forces();
                return;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                set_seq(9);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                set_seq(9);
            }
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 && not_charge_attack )
              {
                next_subseq();
                scene_add_effect(this, 62, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 7 )
                {
                  field_190 = 1;
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  ++field_8A8;
                  t[0] = 0.0;
                  t[1] = (double)field_8A8;
                  t[2] = 0.0;
                  addbullet(this, NULL, 821, (double)(65 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                  play_sfx(19);
                }
                if ( !get_frame_time() && get_frame() == 14 )
                  v_force = 0.5;
              }
            }
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() != 2 )
              goto LABEL_1919;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            ++field_8A8;
            t[0] = 0.0;
            t[1] = (double)field_8A8;
            t[2] = 0.0;
            a4g = y + 100.0;
            v648 = (double)(215 * dir) + x;
            goto LABEL_1918;
          case 548:
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 6;
            if ( get_subseq() < 2 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
            {
              y = getlvl_height();
              set_subseq(2);
              reset_forces();
            }
            else
            {
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  set_seq(9);
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                  set_seq(9);
              }
              if ( !get_subseq() && !get_frame_time() )
              {
                if ( get_frame() == 6 && not_charge_attack )
                {
                  next_subseq();
                  scene_add_effect(this, 62, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 7 )
                  {
                    field_190 = 1;
                    spell_energy_spend(200, 120);
                    add_card_energy(50);
                    ++field_8A8;
                    t[0] = 0.0;
                    t[1] = (double)field_8A8;
                    t[2] = 0.0;
                    addbullet(this, NULL, 821, (double)(365 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                    play_sfx(19);
                  }
                  if ( !get_frame_time() && get_frame() == 14 )
                    v_force = 0.5;
                }
              }
              if ( get_subseq() == 1 && !get_frame_time() )
              {
                if ( get_frame() == 2 )
                {
                  field_190 = 1;
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  ++field_8A8;
                  t[0] = 0.0;
                  t[1] = (double)field_8A8;
                  t[2] = 0.0;
                  a4g = y + 100.0;
                  v648 = (double)(515 * (char)dir) + x;
LABEL_1918:
                  addbullet(this, NULL, 821, v648, a4g, dir, 1, t, 3);
                  play_sfx(19);
                }
LABEL_1919:
                if ( !get_frame_time() )
                {
                  v255 = get_frame() == 9;
                  goto LABEL_903;
                }
              }
            }
            return;
          case 550:
            sub10func();
            field_18C = 10;
            if ( process() )
              set_seq(0);
            if ( get_frame_time() || get_frame() != 7 )
              return;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(25);
            tt[0] = 0.0;
            tt[1] = 0.0;
            tt[2] = 0.0;
            tt[3] = 0.0;
            a4h = y + 100.0;
            v663 = (double)(65 * (char)dir) + x;
            goto LABEL_1960;
          case 551:
            sub10func();
            field_18C = 10;
            if ( process() )
              set_seq(0);
            if ( get_frame_time() || get_frame() != 7 )
              return;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(25);
            tt[0] = 0.0;
            tt[1] = 0.0;
            tt[2] = 0.0;
            tt[3] = 1.0;
            a4h = y + 100.0;
            v663 = (double)(65 * (char)dir) + x;
LABEL_1960:
            addbullet(this, NULL, 822, v663, a4h, dir, 1, tt, 4);
            goto LABEL_1961;
          case 552:
            if ( get_subseq() == 1 )
              sub10func();
            field_18C = 10;
            if ( !get_subseq() )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1809;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_633;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() != 7 )
              goto LABEL_1823;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(25);
            tt[0] = 0.0;
            tt[1] = 0.0;
            tt[2] = 0.0;
            tt[3] = 0.0;
            addbullet(this, NULL, 822, (double)(65 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
            goto LABEL_1822;
          case 553:
            if ( get_subseq() == 1 )
              sub10func();
            field_18C = 10;
            if ( !get_subseq() )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1809:
                y = getlvl_height();
                next_subseq();
                reset_forces();
                return;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_633;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() == 7 )
            {
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(25);
              tt[0] = 0.0;
              tt[1] = 0.0;
              tt[2] = 0.0;
              tt[3] = 1.0;
              addbullet(this, NULL, 822, (double)(65 * (char)dir) + x, y + 100.0, dir, 1, tt, 4);
LABEL_1822:
              play_sfx(13);
            }
LABEL_1823:
            if ( get_frame_time() )
              return;
            v255 = get_frame() == 14;
            goto LABEL_903;
          case 560:
            if ( get_subseq() > 0 )
              sub10func();
            field_18C = 3;
            if ( get_subseq() )
            {
              h_inerc = h_inerc - 0.300000011920929;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            else if ( get_frame() >= 5 )
            {
              x_off = 0.0;
              y_off = 100.0;
              scaleX = scaleX * 0.800000011920929;
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 36 )
              next_subseq();
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                play_sfx(15);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 825, x, y + 100.0, dir, -1, t, 3);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 5 )
                {
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                }
                if ( !get_frame_time() && get_frame() == 7 )
                {
                  if ( dX(dir) > 0 )
                    x = (double)(450 * dir) + x;
                  if ( dX(dir) < 0 )
                    x = x - (double)(300 * dir);
                  if ( !keyDown(INP_X_AXIS) /*down_X*/ )
                    x = (double)(250 * dir) + x;
                  if ( x > 980.0 && dir == 1 )
                    x = 980.0;
                  if ( x < 200.0 && dir == -1 )
                    x = 200.0;
                  y = getlvl_height();
                }
              }
            }
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 && field_7D0 == 1 )
            {
              field_194 = 1;
              ++field_7D0;
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            if ( field_7D0 )
              goto LABEL_2041;
            play_sfx(16);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 1.0;
            a4i = y + 100.0;
            v681 = (double)(70 * dir) + x;
            goto LABEL_2040;
          case 561:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 3;
            if ( !get_subseq() && get_frame() >= 5 )
            {
              x_off = 0.0;
              y_off = 100.0;
              scaleX = scaleX * 0.800000011920929;
            }
            if ( get_subseq() == 1 )
            {
              x_off = 0.0;
              y_off = 100.0;
              angZ = angZ - 35.0;
              if ( char_on_ground_down() )
              {
                angZ = 0.0;
                y = getlvl_height();
                v_inerc = 0.0;
                next_subseq();
              }
            }
            if ( get_subseq() == 2 && 0.0 != h_inerc )
            {
              h_inerc = h_inerc * 0.800000011920929;
              if ( fabs(h_inerc) < 0.0099999998 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( get_subseq() || get_frame_time() )
              goto LABEL_2071;
            if ( get_frame() == 2 )
            {
              play_sfx(15);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 825, x, y + 100.0, dir, -1, t, 3);
            }
            if ( get_frame_time() )
              goto LABEL_2071;
            if ( get_frame() == 5 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( get_frame_time() || get_frame() != 7 )
              goto LABEL_2071;
            if ( dX(dir) <= 0 )
            {
              if ( dX(dir) >= 0 )
                goto LABEL_2070;
              v688 = -1.0;
            }
            else
            {
              v688 = 1.0;
            }
            dash_angle = v688;
LABEL_2070:
            y = getlvl_height() + 600.0;
LABEL_2071:
            if ( get_subseq() == 1 && get_elaps_frames() == 6 )
            {
              field_194 = 1;
              ++field_7D0;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              if ( !field_7D0 )
              {
                play_sfx(16);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 2.0;
                addbullet(this, NULL, 825, x, y, dir, -1, t, 3);
                ;
                scaleX = 1.0;
                h_inerc = 0.0;
                v_inerc = -25.0;
                h_inerc = dash_angle * 25.0;
                field_51C = 6;
                field_520 = 6;
              }
              ++field_7D0;
            }
            if ( get_subseq() != 2 )
              return;
            if ( (skills_1[3] < 1 || get_frame_time() < 11) && (skills_1[3] < 2 || get_frame_time() < 9) )
              goto LABEL_2086;
            goto LABEL_2088;
          case 562:
            if ( get_subseq() > 0 )
              sub10func();
            field_18C = 3;
            if ( get_subseq() )
            {
              h_inerc = h_inerc - 0.300000011920929;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            else if ( get_frame() >= 5 )
            {
              x_off = 0.0;
              y_off = 100.0;
              scaleX = scaleX * 0.800000011920929;
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 36 )
              next_subseq();
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                play_sfx(15);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 825, x, y + 100.0, dir, -1, t, 3);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 5 )
                {
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                }
                if ( !get_frame_time() && get_frame() == 7 )
                {
                  if ( dX(dir) > 0 )
                    x = (double)(450 * dir) + x;
                  if ( dX(dir) < 0 )
                    x = x - (double)(300 * dir);
                  if ( !dX(dir) )
                    x = (double)(250 * dir) + x;
                  if ( x > 980.0 && dir == 1 )
                    x = 980.0;
                  if ( x < 200.0 && dir == -1 )
                    x = 200.0;
                  y = getlvl_height();
                }
              }
            }
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 && field_7D0 == 1 )
            {
              field_194 = 1;
              ++field_7D0;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              if ( !field_7D0 )
              {
                play_sfx(16);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                a4i = y + 100.0;
                v681 = (double)(70 * dir) + x;
LABEL_2040:
                addbullet(this, NULL, 825, v681, a4i, dir, -1, t, 3);
                ;
                scaleX = 1.0;
                h_inerc = 20.0;
                field_51C = 6;
                field_520 = 6;
              }
LABEL_2041:
              ++field_7D0;
            }
            return;
          case 563:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 3;
            if ( !get_subseq() && get_frame() >= 5 )
            {
              x_off = 0.0;
              y_off = 100.0;
              scaleX = scaleX * 0.800000011920929;
            }
            if ( get_subseq() == 1 )
            {
              x_off = 0.0;
              y_off = 100.0;
              angZ = angZ - 35.0;
              if ( char_on_ground_down() )
              {
                angZ = 0.0;
                y = getlvl_height();
                v_inerc = 0.0;
                next_subseq();
              }
            }
            if ( get_subseq() == 2 && 0.0 != h_inerc )
            {
              h_inerc = h_inerc * 0.800000011920929;
              if ( fabs(h_inerc) < 0.0099999998 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( get_subseq() || get_frame_time() )
              goto LABEL_2163;
            if ( get_frame() == 2 )
            {
              play_sfx(15);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 825, x, y + 100.0, dir, -1, t, 3);
            }
            if ( get_frame_time() )
              goto LABEL_2163;
            if ( get_frame() == 5 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( get_frame_time() || get_frame() != 7 )
              goto LABEL_2163;
            if ( dX(dir) <= 0 )
            {
              if ( dX(dir) >= 0 )
                goto LABEL_2162;
              v688 = -1.0;
            }
            else
            {
              v688 = 1.0;
            }
            dash_angle = v688;
LABEL_2162:
            y = getlvl_height() + 600.0;
LABEL_2163:
            if ( get_subseq() == 1 && get_elaps_frames() == 6 )
            {
              field_194 = 1;
              ++field_7D0;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              if ( !field_7D0 )
              {
                play_sfx(16);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 2.0;
                addbullet(this, NULL, 825, x, y, dir, -1, t, 3);
                ;
                scaleX = 1.0;
                h_inerc = 0.0;
                v_inerc = -25.0;
                h_inerc = dash_angle * 25.0;
                field_51C = 6;
                field_520 = 6;
              }
              ++field_7D0;
            }
            if ( get_subseq() != 2 )
              return;
            if ( skills_1[3] >= 1 && get_frame_time() >= 11 )
              goto LABEL_2088;
            if ( skills_1[3] < 2 || get_frame_time() < 9 )
            {
LABEL_2086:
              if ( skills_1[3] >= 4 && get_frame_time() >= 7 )
LABEL_2088:
                next_frame();
            }
            else
            {
              next_frame();
            }
            return;
          case 565:
            field_18C = 7;
            if ( get_subseq() == 3 )
              sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( (double)dir * h_inerc > 0.0 && x > 1240.0 )
              x = 1240.0;
            if ( (double)dir * h_inerc < 0.0 && x < 40.0 )
              x = 40.0;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                x_off = 0.0;
                y_off = 135.0;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 6.0;
                addbullet(this, NULL, 826, x, y, dir, -1, t, 3);
                t[1] = 0.5;
                t[2] = 4.0;
                addbullet(this, NULL, 826, x, y, dir, -1, t, 3);
                t[2] = 4.0;
                t[1] = 0.25;
                addbullet(this, NULL, 826, x, y, dir, -1, t, 3);
                play_sfx(1);
                spell_energy_spend(200, 120);
                add_card_energy(50);
              }
              if ( !get_frame_time() && get_frame() == 5 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 5.0;
                addbullet(this, NULL, 826, x, y, dir, 1, t, 3);
                play_sfx(5);
              }
            }
            if ( get_subseq() != 1 )
              goto LABEL_2230;
            if ( !get_frame_time() && !get_frame() )
            {
              //sub_465E50(992);
              //field_154->field_EC = /*chrt->*/y;
              //field_154->field_F8 = 2.0;
              //field_154->field_FC = 2.0;
              //field_154->field_104 = dir;
              field_572 = 0;
              field_571 = 0;
              y = y - 250.0;
            }
            //field_154->field_E8 = x;
            if ( !get_frame() )
            {
              if ( get_frame_time() < 75 )
              {
                if ( dX(dir) > 0 )
                  h_inerc = 6.0;
                if ( dX(dir) < 0 )
                  h_inerc = -6.0;
                if ( !dX(dir) )
                  h_inerc = 0.0;
                v705 = 15;
                if ( skills_1[7] >= 2 )
                  v705 = 12;
                if ( skills_1[7] >= 3 )
                  v705 = 8;
                if ( skills_1[7] >= 4 )
                  v705 = 2;
                //if ( get_frame_time() >= v705 && !not_charge_attack )
                  //get_frame_time() = 75;
              }
              if ( get_frame_time() == 75 )
                h_inerc = 0.0;
              if ( get_frame_time() == 85 )
              {
                t[0] = 0.0;
                t[1] = 0.5;
                t[2] = 4.0;
                addbullet(this, NULL, 826, x, y, dir, -1, t, 3);
                t[2] = 4.0;
                t[1] = 0.25;
                addbullet(this, NULL, 826, x, y, dir, -1, t, 3);
                t[0] = 0.0;
                t[1] = 0.5;
                t[2] = 0.0;
                addbullet(this, NULL, 826, x, y + 130.0, dir, 1, t, 3);
                play_sfx(1);
                next_frame();
                return;
              }
            }
            if ( get_frame() == 1 )
            {
              angZ = angZ - 40.0;
              y = y + 20.0;
              if ( y > -115.0 )
                y = -115.0;
              if ( field_190 )
              {
                if ( ++field_7D0 >= 6 )
                {
                  field_190 = 0;
                  field_7D0 = 0;
                }
              }
            }
LABEL_2230:
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2235;
            if ( get_subseq() == 2 )
            {
              v_force = 1.25;
              v_inerc = 25.0;
              field_194 = 1;
              field_190 = 0;
LABEL_2235:
              if ( get_subseq() == 2 )
              {
                v_inerc = v_inerc - v_force;
                if ( v_inerc < 0.0 )
                  //sub_5586E0();
                if ( !(get_elaps_frames() % 12) )
                  scene_play_sfx(29);
                angZ = angZ - 40.0;
                if ( field_190 )
                {
                  if ( ++field_7D0 >= 6 )
                  {
                    field_190 = 0;
                    field_7D0 = 0;
                  }
                }
                if ( char_on_ground_down() )
                {
                  field_572 = 1;
                  field_571 = 1;
LABEL_2245:
                  reset_ofs();
                  y = getlvl_height();
                  reset_forces();
                  next_subseq();
                }
              }
            }
            return;
          case 566:
            field_18C = 7;
            if ( get_subseq() == 3 )
              sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( (double)dir * h_inerc > 0.0 && x > 1240.0 )
              x = 1240.0;
            if ( (double)dir * h_inerc < 0.0 && x < 40.0 )
              x = 40.0;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                x_off = 0.0;
                y_off = 135.0;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 6.0;
                addbullet(this, NULL, 826, x, y, dir, -1, t, 3);
                t[1] = 0.5;
                t[2] = 4.0;
                addbullet(this, NULL, 826, x, y, dir, -1, t, 3);
                t[2] = 4.0;
                t[1] = 0.25;
                addbullet(this, NULL, 826, x, y, dir, -1, t, 3);
                play_sfx(1);
                spell_energy_spend(200, 120);
                add_card_energy(50);
              }
              if ( !get_frame_time() && get_frame() == 5 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 5.0;
                addbullet(this, NULL, 826, x, y, dir, 1, t, 3);
                play_sfx(5);
              }
            }
            if ( get_subseq() == 1 )
            {
              if ( !get_frame_time() )
              {
                if ( !get_frame() )
                {
                  //sub_465E50(992);
                  //field_154->field_EC = /*chrt->*/y;
                  //field_154->field_F8 = 2.0;
                  //field_154->field_FC = 2.0;
                  //field_154->field_104 = dir;
                  field_572 = 0;
                  field_571 = 0;
                  y = y - 250.0;
                }
                if ( !get_frame_time() && get_frame() == 1 )
                {
                  x = enemy->x;
                  y = enemy->getlvl_height() - 290.0;
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 6.0;
                  addbullet(this, NULL, 826, x, getlvl_height(), dir, -1, t, 3);
                }
              }
              //field_154->field_E8 = x;
              if ( get_frame() == 1 )
              {
                v705 = 20;
                if ( skills_1[7] >= 2 )
                  v705 = 16;
                if ( skills_1[7] >= 3 )
                  v705 = 12;
                if ( skills_1[7] >= 4 )
                  v705 = 5;
                if ( get_frame_time() >= v705 )
                {
                  next_subseq();
                }
              }
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
              t[0] = 0.0;
              t[1] = 0.5;
              t[2] = 0.0;
              addbullet(this, NULL, 826, x, y + 130.0, dir, 1, t, 3);
              v_force = 0.85000002;
              v_inerc = 35.0;
              h_inerc = 0.0;
              field_194 = 1;
              field_190 = 0;
            }
            if ( get_subseq() == 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( getlvl_height() < y )
              {
                field_572 = 1;
                field_571 = 1;
              }
              if ( v_inerc < 0.0 )
              {
                //sub_5586E0();
                if ( !get_frame() )
                  next_frame();
              }
              if ( !(get_elaps_frames() % 12) )
                scene_play_sfx(29);
              angZ = angZ - 40.0;
              if ( field_190 )
              {
                if ( ++field_7D0 >= 6 )
                {
                  field_194 = 1;
                  field_190 = 0;
                  field_7D0 = 0;
                }
              }
              if ( char_on_ground_down() )
                goto LABEL_2245;
            }
            return;
          case 570:
            sub10func();
            field_18C = 11;
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 7 )
            {
              field_190 = 1;
              spell_energy_spend(200, 60);
              add_card_energy(25);
              /* *(&field_8B8 + field_8B4) */
              /* *(&field_8C4 + field_8B4++) */
              field_8B8 = x;
              field_8B4 = x;
              field_8C4 = y;
              field_8B4 = y++;
              if ( field_8B4 > 3 )
                field_8B4 = 3;
              tt[0] = 0.0;
              tt[1] = 0.0;
              tt[2] = 0.0;
              tt[3] = (double)field_8B4;
              addbullet(this, NULL, 827, x, y + 228.0, dir, -1, tt, 4);
LABEL_1961:
              play_sfx(13);
            }
            return;
          case 571:
            field_18C = 11;
            if ( process() )
              goto LABEL_2307;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(15);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 3.0;
              addbullet(this, NULL, 827, x, y, dir, -1, t, 3);
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            if ( --field_8B4 < 0 )
              field_8B4 = 0;
            goto LABEL_2320;
          case 572:
            field_18C = 11;
            if ( get_subseq() )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                reset_forces();
LABEL_383:
                y = getlvl_height();
                set_subseq(v2);
                return;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( get_frame_time() )
                return;
              if ( !get_frame() && get_subseq() == 1 )
                set_seq(9);
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 7 )
              {
                field_190 = 1;
                spell_energy_spend(200, 60);
                add_card_energy(25);
                /* *(&field_8B8 + field_8B4)  = x;*/
                /* *(&field_8C4 + field_8B4++)  = y;*/
                field_8B8 = x;
                field_8B4 = x;
                field_8C4 = y;
                field_8B4 = y++;
                if ( field_8B4 > 3 )
                  field_8B4 = 3;
                tt[0] = 0.0;
                tt[1] = 0.0;
                tt[2] = 0.0;
                tt[3] = (double)field_8B4;
                addbullet(this, NULL, 827, x, y + 228.0, dir, -1, tt, 4);
                play_sfx(13);
              }
              if ( !get_frame_time() )
              {
                v255 = get_frame() == 12;
                goto LABEL_903;
              }
            }
            return;
          case 573:
            field_18C = 11;
            if ( process() )
            {
LABEL_2307:
              if ( char_on_ground_flag() )
              {
                set_seq(0);
              }
              else
              {
                flip_with_force();
                set_seq(9);
                v_force = 0.5;
              }
            }
            else
            {
              if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
              {
                spell_energy_spend(200, 120);
                add_card_energy(50);
                play_sfx(15);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 3.0;
                addbullet(this, NULL, 827, x, y, dir, -1, t, 3);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                if ( --field_8B4 >= 0 )
                {
LABEL_2320:
                  x = field_8B8 + field_8B4;
                  y = field_8C4 + field_8B4;
                  play_sfx(16);
                }
                else
                {
                  field_8B4 = 0;
                  x = field_8B8;
                  y = field_8C4 + field_8B4;
                  play_sfx(16);
                }
              }
            }
            return;
          case 600:
            sub10func();
            sub_46AB50(2, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(55 * (char)dir), y + 122.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 4 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 850, (double)(150 * (char)dir) + x, y + 145.0, dir, 1, t, 3);
                play_sfx(50);
              }
            }
            return;
          case 601:
            sub10func();
            sub_46AB50(2, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x, y + 100.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 4 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 851, (double)(75 * (char)dir) + x, y + 135.0, dir, 1, t, 3);
                play_sfx(51);
              }
            }
            return;
          case 602:
            sub10func();
            sub_46AB50(2, 2);
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_56;
            if ( get_subseq() )
              goto LABEL_2384;
            if ( !get_frame_time() && get_frame() == 2 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(34 * (char)dir) + x, y + 152.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( get_frame_time() )
              goto LABEL_2384;
            if ( get_frame() != 4 || dX(dir) >= 0 )
            {
              if ( get_frame() == 6 )
              {
                t[0] = 0.0;
                t[1] = 14.0;
                t[2] = 0.0;
                addbullet(this, NULL, 852, x, 0.0, dir, 1, t, 3);
                play_sfx(56);
              }
LABEL_2384:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
              {
                t[0] = 0.0;
                t[1] = 14.0;
                t[2] = 0.0;
                addbullet(this, NULL, 852, x, 0.0, -dir, 1, t, 3);
                play_sfx(56);
              }
            }
            else
            {
              next_subseq();
            }
            return;
          case 603:
            sub10func();
            sub_46AB50(2, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(55 * (char)dir), y + 122.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 5 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 853, (double)(150 * (char)dir) + x, y + 145.0, dir, 1, t, 3);
                play_sfx(50);
              }
            }
            return;
          case 604:
            sub10func();
            sub_46AB50(2, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x, y + 100.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 4 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 854, (double)(75 * (char)dir) + x, y + 135.0, dir, 1, t, 3);
                play_sfx(51);
              }
            }
            return;
          case 605:
            sub10func();
            sub_46AB50(2, 2);
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_56;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(34 * (char)dir) + x, y + 152.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                t[0] = 0.0;
                t[1] = 20.0;
                t[2] = 0.0;
                addbullet(this, NULL, 855, (double)(100 * dir) + x, y + 115.0, 1, 1, t, 3);
                t[0] = 90.0;
                addbullet(this, NULL, 855, (double)(100 * dir) + x, y + 115.0, 1, 1, t, 3);
                t[0] = -90.0;
                addbullet(this, NULL, 855, (double)(100 * dir) + x, y + 115.0, 1, 1, t, 3);
                t[0] = 180.0;
                addbullet(this, NULL, 855, (double)(100 * dir) + x, y + 115.0, 1, 1, t, 3);
                play_sfx(56);
              }
            }
            return;
          case 606:
            sub_46AB50(2, 2);
            if ( get_subseq() == 1 && get_elaps_frames() >= 40 )
              goto LABEL_908;
            if ( field_7D0 > 0 )
            {
              if ( !(field_7D0 % 2) && field_7D0 <= 60 )
              {
                play_sfx(21);
                t[0] = 0.0;
                t[1] = field_7DC;
                t[2] = 0.0;
                addbullet(this, NULL, 856, (100.0 - (double)scene_rand_rng(300)) * (double)dir + x, y + 350.0 - (double)scene_rand_rng(400), dir, -1, t, 3);
                field_7DC = field_7DC + 1.0;
              }
              ++field_7D0;
            }
            if ( get_subseq() == 2 && get_elaps_frames() >= 80 )
              goto LABEL_908;
            if ( process() )
              goto LABEL_56;
            if ( get_subseq() || get_frame_time() || get_frame() != 3 )
              return;
            field_4A6 = 40;
            scene_play_sfx(23);
            y = y + 172.0;
            v776 = x - (double)(114 * (char)dir);
            goto LABEL_2433;
          case 607:
            sub10func();
            sub_46AB50(2, 2);
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_56;
            if ( field_7D0 == 1 )
            {
              if ( !(field_7D2 % 5) )
              {
                if ( field_7D4 < 4 )
                {
                  play_sfx(21);
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  if ( field_7D4 )
                  {
                    v980 = (double)scene_rand_rng(640) - 320.0 + enemy->x;
                    if ( v980 <= 1200.0 )
                    {
                      if ( v980 < 80.0 )
                        v980 = 80.0;
                    }
                    else
                    {
                      v980 = 1200.0;
                    }
                    v1006 = (double)scene_rand_rng(480) - 140.0;
                    if ( v1006 >= -50.0 )
                    {
                      if ( v1006 > 680.0 )
                        v1006 = 680.0;
                    }
                    else
                    {
                      v1006 = -50.0;
                    }
                    a4j = v1006;
                    v791 = v980;
                  }
                  else
                  {
                    a4j = enemy->y + 100.0;
                    v791 = enemy->x;
                  }
                  addbullet(this, NULL, 857, v791, a4j, dir, 1, t, 3);
                }
                ++field_7D4;
              }
              ++field_7D2;
            }
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(8 * (char)dir), y + 141.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 5 )
                field_7D0 = 1;
            }
            return;
          case 608:
            sub_46AB50(2, 2);
            if ( get_subseq() == 1 && get_elaps_frames() >= 40 )
              goto LABEL_1273;
            if ( field_7D0 > 0 )
            {
              if ( !(field_7D0 % 5) && field_7D0 <= 60 )
              {
                play_sfx(21);
                t[0] = 0.0;
                t[1] = field_7DC;
                t[2] = 0.0;
                addbullet(this, NULL, 858, (double)scene_rand_rng(1080) + 100.0, (double)scene_rand_rng(480) + 100.0, dir, -1, t, 3);
                field_7DC = field_7DC + 1.0;
              }
              ++field_7D0;
            }
            if ( get_subseq() == 2 && get_elaps_frames() >= 20 )
              goto LABEL_908;
            if ( process() )
              goto LABEL_56;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              y = y + 172.0;
              v776 = x - (double)(114 * (char)dir);
LABEL_2433:
              scene_add_effect(this, 115, v776, y, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              field_7D0 = 1;
            }
            return;
          case 615:
            sub10func();
            sub_46AB50(2, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(43 * (char)dir), y + 150.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 865, x - (double)(150 * (char)dir), 200.0, dir, -2, t, 3);
                play_sfx(53);
              }
            }
            return;
          case 656:
            if ( get_subseq() <= 3 )
              sub_46AB50(2, 2);
            if ( get_subseq() == 5 )
              sub10func();
            if ( get_subseq() == 3 || get_subseq() == 4 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_2441;
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 40 )
              goto LABEL_908;
            if ( field_7D0 > 0 )
            {
              if ( !(field_7D0 % 2) && field_7D0 <= 60 )
              {
                play_sfx(21);
                t[0] = 0.0;
                t[1] = field_7DC;
                t[2] = 0.0;
                addbullet(this, NULL, 856, (100.0 - (double)scene_rand_rng(300)) * (double)dir + x, (y + 350.0) - (double)scene_rand_rng(400), dir, -1, t, 3);
                field_7DC = field_7DC + 1.0;
              }
              ++field_7D0;
            }
            if ( get_subseq() == 2 && get_elaps_frames() >= 80 )
              goto LABEL_908;
            if ( process() )
            {
              set_seq(0);
            }
            else
            {
              if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(114 * (char)dir), y + 172.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
                field_7D0 = 1;
              }
              if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 4 )
                v_force = 0.25;
            }
            return;
          case 657:
            if ( get_subseq() == 1 )
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
                set_subseq(1);
                return;
              }
            }
            sub_46AB50(2, 2);
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_633;
            if ( field_7D0 == 1 )
            {
              if ( !(field_7D2 % 5) )
              {
                if ( field_7D4 < 4 )
                {
                  play_sfx(21);
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  if ( field_7D4 )
                  {
                    v1007 = (double)scene_rand_rng(640) + enemy->x;
                    v800 = v1007;
                    if ( v1007 <= 1200.0 )
                    {
                      if ( v800 < 80.0 )
                        v1007 = 80.0;
                    }
                    else
                    {
                      v1007 = 1200.0;
                    }
                    v981 = (double)scene_rand_rng(480) - 140.0;
                    if ( v981 >= -50.0 )
                    {
                      if ( v981 > 680.0 )
                        v981 = 680.0;
                    }
                    else
                    {
                      v981 = -50.0;
                    }
                    a4k = v981;
                    v799 = v1007;
                  }
                  else
                  {
                    a4k = enemy->y + 100.0;
                    v799 = enemy->x;
                  }
                  addbullet(this, NULL, 857, v799, a4k, dir, 1, t, 3);
                }
                ++field_7D4;
              }
              ++field_7D2;
            }
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(8 * (char)dir), y + 141.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 5 )
                  field_7D0 = 1;
                if ( !get_frame_time() )
                {
                  v255 = get_frame() == 8;
LABEL_903:
                  if ( v255 )
                    v_force = 0.5;
                }
              }
            }
            return;
          case 658:
            if ( get_subseq() <= 3 )
              sub_46AB50(2, 2);
            if ( get_subseq() == 5 )
              sub10func();
            if ( (get_subseq() == 3 || get_subseq() == 4) && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
            {
LABEL_2441:
              move_val = 5;
LABEL_100:
              set_subseq(move_val);
LABEL_101:
              y = getlvl_height();
              reset_forces();
            }
            else
            {
              if ( get_subseq() == 1 && get_elaps_frames() >= 40 )
                goto LABEL_908;
              if ( field_7D0 > 0 )
              {
                if ( !(field_7D0 % 5) && field_7D0 <= 60 )
                {
                  play_sfx(21);
                  t[0] = 0.0;
                  t[1] = field_7DC;
                  t[2] = 0.0;
                  addbullet(this, NULL, 858, (double)scene_rand_rng(1080) + 100.0, (double)scene_rand_rng(480) + 100.0, dir, -1, t, 3);
                  field_7DC = field_7DC + 1.0;
                }
                ++field_7D0;
                v2 = 1;
              }
              if ( get_subseq() == 2 && get_elaps_frames() >= 20 )
              {
LABEL_1273:
                next_subseq();
              }
              else if ( process() )
              {
LABEL_1440:
                set_seq(0);
              }
              else
              {
                if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
                {
                  field_4A6 = 40;
                  scene_play_sfx(23);
                  scene_add_effect(this, 115, x - (double)(114 * (char)dir), y + 172.0, dir, 1);
                  sub_469450(0, 0, 60);
                  sub_483570();
                  weather_forecast_next();
                  field_7D0 = v2;
                }
                if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 4 )
                  v_force = 0.25;
              }
            }
            break;
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
            if ( get_frame() > 1 )
            {
              h_inerc = h_inerc - 2.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                h_inerc = 5.0;
                field_49A = 0;
              }
LABEL_794:
              if ( !get_frame_time() && get_frame() == 4 )
              {
                play_sfx(0);
                field_49A = 0;
              }
            }
            return;
          case 710:
            if ( get_subseq() >= 1 && get_subseq() <= 3 )
            {
              h_inerc = h_inerc * 0.9800000190734863;
              v_inerc = v_inerc - v_force;
              if ( v_inerc < 0.0 && !field_7D0 )
              {
                v_inerc = 0.0;
                field_7D0 = 1;
              }
            }
            if ( get_subseq() != 3 )
              goto LABEL_2652;
            if ( v_inerc < 0.0 )
              v_inerc = 0.0;
            if ( field_7D0 != 1 )
              goto LABEL_2652;
            if ( field_7D2 < 390 )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  if ( !(field_7D2 % 90) )
                  {
                    play_sfx(2);
                    t[1] = 0.0;
                    t[2] = 0.0;
                    v988 = 0.0;
                    v877 = (float)0.0;
                    while ( 1 )
                    {
                      t[0] = v877 * 30.0;
                      if ( field_7D4 % 2 )
                      {
                        xt = -dir;
                      }
                      else
                      {
                        xt = dir;
                      }
                      addbullet(this, NULL, 900, x, 100.0 + y, xt, 1, t, 3);
                      v988 = v988 + 1.0;
                      if ( v988 >= 12.0 )
                        break;
                      v877 = v988;
                      //v876 = 100.0;
                    }
                    goto LABEL_2650;
                  }
                  break;
                case 1:
                  if ( !(field_7D2 % 72) )
                  {
                    play_sfx(2);
                    t[1] = 0.0;
                    t[2] = 0.0;
                    /*v986 = 0.0;
                    v863 = 100.0;
                    v864 = (float)0.0;
                    while ( 1 )
                    {
                      t[0] = v864 * 30.0;
                      v865 = v863 + y;
                      if ( field_7D4 % 2 )
                      {
                        v868 = v865;
                        v867 = v868;
                        xr = -dir;
                      }
                      else
                      {
                        v866 = v865;
                        v867 = v866;
                        xr = dir;
                      }
                      v869 = v867;
                      addbullet(this, NULL, 900, x, v869, xr, 1, t, 3);
                      v986 = v986 + 1.0;
                      if ( v986 >= 12.0 )
                        break;
                      v864 = v986;
                      v863 = 100.0;
                    }*/
                    if ( !(field_7D4 % 3) )
                    {
                      /*v1060 = 1.0;
                      v987 = 0.0;
                      v870 = (float)0.0;
                      do
                      {
                        v1058 = v870 * 30.0;
                        v871 = y + 100.0;
                        if ( field_7D4 % 4 )
                        {
                          v874 = v871;
                          v873 = v874;
                          xs = -dir;
                        }
                        else
                        {
                          v872 = v871;
                          v873 = v872;
                          xs = dir;
                        }
                        v875 = v873;
                        addbullet(this, NULL, 900, x, v875, xs, 1, (int)&v1058, 3);
                        v987 = v987 + 1.0;
                        v870 = v987;
                      }
                      while ( v987 < 12.0 );*/
                    }
                    goto LABEL_2650;
                  }
                  break;
                case 2:
                  if ( !(field_7D2 % 72) )
                  {
                    play_sfx(2);
                    /*v1056 = 0.0;
                    v1057 = 0.0;
                    v984 = 0.0;
                    v850 = 100.0;
                    v851 = (float)0.0;
                    while ( 1 )
                    {
                      v1055 = v851 * 30.0;
                      v852 = v850 + y;
                      if ( field_7D4 % 2 )
                      {
                        v855 = v852;
                        v854 = v855;
                        xp = -dir;
                      }
                      else
                      {
                        v853 = v852;
                        v854 = v853;
                        xp = dir;
                      }
                      v856 = v854;
                      addbullet(this, NULL, 900, x, v856, xp, 1, (int)&v1055, 3);
                      v984 = v984 + 1.0;
                      if ( v984 >= 12.0 )
                        break;
                      v851 = v984;
                      v850 = 100.0;
                    }*/
                    if ( !(field_7D4 % 2) )
                    {
                      /*v1057 = 1.0;
                      v985 = 0.0;
                      v857 = (float)0.0;
                      do
                      {
                        v1055 = v857 * 30.0;
                        v858 = y + 100.0;
                        if ( field_7D4 % 4 )
                        {
                          v861 = v858;
                          v860 = v861;
                          xq = -dir;
                        }
                        else
                        {
                          v859 = v858;
                          v860 = v859;
                          xq = dir;
                        }
                        v862 = v860;
                        addbullet(this, NULL, 900, x, v862, xq, 1, (int)&v1055, 3);
                        v985 = v985 + 1.0;
                        v857 = v985;
                      }
                      while ( v985 < 12.0 );*/
                    }
                    goto LABEL_2650;
                  }
                  break;
                case 3:
                  if ( !(field_7D2 % 60) )
                  {
                    play_sfx(2);
                    /*v1068 = 0.0;
                    v1069 = 0.0;
                    v982 = 0.0;
                    v837 = 100.0;
                    v838 = (float)0.0;
                    while ( 1 )
                    {
                      v1067 = v838 * 30.0;
                      v839 = v837 + y;
                      if ( field_7D4 % 2 )
                      {
                        v842 = v839;
                        v841 = v842;
                        xn = -dir;
                      }
                      else
                      {
                        v840 = v839;
                        v841 = v840;
                        xn = dir;
                      }
                      v843 = v841;
                      addbullet(this, NULL, 900, x, v843, xn, 1, (int)&v1067, 3);
                      v982 = v982 + 1.0;
                      if ( v982 >= 12.0 )
                        break;
                      v838 = v982;
                      v837 = 100.0;
                    }*/
                    if ( !(field_7D4 % 2) )
                    {
                    /*  v1069 = 1.0;
                      v983 = 0.0;
                      v844 = (float)0.0;
                      do
                      {
                        v1067 = v844 * 30.0;
                        v845 = y + 100.0;
                        if ( field_7D4 % 4 )
                        {
                          v848 = v845;
                          v847 = v848;
                          xo = -dir;
                        }
                        else
                        {
                          v846 = v845;
                          v847 = v846;
                          xo = dir;
                        }
                        v849 = v847;
                        addbullet(this, NULL, 900, x, v849, xo, 1, (int)&v1067, 3);
                        v983 = v983 + 1.0;
                        v844 = v983;
                      }
                      while ( v983 < 12.0 );*/
                    }
LABEL_2650:
                    ++field_7D4;
                  }
                  break;
                default:
                  break;
              }
              ++field_7D2;
LABEL_2652:
              if ( get_subseq() == 4 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
              {
LABEL_908:
                next_subseq();
              }
              else
              {
                if ( process() )
                  set_seq(700);
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  h_inerc = (double)scene_rand_rng(10) - 5.0;
                  v_inerc = 10.0;
                  v_force = 0.25;
                }
              }
            }
            else
            {
              next_subseq();
              v_force = 0.15000001;
            }
            break;
          case 720:
            if ( get_subseq() == 3 )
              sub10func();
            if ( process() )
              set_seq(700);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              h_inerc = 30.0;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                x_off = 0.0;
                y_off = 135.0;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                addbullet(this, NULL, 910, x, y, dir, -1, t, 3);
                t[1] = 0.5;
                t[2] = 4.0;
                addbullet(this, NULL, 910, x, y, dir, -1, t, 3);
                t[2] = 4.0;
                t[1] = 0.25;
                addbullet(this, NULL, 910, x, y, dir, -1, t, 3);
                play_sfx(1);
              }
              if ( !get_frame_time() && get_frame() == 5 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 5.0;
                addbullet(this, NULL, 910, x, y, dir, 1, t, 3);
                play_sfx(5);
              }
            }
            if ( get_subseq() == 1 )
            {
              if ( !get_frame() )
              {
                if ( !get_frame_time() )
                {
                  h_inerc = (enemy->x - x) * (double)dir / 60.0;
                  v_inerc = 0.0;
                }
                if ( get_frame_time() == 60 )
                  h_inerc = 0.0;
                switch ( settings_get()->get_difficulty() )
                {
                  /*case 0:
                    v885 = __OFSUB__(get_elaps_frames(), 90);
                    v884 = get_elaps_frames() - 90 < 0;
                    goto LABEL_2687;
                  case 1:
                  case 2:
                    v885 = __OFSUB__(get_elaps_frames(), 70);
                    v884 = get_elaps_frames() - 70 < 0;
                    goto LABEL_2687;
                  case 3:
                    v885 = __OFSUB__(get_elaps_frames(), 60);
                    v884 = get_elaps_frames() - 60 < 0;
LABEL_2687:
                    if ( !(v884 ^ v885) )
                    {
                      next_frame();
                      h_inerc = 0.0;
                    }
                    break;*/
                  default:
                    break;
                }
              }
              if ( !get_frame_time() )
              {
                if ( !get_frame() )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 6.0;
                  addbullet(this, NULL, 910, x, y, dir, 1, t, 3);
                }
                if ( !get_frame_time() && get_frame() == 1 )
                {
                  h_inerc = 6.0;
                  t[0] = 0.0;
                  t[1] = 0.5;
                  t[2] = 4.0;
                  addbullet(this, NULL, 910, x, y, dir, -1, t, 3);
                  t[2] = 4.0;
                  t[1] = 0.25;
                  addbullet(this, NULL, 910, x, y, dir, -1, t, 3);
                  t[2] = 9.0;
                  addbullet(this, NULL, 910, x, y - 250.0, dir, 1, t, 3);
                  play_sfx(1);
                }
              }
            }
            if ( get_subseq() == 2 )
            {
              if ( !field_7D8 )
              {
                switch ( settings_get()->get_difficulty() )
                {
                  /*
                  case 1:
                    field_7D8 = 1;
                    v897 = 13;
                    do
                    {
                      v1016 = -60.0 - (double)scene_rand_rng(60);
                      v1017 = (double)scene_rand_rng(70) * 0.1000000014901161 + 5.0;
                      v1018 = 12.0;
                      v898 = dir;
                      v899 = x + 100.0;
                      v900 = /*chrt->*//*y;
                      v901 = v899 - (double)scene_rand_rng(200);
                      addbullet(this, NULL, 910, v901, v900, v898, 1, (int)&v1016, 3);
                      --v897;
                    }
                    while ( v897 );
                    break;
                  case 2:
                    field_7D8 = 1;
                    v892 = 18;
                    do
                    {
                      v1016 = -50.0 - (double)scene_rand_rng(80);
                      v1017 = (double)scene_rand_rng(80) * 0.1000000014901161 + 8.0;
                      v1018 = 12.0;
                      v893 = dir;
                      v894 = x + 100.0;
                      v895 = /*chrt->*//*y;
                      v896 = v894 - (double)scene_rand_rng(200);
                      addbullet(this, NULL, 910, v896, v895, v893, 1, (int)&v1016, 3);
                      --v892;
                    }
                    while ( v892 );
                    break;
                  case 3:
                    field_7D8 = 1;
                    v887 = 23;
                    do
                    {
                      v1016 = -40.0 - (double)scene_rand_rng(100);
                      v1017 = (double)scene_rand_rng(100) * 0.1000000014901161 + 10.0;
                      v1018 = 12.0;
                      v888 = dir;
                      v889 = x + 100.0;
                      v890 = /*chrt->*//*y;
                      v891 = v889 - (double)scene_rand_rng(200);
                      addbullet(this, NULL, 910, v891, v890, v888, 1, (int)&v1016, 3);
                      --v887;
                    }
                    while ( v887 );
                    break;*/
                }
              }
              v_inerc = v_inerc - v_force;
              if ( !(get_elaps_frames() % 12) )
                scene_play_sfx(29);
              angZ = angZ - 40.0;
              if ( field_190 )
              {
                if ( ++field_7D0 >= 6 )
                {
                  field_190 = 0;
                  field_7D0 = 0;
                }
              }
              if ( char_on_ground_down() )
                goto LABEL_2245;
            }
            return;
          case 721:
            if ( get_subseq() == 3 )
              sub10func();
            if ( process() )
              set_seq(700);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                x_off = 0.0;
                y_off = 135.0;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                addbullet(this, NULL, 910, x, y, dir, -1, t, 3);
                t[1] = 0.5;
                t[2] = 4.0;
                addbullet(this, NULL, 910, x, y, dir, -1, t, 3);
                t[2] = 4.0;
                t[1] = 0.25;
                addbullet(this, NULL, 910, x, y, dir, -1, t, 3);
                play_sfx(1);
              }
              if ( !get_frame_time() && get_frame() == 5 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 5.0;
                addbullet(this, NULL, 910, x, y, dir, 1, t, 3);
                play_sfx(5);
              }
            }
            if ( get_subseq() != 1 )
              goto LABEL_2745;
            if ( get_frame_time() )
              goto LABEL_2736;
            if ( !get_frame() )
            {
              v_inerc = 0.0;
              if ( (double)scene_rand_rng(3) == 0.0 )
                y = 0.0;
              if ( 1.0 == (double)scene_rand_rng(3) )
                y = 200.0;
              if ( 2.0 == (double)scene_rand_rng(3) )
                y = 400.0;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 6.0;
              addbullet(this, NULL, 910, x, y, dir, 1, t, 3);
LABEL_2736:
              if ( !get_frame() )
              {
                v905 = get_frame_time() == 10;
                if ( get_frame_time() < 10 )
                {
                  h_inerc = 7.0;
                  v905 = get_frame_time() == 10;
                }
                if ( v905 )
                {
                  h_inerc = 7.0;
                  t[0] = 0.0;
                  t[1] = 0.5;
                  t[2] = 4.0;
                  addbullet(this, NULL, 910, x, y, dir, -1, t, 3);
                  t[2] = 4.0;
                  t[1] = 0.25;
                  addbullet(this, NULL, 910, x, y, dir, -1, t, 3);
                  t[2] = 10.0;
                  addbullet(this, NULL, 910, x, y - 250.0, dir, 1, t, 3);
                  play_sfx(1);
                }
              }
            }
            if ( get_frame() == 1 )
            {
              if ( field_190 )
              {
                if ( ++field_7D0 >= 6 )
                {
                  field_190 = 0;
                  field_7D0 = 0;
                }
              }
            }
LABEL_2745:
            if ( get_subseq() == 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( !(get_elaps_frames() % 12) )
                scene_play_sfx(29);
              angZ = angZ - 40.0;
              if ( field_190 )
              {
                if ( ++field_7D0 >= 6 )
                {
                  field_190 = 0;
                  field_7D0 = 0;
                }
              }
              if ( char_on_ground_down() )
                goto LABEL_2245;
            }
            return;
          case 730:
            h_inerc = h_inerc * 0.9800000190734863;
            v_inerc = 0.9800000190734863 * v_inerc;
            if ( get_subseq() == 1 && get_elaps_frames() >= 120 )
              goto LABEL_908;
            if ( process() )
            {
              set_seq(704);
              field_8AC = scene_rand_rng(60) + 120;
            }
            else if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                    field_8AA = 180;
                    break;
                  case 1:
                    field_8AA = 210;
                    break;
                  case 2:
                    field_8AA = 240;
                    break;
                  case 3:
                    field_8AA = 270;
                    break;
                  default:
                    break;
                }
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                if ( getlvl_height() >= y )
                {
                  reset_forces();
                  set_seq(700);
                  field_8AC = scene_rand_rng(60) + 120;
                }
              }
            }
            return;
          case 740:
            sub10func();
            if ( process() )
              set_seq(700);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_56;
            if ( field_7D0 == 1 )
            {
              if ( !(field_7D2 % 5) )
              {
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                  case 1:
                    v908 = 3;
                    break;
                  case 2:
                    v908 = 4;
                    break;
                  case 3:
                    v908 = 5;
                    break;
                  default:
                    v908 = x;//LOWORD(v969);
                    break;
                }
                if ( field_7D4 < v908 )
                {
                  play_sfx(21);
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  if ( field_7D4 )
                  {
                    v1008 = (double)scene_rand_rng(640) + enemy->x;
                    v912 = v1008;
                    if ( v1008 <= 1200.0 )
                    {
                      if ( v912 < 80.0 )
                        v1008 = 80.0;
                    }
                    else
                    {
                      v1008 = 1200.0;
                    }
                    v989 = (double)scene_rand_rng(480) - 140.0;
                    if ( v989 >= -50.0 )
                    {
                      if ( v989 > 680.0 )
                        v989 = 680.0;
                    }
                    else
                    {
                      v989 = -50.0;
                    }
                    a4l = v989;
                    v911 = v1008;
                  }
                  else
                  {
                    a4l = enemy->y + 100.0;
                    v911 = enemy->x;
                  }
                  addbullet(this, NULL, 930, v911, a4l, dir, 1, t, 3);
                }
                ++field_7D4;
              }
              ++field_7D2;
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
              field_7D0 = 1;
            return;
          case 741:
            sub10func();
            if ( process() )
              set_seq(700);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_56;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  field_8B0 = 45;
                  goto LABEL_2818;
                case 1:
                  field_8B0 = 80;
                  field_8B2 = 0;
                  break;
                case 2:
                  field_8B0 = 115;
                  field_8B2 = 0;
                  break;
                case 3:
                  field_8B0 = 150;
                  field_8B2 = 0;
                  break;
                default:
LABEL_2818:
                  field_8B2 = 0;
                  break;
              }
            }
            return;
          case 750:
            x = 640.0;
            y = 200.0;
            if ( !field_7D0 )
            {
              if ( !get_subseq() )
                set_subseq(1);
              if ( ++field_7D2 == 60 )
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
              if ( field_7D2 >= 60 )
              {
                /*v914 = color_A;
                if ( v914 > 0xFAu )
                {
                  //color_A = -1;
                  field_7D0 = 1;
                  field_7D2 = 0;
                }
                else
                {
                  //color_A = v914 + 5;
                }*/
              }
            }
            if ( field_7D0 == 1 )
              ++field_7D2;
            if ( process() )
              set_seq(0);
            if ( get_subseq() == 1 && !get_frame() && !get_frame_time() && field_7D0 == 1 && field_7D2 >= 60 )
              next_subseq();
            return;
          default:
            goto LABEL_2869;
        }
      }
    }
    else if ( get_seq() == 500 )
    {
      sub10func();
      field_18C = 0;
      if ( !keyDown(INP_B) )
        not_charge_attack = 0;
      if ( process() )
        set_seq(0);
      if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
      {
        if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
        {
          field_190 = 1;
          spell_energy_spend(200, 120);
          add_card_energy(50);
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          x = dir;
          v450 = (double)(300 * (char)x) + x;
LABEL_1376:
          addbullet(this, NULL, 810, v450, 0.0, x, 1, t, 3);
          play_sfx(10);
        }
      }
      else
      {
LABEL_56:
        set_seq(0);
      }
    }
    else
    {
      switch ( get_seq() )
      {
        case 301:
          sub10func();
          if (false /*get_true(0)*/ )
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
          if ( get_frame() >= 5 )
          {
            h_inerc = h_inerc - 0.2000000029802322;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( get_frame_time() )
            return;
          if ( get_frame() != 3 )
            goto LABEL_794;
          h_inerc = 2.0;
          field_49A = 0;
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          goto LABEL_793;
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
            goto LABEL_631;
          if ( get_subseq() || get_frame_time() )
            goto LABEL_818;
          if ( get_frame() != 2 )
            goto LABEL_815;
          if ( not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(92 * (char)dir), y + 224.0, dir, 1);
          }
          else
          {
            h_inerc = 10.0;
            field_49A = 0;
LABEL_815:
            if ( !get_frame_time() && get_frame() == 4 )
            {
              scene_play_sfx(29);
              h_inerc = 0.0;
            }
LABEL_818:
            if ( get_subseq() == 1 && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                h_inerc = 20.0;
                field_49A = 0;
              }
              if ( !get_frame_time() && get_frame() == 3 )
              {
                scene_play_sfx(29);
                h_inerc = 0.0;
              }
            }
          }
          return;
        case 303:
          sub10func();
          if ( true /*!get_true(0)*/ )
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
            if ( !get_frame_time() && get_frame() == 3 )
              scene_play_sfx(27);
          }
          return;
        case 304:
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
            set_seq(2);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
LABEL_43:
            set_seq(2);
            return;
          }
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 6.0;
              addbullet(this, NULL, 848, x, y, dir, -1, t, 3);
            }
            if ( !get_frame_time() && get_frame() == 4 )
            {
              scene_play_sfx(29);
              h_inerc = 0.0;
            }
          }
          if ( get_subseq() != 1 || get_frame_time() )
            return;
          if ( get_frame() == 1 )
          {
            h_inerc = 20.0;
            field_49A = 0;
          }
          if ( get_frame_time() )
            return;
          v251 = get_frame() == 3;
          goto LABEL_859;
        case 305:
          sub10func();
          if ( false /*get_true(1)*/ )
            return;
          if ( get_frame() > 4 && h_inerc > 0.0 )
            h_inerc = h_inerc - 1.0;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          if ( process() )
            set_seq(0);
          if ( get_frame_time() )
            return;
          if ( get_frame() == 2 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 2.0;
            addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
          }
          goto LABEL_872;
        case 306:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_443;
          if ( process() )
            set_seq(9);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            }
            if ( !get_frame_time() && get_frame() == 5 )
              play_sfx(0);
          }
          return;
        case 307:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_743:
            set_seq(10);
            goto LABEL_101;
          }
          if ( field_7D0 == 1 )
          {
            h_inerc = h_inerc * 0.8999999761581421;
            if ( h_inerc < 2.0 )
              h_inerc = 2.0;
          }
          if ( process() )
            set_seq(9);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_633;
          if ( get_subseq() )
            return;
          if ( !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 3.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            }
            if ( !get_frame_time() && get_frame() == 4 )
            {
              h_inerc = 15.0;
              v_inerc = 0.0;
              v_force = 0.0;
              play_sfx(0);
              field_7D0 = 1;
            }
          }
          if ( get_frame_time() )
            return;
          v255 = get_frame() == 10;
          goto LABEL_903;
        case 308:
          if ( get_subseq() != 1 )
            goto LABEL_911;
          x_off = 0.0;
          y_off = 135.0;
          angZ = angZ + 35.0;
          if ( char_on_ground_down() )
          {
            angZ = 0.0;
            reset_forces();
            y = getlvl_height();
            goto LABEL_908;
          }
          if ( !(get_elaps_frames() % 20) )
            scene_play_sfx(29);
LABEL_911:
          if ( get_subseq() == 2 )
            sub10func();
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            h_inerc = 7.5;
            v_inerc = -7.5;
          }
          return;
        case 309:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_443:
            set_seq(10);
            goto LABEL_101;
          }
          if ( process() )
            set_seq(9);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            }
LABEL_872:
            if ( !get_frame_time() && get_frame() == 3 )
              play_sfx(0);
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
          if ( get_subseq() != 1 )
            goto LABEL_2874;
          v_inerc = v_inerc - v_force * 0.5;
          angZ = angZ + 40.0;
          v_inerc = v_inerc - v_force;
          if ( !(get_elaps_frames() % 15) )
            scene_play_sfx(27);
          if ( (getlvl_height() < v_inerc + y) || v_inerc >= 0.0 )
          {
LABEL_2874:
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 1.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
          }
          else
          {
            v_inerc = 0.0;
            y = getlvl_height();
            next_subseq();
            angZ = 0.0;
            reset_ofs();
          }
          return;
        case 320:
        case 330:
          goto LABEL_772;
        case 321:
          sub10func();
          if (false /*get_true(0)*/ )
            return;
          if ( get_frame() > 1 )
          {
            h_inerc = h_inerc - 2.0;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( get_frame_time() )
            return;
          if ( get_frame() == 3 )
          {
            h_inerc = 5.0;
            field_49A = 0;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 5.0;
LABEL_793:
            addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
          }
          goto LABEL_794;
        case 322:
          sub10func();
          if ( true /*!get_true(1)*/ )
          {
            if ( h_inerc > 0.0 )
              h_inerc = h_inerc - 0.75;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                h_inerc = 10.0;
                field_49A = 0;
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 3 )
                  scene_play_sfx(29);
                if ( !get_frame_time() && get_frame() == 4 )
                  h_inerc = 0.0;
              }
            }
          }
          return;
        case 400:
          sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 != 1 )
            goto LABEL_980;
          if ( get_subseq() )
          {
            if ( !(field_7D2 % 3) && field_7D4 < 5 )
            {
              /*
              v268 = 0;
              field_190 = 1;
              v973 = 0;
              do
              {
                v1360 = (double)(10 * field_7D4) + field_7E4 - 20.0 + (double)v973 - 30.0;
                v1361 = 10.0;
                v1362 = 0.0;
                v269 = dir;
                v270 = y + 135.0;
                v271 = v270;
                v272 = (double)(82 * (char)v269) + x;
                addbullet(this, NULL, 800, v272, v271, v269, 1, (int)&v1360, 3);
                v268 += 15;
                v973 = v268;
              }
              while ( v268 < 75 );*/
              goto LABEL_978;
            }
          }
          else if ( !(field_7D2 % 3) && field_7D4 < 5 )
          {
            /*
            v263 = 0;
            field_190 = 1;
            v972 = 0;
            do
            {
              v1147 = (double)(10 * field_7D4) + field_7E4 - 20.0 + (double)v972 - 15.0;
              v1148 = 10.0;
              v1149 = 0.0;
              v264 = dir;
              v265 = y + 135.0;
              v266 = v265;
              v267 = (double)(82 * (char)v264) + x;
              addbullet(this, NULL, 800, v267, v266, v264, 1, (int)&v1147, 3);
              v263 += 15;
              v972 = v263;
            }
            while ( v263 < 45 );*/
LABEL_978:
            add_card_energy(10);
            play_sfx(2);
            ++field_7D4;
            goto LABEL_979;
          }
LABEL_979:
          ++field_7D2;
LABEL_980:
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_631;
          if ( !get_subseq() )
          {
            if ( !(get_frame_time()) )
            {
              if ( get_frame() == 2 && not_charge_attack )
              {
                next_subseq();
                scene_add_effect(this, 62, (double)(30 * (char)dir) + x, y + 190.0, dir, 1);
                return;
              }
              if ( !(get_frame_time()) && get_frame() == 3 )
              {
                field_7D0 = 1;
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                spell_energy_spend(200, 45);
                if ( field_7E4 < -30.0 )
                  field_7E4 = -30.0;
                if ( field_7E4 > 30.0 )
                  field_7E4 = 30.0;
              }
            }
          }
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
          {
            field_7D0 = 1;
            spell_energy_spend(200, 45);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -30.0 )
              field_7E4 = -30.0;
            if ( field_7E4 > 30.0 )
              field_7E4 = 30.0;
          }
          return;
        case 401:
          sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 != 1 )
            goto LABEL_1019;
          if ( get_subseq() )
          {
            if ( !(field_7D2 % 3) && field_7D4 < 5 )
            {
              /*
              v293 = 0;
              field_190 = 1;
              v975 = 0;
              do
              {
                v1273 = (double)(10 * field_7D4) + field_7E4 - 20.0 + (double)v975 - 30.0;
                v1274 = 10.0;
                v1275 = 0.0;
                v294 = dir;
                v295 = y + 335.0;
                v296 = v295;
                v297 = (double)(82 * (char)v294) + x;
                addbullet(this, NULL, 800, v297, v296, v294, 1, (int)&v1273, 3);
                v293 += 15;
                v975 = v293;
              }
              while ( v293 < 75 );*/
              goto LABEL_1017;
            }
          }
          else if ( !(field_7D2 % 3) && field_7D4 < 5 )
          {
            /*
            v288 = 0;
            field_190 = 1;
            v974 = 0;
            do
            {
              v1153 = (double)(10 * field_7D4) + field_7E4 - 20.0 + (double)v974 - 15.0;
              v1154 = 10.0;
              v1155 = 0.0;
              v289 = dir;
              v290 = y + 335.0;
              v291 = v290;
              v292 = (double)(82 * (char)v289) + x;
              addbullet(this, NULL, 800, v292, v291, v289, 1, (int)&v1153, 3);
              v288 += 15;
              v974 = v288;
            }
            while ( v288 < 45 );
            */
LABEL_1017:
            add_card_energy(10);
            play_sfx(2);
            ++field_7D4;
            goto LABEL_1018;
          }
LABEL_1018:
          ++field_7D2;
LABEL_1019:
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          {
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              spell_energy_spend(200, 45);
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 5.0;
              addbullet(this, NULL, 800, (double)(82 * (char)dir) + x, y + 335.0, dir, 1, t, 3);
            }
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
            {
              field_7D0 = 1;
              spell_energy_spend(200, 45);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -30.0 )
                field_7E4 = -30.0;
              if ( field_7E4 > 30.0 )
                field_7E4 = 30.0;
              field_7E4 = 0.0;
            }
            return;
          }
LABEL_631:
          set_seq(0);
          return;
        case 402:
          sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 3.0;
            addbullet(this, NULL, 800, x, y, dir, -1, t, 3);
          }
          if ( field_7D0 == 1 )
          {
            if ( get_subseq() || field_7D2 % 3 || dash_angle >= 5.0 )
            {
              ++field_7D2;
            }
            else
            {
              /*
              v991 = 0.0;
              field_190 = 1;
              v308 = 20.0;
              v309 = 10.0;
              v310 = v991;
              while ( 1 )
              {
                v1165 = dash_angle * 5.0 + field_7E4 - v308 + v310 * v309 - v309;
                v1166 = 10.0;
                v1167 = 1.0;
                v311 = dir;
                v312 = y - v308;
                v313 = v312;
                v314 = (v308 + dash_angle * 15.0) * (double)(char)v311 + x;
                addbullet(this, NULL, 800, v314, v313, v311, 1, (int)&v1165, 3);
                v991 = v991 + 1.0;
                if ( v991 >= 3.0 )
                  break;
                v309 = 10.0;
                v310 = v991;
                v308 = 20.0;
              }*/
              add_card_energy(10);
              play_sfx(2);
              dash_angle = dash_angle + 1.0;
              ++field_7D2;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_56;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
          {
            field_7D0 = 1;
            spell_energy_spend(200, 45);
            field_7E4 = -60.0;
          }
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
          {
            field_7D0 = 1;
            spell_energy_spend(200, 45);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -10.0 )
              field_7E4 = -10.0;
            if ( field_7E4 > 10.0 )
              field_7E4 = 10.0;
          }
          return;
        case 404:
          if ( get_subseq() == 2 )
            sub10func();
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 2 )
            goto LABEL_1074;
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 != 1 )
            goto LABEL_1094;
          if ( get_subseq() )
          {
            if ( (field_7D2 % 3) == 1 && field_7D4 < 5 )
            {
              field_190 = 1;
              if ( !field_7D4 )
                spell_energy_spend(200, 45);
              /*
              v326 = 0;
              v977 = 0;
              do
              {
                v1171 = (double)(10 * field_7D4) + field_7E4 - 20.0 + (double)v977 - 30.0;
                v1172 = 10.0;
                v1173 = 0.0;
                v327 = dir;
                v328 = y + 104.0;
                v329 = v328;
                v330 = (double)(82 * (char)v327) + x;
                addbullet(this, NULL, 800, v330, v329, v327, 1, (int)&v1171, 3);
                v326 += 15;
                v977 = v326;
              }
              while ( v326 < 75 );*/
              goto LABEL_1092;
            }
          }
          else if ( !(field_7D2 % 3) && field_7D4 < 5 )
          {
            field_190 = 1;
            if ( !field_7D4 )
              spell_energy_spend(200, 45);
            /*v321 = 0;
            v976 = 0;
            do
            {
              v1279 = (double)(10 * field_7D4) + field_7E4 - 20.0 + (double)v976 - 15.0;
              v1280 = 10.0;
              v1281 = 0.0;
              v322 = dir;
              v323 = y + 104.0;
              v324 = v323;
              v325 = (double)(82 * (char)v322) + x;
              addbullet(this, NULL, 800, v325, v324, v322, 1, (int)&v1279, 3);
              v321 += 15;
              v976 = v321;
            }
            while ( v321 < 45 );*/
LABEL_1092:
            add_card_energy(10);
            play_sfx(2);
            ++field_7D4;
            goto LABEL_1093;
          }
LABEL_1093:
          ++field_7D2;
LABEL_1094:
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_633;
          if ( !get_subseq() )
          {
            if ( !get_frame_time() )
            {
              if ( get_frame() == 2 && not_charge_attack )
              {
                next_subseq();
                scene_add_effect(this, 62, (double)(30 * (char)dir) + x, y + 190.0, dir, 1);
                return;
              }
              if ( !get_frame_time() && get_frame() == 3 )
              {
                field_7D0 = 1;
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7E4 < -30.0 )
                  field_7E4 = -30.0;
                if ( field_7E4 > 30.0 )
                  field_7E4 = 30.0;
              }
            }
            if ( !get_frame_time() && get_frame() == 8 )
              v_force = 0.60000002;
          }
          if ( get_subseq() != 1 || get_frame_time() )
            return;
          if ( get_frame() != 2 )
            goto LABEL_1125;
          field_7D0 = 1;
          v346 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          goto LABEL_1121;
        case 405:
          if ( get_subseq() == 2 )
            sub10func();
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 2 )
            goto LABEL_1074;
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 != 1 )
            goto LABEL_1152;
          if ( get_subseq() )
          {
            if ( (field_7D2 % 3) == 1 && field_7D4 < 5 )
            {
              field_190 = 1;
              if ( !field_7D4 )
                spell_energy_spend(200, 45);
              /*
              v354 = 0;
              v979 = 0;
              do
              {
                v1177 = (double)(10 * field_7D4) + field_7E4 - 20.0 + (double)v979 - 30.0;
                v1178 = 10.0;
                v1179 = 0.0;
                v355 = dir;
                v356 = y + 104.0;
                v357 = v356;
                v358 = (double)(232 * (char)v355) + x;
                addbullet(this, NULL, 800, v358, v357, v355, 1, (int)&v1177, 3);
                v354 += 15;
                v979 = v354;
              }
              while ( v354 < 75 );*/
              goto LABEL_1150;
            }
          }
          else if ( !(field_7D2 % 3) && field_7D4 < 5 )
          {
            field_190 = 1;
            if ( !field_7D4 )
              spell_energy_spend(200, 45);
            /*
            v349 = 0;
            v978 = 0;
            do
            {
              v1354 = (double)(10 * field_7D4) + field_7E4 - 20.0 + (double)v978 - 15.0;
              v1355 = 10.0;
              v1356 = 0.0;
              v350 = dir;
              v351 = y + 104.0;
              v352 = v351;
              v353 = (double)(232 * (char)v350) + x;
              addbullet(this, NULL, 800, v353, v352, v350, 1, (int)&v1354, 3);
              v349 += 15;
              v978 = v349;
            }
            while ( v349 < 45 );*/
LABEL_1150:
            add_card_energy(10);
            play_sfx(2);
            ++field_7D4;
            goto LABEL_1151;
          }
LABEL_1151:
          ++field_7D2;
LABEL_1152:
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
          {
LABEL_633:
            set_seq(9);
            return;
          }
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 5 )
            {
              spell_energy_spend(200, 45);
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 5.0;
              addbullet(this, NULL, 800, (double)(400 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
            }
            if ( !get_frame_time() && get_frame() == 9 )
              v_force = 0.60000002;
          }
          if ( get_subseq() != 1 || get_frame_time() )
            return;
          if ( get_frame() == 2 )
          {
            field_7D0 = 1;
            v346 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
LABEL_1121:
            field_7E4 = v346;
            if ( field_7E4 < -30.0 )
              field_7E4 = -30.0;
            if ( field_7E4 > 30.0 )
              field_7E4 = 30.0;
          }
LABEL_1125:
          if ( !get_frame_time() )
          {
            v347 = get_frame() == 7;
LABEL_1127:
            if ( v347 )
              v_force = 0.60000002;
          }
          break;
        case 406:
          if ( get_subseq() == 2 )
            sub10func();
          v_inerc = v_inerc - v_force;
          if ( !get_subseq() && get_frame() >= 11 && char_on_ground_down() && get_subseq() < 2 )
          {
LABEL_1074:
            field_7D0 = 0;
            set_subseq(2);
            air_dash_cnt = 0;
            goto LABEL_101;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 3.0;
            addbullet(this, NULL, 800, x, y + 30.0, dir, -1, t, 3);
          }
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 == 1 )
          {
            if ( get_subseq() || field_7D2 % 3 || dash_angle >= 5.0 )
            {
              ++field_7D2;
            }
            else
            {
              if ( 0.0 == dash_angle )
              {
                spell_energy_spend(200, 45);
              }
              /*
              v992 = 0.0;
              field_190 = 1;
              v370 = 10.0;
              v371 = v992;
              while ( 1 )
              {
                v1339 = field_7E4 - dash_angle * v370 + v371 * v370 - v370;
                v1340 = 10.0;
                v1341 = 2.0;
                v372 = dir;
                v373 = y + 40.0;
                v374 = v373;
                v375 = (dash_angle * 15.0 + 20.0) * (double)(char)v372 + x;
                addbullet(this, NULL, 800, v375, v374, v372, 1, (int)&v1339, 3);
                v992 = v992 + 1.0;
                if ( v992 >= 3.0 )
                  break;
                v371 = v992;
                v370 = 10.0;
              }*/
              add_card_energy(10);
              play_sfx(2);
              dash_angle = dash_angle + 1.0;
              ++field_7D2;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_530;
          if ( get_subseq() || get_frame_time() )
            return;
          if ( get_frame() == 5 )
          {
            field_7D0 = 1;
            field_7E4 = 80.0;
          }
          if ( get_frame_time() )
            return;
          v347 = get_frame() == 12;
          goto LABEL_1127;
        case 408:
          if ( get_frame() < 10 )
          {
            h_inerc = h_inerc - 0.1000000014901161;
          }
          else
          {
            h_inerc = h_inerc - 1.0;
            sub10func();
          }
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
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
            if ( !get_frame_time() && get_frame() == 5 )
              scene_play_sfx(29);
          }
          return;
        case 410:
          sub10func();
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_631;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            field_190 = 1;
            spell_energy_spend(200, 60);
            add_card_energy(50);
            play_sfx(3);
            /*
            v993 = 0.0;
            v377 = 5.0;
            v378 = (float)0.0;
            while ( 1 )
            {
              v1027 = 90.0;
              v1028 = 10.0;
              v1029 = 0.0;
              v1030 = v377 + v378 * v377;
              v379 = dir;
              v380 = y + 90.0;
              v381 = v380;
              v382 = (double)(177 * (char)v379) + x;
              addbullet(this, NULL, 801, v382, v381, v379, 1, (int)&v1027, 4);
              v993 = v993 + 1.0;
              if ( v993 >= 2.0 )
                break;
              v378 = v993;
              v377 = 5.0;
            }
            v994 = 0.0;
            v383 = (float)0.0;
            do
            {
              v1027 = 90.0;
              v1028 = -10.0;
              v1029 = 0.0;
              v1030 = v383 * 5.0 + 5.0;
              v384 = dir;
              v385 = y + 90.0;
              v386 = v385;
              v387 = (double)(177 * (char)v384) + x;
              addbullet(this, NULL, 801, v387, v386, v384, 1, (int)&v1027, 4);
              v994 = v994 + 1.0;
              v383 = v994;
            }
            while ( v994 < 2.0 );*/
            tt[0] = 90.0;
            tt[1] = 0.0;
            tt[2] = 0.0;
            tt[3] = 0.0;
            addbullet(this, NULL, 801, (double)(177 * (char)dir) + x, y + 90.0, dir, 1, tt, 4);
          }
          return;
        case 411:
          sub10func();
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_631;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            field_190 = 1;
            spell_energy_spend(200, 60);
            add_card_energy(50);
            play_sfx(3);
            /*
            v995 = 0.0;
            v392 = (float)0.0;
            do
            {
              v1073 = -90.0;
              v1074 = 10.0;
              v1075 = 5.0;
              v1076 = v392 * 5.0 + 10.0;
              v393 = dir;
              v394 = y + 90.0;
              v395 = v394;
              v396 = (double)(177 * (char)v393) + x;
              addbullet(this, NULL, 801, v396, v395, v393, 1, (int)&v1073, 4);
              v995 = v995 + 1.0;
              v392 = v995;
            }
            while ( v995 < 3.0 );
            v996 = 0.0;
            v397 = (float)0.0;
            do
            {
              v1073 = 90.0;
              v1074 = 10.0;
              v1075 = 6.0;
              v1076 = v397 * 5.0 + 10.0;
              v398 = dir;
              v399 = y + 90.0;
              v400 = v399;
              v401 = (double)(177 * (char)v398) + x;
              addbullet(this, NULL, 801, v401, v400, v398, 1, (int)&v1073, 4);
              v996 = v996 + 1.0;
              v397 = v996;
            }
            while ( v996 < 3.0 );*/
          }
          return;
        case 412:
          sub10func();
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            goto LABEL_631;
          if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
          {
            spell_energy_spend(200, 60);
            field_190 = 1;
            add_card_energy(50);
            play_sfx(3);
            /*
            v402 = 0.0;
            v997 = 0.0;
            v403 = (float)0.0;
            while ( 1 )
            {
              v1372 = v402;
              v1373 = 10.0;
              v1374 = v402;
              v1375 = v403 * 5.0 + 10.0;
              v404 = dir;
              v405 = y + 50.0;
              v406 = v405;
              v407 = (double)(75 * (char)v404) + x;
              addbullet(this, NULL, 801, v407, v406, v404, 1, (int)&v1372, 4);
              v997 = v997 + 1.0;
              if ( v997 >= 5.0 )
                break;
              v403 = v997;
              v402 = 0.0;
            }*/
          }
          if ( get_subseq() == 1 && get_elaps_frames() > 20 )
            goto LABEL_1273;
          return;
        case 414:
          if ( get_subseq() == 1 )
            sub10func();
          if ( get_subseq() < 1 && get_frame() >= 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1279;
          }
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_633;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            field_190 = 1;
            spell_energy_spend(200, 60);
            add_card_energy(50);
            play_sfx(3);
            h_inerc = -5.0;
            v_inerc = 7.5;
            v_force = 0.5;
            /*
            v998 = 0.0;
            v408 = 5.0;
            v409 = (float)0.0;
            while ( 1 )
            {
              v1019 = 90.0;
              v1020 = 10.0;
              v1021 = 0.0;
              v1022 = v408 + v409 * v408;
              v410 = dir;
              v411 = y + 85.0;
              v412 = v411;
              v413 = (double)(75 * (char)v410) + x;
              addbullet(this, NULL, 801, v413, v412, v410, 1, (int)&v1019, 4);
              v998 = v998 + 1.0;
              if ( v998 >= 2.0 )
                break;
              v409 = v998;
              v408 = 5.0;
            }
            v999 = 0.0;
            v414 = (float)0.0;
            do
            {
              v1019 = 90.0;
              v1020 = -10.0;
              v1021 = 0.0;
              v1022 = v414 * 5.0 + 5.0;
              v415 = dir;
              v416 = y + 85.0;
              v417 = v416;
              v418 = (double)(75 * (char)v415) + x;
              addbullet(this, NULL, 801, v418, v417, v415, 1, (int)&v1019, 4);
              v999 = v999 + 1.0;
              v414 = v999;
            }
            while ( v999 < 2.0 );*/
            tt[0] = 90.0;
            tt[1] = 0.0;
            tt[2] = 0.0;
            tt[3] = 0.0;
            addbullet(this, NULL, 801, (double)(75 * (char)dir) + x, y + 85.0, dir, 1, tt, 4);
          }
          return;
        case 415:
          if ( get_subseq() == 1 )
            sub10func();
          if ( get_subseq() < 1 && get_frame() >= 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1279;
          }
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_633;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            field_190 = 1;
            spell_energy_spend(200, 60);
            add_card_energy(50);
            play_sfx(3);
            h_inerc = -5.0;
            v_inerc = 7.5;
            v_force = 0.5;
            /*
            v1000 = 0.0;
            v423 = (float)0.0;
            do
            {
              v1077 = -90.0;
              v1078 = 10.0;
              v1079 = 5.0;
              v1080 = v423 * 5.0 + 10.0;
              v424 = dir;
              v425 = y + 85.0;
              v426 = v425;
              v427 = (double)(75 * (char)v424) + x;
              addbullet(this, NULL, 801, v427, v426, v424, 1, (int)&v1077, 4);
              v1000 = v1000 + 1.0;
              v423 = v1000;
            }
            while ( v1000 < 3.0 );
            v1001 = 0.0;
            v428 = (float)0.0;
            do
            {
              v1077 = 90.0;
              v1078 = 10.0;
              v1079 = 6.0;
              v1080 = v428 * 5.0 + 10.0;
              v429 = dir;
              v430 = y + 85.0;
              v431 = v430;
              v432 = (double)(75 * (char)v429) + x;
              addbullet(this, NULL, 801, v432, v431, v429, 1, (int)&v1077, 4);
              v1001 = v1001 + 1.0;
              v428 = v1001;
            }
            while ( v1001 < 3.0 );*/
          }
          return;
        case 416:
          if ( get_subseq() == 1 )
            sub10func();
          if ( get_subseq() < 1 && get_frame() >= 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_1279:
              reset_forces();
              y = getlvl_height();
              set_subseq(1);
              return;
            }
          }
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_633;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            field_190 = 1;
            spell_energy_spend(200, 60);
            add_card_energy(50);
            play_sfx(3);
            h_inerc = -5.0;
            v_inerc = 7.5;
            v_force = 0.5;
            /*
            v1002 = 0.0;
            v433 = 5.0;
            v434 = (float)0.0;
            while ( 1 )
            {
              v1023 = 120.0;
              v1024 = 10.0;
              v1025 = 0.0;
              v1026 = v433 + v434 * v433;
              v435 = dir;
              v436 = y + 85.0;
              v437 = v436;
              v438 = (double)(75 * (char)v435) + x;
              addbullet(this, NULL, 801, v438, v437, v435, 1, (int)&v1023, 4);
              v1002 = v1002 + 1.0;
              if ( v1002 >= 2.0 )
                break;
              v434 = v1002;
              v433 = 5.0;
            }
            v1003 = 0.0;
            v439 = (float)0.0;
            do
            {
              v1023 = 120.0;
              v1024 = -10.0;
              v1025 = 0.0;
              v1026 = v439 * 5.0 + 5.0;
              v440 = dir;
              v441 = y + 85.0;
              v442 = v441;
              v443 = (double)(75 * (char)v440) + x;
              addbullet(this, NULL, 801, v443, v442, v440, 1, (int)&v1023, 4);
              v1003 = v1003 + 1.0;
              v439 = v1003;
            }
            while ( v1003 < 2.0 );*/
            tt[0] = 120.0;
            tt[1] = 0.0;
            tt[2] = 0.0;
            tt[3] = 0.0;
            addbullet(this, NULL, 801, (double)(75 * (char)dir) + x, y + 85.0, dir, 1, tt, 4);
          }
          return;
        case 418:
          sub10func();
          field_49A = 0;
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          if ( !keyDown(INP_A) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(2);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          {
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 6.0;
                addbullet(this, NULL, 848, x, y, dir, -1, t, 3);
              }
              if ( !get_frame_time() && get_frame() == 3 )
                scene_play_sfx(29);
            }
            if ( get_subseq() == 1 && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                h_inerc = 20.0;
                field_49A = 0;
              }
              if ( !get_frame_time() )
              {
                v251 = get_frame() == 3;
LABEL_859:
                if ( v251 )
                {
                  play_sfx(0);
                  h_inerc = 0.0;
                }
              }
            }
          }
          else
          {
            set_seq(2);
          }
          return;
        default:
          goto LABEL_2869;
      }
    }
  }
}

// NOTE: taken from marisa.cpp

void char_yukari::func20()
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

void char_yukari::set_seq_params()
{
  float t[3];
  t[0] = 0.0;
  t[1] = 0.0;
  t[2] = 0.0;
  double v44 = 0.0;

  double v37 = 0.0;
  double v38 = 0.0;
  double v4 = 0.0;
  double v5 = 0.0;

  int i_loop = 0;

  if ( get_seq() > 300 )
  {
    if ( get_seq() > 561 )
    {
      switch ( get_seq() )
      {
        case 562:
        case 563:
          goto LABEL_95;
        case 565:
        case 566:
          field_18C = 7;
          reset_forces();
          field_7DC = 10.0;
          x_off = 0.0;
          field_7D0 = 0;
          field_49A = 0;
          field_190 = 0;
          y_off = 135.0;
          field_194 = 10;
          not_charge_attack = 1;
          return;
        case 570:
        case 571:
        case 572:
        case 573:
          field_18C = 11;
          reset_forces();
          field_194 = 0;
          field_190 = 0;
          return;
        case 600:
        case 601:
        case 602:
        case 603:
          goto LABEL_99;
        case 604:
        case 605:
          field_7D0 = 0;
          field_7D2 = 0;
          goto LABEL_99;
        case 606:
        case 608:
        case 656:
        case 658:
          field_7DC = 0.0;
          field_7D0 = 0;
          field_7D8 = 0;
          field_190 = 0;
          reset_forces();
          return;
        case 607:
        case 657:
        case 740:
        case 741:
        case 750:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          field_7D6 = 0;
          return;
        case 615:
          reset_forces();
          field_190 = 0;
          return;
        case 700:
        case 701:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 1;
          reset_forces();
          v_force = 0.25;
          return;
        case 708:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
LABEL_99:
          field_190 = 1;
          reset_forces();
          return;
        case 710:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          reset_forces();
          return;
        case 720:
          reset_forces();
          field_7D0 = 0;
          field_7D8 = 0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 721:
          reset_forces();
          field_7D0 = 0;
          field_49A = 0;
          field_190 = 0;
          field_194 = 10;
          return;
        case 730:
          field_7D0 = 0;
          field_7D8 = 0;
          field_190 = 0;
          return;
        case 797:
          reset_forces();
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          x = dir;
          goto LABEL_110;
        case 798:
          reset_forces();
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          x = dir;
          v44 = 920.0;
LABEL_110:
          field_7D0 = 0;
          addbullet(this, NULL, 899, v44, 100.0, x, -1, t, 3);
          play_sfx(1);
          return;
        default:
          break;
      }
    }
    else
    {
      if ( get_seq() >= 560 )
      {
LABEL_95:
        field_18C = 3;
        reset_forces();
        dash_angle = 0.0;
        field_194 = 0;
        field_190 = 0;
        field_7D0 = 0;
        return;
      }
      switch ( get_seq() )
      {
        case 301:
        case 303:
        case 320:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_194 = 1;
          return;
        case 302:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_194 = 1;
          not_charge_attack = 1;
          return;
        case 304:
          v_inerc = 0.0;
          field_194 = 1;
          v_force = 0.0;
          field_190 = 0;
          reset_forces();
          field_49A = 0;
          not_charge_attack = 1;
          return;
        case 305:
          h_inerc = 10.0;
          field_190 = 0;
          field_49A = 0;
          field_7D8 = 0;
          field_194 = 1;
          return;
        case 306:
        case 307:
        case 309:
          field_7D0 = 0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 308:
          field_194 = 1;
          field_190 = 0;
          reset_forces();
          return;
        case 310:
          h_inerc = 15.0;
          field_7D0 = 0;
          v_force = 0.5;
          field_190 = 0;
          field_194 = 3;
          x_off = 0.0;
          y_off = 105.0;
          return;
        case 321:
          goto LABEL_69;
        case 322:
          reset_forces();
          field_194 = 1;
          field_190 = 0;
          return;
        case 330:
          goto LABEL_36;
        case 400:
        case 401:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          not_charge_attack = 1;
          return;
        case 402:
          field_190 = 0;
          reset_forces();
          dash_angle = 0.0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          return;
        case 404:
        case 405:
          v_force = 0.0;
          field_190 = 0;
          field_7D2 = 0;
          v37 = 0.2000000029802322;
          field_7D4 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          goto LABEL_64;
        case 406:
          v38 = 0.0;
          dash_angle = 0.0;
          field_190 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          goto LABEL_67;
        case 408:
        case 418:
          h_inerc = 12.5;
          v_inerc = 0.0;
          v_force = 0.0;
LABEL_69:
          field_49A = 0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 410:
        case 411:
        case 412:
          field_190 = 0;
          reset_forces();
          goto LABEL_71;
        case 414:
        case 415:
        case 416:
          field_190 = 0;
          h_inerc = h_inerc * 0.25;
          v_inerc = 0.25 * v_inerc;
LABEL_71:
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          goto LABEL_65;
        case 500:
        case 501:
        case 502:
        case 503:
          field_18C = 0;
          field_190 = 1;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 505:
        case 506:
          field_18C = 4;
          goto LABEL_75;
        case 510:
        case 511:
          field_18C = 8;
LABEL_75:
          field_190 = 1;
          reset_forces();
          goto LABEL_76;
        case 512:
        case 513:
          field_18C = 8;
          v_force = 0.0;
          field_190 = 1;
          h_inerc = h_inerc * 0.1000000014901161;
          v_inerc = 0.1000000014901161 * v_inerc;
LABEL_76:
          field_7D2 = 0;
          field_7D6 = 0;
          goto LABEL_65;
        case 520:
          //v41 = __OFSUB__(skills_1[1], 3);
          //v40 = (char)(skills_1[1] - 3) < 0;
          field_18C = 1;
          field_7D0 = 0;
          field_194 = 4;
          //if ( !(v40 ^ v41) )
          //  field_194 = 5;
          field_190 = 0;
          reset_forces();
          return;
        case 521:
          field_7D0 = 0;
          field_190 = 0;
          field_18C = 1;
          field_194 = 4;
          reset_forces();
          return;
        case 522:
        case 523:
          field_18C = 1;
          field_190 = 0;
          h_inerc = h_inerc * 0.25;
          v_inerc = 0.25 * v_inerc;
          return;
        case 525:
        case 526:
          field_18C = 5;
          field_7D0 = 0;
          field_194 = 0;
          field_190 = 1;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 527:
        case 528:
          v38 = 0.025;
          field_18C = 5;
          field_194 = 0;
          field_190 = 1;
LABEL_67:
          v_force = v38;
          v37 = 0.1000000014901161;
LABEL_64:
          h_inerc = h_inerc * v37;
          v_inerc = v37 * v_inerc;
LABEL_65:
          field_7D0 = 0;
          not_charge_attack = 1;
          return;
        case 530:
        case 531:
          field_18C = 9;
          field_194 = 0;
          field_190 = 1;
          reset_forces();
          field_7D0 = 0;
          not_charge_attack = 1;
          return;
        case 540:
        case 541:
        case 542:
        case 543:
          field_18C = 2;
          goto LABEL_88;
        case 545:
        case 546:
          not_charge_attack = 1;
          field_18C = 6;
          reset_forces();
          field_194 = 1;
          goto LABEL_89;
        case 547:
        case 548:
          not_charge_attack = 1;
          field_18C = 6;
          goto LABEL_88;
        case 550:
        case 551:
          field_18C = 10;
LABEL_88:
          reset_forces();
          goto LABEL_89;
        case 552:
        case 553:
          field_18C = 10;
          v_force = 0.0;
          h_inerc = h_inerc * 0.1000000014901161;
          v_inerc = 0.1000000014901161 * v_inerc;
LABEL_89:
          field_190 = 1;
          field_49A = 0;
          return;
        default:
          break;
      }
    }
LABEL_112:
    char_c::set_seq_params();
  }
  else if ( get_seq() == 300 )
  {
LABEL_36:
    if ( !get_frame_time() && !get_frame() )
    {
      if ( !field_49A )
        reset_forces();
      field_194 = 1;
      field_190 = 0;
    }
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
  else
  {
    switch ( get_seq() )
    {
      case 4:
        h_inerc = 4.5;
        return;
      case 5:
        h_inerc = -4.5;
        return;
      case 70:
        field_7D0 = 0;
        h_inerc = -field_1A4;
        v_inerc = field_1A8;
        v_force = 0.80000001;
        if ( h_inerc > 0.0 )
          field_7D0 = 1;
        if ( h_inerc < 0.0 )
          field_7D0 = -1;
        angZ = 0.0;
        return;
      case 71:
        h_inerc = -field_1A4;
        v4 = field_1A8;
        goto LABEL_13;
      case 72:
        h_inerc = -field_1A4;
        v_inerc = field_1A8;
        v_force = 1.3;
        angZ = 0.0;
        return;
      case 73:
      case 88:
        h_inerc = -field_1A4;
        v_inerc = field_1A8;
        v5 = 0.80000001;
        goto LABEL_14;
      case 74:
      case 75:
        h_inerc = -field_1A4;
        v_inerc = field_1A8;
        v5 = 0.80000001;
        goto LABEL_15;
      case 76:
        weather_forecast_next();
        i_loop = 5;
        do
        {
          scene_add_effect(this, 201, x, y + 100.0, dir, 1);
          --i_loop;
        }
        while ( i_loop );
        ++field_7D0;
        y = y + 100.0;
        hit_stop = 5;
        x_delta = 0;
        y_delta = 85;
        scene_add_effect(this, 38, x - (double)(50 * (char)dir), y, dir, 1);
        scene_add_effect(this, 59, x - (double)(50 * (char)dir), y + 100.0, dir, 1);
        x_off = (double)x_delta;
        y_off = (double)y_delta;
        h_inerc = 0.0;
        v_inerc = 0.0;
        v_force = 0.0;
        //shake_camera(6.0);
        scene_play_sfx(22);
        angZ = 0.0;
        break;
      case 77:
        x_delta = 0;
        h_inerc = -field_1A4;
        y_delta = 85;
        v_inerc = field_1A8;
        v_force = 0.80000001;
        x_off = 0.0;
        y_off = 85.0;
        angZ = 0.0;
        break;
      case 78:
        weather_forecast_next();
        i_loop = 5;
        do
        {
          scene_add_effect(this, 201, x, y + 100.0, dir, 1);
          --i_loop;
        }
        while ( i_loop );
        ++field_7D0;
        h_inerc = 0.0;
        v_inerc = 0.0;
        v_force = 0.0;
        //shake_camera(4.0);
        scene_play_sfx(22);
        scene_add_effect(this, 38, x - (double)(50 * (char)dir), y + 100.0, dir, 1);
        scene_add_effect(this, 59, x - (double)(50 * (char)dir), y + 100.0, dir, 1);
        angZ = 0.0;
        break;
      case 89:
        weather_forecast_next();
        i_loop = 5;
        do
        {
          scene_add_effect(this, 201, x, y + 100.0, dir, 1);
          --i_loop;
        }
        while ( i_loop );
        if ( !field_890 )
        {
          field_890 = 1;
          addbullet(this, NULL, 999, x, y, dir, 1, 0, 0);
        }
        scene_add_effect(this, 58, x, 0.0, dir, -1);
        angZ = 0.0;
        break;
      case 145:
        h_inerc = -10.0;
        v4 = 14.0;
LABEL_13:
        v_inerc = v4;
        v5 = 0.5;
LABEL_14:
        field_7D0 = 7;
LABEL_15:
        v_force = v5;
        angZ = 0.0;
        break;
      case 214:
      case 217:
        reset_ofs();
        h_inerc = 0.0;
        v_inerc = 0.0;
        field_7D6 = 0;
        v_force = 0.60000002;
        x_off = 0.0;
        y_off = 115.0;
        field_7DC = 10.0;
        field_7EC = 0.0;
        break;
      default:
        goto LABEL_112;
    }
  }
}
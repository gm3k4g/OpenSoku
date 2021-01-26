#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "yuyuko.h"
#include <math.h>

char_yuyuko::char_yuyuko(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_YUYUKO;
	pgp->load_dat("yuyuko",pal);
	char_loadsfx("yuyuko");
	cards_load_cards(&chr_cards,"yuyuko");
	load_face("yuyuko");
	load_spells("yuyuko");
	stand_gfx->init(this,"yuyuko");
}

void char_yuyuko::init_vars()
{
	field_138 = -6.0;
	field_890 = 0;
	field_894 = 0;
	field_898 = 0;
	field_89C = 0;
	field_8A0 = 0;
	field_8A4 = 0;
	field_8A8 = 0;
	char_c::init_vars();
}
/*
c_bullet *char_yuyuko::new_bullet()
{
    c_bullet *tmp = new yuyuko_bullets();
    return tmp;
}
*/
void char_yuyuko::func10()
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

  double v459 = 0.0;
  bool v232 = false;

  double v1174 = 0.0;
  double v249 = 0.0;

  double v1175 = 0.0;
  double v313 = 0.0;
  double v331 = 0.0;

  double v1176 = 0.0;
  double v342 = 0.0;
  double v364 = 0.0;

  double v466 = 0.0;
  double v473 = 0.0;
  double v480 = 0.0;

  bool v487 = false;

  double v1177 = 0.0;
  double v490 = 0.0;
  double v515 = 0.0;

  double v1273 = 0.0;
  double v1279 = 0.0;
  double v1282 = 0.0;
  double v1276 = 0.0;

  double v1208 = 0.0;

  double v679 = 0.0;
  double v711 = 0.0;

  double v1232 = 0.0;
  double v1240 = 0.0;
  double v961 = 0.0;
  double v974 = 0.0;

  double v1099 = 0.0;
  double v1100 = 0.0;

  double v22 = 0.0;
  double v31 = 0.0;
  double v87 = 0.0;
  double v90 = 0.0;
  double v94 = 0.0;

  double v172 = 0.0;

  double v1178 = 0.0;
  double v496 = 0.0;

  double v1179 = 0.0;
  double v613 = 0.0;
  double v617 = 0.0;

  double move_val = 0.0;


  x_delta = 0;
  y_delta = 90;
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
  if ( field_8A8 > 0 )
  {
    field_8A8 = field_8A8 - 1;
    if ( field_8A8 < 0 )
      field_8A8 = 0;
    if ( char_is_shock() )
      field_8A8 = 0;
  }
  if ( hit_stop || enemy->time_stop )
    return;
  if ( get_seq() > 300 )
  {
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
          if ( !get_subseq() && !get_frame_time() )
          {
            v459 = 4;
            if ( get_frame() == 4 )
            {
              if ( skills_1[0] >= 1 )
                v459 = 5;
              if ( skills_1[0] >= 4 )
                v459 = 6;
              /*v461 = 0;
              v1599 = 6.0;
              v1600 = 12.0;
              if ( v459 > 0 )
              {
                v1196 = 0;
                do
                {
                  *(float *)&v1598 = -20.0 - (double)v1196;
                  v1601 = (double)(v461 & 3);
                  v462 = dir;
                  v463 = y + 177.0;
                  v464 = v463;
                  v465 = (double)(38 * (char)v462) + x;
                  addbullet(this, NULL, 810, v465, v464, v462, 1, (int)&v1598, 4);
                  v1196 += 10;
                  ++v461;
                }
                while ( v461 < v459 );
              }*/
LABEL_1310:
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(10);
            }
          }
          return;
        }
LABEL_421:
        set_seq(0);
        return;
      }
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
          if ( get_frame() >= 5 )
          {
            h_inerc = h_inerc - 0.1500000059604645;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( get_frame_time() )
            return;
          if ( get_frame() == 2 )
          {
            h_inerc = 4.0;
            field_49A = 0;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 3.0;
            addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
          }
          goto LABEL_807;
        case 302:
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
          if ( !keyDown(INP_A) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_2738;
          if ( get_subseq() )
            goto LABEL_651;
          if ( get_frame_time() )
            goto LABEL_648;
          if ( get_frame() != 4 )
            goto LABEL_645;
          if ( not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(43 * (char)dir), y + 162.0, dir, 1);
            return;
          }
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 4.0;
          addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
          h_inerc = 10.0;
          field_49A = 0;
LABEL_645:
          if ( !get_frame_time() && get_frame() == 5 )
            play_sfx(0);
LABEL_648:
          if ( get_frame() >= 6 ) //condition reversed (old: < )
          {
LABEL_651:
            h_inerc = h_inerc - 1.200000047683716;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( get_subseq() != 1 )
            return;
          if ( !get_frame_time() )
          {
            if ( get_frame() == 1 )
            {
              h_inerc = 10.0;
              field_49A = 0;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 4.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
              
            }
            if ( !get_frame_time() && get_frame() == 2 )
            {
              play_sfx(0);
              
            }
          }
          if ( get_frame() < 3 )
            return;
          h_inerc = h_inerc - 1.200000047683716;
          if ( h_inerc >= 0.0 )
            return;
          goto LABEL_2525;
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
            if ( !get_frame_time() && get_frame() == 1 )
            {
              scene_play_sfx(28);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            }
          }
          return;
        case 304:
          sub10func();
          if ( false /*get_true(1)*/)
            return;
          if ( field_49A > 0 )
          {
            h_inerc = h_inerc - 0.6000000238418579;
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
LABEL_42:
            set_seq(2);
            return;
          }
          if ( get_subseq() )
            goto LABEL_695;
          if ( get_frame_time() )
            goto LABEL_692;
          if ( get_frame() == 3 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 5.0;
            addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
          }
          if ( get_frame_time() || get_frame() != 3 )
            goto LABEL_692;
          if ( not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(20 * (char)dir), y + 50.0, dir, 1);
          }
          else
          {
            h_inerc = 2.0;
            scene_play_sfx(29);
LABEL_692:
            if ( get_frame() >= 5 ) //condition reversed (old: < )
            {
LABEL_695:
              h_inerc = h_inerc - 0.1500000059604645;
              
              if ( h_inerc < 0.0 )
              {
                h_inerc = 0.0;
                field_49A = 0;
              }
            }
            if ( get_subseq() == 1 )
            {
              if ( !get_frame_time() )
              {
                if ( get_frame() == 1 )
                {
                  h_inerc = 2.0;
                  scene_play_sfx(29);
                  
                }
                if ( !get_frame_time() && get_frame() == 1 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 5.0;
                  addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
                  
                }
              }
              if ( get_frame() >= 3 )
              {
                h_inerc = h_inerc - 0.1500000059604645;
                if ( h_inerc < 0.0 )
                {
                  h_inerc = 0.0;
                  field_49A = 0;
                }
              }
            }
          }
          return;
        case 305:
          sub10func();
          if ( true /*!get_true(1)*/)
          {
            h_inerc = h_inerc - 0.2000000029802322;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 10.0;
                addbullet(this, NULL, 848, x - (double)(40 * (char)dir), y + 120.0, dir, 1, t, 3);
              }
              if ( !get_frame_time() && get_frame() == 2 )
                scene_play_sfx(28);
            }
          }
          return;
        case 306:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_749;
          if ( process() )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 2 )
              scene_play_sfx(28);
            if ( !get_frame_time() && get_frame() == 2 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 6.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            }
          }
          return;
        case 307:
          if ( !keyDown(INP_A) )
            not_charge_attack = 0;
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 2.0 )
            h_inerc = 2.0;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_769;
          if ( process() )
            set_seq(9);
          if ( get_subseq() || get_frame_time() )
            return;
          if ( get_frame() == 1 )
          {
            h_inerc = 12.5;
            v_inerc = 10.0;
            v_force = 0.5;
          }
          if ( get_frame_time() )
            return;
          if ( get_frame() == 2 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 7.0;
            addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
          }
          if ( get_frame_time() )
            return;
          if ( get_frame() == 3 )
            play_sfx(0);
          if ( get_frame_time() )
            return;
          v232 = get_frame() == 8;
          goto LABEL_1987;
        case 308:
          if ( !keyDown(INP_A) )
            not_charge_attack = 0;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_749:
            set_seq(10);
            goto LABEL_1940;
          }
          if ( process() )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 4 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 8.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 5 )
                scene_play_sfx(29);
              if ( !get_frame_time() )
              {
                if ( get_frame() == 6 )
                  field_190 = 0;
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 7 )
                    field_190 = 0;
                  if ( !get_frame_time() && get_frame() == 8 )
                    field_190 = 0;
                }
              }
            }
          }
          return;
        case 309:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_769:
            set_seq(10);
            goto LABEL_1940;
          }
          if ( process() )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              h_inerc = h_inerc * 0.5;
              v_inerc = 5.0;
              v_force = 0.5;
              scene_play_sfx(29);
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
          if ( get_subseq() != 2 )
            goto LABEL_1062;
          v_inerc = v_inerc - v_force;
          if ( !char_on_ground_down() )
            goto LABEL_1062;
          v_inerc = 0.0;
          y = getlvl_height();
          set_seq(9);
          return;
        case 320:
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
            if ( get_frame() >= 5 )
            {
              h_inerc = h_inerc - 0.1500000059604645;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                h_inerc = 4.0;
                field_49A = 0;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 3.0;
                addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
              }
LABEL_807:
              if ( !get_frame_time() && get_frame() == 3 )
              {
                play_sfx(0);
                field_49A = 0;
              }
            }
          }
          return;
        case 321:
          sub10func();
          if ( true /*!get_true(1)*/)
          {
            if ( get_frame() > 3 )
            {
              h_inerc = h_inerc - 0.300000011920929;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 2 )
                h_inerc = 4.5;
              if ( !get_frame_time() && get_frame() == 3 )
              {
                play_sfx(0);
                field_49A = 0;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 12.0;
                addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
              }
            }
          }
          return;
        case 322:
          sub10func();
          if ( true /*!get_true(1)*/)
          {
            if ( get_frame() >= 4 )
            {
              h_inerc = h_inerc - 0.2000000029802322;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
                h_inerc = 4.0;
              if ( !get_frame_time() && get_frame() == 4 )
                play_sfx(0);
            }
          }
          return;
        case 330:
          goto LABEL_603;
        case 400:
          sub10func();
          if ( get_subseq() < 2 && !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 <= 0 )
            goto LABEL_850;
          field_7D0 = field_7D0 + 1;
          if ( get_subseq() )
          {
            if ( (field_7D0 % 10) == 1 && field_7D2 < 4 )
            {
              field_190 = 1;
              add_card_energy(10);
              /*
              v250 = 0;
              do
              {
                t[0] = (double)(field_7D4 + 5 * (field_7D2 + 2) * v250) - (double)(10 * (field_7D2 + 2));
                t[1] = 1.0;
                t[2] = (double)field_7D2;
                v251 = dir;
                v252 = y + 160.0;
                v253 = v252;
                v254 = (double)(60 * (char)v251) + x;
                addbullet(this, NULL, 800, v254, v253, v251, 1, (int)&v1343, 3);
                ++v250;
              }
              while ( v250 < 5 );*/
              t[2] = (double)field_7D2 + 16.0;
              x = dir;
              v1174 = y + 160.0;
              v249 = (double)(60 * (char)x) + x;
              goto LABEL_849;
            }
          }
          else if ( (field_7D0 % 10) == 1 && field_7D2 < 3 )
          {
            field_190 = 1;
            add_card_energy(10);
            /*
            v242 = 0;
            do
            {
              t[0] = (double)(field_7D4 + 5 * (field_7D2 + 3) * v242) - (double)(10 * (field_7D2 + 3));
              t[1] = 1.0;
              t[2] = (double)field_7D2;
              v243 = dir;
              v244 = y + 160.0;
              v245 = v244;
              v246 = (double)(60 * (char)v243) + x;
              addbullet(this, NULL, 800, v246, v245, v243, 1, (int)&v1337, 3);
              ++v242;
            }
            while ( v242 < 5 );*/
            t[2] = (double)field_7D2 + 16.0;
            x = dir;
            v1174 = y + 160.0;
            v249 = (double)(60 * (char)x) + x;
LABEL_849:
            addbullet(this, NULL, 800, v249, v1174, x, 1, t, 3);
            play_sfx(1);
            ++field_7D2;
            goto LABEL_850;
          }
LABEL_850:
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_421;
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 5 && not_charge_attack )
            {
              scene_add_effect(this, 62, x, y + 150.0, dir, 1);
              next_subseq();
            }
            if ( !get_frame_time() && get_frame() == 6 )
            {
              field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7D4 < -20 )
                field_7D4 = -20;
              if ( field_7D4 > 20 )
                field_7D4 = 20;
              field_7D0 = 1;
              spell_energy_spend(200, 45);
            }
          }
          if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
            return;
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < -20 )
            field_7D4 = -20;
          if ( field_7D4 > 20 )
          {
            field_7D4 = 20;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
            return;
          }
          goto LABEL_915;
        case 401:
          sub10func();
          if ( get_subseq() < 2 && !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 <= 0 )
            goto LABEL_890;
          field_7D0 = field_7D0 + 1;
          if ( get_subseq() )
          {
            if ( (field_7D0 % 10) == 1 && field_7D2 < 3 )
            {
              field_190 = 1;
              add_card_energy(10);
              /*
              v277 = 0;
              do
              {
                *(float *)&v1442 = (double)(field_7D4 + 5 * v277 * (field_7D2 + 2)) - (double)(10 * (field_7D2 + 2));
                v1443 = 1.0;
                v1444 = (double)field_7D2;
                v278 = dir;
                v279 = y + 160.0;
                v280 = v279;
                v281 = (double)(60 * (char)v278) + x;
                addbullet(this, NULL, 800, v281, v280, v278, 1, (int)&v1442, 3);
                ++v277;
              }
              while ( v277 < 5 );
              */
              goto LABEL_889;
            }
          }
          else if ( (field_7D0 % 10) == 1 && field_7D2 < 3 )
          {
            field_190 = 1;
            add_card_energy(10);
            /*
            v272 = 0;
            do
            {
              *(float *)&v1526 = (double)(field_7D4 + 5 * v272 * (field_7D2 + 3)) - (double)(10 * (field_7D2 + 3));
              v1527 = 1.0;
              v1528 = (double)field_7D2;
              v273 = dir;
              v274 = y + 160.0;
              v275 = v274;
              v276 = (double)(60 * (char)v273) + x;
              addbullet(this, NULL, 800, v276, v275, v273, 1, (int)&v1526, 3);
              ++v272;
            }
            while ( v272 < 5 );*/
LABEL_889:
            play_sfx(1);
            ++field_7D2;
            goto LABEL_890;
          }
LABEL_890:
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          {
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 5 && not_charge_attack )
              {
                scene_add_effect(this, 62, x, y + 150.0, dir, 1);
                next_subseq();
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7D4 < -20 )
                  field_7D4 = -20;
                if ( field_7D4 > 20 )
                  field_7D4 = 20;
                field_7D0 = 1;
                spell_energy_spend(200, 45);
              }
            }
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7D4 < -20 )
              field_7D4 = -20;
            if ( field_7D4 > 20 )
              field_7D4 = 20;
LABEL_915:
            field_7D0 = 1;
            spell_energy_spend(200, 45);
            return;
          }
          goto LABEL_421;
        case 402:
          if ( (get_frame()) <= 1 || (get_frame()) >= 7 )
            sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( h_inerc < 0.0 )
          {
            h_inerc = h_inerc + 0.75;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
          }
          if ( field_7D0 == 1 )
          {
            if ( !(field_7D2 % 3) && field_7D4 < 4 )
            {
              /*
              v295 = 0;
              v1195 = 0;
              do
              {
                a4 = (double)(-20 * field_7D4);
                v1305 = (double)v1195 + 10.0;
                v1306 = (double)field_7D4 + 12.0;
                v296 = dir;
                v297 = (double)(20 * field_7D4);
                v298 = sin_deg(v297) * 150.0 + y + 50.0;
                addbullet(this, NULL, 800, x, v298, v296, 1, (int)&a4, 3);
                v295 += 10;
                v1195 = v295;
              }
              while ( v295 < 30 );
              v299 = 4;
              do
              {
                a4 = (double)scene_rand_rng(360);
                v1305 = (double)scene_rand_rng(50) * 0.1000000014901161 + 5.0;
                v1306 = (double)field_7D4 + 4.0;
                v300 = dir;
                v301 = (double)(20 * field_7D4);
                v302 = sin_deg(v301) * 150.0 + y + 50.0;
                addbullet(this, NULL, 800, x, v302, v300, 1, (int)&a4, 3);
                --v299;
              }
              while ( v299 );*/
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 2 )
              h_inerc = -15.0;
            if ( !get_frame_time() && get_frame() == 3 )
            {
              field_190 = 1;
              spell_energy_spend(200, 45);
              add_card_energy(50);
              field_7D0 = 1;
              play_sfx(1);
            }
          }
          return;
        case 404:
          if ( get_subseq() == 2 )
            sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 2 )
          {
            field_7D0 = 0;
            set_subseq(2);
            goto LABEL_1939;
          }
          if ( field_7D0 <= 0 )
            goto LABEL_961;
          field_7D0 = field_7D0 + 1;
          if ( get_subseq() )
          {
            if ( (field_7D0 % 10) == 1 && field_7D2 < 4 )
            {
              field_190 = 1;
              add_card_energy(10);
              /*
              v314 = 0;
              do
              {
                t[0] = (double)(field_7D4 + 5 * v314 * (field_7D2 + 2)) - (double)(10 * (field_7D2 + 2));
                t[1] = 1.0;
                t[2] = (double)field_7D2;
                v315 = dir;
                v316 = y + 160.0;
                v317 = v316;
                v318 = (double)(60 * (char)v315) + x;
                addbullet(this, NULL, 800, v318, v317, v315, 1, (int)&v1352, 3);
                ++v314;
              }
              while ( v314 < 5 );*/
              t[2] = (double)field_7D2 + 16.0;
              v1175 = y + 160.0;
              v313 = (double)(60 * (char)dir) + x;
              goto LABEL_960;
            }
          }
          else if ( (field_7D0 % 10) == 1 && field_7D2 < 3 )
          {
            field_190 = 1;
            add_card_energy(10);
            /*
            v306 = 0;
            do
            {
              t[0] = (double)(field_7D4 + 5 * v306 * (field_7D2 + 3)) - (double)(10 * (field_7D2 + 3));
              t[1] = 1.0;
              t[2] = (double)field_7D2;
              v307 = dir;
              v308 = y + 160.0;
              v309 = v308;
              v310 = (double)(60 * (char)v307) + x;
              addbullet(this, NULL, 800, v310, v309, v307, 1, (int)&v1328, 3);
              ++v306;
            }
            while ( v306 < 5 );
            */
            t[2] = (double)field_7D2 + 16.0;
            v1175 = y + 160.0;
            v313 = (double)(60 * (char)dir) + x;
LABEL_960:
            addbullet(this, NULL, 800, v313, v1175, dir, 1, t, 3);
            play_sfx(1);
            ++field_7D2;
            goto LABEL_961;
          }
LABEL_961:
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_2097;
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 5 && not_charge_attack )
            {
              scene_add_effect(this, 62, x, y + 150.0, dir, 1);
              next_subseq();
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7D4 < -20 )
                  field_7D4 = -20;
                if ( field_7D4 > 20 )
                  field_7D4 = 20;
                field_7D0 = 1;
                spell_energy_spend(200, 45);
              }
              if ( !get_frame_time() && get_frame() == 14 )
                v_force = 0.60000002;
            }
          }
          if ( get_subseq() != 1 || get_frame_time() )
            return;
          if ( get_frame() != 2 )
            goto LABEL_1042;
          move_val = (enemy->x - x) * (double)dir;
          v331 = enemy->y - y;
          goto LABEL_1037;
        case 406:
          if ( get_subseq() == 2 )
            sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 2 )
          {
            field_7D0 = 0;
            set_subseq(2);
            goto LABEL_1939;
          }
          if ( field_7D0 <= 0 )
            goto LABEL_1009;
          field_7D0 = field_7D0 + 1;
          if ( get_subseq() )
          {
            if ( (field_7D0 % 10) == 1 && field_7D2 < 4 )
            {
              field_190 = 1;
              add_card_energy(10);
              /*
              v343 = 0;
              do
              {
                t[0] = (double)(field_7D4 + 5 * v343 * (field_7D2 + 2)) - (double)(10 * (field_7D2 + 2));
                t[1] = 1.0;
                t[2] = (double)field_7D2;
                v344 = dir;
                v345 = y + 160.0;
                v346 = v345;
                v347 = (double)(60 * (char)v344) + x;
                addbullet(this, NULL, 800, v347, v346, v344, 1, (int)&v1349, 3);
                ++v343;
              }
              while ( v343 < 5 );
              */
              t[2] = (double)field_7D2 + 16.0;
              v1176 = y + 160.0;
              v342 = (double)(60 * (char)dir) + x;
              goto LABEL_1008;
            }
          }
          else if ( (field_7D0 % 10) == 1 && field_7D2 < 3 )
          {
            field_190 = 1;
            add_card_energy(10);
            /*
            v335 = 0;
            do
            {
              t[0] = (double)(field_7D4 + 5 * v335 * (field_7D2 + 3)) - (double)(10 * (field_7D2 + 3));
              t[1] = 1.0;
              t[2] = (double)field_7D2;
              v336 = dir;
              v337 = y + 160.0;
              v338 = v337;
              v339 = (double)(60 * (char)v336) + x;
              addbullet(this, NULL, 800, v339, v338, v336, 1, (int)&v1334, 3);
              ++v335;
            }
            while ( v335 < 5 );
            */
            t[2] = (double)field_7D2 + 16.0;
            v1176 = y + 160.0;
            v342 = (double)(60 * (char)dir) + x;
LABEL_1008:
            addbullet(this, NULL, 800, v342, v1176, dir, 1, t, 3);
            play_sfx(1);
            ++field_7D2;
            goto LABEL_1009;
          }
LABEL_1009:
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
          {
LABEL_2097:
            set_seq(9);
            return;
          }
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 5 && not_charge_attack )
            {
              scene_add_effect(this, 62, x, y + 150.0, dir, 1);
              next_subseq();
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7D4 < -20 )
                  field_7D4 = -20;
                if ( field_7D4 > 20 )
                  field_7D4 = 20;
                field_7D0 = 1;
                spell_energy_spend(200, 45);
              }
              if ( !get_frame_time() && get_frame() == 14 )
                v_force = 0.60000002;
            }
          }
          if ( get_subseq() != 1 || get_frame_time() )
            return;
          if ( get_frame() == 2 )
          {
            move_val = (enemy->x - x) * (double)dir;
            v331 = enemy->y - y;
LABEL_1037:
            field_7D4 = -atan2_deg(v331, move_val);
            if ( field_7D4 < -20 )
              field_7D4 = -20;
            if ( field_7D4 > 20 )
              field_7D4 = 20;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
          }
LABEL_1042:
          if ( !get_frame_time() )
          {
            v232 = get_frame() == 12;
LABEL_1987:
            if ( v232 )
              v_force = 0.60000002;
          }
          return;
        case 408:
          sub10func();
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          if ( !keyDown(INP_A) )
            not_charge_attack = 0;
          if ( process() )
          {
            set_seq(0);
            field_49A = 0;
          }
          if ( get_subseq() )
            return;
          if ( !get_frame_time() )
          {
            if ( get_frame() == 4 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 4.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
              field_49A = 0;
            }
            if ( !get_frame_time() && get_frame() == 4 )
              play_sfx(0);
          }
          if ( get_frame() < 6 )
            return;
          v364 = h_inerc - 1.0;
          goto LABEL_2524;
        case 409:
          v_inerc = v_inerc - v_force;
          if ( getlvl_height() >= (v_inerc + y) && v_inerc < 0.0 )
          {
            set_seq(10);
            goto LABEL_2620;
          }
LABEL_1062:
          if ( process() )
            set_seq(9);
          return;
        case 410:
          sub10func();
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( !get_subseq() && field_7D0 == 1 )
          {
            if ( !(field_7D2 % 5) && field_7D4 <= 5 )
            {
              play_sfx(2);
              field_190 = 1;
              add_card_energy(10);
              t[0] = (double)(-135 - 10 * field_7D4);
              t[1] = 8.0;
              t[2] = 1.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1,t, 3);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( get_subseq() == 1 && field_7D0 == 1 )
          {
            if ( !(field_7D2 % 3) && field_7D4 <= 9 )
            {
              play_sfx(2);
              field_190 = 1;
              add_card_energy(10);
              t[0] = (double)(-125 - 10 * field_7D4);
              t[1] = 8.0;
              t[2] = 1.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1, t, 3);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_1616;
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 5 && not_charge_attack )
            {
              scene_add_effect(this, 62, x, y + 155.0, dir, 1);
              next_subseq();
            }
            if ( !get_frame_time() && get_frame() == 7 )
            {
              field_7D0 = 1;
              spell_energy_spend(200, 60);
            }
          }
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 3 )
          {
            field_7D0 = 1;
            spell_energy_spend(200, 60);
          }
          return;
        case 411:
          sub10func();
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_2738;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
          {
            add_card_energy(50);
            play_sfx(3);
            field_190 = 1;
            spell_energy_spend(200, 60);
            t[0] = 0.0;
            t[1] = 15.0;
            t[2] = 3.0;
            addbullet(this, NULL, 801, (double)(120 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 801, (double)(120 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
          }
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 4 )
          {
            add_card_energy(50);
            play_sfx(3);
            field_190 = 1;
            spell_energy_spend(200, 60);
            t[0] = 0.0;
            t[1] = 15.0;
            t[2] = 3.0;
            addbullet(this, NULL, 801, (double)(120 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
          }
          return;
        case 412:
          if ( !get_subseq() || get_subseq() == 5 )
            sub10func();
          if ( get_subseq() >= 1 && get_subseq() <= 4 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
          {
            reset_forces();
            y = getlvl_height();
            set_subseq(5);
          }
          else
          {
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                v_inerc = 10.0;
                v_force = 0.30000001;
              }
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
                {
                  /*
                  v1233 = 0.0;
                  v398 = 6.0;
                  v399 = (float)0.0;
                  do
                  {
                    *(float *)&v1262 = v399 * 60.0;
                    v1263 = v398;
                    v1264 = 1.0;
                    v400 = dir;
                    v401 = sin_deg(*(float *)&v1262) * 100.0 + y + 100.0;
                    v402 = v401;
                    v403 = -*(float *)&v1262;
                    v404 = cos_deg(v403) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 801, v404, v402, v400, 1, (int)&v1262, 3);
                    *(float *)&v1262 = 0.0;
                    v1263 = 0.0;
                    v1264 = 0.0;
                    v405 = dir;
                    v406 = sin_deg(0.0) * 100.0 + y + 100.0;
                    v407 = v406;
                    v408 = -*(float *)&v1262;
                    v409 = cos_deg(v408) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 801, v409, v407, v405, 1, (int)&v1262, 3);
                    v1233 = v1233 + 1.0;
                    v398 = 6.0;
                    v399 = v1233;
                  }
                  while ( v1233 < 6.0 );
                  */
                  v_inerc = v_inerc * 0.25;
                  spell_energy_spend(200, 60);
                  add_card_energy(30);
                  play_sfx(3);
                  v_force = 0.0;
                  field_190 = 1;
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                  v_force = 0.30000001;
              }
            }
          }
          return;
        case 414:
          if ( get_subseq() == 2 )
            sub10func();
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 2 )
            goto LABEL_1208;
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( !get_subseq() && field_7D0 == 1 )
          {
            if ( !(field_7D2 % 5) && field_7D4 <= 5 )
            {
              play_sfx(2);
              field_190 = 1;
              add_card_energy(10);
              t[0] = (double)(-135 - 10 * field_7D4);
              t[1] = 8.0;
              t[2] = 1.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1, t, 3);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( get_subseq() == 1 && field_7D0 == 1 )
          {
            if ( !(field_7D2 % 3) && field_7D4 <= 9 )
            {
              play_sfx(2);
              field_190 = 1;
              add_card_energy(10);
              t[0] = (double)(-125 - 10 * field_7D4);
              t[1] = 8.0;
              t[2] = 1.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1, t, 3);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_2097;
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 5 && not_charge_attack )
            {
              scene_add_effect(this, 62, x, y + 155.0, dir, 1);
              next_subseq();
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 7 )
              {
                field_7D0 = 1;
                spell_energy_spend(200, 60);
              }
              if ( !get_frame_time() && get_frame() == 15 )
                v_force = 0.5;
            }
          }
          if ( get_subseq() != 1 || get_frame_time() )
            return;
          if ( get_frame() == 3 )
          {
            field_7D0 = 1;
            spell_energy_spend(200, 60);
          }
          goto LABEL_1247;
        case 415:
          if ( get_subseq() == 2 )
            sub10func();
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 2 )
          {
            set_subseq(2);
            goto LABEL_1938;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_2231;
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 6 )
            {
              add_card_energy(50);
              play_sfx(3);
              field_190 = 1;
              spell_energy_spend(200, 60);
              t[0] = 0.0;
              t[1] = 15.0;
              t[2] = 3.0;
              addbullet(this, NULL, 801, (double)(120 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(120 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
            }
            if ( !get_frame_time() && get_frame() == 15 )
              v_force = 0.5;
          }
          if ( get_subseq() != 1 || get_frame_time() )
            return;
          if ( get_frame() == 4 )
          {
            add_card_energy(50);
            play_sfx(3);
            field_190 = 1;
            spell_energy_spend(200, 60);
            t[0] = 0.0;
            t[1] = 15.0;
            t[2] = 3.0;
            addbullet(this, NULL, 801, (double)(120 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
          }
          goto LABEL_1247;
        case 416:
          if ( get_subseq() == 2 )
            sub10func();
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 2 )
          {
LABEL_1208:
            set_subseq(2);
            goto LABEL_1938;
          }
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( !get_subseq() && field_7D0 == 1 )
          {
            if ( !(field_7D2 % 5) && field_7D4 <= 5 )
            {
              play_sfx(2);
              field_190 = 1;
              add_card_energy(10);
              t[0] = (double)(10 * (field_7D4 + 12));
              t[1] = 8.0;
              t[2] = 1.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1, t, 3);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( get_subseq() == 1 && field_7D0 == 1 )
          {
            if ( !(field_7D2 % 3) && field_7D4 <= 9 )
            {
              play_sfx(2);
              field_190 = 1;
              add_card_energy(10);
              t[0] = (double)(10 * (field_7D4 + 12));
              t[1] = 8.0;
              t[2] = 1.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1, t, 3);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(57 * (char)dir) + x, y + 200.0, dir, 1, t, 3);
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_2097;
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 5 && not_charge_attack )
            {
              scene_add_effect(this, 62, x, y + 155.0, dir, 1);
              next_subseq();
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 7 )
              {
                field_7D0 = 1;
                spell_energy_spend(200, 60);
                add_card_energy(30);
              }
              if ( !get_frame_time() && get_frame() == 15 )
                v_force = 0.5;
            }
          }
          if ( get_subseq() == 1 && !get_frame_time() )
          {
            if ( get_frame() == 3 )
            {
              field_7D0 = 1;
              spell_energy_spend(200, 60);
              add_card_energy(30);
            }
LABEL_1247:
            if ( !get_frame_time() && get_frame() == 13 )
              v_force = 0.5;
          }
          return;
        case 418:
          if ( get_subseq() != 1 && (get_subseq() || get_frame() < 3) )
            goto LABEL_2744;
          v_inerc = v_inerc - v_force;
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          if ( !char_on_ground_down() )
          {
LABEL_2744:
            if ( !get_subseq() && get_frame() <= 2 || get_subseq() == 2 )
              sub10func();
            if ( process() )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                h_inerc = 15.0;
                v_inerc = 10.0;
                v_force = 0.5;
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 3 )
                  play_sfx(0);
                if ( !get_frame_time() && get_frame() == 4 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 7.0;
                  addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
                }
              }
            }
          }
          else
          {
            set_subseq(2);
            y = getlvl_height();
            reset_forces();
          }
          return;
        default:
          goto LABEL_2722;
      }
    }
    if ( get_seq() <= 770 )
    {
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
              goto LABEL_1380;
            if ( get_subseq() )
              return;
            if ( get_frame_time() )
              return;
            v466 = 4;
            if ( get_frame() != 4 )
              return;
            if ( skills_1[0] >= 1 )
              v466 = 5;
            if ( skills_1[0] >= 4 )
              v466 = 6;
            /*
            v468 = 0;
            v1607 = 6.0;
            v1608 = 12.0;
            if ( v466 > 0 )
            {
              v1197 = 0;
              do
              {
                v1609 = (double)(v468 & 3);
                *(float *)&v1606 = -110.0 - (double)v1197;
                v469 = dir;
                v470 = y + 177.0;
                v471 = v470;
                v472 = (double)(38 * (char)v469) + x;
                addbullet(this, NULL, 810, v472, v471, v469, 1, (int)&v1606, 4);
                v1197 += 10;
                ++v468;
              }
              while ( v468 < v466 );
            }*/
            goto LABEL_1310;
          case 502:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 0;
            if ( get_subseq() < 2 )
              v_inerc = v_inerc - v_force;
            if ( !get_subseq() && get_frame() >= 11 && char_on_ground_down() || get_subseq() == 1 && get_frame() >= 11 && char_on_ground_down() )
              goto LABEL_1351;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_2231;
            if ( get_subseq() || get_frame_time() )
              return;
            v473 = 4;
            if ( get_frame() != 4 )
              goto LABEL_1372;
            if ( skills_1[0] >= 1 )
              v473 = 5;
            if ( skills_1[0] >= 4 )
              v473 = 6;
            /*
            v475 = 0;
            v1615 = 6.0;
            v1616 = 12.0;
            if ( v473 > 0 )
            {
              v1198 = 0;
              do
              {
                v1617 = (double)(v475 & 3);
                *(float *)&v1614 = -20.0 - (double)v1198;
                v476 = dir;
                v477 = y + 177.0;
                v478 = v477;
                v479 = (double)(38 * (char)v476) + x;
                addbullet(this, NULL, 810, v479, v478, v476, 1, (int)&v1614, 4);
                v1198 += 10;
                ++v475;
              }
              while ( v475 < v473 );
            }*/
            goto LABEL_1371;
          case 503:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 0;
            if ( get_subseq() < 2 )
              v_inerc = v_inerc - v_force;
            if ( !get_subseq() && get_frame() >= 11 && char_on_ground_down() || get_subseq() == 1 && get_frame() >= 11 && char_on_ground_down() )
            {
LABEL_1351:
              set_subseq(2);
              goto LABEL_2620;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_2231;
            if ( get_subseq() || get_frame_time() )
              return;
            v480 = 4;
            if ( get_frame() == 4 )
            {
              if ( skills_1[0] >= 1 )
                v480 = 5;
              if ( skills_1[0] >= 4 )
                v480 = 6;
              /*
              v482 = 0;
              v1603 = 6.0;
              v1604 = 12.0;
              if ( v480 > 0 )
              {
                v1199 = 0;
                do
                {
                  v1605 = (double)(v482 & 3);
                  *(float *)&v1602 = -110.0 - (double)v1199;
                  v483 = dir;
                  v484 = y + 177.0;
                  v485 = v484;
                  v486 = (double)(38 * (char)v483) + x;
                  addbullet(this, NULL, 810, v486, v485, v483, 1, (int)&v1602, 4);
                  v1199 += 10;
                  ++v482;
                }
                while ( v482 < v480 );
              }*/
LABEL_1371:
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(10);
            }
LABEL_1372:
            if ( get_frame_time() )
              return;
            v487 = get_frame() == 11;
            goto LABEL_1598;
          case 505:
            sub10func();
            field_18C = 4;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            {
              if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
              {
                t[1] = 20.0;
                t[2] = 12.0;
                t[0] = -60.0;
                v1177 = y + 177.0;
                v490 = (double)(38 * dir) + x;
LABEL_1395:
                addbullet(this, NULL, 811, v490, v1177, dir, 1, t, 3);
                add_card_energy(50);
                spell_energy_spend(200, 120);
                play_sfx(6);
              }
            }
            else
            {
LABEL_1380:
              set_seq(0);
            }
            return;
          case 506:
            sub10func();
            field_18C = 4;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1616;
            if ( get_subseq() || get_frame_time() || get_frame() != 4 )
              return;
            t[1] = 20.0;
            t[2] = 12.0;
            t[0] = -45.0;
            v1177 = y + 177.0;
            v490 = (double)(38 * dir) + x;
            goto LABEL_1395;
          case 507:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 4;
            if ( get_subseq() < 2 )
              v_inerc = v_inerc - v_force;
            if ( !get_subseq() && get_frame() >= 11 && char_on_ground_down() || get_subseq() == 1 && get_frame() >= 11 && char_on_ground_down() )
              goto LABEL_1403;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_2097;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() != 4 )
              goto LABEL_1444;
            t[1] = 20.0;
            t[2] = 12.0;
            t[0] = -60.0;
            v1178 = y + 177.0;
            v496 = (double)(38 * dir) + x;
            goto LABEL_1443;
          case 508:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 4;
            if ( get_subseq() < 2 )
              v_inerc = v_inerc - v_force;
            if ( !get_subseq() && get_frame() >= 11 && char_on_ground_down() || get_subseq() == 1 && get_frame() >= 11 && char_on_ground_down() )
            {
LABEL_1403:
              set_subseq(2);
              goto LABEL_2620;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_2097;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() == 4 )
            {
              t[1] = 20.0;
              t[2] = 12.0;
              t[0] = -45.0;
              v1178 = y + 177.0;
              v496 = (double)(38 * dir) + x;
LABEL_1443:
              addbullet(this, NULL, 811, v496, v1178, dir, 1, t, 3);
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(6);
            }
LABEL_1444:
            if ( get_frame_time() )
              return;
            v487 = get_frame() == 11;
            goto LABEL_1598;
          case 510:
            sub10func();
            field_18C = 8;
            if ( field_7D0 == 1 )
            {
              if ( dash_angle < 30.0 )
              {
                tt[0] = 80.0 - dash_angle * 9.0;
                tt[1] = sin_deg(dash_angle * 10.0) * 20.0 + 2.0;
                tt[2] = 0.0;
                tt[3] = dash_angle;
                addbullet(this, NULL, 812, (cos_deg(-tt[0]) * 100.0 + dash_angle * 5.0 - 85.0) * (double)dir + x, sin_deg(-tt[0]) * 40.0 + y + 120.0, dir, 1, tt, 4);
              }
              dash_angle = dash_angle + 1.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1616;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(10);
              field_7D0 = 1;
            }
            return;
          case 511:
            if ( get_subseq() )
            {
              v_inerc = v_inerc - v_force;
              h_inerc = h_inerc + 0.25;
              if ( h_inerc > -2.0 )
                h_inerc = -2.0;
              if ( char_on_ground_down() )
              {
LABEL_1501:
                reset_forces();
                y = getlvl_height();
                set_seq(10);
                return;
              }
            }
            else
            {
              sub10func();
            }
            field_18C = 8;
            if ( get_subseq() == 1 )
            {
              if ( dash_angle < 30.0 )
              {
                tt[0] = -dash_angle * 9.0 - 20.0;
                tt[1] = sin_deg(dash_angle * 10.0) * 10.0 + 3.0;
                tt[2] = 6.0;
                tt[3] = dash_angle;
                addbullet(this, NULL, 812, cos_deg(-tt[0]) * 50.0 * (double)dir + x, sin_deg(-tt[0]) * 50.0 + y + 135.0, dir, 1, tt, 4);
              }
              dash_angle = dash_angle + 1.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(10);
              field_7D0 = 1;
              h_inerc = -15.0;
              v515 = 10.0;
LABEL_1513:
              v_inerc = v515;
              v_force = 0.34999999;
            }
            return;
          case 512:
            if ( get_subseq() == 1 )
              sub10func();
            if ( !get_subseq() && char_on_ground_down() )
            {
              reset_forces();
              y = getlvl_height();
              next_subseq();
              field_7D0 = 0;
            }
            field_18C = 8;
            if ( field_7D0 == 1 )
            {
              if ( dash_angle < 30.0 )
              {
                tt[0] = 80.0 - dash_angle * 9.0;
                tt[1] = sin_deg(dash_angle * 10.0) * 20.0 + 2.0;
                tt[2] = 0.0;
                tt[3] = dash_angle;
                addbullet(this, NULL, 812, (cos_deg(-tt[0]) * 100.0 + dash_angle * 5.0 - 85.0) * (double)dir + x, sin_deg(-tt[0]) * 40.0 + y + 120.0, dir, 1, tt, 4);
              }
              dash_angle = dash_angle + 1.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_2097;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                add_card_energy(50);
                spell_energy_spend(200, 120);
                play_sfx(10);
                field_7D0 = 1;
              }
              if ( !get_frame_time() && get_frame() == 11 )
                v_force = 0.5;
            }
            return;
          case 513:
            v_inerc = v_inerc - v_force;
            h_inerc = h_inerc + 0.25;
            if ( h_inerc > -2.0 )
              h_inerc = -2.0;
            if ( char_on_ground_down() )
              goto LABEL_1501;
            field_18C = 8;
            if ( get_subseq() == 1 )
            {
              if ( dash_angle < 30.0 )
              {
                tt[0] = 20.0 - dash_angle * 9.0;
                tt[1] = sin_deg(dash_angle * 10.0) * 10.0 + 3.0;
                tt[2] = 6.0;
                tt[3] = dash_angle;
                addbullet(this, NULL, 812, cos_deg(-tt[0]) * 50.0 * (double)dir + x, sin_deg(-tt[0]) * 50.0 + y + 135.0, dir, 1, tt, 4);
              }
              dash_angle = dash_angle + 1.0;
            }
            if ( process() )
              set_seq(9);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            add_card_energy(50);
            spell_energy_spend(200, 120);
            play_sfx(10);
            field_7D0 = 1;
            h_inerc = -15.0;
            v515 = 7.5;
            goto LABEL_1513;
          case 520:
            sub10func();
            field_18C = 1;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1616;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 815, (double)(95 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
              v1273 = 1.0;
              if ( skills_1[1] >= 1 )
                v1273 = 2.0;
              if ( skills_1[1] >= 3 )
                v1273 = 3.0;
              /*
              v535 = 0;
              v1200 = 0;
              do
              {
                *(float *)&v1271 = (double)v1200 - 10.0;
                v536 = dir;
                v537 = y + 150.0;
                v538 = v537;
                v539 = (double)(95 * (char)v536) + x;
                addbullet(this, NULL, 815, v539, v538, v536, 1, (int)&v1271, 3);
                v535 += 5;
                v1200 = v535;
              }
              while ( v535 < 25 );*/
              add_card_energy(50);
              play_sfx(12);
              spell_energy_spend(200, 120);
            }
            return;
          case 521:
            sub10func();
            field_18C = 1;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1616;
            if ( get_subseq() || get_frame_time() || get_frame() != 6 )
              return;
            field_190 = 1;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 815, (double)(95 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
            v1279 = 1.0;
            if ( skills_1[1] >= 1 )
              v1279 = 2.0;
            if ( skills_1[1] >= 3 )
              v1279 = 3.0;
            /*
            v544 = 0;
            v1201 = 0;
            do
            {
              *(float *)&v1277 = (double)v1201 - 16.0;
              v545 = dir;
              v546 = y + 150.0;
              v547 = v546;
              v548 = (double)(95 * (char)v545) + x;
              addbullet(this, NULL, 815, v548, v547, v545, 1, (int)&v1277, 3);
              v544 += 8;
              v1201 = v544;
            }
            while ( v544 < 40 );*/
            play_sfx(12);
            goto LABEL_1621;
          case 522:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 1;
            if ( get_subseq() <= 1 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1576;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_2097;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                field_190 = 1;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 815, (double)(95 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
                v1282 = 1.0;
                if ( skills_1[1] >= 1 )
                  v1282 = 2.0;
                if ( skills_1[1] >= 3 )
                  v1282 = 3.0;
                /*
                v553 = 0;
                v1202 = 0;
                do
                {
                  *(float *)&v1280 = (double)v1202 - 10.0;
                  v554 = dir;
                  v555 = y + 150.0;
                  v556 = v555;
                  v557 = (double)(95 * (char)v554) + x;
                  addbullet(this, NULL, 815, v557, v556, v554, 1, (int)&v1280, 3);
                  v553 += 5;
                  v1202 = v553;
                }
                while ( v553 < 25 );*/
                play_sfx(12);
                add_card_energy(50);
                spell_energy_spend(200, 120);
              }
              if ( !get_frame_time() && get_frame() == 17 )
                v_force = 0.40000001;
            }
            return;
          case 523:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 1;
            if ( get_subseq() <= 1 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1576:
                set_subseq(2);
                y = getlvl_height();
                reset_forces();
                return;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_2097;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                field_190 = 1;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 815, (double)(95 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
                v1276 = 1.0;
                if ( skills_1[1] >= 1 )
                  v1276 = 2.0;
                if ( skills_1[1] >= 3 )
                  v1276 = 3.0;
                /*
                v562 = 0;
                v1203 = 0;
                do
                {
                  *(float *)&v1274 = (double)v1203 - 16.0;
                  v563 = dir;
                  v564 = y + 150.0;
                  v565 = v564;
                  v566 = (double)(95 * (char)v563) + x;
                  addbullet(this, NULL, 815, v566, v565, v563, 1, (int)&v1274, 3);
                  v562 += 8;
                  v1203 = v562;
                }
                while ( v562 < 40 );*/
                play_sfx(12);
                add_card_energy(50);
                spell_energy_spend(200, 120);
              }
              if ( !get_frame_time() )
              {
                v487 = get_frame() == 17;
LABEL_1598:
                if ( v487 )
                  v_force = 0.40000001;
              }
            }
            return;
          case 525:
            sub10func();
            field_18C = 5;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1616;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 20.0;
              t[2] = 12.0;
              addbullet(this, NULL, 816, (double)(95 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
              t[2] = 1.0;
              play_sfx(16);
              add_card_energy(50);
              spell_energy_spend(200, 120);
            }
            return;
          case 526:
            sub10func();
            field_18C = 5;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            {
              if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
              {
                field_190 = 1;
                t[0] = 0.0;
                t[1] = 20.0;
                t[2] = 12.0;
                addbullet(this, NULL, 816, (double)(95 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
                t[2] = 1.0;
                play_sfx(16);
LABEL_1621:
                add_card_energy(50);
                spell_energy_spend(200, 120);
              }
            }
            else
            {
LABEL_1616:
              set_seq(0);
            }
            return;
          case 530:
            sub10func();
            field_18C = 9;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( field_7D0 == 1 )
            {
              if ( !(field_7D4 % 6) && field_7D2 > 0 )
              {
                tt[0] = (double)scene_rand_rng(30) * 0.1000000014901161 + 7.0;
                tt[1] = (double)scene_rand_rng(30) * 0.1000000014901161 + 10.0;
                tt[2] = 1.0;
                tt[3] = 2.0;
                if ( skills_1[9] >= 2 )
                  tt[3] = 3.0;
                if ( skills_1[9] >= 4 )
                  tt[3] = 4.0;
                addbullet(this, NULL, 817, (double)(54 * (char)dir) + x, y + 162.0, dir, 1, tt, 4);
                --field_7D2;
                field_190 = 1;
              }
              ++field_7D4;
            }
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 7 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(19);
              field_7D0 = 1;
              field_7D2 = 3;
              if ( skills_1[9] >= 3 )
                field_7D2 = 4;
            }
            return;
          case 531:
            sub10func();
            field_18C = 9;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( field_7D0 == 1 )
            {
              if ( !(field_7D4 % 6) && field_7D2 > 0 )
              {
                tt[0] = (double)scene_rand_rng(30) * 0.1000000014901161 + 7.0;
                tt[1] = (double)scene_rand_rng(30) * 0.1000000014901161 + 10.0;
                tt[2] = 1.0;
                tt[3] = 2.0;
                if ( skills_1[9] >= 2 )
                  tt[3] = 3.0;
                if ( skills_1[9] >= 4 )
                  tt[3] = 4.0;
                addbullet(this, NULL, 817, (double)(54 * (char)dir) + x, y + 162.0, dir, 1, tt, 4);
                --field_7D2;
                field_190 = 1;
              }
              ++field_7D4;
            }
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 7 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(19);
              field_7D0 = 1;
              field_7D2 = 4;
              if ( skills_1[9] >= 3 )
                field_7D2 = 5;
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
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(13);
              field_190 = 1;
              /*
              v583 = 0;
              v1204 = 0;
              v1222 = 0;
              do
              {
                a1 = (double)v1222;
                v1590 = 300.0;
                v1591 = 4.0;
                v584 = dir;
                v585 = (double)v1204;
                v586 = v585 - 6.0;
                v587 = sin_deg(v586) * 300.0 + y + 170.0;
                v588 = v585 * 60.0;
                v589 = (cos_deg(v588) * 300.0 + 50.0) * (double)dir + x;
                addbullet(this, NULL, 820, v589, v587, v584, 1, (int)&a1, 3);
                ++v1204;
                v583 += 60;
                v1222 = v583;
              }
              while ( v583 < 360 );
              */
            }
            return;
          case 541:
            sub10func();
            field_18C = 2;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(13);
              field_190 = 1;
              /*
              v590 = 0;
              v1205 = 0;
              v1223 = 0;
              do
              {
                *(float *)&v1472 = (double)v1223;
                v1473 = 300.0;
                v1474 = 0.0;
                v591 = dir;
                v592 = (double)v1205;
                v593 = v592 - 6.0;
                v594 = sin_deg(v593) * 300.0 + y + 170.0;
                v595 = v592 * 60.0;
                v596 = (cos_deg(v595) * 300.0 + 50.0) * (double)dir + x;
                addbullet(this, NULL, 820, v596, v594, v591, 1, (int)&v1472, 3);
                ++v1205;
                v590 += 60;
                v1223 = v590;
              }
              while ( v590 < 360 );
              */
            }
            return;
          case 542:
            if ( get_subseq() == 4 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1722;
            }
            field_18C = 2;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_1693;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
              goto LABEL_2231;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              v_force = 0.5;
LABEL_1693:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(13);
              //v597 = 0;
              field_190 = 1;
              /*v1206 = 0;
              v1224 = 0;
              do
              {
                *(float *)&v1544 = (double)v1224;
                v1545 = 300.0;
                v1546 = 4.0;
                v598 = dir;
                v599 = (double)v1206;
                v600 = v599 - 6.0;
                v601 = sin_deg(v600) * 300.0 + y + 170.0;
                v602 = v599 * 60.0;
                v603 = (cos_deg(v602) * 300.0 + 50.0) * (double)dir + x;
                addbullet(this, NULL, 820, v603, v601, v598, 1, (int)&v1544, 3);
                ++v1206;
                v597 += 60;
                v1224 = v597;
              }
              while ( v597 < 360 );*/
            }
            return;
          case 543:
            if ( get_subseq() == 4 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1722:
                set_subseq(4);
                y = getlvl_height();
                reset_forces();
                return;
              }
            }
            field_18C = 2;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_1714;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
              goto LABEL_2231;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              v_force = 0.5;
LABEL_1714:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(13);
              //v604 = 0;
              field_190 = 1;
              /*v1207 = 0;
              v1225 = 0;
              do
              {
                *(float *)&v1478 = (double)v1225;
                v1479 = 300.0;
                v1480 = 0.0;
                v605 = dir;
                v606 = (double)v1207;
                v607 = v606 - 6.0;
                v608 = sin_deg(v607) * 300.0 + y + 170.0;
                v609 = v606 * 60.0;
                v610 = (cos_deg(v609) * 300.0 + 50.0) * (double)dir + x;
                addbullet(this, NULL, 820, v610, v608, v605, 1, (int)&v1478, 3);
                ++v1207;
                v604 += 60;
                v1225 = v604;
              }
              while ( v604 < 360 );*/
            }
            return;
          case 545:
            sub10func();
            field_18C = 6;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1742;
            if ( get_subseq() != 1 )
              return;
            add_card_energy(50);
            spell_energy_spend(200, 120);
            play_sfx(18);
            field_190 = 1;
            t[0] = 0.0;
            t[1] = 10.0;
            t[2] = 0.0;
            v1179 = y + 180.0;
            v613 = (double)(55 * dir) + x;
            goto LABEL_1741;
          case 546:
            sub10func();
            field_18C = 6;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1742;
            if ( get_subseq() == 1 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(18);
              field_190 = 1;
              t[0] = -90.0;
              t[1] = 10.0;
              t[2] = 0.0;
              v1179 = y + 180.0;
              v613 = (double)(55 * dir) + x;
LABEL_1741:
              addbullet(this, NULL, 821, v613, v1179, dir, 1, t, 3);
LABEL_1742:
              if ( get_subseq() == 1 )
              {
                if ( (v617 = get_elaps_frames(), v617 >= 24) && !not_charge_attack || v617 >= 20 * ((char)skills_1[6] + 3) )
                  next_subseq();
              }
            }
            return;
          case 550:
            if ( !get_subseq() || get_subseq() == 6 )
              sub10func();
            if ( get_subseq() == 1 )
            {
              if ( field_190 == 1 || field_190 == 7 )
              {
                set_subseq(3);
                play_sfx(21);
                reset_forces();
                enemy->set_seq(101);
                enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
                enemy->y = y - (double)get_pframe()->extra1[5];
                //sub_4867F0(1, y);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 822, (double)(67 * (char)dir) + x, y - 150.0, dir, 1, t, 3);
                return;
              }
            }
            if ( get_subseq() == 2 || get_subseq()  == 4 || get_subseq()  == 5 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                y = getlvl_height();
                set_subseq(6);
                reset_forces();
                return;
              }
            }
            if ( get_subseq() == 3 )
            {
              enemy->field_571 = 0;
              field_7DC = field_7DC - 0.5;
              if ( field_7DC < 0.0 )
                field_7DC = 0.0;
              //set_vec_speed((render_class *)&cEffectSprite, -45.0, field_7DC);
              enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
              enemy->y = y - (double)get_pframe()->extra1[5];
              if ( get_elaps_frames() >= 60 )
              {
                next_subseq();
                enemy->set_seq(101);
                enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
                enemy->y = y - (double)get_pframe()->extra1[5];
                return;
              }
            }
            field_18C = 10;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_7DC = 10.0;
              //set_vec_speed((render_class *)&cEffectSprite, -45.0, 10.0);
              v_force = 0.40000001;
              play_sfx(20);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL, 822, (double)(51 * (char)dir) + x, y - 157.0, dir, -1, t, 3);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              goto LABEL_2097;
            if ( get_subseq() != 1 )
              goto LABEL_1780;
            if ( get_elaps_frames() >= 30 )
              goto LABEL_1818;
            field_194 = enemy->getlvl_height() < enemy->y;
LABEL_1780:
            if ( get_subseq() == 4 )
            {
              if ( !get_frame() )
              {
                enemy->field_571 = 0;
                enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
                enemy->y = y - (double)get_pframe()->extra1[5];
              }
              if ( !get_frame_time() && get_frame() == 1 )
              {
                enemy->field_571 = 1;
                enemy->field_1A4 = 3.0;
                enemy->field_1A8 = 7.5;
                enemy->field_4BA = 6000;
                enemy->damage_limit = 100;
                enemy->set_seq(71);
                enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
                enemy->y = y - (double)get_pframe()->extra1[5];
                //sub_4867F0(0, 0.0);
                sub_464110(((double)(weather_id == 4) * 0.25 + 1.0) * (((double)(char)skills_1[10] * 0.1000000014901161 + 1.0) * 1000.0), 850, 1, 1);
                h_inerc = -3.0;
                v_inerc = 2.0;
                v_force = 0.30000001;
                if ( field_8A4 < 8 )
                {
                  tt[0] = 0.0;
                  tt[1] = 0.0;
                  tt[2] = 3.0;
                  tt[3] = (double)field_8A4 * 45.0;
                  addbullet(this, NULL, 822, (double)(63 * (char)dir) + x, y + 145.0, dir, 1, tt, 4);
                  ++field_8A4;
                }
                play_sfx(11);
                field_8A8 = 30 * (char)skills_1[10] + 20 * (field_8A4 + 1);
              }
            }
            return;
          case 551:
            if ( !get_subseq() || get_subseq() == 6 )
              sub10func();
            if ( get_subseq() == 1 )
            {
              if ( field_190 == 1 || field_190 == 7 )
              {
                play_sfx(21);
                set_subseq(3);
                reset_forces();
                enemy->set_seq(101);
                enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
                enemy->y = y - (double)get_pframe()->extra1[5];
                //sub_4867F0(1, y);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 822, (double)(67 * (char)dir) + x,  y - 150.0, dir, 1, t, 3);
                return;
              }
            }
            if ( get_subseq() == 2 || get_subseq() == 4 || get_subseq() == 5 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                y = getlvl_height();
                set_subseq(6);
                reset_forces();
                return;
              }
            }
            if ( get_subseq() == 3 )
            {
              enemy->field_571 = 0;
              field_7DC = field_7DC - 0.5;
              if ( field_7DC < 0.0 )
                field_7DC = 0.0;
              //set_vec_speed((render_class *)&cEffectSprite, -45.0, field_7DC);
              enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
              enemy->y = y - (double)get_pframe()->extra1[5];
              if ( get_elaps_frames() >= 60 )
              {
                next_subseq();
                enemy->set_seq(101);
                enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
                enemy->y = y - (double)get_pframe()->extra1[5];
                return;
              }
            }
            field_18C = 10;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(20);
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_7DC = 15.0;
              //set_vec_speed((render_class *)&cEffectSprite, -45.0, 15.0);
              v_force = 0.40000001;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL, 822, (double)(51 * (char)dir) + x, y - 157.0, dir, -1, t, 3);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              goto LABEL_2097;
            if ( get_subseq() != 1 )
              goto LABEL_1822;
            if ( get_elaps_frames() < 30 )
            {
              field_194 = enemy->getlvl_height() < enemy->y;
LABEL_1822:
              if ( get_subseq() == 4 )
              {
                if ( !get_frame() )
                {
                  enemy->field_571 = 0;
                  enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
                  enemy->y = y - (double)get_pframe()->extra1[5];
                }
                if ( !get_frame_time() && get_frame() == 1 )
                {
                  enemy->field_571 = 1;
                  enemy->field_1A4 = 3.0;
                  enemy->field_1A8 = 7.5;
                  enemy->field_4BA = 6000;
                  enemy->damage_limit = 100;
                  enemy->set_seq(71);
                  enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
                  enemy->y = y - (double)get_pframe()->extra1[5];
                  //sub_4867F0(0, 0.0);
                  v1208 = 1000.0;
                  if ( weather_id == 4 )
                    v1208 = 1250.0;
                  sub_464110(((double)(char)skills_1[10] * 0.1000000014901161 + 1.0) * v1208, 850, 1, 1);
                  h_inerc = -3.0;
                  v_inerc = 2.0;
                  v_force = 0.30000001;
                  if ( field_8A4 < 8 )
                  {
                    tt[0] = 0.0;
                    tt[1] = 0.0;
                    tt[2] = 3.0;
                    tt[3] = (double)field_8A4 * 45.0;
                    addbullet(this, NULL, 822, (double)(63 * (char)dir) + x, y + 145.0, dir, 1, tt, 4);
                    ++field_8A4;
                  }
                  play_sfx(11);
                  field_8A8 = 30 * (char)skills_1[10] + 20 * (field_8A4 + 1);
                }
              }
            }
            else
            {
LABEL_1818:
              h_inerc = h_inerc * 0.75;
              v_inerc = v_inerc * 0.800000011920929;
              next_subseq();
            }
            return;
          case 560:
            sub10func();
            field_18C = 3;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_1846;
            v679 = 4;
            if ( skills_1[3] >= 1 )
              v679 = 0;
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 9.0 )
              h_inerc = 9.0;
            if ( get_elaps_frames() >= 25 || (enemy->x - x) * (double)dir <= 120.0 && get_elaps_frames() >= v679 )
              goto LABEL_1907;
            /*
            v683 = get_elaps_frames() & 0x80000001;
            v682 = (get_elaps_frames() & 0x80000001) == 0;
            if ( v683 < 0 )
              v682 = (((_BYTE)v683 - 1) | 0xFFFFFFFE) == -1;
            */
            if ( (get_elaps_frames() & 0x80000001) == 0 ) //v682
            {
              t[0] = (double)scene_rand_rng(360);
              t[1] = (double)scene_rand_rng(50) * 0.1000000014901161 + 5.0;
              t[2] = 1.0;
              addbullet(this, NULL, 825, x + 50.0 - (double)scene_rand_rng(100), (double)scene_rand_rng(200) + y, dir, 1, t, 3);
            }
LABEL_1846:
            
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
              if ( get_frame() <= 4 && !(get_elaps_frames() % 4) )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 825, (double)(56 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
                
              }
            }
            if ( get_subseq() == 3 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
              if ( get_frame() <= 4 && !(get_elaps_frames() % 2) )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 825, (double)(56 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                h_inerc = 15.0;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                play_sfx(14);
                scene_add_effect(this, 127, x, y, dir, -1);
              }
            }
            if ( (get_subseq() == 2 || get_subseq() == 3) && !get_frame_time() && get_frame() == 2 )
              play_sfx(11);
            if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 2 )
            {
              /*
              v701 = 12;
              v1321 = 2.0;
              do
              {
                *(float *)&v1319 = -(double)scene_rand_rng(360);
                v1320 = (double)scene_rand_rng(15) + 10.0;
                v702 = -*(float *)&v1319;
                HIDWORD(v703) = (1 - 2 * (sin_deg(v702) > 0.0));
                (v703) = dir;
                v704 = v703;
                v705 = -*(float *)&v1319;
                v706 = sin_deg(v705) * 20.0 + y;
                v707 = v706;
                v708 = -*(float *)&v1319;
                v709 = cos_deg(v708) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 825, v709, v707, v704, SHIDWORD(v704), (int)&v1319, 3);
                --v701;
              }
              while ( v701 );*/
            }
            return;
          case 561:
            sub10func();
            field_18C = 3;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_1895;
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 11.0 )
              h_inerc = 11.0;
            v711 = 8;
            if ( skills_1[3] >= 1 )
              v711 = 4;
            if ( get_elaps_frames() >= 40 || (enemy->x - x) * (double)dir <= 120.0 && get_elaps_frames() >= v711 )
            {
LABEL_1907:
              next_subseq();
              if ( skills_1[3] >= 3 )
                set_subseq(3);
            }
            else
            {
              /*
              v714 = get_elaps_frames() & 0x80000001;
              v713 = (get_elaps_frames() & 0x80000001) == 0;
              if ( v714 < 0 )
                v713 = (((_BYTE)v714 - 1) | 0xFFFFFFFE) == -1;
                */
              if ( (get_elaps_frames() & 0x80000001) == 0 ) //v713
              {
                t[0] = (double)scene_rand_rng(360);
                t[1] = (double)scene_rand_rng(50) * 0.1000000014901161 + 5.0;
                t[2] = 1.0;
                addbullet(this, NULL, 825, x + 50.0 - (double)scene_rand_rng(100), (double)scene_rand_rng(200) + y, dir, 1, t, 3);
              }
LABEL_1895:
              
              if ( get_subseq() == 2 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
                if ( get_frame() <= 4 && !(get_elaps_frames() % 4) )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 825, (double)(56 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
                  
                }
              }
              if ( get_subseq() == 3 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
                if ( get_frame() <= 4 && !(get_elaps_frames() % 2) )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 825, (double)(56 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
                }
              }
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
                  set_seq(0);
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  h_inerc = 15.0;
                  play_sfx(14);
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  scene_add_effect(this, 127, x, y, dir, -1);
                }
              }
              if ( (get_subseq() == 2 || get_subseq() == 3) && !get_frame_time() && get_frame() == 2 )
                play_sfx(11);
              if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 2 )
              {
                /*
                v732 = 12;
                v1318 = 2.0;
                do
                {
                  *(float *)&v1316 = -(double)scene_rand_rng(360);
                  v1317 = (double)scene_rand_rng(15) + 10.0;
                  v733 = -*(float *)&v1316;
                  HIDWORD(v734) = (1 - 2 * (sin_deg(v733) > 0.0));
                  (v734) = dir;
                  v735 = v734;
                  v736 = -*(float *)&v1316;
                  v737 = sin_deg(v736) * 20.0 + y;
                  v738 = v737;
                  v739 = -*(float *)&v1316;
                  v740 = cos_deg(v739) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 825, v740, v738, v735, SHIDWORD(v735), (int)&v1316, 3);
                  --v732;
                }
                while ( v732 );*/
              }
            }
            return;
          case 562:
            if ( get_subseq() == 5 )
              sub10func();
            field_18C = 3;
            v_inerc = v_inerc - v_force;
            if ( getlvl_height() >= (v_inerc + y) && v_inerc < 0.0 && get_subseq() < 5 )
            {
              set_subseq(5);
LABEL_1938:
              v_force = 0.0;
LABEL_1939:
              air_dash_cnt = 0;
LABEL_1940:
              y = getlvl_height();
              reset_forces();
              return;
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
                    t[0] = (double)field_7D4 + 30.0 - scene_rand() % 60 - 30.0;
                    t[1] = 15.0;
                    t[2] = (double)scene_rand_rng(4);
                  }
                  else
                  {
                    t[0] = (double)field_7D4 + 30.0 - scene_rand() % 60 - 30.0;
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
              goto LABEL_2231;
            if ( get_subseq() == 1 && get_elaps_frames() > 4 && (!not_charge_attack || get_elaps_frames() > 25) )
              next_subseq();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              if ( not_charge_attack == 1 )
              {
                scene_add_effect(this, 62, x - (double)(23 * (char)dir),  y + 107.0, dir, 1);
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
            if ( get_subseq() == 4 && !get_frame_time() )
            {
              v232 = get_frame() == 5;
              goto LABEL_1987;
            }
            return;
          case 565:
            if ( get_frame() >= 7 )
              sub10func();
            field_18C = 7;
            h_inerc = h_inerc + 0.5;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_2000;
            if ( !get_frame_time() )
            {
              if ( !get_frame() && get_subseq() == 1 )
                set_seq(0);
LABEL_2000:
              if ( !get_frame_time() )
              {
                if ( get_frame() == 1 )
                  h_inerc = -20.0;
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 2 )
                  {
                    play_sfx(17);
                    spell_energy_spend(200, 120);
                    add_card_energy(50);
                    t[0] = (double)scene_rand_rng(360);
                    t[1] = 0.0;
                    t[2] = 0.0;
                    if ( get_subseq() == 1 )
                      t[2] = 5.0;
                    addbullet(this, NULL, 826, (double)(45 * (char)dir) + x, y + 26.0, dir, 1, t, 3);
                  }
                  if ( !get_frame_time() )
                  {
                    if ( get_frame() == 3 )
                    {
                      t[0] = (double)scene_rand_rng(360);
                      t[1] = 0.0;
                      t[2] = 0.0;
                      if ( get_subseq() == 1 )
                        t[2] = 5.0;
                      addbullet(this, NULL, 826, (double)(58 * (char)dir) + x, y + 217.0, dir, 1, t, 3);
                    }
                    if ( !get_frame_time() )
                    {
                      if ( get_frame() == 4 )
                      {
                        t[0] = (double)scene_rand_rng(360);
                        t[1] = 0.0;
                        t[2] = 0.0;
                        if ( get_subseq() == 1 )
                          t[2] = 5.0;
                        addbullet(this, NULL, 826, (double)(5 * (char)dir) + x, y + 266.0, dir, 1, t, 3);
                      }
                      if ( !get_frame_time() )
                      {
                        if ( get_frame() == 5 )
                        {
                          t[0] = (double)scene_rand_rng(360);
                          t[1] = 0.0;
                          t[2] = 0.0;
                          if ( get_subseq() == 1 )
                            t[2] = 5.0;
                          addbullet(this, NULL, 826, x - (double)((char)dir << 6), y + 234.0, dir, 1, t, 3);
                        }
                        if ( !get_frame_time() && get_frame() == 6 )
                        {
                          t[0] = (double)scene_rand_rng(360);
                          t[1] = 0.0;
                          t[2] = 0.0;
                          if ( get_subseq() == 1 )
                            t[2] = 5.0;
                          addbullet(this, NULL, 826, x - (double)(90 * (char)dir), y + 132.0, dir, 1, t, 3);
                        }
                      }
                    }
                  }
                }
              }
            }
            return;
          case 566:
            if ( get_frame() >= 7 )
              sub10func();
            field_18C = 7;
            h_inerc = h_inerc + 0.5;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_2039;
            if ( !get_frame_time() )
            {
              if ( !get_frame() && get_subseq() == 1 )
                set_seq(0);
LABEL_2039:
              if ( !get_frame_time() )
              {
                if ( get_frame() == 1 )
                  h_inerc = -20.0;
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 2 )
                  {
                    play_sfx(17);
                    spell_energy_spend(200, 120);
                    add_card_energy(50);
                    t[0] = (double)scene_rand_rng(360);
                    t[1] = 0.0;
                    t[2] = 0.0;
                    if ( get_subseq() == 1 )
                      t[2] = 5.0;
                    addbullet(this, NULL, 826, (double)(45 * (char)dir) + x, y + 26.0, dir, 1, t, 3);
                  }
                  if ( !get_frame_time() )
                  {
                    if ( get_frame() == 3 )
                    {
                      t[0] = (double)scene_rand_rng(360);
                      t[1] = 0.0;
                      t[2] = 0.0;
                      if ( get_subseq() == 1 )
                        t[2] = 5.0;
                      addbullet(this, NULL, 826, (double)(58 * (char)dir) + x, y + 217.0, dir, 1, t, 3);
                    }
                    if ( !get_frame_time() )
                    {
                      if ( get_frame() == 4 )
                      {
                        t[0] = (double)scene_rand_rng(360);
                        t[1] = 0.0;
                        t[2] = 0.0;
                        if ( get_subseq() == 1 )
                          t[2] = 5.0;
                        addbullet(this, NULL, 826, (double)(5 * (char)dir) + x, y + 266.0, dir, 1, t, 3);
                      }
                      if ( !get_frame_time() )
                      {
                        if ( get_frame() == 5 )
                        {
                          t[0] = (double)scene_rand_rng(360);
                          t[1] = 0.0;
                          t[2] = 0.0;
                          if ( get_subseq() == 1 )
                            t[2] = 5.0;
                          addbullet(this, NULL, 826, x - (double)((char)dir << 6), y + 234.0, dir, 1, t, 3);
                        }
                        if ( !get_frame_time() && get_frame() == 6 )
                        {
                          t[0] = (double)scene_rand_rng(360);
                          t[1] = 0.0;
                          t[2] = 0.0;
                          if ( get_subseq() == 1 )
                            t[2] = 5.0;
                          addbullet(this, NULL, 826, x - (double)(90 * (char)dir), y + 132.0, dir, 1, t, 3);
                        }
                      }
                    }
                  }
                }
              }
            }
            return;
          case 567:
            if ( get_subseq() == 2 )
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
                set_subseq(2);
                return;
              }
            }
            field_18C = 7;
            h_inerc = h_inerc + 0.5;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_2097;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                h_inerc = -20.0;
                v_inerc = 10.0;
                v_force = 0.34999999;
                play_sfx(17);
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = (double)scene_rand_rng(360);
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 826, (double)(80 * (char)dir) + x, y + 40.0, dir, 1, t, 3);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 3 )
                {
                  t[0] = (double)scene_rand_rng(360);
                  t[1] = 0.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 826, (double)(95 * (char)dir) + x, y + 230.0, dir, 1, t, 3);
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 4 )
                  {
                    t[0] = (double)scene_rand_rng(360);
                    t[1] = 0.0;
                    t[2] = 0.0;
                    addbullet(this, NULL, 826, (double)(20 * (char)dir) + x, y + 290.0, dir, 1, t, 3);
                  }
                  if ( !get_frame_time() )
                  {
                    if ( get_frame() == 5 )
                    {
                      t[0] = (double)scene_rand_rng(360);
                      t[1] = 0.0;
                      t[2] = 0.0;
                      addbullet(this, NULL, 826, x - (double)(80 * (char)dir), y + 250.0, dir, 1, t, 3);
                    }
                    if ( !get_frame_time() && get_frame() == 6 )
                    {
                      t[0] = (double)scene_rand_rng(360);
                      t[1] = 0.0;
                      t[2] = 0.0;
                      addbullet(this, NULL, 826, x - (double)(110 * (char)dir), y + 160.0, dir, 1, t, 3);
                    }
                  }
                }
              }
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 50 )
              goto LABEL_2097;
            return;
          case 570:
            sub10func();
            field_18C = 11;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( h_inerc > 0.0 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_2115;
            if ( !get_frame_time() )
            {
              if ( !get_frame() && get_subseq() == 2 )
                set_seq(0);
LABEL_2115:
              if ( !get_frame_time() && get_frame() == 8 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 2.0;
                if ( get_subseq() == 1 )
                  t[2] = 0.0;
                if ( get_subseq() == 2 )
                  t[2] = 3.0;
                addbullet(this, NULL, 827, x, y, dir, 1, t, 3);
                h_inerc = 8.0;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                play_sfx(22);
                scene_add_effect(this, 127, x, y, dir, -1);
              }
            }
            return;
          case 571:
            sub10func();
            field_18C = 11;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( h_inerc > 0.0 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 2 )
              goto LABEL_2137;
            if ( skills_1[11] < 4 )
            {
              if ( skills_1[11] < 2 )
              {
LABEL_2137:
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                  set_seq(0);
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
                  set_seq(0);
                if ( (get_subseq() == 2 || get_subseq() == 3 || get_subseq() == 4) && !get_frame_time() && get_frame() == 1 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 2.0;
                  if ( get_subseq() == 3 )
                    t[2] = 0.0;
                  if ( get_subseq() == 4 )
                    t[2] = 3.0;
                  addbullet(this, NULL, 827, x, y, dir, 1, t, 3);
                  h_inerc = 12.5;
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  play_sfx(22);
                  scene_add_effect(this, 127, x, y, dir, -1);
                }
              }
              else
              {
LABEL_2136:
                set_subseq(3);
              }
            }
            else
            {
              set_subseq(4);
            }
            return;
          case 599:
            if ( field_7D0 > 0 && get_frame() < 7 && field_7D0 < 12 )
            {
              field_7D4 = scene_rand() % 0x23u;
              t[0] = (double)(-20 - field_7D4);
              t[1] = (double)(scene_rand() % 5u + 10);
              t[2] = 0.0;
              addbullet(this, NULL, 807, (double)(20 * (char)dir * (field_7D0 + 1)) + x, y, dir, 1, t, 3);
              t[0] = scene_rand() % 360;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 801, (double)(20 * (char)dir * (field_7D0 + 1)) + x, y, dir, 1, t, 3);
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
            sub_46AB50(2, 2);
            if ( get_subseq() == 2 && get_elaps_frames() >= 72 )
              goto LABEL_2575;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              //get_elaps_frames() = 0;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x, y + 125.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 4 )
              {
                /*
                v1234 = 0.0;
                v841 = (float)0.0;
                do
                {
                  v842 = v841 * 30.0;
                  v843 = v842;
                  *(float *)&v844 = v842;
                  v1246 = v844;
                  v1247 = 4.0;
                  v1248 = 0.0;
                  v845 = dir;
                  v846 = -*(float *)&v844;
                  v847 = sin_deg(v846) * 100.0 + y + 100.0;
                  v848 = v847;
                  v849 = -*(float *)&v1246;
                  v850 = cos_deg(v849) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 850, v850, v848, v845, 1, (int)&v1246, 3);
                  v1246 = v844;
                  v1247 = 4.0;
                  v1248 = 0.0;
                  v851 = x;
                  v852 = -dir;
                  v853 = -*(float *)&v844;
                  v854 = sin_deg(v853) * 100.0 + y + 100.0;
                  v855 = v854;
                  v856 = -*(float *)&v1246;
                  v857 = v851 - cos_deg(v856) * 100.0 * (double)dir;
                  addbullet(this, NULL, 850, v857, v855, v852, 1, (int)&v1246, 3);
                  *(float *)&v858 = v843 + 15.0;
                  v1246 = v858;
                  v1247 = 7.0;
                  v1248 = 2.0;
                  v859 = dir;
                  v860 = -*(float *)&v858;
                  v861 = sin_deg(v860) * 100.0 + y + 100.0;
                  v862 = v861;
                  v863 = -*(float *)&v1246;
                  v864 = cos_deg(v863) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 850, v864, v862, v859, 1, (int)&v1246, 3);
                  v1246 = v858;
                  v1247 = 7.0;
                  v1248 = 2.0;
                  v865 = x;
                  v866 = -dir;
                  v867 = -*(float *)&v858;
                  v868 = sin_deg(v867) * 100.0 + y + 100.0;
                  v869 = v868;
                  v870 = -*(float *)&v1246;
                  v871 = v865 - cos_deg(v870) * 100.0 * (double)dir;
                  addbullet(this, NULL, 850, v871, v869, v866, 1, (int)&v1246, 3);
                  v1234 = v1234 + 1.0;
                  v841 = v1234;
                }
                while ( v1234 < 12.0 );
                */
                play_sfx(50);
              }
            }
            return;
          case 601:
            sub10func();
            sub_46AB50(2, 2);
            if ( get_subseq() == 1 && get_elaps_frames() >= 48 )
              goto LABEL_2309;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 4.0;
              addbullet(this, NULL, 851, (double)(105 * (char)dir) + x, y + 146.0, dir, 1, t, 3);
              play_sfx(51);
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(40 * (char)dir), y + 150.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            return;
          case 602:
            sub10func();
            sub_46AB50(2, 2);
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 7 )
              {
                t[0] = 0.0;
                t[1] = 25.0;
                t[2] = 0.0;
                addbullet(this, NULL, 852, (double)(85 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
                play_sfx(52);
              }
              if ( !get_frame_time() && get_frame() == 2 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(80 * (char)dir), y + 145.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
            }
            return;
          case 603:
            sub10func();
            sub_46AB50(2, 2);
            if ( get_subseq() == 2 && field_7D2 >= 120 )
              goto LABEL_2309;
            if ( field_7D0 == 1 )
            {
              if ( !(field_7D2 % 30) && dash_angle < 6.0 )
              {
                /*
                v1235 = 0.0;
                v897 = (float)0.0;
                do
                {
                  v898 = v897 * 30.0;
                  v899 = v898;
                  *(float *)&v900 = v898;
                  v1243 = v900;
                  v1244 = dash_angle + 4.0;
                  v1245 = 0.0;
                  v901 = dir;
                  v902 = -*(float *)&v900;
                  v903 = sin_deg(v902) * 100.0 + y + 100.0;
                  v904 = v903;
                  v905 = -*(float *)&v1243;
                  v906 = cos_deg(v905) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 853, v906, v904, v901, 1, (int)&v1243, 3);
                  v1243 = v900;
                  v1244 = dash_angle + 4.0;
                  v1245 = 0.0;
                  v907 = x;
                  v908 = -dir;
                  v909 = -*(float *)&v900;
                  v910 = sin_deg(v909) * 100.0 + y + 100.0;
                  v911 = v910;
                  v912 = -*(float *)&v1243;
                  v913 = v907 - cos_deg(v912) * 100.0 * (double)dir;
                  addbullet(this, NULL, 853, v913, v911, v908, 1, (int)&v1243, 3);
                  *(float *)&v914 = v899 + 15.0;
                  v1243 = v914;
                  v1244 = dash_angle + 7.0;
                  v1245 = 2.0;
                  v915 = dir;
                  v916 = -*(float *)&v914;
                  v917 = sin_deg(v916) * 100.0 + y + 100.0;
                  v918 = v917;
                  v919 = -*(float *)&v1243;
                  v920 = cos_deg(v919) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 853, v920, v918, v915, 1, (int)&v1243, 3);
                  v1243 = v914;
                  v1244 = dash_angle + 7.0;
                  v1245 = 2.0;
                  v921 = x;
                  v922 = -dir;
                  v923 = -*(float *)&v914;
                  v924 = sin_deg(v923) * 100.0 + y + 100.0;
                  v925 = v924;
                  v926 = -*(float *)&v1243;
                  v927 = v921 - cos_deg(v926) * 100.0 * (double)dir;
                  addbullet(this, NULL, 853, v927, v925, v922, 1, (int)&v1243, 3);
                  v1235 = v1235 + 1.0;
                  v897 = v1235;
                }
                while ( v1235 < 12.0 );*/
                play_sfx(50);
                dash_angle = dash_angle + 5.0;
              }
              ++field_7D2;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              //get_elaps_frames() = 0;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x, y + 125.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 4 )
                field_7D0 = 1;
            }
            return;
          case 604:
            sub10func();
            sub_46AB50(2, 2);
            if ( get_subseq() == 1 && get_elaps_frames() >= 24 )
              goto LABEL_2309;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 4.0;
              addbullet(this, NULL, 854, enemy->x, 0.0, dir, 1, t, 3);
              play_sfx(54);
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(10 * (char)dir) + x, y + 130.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            return;
          case 605:
            sub10func();
            sub_46AB50(2, 2);
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 7 )
              {
                t[0] = 0.0;
                t[1] = 25.0;
                t[2] = 0.0;
                addbullet(this, NULL, 855, (double)(85 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
                play_sfx(52);
              }
              if ( !get_frame_time() && get_frame() == 2 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(80 * (char)dir), y + 145.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
            }
            return;
          case 606:
            sub10func();
            sub_46AB50(2, 2);
            if ( get_subseq() == 2 && get_elaps_frames() >= 48 )
              goto LABEL_2309;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              //get_elaps_frames() = 0;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x, y + 125.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 4 )
              {
                /*
                v1236 = 0.0;
                v942 = 12.0;
                v943 = (float)0.0;
                do
                {
                  *(float *)&v1346 = v943 * 30.0;
                  v1347 = 4.0;
                  v1348 = v942;
                  v944 = dir;
                  v945 = -*(float *)&v1346;
                  v946 = sin_deg(v945) * 100.0 + y + 100.0;
                  v947 = v946;
                  v948 = -*(float *)&v1346;
                  v949 = cos_deg(v948) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 856, v949, v947, v944, 1, (int)&v1346, 3);
                  v1236 = v1236 + 1.0;
                  v942 = 12.0;
                  v943 = v1236;
                }
                while ( v1236 < 12.0 );
                */
                play_sfx(10);
              }
            }
            return;
          case 607:
            sub10func();
            sub_46AB50(2, 2);
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 15) )
              {
                if ( field_7D0 <= 3 )
                {
                  switch ( field_7D0 )
                  {
                    case 0:
                      v1232 = 125.0;
                      v1240 = 100.0;
                      v961 = 9.0;
                      goto LABEL_2338;
                    case 1:
                      v1232 = 150.0;
                      v1240 = 160.0;
                      v961 = 3.0;
                      goto LABEL_2338;
                    case 2:
                      v1232 = 170.0;
                      v1240 = 220.0;
                      v961 = -3.0;
                      goto LABEL_2338;
                    case 3:
                      v1232 = 180.0;
                      v1240 = 280.0;
                      v961 = -9.0;
LABEL_2338:
                      t[0] = v961;
                      break;
                    default:
                      break;
                  }
                  t[0] = t[0] - (double)scene_rand_rng(30) * 0.1000000014901161;
                  t[1] = 35.0;
                  t[2] = 12.0;
                  addbullet(this, NULL, 857, v1232 * (double)(char)dir + x, v1240, dir, -1, t, 3);
                  addbullet(this, NULL, 857, x - v1232 * (double)(char)dir, v1240, dir, 1, t, 3);
                  play_sfx(16);
                  ++field_7D0;
                }
              }
              if ( get_elaps_frames() >= 60 )
                goto LABEL_2575;
            }
            if ( get_subseq() == 2 && get_elaps_frames() >= 0 )
              goto LABEL_2575;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              //get_elaps_frames() = 0;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(40 * (char)dir), y + 153.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 14.0;
              addbullet(this, NULL, 857, x - (double)(20 * (char)dir), y, dir, -1, t, 3);
            }
            return;
          case 608:
            sub10func();
            sub_46AB50(2, 2);
            if ( get_subseq() == 2 && get_elaps_frames() >= 32 )
              goto LABEL_2575;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(13);
              field_190 = 1;
              /*
              v989 = 0;
              v1209 = 0;
              do
              {
                *(float *)&v1505 = (double)v1209;
                v1506 = 600.0;
                v1507 = 1.0;
                v990 = enemy;
                v991 = v990->y + 100.0;
                addbullet(this, NULL, 858, v990->x, v991, dir, 1, (int)&v1505, 3);
                v989 += 40;
                v1209 = v989;
              }
              while ( v989 < 360 );*/
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 150.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            return;
          case 609:
            sub10func();
            sub_46AB50(2, 2);
            if ( h_inerc > 0.0 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( field_190 )
            {
              if ( field_194 >= 1 && ++field_7D2 >= 2 )
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
              scene_add_effect(this, 115, (double)(5 * (char)dir) + x, y + 100.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2422;
            if ( get_subseq() != 1 )
              goto LABEL_2427;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 2.0;
            addbullet(this, NULL, 859, x, y, dir, -1, t, 3);
            play_sfx(58);
LABEL_2422:
            if ( get_subseq() != 1 )
              goto LABEL_2427;
            if ( get_frame_time() || get_frame() != 5 )
              goto LABEL_2427;
            if ( field_7D0 >= 4 )
              goto LABEL_2309;
            field_7D0 = field_7D0 + 1;
LABEL_2427:
            if ( get_subseq() == 2 )
            {
              ++field_7D4;
              play_sfx(59);
              if ( !get_frame_time() && get_frame() == 1 )
              {
                h_inerc = 8.0;
                play_sfx(22);
                scene_add_effect(this, 127, x, y, dir, -1);
              }
              if ( field_7D4 % 10 == 1 && field_7D4 <= 21 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 859, x, y, dir, 1, t, 3);
              }
            }
            return;
          case 619:
            sub10func();
            sub_46AB50(2, 2);
            if ( get_subseq() <= 2 && get_subseq() >= 1 )
            {
              field_7DC = field_7E8 + field_7DC;
              field_7E8 = field_7E8 * 0.8500000238418579;
              if ( field_7E8 < 0.5 )
              {
                field_7E8 = 0.5;
                if ( ++field_7D0 >= 5 * (4 - field_8A0) )
                  field_7D6 = 1;
              }
            }
            if ( get_subseq() != 2 )
              goto LABEL_2462;
            if ( get_elaps_frames() >= 180 )
            {
              next_subseq();
              shader_type = 0.0;
              return;
            }
            if ( get_elaps_frames() >= 60 && !(get_elaps_frames() % 30) && field_7D8 < 4 )
            {
              play_sfx(11);
              if ( field_7D8 % 2 )
              {
                /*
                v1227 = 0.0;
                if ( field_7EC > 0.0 )
                {
                  v1020 = v1227;
                  do
                  {
                    v1239 = v1020 * (360.0 / field_7EC);
                    v1211 = 0.0;
                    if ( (double)field_8A0 > 0.0 )
                    {
                      v1242 = -v1239;
                      do
                      {
                        v1021 = (double)field_7D8 * 10.0;
                        *(float *)&v1255 = v1021 - (cos_deg(v1242) * 25.0 * (double)dir + 80.0) - 20.0 * v1211;
                        v1256 = 9.0 - (v1211 + v1211);
                        v1257 = 9.0;
                        v1022 = x;
                        HIDWORD(v1023) = (1 - 2 * sin_deg__int(-*(float *)&v1255 > 0.0));
                        v1024 = v1242 - field_7DC;
                        (v1023) = -dir;
                        v1025 = v1023;
                        v1026 = sin_deg(v1024) * ((double)field_7D2 * 0.75) * 0.1500000059604645 + y;
                        v1027 = v1026;
                        v1028 = v1242 - field_7DC;
                        v1029 = v1022 - cos_deg(v1028) * ((double)field_7D2 * 0.75) * (double)dir;
                        addbullet(this, NULL, 869, v1029, v1027, v1025, SHIDWORD(v1025), (int)&v1255, 3);
                        v1211 = v1211 + 1.0;
                      }
                      while ( (double)field_8A0 > v1211 );
                    }
                    v1257 = 5.0;
                    v1030 = -v1239;
                    v1031 = x;
                    HIDWORD(v1032) = (1 - 2 * sin_deg__int(-*(float *)&v1255 > 0.0));
                    v1033 = v1030 - field_7DC;
                    (v1032) = -dir;
                    v1034 = v1032;
                    v1035 = sin_deg(v1033) * ((double)field_7D2 * 0.75) * 0.1500000059604645 + y;
                    v1036 = v1035;
                    v1037 = v1030 - field_7DC;
                    v1038 = v1031 - cos_deg(v1037) * ((double)field_7D2 * 0.75) * (double)dir;
                    addbullet(this, NULL, 869, v1038, v1036, v1034, SHIDWORD(v1034), (int)&v1255, 3);
                    v1227 = v1227 + 1.0;
                    v1020 = v1227;
                  }
                  while ( field_7EC > (double)v1227 );
                }*/
              }
              else
              {/*
                v1210 = 0.0;
                if ( field_7EC > 0.0 )
                {
                  v1003 = v1210;
                  do
                  {
                    v1238 = v1003 * (360.0 / field_7EC);
                    v1226 = 0.0;
                    if ( (double)field_8A0 > 0.0 )
                    {
                      v1241 = -v1238;
                      do
                      {
                        *(float *)&v1255 = cos_deg(v1241) * 25.0 * (double)dir - 80.0 + (double)field_7D8 * 10.0 - 20.0 * v1226;
                        v1256 = 9.0 - (v1226 + v1226);
                        v1257 = 6.0;
                        v1004 = sin_deg__int(-*(float *)&v1255 > 0.0);
                        v1005 = v1241 - field_7DC;
                        v1006 = (1 - 2 * v1004);
                        v1007 = dir;
                        v1008 = sin_deg(v1005) * ((double)field_7D2 * 0.75) * 0.1500000059604645 + y;
                        v1009 = v1008;
                        v1010 = v1241 - field_7DC;
                        v1011 = cos_deg(v1010) * ((double)field_7D2 * 0.75) * (double)dir + x;
                        addbullet(this, NULL, 869, v1011, v1009, v1007, v1006, (int)&v1255, 3);
                        v1226 = v1226 + 1.0;
                      }
                      while ( (double)field_8A0 > v1226 );
                    }
                    v1257 = 5.0;
                    v1012 = -v1238;
                    HIDWORD(v1013) = (1 - 2 * sin_deg__int(-*(float *)&v1255 > 0.0));
                    (v1013) = dir;
                    v1014 = v1012 - field_7DC;
                    v1015 = v1013;
                    v1016 = sin_deg(v1014) * ((double)field_7D2 * 0.75) * 0.1500000059604645 + y;
                    v1017 = v1016;
                    v1018 = v1012 - field_7DC;
                    v1019 = cos_deg(v1018) * ((double)field_7D2 * 0.75) * (double)dir + x;
                    addbullet(this, NULL, 869, v1019, v1017, v1015, SHIDWORD(v1015), (int)&v1255, 3);
                    v1210 = v1210 + 1.0;
                    v1003 = v1210;
                  }
                  while ( field_7EC > (double)v1210 );
                }
                */
              }
              ++field_7D8;
            }
            if ( get_elaps_frames() % 15 == 2 * field_8A0 )
            {
              t[0] = -60.0 - (double)scene_rand_rng(60);
              t[1] = (double)scene_rand_rng(7) + 15.0;
              t[2] = 1.0;
              addbullet(this, NULL, 859, (double)scene_rand_rng(600) + x - 300.0, y, (1 - 2 * (scene_rand_rng(100) > 0x32)), 1, t, 3);
            }
LABEL_2462:
            if ( get_subseq() == 3 && get_elaps_frames() >= 10 * (5 - field_8A0) )
              goto LABEL_2575;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              shader_type = 1;
              field_7E8 = 5.0;
              field_7D6 = 0;
              switch ( field_8A0 )
              {
                case 1:
                  
                  field_7DC = 0.0;
                  field_7D2 = 100;
                  dash_angle = 6.0;
                  field_7D4 = 150;
                  field_7E4 = 0.0;
                  field_7D8 = 0;
                  field_7EC = 8.0;
                  break;
                case 2:
                  
                  field_7DC = 0.0;
                  field_7D2 = 150;
                  dash_angle = 8.0;
                  field_7D4 = 200;
                  field_7E4 = 8.0;
                  field_7D8 = 0;
                  field_7EC = 10.0;
                  break;
                case 3:
                  
                  field_7DC = 0.0;
                  field_7D2 = 175;
                  dash_angle = 10.0;
                  field_7D4 = 225;
                  field_7E4 = 10.0;
                  field_7D8 = 0;
                  field_7EC = 12.0;
                  break;
                case 4:
                  
                  field_7DC = 0.0;
                  field_7D2 = 200;
                  dash_angle = 12.0;
                  field_7D4 = 250;
                  field_7E4 = 12.0;
                  field_7D8 = 0;
                  field_7EC = 14.0;
                  break;
                default:
                  
                  break;
              }
              /*
              v1212 = 0.0;
              if ( dash_angle > 0.0 )
              {
                v1043 = v1212;
                while ( 1 )
                {
                  *(float *)&v1258 = v1043 * (360.0 / dash_angle) + field_7DC;
                  v1259 = (double)field_7D2;
                  v1260 = 2.0;
                  v1261 = (double)field_8A0 * 5.0 + 20.0;
                  HIDWORD(v1044) = (1 - 2 * sin_deg__int(-*(float *)&v1258 > 0.0));
                  (v1044) = dir;
                  v1045 = -*(float *)&v1258 - field_7DC;
                  v1046 = v1044;
                  v1047 = sin_deg(v1045);
                  v1048 = v1047 * v1259 * 0.1500000059604645 + y;
                  v1049 = v1048;
                  v1050 = -*(float *)&v1258 - field_7DC;
                  v1051 = cos_deg(v1050);
                  v1052 = v1051 * v1259 * (double)dir + x;
                  addbullet(this, NULL, 869, v1052, v1049, v1046, SHIDWORD(v1046), (int)&v1258, 4);
                  v1212 = v1212 + 1.0;
                  if ( dash_angle <= (double)v1212 )
                    break;
                  v1043 = v1212;
                  
                }
                
              }
              v1213 = 0.0;
              if ( dash_angle > 0.0 )
              {
                v1053 = v1213;
                while ( 1 )
                {
                  *(float *)&v1258 = v1053 * (360.0 / dash_angle) + field_7DC;
                  v1259 = (double)field_7D4;
                  v1260 = 4.0;
                  v1261 = (double)field_8A0 * 5.0 + 20.0;
                  v1054 = x;
                  HIDWORD(v1055) = (1 - 2 * sin_deg__int(-*(float *)&v1258 > 0.0));
                  (v1055) = -dir;
                  v1056 = -*(float *)&v1258 - field_7E4;
                  v1057 = v1055;
                  v1058 = sin_deg(v1056);
                  v1059 = v1058 * v1259 * 0.1500000059604645 + y;
                  v1060 = v1059;
                  v1061 = -*(float *)&v1258 - field_7E4;
                  v1062 = cos_deg(v1061);
                  v1063 = v1054 - v1062 * v1259 * (double)dir;
                  addbullet(this, NULL, 869, v1063, v1060, v1057, SHIDWORD(v1057), (int)&v1258, 4);
                  v1213 = v1213 + 1.0;
                  if ( dash_angle <= (double)v1213 )
                    break;
                  v1053 = v1213;
                  
                }
              }*/
              play_sfx(21);
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 125.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              if ( ++field_8A0 > 4 )
                field_8A0 = 4;
            }
            return;
          case 651:
            if ( get_subseq() == 4 )
              sub10func();
            if ( get_subseq() <= 2 )
              sub_46AB50(2, 2);
            if ( get_subseq() == 2 || get_subseq() == 3 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_2206:
                reset_forces();
                y = getlvl_height();
                set_subseq(4);
                return;
              }
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 63 )
              goto LABEL_2309;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 4.0;
              addbullet(this, NULL, 851, (double)(105 * (char)dir) + x, y + 146.0, dir, 1, t, 3);
              play_sfx(51);
            }
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                field_7DC = h_inerc;
                dash_angle = v_inerc;
                reset_forces();
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(40 * (char)dir), y + 150.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 3 )
              {
                h_inerc = field_7DC;
                v_inerc = dash_angle;
              }
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
              v_force = 0.2;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
LABEL_2231:
              set_seq(9);
            return;
          case 656:
            if ( get_subseq() <= 3 )
              sub_46AB50(2, 2);
            if ( get_subseq() == 5 )
              sub10func();
            if ( get_subseq() != 2 || get_elaps_frames() < 40 )
            {
              if ( (get_subseq() == 3 || get_subseq() == 4) && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
              {
                reset_forces();
                y = getlvl_height();
                set_subseq(5);
              }
              else
              {
                if ( process() )
                  set_seq(0);
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                  //get_elaps_frames() = 0;
                if ( !get_subseq() && !get_frame_time() )
                {
                  if ( get_frame() == 2 )
                  {
                    field_4A6 = 40;
                    scene_play_sfx(23);
                    scene_add_effect(this, 115, x, y + 125.0, dir, 1);
                    sub_469450(0, 0, 60);
                    sub_483570();
                    weather_forecast_next();
                  }
                  if ( !get_frame_time() && get_frame() == 4 )
                  {
                    /*
                    v1237 = 0.0;
                    v952 = 12.0;
                    v953 = (float)0.0;
                    do
                    {
                      *(float *)&v1322 = v953 * 30.0;
                      v1323 = 4.0;
                      v1324 = v952;
                      v954 = dir;
                      v955 = -*(float *)&v1322;
                      v956 = sin_deg(v955) * 100.0 + y + 100.0;
                      v957 = v956;
                      v958 = -*(float *)&v1322;
                      v959 = cos_deg(v958) * 100.0 * (double)dir + x;
                      addbullet(this, NULL, 856, v959, v957, v954, 1, (int)&v1322, 3);
                      v1237 = v1237 + 1.0;
                      v952 = 12.0;
                      v953 = v1237;
                    }
                    while ( v1237 < 12.0 );
                    */
                    play_sfx(10);
                  }
                }
              }
            }
            else
            {
              v_force = 0.5;
LABEL_2309:
              next_subseq();
            }
            return;
          case 657:
            if ( get_subseq() == 5 )
              sub10func();
            if ( get_subseq() <= 2 )
              sub_46AB50(2, 2);
            if ( get_subseq() == 3 || get_subseq() == 4 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_subseq(5);
                goto LABEL_2620;
              }
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 15) )
              {
                if ( field_7D0 <= 3 )
                {
                  switch ( field_7D0 )
                  {
                    case 0:
                      v1240 = 125.0;
                      v1232 = 100.0;
                      v974 = 9.0;
                      goto LABEL_2370;
                    case 1:
                      v1240 = 150.0;
                      v1232 = 160.0;
                      v974 = 3.0;
                      goto LABEL_2370;
                    case 2:
                      v1240 = 170.0;
                      v1232 = 220.0;
                      v974 = -3.0;
                      goto LABEL_2370;
                    case 3:
                      v1240 = 180.0;
                      v1232 = 280.0;
                      v974 = -9.0;
LABEL_2370:
                      t[0] = v974;
                      break;
                    default:
                      break;
                  }
                  t[0] = t[0] - (double)scene_rand_rng(30) * 0.1000000014901161;
                  t[1] = 35.0;
                  t[2] = 12.0;
                  addbullet(this, NULL, 857, v1240 * (double)(char)dir + x, v1232 + y, dir, -1, t, 3);
                  addbullet(this, NULL, 857, x - v1240 * (double)(char)dir, v1232 + y, dir, 1, t, 3);
                  play_sfx(16);
                  ++field_7D0;
                }
              }
              if ( get_elaps_frames() >= 60 )
                goto LABEL_2575;
            }
            if ( get_subseq() == 2 && get_elaps_frames() >= 0 )
              goto LABEL_2575;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              //get_elaps_frames() = 0;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(40 * (char)dir), y + 153.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 14.0;
              addbullet(this, NULL, 857, x - (double)(20 * (char)dir), y, dir, -1, t, 3);
            }
            if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 2 )
              v_force = 0.25;
            return;
          case 695:
            sub10func();
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
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
            if ( get_subseq() )
              return;
            if ( !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 4.0;
                addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
                h_inerc = 10.0;
                field_49A = 0;
              }
              if ( !get_frame_time() && get_frame() == 5 )
                play_sfx(0);
            }
            if ( get_frame() < 6 )
              return;
            v364 = h_inerc - 1.200000047683716;
            goto LABEL_2524;
          case 707:
            if ( h_inerc > 12.0 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 12.0 )
                h_inerc = 12.0;
            }
            if ( process() )
              goto LABEL_2555;
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
                goto LABEL_2309;
            }
            if ( get_subseq() == 2 )
            {
              v364 = h_inerc - 0.5;
LABEL_2524:
              h_inerc = v364;              
              if ( !((0.0 < h_inerc) | (0.0 == h_inerc)) )
LABEL_2525:
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
            if ( !char_on_ground_flag() )
            {
              if ( !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
              }
              v_inerc = v_inerc - 0.5;
              if ( getlvl_height() >= (v_inerc + y) && v_inerc < 0.0 )
              {
                v_inerc = 0.0;
                y = getlvl_height();
                set_subseq(2);
                return;
              }
            }
            if ( process() )
              goto LABEL_2734;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              h_inerc = -14.0;
              v_inerc = 4.0;
              scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
              scene_play_sfx(31);
            }
            return;
          case 709:
            if ( !get_subseq() )
            {
              v_inerc = v_inerc - v_force;
              if ( getlvl_height() >= (v_inerc + y) && v_inerc < 0.0 )
              {
                next_subseq();
                goto LABEL_2726;
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
            if ( get_subseq() != 2 && get_subseq() != 3 || (v1099 = v_inerc - 0.25, v_inerc = v1099, v1100 = v1099 + y, getlvl_height() < v1100) || v_inerc >= 0.0 )
            {
              if ( process() )
LABEL_2555:
                set_seq(700);
            }
            else
            {
              reset_forces();
              y = getlvl_height();
              next_subseq();
            }
            break;
          case 710:
            if ( get_subseq() == 1 )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  if ( !get_elaps_frames() )
                  {
                    /*
                    v1124 = 0;
                    v1221 = (double)scene_rand_rng(360);
                    v1217 = 0;
                    v1231 = 0;
                    do
                    {
                      play_sfx(13);
                      *(float *)&v1252 = (double)v1231 + v1221;
                      v1253 = 700.0;
                      v1254 = 0.0;
                      v1125 = dir;
                      v1126 = (double)v1217;
                      v1127 = v1126 - 6.0;
                      v1128 = sin_deg(v1127) * 300.0 + y + 170.0;
                      v1129 = v1126 * 60.0;
                      v1130 = (cos_deg(v1129) * 300.0 + 50.0) * (double)dir + x;
                      addbullet(this, NULL, 900, v1130, v1128, v1125, 1, (int)&v1252, 3);
                      ++v1217;
                      v1124 += 40;
                      v1231 = v1124;
                    }
                    while ( v1124 < 360 );*/
                  }
                  if ( get_elaps_frames() < 90 )
                    break;
                  goto LABEL_2575;
                case 1:
                  if ( !get_elaps_frames() )
                  {
                    /*
                    v1117 = 0;
                    v1220 = (double)scene_rand_rng(360);
                    v1216 = 0;
                    v1230 = 0;
                    do
                    {
                      play_sfx(13);
                      *(float *)&v1252 = (double)v1230 + v1220;
                      v1253 = 700.0;
                      v1254 = 0.0;
                      v1118 = dir;
                      v1119 = (double)v1216;
                      v1120 = v1119 - 6.0;
                      v1121 = sin_deg(v1120) * 300.0 + y + 170.0;
                      v1122 = v1119 * 60.0;
                      v1123 = (cos_deg(v1122) * 300.0 + 50.0) * (double)dir + x;
                      addbullet(this, NULL, 900, v1123, v1121, v1118, 1, (int)&v1252, 3);
                      ++v1216;
                      v1117 += 40;
                      v1230 = v1117;
                    }
                    while ( v1117 < 360 );*/
                  }
                  if ( get_elaps_frames() >= 120 )
                    goto LABEL_2575;
                  break;
                case 2:
                  if ( !get_elaps_frames() || get_elaps_frames() == 60 )
                  {
                    //v1219 = (double)scene_rand_rng(360);
                    play_sfx(13);
                    /*
                    v1110 = 0;
                    v1215 = 0;
                    v1229 = 0;
                    do
                    {
                      *(float *)&v1252 = (double)v1229 + v1219;
                      v1253 = 700.0;
                      v1254 = 0.0;
                      v1111 = dir;
                      v1112 = (double)v1215;
                      v1113 = v1112 - 6.0;
                      v1114 = sin_deg(v1113) * 300.0 + y + 170.0;
                      v1115 = v1112 * 60.0;
                      v1116 = (cos_deg(v1115) * 300.0 + 50.0) * (double)dir + x;
                      addbullet(this, NULL, 900, v1116, v1114, v1111, 1, (int)&v1252, 3);
                      ++v1215;
                      v1110 += 40;
                      v1229 = v1110;
                    }
                    while ( v1110 < 360 );*/
                  }
                  if ( get_elaps_frames() < 150 )
                    break;
                  next_subseq();
                  return;
                case 3:
                  if ( !get_elaps_frames() || get_elaps_frames() == 60 || get_elaps_frames() == 120 )
                  {
                    //v1218 = (double)scene_rand_rng(360);
                    play_sfx(13);
                    /*v1102 = 0;
                    v1214 = 0;
                    v1228 = 0;
                    do
                    {
                      *(float *)&v1252 = (double)v1228 + v1218;
                      v1253 = 700.0;
                      v1254 = 0.0;
                      v1103 = dir;
                      v1104 = (double)v1214;
                      v1105 = v1104 - 6.0;
                      v1106 = sin_deg(v1105) * 300.0 + y + 170.0;
                      v1107 = v1104 * 60.0;
                      v1108 = (cos_deg(v1107) * 300.0 + 50.0) * (double)dir + x;
                      addbullet(this, NULL, 900, v1108, v1106, v1103, 1, (int)&v1252, 3);
                      ++v1214;
                      v1102 += 40;
                      v1228 = v1102;
                    }
                    while ( v1102 < 360 );
                    */
                  }
                  if ( get_elaps_frames() < 180 )
                    break;
                  next_subseq();
                  return;
                default:
                  break;
              }
            }
            if ( process() )
              set_seq(700);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 4.0;
              addbullet(this, NULL, 900, (double)(50 * (char)dir) + x, y + 170.0, dir, 1, t, 3);
              t[2] = 5.0;
              addbullet(this, NULL, 900, (double)(50 * (char)dir) + x, y + 170.0, dir, 1, t, 3);
            }
            return;
          case 720:
            if ( !get_subseq() && get_frame() == 2 && v_inerc > 0.0 )
            {
              v_inerc = v_inerc - v_force;
              if ( v_inerc < 1.0 )
                v_inerc = 1.0;
            }
            if ( get_subseq() == 1 )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  if ( !get_elaps_frames() )
                    dash_angle = (double)scene_rand_rng(360);
                  if ( get_elaps_frames() % 20 || field_7DC > 100.0 )
                    goto LABEL_2615;
                  play_sfx(10);
                  t[0] = field_7DC * 20.0 + dash_angle;
                  t[1] = 6.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 901, x, y + 120.0, dir, 1, t, 3);
                  t[2] = 5.0;
                  goto LABEL_2614;
                case 1:
                  if ( !get_elaps_frames() )
                    dash_angle = (double)scene_rand_rng(360);
                  if ( get_elaps_frames() % 15 || field_7DC > 100.0 )
                    goto LABEL_2615;
                  play_sfx(10);
                  t[0] = field_7DC * 15.0 + dash_angle;
                  t[1] = 6.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 901, x, y + 120.0, dir, 1, t, 3);
                  t[2] = 5.0;
                  goto LABEL_2614;
                case 2:
                  if ( !get_elaps_frames() )
                    dash_angle = (double)scene_rand_rng(360);
                  if ( get_elaps_frames() % 10 || field_7DC > 100.0 )
                    goto LABEL_2615;
                  play_sfx(10);
                  t[0] = field_7DC * 12.0 + dash_angle;
                  t[1] = 6.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 901, x, y + 120.0, dir, 1, t, 3);
                  t[2] = 5.0;
                  goto LABEL_2614;
                case 3:
                  if ( !get_elaps_frames() )
                    dash_angle = (double)scene_rand_rng(360);
                  if ( !(get_elaps_frames() % 5) && field_7DC <= 100.0 )
                  {
                    play_sfx(10);
                    t[0] = field_7DC * 10.0 + dash_angle;
                    t[1] = 6.0;
                    t[2] = 0.0;
                    addbullet(this, NULL, 901, x, y + 120.0, dir, 1, t, 3);
                    t[2] = 5.0;
LABEL_2614:
                    addbullet(this, NULL, 901, x, y + 120.0, dir, 1, t, 3);
                    field_7DC = field_7DC + 1.0;
                  }
LABEL_2615:
                  if ( get_elaps_frames() < 210 )
                    goto LABEL_2616;
                  break;
                default:
                  goto LABEL_2616;
              }
LABEL_2575:
              next_subseq();
            }
            else
            {
LABEL_2616:
              if ( (get_subseq() == 2 || get_subseq() == 3) && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
              {
                set_subseq(4);
LABEL_2620:
                reset_forces();
                y = getlvl_height();
              }
              else
              {
                if ( process() )
                  set_seq(700);
                if ( !get_elaps_frames() )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                    reset_forces();
                  if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                  {
                    if ( getlvl_height() < y )
                      v_force = 0.2;
                    else
                      set_seq(700);
                  }
                }
                if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
                {
                  v_inerc = (double)scene_rand_rng(13) + 2.0;
                  v_force = 0.25;
                }
              }
            }
            return;
          case 725:
            if ( get_subseq() == 1 )
            {/*
              v1152 = //color_A;
              if ( v1152 < 6u )
                //color_A = 0;
              else
                //color_A = v1152 - 6;*/
            }
            if ( get_subseq() == 3 )
            {
              /*
              v1153 = //color_A;
              if ( v1153 > 0xF9u )
                //color_A = -1;
              else
                //color_A = v1153 + 6;
                */
            }
            if ( process() )
              set_seq(700);
            if ( get_elaps_frames() )
              goto LABEL_2663;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              play_sfx(55);
            if ( get_elaps_frames() )
              goto LABEL_2663;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
            {
              x = (double)scene_rand_rng(300) + 250.0 + x;
              play_sfx(55);
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 4 )
              goto LABEL_2663;
            return;
          case 726:
LABEL_2663:
            if ( get_subseq() == 1 )
            {
              /*
              v1154 = //color_A;
              if ( v1154 < 6u )
                //color_A = 0;
              else
                //color_A = v1154 - 6;*/
            }
            if ( get_subseq() == 3 )
            {
              /*
              v1155 = //color_A;
              if ( v1155 > 0xF9u )
                //color_A = -1;
              else
                //color_A = v1155 + 6;*/
            }
            if ( process() )
              set_seq(700);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                play_sfx(55);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                x = x - ((double)scene_rand_rng(300) + 250.0);
                play_sfx(55);
              }
            }
            return;
          case 730:
            if ( get_subseq() < 1 || (v_inerc = v_inerc - v_force, ++field_7D0, field_7D0 < 60) )
            {
              if ( process() )
                set_seq(700);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                dir = -1;
                h_inerc = (640.0 - x) / 60.0 * -1.0;
                v_inerc = 18.5;
                v_force = 0.5;
              }
            }
            else
            {
              reset_forces();
              set_seq(731);
            }
            return;
          case 731:
            x = 640.0;
            if ( !get_subseq() && get_frame() <= 2 && !(get_elaps_frames() % 5) )
            {
              t[0] = (double)scene_rand_rng(360);
              t[1] = (double)scene_rand_rng(250) + 50.0;
              t[2] = 3.0;
              addbullet(this, NULL, 922, cos_deg(-t[0]) * t[1] * (double)dir + x, cos_deg(-t[0]) * t[1] + y + 100.0, dir, -1, t, 3);
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 120 )
              goto LABEL_2309;
            if ( get_subseq() == 2 )
            {
              y = sin_deg((double)get_elaps_frames() * 3.0) * field_7E4 + dash_angle;
              field_7E4 = field_7E4 + 0.1000000014901161;
              if ( field_7E4 >= 60.0 )
                field_7E4 = 60.0;
            }
            if ( process() )
              set_seq(700);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
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
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 4.0;
              addbullet(this, NULL, 922, x, y + 100.0, dir, 1, t, 3);
              t[2] = 0.0;
              addbullet(this, NULL, 922, x, y, dir, -1, t, 3);
              play_sfx(17);
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL, 922, x, y + 100.0, dir, -1, t, 3);
              play_sfx(18);
            }
            return;
          default:
            goto LABEL_2722;
        }
      }
      return;
    }
    if ( get_seq() - 795 )
    {
      if ( !(get_seq() - 795) - 2 )
      {
        if ( get_subseq() > 1 || (v_inerc = v_inerc - v_force, !char_on_ground_down()) )
        {
          if ( process() )
LABEL_2738:
            set_seq(0);
          return;
        }
LABEL_2725:
        set_subseq(2);
        scene_play_sfx(30);
LABEL_2726:
        y = getlvl_height();
        v_inerc = 0.0;
        return;
      }
      if ( ((get_seq() - 795) - 2) != 1 )
      {
LABEL_2722:
        char_c::func10();
        return;
      }
      if ( get_subseq() <= 1 )
      {
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_2725;
      }
      if ( get_subseq() == 2 )
      {
        h_inerc = h_inerc - 0.75;
        if ( h_inerc < 0.0 ) // conditions reversed (old: >= )
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
LABEL_2734:
      set_seq(700);
    return;
  }
  if ( get_seq() == 300 )
  {
LABEL_603:
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
      if ( !get_frame_time() )
      {
        if ( get_frame() == 2 )
        {
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 1.0;
          addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
        }
        if ( !get_frame_time() && get_frame() == 3 )
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
          goto LABEL_25;
        goto LABEL_26;
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
          goto LABEL_42;
        return;
      case 2:
        sub10func();
        if ( field_49A )
        {
          
LABEL_26:
          if ( 0.0 < h_inerc )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
            {
              reset_forces();
              
              field_49A = 0;
            }
          }
          if ( 0.0 <= h_inerc || (v22 = h_inerc + 0.5, h_inerc = v22, v22 <= 0.0) )
          {
LABEL_99:
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
LABEL_25:
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
        char_h_move(4.0);
        process();
        return;
      case 5:
        sub10func();
        char_h_move(-4.0);
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
            goto LABEL_98;
        }
        process();
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          return;
        v31 = 0.0;
        goto LABEL_94;
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
            goto LABEL_98;
        }
        process();
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          return;
        v31 = 4.0;
        goto LABEL_94;
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
            goto LABEL_98;
        }
        process();
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          v31 = -4.0;
LABEL_94:
          char_h_move(v31);
          v_inerc = 12.0;
          v_force = 0.40000001;
          field_49A = 0;
        }
        return;
      case 9:
        if ( 0.0 == v_force )
          v_force = 0.60000002;
        v_inerc = v_inerc - v_force;
        if ( !char_on_ground_down() )
          goto LABEL_99;
LABEL_98:
        set_seq(10);
        goto LABEL_1940;
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
        if ( !get_subseq() || get_subseq() == 3 )
          sub10func();
        if ( get_subseq() < 3 )
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
        if ( !process() )
          goto LABEL_115;
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
LABEL_115:
          if ( get_subseq() == 3 && get_frame() == 2 && !get_frame_time() )
          {
            if ( enemy->x < (double)x )
              dir = -1;
            if ( enemy->x > (double)x )
              dir = 1;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v_inerc = 8.0;
            h_inerc = 11.5;
            v_force = 0.5;
          }
        }
        return;
      case 198:
        if ( !get_subseq() || get_subseq() == 3 )
          sub10func();
        if ( get_subseq() < 3 )
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
        if ( !process() )
          goto LABEL_138;
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
LABEL_138:
          if ( get_subseq() == 3 && get_frame() == 2 && !get_frame_time() )
          {
            if ( enemy->x < (double)x )
              dir = -1;
            if ( enemy->x > (double)x )
              dir = 1;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v_inerc = 8.0;
            h_inerc = -11.5;
            v_force = 0.5;
          }
        }
        return;
      case 199:
        sub10func();
        if ( !process() )
          goto LABEL_155;
        if ( controlling_type == 2 )
        {
          set_seq(700);
          field_51C = 3;
          field_520 = 3;
        }
        else
        {
          set_seq(2);
          if ( dY() > 0 )
            set_seq(1);
LABEL_155:
          if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
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
        if ( h_inerc > 6.0 )
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 6.0 )
            h_inerc = 6.0;
        }
        process();
        if ( get_subseq() != 1 )
          goto LABEL_176;
        if ( !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
        }
        if ( dY() >= 0 )
        {
          if ( (dX(dir) > 0 || ++field_7D0 <= 5) && ++field_7D0 <= 60 )
          {
LABEL_176:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
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
        if ( !get_subseq() || get_subseq() == 4 )
          sub10func();
        if ( !char_on_ground_flag() && !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
        }
        if ( get_subseq() < 4 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_2206;
        }
        if ( process() )
          goto LABEL_564;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          char_h_move(-10.0);
          v_inerc = 2.0;
          v_force = 0.2;
          scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
          scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
          scene_play_sfx(31);
        }
        return;
      case 202:
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_1501;
        if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
        }
        process();
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          field_7D0 = 0;
          char_h_move(7.5);
          v_inerc = 3.5;
          v_force = 0.44999999;
          scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
          scene_add_effect(this, 126, x, y + 110.0, dir, 1);
          scene_play_sfx(31);
        }
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 5 )
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
          if ( get_subseq() < 2 && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
          }
          process();
          if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
          {
            char_h_move(-7.5);
            v_inerc = 3.5;
            v_force = 0.44999999;
            scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
            scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
            scene_play_sfx(31);
          }
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
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
          field_49A = 0;
        }
        return;
      case 208:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_769;
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
        v87 = 0.0;
        goto LABEL_277;
      case 209:
      case 212:
      case 221:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_769;
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
        v90 = 10.0;
        goto LABEL_537;
      case 210:
      case 222:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_769;
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
        v90 = -10.0;
LABEL_537:
        char_h_move(v90);
        v_inerc = 13.5;
        v94 = 0.5;
        goto LABEL_538;
      case 211:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_769;
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
          v87 = 2.0;
LABEL_277:
          char_h_move(v87);
          v_inerc = 18.5;
          v94 = 0.55000001;
LABEL_538:
          v_force = v94;
          field_49A = 0;
          scene_add_effect(this, 63, x, y, dir, 1);
        }
        return;
      case 214:
        if ( process() )
          goto LABEL_2231;
        if ( get_elaps_frames() )
          goto LABEL_294;
        if ( get_frame_time() || get_frame() || get_subseq() != 1 )
          goto LABEL_289;
        scene_play_sfx(31);
        if ( dash_angle >= 135.0 || dash_angle <= -135.0 )
        {
          set_subseq(6);
          return;
        }
        if ( dash_angle > 45.0 || dash_angle < -45.0 )
        {
          set_subseq(4);
          return;
        }
LABEL_289:
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 9 )
          set_subseq(5);
LABEL_294:
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 10 || !get_frame_time() && !get_frame() && get_subseq() == 11) )
          goto LABEL_2231;
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
        if ( get_subseq() == 9 || get_subseq() == 10 || get_subseq() == 11 )
          v_inerc = v_inerc - v_force;
        if ( get_subseq() <= 0 || get_subseq() >= 9 )
          goto LABEL_411;
        ++field_7D6;
        field_7D4 = field_7D2 - dash_angle;
        if ( field_7D4 > 180 )
          field_7D4 = field_7D4 - 360;
        if ( field_7D4 < -180 )
          field_7D4 = field_7D4 + 360;
        if ( dash_angle > 180.0 )
          dash_angle = dash_angle - 360.0;
        if ( dash_angle < -180.0 )
          dash_angle = dash_angle + 360.0;
        if ( field_7D4 > 0 )
        {
          if ( weather_id )
            dash_angle = dash_angle + 5.0;
          else
            dash_angle = dash_angle + 6.0;
        }
        if ( field_7D4 < 0 )
        {
          if ( weather_id )
            dash_angle = dash_angle - 5.0;
          else
            dash_angle = dash_angle - 6.0;
        }
        h_inerc = cos_deg(dash_angle) * field_7DC;
        v_inerc = sin_deg(dash_angle) * field_7DC;
        if ( y > 680.0 && v_inerc > 0.0 )
          v_inerc = 0.0;
        if ( weather_id )
          spell_energy_spend(8, 1);
        else
          spell_energy_spend(4, 1);
        if ( (get_subseq() == 1 || get_subseq() == 2) && (dash_angle > 60.0 || dash_angle < -60.0) )
          goto LABEL_2136;
        if ( get_subseq() != 4 && get_subseq() != 5 )
          goto LABEL_354;
        if ( dash_angle <= 45.0 && dash_angle >= -45.0 )
        {
          set_subseq(1);
          return;
        }
        if ( dash_angle >= 135.0 || dash_angle <= -135.0 )
          goto LABEL_498;
LABEL_354:
        if ( (get_subseq() == 6 || get_subseq() == 7) && dash_angle < 120.0 && dash_angle > -120.0 )
        {
          set_subseq(8);
          return;
        }
        if ( (!keyDown(INP_D) && field_7D6 > 10 || spell_energy <= 0) && (!keyDown(INP_D) && field_7D6 > 10 || spell_energy <= 0) )
        {
          if ( get_subseq() == 1 || get_subseq() == 2 )
          {
            if ( dir == 1 )
            {
              if ( enemy->x < x )
              {
                dir = -1;
                h_inerc = -h_inerc;
              }
              set_subseq(9);
            }
            else
            {
              if ( enemy->x > x )
              {
                dir = -dir;
                h_inerc = -h_inerc;
              }
              set_subseq(9);
            }
          }
          if ( get_subseq() != 3 )
            goto LABEL_383;
          field_7D0 = get_frame();
          if ( dir == 1 )
          {
            if ( enemy->x < x )
            {
              dir = -1;
LABEL_378:
              h_inerc = -h_inerc;
              set_subseq(9);
              set_frame(field_7D0);
              goto LABEL_383;
            }
          }
          else
          {
            if ( enemy->x > x )
            {
              dir = -dir;
              goto LABEL_378;
            }
          }
          set_subseq(9);
          set_frame(field_7D0);
LABEL_383:
          if ( get_subseq() == 4 || get_subseq() == 5 )
          {
            if ( dir == 1 )
            {
              if ( enemy->x < x )
              {
                dir = -1;
                h_inerc = -h_inerc;
              }
              set_subseq(10);
            }
            else
            {
              if ( enemy->x > x )
              {
                dir = -dir;
                h_inerc = -h_inerc;
              }
              set_subseq(10);
            }
          }
          if ( get_subseq() == 6 || get_subseq() == 7 )
          {
            if ( dir == 1 )
            {
              if ( enemy->x < x )
              {
                dir = -1;
                h_inerc = -h_inerc;
              }
              set_subseq(11);
            }
            else
            {
              if ( enemy->x > x )
              {
                dir = -dir;
                h_inerc = -h_inerc;
              }
              set_subseq(11);
            }
          }
          if ( get_subseq() == 8 )
          {
            field_7D0 = get_frame();
            if ( dir == 1 )
            {
              if ( enemy->x >= x )
              {
                set_subseq(11);
              }
              else
              {
                dir = -1;
                h_inerc = -h_inerc;
                set_subseq(11);
              }
              set_frame(field_7D0);
            }
            else
            {
              if ( enemy->x <= x )
              {
                set_subseq(11);
              }
              else
              {
                dir = -dir;
                h_inerc = -h_inerc;
                set_subseq(11);
              }
              set_frame(field_7D0);
            }
          }
          return;
        }
LABEL_411:
        if ( !char_on_ground_down() )
          return;
        y = getlvl_height();
        v_inerc = 0.0;
        v_force = 0.0;
        if ( get_subseq() >= 9 )
        {
          set_seq(10);
          reset_forces();
          return;
        }
LABEL_501:
        reset_ofs();
        set_seq(215);
        break;
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
          goto LABEL_421;
        return;
      case 217:
        if ( process() )
          goto LABEL_2097;
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            scene_play_sfx(31);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
            goto LABEL_2097;
        }
        field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
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
              dash_angle = dash_angle + 2.0;
            else
              dash_angle = dash_angle + 4.0;
          }
          if ( field_7D4 < 0 )
          {
            if ( weather_id )
              dash_angle = dash_angle - 2.0;
            else
              dash_angle = dash_angle - 4.0;
          }
          h_inerc = cos_deg(dash_angle) * field_7DC;
          //v142 = sin_deg(dash_angle) * field_7DC;
          //v143 = v142;
          v_inerc = sin_deg(dash_angle) * field_7DC; //v142
          if ( y > 680.0 && v_inerc > 0.0 ) //v143
            v_inerc = 0.0;
          field_7DC = field_7DC + 0.300000011920929;
          if ( field_7DC > 9.0 )
            field_7DC = 9.0;
          if ( weather_id )
            spell_energy_spend(8, 60);
          else
            spell_energy_spend(4, 1);
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
          if ( (keyDown(INP_D)) == 0 && field_7D6 > 20 || spell_energy <= 0 )
          {
            if ( !keyDown(INP_D) && field_7D6 > 20 || spell_energy <= 0 )
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
                else if ( enemy->x <= x )
                {
LABEL_498:
                  set_subseq(6);
                }
                else
                {
                  dir = -dir;
                  h_inerc = -h_inerc;
                  set_subseq(5);
                }
              }
              return;
            }
          }
        }
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
        goto LABEL_501;
      case 220:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_749;
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
          v_inerc = 18.5;
          v_force = 0.55000001;
          field_49A = 0;
          scene_add_effect(this, 63, x, y, dir, 1);
        }
        return;
      case 223:
        sub10func();
        field_49A = 1;
        if ( h_inerc > 6.0 )
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 6.0 )
            h_inerc = 6.0;
        }
        process();
        if ( get_subseq() != 1 )
          goto LABEL_2745;
        if ( !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
        }
        if ( ((++field_7D0, v172 = field_7D0, dX(dir) > 0) || v172 <= 15) && v172 <= 60 )
        {
LABEL_2745:
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
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
        if ( !get_subseq() || get_subseq() == 4 )
          sub10func();
        if ( !char_on_ground_flag() && !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
        }
        if ( get_subseq() < 4 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_2206;
        }
        if ( process() )
        {
LABEL_564:
          set_seq(0);
          h_inerc = 0.0;
        }
        else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          char_h_move(-10.0);
          v_inerc = 2.0;
          v_force = 0.2;
          scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
          scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
          scene_play_sfx(31);
        }
        return;
      case 225:
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_1501;
        if ( get_subseq() < 3 && !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
        }
        if ( process() )
          set_seq(9);
        if ( !get_subseq() )
        {
          if ( !get_frame_time() && get_frame() == 1 )
          {
            char_h_move(-7.5);
            v_inerc = 3.5;
            v_force = 0.44999999;
            scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
            scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
            scene_play_sfx(31);
          }
          if ( !get_subseq() && !get_frame_time() && get_frame() == 9 )
            flip_with_force();
        }
        return;
      case 226:
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_1501;
        if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
        }
        if ( process() )
          set_seq(9);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          field_7D0 = 0;
          char_h_move(7.5);
          v_inerc = 3.5;
          v_force = 0.44999999;
          scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
          scene_add_effect(this, 126, x, y + 110.0, dir, 1);
          scene_play_sfx(31);
        }
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 5 )
          flip_with_force();
        return;
      default:
        goto LABEL_2722;
    }
  }
}


// NOTE: taken from marisa.cpp
void char_yuyuko::func20()
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

void char_yuyuko::set_seq_params()
{
  if ( get_seq() > 501 )
  {
    if ( get_seq() > 797 )
    {
      if ( get_seq() != 798 )
      {
LABEL_93:
        char_c::set_seq_params();
        return;
      }
    }
    else if ( get_seq() != 797 )
    {
      switch ( get_seq() )
      {
        case 502:
        case 503:
          field_18C = 0;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          v_force = 0.0;
          goto LABEL_35;
        case 505:
        case 506:
          field_18C = 4;
          reset_forces();
          goto LABEL_35;
        case 507:
        case 508:
          field_18C = 4;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          v_force = 0.0;
          goto LABEL_35;
        case 510:
        case 511:
          field_18C = 8;
          reset_forces();
          dash_angle = 0.0;
          field_49A = 0;
          field_7D0 = 0;
          field_190 = 1;
          return;
        case 512:
        case 513:
          field_49A = 0;
          field_7D0 = 0;
          field_18C = 8;
          field_190 = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          v_force = 0.0;
          dash_angle = 0.0;
          return;
        case 520:
        case 521:
          field_18C = 1;
          goto LABEL_45;
        case 522:
        case 523:
          field_190 = 0;
          field_49A = 0;
          field_18C = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          v_force = 0.0;
          return;
        case 525:
        case 526:
          field_18C = 5;
LABEL_45:
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          return;
        case 530:
        case 531:
          field_18C = 9;
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          return;
        case 540:
        case 541:
          field_18C = 2;
          field_190 = 0;
          reset_forces();
          goto LABEL_50;
        case 542:
        case 543:
          v_force = 0.0;
          field_18C = 2;
          field_190 = 0;
          h_inerc = h_inerc * 0.1000000014901161;
          v_inerc = 0.1000000014901161 * v_inerc;
LABEL_50:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          not_charge_attack = 0;
          return;
        case 545:
        case 546:
          field_18C = 6;
          goto LABEL_53;
        case 547:
          field_190 = 0;
          not_charge_attack = 0;
          field_18C = 2;
          field_194 = 1;
          return;
        case 550:
        case 551:
          field_18C = 10;
          field_194 = 0;
LABEL_53:
          field_190 = 0;
          reset_forces();
          goto LABEL_54;
        case 560:
        case 561:
          field_18C = 3;
          goto LABEL_58;
        case 562:
          field_18C = 3;
LABEL_60:
          field_7D6 = 0;
LABEL_61:
          field_7D2 = 0;
          v_force = 0.0;
          field_7D0 = 0;
          field_190 = 0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 565:
        case 566:
          if ( skills_1[7] >= 3 )
            set_subseq(1);
          goto LABEL_64;
        case 567:
LABEL_64:
          field_18C = 7;
          goto LABEL_58;
        case 570:
          field_18C = 11;
          field_194 = 1;
          field_190 = 0;
          reset_forces();
          /*
          v12 = __OFSUB__(skills_1[11], 2);
          v11 = (char)(skills_1[11] - 2) < 0;
          not_charge_attack = 1;
          if ( !((unsigned __int8)v11 ^ v12) )
            vtbl->set_subseq_func3(&meta, 1);
          if ( skills_1[11] >= 4 )
            vtbl->set_subseq_func3(&meta, 2);
          */
          return;
        case 571:
          field_18C = 11;
LABEL_58:
          field_194 = 1;
          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 599:
          field_190 = 1;
          reset_forces();
          goto LABEL_71;
        case 600:
        case 602:
        case 605:
        case 606:
        case 656:
          goto LABEL_73;
        case 601:
        case 604:
        case 608:
        case 610:
          field_7D0 = 0;
          field_7D2 = 0;
LABEL_73:
          field_190 = 1;
          goto LABEL_74;
        case 603:
          field_7D0 = 0;
          dash_angle = 0.0;
          field_7D2 = 0;
          field_190 = 1;
          reset_forces();
          return;
        case 607:
        case 657:
          field_190 = 1;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          return;
        case 609:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          field_190 = 0;
          field_194 = 7;
          reset_forces();
          return;
        case 612:
        case 615:
          field_190 = 1;
          reset_forces();
LABEL_54:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          not_charge_attack = 1;
          return;
        case 613:
LABEL_22:
          field_190 = 0;
          not_charge_attack = 1;
          return;
        case 619:
          field_7D0 = 0;
          field_190 = 1;
          reset_forces();
          return;
        case 651:
          v_force = 0.0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 1;
          v_inerc = v_inerc * 0.2000000029802322;
          h_inerc = 0.2000000029802322 * h_inerc;
          return;
        case 700:
          return;
        case 701:
        case 702:
        case 703:
          if ( !field_49A )
            reset_forces();
          return;
        case 704:
        case 707:
LABEL_74:
          reset_forces();
          return;
        case 705:
          h_inerc = 6.0;
          return;
        case 706:
          h_inerc = -6.0;
          return;
        case 708:
          h_inerc = 0.0;
          goto LABEL_86;
        case 709:
LABEL_86:
          field_7D0 = 0;
          return;
        case 710:
          field_190 = 0;
          reset_forces();
LABEL_71:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          return;
        case 720:
        case 730:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7DC = 0.0;
          return;
        case 725:
          field_7D0 = 0;
          h_inerc = 4.0;
          return;
        case 726:
          field_7D0 = 0;
          h_inerc = -4.0;
          return;
        case 731:
          field_190 = 0;
          reset_forces();
          field_7DC = 0.0;
          field_7D0 = 0;
          dash_angle = y;
          field_7E4 = 0.0;
          return;
        default:
          goto LABEL_93;
      }
      goto LABEL_93;
    }
    field_7D0 = 0;
    play_sfx(50);
    return;
  }
  if ( get_seq() < 500 )
  {
    if ( get_seq() > 214 )
    {
      switch ( get_seq() )
      {
        case 217:
          reset_ofs();
          goto LABEL_11;
        case 300:
        case 301:
        case 303:
        case 322:
        case 330:
          if ( !field_49A )
            goto LABEL_13;
          goto LABEL_14;
        case 302:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
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
          h_inerc = 12.0;
          field_194 = 1;
          v_force = 0.0;
          return;
        case 306:
          field_7D0 = 0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 307:
        case 309:
          field_194 = 1;
          goto LABEL_22;
        case 308:
          field_194 = 4;
          field_190 = 0;
          not_charge_attack = 1;
          return;
        case 310:
          h_inerc = 0.0;
          field_7D0 = 0;
          v_inerc = 0.0;
          field_190 = 0;
          field_194 = 99;
          v_force = 0.5;
          return;
        case 320:
          field_49A = 0;
LABEL_13:
          reset_forces();
LABEL_14:
          field_190 = 0;
          field_194 = 1;
          return;
        case 321:
          reset_forces();
          field_194 = 1;
          field_190 = 0;
          return;
        case 400:
        case 401:
        case 411:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          not_charge_attack = 1;
          return;
        case 402:
        case 410:
        case 412:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          not_charge_attack = 1;
          return;
        case 404:
        case 406:
          goto LABEL_60;
        case 408:
          h_inerc = 14.5;
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
        case 414:
        case 416:
          v_force = 0.050000001;
          field_190 = 0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 415:
          field_7D4 = 0;
          goto LABEL_61;
        case 418:
          field_194 = 1;
          h_inerc = 15.0;
          field_190 = 0;
          return;
        default:
          goto LABEL_93;
      }
    }
    else
    {
      if ( get_seq() == 214 )
      {
LABEL_11:
        field_7D6 = 0;
        h_inerc = 0.0;
        v_inerc = 0.0;
        v_force = 0.60000002;
        x_off = 0.0;
        y_off = 95.0;
        field_7DC = 9.0;
        field_7EC = 0.0;
        return;
      }
      if ( !(get_seq() - 4) )
      {
        h_inerc = 4.0;
        return;
      }
      if ( (get_seq() - 4) == 1 )
      {
        h_inerc = -4.0;
        return;
      }
    }
    goto LABEL_93;
  }
  field_18C = 0;
  reset_forces();
LABEL_35:
  field_49A = 0;
  field_7D0 = 0;
  field_190 = 1;
}
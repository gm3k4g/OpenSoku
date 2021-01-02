#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "udonge.h"
#include <math.h>

char_udonge::char_udonge(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_UDONGE;
	pgp->load_dat("udonge",pal);
	char_loadsfx("udonge");
	cards_load_cards(&chr_cards,"udonge");
	load_face("udonge");
	load_spells("udonge");
	stand_gfx->init(this,"udonge");
}

void char_udonge::init_vars()
{
  field_138 = -6.0;
  field_890 = 0;
  field_892 = 255;
  field_894 = 1.0;
  field_8A0 = 0;
  field_8A4 = 0;
  field_89C = 0.0;
  field_898 = 0;
  field_89A = 0;
  field_8AC = 200.0;
  field_8A8 = 0;
  field_8B0 = 0;
  field_8B2 = 0;
  field_8B4 = 0;
  char_c::init_vars();
}
/*
c_bullet *char_udonge::new_bullet()
{
    c_bullet *tmp = new udonge_bullets();
    return tmp;
}
*/
void char_udonge::func10()
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

  bool v63 = false;
  double v66 = 0.0;
  double v122 = 0.0;
  double v125 = 0.0;
  double v129 = 0.0;
  double v132 = 0.0;

  double v256 = 0.0;

  double v1480 = 0.0;
  double v325 = 0.0;

  double v1481 = 0.0;
  double v510 = 0.0;

  double v1483 = 0.0;
  double v774 = 0.0;

  double v1484 = 0.0;
  double v965 = 0.0;

  bool v978 = false;

  int v1228 = 0;

  double move_val = 0.0;

  double v1482 = 0.0;
  double v642 = 0.0;

  double v1485 = 0.0;
  double v985 = 0.0;

  double v1486 = 0.0;
  double v1066 = 0.0;

  double v1487 = 0.0;
  double v1138 = 0.0;

  double v1488 = 0.0;
  double v1160 = 0.0;

  double v1491 = 0.0;
  double v1437 = 0.0;

  if ( getlvl_height() >= y && !(get_pframe()->fflags & 4) )
    field_8B4 = 0;
  x_delta = 0;
  y_delta = 95;
  if ( /*chrt->*/health <= 0 )
  {
    field_8B0 = 0;
    field_8B2 = 0;
  }
  if ( field_8B0 <= 0 )
  {
    field_8B0 = 0;
    if ( field_89A <= 0 )
    {
      field_8A8 = 0;
    }
    else
    {
      if ( !time_stop )
        field_89A = field_89A - 1;
      if ( !field_8A8 )
      {
        field_8A8 = 1;
        t[0] = 0.0;
        t[1] = field_8AC;
        t[2] = 0.0;
        addbullet(this, NULL, 847, x, y, dir, 1, t, 3);
        
      }
      if ( field_8A8 == 1 && skills_1[6] >= 3 )
      {
        field_8A8 = 2;
        t[0] = 0.0;
        t[1] = -field_8AC;
        t[2] = 0.0;
        addbullet(this, NULL, 847, x, y, dir, 1, t, 3);
        goto LABEL_27;
      }
    }
  }
  else
  {
    field_54C = 0.0;
    if ( !time_stop )
      --field_8B0;
    if ( get_seq() >= 600 && get_seq() <= 689 && (get_seq() != 610 || !get_subseq() && !get_frame()) )
      field_8B0 = 0;
    if ( !field_8A8 )
    {
      field_8A8 = 1;
      t[0] = 0.0;
      t[1] = field_8AC;
      t[2] = 0.0;
      addbullet(this, NULL, 847, x, y, dir, 1, t, 3);
      
    }
    if ( field_8A8 == 1 )
    {
      field_8A8 = 2;
      t[0] = 0.0;
      t[1] = -field_8AC;
      t[2] = 0.0;
      addbullet(this, NULL, 847, x, y, dir, 1, t, 3);
LABEL_27:
      
      goto LABEL_29;
    }
  }
LABEL_29:
  if ( field_8B2 <= 0 )
  {
    if ( field_898 <= 0 )
    {
      if ( field_894 < 1.0 )
      {
        field_894 = field_894 + 0.05000000074505806;
        if ( field_894 > 1.0 )
          field_894 = 1.0;
      }
      goto LABEL_55;
    }
    ++field_520;
    if ( !time_stop )
      --field_898;
  }
  else
  {
    field_54C = 0.0;
    ++field_520;
    if ( !time_stop )
      --field_8B2;
    if ( get_seq() >= 600 && get_seq() <= 689 && (get_seq() != 611 || !get_subseq() && !get_frame()) )
      field_8B2 = 0;
  }
  if ( char_is_shock() || get_seq() > 299 || char_is_block_knock() )
  {
    if ( field_894 < 0.5 )
    {
      field_894 = field_894 + 0.05000000074505806;
      if ( field_894 >= 0.5 )
      {
        field_894 = 0.5;
        goto LABEL_55;
      }
    }
    else
    {
      field_894 = field_894 - 0.05000000074505806;
      if ( field_894 <= 0.5 )
      {
        field_894 = 0.5;
        goto LABEL_55;
      }
    }
    
    goto LABEL_55;
  }
  field_894 = field_894 - 0.05000000074505806;
  
  if ( field_894 <= 0.0 )
    field_894 = 0.0;
LABEL_55:
  if ( get_seq() == 200 && get_subseq() == 2 && 0.0 <= field_894 )
  {
    field_894 = field_894 - 0.1500000059604645;
    if ( field_894 <= 0.0 )
      field_894 = 0.0;
  }
  if ( get_seq() > 149 && get_seq() < 159 && !bbarrier_show )
  {
    bbarrier_show = 1;
    t[0] = 0.0;
    t[2] = 0.0;
    if ( get_seq() > 149 && get_seq() < 154 )
    {
      t[1] = 0.0;
      addbullet(this, NULL, 998, (double)(20 * (char)dir) + x, y + 130.0, dir, 1, t, 3);
      t[1] = 1.0;
      addbullet(this, NULL, 998, (double)(60 * (char)dir) + x, y + 130.0, dir, 1, t, 3);
      
    }
    if ( get_seq() > 153 && get_seq() < 158 )
    {
      t[1] = 0.0;
      addbullet(this, NULL, 998, (double)(30 * (char)dir) + x, y + 80.0, dir, 1, t, 3);
      t[1] = 1.0;
      addbullet(this, NULL, 998, (double)(70 * (char)dir) + x, y + 80.0, dir, 1, t, 3);
      
    }
    if ( get_seq() == 158 )
    {
      t[1] = 0.0;
      addbullet(this, NULL, 998, (double)(30 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
      t[1] = 1.0;
      addbullet(this, NULL, 998, (double)(70 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
      
    }
  }
  
  if ( field_8A0 )
  {
    if ( field_8A0 > 4 )
      field_8A0 = 4;
    switch ( field_8A0 )
    {
      case 1:
        field_530 = field_530 * 1.049999952316284;
        field_534 = field_534 * 0.949999988079071;
        goto LABEL_79;
      case 2:
        field_530 = field_530 * 1.125;
        field_534 = field_534 * 0.875;
        goto LABEL_79;
      case 3:
        field_530 = field_530 * 1.25;
        field_534 = field_534 * 0.800000011920929;
        goto LABEL_79;
      case 4:
        field_530 = field_530 * 1.350000023841858;
        field_534 = field_534 * 0.699999988079071;
LABEL_79:
        break;
      default:
        break;
    }
    if ( !(field_8A4 % 30) )
    {
      t[0] = 0.0;
      t[1] = 0.0;
      t[2] = 4.0;
      addbullet(this, NULL, 859, x, y + 100.0, dir, 1, t, 3);
      
      
    }
    if ( field_8A0 > 1 && !(field_8A4 % 45) )
    {
      t[0] = 0.0;
      t[1] = 0.0;
      t[2] = 5.0;
      addbullet(this, NULL, 859, scene_rand_rng(200) + x - 100.0, scene_rand_rng(100) + y - 50.0, dir, 1, t, 3);
      
      
    }
    if ( field_8A0 > 2 && !(field_8A4 % 40) )
    {
      t[0] = 0.0;
      t[1] = 0.0;
      t[2] = 5.0;
      addbullet(this, NULL, 859, scene_rand_rng(200) + x - 100.0, scene_rand_rng(100) + y - 50.0, dir, 1, t, 3);
      
      
    }
    ++field_8A4;
  }
  else
  {
    field_8A4 = 0;
  }
  if ( health > 0 )
  {
    //color_A = ((double)field_892 * field_894);
    if ( field_892 > 235 )
      field_892 = 255;
    else
      field_892 = field_892 + 20;
  }
  if ( !hit_stop && !enemy->time_stop )
  {
    if ( get_seq() <= 300 )
    {
      if ( get_seq() == 300 )
      {
LABEL_653:
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
          if ( !get_frame_time() && get_frame() == 4 )
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
              goto LABEL_102;
            goto LABEL_103;
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
LABEL_103:
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
LABEL_178:
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
LABEL_102:
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
            v63 = get_frame() == 0;
            goto LABEL_2496;
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
              sub10func();
            if ( !get_subseq() )
            {
              if ( !field_49A )
                reset_forces();
            }
            if ( !((get_subseq() < 0) | (get_subseq() == 0)) )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_177;
            }
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v66 = 0.0;
            goto LABEL_173;
          case 7:
            if ( !get_subseq() )
              sub10func();
            if ( !get_subseq() )
            {
              if ( !field_49A )
                reset_forces();
            }
            if ( !((get_subseq() < 0) | (get_subseq() == 0)) )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_177;
            }
            process();
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            v66 = 5.0;
            goto LABEL_173;
          case 8:
            if ( !get_subseq() )
              sub10func();
            if ( !get_subseq() )
            {
              if ( !field_49A )
                reset_forces();
            }
            if ( !((get_subseq() < 0) | (get_subseq() == 0)) )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_177;
            }
            process();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              v66 = -5.0;
LABEL_173:
              move_val = v66;
              char_h_move(move_val);
              v_inerc = 15.0;
              v_force = 0.60000002;
              field_49A = 0;
            }
            return;
          case 9:
          case 11:
            if ( 0.0 == v_force )
              v_force = 0.60000002;
            v_inerc = v_inerc - v_force;
            if ( !char_on_ground_down() )
              goto LABEL_178;
LABEL_177:
            goto LABEL_860;
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
            if ( !get_subseq() && get_frame() <= 2 || get_subseq() == 3 )
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
              goto LABEL_194;
            if ( controlling_type == 2 )
            {
LABEL_233:
              set_seq(700);
              goto LABEL_234;
            }
            set_seq(0);
            if ( dY() > 0 )
              set_seq(1);
LABEL_194:
            if ( get_subseq() == 3 && get_frame() == 2 && !get_frame_time() )
            {
              if ( enemy->x < (double)x )
                dir = -1;
              if ( enemy->x > (double)x )
                dir = 1;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              v_inerc = 4.5;
              h_inerc = 12.5;
              v_force = 0.34999999;
            }
            return;
          case 198:
            if ( !get_subseq() && get_frame() <= 2 || get_subseq() == 3 )
              sub10func();
            if ( get_subseq() < 3 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                y = getlvl_height();
                reset_forces();
                goto LABEL_213;
              }
            }
            if ( !process() )
              goto LABEL_219;
            if ( controlling_type == 2 )
            {
              set_seq(700);
LABEL_234:
              field_51C = 3;
              field_520 = 3;
            }
            else
            {
              set_seq(0);
              if ( dY() > 0 )
                set_seq(1);
LABEL_219:
              if ( get_subseq() == 3 && get_frame() == 2 && !get_frame_time() )
              {
                if ( enemy->x < (double)x )
                  dir = -1;
                if ( enemy->x > (double)x )
                  dir = 1;
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                v_inerc = 4.5;
                h_inerc = -12.5;
                v_force = 0.34999999;
              }
            }
            return;
          case 199:
            sub10func();
            if ( !process() )
              goto LABEL_237;
            if ( controlling_type == 2 )
              goto LABEL_233;
            set_seq(0);
            if ( dY() > 0 )
              set_seq(1);
LABEL_237:
            if ( !get_subseq() && get_frame() == 11 && !get_frame_time() )
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
            process();
            if ( get_subseq() < 1 )
              goto LABEL_255;
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            if ( dY() >= 0 )
            {
              if ( (dX(dir) > 0 || ++field_7D0 <= 5) && ++field_7D0 <= 60 )
              {
LABEL_255:
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  char_h_move(9.0);
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
            if ( !get_subseq() && get_frame() <= 1 || get_subseq() == 3 )
            {
              sub10func();
              
            }
            if ( get_subseq() == 2 )
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
                goto LABEL_615;
              }
            }
            if ( process() )
              goto LABEL_617;
            if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
            {
              char_h_move(-12.0);
              v_inerc = 4.0;
              v_force = 0.5;
              scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
              scene_play_sfx(31);
            }
            return;
          case 202:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_279;
            if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            process();
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              field_7D0 = 0;
              char_h_move(9.0);
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
              goto LABEL_2547;
            if ( get_subseq() < 3 && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            process();
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                char_h_move(-9.0);
                v_inerc = 4.0;
                v_force = 0.5;
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
              goto LABEL_860;
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
            v122 = 0.0;
            goto LABEL_362;
          case 209:
          case 221:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_860;
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
            v125 = 8.0;
            goto LABEL_586;
          case 210:
          case 222:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_860;
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
            v125 = -8.0;
LABEL_586:
            char_h_move(v125);
            v129 = 17.5;
            goto LABEL_587;
          case 211:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_860;
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
            v122 = 2.0;
LABEL_362:
            char_h_move(v122);
            v129 = 20.0;
LABEL_587:
            v_inerc = v129;
            v132 = 0.75;
            goto LABEL_588;
          case 212:
            if ( !get_subseq() )
              sub10func();
            if ( char_on_ground_down() )
              goto LABEL_860;
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
              char_h_move(8.5);
              v_inerc = 15.5;
              v132 = 0.64999998;
LABEL_588:
              v_force = v132;
              field_49A = 0;
              scene_add_effect(this, 63, x, y, dir, 1);
            }
            return;
          case 214:
            if ( process() )
              goto LABEL_385;
            if ( get_elaps_frames() )
              goto LABEL_390;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 6 )
            {
LABEL_385:
              flip_with_force();
              set_seq(9);
              return;
            }
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              scene_play_sfx(31);
LABEL_390:
            if ( dY() < 0 | (dY() == 0) )
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
              goto LABEL_2732;
            ++field_7D6;
            field_7D4 = field_7D2 - dash_angle;
            if ( field_7D2 > 180 )
              field_7D4 = field_7D2 - 360;
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
            if ( (keyDown(INP_D) || field_7D6 <= 10) && spell_energy > 0 )
            {
LABEL_2732:
              if ( !char_on_ground_down() )
                return;
              y = getlvl_height();
              v_inerc = 0.0;
              v_force = 0.0;
              goto LABEL_468;
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
              goto LABEL_463;
            goto LABEL_460;
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
            goto LABEL_2700;
          case 217:
            if ( process() )
              goto LABEL_1078;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              scene_play_sfx(31);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
              goto LABEL_1078;
            field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
            if ( get_subseq() == 5 || get_subseq() == 6 )
              v_inerc = v_inerc - v_force;
            if ( get_subseq() <= 0 || get_subseq() >= 5 )
              goto LABEL_2733;
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
LABEL_2733:
              if ( char_on_ground_down() )
              {
                y = getlvl_height();
                v_force = 0.0;
                v_inerc = 0.0;
LABEL_468:
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
LABEL_460:
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
LABEL_463:
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
              goto LABEL_820;
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
              v_force = 0.75;
              field_49A = 0;
              scene_add_effect(this, 63, x, y, dir, 1);
            }
            return;
          case 223:
            sub10func();
            field_49A = 1;
            process();
            if ( get_subseq() != 1 )
              goto LABEL_2734;
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            if ( ((++field_7D0, dX(dir) > 0) || field_7D0 <= 15) && field_7D0 <= 45 )
            {
LABEL_2734:
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                char_h_move(4.5);
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
            if ( !get_subseq() && get_frame() <= 1 || get_subseq() == 3 )
            {
              sub10func();
              
            }
            if ( get_subseq() == 2 )
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
LABEL_615:
              y = getlvl_height();
              set_subseq(3);
            }
            else if ( process() )
            {
LABEL_617:
              set_seq(0);
              h_inerc = 0.0;
            }
            else if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
            {
              char_h_move(-12.0);
              v_inerc = 4.0;
              v_force = 0.5;
              scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
              scene_play_sfx(31);
            }
            return;
          case 225:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_279:
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
                  char_h_move(-9.0);
                  v_inerc = 4.0;
                  v_force = 0.5;
                  scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
                  scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
                  scene_play_sfx(31);
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                  flip_with_force();
              }
            }
            return;
          case 226:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_2547;
            if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
            process();
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              field_7D0 = 0;
              char_h_move(9.0);
              v_inerc = 4.0;
              v_force = 0.5;
              scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
              scene_add_effect(this, 126, x, y + 110.0, dir, 1);
              scene_play_sfx(31);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              flip_with_force();
            return;
          default:
            goto LABEL_2713;
        }
      }
      return;
    }
    if ( get_seq() <= 500 )
    {
      if ( get_seq() == 500 )
      {
        sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
        {
          field_190 = 1;
          spell_energy_spend(200, 120);
          add_card_energy(50);
          field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7E4 < -10.0 )
            field_7E4 = -10.0;
          if ( field_7E4 > 10.0 )
            field_7E4 = 10.0;
          t[0] = field_7E4;
          t[1] = 1.0;
          t[2] = 0.0;
          addbullet(this, NULL, 810, (double)(72 * (char)dir) + x, y + 95.0, dir, 1, t, 3);
          t[2] = 5.0;
          addbullet(this, NULL, 810, (double)(72 * (char)dir) + x, y + 95.0, dir, 1, t, 3);
LABEL_1633:
          play_sfx(5);
        }
LABEL_1634:
        if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
        {
          field_190 = 1;
          play_sfx(5);
        }
      }
      else
      {
        switch ( get_seq() )
        {
          case 301:
            sub10func();
            if ( true /*!get_true(0)*/ )
            {
              if ( field_49A || get_frame() >= 4 )
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
                if ( get_frame() == 4 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 1.0;
                  addbullet(this, NULL, 849, x, y, dir, 1, t, 3);
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 5 )
                    play_sfx(0);
                  if ( !get_frame_time() && get_frame() == 4 )
                  {
                    h_inerc = 7.5;
                    field_49A = 0;
                  }
                }
              }
            }
            return;
          case 302:
            sub10func();
            if ( false /*get_true(1)*/  )
              return;
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              h_inerc = 17.5;
            if ( !get_subseq() )
            {
              if ( h_inerc > 0.0 )
                h_inerc = h_inerc - 0.75;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_710;
            if ( get_frame_time() || get_frame() || get_subseq() != 1 )
              goto LABEL_700;
            if ( not_charge_attack == 1 )
            {
              set_subseq(3);
              scene_add_effect(this, 62, x - (double)(86 * (char)dir), y + 108.0, dir, 1);
              field_194 = 1;
              return;
            }
            scene_play_sfx(29);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 4.0;
            addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            field_892 = 0;
            //color_A = 0;
            h_inerc = -250.0;
LABEL_700:
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
              {
                h_inerc = 17.5;
                scene_play_sfx(29);
              }
            }
LABEL_710:
            if ( get_subseq() == 1 )
            {
              h_inerc = h_inerc - 0.05000000074505806;
              field_892 = field_892 > 250 ? 255 : field_892 + 5;
              if ( get_elaps_frames() >= 18 || field_190 )
              {
                field_892 = 255;
                next_subseq();
                return;
              }
            }
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 1.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            else
            {
            }
            if ( get_subseq() == 4 )
            {
              h_inerc = h_inerc - 0.1000000014901161;
              if ( get_elaps_frames() >= 24 || field_190 )
                goto LABEL_724;
            }
            if ( get_subseq() == 5 )
            {
              h_inerc = h_inerc - 1.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            return;
          case 303:
            sub10func();
            if ( true /*!get_true(0)*/ )
            {
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
              {
                if ( !field_49A )
                  reset_forces();
                field_194 = 1;
                field_190 = 0;
              }
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
            if ( get_subseq() == 5 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                y = getlvl_height();
                reset_forces();
                set_subseq(6);
                return;
              }
            }
            else
            {
              sub10func();
            }
            if ( false /*get_true(1)*/  )
              return;
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && !get_subseq() )
              {
                field_49A = 0;
                field_194 = 1;
                field_190 = 0;
                reset_forces();
                not_charge_attack = 1;
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                h_inerc = field_7DC;
                field_194 = 1;
              }
            }
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            if ( (!get_subseq() || get_subseq() == 2 || get_subseq() == 4) && h_inerc > 0.0 )
            {
              h_inerc = h_inerc - 1.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              goto LABEL_792;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              h_inerc = 12.5;
              scene_play_sfx(28);
            }
            if ( get_subseq() != 1 )
              goto LABEL_784;
            if ( not_charge_attack && get_elaps_frames() >= 9 )
            {
              if ( !field_190 )
                field_7D0 = 1;
              t[0] = 0.0;
              t[0] = h_inerc;
              t[0] = 10.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
              field_892 = 0;
              //color_A = 0;
              field_194 = 0;
              field_190 = 0;
              field_7DC = h_inerc;
              h_inerc = -280.0;
              set_subseq(3);
              scene_add_effect(this, 62, x - (double)(15 * (char)dir), y + 60.0, dir, 1);
            }
            else
            {
              if ( get_elaps_frames() > 16 )
                goto LABEL_2627;
LABEL_784:
              if ( get_subseq() != 3 || get_elaps_frames() <= 36 )
              {
                if ( get_elaps_frames() || get_frame_time() || get_frame() )
                {
                  if ( get_subseq() == 5 && !get_frame_time() && get_frame() == 10 )
                    scene_play_sfx(29);
                }
                else if ( get_subseq() == 5 )
                {
LABEL_792:
                  set_seq(0);
                  return;
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
                  set_seq(9);
              }
              else
              {
                next_subseq();
                if ( field_7D0 )
                  set_frame(2);
              }
            }
            return;
          case 305:
            sub10func();
            if ( true /*!get_true(1)*/  )
            {
              if ( get_frame() > 5 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                set_seq(0);
              if ( !get_frame_time() && get_frame() == 3 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 5.0;
                addbullet(this, NULL, 849, x, y, dir, 1, t, 3);
                play_sfx(1);
              }
            }
            return;
          case 306:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_820;
            if ( process() )
              set_seq(11);
            if ( !get_frame_time() && get_frame() == 4 )
              scene_play_sfx(28);
            return;
          case 307:
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_820:
              set_seq(10);
              goto LABEL_861;
            }
            if ( process() )
              set_seq(9);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 5 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 3.0;
                addbullet(this, NULL, 849, x, y, dir, 1, t, 3);
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                play_sfx(1);
                h_inerc = -7.0;
                v_inerc = 6.0;
                v_force = 0.5;
              }
            }
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            play_sfx(1);
            h_inerc = -7.0;
            v256 = 6.0;
            goto LABEL_2475;
          case 308:
            if ( ++field_7D0 <= 10 )
              field_892 = 0;
            if ( !get_subseq() )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_subseq(1);
                goto LABEL_861;
              }
            }
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            if ( process() )
              goto LABEL_2723;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_896;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 9 )
              scene_play_sfx(28);
            return;
          case 309:
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_860:
              set_seq(10);
LABEL_861:
              y = getlvl_height();
              reset_forces();
            }
            else
            {
              if ( process() )
                set_seq(9);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                v_inerc = v_inerc * 0.25;
              if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
              {
                play_sfx(1);
                h_inerc = 4.0;
                v_inerc = 15.0;
                v_force = 0.5;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 7.0;
                addbullet(this, NULL, 849, x, y, dir, 1, t, 3);
              }
            }
            return;
          case 310:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
            {
              h_inerc = 0.0;
              v_inerc = 0.0;
              v_force = 0.5;
              field_7D0 = 0;
              field_194 = 99;
              field_190 = 0;
            }
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
                v_force = 0.0;
                y = getlvl_height();
                set_seq(9);
                return;
              }
            }
LABEL_895:
            if ( process() )
              goto LABEL_896;
            return;
          case 320:
            sub10func();
            if ( true /*!get_true(0)*/ )
            {
              if ( !get_frame_time() && !get_frame() )
              {
                field_49A = 0;
                field_194 = 1;
                field_190 = 0;
              }
              if ( process() )
                set_seq(0);
              if ( !get_frame_time() && get_frame() == 2 )
              {
                scene_play_sfx(27);
                field_49A = 0;
              }
            }
            return;
          case 321:
            sub10func();
            if ( true /*!get_true(0)*/ )
            {
              if ( !get_frame_time() && !get_frame() )
              {
                if ( !field_49A )
                  reset_forces();
                field_194 = 1;
                field_190 = 0;
              }
              if ( get_frame() > 4 )
              {
                h_inerc = h_inerc - 0.75;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                set_seq(0);
              if ( !get_frame_time() )
              {
                if ( get_frame() == 3 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 1.0;
                  addbullet(this, NULL, 849, x, y, dir, 1, t, 3);
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 4 )
                  {
                    play_sfx(0);
                    h_inerc = 10.0;
                    field_49A = 0;
                  }
                  if ( !get_frame_time() && get_frame() == 6 )
                    h_inerc = 0.0;
                }
              }
            }
            return;
          case 322:
            sub10func();
            if ( false /*get_true(1)*/  )
              return;
            if ( !get_frame_time() && !get_frame() )
            {
              if ( !field_49A )
                reset_forces();
              field_194 = 1;
              field_190 = 0;
            }
            if ( get_frame() >= 5 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( get_frame_time() )
              return;
            if ( get_frame() == 3 )
            {
              h_inerc = 15.0;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 5.0;
              addbullet(this, NULL, 849, x, y, dir, 1, t, 3);
            }
            goto LABEL_2606;
          case 330:
            goto LABEL_653;
          case 400:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              goto LABEL_2723;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(0);
              return;
            }
            if ( get_subseq() || get_frame_time() )
              goto LABEL_967;
            if ( get_frame() == 3 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(80 * (char)dir) + x, y + 108.0, dir, 1);
              return;
            }
            if ( get_frame() == 3 )
              goto LABEL_957;
            if ( get_frame() == 6 || get_frame() == 9 )
            {
              if ( get_frame() == 3 )
              {
LABEL_957:
                spell_energy_spend(200, 45);
                field_190 = 1;
              }
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -20.0 )
                field_7E4 = -20.0;
              if ( field_7E4 > 20.0 )
                field_7E4 = 20.0;
              field_7E4 = scene_rand_rng(9) - 4.0 + field_7E4;
              t[0] = field_7E4;
              t[1] = 25.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(76 * (char)dir) + x, y + 106.0, dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 800, (double)(76 * (char)dir) + x, y + 106.0, dir, 1, t, 3);
              if ( field_8A8 >= 1 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (field_8AC + 76.0) * (double)(char)dir + x, y + 106.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (field_8AC + 76.0) * (double)(char)dir + x, y + 106.0, dir, 1, t, 3);
              }
              if ( field_8A8 == 2 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (76.0 - field_8AC) * (double)(char)dir + x, y + 106.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (76.0 - field_8AC) * (double)(char)dir + x, y + 106.0, dir, 1, t, 3);
              }
              add_card_energy(10);
            }
LABEL_967:
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() == 1 )
              goto LABEL_975;
            if ( get_frame() != 4 && get_frame() != 7 && get_frame() != 10 && get_frame() != 13 )
              return;
            if ( get_frame() == 1 )
            {
LABEL_975:
              spell_energy_spend(200, 45);
              field_190 = 1;
            }
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -20.0 )
              field_7E4 = -20.0;
            if ( field_7E4 > 20.0 )
              field_7E4 = 20.0;
            field_7E4 = scene_rand_rng(9) - 4.0 + field_7E4;
            t[0] = field_7E4;
            t[1] = 25.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(76 * (char)dir) + x, y + 106.0, dir, 1, t, 3);
            t[2] = 1.0;
            addbullet(this, NULL, 800, (double)(76 * (char)dir) + x, y + 106.0, dir, 1, t, 3);
            if ( field_8A8 >= 1 )
            {
              t[0] = field_7E4;
              t[1] = 25.0;
              t[2] = 4.0;
              addbullet(this, NULL, 800, (field_8AC + 76.0) * (double)(char)dir + x, y + 106.0, dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 800, (field_8AC + 76.0) * (double)(char)dir + x, y + 106.0, dir, 1, t, 3);
            }
            if ( field_8A8 != 2 )
              goto LABEL_1066;
            t[0] = field_7E4;
            t[1] = 25.0;
            t[2] = 4.0;
            addbullet(this, NULL, 800, (76.0 - field_8AC) * (double)(char)dir + x, y + 106.0, dir, 1, t, 3);
            t[2] = 1.0;
            x = dir;
            v1480 = y + 106.0;
            v325 = (76.0 - field_8AC) * (double)(char)x + x;
            goto LABEL_1065;
          case 401:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              goto LABEL_2701;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(0);
              return;
            }
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1011;
            if ( get_frame() == 3 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(72 * (char)dir) + x, y + 136.0, dir, 1);
              return;
            }
            if ( get_frame() == 3 )
              goto LABEL_1001;
            if ( get_frame() == 6 || get_frame() == 9 )
            {
              if ( get_frame() == 3 )
              {
LABEL_1001:
                spell_energy_spend(200, 45);
                field_190 = 1;
              }
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -60.0 )
                field_7E4 = -60.0;
              if ( field_7E4 > -20.0 )
                field_7E4 = -20.0;
              field_7E4 = scene_rand_rng(9) - 4.0 + field_7E4;
              t[0] = field_7E4;
              t[1] = 25.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(73 * (char)dir) + x, y + 138.0, dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 800, (double)(73 * (char)dir) + x, y + 138.0, dir, 1, t, 3);
              if ( field_8A8 >= 1 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (field_8AC + 73.0) * (double)(char)dir + x, y + 138.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (field_8AC + 73.0) * (double)(char)dir + x, y + 138.0, dir, 1, t, 3);
              }
              if ( field_8A8 == 2 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (73.0 - field_8AC) * (double)(char)dir + x, y + 138.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (73.0 - field_8AC) * (double)(char)dir + x, y + 138.0, dir, 1, t, 3);
              }
              add_card_energy(10);
            }
LABEL_1011:
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() == 1 )
              goto LABEL_1019;
            if ( get_frame() != 4 && get_frame() != 7 && get_frame() != 10 && get_frame() != 13 )
              return;
            if ( get_frame() == 1 )
            {
LABEL_1019:
              spell_energy_spend(200, 45);
              field_190 = 1;
            }
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -60.0 )
              field_7E4 = -60.0;
            if ( field_7E4 > -20.0 )
              field_7E4 = -20.0;
            field_7E4 = scene_rand_rng(9) - 4.0 + field_7E4;
            t[0] = field_7E4;
            t[1] = 25.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(73 * (char)dir) + x, y + 138.0, dir, 1, t, 3);
            t[2] = 1.0;
            addbullet(this, NULL, 800, (double)(73 * (char)dir) + x, y + 138.0, dir, 1, t, 3);
            if ( field_8A8 >= 1 )
            {
              t[0] = field_7E4;
              t[1] = 25.0;
              t[2] = 4.0;
              addbullet(this, NULL, 800, (field_8AC + 73.0) * (double)(char)dir + x, y + 138.0, dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 800, (field_8AC + 73.0) * (double)(char)dir + x, y + 138.0, dir, 1, t, 3);
            }
            if ( field_8A8 != 2 )
              goto LABEL_1066;
            t[0] = field_7E4;
            t[1] = 25.0;
            t[2] = 4.0;
            addbullet(this, NULL, 800, (73.0 - field_8AC) * (double)(char)dir + x, y + 138.0, dir, 1, t, 3);
            t[2] = 1.0;
            x = dir;
            v1480 = y + 138.0;
            v325 = (73.0 - field_8AC) * (double)(char)x + x;
            goto LABEL_1065;
          case 402:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(2);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(2);
              return;
            }
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1052;
            if ( get_frame() == 3 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(70 * (char)dir) + x, y + 64.0, dir, 1);
              return;
            }
            if ( get_frame() == 3 )
              goto LABEL_1046;
            if ( get_frame() == 6 || get_frame() == 9 )
            {
              if ( get_frame() == 3 )
              {
LABEL_1046:
                spell_energy_spend(200, 45);
                field_190 = 1;
              }
              field_7E4 = scene_rand_rng(9) - 4.0;
              t[0] = field_7E4;
              t[1] = 25.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 64.0, dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 64.0, dir, 1, t, 3);
              if ( field_8A8 >= 1 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (field_8AC + 70.0) * (double)(char)dir + x, y + 64.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (field_8AC + 70.0) * (double)(char)dir + x, y + 64.0, dir, 1, t, 3);
              }
              if ( field_8A8 == 2 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (70.0 - field_8AC) * (double)(char)dir + x, y + 64.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (70.0 - field_8AC) * (double)(char)dir + x, y + 64.0, dir, 1, t, 3);
              }
              add_card_energy(10);
            }
LABEL_1052:
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() == 1 )
              goto LABEL_1060;
            if ( get_frame() == 4 || get_frame() == 7 || get_frame() == 10 || get_frame() == 13 )
            {
              if ( get_frame() == 1 )
              {
LABEL_1060:
                spell_energy_spend(200, 45);
                field_190 = 1;
              }
              field_7E4 = scene_rand_rng(9) - 4.0;
              t[0] = field_7E4;
              t[1] = 25.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 64.0, dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 64.0, dir, 1, t, 3);
              if ( field_8A8 >= 1 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (field_8AC + 70.0) * (double)(char)dir + x, y + 64.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (field_8AC + 70.0) * (double)(char)dir + x, y + 64.0, dir, 1, t, 3);
              }
              if ( field_8A8 == 2 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (70.0 - field_8AC) * (double)(char)dir + x, y + 64.0, dir, 1, t, 3);
                t[2] = 1.0;
                x = dir;
                v1480 = y + 64.0;
                v325 = (70.0 - field_8AC) * (double)(char)x + x;
LABEL_1065:
                addbullet(this, NULL, 800, v325, v1480, x, 1, t, 3);
              }
LABEL_1066:
              add_card_energy(10);
            }
            return;
          case 404:
            if ( get_subseq() == 2 )
              sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() < 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1129;
            }
            if ( process() )
              goto LABEL_2701;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1078;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
              set_seq(9);
              return;
            }
            if ( get_subseq() )
              goto LABEL_1106;
            if ( get_frame_time() )
              goto LABEL_1103;
            if ( get_frame() == 3 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(66 * (char)dir) + x, y + 129.0, dir, 1);
              return;
            }
            if ( get_frame() == 3 )
              goto LABEL_1093;
            if ( get_frame() == 6 || get_frame() == 9 )
            {
              if ( get_frame() == 3 )
              {
LABEL_1093:
                spell_energy_spend(200, 45);
                field_190 = 1;
              }
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -20.0 )
                field_7E4 = -20.0;
              if ( field_7E4 > 20.0 )
                field_7E4 = 20.0;
              field_7E4 = scene_rand_rng(9) - 4.0 + field_7E4;
              t[0] = field_7E4;
              t[1] = 25.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(67 * (char)dir) + x, y + 130.0, dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 800, (double)(67 * (char)dir) + x, y + 130.0, dir, 1, t, 3);
              if ( field_8A8 >= 1 )
              {
                t[2] = field_7E4;
                t[2] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (field_8AC + 67.0) * (double)(char)dir + x, y + 140.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (field_8AC + 67.0) * (double)(char)dir + x, y + 140.0, dir, 1, t, 3);
              }
              if ( field_8A8 == 2 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (67.0 - field_8AC) * (double)(char)dir + x, y + 140.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (67.0 - field_8AC) * (double)(char)dir + x, y + 140.0, dir, 1, t, 3);
              }
              add_card_energy(10);
            }
LABEL_1103:
            if ( !get_frame_time() && get_frame() == 12 )
              v_force = 0.60000002;
LABEL_1106:
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() == 1 )
              goto LABEL_1114;
            if ( get_frame() != 4 && get_frame() != 7 && get_frame() != 10 && get_frame() != 13 )
              goto LABEL_1182;
            if ( get_frame() == 1 )
            {
LABEL_1114:
              spell_energy_spend(200, 45);
              field_190 = 1;
            }
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -20.0 )
              field_7E4 = -20.0;
            if ( field_7E4 > 20.0 )
              field_7E4 = 20.0;
            field_7E4 = scene_rand_rng(9) - 4.0 + field_7E4;
            t[0] = field_7E4;
            t[1] = 25.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(67 * (char)dir) + x, y + 130.0, dir, 1, t, 3);
            t[2] = 1.0;
            addbullet(this, NULL, 800, (double)(67 * (char)dir) + x, y + 130.0, dir, 1, t, 3);
            if ( field_8A8 >= 1 )
            {
              t[0] = field_7E4;
              t[1] = 25.0;
              t[2] = 4.0;
              addbullet(this, NULL, 800, (field_8AC + 67.0) * (double)(char)dir + x, y + 130.0, dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 800, (field_8AC + 67.0) * (double)(char)dir + x, y + 130.0, dir, 1, t, 3);
            }
            if ( field_8A8 != 2 )
              goto LABEL_1181;
            t[0] = field_7E4;
            t[1] = 25.0;
            t[2] = 4.0;
            addbullet(this, NULL, 800, (67.0 - field_8AC) * (double)(char)dir + x, y + 130.0, dir, 1, t, 3);
            t[2] = 1.0;
            v1481 = y + 130.0;
            v510 = (67.0 - field_8AC) * (double)(char)dir + x;
            goto LABEL_1180;
          case 406:
            if ( get_subseq() == 2 )
              sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() < 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1129:
                set_subseq(2);
                air_dash_cnt = 0;
                y = getlvl_height();
                reset_forces();
                return;
              }
            }
            if ( process() )
              goto LABEL_2701;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(9);
              return;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
              set_seq(9);
              return;
            }
            if ( get_subseq() )
              goto LABEL_1163;
            if ( get_frame_time() )
              goto LABEL_1160;
            if ( get_frame() == 4 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(56 * (char)dir) + x, y + 100.0, dir, 1);
              return;
            }
            if ( get_frame() == 4 )
              goto LABEL_1150;
            if ( get_frame() == 7 || get_frame() == 10 )
            {
              if ( get_frame() == 4 )
              {
LABEL_1150:
                spell_energy_spend(200, 45);
                field_190 = 1;
              }
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < 20.0 )
                field_7E4 = 20.0;
              if ( field_7E4 > 60.0 )
                field_7E4 = 60.0;
              field_7E4 = scene_rand_rng(9) - 4.0 + field_7E4;
              t[0] = field_7E4;
              t[1] = 25.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(56 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 800, (double)(56 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
              if ( field_8A8 >= 1 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (field_8AC + 56.0) * (double)(char)dir + x, y + 100.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (field_8AC + 56.0) * (double)(char)dir + x, y + 100.0, dir, 1, t, 3);
              }
              if ( field_8A8 == 2 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (56.0 - field_8AC) * (double)(char)dir + x, y + 100.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (56.0 - field_8AC) * (double)(char)dir + x, y + 100.0, dir, 1, t, 3);
              }
              add_card_energy(10);
            }
LABEL_1160:
            if ( !get_frame_time() && get_frame() == 12 )
              v_force = 0.60000002;
LABEL_1163:
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() == 1 )
              goto LABEL_1171;
            if ( get_frame() == 4 || get_frame() == 7 || get_frame() == 10 || get_frame() == 13 )
            {
              if ( get_frame() == 1 )
              {
LABEL_1171:
                spell_energy_spend(200, 45);
                field_190 = 1;
              }
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < 20.0 )
                field_7E4 = 20.0;
              if ( field_7E4 > 60.0 )
                field_7E4 = 60.0;
              field_7E4 = scene_rand_rng(9) - 4.0 + field_7E4;
              t[0] = field_7E4;
              t[1] = 25.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(56 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 800, (double)(56 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
              if ( field_8A8 >= 1 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (field_8AC + 56.0) * (double)(char)dir + x, y + 100.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 800, (field_8AC + 56.0) * (double)(char)dir + x, y + 100.0, dir, 1, t, 3);
              }
              if ( field_8A8 == 2 )
              {
                t[0] = field_7E4;
                t[1] = 25.0;
                t[2] = 4.0;
                addbullet(this, NULL, 800, (56.0 - field_8AC) * (double)(char)dir + x, y + 100.0, dir, 1, t, 3);
                t[2] = 1.0;
                v1481 = y + 100.0;
                v510 = (56.0 - field_8AC) * (double)(char)dir + x;
LABEL_1180:
                addbullet(this, NULL, 800, v510, v1481, dir, 1, t, 3);
              }
LABEL_1181:
              add_card_energy(10);
            }
LABEL_1182:
            if ( !get_frame_time() && get_frame() == 15 )
              v_force = 0.60000002;
            return;
          case 408:
            sub10func();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
            {
              field_49A = 0;
              field_194 = 1;
              h_inerc = 12.0;
              field_190 = 0;
              reset_forces();
              not_charge_attack = 1;
            }
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            if ( get_subseq() == 2 && h_inerc > 0.0 )
            {
              h_inerc = h_inerc - 1.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
            {
              h_inerc = 12.0;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 3.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
              //color_A = 0;
              field_892 = 0;
            }
            if ( get_subseq() == 1 )
            {
              if ( !get_elaps_frames() )
                scene_play_sfx(29);
              if ( get_elaps_frames() > 12 )
                next_subseq();
            }
            return;
          case 409:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
            {
              v_force = 0.34999999;
              field_49A = 0;
              field_7D0 = 0;
              field_194 = 1;
              field_190 = 0;
            }
            v_inerc = v_inerc - v_force;
            if ( !char_on_ground_down() )
              goto LABEL_895;
            set_seq(10);
            goto LABEL_1582;
          case 410:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
            {
              field_190 = 1;
              reset_forces();
              field_7D0 = 0;
              field_7D2 = 0;
              field_7D6 = 0;
              not_charge_attack = 1;
            }
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_2723;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1241;
            if ( get_frame() == 3 && not_charge_attack == 1 )
            {
              scene_add_effect(this, 62, x - (double)(46 * (char)dir), y + 128.0, dir, 1);
              next_subseq();
              return;
            }
            if ( get_frame() == 4 )
            {
              spell_energy_spend(200, 60);
              field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7D4 < -10 )
                field_7D4 = -10;
              if ( field_7D4 > 10 )
                field_7D4 = 10;
              t[0] = (double)field_7D4;
              t[1] = 5.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(72 * (char)dir) + x, y + 95.0, dir, 1, t, 3);
              t[2] = 4.0;
              addbullet(this, NULL, 801, (double)(72 * (char)dir) + x, y + 95.0, dir, 1, t, 3);
              if ( field_8A8 >= 1 )
              {
                t[0] = (double)field_7D4;
                t[1] = 5.0;
                t[2] = 8.0;
                addbullet(this, NULL, 801, (field_8AC + 72.0) * (double)(char)dir + x, y + 95.0, dir, 1, t, 3);
                t[2] = 4.0;
                addbullet(this, NULL, 801, (field_8AC + 72.0) * (double)(char)dir + x, y + 95.0, dir, 1, t, 3);
              }
              if ( field_8A8 == 2 )
              {
                t[0] = (double)field_7D4;
                t[1] = 5.0;
                t[2] = 8.0;
                addbullet(this, NULL, 801, (72.0 - field_8AC) * (double)(char)dir + x, y + 95.0, dir, 1, t, 3);
                t[2] = 4.0;
                addbullet(this, NULL, 801, (72.0 - field_8AC) * (double)(char)dir + x, y + 95.0, dir, 1, t, 3);
              }
              add_card_energy(50);
              play_sfx(3);
            }
LABEL_1241:
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            spell_energy_spend(200, 60);
            field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7D4 < -10 )
              field_7D4 = -10;
            if ( field_7D4 > 10 )
              field_7D4 = 10;
            tt[1] = 5.0;
            tt[2] = 7.0;
            /*
            v1520 = 0.0;
            v617 = (float)0.0;
            do
            {
              *(float *)&v1604 = (double)field_7D4 + 40.0 - v617 * 20.0;
              v618 = dir;
              v619 = y + 95.0;
              v620 = v619;
              v621 = (double)(72 * (char)v618) + x;
              addbullet(this, NULL, 801, v621, v620, v618, 1, (int)&v1604, 3);
              v1520 = v1520 + 1.0;
              v617 = v1520;
            }
            while ( v1520 < 5.0 );*/
            tt[3] = 4.0;
            addbullet(this, NULL, 801, (double)(72 * (char)dir) + x, y + 95.0, dir, 1, tt, 3);
            if ( field_8A8 >= 1 )
            {
              /*v1606 = 9.0;
              v1521 = 0.0;
              v626 = (float)0.0;
              do
              {
                *(float *)&v1604 = (double)field_7D4 + 50.0 - v626 * 25.0;
                v627 = dir;
                v628 = y + 95.0;
                v629 = v628;
                v630 = (field_8AC + 72.0) * (double)(char)v627 + x;
                addbullet(this, NULL, 801, v630, v629, v627, 1, (int)&v1604, 3);
                v1521 = v1521 + 1.0;
                v626 = v1521;
              }
              while ( v1521 < 5.0 );
              v1606 = 4.0;*/
              addbullet(this, NULL, 801, (field_8AC + 72.0) * (double)(char)dir + x, y + 95.0, dir, 1, tt, 3);
            }
            if ( field_8A8 != 2 )
              goto LABEL_1303;
            /*
            v1606 = 9.0;
            v1522 = 0.0;
            v635 = (float)0.0;
            do
            {
              *(float *)&v1604 = (double)field_7D4 + 50.0 - v635 * 25.0;
              v636 = dir;
              v637 = y + 95.0;
              v638 = v637;
              v639 = (72.0 - field_8AC) * (double)(char)v636 + x;
              addbullet(this, NULL, 801, v639, v638, v636, 1, (int)&v1604, 3);
              v1522 = v1522 + 1.0;
              v635 = v1522;
            }
            while ( v1522 < 5.0 );
            v1606 = 4.0;*/
            v1482 = y + 95.0;
            v642 = (72.0 - field_8AC) * (double)(char)dir + x;
            goto LABEL_1302;
          case 411:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
            {
              field_190 = 1;
              reset_forces();
              field_7D0 = 0;
              field_7D2 = 0;
              field_7D6 = 0;
              not_charge_attack = 1;
            }
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_2701;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1285;
            if ( get_frame() != 3 || not_charge_attack != 1 )
            {
              if ( get_frame() == 4 )
              {
                spell_energy_spend(200, 60);
                field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7D4 < -50 )
                  field_7D4 = -50;
                if ( field_7D4 > -20 )
                  field_7D4 = -20;
                t[0] = (double)field_7D4;
                t[1] = 5.0;
                t[2] = 0.0;
                addbullet(this, NULL, 801, (double)(66 * (char)dir) + x, y + 128.0, dir, 1, t, 3);
                t[2] = 4.0;
                addbullet(this, NULL, 801, (double)(66 * (char)dir) + x, y + 128.0, dir, 1, t, 3);
                if ( field_8A8 >= 1 )
                {
                  t[0] = (double)field_7D4;
                  t[1] = 5.0;
                  t[2] = 8.0;
                  addbullet(this, NULL, 801, (field_8AC + 66.0) * (double)(char)dir + x, y + 128.0, dir, 1, t, 3);
                  t[2] = 4.0;
                  addbullet(this, NULL, 801, (field_8AC + 66.0) * (double)(char)dir + x, y + 128.0, dir, 1, t, 3);
                }
                if ( field_8A8 == 2 )
                {
                  t[0] = (double)field_7D4;
                  t[1] = 5.0;
                  t[2] = 8.0;
                  addbullet(this, NULL, 801, (66.0 - field_8AC) * (double)(char)dir + x, y + 128.0, dir, 1, t, 3);
                  t[2] = 4.0;
                  addbullet(this, NULL, 801, (66.0 - field_8AC) * (double)(char)dir + x, y + 128.0, dir, 1, t, 3);
                }
                add_card_energy(50);
                play_sfx(3);
              }
LABEL_1285:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
              {
                spell_energy_spend(200, 60);
                field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7D4 < -50 )
                  field_7D4 = -50;
                if ( field_7D4 > -20 )
                  field_7D4 = -20;
                /*
                v1587 = 5.0;
                v1588 = 7.0;
                v1523 = 0.0;
                v681 = (float)0.0;
                do
                {
                  *(float *)&v1586 = (double)field_7D4 + 40.0 - v681 * 20.0;
                  v682 = dir;
                  v683 = y + 128.0;
                  v684 = v683;
                  v685 = (double)(66 * (char)v682) + x;
                  addbullet(this, NULL, 801, v685, v684, v682, 1, (int)&v1586, 3);
                  v1523 = v1523 + 1.0;
                  v681 = v1523;
                }
                while ( v1523 < 5.0 );
                v1588 = 4.0;*/
                addbullet(this, NULL, 801, (double)(66 * (char)dir) + x, y + 128.0, dir, 1, t, 3);
                if ( field_8A8 >= 1 )
                {
                  /*
                  v1587 = 5.0;
                  v1588 = 9.0;
                  v1524 = 0.0;
                  v690 = (float)0.0;
                  do
                  {
                    *(float *)&v1586 = (double)field_7D4 + 40.0 - v690 * 20.0;
                    v691 = dir;
                    v692 = y + 128.0;
                    v693 = v692;
                    v694 = (field_8AC + 66.0) * (double)(char)v691 + x;
                    addbullet(this, NULL, 801, v694, v693, v691, 1, (int)&v1586, 3);
                    v1524 = v1524 + 1.0;
                    v690 = v1524;
                  }
                  while ( v1524 < 5.0 );
                  v1588 = 4.0;*/
                  addbullet(this, NULL, 801, (field_8AC + 66.0) * (double)(char)dir + x, y + 128.0, dir, 1, t, 3);
                }
                if ( field_8A8 == 2 )
                {
                  /*
                  v1587 = 5.0;
                  v1588 = 9.0;
                  v1525 = 0.0;
                  v699 = (float)0.0;
                  do
                  {
                    *(float *)&v1586 = (double)field_7D4 + 40.0 - v699 * 20.0;
                    v700 = dir;
                    v701 = y + 128.0;
                    v702 = v701;
                    v703 = (66.0 - field_8AC) * (double)(char)v700 + x;
                    addbullet(this, NULL, 801, v703, v702, v700, 1, (int)&v1586, 3);
                    v1525 = v1525 + 1.0;
                    v699 = v1525;
                  }
                  while ( v1525 < 5.0 );
                  v1588 = 4.0;
                  */
                  v1482 = y + 128.0;
                  v642 = (66.0 - field_8AC) * (double)(char)dir + x;
LABEL_1302:
                  addbullet(this, NULL, 801, v642, v1482, dir, 1, tt, 3);
                }
LABEL_1303:
                add_card_energy(50);
                play_sfx(3);
              }
            }
            else
            {
              scene_add_effect(this, 62, x - (double)(46 * (char)dir), y + 128.0, dir, 1);
              next_subseq();
            }
            return;
          case 412:
            if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
            {
              play_sfx(7);
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 802, x, y, dir, 1, t, 3);
              if ( field_8A8 >= 1 )
              {
                t[0] = field_8AC;
                t[2] = 4.0;
                addbullet(this, NULL, 802, (double)(char)dir * field_8AC + x, y, dir, 1, t, 3);
              }
              if ( field_8A8 == 2 )
              {
                t[0] = -field_8AC;
                t[2] = 4.0;
                addbullet(this, NULL, 802, x - (double)(char)dir * field_8AC, y, dir, 1, t, 3);
              }
              spell_energy_spend(200, 60);
              add_card_energy(50);
            }
            if ( process() )
              set_seq(2);
            return;
          case 414:
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() < 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1406;
            }
            if ( process() )
              goto LABEL_2701;
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_1078;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1341;
            if ( get_frame() == 3 && not_charge_attack == 1 )
            {
              scene_add_effect(this, 62, x - (double)(47 * (char)dir), y + 142.0, dir, 1);
              next_subseq();
              return;
            }
            if ( get_frame() == 4 )
            {
              spell_energy_spend(200, 60);
              field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7D4 < -10 )
                field_7D4 = -10;
              if ( field_7D4 > 10 )
                field_7D4 = 10;
              t[0] = (double)field_7D4;
              t[1] = 5.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(62 * (char)dir) + x,  y + 127.0, dir, 1, t, 3);
              t[2] = 4.0;
              addbullet(this, NULL, 801, (double)(62 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
              if ( field_8A8 >= 1 )
              {
                t[0] = (double)field_7D4;
                t[1] = 5.0;
                t[2] = 8.0;
                addbullet(this, NULL, 801, (field_8AC + 62.0) * (double)(char)dir + x, y + 127.0, dir, 1, t, 3);
                t[2] = 4.0;
                addbullet(this, NULL, 801, (field_8AC + 62.0) * (double)(char)dir + x, y + 127.0, dir, 1, t, 3);
              }
              if ( field_8A8 == 2 )
              {
                t[0] = (double)field_7D4;
                t[1] = 5.0;
                t[2] = 8.0;
                addbullet(this, NULL, 801, (62.0 - field_8AC) * (double)(char)dir + x, y + 127.0, dir, 1, t, 3);
                t[2] = 4.0;
                addbullet(this, NULL, 801, (62.0 - field_8AC) * (double)(char)dir + x, y + 127.0, dir, 1, t, 3);
              }
              play_sfx(3);
              h_inerc = -6.0;
              v_inerc = 5.0;
              v_force = 0.60000002;
              add_card_energy(50);
            }
LABEL_1341:
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            spell_energy_spend(200, 60);
            field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7D4 < -10 )
              field_7D4 = -10;
            if ( field_7D4 > 10 )
              field_7D4 = 10;
            /*
            v1575 = 5.0;
            v1576 = 7.0;
            v1526 = 0.0;
            v749 = (float)0.0;
            do
            {
              *(float *)&v1574 = (double)field_7D4 + 40.0 - v749 * 20.0;
              v750 = dir;
              v751 = y + 127.0;
              v752 = v751;
              v753 = (double)(62 * (char)v750) + x;
              addbullet(this, NULL, 801, v753, v752, v750, 1, (int)&v1574, 3);
              v1526 = v1526 + 1.0;
              v749 = v1526;
            }
            while ( v1526 < 5.0 );
            v1576 = 4.0;*/
            addbullet(this, NULL, 801, (double)(62 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
            if ( field_8A8 >= 1 )
            {
              /*
              v1575 = 5.0;
              v1576 = 9.0;
              v1527 = 0.0;
              v758 = (float)0.0;
              do
              {
                *(float *)&v1574 = (double)field_7D4 + 40.0 - v758 * 20.0;
                v759 = dir;
                v760 = y + 127.0;
                v761 = v760;
                v762 = (field_8AC + 62.0) * (double)(char)v759 + x;
                addbullet(this, NULL, 801, v762, v761, v759, 1, (int)&v1574, 3);
                v1527 = v1527 + 1.0;
                v758 = v1527;
              }
              while ( v1527 < 5.0 );
              v1576 = 4.0;*/
              addbullet(this, NULL, 801, (field_8AC + 62.0) * (double)(char)dir + x, y + 127.0, dir, 1, t, 3);
            }
            if ( field_8A8 != 2 )
              goto LABEL_1448;
            /*
            v1575 = 5.0;
            v1576 = 9.0;
            v1528 = 0.0;
            v767 = (float)0.0;
            do
            {
              *(float *)&v1574 = (double)field_7D4 + 40.0 - v767 * 20.0;
              v768 = dir;
              v769 = y + 127.0;
              v770 = v769;
              v771 = (62.0 - field_8AC) * (double)(char)v768 + x;
              addbullet(this, NULL, 801, v771, v770, v768, 1, (int)&v1574, 3);
              v1528 = v1528 + 1.0;
              v767 = v1528;
            }
            while ( v1528 < 5.0 );
            v1576 = 4.0;*/
            v1483 = y + 127.0;
            v774 = (62.0 - field_8AC) * (double)(char)dir + x;
            goto LABEL_1447;
          case 415:
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() < 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1406;
            }
            if ( process() )
              goto LABEL_2701;
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_1078;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1385;
            if ( get_frame() == 3 && not_charge_attack == 1 )
            {
              scene_add_effect(this, 62, x - (double)(47 * (char)dir), y + 142.0, dir, 1);
              next_subseq();
              return;
            }
            if ( get_frame() == 4 )
            {
              spell_energy_spend(200, 60);
              field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7D4 < -10 )
                field_7D4 = -10;
              if ( field_7D4 > 10 )
                field_7D4 = 10;
              t[0] = (double)field_7D4;
              t[1] = 5.0;
              t[2] = 0.0;
              addbullet(this, NULL, 801, (double)(62 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
              t[2] = 4.0;
              addbullet(this, NULL, 801, (double)(62 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
              if ( field_8A8 >= 1 )
              {
                t[0] = (double)field_7D4;
                t[1] = 5.0;
                t[2] = 8.0;
                addbullet(this, NULL, 801, (field_8AC + 62.0) * (double)(char)dir + x, y + 127.0, dir, 1, t, 3);
                t[2] = 4.0;
                addbullet(this, NULL, 801, (field_8AC + 62.0) * (double)(char)dir + x, y + 127.0, dir, 1, t, 3);
              }
              if ( field_8A8 == 2 )
              {
                t[0] = (double)field_7D4;
                t[1] = 5.0;
                t[2] = 8.0;
                addbullet(this, NULL, 801, (62.0 - field_8AC) * (double)(char)dir + x, y + 127.0, dir, 1, t, 3);
                t[2] = 4.0;
                addbullet(this, NULL, 801, (62.0 - field_8AC) * (double)(char)dir + x, y + 127.0, dir, 1, t, 3);
              }
              play_sfx(3);
              h_inerc = -6.0;
              v_inerc = 5.0;
              v_force = 0.60000002;
              add_card_energy(50);
            }
LABEL_1385:
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            spell_energy_spend(200, 60);
            field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7D4 < -10 )
              field_7D4 = -10;
            if ( field_7D4 > 10 )
              field_7D4 = 10;
            /*
            v1557 = 5.0;
            v1558 = 7.0;
            v1529 = 0.0;
            v813 = (float)0.0;
            do
            {
              *(float *)&v1556 = (double)field_7D4 + 40.0 - v813 * 20.0;
              v814 = dir;
              v815 = y + 127.0;
              v816 = v815;
              v817 = (double)(62 * (char)v814) + x;
              addbullet(this, NULL, 801, v817, v816, v814, 1, (int)&v1556, 3);
              v1529 = v1529 + 1.0;
              v813 = v1529;
            }
            while ( v1529 < 5.0 );
            v1558 = 4.0;*/
            addbullet(this, NULL, 801, (double)(62 * (char)dir) + x, y + 127.0, dir, 1,t, 3);
            if ( field_8A8 >= 1 )
            {
              /*
              v1557 = 5.0;
              v1558 = 9.0;
              v1530 = 0.0;
              v822 = (float)0.0;
              do
              {
                *(float *)&v1556 = (double)field_7D4 + 40.0 - v822 * 20.0;
                v823 = dir;
                v824 = y + 127.0;
                v825 = v824;
                v826 = (field_8AC + 62.0) * (double)(char)v823 + x;
                addbullet(this, NULL, 801, v826, v825, v823, 1, (int)&v1556, 3);
                v1530 = v1530 + 1.0;
                v822 = v1530;
              }
              while ( v1530 < 5.0 );
              v1558 = 4.0;*/
              addbullet(this, NULL, 801, (field_8AC + 62.0) * (double)(char)dir + x, y + 127.0, dir, 1, t, 3);
            }
            if ( field_8A8 != 2 )
              goto LABEL_1448;
            /*
            v1557 = 5.0;
            v1558 = 9.0;
            v1531 = 0.0;
            v831 = (float)0.0;
            do
            {
              *(float *)&v1556 = (double)field_7D4 + 40.0 - v831 * 20.0;
              v832 = dir;
              v833 = y + 127.0;
              v834 = v833;
              v835 = (62.0 - field_8AC) * (double)(char)v832 + x;
              addbullet(this, NULL, 801, v835, v834, v832, 1, (int)&v1556, 3);
              v1531 = v1531 + 1.0;
              v831 = v1531;
            }
            while ( v1531 < 5.0 );
            v1558 = 4.0;*/
            v1483 = y + 127.0;
            v774 = (62.0 - field_8AC) * (double)(char)dir + x;
            goto LABEL_1447;
          case 416:
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() < 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1406:
                set_subseq(2);
                reset_forces();
                y = getlvl_height();
                return;
              }
            }
            if ( process() )
              goto LABEL_2701;
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            {
LABEL_1078:
              set_seq(9);
              return;
            }
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1430;
            if ( get_frame() != 3 || not_charge_attack != 1 )
            {
              if ( get_frame() == 4 )
              {
                spell_energy_spend(200, 60);
                field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7D4 < 20 )
                  field_7D4 = 20;
                if ( field_7D4 > 50 )
                  field_7D4 = 50;
                t[0] = (double)field_7D4;
                t[1] = 5.0;
                t[2] = 0.0;
                addbullet(this, NULL, 801, (double)(dir << 6) + x, y + 105.0, dir, 1, t, 3);
                t[2] = 4.0;
                addbullet(this, NULL, 801, (double)((char)dir << 6) + x, y + 105.0, dir, 1,t, 3);
                if ( field_8A8 >= 1 )
                {
                  t[0] = (double)field_7D4;
                  t[1] = 5.0;
                  t[2] = 8.0;
                  addbullet(this, NULL, 801, (field_8AC + 64.0) * (double)(char)dir + x, y + 105.0, dir, 1, t, 3);
                  t[2] = 4.0;
                  addbullet(this, NULL, 801, (field_8AC + 64.0) * (double)(char)dir + x, y + 105.0, dir, 1, t, 3);
                }
                if ( field_8A8 == 2 )
                {
                  t[0] = (double)field_7D4;
                  t[1] = 5.0;
                  t[2] = 8.0;
                  addbullet(this, NULL, 801, (64.0 - field_8AC) * (double)(char)dir + x, y + 105.0, dir, 1, t, 3);
                  t[2] = 4.0;
                  addbullet(this, NULL, 801, (64.0 - field_8AC) * (double)(char)dir + x, y + 105.0, dir, 1, t, 3);
                }
                play_sfx(3);
                h_inerc = -6.0;
                v_inerc = 5.0;
                v_force = 0.60000002;
                add_card_energy(50);
              }
LABEL_1430:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
              {
                spell_energy_spend(200, 60);
                field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7D4 < 20 )
                  field_7D4 = 20;
                if ( field_7D4 > 50 )
                  field_7D4 = 50;
                /*
                v1569 = 5.0;
                v1570 = 7.0;
                v1532 = 0.0;
                v875 = (float)0.0;
                do
                {
                  *(float *)&v1568 = (double)field_7D4 + 40.0 - v875 * 20.0;
                  v876 = y + 105.0;
                  v877 = v876;
                  v878 = (double)(dir << 6) + x;
                  addbullet(this, NULL, 801, v878, v877, dir, 1, (int)&v1568, 3);
                  v1532 = v1532 + 1.0;
                  v875 = v1532;
                }
                while ( v1532 < 5.0 );
                v1570 = 4.0;*/
                addbullet(this, NULL, 801, (double)((char)dir << 6) + x, y + 105.0, dir, 1, t, 3);
                if ( field_8A8 >= 1 )
                {
                  /*
                  v1569 = 5.0;
                  v1570 = 8.0;
                  v1533 = 0.0;
                  v883 = (float)0.0;
                  do
                  {
                    *(float *)&v1568 = (double)field_7D4 + 40.0 - v883 * 20.0;
                    v884 = dir;
                    v885 = y + 105.0;
                    v886 = v885;
                    v887 = (field_8AC + 64.0) * (double)(char)v884 + x;
                    addbullet(this, NULL, 801, v887, v886, v884, 1, (int)&v1568, 3);
                    v1533 = v1533 + 1.0;
                    v883 = v1533;
                  }
                  while ( v1533 < 5.0 );
                  v1570 = 4.0;*/
                  addbullet(this, NULL, 801, (field_8AC + 64.0) * (double)(char)dir + x, y + 105.0, dir, 1, t, 3);
                }
                if ( field_8A8 == 2 )
                {/*
                  v1569 = 5.0;
                  v1570 = 8.0;
                  v1534 = 0.0;
                  v892 = (float)0.0;
                  do
                  {
                    *(float *)&v1568 = (double)field_7D4 + 40.0 - v892 * 20.0;
                    v893 = dir;
                    v894 = y + 105.0;
                    v895 = v894;
                    v896 = (64.0 - field_8AC) * (double)(char)v893 + x;
                    addbullet(this, NULL, 801, v896, v895, v893, 1, (int)&v1568, 3);
                    v1534 = v1534 + 1.0;
                    v892 = v1534;
                  }
                  while ( v1534 < 5.0 );
                  v1570 = 4.0;*/
                  v1483 = y + 105.0;
                  v774 = (64.0 - field_8AC) * (double)(char)dir + x;
LABEL_1447:
                  addbullet(this, NULL, 801, v774, v1483, dir, 1, t, 3);
                }
LABEL_1448:
                play_sfx(3);
                h_inerc = -6.0;
                v_inerc = 5.0;
                v_force = 0.60000002;
                add_card_energy(50);
              }
            }
            else
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(47 * (char)dir), y + 142.0, dir, 1);
            }
            break;
          case 418:
            if ( get_subseq() <= 0 )
              goto LABEL_1452;
            if ( get_subseq() >= 5 )
            {
LABEL_1452:
              if ( !(get_subseq() == 0) )
                goto LABEL_1460;
              if ( get_frame() <= 0 )
                goto LABEL_1460;
            }
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              y = getlvl_height();
              reset_forces();
              set_subseq(5);
            }
            else if ( field_190 && get_subseq() <= 1 )
            {
              reset_forces();
              set_subseq(4);
            }
            else
            {
              
LABEL_1460:
              if ( !get_subseq() && !get_frame() )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( get_subseq() != 1 || get_elaps_frames() < 24 )
              {
                if ( get_subseq() == 4 )
                {
                  h_inerc = h_inerc + 0.2000000029802322;
                  if ( h_inerc > 0.0 )
                    h_inerc = 0.0;
                }
                if ( process() )
                  set_seq(0);
                if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 5 )
                {
                  if ( !get_subseq() )
                  {
                    if ( !get_frame_time() )
                    {
                      if ( get_frame() == 1 )
                      {
                        h_inerc = 12.0;
                        v_inerc = 6.0;
                        v_force = 0.34999999;
                        t[0] = 0.0;
                        t[1] = h_inerc;
                        t[2] = 9.0;
                        addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
                      }
                      if ( !get_frame_time() && get_frame() == 8 )
                        scene_play_sfx(29);
                    }
                    if ( get_frame() >= 1 && get_frame() <= 3 )
                      field_892 = 0;
                  }
                  if ( get_subseq() == 4 && !get_frame_time() && get_frame() == 3 )
                  {
                    v_force = 0.5;
                    h_inerc = -10.0;
                    v_inerc = 7.0;
                  }
                }
                else
                {
LABEL_213:
                  set_subseq(3);
                }
              }
              else
              {
                next_subseq();
              }
            }
            return;
          default:
            goto LABEL_2713;
        }
      }
      return;
    }
    if ( get_seq() <= 770 )
    {
      if ( get_seq() == 770 )
      {
        if ( process() )
          set_seq(700);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
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
          case 501:
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(0);
            if ( get_subseq() || get_frame_time() || get_frame() != 4 )
              goto LABEL_1634;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -50.0 )
              field_7E4 = -50.0;
            if ( field_7E4 > -30.0 )
              field_7E4 = -30.0;
            t[0] = field_7E4;
            t[1] = 1.0;
            t[2] = 0.0;
            addbullet(this, NULL, 810, (double)(68 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
            t[2] = 5.0;
            addbullet(this, NULL, 810, (double)(68 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
            goto LABEL_1633;
          case 505:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -10.0 )
                field_7E4 = -10.0;
              if ( field_7E4 > 10.0 )
                field_7E4 = 10.0;
              t[0] = field_7E4;
              t[1] = 20.0;
              t[2] = 0.0;
              addbullet(this, NULL, 811, (double)(72 * (char)dir) + x, y + 95.0, dir, 1, t, 3);
              t[2] = 4.0;
              addbullet(this, NULL, 811, (double)(72 * (char)dir) + x, y + 95.0, dir, 1, t, 3);
              play_sfx(15);
            }
            goto LABEL_1634;
          case 506:
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -50.0 )
                field_7E4 = -50.0;
              if ( field_7E4 > -30.0 )
                field_7E4 = -30.0;
              t[0] = field_7E4;
              t[1] = 20.0;
              t[2] = 0.0;
              addbullet(this, NULL, 811, (double)(68 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
              t[2] = 4.0;
              play_sfx(15);
            }
            goto LABEL_1634;
          case 507:
            if ( get_subseq() < 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1581;
            }
            if ( process() )
              goto LABEL_2723;
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_896;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() != 4 )
              goto LABEL_1600;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -10.0 )
              field_7E4 = -10.0;
            if ( field_7E4 > 10.0 )
              field_7E4 = 10.0;
            t[0] = field_7E4;
            t[1] = 20.0;
            t[2] = 0.0;
            addbullet(this, NULL, 811, (double)(62 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
            t[2] = 4.0;
            v1484 = y + 127.0;
            v965 = (double)(62 * (char)dir) + x;
            goto LABEL_1599;
          case 508:
            if ( get_subseq() < 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1581:
                set_subseq(2);
LABEL_1582:
                reset_forces();
                y = getlvl_height();
                return;
              }
            }
            if ( process() )
              goto LABEL_2723;
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_896;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                spell_energy_spend(200, 60);
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7E4 < 20.0 )
                  field_7E4 = 20.0;
                if ( field_7E4 > 50.0 )
                  field_7E4 = 50.0;
                t[0] = field_7E4;
                t[1] = 20.0;
                t[2] = 0.0;
                addbullet(this, NULL, 811, (double)((char)dir << 6) + x, y + 105.0, dir, 1, t, 3);
                t[2] = 4.0;
                v1484 = y + 105.0;
                v965 = (double)((char)dir << 6) + x;
LABEL_1599:
                addbullet(this, NULL, 811, v965, v1484, dir, 1, t, 3);
                play_sfx(15);
                h_inerc = -6.0;
                v_inerc = 5.0;
                v_force = 0.60000002;
                add_card_energy(50);
              }
LABEL_1600:
              if ( !get_frame_time() )
              {
                v978 = get_frame() == 13;
                goto LABEL_2211;
              }
            }
            return;
          case 510:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(0);
            if ( get_subseq() || get_frame_time() || get_frame() != 4 )
              goto LABEL_1634;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            tt[0] = -40.0;
            tt[1] = 30.0;
            tt[2] = 0.0;
            tt[3] = 0.0;
            if ( not_charge_attack )
              tt[3] = 1.0;
            addbullet(this, NULL, 812, (double)(68 * (char)dir) + x, y + 127.0, dir, 1, tt, 4);
            tt[2] = 5.0;
            v1485 = y + 127.0;
            v985 = (double)(68 * (char)dir) + x;
            goto LABEL_1632;
          case 511:
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(0);
            if ( get_subseq() || get_frame_time() || get_frame() != 4 )
              goto LABEL_1634;
            field_190 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            tt[0] = -30.0;
            tt[1] = 50.0;
            tt[2] = 0.0;
            tt[3] = 0.0;
            if ( not_charge_attack )
              tt[3] = 2.0;
            addbullet(this, NULL, 812, (double)(68 * (char)dir) + x, y + 127.0, dir, 1, tt, 4);
            tt[2] = 5.0;
            v1485 = y + 127.0;
            v985 = (double)(68 * (char)dir) + x;
LABEL_1632:
            addbullet(this, NULL, 812, v985, v1485, dir, 1, tt, 4);
            goto LABEL_1633;
          case 520:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
              set_seq(0);
            if ( get_subseq() )
              goto LABEL_1656;
            if ( get_frame() == 6 && skills_1[1] >= 1 && get_frame_time() >= 5 )
              goto LABEL_2035;
            if ( !get_frame_time() && get_frame() == 8 )
            {
              play_sfx(7);
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              if ( skills_1[1] >= 3 )
                t[2] = 4.0;
              addbullet(this, NULL, 815, (double)(60 * (char)dir) + x, y + 108.0, dir, 1, t, 3);
            }
LABEL_1656:
            if ( get_subseq() == 2 && get_elaps_frames() >= 20 )
              next_subseq();
            if ( get_subseq() == 4 && !get_frame_time() && get_frame() == 6 )
            {
              play_sfx(7);
              field_190 = 1;
            }
            if ( get_subseq() != 6 )
              return;
            /*v999 = __OFSUB__(get_elaps_frames(), 20);
            v998 = get_elaps_frames() - 20 < 0;
            goto LABEL_2017;
            */
            return; //TODO: change
          case 521:
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
              set_seq(0);
            if ( get_subseq() )
              goto LABEL_1683;
            if ( get_frame() == 2 && skills_1[1] >= 2 && get_frame_time() >= 6 )
              goto LABEL_2035;
            if ( !get_frame_time() && get_frame() == 4 )
            {
              play_sfx(7);
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              t[0] = -25.0;
              t[1] = -0.5;
              t[2] = 0.0;
              if ( skills_1[1] >= 4 )
                t[2] = 4.0;
              addbullet(this, NULL, 815, (double)(20 * (char)dir) + x, y + 145.0, dir, 1, t, 3);
            }
LABEL_1683:
            if ( get_subseq() == 2 && get_elaps_frames() >= 30 )
              next_subseq();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            {
              play_sfx(7);
              field_190 = 1;
            }
            goto LABEL_2015;
          case 525:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( field_7DC > 0.0 )
            {
              field_89C = field_89C + field_7DC;
              field_7DC = field_7DC - 0.2000000029802322;
              if ( field_7DC < 0.125 )
                field_7DC = 0.125;
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % (5 * (8 - (char)skills_1[5]))) )
              {
                t[0] = 0.0;
                t[1] = 1.0;
                t[2] = 4.0;
                addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
                t[1] = -1.0;
                t[2] = 4.0;
                addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
              }
              if ( !not_charge_attack || get_elaps_frames() >= 180 )
                goto LABEL_1736;
            }
            if ( field_7D0 == 1 )
            {
              if ( !(field_7D2 % 60) )
                play_sfx(13);
              ++field_7D2;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
              t[0] = scene_rand_rng(360);
              t[1] = 0.0;
              t[2] = 3.0;
              addbullet(this, NULL, 816, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
              play_sfx(14);
              if ( dir == 1 )
              {
                if ( x < (double)enemy->x )
                {/*
                  if ( tan_deg(field_89C) * (enemy->x - x) + y > enemy->y )
                  {
                    if ( tan_deg(-field_89C) * (enemy->x - x) + y < enemy->y )
                      goto LABEL_2735;
                  }
                  */
                }
              }
              if ( dir == -1 )
              {
                if ( x > (double)enemy->x )
                {
                  if ( tan_deg(field_89C) * (x - enemy->x) + y > enemy->y )
                  {/*
                    if ( tan_deg(-field_89C) * (x - enemy->x) + y < enemy->y )
                    {
LABEL_2735:
                      t[2] = 1.0;
                      addbullet(this, NULL, 816, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
                    }*/
                  }
                }
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 8 )
            {
              field_7D0 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
              t[1] = 1.0;
              t[2] = 0.0;
              addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
              field_89C = 0.0;
LABEL_1725:
              field_7DC = 0.80000001;
            }
            return;
          case 526:
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( field_7DC > 0.0 )
            {
              field_89C = field_89C + field_7DC;
              field_7DC = field_7DC - 0.2000000029802322;
              if ( field_7DC < 0.25 )
                field_7DC = 0.25;
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % (5 * (13 - (char)skills_1[5]))) )
              {
                t[0] = 0.0;
                t[1] = 1.0;
                t[2] = 4.0;
                addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
                t[1] = -1.0;
                t[2] = 4.0;
                addbullet(this, NULL, 816,  (double)(50 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
              }
              if ( !not_charge_attack || get_elaps_frames() >= 180 )
                goto LABEL_1736;
            }
            if ( field_7D0 == 1 )
            {
              if ( !(field_7D2 % 60) )
                play_sfx(13);
              ++field_7D2;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
              t[0] = scene_rand_rng(360);
              t[1] = 0.0;
              t[2] = 3.0;
              addbullet(this, NULL, 816, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
              play_sfx(14);
              if ( dir == 1 )
              {/*
                if ( x < (double)enemy->x )
                {
                  if ( tan_deg(field_89C) * (enemy->x - x) + y > enemy->y )
                  {
                    if ( tan_deg(-field_89C) * (enemy->x - x) + y < enemy->y )
                      goto LABEL_2736;
                  }
                }*/
              }
              if ( dir == -1 )
              {/*
                if ( x > (double)enemy->x )
                {
                  if ( tan_deg(field_89C) * (x - enemy->x) + y > enemy->y )
                  {
                    if ( tan_deg(-field_89C) * (x - enemy->x) + y < enemy->y )
                    {
LABEL_2736:
                      t[2] = 1.0;
                      addbullet(this, NULL, 816, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
                    }
                  }
                }*/
              }
            }
            if ( process() )
              set_seq(0);
            if ( get_subseq() || get_frame_time() || get_frame() != 8 )
              return;
            field_7D0 = 1;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            field_190 = 1;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
            t[1] = 1.0;
            t[2] = 0.0;
            v1486 = y + 110.0;
            v1066 = (double)(50 * dir) + x;
            goto LABEL_1839;
          case 527:
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( 0.0 < field_7DC )
            {
              field_89C = field_89C + field_7DC;
              field_7DC = field_7DC - 0.2000000029802322;
              if ( field_7DC < 0.125 )
                field_7DC = 0.125;
            }
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1766;
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % (5 * (8 - (char)skills_1[5]))) )
              {
                t[0] = 0.0;
                t[1] = 1.0;
                t[2] = 4.0;
                addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
                t[1] = -1.0;
                t[2] = 4.0;
                addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
              }
              if ( !not_charge_attack || get_elaps_frames() >= 180 )
                goto LABEL_1736;
            }
            if ( field_7D0 == 1 )
            {
              if ( !(field_7D2 % 60) )
                play_sfx(13);
              ++field_7D2;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
              t[0] = scene_rand_rng(360);
              t[1] = 0.0;
              t[2] = 3.0;
              addbullet(this, NULL, 816, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
              play_sfx(14);
              if ( dir == 1 )
              {/*
                if ( x < (double)enemy->x )
                {
                  if ( tan_deg(field_89C) * (enemy->x - x) + y > enemy->y )
                  {
                    if ( tan_deg(-field_89C) * (enemy->x - x) + y < enemy->y )
                      goto LABEL_2737;
                  }
                }*/
              }
              if ( dir == -1 )
              {/*
                if ( x > (double)enemy->x )
                {
                  if ( tan_deg(field_89C) * (x - enemy->x) + y > enemy->y )
                  {
                    if ( tan_deg(-field_89C) * (x - enemy->x) + y < enemy->y )
                    {
LABEL_2737:
                      t[2] = 1.0;
                      addbullet(this, NULL, 816, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
                    }
                  }
                }*/
              }
            }
            if ( process() )
              set_seq(9);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              v_force = 0.5;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              field_7D0 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
              t[1] = 1.0;
              t[2] = 0.0;
              addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
              field_89C = 0.0;
              field_7DC = 0.80000001;
            }
            return;
          case 528:
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( 0.0 < field_7DC )
            {
              field_89C = field_89C + field_7DC;
              field_7DC = field_7DC - 0.2000000029802322;
              if ( field_7DC < 0.25 )
                field_7DC = 0.25;
            }
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_1766:
              reset_forces();
              y = getlvl_height();
              set_seq(529);
            }
            else
            {
              if ( get_subseq() != 1 )
                goto LABEL_2738;
              if ( !(get_elaps_frames() % (5 * (13 - (char)skills_1[5]))) )
              {
                t[0] = 0.0;
                t[1] = 1.0;
                t[2] = 4.0;
                addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
                t[1] = -1.0;
                t[2] = 4.0;
                addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
              }
              if ( not_charge_attack && get_elaps_frames() < 180 )
              {
LABEL_2738:
                if ( field_7D0 == 1 )
                {
                  if ( !(field_7D2 % 60) )
                    play_sfx(13);
                  ++field_7D2;
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                {
                  t[0] = scene_rand_rng(360);
                  t[1] = 0.0;
                  t[2] = 3.0;
                  addbullet(this, NULL, 816, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
                  play_sfx(14);
                  if ( dir == 1 )
                  {/*
                    if ( x < (double)enemy->x )
                    {
                      if ( tan_deg(field_89C) * (enemy->x - x) + y > enemy->y )
                      {
                        if ( tan_deg(-field_89C) * (enemy->x - x) + y < enemy->y )
                          goto LABEL_2739;
                      }
                    }*/
                  }
                  if ( dir == -1 )
                  {/*
                    if ( x > (double)enemy->x )
                    {
                      if ( tan_deg(field_89C) * (x - enemy->x) + y > enemy->y )
                      {
                        if ( tan_deg(-field_89C) * (x - enemy->x) + y < enemy->y )
                        {
LABEL_2739:
                          t[2] = 1.0;
                          addbullet(this, NULL, 816, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
                        }
                      }
                    }*/
                  }
                }
                if ( process() )
                  set_seq(9);
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                  v_force = 0.5;
                if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
                {
                  field_7D0 = 1;
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  field_190 = 1;
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 816, (double)(50 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
                  t[1] = 1.0;
                  t[2] = 0.0;
                  v1486 = y + 140.0;
                  v1066 = (double)(50 * dir) + x;
LABEL_1839:
                  addbullet(this, NULL, 816, v1066, v1486, dir, 1, t, 3);
                  field_89C = 0.0;
                  field_7DC = 1.4;
                }
              }
              else
              {
LABEL_1736:
                next_subseq();
                field_7D0 = 0;
              }
            }
            return;
          case 529:
            sub10func();
            goto LABEL_2700;
          case 530:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(0);
              return;
            }
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 && not_charge_attack == 1 )
              {
                next_subseq();
                scene_add_effect(this, 62, x - (double)(45 * (char)dir), y + 132.0, dir, 1);
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                t[0] = 0.0;
                t[1] = 10.0;
                t[2] = 0.0;
                addbullet(this, NULL, 817, (double)(60 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                field_190 = 1;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                play_sfx(12);
              }
            }
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 3 )
              return;
            t[0] = 0.0;
            t[1] = 10.0;
            t[2] = 1.0;
            v1487 = y + 100.0;
            v1138 = (double)(60 * (char)dir) + x;
            goto LABEL_1883;
          case 531:
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            {
              if ( !get_subseq() && !get_frame_time() )
              {
                if ( get_frame() == 3 && not_charge_attack == 1 )
                {
                  next_subseq();
                  scene_add_effect(this, 62, (double)(32 * (char)dir) + x, y + 57.0, dir, 1);
                }
                if ( !get_frame_time() && get_frame() == 5 )
                {
                  t[0] = -30.0;
                  t[1] = 10.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 817, (double)(25 * (char)dir) + x, y + 145.0, dir, 1, t, 3);
                  field_190 = 1;
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  play_sfx(12);
                }
              }
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
              {
                t[0] = -30.0;
                t[1] = 10.0;
                t[2] = 1.0;
                v1487 = y + 145.0;
                v1138 = (double)(25 * dir) + x;
LABEL_1883:
                addbullet(this, NULL, 817, v1138, v1487, dir, 1, t, 3);
                field_190 = 1;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                play_sfx(12);
              }
            }
            else
            {
              set_seq(0);
            }
            return;
          case 532:
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 2 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1927;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(9);
              return;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              goto LABEL_1925;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 5 && not_charge_attack == 1 )
              {
                next_subseq();
                scene_add_effect(this, 62, x + 0.0, y + 145.0, dir, 1);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 6 )
                {
                  t[0] = 0.0;
                  t[1] = 10.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 817, (double)(50 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
                  field_190 = 1;
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  play_sfx(12);
                }
                if ( !get_frame_time() && get_frame() == 9 )
                  v_force = 0.5;
              }
            }
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() != 2 )
              goto LABEL_1948;
            t[0] = 0.0;
            t[1] = 10.0;
            t[2] = 1.0;
            v1488 = y + 145.0;
            v1160 = (double)(25 * dir) + x;
            goto LABEL_1947;
          case 533:
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() == 2 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1927:
                reset_forces();
                y = getlvl_height();
                set_subseq(2);
                return;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
LABEL_1925:
              set_seq(9);
              return;
            }
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 5 && not_charge_attack == 1 )
              {
                next_subseq();
                scene_add_effect(this, 62, x + 0.0, y + 145.0, dir, 1);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 6 )
                {
                  t[0] = 30.0;
                  t[1] = 10.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 817, (double)(50 * (char)dir) + x, y + 140.0, dir, 1, t, 3);
                  field_190 = 1;
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  play_sfx(12);
                }
                if ( !get_frame_time() && get_frame() == 9 )
                  v_force = 0.5;
              }
            }
            if ( get_subseq() != 1 || get_frame_time() )
              return;
            if ( get_frame() == 2 )
            {
              t[0] = 30.0;
              t[1] = 10.0;
              t[2] = 1.0;
              v1488 = y + 145.0;
              v1160 = (double)(25 * dir) + x;
LABEL_1947:
              addbullet(this, NULL, 817, v1160, v1488, dir, 1, t, 3);
              field_190 = 1;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(12);
            }
LABEL_1948:
            if ( get_frame_time() )
              return;
            v978 = get_frame() == 5;
            goto LABEL_2211;
          case 540:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                play_sfx(8);
                field_190 = 1;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = 2.5;
                t[1] = (double)(char)skills_1[2] * 45.0 + 120.0;
                t[2] = 0.0;
                addbullet(this, NULL, 820, x - (double)(8 * (char)dir), y + 120.0, dir, 1, t, 3);
              }
            }
            goto LABEL_2006;
          case 541:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                play_sfx(8);
                field_190 = 1;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = 1.5;
                t[1] = (double)(char)skills_1[2] * 20.0 + 60.0;
                t[2] = 0.0;
                addbullet(this, NULL, 820, enemy->x, enemy->y + 120.0, dir, 1, t, 3);
              }
            }
            goto LABEL_2006;
          case 545:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                play_sfx(17);
                field_190 = 1;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = (double)(char)skills_1[6] * 0.300000011920929 + 2.200000047683716;
                t[1] = 180.0;
                t[2] = 0.0;
                addbullet(this, NULL, 821, x - (double)(8 * (char)dir), y + 120.0, dir, 1, t, 3);
              }
            }
            goto LABEL_2006;
          case 546:
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                play_sfx(8);
                field_190 = 1;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = (double)(char)skills_1[6] * 0.25 + 1.5;
                t[1] = 90.0;
                t[2] = 0.0;
                addbullet(this, NULL, 821, enemy->x, enemy->y + 120.0, dir, 1, t, 3);
              }
            }
LABEL_2006:
            if ( get_subseq() == 2 && get_elaps_frames() >= 12 )
              next_subseq();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            {
              play_sfx(8);
              field_190 = 1;
            }
LABEL_2015:
            if ( get_subseq() == 6 )
            {
              //v999 = __OFSUB__(get_elaps_frames(), 20);
              //v998 = get_elaps_frames() - 20 < 0;
//LABEL_2017:
              //if ( !(v998 ^ v999) )
              //  next_subseq();
            }
            return;
          case 550:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( field_7D6 && !get_subseq() )
              field_522 = 2;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              field_190 = 1;
            if ( process() )
              set_seq(0);
            if ( get_subseq() || get_frame_time() || get_frame() != 3 || skills_1[10] < 2 )
            {
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                play_sfx(18);
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 822, x, y + 120.0, dir, 1, t, 3);
              }
              if ( get_subseq() == 1 )
              {
                //v1187 = __OFSUB__(get_elaps_frames(), 18);
                //v1186 = get_elaps_frames() - 18 < 0;
//LABEL_2530:
                //if ( !(v1186 ^ v1187) )
                //  next_subseq();
              }
            }
            else
            {
LABEL_2035:
              next_frame();
            }
            return;
          case 551:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( field_7D6 && !get_subseq() )
              field_522 = 2;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              field_190 = 1;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2060;
            if ( get_subseq() == 1 )
            {
              play_sfx(18);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 822, x, y + 120.0, dir, 1, t, 3);
LABEL_2060:
              if ( get_subseq() == 1 && get_elaps_frames() >= 25 )
                next_subseq();
            }
            return;
          case 560:
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( !get_subseq() )
              sub10func();
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              reset_forces();
              y = getlvl_height();
              set_seq(10);
            }
            else
            {
              if ( get_subseq() == 1 || get_subseq() == 2 )
              {
                //v1190 = //color_A;
                //if ( v1190 > 0xF5u )
                  //color_A = -1;
                //else
                  //color_A = v1190 + 10;
              }
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                field_7DC = x;
                dash_angle = y;
                //color_A = 0;
                play_sfx(9);
                field_190 = 1;
                h_inerc = -4.0;
                v_inerc = 13.5;
                v_force = 0.44999999;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 825, x, y, dir, 1, t, 3);
              }
            }
            return;
          case 561:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 || get_subseq() == 2 )
            {
              //v1192 = //color_A;
              //if ( v1192 > 0xF5u )
                //color_A = -1;
              //else
                //color_A = v1192 + 10;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(9);
              field_190 = 1;
              //color_A = 0;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL, 825, x, y, dir, 1, t, 3);
            }
            return;
          case 565:
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 2 )
            {
              sub10func();
              
            }
            if ( get_subseq() != 1 )
              goto LABEL_2740;
            if ( !field_7D0 )
            {
              field_7DC = dash_angle + field_7DC;
              if ( field_7DC >= 200.0 )
              {
                field_7DC = 200.0;
                field_7D0 = 1;
              }
            }
            if ( field_7D0 >= 1 && field_7D0 < 20 )
            {
              field_7DC = field_7DC + dash_angle;
              dash_angle = dash_angle - 8.0;
              if ( dash_angle < 1.0 )
              {
                dash_angle = 1.0;
                ++field_7D0;
              }
            }
            if ( field_7D0 < 20 || (field_7DC = field_7DC - 40.0, field_7DC >= 0.0) )
            {
LABEL_2740:
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                field_7D0 = 0;
                field_7DC = 0.0;
                dash_angle = 40.0;
                play_sfx(19);
                spell_energy_spend(200, 120);
                add_card_energy(50);
                field_190 = 1;
                //v999 = __OFSUB__(skills_1[7], 4);
                //v65 = (char)(skills_1[7] - 4) < 0;
                tt[0] = 0.0;
                tt[1] = 0.0;
                //v1198 = 1.0;
                //if ( v65 ^ v999 )
                //{
                //  v1627 = 1.0;
                //}
                //else
                //{
                //  v1627 = 1.0;
                //  v1198 = 3.0;
                //}
                tt[2] = 1.0; //  v1627 = 1.0;
                tt[3] = 1.0; //v1198
                addbullet(this, NULL, 826, x, y, 1, 1, tt, 4);
                tt[2] = 5.0;
LABEL_2145:
                addbullet(this, NULL, 826, x, y + 100.0, dir, 1, tt, 3);
              }
            }
            else
            {
              field_7DC = 0.0;
              next_subseq();
            }
            return;
          case 566:
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 2 )
            {
              sub10func();
              
            }
            if ( get_subseq() == 1 )
            {
              if ( !field_7D0 )
              {
                field_7DC = dash_angle + field_7DC;
                if ( field_7DC >= 200.0 )
                {
                  field_7DC = 200.0;
                  field_7D0 = 1;
                }
              }
              if ( field_7D0 >= 1 && field_7D0 < 20 )
              {
                field_7DC = field_7DC + dash_angle;
                dash_angle = dash_angle - 8.0;
                if ( dash_angle < 1.0 )
                {
                  dash_angle = 1.0;
                  ++field_7D0;
                }
              }
              if ( field_7D0 >= 20 )
              {
                field_7DC = field_7DC - 40.0;
                if ( field_7DC < 0.0 )
                  goto LABEL_2192;
              }
            }
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            field_7D0 = 0;
            field_7DC = 0.0;
            dash_angle = 40.0;
            play_sfx(19);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            field_190 = 1;
            if ( skills_1[7] < 4 )
            {
              tt[0] = 45.0;
              tt[1] = 0.0;
              tt[2] = 1.0;
              tt[3] = 2.0;
            }
            else
            {
              tt[0] = 0.0;
              tt[1] = 0.0;
              tt[2] = 1.0;
              tt[3] = 3.0;
            }
            addbullet(this, NULL, 826, x, y, 1, 1, tt, 4);
            tt[2] = 5.0;
            goto LABEL_2145;
          case 567:
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 4 )
            {
              sub10func();
              
            }
            v_inerc = v_inerc - v_force;
            if ( get_subseq() >= 4 )
              goto LABEL_2154;
            if ( char_on_ground_down() )
            {
              reset_forces();
              y = getlvl_height();
              set_subseq(4);
              return;
            }
            
LABEL_2154:
            if ( get_subseq() == 1 )
            {
              if ( !field_7D0 )
              {
                field_7DC = dash_angle + field_7DC;
                if ( field_7DC >= 200.0 )
                {
                  field_7DC = 200.0;
                  field_7D0 = 1;
                }
              }
              if ( field_7D0 >= 1 && field_7D0 < 20 )
              {
                field_7DC = field_7DC + dash_angle;
                dash_angle = dash_angle - 8.0;
                if ( dash_angle < 1.0 )
                {
                  dash_angle = 1.0;
                  ++field_7D0;
                }
              }
              if ( field_7D0 >= 20 )
              {
                field_7DC = field_7DC - 40.0;
                if ( field_7DC < 0.0 )
                  goto LABEL_2192;
              }
            }
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_2208;
            if ( get_frame_time() || get_frame() || get_subseq() != 1 )
              goto LABEL_2204;
            field_7D0 = 0;
            field_7DC = 0.0;
            dash_angle = 40.0;
            play_sfx(19);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            field_190 = 1;
            //v999 = __OFSUB__(skills_1[7], 4);
            //v65 = (char)(skills_1[7] - 4) < 0;
            tt[0] = 0.0;
            tt[1] = 0.0;
            //v1212 = 1.0;
            //if ( v65 ^ v999 )
            //{
            //  v1639 = 1.0;
            //}
            //else
            //{
            //  v1639 = 1.0;
            //  v1212 = 3.0;
            //}
            tt[2] = 1.0; //  v1639 = 1.0;
            tt[3] = 1.0; //v1640 = v1212;
            addbullet(this, NULL, 826, x, y, 1, 1, tt, 4);
            tt[2] = 5.0;
            t[0] = tt[0];
            t[1] = y + 100.0;
            t[2] = y + 100.0;
            goto LABEL_2203;
          case 568:
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 4 )
            {
              sub10func();
              
            }
            v_inerc = v_inerc - v_force;
            if ( get_subseq() >= 4 )
              goto LABEL_2182;
            if ( char_on_ground_down() )
            {
              reset_forces();
              y = getlvl_height();
              set_subseq(4);
            }
            else
            {
              
LABEL_2182:
              if ( get_subseq() != 1 )
                goto LABEL_2741;
              if ( !field_7D0 )
              {
                field_7DC = dash_angle + field_7DC;
                if ( field_7DC >= 200.0 )
                {
                  field_7DC = 200.0;
                  field_7D0 = 1;
                }
              }
              if ( field_7D0 >= 1 && field_7D0 < 20 )
              {
                field_7DC = field_7DC + dash_angle;
                dash_angle = dash_angle - 8.0;
                if ( dash_angle < 1.0 )
                {
                  dash_angle = 1.0;
                  ++field_7D0;
                }
              }
              if ( field_7D0 < 20 || (field_7DC - 40.0, field_7DC >= 0.0) )
              {
LABEL_2741:
                if ( process() )
                  set_seq(0);
                if ( get_elaps_frames() )
                  goto LABEL_2208;
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  field_7D0 = 0;
                  field_7DC = 0.0;
                  dash_angle = 40.0;
                  play_sfx(19);
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  field_190 = 1;
                  if ( skills_1[7] < 4 )
                  {
                    tt[0] = 45.0;
                    tt[1] = 0.0;
                    tt[2] = 1.0;
                    tt[3] = 2.0;
                  }
                  else
                  {
                    tt[0] = 0.0;
                    tt[1] = 0.0;
                    tt[2] = 1.0;
                    tt[3] = 3.0;
                  }
                  addbullet(this, NULL, 826, x, y, 1, 1, tt, 4);
                  tt[2] = 5.0;
                  t[0] = tt[0];
                  t[1] = y + 100.0;
                  t[2] = y + 100.0;
LABEL_2203:
                  addbullet(this, NULL, 826, x, y + 100.0, dir, 1, t, 3);
                }
LABEL_2204:
                if ( get_elaps_frames() )
                  goto LABEL_2208;
                if ( get_frame_time() || get_frame() || get_subseq() != 4 )
                {
LABEL_2208:
                  if ( get_subseq() == 2 && !get_frame_time() )
                  {
                    v978 = get_frame() == 6;
LABEL_2211:
                    if ( v978 )
                      v_force = 0.5;
                  }
                }
                else
                {
LABEL_896:
                  set_seq(9);
                }
              }
              else
              {
LABEL_2192:
                field_7DC = 0.0;
                next_subseq();
              }
            }
            return;
          case 570:
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_2742;
            //set_vec_speed((render_class *)&cEffectSprite, -40.0, 1.25 * dash_angle);
            if ( !field_7D0 )
            {
              field_7DC = field_7DC + dash_angle;
              if ( field_7DC >= 150.0 )
              {
                field_7DC = 150.0;
                field_7D0 = 1;
              }
            }
            if ( field_7D0 >= 1 )
            {
              field_7DC = field_7DC + dash_angle;
              dash_angle = dash_angle - 8.0;
              if ( dash_angle < 1.0 )
              {
                dash_angle = 1.0;
                ++field_7D0;
              }
            }
            v1228 = 10;
            if ( skills_1[11] >= 2 )
              v1228 = 5;
            if ( skills_1[11] >= 3 )
              v1228 = 5;
            if ( skills_1[11] >= 4 )
              v1228 = 5;
            if ( field_7D0 < v1228 )
            {
LABEL_2742:
              if ( process() )
              {
                set_seq(9);
                flip_with_force();
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                field_7D0 = 0;
                field_7DC = 0.0;
                dash_angle = 40.0;
                field_7D2 = 0;
                field_7D4 = 0;
                play_sfx(19);
                spell_energy_spend(200, 120);
                add_card_energy(50);
                field_190 = 1;
                if ( dX(dir) > 0 )
                  field_7D2 = 1;
                if ( dX(dir) < 0 )
                  field_7D2 = -1;
                if ( dY() > 0 )
                {
                  field_7D4 = -1;
                }
                if ( dY() < 0 )
                  field_7D4 = 1;
                /*
                v1713 = 5.0;
                v1235 = y + 100.0;
                addbullet(this, NULL, 826, x, v1235, dir, 1, (int)&v1711, 3);
                v1535 = 0.0;
                v1236 = (float)0.0;
                do
                {
                  *(float *)&v1711 = v1236 * 45.0;
                  v1712 = 0.0;
                  v1713 = 1.0;
                  addbullet(this, NULL, 827, x, y, dir, 1, (int)&v1711, 3);
                  v1535 = v1535 + 1.0;
                  v1236 = v1535;
                }
                while ( v1535 < 8.0 );*/
              }
            }
            else
            {
              next_subseq();
              h_inerc = 0.0;
              v_inerc = 0.0;
              v_force = 0.5;
              field_7E4 = atan2_deg((double)field_7D4, (double)field_7D2);
              x = cos_deg(field_7E4) * field_7DC * (double)dir + x;
              y = sin_deg(field_7E4) * field_7DC * 0.5 + y;
              if ( enemy->get_border_near() != 1 )
                goto LABEL_2332;
              if ( get_border_near() == 1 )
                x = 41.0;
            }
            return;
          case 571:
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_2743;
            //set_vec_speed((render_class *)&cEffectSprite, -140.0, 1.25 * dash_angle);
            if ( !field_7D0 )
            {
              field_7DC = field_7DC + dash_angle;
              if ( field_7DC >= 150.0 )
              {
                field_7DC = 150.0;
                field_7D0 = 1;
              }
            }
            if ( field_7D0 >= 1 )
            {
              field_7DC = field_7DC + dash_angle;
              dash_angle = dash_angle - 8.0;
              if ( dash_angle < 1.0 )
              {
                dash_angle = 1.0;
                ++field_7D0;
              }
            }
            v1228 = 10;
            if ( skills_1[11] >= 2 )
              v1228 = 5;
            if ( skills_1[11] >= 3 )
              v1228 = 5;
            if ( skills_1[11] >= 4 )
              v1228 = 5;
            if ( field_7D0 < v1228 )
            {
LABEL_2743:
              if ( process() )
              {
                set_seq(9);
                flip_with_force();
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                field_7D0 = 0;
                field_7DC = 0.0;
                dash_angle = 40.0;
                field_7D2 = 0;
                field_7D4 = 0;
                play_sfx(19);
                spell_energy_spend(200, 120);
                add_card_energy(50);
                field_190 = 1;
                if ( dX(dir) > 0 )
                  field_7D2 = 1;
                if ( dX(dir) < 0 )
                  field_7D2 = -1;
                if ( dY() > 0 )
                {
                  field_7D4 = -1;
                }
                if ( dY() < 0 )
                  field_7D4 = 1;
                /*
                v1673 = 5.0;
                v1248 = y + 100.0;
                addbullet(this, NULL, 826, x, v1248, dir, 1, (int)&v1671, 3);
                v1536 = 0.0;
                v1249 = (float)0.0;
                do
                {
                  *(float *)&v1671 = v1249 * 45.0;
                  v1672 = 0.0;
                  v1673 = 2.0;
                  addbullet(this, NULL, 827, x, y, dir, 1, (int)&v1671, 3);
                  v1536 = v1536 + 1.0;
                  v1249 = v1536;
                }
                while ( v1536 < 8.0 );*/
              }
            }
            else
            {
              next_subseq();
              h_inerc = 0.0;
              v_inerc = 0.0;
              v_force = 0.5;
              field_7E4 = atan2_deg((double)field_7D4, (double)field_7D2);
              x = cos_deg(field_7E4) * field_7DC * (double)dir + x;
              y = sin_deg(field_7E4) * field_7DC * 0.5 + y;
              if ( enemy->get_border_near() != 1 )
                goto LABEL_2332;
              if ( get_border_near() == 1 )
                x = 41.0;
            }
            return;
          case 572:
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_2744;
            //set_vec_speed((render_class *)&cEffectSprite, -40.0, 1.25 * dash_angle);
            if ( !field_7D0 )
            {
              field_7DC = field_7DC + dash_angle;
              if ( field_7DC >= 150.0 )
              {
                field_7DC = 150.0;
                field_7D0 = 1;
              }
            }
            if ( field_7D0 >= 1 )
            {
              field_7DC = field_7DC + dash_angle;
              dash_angle = dash_angle - 8.0;
              if ( dash_angle < 1.0 )
              {
                dash_angle = 1.0;
                ++field_7D0;
              }
            }
            v1228 = 10;
            if ( skills_1[11] >= 4 )
              v1228 = 5;
            if ( field_7D0 < v1228 )
            {
LABEL_2744:
              if ( process() )
              {
                field_8B4 = 1;
                set_seq(9);
                flip_with_force();
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                field_7D0 = 0;
                field_7DC = 0.0;
                dash_angle = 40.0;
                field_7D2 = 0;
                field_7D4 = 0;
                play_sfx(19);
                spell_energy_spend(200, 120);
                add_card_energy(50);
                field_190 = 1;
                if ( dX(dir) > 0 )
                  field_7D2 = 1;
                if ( dX(dir) < 0 )
                  field_7D2 = -1;
                if ( dY() > 0 )
                {
                  field_7D4 = -1;
                }
                if ( dY() < 0 )
                  field_7D4 = 1;
                /*
                v1707 = 5.0;
                v1260 = y + 100.0;
                addbullet(this, NULL, 826, x, v1260, dir, 1, (int)&v1705, 3);
                v1537 = 0.0;
                v1261 = (float)0.0;
                do
                {
                  *(float *)&v1705 = v1261 * 45.0;
                  v1706 = 0.0;
                  v1707 = 1.0;
                  addbullet(this, NULL, 827, x, y, dir, 1, (int)&v1705, 3);
                  v1537 = v1537 + 1.0;
                  v1261 = v1537;
                }
                while ( v1537 < 8.0 );*/
              }
            }
            else
            {
              next_subseq();
              h_inerc = 0.0;
              v_inerc = 0.0;
              v_force = 0.5;
              field_7E4 = atan2_deg((double)field_7D4, (double)field_7D2);
              x = cos_deg(field_7E4) * field_7DC * (double)dir + x;
              y = sin_deg(field_7E4) * field_7DC * 0.5 + y;
              if ( enemy->get_border_near() != 1 )
                goto LABEL_2332;
              if ( get_border_near() == 1 )
                x = 41.0;
            }
            return;
          case 573:
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_2745;
            //set_vec_speed((render_class *)&cEffectSprite, -140.0, 1.25 * dash_angle);
            if ( !field_7D0 )
            {
              field_7DC = field_7DC + dash_angle;
              if ( field_7DC >= 150.0 )
              {
                field_7DC = 150.0;
                field_7D0 = 1;
              }
            }
            if ( field_7D0 >= 1 )
            {
              field_7DC = field_7DC + dash_angle;
              dash_angle = dash_angle - 8.0;
              if ( dash_angle < 1.0 )
              {
                dash_angle = 1.0;
                ++field_7D0;
              }
            }
            v1228 = 10;
            if ( skills_1[11] >= 4 )
              v1228 = 5;
            if ( field_7D0 < v1228 )
            {
LABEL_2745:
              if ( process() )
              {
                field_8B4 = 1;
                set_seq(9);
                flip_with_force();
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                field_7D0 = 0;
                field_7DC = 0.0;
                dash_angle = 40.0;
                field_7D2 = 0;
                field_7D4 = 0;
                play_sfx(19);
                spell_energy_spend(200, 120);
                add_card_energy(50);
                field_190 = 1;
                if ( dX(dir) > 0 )
                  field_7D2 = 1;
                if ( dX(dir) < 0 )
                  field_7D2 = -1;
                if ( dY() > 0 )
                {
                  field_7D4 = -1;
                }
                if ( dY() < 0 )
                  field_7D4 = 1;
                /*
                v1682 = 5.0;
                v1272 = y + 100.0;
                addbullet(this, NULL, 826, x, v1272, dir, 1, (int)&v1680, 3);
                v1538 = 0.0;
                v1273 = (float)0.0;
                do
                {
                  *(float *)&v1680 = v1273 * 45.0;
                  v1681 = 0.0;
                  v1682 = 2.0;
                  addbullet(this, NULL, 827, x, y, dir, 1, (int)&v1680, 3);
                  v1538 = v1538 + 1.0;
                  v1273 = v1538;
                }
                while ( v1538 < 8.0 );*/
              }
            }
            else
            {
              next_subseq();
              h_inerc = 0.0;
              v_inerc = 0.0;
              v_force = 0.5;
              field_7E4 = atan2_deg((double)field_7D4, (double)field_7D2);
              x = cos_deg(field_7E4) * field_7DC * (double)dir + x;
              y = sin_deg(field_7E4) * field_7DC * 0.5 + y;
              if ( enemy->get_border_near() == 1 )
              {
                if ( get_border_near() == 1 )
                  x = 41.0;
              }
              else
              {
LABEL_2332:
                if ( enemy->get_border_near() == -1 && get_border_near() == -1 )
                  x = 1239.0;
              }
            }
            return;
          case 600:
            sub10func();
            sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(45 * (char)dir), y + 143.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                t[0] = 0.0;
                t[1] = 10.0;
                t[2] = 0.0;
                addbullet(this, NULL, 850, (double)(60 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                play_sfx(12);
              }
            }
            return;
          case 602:
            sub_46AB50(0, 2);
            if ( get_subseq() == 1 && get_elaps_frames() >= 30 )
              goto LABEL_2627;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              /*
              v1539 = 0.0;
              v1282 = (float)0.0;
              do
              {
                a4 = v1282 * 60.0;
                v1739 = 25.0;
                v1740 = 0.0;
                v1741 = 5.0;
                v1283 = dir;
                v1284 = -a4;
                v1285 = sin_deg(v1284) * 100.0 + y + 130.0;
                v1286 = v1285;
                v1287 = -a4;
                v1288 = cos_deg(v1287) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 852, v1288, v1286, v1283, 1, (int)&a4, 4);
                v1539 = v1539 + 1.0;
                v1282 = v1539;
              }
              while ( v1539 < 6.0 );
              v1540 = 0.0;
              v1289 = (float)0.0;
              do
              {
                a1 = v1289 * 60.0 + 30.0;
                v1731 = 25.0;
                v1732 = 0.0;
                v1733 = 20.0;
                v1290 = dir;
                v1291 = -a1;
                v1292 = sin_deg(v1291) * 100.0 + y + 130.0;
                v1293 = v1292;
                v1294 = -a1;
                v1295 = cos_deg(v1294) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 852, v1295, v1293, v1290, 1, (int)&a1, 4);
                v1540 = v1540 + 1.0;
                v1289 = v1540;
              }
              while ( v1540 < 6.0 );
              v1541 = 0.0;
              v1296 = (float)0.0;
              do
              {
                *(float *)&v1722 = v1296 * 60.0 + 60.0;
                v1723 = 25.0;
                v1724 = 0.0;
                v1725 = 35.0;
                v1297 = dir;
                v1298 = -*(float *)&v1722;
                v1299 = sin_deg(v1298) * 100.0 + y + 130.0;
                v1300 = v1299;
                v1301 = -*(float *)&v1722;
                v1302 = cos_deg(v1301) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 852, v1302, v1300, v1297, 1, (int)&v1722, 4);
                v1541 = v1541 + 1.0;
                v1296 = v1541;
              }
              while ( v1541 < 6.0 );*/
            }
            if ( !get_subseq() && get_frame() == 7 && !get_frame_time() )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 100.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            return;
          case 603:
            sub10func();
            sub_46AB50(0, 2);
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 10) && field_7D0 < 10 )
              {
                t[0] = 0.0;
                t[1] = 25.0;
                t[2] = 0.0;
                if ( field_7D0 == 9 )
                  t[2] = 3.0;
                addbullet(this, NULL, 853, (double)(60 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
                play_sfx(12);
                ++field_7D0;
              }
              if ( get_elaps_frames() >= 120 )
                goto LABEL_2627;
            }
            if ( process() )
              set_seq(0);
            //if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            //  get_elaps_frames() = 0;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(45 * (char)dir), y + 143.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            return;
          case 604:
            sub10func();
            if ( get_subseq() <= 1 )
              sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(28 * (char)dir) + x, y + 57.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 4 )
              {
                play_sfx(57);
                t[0] = -35.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 854, (double)(20 * (char)dir) + x, y + 145.0, dir, 1, t, 3);
              }
            }
            if ( get_subseq() != 1 )
              return;
            //v1187 = __OFSUB__(get_elaps_frames(), 90);
            //v1186 = get_elaps_frames() - 90 < 0;
            //goto LABEL_2530;
            return; // TODO: change
          case 605:
            if ( get_subseq() > 0 || !get_subseq() && get_frame() >= 7 )
            {
              sub_46AB50(0, 2);
              
            }
            if ( get_subseq() != 1 )
              goto LABEL_2427;
            if ( get_elaps_frames() >= 120 )
            {
LABEL_724:
              next_subseq();
            }
            else
            {
              if ( !(get_elaps_frames() % 5) )
              {
                if ( !get_elaps_frames() )
                {
                  play_sfx(50);
                  
                }
                if ( field_7D0 <= 15 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  if ( field_7D0 == 15 )
                  {
                    play_sfx(51);
                    t[2] = 1.0;
                  }
                  addbullet(this, NULL, 855, x, y + 130.0, dir, 1, t, 3);
                  ++field_7D0;
                }
              }
LABEL_2427:
              if ( process() )
                set_seq(0);
              if ( !get_subseq() && get_frame() == 7 && !get_frame_time() )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x, y + 100.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
            }
            return;
          case 606:
            sub10func();
            sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(45 * (char)dir), y + 143.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 5 )
              {
                t[0] = 0.0;
                t[1] = 10.0;
                t[2] = 0.0;
                addbullet(this, NULL, 856, (double)(150 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
                /*
                v1332 = 0;
                v1542 = 0;
                do
                {
                  *(float *)&v1622 = scene_rand_rng(30) + (double)v1542 + 30.0;
                  v1623 = 10.0;
                  v1624 = 8.0;
                  if ( *(float *)&v1622 < 0.0 || *(float *)&v1622 > 180.0 )
                  {
                    y = -1;
                    xj = dir;
                    v1489 = y;
                    v1335 = (double)(150 * (char)xj) + x;
                    v1334 = v1335;
                  }
                  else
                  {
                    y = 1;
                    xj = dir;
                    v1489 = y;
                    v1333 = (double)(150 * (char)xj) + x;
                    v1334 = v1333;
                  }
                  v1336 = v1334;
                  addbullet(this, NULL, 856, v1336, v1489, xj, y, (int)&v1622, 3);
                  v1332 += 60;
                  v1542 = v1332;
                }
                while ( v1332 < 360 );*/
                play_sfx(55);
              }
            }
            return;
          case 607:
            sub10func();
            sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(47 * (char)dir), y, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 4 )
              {
                t[0] = 0.0;
                t[1] = 40.0;
                t[2] = 9.0;
                addbullet(this, NULL, 857, (double)(70 * (char)dir) + x, y + 96.0, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 857, (double)(70 * (char)dir) + x, y + 96.0, dir, 1, t, 3);
                /*
                v1349 = 0;
                v1543 = 0;
                do
                {
                  *(float *)&v1613 = scene_rand_rng(30) + (double)v1543 + 30.0;
                  v1614 = 10.0;
                  v1615 = 8.0;
                  if ( *(float *)&v1613 < 0.0 || *(float *)&v1613 > 180.0 )
                  {
                    ya = -1;
                    xk = dir;
                    v1490 = y;
                    v1352 = (double)(96 * (char)xk) + x;
                    v1351 = v1352;
                  }
                  else
                  {
                    ya = 1;
                    xk = dir;
                    v1490 = y;
                    v1350 = (double)(96 * (char)xk) + x;
                    v1351 = v1350;
                  }
                  v1353 = v1351;
                  addbullet(this, NULL, 856, v1353, v1490, xk, ya, (int)&v1613, 3);
                  v1349 += 60;
                  v1543 = v1349;
                }
                while ( v1349 < 360 );*/
                play_sfx(5);
              }
            }
            return;
          case 608:
            sub10func();
            sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(35 * (char)dir) + x, y + 160.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                t[0] = 80.0;
                t[1] = 40.0;
                t[2] = 0.0;
                addbullet(this, NULL, 858, (double)(50 * (char)dir) + x, y + 50.0, dir, 1, t, 3);
              }
            }
            return;
          case 609:
            if ( get_subseq() > 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                field_7D0 = 100 * h_inerc;
                field_7D2 = 100 * v_inerc;
                reset_forces();
                y = 0.0;
                set_seq(97);
                //shake_camera(5.0);
                scene_play_sfx(22);
                return;
              }
            }
            else
            {
              sub10func();
            }
            sub_46AB50(0, 2);
            if ( get_subseq() != 1 || get_elaps_frames() < 45 )
            {
              if ( process() )
                set_seq(0);
              if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(35 * (char)dir) + x, y + 160.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  if ( field_8A0 > 2 )
                    field_7D0 = 1;
                  else
                    field_8A0 = field_8A0 + 1;
                  play_sfx(54);
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 859, x, y + 100.0, dir, 1, t, 3);
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() )
                {
                  v63 = get_subseq() == 3;
LABEL_2496:
                  if ( v63 )
                    set_seq(0);
                }
              }
            }
            else if ( field_7D0 == 1 )
            {
              field_8A0 = 0;
              //shake_camera(10.0);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 6.0;
              addbullet(this, NULL, 859, x, y + 100.0, dir, 1, t, 3);
              set_subseq(3);
              play_sfx(56);
              h_inerc = -30.0;
              v256 = 15.0;
LABEL_2475:
              v_inerc = v256;
              v_force = 0.5;
            }
            else
            {
LABEL_2627:
              next_subseq();
            }
            break;
          case 610:
            sub10func();
            if ( get_subseq() <= 2 )
              sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2511;
            if ( get_subseq() != 1 )
              return;
            play_sfx(18);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 860, x, y + 120.0, dir, 1, t, 3);
LABEL_2511:
            goto LABEL_2528;
          case 611:
            sub10func();
            if ( get_subseq() <= 2 )
              sub_46AB50(0, 2);
            if ( get_subseq() >= 1 )
              field_8B2 = 420;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2527;
            if ( get_subseq() != 1 )
              return;
            play_sfx(8);
            t[0] = 10.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 861, 640.0, 400.0, dir, 1, t, 3);
LABEL_2527:
LABEL_2528:
            if ( !(get_subseq() == 1) )
              return;
            //v1187 = __OFSUB__(get_elaps_frames(), 25);
            //v1186 = get_elaps_frames() - 25 < 0;
            //goto LABEL_2530;
            return; //TODO: change
          case 650:
            sub_46AB50(0, 2);
            v_inerc = v_inerc - v_force;
            if ( get_subseq() == 2 && char_on_ground_down() )
              goto LABEL_2547;
            if ( process() )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(10 * (char)dir), y + 145.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
                reset_forces();
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                t[0] = 0.0;
                t[1] = 10.0;
                t[2] = 0.0;
                addbullet(this, NULL, 850,  (double)(60 * (char)dir) + x, y + 135.0, dir, 1, t, 3);
                play_sfx(12);
                h_inerc = -7.0;
                v_inerc = 6.0;
                v_force = 0.34999999;
              }
            }
            return;
          case 652:
            sub_46AB50(0, 2);
            if ( get_subseq() == 1 && get_elaps_frames() >= 30 )
              goto LABEL_2570;
            if ( get_subseq() == 2 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
            {
LABEL_2547:
              reset_forces();
              y = getlvl_height();
              set_seq(10);
            }
            else
            {
              if ( process() )
                set_seq(9);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                /*
                v1544 = 0.0;
                v1391 = (float)0.0;
                do
                {
                  *(float *)&v1726 = v1391 * 60.0;
                  v1727 = 25.0;
                  v1728 = 0.0;
                  v1729 = 5.0;
                  v1392 = dir;
                  v1393 = -*(float *)&v1726;
                  v1394 = sin_deg(v1393) * 100.0 + y + 130.0;
                  v1395 = v1394;
                  v1396 = -*(float *)&v1726;
                  v1397 = cos_deg(v1396) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 852, v1397, v1395, v1392, 1, (int)&v1726, 4);
                  v1544 = v1544 + 1.0;
                  v1391 = v1544;
                }
                while ( v1544 < 6.0 );
                v1545 = 0.0;
                v1398 = (float)0.0;
                do
                {
                  *(float *)&v1734 = v1398 * 60.0 + 30.0;
                  v1735 = 25.0;
                  v1736 = 0.0;
                  v1737 = 20.0;
                  v1399 = dir;
                  v1400 = -*(float *)&v1734;
                  v1401 = sin_deg(v1400) * 100.0 + y + 130.0;
                  v1402 = v1401;
                  v1403 = -*(float *)&v1734;
                  v1404 = cos_deg(v1403) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 852, v1404, v1402, v1399, 1, (int)&v1734, 4);
                  v1545 = v1545 + 1.0;
                  v1398 = v1545;
                }
                while ( v1545 < 6.0 );
                v1546 = 0.0;
                v1405 = (float)0.0;
                do
                {
                  *(float *)&v1742 = v1405 * 60.0 + 60.0;
                  v1743 = 25.0;
                  v1744 = 0.0;
                  v1745 = 35.0;
                  v1406 = dir;
                  v1407 = -*(float *)&v1742;
                  v1408 = sin_deg(v1407) * 100.0 + y + 130.0;
                  v1409 = v1408;
                  v1410 = -*(float *)&v1742;
                  v1411 = cos_deg(v1410) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 852, v1411, v1409, v1406, 1, (int)&v1742, 4);
                  v1546 = v1546 + 1.0;
                  v1405 = v1546;
                }
                while ( v1546 < 6.0 );*/
              }
              if ( !get_subseq() && get_frame() == 7 && !get_frame_time() )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x, y + 100.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
            }
            return;
          case 655:
            if ( get_subseq() > 0 || !get_subseq() && get_frame() >= 7 )
            {
              sub_46AB50(0, 2);
              
            }
            if ( get_subseq() != 1 )
              goto LABEL_2578;
            if ( get_elaps_frames() < 120 )
            {
              if ( !(get_elaps_frames() % 5) )
              {
                if ( !get_elaps_frames() )
                {
                  play_sfx(50);
                  
                }
                if ( field_7D0 <= 15 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  if ( field_7D0 == 15 )
                  {
                    play_sfx(51);
                    t[2] = 1.0;
                  }
                  addbullet(this, NULL, 855, x, y + 130.0, dir, 1, t, 3);
                  ++field_7D0;
                }
              }
LABEL_2578:
              if ( get_subseq() >= 2 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
              {
                set_seq(10);
                y = getlvl_height();
                reset_forces();
              }
              else
              {
                if ( process() )
                  set_seq(9);
                if ( !get_subseq() && get_frame() == 7 && !get_frame_time() )
                {
                  sub_4834E0(40);
                  scene_play_sfx(23);
                  scene_add_effect(this, 115, x, y + 100.0, dir, 1);
                  sub_469450(0, 0, 60);
                  sub_483570();
                  weather_forecast_next();
                }
              }
            }
            else
            {
LABEL_2570:
              next_subseq();
              v_force = 0.5;
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
            if ( !get_frame_time() && !get_frame() )
            {
              if ( !field_49A )
                reset_forces();
              field_194 = 1;
              field_190 = 0;
            }
            if ( get_frame() >= 5 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
                h_inerc = 15.0;
LABEL_2606:
              if ( !get_frame_time() && get_frame() == 5 )
              {
                play_sfx(1);
                h_inerc = 5.0;
                field_49A = 0;
              }
            }
            return;
          case 710:
            sub10func();
            if ( process() )
              set_seq(700);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2620;
            if ( get_subseq() != 1 )
              return;
            field_7DC = 90.0;
            switch ( settings_get()->get_difficulty() )
            {
              case 0:
                field_7D0 = 2;
                break;
              case 1:
                field_7D0 = 4;
                break;
              case 2:
                field_7D0 = 6;
                break;
              case 3:
                field_7D0 = 8;
                break;
              default:
                break;
            }
LABEL_2620:
            if ( get_subseq() != 1 )
              return;
            if ( get_elaps_frames() % 12 )
              goto LABEL_2624;
            if ( field_7D0 > 0 )
            {
              t[0] = field_7DC;
              t[1] = 20.0;
              t[2] = 0.0;
              addbullet(this, NULL, 900, cos_deg(-t[0]) * 100.0 * (double)dir + x, sin_deg(-t[0]) * 100.0 + y + 85.0, dir, 1, t, 3);
              t[0] = -field_7DC;
              t[1] = 20.0;
              t[2] = 0.0;
              addbullet(this, NULL, 900, cos_deg(-t[0]) * 100.0 * (double)dir + x, sin_deg(-t[0]) * 100.0 + y + 85.0, dir, 1, t, 3);
              play_sfx(5);
              --field_7D0;
              field_7DC = field_7DC + 10.0;
            }
LABEL_2624:            
            if ( (field_7D0 == 0) && ++field_7D2 >= 90 )
              goto LABEL_2627;
            return;
          case 725:
            sub10func();
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2640;
            if ( get_subseq() == 1 )
            {
              play_sfx(8);
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  t[0] = 2.5;
                  t[1] = 240.0;
                  t[2] = 0.0;
                  v1491 = y + 120.0;
                  v1437 = x - (double)(8 * (char)dir);
                  goto LABEL_2639;
                case 1:
                  t[0] = 2.5;
                  t[1] = 240.0;
                  t[2] = 0.0;
                  v1491 = y + 120.0;
                  v1437 = x - (double)(8 * (char)dir);
                  goto LABEL_2639;
                case 2:
                  t[0] = 2.75;
                  t[1] = 300.0;
                  t[2] = 0.0;
                  v1491 = y + 120.0;
                  v1437 = x - (double)(8 * (char)dir);
                  goto LABEL_2639;
                case 3:
                  t[0] = 3.0;
                  t[1] = 360.0;
                  t[2] = 0.0;
                  v1491 = y + 120.0;
                  v1437 = x - (double)(8 * (char)dir);
LABEL_2639:
                  addbullet(this, NULL, 911, v1437, v1491, dir, 1, t, 3);
                  break;
                default:
                  break;
              }
LABEL_2640:
              if ( get_subseq() == 1 && get_elaps_frames() >= 48 )
                next_subseq();
            }
            return;
          case 726:
            sub10func();
            if ( field_7DC > 0.0 )
            {
              field_89C = field_89C + field_7DC;
              field_7DC = field_7DC - 0.2000000029802322;
              if ( field_7DC < 0.25 )
                field_7DC = 0.25;
            }
            if ( get_subseq() != 1 )
              goto LABEL_2746;
            if ( !(get_elaps_frames() % 30) )
            {
              t[0] = 0.0;
              t[1] = 1.0;
              t[2] = 4.0;
              addbullet(this, NULL, 912, (double)(50 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
              t[1] = -1.0;
              t[2] = 4.0;
              addbullet(this, NULL, 912, (double)(50 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
            }
            if ( dir == 1 )
            {
              if ( x < (double)enemy->x )
              {
                if ( tan_deg(field_89C) * (enemy->x - x) + y > enemy->y )
                {
                  if ( tan_deg(-field_89C) * (enemy->x - x) + y < enemy->y )
                    goto LABEL_2747;
                }
              }
            }
            if ( dir == -1 )
            {
              if ( x > (double)enemy->x )
              {
                if ( tan_deg(field_89C) * (x - enemy->x) + y > enemy->y )
                {
                  if ( tan_deg(-field_89C) * (x - enemy->x) + y < enemy->y )
LABEL_2747:
                    field_89A = 3;
                }
              }
            }
            if ( get_elaps_frames() < 180 )
            {
LABEL_2746:
              if ( field_7D0 == 1 )
              {
                if ( !(field_7D2 % 60) )
                  play_sfx(13);
                ++field_7D2;
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              {
                t[0] = scene_rand_rng(360);
                t[1] = 0.0;
                t[2] = 3.0;
                addbullet(this, NULL, 912, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
                play_sfx(14);
              }
              if ( process() )
                set_seq(0);
              if ( !get_subseq() && !get_frame_time() && get_frame() == 8 )
              {
                field_7D0 = 1;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 912, (double)(50 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
                t[1] = 1.0;
                t[2] = 0.0;
                addbullet(this, NULL, 912, (double)(50 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
                field_89C = 0.0;
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                    field_7DC = 0.60000002;
                    break;
                  case 1:
                    goto LABEL_1725;
                  case 2:
                    field_7DC = 1.2;
                    break;
                  case 3:
                    field_7DC = 1.5;
                    break;
                  default:
                    return;
                }
              }
            }
            else
            {
              next_subseq();
              field_7D0 = 0;
            }
            return;
          case 730:
            if ( get_subseq() != 1 )
              goto LABEL_2700;
            switch ( settings_get()->get_difficulty() )
            {
              case 0:
                field_7D6 = 2;
                break;
              case 1:
                field_7D6 = 4;
                break;
              case 2:
                field_7D6 = 5;
                break;
              case 3:
                field_7D6 = 6;
                break;
              default:
                break;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              field_7D2 = scene_rand_rng(field_7D6);
            if ( field_7D0 < field_7D6 )
              goto LABEL_2692;
            if ( field_892 < 30 )
              goto LABEL_2627;
            field_892 = field_892 - 30;
LABEL_2692:
            if ( !(get_elaps_frames() % 15) && field_7D0 < field_7D6 )
            {
              play_sfx(19);
              tt[0] = -45.0 - scene_rand_rng(40);
              tt[1] = scene_rand_rng(5) + 20.0;
              tt[2] = 1.0;
              tt[3] = 0.0;
              if ( field_7D2 == field_7D0 )
                tt[3] = 1.0;
              if ( field_7D0 % 2 )
                addbullet(this, NULL, 920, x, y, -dir, 1, t, 4);
              else
                addbullet(this, NULL, 920, x, y, dir, 1, t, 4);
              ++field_7D0;
            }
LABEL_2700:
            if ( process() )
LABEL_2701:
              set_seq(0);
            return;
          default:
            goto LABEL_2713;
        }
      }
      return;
    }
    if ( !(get_seq() - 795) )
    {
      if ( !get_subseq() )
      {
        v_inerc = v_inerc - 0.300000011920929;
        if ( char_on_ground_down() )
        {
          set_subseq(1);
          y = getlvl_height();
          reset_forces();
          scene_play_sfx(30);
          return;
        }
      }
      goto LABEL_2728;
    }
    if ( ((get_seq() - 795) - 2) )
    {
      if ( ((get_seq() - 795) - 2) != 1 )
      {
LABEL_2713:
        char_c::func10();
        return;
      }
      h_inerc = 3.0;
      if ( field_7D0 >= 252 )
        field_7D0 = 255;
      else
        field_7D0 = field_7D0 + 3;
      field_892 = field_7D0;
      if ( x <= 800.0 )
      {
        x = 800.0;
        field_892 = 255;
        reset_forces();
        set_seq(700);
        return;
      }
LABEL_2728:
      if ( process() )
        set_seq(700);
      return;
    }
    h_inerc = 3.0;
    if ( field_7D0 >= 252 )
      field_7D0 = 255;
    else
      field_7D0 = field_7D0 + 3;
    field_892 = field_7D0;
    if ( x < 480.0 )
    {
      if ( process() )
LABEL_2723:
        set_seq(0);
    }
    else
    {
      x = 480.0;
      field_892 = 255;
      reset_forces();
      set_seq(0);
    }
  }
}

// note: taken from marisa.cpp
void char_udonge::func20()
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

void char_udonge::set_seq_params()
{
  float t[3];
  t[0] = 0.0;
  t[1] = 0.0;
  t[2] = 0.0;

  double v3 = 0.0;
  double v10 = 0.0;
  double v39 = 0.0;
  double v41 = 0.0;

  int i_loop = 0;

  if ( get_seq() > 301 )
  {
    if ( get_seq() > 561 )
    {
      switch ( get_seq() )
      {
        case 565:
        case 566:
        case 567:
        case 568:
          field_18C = 7;
          field_190 = 0;
          reset_forces();
          field_7DC = 0.0;
          field_7D0 = 0;
          dash_angle = 0.0;
          not_charge_attack = 1;
          return;
        case 570:
        case 571:
        case 572:
        case 573:
          field_18C = 11;
          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 600:
        case 604:
        case 606:
        case 607:
        case 608:
        case 610:
        case 611:
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          return;
        case 602:
        case 605:
        case 652:
        case 655:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 1;
          reset_forces();
          return;
        case 603:
          reset_forces();
          field_7D0 = 0;
          field_190 = 0;
          field_49A = 0;
          return;
        case 609:
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_7D0 = 0;
          return;
        case 650:
          v_force = 0.0;
          field_190 = 0;
          field_49A = 0;
          h_inerc = h_inerc * 0.1000000014901161;
          v_inerc = 0.1000000014901161 * v_inerc;
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
LABEL_76:
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
          goto LABEL_107;
        case 709:
LABEL_107:
          field_7D0 = 0;
          return;
        case 710:
          field_7DC = 0.0;
          field_7D0 = 0;
          field_7D2 = 0;
          reset_forces();
          goto LABEL_59;
        case 725:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          break;
        case 726:
LABEL_84:
          field_7DC = 0.0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_18C = 5;
          reset_forces();
LABEL_59:
          field_190 = 0;
          field_49A = 0;
          not_charge_attack = 1;
          break;
        case 730:
          reset_forces();
          field_7DC = 0.0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          field_7D6 = 0;
          break;
        case 797:
        case 798:
          reset_forces();
          v_inerc = 0.0;
          field_892 = 0;
          field_7D0 = 0;
          play_sfx(9);
          break;
        default:
          goto LABEL_112;
      }
    }
    else if ( get_seq() >= 560 )
    {
      field_18C = 3;
      field_190 = 0;
      reset_forces();
      field_7D0 = 0;
      field_7D2 = 0;
      not_charge_attack = 1;
    }
    else
    {
      switch ( get_seq() )
      {
        case 302:
          if ( !field_49A )
            reset_forces();
          field_194 = 1;
          goto LABEL_59;
        case 303:
        case 321:
        case 322:
        case 330:
          goto LABEL_53;
        case 304:
          field_7D0 = 0;
          field_49A = 0;
          field_194 = 1;
          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 305:
          v_inerc = 0.0;
          h_inerc = 12.5;
          v_force = 0.0;
          goto LABEL_62;
        case 306:
          field_7D0 = 0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 307:
          field_194 = 1;
          field_190 = 0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          v_force = 0.0;
          return;
        case 308:
          v_force = 0.5;
          t[0] = h_inerc;
          t[1] = v_inerc;
          t[2] = 5.0;
          not_charge_attack = 1;
          field_194 = 1;
          field_190 = 0;
          field_892 = 0;
          addbullet(this, NULL,  848, x, y, dir, 1, t, 3);
          field_7D0 = 0;
          v_inerc = 5.5;
          return;
        case 309:
          not_charge_attack = 1;
          field_194 = 1;
          field_190 = 0;
          return;
        case 310:
          h_inerc = 0.0;
          v_inerc = 0.0;
          field_7D0 = 0;
          field_190 = 0;
          v_force = 0.5;
          field_194 = 99;
          return;
        case 320:
LABEL_62:
          field_49A = 0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 400:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          not_charge_attack = 1;
          return;
        case 401:
        case 402:
        case 411:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          not_charge_attack = 1;
          return;
        case 404:
        case 406:
          v_force = 0.0;
          field_190 = 0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 408:
          h_inerc = 17.5;
          v_inerc = 0.0;
          goto LABEL_72;
        case 409:
          v_force = 0.34999999;
LABEL_72:
          field_49A = 0;
          field_7D0 = 0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 410:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          not_charge_attack = 1;
          return;
        case 412:
          field_190 = 0;
          goto LABEL_76;
        case 414:
        case 415:
        case 416:
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          h_inerc = h_inerc * 0.25;
          field_190 = 1;
          not_charge_attack = 1;
          v_inerc = 0.25 * v_inerc;
          v_force = 0.0;
          return;
        case 418:
          h_inerc = 12.0;
          field_190 = 0;
          field_49A = 0;
          field_194 = 1;
          return;
        case 500:
        case 501:
          field_18C = 0;
          reset_forces();
          goto LABEL_59;
        case 505:
        case 506:
          field_18C = 4;
          reset_forces();
          goto LABEL_59;
        case 507:
        case 508:
          field_190 = 1;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          v_force = 0.0;
          return;
        case 510:
        case 511:
          field_18C = 8;
          reset_forces();
          goto LABEL_59;
        case 520:
        case 521:
          field_18C = 1;
          reset_forces();
          goto LABEL_59;
        case 525:
        case 526:
          goto LABEL_84;
        case 527:
        case 528:
          field_7DC = 0.0;
          field_7D0 = 0;
          v_force = 0.0;
          field_7D2 = 0;
          field_18C = 5;
          h_inerc = h_inerc * 0.1000000014901161;
          v_inerc = 0.1000000014901161 * v_inerc;
          goto LABEL_59;
        case 529:
          reset_forces();
          field_49A = 0;
          return;
        case 530:
        case 531:
          field_18C = 9;
          reset_forces();
          goto LABEL_59;
        case 532:
        case 533:
          field_18C = 9;
          v_force = 0.0;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          goto LABEL_59;
        case 540:
        case 541:
          field_18C = 2;
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          not_charge_attack = 1;
          return;
        case 545:
        case 546:
          field_18C = 6;
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          not_charge_attack = 1;
          return;
        case 550:
        case 551:
          field_18C = 10;
          field_190 = 0;
          reset_forces();
          //v52 = __OFSUB__(skills_1[10], 4);
          //v51 = (char)(skills_1[10] - 4) < 0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D4 = 0;
          field_7D6 = 0;
          not_charge_attack = 1;
          /*if ( !(v51 ^ v52) )
          {
            field_522 = 2;
            field_7D6 = 1;
          }*/
          return;
        default:
          break;
      }
LABEL_112:
      char_c::set_seq_params();
    }
  }
  else if ( get_seq() >= 300 )
  {
LABEL_53:
    if ( !field_49A )
      reset_forces();
    field_190 = 0;
    field_194 = 1;
  }
  else
  {
    switch ( get_seq() )
    {
      case 4:
        h_inerc = 4.0;
        return;
      case 5:
        h_inerc = -4.0;
        return;
      case 50:
      case 57:
      case 63:
        v3 = -15.0;
        goto LABEL_7;
      case 51:
        h_inerc = -20.0;
        v_inerc = 0.0;
        field_1A4 = 0.0;
        field_1A8 = 0.0;
        angZ = 0.0;
        //sub_6310C0((int)this);
        return;
      case 52:
        goto LABEL_12;
      case 53:
        field_7D0 = 0;
        field_7D2 = 0;
LABEL_12:
        h_inerc = -25.0;
        v_inerc = 0.0;
        field_1A4 = 0.0;
        field_1A8 = 0.0;
        angZ = 0.0;
        //sub_6310C0((int)this);
        return;
      case 54:
      case 60:
      case 66:
        h_inerc = 0.0;
        goto LABEL_8;
      case 55:
      case 58:
      case 61:
      case 64:
      case 67:
        v3 = -20.0;
        goto LABEL_7;
      case 56:
      case 62:
        v3 = -10.0;
        goto LABEL_7;
      case 59:
      case 65:
        v3 = -25.0;
        field_7D0 = 0;
        field_7D2 = 0;
LABEL_7:
        h_inerc = v3;
LABEL_8:
        v_inerc = 0.0;
        field_1A4 = 0.0;
        field_1A8 = 0.0;
        goto LABEL_9;
      case 70:
        field_7D0 = 0;
        h_inerc = -field_1A4;
        v_inerc = field_1A8;
        v_force = 0.80000001;
        if ( -field_1A4 > 0.0 )
          field_7D0 = 1;
        if ( (0.0 < -field_1A4) | (0.0 == -field_1A4) )
        {
LABEL_9:
          angZ = 0.0;
          //sub_6310C0((int)this);
        }
        else
        {
          angZ = 0.0;
          field_7D0 = -1;
          //sub_6310C0((int)this);
        }
        return;
      case 71:
        h_inerc = -field_1A4;
        v_inerc = field_1A8;
        v10 = 0.5;
        goto LABEL_22;
      case 72:
        h_inerc = -field_1A4;
        v_inerc = field_1A8;
        v_force = 1.3;
        angZ = 0.0;
        //sub_6310C0((int)this);
        return;
      case 73:
      case 88:
        h_inerc = -field_1A4;
        v_inerc = field_1A8;
        v10 = 0.80000001;
LABEL_22:
        field_7D0 = 7;
        goto LABEL_23;
      case 74:
      case 75:
        h_inerc = -field_1A4;
        v_inerc = field_1A8;
        v10 = 0.80000001;
        goto LABEL_23;
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
        x_off = (double)x_delta;
        y_off = (double)y_delta;
        y = y + 100.0;
        hit_stop = 5;
        x = x - (double)(50 * (char)dir);
        scene_add_effect(this, 38, x, y, dir, 1);
        scene_add_effect(this, 59, x - (double)(50 * (char)dir), y + 100.0, dir, 1);
        h_inerc = 0.0;
        v_inerc = 0.0;
        v_force = 0.0;
        //shake_camera(2.0);
        scene_play_sfx(22);
        angZ = 0.0;
        //sub_6310C0((int)v1);
        return;
      case 77:
        h_inerc = -field_1A4;
        v_inerc = field_1A8;
        v_force = 0.80000001;
        x_off = (double)x_delta;
        y_off = (double)y_delta;
        angZ = 0.0;
        //sub_6310C0((int)v1);
        return;
      case 78:
        weather_forecast_next();
        i_loop = 5;
        do
        {
          scene_add_effect(this, 201, x, y, dir, 1);
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
        //sub_6310C0((int)v1);
        return;
      case 89:
        weather_forecast_next();
        scene_add_effect(this, 58, x, 0.0, dir, -1);
        i_loop = 5;
        do
        {
          scene_add_effect(this, 201, x, y + 100.0, dir, 1);
          --i_loop;
        }
        while ( i_loop );
        angZ = 0.0;
        //sub_6310C0((int)v1);
        return;
      case 97:
        weather_forecast_next();
        scene_add_effect(this, 58, x, 0.0, dir, -1);
        i_loop = 5;
        do
        {
          scene_add_effect(this, 201, x, y, dir, 1);
          --i_loop;
        }
        while ( i_loop );
        angZ = 0.0;
        //sub_6310C0((int)v1);
        return;
      case 98:
        reset_forces();
        air_dash_cnt = 0;
        field_7D0 = 0;
        //sub_6310C0((int)v1);
        return;
      case 99:
        reset_forces();
        field_7DC = 0.0;
        dash_angle = 0.0;
        field_7E4 = 0.0;
        air_dash_cnt = 0;
        field_7E8 = 0.0;
        field_7D0 = 0;
        field_7D2 = 0;
        field_7EC = 0.0;
        field_7D4 = 0;
        field_7D6 = 0;
        field_7D8 = 0;
        return;
      case 140:
        v39 = -11.0;
        goto LABEL_43;
      case 143:
      case 144:
        v39 = -12.0;
LABEL_43:
        h_inerc = v39;
        field_7D0 = 0;
        v_inerc = 0.0;
        angZ = 0.0;
        //sub_6310C0((int)this);
        return;
      case 145:
        h_inerc = -10.0;
        v_inerc = 14.0;
        v10 = 0.5;
LABEL_23:
        v_force = v10;
        angZ = 0.0;
        //sub_6310C0((int)this);
        return;
      case 149:
        h_inerc = -10.0;
        v_inerc = 14.0;
        v_force = 0.5;
        //sub_6310C0((int)this);
        return;
      case 214:
        h_inerc = 0.0;
        v_inerc = 0.0;
        v_force = 0.60000002;
        x_off = 0.0;
        y_off = 95.0;
        v41 = 9.0;
        break;
      case 217:
        reset_ofs();
        h_inerc = 0.0;
        v_inerc = 0.0;
        v_force = 0.60000002;
        x_off = 0.0;
        y_off = 95.0;
        v41 = 11.0;
        break;
      default:
        goto LABEL_112;
    }
    field_7DC = v41;
    field_7D6 = 0;
    field_7EC = 0.0;
  }
}
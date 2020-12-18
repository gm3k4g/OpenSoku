#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "reimu.h"
#include <math.h>

char_reimu::char_reimu(inp_ab *func,uint8_t pal):
	char_c(func)
{
	char_id = CHAR_ID_REIMU;
	pgp->load_dat("reimu",pal);
	char_loadsfx("reimu");
	cards_load_cards(&chr_cards,"reimu");
	load_face("reimu");
	load_spells("reimu");
	stand_gfx->init(this,"reimu");
}

void char_reimu::init_vars()
{
  field_138 = -6.0;
  field_890 = 0;
  field_8BA = 0;
  field_894 = 0.0;
  field_8B4 = 0;
  field_898 = 0.0;
  field_8B6 = 0;
  field_89C = 0.0;
  field_8B8 = 0;
  field_8A0 = 0.0;
  field_8A4 = 0.0;
  field_8A8 = 0.0;
  field_8AC = 0.0;
  field_8B0 = 0.0;
  char_c::init_vars();
}
/*
c_bullet *char_reimu::new_bullet()
{
    c_bullet *tmp = new reimu_bullets();
    return tmp;
}
*/

//WIP
//TODO: Some hiccups (try hi-jumping with reimu from the ground straight up). Look for more of those.
//TODO: why no shadow?
void char_reimu::func10()
{
    int32_t sq = get_seq();

    // etc

    int move_val = 0;
    double move_vala = 0.0;
    double move_valb = 0.0;
    double v3 = 0.0;
    double v39 = 0.0;
    double v51 = 0.0;
    double v63 = 0.0;
    double v65 = 0.0;
    double v82 = 0.0;
    bool v119 = false;

    double v1718 = 0.0;
    double v134 = 0.0;

    double v136 = 0.0;
    double v139 = 0.0;

    double v1575 = 0.0;

    int v1318 = 0;
    double v1368 = 0.0;

    int v535 = 0;

  x_delta = 0;
  y_delta = 85;
  if ( controlling_type == 2 )
  {
    if ( cards_added >= 1 )
    {
      switch ( cards_active[0]->id )
      {
        case 0:
        case 1:
        case 2:
        case 3:
          field_4AA = 2;
          field_534 = 0.25;
          field_55C = 2.0;
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] == 1 )
          {
            field_86A = 3;
            field_55C = 3.0;
          }
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_55C = 8.0;
          }
          break;
        case 4:
        case 5:
        case 6:
        case 7:
          field_4AA = 2;
          field_534 = 0.25;
          
          field_55C = 1.0;
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] != 1 )
            goto LABEL_12;
          v3 = 6.0;
          goto LABEL_11;
        case 8:
        case 9:
        case 10:
        case 11:
          field_4AA = 2;
          field_534 = 0.25;
          
          field_55C = 1.0;
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] == 1 )
          {
            field_86A = 3;
            field_55C = 3.0;
          }
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_55C = 12.0;
          }
          break;
        case 12:
        case 13:
        case 14:
        case 15:
          field_4AA = 2;
          field_534 = 0.25;
          
          field_55C = 1.0;
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] == 1 )
          {
            v3 = 3.0;
LABEL_11:
            field_86A = 3;
            field_55C = v3;
          }
LABEL_12:
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_55C = 6.0;
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
        set_seq(149);
        scene_add_effect(this, 53, x, y + 100.0, dir, 1);
        if ( cards_added >= 1 )
        {
          if ( cards_active[0]->id <= 0xF )
          {
            //v6 = byte_4A7068[v5];
            field_884 = 300;
            field_886 = 300;
          }
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
        if ( health > 0 )
        {
          float t[3];
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL,1201, 180.0, 130.0, 1, 2, t, 3);
        }
      }
      else
      {
        field_86A = 2;
        field_4AA = 2;
        field_538 = 1.0;
        field_534 = 1.0;
        --field_884;
        field_4BA = 6000;
      }
    }
    if ( health <= 0 )
      field_86A = 0;
  }
  if ( get_seq() > 149 && get_seq() < 159 && !bbarrier_show )
  {
    bbarrier_show = 1;
    if ( get_seq() > 149 && get_seq() < 154 )
    {
      addbullet(this, NULL,998, (double)(57 * dir) + x, y + 94.0, dir, 1, 0, 0);    
    }
    if ( get_seq() > 153 && get_seq() < 158 )
    {
      addbullet(this, NULL,998, (double)(57 * dir) + x,  y + 60.0, dir, 1, 0, 0);
    }
    if ( get_seq() == 158 )
    {
      addbullet(this, NULL,998, (double)(57 * dir) + x, y + 100.0, dir, 1, 0, 0);
    }
  }
  if ( field_8BA )
  {
    if ( getlvl_height() >= y && !(get_pframe()->fflags & 4) )
    {
      if ( get_seq() <= 544 || get_seq() >= 550 )
        field_8BA = 0;
    }
    
  }
  if ( field_8B4 > 0 )
  {
    if ( health <= 0 || enemy->health <= 0 )
      field_8B4 = 0;
    if ( !field_8B8 )
    {
      if ( field_190 == 1 || field_190 == 7 )
      {
        if ( field_8B6 == 6 )
        {
          if ( win_count )
          {
            if ( enemy->win_count )
            {
              if ( enemy->health > 0 && health > 0 )
              {
                //play_music("data/bgm/st99.ogg");
                
              }
            }
          }
        }
        ++field_8B6;
        field_8B8 = 1;
      }
    }
    if ( field_8B6 >= 7 && get_seq() <= 10 )
    {
      set_seq(669);
      return;
    }
    --field_8B4;
  }
  if ( hit_stop || enemy->time_stop )
    return;
  if ( get_seq() <= 300 )
  {
    if ( get_seq() == 300 )
    {
LABEL_838:
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
        if ( !get_frame_time() && get_frame() == 3 )
        {
          scene_play_sfx(27);
LABEL_847:
          field_49A = 0;
        }
      }
    }
    else
    {
      switch ( sq )
      {
        case 0:
          sub10func();
          if ( 0.0 == h_inerc )
            field_49A = 0;
          if ( !field_49A )
            goto LABEL_85;
          goto LABEL_86;
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
          if ( !field_49A )
          {
LABEL_85:
            reset_forces();
            process();
            return;
          }
LABEL_86:
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
            goto LABEL_161;
          h_inerc = h_inerc + 0.5;
          if ( h_inerc <= 0.0 )
            goto LABEL_161;
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
            goto LABEL_115;
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
          if ( !(get_subseq() < 0 | get_subseq() == 0) )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_158;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v39 = 0.0;
          goto LABEL_130;
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
              goto LABEL_158;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v39 = 4.0;
          goto LABEL_130;
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
              goto LABEL_158;
          }
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v39 = -4.0;
LABEL_130:
            char_h_move(v39);
            v_inerc = 15.0;
            v_force = 0.55000001;
            field_49A = 0;
          }
          return;
        case 9:
          if ( 0.0 == v_force )
            v_force = 0.60000002;
          v_inerc = v_inerc - v_force;
          if ( !char_on_ground_down() )
            goto LABEL_161;
LABEL_158:
          
          move_val = 10;
          goto LABEL_159;
        case 10:
          sub10func();
          reset_forces();
          if ( !process() )
            return;


          if ( dY() )
            goto LABEL_165;
          set_seq(0);
          return;
        case 71:
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
            goto LABEL_172;
          if ( get_subseq() == 1 )
          {
            if ( !field_890 )
            {
              field_890 = 1;
              addbullet(this, NULL,951, x, y, dir, 1, 0, 0);
            }
LABEL_172:
            if ( get_subseq() == 1 && v_inerc < 2.0 )
              goto LABEL_992;
          }
          v_inerc = v_inerc - v_force;
          if ( v_inerc > 0.0 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            if ( !field_80C )
              goto LABEL_183;
            if ( weather_id == 18 )
            {
              //
              goto LABEL_180;
            }
            goto LABEL_181;
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
          goto LABEL_161;
        case 72:
          if ( get_subseq() == 1 && v_inerc < 2.0 )
            goto LABEL_992;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            if ( !field_80C )
              goto LABEL_183;
            if ( weather_id == 18 )
            {
              
              goto LABEL_180;
            }
            goto LABEL_181;
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
          goto LABEL_161;
        case 73:
          if ( char_on_ground_down() )
          {
            if ( !field_80C )
              goto LABEL_210;
            if ( weather_id == 18 )
            {
              
              goto LABEL_180;
            }
            goto LABEL_181;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            goto LABEL_3213;
          if ( !field_890 )
          {
            field_890 = 1;
            addbullet(this, NULL,951, x, y, dir, 1, 0, 0);
          }
          
          if ( 0.0 == v_inerc )
          {
LABEL_3213:
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
          goto LABEL_267;
        case 74:
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
            goto LABEL_232;
          if ( get_subseq() == 1 )
          {
            if ( !field_890 )
            {
              field_890 = 1;
              addbullet(this, NULL,951, x, y, dir, 1, 0, 0);
            }
LABEL_232:
            if ( get_subseq() == 1 && v_inerc < 2.0 )
              goto LABEL_1849;
          }
          if ( get_border_near() && (h_inerc <= -25.0 || field_80C) )
          {
            if ( weather_id != 18 )
              goto LABEL_240;
            //v60 = (double)weather_time;
            goto LABEL_239;
          }
          if ( get_border_near() && h_inerc <= -15.0 )
          {
            set_seq(78);
            return;
          }
          v_inerc = v_inerc - v_force;
          if ( !char_on_ground_down() )
          {
LABEL_161:
            process();
            return;
          }
          if ( !field_80C )
          {
LABEL_183:
            field_7D0 = 100 * h_inerc;
            field_7D2 = 100 * v_inerc;
            reset_forces();
            y = getlvl_height();
            set_seq(97);
            goto LABEL_184;
          }
          if ( weather_id == 18 )
          {
            
            goto LABEL_180;
          }
          goto LABEL_181;
        case 75:
          if ( char_on_ground_down() )
          {
            if ( field_80C )
            {
              //if ( weather_id == 18 )
              //{
                
LABEL_180:
                ///weather_time =((double)weather_time * 0.75);
              //}
LABEL_181:
              field_7D0 = 100 * h_inerc;
              field_7D2 = 100 * v_inerc;
              reset_forces();
              move_vala = 89;
            }
            else
            {
LABEL_210:
              field_7D0 = 100 * h_inerc;
              field_7D2 = 100 * v_inerc;
              reset_forces();
              move_vala = 97;
            }
            y = getlvl_height();
            v51 = 5.0;
            goto LABEL_185;
          }
          if ( get_border_near() && (h_inerc <= -25.0 || field_80C) )
          {
            //if ( weather_id == 18 )
            //{
              //v60 = (double)weather_time;
LABEL_239:
              //weather_time = (v60 * 0.75);
            //}
LABEL_240:
            set_seq(76);
            return;
          }
          if ( get_border_near() && h_inerc <= -15.0 )
          {
            set_seq(78);
            return;
          }
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            if ( !field_890 )
            {
              field_890 = 1;
              addbullet(this, NULL,951, x, y, dir, 1, 0, 0);
            }
            
            if ( 0.0 != v_inerc )
              goto LABEL_267;
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
            goto LABEL_273;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          dir = -dir;
          h_inerc = -3.0;
          v65 = 10.0;
          goto LABEL_281;
        case 77:
          angZ = angZ - 30.0;
          v_inerc = v_inerc - v_force;
          if ( !char_on_ground_down() )
          {
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_890 )
            {
              field_890 = 1;
              addbullet(this, NULL,951, x, y, dir, 1, 0, 0);
            }
            goto LABEL_295;
          }
          if ( field_80C )
          {
            if ( weather_id == 18 )
              //weather_time = ((double)weather_time * 0.75);
            scene_play_sfx(22);
            field_7D0 = 100 * h_inerc;
            field_7D2 = 100 * v_inerc;
            reset_forces();
            y = getlvl_height();
            set_seq(89);
            angZ = 0.0;
            v63 = 4.0;
            goto LABEL_275;
          }
          scene_play_sfx(22);
          field_7D0 = 100 * h_inerc;
          field_7D2 = 100 * v_inerc;
          reset_forces();
LABEL_273:
          y = getlvl_height();
          set_seq(97);
          goto LABEL_274;
        case 78:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            scene_play_sfx(22);
            field_7D0 = 100 * h_inerc;
            field_7D2 = 100 * v_inerc;
            reset_forces();
            y = 0.0;
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
              v65 = 3.0;
LABEL_281:
              v_inerc = v65;
              v_force = 0.5;
              if ( !field_890 )
              {
                field_890 = 1;
                addbullet(this, NULL,951, x, y, dir, 1, 0, 0);
              }
            }
          }
          return;
        case 88:
          if ( char_on_ground_down() )
          {
            field_7D0 = 100 * h_inerc;
            field_7D2 = 100 * v_inerc;
            reset_forces();
            y = getlvl_height();
            set_seq(89);
            v51 = 5.0;
            goto LABEL_185;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            goto LABEL_3214;
          if ( !field_890 )
          {
            field_890 = 1;
            addbullet(this, NULL,951, x, y, dir, 1, 0, 0);
          }
          
          if ( 0.0 == v_inerc )
          {
LABEL_3214:
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
          }
          else
          {
LABEL_267:
  
            if ( 0.0 == h_inerc )
              set_seq(3);
            else
LABEL_165:
              set_seq(2);
          }
          return;
        case 89:
          if ( get_subseq() > 0 && (angZ = angZ - 40.0, v_inerc = v_inerc - v_force, char_on_ground_down()) )
          {
            field_7D0 = 100 * h_inerc;
            field_7D2 = 100 * v_inerc;
            reset_forces();
            y = getlvl_height();
            set_seq(97);
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
            goto LABEL_334;
          if ( get_subseq() == 1 )
          {
            if ( !field_890 )
            {
              field_890 = 1;
              addbullet(this, NULL,951, x, y, dir, 1, 0, 0);
            }
LABEL_334:
            if ( get_subseq() == 1 && v_inerc < 2.0 )
              goto LABEL_1849;
          }
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            field_7D0 = 100 * h_inerc;
            field_7D2 = 100 * v_inerc;
            reset_forces();
            y = getlvl_height();
            set_seq(97);
LABEL_184:
            v51 = 2.0;
LABEL_185:
            //shake_camera(v51);
            scene_play_sfx(22);
            return;
          }
          if ( !process() )
            return;
          goto LABEL_339;
        case 149:
          angZ = angZ - 30.0;
          if ( v_inerc <= 0.0 )
            v_inerc = v_inerc - v_force * 0.25;
          else
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            scene_play_sfx(22);
            field_7D0 = 100 * h_inerc;
            field_7D2 = 100 * v_inerc;
            reset_forces();
            y = 0.0;
            set_seq(97);
LABEL_274:
            angZ = 0.0;
            v63 = 2.0;
LABEL_275:
            //shake_camera(v63);
            reset_ofs();
          }
          else
          {
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_890 )
            {
              field_890 = 1;
              addbullet(this, NULL,951, x, y, dir, 1, 0, 0);
            }
LABEL_295:
            process();
          }
          return;
        case 197:
          if ( !get_subseq() && get_frame() <= 2 || get_subseq() == 2 )
            sub10func();
          if ( get_subseq() < 2 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            y = getlvl_height();
            reset_forces();
            set_subseq(2);
            return;
          }
          if ( !process() )
            goto LABEL_365;
          if ( controlling_type == 2 )
          {
LABEL_361:
            set_seq(700);
            goto LABEL_362;
          }
          set_seq(0);
          if ( dY() > 0 )
            set_seq(1);
LABEL_365:
          if ( get_subseq() == 2 && get_frame() == 4 && !get_frame_time() )
          {
            if ( enemy->x < (double)x )
              dir = -1;
            if ( enemy->x > (double)x )
              dir = 1;
          }
          if ( get_subseq() || get_frame() != 3 || get_frame_time() )
            return;
          v_inerc = 4.5;
          v82 = 12.5;
          goto LABEL_376;
        case 198:
          if ( !get_subseq() && get_frame() <= 2 || get_subseq() == 2 )
            sub10func();
          if ( get_subseq() < 2 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            y = getlvl_height();
            reset_forces();
            set_subseq(2);
            return;
          }
          if ( !process() )
            goto LABEL_390;
          if ( controlling_type == 2 )
          {
            set_seq(700);
LABEL_362:
            field_51C = 3;
            field_520 = 3;
          }
          else
          {
            set_seq(0);
            if ( dY() > 0 )
              set_seq(1);
LABEL_390:
            if ( get_subseq() == 2 && get_frame() == 4 && !get_frame_time() )
            {
              if ( enemy->x < (double)x )
                dir = -1;
              if ( enemy->x > (double)x )
                dir = 1;
            }
            if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
            {
              v_inerc = 4.5;
              v82 = -12.5;
LABEL_376:
              h_inerc = v82;
              v_force = 0.34999999;
            }
          }
          return;
        case 199:
          sub10func();
          if ( !process() )
            goto LABEL_405;
          if ( controlling_type == 2 )
            goto LABEL_361;
          set_seq(0);
          if ( dY() > 0 )
            set_seq(1);
LABEL_405:
          if ( get_subseq() == 2 && get_frame() == 2 && !get_frame_time() )
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
          if ( h_inerc > 8.0 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 8.0 )
              h_inerc = 8.0;
          }
          process();
          if ( get_subseq() != 1 )
            goto LABEL_426;
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this,124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          if ( dY() >= 0 )
          {
            if ( (dX(dir) > 0 || ++field_7D0 <= 5) && ++field_7D0 <= 45 )
            {
LABEL_426:
              if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
              {
                char_h_move(15.5);
                scene_add_effect(this,125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
                scene_add_effect(this,126, x, y + 80.0, dir, 1);
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
          if ( !get_subseq() || get_subseq() == 3 )
            sub10func();
          if ( get_subseq() == 1 || get_subseq() == 2 )
            v_inerc = v_inerc - 0.5;
          if ( get_subseq() == 3 )
          {
            h_inerc = h_inerc + 3.0;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
          }
          if ( !char_on_ground_flag() && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this,124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
          }
          if ( char_on_ground_down() && get_subseq() < 3 )
          {
            v_inerc = 0.0;
            v_force = 0.0;
            goto LABEL_445;
          }
          if ( process() )
            goto LABEL_447;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            char_h_move(-14.0);
            v_inerc = 4.0;
            scene_add_effect(this,125, x, y + 80.0, -dir, 1);
            scene_add_effect(this,126, x, y + 80.0, -dir, 1);
            scene_play_sfx(31);
          }
          return;
        case 202:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_454;
          if ( get_subseq() == 1 && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this,124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          process();
          if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
          {
            field_7D0 = 0;
            char_h_move(10.0);
            v_inerc = 4.0;
            v_force = 0.44999999;
            scene_add_effect(this,125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
            scene_add_effect(this,126, x, y + 110.0, dir, 1);
            scene_play_sfx(31);
          }
          goto LABEL_462;
        case 203:
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
          {
            char_h_move(-10.0);
            v_inerc = 4.0;
            v_force = 0.44999999;
            scene_add_effect(this,125, x, y + 120.0, -dir, 1);
            scene_add_effect(this,126, x, y + 120.0, -dir, 1);
            scene_play_sfx(31);
          }
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_454;
          if ( get_subseq() == 1 && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this,124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
          }
          process();
LABEL_462:
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
            return;
          v119 = get_subseq() == 2;
          break;
        case 204:
          sub10func();
          h_inerc = h_inerc - 0.75;
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
            goto LABEL_485;
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() > 0 )
          {
            v_inerc = v_inerc - v_force;
            if ( v_inerc < -20.0 )
              v_inerc = -20.0;
          }
          if ( get_subseq() != 1 )
            goto LABEL_499;
          if ( get_elaps_frames() % 5 )
            goto LABEL_496;
          v1718 = dir;
          y = (scene_rand() % 200) + y;
          v134 = x - (scene_rand() % 100) + 50;
          goto LABEL_495;
        case 209:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_485;
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() > 0 )
          {
            v_inerc =v_inerc - v_force;
            if ( v_inerc < -20.0 )
              v_inerc = -20.0;
          }
          goto LABEL_515;
        case 210:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_485;
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() > 0 )
          {
            v_inerc = v_inerc - v_force;
            if ( v_inerc < -20.0 )
              v_inerc = -20.0;
          }
          goto LABEL_533;
        case 211:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_485;
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() > 0 )
          {
            v_inerc = v_inerc - v_force;
            if ( v_inerc < -20.0 )
              v_inerc = -20.0;
          }
          if ( get_subseq() == 1 && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this,123, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            char_h_move(3.0);
            v_inerc = 20.0;
            v_force = 0.64999998;
            field_49A = 0;
            scene_add_effect(this,63, x, y, dir, 1);
          }
          return;
        case 212:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_561;
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() > 0 )
          {
            v_inerc = v_inerc - v_force;
            if ( v_inerc < -20.0 )
              v_inerc = -20.0;
          }
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            char_h_move(9.0);
            v_inerc = 15.0;
            v_force = 0.64999998;
            field_49A = 0;
            scene_add_effect(this,63, x, y, dir, 1);
          }
          return;
        case 214:
          if ( process() )
            goto LABEL_1396;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            scene_play_sfx(31);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
            goto LABEL_1396;
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
            // dashes?
            if ( field_7D2 - dash_angle > 180 )
              field_7D4 = field_7D4 - 360; //7d2 or 7d4?
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
            if ( 0.09 > h_inerc && get_subseq() == 2 )
            {
              set_subseq(4);
            }
            if ( 0.0 <= h_inerc && get_subseq() == 4 )
              set_subseq(2);
            if ( get_elaps_frames() % 5 == 1 )
            {
              scene_add_effect(this,125, cos_deg(dash_angle) * 100.0 * (double)dir + x, sin_deg(dash_angle) * 100.0 + y + 100.0, dir, 1);
            }
            if ( keyDown(INP_D) == 0 && field_7D6 > 10 || spell_energy <= 0 )
            {
              if ( !keyDown(INP_D) && field_7D6 > 10 || spell_energy <= 0 )
              {
                reset_ofs();
                goto LABEL_645;
              }
            }
          }
          if ( !char_on_ground_down() )
            return;
          y = getlvl_height();
          
          goto LABEL_665;
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
            goto LABEL_675;
          return;
        case 217:
          if ( process() )
            goto LABEL_1439;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            scene_play_sfx(31);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
            goto LABEL_1439;
          field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
          if ( get_subseq() == 5 ||get_subseq() == 6 )
            v_inerc = v_inerc - v_force;
          if ( get_subseq() <= 0 || get_subseq() >= 5 )
            goto LABEL_3215;
          ++field_7D6;
          field_7D4 = field_7D2 - dash_angle;
          //dashes?
          if ( field_7D2 - dash_angle > 180 )
            field_7D4 = field_7D2 - dash_angle - 360;
          if ( field_7D4 < -180 )
            field_7D4 = field_7D4 + 360;
          if ( field_7D4 < 0 > 0 )
          {
            if ( weather_id )
              dash_angle = dash_angle + 0.699999988079071;
            else
              dash_angle = dash_angle + 2.799999952316284;
          }
          if ( field_7D4 < 0)
          {
            if ( weather_id )
              dash_angle = dash_angle - 0.699999988079071;
            else
              dash_angle = dash_angle - 2.799999952316284;
          }
          h_inerc = cos_deg(dash_angle) * field_7DC;
          v_inerc = sin_deg(dash_angle) * field_7DC;
          if ( y > 680.0 && v_inerc > 0.0 )
            v_inerc = 0.0;
          field_7DC = field_7DC + 0.300000011920929;
          if ( field_7DC  > 10.0 )
            field_7DC = 10.0;
          if ( weather_id )
            spell_energy_spend(15, 60);
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
            scene_add_effect(this,125, cos_deg(dash_angle) * 100.0 * (double)dir + x, sin_deg(dash_angle) * 100.0 + y + 100.0, dir, 1);
          }
          if ( (keyDown(INP_D) != 0 || field_7D6 <= 20) && spell_energy > 0 || (keyDown(INP_D) || field_7D6 <= 20) && spell_energy > 0 )
          {
LABEL_3215:
            if ( char_on_ground_down() )
            {
              y = getlvl_height();
              
              v_force = 0.0;
LABEL_665:
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
LABEL_645:
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
            goto LABEL_561;
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() > 0 )
          {
            v_inerc = v_inerc - v_force;
            if ( v_inerc < -20.0 )
              v_inerc = -20.0;
          }
          if ( get_subseq() == 1 )
          {
            if ( !(get_elaps_frames() % 5) )
            {
              v1718 = dir;
              y = (scene_rand() % 200) + y;
              v134 = x - (scene_rand() % 100) + 50;
LABEL_495:
              scene_add_effect(this,123, v134, y, v1718, 1);
            }
LABEL_496:
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
          }
LABEL_499:
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          char_h_move(0.0);
          v136 = 20.0;
          goto LABEL_504;
        case 221:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_485;
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() > 0 )
          {
            v_inerc = v_inerc - v_force;
            if ( v_inerc < -20.0 )
              v_inerc = -20.0;
          }
          if ( get_subseq() == 1 )
          {
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this,123, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
LABEL_515:
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v139 = 8.0;
          goto LABEL_523;
        case 222:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_485;
          if ( char_on_ground_flag() || v_inerc > 0.0 )
            field_522 = 2;
          if ( get_subseq() > 0 )
          {
            v_inerc = v_inerc - v_force;
            if ( v_inerc < -20.0 )
              v_inerc = -20.0;
          }
          if ( get_subseq() == 1 )
          {
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this,123, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
            }
LABEL_533:
            if ( get_subseq() == 1 && v_inerc < 4.0 )
              set_subseq(2);
          }
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v139 = -8.0;
LABEL_523:
            char_h_move(v139);
            v136 = 17.5;
LABEL_504:
            v_inerc = v136;
            v_force = 0.64999998;
            field_49A = 0;
            scene_add_effect(this,63, x, y, dir, 1);
          }
          return;
        case 223:
          sub10func();
          field_49A = 1;
          process();
          if ( get_subseq() != 1 )
            goto LABEL_3216;
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this,124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          if ( ((++field_7D0, dX(dir) > 0) || field_7D0 <= 12) && field_7D0 <= 45 )
          {
LABEL_3216:
            if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
            {
              char_h_move(7.5);
              ++field_7D0;
              scene_add_effect(this,125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
              scene_add_effect(this,126, x, y + 80.0, dir, 1);
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
          if ( get_subseq() == 1 || get_subseq() == 2 )
            v_inerc = v_inerc - 0.5;
          if ( get_subseq() == 3 )
          {
            h_inerc = h_inerc + 2.0;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
          }
          if ( !char_on_ground_flag() && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this,124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
          }
          if ( char_on_ground_down() && get_subseq() < 3 )
          {
            v_inerc = 0.0;
            goto LABEL_445;
          }
          if ( process() )
          {
LABEL_447:
            set_seq(0);
            h_inerc = 0.0;
          }
          else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_7D0 )
          {
            field_7D0 = 1;
            char_h_move(-14.0);
            v_inerc = 4.0;
            scene_add_effect(this,125, x, y + 80.0, -dir, 1);
            scene_add_effect(this,126, x, y + 80.0, -dir, 1);
            scene_play_sfx(31);
          }
          return;
        case 225:
          if ( get_subseq() >= 1 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_454;
          if ( get_subseq() == 2 && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this,124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
          }
          if ( process() )
            set_seq(9);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            char_h_move(-10.0);
            v_inerc = 4.0;
            v_force = 0.44999999;
            scene_add_effect(this,125, x, y + 120.0, -dir, 1);
            scene_add_effect(this,126, x, y + 120.0, -dir, 1);
            scene_play_sfx(31);
          }
          return;
        case 226:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_454:
            reset_forces();
            y = getlvl_height();
            set_seq(10);
            return;
          }
          if ( get_subseq() == 2 && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this,124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          if ( process() )
            set_seq(9);
          if ( get_elaps_frames() )
            return;
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            field_7D0 = 0;
            char_h_move(10.0);
            v_inerc = 4.0;
            v_force = 0.44999999;
            scene_add_effect(this,125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
            scene_add_effect(this,126, x, y + 110.03, dir, 1);
            scene_play_sfx(31);
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
            return;
          v119 = get_subseq() == 3;
          break;
        default:
          goto LABEL_3210;
      }
LABEL_466:
      if ( v119 )
        flip_with_force();
    }
    return;
  }
  if ( sq > 560 )
  {
    switch ( sq )
    {
      case 561:
        if ( !get_subseq() || get_subseq() == 3 )
          sub10func();
        field_18C = 3;
        if ( get_subseq() == 1 || get_subseq() == 2 )
          v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 3 )
          goto LABEL_1387;
        if ( process() )
          set_seq(0);
        if ( !get_frame_time() && get_frame() == 3 && !get_subseq() )
        {
          /*
          *(float *)&v2164 = 0.0;
          v2165 = 12.0;
          v2166 = 0.0;
          */
          addbullet(this, NULL,825, x, y, dir, 1, 0, 3);
          play_sfx(7);
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          spell_energy_spend(200, 120);
          add_card_energy(50);
          h_inerc = 4.5;
          v_inerc = 22.5;
          v_force = 0.75;
        }
        return;
      case 565:
        if ( !get_subseq() && get_frame() <= 1 || get_subseq() == 1 || get_subseq() == 2 ||get_subseq() == 3 || get_subseq() == 6 || get_subseq() == 8 )
          sub10func();
        field_18C = 7;
        if ( keyDown(INP_B) == 1 )
          field_7D4 = 10;
        if ( --field_7D4 < 0 )
          field_7D4 = 0;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 1 )
        {
          play_sfx(7);
          y = getlvl_height();
          v_force = 0.0;
          v_inerc = 0.0;
          set_subseq(1);
          /*
          *(float *)&v2089 = 0.0;
          v2090 = 0.0;
          v2091 = 0.0;
          */
          addbullet(this, NULL,826, x, y, dir, 1, 0, 3);
        }
        if ( !(getlvl_height() < y + v_inerc) && v_inerc < 0.0 )
        {
          if ( get_subseq() == 4 || get_subseq() == 5 || get_subseq() == 7 )
          {
            y = getlvl_height();
            reset_forces();
            set_subseq(6);
          }
        }
        if ( get_subseq() == 1 )
        {
          if ( !(get_elaps_frames() % 8) )
          {
            scene_add_effect(this,128, (double)(100 * (char)dir) + x, y, dir, 1);
          }
          if ( get_elaps_frames() >= 10 && field_7D4 > 0 )
            goto LABEL_2269;
          if ( get_elaps_frames() >= 18 )
            goto LABEL_2271;
        }
        if ( get_subseq() == 4 || get_subseq() == 5 )
        {
          h_inerc = h_inerc - 0.25;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( get_subseq() == 7 )
        {
          h_inerc = h_inerc - 0.1000000014901161;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( get_subseq() == 8 )
        {
          h_inerc = h_inerc - 0.4000000059604645;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 8 )
          goto LABEL_339;
        if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
        {
          h_inerc = 10.0;
          v_inerc = 2.0;
          v_force = 0.75;
          spell_energy_spend(200, 120);
          add_card_energy(50);
        }
        if ( get_subseq() == 4 && !get_frame_time() && get_frame() == 4 && field_7D4 > 0 && skills_1[7] >= 4 )
          goto LABEL_2297;
        if ( get_subseq() == 7 && !get_frame_time() && get_frame() == 1 )
        {
          float t[3];
          t[0] = -75.0;
          t[1] = 12.0;
          t[2] = 1.0;
          addbullet(this, NULL,825, (double)(85 * (char)dir) + x, y + 117.0, dir, 1, t, 3);
          play_sfx(10);
        }
        if ( get_elaps_frames() )
          goto LABEL_2313;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
        {
          field_190 = 0;
          field_194 = 1;
          v_inerc = 10.0;
          //v1316 = &v2002;
          v_force = 0.5;
          /*
          *(float *)&v2002 = 0.0;
          v2003 = 12.0;
          v2004 = 0.0;
          */
          goto LABEL_2307;
        }
        goto LABEL_2308;
      case 566:
        if ( !get_subseq() && get_frame() <= 1 || get_subseq() == 1 || get_subseq() == 2 || get_subseq() == 3 || get_subseq() == 6 || get_subseq() == 8 )
          sub10func();
        field_18C = 7;
        if ( keyDown(INP_C) == 1 )
          field_7D4 = 10;
        if ( --field_7D4 < 0 )
          field_7D4 = 0;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 1 )
        {
          play_sfx(7);
          y = getlvl_height();
          v_force = 0.0;
          v_inerc = 0.0;
          set_subseq(1);
          /*
          *(float *)&v2155 = 0.0;
          v2156 = 0.0;
          v2157 = 0.0;
          addbullet(this, NULL,826, x, y, dir, 1, (int)&v2155, 3);
          */
        }
        if ( !(getlvl_height() < y + v_inerc) && v_inerc < 0.0 )
        {
          if ( get_subseq() == 4 || get_subseq() == 5 || get_subseq() == 7 )
          {
            y = getlvl_height();
            reset_forces();
            set_subseq(6);
          }
        }
        if ( get_subseq() != 1 )
          goto LABEL_2348;
        if ( !(get_elaps_frames() % 8) )
        {
          scene_add_effect(this,128, (double)(100 * (char)dir) + x, y, dir, 1);
        }
        if ( get_elaps_frames() >= 10 && field_7D4 > 0 )
        {
LABEL_2269:
          next_subseq();
        }
        else if ( get_elaps_frames() > 25 )
        {
LABEL_2271:
          set_subseq(8);
        }
        else
        {
LABEL_2348:
          if ( get_subseq() == 4 || get_subseq() == 5 )
          {
            h_inerc = h_inerc - 0.25;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( get_subseq() == 7 )
          {
            h_inerc = h_inerc - 0.1000000014901161;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( get_subseq() == 8 )
          {
            h_inerc = h_inerc - 0.4000000059604645;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 8 )
          {
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              h_inerc = 12.5;
              v_inerc = 4.0;
              v_force = 0.89999998;
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            if ( get_subseq() != 4 || get_frame_time() || get_frame() != 4 || field_7D4 <= 0 || skills_1[7] < 4 )
            {
              if ( get_subseq() == 7 && !get_frame_time() && get_frame() == 1 )
              {
                /*
                *(float *)&v2005 = -75.0;
                v2006 = 12.0;
                v2007 = 1.0;
                v1333 = dir;
                v1334 = y + 117.0;
                v1335 = v1334;
                v1336 = (double)(85 * (char)v1333) + x;
                addbullet(this, NULL,825, v1336, v1335, v1333, 1, (int)&v2005, 3);
                */
                play_sfx(10);
              }
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                {
                  field_190 = 0;
                  field_194 = 1;
                  v_inerc = 10.0;
                  //v1316 = (int *)&v2008;
                  v_force = 0.5;
                  /*
                  v2008 = 0.0;
                  v2009 = 12.0;
                  v2010 = 0.0;
                  */
LABEL_2307:
                  addbullet(this, NULL,825, x, y, dir, 1, 0, 3);

                  play_sfx(7);
                }
LABEL_2308:
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 7 )
                  set_seq(0);
              }
LABEL_2313:
              if ( get_subseq() == 8 && get_frame() == 2 )
              {
                v1318 = 8;
                if ( skills_1[7] >= 2 )
                  v1318 = 6;
                if ( skills_1[7] >= 3 )
                  v1318 = 4;
                if ( get_frame_time() >= v1318 )
                  next_frame();
              }
            }
            else
            {
LABEL_2297:
              set_subseq(7);
              field_190 = 0;
              field_194 = 1;
              v_inerc = 10.0;
              v_force = 0.5;
            }
          }
          else
          {
LABEL_339:
            set_subseq(5);
          }
        }
        return;
      case 570:
        field_18C = 11;
        if ( get_subseq() && get_subseq() != 5 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 5 )
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
        if ( get_subseq() == 1 )
        {
          h_inerc = h_inerc - 0.1000000014901161;
          if ( h_inerc < 2.0 )
            h_inerc = 2.0;
        }
        if ( get_subseq() == 2 )
        {
          h_inerc = h_inerc - 0.25;
          if ( h_inerc < 1.0 )
            h_inerc = 1.0;
          if ( get_elaps_frames() >= 30 )
            goto LABEL_1938;
        }
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() )
          return;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          h_inerc = 12.5;
          v_inerc = 14.0;
          v_force = 0.75;
          scene_add_effect(this,127, x, y, dir, 1);
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 2 )
          return;
        field_190 = 1;
        spell_energy_spend(200, 120);
        add_card_energy(50);
        /*
        *(float *)&v1993 = 0.0;
        v1994 = 1.0;
        v1995 = 0.0;
        if ( skills_1[11] >= 3 )
          v1995 = 2.0;
        v1340 = (float *)&v1993;
        */
        goto LABEL_2409;
      case 571:
        field_18C = 11;
        if ( get_subseq() && get_subseq() != 5 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 5 )
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
        if ( get_subseq() == 1 )
        {
          h_inerc = h_inerc - 0.1000000014901161;
          if ( h_inerc < 2.0 )
            h_inerc = 2.0;
        }
        if ( get_subseq() == 2 )
        {
          h_inerc = h_inerc - 0.25;
          if ( h_inerc < 1.0 )
            h_inerc = 1.0;
          if ( get_elaps_frames() >= 30 )
            goto LABEL_1938;
        }
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() )
          return;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          h_inerc = 18.5;
          v_inerc = 15.0;
          v_force = 0.75;
          scene_add_effect(this,127, x, y, dir, 1);
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 2 )
          return;
        field_190 = 1;
        spell_energy_spend(200, 120);
        add_card_energy(50);
        /*
        v1990 = 0.0;
        v1991 = 1.0;
        v1992 = 0.0;
        if ( skills_1[11] >= 3 )
          v1992 = 2.0;
        v1340 = &v1990;
        */
        //goto LABEL_2409;
        return; //TODO: change!
      case 572:
        field_18C = 11;
        if ( get_subseq() == 5 )
        {
          sub10func();
        }
        else
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 5 )
          {
LABEL_1859:
            reset_forces();
            y = getlvl_height();
            set_subseq(5);
            return;
          }
        }
        if ( get_subseq() == 1 )
        {
          h_inerc = h_inerc - 0.1000000014901161;
          if ( h_inerc < 2.0 )
            h_inerc = 2.0;
        }
        if ( get_subseq() == 2 )
        {
          h_inerc = h_inerc - 0.25;
          if ( h_inerc < 1.0 )
            h_inerc = 1.0;
          if ( get_elaps_frames() >= 30 )
          {
LABEL_1938:
            v_force = 0.5;
            next_subseq();
            return;
          }
        }
        if ( get_subseq() == 4 && get_elaps_frames() >= 8 )
        {
LABEL_1439:
          set_seq(9);
          return;
        }
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() )
          return;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          h_inerc = 12.5;
          v_inerc = 12.0;
          v_force = 0.75;
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 2 )
          return;
        field_190 = 1;
        spell_energy_spend(200, 120);
        add_card_energy(50);
        /*
        v1999 = 0.0;
        v2000 = 1.0;
        v2001 = 0.0;
        if ( skills_1[11] >= 3 )
          v2001 = 2.0;
          */
        addbullet(this, NULL,827, x, y, dir, 1, 0, 3);
        goto LABEL_2410;
      case 573:
        field_18C = 11;
        if ( get_subseq() == 5 )
        {
          sub10func();
        }
        else
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 5 )
          {
LABEL_1674:
            reset_forces();
            y = getlvl_height();
            set_subseq(5);
            return;
          }
        }
        if ( get_subseq() == 1 )
        {
          h_inerc = h_inerc - 0.1000000014901161;
          if ( h_inerc < 2.0 )
            h_inerc = 2.0;
        }
        if ( get_subseq() != 2 )
          goto LABEL_3217;
        h_inerc = h_inerc - 0.25;
        if ( h_inerc < 1.0 )
          h_inerc = 1.0;
        if ( get_elaps_frames() >= 30 )
        {
LABEL_1918:
          v_force = 0.5;
          next_subseq();
        }
        else
        {
LABEL_3217:
          if ( get_subseq() == 4 && get_elaps_frames() >= 8 )
          {
LABEL_1396:
            set_seq(9);
          }
          else
          {
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                h_inerc = 18.5;
                v_inerc = 12.5;
                v_force = 0.75;
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              {
                field_190 = 1;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                /*
                v1996 = 0.0;
                v1997 = 1.0;
                v1998 = 0.0;
                if ( skills_1[11] >= 3 )
                  v1998 = 2.0;
                v1340 = &v1996;
                */
LABEL_2409:
                addbullet(this, NULL,827, x, y, dir, 1, 0, 3);
LABEL_2410:
                play_sfx(27);
                v_force = 0.0;
              }
            }
          }
        }
        return;
      case 600:
        sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() != 1 )
          goto LABEL_2497;
        if ( get_elaps_frames() > 30 )
          goto LABEL_1849;
        if ( field_7D0 < 5 && !(get_elaps_frames() % 5) )
        {
          play_sfx(8);
          /*
          *(float *)&v1859 = (double)(30 * field_7D0 - 225);
          v1860 = 15.0;
          v1861 = (double)(field_7D0 % 3) + 3.0;
          v1348 = dir;
          v1349 = -*(float *)&v1859;
          v1350 = sin_deg(v1349) * 35.0 + y + 120.0;
          v1351 = v1350;
          v1352 = -*(float *)&v1859;
          v1353 = (cos_deg(v1352) * 35.0 + 18.0) * (double)dir + x;
          addbullet(this, NULL,850, v1353, v1351, v1348, 1, (int)&v1859, 3);
          *(float *)&v1859 = (double)(225 - 30 * field_7D0);
          v1860 = 15.0;
          v1861 = (double)(field_7D0 % 3) + 3.0;
          v1354 = dir;
          v1355 = -*(float *)&v1859;
          v1356 = sin_deg(v1355) * 35.0 + y + 120.0;
          v1357 = v1356;
          v1358 = -*(float *)&v1859;
          v1359 = (cos_deg(v1358) * 35.0 + 18.0) * (double)dir + x;
          addbullet(this, NULL,850, v1359, v1357, v1354, 1, (int)&v1859, 3);
          */
          ++field_7D0;
        }
LABEL_2497:
        if ( process() )
        {
          set_seq(0);
          sub_46AB50(6, 30);
        }
        if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
        {
          sub_4834E0(40);
          scene_play_sfx(23);
          scene_add_effect(this,115, x - (double)(2 * (char)dir), y + 120.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        return;
      case 601:
        sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() != 1 )
          goto LABEL_2533;
        if ( get_elaps_frames() > 60 )
          goto LABEL_992;
        if ( field_7D0 < 10 && !(get_elaps_frames() % 5) )
        {
          play_sfx(8);
          /*
          *(float *)&v1933 = (double)field_7D0 * -36.0;
          v1934 = 0.0;
          v1935 = (double)(field_7D0 % 3);
          v1381 = dir;
          v1382 = y + 120.0;
          v1383 = v1382;
          v1384 = (double)(18 * (char)v1381) + x;
          addbullet(this, NULL,853, v1384, v1383, v1381, 1, (int)&v1933, 3);
          *(float *)&v1933 = 0.0;
          v1934 = 0.0;
          v1385 = dir;
          v1386 = y + 120.0;
          v1387 = v1386;
          v1388 = (double)(18 * (char)v1385) + x;
          addbullet(this, NULL,890, v1388, v1387, v1385, 1, (int)&v1933, 3);
          */
          ++field_7D0;
        }
LABEL_2533:
        if ( process() )
        {
          set_seq(0);
          sub_46AB50(6, 60);
        }
        if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
        {
          sub_4834E0(40);
          scene_play_sfx(23);
          scene_add_effect(this,115, x - (double)(2 * (char)dir),  y + 120.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        return;
      case 602:
        sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() == 1 && get_elaps_frames() > 45 )
          goto LABEL_992;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && field_7D0 < 14 )
        {
          play_sfx(8);
          /*
          *(float *)&v2014 = (double)(MT_getnext() % 0x46u) - 35.0;
          v2015 = 0.0;
          v2016 = (double)(field_7D0 % 3);
          v1394 = dir;
          v1395 = y + 120.0;
          v1396 = v1395;
          v1397 = (double)(18 * (char)v1394) + x;
          addbullet(this, NULL,854, v1397, v1396, v1394, 1, (int)&v2014, 3);
          */
          ++field_7D0;
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
        {
          sub_4834E0(40);
          scene_play_sfx(23);
          scene_add_effect(this,115, x - (double)(2 * (char)dir), y + 120.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        return;
      case 604:
        sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() == 2 && get_elaps_frames() >= 60 )
          goto LABEL_992;
        if ( !get_subseq() && get_frame() == 6 && !get_frame_time() )
        {
          sub_4834E0(40);
          scene_play_sfx(23);
          scene_add_effect(this,115, (double)(7 * (char)dir) + x, y + 226.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 8 )
        {
          addbullet(this,NULL, 854, x, y, dir, 1, 0, 1);
          play_sfx(22);
        }
        return;
      case 605:
        sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() == 1 && get_elaps_frames() > 30 )
          goto LABEL_1849;
        if ( !get_subseq() && get_frame() == 6 && !get_frame_time() )
        {
          sub_4834E0(40);
          scene_play_sfx(23);
          scene_add_effect(this,115, (double)(7 * (char)dir) + x, y + 226.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 8 )
        {
          /*
          *(float *)&v1893 = 0.0;
          v1412 = dir;
          v1413 = (double)(75 * (char)v1412) + x;
          addbullet(this, NULL,855, v1413, y, v1412, 1, (int)&v1893, 1);
          v1414 = dir;
          v1415 = x - (double)(75 * v1414);
          addbullet(this, NULL,855, v1415, y, -v1414, 1, (int)&v1893, 1);
          */
          play_sfx(9);
        }
        return;
      case 606:
        sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() == 1 && get_elaps_frames() > 90 || get_subseq() == 2 && get_elaps_frames() > 70 )
          goto LABEL_992;
        if ( !get_subseq() && get_frame() == 6 && !get_frame_time() )
        {
          sub_4834E0(40);
          scene_play_sfx(23);
          scene_add_effect(this,115, (double)(7 * (char)dir) + x,  y + 226.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 8 )
        {
          addbullet(this, NULL,856, x, y, dir, 1, 0, 1);
          play_sfx(9);
        }
        return;
      case 607:
        sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() != 1 )
          goto LABEL_2599;
        if ( get_elaps_frames() > 100 )
          goto LABEL_1849;
        if ( field_7DC < 15.0 && !(get_elaps_frames() % 5) )
        {
          play_sfx(23);
          /*
          v1765 = 0.0;
          for ( i = (float)0.0; ; i = v1765 )
          {
            *(float *)&v2020 = i * 90.0 + field_7DC * 25.0;
            v2021 = field_7DC * 15.0 + 10.0;
            v2022 = 0.0;
            v1422 = dir;
            v1423 = y + 120.0;
            v1424 = v1423;
            v1425 = (double)(18 * (char)v1422) + x;
            addbullet(this, NULL,857, v1425, v1424, v1422, 1, (int)&v2020, 3);
            v1765 = v1765 + 1.0;
            if ( v1765 >= 4.0 )
              break;
          }
          */
          field_7DC = field_7DC + 1.0;
        }
LABEL_2599:
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && get_frame() == 5 && !get_frame_time() )
        {
          sub_4834E0(40);
          scene_play_sfx(23);
          scene_add_effect(this,115, x - (double)(2 * (char)dir), y + 120.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        return;
      case 608:
        if ( !get_subseq() && get_frame() <= 3 || get_subseq() == 3 )
          sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() == 1 && get_elaps_frames() > 20 )
          goto LABEL_992;
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
        if ( process() )
        {
          set_seq(0);
          sub_46AB50(6, 60);
        }
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 4 )
          {
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this,115, (double)(24 * (char)dir) + x, y + 144.0, dir, 1);
          }
          if ( !get_frame_time() )
          {
            if ( get_frame() == 5 )
            {
              h_inerc = -2.0;
              v_inerc = 7.5;
              v_force = 0.30000001;
            }
            if ( !get_frame_time() && get_frame() == 10 )
              field_7D0 = 1;
          }
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
          set_seq(9);
        if ( field_7D0 <= 0 )
          return;
        if ( --field_7D2 > 0 )
          return;
        if ( field_7D4 >= 3 )
          return;
        /*
        *(float *)&v1906 = (double)field_7D4 * 10.0 - 80.0;
        v1907 = 0.0;
        v1908 = 0.0;
        v1446 = dir;
        v1447 = y + 120.0;
        v1448 = v1447;
        v1449 = (double)(78 * (char)v1446) + x;
        addbullet(this, NULL,858, v1449, v1448, v1446, 1, (int)&v1906, 3);
        *(float *)&v1906 = 0.0;
        v1907 = 0.0;
        v1726 = &v1906;
        v1908 = 2.0;
        xd = dir;
        v1450 = y + 120.0;
        v1705 = v1450;
        v1451 = (double)(78 * dir) + x;
        v1452 = v1451;
        */
        //goto LABEL_2653;
        return; //TODO: change!
      case 609:
        sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() == 1 && (get_elaps_frames() > 40 || field_7D8 == 1) || get_subseq() == 2 && get_elaps_frames() > 24 )
          goto LABEL_1849;
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
        {
          /*
          *(float *)&v2032 = 0.0;
          v2033 = 0.0;
          v2034 = 0.0;
          v1455 = dir;
          v1456 = y + 93.0;
          v1457 = v1456;
          v1458 = (double)(228 * (char)v1455) + x;
          addbullet(this, NULL,852, v1458, v1457, v1455, 1, (int)&v2032, 3);
          */
          play_sfx(12);
        }
        return;
      case 610:
        sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() == 1 && get_elaps_frames() > 60 )
          goto LABEL_1849;
        if ( process() )
        {
          set_seq(0);
          sub_46AB50(6, 120);
        }
        if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
        {
          addbullet(this, NULL,859, (double)(280 * (char)dir) + x, y + 93.0, dir, 1, 0, 0);
          play_sfx(13);
        }
        return;
      case 612:
        if ( !get_subseq() )
        {
          if ( !get_frame_time() && get_frame() == 1 )
          {
            x_off = 0.0;
            y_off = 50.0;
            scaleX = 1.0;
            scaleY = 1.0;
           //color_a = -1;
           //color_G = -1;
           //color_G = -1;
           //color_b = -1;
            play_sfx(2);
            
          }
          if ( get_frame() > 0 )
          {
            if ( scaleX > 0.0 )
            {
              scaleX = scaleX - 0.1000000014901161;
              scaleY = scaleY + 0.2000000029802322;
            }
            /*
            v1463 =//color_a;
            if ( v1463 <= 0x19u )
             //color_a = 0;
            else
             //color_a = v1463 - 25;
              */
          }
        }
        if ( get_subseq() == 2 )
        {
          if ( !get_frame() )
          {
            if ( 1.0 <= scaleX )
            {
              scaleX = 1.0;
              scaleY = 1.0;
             //color_a = -1;
            }
            else
            {
              scaleX = scaleX + 0.1000000014901161;
              scaleY = scaleY - 0.2000000029802322;
             //color_a += 25;
            }
          }
          if ( get_frame() < 3 )
            v_inerc = v_inerc - 0.699999988079071;
        }
        if ( get_subseq() == 3 )
        {
          if ( field_190 && field_194 > 0 )
            field_190 = 0;
          if ( getlvl_height() >= (y + v_inerc) && v_inerc < 0.0 )
          {
            y = getlvl_height();
            reset_forces();
            next_subseq();
            return;
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
        {
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
          sub_4834E0(40);
          scene_play_sfx(23);
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_2708;
        if ( get_subseq() == 2 )
        {
          x = enemy->x - (double)(180 * dir);
          y = 150.0;
          h_inerc = 6.0;
          v_inerc = 8.0;
          play_sfx(6);
LABEL_2708:
          if ( get_subseq() == 2 && get_frame() == 3 && !get_frame_time() )
          {
            h_inerc = 7.5;
            v_inerc = -24.0;
          }
        }
        return;
      case 614:
        if ( !get_subseq() || get_subseq() == 3 || get_subseq() == 4 || get_subseq() == 7 )
          sub10func();
        sub_46AB50(6, 2);
        v_inerc = v_inerc - v_force;
        if ( !char_on_ground_down() )
          goto LABEL_2722;
        if ( get_subseq() < 3 )
        {
LABEL_1429:
          reset_forces();
          y = getlvl_height();
          goto LABEL_1430;
        }
        if ( get_subseq() > 3 && get_subseq() < 7 )
        {
          reset_forces();
          y = getlvl_height();
          set_subseq(7);
          return;
        }
LABEL_2722:
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 1 )
          {
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this,115, (double)(24 * (char)dir) + x, y + 144.0, dir, 1);
          }
          if ( !get_frame_time() && get_frame() == 3 )
          {
            /*
            *(float *)&v2038 = 0.0;
            v2039 = 12.0;
            v2040 = 0.0;
            addbullet(this, NULL,825, x, y, dir, 1, (int)&v2038, 3);
            */
            play_sfx(7);
          }
        }
        if ( get_elaps_frames() )
          goto LABEL_2742;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          field_190 = 0;
          field_194 = 1;
          h_inerc = 6.0;
          v_inerc = 10.0;
          v_force = 1.25;
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_2742;
        if ( get_subseq() == 4 )
        {
          if ( field_7D0 < 2 )
          {
            field_7D0 = field_7D0 + 1;
            set_subseq(0);
            
            /*
            *(float *)&v2044 = 0.0;
            v2045 = 12.0;
            v2046 = 0.0;
            addbullet(this, NULL,825, x, y, dir, 1, (int)&v2044, 3);
            */
            play_sfx(7);
          }
LABEL_2742:
          if ( get_subseq() == 4 && !get_frame_time() && get_frame() == 2 )
          {
            /*
            *(float *)&v2050 = 0.0;
            v2051 = 12.0;
            v2052 = 0.0;
            */
            addbullet(this, NULL,825, x, y, dir, 1, 0, 3);
            play_sfx(7);
          }
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_2751;
        if ( get_subseq() == 5 )
        {
          field_190 = 0;
          field_194 = 1;
          h_inerc = 6.0;
          v_inerc = 18.5;
          v_force = 0.5;
LABEL_2751:
          if ( get_subseq() == 5 && !get_frame_time() )
          {
            if ( get_frame() == 5 )
            {
              field_194 = 1;
              field_190 = 0;
              /*
              *(float *)&v2056 = -75.0;
              v2057 = 12.0;
              v2058 = 1.0;
              v1472 = dir;
              v1473 = y + 117.0;
              v1474 = v1473;
              v1475 = (double)(85 * (char)v1472) + x;
              addbullet(this, NULL,825, v1475, v1474, v1472, 1, (int)&v2056, 3);
              */
              play_sfx(10);
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                v_force = 0.1;
                h_inerc = h_inerc * 0.5;
                v_inerc = 0.5 * v_inerc;
              }
              if ( !get_frame_time() && get_frame() == 8 )
                v_force = 0.5;
            }
          }
        }
        return;
      case 616:
        if ( get_subseq() == 8 )
          sub10func();
        sub_46AB50(6, 2);
        switch ( get_subseq() )
        {
          case 1:
          case 2:
            v_inerc = v_inerc - v_force;
            if ( getlvl_height() + 300.0 < (v_inerc + y) || v_inerc >= 0.0 )
              break;
            reset_forces();
            set_subseq(3);
            y = getlvl_height() + 280.0;
            /*
            v2064 = 2.0;
            v1767 = 0.0;
            v1478 = (float)0.0;
            do
            {
              *(float *)&v2062 = v1478 * 45.0;
              v2063 = 30.0;
              v1479 = dir;
              v1480 = getlvl_height();
              addbullet(this, NULL,866, x, v1480, v1479, 1, (int)&v2062, 3);
              v1767 = v1767 + 1.0;
              v1478 = v1767;
            }
            while ( v1767 < 8.0 );
            */
            return;
          case 3:
            y = getlvl_height() + 280.0 + field_7DC;
            field_7DC = field_7DC + 2.0;
            if ( field_7DC > 20.0 )
              field_7DC = 20.0;
            break;
          case 4:
          case 5:
            h_inerc = h_inerc + 0.2000000029802322;
            if ( h_inerc > 8.0 )
              h_inerc = 8.0;
            if ( getlvl_height() + 300.0 < y )
            {
              v_inerc = v_inerc - 0.2000000029802322;
              if ( getlvl_height() + 300.0 >= (v_inerc + y) )
              {
                y = getlvl_height() + 300.0;
                v_inerc = 0.0;
              }
            }
            if ( get_subseq() == 5 && get_elaps_frames() >= 120 )
            {
              next_subseq();
              v_inerc = 4.5;
              h_inerc = -4.0;
              v_force = 0.5;
            }
            break;
          case 6:
          case 7:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              reset_forces();
              y = getlvl_height();
              set_subseq(8);
            }
            break;
          default:
            break;
        }
        if ( process() )
          goto LABEL_115;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          h_inerc = 0.0;
          v_inerc = 25.0;
          v_force = 0.69999999;
          /*
          *(float *)&v2068 = 0.0;
          v2069 = 0.0;
          v2070 = 0.0;
          v1486 = dir;
          v1487 = getlvl_height() + 150.0;
          addbullet(this, NULL,866, x, v1487, v1486, -1, (int)&v2068, 3);
          */
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
          sub_4834E0(120);
          scene_play_sfx(23);
          scene_add_effect(this,115, (double)(24 * (char)dir) + x, y + 144.0, dir, 1);
        }
        if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 5 )
          sub_4834E0(1);
        return;
      case 619:
        sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() == 1 && get_elaps_frames() >= 20 )
          goto LABEL_992;
        if ( process() )
          goto LABEL_115;
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 3 )
          {
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this,115, x, y + 120.0, dir, 1);
          }
          if ( !get_frame_time() && get_frame() == 5 )
          {
            play_sfx(22);
            /*
            v1493 = 0.0;
            v1768 = 0.0;
            v1494 = (float)0.0;
            while ( 1 )
            {
              *(float *)&v1978 = 51.40000152587891 * v1494;
              v1979 = v1493;
              v1980 = v1493;
              v1981 = v1494;
              yd = sin_deg(*(float *)&v1978) <= 0.0 ? 1 : -1;
              v1495 = dir;
              v1496 = getlvl_height() + 150.0;
              addbullet(this, NULL,869, x, v1496, v1495, yd, (int)&v1978, 4);
              v1768 = v1768 + 1.0;
              if ( v1768 >= 7.0 )
                break;
              v1494 = v1768;
              v1493 = 0.0;
            }
            */
            field_8B4 = 900;
            field_8B6 = 0;
            field_8B8 = 0;
          }
        }
        return;
      case 650:
        if ( get_subseq() == 4 )
          sub10func();
        sub_46AB50(6, 2);
        /*
        v1364 = get_subseq();
        v1367 = __OFSUB__(v1364, 1);
        v1365 = v1364 == 1;
        v1366 = (v1364 - 1) < 0;
        if ( v1364 != 1 )
          goto LABEL_2508;
        if ( get_elaps_frames() > 60 )
          goto LABEL_992;
        v1367 = 0;
        v1365 = 1;
        v1366 = 0;
LABEL_2508:
        if ( !((v1366 ^ v1367) | v1365) && v1364 < 4 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            v1368 = getlvl_height();
            goto LABEL_2512;
          }
        }*/
        if ( get_subseq() == 1 && field_7D0 < 5 && !(get_elaps_frames() % 5) )
        {
          play_sfx(8);
          /*
          *(float *)&v1900 = (double)(30 * field_7D0 - 225);
          v1901 = 15.0;
          v1902 = (double)(field_7D0 % 3) + 3.0;
          v1369 = dir;
          v1370 = y + 120.0;
          v1371 = v1370;
          v1372 = (double)(18 * (char)v1369) + x;
          addbullet(this, NULL,850, v1372, v1371, v1369, 1, (int)&v1900, 3);
          *(float *)&v1900 = (double)(225 - 30 * field_7D0);
          v1901 = 15.0;
          v1902 = (double)(field_7D0 % 3) + 3.0;
          v1373 = dir;
          v1374 = y + 120.0;
          v1375 = v1374;
          v1376 = (double)(18 * (char)v1373) + x;
          addbullet(this, NULL,850, v1376, v1375, v1373, 1, (int)&v1900, 3);
          */
          ++field_7D0;
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
        {
          sub_4834E0(40);
          scene_play_sfx(23);
          scene_add_effect(this,115, x - (double)(2 * (char)dir), y + 120.0, dir, 1);
          sub_469450(0, 0, 60);
          sub_483570();
          weather_forecast_next();
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
          set_seq(9);
        return;
      case 651:
        if ( get_subseq() == 4 )
          sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() != 1 )
          goto LABEL_2814;
        if ( get_elaps_frames() > 60 )
        {
LABEL_1849:
          next_subseq();
        }
        else
        {
          if ( field_7D0 < 10 && !(get_elaps_frames() % 5) )
          {
            play_sfx(8);
            /*
            *(float *)&v1936 = (double)field_7D0 * -45.0;
            v1937 = 0.0;
            v1938 = (double)(field_7D0 % 3);
            v1497 = dir;
            v1498 = y + 120.0;
            v1499 = v1498;
            v1500 = (double)(18 * (char)v1497) + x;
            addbullet(this, NULL,853, v1500, v1499, v1497, 1, (int)&v1936, 3);
            *(float *)&v1936 = 0.0;
            v1937 = 0.0;
            v1501 = dir;
            v1502 = y + 120.0;
            v1503 = v1502;
            v1504 = (double)(18 * (char)v1501) + x;
            addbullet(this, NULL,890, v1504, v1503, v1501, 1, (int)&v1936, 3);
            */
            ++field_7D0;
          }
LABEL_2814:
          if ( get_subseq()> 1 && get_subseq() < 4 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
          {
            y = getlvl_height();
            reset_forces();
            set_subseq(4);
          }
          else
          {
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this,115, x - (double)(2 * (char)dir), y + 120.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
          }
        }
        return;
      case 657:
        if ( get_subseq() == 4 )
        {
          sub10func();
        }
        else
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_1920;
        }
        sub_46AB50(6, 2);
        if ( get_subseq() != 1 )
          goto LABEL_2617;
        if ( get_elaps_frames() <= 100 )
        {
          if ( field_7DC < 15.0 && !(get_elaps_frames() % 5) )
          {
            play_sfx(23);
            /*
            v1766 = 0.0;
            for ( j = (float)0.0; ; j = v1766 )
            {
              *(float *)&v2026 = j * 90.0 + field_7DC * 25.0;
              v2027 = field_7DC * 15.0 + 10.0;
              v2028 = 0.0;
              v1431 = dir;
              v1432 = y + 120.0;
              v1433 = v1432;
              v1434 = (double)(18 * (char)v1431) + x;
              addbullet(this, NULL,857, v1434, v1433, v1431, 1, (int)&v2026, 3);
              v1766 = v1766 + 1.0;
              if ( v1766 >= 4.0 )
                break;
            }
            */
            field_7DC = field_7DC + 1.0;
          }
LABEL_2617:
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && get_frame() == 5 && !get_frame_time() )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this,115, x - (double)(2 * (char)dir), y + 120.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
        }
        else
        {
          next_subseq();
          v_force = 0.5;
        }
        return;
      case 658:
        if ( get_subseq() == 3 )
          sub10func();
        sub_46AB50(6, 2);
        if ( get_subseq() == 1 && get_elaps_frames() > 20 )
          goto LABEL_992;
        v_inerc = v_inerc - v_force;
        if ( get_subseq() < 3 && char_on_ground_down() )
        {
          y = getlvl_height();
          reset_forces();
          set_subseq(3);
        }
        else
        {
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 4 )
            {
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this,115, (double)(24 * (char)dir) + x, y + 144.0, dir, 1);
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 5 )
              {
                h_inerc = -2.0;
                v_inerc = 7.5;
                v_force = 0.30000001;
              }
              if ( !get_frame_time() && get_frame() == 10 )
                field_7D0 = 1;
            }
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            set_seq(9);
          if ( field_7D0 > 0 && --field_7D2 <= 0 )
          {
            if ( field_7D4 < 3 )
            {
              /*
              *(float *)&v1912 = (double)field_7D4 * 10.0 - 80.0;
              v1913 = 0.0;
              v1914 = 0.0;
              v1515 = dir;
              v1516 = y + 120.0;
              v1517 = v1516;
              v1518 = (double)(78 * (char)v1515) + x;
              addbullet(this, NULL,858, v1518, v1517, v1515, 1, (int)&v1912, 3);
              *(float *)&v1912 = 0.0;
              v1913 = 0.0;
              v1726 = &v1912;
              v1914 = 2.0;
              xd = dir;
              v1519 = y + 120.0;
              v1705 = v1519;
              v1520 = (double)(78 * dir) + x;
              v1452 = v1520;
LABEL_2653:
              v1453 = v1452;
              addbullet(this, NULL,858, v1453, v1705, xd, 1, (int)v1726, 3);
              */
              play_sfx(11);
              field_7D2 = 6;
              ++field_7D4;
            }
          }
        }
        return;
      case 669:
        sub_46AB50(6, 2);
        if ( get_subseq() != 1 )
          goto LABEL_2870;
        if ( get_elaps_frames() < 240 )
        {
          if ( get_elaps_frames() <= 180 )
          { /*
            v1523 = get_elaps_frames() & 0x80000001;
            v1522 = v1523 == 0;
            if ( v1523 < 0 )
              v1522 = (((_BYTE)v1523 - 1) | 0xFFFFFFFE) == -1;
            if ( v1522 )
            {
              v1769 = 0.0;
              v1524 = (float)0.0;
              v1525 = 3.0;
              while ( 1 )
              {
                *(float *)&v1865 = v1524 * 120.0 + field_7DC;
                v1866 = 30.0;
                v1867 = v1525;
                v1526 = dir;
                v1527 = -*(float *)&v1865;
                v1528 = sin_deg(v1527) * 80.0 + y + 100.0;
                v1529 = v1528;
                v1530 = -*(float *)&v1865;
                v1531 = cos_deg(v1530) * 80.0 * (double)dir + x;
                addbullet(this, NULL,869, v1531, v1529, v1526, 1, (int)&v1865, 3);
                v1769 = v1769 + 1.0;
                v1532 = 3.0;
                if ( v1769 >= 3.0 )
                  break;
                v1525 = 3.0;
                v1524 = v1769;
              }
              v1770 = 0.0;
              v1533 = (float)0.0;
              while ( 1 )
              {
                *(float *)&v1865 = v1533 * 90.0 - field_7DC;
                v1866 = 30.0;
                v1867 = v1532;
                v1534 = dir;
                v1535 = -*(float *)&v1865;
                v1536 = sin_deg(v1535) * 80.0 + y + 100.0;
                v1537 = v1536;
                v1538 = -*(float *)&v1865;
                v1539 = cos_deg(v1538) * 80.0 * (double)dir + x;
                addbullet(this, NULL,869, v1539, v1537, v1534, 1, (int)&v1865, 3);
                v1770 = v1770 + 1.0;
                if ( v1770 >= 4.0 )
                  break;
                v1533 = v1770;
                v1532 = 3.0;
              }
              field_7DC = field_7DC + 4.0;
            }
            if ( !(get_elaps_frames() % 8) )
            {
              *(float *)&v2074 = 0.0;
              v2075 = 0.0;
              v2076 = 4.0;
              v1540 = y + 100.0;
              addbullet(this, NULL,869, x, v1540, dir, 1, (int)&v2074, 3);
            }
            if ( !(get_elaps_frames() % 10) )
            {
              *(float *)&v2080 = (double)get_MT_range(360);
              v2081 = 0.0;
              v2082 = 5.0;
              v1541 = y + 100.0;
              addbullet(this, NULL,869, x, v1541, dir, 1, (int)&v2080, 3);
            }*/
          } 
LABEL_2870:
          if ( (get_subseq() == 2 || get_subseq() == 3) && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
          {
LABEL_1920:
            reset_forces();
            y = getlvl_height();
            set_subseq(4);
          }
          else if ( process() )
          {
LABEL_115:
            set_seq(0);
          }
          else
          {
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(24);
              //shake_camera(8.0);
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              weather_forecast_next();
              sub_4834E0(70);
              scene_play_sfx(23);
              scene_add_effect(this,115, x, y + 120.0, dir, 1);
              field_8B4 = 0;
              field_8B6 = 0;
              field_8B8 = 0;
            }
          }
        }
        else
        {
          next_subseq();
          v_force = 0.2;
        }
        return;
      case 695:
        sub10func();
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
        {
          scene_play_sfx(55);
          scene_add_effect(this,140, x, y + 100.0, dir, 1);
          scene_add_effect(this,140, x, y + 100.0, dir, 1);
          scene_add_effect(this,140, x, y + 100.0, dir, 1);
          scene_add_effect(this,141, x, y + 100.0, dir, -1);
          scene_add_effect(this,142, x, y, dir, -1);
        }
        return;
      case 696:
        sub10func();
        if ( h_inerc > 0.0 )
          h_inerc = h_inerc - 1.5;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 3 )
            h_inerc = 20.0;
          if ( !get_frame_time() && get_frame() == 4 )
            scene_play_sfx(28);
        }
        return;
      case 710:
        sub10func();
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          //difficulty?
          switch ( settings_get()->get_difficulty() )
          {
            case GAME_DIFF_LUNA:
              //v1549 = 3.0;
              field_7D0 = 30;
              field_7D2 = 60;
              goto LABEL_2913;
            case GAME_DIFF_HARD:
              //v1549 = 4.0;
              field_7D0 = 30;
              field_7D2 = 45;
LABEL_2913:
              //field_7DC = v1549;
              //v1548 = 20.0;
              goto LABEL_2914;
            case GAME_DIFF_NORMAL:
              field_7D0 = 20;
              field_7D2 = 45;
              field_7DC = 6.0;
              //v1548 = 15.0;
              goto LABEL_2914;
            case GAME_DIFF_EASY:
              field_7D0 = 10;
              field_7D2 = 45;
              field_7DC = 8.0;
              //v1548 = 13.0;
LABEL_2914:
              dash_angle = 20.0;//v1548;
              break;
            default:
              break;
          }
        }
        if ( get_subseq() != 1 || get_elaps_frames() < field_7D0 )
        {
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
          {
            play_sfx(4);
            dash_angle = 45.0 - 90.0;
            //v1771 = 0.0;
            if ( field_7DC > 0.0 )
            {
              /*
              v1551 = v1771;
              do
              {
                *(float *)&v1986 = dash_angle - v1551 * dash_angle;
                v1987 = (double)get_MT_range(25) * 0.1000000014901161 + 7.5;
                v1988 = 0.0;
                v1989 = (double)get_MT_range(20) + 20.0;
                v1552 = dir;
                v1553 = -*(float *)&v1986;
                v1554 = sin_deg(v1553) * 150.0 + y - (double)get_pframe()->extra_24byte[5];
                v1555 = v1554;
                v1556 = -*(float *)&v1986;
                v1557 = (sin_deg(v1556) * 150.0 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
                addbullet(this, NULL,900, v1557, v1555, v1552, 1, (int)&v1986, 4);
                v1771 = v1771 + 1.0;
                v1551 = v1771;
              }
              while ( field_7DC > (double)v1771 );
              */
            }
          }
          if ( get_subseq() == 3 && get_elaps_frames() >= field_7D2 )
            next_subseq();
        }
        else
        {
          next_subseq();
          flip_with_force();
        }
        return;
      case 711:
        if ( get_subseq() && get_subseq() != 6 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            y = getlvl_height();
            reset_forces();
            set_subseq(6);
            scene_play_sfx(30);
            return;
          }
        }
        else
        {
          sub10func();
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            h_inerc = field_85C;
            v_inerc = field_860;
            v_force = field_864;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
          {
            v_force = 0.0;
            h_inerc = h_inerc * 0.1000000014901161;
            v_inerc = 0.1000000014901161 * v_inerc;
            //difficulty?
            switch ( settings_get()->get_difficulty() )
            {
              case GAME_DIFF_LUNA:
                //v1560 = 3.0;
                field_7D0 = 150;
                field_7D2 = 60;
                goto LABEL_2948;
              case GAME_DIFF_HARD:
                //v1560 = 4.0;
                field_7D0 = 120;
                field_7D2 = 45;
LABEL_2948:
                //field_7DC = v1560;
                //v1559 = 20.0;
                goto LABEL_2949;
              case GAME_DIFF_NORMAL:
                field_7D0 = 90;
                field_7D2 = 45;
                field_7DC = 6.0;
                //v1559 = 15.0;
                goto LABEL_2949;
              case GAME_DIFF_EASY:
                field_7D0 = 60;
                field_7D2 = 45;
                field_7DC = 8.0;
                //v1559 = 13.0;
LABEL_2949:
                dash_angle = 15.0;//v1559;
                break;
              default:
                break;
            }
          }
        }
        if ( get_subseq() != 3 || get_elaps_frames() < field_7D0 )
        {
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
          {
            flip_with_force();
            play_sfx(3);
            h_inerc = -6.0;
            v_inerc = 7.5;
            v_force = 0.2;
            sub_486FD0(75.0, 25.0);
            /*
            v1880 = SLODWORD(field_7F0);
            v1881 = 0.0;
            v1882 = 0.0;
            v1562 = dir;
            v1563 = -*(float *)&v1880;
            v1564 = sin_deg(v1563) * 100.0 + y - (double)get_pframe()->extra_24byte[5];
            v1565 = v1564;
            v1566 = -*(float *)&v1880;
            v1567 = (sin_deg(v1566) * 100.0 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
            addbullet(this, NULL,901, v1567, v1565, v1562, 1, (int)&v1880, 3);
            v1882 = 1.0;
            v1568 = dir;
            v1569 = -*(float *)&v1880;
            v1570 = sin_deg(v1569) * 100.0 + y - (double)get_pframe()->extra_24byte[5];
            v1571 = v1570;
            v1572 = -*(float *)&v1880;
            v1573 = (sin_deg(v1572) * 100.0 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
            addbullet(this, NULL,901, v1573, v1571, v1568, 1, (int)&v1880, 3);
            */
          }
        }
        else
        {
          next_subseq();
          h_inerc = h_inerc * 0.25;
          v_inerc = 0.25 * v_inerc;
          v_force = 0.0;
        }
        return;
      case 720:
        if ( get_subseq() == 5 )
          sub10func();
        if ( get_subseq() != 1 )
          goto LABEL_2983;
        if ( x <= 640.0 )
        {
          if ( dir == 1 )
          {
            v1575 = h_inerc + 0.02999999932944775;
            goto LABEL_2967;
          }
        }
        else if ( dir != 1 )
        {
          v1575 = h_inerc + 0.02999999932944775;
          goto LABEL_2967;
        }
        v1575 = h_inerc - 0.02999999932944775;
LABEL_2967:
        h_inerc = v1575;
        if ( h_inerc > 6.0 )
          h_inerc = 6.0;
        if ( h_inerc < -6.0 )
          h_inerc = -6.0;
        if ( y >= 150.0 )
          v_inerc = v_inerc - 0.01250000018626451;
        else
          v_inerc = v_inerc + 0.01250000018626451;
        if ( v_inerc > 2.5 )
          v_inerc = 2.5;
        if ( v_inerc < -2.5 )
          v_inerc = -2.5;
        if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 60 )
        {
          /*
          *(float *)&v1918 = (double)get_MT_range(360);
          v1919 = (double)get_MT_range(400) + 200.0;
          v1920 = (double)get_MT_range(3);
          v1578 = dir;
          v1579 = -*(float *)&v1918;
          v1580 = sin_deg(v1579);
          v1581 = v1580 * v1919 + y - (double)get_pframe()->extra_24byte[5];
          v1582 = v1581;
          v1583 = -*(float *)&v1918;
          v1584 = cos_deg(v1583);
          v1585 = (v1584 * v1919 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
          addbullet(this, NULL,970, v1585, v1582, v1578, 1, (int)&v1918, 3);
          */
        }
        if ( get_elaps_frames() < field_7D0 )
        {
LABEL_2983:
          if ( get_subseq() != 2 || (h_inerc = h_inerc * 0.9800000190734863, v_inerc = 0.9800000190734863 * v_inerc, get_elaps_frames() < 120) )
          {
            if ( (get_subseq() == 3 || get_subseq() == 4) && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
            {
              y = getlvl_height();
              reset_forces();
              set_subseq(5);
            }
            else
            {
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                //difficulty?
                switch ( settings_get()->get_difficulty() )
                {
                  case GAME_DIFF_LUNA:
                    field_7D0 = 480;
                    field_7DC = 6.0;
                    //v1588 = 2.0;
                    goto LABEL_3001;
                  case GAME_DIFF_HARD:
                    field_7D0 = 480;
                    field_7DC = 8.0;
                    //v1588 = 4.0;
                    goto LABEL_3001;
                  case GAME_DIFF_NORMAL:
                    field_7D0 = 420;
                    field_7DC = 10.0;
                    //v1588 = 6.0;
                    goto LABEL_3001;
                  case GAME_DIFF_EASY:
                    field_7D0 = 420;
                    field_7DC = 12.0;
                    //v1588 = 8.0;
LABEL_3001:
                    dash_angle = 6.0;//v1588;
                    break;
                  default:
                    break;
                }
                play_sfx(8);
                //v1772 = 0.0;
                if ( field_7DC > 0.0 )
                {
                  /*
                  v1589 = v1772;
                  do
                  {
                    *(float *)&v1974 = 360.0 / field_7DC * v1589;
                    v1975 = 0.0;
                    v1976 = (double)(v1589 % 3) + 3.0;
                    v1977 = (double)(v1589 % (field_7DC / 2)) * 480.0 / field_7DC;
                    v1590 = dir;
                    v1591 = -*(float *)&v1974;
                    v1592 = sin_deg(v1591) * 100.0 + y - (double)get_pframe()->extra_24byte[5];
                    v1593 = v1592;
                    v1594 = -*(float *)&v1974;
                    v1595 = (sin_deg(v1594) * 100.0 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
                    addbullet(this, NULL,910, v1595, v1593, v1590, 1, (int)&v1974, 4);
                    v1772 = v1772 + 1.0;
                    v1589 = v1772;
                  }
                  while ( field_7DC > (double)v1772 );
                  */
                }
                h_inerc = 7.0 - 3.0;
                v_inerc = 4.0;
              }
            }
          }
          else
          {
            v_force = 0.25;
            next_subseq();
          }
        }
        else
        {
          next_subseq();
          play_sfx(8);
        }
        return;
      case 730:
        if ( get_subseq() == 1 || get_subseq() == 2 )
        {
          dash_angle = dash_angle + 2.0;
          if ( dash_angle >= 60.0 )
            dash_angle = 60.0;
          //set_vec_speed((render_class *)&cEffectSprite, field_7DC, dash_angle);
        }
        if ( get_subseq() != 2 )
          goto LABEL_3029;
        field_571 = 0;
        if ( !(get_elaps_frames() % 2) )
        {
          /*
          *(float *)&v2086 = 0.0;
          v2087 = 0.0;
          v2088 = 0.0;
          addbullet(this, NULL,921, x, y, dir, 1, (int)&v2086, 3);
          */
        }
        if ( x < -100.0 && dir == 1 )
          x = 1380.0;
        if ( x > 1380.0 && dir == -1 )
          x = 100.0;
        if ( get_elaps_frames() < field_7D0 )
          goto LABEL_3029;
        if ( dir == 1 && (x < 0.0 || x > 640.0) )
          goto LABEL_3028;
        if ( dir != -1 )
          goto LABEL_3029;
        if ( x > 1280.0 )
        {
LABEL_3028:
          next_subseq();
          return;
        }
        if ( x < 640.0 )
        {
          next_subseq();
          return;
        }
LABEL_3029:
        if ( get_subseq() == 3 || get_subseq() == 4 )
        {
          dash_angle = dash_angle * 0.8999999761581421;
          //set_vec_speed((render_class *)&cEffectSprite, field_7DC, v1600);
          if ( x < -100.0 && dir == 1 )
            x = 1380.0;
          if ( x > 1380.0 && dir == -1 )
            x = 100.0;
        }
        if ( get_subseq() == 4 && get_elaps_frames() >= field_7D2 )
          goto LABEL_992;
        if ( process() )
        {
          field_7D0 = 20.0 + 40;
          //difficulty?
          switch ( settings_get()->get_difficulty() )
          {
            case GAME_DIFF_LUNA:
              field_7D2 = 120;
              field_7E4 = 10.0;
              field_7D4 = 180;
              //v1601 = 0.0;
              goto LABEL_3045;
            case GAME_DIFF_HARD:
              field_7D2 = 90;
              field_7E4 = 15.0;
              field_7D4 = 240;
              //v1601 = 20.0;
              goto LABEL_3045;
            case GAME_DIFF_NORMAL:
              field_7D2 = 60;
              field_7E4 = 20.0;
              field_7D4 = 300;
              //v1601 = 40.0;
              goto LABEL_3045;
            case GAME_DIFF_EASY:
              field_7D2 = 40;
              field_7E4 = 30.0;
              field_7D4 = 360;
              //v1601 = 60.0;
LABEL_3045:
              field_7E8 = 40.0;//v1601;
              break;
            default:
              break;
          }
          if ( y > 240.0 )
            field_7DC = 5.0 + 174.0;
          else
            field_7DC = -174.0 - 5.0;
          set_subseq(1);
        }
        else
        {
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            field_7D0 = 20.0 + 40;
            //difficulty?
            switch ( settings_get()->get_difficulty() )
            {
              case GAME_DIFF_LUNA:
                field_7D2 = 120;
                field_7E4 = 10.0;
                field_7D4 = 180;
                //v1604 = 25.0;
                goto LABEL_3059;
              case GAME_DIFF_HARD:
                field_7D2 = 90;
                field_7E4 = 15.0;
                field_7D4 = 240;
                //v1604 = 50.0;
                goto LABEL_3059;
              case GAME_DIFF_NORMAL:
                field_7D2 = 60;
                field_7E4 = 20.0;
                field_7D4 = 300;
                //v1604 = 50.0;
                goto LABEL_3059;
              case GAME_DIFF_EASY:
                field_7D2 = 40;
                field_7E4 = 30.0;
                field_7D4 = 360;
                //v1604 = 60.0;
LABEL_3059:
                field_7E8 = 50.0;//v1604;
                break;
              default:
                break;
            }
            if ( y > 240.0 )
              field_7DC = 6.0 + 172.0;
            else
              field_7DC = -172.0 - 6.0;
          }
          if ( get_subseq() == 4 )
          {
            if ( !get_elaps_frames() )
            {
              play_sfx(23);
              /*
              v1743 = 360.0;
              v1773 = 0.0;
              if ( field_822 )
              {
                if ( field_7E8 > 0.0 )
                {
                  do
                  {
                    *(float *)&v1889 = (double)get_MT_range(360);
                    v1890 = (double)get_MT_range(26) + 4.0;
                    v1891 = (double)get_MT_range(4);
                    v1615 = dir;
                    v1616 = y + 120.0;
                    v1617 = v1616;
                    v1618 = (double)(18 * (char)v1615) + x;
                    addbullet(this, NULL,922, v1618, v1617, v1615, 1, (int)&v1889, 4);
                    v1773 = v1773 + 1.0;
                  }
                  while ( field_7E8 > (double)v1773 );
                }
                if ( settings_get()->get_difficulty() )
                {
                  play_sfx(23);
                  v1744 = (double)get_MT_range(360);
                  v1775 = 0.0;
                  v1619 = (float)0.0;
                  do
                  {
                    *(float *)&v2187 = v1619 * 90.0 + v1744;
                    v2188 = field_7E4;
                    v2189 = 0.0;
                    v2190 = (double)field_7D4;
                    v1620 = dir;
                    v1621 = y + 120.0;
                    v1622 = v1621;
                    v1623 = (double)(18 * (char)v1620) + x;
                    addbullet(this, NULL,920, v1623, v1622, v1620, 1, (int)&v2187, 4);
                    v1775 = v1775 + 1.0;
                    v1619 = v1775;
                  }
                  while ( v1775 < 4.0 );
                }
                field_822 = 0;
              }
              else
              {
                v1606 = v1773;
                do
                {
                  *(float *)&v1889 = v1606 * 90.0 + v1743;
                  v1890 = field_7E4;
                  v1891 = 0.0;
                  v1892 = (double)field_7D4;
                  v1607 = dir;
                  v1608 = y + 120.0;
                  v1609 = v1608;
                  v1610 = (double)(18 * (char)v1607) + x;
                  addbullet(this, NULL,920, v1610, v1609, v1607, 1, (int)&v1889, 4);
                  v1773 = v1773 + 1.0;
                  v1606 = v1773;
                }
                while ( v1773 < 4.0 );
                v1774 = 0.0;
                if ( field_7E8 > 0.0 )
                {
                  do
                  {
                    *(float *)&v1889 = (double)get_MT_range(360);
                    v1890 = (double)get_MT_range(26) + 4.0;
                    v1891 = (double)get_MT_range(4);
                    v1611 = dir;
                    v1612 = y + 120.0;
                    v1613 = v1612;
                    v1614 = (double)(18 * (char)v1611) + x;
                    addbullet(this, NULL,922, v1614, v1613, v1611, 1, (int)&v1889, 4);
                    v1774 = v1774 + 1.0;
                  }
                  while ( field_7E8 > (double)v1774 );
                }
                field_822 = 1;
              }*/
            }
            if ( get_elaps_frames() == 20 && (settings_get()->get_difficulty() == 2 || settings_get()->get_difficulty() == 3) )
            {
              play_sfx(23);
              /*
              v1745 = (double)get_MT_range(360);
              v1776 = 0.0;
              v1624 = (float)0.0;
              do
              {
                *(float *)&v2195 = v1624 * 90.0 + v1745;
                v2196 = field_7E4;
                v2197 = 0.0;
                v2198 = (double)field_7D4;
                v1625 = dir;
                v1626 = y + 120.0;
                v1627 = v1626;
                v1628 = (double)(18 * (char)v1625) + x;
                addbullet(this, NULL,920, v1628, v1627, v1625, 1, (int)&v2195, 4);
                v1776 = v1776 + 1.0;
                v1624 = v1776;
              }
              while ( v1776 < 4.0 );
              */
            }
            if ( get_elaps_frames() == 40 && settings_get()->get_difficulty() == 3 )
            {
              play_sfx(23);
              /*
              v1746 = 360.0;
              v1777 = 0.0;
              v1629 = (float)0.0;
              do
              {
                *(float *)&v2203 = v1629 * 90.0 + v1746;
                v2204 = field_7E4;
                v2205 = 0.0;
                v2206 = (double)field_7D4;
                v1630 = dir;
                v1631 = y + 120.0;
                v1632 = v1631;
                v1633 = (double)(18 * (char)v1630) + x;
                addbullet(this, NULL,920, v1633, v1632, v1630, 1, (int)&v2203, 4);
                v1777 = v1777 + 1.0;
                v1629 = v1777;
              }
              while ( v1777 < 4.0 );
              */
            }
          }
          if ( get_subseq() == 5 && !get_frame_time() )
          {
            //v119 = get_frame() == 2;
            goto LABEL_466;
          }
        }
        return;
      case 740:
      /*
        if ( x <= 640.0 )
        {
          if ( dir == 1 )
          {
            v1635 = h_inerc + 0.02999999932944775;
            goto LABEL_3096;
          }
        }
        else if ( dir != 1 )
        {
          v1635 = h_inerc + 0.02999999932944775;
          goto LABEL_3096;
        }
        v1635 = h_inerc - 0.02999999932944775;
LABEL_3096:
        h_inerc = v1635;
        if ( h_inerc > 6.0 )
          h_inerc = 6.0;
        if ( h_inerc < -6.0 )
          h_inerc = -6.0;
        v1636 = v_inerc;
        if ( y >= 150.0 )
          v1637 = v1636 - 0.01250000018626451;
        else
          v1637 = v1636 + 0.01250000018626451;
        v_inerc = v1637;
        if ( v_inerc > 2.5 )
          v_inerc = 2.5;
        if ( v_inerc < -2.5 )
          v_inerc = -2.5;
        */
        if ( get_subseq() == 1 )
        {
          if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 60 )
          {
            /*
            *(float *)&v1897 = (double)get_MT_range(360);
            v1898 = (double)get_MT_range(400) + 200.0;
            v1899 = (double)get_MT_range(3);
            v1638 = dir;
            v1639 = -*(float *)&v1897;
            v1640 = sin_deg(v1639);
            v1641 = v1640 * v1898 + y - (double)get_pframe()->extra_24byte[5];
            v1642 = v1641;
            v1643 = -*(float *)&v1897;
            v1644 = cos_deg(v1643);
            v1645 = (v1644 * v1898 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
            addbullet(this, NULL,970, v1645, v1642, v1638, 1, (int)&v1897, 3);
            */
          }
          if ( get_elaps_frames() >= field_7D0 )
            goto LABEL_1430;
        }
        if ( get_subseq() == 2 )
        {
          if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 60 )
          {
            /*
            *(float *)&v1924 = (double)get_MT_range(360);
            v1925 = (double)get_MT_range(400) + 200.0;
            v1926 = (double)get_MT_range(3);
            v1646 = dir;
            v1647 = -*(float *)&v1924;
            v1648 = sin_deg(v1647);
            v1649 = v1648 * v1925 + y - (double)get_pframe()->extra_24byte[5];
            v1650 = v1649;
            v1651 = -*(float *)&v1924;
            v1652 = cos_deg(v1651);
            v1653 = (v1652 * v1925 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
            addbullet(this, NULL,970, v1653, v1650, v1646, 1, (int)&v1924, 3);
            */
          }
          if ( get_elaps_frames() >= field_7D0 )
          {
LABEL_1430:
            set_subseq(3);
            return;
          }
        }
        if ( get_subseq() != 4 )
          goto LABEL_3122;
        if ( field_7DC > 0.0 )
        {
          if ( get_elaps_frames() >= field_7D2 )
          {
LABEL_992:
            next_subseq();
            return;
          }
        }
        else if ( get_elaps_frames() >= field_7D4 )
        {
          next_subseq();
          return;
        }
LABEL_3122:
        if ( process() )
        {
          set_subseq(1);
          if ( field_7DC > 0.0 )
          {
            /*
            *(float *)&v2098 = 0.0;
            v2099 = 0.0;
            v2100 = 0.0;
            v1671 = get_pframe();
            v1728 = (float *)&v2098;
            xe = dir;
            v1672 = y - (double)v1671->extra_24byte[5];
            v1706 = v1672;
            v1673 = (double)(v1671->extra_24byte[4] * (char)xe) + x;
            v1670 = v1673;
            */
          }
          else
          {
            if ( field_81C <= 0 )
            {
              //difficulty?
              switch ( settings_get()->get_difficulty() )
              {
                case GAME_DIFF_LUNA:
                  field_7D0 = 270;
                  field_7D4 = 180;
                  break;
                case GAME_DIFF_HARD:
                  field_7D0 = 240;
                  field_7D4 = 150;
                  break;
                case GAME_DIFF_NORMAL:
                  field_7D0 = 210;
                  field_7D4 = 120;
                  break;
                case GAME_DIFF_EASY:
                  field_7D0 = 180;
                  field_7D4 = 120;
                  break;
                default:
                  break;
              }
              set_subseq(2);
              /*
              *(float *)&v1949 = 0.0;
              v1950 = 0.0;
              v1951 = 0.0;
              v1654 = get_pframe();
              v1655 = y - (double)v1654->extra_24byte[5];
              v1732 = &v1949;
              */
              if ( settings_get()->get_difficulty() == 3 )
              {
                /*
                v1656 = v1655;
                v1657 = dir;
                v1658 = v1656;
                v1659 = (double)(v1654->extra_24byte[4] * (char)v1657) + x;
                addbullet(this, NULL,933, v1659, v1658, v1657, 1, (int)&v1949, 3);
                */
LABEL_3136:
                field_81C = 480;
                return;
              }
              move_valb = dir;
                              /*
              if ( settings_get()->get_difficulty() == 2 )
              {
                v1660 = v1655;
                v1661 = v1660;
                v1662 = (double)(v1654->extra_24byte[4] * (char)move_valb) + x;
                addbullet(this, NULL,932, v1662, v1661, move_valb, 1, (int)&v1949, 3);
                goto LABEL_3136;
              }
              v1663 = v1655;
              v1727 = v1663;
              v1664 = (double)(v1654->extra_24byte[4] * (char)move_valb) + x;
              v1665 = v1664;
LABEL_3135:
              v1666 = v1665;
              addbullet(this, NULL,931, v1666, v1727, move_valb, 1, (int)v1732, 3);
              */
              goto LABEL_3136;
            }
            //difficulty?
            switch ( settings_get()->get_difficulty() )
            {
              case GAME_DIFF_LUNA:
                field_7D0 = 180;
                field_7DC = 3.0;
                field_7D2 = 14;
                field_7D4 = 210;
                break;
              case GAME_DIFF_HARD:
                field_7D0 = 180;
                field_7DC = 3.0;
                field_7D2 = 14;
                field_7D4 = 180;
                break;
              case GAME_DIFF_NORMAL:
                field_7D0 = 120;
                field_7DC = 3.0;
                field_7D2 = 9;
                field_7D4 = 120;
                break;
              case GAME_DIFF_EASY:
                field_7D0 = 120;
                field_7DC = 4.0;
                field_7D2 = 4;
                field_7D4 = 120;
                break;
              default:
                break;
            }
            /*
            v2092 = 0.0;
            v2093 = 0.0;
            v2094 = 0.0;
            v1667 = get_pframe();
            v1728 = &v2092;
            xe = dir;
            v1668 = y - (double)v1667->extra_24byte[5];
            v1706 = v1668;
            v1669 = (double)(v1667->extra_24byte[4] * (char)xe) + x;
            v1670 = v1669;
            */
          }
        }
        else
        {
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          if ( field_81C <= 0 && settings_get()->get_difficulty() )
          {
            //difficulty?
            switch ( settings_get()->get_difficulty() )
            {
              case GAME_DIFF_LUNA:
                field_7D0 = 270;
                field_7D4 = 180;
                break;
              case GAME_DIFF_HARD:
                field_7D0 = 240;
                field_7D4 = 150;
                break;
              case GAME_DIFF_NORMAL:
                field_7D0 = 210;
                field_7D4 = 120;
                break;
              case GAME_DIFF_EASY:
                field_7D0 = 180;
                field_7D4 = 120;
                break;
              default:
                break;
            }
            set_subseq(2);
            /*
            *(float *)&v1952 = 0.0;
            v1953 = 0.0;
            v1954 = 0.0;
            v1675 = get_pframe();
            v1676 = y - (double)v1675->extra_24byte[5];
            v1732 = &v1952;
            if ( settings_get()->get_difficulty() == 3 )
            {
              v1677 = v1676;
              v1678 = dir;
              v1679 = v1677;
              v1680 = (double)(v1675->extra_24byte[4] * (char)v1678) + x;
              addbullet(this, NULL,933, v1680, v1679, v1678, 1, (int)&v1952, 3);
              goto LABEL_3136;
            }
            move_valb = dir;
            if ( settings_get()->get_difficulty() == 2 )
            {
              v1681 = v1676;
              v1682 = v1681;
              v1683 = (double)(v1675->extra_24byte[4] * (char)move_valb) + x;
              addbullet(this, NULL,932, v1683, v1682, move_valb, 1, (int)&v1952, 3);
              goto LABEL_3136;
            }
            v1684 = v1676;
            v1727 = v1684;
            v1685 = (double)(v1675->extra_24byte[4] * (char)move_valb) + x;
            v1665 = v1685;
            goto LABEL_3135;
            */
          }
          switch ( settings_get()->get_difficulty() )
          {
            case GAME_DIFF_LUNA:
              field_7D0 = 180;
              field_7DC = 3.0;
              field_7D2 = 14;
              field_7D4 = 210;
              break;
            case GAME_DIFF_HARD:
              field_7D0 = 180;
              field_7DC = 3.0;
              field_7D2 = 14;
              field_7D4 = 180;
              break;
            case GAME_DIFF_NORMAL:
              field_7D0 = 120;
              field_7DC = 3.0;
              field_7D2 = 9;
              field_7D4 = 120;
              break;
            case GAME_DIFF_EASY:
              field_7D0 = 120;
              field_7DC = 4.0;
              field_7D2 = 4;
              field_7D4 = 120;
              break;
            default:
              break;
          }
          /*
          v2104 = 0.0;
          v2105 = 0.0;
          v1728 = &v2104;
          v2106 = 0.0;
          v1686 = get_pframe();
          xe = dir;
          v1687 = y - (double)v1686->extra_24byte[5];
          v1706 = v1687;
          v1688 = (double)(v1686->extra_24byte[4] * (char)xe) + x;
          v1670 = v1688;
          */
        }
        //v1674 = v1670;
        //addbullet(this, NULL,930, v1674, v1706, xe, 1, (int)v1728, 3);
        field_7DC = field_7DC - 1.0;
        return;
      case 770:
        if ( process() )
          set_seq(700);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
        {
          field_6F5 = 1;
          sub_4685C0(-1);
          sub_46AB50(2, -1);
          field_188 = 0;
          health_to_max();
          field_868 = 1;
          field_820 = 0;
          field_81E = 1;
          field_81A = 0;
          field_81C = 0;
          field_818 = 0;
          scene_play_sfx(23);
          field_882 = 1;
          field_86A = 1;
          /*
          *(float *)&v1955 = 0.0;
          v1956 = 0.0;
          v1957 = 0.0;
          addbullet(this, NULL,1201, 180.0, 130.0, 1, 2, (int)&v1955, 3);
          v1957 = 1.0;
          v1689 = y + 100.0;
          addbullet(this, NULL,1202, x, v1689, dir, -1, (int)&v1955, 3);
          */
        }
        return;
      case 780:
        if ( get_subseq() )
        {
          if ( (get_subseq() - 2) <= 1 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              v1368 = 0.0;
LABEL_2512:
              y = v1368;
              reset_forces();
              set_subseq(4);
              return;
            }
          }
        }
        else
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            field_7D0 = 100 * h_inerc;
            field_7D2 = 100 * v_inerc;
            reset_forces();


            y = getlvl_height();
            set_subseq(1);
            //shake_camera(2.0);
            scene_play_sfx(22);
            scene_add_effect(this,58, x, y, dir, -1);
            return;
          }
        }
        if ( process() )
        {
LABEL_3198:
          set_seq(700);
        }
        else if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
          {
            h_inerc = (double)field_7D0 * 0.004999999888241291;
            v_inerc = 0.004999999888241291 * (double)-field_7D2;
            v_force = 2.0;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 10 )
            set_seq(700);
        }
        return;
      case 788:
        if ( get_subseq() == 9 )
        {
          //shake_camera(2.0);
          if ( !(get_elaps_frames() % 2) )
          {
            /*
            *(float *)&v1894 = -(double)get_MT_range(90) - 45.0;
            v1895 = (double)get_MT_range(10) + 6.0;
            v1896 = 0.0;
            v1692 = (1 - 2 * (get_MT_range(100) <= 0x4B));
            v1693 = dir;
            v1694 = (double)get_MT_range(50) + y - 25.0;
            v1695 = v1694;
            v1696 = (double)get_MT_range(150) + x - 75.0;
            addbullet(this, NULL,971, v1696, v1695, v1693, v1692, (int)&v1894, 3);
            *(float *)&v1894 = -(double)get_MT_range(360);
            v1895 = (double)get_MT_range(10) + 6.0;
            v1896 = 1.0;
            v1697 = sin_deg__int(*(float *)&v1894 > 0.0);
            v1698 = dir;
            v1699 = y;
            v1700 = (double)get_MT_range(150) + x - 75.0;
            addbullet(this, NULL,971, v1700, v1699, v1698, (1.0 - (v1697 + v1697)), (int)&v1894, 3);
            */
          }
        }
        if ( process() || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
          goto LABEL_3198;
        return;
      case 795:
        if ( get_subseq() )
          goto LABEL_3202;
        v_inerc = v_inerc - 0.300000011920929;
        if ( !char_on_ground_down() )
          goto LABEL_3202;
        move_val = 1;
LABEL_159:
        set_seq(move_val);
        goto LABEL_160;
      case 797:
        if ( !get_subseq() )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            set_subseq(1);
            scene_play_sfx(30);
            x = 480.0;
            goto LABEL_160;
          }
        }
LABEL_1010:
        if ( process() )
          set_seq(0);
        return;
      case 798:
        if ( get_subseq() || (v_inerc = v_inerc - v_force, !char_on_ground_down()) )
        {
LABEL_3202:
          if ( process() )
            set_seq(700);
        }
        else
        {
          set_subseq(1);
          scene_play_sfx(30);
          x = 800.0;
LABEL_160:
          y = getlvl_height();
          reset_forces();
        }
        return;
      default:
LABEL_3210:
        char_c::func10();
        return;
    }
  }
  if ( sq != 560 )
  {
    switch ( sq )
    {
      case 301:
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
          if ( get_frame() > 4 )
          {
            h_inerc = h_inerc - 1.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() && get_frame() == 4 )
          {
            scene_play_sfx(27);
            h_inerc = 5.0;
            field_49A = 0;
          }
        }
        return;
      case 302:
        sub10func();
        if (false /*get_true(1)*/ )
          return;
        if ( get_frame() < 4 && !keyDown(INP_A) )
          not_charge_attack = 0;
        if ( h_inerc > 0.0 )
          h_inerc = h_inerc - 1.5;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          set_seq(0);
        if ( get_subseq() || get_frame_time() )
          goto LABEL_885;
        if ( get_frame() != 3 )
          goto LABEL_882;
        if ( not_charge_attack == 1 )
        {
          next_subseq();
          scene_add_effect(this,62, (double)(40 * (char)dir) + x, y + 70.0, dir, 1);
        }
        else
        {
          h_inerc = 20.0;
LABEL_882:
          if ( !get_frame_time() && get_frame() == 4 )
          {
            scene_play_sfx(28);
            /*
            *(float *)&v2134 = 0.0;
            v2135 = 0.0;
            v2136 = 1.0;
            v272 = dir;
            v273 = y + 80.0;
            v274 = v273;
            v275 = (double)(130 * (char)v272) + x;
            addbullet(this, NULL,848, v275, v274, v272, 1, (int)&v2134, 3);
            */
          }
LABEL_885:
          if ( get_subseq() == 1 && !get_frame_time() )
          {
            if ( get_frame() == 1 )
              h_inerc = 20.0;
            if ( !get_frame_time() && get_frame() == 1 )
            {
              scene_play_sfx(28);
              /*
              *(float *)&v2095 = 0.0;
              v2096 = 0.0;
              v2097 = 1.0;
              v276 = dir;
              v277 = y + 80.0;
              v278 = v277;
              v279 = (double)(130 * (char)v276) + x;
              addbullet(this, NULL,848, v279, v278, v276, 1, (int)&v2095, 3);
              */
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
          if ( !get_frame_time() )
          {
            if ( get_frame() < 12 )
              field_190 = 0;
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
                scene_play_sfx(27);
              if ( !get_frame_time() )
              {
                if ( get_frame() == 5 )
                  scene_play_sfx(27);
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 7 )
                    scene_play_sfx(27);
                  if ( !get_frame_time() && get_frame() == 9 )
                    scene_play_sfx(27);
                }
              }
            }
          }
        }
        return;
      case 304:
        if ( !get_subseq() || get_subseq() == 2 || get_subseq() == 5 || get_subseq() == 6 )
          sub10func();
        if ( !keyDown(INP_A) )
          not_charge_attack = 0;
        if ( get_subseq() == 1 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            v_inerc = 0.0;
            v_force = 0.0;
            y = getlvl_height();
            set_subseq(2);
          }
        }
        if ( get_subseq() == 2 )
        {
          h_inerc = h_inerc - 1.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( get_subseq() == 4 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            v_inerc = 0.0;
            y = getlvl_height();
            set_subseq(5);
            scene_play_sfx(29);
          }
        }
        if ( get_subseq() == 5 && get_elaps_frames() >= 12 )
          goto LABEL_1849;
        if ( get_subseq() == 6 )
        {
          h_inerc = h_inerc - 1.0;
          if ( h_inerc < 0.0 )
          {
            h_inerc = 0.0;
            field_49A = 0;
          }
        }
        if ( h_inerc > 14.0 )
          h_inerc = h_inerc - 0.5;
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          goto LABEL_945;
        if ( not_charge_attack == 1 )
        {
          set_subseq(3);
          scene_add_effect(this,62, x + 0.0, y + 50.0, dir, 1);
          return;
        }
        field_49A = 0;
        scene_play_sfx(28);
        h_inerc = 10.0;
        v_inerc = 12.0;
        v_force = 0.75;
LABEL_945:
        if ( get_elaps_frames() )
          return;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
          goto LABEL_115;
        if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
        {
          h_inerc = 18.0;
          v_inerc = 5.0;
          v_force = 1.0;
        }
        return;
      case 305:
        sub10func();
        if ( true /*!get_true(1)*/ )
        {
          if ( get_frame() > 4 && h_inerc > 0.0 )
            h_inerc = h_inerc - 1.0;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 3 )
              h_inerc = 10.0;
            if ( !get_frame_time() && get_frame() == 4 )
              scene_play_sfx(27);
          }
        }
        return;
      case 306:
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_485;
        if ( process() )
          set_seq(9);
        if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
        {
          scene_play_sfx(27);
          /*
          *(float *)&v2110 = 0.0;
          v2111 = 0.0;
          v2112 = 3.0;
          v289 = dir;
          v290 = y + 65.0;
          v291 = v290;
          v292 = (double)(150 * (char)v289) + x;
          addbullet(this, NULL,848, v292, v291, v289, 1, (int)&v2110, 3);
          */
        }
        return;
      case 307:
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
        {
          set_seq(10);
          goto LABEL_160;
        }
        if ( get_frame() > 2 )
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 6.0 )
            h_inerc = 6.0;
        }
        if ( process() )
          set_seq(9);
        if ( !get_frame_time() && get_frame() == 2 )
        {
          scene_play_sfx(29);
          h_inerc = 15.0;
          v_inerc = 5.0;
          v_force = 0.34999999;
        }
        return;
      case 308:
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
        {
LABEL_561:
          set_seq(10);
          goto LABEL_160;
        }
        if ( process() )
          set_seq(9);
        if ( !get_frame_time() && get_frame() == 4 )
        {
          scene_play_sfx(29);
          /*
          *(float *)&v2116 = 0.0;
          v2117 = 0.0;
          v2118 = 5.0;
          addbullet(this, NULL,848, x, y, dir, 1, (int)&v2116, 3);
          */
        }
        if ( get_subseq() == 1 && get_elaps_frames() > 10 )
          goto LABEL_992;
        return;
      case 309:
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
        {
LABEL_485:
          set_seq(10);
          goto LABEL_160;
        }
        if ( process() )
          set_seq(9);
        if ( !get_frame_time() && get_frame() == 2 )
        {
          scene_play_sfx(29);
          h_inerc = 5.0;
          v_inerc = 15.0;
          v_force = 0.89999998;
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
          v_inerc = v_inerc - v_force * 0.5;
          angZ = angZ + 40.0;
          if ( !(get_elaps_frames() % 15) )
            scene_play_sfx(27);
          if ( char_on_ground_down() )
          {
            v_inerc = 0.0;
            y = getlvl_height();
            next_subseq();
            angZ = 0.0;
            return;
          }
        }
        if ( get_subseq() == 2 )
        {
          h_inerc = h_inerc - 1.0;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        goto LABEL_1010;
      case 320:
      case 330:
        goto LABEL_838;
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
        if ( get_frame_time() || get_frame() != 2 )
          return;
        h_inerc = 0.0;
        scene_play_sfx(28);
        goto LABEL_847;
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
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 3 )
              h_inerc = 17.5;
            if ( !get_frame_time() && get_frame() == 5 )
              scene_play_sfx(28);
          }
        }
        return;
      case 400:
        sub10func();
        if ( !get_subseq() && !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && not_charge_attack == 1 )
        {
          set_subseq(4);
          scene_add_effect(this,62,  (double)(65 * (char)dir) + x, y + 55.0, dir, 1);
          return;
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1060;
        if ( get_subseq() == 2 )
        {
          sub_486FD0(35.0, -35.0);
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < -30 )
            field_7D4 = -30;
          if ( field_7D4 > 30 )
            field_7D4 = 30;
          field_7D0 = 1;
LABEL_1060:
          if ( get_subseq() == 2 && get_elaps_frames() > 15 )
            next_subseq();
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1068;
        if ( get_subseq() == 4 )
        {
          set_seq(0);
LABEL_1068:
          if ( get_subseq() == 4 && get_elaps_frames() > 15 )
            next_subseq();
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1080;
        if ( get_subseq() == 6 )
        {
          sub_486FD0(35.0, -35.0);
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < -30 )
            field_7D4 = -30;
          if ( field_7D4 > 30 )
            field_7D4 = 30;
          field_7D0 = 1;
LABEL_1080:
          if ( get_subseq() == 6 && get_elaps_frames() > 15 )
            next_subseq();
        }
        if ( field_7D0 <= 0 )
          return;
        if ( not_charge_attack )
        {
          if ( (field_7D0 % 3) != 1 || field_7D2 >= 5 )
            goto LABEL_1097;
          field_190 = 1;
          if ( !field_7D2 )
            spell_energy_spend(200, 45);
          /*
          *(float *)&v1965 = (double)(5 * (field_7D2 - 2)) + field_7F0;
          v1966 = 15.0;
          v1967 = 0.0;
          */
          add_card_energy(10);
          /*
          v319 = 2;
          do
          {
            *(float *)&v1965 = (double)sub_4380D0(-30, 30) + field_7F0;
            v1966 = (double)(15 - sub_4380D0(0, 5));
            v320 = dir;
            v321 = y + 96.0;
            v322 = v321;
            v323 = (double)(114 * (char)v320) + x;
            addbullet(this, NULL,800, v323, v322, v320, 1, (int)&v1965, 3);
            --v319;
          }
          while ( v319 );
          */
        }
        else
        {
          if ( (field_7D0 % 3) != 1 || field_7D2 >= 5 )
            goto LABEL_1097;
          field_190 = 1;
          if ( !field_7D2 )
            spell_energy_spend(200, 45);
          /*
          *(float *)&v2122 = (double)(5 * (field_7D2 - 2)) + field_7F0;
          v2123 = 15.0;
          v2124 = 0.0;
          */
          add_card_energy(10);
          /*
          v315 = dir;
          v316 = y + 96.0;
          v317 = v316;
          v318 = (double)(114 * (char)v315) + x;
          addbullet(this, NULL,800, v318, v317, v315, 1, (int)&v2122, 3);
          */
        }
        goto LABEL_1096;
      case 401:
        sub10func();
        if ( !get_subseq() && !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && not_charge_attack == 1 )
        {
          set_subseq(4);
          scene_add_effect(this,62, (double)(65 * (char)dir) + x, y + 55.0, dir, 1);
          return;
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1118;
        if ( get_subseq() == 2 )
        {
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < -60 )
            field_7D4 = -60;
          if ( field_7D4 > -40 )
            field_7D4 = -40;
          sub_486FD0(-35.0, -70.0);
          field_7D0 = 1;
LABEL_1118:
          if ( get_subseq() == 2 && get_elaps_frames() > 15 )
            next_subseq();
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1126;
        if ( get_subseq() == 4 )
        {
          set_seq(0);
LABEL_1126:
          if ( get_subseq() == 4 && get_elaps_frames() > 15 )
            next_subseq();
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1138;
        if ( get_subseq() == 6 )
        {
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < -60 )
            field_7D4 = -60;
          if ( field_7D4 > -40 )
            field_7D4 = -40;
          sub_486FD0(-35.0, -70.0);
          field_7D0 = 1;
LABEL_1138:
          if ( get_subseq() == 6 && get_elaps_frames() > 15 )
            next_subseq();
        }
        if ( field_7D0 <= 0 )
          return;
        if ( not_charge_attack )
        {
          if ( field_7D0 % 3 == 1 && field_7D2 < 5 )
          {
            field_190 = 1;
            if ( !field_7D2 )
              spell_energy_spend(200, 45);
            add_card_energy(10);
            /*
            v345 = 2;
            *(float *)&v1939 = (double)(5 * (field_7D2 - 2)) + field_7F0;
            v1940 = 15.0;
            v1941 = 0.0;
            do
            {
              *(float *)&v1939 = (double)sub_4380D0(-30, 30) + field_7F0;
              v1940 = (double)(15 - sub_4380D0(0, 5));
              v346 = dir;
              v347 = y + 158.0;
              v348 = v347;
              v349 = (double)(90 * (char)v346) + x;
              addbullet(this, NULL,800, v349, v348, v346, 1, (int)&v1939, 3);
              --v345;
            }
            while ( v345 );
            */
            play_sfx(0);
            ++field_7D2;
          }
        }
        else if ( field_7D0 % 3 == 1 && field_7D2 < 5 )
        {
          field_190 = 1;
          if ( !field_7D2 )
            spell_energy_spend(200, 45);
          add_card_energy(10);
          /*
          *(float *)&v2101 = (double)(5 * (field_7D2 - 2)) + field_7F0;
          v2102 = 15.0;
          v2103 = 0.0;
          v341 = dir;
          v342 = y + 158.0;
          v343 = v342;
          v344 = (double)(90 * (char)v341) + x;
          addbullet(this, NULL,800, v344, v343, v341, 1, (int)&v2101, 3);
          */
          play_sfx(0);
          ++field_7D2;
          ++field_7D0;
          return;
        }
        ++field_7D0;
        return;
      case 402:
        sub10func();
        if ( field_7D0 > 0 )
        {
          field_7D0 = field_7D0 + 1;
          if ( field_7D8 )
          {
            if ( field_7D0 % 3 == 1 )
            {
              if ( field_7D2 < 5 )
                field_7D2 = field_7D2 + 1;
            }
          }
        }
        if ( get_subseq() == 2 && get_elaps_frames() > 10 )
          goto LABEL_992;
        if ( process() )
          set_seq(2);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
          {
            field_190 = 1;
            add_card_energy(30);
            /*
            *(float *)&v1962 = 0.0;
            v1963 = 0.0;
            v1964 = 0.0;
            v353 = dir;
            v354 = (double)(94 * (char)v353) + x;
            addbullet(this, NULL,807, v354, y, v353, -1, (int)&v1962, 3);
            v1964 = 1.0;
            v355 = dir;
            v356 = (double)(94 * (char)v355) + x;
            addbullet(this, NULL,807, v356, y, v355, -1, (int)&v1962, 3);
            */
            play_sfx(1);
            spell_energy_spend(200, 45);
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
            set_seq(2);
        }
        return;
      case 404:
        if ( get_subseq() == 8 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 8 )
        {
          set_subseq(8);
          air_dash_cnt = 0;
          y = getlvl_height();
          reset_forces();
          field_7D0 = 0;
          return;
        }
        if ( !get_subseq() && !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && not_charge_attack == 1 )
        {
          set_subseq(4);
          scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
          return;
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1200;
        if ( get_subseq() == 2 )
        {
          sub_486FD0(35.0, -35.0);
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < -30 )
            field_7D4 = -30;
          if ( field_7D4 > 30 )
            field_7D4 = 30;
          field_7D0 = 1;
LABEL_1200:
          if ( get_subseq() == 2 && get_elaps_frames() > 20 )
          {
            next_subseq();
            v_force = 0.34999999;
          }
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1208;
        if ( get_subseq() == 4 )
        {
          set_seq(9);
LABEL_1208:
          if ( get_subseq() == 4 && get_elaps_frames() > 15 )
            next_subseq();
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1220;
        if ( get_subseq() == 6 )
        {
          sub_486FD0(35.0, -35.0);
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < -30 )
            field_7D4 = -30;
          if ( field_7D4 > 30 )
            field_7D4 = 30;
          field_7D0 = 1;
LABEL_1220:
          if ( get_subseq() == 6 && get_elaps_frames() > 20 )
          {
            next_subseq();
            v_force = 0.34999999;
          }
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 8 )
          set_seq(9);
        if ( field_7D0 <= 0 )
          return;
        if ( !not_charge_attack )
        {
          if ( field_7D0 % 3 != 1 || field_7D2 >= 5 )
            goto LABEL_1097;
          field_190 = 1;
          add_card_energy(10);
          if ( !field_7D2 )
            spell_energy_spend(200, 45);
          /*
          v1719 = &v2011;
          *(float *)&v2011 = (double)(5 * (field_7D2 - 2)) + field_7F0;
          v2012 = 15.0;
          v2013 = 0.0;
          x = dir;
          v374 = y + 117.0;
          v1701 = v374;
          v375 = (double)(83 * dir) + x;
          v376 = v375;
          goto LABEL_1235;
          */
        }
        if ( field_7D0 % 3 != 1 || field_7D2 >= 5 )
          goto LABEL_1097;
        field_190 = 1;
        add_card_energy(10);
        if ( !field_7D2 )
          spell_energy_spend(200, 45);
        /*
        v378 = 2;
        *(float *)&v1949 = (double)(5 * (field_7D2 - 2)) + field_7F0;
        v1950 = 15.0;
        v1951 = 0.0;
        do
        {
          *(float *)&v1949 = (double)sub_4380D0(-30, 30) + field_7F0;
          v1950 = (double)(15 - sub_4380D0(0, 5));
          v379 = dir;
          v380 = y + 117.0;
          v381 = v380;
          v382 = (double)(83 * (char)v379) + x;
          addbullet(this, NULL,800, v382, v381, v379, 1, (int)&v1949, 3);
          --v378;
        }
        while ( v378 );
        */
        goto LABEL_1096;
      case 406:
        if ( get_subseq() == 8 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 8 )
        {
          set_subseq(8);
          air_dash_cnt = 0;
          y = getlvl_height();
          reset_forces();
          field_7D0 = 0;
          return;
        }
        if ( !get_subseq() && !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && not_charge_attack == 1 )
        {
          scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
          set_subseq(4);
          return;
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          sub_486FD0(65.0, 30.0);
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < 40 )
            field_7D4 = 40;
          if ( field_7D4 > 60 )
            field_7D4 = 60;
          field_7D0 = 1;
        }
        if ( get_subseq() == 2 && get_elaps_frames() > 20 )
        {
          next_subseq();
          v_force = 0.34999999;
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1276;
        if ( get_subseq() == 4 )
        {
          set_seq(9);
LABEL_1276:
          if ( get_subseq() == 4 && get_elaps_frames() > 15 )
            next_subseq();
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() )
          goto LABEL_1288;
        if ( get_subseq() == 6 )
        {
          sub_486FD0(65.0, 30.0);
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < 40 )
            field_7D4 = 40;
          if ( field_7D4 > 60 )
            field_7D4 = 60;
          field_7D0 = 1;
LABEL_1288:
          if ( get_subseq() == 6 && get_elaps_frames() > 20 )
          {
            next_subseq();
            v_force = 0.34999999;
          }
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 8 )
          set_seq(9);
        if ( field_7D0 <= 0 )
          return;
        if ( not_charge_attack )
        {
          if ( field_7D0 % 3 == 1 && field_7D2 < 5 )
          {
            field_190 = 1;
            add_card_energy(10);
            if ( !field_7D2 )
              spell_energy_spend(200, 45);
            /*
            v402 = 2;
            *(float *)&v1971 = (double)(5 * (field_7D2 - 2)) + field_7F0;
            v1972 = 15.0;
            v1973 = 0.0;
            do
            {
              *(float *)&v1971 = (double)sub_4380D0(-30, 30) + field_7F0;
              v1972 = (double)(15 - sub_4380D0(0, 5));
              v403 = dir;
              v404 = y + 75.0;
              v405 = v404;
              v406 = (double)(67 * (char)v403) + x;
              addbullet(this, NULL,800, v406, v405, v403, 1, (int)&v1971, 3);
              --v402;
            }
            while ( v402 );
            */
LABEL_1096:
            play_sfx(0);
            ++field_7D2;
          }
        }
        else if ( field_7D0 % 3 == 1 && field_7D2 < 5 )
        {
          field_190 = 1;
          add_card_energy(10);
          if ( !field_7D2 )
            spell_energy_spend(200, 45);
          /*
          v1719 = (int *)&v2149;
          v2149 = (double)(5 * (field_7D2 - 2)) + field_7F0;
          v2150 = 15.0;
          v2151 = 0.0;
          x = dir;
          v400 = y + 75.0;
          v1701 = v400;
          v401 = (double)(67 * dir) + x;
          v376 = v401;
LABEL_1235:
          a3 = v376;
          addbullet(this, NULL,800, a3, v1701, x, 1, (int)v1719, 3);
          */
          play_sfx(0);
          ++field_7D2;
          ++field_7D0;
          return;
        }
LABEL_1097:
        ++field_7D0;
        return;
      case 408:
        if ( get_subseq() == 1 || get_subseq() == 2 )
          sub10func();
        if ( !get_subseq() && get_frame() == 2 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            y = getlvl_height();
            v_force = 0.0;
            v_inerc = 0.0;
            next_subseq();
            scene_play_sfx(29);
          }
        }
        if ( get_subseq() == 1 && get_elaps_frames() > 10 )
          next_subseq();
        if ( get_subseq() == 2 )
        {
          h_inerc = h_inerc - 1.0;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
        {
          v_inerc = 3.5;
          v_force = 0.75;
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          scene_play_sfx(28);
        return;
      case 410:
        sub10func();
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          set_seq(0);
          return;
        }
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1355;
        if ( get_frame() == 6 && not_charge_attack )
        {
          /*
          v410 = y + 57.0;
          v1720 = dir;
          ya = v410;
          v411 = (double)(67 * (char)v1720) + x;
          v412 = v411;
          goto LABEL_1348;
          */
        }
        if ( get_frame() == 8 )
        {
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < -10 )
            field_7D4 = -10;
          if ( field_7D4 > 10 )
            field_7D4 = 10;
          play_sfx(2);
          spell_energy_spend(200, 60);
          field_190 = 1;
          /* 
          *(float *)&v2167 = (double)field_7D4;
          v2168 = 10.0;
          v2169 = 1.0;
          v2170 = 0.0;
          */
          add_card_energy(50);
          /*
          v419 = dir;
          v420 = y + 100.0;
          v421 = v420;
          v422 = (double)(48 * (char)v419) + x;
          addbullet(this, NULL,801, v422, v421, v419, 1, (int)&v2167, 4);
          */
        }
LABEL_1355:
        if ( get_subseq() == 1 && get_elaps_frames() >= 25 )
          goto LABEL_1849;
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
        {
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < -10 )
            field_7D4 = -10;
          if ( field_7D4 > 10 )
            field_7D4 = 10;
          play_sfx(2);
          spell_energy_spend(200, 60);
          field_190 = 1;
          /*
          *(float *)&v2175 = (double)field_7D4;
          v2176 = 10.0;
          v2177 = 1.0;
          v2178 = 1.0;
          */
          add_card_energy(50);
          /*
          v429 = dir;
          v430 = y + 100.0;
          v431 = v430;
          v432 = (double)(48 * (char)v429) + x;
          addbullet(this, NULL,801, v432, v431, v429, 1, (int)&v2175, 4);
          */
        }
        return;
      case 412:
        sub10func();
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 3 )
        {
          if ( !get_subseq() && get_frame() == 5 && !get_frame_time() )
          {
            spell_energy_spend(200, 60);
            field_190 = 1;
            add_card_energy(50);
            play_sfx(3);
            /*
            *(float *)&v1952 = 0.0;
            v1953 = 0.0;
            v1954 = 0.0;
            addbullet(this, NULL,808, x, y, dir, -1, (int)&v1952, 3);
            v1954 = 1.0;
            addbullet(this, NULL,808, x, y, dir, -1, (int)&v1952, 3);
            */
          }
          if ( get_subseq() == 1 && get_elaps_frames() > 20 )
            next_subseq();
        }
        else
        {
LABEL_675:
          set_seq(0);
        }
        return;
      case 414:
        if ( get_subseq() == 3 )
          sub10func();
        if ( !get_subseq() && get_frame() >= 8 || get_subseq() == 2 && get_frame() >= 4 )
        {
          v_force = 0.60000002;
          v_inerc = v_inerc - 0.6000000238418579;
          if ( char_on_ground_down() )
            goto LABEL_1387;
        }
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
          goto LABEL_1396;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1412;
        if ( get_frame() == 4 && not_charge_attack )
        {
          /*
          v1720 = dir;
          v435 = y + 128.0;
          ya = v435;
          v436 = x - (double)(34 * (char)v1720);
          v412 = v436;
          goto LABEL_1348;
          */
        }
        if ( get_frame() == 5 )
        {
          add_card_energy(50);
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < -10 )
            field_7D4 = -10;
          if ( field_7D4 > 10 )
            field_7D4 = 10;
          play_sfx(2);
          spell_energy_spend(200, 60);
          field_190 = 1;
          /*
          *(float *)&v2191 = (double)field_7D4;
          v2192 = 10.0;
          v2193 = 1.0;
          v2194 = 0.0;
          v442 = dir;
          v443 = y + 108.0;
          v444 = v443;
          v445 = (double)(62 * (char)v442) + x;
          addbullet(this, NULL,801, v445, v444, v442, 1, (int)&v2191, 4);
          */
        }
LABEL_1412:
        if ( get_subseq() == 1 && get_elaps_frames() >= 25 )
          goto LABEL_1849;
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
        {
          add_card_energy(50);
          field_7D4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7D4 < -10 )
            field_7D4 = -10;
          if ( field_7D4 > 10 )
            field_7D4 = 10;
          play_sfx(2);
          spell_energy_spend(200, 60);
          field_190 = 1;
          /*
          *(float *)&v2183 = (double)field_7D4;
          v2184 = 10.0;
          v2185 = 1.0;
          v2186 = 1.0;
          v452 = dir;
          v453 = y + 108.0;
          v454 = v453;
          v455 = (double)(62 * (char)v452) + x;
          addbullet(this, NULL,801, v455, v454, v452, 1, (int)&v2183, 4);
          */
        }
        return;
      case 416:
        if ( get_subseq() == 3 )
          sub10func();
        if ( !get_subseq() && get_frame() >= 4 || get_subseq() == 2 && get_frame() >= 1 )
        {
          v_force = 0.60000002;
          v_inerc = v_inerc - 0.6000000238418579;
          if ( char_on_ground_down() )
            goto LABEL_1429;
        }
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
          goto LABEL_1439;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1451;
        if ( get_frame() == 3 && not_charge_attack )
        {
          /*
          v1720 = dir;
          v458 = y + 197.0;
          ya = v458;
          v459 = (double)(14 * (char)v1720) + x;
          v412 = v459;
LABEL_1348:
          v413 = v412;
          scene_add_effect(this,62, v413, ya, v1720, 1);
          */
          next_subseq();
          return;
        }
        if ( get_frame() == 4 )
        {
          h_inerc = -5.0;
          v_inerc = 6.5;
          v_force = 0.60000002;
          field_7E4 = 45.0;
          play_sfx(2);
          spell_energy_spend(200, 60);
          field_190 = 1;
          add_card_energy(50);
          /*
          v2199 = SLODWORD(field_7E4);
          v2200 = 10.0;
          v2201 = 1.0;
          v2202 = 0.0;
          v460 = dir;
          v461 = y + 80.0;
          v462 = v461;
          v463 = (double)(55 * (char)v460) + x;
          addbullet(this, NULL,801, v463, v462, v460, 1, (int)&v2199, 4);
          */
        }
LABEL_1451:
        if ( get_subseq() != 1 || get_elaps_frames() < 25 )
        {
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
          {
            h_inerc = -5.0;
            v_inerc = 6.5;
            v_force = 0.60000002;
            field_7E4 = 45.0;
            play_sfx(2);
            spell_energy_spend(200, 60);
            field_190 = 1;
            add_card_energy(50);
            /*
            v2171 = SLODWORD(field_7E4);
            v2172 = 10.0;
            v2173 = 1.0;
            v2174 = 1.0;
            v465 = dir;
            v466 = y + 80.0;
            v467 = v466;
            v468 = (double)(55 * (char)v465) + x;
            addbullet(this, NULL,801, v468, v467, v465, 1, (int)&v2171, 4);
            */
          }
          return;
        }
        goto LABEL_1849;
      case 418:
        if ( !get_subseq() && get_frame() <= 2 || get_subseq() == 2 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( !char_on_ground_down() )
          goto LABEL_1464;
        if ( get_subseq() < 2 )
        {
          y = getlvl_height();
          v_force = 0.0;
          v_inerc = 0.0;
          set_subseq(2);
        }
LABEL_1464:
        if ( get_subseq() == 2 )
        {
          h_inerc = h_inerc - 1.0;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
        {
          v_inerc = 20.0;
          v_force = 1.75;
          scene_play_sfx(29);
        }
        return;
      case 500:
        sub10func();
        field_18C = 0;
        if ( get_subseq() <= 1 && !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(4);
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1903 = 20.0;
            v1904 = 15.0;
            v1905 = 0.0;
            v473 = dir;
            v474 = y + 96.0;
            v475 = v474;
            v476 = (double)(114 * (char)v473) + x;
            addbullet(this, NULL,810, v476, v475, v473, 1, (int)&v1903, 3);
            *(float *)&v1903 = -20.0;
            v1904 = 15.0;
            v1905 = 0.0;
            v477 = dir;
            v478 = y + 96.0;
            v479 = v478;
            v480 = (double)(114 * (char)v477) + x;
            addbullet(this, NULL,810, v480, v479, v477, 1, (int)&v1903, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            v481 = 20;
            v1747 = 20;
            do
            {
              *(float *)&v2017 = (double)v1747;
              v2018 = 15.0;
              v2019 = 0.0;
              v482 = dir;
              v483 = y + 96.0;
              v484 = v483;
              v485 = (double)(114 * (char)v482) + x;
              addbullet(this, NULL,810, v485, v484, v482, 1, (int)&v2017, 3);
              v481 += 20;
              v1747 = v481;
            }
            while ( v481 < 60 );
            v486 = -20;
            v1748 = -20;
            do
            {
              *(float *)&v2107 = (double)v1748;
              v2108 = 15.0;
              v2109 = 0.0;
              v487 = dir;
              v488 = y + 96.0;
              v489 = v488;
              v490 = (double)(114 * (char)v487) + x;
              addbullet(this, NULL,810, v490, v489, v487, 1, (int)&v2107, 3);
              v486 -= 20;
              v1748 = v486;
            }
            while ( v486 > -60 );
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            v491 = 20;
            v1749 = 20;
            do
            {
              *(float *)&v2023 = (double)v1749;
              v2024 = 15.0;
              v2025 = 0.0;
              v492 = dir;
              v493 = y + 96.0;
              v494 = v493;
              v495 = (double)(114 * (char)v492) + x;
              addbullet(this, NULL,810, v495, v494, v492, 1, (int)&v2023, 3);
              v491 += 20;
              v1749 = v491;
            }
            while ( v491 < 80 );
            v496 = -20;
            v1750 = -20;
            do
            {
              *(float *)&v2161 = (double)v1750;
              v2162 = 15.0;
              v2163 = 0.0;
              v497 = dir;
              v498 = y + 96.0;
              v499 = v498;
              v500 = (double)(114 * (char)v497) + x;
              addbullet(this, NULL,810, v500, v499, v497, 1, (int)&v2161, 3);
              v496 -= 20;
              v1750 = v496;
            }
            while ( v496 > -80 );
            */
          }
        }
        if ( process() )
          set_seq(0);
        if ( get_subseq() == 1 )
        {
          if ( get_elaps_frames() > (3 * (10 - skills_1[0])) && !field_7D6 )
          {
            field_7D6 = 1;
            scene_add_effect(this,62, (double)(65 * (char)dir) + x, y + 55.0, dir, 1);
          }
          if ( get_elaps_frames() > (3 * (10 - skills_1[0])) + 30 )
            not_charge_attack = 0;
          if ( !not_charge_attack && get_elaps_frames() >= 0 )
            next_subseq();
        }
        if ( get_subseq() != 3 )
          return;
        goto LABEL_1505;
      case 501:
        sub10func();
        field_18C = 0;
        if ( get_subseq() <= 1 && !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(4);
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1921 = 20.0;
            v1922 = 15.0;
            v1923 = 0.0;
            v507 = dir;
            v508 = y + 96.0;
            v509 = v508;
            v510 = (double)(114 * (char)v507) + x;
            addbullet(this, NULL,810, v510, v509, v507, 1, (int)&v1921, 3);
            *(float *)&v1921 = -20.0;
            v1922 = 15.0;
            v1923 = 0.0;
            v511 = dir;
            v512 = y + 96.0;
            v513 = v512;
            v514 = (double)(114 * (char)v511) + x;
            addbullet(this, NULL,810, v514, v513, v511, 1, (int)&v1921, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            v515 = 20;
            v1751 = 20;
            do
            {
              *(float *)&v2029 = (double)v1751;
              v2030 = 15.0;
              v2031 = 0.0;
              v516 = dir;
              v517 = y + 96.0;
              v518 = v517;
              v519 = (double)(114 * (char)v516) + x;
              addbullet(this, NULL,810, v519, v518, v516, 1, (int)&v2029, 3);
              v515 += 20;
              v1751 = v515;
            }
            while ( v515 < 60 );
            v520 = -20;
            v1752 = -20;
            do
            {
              *(float *)&v2113 = (double)v1752;
              v2114 = 15.0;
              v2115 = 0.0;
              v521 = dir;
              v522 = y + 96.0;
              v523 = v522;
              v524 = (double)(114 * (char)v521) + x;
              addbullet(this, NULL,810, v524, v523, v521, 1, (int)&v2113, 3);
              v520 -= 20;
              v1752 = v520;
            }
            while ( v520 > -60 );
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            v525 = 20;
            v1753 = 20;
            do
            {
              *(float *)&v2035 = (double)v1753;
              v2036 = 15.0;
              v2037 = 0.0;
              v526 = dir;
              v527 = y + 96.0;
              v528 = v527;
              v529 = (double)(114 * (char)v526) + x;
              addbullet(this, NULL,810, v529, v528, v526, 1, (int)&v2035, 3);
              v525 += 20;
              v1753 = v525;
            }
            while ( v525 < 80 );
            v530 = -20;
            v1754 = -20;
            do
            {
              *(float *)&v2140 = (double)v1754;
              v2141 = 15.0;
              v2142 = 0.0;
              v531 = dir;
              v532 = y + 96.0;
              v533 = v532;
              v534 = (double)(114 * (char)v531) + x;
              addbullet(this, NULL,810, v534, v533, v531, 1, (int)&v2140, 3);
              v530 -= 20;
              v1754 = v530;
            }
            while ( v530 > -80 );
            */
          }
        }
        if ( process() )
          set_seq(0);
        v535 = 1;
        if ( get_subseq() != 1 )
          goto LABEL_1538;
        if ( get_elaps_frames() > (3 * (10 - skills_1[0])) && !field_7D6 )
        {
          field_7D6 = 1;
          scene_add_effect(this,62, (double)(65 * (char)dir) + x, y + 55.0, dir, 1);
        }
        if ( get_elaps_frames() <= (3 * (10 - skills_1[0])) + 30 )
          goto LABEL_1534;

        field_7D6 = 2;
        /*
        v1721 = dir;
        v541 = y + 55.0;
        yb = v541;
        v542 = (double)(65 * (char)v1721) + x;
        v543 = v542;
        goto LABEL_1533;
        */
      case 502:
        if ( get_subseq() == 5 )
          sub10func();
        field_18C = 0;
        if ( get_subseq() <= 1 && !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( get_subseq() < 5 )
        {
          if ( get_subseq() == 4 )
          {
            v_force = 0.60000002;
            v_inerc = v_inerc - 0.6000000238418579;
          }
          if ( char_on_ground_down() )
            goto LABEL_1551;
        }
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(4);
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1909 = 20.0;
            v1910 = 15.0;
            v1911 = 0.0;
            v549 = dir;
            v550 = y + 108.0;
            v551 = v550;
            v552 = (double)(50 * (char)v549) + x;
            addbullet(this, NULL,810, v552, v551, v549, 1, (int)&v1909, 3);
            *(float *)&v1909 = -20.0;
            v1910 = 15.0;
            v1911 = 0.0;
            v553 = dir;
            v554 = y + 108.0;
            v555 = v554;
            v556 = (double)(50 * (char)v553) + x;
            addbullet(this, NULL,810, v556, v555, v553, 1, (int)&v1909, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            v557 = 20;
            v1755 = 20;
            do
            {
              *(float *)&v2041 = (double)v1755;
              v2042 = 15.0;
              v2043 = 0.0;
              v558 = dir;
              v559 = y + 108.0;
              v560 = v559;
              v561 = (double)(50 * (char)v558) + x;
              addbullet(this, NULL,810, v561, v560, v558, 1, (int)&v2041, 3);
              v557 += 20;
              v1755 = v557;
            }
            while ( v557 < 60 );
            v562 = -20;
            v1756 = -20;
            do
            {
              *(float *)&v2119 = (double)v1756;
              v2120 = 15.0;
              v2121 = 0.0;
              v563 = dir;
              v564 = y + 108.0;
              v565 = v564;
              v566 = (double)(50 * (char)v563) + x;
              addbullet(this, NULL,810, v566, v565, v563, 1, (int)&v2119, 3);
              v562 -= 20;
              v1756 = v562;
            }
            while ( v562 > -60 );
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            v567 = 20;
            v1757 = 20;
            do
            {
              *(float *)&v2047 = (double)v1757;
              v2048 = 15.0;
              v2049 = 0.0;
              v568 = dir;
              v569 = y + 108.0;
              v570 = v569;
              v571 = (double)(50 * (char)v568) + x;
              addbullet(this, NULL,810, v571, v570, v568, 1, (int)&v2047, 3);
              v567 += 20;
              v1757 = v567;
            }
            while ( v567 < 80 );
            v572 = -20;
            v1758 = -20;
            do
            {
              *(float *)&v2146 = (double)v1758;
              v2147 = 15.0;
              v2148 = 0.0;
              v573 = dir;
              v574 = y + 108.0;
              v575 = v574;
              v576 = (double)(50 * (char)v573) + x;
              addbullet(this, NULL,810, v576, v575, v573, 1, (int)&v2146, 3);
              v572 -= 20;
              v1758 = v572;
            }
            while ( v572 > -80 );
            */
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
          goto LABEL_1439;
        v535 = 1;
        if ( get_subseq() != 1 )
          goto LABEL_1538;
        if ( get_elaps_frames() > (3 * (10 - skills_1[0])) && !field_7D6 )
        {
          field_7D6 = 1;
          scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
        }
        if ( get_elaps_frames() > (3 * (10 - skills_1[0])) + 30 )
          not_charge_attack = 0;
        if ( not_charge_attack )
          goto LABEL_1538;
        /*
        v546 = 0;
        v545 = get_elaps_frames() < 0;
        goto LABEL_1536;
        */
        return; //TODO: change!
      case 503:
        if ( get_subseq() == 5 )
          sub10func();
        field_18C = 0;
        if ( get_subseq() <= 1 && !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( get_subseq() < 5 )
        {
          if ( get_subseq() == 4 )
          {
            v_force = 0.60000002;
            v_inerc = v_inerc - 0.6000000238418579;
          }
          if ( char_on_ground_down() )
          {
LABEL_1551:
            reset_forces();
            y = getlvl_height();
            set_subseq(5);
            return;
          }
        }
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(4);
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1930 = 20.0;
            v1931 = 15.0;
            v1932 = 0.0;
            v584 = dir;
            v585 = y + 108.0;
            v586 = v585;
            v587 = (double)(50 * (char)v584) + x;
            addbullet(this, NULL,810, v587, v586, v584, 1, (int)&v1930, 3);
            *(float *)&v1930 = -20.0;
            v1931 = 15.0;
            v1932 = 0.0;
            v588 = dir;
            v589 = y + 108.0;
            v590 = v589;
            v591 = (double)(50 * (char)v588) + x;
            addbullet(this, NULL,810, v591, v590, v588, 1, (int)&v1930, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            v592 = 20;
            v1759 = 20;
            do
            {
              *(float *)&v2053 = (double)v1759;
              v2054 = 15.0;
              v2055 = 0.0;
              v593 = dir;
              v594 = y + 108.0;
              v595 = v594;
              v596 = (double)(50 * (char)v593) + x;
              addbullet(this, NULL,810, v596, v595, v593, 1, (int)&v2053, 3);
              v592 += 20;
              v1759 = v592;
            }
            while ( v592 < 60 );
            v597 = -20;
            v1760 = -20;
            do
            {
              *(float *)&v2125 = (double)v1760;
              v2126 = 15.0;
              v2127 = 0.0;
              v598 = dir;
              v599 = y + 108.0;
              v600 = v599;
              v601 = (double)(50 * (char)v598) + x;
              addbullet(this, NULL,810, v601, v600, v598, 1, (int)&v2125, 3);
              v597 -= 20;
              v1760 = v597;
            }
            while ( v597 > -60 );
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            v602 = 20;
            v1761 = 20;
            do
            {
              *(float *)&v2059 = (double)v1761;
              v2060 = 15.0;
              v2061 = 0.0;
              v603 = dir;
              v604 = y + 108.0;
              v605 = v604;
              v606 = (double)(50 * (char)v603) + x;
              addbullet(this, NULL,810, v606, v605, v603, 1, (int)&v2059, 3);
              v602 += 20;
              v1761 = v602;
            }
            while ( v602 < 80 );
            v607 = -20;
            v1762 = -20;
            do
            {
              *(float *)&v2152 = (double)v1762;
              v2153 = 15.0;
              v2154 = 0.0;
              v608 = dir;
              v609 = y + 108.0;
              v610 = v609;
              v611 = (double)(50 * (char)v608) + x;
              addbullet(this, NULL,810, v611, v610, v608, 1, (int)&v2152, 3);
              v607 -= 20;
              v1762 = v607;
            }
            while ( v607 > -80 );
            */
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
          goto LABEL_1439;
        v535 = 1;
        if ( get_subseq() == 1 )
        {
          if ( get_elaps_frames() > (3 * (10 - skills_1[0])) && !field_7D6 )
          {
            field_7D6 = 1;
            scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
          }
          if ( get_elaps_frames() > (3 * (10 - skills_1[0])) + 30 )
          {
            field_7D6 = 2;
            /*
            v618 = y + 135.0;
            v1721 = dir;
            yb = v618;
            v619 = x - (double)(35 * (char)v1721);
            v543 = v619;
LABEL_1533:
            v544 = v543;
            scene_add_effect(this,62, v544, yb, v1721, 1);
            */
            not_charge_attack = 0;
          }
LABEL_1534:
          if ( !not_charge_attack )
          {
            /*
            v546 = __OFSUB__(get_elaps_frames(), 8);
            v545 = get_elaps_frames() - 8 < 0;
LABEL_1536:
            if ( !(v545 ^ v546) )
              */
LABEL_1537:
              next_subseq();
          }
        }
LABEL_1538:
        if ( get_subseq() == 3 )
        {
LABEL_1540:
          if ( get_elaps_frames() > 10 * (v535 + field_7D6) )
            next_subseq();
        }
        return;
      case 505:
        sub10func();
        field_18C = 4;
        if ( get_subseq() <= 1 && !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(2);
          //v1779 = skills_1[4] - 1.0;
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1844 = 10.0;
            v620 = v1779 + 23.0;
            v1845 = v620;
            v1846 = 0.0;
            v621 = dir;
            v622 = y + 96.0;
            v623 = v622;
            v624 = (double)(114 * (char)v621) + x;
            addbullet(this, NULL,811, v624, v623, v621, 1, (int)&v1844, 3);
            *(float *)&v1844 = 0.0;
            v1845 = v1779 + 25.0;
            v1846 = 0.0;
            v625 = dir;
            v626 = y + 96.0;
            v627 = v626;
            v628 = (double)(114 * (char)v625) + x;
            addbullet(this, NULL,811, v628, v627, v625, 1, (int)&v1844, 3);
            *(float *)&v1844 = -10.0;
            v1845 = v620;
            v1846 = 0.0;
            v629 = dir;
            v630 = y + 96.0;
            v631 = v630;
            v632 = (double)(114 * (char)v629) + x;
            addbullet(this, NULL,811, v632, v631, v629, 1, (int)&v1844, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            *(float *)&v1820 = 15.0;
            v633 = v1779 + 25.0;
            v1821 = v633;
            v1822 = 0.0;
            v634 = dir;
            v635 = y + 96.0;
            v636 = v635;
            v637 = (double)(114 * (char)v634) + x;
            addbullet(this, NULL,811, v637, v636, v634, 1, (int)&v1820, 3);
            *(float *)&v1820 = 5.0;
            v638 = v1779 + 27.0;
            v1821 = v638;
            v1822 = 0.0;
            v639 = dir;
            v640 = y + 96.0;
            v641 = v640;
            v642 = (double)(114 * (char)v639) + x;
            addbullet(this, NULL,811, v642, v641, v639, 1, (int)&v1820, 3);
            *(float *)&v1820 = -5.0;
            v1821 = v638;
            v1822 = 0.0;
            v643 = dir;
            v644 = y + 96.0;
            v645 = v644;
            v646 = (double)(114 * (char)v643) + x;
            addbullet(this, NULL,811, v646, v645, v643, 1, (int)&v1820, 3);
            *(float *)&v1820 = -15.0;
            v1821 = v633;
            v1822 = 0.0;
            v647 = dir;
            v648 = y + 96.0;
            v649 = v648;
            v650 = (double)(114 * (char)v647) + x;
            addbullet(this, NULL,811, v650, v649, v647, 1, (int)&v1820, 3);
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            *(float *)&v1799 = 20.0;
            v651 = v1779 + 26.0;
            v1800 = v651;
            v1801 = 0.0;
            v652 = dir;
            v653 = y + 96.0;
            v654 = v653;
            v655 = (double)(114 * (char)v652) + x;
            addbullet(this, NULL,811, v655, v654, v652, 1, (int)&v1799, 3);
            *(float *)&v1799 = 10.0;
            v656 = v1779 + 27.0;
            v1800 = v656;
            v1801 = 0.0;
            v657 = dir;
            v658 = y + 96.0;
            v659 = v658;
            v660 = (double)(114 * (char)v657) + x;
            addbullet(this, NULL,811, v660, v659, v657, 1, (int)&v1799, 3);
            *(float *)&v1799 = 0.0;
            v1800 = v1779 + 29.0;
            v1801 = 0.0;
            v661 = dir;
            v662 = y + 96.0;
            v663 = v662;
            v664 = (double)(114 * (char)v661) + x;
            addbullet(this, NULL,811, v664, v663, v661, 1, (int)&v1799, 3);
            *(float *)&v1799 = -10.0;
            v1800 = v656;
            v1801 = 0.0;
            v665 = dir;
            v666 = y + 96.0;
            v667 = v666;
            v668 = (double)(114 * (char)v665) + x;
            addbullet(this, NULL,811, v668, v667, v665, 1, (int)&v1799, 3);
            *(float *)&v1799 = -20.0;
            v1800 = v651;
            v1801 = 0.0;
            v669 = dir;
            v670 = y + 96.0;
            v671 = v670;
            v672 = (double)(114 * (char)v669) + x;
            addbullet(this, NULL,811, v672, v671, v669, 1, (int)&v1799, 3);
            */
          }
        }
        if ( process() )
          set_seq(0);
        if ( get_subseq() != 1 )
          goto LABEL_1640;
        if ( get_elaps_frames() > 20 && !field_7D6 )
        {
          field_7D6 = 1;
          scene_add_effect(this,62, (double)(65 * (char)dir) + x, y + 55.0, dir, 1);
        }
        if ( get_elaps_frames() <= 60 )
          goto LABEL_1638;

        field_7D6 = 2;
        /*
        v1722 = dir;
        v677 = y + 55.0;
        yc = v677;
        v678 = (double)(65 * (char)v1722) + x;
        v679 = v678;
        goto LABEL_1637;
        */
        return; //TODO: change!
      case 506:
        sub10func();
        field_18C = 4;
        if ( get_subseq() <= 1 && !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(2);
          //v1780 = skills_1[4] - 1.0;
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1838 = 10.0;
            v681 = v1780 + 28.0;
            v1839 = v681;
            v1840 = 0.0;
            v682 = dir;
            v683 = y + 96.0;
            v684 = v683;
            v685 = (double)(114 * (char)v682) + x;
            addbullet(this, NULL,811, v685, v684, v682, 1, (int)&v1838, 3);
            *(float *)&v1838 = 0.0;
            v1839 = v1780 + 30.0;
            v1840 = 0.0;
            v686 = dir;
            v687 = y + 96.0;
            v688 = v687;
            v689 = (double)(114 * (char)v686) + x;
            addbullet(this, NULL,811, v689, v688, v686, 1, (int)&v1838, 3);
            *(float *)&v1838 = -10.0;
            v1839 = v681;
            v1840 = 0.0;
            v690 = dir;
            v691 = y + 96.0;
            v692 = v691;
            v693 = (double)(114 * (char)v690) + x;
            addbullet(this, NULL,811, v693, v692, v690, 1, (int)&v1838, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            *(float *)&v1814 = 15.0;
            v1815 = v1780 + 30.0;
            v1816 = 0.0;
            v694 = dir;
            v695 = y + 96.0;
            v696 = v695;
            v697 = (double)(114 * (char)v694) + x;
            addbullet(this, NULL,811, v697, v696, v694, 1, (int)&v1814, 3);
            *(float *)&v1814 = 5.0;
            v698 = v1780 + 32.0;
            v1815 = v698;
            v1816 = 0.0;
            v699 = dir;
            v700 = y + 96.0;
            v701 = v700;
            v702 = (double)(114 * (char)v699) + x;
            addbullet(this, NULL,811, v702, v701, v699, 1, (int)&v1814, 3);
            *(float *)&v1814 = -5.0;
            v1815 = v698;
            v1816 = 0.0;
            v703 = dir;
            v704 = y + 96.0;
            v705 = v704;
            v706 = (double)(114 * (char)v703) + x;
            addbullet(this, NULL,811, v706, v705, v703, 1, (int)&v1814, 3);
            *(float *)&v1814 = -15.0;
            v1815 = 30.0;
            v1816 = 0.0;
            v707 = dir;
            v708 = y + 96.0;
            v709 = v708;
            v710 = (double)(114 * (char)v707) + x;
            addbullet(this, NULL,811, v710, v709, v707, 1, (int)&v1814, 3);
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            *(float *)&v1790 = 20.0;
            v711 = v1780 + 31.0;
            v1791 = v711;
            v1792 = 0.0;
            v712 = dir;
            v713 = y + 96.0;
            v714 = v713;
            v715 = (double)(114 * (char)v712) + x;
            addbullet(this, NULL,811, v715, v714, v712, 1, (int)&v1790, 3);
            *(float *)&v1790 = 10.0;
            v716 = v1780 + 32.0;
            v1791 = v716;
            v1792 = 0.0;
            v717 = dir;
            v718 = y + 96.0;
            v719 = v718;
            v720 = (double)(114 * (char)v717) + x;
            addbullet(this, NULL,811, v720, v719, v717, 1, (int)&v1790, 3);
            *(float *)&v1790 = 0.0;
            v1791 = v1780 + 34.0;
            v1792 = 0.0;
            v721 = dir;
            v722 = y + 96.0;
            v723 = v722;
            v724 = (double)(114 * (char)v721) + x;
            addbullet(this, NULL,811, v724, v723, v721, 1, (int)&v1790, 3);
            *(float *)&v1790 = -10.0;
            v1791 = v716;
            v1792 = 0.0;
            v725 = dir;
            v726 = y + 96.0;
            v727 = v726;
            v728 = (double)(114 * (char)v725) + x;
            addbullet(this, NULL,811, v728, v727, v725, 1, (int)&v1790, 3);
            *(float *)&v1790 = -20.0;
            v1791 = v711;
            v1792 = 0.0;
            v729 = dir;
            v730 = y + 96.0;
            v731 = v730;
            v732 = (double)(114 * (char)v729) + x;
            addbullet(this, NULL,811, v732, v731, v729, 1, (int)&v1790, 3);
            */
          }
        }
        if ( process() )
          set_seq(0);
        if ( get_subseq() == 1 )
        {
          if ( get_elaps_frames() > 20 && !field_7D6 )
          {
            field_7D6 = 1;
            scene_add_effect(this,62, (double)(65 * (char)dir) + x, y + 55.0, dir, 1);
          }
          if ( get_elaps_frames() > 60 )
          {
            field_7D6 = 2;
            scene_add_effect(this,62, (double)(65 * (char)dir) + x, y + 55.0, dir, 1);
            not_charge_attack = 0;
          }
          if ( !not_charge_attack && get_elaps_frames() >= 12 )
            goto LABEL_1639;
        }
        goto LABEL_1640;
      case 507:
        if ( get_subseq() == 5 )
          sub10func();
        field_18C = 4;
        if ( get_subseq() <= 1 && !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( get_subseq() < 5 )
        {
          if ( get_subseq() == 4 )
          {
            v_force = 0.60000002;
            v_inerc = v_inerc - 0.6000000238418579;
          }
          if ( char_on_ground_down() )
            goto LABEL_1674;
        }
        v535 = 2;
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(2);
          //v1781 = skills_1[4] - 1.0;
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1856 = 10.0;
            v742 = v1781 + 23.0;
            v1857 = v742;
            v1858 = 0.0;
            v743 = dir;
            v744 = y + 108.0;
            v745 = v744;
            v746 = (double)(50 * (char)v743) + x;
            addbullet(this, NULL,811, v746, v745, v743, 1, (int)&v1856, 3);
            *(float *)&v1856 = 0.0;
            v1857 = v1781 + 25.0;
            v1858 = 0.0;
            v747 = dir;
            v748 = y + 108.0;
            v749 = v748;
            v750 = (double)(50 * (char)v747) + x;
            addbullet(this, NULL,811, v750, v749, v747, 1, (int)&v1856, 3);
            *(float *)&v1856 = -10.0;
            v1857 = v742;
            v1858 = 0.0;
            v751 = dir;
            v752 = y + 108.0;
            v753 = v752;
            v754 = (double)(50 * (char)v751) + x;
            addbullet(this, NULL,811, v754, v753, v751, 1, (int)&v1856, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            *(float *)&v1832 = 15.0;
            v755 = v1781 + 25.0;
            v1833 = v755;
            v1834 = 0.0;
            v756 = dir;
            v757 = y + 108.0;
            v758 = v757;
            v759 = (double)(50 * (char)v756) + x;
            addbullet(this, NULL,811, v759, v758, v756, 1, (int)&v1832, 3);
            *(float *)&v1832 = 5.0;
            v760 = v1781 + 27.0;
            v1833 = v760;
            v1834 = 0.0;
            v761 = dir;
            v762 = y + 108.0;
            v763 = v762;
            v764 = (double)(50 * (char)v761) + x;
            addbullet(this, NULL,811, v764, v763, v761, 1, (int)&v1832, 3);
            *(float *)&v1832 = -5.0;
            v1833 = v760;
            v1834 = 0.0;
            v765 = dir;
            v766 = y + 108.0;
            v767 = v766;
            v768 = (double)(50 * (char)v765) + x;
            addbullet(this, NULL,811, v768, v767, v765, 1, (int)&v1832, 3);
            *(float *)&v1832 = -15.0;
            v1833 = v755;
            v1834 = 0.0;
            v769 = dir;
            v770 = y + 108.0;
            v771 = v770;
            v772 = (double)(50 * (char)v769) + x;
            addbullet(this, NULL,811, v772, v771, v769, 1, (int)&v1832, 3);
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            *(float *)&v1784 = 20.0;
            v773 = v1781 + 26.0;
            v1785 = v773;
            v1786 = 0.0;
            v774 = dir;
            v775 = y + 108.0;
            v776 = v775;
            v777 = (double)(50 * (char)v774) + x;
            addbullet(this, NULL,811, v777, v776, v774, 1, (int)&v1784, 3);
            *(float *)&v1784 = 10.0;
            v778 = v1781 + 27.0;
            v1785 = v778;
            v1786 = 0.0;
            v779 = dir;
            v780 = y + 108.0;
            v781 = v780;
            v782 = (double)(50 * (char)v779) + x;
            addbullet(this, NULL,811, v782, v781, v779, 1, (int)&v1784, 3);
            *(float *)&v1784 = 0.0;
            v1785 = v1781 + 29.0;
            v1786 = 0.0;
            v783 = dir;
            v784 = y + 108.0;
            v785 = v784;
            v786 = (double)(50 * (char)v783) + x;
            addbullet(this, NULL,811, v786, v785, v783, 1, (int)&v1784, 3);
            *(float *)&v1784 = -10.0;
            v1785 = v778;
            v1786 = 0.0;
            v787 = dir;
            v788 = y + 108.0;
            v789 = v788;
            v790 = (double)(50 * (char)v787) + x;
            addbullet(this, NULL,811, v790, v789, v787, 1, (int)&v1784, 3);
            *(float *)&v1784 = -20.0;
            v1785 = v773;
            v1786 = 0.0;
            v791 = dir;
            v792 = y + 108.0;
            v793 = v792;
            v794 = (double)(50 * (char)v791) + x;
            addbullet(this, NULL,811, v794, v793, v791, 1, (int)&v1784, 3);
            */
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
          goto LABEL_1439;
        if ( get_subseq() == 1 )
        {
          if ( get_elaps_frames() > 20 && !field_7D6 )
          {
            field_7D6 = 1;
            scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
          }
          if ( get_elaps_frames() > 60 )
          {
            field_7D6 = 2;
            scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
            not_charge_attack = 0;
          }
          if ( !not_charge_attack )
            goto LABEL_1537;
        }
        goto LABEL_1538;
      case 508:
        if ( get_subseq() == 5 )
          sub10func();
        field_18C = 4;
        if ( get_subseq() <= 1 && !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( get_subseq() < 5 )
        {
          if ( get_subseq() == 4 )
          {
            v_force = 0.60000002;
            v_inerc = v_inerc - 0.6000000238418579;
          }
          if ( char_on_ground_down() )
            goto LABEL_1674;
        }
        v535 = 2;
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(2);
          //v1782 = skills_1[4] - 1.0;
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1850 = 10.0;
            v805 = v1782 + 28.0;
            v1851 = v805;
            v1852 = 0.0;
            v806 = dir;
            v807 = y + 108.0;
            v808 = v807;
            v809 = (double)(50 * (char)v806) + x;
            addbullet(this, NULL,811, v809, v808, v806, 1, (int)&v1850, 3);
            *(float *)&v1850 = 0.0;
            v1851 = v1782 + 30.0;
            v1852 = 0.0;
            v810 = dir;
            v811 = y + 108.0;
            v812 = v811;
            v813 = (double)(50 * (char)v810) + x;
            addbullet(this, NULL,811, v813, v812, v810, 1, (int)&v1850, 3);
            *(float *)&v1850 = -10.0;
            v1851 = v805;
            v1852 = 0.0;
            v814 = dir;
            v815 = y + 108.0;
            v816 = v815;
            v817 = (double)(50 * (char)v814) + x;
            addbullet(this, NULL,811, v817, v816, v814, 1, (int)&v1850, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            *(float *)&v1826 = 15.0;
            v818 = v1782 + 30.0;
            v1827 = v818;
            v1828 = 0.0;
            v819 = dir;
            v820 = y + 108.0;
            v821 = v820;
            v822 = (double)(50 * (char)v819) + x;
            addbullet(this, NULL,811, v822, v821, v819, 1, (int)&v1826, 3);
            *(float *)&v1826 = 5.0;
            v823 = v1782 + 32.0;
            v1827 = v823;
            v1828 = 0.0;
            v824 = dir;
            v825 = y + 108.0;
            v826 = v825;
            v827 = (double)(50 * (char)v824) + x;
            addbullet(this, NULL,811, v827, v826, v824, 1, (int)&v1826, 3);
            *(float *)&v1826 = -5.0;
            v1827 = v823;
            v1828 = 0.0;
            v828 = dir;
            v829 = y + 108.0;
            v830 = v829;
            v831 = (double)(50 * (char)v828) + x;
            addbullet(this, NULL,811, v831, v830, v828, 1, (int)&v1826, 3);
            *(float *)&v1826 = -15.0;
            v1827 = v818;
            v1828 = 0.0;
            v832 = dir;
            v833 = y + 108.0;
            v834 = v833;
            v835 = (double)(50 * (char)v832) + x;
            addbullet(this, NULL,811, v835, v834, v832, 1, (int)&v1826, 3);
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            *(float *)&v1796 = 20.0;
            v836 = v1782 + 31.0;
            v1797 = v836;
            v1798 = 0.0;
            v837 = dir;
            v838 = y + 108.0;
            v839 = v838;
            v840 = (double)(50 * (char)v837) + x;
            addbullet(this, NULL,811, v840, v839, v837, 1, (int)&v1796, 3);
            *(float *)&v1796 = 10.0;
            v841 = v1782 + 32.0;
            v1797 = v841;
            v1798 = 0.0;
            v842 = dir;
            v843 = y + 108.0;
            v844 = v843;
            v845 = (double)(50 * (char)v842) + x;
            addbullet(this, NULL,811, v845, v844, v842, 1, (int)&v1796, 3);
            *(float *)&v1796 = 0.0;
            v1797 = v1782 + 34.0;
            v1798 = 0.0;
            v846 = dir;
            v847 = y + 108.0;
            v848 = v847;
            v849 = (double)(50 * (char)v846) + x;
            addbullet(this, NULL,811, v849, v848, v846, 1, (int)&v1796, 3);
            *(float *)&v1796 = -10.0;
            v1797 = v841;
            v1798 = 0.0;
            v850 = dir;
            v851 = y + 108.0;
            v852 = v851;
            v853 = (double)(50 * (char)v850) + x;
            addbullet(this, NULL,811, v853, v852, v850, 1, (int)&v1796, 3);
            *(float *)&v1796 = -20.0;
            v1797 = v836;
            v1798 = 0.0;
            v854 = dir;
            v855 = y + 108.0;
            v856 = v855;
            v857 = (double)(50 * (char)v854) + x;
            addbullet(this, NULL,811, v857, v856, v854, 1, (int)&v1796, 3);
            */
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
          goto LABEL_1439;
        if ( get_subseq() != 1 )
          goto LABEL_1538;
        if ( get_elaps_frames() > 20 && !field_7D6 )
        {
          field_7D6 = 1;
          scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
        }
        if ( get_elaps_frames() > 60 )
        {
          field_7D6 = 2;
          scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
          not_charge_attack = 0;
        }
        if ( not_charge_attack )
          goto LABEL_1538;
        /*
        v546 = __OFSUB__(get_elaps_frames(), 12);
        v545 = get_elaps_frames() - 12 < 0;
        goto LABEL_1536;
        */
        return; //TODO: change!
      case 510:
        sub10func();
        field_18C = 8;
        if ( get_subseq() <= 1 && !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(4);
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1915 = 20.0;
            v1916 = 15.0;
            v1917 = 0.0;
            v867 = dir;
            v868 = y + 96.0;
            v869 = v868;
            v870 = (double)(114 * (char)v867) + x;
            addbullet(this, NULL,812, v870, v869, v867, 1, (int)&v1915, 3);
            *(float *)&v1915 = -20.0;
            v1916 = 15.0;
            v1917 = 0.0;
            v871 = dir;
            v872 = y + 96.0;
            v873 = v872;
            v874 = (double)(114 * (char)v871) + x;
            addbullet(this, NULL,812, v874, v873, v871, 1, (int)&v1915, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            *(float *)&v1862 = 30.0;
            v1863 = 15.0;
            v1864 = 0.0;
            v875 = dir;
            v876 = y + 96.0;
            v877 = v876;
            v878 = (double)(114 * (char)v875) + x;
            addbullet(this, NULL,812, v878, v877, v875, 1, (int)&v1862, 3);
            *(float *)&v1862 = 0.0;
            v1863 = 15.0;
            v1864 = 0.0;
            v879 = dir;
            v880 = y + 96.0;
            v881 = v880;
            v882 = (double)(114 * (char)v879) + x;
            addbullet(this, NULL,812, v882, v881, v879, 1, (int)&v1862, 3);
            *(float *)&v1862 = -30.0;
            v1863 = 15.0;
            v1864 = 0.0;
            v883 = y + 96.0;
            v884 = v883;
            v885 = (double)(114 * dir) + x;
            addbullet(this, NULL,812, v885, v884, dir, 1, (int)&v1862, 3);
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            *(float *)&v1817 = 45.0;
            v1818 = 15.0;
            v1819 = 0.0;
            v886 = dir;
            v887 = y + 96.0;
            v888 = v887;
            v889 = (double)(114 * (char)v886) + x;
            addbullet(this, NULL,812, v889, v888, v886, 1, (int)&v1817, 3);
            *(float *)&v1817 = 15.0;
            v1818 = 15.0;
            v1819 = 0.0;
            v890 = dir;
            v891 = y + 96.0;
            v892 = v891;
            v893 = (double)(114 * (char)v890) + x;
            addbullet(this, NULL,812, v893, v892, v890, 1, (int)&v1817, 3);
            *(float *)&v1817 = -15.0;
            v1818 = 15.0;
            v1819 = 0.0;
            v894 = y + 96.0;
            v895 = v894;
            v896 = (double)(114 * dir) + x;
            addbullet(this, NULL,812, v896, v895, dir, 1, (int)&v1817, 3);
            *(float *)&v1817 = -45.0;
            v1818 = 15.0;
            v1819 = 0.0;
            v897 = dir;
            v898 = y + 96.0;
            v899 = v898;
            v900 = (double)(114 * (char)v897) + x;
            addbullet(this, NULL,812, v900, v899, v897, 1, (int)&v1817, 3);
            */
          }
        }
        if ( process() )
          set_seq(0);
        if ( get_subseq() == 1 )
        {
          if ( get_elaps_frames() > 20 && !field_7D6 )
          {
            field_7D6 = 1;
            scene_add_effect(this,62, (double)(65 * (char)dir) + x,  y + 55.0, dir, 1);
          }
          if ( get_elaps_frames() > 60 )
          {
            field_7D6 = 2;
            /*
            v1722 = dir;
            v905 = y + 55.0;
            yc = v905;
            v906 = (double)(65 * (char)v1722) + x;
            v679 = v906;
LABEL_1637:
            v680 = v679;
            scene_add_effect(this,62, v680, yc, v1722, 1);
            */
            not_charge_attack = 0;
          }
LABEL_1638:
          if ( !not_charge_attack )
            goto LABEL_1639;
        }
        goto LABEL_1640;
      case 511:
        sub10func();
        field_18C = 8;
        if ( get_subseq() <= 1 && !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(4);
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1841 = 30.0;
            v1842 = 15.0;
            v1843 = 0.0;
            v907 = dir;
            v908 = y + 96.0;
            v909 = v908;
            v910 = (double)(114 * (char)v907) + x;
            addbullet(this, NULL,812, v910, v909, v907, 1, (int)&v1841, 3);
            *(float *)&v1841 = 0.0;
            v1842 = 15.0;
            v1843 = 0.0;
            v911 = dir;
            v912 = y + 96.0;
            v913 = v912;
            v914 = (double)(114 * (char)v911) + x;
            addbullet(this, NULL,812, v914, v913, v911, 1, (int)&v1841, 3);
            *(float *)&v1841 = -30.0;
            v1842 = 15.0;
            v1843 = 0.0;
            v915 = y + 96.0;
            v916 = v915;
            v917 = (double)(114 * dir) + x;
            addbullet(this, NULL,812, v917, v916, dir, 1, (int)&v1841, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            *(float *)&v1823 = 45.0;
            v1824 = 15.0;
            v1825 = 0.0;
            v918 = dir;
            v919 = y + 96.0;
            v920 = v919;
            v921 = (double)(114 * (char)v918) + x;
            addbullet(this, NULL,812, v921, v920, v918, 1, (int)&v1823, 3);
            *(float *)&v1823 = 15.0;
            v1824 = 15.0;
            v1825 = 0.0;
            v922 = dir;
            v923 = y + 96.0;
            v924 = v923;
            v925 = (double)(114 * (char)v922) + x;
            addbullet(this, NULL,812, v925, v924, v922, 1, (int)&v1823, 3);
            *(float *)&v1823 = -15.0;
            v1824 = 15.0;
            v1825 = 0.0;
            v926 = y + 96.0;
            v927 = v926;
            v928 = (double)(114 * dir) + x;
            addbullet(this, NULL,812, v928, v927, dir, 1, (int)&v1823, 3);
            *(float *)&v1823 = -45.0;
            v1824 = 15.0;
            v1825 = 0.0;
            v929 = dir;
            v930 = y + 96.0;
            v931 = v930;
            v932 = (double)(114 * (char)v929) + x;
            addbullet(this, NULL,812, v932, v931, v929, 1, (int)&v1823, 3);
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            *(float *)&v1793 = 60.0;
            v1794 = 15.0;
            v1795 = 0.0;
            v933 = dir;
            v934 = y + 96.0;
            v935 = v934;
            v936 = (double)(114 * (char)v933) + x;
            addbullet(this, NULL,812, v936, v935, v933, 1, (int)&v1793, 3);
            *(float *)&v1793 = 30.0;
            v1794 = 15.0;
            v1795 = 0.0;
            v937 = dir;
            v938 = y + 96.0;
            v939 = v938;
            v940 = (double)(114 * (char)v937) + x;
            addbullet(this, NULL,812, v940, v939, v937, 1, (int)&v1793, 3);
            *(float *)&v1793 = 0.0;
            v1794 = 15.0;
            v1795 = 0.0;
            v941 = y + 96.0;
            v942 = v941;
            v943 = (double)(114 * dir) + x;
            addbullet(this, NULL,812, v943, v942, dir, 1, (int)&v1793, 3);
            *(float *)&v1793 = -30.0;
            v1794 = 15.0;
            v1795 = 0.0;
            v944 = dir;
            v945 = y + 96.0;
            v946 = v945;
            v947 = (double)(114 * (char)v944) + x;
            addbullet(this, NULL,812, v947, v946, v944, 1, (int)&v1793, 3);
            *(float *)&v1793 = -60.0;
            v1794 = 15.0;
            v1795 = 0.0;
            v948 = dir;
            v949 = y + 96.0;
            v950 = v949;
            v951 = (double)(114 * (char)v948) + x;
            addbullet(this, NULL,812, v951, v950, v948, 1, (int)&v1793, 3);
            */
          }
        }
        if ( process() )
          set_seq(0);
        if ( get_subseq() == 1 )
        {
          if ( get_elaps_frames() > 20 && !field_7D6 )
          {
            field_7D6 = 1;
            scene_add_effect(this,62, (double)(65 * (char)dir) + x, y + 55.0, dir, 1);
          }
          if ( get_elaps_frames() > 60 )
          {
            field_7D6 = 2;
            scene_add_effect(this,62, (double)(65 * (char)dir) + x, y + 55.0, dir, 1);
            not_charge_attack = 0;
          }
          if ( !not_charge_attack && get_elaps_frames() >= 8 )
LABEL_1639:
            next_subseq();
        }
LABEL_1640:
        if ( get_subseq() == 3 )
        {
LABEL_1505:
          if ( get_elaps_frames() > 10 * (field_7D6 + 1) )
            next_subseq();
        }
        return;
      case 512:
        if ( get_subseq() == 5 )
          sub10func();
        field_18C = 8;
        if ( get_subseq() <= 1 && !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( get_subseq() < 5 )
        {
          if ( get_subseq() == 4 )
          {
            v_force = 0.60000002;
            v_inerc = v_inerc - 0.6000000238418579;
          }
          if ( char_on_ground_down() )
            goto LABEL_1674;
        }
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(4);
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1927 = 20.0;
            v1928 = 15.0;
            v1929 = 0.0;
            v961 = dir;
            v962 = y + 108.0;
            v963 = v962;
            v964 = (double)(50 * (char)v961) + x;
            addbullet(this, NULL,812, v964, v963, v961, 1, (int)&v1927, 3);
            *(float *)&v1927 = -20.0;
            v1928 = 15.0;
            v1929 = 0.0;
            v965 = dir;
            v966 = y + 108.0;
            v967 = v966;
            v968 = (double)(50 * (char)v965) + x;
            addbullet(this, NULL,812, v968, v967, v965, 1, (int)&v1927, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            *(float *)&v1847 = 30.0;
            v1848 = 15.0;
            v1849 = 0.0;
            v969 = dir;
            v970 = y + 108.0;
            v971 = v970;
            v972 = (double)(50 * (char)v969) + x;
            addbullet(this, NULL,812, v972, v971, v969, 1, (int)&v1847, 3);
            *(float *)&v1847 = 0.0;
            v1848 = 15.0;
            v1849 = 0.0;
            v973 = dir;
            v974 = y + 108.0;
            v975 = v974;
            v976 = (double)(50 * (char)v973) + x;
            addbullet(this, NULL,812, v976, v975, v973, 1, (int)&v1847, 3);
            *(float *)&v1847 = -30.0;
            v1848 = 15.0;
            v1849 = 0.0;
            v977 = y + 108.0;
            v978 = v977;
            v979 = (double)(50 * dir) + x;
            addbullet(this, NULL,812, v979, v978, dir, 1, (int)&v1847, 3);
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            *(float *)&v1829 = 45.0;
            v1830 = 15.0;
            v1831 = 0.0;
            v980 = dir;
            v981 = y + 108.0;
            v982 = v981;
            v983 = (double)(50 * (char)v980) + x;
            addbullet(this, NULL,812, v983, v982, v980, 1, (int)&v1829, 3);
            *(float *)&v1829 = 15.0;
            v1830 = 15.0;
            v1831 = 0.0;
            v984 = dir;
            v985 = y + 108.0;
            v986 = v985;
            v987 = (double)(50 * (char)v984) + x;
            addbullet(this, NULL,812, v987, v986, v984, 1, (int)&v1829, 3);
            *(float *)&v1829 = -15.0;
            v1830 = 15.0;
            v1831 = 0.0;
            v988 = y + 108.0;
            v989 = v988;
            v990 = (double)(50 * dir) + x;
            addbullet(this, NULL,812, v990, v989, dir, 1, (int)&v1829, 3);
            *(float *)&v1829 = -45.0;
            v1830 = 15.0;
            v1831 = 0.0;
            v991 = dir;
            v992 = y + 108.0;
            v993 = v992;
            v994 = (double)(50 * (char)v991) + x;
            addbullet(this, NULL,812, v994, v993, v991, 1, (int)&v1829, 3);
            */
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
          goto LABEL_1439;
        if ( get_subseq() == 1 )
        {
          if ( get_elaps_frames() > 20 && !field_7D6 )
          {
            field_7D6 = 1;
            scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
          }
          if ( get_elaps_frames() > 60 )
          {
            field_7D6 = 2;
            scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
            not_charge_attack = 0;
          }
          if ( !not_charge_attack )
            goto LABEL_1804;
        }
        goto LABEL_1805;
      case 513:
        if ( get_subseq() == 5 )
          sub10func();
        field_18C = 8;
        if ( get_subseq() <= 1 && !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( get_subseq() < 5 )
        {
          if ( get_subseq() == 4 )
          {
            v_force = 0.60000002;
            v_inerc = v_inerc - 0.6000000238418579;
          }
          if ( char_on_ground_down() )
            goto LABEL_1674;
        }
        if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          play_sfx(4);
          if ( !field_7D6 )
          {
            /*
            *(float *)&v1853 = 30.0;
            v1854 = 15.0;
            v1855 = 0.0;
            v1005 = dir;
            v1006 = y + 108.0;
            v1007 = v1006;
            v1008 = (double)(50 * (char)v1005) + x;
            addbullet(this, NULL,812, v1008, v1007, v1005, 1, (int)&v1853, 3);
            *(float *)&v1853 = 0.0;
            v1854 = 15.0;
            v1855 = 0.0;
            v1009 = dir;
            v1010 = y + 108.0;
            v1011 = v1010;
            v1012 = (double)(50 * (char)v1009) + x;
            addbullet(this, NULL,812, v1012, v1011, v1009, 1, (int)&v1853, 3);
            *(float *)&v1853 = -30.0;
            v1854 = 15.0;
            v1855 = 0.0;
            v1013 = y + 108.0;
            v1014 = v1013;
            v1015 = (double)(50 * dir) + x;
            addbullet(this, NULL,812, v1015, v1014, dir, 1, (int)&v1853, 3);
            */
          }
          if ( field_7D6 == 1 )
          {
            /*
            *(float *)&v1835 = 45.0;
            v1836 = 15.0;
            v1837 = 0.0;
            v1016 = dir;
            v1017 = y + 108.0;
            v1018 = v1017;
            v1019 = (double)(50 * (char)v1016) + x;
            addbullet(this, NULL,812, v1019, v1018, v1016, 1, (int)&v1835, 3);
            *(float *)&v1835 = 15.0;
            v1836 = 15.0;
            v1837 = 0.0;
            v1020 = dir;
            v1021 = y + 108.0;
            v1022 = v1021;
            v1023 = (double)(50 * (char)v1020) + x;
            addbullet(this, NULL,812, v1023, v1022, v1020, 1, (int)&v1835, 3);
            *(float *)&v1835 = -15.0;
            v1836 = 15.0;
            v1837 = 0.0;
            v1024 = y + 108.0;
            v1025 = v1024;
            v1026 = (double)(50 * dir) + x;
            addbullet(this, NULL,812, v1026, v1025, dir, 1, (int)&v1835, 3);
            *(float *)&v1835 = -45.0;
            v1836 = 15.0;
            v1837 = 0.0;
            v1027 = dir;
            v1028 = y + 108.0;
            v1029 = v1028;
            v1030 = (double)(50 * (char)v1027) + x;
            addbullet(this, NULL,812, v1030, v1029, v1027, 1, (int)&v1835, 3);
            */
          }
          if ( field_7D6 == 2 )
          {
            /*
            *(float *)&v1787 = 60.0;
            v1788 = 15.0;
            v1789 = 0.0;
            v1031 = dir;
            v1032 = y + 108.0;
            v1033 = v1032;
            v1034 = (double)(50 * (char)v1031) + x;
            addbullet(this, NULL,812, v1034, v1033, v1031, 1, (int)&v1787, 3);
            *(float *)&v1787 = 30.0;
            v1788 = 15.0;
            v1789 = 0.0;
            v1035 = dir;
            v1036 = y + 108.0;
            v1037 = v1036;
            v1038 = (double)(50 * (char)v1035) + x;
            addbullet(this, NULL,812, v1038, v1037, v1035, 1, (int)&v1787, 3);
            *(float *)&v1787 = 0.0;
            v1788 = 15.0;
            v1789 = 0.0;
            v1039 = y + 108.0;
            v1040 = v1039;
            v1041 = (double)(50 * dir) + x;
            addbullet(this, NULL,812, v1041, v1040, dir, 1, (int)&v1787, 3);
            *(float *)&v1787 = -30.0;
            v1788 = 15.0;
            v1789 = 0.0;
            v1042 = dir;
            v1043 = y + 108.0;
            v1044 = v1043;
            v1045 = (double)(50 * (char)v1042) + x;
            addbullet(this, NULL,812, v1045, v1044, v1042, 1, (int)&v1787, 3);
            *(float *)&v1787 = -60.0;
            v1788 = 15.0;
            v1789 = 0.0;
            v1046 = dir;
            v1047 = y + 108.0;
            v1048 = v1047;
            v1049 = (double)(50 * (char)v1046) + x;
            addbullet(this, NULL,812, v1049, v1048, v1046, 1, (int)&v1787, 3);
            */
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
          goto LABEL_1439;
        if ( get_subseq() == 1 )
        {
          if ( get_elaps_frames() > 20 && !field_7D6 )
          {
            field_7D6 = 1;
            scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
          }
          if ( get_elaps_frames() > 60 )
          {
            field_7D6 = 2;
            scene_add_effect(this,62, x - (double)(35 * (char)dir), y + 135.0, dir, 1);
            not_charge_attack = 0;
          }
          if ( !not_charge_attack && get_elaps_frames() >= 8 )
LABEL_1804:
            next_subseq();
        }
LABEL_1805:
        if ( get_subseq() != 3 )
          return;
        goto LABEL_1540;
      case 520:
        sub10func();
        field_18C = 1;
        if ( get_subseq() != 3 || get_elaps_frames() )
          goto LABEL_1844;
        spell_energy_spend(200, 120);
        field_190 = 1;
        add_card_energy(50);
        /*
        *(float *)&v1802 = 0.0;
        v1803 = 12.0;
        v1804 = 0.0;
        v1059 = dir;
        v1060 = y + 96.0;
        v1061 = v1060;
        v1062 = (double)(114 * (char)v1059) + x;
        addbullet(this, NULL,815, v1062, v1061, v1059, 1, (int)&v1802, 3);
        *(float *)&v1802 = atan2_deg(135.0, 135.0);
        v1063 = sqrt(37825.0) / 15.0;
        v1803 = v1063;
        v1804 = 2.0;
        v1064 = dir;
        v1065 = y + 96.0;
        v1066 = v1065;
        v1067 = (double)(114 * (char)v1064) + x;
        addbullet(this, NULL,815, v1067, v1066, v1064, 1, (int)&v1802, 3);
        *(float *)&v1802 = atan2_deg(-135.0, 135.0);
        v1803 = v1063;
        v1068 = dir;
        v1069 = y + 96.0;
        v1070 = v1069;
        v1071 = (double)(114 * (char)v1068) + x;
        addbullet(this, NULL,815, v1071, v1070, v1068, 1, (int)&v1802, 3);
        *(float *)&v1802 = atan2_deg(-115.0, 225.0);
        v1072 = sqrt(65025.0) / 15.0;
        v1803 = v1072;
        v1073 = dir;
        v1074 = y + 96.0;
        v1075 = v1074;
        v1076 = (double)(114 * (char)v1073) + x;
        addbullet(this, NULL,815, v1076, v1075, v1073, 1, (int)&v1802, 3);
        *(float *)&v1802 = atan2_deg(115.0, 225.0);
        v1803 = v1072;
        v1723 = &v1802;
        xa = dir;
        v1077 = y + 96.0;
        v1702 = v1077;
        v1078 = (double)(114 * (char)xa) + x;
        v1079 = v1078;
        goto LABEL_1843;
        */
        return; //TODO: change!
      case 521:
        sub10func();
        field_18C = 1;
        if ( get_subseq() == 3 && !get_elaps_frames() )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          /*
          *(float *)&v1808 = 0.0;
          v1809 = 25.0;
          v1810 = 0.0;
          v1083 = dir;
          v1084 = y + 96.0;
          v1085 = v1084;
          v1086 = (double)(114 * (char)v1083) + x;
          addbullet(this, NULL,815, v1086, v1085, v1083, 1, (int)&v1808, 3);
          *(float *)&v1808 = atan2_deg(135.0, 330.0);
          v1087 = sqrt(128500.0) / 15.0;
          v1809 = v1087;
          v1810 = 2.0;
          v1088 = dir;
          v1089 = y + 96.0;
          v1090 = v1089;
          v1091 = (double)(114 * (char)v1088) + x;
          addbullet(this, NULL,815, v1091, v1090, v1088, 1, (int)&v1808, 3);
          *(float *)&v1808 = atan2_deg(-135.0, 330.0);
          v1809 = v1087;
          v1092 = dir;
          v1093 = y + 96.0;
          v1094 = v1093;
          v1095 = (double)(114 * (char)v1092) + x;
          addbullet(this, NULL,815, v1095, v1094, v1092, 1, (int)&v1808, 3);
          *(float *)&v1808 = atan2_deg(-115.0, 420.0);
          v1096 = sqrt(190800.0) / 15.0;
          v1809 = v1096;
          v1097 = dir;
          v1098 = y + 96.0;
          v1099 = v1098;
          v1100 = (double)(114 * (char)v1097) + x;
          addbullet(this, NULL,815, v1100, v1099, v1097, 1, (int)&v1808, 3);
          *(float *)&v1808 = atan2_deg(115.0, 420.0);
          v1809 = v1096;
          v1723 = &v1808;
          xa = dir;
          v1101 = y + 96.0;
          v1702 = v1101;
          v1102 = (double)(114 * (char)xa) + x;
          v1079 = v1102;
LABEL_1843:
          v1080 = v1079;
          addbullet(this, NULL,815, v1080, v1702, xa, 1, (int)v1723, 3);
          */
          play_sfx(21);
        }
LABEL_1844:
        if ( process() )
          set_seq(0);
        if ( get_subseq() != 1 )
          return;
        goto LABEL_1848;
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
          if ( char_on_ground_down() )
            goto LABEL_1859;
        }
        if ( get_subseq() == 3 && !get_elaps_frames() )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          /*
          *(float *)&v1805 = 0.0;
          v1806 = 12.0;
          v1807 = 0.0;
          v1104 = dir;
          v1105 = y + 107.0;
          v1106 = v1105;
          v1107 = (double)(43 * (char)v1104) + x;
          addbullet(this, NULL,815, v1107, v1106, v1104, 1, (int)&v1805, 3);
          *(float *)&v1805 = atan2_deg(135.0, 135.0);
          v1108 = sqrt(37825.0) / 15.0;
          v1806 = v1108;
          v1807 = 2.0;
          v1109 = dir;
          v1110 = y + 107.0;
          v1111 = v1110;
          v1112 = (double)(43 * (char)v1109) + x;
          addbullet(this, NULL,815, v1112, v1111, v1109, 1, (int)&v1805, 3);
          *(float *)&v1805 = atan2_deg(-135.0, 135.0);
          v1806 = v1108;
          v1113 = dir;
          v1114 = y + 107.0;
          v1115 = v1114;
          v1116 = (double)(43 * (char)v1113) + x;
          addbullet(this, NULL,815, v1116, v1115, v1113, 1, (int)&v1805, 3);
          *(float *)&v1805 = atan2_deg(-115.0, 225.0);
          v1117 = sqrt(65025.0) / 15.0;
          v1806 = v1117;
          v1118 = dir;
          v1119 = y + 107.0;
          v1120 = v1119;
          v1121 = (double)(43 * (char)v1118) + x;
          addbullet(this, NULL,815, v1121, v1120, v1118, 1, (int)&v1805, 3);
          *(float *)&v1805 = atan2_deg(115.0, 225.0);
          v1806 = v1117;
          v1122 = dir;
          v1123 = y + 107.0;
          v1124 = v1123;
          v1125 = (double)(43 * (char)v1122) + x;
          addbullet(this, NULL,815, v1125, v1124, v1122, 1, (int)&v1805, 3);
          */
          play_sfx(21);
        }
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 5 )
          goto LABEL_1869;
        goto LABEL_1439;
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
          if ( char_on_ground_down() )
            goto LABEL_1859;
        }
        if ( get_subseq() == 3 && !get_elaps_frames() )
        {
          spell_energy_spend(200, 120);
          field_190 = 1;
          add_card_energy(50);
          /*
          *(float *)&v1811 = 0.0;
          v1812 = 25.0;
          v1813 = 0.0;
          v1128 = dir;
          v1129 = y + 107.0;
          v1130 = v1129;
          v1131 = (double)(43 * (char)v1128) + x;
          addbullet(this, NULL,815, v1131, v1130, v1128, 1, (int)&v1811, 3);
          *(float *)&v1811 = atan2_deg(135.0, 330.0);
          v1132 = sqrt(128500.0) / 15.0;
          v1812 = v1132;
          v1813 = 2.0;
          v1133 = dir;
          v1134 = y + 107.0;
          v1135 = v1134;
          v1136 = (double)(43 * (char)v1133) + x;
          addbullet(this, NULL,815, v1136, v1135, v1133, 1, (int)&v1811, 3);
          *(float *)&v1811 = atan2_deg(-135.0, 330.0);
          v1812 = v1132;
          v1137 = dir;
          v1138 = y + 107.0;
          v1139 = v1138;
          v1140 = (double)(43 * (char)v1137) + x;
          addbullet(this, NULL,815, v1140, v1139, v1137, 1, (int)&v1811, 3);
          *(float *)&v1811 = atan2_deg(-115.0, 420.0);
          v1141 = sqrt(190800.0) / 15.0;
          v1812 = v1141;
          v1142 = dir;
          v1143 = y + 107.0;
          v1144 = v1143;
          v1145 = (double)(43 * (char)v1142) + x;
          addbullet(this, NULL,815, v1145, v1144, v1142, 1, (int)&v1811, 3);
          *(float *)&v1811 = atan2_deg(115.0, 420.0);
          v1812 = v1141;
          v1146 = dir;
          v1147 = y + 107.0;
          v1148 = v1147;
          v1149 = (double)(43 * (char)v1146) + x;
          addbullet(this, NULL,815, v1149, v1148, v1146, 1, (int)&v1811, 3);
          */
          play_sfx(21);
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
        {
          set_seq(9);
          return;
        }
LABEL_1869:
        if ( get_subseq() == 1 )
        {
LABEL_1848:
          if ( !(get_elaps_frames() < 0 | get_elaps_frames() == 0) )
            goto LABEL_1849;
        }
        return;
      case 525:
        sub10func();
        field_18C = 5;
        if ( get_subseq() == 1 && get_elaps_frames() > 10 || get_subseq() == 2 && get_elaps_frames() > 50 )
          goto LABEL_1849;
        if ( process() )
          set_seq(0);
        if ( get_subseq() || get_frame_time() || get_frame() != 7 )
          return;
        spell_energy_spend(200, 120);
        add_card_energy(50);
        field_190 = 1;
        /*
        *(float *)&v1877 = 0.0;
        v1878 = 0.0;
        v1879 = 0.0;
        v1151 = dir;
        v1152 = enemy;
        v1153 = v1152->y + 125.0;
        v1154 = v1153;
        v1155 = v1152->x - (double)(50 * (char)v1151);
        addbullet(this, NULL,816, v1155, v1154, v1151, 1, (int)&v1877, 3);
        v1156 = dir;
        v1157 = enemy;
        v1158 = v1157->y + 125.0;
        v1159 = v1158;
        v1160 = (double)(50 * v1156) + v1157->x;
        addbullet(this, NULL,816, v1160, v1159, -v1156, 1, (int)&v1877, 3);
        if ( skills_1[5] < 4 )
          goto LABEL_1900;
        *(float *)&v1877 = 90.0;
        v1878 = 30.0;
        v1879 = 4.0;
        v1161 = enemy;
        v1162 = v1161->y + 50.0;
        addbullet(this, NULL,816, v1161->x, v1162, dir, 1, (int)&v1877, 3);
        *(float *)&v1877 = -90.0;
        v1163 = enemy;
        v1164 = &v1877;
        v1165 = v1163->y + 150.0;
        v1166 = v1165;
        goto LABEL_1898;
        */
        return; //TODO: change!
      case 526:
        sub10func();
        field_18C = 5;
        if ( get_subseq() == 1 && get_elaps_frames() > 10 || get_subseq() == 2 && get_elaps_frames() > 50 )
          goto LABEL_1849;
        if ( process() )
          set_seq(0);
        if ( get_subseq() || get_frame_time() || get_frame() != 7 )
          return;
        spell_energy_spend(200, 120);
        add_card_energy(50);
        field_190 = 1;
        /*
        *(float *)&v1868 = 90.0;
        v1869 = 30.0;
        v1870 = 4.0;
        v1170 = enemy;
        v1171 = v1170->y + 50.0;
        addbullet(this, NULL,816, v1170->x, v1171, dir, 1, (int)&v1868, 3);
        *(float *)&v1868 = -90.0;
        v1172 = enemy;
        v1173 = v1172->y + 150.0;
        addbullet(this, NULL,816, v1172->x, v1173, dir, 1, (int)&v1868, 3);
        if ( skills_1[5] < 4 )
          goto LABEL_1900;
        *(float *)&v1868 = 0.0;
        v1869 = 0.0;
        v1870 = 0.0;
        v1174 = enemy;
        v1175 = dir;
        v1176 = v1174->y + 125.0;
        v1177 = v1176;
        v1178 = v1174->x - (double)(50 * (char)v1175);
        addbullet(this, NULL,816, v1178, v1177, v1175, 1, (int)&v1868, 3);
        v1179 = dir;
        v1180 = enemy;
        v1724 = &v1868;
        v1181 = v1180->y + 125.0;
        xb = -v1179;
        v1703 = v1181;
        v1182 = (double)(50 * v1179) + v1180->x;
        v1167 = v1182;
        goto LABEL_1899;
        */
        return; //TODO: change!
      case 527:
        if ( get_subseq() == 4 )
        {
          sub10func();
        }
        else
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_1920;
        }
        field_18C = 5;
        if ( get_subseq() == 1 && get_elaps_frames() > 10 )
          goto LABEL_992;
        if ( get_subseq() == 2 && get_elaps_frames() > 50 )
          goto LABEL_1918;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
          goto LABEL_1396;
        if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
        {
          spell_energy_spend(200, 120);
          add_card_energy(50);
          field_190 = 1;
          /*
          *(float *)&v1874 = 0.0;
          v1875 = 0.0;
          v1876 = 0.0;
          v1185 = dir;
          v1186 = enemy;
          v1187 = v1186->y + 125.0;
          v1188 = v1187;
          v1189 = v1186->x - (double)(50 * (char)v1185);
          addbullet(this, NULL,816, v1189, v1188, v1185, 1, (int)&v1874, 3);
          v1190 = dir;
          v1191 = enemy;
          v1192 = v1191->y + 125.0;
          v1193 = v1192;
          v1194 = (double)(50 * v1190) + v1191->x;
          addbullet(this, NULL,816, v1194, v1193, -v1190, 1, (int)&v1874, 3);
          if ( skills_1[5] >= 4 )
          {
            *(float *)&v1874 = 90.0;
            v1875 = 30.0;
            v1876 = 4.0;
            v1195 = enemy;
            v1196 = v1195->y + 50.0;
            addbullet(this, NULL,816, v1195->x, v1196, dir, 1, (int)&v1874, 3);
            *(float *)&v1874 = -90.0;
            v1163 = enemy;
            v1164 = &v1874;
            v1197 = v1163->y + 150.0;
            v1166 = v1197;
LABEL_1898:
            v1724 = v1164;
            xb = dir;
            v1703 = v1166;
            v1167 = v1163->x;
LABEL_1899:
            v1168 = v1167;
            addbullet(this, NULL,816, v1168, v1703, xb, 1, (int)v1724, 3);
          }
          */
LABEL_1900:
          play_sfx(5);
        }
        return;
      case 528:
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
        if ( get_subseq() == 1 && get_elaps_frames() > 10 )
          goto LABEL_1849;
        if ( get_subseq() == 2 && get_elaps_frames() > 50 )
          goto LABEL_1938;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
          goto LABEL_1439;
        if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
        {
          spell_energy_spend(200, 120);
          add_card_energy(50);
          field_190 = 1;
          /*
          *(float *)&v1871 = 90.0;
          v1872 = 30.0;
          v1873 = 4.0;
          v1200 = enemy;
          v1201 = v1200->y + 50.0;
          addbullet(this, NULL,816, v1200->x, v1201, dir, 1, (int)&v1871, 3);
          *(float *)&v1871 = -90.0;
          v1202 = enemy;
          v1203 = v1202->y + 150.0;
          addbullet(this, NULL,816, v1202->x, v1203, dir, 1, (int)&v1871, 3);
          if ( skills_1[5] >= 4 )
          {
            *(float *)&v1871 = 0.0;
            v1872 = 0.0;
            v1873 = 0.0;
            v1204 = enemy;
            v1205 = dir;
            v1206 = v1204->y + 125.0;
            v1207 = v1206;
            v1208 = v1204->x - (double)(50 * (char)v1205);
            addbullet(this, NULL,816, v1208, v1207, v1205, 1, (int)&v1871, 3);
            v1209 = dir;
            v1210 = enemy;
            v1211 = v1210->y + 125.0;
            v1212 = v1211;
            v1213 = (double)(50 * v1209) + v1210->x;
            addbullet(this, NULL,816, v1213, v1212, -v1209, 1, (int)&v1871, 3);
          }
          */
          play_sfx(5);
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
          v_force = 0.5;
        return;
      case 530:
        sub10func();
        field_18C = 9;
        if ( get_subseq() == 1 && get_elaps_frames() >= 18 )
          goto LABEL_992;
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          return;
        spell_energy_spend(200, 120);
        add_card_energy(50);
        field_190 = 1;
        /*
        *(float *)&v2065 = 0.0;
        v2066 = 0.0;
        v2067 = 0.0;
        v1725 = &v2065;
        xc = dir;
        v1214 = y - 10.0;
        v1704 = v1214;
        v1215 = (double)(10 * (char)xc) + x;
        v1216 = v1215;
        goto LABEL_1967;
        */
        return; //TODO: change!
      case 531:
        sub10func();
        field_18C = 9;
        if ( get_subseq() == 1 && get_elaps_frames() >= 18 )
          goto LABEL_1849;
        if ( process() )
          set_seq(2);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          spell_energy_spend(200, 120);
          add_card_energy(50);
          field_190 = 1;
          /*
          v2131 = 0.0;
          v2132 = 20.0;
          v1725 = (int *)&v2131;
          v2133 = 9.0;
          xc = dir;
          v1218 = y - 10.0;
          v1704 = v1218;
          v1219 = (double)(50 * dir) + x;
          v1216 = v1219;
LABEL_1967:
          v1217 = v1216;
          addbullet(this, NULL,817, v1217, v1704, xc, -1, (int)v1725, 3);
          */
          play_sfx(15);
        }
        return;
      case 540:
        if ( get_subseq() == 4 )
        {
          sub10func();
          
        }
        field_18C = 2;
        if ( !get_subseq() )
        {
          if ( !get_frame_time() && get_frame() == 4 )
          {
            x_off = 0.0;
            y_off = 100.0;
            scaleX = 1.0;
            scaleY = 1.0;
           //color_a = -1;
           //color_G = -1;
           //color_G = -1;
           //color_b = -1;
            play_sfx(6);
            
          }
          if ( get_frame() > 3 )
          {
            if ( scaleX > 0.0 )
            {
              scaleX = scaleX - 0.1000000014901161;
              scaleY = scaleY + 0.2000000029802322;
            }
            /*
            v1220 =//color_a;
            if ( v1220 > 0x19u )
             //color_a = v1220 - 25;
            */
          }
        }
        if ( get_subseq() == 2 )
        {
          if ( get_frame() < 5 )
          {
            if ( 1.0 <= scaleX )
            {
              scaleX = 1.0;
              scaleY = 1.0;
             //color_a = -1;
            }
            else
            {
              scaleX = scaleX + 0.1000000014901161;
              scaleY = scaleY - 0.2000000029802322;
             //color_a += 25;
            }
          }
          if ( get_frame() < 7 )
            v_inerc = v_inerc - 0.699999988079071;
        }
        if ( get_subseq() == 3 && char_on_ground_down() )
        {
          y = getlvl_height();
          reset_forces();
          next_subseq();
        }
        else
        {
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
              spell_energy_spend(200, 120);
              x = enemy->x - (double)(180 * dir);
              y = 200.0;
              h_inerc = 6.0;
              v_inerc = 8.0;
              play_sfx(6);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            {
              /*
              *(float *)&v2071 = 0.0;
              v2072 = 0.0;
              v2073 = 3.0;
              addbullet(this, NULL,820, x, y, dir, 1, (int)&v2071, 3);
              */
            }
          }
          if ( get_subseq() == 2 )
          {
            if ( get_frame() == 5 && ((skills_1[2] >= 1) && get_frame_time() >= 4 || skills_1[2] >= 3 && get_frame_time() >= 2) )
            {
              next_frame();
            }
            else if ( get_frame() == 7 && !get_frame_time() )
            {
              h_inerc = 7.5;
              v_inerc = -24.0;
              add_card_energy(50);
            }
          }
        }
        return;
      case 541:
        if ( get_subseq() == 3 || get_subseq() == 4 || get_subseq() == 5 )
        {
          sub10func();
          
        }
        field_18C = 2;
        if ( !get_subseq() )
        {
          if ( !get_frame_time() && get_frame() == 4 )
          {
            x_off = 0.0;
            y_off = 100.0;
            scaleX = 1.0;
            scaleY = 1.0;
           //color_a = -1;
           //color_G = -1;
           //color_G = -1;
           //color_b = -1;
            play_sfx(6);
            
          }
          if ( get_frame() > 3 )
          {
            if ( scaleX > 0.0 )
            {
              scaleX = scaleX - 0.1000000014901161;
              scaleY = scaleY + 0.2000000029802322;
            }
            /*
            v1223 =//color_a;
            if ( v1223 > 0x19u )
             //color_a = v1223 - 25;
            */
          }
        }
        if ( get_subseq() == 2 )
        {
          v_inerc = v_inerc - 1.0;
          if ( 1.0 <= scaleX )
          {
            scaleX = 1.0;
            scaleY = 1.0;
           //color_a = -1;
          }
          else
          {
            scaleX = scaleX + 0.1000000014901161;
            scaleY = scaleY - 0.2000000029802322;
           //color_a += 25;
          }
          if ( char_on_ground_down() )
          {
            scaleX = 1.0;
            scaleY = 1.0;
            //color_A = -1;
            y = getlvl_height();
            v_inerc = 0.0;
            set_subseq(3);
            /*
            *(float *)&v2158 = 0.0;
            v2159 = 0.0;
            v2160 = 0.0;
            */
            addbullet(this, NULL,820, x, y, dir, 1, 0, 3);

          }
        }
        if ( get_subseq() == 3 )
        {
          if ( field_190 )
          {
            if ( ++field_7D4 > 5 )
            {
              field_190 = 0;
              field_7D4 = 0;
            }
          }
          if ( get_elaps_frames() >= 8 )
          {
            next_subseq();
            field_194 = 1;
          }
        }
        if ( get_subseq() == 4 )
        {
          if ( field_190 )
          {
            if ( ++field_7D4 > 5 )
            {
              field_190 = 0;
              field_7D4 = 0;
            }
          }
        }
        if ( get_subseq() > 3 )
        {
          h_inerc = h_inerc - 0.800000011920929;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          spell_energy_spend(200, 120);
          x = (double)(100 * dir) + x;
          y = 50.0;
          h_inerc = 12.5;
          v_inerc = 6.0;
          play_sfx(6);
          add_card_energy(50);
        }
        return;
      case 545:
        if ( get_subseq() == 6 )
        {
          sub10func();
          
        }
        field_18C = 6;
        if ( !get_subseq() )
        {
          if ( !get_frame_time() && get_frame() == 4 )
          {
            x_off = 0.0;
            y_off = 100.0;
            scaleX = 1.0;
            scaleY = 1.0;
           //color_a = -1;
           //color_G = -1;
           //color_G = -1;
           //color_b = -1;
            play_sfx(6);
            
          }
          if ( get_frame() > 3 )
          {
            if ( scaleX > 0.0 )
            {
              scaleX = scaleX - 0.1000000014901161;
              scaleY = scaleY + 0.2000000029802322;
            }
            /*
            v1226 =//color_a;
            if ( v1226 > 0x19u )
             //color_a = v1226 - 25;
              */
          }
        }
        if ( get_subseq() == 2 && get_frame() < 5 )
        {
          if ( 1.0 <= scaleX )
          {
            scaleX = 1.0;
            scaleY = 1.0;
           //color_a = -1;
          }
          else
          {
            scaleX = scaleX + 0.1000000014901161;
            scaleY = scaleY - 0.2000000029802322;
           //color_a += 25;
          }
        }
        if ( get_subseq() >= 2 && get_subseq() <= 5 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_2078;
        }
        if ( get_subseq() != 3 )
          goto LABEL_2085;
        if ( get_elaps_frames() >= 8 )
          goto LABEL_992;
        if ( get_elaps_frames() == 6 && skills_1[6] >= 2 )
        {
          play_sfx(14);
          /*
          v1229 = 0;
          v1735 = 0;
          do
          {
            a4 = (double)v1735 * 9.0 + 30.0;
            v1969 = 25.0;
            v1970 = 0.0;
            v1230 = dir;
            v1231 = -a4;
            v1232 = sin_deg(v1231) * 50.0 + y + 100.0;
            v1233 = v1232;
            v1234 = -a4;
            v1235 = cos_deg(v1234) * (double)(50 * dir) + x;
            addbullet(this, NULL,821, v1235, v1233, v1230, 1, (int)&a4, 3);
            v1735 = ++v1229;
          }
          while ( v1229 <= 5 );
          */
        }
LABEL_2085:
        if ( get_subseq() == 4 && get_elaps_frames() == 4 && skills_1[6] >= 4 )
        {
          play_sfx(14);
          /*
          v1236 = 0;
          v1736 = 0;
          do
          {
            a1a = (double)v1736 * 9.0 + 30.0;
            v1959 = 25.0;
            v1960 = 0.0;
            v1237 = dir;
            v1238 = -a1a;
            v1239 = sin_deg(v1238) * 50.0 + y + 100.0;
            v1240 = v1239;
            v1241 = -a1a;
            v1242 = cos_deg(v1241) * (double)(50 * dir) + x;
            addbullet(this, NULL,821, v1242, v1240, v1237, 1, (int)&a1a, 3);
            v1736 = ++v1236;
          }
          while ( v1236 <= 5 );
          */
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
          {
            spell_energy_spend(200, 120);
            y = y + 150.0;
            if ( y > 350.0 )
              y = 350.0;
            h_inerc = 5.0;
            v_inerc = 10.0;
            v_force = 0.5;
            play_sfx(6);
            /*
            *(float *)&v2077 = 0.0;
            v2078 = 0.0;
            v2079 = 3.0;
            v1244 = y + 100.0;
            addbullet(this, NULL,821, x, v1244, dir, -1, (int)&v2077, 3);
            */
          }
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
            {
              play_sfx(14);
              add_card_energy(50);
              /*
              v1245 = 0;
              v1737 = 0;
              do
              {
                *(float *)&v1883 = (double)v1737 * 9.0 + 30.0;
                v1884 = 25.0;
                v1885 = 0.0;
                v1246 = dir;
                v1247 = -*(float *)&v1883;
                v1248 = sin_deg(v1247) * 50.0 + y + 100.0;
                v1249 = v1248;
                v1250 = -*(float *)&v1883;
                v1251 = cos_deg(v1250) * (double)(50 * dir) + x;
                addbullet(this, NULL,821, v1251, v1249, v1246, 1, (int)&v1883, 3);
                v1737 = ++v1245;
              }
              while ( v1245 <= 5 );
              *(float *)&v1883 = 0.0;
              v1884 = 0.0;
              v1885 = 4.0;
              v1252 = y + 100.0;
              addbullet(this, NULL,821, x, v1252, dir, 1, (int)&v1883, 3);
              */
              field_190 = 1;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
              set_seq(9);
          }
        }
        return;
      case 546:
        if ( get_subseq() == 6 )
        {
          sub10func();
          
        }
        field_18C = 6;
        if ( !get_subseq() )
        {
          if ( !get_frame_time() && get_frame() == 4 )
          {
            x_off = 0.0;
            y_off = 100.0;
            scaleX = 1.0;
            scaleY = 1.0;
           //color_a = -1;
           //color_G = -1;
           //color_G = -1;
           //color_b = -1;
            play_sfx(6);
            
          }
          if ( get_frame() > 3 )
          {
            /*
            if ( scaleX > 0.0 )
            {
              scaleX = scaleX - 0.1000000014901161;
              scaleY = scaleY + 0.2000000029802322;
            }
            v1253 =//color_a;
            if ( v1253 > 0x19u )
             //color_a = v1253 - 25;
              */
          }
        }
        if ( get_subseq() == 2 && get_frame() < 5 )
        {
          /*
          if ( 1.0 <= scaleX )
          {
            scaleX = 1.0;
            scaleY = 1.0;
           //color_a = -1;
          }
          else
          {
            scaleX = scaleX + 0.1000000014901161;
            scaleY = scaleY - 0.2000000029802322;
           //color_a += 25;
          }
          */
        }
        if ( get_subseq() >= 2 && get_subseq() <= 5 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_2078:
            y = getlvl_height();
            reset_forces();
            set_subseq(6);
            return;
          }
        }
        if ( get_subseq() != 3 )
          goto LABEL_2136;
        if ( get_elaps_frames() >= 8 )
          goto LABEL_992;
        if ( get_elaps_frames() == 6 && skills_1[6] >= 3 )
        {
          play_sfx(14);
          /*
          v1256 = 0;
          v1738 = 0;
          do
          {
            *(float *)&v1942 = 40.0 - (double)v1738 * 9.0;
            v1943 = 25.0;
            v1944 = 0.0;
            v1257 = dir;
            v1258 = -*(float *)&v1942;
            v1259 = sin_deg(v1258) * 50.0 + y + 100.0;
            v1260 = v1259;
            v1261 = -*(float *)&v1942;
            v1262 = cos_deg(v1261) * (double)(50 * dir) + x;
            addbullet(this, NULL,821, v1262, v1260, v1257, 1, (int)&v1942, 3);
            v1738 = ++v1256;
          }
          while ( v1256 <= 5 );
          */
        }
LABEL_2136:
        if ( get_subseq() == 4 && get_elaps_frames() == 4 && skills_1[6] >= 4 )
        {
          play_sfx(14);
          /*
          v1263 = 0;
          v1739 = 0;
          do
          {
            *(float *)&v1945 = 40.0 - (double)v1739 * 9.0;
            v1946 = 25.0;
            v1947 = 0.0;
            v1264 = dir;
            v1265 = -*(float *)&v1945;
            v1266 = sin_deg(v1265) * 50.0 + y + 100.0;
            v1267 = v1266;
            v1268 = -*(float *)&v1945;
            v1269 = cos_deg(v1268) * (double)(50 * dir) + x;
            addbullet(this, NULL,821, v1269, v1267, v1264, 1, (int)&v1945, 3);
            v1739 = ++v1263;
          }
          while ( v1263 <= 5 );
          */
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
          {
            spell_energy_spend(200, 120);
            x = x - (double)(320 * dir);
            y = y + 150.0;
            if ( y > 350.0 )
              y = 350.0;
            h_inerc = -5.0;
            v_inerc = 10.0;
            v_force = 0.5;
            play_sfx(6);
            /*
            *(float *)&v2137 = 0.0;
            v2138 = 0.0;
            v2139 = 3.0;
            v1271 = y + 100.0;
            addbullet(this, NULL,821, x, v1271, dir, -1, (int)&v2137, 3);
            */
          }
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
            {
              play_sfx(14);
              add_card_energy(50);
              /*
              v1272 = 0;
              v1740 = 0;
              do
              {
                *(float *)&v1886 = 40.0 - (double)v1740 * 9.0;
                v1887 = 25.0;
                v1888 = 0.0;
                v1273 = dir;
                v1274 = -*(float *)&v1886;
                v1275 = sin_deg(v1274) * 50.0 + y + 100.0;
                v1276 = v1275;
                v1277 = -*(float *)&v1886;
                v1278 = cos_deg(v1277) * (double)(50 * dir) + x;
                addbullet(this, NULL,821, v1278, v1276, v1273, 1, (int)&v1886, 3);
                v1740 = ++v1272;
              }
              while ( v1272 <= 5 );
              *(float *)&v1886 = 0.0;
              v1887 = 0.0;
              v1888 = 4.0;
              v1279 = y + 100.0;
              addbullet(this, NULL,821, x, v1279, dir, 1, (int)&v1886, 3);
              */
              field_190 = 1;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
              set_seq(9);
          }
        }
        return;
      case 550:
      case 551:
        field_18C = 10;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
          h_inerc = -2.0;
        switch ( sq )
        {
          case 0:
            sub10func();
            if ( field_190 != 3 )
              goto LABEL_2187;
            field_190 = 0;
            next_subseq();
            play_sfx(18);
            return;
          case 1:
            if ( !(get_frame_time() % 3) )
            {
              if ( get_frame_time() <= 9 )
              {
                /*
                v1983 = 0.0;
                v1984 = 4.0;
                v1985 = 0.0;
                v1763 = 0.0;
                do
                {
                  *(float *)&v1982 = (double)get_MT_range(45) + v1763 * 45.0;
                  v1281 = dir;
                  v1282 = sin_deg(*(float *)&v1982) * (double)(20 * get_frame_time()) + y + 100.0;
                  v1283 = v1282;
                  v1284 = cos_deg(*(float *)&v1982) * (double)(20 * get_frame_time()) * (double)dir + x;
                  addbullet(this, NULL,822, v1284, v1283, v1281, 1, (int)&v1982, 4);
                  v1763 = v1763 + 1.0;
                }
                while ( v1763 < 8.0 );
                */
              }
              if ( !get_frame_time() )
              {
                /*
                v2181 = 0.0;
                v1783 = 0.0;
                v1285 = 90.0;
                v1286 = (float)0.0;
                while ( 1 )
                {
                  v1764 = 0.0;
                  v1287 = v1286 * 72.0;
                  *(float *)&v1742 = v1287 - v1285 + 162.0;
                  v1741 = v1285 - v1287;
                  for ( k = (float)0.0; ; k = v1764 )
                  {
                    v2179 = v1742;
                    v2180 = 18.0 * k + 8.0;
                    v2182 = k + 30.0;
                    v1289 = dir;
                    v1290 = sin_deg(v1741) * 250.0 + y + 100.0;
                    v1291 = v1290;
                    v1292 = cos_deg(v1741) * 250.0 * (double)dir + x;
                    addbullet(this, NULL,822, v1292, v1291, v1289, 1, (int)&v2179, 4);
                    v1764 = v1764 + 1.0;
                    if ( v1764 >= 5.0 )
                      break;
                  }
                  v1783 = v1783 + 1.0;
                  if ( v1783 >= 5.0 )
                    break;
                  v1286 = v1783;
                  v1285 = 90.0;
                }
                */
              }
            }
            goto LABEL_2187;
          case 2:
          case 3:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_seq(10);
              y = getlvl_height();
              reset_forces();
              //color_A = -1;
              return;
            }
            /*
            v1293 =//color_a;
            if ( v1293 >= 0xF5u )
             //color_a = -1;
            else
             //color_a = v1293 + 10;
            */
LABEL_2187:
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_2197;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_115;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
              h_inerc = -200.0;
              y = y + 100.0;
              v_inerc = 2.0;
              //color_A = 0;
              v_force = 0.5;
            }
LABEL_2197:
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
            }
            break;
          default:
            goto LABEL_2187;
        }
        return;
      default:
        goto LABEL_3210;
    }
  }
  if ( !get_subseq() || get_subseq() == 3 )
    sub10func();
  if ( !get_subseq() && skills_1[3] >= 4 )
    field_51C = 2;
  field_18C = 3;
  if ( get_subseq() == 1 || get_subseq() == 2 )
    v_inerc = v_inerc - v_force;
  if ( char_on_ground_down() && get_subseq() < 3 )
  {
LABEL_1387:
    reset_forces();
LABEL_445:
    y = getlvl_height();
    set_subseq(3);
  }
  else
  {
    if ( process() )
      set_seq(0);
    if ( !get_frame_time() && get_frame() == 3 && !get_subseq() )
    {
      /*
      *(float *)&v2083 = 0.0;
      v2084 = 12.0;
      v2085 = 0.0;
      addbullet(this, NULL,825, x, y, dir, 1, (int)&v2083, 3);
      */
      play_sfx(7);
    }
    if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
    {
      spell_energy_spend(200, 120);
      add_card_energy(50);
      h_inerc = 4.5;
      v_inerc = 14.0;
      v_force = 0.75;
    }
  }
}

//note: taken from alice.cpp
void char_reimu::func20()
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


void char_reimu::set_seq_params()
{
  double v4 = 0.0;
  double v5 = 0.0;
  int v7 = 0;
  double v40 = 0.0;

  if ( get_seq() <= 300 )
  {
    if ( get_seq() == 300 )
    {
LABEL_37:
      if ( !field_49A )
        reset_forces();
      field_190 = 0;
      field_8B8 = 0;
      field_194 = 1;
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
          field_571 = 1;
          field_572 = 1;
          field_7D0 = 0;
          h_inerc = -field_1A4;
          v_inerc = field_1A8;
          v_force = 0.80000001;
          if ( -field_1A4 > 0.0 )
            field_7D0 = 1;
          if ( -field_1A4 < 0.0 )
            field_7D0 = -1;
          angZ = 0.0;
          return;
        case 71:
          h_inerc = -field_1A4;
          v4 = field_1A8;
          goto LABEL_12;
        case 72:
          field_571 = 1;
          h_inerc = -field_1A4;
          field_572 = 1;
          v_inerc = field_1A8;
          v_force = 1.3;
          angZ = 0.0;
          return;
        case 73:
        case 88:
          h_inerc = -field_1A4;
          v_inerc = field_1A8;
          v5 = 0.80000001;
          goto LABEL_13;
        case 74:
        case 75:
          h_inerc = -field_1A4;
          v_inerc = field_1A8;
          v5 = 0.80000001;
          goto LABEL_14;
        case 76:
          field_571 = 1;
          field_572 = 1;
          weather_forecast_next();
          v7 = 5;
          do
          {
            scene_add_effect(this, 201, x, y + 100.0, dir, 1);
            --v7;
          }
          while ( v7 );
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
          return;
        case 77:
          field_571 = 1;
          h_inerc = field_1A4;
          field_572 = 1;
          x_delta = 0;
          v_inerc = field_1A8;
          y_delta = 85;
          v_force = 0.80000001;
          x_off = 0.0;
          y_off = 85.0;
          angZ = 0.0;
          return;
        case 78:
          field_571 = 1;
          field_572 = 1;
          weather_forecast_next();
          v7 = 5;
          do
          {
            scene_add_effect(this, 201, x, y + 100.0, dir, 1);
            --v7;
          }
          while ( v7 );
          ++field_7D0;
          h_inerc = 0.0;
          v_inerc = 0.0;
          v_force = 0.0;
          //shake_camera(4.0);
          scene_play_sfx(22);
          scene_add_effect(this, 38, x - (double)(50 * (char)dir), y + 100.0, dir, 1);
          scene_add_effect(this, 59, x - (double)(50 * (char)dir), y + 100.0, dir, 1);
          angZ = 0.0;
          return;
        case 89:
          field_571 = 1;
          field_572 = 1;
          weather_forecast_next();
          v7 = 5;
          do
          {
            scene_add_effect(this, 201, x, y + 100.0, dir, 1);
            --v7;
          }
          while ( v7 );
          if ( !field_890 )
          {
            x = dir;
            field_890 = 1;
            addbullet(this, NULL, 951, x, y, x, 1, 0, 0);
          }
          scene_add_effect(this, 58, x, 0.0, dir, -1);
          angZ = 0.0;
          return;
        case 145:
          h_inerc = -10.0;
          v4 = 14.0;
LABEL_12:
          v_inerc = v4;
          v5 = 0.5;
LABEL_13:
          field_7D0 = 7;
LABEL_14:
          v_force = v5;
          field_572 = 1;
          angZ = 0.0;
          field_571 = 1;
          return;
        case 149:
          field_571 = 1;
          field_572 = 1;
          x_off = (double)x_delta;
          y_off = (double)y_delta;
          h_inerc = -3.0;
          v_inerc = 17.5;
          v_force = 0.5;
          return;
        case 214:
          break;
        case 217:
          reset_ofs();
          break;
        default:
          goto LABEL_100;
      }
      h_inerc = 0.0;
      field_7D6 = 0;
      v_inerc = 0.0;
      v_force = 0.60000002;
      x_off = 0.0;
      y_off = 95.0;
      field_7DC = 10.0;
      field_7EC = 0.0;
    }
    return;
  }
  if ( get_seq() > 561 )
  {
    switch ( get_seq() )
    {
      case 565:
      case 566:
        h_inerc = 0.0;
        v_inerc = 0.0;
        field_7D0 = 0;
        field_7D2 = 0;
        v_force = 0.0;
        field_7D4 = 0;
        field_49A = 0;
        field_190 = 0;
        field_8B8 = 0;
        field_18C = 7;
        field_194 = 1;
        not_charge_attack = 1;
        return;
      case 570:
      case 571:
      case 572:
      case 573:
        field_18C = 11;
        reset_forces();
        field_190 = 0;
        field_8B8 = 1;
        not_charge_attack = 1;
        return;
      case 600:
      case 601:
      case 602:
      case 605:
      case 606:
        goto LABEL_87;
      case 604:
        goto LABEL_88;
      case 607:
      case 657:
        field_7DC = 0.0;
LABEL_72:
        field_190 = 0;
        reset_forces();
        field_8B8 = 1;
        return;
      case 608:
      case 658:
        field_7D4 = 0;
        goto LABEL_87;
      case 609:
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D8 = 0;
        field_190 = 1;
        reset_forces();
        sub_469450(0, 0, 60);
        sub_483570();
        weather_forecast_next();
        field_4A6 = 40;
        scene_play_sfx(23);
        scene_add_effect(this, 115, (double)(24 * (char)dir) + x, y + 144.0, dir, 1);
        field_8B8 = 1;
        return;
      case 610:
        field_7D0 = 0;
        field_7D2 = 0;
        field_190 = 1;
        reset_forces();
        sub_469450(0, 0, 60);
        sub_483570();
        weather_forecast_next();
        field_4A6 = 40;
        scene_play_sfx(23);
        scene_add_effect(this, 115, (double)(24 * (char)dir) + x, y + 144.0, dir, 1);
        field_8B8 = 1;
        return;
      case 612:
        reset_forces();
        field_190 = 0;
        field_49A = 0;
        field_194 = 5;
        field_8B8 = 1;
        return;
      case 614:
        h_inerc = 0.0;
        v_inerc = 0.0;
        field_7D0 = 0;
        field_190 = 0;
        v_force = 0.0;
        field_8B8 = 0;
        return;
      case 616:
        reset_forces();
        field_7DC = 0.0;
        field_190 = 0;
        field_49A = 0;
        field_194 = 5;
        field_8B8 = 1;
        return;
      case 619:
        reset_forces();
        field_7DC = 0.0;
        field_8B4 = 0;
        field_8B6 = 0;
LABEL_44:
        field_49A = 0;
        field_190 = 0;
        field_8B8 = 0;
        return;
      case 650:
      case 651:
        field_7D0 = 0;
        field_7D2 = 0;
        field_190 = 1;
        reset_forces();
        field_8B8 = 1;
        v_force = 0.25;
        return;
      case 669:
        field_7DC = 0.0;
        field_7D4 = 0;
LABEL_87:
        field_7D0 = 0;
        field_7D2 = 0;
LABEL_88:
        field_190 = 1;
        reset_forces();
        field_8B8 = 1;
        return;
      case 695:
      case 696:
      case 697:
      case 698:
        field_8B8 = 0;
        goto LABEL_100;
      case 710:
      case 711:
      case 730:
      case 731:
      case 740:
        reset_forces();
        goto LABEL_103;
      case 720:
      case 721:
        reset_forces();
        return;
      case 760:
        reset_forces();
        field_7D0 = 0;
        sub_4685C0(-1);
        field_6F5 = 1;
        sub_46AB50(6, -1);
        health_to_max();
        scene_play_sfx(23);
        return;
      case 797:
LABEL_103:
        field_7D0 = 0;
        return;
      case 798:
        reset_forces();
        h_inerc = 12.0;
        field_7D0 = 0;
        v_inerc = 0.0;
        v_force = 0.5;
        return;
      default:
        goto LABEL_100;
    }
    goto LABEL_100;
  }
  if ( get_seq() < 560 )
  {
    switch ( get_seq() )
    {
      case 301:
      case 320:
      case 330:
        goto LABEL_37;
      case 302:
        if ( !field_49A )
          reset_forces();
        goto LABEL_42;
      case 303:
        if ( !field_49A )
          reset_forces();
        field_190 = 0;
        field_8B8 = 0;
        field_194 = 6;
        return;
      case 304:
        reset_forces();
LABEL_42:
        not_charge_attack = 1;
        goto LABEL_43;
      case 305:
        h_inerc = 15.0;
        goto LABEL_50;
      case 306:
        goto LABEL_52;
      case 307:
        reset_forces();
LABEL_52:
        field_7D0 = 0;
        field_190 = 0;
        field_8B8 = 0;
        field_194 = 1;
        return;
      case 308:
      case 309:
        field_190 = 0;
        field_8B8 = 0;
        field_194 = 1;
        return;
      case 310:
        h_inerc = 15.0;
        field_7D0 = 0;
        v_force = 0.5;
        field_190 = 0;
        field_8B8 = 0;
        x_off = 0.0;
        field_194 = 3;
        y_off = 105.0;
        return;
      case 321:
        goto LABEL_43;
      case 322:
        if ( field_49A )
        {
LABEL_50:
          field_7D8 = 0;
        }
        else
        {
          reset_forces();
          field_7D8 = 0;
        }
        goto LABEL_43;
      case 400:
      case 401:
      case 410:
      case 412:
        field_190 = 0;
        reset_forces();
        goto LABEL_58;
      case 402:
        field_190 = 0;
        reset_forces();
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        field_7D8 = 0;
        field_8B8 = 1;
        return;
      case 404:
      case 406:
        v_force = 0.0;
        field_7D4 = 0;
        v40 = 0.2000000029802322;
        goto LABEL_64;
      case 408:
        h_inerc = 14.0;
        v_inerc = 0.0;
        v_force = 0.0;
        goto LABEL_43;
      case 414:
      case 416:
        v40 = 0.25;
LABEL_64:
        field_190 = 0;
        h_inerc = h_inerc * v40;
        v_inerc = v40 * v_inerc;
LABEL_58:
        field_7D8 = 0;
        goto LABEL_59;
      case 418:
        h_inerc = 8.5;
        v_inerc = 0.0;
        v_force = 0.0;
        goto LABEL_43;
      case 500:
      case 501:
        field_18C = 0;
        field_190 = 0;
        reset_forces();
        goto LABEL_59;
      case 502:
      case 503:
      case 512:
      case 513:
        field_18C = 0;
        field_190 = 0;
        h_inerc = h_inerc * 0.25;
        v_inerc = 0.25 * v_inerc;
        goto LABEL_59;
      case 505:
      case 506:
        field_18C = 4;
        field_190 = 0;
        reset_forces();
        goto LABEL_59;
      case 507:
      case 508:
        field_18C = 4;
        field_190 = 0;
        h_inerc = h_inerc * 0.25;
        v_inerc = 0.25 * v_inerc;
        goto LABEL_59;
      case 510:
      case 511:
        field_18C = 8;
        field_190 = 0;
        reset_forces();
LABEL_59:
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        not_charge_attack = 1;
        field_8B8 = 1;
        return;
      case 520:
      case 521:
        field_18C = 1;
        goto LABEL_72;
      case 522:
      case 523:
        field_18C = 1;
        field_190 = 0;
        field_8B8 = 1;
        h_inerc = h_inerc * 0.25;
        v_inerc = 0.25 * v_inerc;
        return;
      case 525:
      case 526:
        field_18C = 5;
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D8 = 0;
        field_190 = 0;
        reset_forces();
        field_8B8 = 1;
        return;
      case 527:
      case 528:
        v_force = 0.0;
        h_inerc = h_inerc * 0.1000000014901161;
        field_18C = 5;
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D8 = 0;
        v_inerc = 0.1000000014901161 * v_inerc;
        field_190 = 0;
        field_8B8 = 1;
        /*
        *(float *)&a7 = 0.0;
        v58 = 0.0;
        v59 = 8.0;
        */
        addbullet(this, NULL, 816, x, y, dir, -1, 0, 3);
        return;
      case 530:
      case 531:
        field_18C = 9;
        goto LABEL_72;
      case 540:
        field_18C = 2;
        reset_forces();
LABEL_43:
        field_194 = 1;
        goto LABEL_44;
      case 541:
        field_18C = 2;
        reset_forces();
        field_194 = 99;
        field_7D0 = 0;
        field_7D4 = 0;
        goto LABEL_44;
      case 545:
      case 546:
        field_18C = 6;
        reset_forces();
        field_194 = 1;
        field_190 = 1;
        field_49A = 0;
        field_8B8 = 1;
        return;
      case 550:
      case 551:
        field_18C = 10;
        reset_forces();
        field_194 = 0;
        field_190 = 0;
        field_49A = 0;
        field_8B8 = 1;
        return;
      default:
        break;
    }
LABEL_100:
    char_c::set_seq_params();
    return;
  }
  //v47 = __OFSUB__(skills_1[3], 4);
  //v46 = (char)(skills_1[3] - 4) < 0;
  h_inerc = 0.0;
  v_inerc = 0.0;
  field_18C = 3;
  v_force = 0.0;
  field_194 = 1;
  field_190 = 0;
  field_8B8 = 0;
  //if ( !(v46 ^ v47) && get_seq() == 560 )
  //  field_51C = 2;
}
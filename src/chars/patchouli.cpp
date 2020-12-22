#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "patchouli.h"
#include <math.h>

char_pachou::char_pachou(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_PACHOU;
	pgp->load_dat("patchouli",pal);
	char_loadsfx("patchouli");
	cards_load_cards(&chr_cards,"patchouli");
	load_face("patchouli");
	load_spells("patchouli");
	stand_gfx->init(this,"patchouli");
}

void char_pachou::init_vars()
{
  field_138 = -6.0;
  field_890 = 0;
  field_892 = 0;
  field_8A4 = 0.0;
  field_894 = 0;
  field_896 = 0;
  field_898 = 0;
  field_89A = 0;
  field_89C = 0;
  field_89E = 0;
  field_8A0 = 0;
  field_8A2 = 0;
  char_c::init_vars();
  skills_2[4] = 0;
}

/*c_bullet *char_pachou::new_bullet()
{
    c_bullet *tmp = new patchouli_bullets();
    return tmp;
}*/

void char_pachou::func10() 
{
  double v4 = 0.0;
  double v1337 = 0.0;

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

  double v35 = 0.0;
  double v36 = 0.0;
  int v554 = 0;
  double a2h = 0.0;
  double v632 = 0.0;
  double v103 = 0.0;
  
  bool v639 = false;

  double v1292 = 0.0;
  double v679 = 0.0;
  int v685 = 0;

  double v182 = 0.0;
  double v752 = 0.0;

  double v1349 = 0.0;
  double v1294 = 0.0;
  double v1335 = 0.0;

  double yc = 0.0;
  double v1131 = 0.0;
  bool v1237 = false;

  double v359 = 0.0;

  double v344 = 0.0;
  double v77 = 0.0;

  double v136 = 0.0;

  bool v293 = false;

  double v134 = 0.0;
  double v139 = 0.0;

  x_delta = 0;
  y_delta = 103;
  //v3 = 2;
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
          v4 = 2.0;
          goto LABEL_5;
        case 4:
        case 5:
        case 6:
        case 7:
          field_4AA = 2;
          field_534 = 0.25;
          field_55C = 1.0;
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] == 1 )
          {
            field_86A = 3;
            field_55C = 4.0;
          }
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_55C = 7.0;
          }
          break;
        case 8:
        case 9:
        case 10:
        case 11:
          field_4AA = 2;
          field_534 = 0.25;
          v4 = 1.0;
LABEL_5:
          field_55C = v4;
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
        v1337 = y + 100.0;
        scene_add_effect(this, 53, x, v1337, dir, 1);
        if ( cards_added >= 1 )
        {
          if ( cards_active[0]->id <= 0xB )
          {
            //v6 = byte_553510[v5];
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
        if ( health <= 0 )
          goto LABEL_32;
        t[0] = 0.0;
        t[1] = 0.0;
        t[2] = 0.0;
        addbullet(this, NULL, 1201, 180.0, 130.0, 1, 2, t, 3);
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
    if ( health > 0 )
    {
LABEL_33:
      
      goto LABEL_34;
    }
LABEL_32:
    field_86A = 0;
    goto LABEL_33;
  }
LABEL_34:
  if ( field_8A0 <= 0 )
  {
    if ( !field_84E && !field_852 )
    {
      if ( shader_type != 1 && shader_type != 0.0 )
        shader_type = 0.0;
    }
  }
  else
  {
    field_8A0 = field_8A0 - 1;
    field_538 = 0.0;
    v1337 = (char)skills_1[14];
    field_534 = (0.8999999761581421 - (double)v1337 * 0.1000000014901161) * field_534;
    if ( !field_84E && !field_852 )
    {
      if ( shader_type != 1 )
      {
        if ( shader_type == 0.0 )
          shader_type  = 3;
        v1337 = field_7FC + 8.0;
        field_7FC = v1337;
        shader_cR = (127.0 - cos_deg(v1337) * 127.0);
        shader_cG = (127.0 - cos_deg(v1337) * 127.0);
        shader_cB = 0;
      }
    }
    
    if ( field_188 > 0 )
      field_8A0 = 0;
  }
  if ( field_8A2 > 0 )
  {
    field_8A2 = field_8A2 - 1;
    field_54C = 0.0;
    if ( /*chrt->*/health <= 0 || enemy->health <= 0 )
      field_8A2 = 0;
  }
  if ( field_890 > 0 )
  {
    field_890 = field_890 - 1;
    field_54C = 0.0;
    if ( get_seq() >= 600 && get_seq() <= 689 && (get_seq() != 605 || get_subseq() < 1) )
      field_890 = 0;
    if ( /*chrt->*/health <= 0 || enemy->health <= 0 )
      field_890 = 0;
  }
  if ( 0.0 < field_8A4 )
  {
    field_8A4 = field_8A4 - (0.4000000059604645 - (double)(char)skills_1[2] * 0.05000000074505806);
    if ( field_8A4 < 0.0 )
      field_8A4 = 0.0;
    field_74C = -field_8A4;
    if ( x < (double)enemy->x && enemy->dir == 1 || x > (double)enemy->x && enemy->dir == -1 )
      field_74C = field_8A4;
  }
  if ( field_89C > 0 )
    field_89C = field_89C - 1;
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
  if ( get_seq() == 710 && get_subseq() == 1 )
  {
    ++field_7D4;
    switch ( settings_get()->get_difficulty() )
    {
      case 0:
        dash_angle = dash_angle + 0.01999999955296516;
        v36 = 2.0;
        goto LABEL_90;
      case 1:
        v35 = dash_angle + 0.02999999932944775;
        goto LABEL_89;
      case 2:
        v35 = dash_angle + 0.03999999910593033;
LABEL_89:
        dash_angle = v35;
        v36 = 4.0;
LABEL_90:
        if ( v36 <= v35 )
          dash_angle = v36;
        goto LABEL_87;
      case 3:
        dash_angle = dash_angle + 0.05000000074505806;
        if ( dash_angle >= 5.0 )
          dash_angle = 5.0;
LABEL_87:
        field_7DC = dash_angle + field_7DC;
        field_7E4 = field_7E4 - dash_angle;
        break;
      default:
        break;
    }
    if ( !(field_7D4 % 2) && (v_inerc > 0.0 || v_inerc < 0.0 && y >= 100.0) )
    {
      t[0] = /*get_MT_range(10)*/10.0 + field_7DC - 5.0;
      t[1] = 25.0;
      t[2] = 0.0;
      addbullet(this, NULL, 900, cos_deg(-field_7DC) * 150.0 * (double)dir + x, sin_deg(-field_7DC) * 150.0 + y + 100.0, dir, 1, t, 3);
      /*
      do
      {
        *(float *)&v1444 = /*get_MT_range(360)*//*360.0;
        v1445 = get_MT_range(4) + 8.0;
        v1446 = 4.0;
        v45 = dir;
        v46 = -field_7DC;
        v47 = sin_deg(v46) * 150.0 + y + 100.0;
        v48 = v47;
        v49 = -field_7DC;
        v50 = cos_deg(v49) * 150.0 * (double)dir + x;
        addbullet(this, NULL, 900, v50, v48, v45, 1, (int)&v1444, 3);
        --v3;
      }
      while ( v3 );
      */
      if ( settings_get()->get_difficulty() == 3 || settings_get()->get_difficulty() == 2 )
      {
        t[0] = /*get_MT_range(10)*/10.0 + field_7E4 - 5.0;
        t[1] = 25.0;
        t[2] = 2.0;
        addbullet(this, NULL, 900, cos_deg(-field_7E4) * 150.0 * (double)dir + x, sin_deg(-field_7E4) * 150.0 + y + 100.0, dir, 1, t, 3);
        /*
        v57 = 2;
        do
        {
          *(float *)&v1423 = /*get_MT_range(360)*//*360.0;
          v1424 = get_MT_range(4) + 8.0;
          v1425 = 5.0;
          v58 = dir;
          v59 = -field_7E4;
          v60 = sin_deg(v59) * 150.0 + y + 100.0;
          v61 = v60;
          v62 = -field_7E4;
          v63 = cos_deg(v62) * 150.0 * (double)dir + x;
          addbullet(this, NULL, 900, v63, v61, v58, 1, (int)&v1423, 3);
          --v57;
        }
        while ( v57 );
        */
      }
    }
  }
  //LOWORD(v64) = 0;
  if ( hit_stop || enemy->time_stop )
    return;
  int32_t sq = get_seq();
  if ( sq > 300 )
  {
    if ( sq > 500 )
    {
      if ( sq > 770 )
      {
        switch ( sq )
        {
          case 788:
            goto LABEL_2726;
          case 795:
            if ( get_subseq() )
              goto LABEL_2726;
            v_inerc = v_inerc - 0.300000011920929;
            if ( !char_on_ground_down() )
              goto LABEL_2726;
            set_subseq(1);
            y = getlvl_height();
            reset_forces();
            scene_play_sfx(30);
            break;
          case 797:
            if ( get_subseq() || (v_inerc = v_inerc - v_force, y > 150.0) )
            {
              if ( (get_subseq() == 1 || get_subseq() == 2) && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
              {
                set_subseq(3);
                x = 480.0;
                y = getlvl_height();
                scene_play_sfx(30);
                reset_forces();
              }
              else if ( process() )
              {
                set_seq(0);
              }
            }
            else
            {
              play_sfx(6);
              set_subseq(1);
              reset_forces();
              v_force = 0.2;
              //v1261 = 0;
              v_inerc = 4.0;
              /*
              v1456 = 0.0;
              v1455 = 12.0;
              do
              {
                *(float *)&v1454 = (v1261 + /*get_MT_range(30)*//*30.0);
                if ( *(float *)&v1454 < 0.0 || *(float *)&v1454 < 180.0 )
                  field_7D0 = 1;
                else
                  field_7D0 = -1;
                v1262 = -*(float *)&v1454;
                v1263 = sin_deg(v1262);
                v1264 = LOBYTE(field_7D0);
                v1265 = dir;
                v1373 = v1263 * 75.0 * 0.25;
                v1266 = v1264;
                v1267 = v1265;
                v1268 = getlvl_height() + v1373;
                v1269 = v1268;
                v1270 = -*(float *)&v1454;
                v1271 = cos_deg(v1270) * 75.0 + x;
                addbullet(this, NULL, 820, v1271, v1269, v1267, v1266, (int)&v1454, 3);
                v1261 += 45;
              }
              while ( v1261 < 360 );
              */
            }
            break;
          case 798:
            if ( get_subseq() || (v_inerc = v_inerc - v_force, y > 150.0) )
            {
              if ( (get_subseq() == 1 || get_subseq() == 2) && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
              {
                scene_play_sfx(30);
                set_subseq(3);
                x = 800.0;
LABEL_196:
                y = getlvl_height();
                reset_forces();
              }
              else
              {
LABEL_2726:
                if ( process() )
                  set_seq(700);
              }
            }
            else
            {
              play_sfx(6);
              set_subseq(1);
              reset_forces();
              v_force = 0.2;
              //v1273 = 0;
              v_inerc = 4.0;
              /*
              v1462 = 0.0;
              v1461 = 12.0;
              do
              {
                *(float *)&v1460 = (v1273 + /*get_MT_range(30)*//*30.0);
                if ( *(float *)&v1460 < 0.0 || *(float *)&v1460 < 180.0 )
                  field_7D0 = 1;
                else
                  field_7D0 = -1;
                v1274 = -*(float *)&v1460;
                v1275 = sin_deg(v1274);
                v1276 = LOBYTE(field_7D0);
                v1277 = dir;
                v1373 = v1275 * 75.0 * 0.25;
                v1278 = v1276;
                v1279 = v1277;
                v1280 = getlvl_height() + v1373;
                v1281 = v1280;
                v1282 = -*(float *)&v1460;
                v1283 = cos_deg(v1282) * 75.0 + x;
                addbullet(this, NULL, 820, v1283, v1281, v1279, v1278, (int)&v1460, 3);
                v1273 += 45;
              }
              while ( v1273 < 360 );
              */
            }
            break;
          default:
LABEL_2759:
            char_c::func10();
            break;
        }
      }
      else if ( sq == 770 )
      {
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
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 1201, 180.0, 130.0, 1, 2, t, 3);
          t[2] = 1.0;
          addbullet(this, NULL, 1202, x, y + 100.0, dir, -1, t, 3);
        }
      }
      else
      {
        switch ( sq )
        {
          case 501:
            sub10func();
            field_18C = 0;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( h_inerc < 0.0 )
            {
              h_inerc = h_inerc + 0.75;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_142;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
            {
              if ( skills_1[0] < 3 )
              {
                t[0] = 0.0;
                t[1] = 25.0;
                t[2] = 0.0;
                addbullet(this, NULL, 810, (double)(60 * (char)dir) + x, y + 114.0, dir, 1, t, 3);
              }
              else
              {
                t[0] = 0.0;
                t[1] = 25.0;
                t[2] = 6.0;
                addbullet(this, NULL, 810, (double)(60 * (char)dir) + x, y + 114.0, dir, 1, t, 3);
              }
              scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
              add_card_energy(50);
              spell_energy_spend(200, 60);
              play_sfx(3);
            }
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            t[0] = 0.0;
            t[1] = 25.0;
            t[2] = 1.0;
            addbullet(this, NULL, 810, (double)(60 * (char)dir) + x, 114.0 + y, dir, 1, t, 3);
            goto LABEL_1390;
          case 502:
            v554 = 2;
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 0;
            if ( get_subseq() < 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1344:
                set_subseq(v554);
                reset_forces();
                y = getlvl_height();
                return;
              }
            }
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(9);
              return;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              goto LABEL_886;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              if ( skills_1[0] < 3 )
              {
                t[0] = 45.0;
                t[1] = 15.0;
                t[2] = 0.0;
              }
              else
              {
                t[0] = 45.0;
                t[1] = 15.0;
                t[2] = 6.0;
              }
              addbullet(this, NULL, 810, (double)(40 * dir) + x, y + 45.0, dir, 1, t, 3);
              spell_energy_spend(200, 60);
              add_card_energy(50);
              play_sfx(3);
              h_inerc = -6.0;
              v_inerc = 8.0;
              v_force = 0.44999999;
            }
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 1 )
              return;
            t[0] = 60.0;
            a2h = t[0];
            t[1] = 15.0;
            t[2] = 0.0;
            goto LABEL_1444;
          case 503:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 0;
            if ( get_subseq() < 2 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_subseq(2);
                reset_forces();
                y = getlvl_height();
                return;
              }
            }
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(9);
              return;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              goto LABEL_846;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              if ( skills_1[0] < 3 )
              {
                t[0] = 25.0;
                t[1] = 15.0;
                t[2] = 0.0;
              }
              else
              {
                t[0] = 25.0;
                t[1] = 15.0;
                t[2] = 6.0;
              }
              addbullet(this, NULL, 810, (double)(40 * dir) + x, y + 45.0, dir, 1, t, 3);
              spell_energy_spend(200, 60);
              add_card_energy(50);
              play_sfx(3);
              h_inerc = -6.0;
              v_inerc = 8.0;
              v_force = 0.44999999;
            }
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 1 )
            {
              t[0] = 45.0;
              //a2h = t;
              t[1] = 15.0;
              t[2] = 0.0;
LABEL_1444:
              addbullet(this, NULL, 810, (double)(40 * (char)dir) + x, 45.0 + y, dir, 1, t, 3);
              spell_energy_spend(200, 60);
              add_card_energy(50);
              play_sfx(3);
              h_inerc = -6.0;
              v_inerc = 8.0;
              v_force = 0.44999999;
            }
            return;
          case 505:
            field_18C = 5;
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 3) )
              {
                t[0] = sin_deg((double)(10 * get_elaps_frames())) * 20.0 + 10.0;
                t[1] = 18.0;
                t[2] = 0.0;
                addbullet(this, NULL, 811, (double)(66 * (char)dir) + x, y + 117.0, dir, 1, t, 3);
              }
              if ( get_elaps_frames() >= 10 * ((char)skills_1[5] + 4) || get_elaps_frames() >= 20 && !not_charge_attack )
                goto LABEL_959;
            }
            if ( process() )
              set_seq(0);
            goto LABEL_1484;
          case 506:
            field_18C = 5;
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 3) )
              {
                
                t[0] = sin_deg((double)(10 * get_elaps_frames())) * 20.0 - 45.0;
                t[1] = 20.0;
                t[2] = 0.0;
                addbullet(this, NULL, 811, (double)(66 * (char)dir) + x, y + 117.0, dir, 1, t, 3);
              }
              if ( get_elaps_frames() >= 10 * ((char)skills_1[5] + 4) || get_elaps_frames() >= 20 && !not_charge_attack )
                goto LABEL_1740;
            }
            if ( process() )
              set_seq(0);
LABEL_1484:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              spell_energy_spend(200, 60);
              add_card_energy(50);
              field_190 = 1;
              play_sfx(11);
            }
            return;
          case 507:
            v632 = 3;
            field_18C = 5;
            if ( get_subseq() == 3 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1527;
            }
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 3) )
              {
                t[0] = sin_deg((double)(10 * get_elaps_frames())) * 20.0 + 10.0;
                t[1] = 18.0;
                t[2] = 0.0;
                addbullet(this, NULL, 811, (double)(71 * (char)dir) + x, y + 114.0, dir, 1, t, 3);
              }
              if ( get_elaps_frames() >= 10 * ((char)skills_1[5] + 4) || get_elaps_frames() >= 20 && !not_charge_attack )
                goto LABEL_959;
            }
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_1521;
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              set_seq(9);
            goto LABEL_1516;
          case 508:
            v103 = 3;
            field_18C = 5;
            if ( get_subseq() == 3 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_263:
                reset_forces();
                y = getlvl_height();
                set_subseq(v103);
                return;
              }
            }
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 3) )
              {
                t[0] = sin_deg((double)(10 * get_elaps_frames())) * 20.0 + 45.0;
                t[1] = 20.0;
                t[2] = 0.0;
                addbullet(this, NULL, 811, (double)(71 * (char)dir) + x, y + 114.0, dir, 1, t, 3);
              }
              if ( get_elaps_frames() >= 10 * ((char)skills_1[5] + 4) || get_elaps_frames() >= 20 && !not_charge_attack )
                goto LABEL_1740;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
                set_seq(9);
LABEL_1516:
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                spell_energy_spend(200, 60);
                add_card_energy(50);
                field_190 = 1;
                play_sfx(11);
              }
            }
LABEL_1521:
            if ( get_subseq() != 2 || get_frame_time() )
              return;
            v639 = get_frame() == 6;
            goto LABEL_1524;
          case 510:
            field_18C = 10;
            sub10func();
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
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                h_inerc = 10.0;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 2.0;
                if ( skills_1[10] >= 3 )
                  t[2] = 0.0;
                addbullet(this, NULL, 812, x, y, dir, 1, t, 3);
                spell_energy_spend(200, 60);
                add_card_energy(50);
                field_190 = 1;
                play_sfx(11);
                /*
                v1343 = 0.0;
                v647 = (float)0.0;
                do
                {
                  *(float *)&v1408 = v647 * 30.0;
                  v1409 = /*get_MT_range(30)*//*30.0 * 0.1000000014901161 + 15.0;
                  v1410 = 1.0;
                  v648 = -*(float *)&v1408;
                  v649 = sin_deg(v648) >= 0.0;
                  addbullet(this, NULL, 812, x, y, dir, (1 - 2 * v649), (int)&v1408, 3);
                  v1343 = v1343 + 1.0;
                  v647 = v1343;
                }
                while ( v1343 < 12.0 );
                */
              }
              if ( !get_frame_time() && get_frame() == 11 )
              {
                h_inerc = 10.0;
                t[0] = 45.0;
                t[1] = 0.0;
                t[2] = 2.0;
                if ( skills_1[10] >= 3 )
                  t[2] = 0.0;
                addbullet(this, NULL, 812, x, y, dir, 1, t, 3);
                field_190 = 1;
                play_sfx(11);
                /*
                v1344 = 0.0;
                v650 = (float)0.0;
                do
                {
                  *(float *)&v1399 = v650 * 30.0;
                  v1400 = /*get_MT_range(30)*//*30.0 * 0.1000000014901161 + 15.0;
                  v1401 = 1.0;
                  v651 = -*(float *)&v1399;
                  v652 = sin_deg(v651) >= 0.0;
                  addbullet(this, NULL, 812, x, y, dir, (1 - 2 * v652), (int)&v1399, 3);
                  v1344 = v1344 + 1.0;
                  v650 = v1344;
                }
                while ( v1344 < 12.0 );
                */
              }
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              return;
            goto LABEL_1570;
          case 511:
            field_18C = 10;
            sub10func();
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
            if ( !get_subseq() )
            {
              if ( !get_frame_time() && get_frame() == 4 )
              {
                h_inerc = 10.0;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 2.0;
                if ( skills_1[10] >= 3 )
                  t[2] = 0.0;
                addbullet(this, NULL, 812, x, y, dir, 1, t, 3);
                spell_energy_spend(200, 60);
                add_card_energy(50);
                field_190 = 1;
                play_sfx(11);
                /*
                v1345 = 0.0;
                v655 = (float)0.0;
                do
                {
                  *(float *)&v1402 = v655 * 30.0;
                  v1403 = /*get_MT_range(30)*//*30.0 * 0.1000000014901161 + 15.0;
                  v1404 = 1.0;
                  v656 = -*(float *)&v1402;
                  v657 = sin_deg(v656) >= 0.0;
                  addbullet(this, NULL, 812, x, y, dir, (1 - 2 * v657), (int)&v1402, 3);
                  v1345 = v1345 + 1.0;
                  v655 = v1345;
                }
                while ( v1345 < 12.0 );
                */
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 11 )
                {
                  h_inerc = 10.0;
                  t[0] = 45.0;
                  t[1] = 0.0;
                  t[2] = 2.0;
                  if ( skills_1[10] >= 3 )
                    t[2] = 0.0;
                  addbullet(this, NULL, 812, x, y, dir, 1, t, 3);
                  field_190 = 1;
                  play_sfx(11);
                  /*
                  v1346 = 0.0;
                  v658 = (float)0.0;
                  do
                  {
                    *(float *)&v1393 = v658 * 30.0;
                    v1394 = /*get_MT_range(30)*//*30.0 * 0.1000000014901161 + 15.0;
                    v1395 = 1.0;
                    v659 = -*(float *)&v1393;
                    v660 = sin_deg(v659) >= 0.0;
                    addbullet(this, NULL, 812, x, y, dir, (1 - 2 * v660), (int)&v1393, 3);
                    v1346 = v1346 + 1.0;
                    v658 = v1346;
                  }
                  while ( v1346 < 12.0 );
                  */
                }
                if ( !get_frame_time() && get_frame() == 22 )
                {
                  h_inerc = 10.0;
                  t[0] = 45.0;
                  t[1] = 0.0;
                  t[2] = 2.0;
                  if ( skills_1[10] >= 3 )
                    t[2] = 0.0;
                  addbullet(this, NULL, 812, x, y, dir, 1, t, 3);
                  field_190 = 1;
                  play_sfx(11);
                  /*
                  v1347 = 0.0;
                  v661 = (float)0.0;
                  do
                  {
                    *(float *)&v1405 = v661 * 30.0;
                    v1406 = /*get_MT_range(30)*//*30.0 * 0.1000000014901161 + 15.0;
                    v1407 = 1.0;
                    v662 = -*(float *)&v1405;
                    v663 = sin_deg(v662) >= 0.0;
                    addbullet(this, NULL, 812, x, y, dir, (1 - 2 * v663), (int)&v1405, 3);
                    v1347 = v1347 + 1.0;
                    v661 = v1347;
                  }
                  while ( v1347 < 12.0 );
                  */
                }
              }
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() )
            {
LABEL_1570:
              if ( get_subseq() == 1 )
                set_seq(0);
            }
            return;
          case 520:
            sub10func();
            field_18C = 1;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_522;
            if ( get_subseq() || get_frame_time() || get_frame() != 5 )
              return;
            t[0] = 0.0;
            t[1] = 30.0;
            t[2] = 4.0;
            if ( (enemy->x - x) < 512.0 )
            {
              if ( (enemy->x - x) <= -512.0 )
                enemy->x = x - 512.0;
            }
            else
            {
              enemy->x = x + 512.0;
            }
            //v666 = t;
            goto LABEL_1616;
          case 521:
            sub10func();
            field_18C = 1;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_522;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
            {
              t[0] = 0.0;
              t[1] = 30.0;
              t[2] = 4.0;
              if ( (enemy->x - x) > 512.0 || (enemy->x - x) <= 0.0 )
              {
                if ( (enemy->x - x) < -512.0 || (enemy->x - x) >= 0.0 )
                {
                  //v666 = t;
                }
                else
                {
                  //v666 = t;
                  enemy->x = x - 512.0;
                }
              }
              else
              {
                //v666 = t;
                enemy->x = x + 512.0;
              }
LABEL_1616:
              //v667 = (int)v666; //t instead of this (for addbullet)
              addbullet(this, NULL, 815, enemy->x, enemy->getlvl_height(), dir, 1, t, 3);
              spell_energy_spend(200, 60);
              add_card_energy(50);
            }
            return;
          case 525:
            sub10func();
            field_18C = 6;
            if ( process() )
              set_seq(0);
            if ( get_subseq() || get_frame_time() || get_frame() != 5 )
              return;
            t[0] = -10.0;
            t[1] = 5.0;
            t[2] = 0.0;
            if ( skills_1[6] >= 4 )
              t[2] = 3.0;
            //a2j = &v1519;
            goto LABEL_1641;
          case 526:
            sub10func();
            field_18C = 6;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
            {
              t[0] = -10.0;
              t[1] = 13.0;
              t[2] = 0.0;
              if ( skills_1[6] >= 4 )
                t[2] = 3.0;
              //a2j = (int *)&v1531;
LABEL_1641:
              addbullet(this, NULL, 816, (double)(62 * (char)dir) + x, y + 118.0, dir, 1, t, 3);
              spell_energy_spend(200, 60);
              add_card_energy(50);
              play_sfx(12);
              field_190 = 1;
            }
            return;
          case 527:
            v632 = 1;
            if ( get_subseq() == 1 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1527;
            }
            field_18C = 6;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(9);
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() != 5 )
              goto LABEL_1667;
            t[0] = 10.0;
            t[1] = 5.0;
            t[2] = 0.0;
            if ( skills_1[6] >= 4 )
              t[2] = 3.0;
            //a2k = t;
            v1292 = y + 115.0;
            v679 = (double)(71 * (char)dir) + x;
            goto LABEL_1666;
          case 528:
            v632 = 1;
            if ( get_subseq() == 1 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1527:
                reset_forces();
                y = getlvl_height();
                set_subseq(v632);
                return;
              }
            }
            field_18C = 6;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(9);
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() == 5 )
            {
              t[0] = 10.0;
              t[1] = 13.0;
              t[2] = 0.0;
              if ( skills_1[6] >= 4 )
                t[2] = 3.0;
              //a2k = t;
              v1292 = y + 118.0;
              v679 = (double)(62 * (char)dir) + x;
LABEL_1666:
              addbullet(this, NULL, 816, v679, v1292, dir, 1, t, 3);
              spell_energy_spend(200, 60);
              add_card_energy(50);
              play_sfx(12);
              field_190 = 1;
            }
            goto LABEL_1667;
          case 530:
            sub10func();
            field_18C = 11;
            if ( field_7D0 && get_frame() <= 12 )
            {
              v685 = 5;
              if ( skills_1[11] >= 2 )
                v685 = 4;
              if ( skills_1[11] >= 3 )
                v685 = 3;
              if ( field_7D0 % v685 == 1 )
              {
                tt[0] = /*get_MT_range(15)*/15.0 + 10.0;
                tt[1] = /*get_MT_range(3)*/3.0 + 12.0 + (double)(char)skills_1[11];
                tt[2] = 0.0;
                tt[3] = (double)(char)skills_1[11] * 10.0 + 50.0;
                addbullet(this, NULL, 817, (double)(62 * (char)dir) + x, y + 118.0, dir, 1, tt, 4);
                play_sfx(2);
              }
              ++field_7D0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
            {
              spell_energy_spend(200, 60);
              add_card_energy(50);
              field_190 = 1;
              field_7D0 = 1;
            }
            return;
          case 531:
            sub10func();
            field_18C = 11;
            if ( field_7D0 && get_frame() <= 12 )
            {
              v685 = 5;
              if ( skills_1[11] >= 2 )
                v685 = 4;
              if ( skills_1[11] >= 3 )
                v685 = 3;
              if ( field_7D0 % v685 == 1 )
              {
                tt[0] = /*get_MT_range(15)*/15.0 - 10.0;
                tt[1] = /*get_MT_range(3)*/3.0 + 12.0 + (double)(char)skills_1[11];
                tt[2] = 0.0;
                tt[3] = (double)(char)skills_1[11] * 10.0 + 50.0;
                addbullet(this, NULL, 817, (double)(62 * (char)dir) + x, y + 118.0, dir, 1, tt, 4);
                play_sfx(2);
              }
              ++field_7D0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
            {
              spell_energy_spend(200, 60);
              add_card_energy(50);
              field_190 = 1;
              field_7D0 = 1;
            }
            return;
          case 532:
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
                goto LABEL_1740;
              }
            }
            field_18C = 11;
            
            if ( field_7D0 && get_frame() <= 12 && !get_subseq() )
            {
              v685 = 5;
              if ( skills_1[11] >= 2 )
                v685 = 4;
              if ( skills_1[11] >= 3 )
                v685 = 3;
              if ( field_7D0 % v685 == 1 )
              {
                tt[0] = /*get_MT_range(15)*/15.0 + 10.0;
                tt[0] = /*get_MT_range(3)*/3.0 + 12.0 + (double)(char)skills_1[11];
                tt[0] = 0.0;
                tt[0] = (double)(char)skills_1[11] * 10.0 + 50.0;
                addbullet(this, NULL, 817, (double)(71 * (char)dir) + x, y + 115.0, dir, 1, tt, 4);
                play_sfx(2);
              }
              ++field_7D0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(9);
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() == 5 )
            {
              spell_energy_spend(200, 60);
              add_card_energy(50);
              field_190 = 1;
              field_7D0 = 1;
            }
            goto LABEL_1667;
          case 533:
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
                next_subseq();
                return;
              }
            }
            field_18C = 11;
            if ( field_7D0 && get_frame() <= 12 && !get_subseq() )
            {
              v685 = 5;
              if ( skills_1[11] >= 2 )
                v685 = 4;
              if ( skills_1[11] >= 3 )
                v685 = 3;
              if ( field_7D0 % v685 == 1 )
              {
                tt[0] = /*get_MT_range(15)*/15.0 - 10.0;
                tt[1] = /*get_MT_range(3)*/3.0 + 12.0 + (double)(char)skills_1[11];
                tt[2] = 0.0;
                tt[3] = (double)(char)skills_1[11] * 10.0 + 50.0;
                addbullet(this, NULL, 817, (double)(71 * (char)dir) + x, y + 115.0, dir, 1, tt, 4);
                play_sfx(2);
              }
              ++field_7D0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 5 )
              {
                spell_energy_spend(200, 60);
                add_card_energy(50);
                field_190 = 1;
                field_7D0 = 1;
              }
LABEL_1667:
              if ( !get_frame_time() )
              {
                v639 = get_frame() == 15;
                goto LABEL_1524;
              }
            }
            return;
          case 540:
            if ( !get_subseq() || get_subseq() == 4 )
              sub10func();
            field_18C = 2;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() < 4 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1972;
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 5) )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                addbullet(this, NULL, 820, x, y + 100.0, dir, 1, t, 3);
              }
              if ( !(get_elaps_frames() % 10) )
              {
                if ( y - getlvl_height() < 200.0 )
                {
                  /*
                  v714 = 0;
                  v1459 = 0.0;
                  v1458 = 12.0;
                  do
                  {
                    *(float *)&v1457 = (v714 + /*get_MT_range(30)*//*30.0);
                    if ( *(float *)&v1457 < 0.0 || *(float *)&v1457 < 180.0 )
                      field_7D0 = 1;
                    else
                      field_7D0 = -1;
                    v715 = -*(float *)&v1457;
                    v716 = sin_deg(v715);
                    v717 = LOBYTE(field_7D0);
                    v718 = dir;
                    v719 = getlvl_height() + v716 * 75.0 * 0.25;
                    v720 = v719;
                    v721 = -*(float *)&v1457;
                    v722 = cos_deg(v721) * 75.0 + x;
                    addbullet(this, NULL, 820, v722, v720, v718, v717, (int)&v1457, 3);
                    v714 += 45;
                  }
                  while ( v714 < 360 );
                  */
                }
              }
              if ( get_elaps_frames() >= 34 )
                goto LABEL_959;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(6);
              add_card_energy(50);
              spell_energy_spend(200, 60);
              v_inerc = 7.0;
              v_force = 0.40000001;
              field_8A4 = 14.5;
            }
            return;
          case 541:
            if ( !get_subseq() || get_subseq() == 4 )
              sub10func();
            field_18C = 2;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() < 4 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_2011;
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 5) )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                addbullet(this, NULL, 820, x, y + 100.0, dir, 1, t, 3);
              }
              if ( !(get_elaps_frames() % 10) )
              {
                if ( y - getlvl_height() < 500.0 )
                {
                  /*
                  v726 = 0;
                  v1468 = 0.0;
                  v1467 = 12.0;
                  do
                  {
                    *(float *)&v1466 = (v726 + /*get_MT_range(30)*//*30.0);
                    if ( *(float *)&v1466 < 0.0 || *(float *)&v1466 < 180.0 )
                      field_7D0 = 1;
                    else
                      field_7D0 = -1;
                    v727 = -*(float *)&v1466;
                    v728 = sin_deg(v727);
                    v729 = LOBYTE(field_7D0);
                    v730 = dir;
                    v731 = getlvl_height() + v728 * 75.0 * 0.25;
                    v732 = v731;
                    v733 = -*(float *)&v1466;
                    v734 = cos_deg(v733) * 75.0 + x;
                    addbullet(this, NULL, 820, v734, v732, v730, v729, (int)&v1466, 3);
                    v726 += 45;
                  }
                  while ( v726 < 360 );
                  */
                }
              }
              if ( get_elaps_frames() >= 34 )
                goto LABEL_959;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(6);
              add_card_energy(50);
              spell_energy_spend(200, 60);
              v_inerc = 12.5;
              v_force = 0.40000001;
              field_8A4 = 18.5;
            }
            return;
          case 545:
            sub10func();
            field_18C = 7;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_1826;
            if ( not_charge_attack && (keyDown(INP_A) || keyDown(INP_C)) )
              goto LABEL_2701;
            if ( get_elaps_frames() >= 120 || !not_charge_attack )
              goto LABEL_959;
LABEL_1826:
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            {
              set_seq(0);
              return;
            }
            if ( get_subseq() || get_frame_time() || get_frame() != 4 )
              goto LABEL_1838;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            goto LABEL_1837;
          case 546:
            sub10func();
            field_18C = 7;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_1855;
            if ( not_charge_attack && (keyDown(INP_A) || keyDown(INP_B)) )
              goto LABEL_509;
            if ( get_elaps_frames() >= 120 || !not_charge_attack )
              goto LABEL_1740;
LABEL_1855:
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 3 )
            {
              if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
LABEL_1837:
                addbullet(this, NULL, 821, (double)(100 * dir) + x, y + 110.0, dir, 1, t, 3);
                spell_energy_spend(200, 60);
                add_card_energy(50);
                play_sfx(14);
                field_190 = 1;
              }
LABEL_1838:
              if ( get_subseq() == 3 )
              {
                if ( (skills_1[7] >= 4) && get_frame_time() >= 2 || skills_1[7] >= 2 && get_frame_time() >= 3 )
                {
                  if ( get_frame() == 4 )
                    set_seq(0);
                  else
                    next_frame();
                }
              }
            }
            else
            {
              set_seq(0);
            }
            return;
          case 547:
            v182 = 4;
            if ( get_subseq() == 4 )
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
LABEL_1890:
                set_subseq(v182);
                return;
              }
            }
            field_18C = 7;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 )
            {
              if ( not_charge_attack && (keyDown(INP_A) || keyDown(INP_C)) )
                goto LABEL_509;
              if ( get_elaps_frames() >= 120 || !not_charge_attack )
                goto LABEL_1740;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                set_seq(9);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                set_seq(9);
                return;
              }
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 821, (double)(100 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
              spell_energy_spend(200, 60);
              add_card_energy(50);
              play_sfx(14);
              field_190 = 1;
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 9 )
              v_force = 0.5;
            if ( get_subseq() == 3 )
            {
              if ( !get_frame_time() && get_frame() == 1 )
                v_force = 0.5;
              if ( (skills_1[7] >= 4) && get_frame_time() >= 2 || skills_1[7] >= 2 && get_frame_time() >= 3 )
              {
                if ( get_frame() == 4 )
                {
                  set_seq(9);
                  return;
                }
                next_frame();
                if ( !get_frame_time() )
                {
                  v639 = get_frame() == 1;
                  goto LABEL_1524;
                }
              }
            }
            return;
          case 548:
            if ( get_subseq() == 4 )
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
                set_subseq(4);
                return;
              }
            }
            field_18C = 7;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            v752 = 1;
            if ( get_subseq() == 1 )
            {
              if ( not_charge_attack && (keyDown(INP_A) || keyDown(INP_B)) )
              {
LABEL_509:
                set_subseq(3);
                return;
              }
              if ( get_elaps_frames() >= 120 || !not_charge_attack )
                goto LABEL_1740;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                set_seq(9);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                set_seq(9);
                return;
              }
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 821, (double)(100 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
              spell_energy_spend(200, 60);
              add_card_energy(50);
              play_sfx(14);
              field_190 = 1;
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 9 )
              v_force = 0.5;
            if ( get_subseq() != 3 )
              return;
            if ( !get_frame_time() && get_frame() == 1 )
              v_force = 0.5;
            if ( (skills_1[7] < 4 || get_frame_time() < 2) && (skills_1[7] < 2 || get_frame_time() < 3) )
              return;
            if ( get_frame() == 4 )
            {
              set_seq(9);
              return;
            }
            if ( !get_frame() )
              v_force = 0.5;
            next_frame();
            goto LABEL_1955;
          case 550:
            if ( !get_subseq() || get_subseq() == 4 )
              sub10func();
            field_18C = 10;
            if ( get_subseq() > 3 || get_subseq() < 1 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( get_subseq() == 1 )
              {
                if ( !((1.0 < v_inerc) | (1.0 == v_inerc)) )
                  v_inerc = 1.0;
              }
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 1.0 )
                h_inerc = 1.0;
              if ( char_on_ground_down() )
              {
LABEL_1972:
                reset_forces();
                set_subseq(4);
                y = getlvl_height();
                return;
              }
            }
            if ( !get_subseq() && skills_1[12] >= 2 )
              field_51C = 3;
            if ( get_subseq() == 1 )
            {
              if ( get_elaps_frames() == 25 )
              {
                //shake_camera(2.0);
                play_sfx(22);
                field_7D0 = 1;
                tt[0] = 90.0;
                tt[1] = 0.0;
                tt[2] = 3.0;
                tt[3] = 1.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
                t[2] = 2.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
                /*
                v778 = 0;
                do
                {
                  *(float *)&v1380 = (v778 + /*get_MT_range(30)*//*30.0);
                  if ( *(float *)&v1380 < 0.0 || *(float *)&v1380 < 180.0 )
                    field_7D0 = 1;
                  else
                    field_7D0 = -1;
                  v1381 = 12.0;
                  v1382 = 0.0;
                  v779 = -*(float *)&v1380;
                  v780 = sin_deg(v779);
                  v781 = LOBYTE(field_7D0);
                  v782 = dir;
                  v783 = getlvl_height() + v780 * 75.0 * 0.25;
                  v784 = v783;
                  v785 = -*(float *)&v1380;
                  v786 = cos_deg(v785) * 75.0 + x;
                  addbullet(this, NULL, 820, v786, v784, v782, v781, (int)&v1380, 3);
                  v778 += 45;
                }
                while ( v778 < 360 );
                */
              }
              if ( get_elaps_frames() == 28 && skills_1[12] >= 3 )
              {
                //shake_camera(2.0);
                play_sfx(22);
                field_7D0 = 1;
                tt[0] = 110.0;
                tt[1] = 0.0;
                tt[2] = 4.0;
                tt[3] = 1.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
                tt[0] = 70.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
              }
              if ( get_elaps_frames() == 31 && skills_1[12] >= 4 )
              {
                //shake_camera(2.0);
                play_sfx(22);
                field_7D0 = 1;
                tt[0] = 135.0;
                tt[1] = 0.0;
                tt[2] = 4.0;
                tt[3] = 1.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
                tt[0] = 45.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
              }
              if ( get_elaps_frames() >= 35 )
                goto LABEL_959;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(21);
              add_card_energy(50);
              spell_energy_spend(200, 60);
              field_190 = 1;
              h_inerc = 12.5;
              v_inerc = 10.5;
              v_force = 0.5;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, (double)get_pframe()->extra1[5] + y, dir, 1, t, 3);
            }
            return;
          case 551:
            if ( !get_subseq() || get_subseq() == 4 )
              sub10func();
            field_18C = 10;
            if ( get_subseq() > 3 || get_subseq() < 1 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( get_subseq() == 1 )
              {
                if ( !((1.0 < v_inerc) | (1.0 == v_inerc)) )
                  v_inerc = 1.0;
              }
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 1.0 )
                h_inerc = 1.0;
              if ( char_on_ground_down() )
              {
LABEL_2011:
                reset_forces();
                set_subseq(4);
                y = getlvl_height();
                return;
              }
            }
            if ( !get_subseq() && skills_1[12] >= 2 )
              field_51C = 3;
            if ( get_subseq() == 1 )
            {
              if ( get_elaps_frames() == 25 )
              {
                //shake_camera(2.0);
                play_sfx(22);
                field_7D0 = 1;
                tt[0] = 0.0;
                tt[1] = 0.0;
                tt[2] = 3.0;
                tt[3] = 1.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
                tt[2] = 2.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
              }
              if ( get_elaps_frames() == 28 && skills_1[12] >= 3 )
              {
                //shake_camera(2.0);
                play_sfx(22);
                field_7D0 = 1;
                tt[0] = 10.0;
                tt[1] = 0.0;
                tt[2] = 4.0;
                tt[3] = 1.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
                tt[0] = -10.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
              }
              if ( get_elaps_frames() == 31 && skills_1[12] >= 4 )
              {
                //shake_camera(2.0);
                play_sfx(22);
                field_7D0 = 1;
                tt[0] = 25.0;
                tt[1] = 0.0;
                tt[2] = 4.0;
                tt[3] = 1.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
                tt[0] = -25.0;
                addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
              }
              if ( get_elaps_frames() >= 35 )
                goto LABEL_959;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(21);
              add_card_energy(50);
              spell_energy_spend(200, 60);
              field_190 = 1;
              h_inerc = 12.5;
              v_inerc = 12.5;
              v_force = 0.5;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 822, (double)(get_pframe()->extra1[4] * (char)dir) + x, (double)get_pframe()->extra1[5] + y, dir, 1, t, 3);
            }
            return;
          case 560:
            sub10func();
            field_18C = 3;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() > 1 )
              goto LABEL_2055;
            if ( field_7D0 != 1 )
              goto LABEL_2052;
            //
            v1349 = 2.0;
            v685 = 7;
            if ( skills_1[3] == 2 )
            {
              v685 = 6;
              v1349 = 3.0;
            }
            if ( skills_1[3] == 3 )
            {
              v685 = 5;
              v1349 = 4.0;
            }
            if ( skills_1[3] >= 4 )
            {
              v685 = 4;
              v1349 = 5.0;
            }
            if ( not_charge_attack != 1 )
              v1349 = 2.0;
            if ( field_7D2 % v685 || v1349 < (double)field_7E4 )
              goto LABEL_2052;
            play_sfx(0);
            if ( 0.0 == field_7E4 )
            {
              t[0] = 0.0;
              //a2m = &a1a;
              t[1] = 40.0;
              t[2] = 0.0;
              v1294 = sin_deg(-t[0]) * 200.0 + y + 100.0;
              v1335 = (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x;
            }
            else
            {
              t[0] = field_7E4 * 6.0;
              t[1] = 40.0;
              t[2] = 0.0;
              addbullet(this, NULL, 825, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-t[0]) * 200.0 + y + 100.0, dir, 1, t, 3);
              //a2m = &a4;
              t[0] = field_7E4 * -6.0;
              v1294 = sin_deg(-t[0]) * 200.0 + y + 100.0;
              v1335 = (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x;
            }
            goto LABEL_2051;
          case 561:
            sub10func();
            field_18C = 3;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() <= 1 )
            {
              if ( field_7D0 == 1 )
              {
                if ( skills_1[3] <= 3 )
                  v1349 = 4.0;
                if ( skills_1[3] <= 2 )
                  v1349 = 3.0;
                if ( skills_1[3] <= 0 )
                  v1349 = 2.0;
                if ( skills_1[3] >= 4 )
                  v1349 = 5.0;
                if ( !(field_7D2 % 7) && v1349 >= (double)field_7E4 )
                {
                  play_sfx(0);
                  t[0] = field_7E4 * 7.0 + 20.0;
                  t[1] = 40.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 825, (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x, sin_deg(-t[0]) * 200.0 + y + 100.0, dir, 1, t, 3);
                  //a2m = &v1390;
                  t[0] = field_7E4 * -7.0 - 20.0;
                  v1294 = sin_deg(-t[0]) * 200.0 + y + 100.0;
                  v1335 = (cos_deg(-t[0]) * 200.0 - 100.0) * (double)dir + x;
LABEL_2051:
                  addbullet(this, NULL, 825, v1335, v1294, dir, 1, t, 3);
                  field_7E4 = field_7E4 + 1.0;
                }
              }
LABEL_2052:
              ++field_7D2;
              if ( !not_charge_attack && get_elaps_frames() >= 10 )
                goto LABEL_959;
              if ( get_elaps_frames() >= 90 )
                goto LABEL_959;
            }
LABEL_2055:
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 60);
              field_190 = 1;
              field_7D0 = 1;
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
            {
              field_7D0 = 2;
              play_sfx(8);
            }
            return;
          case 565:
            sub10func();
            field_18C = 8;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_142;
            if ( get_subseq() || get_frame_time() || get_frame() != 5 )
              return;
            play_sfx(16);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -45.0 )
              field_7E4 = -45.0;
            if ( field_7E4 > 45.0 )
              field_7E4 = 45.0;
            t[0] = field_7E4;
            //a2n = &v1583;
            t[1] = 15.0;
            t[2] = 0.0;
            goto LABEL_2096;
          case 566:
            sub10func();
            field_18C = 8;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_142;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
            {
              play_sfx(16);
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -45.0 )
                field_7E4 = -45.0;
              if ( field_7E4 > 45.0 )
                field_7E4 = 45.0;
              t[0] = field_7E4 + 45.0;
              t[1] = 15.0;
              t[2] = 0.0;
              addbullet(this, NULL, 826, (double)(70 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
              //a2n = &v1441;
              t[0] = field_7E4 - 45.0;
              t[1] = 15.0;
              t[2] = 0.0;
LABEL_2096:
              addbullet(this, NULL, 826, (double)(70 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
              spell_energy_spend(200, 60);
              add_card_energy(50);
              field_190 = 1;
            }
            return;
          case 567:
            if ( get_subseq() == 1 )
              sub10func();
            field_18C = 8;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 1 )
            {
LABEL_1283:
              set_subseq(1);
LABEL_1284:
              air_dash_cnt = 0;
              goto LABEL_196;
            }
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_846;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() != 5 )
              goto LABEL_2134;
            play_sfx(16);
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -45.0 )
              field_7E4 = -45.0;
            if ( field_7E4 > 45.0 )
              field_7E4 = 45.0;
            t[0] = field_7E4;
            //a2o = &v1589;
            t[1] = 15.0;
            t[2] = 0.0;
            goto LABEL_2133;
          case 568:
            if ( get_subseq() == 1 )
              sub10func();
            field_18C = 8;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 1 )
            {
              set_subseq(1);
              air_dash_cnt = 0;
              goto LABEL_196;
            }
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_886;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 5 )
              {
                play_sfx(16);
                field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
                if ( field_7E4 < -45.0 )
                  field_7E4 = -45.0;
                if ( field_7E4 > 45.0 )
                  field_7E4 = 45.0;
                t[0] = field_7E4 + 45.0;
                t[1] = 15.0;
                t[2] = 0.0;
                addbullet(this, NULL, 826, (double)(60 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
                //a2o = &v1411;
                t[0] = field_7E4 - 45.0;
                t[1] = 15.0;
                t[2] = 0.0;
LABEL_2133:
                addbullet(this, NULL, 826, (double)(60 * (char)dir) + x, y + 110.0, dir, 1, t, 3);
                spell_energy_spend(200, 60);
                add_card_energy(50);
                field_190 = 1;
              }
LABEL_2134:
              if ( !get_frame_time() )
              {
                v639 = get_frame() == 9;
                goto LABEL_1524;
              }
            }
            return;
          case 570:
            sub10func();
            field_18C = 13;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 )
            {
              if ( field_7D0 < field_7D2 && !(get_elaps_frames() % 3) )
              {
                tt[0] = /*get_MT_range(30)*/30.0 + 30.0;
                tt[1] = 40.0;
                tt[2] = 0.0;
                tt[3] = (double)get_elaps_frames();
                addbullet(this, NULL, 827,  /*get_MT_range(300)*/300.0 + x - 150.0, /*get_MT_range(75)*/75.0 + y + 200.0, dir, 1, tt, 4);
                ++field_7D0;
              }
              if ( get_elaps_frames() >= 24 )
                goto LABEL_2164;
            }
            goto LABEL_2166;
          case 571:
            sub10func();
            field_18C = 13;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_2166;
            if ( field_7D0 < field_7D2 && !(get_elaps_frames() % 3) )
            {
              tt[0] = /*get_MT_range(30)*/30.0 + 5.0;
              tt[1] = 40.0;
              tt[2] = 1.0;
              tt[3] = (double)get_elaps_frames();
              addbullet(this, NULL, 827, /*get_MT_range(300)*/300.0 + x - 150.0, /*get_MT_range(75)*/75.0 + y + 200.0, dir, 1, tt, 4);
              ++field_7D0;
            }
            if ( get_elaps_frames() >= 24 )
            {
LABEL_2164:
              if ( !not_charge_attack )
                goto LABEL_960;
              set_subseq(4);
            }
            else
            {
LABEL_2166:
              if ( get_subseq() == 4 && get_elaps_frames() >= 16 )
                next_subseq();
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                  goto LABEL_142;
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  play_sfx(23);
                  add_card_energy(50);
                  spell_energy_spend(200, 60);
                  field_190 = 1;
                  field_7D2 = 6;
                  if ( skills_1[13] >= 2 )
                    field_7D2 = 7;
                  if ( skills_1[13] >= 4 )
                    field_7D2 = 8;
                }
              }
            }
            return;
          case 580:
            sub10func();
            field_18C = 4;
            if ( field_7D0 == 1 )
            {
              v1335 = 4.0;
              if ( skills_1[4] == 4 )
                v1335 = 7.0;
              if ( (char)skills_1[4] <= 3 )
                v1335 = 6.0;
              if ( (char)skills_1[4] <= 2 )
                v1335 = 5.0;
              if ( (char)skills_1[4] <= 0 )
                v1335 = 4.0;
              if ( !(field_7D2 % 5) && v1335 >= (double)field_7E4 )
              {
                tt[0] = 0.0;
                tt[1] = 0.0;
                tt[2] = 0.0;
                tt[3] = field_7E4 * 4.0;
                addbullet(this, NULL, 830, (cos_deg(-field_7E4 * 140.0) * 100.0 + 200.0) * (double)dir + x, sin_deg(-field_7E4 * 140.0) * 25.0, dir, 1, tt, 4);
                field_7E4 = field_7E4 + 1.0;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_142;
            goto LABEL_2208;
          case 581:
            sub10func();
            field_18C = 4;
            if ( field_7D0 == 1 )
            {
              if ( skills_1[4] == 4 )
                v1335 = 7.0;
              if ( skills_1[4] <= 3 )
                v1335 = 6.0;
              if ( skills_1[4] <= 2 )
                v1335 = 5.0;
              if ( skills_1[4] <= 0 )
                v1335 = 4.0;
              if ( !(field_7D2 % 5) && v1335 >= (double)field_7E4 )
              {
                tt[0] = 0.0;
                tt[1] = 0.0;
                tt[2] = 0.0;
                tt[3] = field_7E4 * 4.0;
                addbullet(this, NULL, 830, (cos_deg(-field_7E4 * 140.0) * 100.0 + 450.0) * (double)dir + x, sin_deg(-field_7E4 * 140.0) * 25.0, dir, 1, tt, 4);
                field_7E4 = field_7E4 + 1.0;
              }
            }
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            {
LABEL_2208:
              if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
              {
                add_card_energy(50);
                spell_energy_spend(200, 60);
                field_190 = 1;
                field_7D0 = 1;
                play_sfx(9);
              }
            }
            else
            {
              set_seq(0);
            }
            return;
          case 585:
          case 586:
            sub10func();
            field_18C = 9;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 && get_elaps_frames() >= 40 )
              goto LABEL_959;
            if ( process() )
              set_seq(0);
            if ( get_subseq() )
              return;
            if ( get_frame() == 2 && skills_1[9] >= 2 && get_frame_time() >= 4 )
              next_frame();
            if ( get_frame_time() || get_frame() != 3 )
              return;
            //shake_camera(5.0);
            play_sfx(17);
            t[0] = -95.0;
            t[1] = 100.0;
            if ( skills_1[9] < 4 )
            {
              t[2] = 0.0;
              addbullet(this, NULL, 831, x - 100.0, y - 320.0, 1, 1, t, 4);
            }
            else
            {
              t[2] = 3.0;
              addbullet(this, NULL, 831, x - 110.0, y - 380.0, 1, 1, t, 4); 
            }
            goto LABEL_2248;
          case 590:
            sub10func();
            field_18C = 14;
            if ( get_subseq() == 1 && get_elaps_frames() >= 3 * (11 - (char)skills_1[14]) )
              goto LABEL_1740;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() )
            {
              if ( get_frame() == 5 && get_frame_time() >= 11 - (char)skills_1[14] )
                next_frame();
              if ( !get_frame_time() && get_frame() == 6 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 832, (double)get_pframe()->extra1[4] + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              }
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              return;
            //shake_camera(5.0);
            play_sfx(19);
            /*
            v1351 = 0.0;
            do
            {
              *(float *)&v1367 = -40.0 - /*get_MT_range(30)*//*30.0;
              v1368 = get_MT_range(6) + 65.0;
              v1369 = 2.0;
              v949 = -*(float *)&v1367;
              v950 = (1 - 2 * (sin_deg(v949) >= 0.0));
              v951 = -*(float *)&v1367;
              v952 = sin_deg(v951) * 20.0 + y - 150.0;
              v953 = v952;
              v954 = -*(float *)&v1367;
              v955 = cos_deg(v954) * 60.0 + x;
              addbullet(this, NULL, 832, v955, v953, 1, v950, (int)&v1367, 3);
              v1351 = v1351 + 1.0;
            }
            while ( v1351 < 2.0 );
            v1352 = 0.0;
            do
            {
              *(float *)&v1367 = /*get_MT_range(30)*//*30.0 + 40.0;
              v1368 = get_MT_range(6) + 65.0;
              v1369 = 2.0;
              v956 = -*(float *)&v1367;
              v957 = (1 - 2 * (sin_deg(v956) >= 0.0));
              v958 = -*(float *)&v1367;
              v959 = sin_deg(v958) * 20.0 + y - 150.0;
              v960 = v959;
              v961 = -*(float *)&v1367;
              v962 = cos_deg(v961) * 60.0 + x;
              addbullet(this, NULL, 832, v962, v960, 1, v957, (int)&v1367, 3);
              v1352 = v1352 + 1.0;
            }
            while ( v1352 < 1.0 );
            v1353 = 0.0;
            do
            {
              *(float *)&v1367 = -40.0 - /*get_MT_range(30)*//*30.0;
              v1368 = get_MT_range(6) + 65.0;
              v1369 = 2.0;
              v963 = -*(float *)&v1367;
              v964 = sin_deg(v963) >= 0.0;
              v1373 = x;
              v965 = (1 - 2 * v964);
              v966 = -*(float *)&v1367;
              v967 = sin_deg(v966) * 20.0 + y - 150.0;
              v968 = v967;
              v969 = -*(float *)&v1367;
              v970 = cos_deg(v969);
              v971 = v1373 - v970 * 60.0;
              addbullet(this, NULL, 832, v971, v968, -1, v965, (int)&v1367, 3);
              v1353 = v1353 + 1.0;
            }
            while ( v1353 < 2.0 );
            v1354 = 0.0;
            do
            {
              *(float *)&v1367 = /*get_MT_range(30)*//*30.0 + 40.0;
              v1368 = get_MT_range(6) + 65.0;
              v1369 = 2.0;
              v972 = -*(float *)&v1367;
              v973 = sin_deg(v972) >= 0.0;
              v1373 = x;
              v974 = (1 - 2 * v973);
              v975 = -*(float *)&v1367;
              v976 = sin_deg(v975) * 20.0 + y - 150.0;
              v977 = v976;
              v978 = -*(float *)&v1367;
              v979 = cos_deg(v978);
              v980 = v1373 - v979 * 60.0;
              addbullet(this, NULL, 832, v980, v977, -1, v974, (int)&v1367, 3);
              v1354 = v1354 + 1.0;
            }
            while ( v1354 < 1.0 );
            *(float *)&v1367 = 0.0;
            v1368 = 0.0;
            v1369 = 1.0;
            addbullet(this, NULL, 832, x, y, dir, 1, (int)&v1367, 3);
            v1368 = 25.0;
            v1369 = 1.0;
            v1355 = 0.0;
            do
            {
              *(float *)&v1367 = (get_MT_range(40) - 20) + v1355 * 36.0;
              v981 = -*(float *)&v1367;
              v982 = sin_deg(v981) > 0.0;
              addbullet(this, NULL, 831, x, y, dir, (1 - 2 * v982), (int)&v1367, 3);
              v1355 = v1355 + 1.0;
            }
            while ( v1355 < 10.0 );
            */
            field_7FC = 0.0;
            field_8A0 += 180;
            if ( skills_1[14] >= 2 )
              field_8A0 += 240;
            if ( skills_1[14] >= 3 )
              field_8A0 += 280;
            if ( skills_1[14] >= 4 )
              field_8A0 += 310;
            if ( field_8A0 > 60 * skills_1[14] + 320 )
              field_8A0 = 60 * skills_1[14] + 320;
            field_188 = 0;
            goto LABEL_2248;
          case 591:
            sub10func();
            field_18C = 14;
            if ( get_subseq() == 1 && get_elaps_frames() >= 4 * (11 - (char)skills_1[14]) )
              goto LABEL_1740;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() )
            {
              if ( get_frame() == 5 && get_frame_time() >= 28 - 3 * (char)skills_1[14] )
                next_frame();
              if ( !get_frame_time() && get_frame() == 6 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 832, (double)get_pframe()->extra1[4] + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              }
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              //shake_camera(5.0);
              play_sfx(19);
              /*
              v1356 = 0.0;
              do
              {
                *(float *)&v1364 = -40.0 - /*get_MT_range(30)*//*30.0;
                v1365 = get_MT_range(6) + 65.0;
                v1366 = 2.0;
                v988 = -*(float *)&v1364;
                v989 = (1 - 2 * (sin_deg(v988) >= 0.0));
                v990 = -*(float *)&v1364;
                v991 = sin_deg(v990) * 20.0 + y - 150.0;
                v992 = v991;
                v993 = -*(float *)&v1364;
                v994 = cos_deg(v993) * 60.0 + x;
                addbullet(this, NULL, 832, v994, v992, 1, v989, (int)&v1364, 3);
                v1356 = v1356 + 1.0;
              }
              while ( v1356 < 2.0 );
              v1357 = 0.0;
              do
              {
                *(float *)&v1364 = /*get_MT_range(30)*//*30.0 + 40.0;
                v1365 = get_MT_range(6) + 65.0;
                v1366 = 2.0;
                v995 = -*(float *)&v1364;
                v996 = (1 - 2 * (sin_deg(v995) >= 0.0));
                v997 = -*(float *)&v1364;
                v998 = sin_deg(v997) * 20.0 + y - 150.0;
                v999 = v998;
                v1000 = -*(float *)&v1364;
                v1001 = cos_deg(v1000) * 60.0 + x;
                addbullet(this, NULL, 832, v1001, v999, 1, v996, (int)&v1364, 3);
                v1357 = v1357 + 1.0;
              }
              while ( v1357 < 1.0 );
              v1358 = 0.0;
              do
              {
                *(float *)&v1364 = -40.0 - /*get_MT_range(30)*//*30.0;
                v1365 = get_MT_range(6) + 65.0;
                v1366 = 2.0;
                v1002 = -*(float *)&v1364;
                v1003 = sin_deg(v1002) >= 0.0;
                v1373 = x;
                v1004 = (1 - 2 * v1003);
                v1005 = -*(float *)&v1364;
                v1006 = sin_deg(v1005) * 20.0 + y - 150.0;
                v1007 = v1006;
                v1008 = -*(float *)&v1364;
                v1009 = cos_deg(v1008);
                v1010 = v1373 - v1009 * 60.0;
                addbullet(this, NULL, 832, v1010, v1007, -1, v1004, (int)&v1364, 3);
                v1358 = v1358 + 1.0;
              }
              while ( v1358 < 2.0 );
              v1359 = 0.0;
              do
              {
                *(float *)&v1364 = /*get_MT_range(30)*//*30.0 + 40.0;
                v1365 = get_MT_range(6) + 65.0;
                v1366 = 2.0;
                v1011 = -*(float *)&v1364;
                v1012 = sin_deg(v1011) >= 0.0;
                v1373 = x;
                v1013 = (1 - 2 * v1012);
                v1014 = -*(float *)&v1364;
                v1015 = sin_deg(v1014) * 20.0 + y - 150.0;
                v1016 = v1015;
                v1017 = -*(float *)&v1364;
                v1018 = cos_deg(v1017);
                v1019 = v1373 - v1018 * 60.0;
                addbullet(this, NULL, 832, v1019, v1016, -1, v1013, (int)&v1364, 3);
                v1359 = v1359 + 1.0;
              }
              while ( v1359 < 1.0 );
              *(float *)&v1364 = 0.0;
              v1365 = 0.0;
              v1366 = 1.0;
              addbullet(this, NULL, 832, x, y, dir, 1, (int)&v1364, 3);
              v1365 = 25.0;
              v1366 = 1.0;
              v1360 = 0.0;
              do
              {
                *(float *)&v1364 = (get_MT_range(40) - 20) + v1360 * 36.0;
                v1020 = -*(float *)&v1364;
                v1021 = sin_deg(v1020) > 0.0;
                addbullet(this, NULL, 831, x, y, dir, (1 - 2 * v1021), (int)&v1364, 3);
                v1360 = v1360 + 1.0;
              }
              while ( v1360 < 10.0 );
              */
              field_7FC = 0.0;
              field_8A0 += 270;
              if ( skills_1[14] >= 2 )
                field_8A0 += 360;
              if ( skills_1[14] >= 3 )
                field_8A0 += 420;
              if ( skills_1[14] >= 4 )
                field_8A0 += 465;
              if ( field_8A0 > 60 * (skills_1[14] + 8) )
                field_8A0 = 60 * (skills_1[14] + 8);
              field_188 = 0;
LABEL_2248:
              spell_energy_spend(200, 60);
              add_card_energy(50);
              field_190 = 1;
            }
            return;
          case 599:
            if ( field_7D0 > 0 && get_frame() < 7 && field_7D0 < 12 )
            {
              /*
              v1024 = MT_getnext() % 0x23u;
              field_7D4 = v1024;
              *(float *)&v1420 = (double)(-20 - v1024);
              v1421 = (double)(signed __int16)(MT_getnext() % 5u + 10);
              v1422 = 0.0;
              v1025 = dir;
              v1026 = (double)(20 * (char)v1025 * (field_7D0 + 1)) + x;
              addbullet(this, NULL, 807, v1026, y, v1025, 1, (int)&v1420, 3);
              *(float *)&v1420 = (double)(MT_getnext() % 0x168u);
              v1421 = 0.0;
              v1422 = 1.0;
              v1027 = dir;
              v1028 = (double)(20 * (char)v1027 * (field_7D0 + 1)) + x;
              addbullet(this, NULL, 801, v1028, y, v1027, 1, (int)&v1420, 3);
              */
              if ( field_7D0 == 1 )
              {
                play_sfx(0);
                spell_energy_spend(200, 60);
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
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115,  x - (double)(33 * (char)dir), y + 170.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 4 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 890, (double)(66 * (char)dir) + x, y + 67.0, dir, 1, t, 3);
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 5 )
                  {
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 0.0;
                    addbullet(this, NULL, 850, x - (double)(55 * (char)dir), y + 230.0, dir, 1, t, 3);
                    play_sfx(50);
                  }
                  if ( !get_frame_time() && get_frame() == 10 )
                    play_sfx(3);
                }
              }
            }
            return;
          case 601:
            sub10func();
            sub_46AB50(5, 2);
            if ( field_7D0 > 0 )
            {
              field_7D0 = field_7D0 + 1;
              field_7DC = field_7DC + 0.5;
              if ( field_7D0 % 2 == 1 && field_7D2 < 20 )
              {
                /*
                v1042 = (double)(10 * field_7D0);
                *(float *)&v1384 = sin_deg(v1042) * field_7DC;
                v1385 = 25.0;
                v1386 = 1.0;
                v1043 = dir;
                v1044 = y + 117.0;
                v1045 = v1044;
                v1046 = (double)(63 * (char)v1043) + x;
                addbullet(this, NULL, 851, v1046, v1045, v1043, 1, (int)&v1384, 3);
                v1047 = (double)(10 * field_7D0);
                *(float *)&v1384 = sin_deg(v1047) * -field_7DC;
                v1385 = 25.0;
                v1386 = 1.0;
                v1048 = dir;
                v1049 = y + 117.0;
                v1050 = v1049;
                v1051 = (double)(63 * (char)v1048) + x;
                addbullet(this, NULL, 851, v1051, v1050, v1048, 1, (int)&v1384, 3);
                v1386 = 2.0;
                v1052 = dir;
                v1053 = y + 117.0;
                v1054 = v1053;
                v1055 = (double)(63 * (char)v1052) + x;
                addbullet(this, NULL, 851, v1055, v1054, v1052, 1, (int)&v1384, 3);
                */
                play_sfx(2);
                ++field_7D2;
              }
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 60 )
              goto LABEL_1740;
            if ( process() )
              set_seq(0);
            //if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            //  get_elaps_frames() = 0;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() != 3 )
              goto LABEL_2361;
            sub_4834E0(40);
            scene_play_sfx(23);
            goto LABEL_2360;
          case 602:
            sub_46AB50(5, 2);
            if ( !get_subseq() || get_subseq() == 2 )
              sub10func();
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(30 * (char)dir) + x, y + 95.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( get_subseq() != 1 )
              goto LABEL_2415;
            if ( field_190 )
            {
              if ( ++field_7D0 >= 8 )
              {
                field_190 = 0;
                field_7D0 = 0;
              }
            }
            if ( !get_frame() && !get_frame_time() )
              play_sfx(52);
            v_inerc = v_inerc - v_force;
            if ( get_elaps_frames() >= 180 )
            {
              set_seq(9);
              v_force = 0.5;
              return;
            }
            if ( !(get_elaps_frames() % 5) )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 3.0;
              addbullet(this, NULL, 852, x, y + 100.0, dir, 1, t, 3);
            }
            if ( char_on_ground_down() )
            {
              next_subseq();
              goto LABEL_196;
            }
LABEL_2415:
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              //get_elaps_frames() = 0;
              h_inerc = 2.0;
              v_inerc = 3.5;
              v_force = 0.050000001;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 852, x, y + 100.0, dir, -1, t, 3);
              t[0] = 30.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 852, cos_deg(-t[0]) * 150.0 * (double)dir + x, sin_deg(30.0) * 150.0 + y + 100.0, dir, 1, t, 3);
              t[0] = -90.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 852, cos_deg(-t[0]) * 150.0 * (double)dir + x, sin_deg(-90.0) * 150.0 + y + 100.0, dir, 1, t, 3);
              t[0] = 150.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 852, cos_deg(-t[0]) * 150.0 * (double)dir + x, sin_deg(150.0) * 150.0 + y + 100.0, dir, 1, t, 3);
              /*
              v1361 = 0.0;
              v1102 = (float)0.0;
              do
              {
                *(float *)&v1370 = v1102 * 90.0 + 45.0;
                v1371 = 100.0;
                v1372 = 2.0;
                v1103 = dir;
                v1104 = sin_deg(*(float *)&v1370) * 100.0 + y + 100.0;
                v1105 = v1104;
                v1106 = -*(float *)&v1370;
                v1107 = cos_deg(v1106) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 852, v1107, v1105, v1103, 1, (int)&v1370, 3);
                v1361 = v1361 + 1.0;
                v1102 = v1361;
              }
              while ( v1361 < 4.0 );
              */
            }
            return;
          case 603:
            sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() == 1 && get_elaps_frames() > 120 || get_subseq() == 2 && get_elaps_frames() > 60 )
              goto LABEL_1740;
            if ( process() )
              set_seq(0);
            //if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            //  get_elaps_frames() = 0;
            if ( !get_subseq() && get_frame() == 8 && !get_frame_time() )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(20 * (char)dir) + x, y + 240.0, dir, 1);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 853, x + 20.0, y + 240.0, dir, 1, t, 3);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              play_sfx(53);
            }
            return;
          case 604:
            sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() == 1 && get_elaps_frames() >= 90 || get_subseq() == 2 && get_elaps_frames() >= 90 )
              goto LABEL_1740;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(10 * (char)dir), y + 85.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 854, x, y, dir, -1, t, 3);
              t[1] = 0.30000001;
              t[2] = 8.0;
              addbullet(this, NULL, 854, x, y, dir, -1, t, 3);
              play_sfx(55);
              //get_elaps_frames() = 0;
            }
            return;
          case 605:
            sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() != 1 || get_elaps_frames() % 10 )
              goto LABEL_2467;
            if ( field_7DC < 10.0 )
            {
              /*
              v64 = 12;
              do
              {
                *(float *)&v1435 = /*get_MT_range(360)*//*360.0;
                v1436 = /*get_MT_range(15)*//*15.0 + 5.0;
                v1437 = field_7DC;
                v1127 = y + 100.0;
                addbullet(this, NULL, 855, x, v1127, dir, 1, (int)&v1435, 3);
                --v64;
              }
              while ( v64 );
              */
              play_sfx(59);
              t[0] = 0.0;
              t[1] = 0.5;
              t[2] = field_7DC + 5.0;
              addbullet(this, NULL, 855, x, y + 100.0, dir, 1, t, 3);
              field_7DC = field_7DC + 1.0;
LABEL_2467:
              if ( process() )
                set_seq(0);
              if ( get_subseq() == /*(_WORD)v64*/12 && get_frame_time() == /*(_WORD)v64*/12 && get_frame() == 4 )
              {
                field_7DC = 5.0;
                sub_4834E0(40);
                scene_play_sfx(23);
                yc = y + 75.0;
                v1131 = x - (double)(51 * (char)dir);
LABEL_2473:
                scene_add_effect(this, 115, v1131, yc, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
            }
            else
            {
              field_890 = 1200;
              play_sfx(60);
              /*
              v1362 = 0.0;
              v1121 = (float)0.0;
              do
              {
                *(float *)&v1374 = 72.0 * v1121;
                v1375 = 0.0;
                v1376 = v1121;
                v1122 = y + 100.0;
                addbullet(this, NULL, 855, x, v1122, dir, 1, (int)&v1374, 3);
                v1362 = v1362 + 1.0;
                v1121 = v1362;
              }
              while ( v1362 < 5.0 );
              v1363 = 0.0;
              v1123 = (float)0.0;
              do
              {
                *(float *)&v1374 = 72.0 * v1123;
                v1375 = 25.0;
                v1376 = v1123 + 20.0;
                v1124 = y + 100.0;
                addbullet(this, NULL, 855, x, v1124, dir, 1, (int)&v1374, 3);
                v1363 = v1363 + 1.0;
                v1123 = v1363;
              }
              while ( v1363 < 5.0 );
              v1125 = 0;
              do
              {
                *(float *)&v1374 = /*get_MT_range(360)*//*360.0;
                v1375 = /*get_MT_range(15)*//*15.0 + 15.0;
                v1376 = (double)(v1125 % 5u) + 5.0;
                v1126 = y + 100.0;
                addbullet(this, NULL, 855, x, v1126, dir, 1, (int)&v1374, 3);
                ++v1125;
              }
              while ( v1125 < 30 );
              */
              next_subseq();
            }
            return;
          case 606:
            sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() == 1 && get_elaps_frames() >= 32 )
              goto LABEL_959;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(30 * (char)dir) + x, y + 95.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 856, x, y + 210.0, dir, 1, t, 3);
              play_sfx(12);
              field_8A2 = 360;
            }
            return;
          case 607:
            sub10func();
            sub_46AB50(5, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(30 * (char)dir) + x, y + 100.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 9 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 857, x, y + 210.0, dir, -1, t, 3);
                t[0] = 180.0;
                t[2] = 1.0;
                addbullet(this, NULL, 857, x, y + 210.0, dir, -1, t, 3);
                play_sfx(57);
              }
            }
            return;
          case 610:
            sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() == 1 && get_elaps_frames() >= 48 )
              goto LABEL_1740;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 860, x, 0.0, dir, -1, t, 3);
              play_sfx(58);
            }
            if ( get_subseq() || get_frame_time() || get_frame() != 2 )
              return;
            sub_4834E0(40);
            scene_play_sfx(23);
            yc =  y + 86.0;
            v1131 = (double)(13 * (char)dir) + x;
            goto LABEL_2473;
          case 611:
            sub10func();
            sub_46AB50(5, 2);
            if ( field_7D0 > 0 )
            {
              field_7D0 = field_7D0 + 1;
              field_7DC = field_7DC + 0.5;
              if ( field_7D0 % 8 == 1 && field_7D2 < 6 )
              {
                t[0] = -80.0;
                t[1] = 25.0;
                t[2] = 0.0;
                addbullet(this, NULL, 861, (double)(63 * (char)dir) + x, y + 117.0, dir, 1, t, 3);
                t[0] = 80.0;
                t[1] = 25.0;
                t[2] = 1.0;
                addbullet(this, NULL, 861, (double)(63 * (char)dir) + x, y + 117.0, dir, 1, t, 3);
                play_sfx(64);
                ++field_7D2;
              }
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 60 )
              goto LABEL_1740;
            if ( process() )
              set_seq(0);
            //if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            //  get_elaps_frames() = 0;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
LABEL_2360:
                scene_add_effect(this, 115, (double)(33 * (char)dir) + x, y + 188.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
LABEL_2361:
              if ( !get_frame_time() && get_frame() == 4 )
                field_7D0 = 1;
            }
            return;
          case 612:
            sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() == 1 && get_elaps_frames() >= 40 )
              goto LABEL_959;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(30 * (char)dir) + x, y + 100.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 9 )
              {
                //shake_camera(5.0);
                play_sfx(17);
                tt[0] = -90.0;
                tt[1] = 100.0;
                tt[2] = 0.0;
                tt[3] = 0.0;
                addbullet(this, NULL, 862, x + 150.0, y - 512.0, 1, -1, tt, 4);
                addbullet(this, NULL, 862, x - 150.0, y - 512.0, -1, -1, tt, 4);
              }
            }
            return;
          case 613:
            sub10func();
            sub_46AB50(5, 2);
            if ( get_subseq() == 1 && get_elaps_frames() > 40 )
              goto LABEL_959;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 3.0;
                addbullet(this, NULL, 863, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              }
              if ( !get_frame_time() && get_frame() == 8 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(20 * (char)dir) + x, y + 240.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
                play_sfx(53);
              }
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              tt[0] = 0.0;
              tt[1] = 0.0;
              tt[2] = 5.0;
              tt[3] = 0.0 - 90.0;
              addbullet(this, NULL, 863, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5] + 50.0, dir, 1, tt, 4);
            }
            return;
          case 651:
            v752 = 2;
            sub_46AB50(5, 2);
            if ( get_subseq() == 3 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_2371;
            }
            if ( field_7D0 > 0 )
            {
              field_7D0 = field_7D0 + 1;
              field_7DC = field_7DC + 0.5;
              if ( field_7D0 % 2 == 1 && field_7D2 < 20 )
              {
                t[0] = sin_deg((double)(10 * field_7D0)) * field_7DC;
                t[1] = 25.0;
                t[2] = 1.0;
                addbullet(this, NULL, 851, (double)(71 * (char)dir) + x, y + 115.0, dir, 1, t, 3);
                t[0] = sin_deg((double)(10 * field_7D0)) * -field_7DC;
                t[1] = 25.0;
                t[2] = 1.0;
                addbullet(this, NULL, 851, (double)(71 * (char)dir) + x, y + 115.0, dir, 1, t, 3);
                t[2] = 2.0;
                addbullet(this, NULL, 851, (double)(71 * (char)dir) + x, y + 115.0, dir, 1, t, 3);
                play_sfx(2);
                ++field_7D2;
              }
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 60 )
            {
LABEL_1740:
              next_subseq();
              return;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              //if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              //  get_elaps_frames() = 0;
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                goto LABEL_846;
            }
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(41 * (char)dir) + x, y + 192.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 4 )
                field_7D0 = 1;
            }
            if ( get_subseq() == 2 )
              goto LABEL_1955;
            return;
          case 661:
            v752 = 2;
            sub_46AB50(5, 2);
            if ( get_subseq() == 3 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_2371:
                reset_forces();
                y = getlvl_height();
                set_subseq(3);
                return;
              }
            }
            if ( field_7D0 > 0 )
            {
              field_7D0 = field_7D0 + 1;
              field_7DC = field_7DC + 0.5;
              if ( field_7D0 % 8 == 1 && field_7D2 < 6 )
              {
                t[0] = /*get_MT_range(50)*/50.0 * 0.1000000014901161 - 80.0;
                t[1] = 25.0;
                t[2] = 0.0;
                addbullet(this, NULL, 861, (double)(63 * (char)dir) + x, y + 117.0, dir, 1, t, 3);
                t[0] = /*get_MT_range(50)*/50.0 * 0.1000000014901161 + 80.0;
                t[1] = 25.0;
                t[2] = 1.0;
                addbullet(this, NULL, 861, (double)(63 * (char)dir) + x, y + 117.0, dir, 1, t, 3);
                play_sfx(64);
                ++field_7D2;
              }
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 60 )
              goto LABEL_959;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_2762;
            //if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            //  get_elaps_frames() = 0;
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 3 )
            {
LABEL_2762:
              if ( !get_subseq() && !get_frame_time() )
              {
                if ( get_frame() == 3 )
                {
                  sub_4834E0(40);
                  scene_play_sfx(23);
                  scene_add_effect(this, 115, (double)(41 * (char)dir) + x, y + 192.0, dir, 1);
                  sub_469450(0, 0, 60);
                  sub_483570();
                  weather_forecast_next();
                }
                if ( !get_frame_time() && get_frame() == 4 )
                  field_7D0 = 1;
              }
              if ( get_subseq() == 2 )
              {
LABEL_1955:
                if ( !get_frame_time() )
                {
                  v639 = get_frame() == v752;
LABEL_1524:
                  if ( v639 )
                    v_force = 0.5;
                }
              }
            }
            else
            {
LABEL_886:
              set_seq(9);
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
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
              }
              if ( !get_frame_time() && get_frame() == 5 )
              {
                scene_play_sfx(27);
                field_49A = 0;
              }
            }
            return;
          case 710:
            sub10func();
            if ( process() )
              goto LABEL_142;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  field_7D0 = 120;
                  field_7D2 = 180;
                  field_7DC = 8.0;
                  break;
                case 1:
                  field_7D0 = 120;
                  field_7D2 = 150;
                  field_7DC = 12.0;
                  break;
                case 2:
                  field_7D0 = 180;
                  field_7D2 = 120;
                  field_7DC = 16.0;
                  break;
                case 3:
                  field_7D0 = 180;
                  field_7D2 = 120;
                  field_7DC = 20.0;
                  break;
                default:
                  break;
              }
            }
            if ( !get_subseq() && !(get_elaps_frames() % 2) )
            {
              t[0] = /*get_MT_range(360)*/360.0;
              t[1] = /*get_MT_range(400)*/400.0 + 200.0;
              t[2] = 0.0;
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
              {
                t[0] = /*get_MT_range(360)*/360.0;
                t[1] = /*get_MT_range(400)*/400.0 + 200.0;
                t[2] = 0.0;
                addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              }
              if ( get_elaps_frames() >= field_7D0 )
                goto LABEL_2618;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(11);
              tt[0] = 0.0;
              tt[1] = 0.0;
              tt[2] = 3.0;
              tt[3] = field_7DC;
              addbullet(this, NULL, 900, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
            }
            if ( get_subseq() == 3 && get_elaps_frames() >= field_7D2 )
              next_subseq();
            return;
          case 720:
            if ( get_subseq() <= 2 || get_subseq() == 6 )
            {
              sub10func();
            }
            else if ( get_subseq() > 3 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                move_val = 6;
LABEL_195:
                //set_subseq(move_val);
                set_seq(move_val);
                goto LABEL_196;
              }
            }
            if ( !get_subseq() && !(get_elaps_frames() % 2) )
            {
              t[0] = /*get_MT_range(360)*/360.0;
              t[1] = /*get_MT_range(400)*/400.0 + 200.0;
              t[2] = 1.0;
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_subseq() != 1 )
              goto LABEL_2763;
            if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
            {
              t[0] = /*get_MT_range(360)*/360.0;
              t[1] = /*get_MT_range(400)*/400.0 + 200.0;
              t[2] = 1.0;
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_elaps_frames() >= field_7D0 )
            {
LABEL_2618:
              next_subseq();
              flip_with_force();
            }
            else
            {
LABEL_2763:
              if ( get_subseq() != 3 )
                goto LABEL_2764;
              if ( !(get_elaps_frames() % field_7D4) && field_7DC > 0.0 )
              {
                play_sfx(5);
                sub_486FD0(180.0, -180.0);
                tt[0] = field_7F0;
                tt[1] = 150.0;
                tt[2] = 3.0;
                tt[3] = dash_angle;
                /*
                v1237 = (field_7DC & 0x80000001) == 0;
                if ( (field_7DC & 0x80000001) < 0 )
                  v1237 = (((field_7DC & 0x80000001) - 1) | 0xFFFFFFFE) == -1;
                if ( v1237 )
                  t[3] = -dash_angle;
                */
                addbullet(this, NULL, 910, cos_deg(-tt[0]) * tt[1] * (double)dir + x, sin_deg(-tt[0]) * tt[1] + y + 100.0, dir, 1, tt, 4);
                field_7DC = field_7DC - 1.0;
              }
              if ( dir == 1 )
              {
                if ( x <= 640.0 )
                  h_inerc = h_inerc + 0.05000000074505806;
                else
                  h_inerc = h_inerc - 0.05000000074505806;
              }
              else if ( x >= 640.0 )
              {
                h_inerc = h_inerc + 0.02500000037252903;
              }
              else
              {
                h_inerc = h_inerc - 0.02500000037252903;
              }
              if ( h_inerc > 6.0 )
                h_inerc = 6.0;
              if ( h_inerc < -6.0 )
                h_inerc = -6.0;
              if ( y >= 175.0 )
                v_inerc = v_inerc - 0.01999999955296516;
              else
                v_inerc = v_inerc + 0.01999999955296516;
              if ( v_inerc > 4.5 )
                v_inerc = 4.5;
              if ( v_inerc < -4.5 )
                v_inerc = -4.5;
              if ( get_elaps_frames() <= field_7D2 )
              {
LABEL_2764:
                if ( process() )
                {
LABEL_1155:
                  set_seq(0);
                }
                else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  switch ( settings_get()->get_difficulty() )
                  {
                    case 0:
                      field_7DC = 3.0;
                      field_7D0 = 120;
                      field_7D2 = 300;
                      goto LABEL_2680;
                    case 1:
                      field_7DC = 5.0;
                      field_7D0 = 120;
                      field_7D2 = 360;
LABEL_2680:
                      field_7D4 = 60;
                      //field_7DC = v1252;
                      dash_angle = 180.0;
                      return;
                    case 2:
                      field_7DC = 5.0;
                      field_7D0 = 120;
                      field_7D2 = 420;
                      field_7D4 = 60;
                      goto LABEL_2676;
                    case 3:
                      field_7DC = 7.0;
                      field_7D0 = 120;
                      field_7D2 = 480;
                      field_7D4 = 40;
LABEL_2676:
                      //field_7DC = v1251;
                      dash_angle = 540.0;
                      break;
                    default:
                      return;
                  }
                }
              }
              else
              {
                next_subseq();
                v_force = 0.15000001;
              }
            }
            return;
          case 721:
            if ( get_subseq() <= 1 )
            {
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
              {
                if ( x >= 640.0 )
                  field_7EC = 580.0 - /*get_MT_range(360)*/360.0;
                else
                  field_7EC = /*get_MT_range(360)*/360.0 + 700.0;
                field_7E8 = /*get_MT_range(260)*/260.0 + 60.0;
                if ( field_7EC >= (double)x )
                  dir = 1;
                else
                  dir = -1;
              }
              h_inerc = (field_7EC - x) * 0.01999999955296516 * (double)dir;
              v_inerc = 0.01999999955296516 * (field_7E8 - y);
              if ( h_inerc > 6.0 )
                h_inerc = 6.0;
              if ( v_inerc > 6.0 )
                v_inerc = 6.0;
              if ( (sqrt(field_7EC - x) + sqrt(field_7E8 - y)) <= 900.0 )
                goto LABEL_959;
            }
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc * 0.9800000190734863;
              v_inerc = 0.9800000190734863 * v_inerc;
            }
            if ( process() )
            {
              set_seq(720);
LABEL_2701:
              set_subseq(3);
            }
            return;
          case 730:
            if ( get_subseq() == 1 )
            {
              if ( get_elaps_frames() >= 32 )
                goto LABEL_959;
            }
            else if ( get_subseq() != 2 )
            {
              goto LABEL_2712;
            }
            v_inerc = v_inerc - v_force;
            if ( v_inerc < 0.0 )
              v_inerc = 0.0;
            h_inerc = (640.0 - x) * -0.1000000014901161;
            if ( h_inerc > 10.0 )
              h_inerc = 10.0;
            if ( h_inerc < -10.0 )
              h_inerc = -10.0;
LABEL_2712:
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              dir = -1;
              v_inerc = 15.0;
              v_force = 0.5;
            }
            break;
          default:
            goto LABEL_2759;
        }
      }
      return;
    }
    if ( sq == 500 )
    {
      sub10func();
      field_18C = 0;
      if ( !keyDown(INP_B) )
        not_charge_attack = 0;
      if ( h_inerc < 0.0 )
      {
        h_inerc = h_inerc + 0.75;
        if ( h_inerc > 0.0 )
          h_inerc = 0.0;
      }
      if ( process() )
        set_seq(0);
      if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
      {
        if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
        {
          if ( skills_1[0] < 3 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 15.0;
            addbullet(this, NULL, 810, (double)(60 * (char)dir) + x, y + 114.0, dir, 1, t, 3);
          }
          else
          {
            t[0] = 0.0;
            t[1] = 15.0;
            t[2] = 6.0;
            addbullet(this, NULL, 810, (double)(60 * (char)dir) + x, y + 114.0, dir, 1, t, 3);
          }
          scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
          add_card_energy(50);
          spell_energy_spend(200, 60);
          play_sfx(3);
        }
        if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
        {
          t[0] = 0.0;
          t[1] = 15.0;
          t[2] = 1.0;
          addbullet(this, NULL, 810, (double)(60 * (char)dir) + x, 114.0 + y, dir, 1, t, 3);
LABEL_1390:
          scene_add_effect(this, 128, (double)(200 * (char)dir) + x, y, dir, -1);
          spell_energy_spend(200, 60);
          add_card_energy(50);
          h_inerc = -10.0;
          play_sfx(3);
        }
      }
      else
      {
LABEL_142:
        set_seq(0);
      }
      return;
    }
    switch ( sq )
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
        if ( !keyDown(INP_A) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          set_seq(0);
          return;
        }
        if ( get_subseq() || get_frame_time() )
          goto LABEL_705;
        if ( get_frame() != 3 )
          goto LABEL_702;
        if ( not_charge_attack == 1 )
        {
          next_subseq();
          scene_add_effect(this, 62, x - (double)(15 * (char)dir), y + 130.0, dir, 1);
        }
        else
        {
          t[0] = 0.0;
          t[1] = 0.0;
          t[2] = 0.0;
          addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
LABEL_702:
          if ( !get_frame_time() && get_frame() == 5 )
          {
            scene_play_sfx(27);
            field_49A = 0;
          }
LABEL_705:
          if ( get_subseq() == 1 && !get_frame_time() )
          {
            if ( get_frame() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            }
            if ( !get_frame_time() && get_frame() == 2 )
            {
              scene_play_sfx(27);
              field_49A = 0;
            }
          }
        }
        return;
      case 302:
        sub10func();
        if ( false /*get_true(1)*/)
          return;
        if ( !keyDown(INP_A) )
          not_charge_attack = 0;
        h_inerc = h_inerc - 0.5;
        if ( h_inerc < 0.0 )
          h_inerc = 0.0;
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_522;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_732;
        if ( get_frame() != 4 )
          goto LABEL_729;
        if ( not_charge_attack == 1 )
        {
          next_subseq();
          scene_add_effect(this, 62, x - (double)(65 * (char)dir), y + 165.0, dir, 1);
        }
        else
        {
          h_inerc = 10.0;
LABEL_729:
          if ( !get_frame_time() && get_frame() == 6 )
            scene_play_sfx(29);
LABEL_732:
          if ( get_subseq() == 1 && !get_frame_time() )
          {
            if ( get_frame() == 1 )
              h_inerc = 13.0;
            if ( !get_frame_time() && get_frame() == 3 )
            {
              scene_play_sfx(29);
              /*
              v1453 = 0.0;
              v261 = 0;
              v1452 = 12.0;
              do
              {
                *(float *)&v1451 = (v261 + /*get_MT_range(30)*//*30.0);
                if ( *(float *)&v1451 < 0.0 || *(float *)&v1451 < 180.0 )
                  field_7D0 = 1;
                else
                  field_7D0 = -1;
                v262 = LOBYTE(field_7D0);
                v263 = dir;
                v264 = -*(float *)&v1451;
                v265 = sin_deg(v264) * 50.0 * 0.25 + y;
                v266 = v265;
                v267 = -*(float *)&v1451;
                v268 = cos_deg(v267) * 50.0 + x + (double)(77 * dir);
                addbullet(this, NULL, 820, v268, v266, v263, v262, (int)&v1451, 3);
                v261 += 45;
              }
              while ( v261 < 360 );
              */
            }
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
          if ( !get_frame_time() && get_frame() == 3 )
            scene_play_sfx(27);
        }
        return;
      case 304:
        sub10func();
        if ( false /*get_true(1)*/)
          return;
        if ( !keyDown(INP_A) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(2);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_763;
        
        if ( get_subseq() )
          goto LABEL_773;
        if ( h_inerc > 0.0 )
        {
          h_inerc = h_inerc - 0.75;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( get_frame_time() || get_frame() != 3 )
          goto LABEL_773;
        if ( not_charge_attack == 1 )
        {
          next_subseq();
          scene_add_effect(this, 62, x, y + 50.0, dir, 1);
        }
        else
        {
          h_inerc = 12.0;
          scene_play_sfx(29);
          
LABEL_773:
          if ( get_subseq() == 1 )
          {
            if ( !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                h_inerc = 15.0;
                scene_play_sfx(29);
                
              }
              if ( !get_frame_time() && get_frame() == 4 )
                h_inerc = 0.0;
            }
            if ( get_frame() >= 2 && get_frame() <= 7 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 10.0 )
                h_inerc = 10.0;
              if ( !(get_elaps_frames() % 10) )
              {
                /*
                v275 = 0;
                v1474 = 0.0;
                v1473 = 10.0;
                do
                {
                  *(float *)&v1472 = (v275 + /*get_MT_range(30)*//*30.0);
                  if ( *(float *)&v1472 < 0.0 || *(float *)&v1472 < 180.0 )
                    field_7D0 = 1;
                  else
                    field_7D0 = -1;
                  v276 = LOBYTE(field_7D0);
                  v277 = dir;
                  v278 = -*(float *)&v1472;
                  v279 = sin_deg(v278) * 50.0 * 0.25 + y;
                  v280 = v279;
                  v281 = -*(float *)&v1472;
                  v282 = cos_deg(v281) * 50.0 + x + (double)(77 * dir);
                  addbullet(this, NULL, 820, v282, v280, v277, v276, (int)&v1472, 3);
                  v275 += 45;
                }
                while ( v275 < 360 );
                */
                
              }
            }
            if ( get_frame() >= 8 )
            {
              h_inerc = h_inerc - 0.300000011920929;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
          }
        }
        return;
      case 305:
        sub10func();
        if ( true /*!get_true(1)*/)
        {
          if ( get_frame() >= 5 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() && get_frame() == 5 )
            scene_play_sfx(29);
        }
        return;
      case 306:
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_805;
        if ( field_190 )
        {
          if ( ++field_7D0 >= 2 && field_194 > 0 )
          {
            field_190 = 0;
            field_7D0 = 0;
          }
        }
        if ( process() )
          set_seq(9);
        if ( !get_frame_time() )
        {
          if ( get_frame() == 1 )
            scene_play_sfx(27);
          if ( !get_frame_time() && get_frame() == 2 )
          {
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 6.0;
            addbullet(this, NULL, 848, (double)(63 * (char)dir) + x, y + 53.0, dir, 1, t, 3);
          }
        }
        return;
      case 307:
        if ( !keyDown(INP_A) )
          not_charge_attack = 0;
        v_inerc = v_inerc - v_force;
        if ( !char_on_ground_down() )
          goto LABEL_823;
        if ( get_frame() >= 12 )
        {
LABEL_805:
          set_seq(10);
          goto LABEL_196;
        }
        v_inerc = 0.0;
LABEL_823:
        if ( process() )
          set_seq(9);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_846;
        if ( get_subseq() || get_frame_time() )
          return;
        if ( get_frame() == 5 )
        {
          play_sfx(18);
          t[0] = -10.0;
          t[1] = 20.0;
          t[2] = 5.0;
          addbullet(this, NULL, 848, (double)(96 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
        }
        if ( get_frame_time() )
          return;
        v293 = get_frame() == 12;
        goto LABEL_835;
      case 308:
        if ( !keyDown(INP_A) )
          not_charge_attack = 0;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_604;
        if ( process() )
          set_seq(9);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_846;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_854;
        if ( get_frame() != 3 || not_charge_attack != 1 )
        {
          if ( get_frame() == 3 )
          {
            scene_play_sfx(28);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 7.0;
            addbullet(this, NULL, 848, (double)(40 * (char)dir) + x, y + 47.0, dir, 1, t, 3);
          }
LABEL_854:
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 1 )
          {
            scene_play_sfx(28);
            h_inerc = -4.0;
            v_inerc = 8.0;
            v_force = 0.5;
            t[0] = 0.0;
            t[1] = 1.0;
            t[2] = 7.0;
            addbullet(this, NULL, 848, (double)(40 * (char)dir) + x, y + 47.0, dir, 1, t, 3);
          }
        }
        else
        {
          next_subseq();
          scene_add_effect(this, 62, (double)(20 * (char)dir) + x, y + 105.0, dir, 1);
        }
        return;
      case 309:
        if ( !keyDown(INP_A) )
          not_charge_attack = 0;
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
        {
LABEL_604:
          set_seq(10);
          goto LABEL_196;
        }
        if ( process() )
          set_seq(9);
        if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
        {
          play_sfx(18);
          h_inerc = h_inerc * 0.5;
          v_inerc = 3.0;
          v_force = 0.0;
          t[0] = -85.0;
          t[1] = 20.0;
          t[2] = 12.0;
          addbullet(this, NULL, 848, (double)(34 * (char)dir) + x, y + 122.0, dir, 1, t, 3);
        }
        if ( get_subseq() == 1 && get_elaps_frames() >= 30 )
        {
          next_subseq();
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
        if ( get_subseq() == 2 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            v_inerc = 0.0;
            y = getlvl_height();
            goto LABEL_886;
          }
        }
        if ( process() )
          set_seq(9);
        return;
      case 320:
        sub10func();
        if ( true /*!get_true(0)*/)
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
          if ( field_190 )
          {
            if ( ++field_7D0 >= 5 && field_194 > 0 )
            {
              field_190 = 0;
              field_7D0 = 0;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 4 )
            {
              scene_play_sfx(28);
              h_inerc = 12.5;
              field_49A = 0;
            }
            if ( !get_frame_time() && get_frame() == 5 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 9.0;
              addbullet(this, NULL, 848, (double)(122 * (char)dir) + x, y + 133.0, dir, 1, t, 3);
            }
          }
        }
        return;
      case 321:
        sub10func();
        if ( true /*!get_true(1)*/)
        {
          if ( get_frame() > 6 )
          {
            h_inerc = h_inerc + 0.5;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
          }
          else
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 6 )
            {
              scene_play_sfx(29);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 10.0;
              addbullet(this, NULL, 848, (double)(101 * (char)dir) + x, y + 111.0, dir, 1, t, 3);
              t[2] = 0.0;
              /*
              v324 = 0;
              v1378 = 12.0;
              do
              {
                *(float *)&v1377 = (v324 + /*get_MT_range(30)*//*30.0);
                if ( *(float *)&v1377 < 0.0 || *(float *)&v1377 < 180.0 )
                  field_7D0 = 1;
                else
                  field_7D0 = -1;
                v325 = LOBYTE(field_7D0);
                v326 = dir;
                v327 = -*(float *)&v1377;
                v328 = sin_deg(v327) * 50.0 * 0.25 + y;
                v329 = v328;
                v330 = -*(float *)&v1377;
                v331 = cos_deg(v330) * 50.0 + x + (double)(101 * dir);
                addbullet(this, NULL, 820, v331, v329, v326, v325, (int)&v1377, 3);
                v324 += 45;
              }
              while ( v324 < 360 );
              */
            }
            if ( !get_frame_time() && get_frame() == 7 )
            {
              h_inerc = h_inerc - 10.0;
              field_49A = 0;
            }
          }
        }
        return;
      case 322:
        sub10func();
        if ( true /*!get_true(1)*/)
        {
          if ( get_frame() > 5 )
          {
            h_inerc = h_inerc - 3.0;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 4 )
            {
              h_inerc = 15.0;
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
        }
        return;
      case 330:
        goto LABEL_674;
      case 400:
        sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( field_7D0 <= 0 )
          goto LABEL_946;
        field_7D0 = field_7D0 + 1;
        if ( get_subseq() )
        {
          if ( (field_7D0 % 3) == 1 && field_7D2 < 5 )
          {
            field_190 = 1;
            add_card_energy(10);
            //a2 = &v1550;
            t[0] = (double)(-15 * field_7D2) + field_7E4 + 30.0;
            t[1] = 12.0;
            t[2] = 0.0;
            x = dir;
            goto LABEL_945;
          }
        }
        else if ( (field_7D0 % 3) == 1 && field_7D2 < 3 )
        {
          field_190 = 1;
          add_card_energy(10);
          //a2 = (int *)&v1733;
          t[0] = (double)(-15 * field_7D2) + field_7E4 + 15.0;
          t[1] = 12.0;
          t[2] = 0.0;
          x = dir;
LABEL_945:
          addbullet(this, NULL, 800, (double)(63 * (char)x) + x, y + 117.0, x, 1, t, 3);
          play_sfx(0);
          ++field_7D2;
          goto LABEL_946;
        }
LABEL_946:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_522;
        if ( get_subseq() || get_frame_time() || get_frame() != 4 )
          goto LABEL_966;
        if ( not_charge_attack == 1 )
        {
          y = y + 100.0;
LABEL_957:
          goto LABEL_958;
        }
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -15.0 )
          field_7E4 = -15.0;
        if ( field_7E4 > 15.0 )
          field_7E4 = 15.0;
        field_7D0 = 1;
        spell_energy_spend(200, 40);
LABEL_966:
        if ( get_subseq() != 1 || get_frame_time() || get_frame() != 1 )
          return;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -15.0 )
          field_7E4 = -15.0;
        if ( field_7E4 <= 15.0 )
          goto LABEL_974;
        v359 = 15.0;
        goto LABEL_973;
      case 401:
        sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( field_7D0 <= 0 )
          goto LABEL_986;
        field_7D0 = field_7D0 + 1;
        if ( get_subseq() )
        {
          if ( (field_7D0 % 3) == 1 && field_7D2 < 5 )
          {
            field_190 = 1;
            add_card_energy(10);
            //a2b = &v1556;
            t[0] = (double)(-15 * field_7D2) + field_7E4 + 30.0;
            t[1] = 12.0;
            t[2] = 0.0;
            goto LABEL_985;
          }
        }
        else if ( (field_7D0 % 3) == 1 && field_7D2 < 3 )
        {
          field_190 = 1;
          add_card_energy(10);
          //a2b = (int *)&v1658;
          t[0] = (double)(-15 * field_7D2) + field_7E4 + 15.0;
          t[1] = 12.0;
          t[2] = 0.0;
LABEL_985:
          addbullet(this, NULL, 800, (double)(100 * dir) + x, y + 136.0, dir, 1, t, 3);
          play_sfx(0);
          ++field_7D2;
          goto LABEL_986;
        }
LABEL_986:
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
        {
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 4 && not_charge_attack == 1 )
            {
              y = y + 102.0;
              v344 = x - (double)(24 * (char)dir);
              goto LABEL_957;
            }
            if ( get_frame() == 5 )
            {
              field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
              if ( field_7E4 < -50.0 )
                field_7E4 = -50.0;
              if ( field_7E4 > -30.0 )
                field_7E4 = -30.0;
              field_7D0 = 1;
              spell_energy_spend(200, 40);
            }
          }
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
          {
            field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
            if ( field_7E4 < -50.0 )
              field_7E4 = -50.0;
            if ( field_7E4 > -30.0 )
              field_7E4 = -30.0;
            field_7D0 = 1;
            spell_energy_spend(200, 40);
          }
          return;
        }
        goto LABEL_522;
      case 402:
        sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( field_7D0 <= 0 )
          goto LABEL_1022;
        field_7D0 = field_7D0 + 1;
        if ( get_subseq() )
        {
          if ( (field_7D0 % 3) == 1 && field_7D2 < 5 )
          {
            field_190 = 1;
            add_card_energy(10);
            //a2c = &v1562;
            t[0] = (double)(-15 * field_7D2) + field_7E4 + 30.0;
            t[1] = 14.0;
            t[2] = 0.0;
            goto LABEL_1021;
          }
        }
        else if ( (field_7D0 % 3) == 1 && field_7D2 < 3 )
        {
          field_190 = 1;
          add_card_energy(10);
          //a2c = (int *)&v1712;
          t[0] = (double)(-15 * field_7D2) + field_7E4 + 15.0;
          t[1] = 14.0;
          t[2] = 0.0;
LABEL_1021:
          addbullet(this, NULL, 800, (double)(103 * dir) + x, y + 63.0, dir, 1, t, 3);
          play_sfx(0);
          ++field_7D2;
          goto LABEL_1022;
        }
LABEL_1022:
        if ( process() )
          set_seq(2);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
LABEL_763:
          set_seq(2);
          return;
        }
        if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
        {
          if ( not_charge_attack == 1 )
          {
            y = y + 132.0;
            v344 = (double)(55 * (char)dir) + x;
            goto LABEL_957;
          }
          field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7E4 < -10.0 )
            field_7E4 = -10.0;
          if ( field_7E4 > 10.0 )
            field_7E4 = 10.0;
          field_7D0 = 1;
          spell_energy_spend(200, 40);
        }
        if ( get_subseq() != 1 || get_frame_time() || get_frame() != 1 )
          return;
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -10.0 )
          field_7E4 = -10.0;
        v359 = 10.0;
        if ( field_7E4 > 10.0 )
LABEL_973:
          field_7E4 = v359;
LABEL_974:
        field_7D0 = 1;
        spell_energy_spend(200, 40);
        return;
      case 404:
        if ( get_subseq() == 2 )
          sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( get_subseq() <= 1 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            reset_forces();
            set_subseq(2);
            y = getlvl_height();
          }
        }
        if ( field_7D0 > 0 )
        {
          field_7D0 = field_7D0 + 1;
          if ( !get_subseq() && field_7D0 % 3 == 1 && field_7D2 < 3 )
          {
            field_190 = 1;
            add_card_energy(10);
            t[0] = (double)(-15 * field_7D2) + field_7E4 + 15.0;
            t[1] = 12.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 115.0, dir, 1, t, 3);
            play_sfx(0);
            ++field_7D2;
          }
          if ( get_subseq() == 1 && field_7D0 % 3 == 1 && field_7D2 < 5 )
          {
            field_190 = 1;
            add_card_energy(10);
            t[0] = (double)(-15 * field_7D2) + field_7E4 + 30.0;
            t[1] = 12.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(70 * (char)dir) + x, y + 115.0, dir, 1, t, 3);
            play_sfx(0);
            ++field_7D2;
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
          goto LABEL_846;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1083;
        if ( get_frame() != 4 )
          goto LABEL_1080;
        if ( not_charge_attack == 1 )
        {
          y = y + 190.0;
          v344 = (double)(40 * (char)dir) + x;
          goto LABEL_957;
        }
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -15.0 )
          field_7E4 = -15.0;
        if ( field_7E4 > 15.0 )
          field_7E4 = 15.0;
        field_7D0 = 1;
        spell_energy_spend(200, 40);
LABEL_1080:
        if ( !get_frame_time() && get_frame() == 13 )
          v_force = 0.60000002;
LABEL_1083:
        if ( get_subseq() != 1 || get_frame_time() )
          return;
        if ( get_frame() == 1 )
        {
          field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7E4 < -10.0 )
            field_7E4 = -10.0;
          if ( field_7E4 > 10.0 )
            field_7E4 = 10.0;
          field_7D0 = 1;
          spell_energy_spend(200, 40);
        }
        goto LABEL_1091;
      case 406:
        if ( get_subseq() == 2 )
          sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( get_subseq() <= 1 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            reset_forces();
            set_subseq(2);
            y = getlvl_height();
          }
        }
        if ( field_7D0 > 0 )
        {
          field_7D0 = field_7D0 + 1;
          if ( !get_subseq() && field_7D0 % 3 == 1 && field_7D2 < 3 )
          {
            field_190 = 1;
            add_card_energy(10);
            t[0] = (double)(-15 * field_7D2) + field_7E4 + 15.0;
            t[1] = 12.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(50 * (char)dir) + x, y + 70.0, dir, 1, t, 3);
            play_sfx(0);
            ++field_7D2;
          }
          if ( get_subseq() == 1 && field_7D0 % 3 == 1 && field_7D2 < 5 )
          {
            field_190 = 1;
            add_card_energy(10);
            t[0] = (double)(-15 * field_7D2) + field_7E4 + 30.0;
            t[1] = 12.0;
            t[2] = 0.0;
            addbullet(this, NULL, 800, (double)(50 * (char)dir) + x, y + 70.0, dir, 1, t, 3);
            play_sfx(0);
            ++field_7D2;
          }
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
          goto LABEL_846;
        if ( get_subseq() )
          goto LABEL_1132;
        if ( get_frame_time() )
          goto LABEL_1129;
        if ( get_frame() == 4 && not_charge_attack == 1 )
        {
          y =  y + 190.0;
          v344 = (double)(40 * (char)dir) + x;
          goto LABEL_957;
        }
        if ( get_frame() == 5 )
        {
          field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7E4 < 35.0 )
            field_7E4 = 35.0;
          if ( field_7E4 > 65.0 )
            field_7E4 = 65.0;
          field_7D0 = 1;
          spell_energy_spend(200, 40);
        }
LABEL_1129:
        if ( !get_frame_time() && get_frame() == 11 )
          v_force = 0.60000002;
LABEL_1132:
        if ( get_subseq() != 1 || get_frame_time() )
          return;
        if ( get_frame() == 2 )
        {
          field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7E4 < 35.0 )
            field_7E4 = 35.0;
          if ( field_7E4 > 65.0 )
            field_7E4 = 65.0;
          field_7D0 = 1;
          spell_energy_spend(200, 40);
        }
        if ( get_frame_time() )
          return;
        v293 = get_frame() == 8;
        goto LABEL_835;
      case 407:
        sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( field_7D0 > 0 )
        {
          field_7D0 = 0;
          /*
          v75 = get_subseq() == 0;
          v1338 = 0.0;
          v446 = (float)0.0;
          field_190 = 1;
          if ( v75 )
          {
            do
            {
              *(float *)&v1670 = v446 * 40.0 - 60.0;
              v1671 = 15.0;
              v1672 = 2.0;
              v447 = dir;
              v448 = y + 117.0;
              v449 = v448;
              v450 = (double)(63 * (char)v447) + x;
              addbullet(this, NULL, 800, v450, v449, v447, 1, (int)&v1670, 3);
              v1338 = v1338 + 1.0;
              v446 = v1338;
            }
            while ( v1338 < 4.0 );
          }
          else
          {
            do
            {
              *(float *)&v1580 = v446 * 25.0 - 75.0;
              v1581 = 15.0;
              v1582 = 2.0;
              v451 = dir;
              v452 = y + 117.0;
              v453 = v452;
              v454 = (double)(63 * (char)v451) + x;
              addbullet(this, NULL, 800, v454, v453, v451, 1, (int)&v1580, 3);
              v1338 = v1338 + 1.0;
              v446 = v1338;
            }
            while ( v1338 < 7.0 );
          }
          */
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_1155;
        if ( get_subseq() || get_frame_time() || get_frame() != 4 )
          goto LABEL_1166;
        if ( not_charge_attack == 1 )
        {
          y = y + 100.0;
          v344 = x - (double)(12 * (char)dir);
          goto LABEL_957;
        }
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -10.0 )
          field_7E4 = -10.0;
        if ( field_7E4 > 10.0 )
          field_7E4 = 10.0;
        field_7D0 = 1;
        play_sfx(0);
        spell_energy_spend(200, 40);
        add_card_energy(30);
LABEL_1166:
        if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 1 )
        {
          field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7E4 < -10.0 )
            field_7E4 = -10.0;
          if ( field_7E4 > 10.0 )
            field_7E4 = 10.0;
          field_7D0 = 1;
          play_sfx(0);
          spell_energy_spend(200, 40);
          add_card_energy(30);
        }
        return;
      case 408:
        if ( true /*!get_true(1)*/)
        {
          sub10func();
          if ( get_frame() >= 7 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
          }
          if ( field_190 )
          {
            if ( ++field_7D0 >= 5 && field_194 > 0 )
            {
              field_190 = 0;
              field_7D0 = 0;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() && get_frame() == 4 )
          {
            scene_play_sfx(28);
            t[0] = -30.0;
            t[1] = 20.0;
            t[2] = 8.0;
            addbullet(this, NULL, 848, (double)(96 * (char)dir) + x, y + 127.0, dir, 1, t, 3);
          }
        }
        return;
      case 409:
        if ( get_subseq() == 2 )
          sub10func();
        if ( !keyDown(INP_B) )
          not_charge_attack = 0;
        if ( get_subseq() <= 1 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
            reset_forces();
            set_subseq(2);
            y = getlvl_height();
          }
        }
        if ( field_7D0 > 0 )
        {
          field_7D0 = 0;
          /*
          v75 = get_subseq() == 0;
          v1339 = 0.0;
          v472 = (float)0.0;
          field_190 = 1;
          if ( v75 )
          {
            do
            {
              *(float *)&v1586 = v472 * 40.0 - 60.0;
              v1587 = 15.0;
              v1588 = 2.0;
              v473 = dir;
              v474 = y + 115.0;
              v475 = v474;
              v476 = (double)(70 * (char)v473) + x;
              addbullet(this, NULL, 800, v476, v475, v473, 1, (int)&v1586, 3);
              v1339 = v1339 + 1.0;
              v472 = v1339;
            }
            while ( v1339 < 4.0 );
          }
          else
          {
            do
            {
              *(float *)&v1676 = v472 * 25.0 - 75.0;
              v1677 = 15.0;
              v1678 = 2.0;
              v477 = dir;
              v478 = y + 115.0;
              v479 = v478;
              v480 = (double)(70 * (char)v477) + x;
              addbullet(this, NULL, 800, v480, v479, v477, 1, (int)&v1676, 3);
              v1339 = v1339 + 1.0;
              v472 = v1339;
            }
            while ( v1339 < 7.0 );
          }
          */
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          set_seq(9);
          return;
        }
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
          goto LABEL_846;
        if ( get_subseq() || get_frame_time() )
          goto LABEL_1223;
        if ( get_frame() != 4 )
          goto LABEL_1220;
        if ( not_charge_attack == 1 )
        {
          y = y + 190.0;
          v344 = (double)(40 * (char)dir) + x;
          goto LABEL_957;
        }
        field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
        if ( field_7E4 < -10.0 )
          field_7E4 = -10.0;
        if ( field_7E4 > 10.0 )
          field_7E4 = 10.0;
        field_7D0 = 1;
        spell_energy_spend(200, 40);
        add_card_energy(30);
        play_sfx(0);
LABEL_1220:
        if ( !get_frame_time() && get_frame() == 13 )
          v_force = 0.60000002;
LABEL_1223:
        if ( get_subseq() != 1 || get_frame_time() )
          return;
        if ( get_frame() == 1 )
        {
          field_7E4 = -atan2_deg(enemy->y - y, (enemy->x - x) * (double)dir);
          if ( field_7E4 < -10.0 )
            field_7E4 = -10.0;
          if ( field_7E4 > 10.0 )
            field_7E4 = 10.0;
          field_7D0 = 1;
          spell_energy_spend(200, 40);
          add_card_energy(30);
          play_sfx(0);
        }
        if ( get_frame_time() )
          return;
        v293 = get_frame() == 10;
        goto LABEL_835;
      case 410:
        sub10func();
        if ( get_subseq() < 2 && !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( !get_frame_time() && get_frame() == 5 )
        {
          field_190 = 1;
          add_card_energy(50);
          play_sfx(1);
          /*
          v1479 = 5.0;
          v1480 = 0.0;
          spell_energy_spend(200, 48);
          v494 = 0;
          v1340 = 0;
          do
          {
            *(float *)&v1478 = (double)v1340;
            v495 = dir;
            v496 = y + 140.0;
            v497 = v496;
            v498 = (double)(100 * (char)v495) + x;
            addbullet(this, NULL, 801, v498, v497, v495, 1, (int)&v1478, 3);
            v494 += 45;
            v1340 = v494;
          }
          while ( v494 < 315 );
          v1480 = 2.0;
          v499 = dir;
          v500 = y + 140.0;
          v501 = v500;
          v502 = (double)(100 * (char)v499) + x;
          addbullet(this, NULL, 801, v502, v501, v499, 1, (int)&v1478, 3);
          */
        }
        return;
      case 411:
        sub10func();
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        
        if ( field_7D0 <= 0 )
          goto LABEL_1255;
        field_7D0 = field_7D0 + 1;
        if ( get_subseq() )
        {
          if ( get_subseq() == 1 && field_7D0 % 2 == 1 && field_7D2 < 10 )
          {
            field_190 = 1;
            add_card_energy(5);
            t[0] = /*get_MT_range(10)*/10.0 - 5.0 + field_7F0;
            t[1] = 27.5;
            t[2] = 6.0;
            addbullet(this, NULL, 801, (double)(63 * (char)dir) + x, y + 117.0, dir, 1, t, 3);
            t[2] = 7.0;
            //a2d = &v1487;
            goto LABEL_1250;
          }
        }
        else if ( field_7D0 % 2 == 1 && field_7D2 < 5 )
        {
          field_190 = 1;
          add_card_energy(5);
          t[0] = /*get_MT_range(8)*/8.0 - 4.0 + field_7F0;
          t[0] = 27.5;
          t[0] = 6.0;
          addbullet(this, NULL, 801, (double)(63 * (char)dir) + x, y + 117.0, dir, 1, t, 3);
          t[2] = 7.0;
          //a2d = &v1481;
LABEL_1250:
          addbullet(this, NULL, 801, (double)(63 * (char)dir) + x, y + 117.0, dir, 1, t, 3);
          play_sfx(2);
          ++field_7D2;
          goto LABEL_1255;
        }
LABEL_1255:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
LABEL_522:
          set_seq(0);
          return;
        }
        if ( get_subseq() || get_frame_time() || get_frame() != 4 )
          goto LABEL_1267;
        if ( not_charge_attack != 1 )
        {
          field_7D0 = 1;
          sub_486FD0(10.0, -10.0);
          spell_energy_spend(200, 48);
LABEL_1267:
          if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 1 )
          {
            field_7D0 = 1;
            sub_486FD0(10.0, -10.0);
            spell_energy_spend(200, 48);
          }
          return;
        }
        goto LABEL_958;
      case 412:
        sub10func();
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(2);
        if ( !get_subseq() && get_frame() == 5 && !get_frame_time() )
        {
          play_sfx(7);
          t[0] = 10.0;
          t[1] = 15.0;
          t[2] = 12.0;
          field_190 = 1;
          spell_energy_spend(200, 48);
          add_card_energy(50);
          addbullet(this, NULL, 801, (double)(100 * (char)dir) + x, y + 56.0, dir, 1, t, 3);
        }
        return;
      case 414:
        if ( get_subseq() == 1 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 1 )
          goto LABEL_1283;
        if ( get_subseq() < 2 && !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( process() )
          set_seq(0);
        if ( get_elaps_frames() )
          goto LABEL_1294;
        if ( get_frame_time() )
          return;
        if ( !get_frame() && get_subseq() == 1 )
          goto LABEL_846;
LABEL_1294:
        if ( get_frame_time() )
          return;
        if ( get_frame() == 5 )
        {
          field_190 = 1;
          spell_energy_spend(200, 48);
          add_card_energy(50);
          play_sfx(1);
          /*
          v1491 = 5.0;
          v526 = 0;
          v1341 = 0;
          v1492 = 0.0;
          do
          {
            *(float *)&v1490 = (double)v1341;
            v527 = dir;
            v528 = y + 140.0;
            v529 = v528;
            v530 = (double)(100 * (char)v527) + x;
            addbullet(this, NULL, 801, v530, v529, v527, 1, (int)&v1490, 3);
            v526 += 45;
            v1341 = v526;
          }
          while ( v526 < 315 );
          v1492 = 2.0;
          v531 = dir;
          v532 = y + 140.0;
          v533 = v532;
          v534 = (double)(100 * (char)v531) + x;
          addbullet(this, NULL, 801, v534, v533, v531, 1, (int)&v1490, 3);
          */
        }
        if ( get_frame_time() )
          return;
        v293 = get_frame() == 15;
        goto LABEL_835;
      case 415:
        if ( get_subseq() == 2 )
          sub10func();
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() && get_subseq() < 2 )
        {
          set_subseq(2);
          goto LABEL_1284;
        }
        if ( !keyDown(INP_C) )
          not_charge_attack = 0;
        if ( field_7D0 <= 0 )
          goto LABEL_1318;
        field_7D0 = field_7D0 + 1;
        if ( get_subseq() )
        {
          if ( get_subseq() == 1 && field_7D0 % 2 == 1 && field_7D2 < 10 )
          {
            field_190 = 1;
            add_card_energy(5);
            t[0] = /*get_MT_range(10)*/10.0 - 5.0 + field_7F0;
            t[1] = 27.5;
            t[2] = 6.0;
            addbullet(this, NULL, 801, (double)(70 * (char)dir) + x, y + 115.0, dir, 1, t, 3);
            t[2] = 7.0;
            //a2e = &v1496;
            goto LABEL_1313;
          }
        }
        else if ( field_7D0 % 2 == 1 && field_7D2 < 5 )
        {
          field_190 = 1;
          add_card_energy(5);
          t[0] = /*get_MT_range(8)*/8.0 - 4.0 + field_7F0;
          t[1] = 27.5;
          t[2] = 6.0;
          addbullet(this, NULL, 801, (double)(70 * (char)dir) + x, y + 115.0, dir, 1, t, 3);
          t[2] = 7.0;
LABEL_1313:
          addbullet(this, NULL, 801, (double)(70 * (char)dir) + x, y + 115.0, dir, 1, t, 3);
          play_sfx(2);
          ++field_7D2;
          goto LABEL_1318;
        }
LABEL_1318:
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
        {
LABEL_846:
          set_seq(9);
          return;
        }
        if ( !get_subseq() && !get_frame_time() )
        {
          if ( get_frame() == 4 )
          {
            if ( not_charge_attack == 1 )
            {
              y = y + 100.0;
LABEL_958:
              scene_add_effect(this, 62, x - (double)(12 * (char)dir), y, dir, 1);
LABEL_959:
LABEL_960:
              next_subseq();
              return;
            }
            field_7D0 = 1;
            spell_energy_spend(200, 48);
            sub_486FD0(10.0, -10.0);
          }
          if ( !get_frame_time() && get_frame() == 13 )
            v_force = 0.60000002;
        }
        if ( get_subseq() == 1 && !get_frame_time() )
        {
          if ( get_frame() == 1 )
          {
            field_7D0 = 1;
            spell_energy_spend(200, 48);
            sub_486FD0(10.0, -10.0);
          }
LABEL_1091:
          if ( !get_frame_time() )
          {
            v293 = get_frame() == 10;
LABEL_835:
            if ( v293 )
              v_force = 0.60000002;
          }
        }
        return;
      case 416:
        v554 = 1;
        if ( get_subseq() == 1 )
          sub10func();
        if ( !get_subseq() )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_1344;
        }
        if ( process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          goto LABEL_886;
        if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
        {
          play_sfx(1);
          h_inerc = -4.0;
          v_inerc = 8.0;
          v_force = 0.5;
          field_190 = 1;
          spell_energy_spend(200, 48);
          add_card_energy(50);
          /*
          v1494 = 20.0;
          v555 = 25;
          v1342 = 25;
          v1495 = 5.0;
          do
          {
            *(float *)&v1493 = (double)v1342;
            v556 = dir;
            v557 = y + 45.0;
            v558 = v557;
            v559 = (double)(40 * (char)v556) + x;
            addbullet(this, NULL, 801, v559, v558, v556, 1, (int)&v1493, 3);
            v555 += 15;
            v1342 = v555;
          }
          while ( v555 < 100 );
          v1495 = 2.0;
          v560 = dir;
          v561 = y + 45.0;
          v562 = v561;
          v563 = (double)(40 * (char)v560) + x;
          addbullet(this, NULL, 801, v563, v562, v560, 1, (int)&v1493, 3);
          */
        }
        return;
      case 418:
        if ( true /*!get_true(1)*/)
        {
          sub10func();
          h_inerc = h_inerc - 0.2000000029802322;
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
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            }
            if ( !get_frame_time() && get_frame() == 5 )
            {
              scene_play_sfx(29);
              field_49A = 0;
            }
          }
        }
        return;
      default:
        goto LABEL_2759;
    }
  }
  if ( sq == 300 )
  {
LABEL_674:
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
    switch ( sq )
    {
      case 0:
        sub10func();
        if ( 0.0 == h_inerc )
          field_49A = 0;
        if ( !field_49A )
          goto LABEL_112;
        goto LABEL_113;
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
LABEL_113:
          if ( 0.0 < h_inerc )
          {
            h_inerc =  h_inerc - 0.5;
            if ( h_inerc < 0.0 )
            {
              reset_forces();
              field_49A = 0;
            }
          }
          if ( 0.0 <= h_inerc || (h_inerc = h_inerc + 0.5, h_inerc <= 0.0) )
          {
LABEL_197:
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
LABEL_112:
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
          goto LABEL_142;
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
            goto LABEL_194;
        }
        if ( get_subseq() == 1 && v_inerc < 4.0 )
          next_subseq();
        process();
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          return;
        v77 = 0.0;
        goto LABEL_160;
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
            goto LABEL_194;
        }
        if ( get_subseq() == 1 && v_inerc < 4.0 )
          next_subseq();
        process();
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          return;
        v77 = 3.0;
        goto LABEL_160;
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
            goto LABEL_194;
        }
        if ( get_subseq() == 1 && v_inerc < 4.0 )
          next_subseq();
        process();
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          v77 = -4.0;
LABEL_160:
          char_h_move(v77);
          v_inerc = 13.0;
          v_force = 0.40000001;
          field_49A = 0;
        }
        return;
      case 9:
        if ( 0.0 == v_force )
          v_force = 0.60000002;
        v_inerc = v_inerc - v_force;
        if ( !char_on_ground_down() )
          goto LABEL_197;
LABEL_194:
        move_val = 10;
        goto LABEL_195;
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
          goto LABEL_208;
        if ( controlling_type == 2 )
          goto LABEL_204;
        set_seq(0);
        if ( dY() > 0 )
          set_seq(1);
LABEL_208:
        if ( get_frame_time() )
          return;
        if ( get_frame() != 6 )
          goto LABEL_215;
        if ( enemy->x < (double)x )
          dir = -1;
        goto LABEL_213;
      case 198:
        sub10func();
        if ( !process() )
          goto LABEL_223;
        if ( controlling_type == 2 )
        {
          set_seq(700);
          goto LABEL_205;
        }
        set_seq(0);
        if ( dY() > 0 )
          set_seq(1);
LABEL_223:
        if ( !get_frame_time() )
        {
          if ( get_frame() == 6 )
          {
            if ( enemy->x < (double)x )
              dir = -1;
LABEL_213:
            if ( enemy->x > x )
              dir = 1;
          }
LABEL_215:
          if ( !get_frame_time() && get_frame() == 6 )
            h_inerc = 0.0;
        }
        return;
      case 199:
        sub10func();
        if ( !process() )
          goto LABEL_232;
        if ( controlling_type == 2 )
        {
LABEL_204:
          set_seq(700);
LABEL_205:
          field_51C = 3;
          field_520 = 3;
        }
        else
        {
          set_seq(0);
          if ( dY() > 0 )
            set_seq(1);
LABEL_232:
          if ( !get_frame_time() && get_frame() == 5 )
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
          goto LABEL_249;
        if ( !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
        }
        if ( dY() >= 0 )
        {
          if ( (dX(dir) > 0 || ++field_7D0 < 5) && ++field_7D0 < 60 )
          {
LABEL_249:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              char_h_move(8.5);
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
        v103 = 2;
        if ( get_subseq() == 2 )
        {
          sub10func();
          if ( get_subseq() == 2 )
          {
            h_inerc = h_inerc + 2.0;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
          }
        }
        if ( !char_on_ground_flag() && !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
        }
        if ( get_subseq() < 2 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_263;
        }
        if ( process() )
          goto LABEL_142;
        if ( !get_subseq() && get_frame() == 1 && !get_frame_time() )
        {
          char_h_move(-10.0);
          v_inerc = 3.0;
          v_force = 0.30000001;
          scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
          scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
          scene_play_sfx(31);
        }
        return;
      case 202:
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
          goto LABEL_270;
        if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
        }
        process();
        if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
        {
          char_h_move(8.0);
          v_inerc = 3.0;
          v_force = 0.40000001;
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
          if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
          {
            char_h_move(-8.0);
            v_inerc = 3.0;
            v_force = 0.40000001;
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
          goto LABEL_305;
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
        v134 = 0.0;
        goto LABEL_320;
      case 209:
      case 212:
      case 221:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_305;
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
        v139 = 8.5;
        goto LABEL_340;
      case 210:
      case 222:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_305;
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
        v139 = -8.5;
LABEL_340:
        char_h_move(v139);
        v136 = 15.0;
        goto LABEL_321;
      case 211:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
        {
LABEL_305:
          set_seq(10);
          goto LABEL_196;
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
          v134 = 3.0;
LABEL_320:
          char_h_move(v134);
          v136 = 19.0;
LABEL_321:
          v_inerc = v136;
          v_force = 0.60000002;
          field_49A = 0;
          scene_add_effect(this, 63, x, y, dir, 1);
        }
        return;
      case 214:
        if ( process() )
          goto LABEL_886;
        if ( get_elaps_frames() )
          goto LABEL_391;
        if ( get_frame_time() || get_frame() || get_subseq() != 1 )
          goto LABEL_386;
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
LABEL_386:
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 9 )
          set_subseq(5);
LABEL_391:
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 10 || !get_frame_time() && !get_frame() && get_subseq() == 11) )
          goto LABEL_886;
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
        if ( get_subseq() == 9 || get_subseq() == 10 || get_subseq() == 11 )
          v_inerc = v_inerc - v_force;
        if ( get_subseq() <= 0 || get_subseq() >= 9 )
          goto LABEL_510;
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
            dash_angle = dash_angle + 4.0;
          else
            dash_angle = dash_angle + 5.0;
        }
        if ( field_7D4 < 0 )
        {
          if ( weather_id )
            dash_angle = dash_angle - 4.0;
          else
            dash_angle = dash_angle - 5.0;
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
          goto LABEL_509;
        if ( get_subseq() != 4 && get_subseq() != 5 )
          goto LABEL_451;
        if ( dash_angle <= 45.0 && dash_angle >= -45.0 )
        {
          set_subseq(1);
          return;
        }
        if ( dash_angle >= 135.0 || dash_angle <= -135.0 )
        {
          set_subseq(6);
          return;
        }
LABEL_451:
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
            goto LABEL_480;
          field_7D0 = get_frame();
          if ( dir == 1 )
          {
            if ( enemy->x < x )
            {
              dir = -1;
LABEL_475:
              h_inerc = -h_inerc;
              set_subseq(9);
              set_frame(field_7D0);
              goto LABEL_480;
            }
          }
          else
          {
            if ( enemy->x > x )
            {
              dir = -dir;
              goto LABEL_475;
            }
          }
          set_subseq(9);
          set_frame(field_7D0);
LABEL_480:
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
LABEL_510:
        if ( !char_on_ground_down() )
          return;
        y = getlvl_height();
        v_inerc = 0.0;
        v_force = 0.0;
        /*
        v179 = __OFSUB__(get_subseq(), 9);
        v178 = (signed __int16)(get_subseq() - 9) < 0;
LABEL_512:
        if ( v178 ^ v179 )
        {
          reset_ofs();
          set_seq(215);
        }
        else
        {
          set_seq(10);
          reset_forces();
        }
        */
        break;
      case 215:
        sub10func();
        if ( h_inerc > 0.0 )
        {
          h_inerc = h_inerc - 0.5;
          if ( h_inerc < 0.0 )
            h_inerc = 0.0;
        }
        if ( h_inerc < 0.0 )
        {
          h_inerc = h_inerc + 0.5;
          if ( h_inerc > 0.0 )
            h_inerc = 0.0;
        }
        if ( process() )
          goto LABEL_522;
        return;
      case 217:
        if ( process() )
          goto LABEL_846;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          scene_play_sfx(31);
        v182 = 6;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
          goto LABEL_846;
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
                else
                {
                  if ( enemy->x <= x )
                    goto LABEL_1890;
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
        /*
        v179 = __OFSUB__(get_subseq(), 5);
        v178 = (signed __int16)(get_subseq() - 5) < 0;
        goto LABEL_512;
        */
        return; //TODO: change
      case 220:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_604;
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
          v_inerc = 19.0;
          v_force = 0.60000002;
          field_49A = 0;
          scene_add_effect(this, 63, x, y, dir, 1);
        }
        return;
      case 223:
        sub10func();
        field_49A = 1;
        process();
        if ( get_subseq() != 1 )
          goto LABEL_2765;
        if ( !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
        }
        if ( ((++field_7D0, dX(dir) > 0) || field_7D0 < 15) && field_7D0 < 60 )
        {
LABEL_2765:
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            char_h_move(6.0);
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
        v103 = 2;
        if ( get_subseq() == 2 )
        {
          sub10func();
          if ( get_subseq() == 2 )
          {
            h_inerc = h_inerc + 2.0;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
          }
        }
        if ( !char_on_ground_flag() && !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
        }
        if ( get_subseq() < 2 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_263;
        }
        if ( process() )
          goto LABEL_142;
        if ( !get_subseq() && get_frame() == 1 && !get_frame_time() )
        {
          char_h_move(-10.0);
          v_inerc = 3.0;
          v_force = 0.30000001;
          scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
          scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
          scene_play_sfx(31);
        }
        return;
      case 225:
        if ( get_subseq() >= 1 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_270;
        }
        if ( get_subseq() >= 2 && !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
        }
        if ( process() )
          set_seq(9);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          char_h_move(-11.0);
          v_inerc = 4.0;
          v_force = 0.5;
          scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
          scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
          scene_play_sfx(31);
        }
        return;
      case 226:
        v_inerc = v_inerc - v_force;
        if ( char_on_ground_down() )
        {
LABEL_270:
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
          process();
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              field_7D0 = 0;
              char_h_move(8.0);
              v_inerc = 3.0;
              v_force = 0.40000001;
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
        goto LABEL_2759;
    }
  }
}

// note: taken from alice.cpp
void char_pachou::func20()
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

void char_pachou::set_seq_params()
{
  //v2 = get_seq();
  if ( get_seq() <= 503 )
  {
    if ( get_seq() >= 500 )
    {
      not_charge_attack = 1;
      field_18C = 0;
      reset_forces();
      field_49A = 0;
      field_190 = 1;
      return;
    }
    if ( get_seq() > 197 )
    {
      switch ( get_seq() )
      {
        case 198:
          h_inerc = -11.0;
          return;
        case 214:
          reset_ofs();
          h_inerc = 0.0;
          v_inerc = 0.0;
          v_force = 0.60000002;
          goto LABEL_13;
        case 217:
          reset_ofs();
          h_inerc = 0.0;
          v_inerc = 0.0;
          v_force = 0.60000002;
          x_off = 0.0;
          y_off = 95.0;
LABEL_13:
          field_7D6 = 0;
          field_7DC = 9.0;
          field_7EC = 0.0;
          return;
        case 300:
        case 301:
        case 330:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_194 = 1;
          not_charge_attack = 1;
          return;
        case 302:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_194 = 1;
          not_charge_attack = 1;
          return;
        case 303:
        case 321:
        case 322:
          goto LABEL_40;
        case 304:
          field_49A = 0;
          field_194 = 1;
          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 305:
          field_49A = 0;
          h_inerc = 10.0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 306:
          field_7D0 = 0;
          field_190 = 0;
          field_194 = 3;
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
          field_194 = 1;
          field_190 = 0;
          not_charge_attack = 1;
          return;
        case 309:
          field_194 = 0;
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
          field_7D0 = 0;
          reset_forces();
          field_49A = 0;
          field_190 = 0;
          field_194 = 3;
          return;
        case 400:
        case 401:
        case 402:
        case 407:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          not_charge_attack = 1;
          return;
        case 404:
        case 406:
        case 409:
        case 415:
          field_190 = 0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          goto LABEL_31;
        case 408:
          v_inerc = 0.0;
          field_7D0 = 0;
          field_49A = 0;
          h_inerc = 10.0;
          field_190 = 0;
          field_194 = 3;
          v_force = 0.0;
          return;
        case 410:
          field_190 = 0;
          reset_forces();
          goto LABEL_34;
        case 411:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          not_charge_attack = 1;
          return;
        case 412:
          goto LABEL_36;
        case 414:
          v_force = 0.0;
          field_190 = 0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 416:
          field_190 = 0;
          field_7D8 = 0;
          field_194 = 1;
          return;
        case 418:
          h_inerc = 8.5;
LABEL_40:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_194 = 1;
          return;
        default:
          goto LABEL_93;
      }
    }
    else
    {
      if ( get_seq() == 197 )
      {
        h_inerc = 11.0;
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
  if ( get_seq() > 797 )
  {
    if ( get_seq() != 798 )
    {
LABEL_93:
      char_c::set_seq_params();
      return;
    }
    goto LABEL_94;
  }
  if ( get_seq() == 797 )
  {
LABEL_94:
    reset_forces();
    v_force = 0.40000001;
    field_7D0 = 0;
    return;
  }
  switch ( get_seq() )
  {
    case 505:
    case 506:
      field_18C = 5;
      not_charge_attack = 1;
      goto LABEL_48;
    case 507:
    case 508:
      field_18C = 5;
      v_force = 0.0;
      not_charge_attack = 1;
      h_inerc = h_inerc * 0.2000000029802322;
      v_inerc = 0.2000000029802322 * v_inerc;
      goto LABEL_49;
    case 510:
    case 511:
      field_18C = 10;
      not_charge_attack = 1;
      goto LABEL_52;
    case 520:
    case 521:
      field_18C = 1;
LABEL_48:
      reset_forces();
LABEL_49:
      field_49A = 0;
      field_7D0 = 0;
      field_190 = 1;
      return;
    case 525:
    case 526:
      field_18C = 6;
      goto LABEL_55;
    case 527:
    case 528:
      v_force = 0.0;
      field_194 = 0;
      field_190 = 0;
      field_49A = 0;
      field_7D0 = 0;
      field_18C = 6;
      h_inerc = h_inerc * 0.2000000029802322;
      v_inerc = 0.2000000029802322 * v_inerc;
      return;
    case 530:
    case 531:
      field_18C = 11;
LABEL_55:
      reset_forces();
      field_194 = 0;
      field_190 = 0;
      field_49A = 0;
      field_7D0 = 0;
      return;
    case 532:
    case 533:
      field_194 = 0;
      field_190 = 0;
      field_49A = 0;
      field_7D0 = 0;
      h_inerc = h_inerc * 0.2000000029802322;
      field_18C = 11;
      v_inerc = 0.2000000029802322 * v_inerc;
      v_force = 0.025;
      return;
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
      return;
    case 542:
      field_190 = 0;
      not_charge_attack = 0;
      field_18C = 2;
      field_194 = 1;
      return;
    case 545:
    case 546:
      field_18C = 6;
      goto LABEL_62;
    case 547:
    case 548:
      v_force = 0.025;
      h_inerc = h_inerc * 0.1000000014901161;
      field_18C = 6;
      field_190 = 0;
      not_charge_attack = 1;
      v_inerc = 0.1000000014901161 * v_inerc;
      float t[3];
      t[0] = 0.0;
      t[1] = 0.0;
      t[2] = 10.0;
      addbullet(this, NULL, 821, x, y, dir, -1, t, 3);
      return;
    case 550:
    case 551:
    /*
      v12 = __OFSUB__(skills_1[12], 2);
      v11 = (char)(skills_1[12] - 2) < 0;
      field_18C = 12;
      if ( !(v11 ^ v12) )
        field_51C = 3;
        */
      field_190 = 0;
      reset_forces();
      field_7D0 = 0;
      not_charge_attack = 1;
      return;
    case 560:
    case 561:
      field_18C = 3;
      field_190 = 0;
      reset_forces();
      field_7D0 = 0;
      field_7E4 = 0.0;
      field_7D2 = 0;
      not_charge_attack = 1;
      return;
    case 565:
    case 566:
      field_18C = 8;
      goto LABEL_62;
    case 567:
    case 568:
      field_18C = 8;
      field_190 = 0;
LABEL_31:
      not_charge_attack = 1;
      v_force = 0.0;
      h_inerc = h_inerc * 0.2000000029802322;
      v_inerc = 0.2000000029802322 * v_inerc;
      return;
    case 570:
    case 571:
      field_18C = 13;
      not_charge_attack = 1;
      field_7D0 = 0;
      goto LABEL_71;
    case 580:
    case 581:
      field_18C = 4;
      field_190 = 1;
      reset_forces();
      field_7E4 = 0.0;
      field_7D0 = 0;
      field_7D2 = 0;
      not_charge_attack = 1;
      return;
    case 585:
    case 586:
      field_18C = 9;
      goto LABEL_62;
    case 590:
    case 591:
      field_18C = 14;
LABEL_62:
      field_190 = 0;
      reset_forces();
      not_charge_attack = 1;
      return;
    case 600:
    case 604:
      field_190 = 0;
      reset_forces();
      return;
    case 601:
    case 611:
    case 651:
    case 661:
      field_7DC = 10.0;
      field_7D0 = 0;
      field_7D2 = 0;
      field_190 = 0;
      reset_forces();
      return;
    case 602:
      field_7D0 = 0;
      field_190 = 0;
      field_194 = 99;
      reset_forces();
      return;
    case 603:
      field_7D0 = 0;
      field_7D2 = 0;
      field_190 = 0;
      reset_forces();
      return;
    case 605:
    case 606:
LABEL_52:
      reset_forces();
      field_190 = 0;
      field_49A = 0;
      return;
    case 607:
      reset_forces();
      field_49A = 0;
      return;
    case 610:
      field_190 = 1;
      reset_forces();
      return;
    case 612:
    case 613:
LABEL_36:
      field_190 = 1;
      reset_forces();
      field_7D0 = 0;
      field_7D2 = 0;
      field_7D6 = 0;
      field_7D8 = 0;
      return;
    case 615:
      field_190 = 1;
      reset_forces();
LABEL_34:
      field_7D0 = 0;
      field_7D2 = 0;
      field_7D6 = 0;
      field_7D8 = 0;
      not_charge_attack = 1;
      return;
    case 690:
      y = y + 100.0;
      scene_add_effect(this, 71, x, y, dir, 1);
      field_7D0 = 0;
      field_7D2 = 0;
      field_190 = 1;
      reset_forces();
      //whatis v14?
      //sub_4892D0();//sub_4892D0(&v1->char_c, v14);
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
    case 710:
    case 720:
LABEL_71:
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
      goto LABEL_88;
    case 709:
LABEL_88:
      field_7D0 = 0;
      break;
    case 721:
      if ( getlvl_height() >= y )
        reset_forces();
      break;
    case 730:
      reset_forces();
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
      break;
    default:
      goto LABEL_93;
  }
}
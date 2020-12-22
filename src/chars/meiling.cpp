#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "meiling.h"
#include <math.h>

char_meiling::char_meiling(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_MEILING;
	//TODO: load_dat with parameter "meiling" gives value "4294967295" for get_seq(). Seems to not work properly (sigsegvs)
	// How to fix this? (replaced with marisa instead of meiling to allow the program to run)
	pgp->load_dat("marisa",pal);
	char_loadsfx("marisa");
	cards_load_cards(&chr_cards,"marisa");
	load_face("marisa");
	load_spells("marisa");
	stand_gfx->init(this,"marisa");
}

/*c_bullet *char_meiling::new_bullet() {
	c_bullet *tmp = new meiling_bullets();
	return tmp;
}*/

void char_meiling::init_vars()
{
	field_890 = 0;
	field_138 = -6.0;
	char_c::init_vars();
}

//WIP
//TODO: still haven't tested because of SIGSEGV
void char_meiling::func10()
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

  int v630 = 0;
  bool v676 = false;

  double v219 = 0.0;
  double v581 = 0.0;

  double v348 = 0.0;

  bool v405 = false;

  double v41 = 0.0;
  double v52 = 0.0;
  double v100 = 0.0;
  double v106 = 0.0;
  double v102 = 0.0;
  double v103 = 0.0;

  double move_val = 0.0;

  x_delta = 0;
  y_delta = 106;
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
            field_55C = 4.0;
          }
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_55C = 7.5;
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
        scene_add_effect(this, 53, x, y + 100.0, dir, 1);
        if ( cards_added >= 1 )
        {
          if ( cards_active[0]->id <= 7 )
          {
            //v5 = byte_727664[v4];
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
        {
LABEL_32:
          field_86A = 0;
          goto LABEL_33;
        }
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
    if ( health <= 0 )
      goto LABEL_32;
  }
LABEL_33:
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
      addbullet(this, NULL, 998, (double)(57 * (char)dir) + x,  y + 100.0, dir, 1, 0, 0);
      
    }
  }
  if ( field_890 > 0 )
  {
    field_890 = field_890 - 1;
    if ( health > 0 && field_890 > 0 )
    {
      if ( !field_190 || field_190 == 1 )
      {
LABEL_51:
        if ( field_1A2 == 1 )
        {
          if ( skills_1[9] >= 2 )
            field_198 = ((double)(skills_1[9] - 1) * 0.1000000014901161 + 1.0)* field_198;
          else
            field_198 = 1.0 * field_198;
        }
        goto LABEL_55;
      }
      if ( field_1A2 != 1 )
      {
LABEL_55:
        if ( field_1A2 >= 2 )
        {
          field_54C = 0.0;
          field_198 = field_198 + field_198;
        }
        if ( field_1A2 <= 0 )
          field_890 = 0;
        if ( field_84E <= 0 && field_852 <= 0 )
        {
          if ( shader_type != 1 )
          {
            if ( shader_type == 0.0 )
              shader_type = 3;
            field_7FC = field_7FC + 8.0;
            shader_cR = (64.0 - cos_deg(field_7FC) * 64.0);
            shader_cG = (64.0 - cos_deg(field_7FC) * 64.0);
            
          }
        }
        goto LABEL_70;
      }
    }
    field_1A2 = 0;
    goto LABEL_51;
  }
  if ( field_84E <= 0 && field_852 <= 0 )
  {
    if ( shader_type != 1 && shader_type != 0.0 )
      shader_type = 0.0;
  }
LABEL_70:
  if ( !hit_stop && !enemy->time_stop )
  {
    if ( get_seq() > 300 )
    {
      if ( get_seq() > 560 )
      {
        switch ( get_seq() )
        {
          case 561:
            sub10func();
            field_18C = 3;
            if ( field_7D0 )
            {
              if ( field_7D0 % 7 == 1 && field_7D0 <= 29 )
              {
                play_sfx(17);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                if ( skills_1[3] >= 2 )
                  t[2] = 2.0;
                addbullet(this, NULL, 825, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              }
              ++field_7D0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() )
            {
              if ( !get_frame() && skills_1[3] >= 1 && get_frame_time() >= 2 )
                goto LABEL_1645;
              if ( !get_frame_time() && get_frame() == 15 )
              {
                spell_energy_spend(200, 120);
                add_card_energy(50);
                field_7D0 = 1;
                field_190 = 1;
              }
            }
            return;
          case 565:
            sub10func();
            field_18C = 7;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 40) )
                play_sfx(18);
              if ( get_elaps_frames() >= 20 && (!not_charge_attack || get_elaps_frames() >= 90) )
                goto LABEL_663;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 826, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 826, (double)(get_pframe()->extra1[2] * (char)dir) + x, y - (double)get_pframe()->extra1[3], dir, 1, t, 3);
              t[2] = 6.0;
              addbullet(this, NULL, 826, (double)(110 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
            {
              add_card_energy(50);
              field_190 = 1;
              play_sfx(19);
              sub_486FD0(20.0, -20.0);
              spell_energy_spend(200, 120);
              tt[0] = field_7F0;
              tt[1] = 17.5;
              if ( skills_1[7] >= 3 )
                tt[1] = 25.0;
              tt[2] = 3.0;
              tt[3] = (double)field_7D0;
              addbullet(this, NULL, 826, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
            }
            return;
          case 566:
            sub10func();
            field_18C = 7;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 40) )
                play_sfx(18);
              if ( get_elaps_frames() >= 60 && (!not_charge_attack || get_elaps_frames() >= 180) )
                goto LABEL_663;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 826, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 826, (double)(get_pframe()->extra1[2] * (char)dir) + x, y - (double)get_pframe()->extra1[3], dir, 1, t, 3);
              t[2] = 6.0;
              addbullet(this, NULL, 826, (double)(110 * (char)dir) + x, y + 100.0, dir, 1, t, 3);
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
            {
              add_card_energy(50);
              field_190 = 1;
              play_sfx(19);
              sub_486FD0(20.0, -20.0);
              spell_energy_spend(200, 120);
              tt[0] = field_7F0;
              tt[1] = 17.5;
              if ( skills_1[7] >= 3 )
                t[1] = 25.0;
              tt[2] = 3.0;
              tt[3] = (double)field_7D0;
              addbullet(this, NULL, 826, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
            }
            return;
          case 570:
            sub10func();
            field_18C = 11;
            if ( get_subseq() == 1 )
            {
              v630 = 12;
              if ( skills_1[11] >= 2 )
                v630 = 14;
              if ( skills_1[11] >= 3 )
                v630 = 16;
              if ( skills_1[11] >= 4 )
                v630 = 18;
              if ( field_7D2 <= v630 )
              {
                t[0] = -/*get_next_ranged(60)*/60.0 - 60.0;
                t[1] = /*get_next_ranged(50)*/50.0 * 0.1000000014901161 + 10.0;
                t[2] = field_7DC;
                addbullet(this, NULL, 827, (cos_deg(-t[0]) * (t[1] * 8.0) + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * (t[1] * 4.0) + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                ++field_7D2;
              }
              field_7DC = field_7DC + 1.0;
              if ( field_7DC >= 7.0 )
                field_7DC = field_7DC - 7.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              field_190 = 1;
              spell_energy_spend(200, 120);
              play_sfx(2);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 14.0;
              addbullet(this, NULL, 827, x, y, dir, 1, t, 3);
            }
            return;
          case 571:
            sub10func();
            field_18C = 11;
            if ( get_subseq() == 1 )
            {
              v630 = 18;
              if ( skills_1[11] >= 2 )
                v630 = 20;
              if ( skills_1[11] >= 3 )
                v630 = 22;
              if ( skills_1[11] >= 4 )
                v630 = 24;
              if ( field_7D2 <= v630 )
              {
                t[0] = -/*get_next_ranged(60)*/60.0 - 60.0;
                t[1] = /*get_next_ranged(50)*/50.0 * 0.1000000014901161 + 10.0;
                t[2] = field_7DC;
                addbullet(this, NULL, 827, (cos_deg(-(t[0])) * (t[1] * 8.0) + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-(t[0])) * (t[1] * 4.0) + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                ++field_7D2;
              }
              field_7DC = field_7DC + 1.0;
              if ( field_7DC >= 7.0 )
                field_7DC = field_7DC - 7.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              field_190 = 1;
              spell_energy_spend(200, 120);
              play_sfx(2);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 14.0;
              addbullet(this, NULL, 827, x, y, dir, 1, t, 3);
            }
            return;
          case 572:
            if ( get_subseq() == 3 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                reset_forces();
                goto LABEL_247;
              }
            }
            field_18C = 11;
            if ( get_subseq() == 1 )
            {
              v630 = 12;
              if ( skills_1[11] >= 2 )
                v630 = 14;
              if ( skills_1[11] >= 3 )
                v630 = 16;
              if ( skills_1[11] >= 4 )
                v630 = 18;
              if ( field_7D2 <= v630 )
              {
                t[0] = /*get_next_ranged(100)*/100.0 + 40.0;
                t[1] = /*get_next_ranged(50)*/50.0 * 0.1000000014901161 + 10.0;
                t[2] = field_7DC;
                addbullet(this, NULL, 827, (cos_deg(-t[0]) * (t[1] * 8.0) + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * (t[1] * 4.0) + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                ++field_7D2;
              }
              field_7DC = field_7DC + 1.0;
              if ( field_7DC >= 7.0 )
                field_7DC = field_7DC - 7.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              field_190 = 1;
              spell_energy_spend(200, 120);
              play_sfx(2);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 14.0;
              addbullet(this, NULL, 827, x, y, dir, 1, t, 3);
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 5 )
              v_force = 0.5;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              set_seq(9);
            return;
          case 573:
            if ( get_subseq() == 3 )
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
                set_subseq(3);
                return;
              }
            }
            field_18C = 11;
            if ( get_subseq() == 1 )
            {
              v630 = 18;
              if ( skills_1[11] >= 2 )
                v630 = 20;
              if ( skills_1[11] >= 3 )
                v630 = 22;
              if ( skills_1[11] >= 4 )
                v630 = 24;
              if ( field_7D2 <= v630 )
              {
                t[0] = /*get_next_ranged(100)*/100.0 + 40.0;
                t[1] = /*get_next_ranged(50)*/50.0 * 0.1000000014901161 + 10.0;
                t[2] = field_7DC;
                addbullet(this, NULL, 827, (cos_deg(-t[0]) * (t[1] * 8.0) + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * (t[1] * 4.0) + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                ++field_7D2;
              }
              field_7DC = field_7DC + 1.0;
              if ( field_7DC >= 7.0 )
                field_7DC = field_7DC - 7.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              field_190 = 1;
              spell_energy_spend(200, 120);
              play_sfx(2);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 14.0;
              addbullet(this, NULL, 827, x, y, dir, 1,t, 3);
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 5 )
              v_force = 0.5;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              set_seq(9);
            return;
          case 599:
            if ( field_7D0 > 0 && get_frame() < 7 && field_7D0 < 12 )
            {
            	/*
              field_7D4 = get_next() % 0x23u;
              t[0] = (double)(-20 - get_next() % 0x23u);
              t[1] = (get_next() % 5u + 10);
              t[2] = 0.0;
              addbullet(this, NULL, 807, (double)(20 * (char)dir * (field_7D0 + 1)) + x, y, dir, 1, t, 3);
              t[0] = (double)(get_next() % 0x168u);
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 801, (double)(20 * (char)dir * (field_7D0 + 1)) + x, y, dir, 1, t, 3);
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
            if ( get_subseq() <= 1 )
            {
              sub_46AB50(0, 2);
              if ( get_subseq() == 1 )
              {
                if ( get_elaps_frames() > 60 )
                  goto LABEL_1609;
                v676 = get_elaps_frames() & 0x8000000F == 0;
                if ( get_elaps_frames() & 0x8000000F < 0 )
                  v676 = ((get_elaps_frames() & 0x8000000F - 1) | 0xFFFFFFF0) == -1;
                if ( v676 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 850, x, y, -dir, 1, t, 3);
                }
                if ( !(get_elaps_frames() % 25) )
                {
                  /*
                  v1367 = 1.0;
                  v1366 = 15.0;
                  v1159 = 0.0;
                  v678 = (float)0.0;
                  do
                  {
                    *(float *)&v1365 = v678 * 45.0 + 22.5;
                    v679 = sin_deg(*(float *)&v1365) >= 0.0;
                    addbullet(this, NULL, 850, x, y, dir, (1 - 2 * v679), (int)&v1365, 3);
                    v1159 = v1159 + 1.0;
                    v678 = v1159;
                  }
                  while ( v1159 < 8.0 );
                  */
                }
                if ( field_190 )
                {
                  if ( ++field_7D0 >= 6 )
                  {
                    field_7D0 = 0;
                    field_190 = 0;
                    field_194 = 1;
                  }
                }
              }
            }
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 0.1000000014901161;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(13 * (char)dir), y + 74.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(100);
              h_inerc = 3.0;
            }
            return;
          case 601:
            if ( get_subseq() == 5 )
            {
              sub10func();
              
            }
            if ( get_subseq() <= 2 )
            {
              sub_46AB50(0, 2);
              
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 6) )
              {
                /*
                v1364 = 1.0;
                v1363 = 30.0;
                dY()3 = /*get_next_ranged(360)*//*360.0;
                v1160 = 0.0;
                v686 = (float)0.0;
                do
                {
                  *(float *)&v1362 = v686 * 45.0 + 22.5 + dY()3;
                  v687 = (1 - 2 * (sin_deg(*(float *)&v1362) >= 0.0));
                  v688 = dir;
                  v689 = getlvl_height();
                  addbullet(this, NULL, 851, x, v689, v688, v687, (int)&v1362, 3);
                  v1160 = v1160 + 1.0;
                  v686 = v1160;
                }
                while ( v1160 < 8.0 );
                */
              }
            }
            else if ( get_subseq() != 2 )
            {
              goto LABEL_1879;
            }
            if ( get_elaps_frames() > 120 && get_subseq() == 2 )
            {
              v_force = 0.2;
              next_subseq();
              return;
            }
            v676 = (get_elaps_frames() & 0x80000001) == 0;
            if ( ((get_elaps_frames() & 0x80000001)) < 0 )
              v676 = ((((get_elaps_frames() & 0x80000001)) - 1) | 0xFFFFFFFE) == -1;
            if ( v676 )
            {
              field_7E4 = /*get_next_ranged(200)*/200.0 + 100.0;
              t[0] = dash_angle;
              t[1] = 3.0;
              t[2] = field_7DC + 2.0;
              addbullet(this, NULL, 851, cos_deg(-dash_angle) * field_7E4 * (double)dir + x, sin_deg(-dash_angle) * (field_7E4 * 0.25) + y + 150.0, dir, (1 - 2 * (sin_deg(dash_angle) >= 0.0)), t, 3);
              t[0] = -dash_angle;
              field_7E4 = /*get_next_ranged(250)*/250.0 + 200.0;
              addbullet(this, NULL, 851, cos_deg(dash_angle) * field_7E4 * (double)dir + x, sin_deg(dash_angle) * (field_7E4 * 0.25) + y + 150.0, dir, (1 - 2 * (sin_deg(-dash_angle) >= 0.0)), t, 3);
              dash_angle = dash_angle - 30.0;
              field_7DC = field_7DC + 1.0;
              if ( field_7DC > 6.0 )
                field_7DC = field_7DC - 7.0;
              
            }
            if ( !(get_elaps_frames() % 16) )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 851, x, y, -dir, 1, t, 3);
            }
            if ( field_190 )
            {
              if ( ++field_7D0 >= 4 )
              {
                field_7D0 = 0;
                field_190 = 0;
                field_194 = 1;
              }
            }
            v_inerc = v_inerc - 0.5;
            if ( v_inerc < 2.0 )
              v_inerc = 2.0;
LABEL_1879:
            if ( get_subseq() == 3 || get_subseq() == 4 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1985;
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(13 * (char)dir), y + 74.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(101);
              v_inerc = 12.5;
            }
            return;
          case 602:
            sub10func();
            sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              play_sfx(102);
              scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 852, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
              play_sfx(103);
            return;
          case 603:
            sub10func();
            sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              play_sfx(104);
              scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 853, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 2 )
              play_sfx(105);
            return;
          case 604:
            sub10func();
            sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                play_sfx(106);
                t[0] = -45.0;
                t[0] = 0.0;
                t[0] = 0.0;
                addbullet(this, NULL, 854, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 854, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1,t, 3);
              }
            }
            return;
          case 605:
            sub10func();
            sub_46AB50(0, 2);
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 8 )
              h_inerc = 0.0;
            if ( process() )
              goto LABEL_108;
            if ( get_subseq() )
              goto LABEL_1937;
            if ( field_190 == 1 )
            {
              next_subseq();
              field_194 = 1;
              field_190 = 0;
              return;
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                play_sfx(106);
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 855, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 855, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                scene_add_effect(this, 58, (double)(75 * (char)dir) + x, y, dir, -1);
                //shake_camera(10.0);
              }
            }
LABEL_1937:
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1942;
            if ( get_subseq() != 1 )
              goto LABEL_1946;
            if ( field_190 != 1 )
              goto LABEL_108;
LABEL_1942:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 8 )
            {
              h_inerc = 100.0;
              play_sfx(106);
              t[0] = -60.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 855, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 855, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              t[2] = 2.0;
              addbullet(this, NULL, 855, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              scene_add_effect(this, 58, (double)(100 * (char)dir) + x, y, dir, -1);
              //shake_camera(10.0);
            }
LABEL_1946:
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1952;
            if ( get_subseq() == 2 )
            {
              if ( !field_190 )
              {
LABEL_108:
                set_seq(0);
                return;
              }
              field_194 = 1;
              field_190 = 0;
LABEL_1952:
              if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 6 )
              {
                play_sfx(107);
                t[0] = -45.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 855, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 855, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                t[2] = 2.0;
                addbullet(this, NULL, 855, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                /*
                v1162 = 0.0;
                v797 = (float)0.0;
                do
                {
                  *(float *)&v1175 = v797 * 18.0;
                  v1176 = 65.0;
                  v1177 = 4.0;
                  v798 = sin_deg(*(float *)&v1175) >= 0.0;
                  LOBYTE(v799) = dir;
                  v800 = get_pframe();
                  v801 = y - (double)v800->extra1[5];
                  v802 = v801;
                  v803 = (double)(v800->extra1[4] * (char)v799) + x;
                  addbullet(this, NULL, 855, v803, v802, v799, (1 - 2 * v798), (int)&v1175, 3);
                  v1162 = v1162 + 1.0;
                  v797 = v1162;
                }
                while ( v1162 < 20.0 );
                v1177 = 1.0;
                v1176 = 30.0;
                dY()4 = /*get_next_ranged(360)*//*360.0;
                v1163 = 0.0;
                v804 = (float)0.0;
                do
                {
                  *(float *)&v1175 = v804 * 45.0 + 22.5 + dY()4;
                  v805 = sin_deg(*(float *)&v1175) >= 0.0;
                  addbullet(this, NULL, 851, x, y, dir, (1 - 2 * v805), (int)&v1175, 3);
                  v1163 = v1163 + 1.0;
                  v804 = v1163;
                }
                while ( v1163 < 8.0 );
                */
              }
            }
            break;
          case 606:
            sub10func();
            sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 20) )
              {
                scene_add_effect(this, 127, x + 0.0, y, dir, -1);
              }
              if ( dX(dir) > 0 )
                h_inerc = 2.0;
              if ( dX(dir) < 0 )
                h_inerc = -2.0;
              if ( !keyDown(INP_X_AXIS) )
                h_inerc = 0.0;
              if ( field_190 )
              {
                if ( ++field_7D0 >= 6 )
                {
                  field_7D0 = 0;
                  field_190 = 0;
                  field_194 = 1;
                }
              }
              if ( !get_frame_time() )
              {
                play_sfx(108);
                /*
                tt[0] = /*get_next_ranged(18)*//*18.0 + (sin_deg(field_7DC * 25.0) * 45.0) - 9.0;
                tt[1] = 15.0;
                tt[2] = 14.0;
                tt[3] = (double)(field_7DC % 7);
                addbullet(this, NULL, 856, v819, sin_deg(-t[0]) * 20.0 + y + 115.0, dir, 1, tt, 4);
                tt[0] = /*get_next_ranged(18)*//*18.0 - sin_deg(field_7DC * 25.0) * 45.0 - 9.0;
                addbullet(this, NULL, 856, (cos_deg(-t[0]) * 20.0 + 40.0) * (double)dir + x, sin_deg(-t[0]) * 20.0 + y + 115.0, dir, 1, tt, 4);
                */
                field_7DC = field_7DC + 1.0;
              }
              if ( get_elaps_frames() >= 90 )
              {
                next_subseq();
                h_inerc = 0.0;
              }
            }
            return;
          case 607:
            if ( get_subseq() && get_subseq() != 5 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1985:
                y = getlvl_height();
                reset_forces();
                set_subseq(5);
                return;
              }
            }
            else
            {
              sub10func();
            }
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 5 )
                h_inerc = 0.0;
              if ( !get_frame_time() && get_frame() == 6 )
                h_inerc = 0.0;
            }
            sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() )
            {
              if ( !get_frame_time() && get_frame() == 2 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 5 )
                  h_inerc = 48.0;
                if ( !get_frame_time() && get_frame() == 6 )
                {
                  h_inerc = 48.0;
                  //shake_camera(10.0);
                  play_sfx(111);
                  t[0] = 0.0;
                  t[1] = 0.5;
                  t[2] = 2.0;
                  addbullet(this, NULL, 857, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, -1, t, 3);
                  t[2] = 4.0;
                  addbullet(this, NULL, 857, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, -1, t, 3);
                }
              }
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2011;
            if ( get_subseq() != 1 )
              goto LABEL_2028;
            play_sfx(112);
            field_7DC = 30.0;
            field_190 = 0;
            field_194 = 1;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 857, x, y, dir, 1, t, 3);
            t[2] = 1.0;
            addbullet(this, NULL, 857, x, y, dir, 1, t, 3);
LABEL_2011:
            if ( get_subseq() != 1 )
              goto LABEL_2028;
            //WHATIS?
            //set_vec_speed((render_class *)&cEffectSprite, -25.0, field_7DC);
            if ( field_190 && !field_7D0 )
            {
              field_7D0 = 1;
              field_7DC = 1.5;
              field_194 = 16;
            }
            if ( field_7D0 != 1 )
              goto LABEL_2022;
            if ( field_190 )
            {
              if ( ++field_7D2 >= 4 )
              {
                field_190 = 0;
                ++field_7D4;
                field_7D2 = 0;
                if ( field_194 <= 0 )
                {
                  field_194 = 1;
                  next_subseq();
                  /*
                  v1164 = 0.0;
                  v844 = (float)0.0;
                  do
                  {
                    *(float *)&v1196 = v844 * 12.0;
                    v1197 = 40.0;
                    v1198 = 4.0;
                    v845 = sin_deg(*(float *)&v1196) >= 0.0;
                    LOBYTE(v846) = dir;
                    v847 = get_pframe();
                    v848 = y - (double)v847->extra1[5];
                    v849 = v848;
                    v850 = (double)(v847->extra1[4] * (char)v846) + x;
                    addbullet(this, NULL, 855, v850, v849, v846, (1 - 2 * v845), (int)&v1196, 3);
                    v1164 = v1164 + 1.0;
                    v844 = v1164;
                  }
                  while ( v1164 < 30.0 );
                  */
                  field_7DC = 40.0;
                }
              }
            }
            else if ( ++field_7D2 >= 10 )
            {
              h_inerc = h_inerc * 0.25;
              v_inerc = v_inerc * 0.5;
              v_force = 0.5;
              set_subseq(2);
              field_194 = 0;
              field_7DC = 40.0;
              return;
            }
LABEL_2022:
            if ( get_elaps_frames() < 20 || field_7D0 )
            {
              t[0] = /*get_next_ranged(360)*/360.0;
              t[1] = 10.0;
              t[2] = 4.0;
              addbullet(this, NULL, 855, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, (1 - 2 * (sin_deg(t[0]) >= 0.0)), t, 3);
LABEL_2028:
              if ( get_subseq() == 2 )
              {
                t[0] = /*get_next_ranged(360)*/360.0;
                t[1] = 10.0;
                t[2] = 4.0;
                addbullet(this, NULL, 855, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, (1 - 2 * (sin_deg(t[0]) >= 0.0)), t, 3);
                field_7DC = field_7DC - 1.0;
                if ( field_7DC > 10.0 )
                {
                  //WHATIS?
            //set_vec_speed((render_class *)&cEffectSprite, -25.0, dY()5);
                }
                else
                {
                  h_inerc = h_inerc * 0.5;
                  v_inerc = 0.5 * v_inerc;
LABEL_2031:
                  v_force = 0.5;
                  next_subseq();
                }
              }
            }
            else
            {
              h_inerc = h_inerc * 0.25;
              v_inerc = v_inerc * 0.5;
              v_force = 0.5;
              set_subseq(3);
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
                field_4A6 = 40;
                scene_play_sfx(23);
                play_sfx(102);
                scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 6 )
              {
                play_sfx(109);
                //shake_camera(10.0);
                /*
                v1165 = 0.0;
                v871 = (float)0.0;
                do
                {
                  *(float *)&v1323 = v871 * 12.0;
                  v1324 = 100.0;
                  v1325 = 0.0;
                  v872 = dir;
                  v873 = get_pframe();
                  v874 = y - (double)v873->extra1[5];
                  v875 = v874;
                  v876 = (double)(v873->extra1[4] * (char)v872) + x;
                  addbullet(this, NULL, 858, v876, v875, v872, 1, (int)&v1323, 3);
                  v1165 = v1165 + 1.0;
                  v871 = v1165;
                }
                while ( v1165 < 30.0 );
                v1325 = 2.0;
                v877 = dir;
                v878 = get_pframe();
                v879 = y - (double)v878->extra1[5];
                v880 = v879;
                v881 = (double)(v878->extra1[4] * (char)v877) + x;
                addbullet(this, NULL, 858, v881, v880, v877, 1, (int)&v1323, 3);
                */
              }
            }
            return;
          case 609:
            sub10func();
            sub_46AB50(0, 2);
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              field_4A6 = 40;
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x,  y - (double)get_pframe()->extra1[5], dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              h_inerc = 17.5;
            
            if ( get_subseq() != 1 )
              goto LABEL_2064;
            if ( get_elaps_frames() >= 30 || (dir == 1) && (enemy->x > (double)x) && enemy->x - x <= 200.0 )
            {
              next_subseq();
              return;
            }
            if ( dir == -1 )
            {
              if ( enemy->x < (double)x && x - enemy->x <= 200.0 )
              {
                next_subseq();
                return;
              }
            }
LABEL_2064:
            if ( get_subseq() == 2 )
            {
              if ( !get_frame_time() && get_frame() == 3 )
                scene_add_effect(this, 127, x, y, dir, -1);
              if ( field_190 == 1 )
              {
                t[0] = 0.0;
                t[1] = 0.5;
                t[2] = 3.0;
                addbullet(this, NULL, 859, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                /*
                v1166 = 0.0;
                v896 = (float)0.0;
                do
                {
                  *(float *)&v1206 = v896 * 18.0;
                  v1207 = 30.0;
                  v1208 = 4.0;
                  v897 = dir;
                  v898 = get_pframe();
                  v899 = y - (double)v898->extra1[5];
                  v900 = v899;
                  v901 = (double)(v898->extra1[4] * (char)v897) + x;
                  addbullet(this, NULL, 859, v901, v900, v897, 1, (int)&v1206, 3);
                  v1166 = v1166 + 1.0;
                  v896 = v1166;
                }
                while ( v1166 < 20.0 );
                */
                enemy->field_4BA = 6000;
                enemy->reset_forces();
                set_seq(102);
                play_sfx(113);
                next_subseq();
                return;
              }
              h_inerc = h_inerc - 0.75;
              
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
            {
              if ( get_subseq() == 3 )
              {
                if ( get_elaps_frames() == 30 )
                {
                  play_sfx(114);
                  tt[0] = 0.0;
                  tt[1] = 0.0;
                  tt[2] = 6.0;
                  tt[3] = 0.0;
                  addbullet(this, NULL, 859, enemy->x, enemy->y + 100.0, dir, 1, tt, 4);
                  
                }
                if ( !(get_elaps_frames() % 15) && field_7DC < 7.0 && get_elaps_frames() >= 15 )
                {
                  tt[0] = field_7DC * 360.0 / 7.0;
                  tt[1] = 0.0;
                  tt[2] = 0.0;
                  tt[3] = 360.0 * field_7DC / 7.0;
                  addbullet(this, NULL, 859, enemy->x, enemy->y + 100.0, dir, 1, tt, 4);
                  field_7DC = field_7DC + 1.0;
                  
                }
                if ( get_elaps_frames() != 180 )
                {
                  dash_angle = dash_angle + 0.5;
                  v219 = h_inerc - 0.5;
                  goto LABEL_675;
                }
                if ( weather_id == 1 )
                  sub_464110(5625.0, 750, 1, 1);
                else
                  sub_464110(4500.0, 750, 1, 1);
                enemy->damage_limit = 100;
                enemy->field_1A4 = 0.0;
                enemy->field_1A8 = 25.0;
                enemy->field_4BA = 6000;
                set_seq(77);
                scene_add_effect(this, 4, enemy->x, enemy->y + 100.0, dir, 1);
                next_subseq();
                //shake_camera(20.0);
                play_sfx(115);
                t[0] = 0.0;
                t[1] = 0.2;
                t[2] = 5.0;
                addbullet(this, NULL, 859, enemy->x, enemy->y + 100.0, dir, 1, t, 3);
                /*
                v912 = 25;
                do
                {
                  *(float *)&v1260 = /*get_next_ranged(360)*//*360.0;
                  v1261 = get_next_ranged(40) + 12.5;
                  v1262 = 7.0;
                  v913 = enemy;
                  v914 = v913->y + 100.0;
                  addbullet(this, NULL, 859, v913->x, v914, dir, 1, (int)&v1260, 3);
                  --v912;
                }
                while ( v912 );
                */
              }
            }
            else if ( get_subseq() == 3 )
            {
              set_seq(get_elaps_frames());
            }
            return;
          case 611:
            sub10func();
            if ( get_subseq() <= 4 )
              sub_46AB50(0, 2);
            if ( get_subseq() >= 3 )
              field_890 = 480;
            if ( process() )
              set_seq(0);
            if ( get_subseq() == 2 && !(get_elaps_frames() % 10) )
            {
              t[0] = 0.0;
              t[1] = (double)get_elaps_frames() + (double)get_elaps_frames();
              t[2] = 1.0;
              addbullet(this, NULL, 861, x, y, dir, 1, t, 3);
            }
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
              {
                field_4A6 = 40;
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                play_sfx(110);
                scene_add_effect(this, 127, x, y, dir, -1);
                field_190 = 1;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 861, x, y, dir, -1, t, 3);
                t[2] = 2.0;
                addbullet(this, NULL, 861, x, y, dir, 1, t, 3);
                field_1A2 = 256;
                field_890 = 480;
                field_7FC = 0.0;
              }
            }
            return;
          case 695:
            sub10func();
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
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
            if ( get_frame() > 5 )
            {
              h_inerc = h_inerc - 3.0;
              if ( h_inerc - 3.0 < 0.0 )
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
                addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
              }
              if ( !get_frame_time() && get_frame() == 5 )
              {
                scene_play_sfx(29);
                field_49A = 0;
              }
            }
            return;
          case 707:
            sub10func();
            if ( h_inerc > 12.0 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 12.0 )
                h_inerc = 12.0;
            }
            if ( process() )
              goto LABEL_2448;
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_2139;
            if ( get_subseq() != 1 )
              goto LABEL_2474;
            h_inerc = 15.0;
            scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
            scene_add_effect(this, 126, x, y + 80.0, dir, 1);
            scene_play_sfx(31);
LABEL_2139:
            if ( get_subseq() == 1 ) //reversed condition
            {
LABEL_2474:
              
              if ( !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
              }
              
              if ( field_854 <= 0.0 )
              {
                next_subseq();
                return;
              }
              field_854 = field_854 - 1.0;
            }
            if ( get_subseq() == 2 )
            {
              v219 = h_inerc - 0.5;
LABEL_675:
              h_inerc = v219;
              if ( v219 < 0.0 )
                h_inerc = 0.0;
            }
            return;
          case 708:
            if ( !get_subseq() || get_subseq() == 3 )
            {
              sub10func();
              
            }
            if ( get_subseq() == 3 )
            {
              h_inerc = h_inerc + 2.0;
              if ( h_inerc + 2.0 > 0.0 )
                h_inerc = 0.0;
            }
            if ( !char_on_ground_flag() && !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
            }
            if ( get_subseq() < 3 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
            {
LABEL_246:
              v_inerc = 0.0;
              v_force = 0.0;
LABEL_247:
              y = getlvl_height();
              set_subseq(3);
            }
            else if ( process() )
            {
LABEL_249:
              set_seq(0);
              reset_forces();
            }
            else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              h_inerc = field_85C;
              v_inerc = field_860;
              v_force = field_864;
              scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
              scene_play_sfx(31);
            }
            return;
          case 710:
            if ( get_subseq() <= 2 || get_subseq() == 6 )
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
                set_subseq(6);
                return;
              }
            }
            if ( !get_subseq() && !(get_elaps_frames() % 2) )
            {
              t[0] = /*get_next_ranged(360)*/360.0;
              t[1] = /*get_next_ranged(400)*/400.0 + 200.0;
              t[2] = (double)(/*get_next_ranged(100)*/100.0 >= 0x32);
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_subseq() != 1 )
              goto LABEL_2475;
            if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
            {
              t[0] = /*get_next_ranged(360)*/360.0;
              t[1] = /*get_next_ranged(400)*/400.0 + 200.0;
              t[2] = (double)(/*get_next_ranged(100)*/100.0 >= 0x32);
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_elaps_frames() < field_7D0 )
            {
LABEL_2475:
              if ( get_subseq() != 3 )
                goto LABEL_2476;
              field_7DC = field_7DC - 0.75;
              if ( field_7DC <= 5.0 )
                field_7DC = 5.0;
              //WHATIS?
            //set_vec_speed((render_class *)&cEffectSprite, -25.0, field_7DC);
              if ( field_7DC > 5.0 || (++field_7D6, field_194 = 0, field_7D6 < 60) )
              {
LABEL_2476:
                if ( process() )
                  set_seq(0);
                if ( !get_elaps_frames() )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  {
                    if ( settings_get()->get_difficulty() == 3 )
                    {
                      //shake_camera(10.0);
                      play_sfx(15);
                      t[0] = 0.0;
                      t[1] = 0.0;
                      t[2] = 1.0;
                      addbullet(this, NULL, 902, (double)(79 * dir) + x, y, dir, -1, t, 3);
                    }
                    else if ( settings_get()->get_difficulty() == 2 )
                    {
                      //shake_camera(10.0);
                      play_sfx(15);
                      t[0] = 0.0;
                      t[1] = 0.0;
                      t[2] = 0.0;
                      addbullet(this, NULL, 902, (double)(79 * (char)dir) + x, y, dir, -1, t, 3);
                    }
                    else
                    {
                      scene_add_effect(this, 58, (double)(76 * (char)dir) + x, y, dir, -1);
                      //shake_camera(5.0);
                      play_sfx(15);
                    }
                    switch ( settings_get()->get_difficulty() )
                    {
                      case 0:
                        field_7D0 = 150;
                        field_7DC = 25.0;
                        field_7D2 = 10;
                        dash_angle = 25.0;
                        field_7E4 = 10.0;
                        field_7D4 = 30;
                        break;
                      case 1:
                        field_7D0 = 120;
                        field_194 = 1;
                        field_7DC = 25.0;
                        field_7D2 = 15;
                        dash_angle = 30.0;
                        field_7E4 = 8.0;
                        field_7D4 = 70;
                        break;
                      case 2:
                        field_7D0 = 90;
                        field_194 = 1;
                        field_7DC = 30.0;
                        field_7D2 = 20;
                        dash_angle = 37.5;
                        field_7E4 = 6.0;
                        field_7D4 = 115;
                        break;
                      case 3:
                        field_7D0 = 60;
                        field_194 = 1;
                        field_7DC = 30.0;
                        field_7D2 = 30;
                        dash_angle = 50.0;
                        field_7E4 = 4.0;
                        field_7D4 = 160;
                        break;
                      default:
                        break;
                    }
                  }
                  if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                  {
                    play_sfx(20);
                    //WHATIS?
            //set_vec_speed((render_class *)&cEffectSprite, -25.0, field_7DC);
                    /*
                    v971 = 0;
                    if ( field_7D2 > 0 )
                    {
                      do
                      {
                        *(float *)&v1190 = get_next_ranged(2 * (unsigned __int64)(signed __int64)dash_angle) - 25.0 - dash_angle;
                        v1191 = get_next_ranged(field_7D4) * 0.1000000014901161 + field_7E4;
                        v1192 = (double)(v971 % 7 + 5);
                        v972 = dir;
                        v973 = get_pframe();
                        v974 = y - (double)v973->extra1[5];
                        v975 = v974;
                        v976 = (double)(v973->extra1[4] * (char)v972) + x;
                        addbullet(this, NULL, 900, v976, v975, v972, 1, (int)&v1190, 3);
                        ++v971;
                      }
                      while ( v971 < field_7D2 );
                    }
                    v1192 = 3.0;
                    addbullet(this, NULL, 900, x, y, dir, 1, (int)&v1190, 3);
                    v1192 = 4.0;
                    addbullet(this, NULL, 900, x, y, dir, 1, (int)&v1190, 3);
                    v1168 = 0.0;
                    v977 = (float)0.0;
                    do
                    {
                      *(float *)&v1190 = v977 * 12.0;
                      v1191 = 40.0;
                      v1192 = 4.0;
                      v978 = sin_deg(*(float *)&v1190) >= 0.0;
                      LOBYTE(v979) = dir;
                      v980 = get_pframe();
                      v981 = y - (double)v980->extra1[5];
                      v982 = v981;
                      v983 = (double)(v980->extra1[4] * (char)v979) + x;
                      addbullet(this, NULL, 855, v983, v982, v979, (1 - 2 * v978), (int)&v1190, 3);
                      v1168 = v1168 + 1.0;
                      v977 = v1168;
                    }
                    while ( v1168 < 30.0 );
                    */
                    scene_add_effect(this, 127, x, y, dir, -1);
                  }
                }
              }
              else
              {
                v_force = 0.5;
                next_subseq();
              }
            }
            else
            {
              next_subseq();
              flip_with_force();
            }
            return;
          case 711:
            if ( get_subseq() <= 1 || get_subseq() == 6 )
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
                set_subseq(6);
                return;
              }
            }
            if ( !get_subseq() && !(get_elaps_frames() % 2) )
            {
              t[0] = /*get_next_ranged(360)*/360.0;
              t[1] = /*get_next_ranged(400)*/400.0 + 200.0;
              t[2] = (double)(/*get_next_ranged(100)*/100.0 >= 0x32);
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
              {
                t[0] = /*get_next_ranged(360)*/360.0;
                t[1] = /*get_next_ranged(400)*/400.0 + 200.0;
                t[2] = (double)(/*get_next_ranged(100)*/100.0 >= 0x32);
                addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              }
              if ( get_elaps_frames() >= field_7D0 )
                goto LABEL_2224;
            }
            if ( process() )
              set_seq(700);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  field_7D0 = 40;
                  field_7DC = 15.0;
                  field_7D2 = 15;
                  dash_angle = 30.0;
                  field_7E4 = 10.0;
                  field_7D4 = 30;
                  break;
                case 1:
                  field_7D0 = 30;
                  field_194 = 1;
                  field_7DC = 20.0;
                  field_7D2 = 20;
                  dash_angle = 35.0;
                  field_7E4 = 8.0;
                  field_7D4 = 70;
                  break;
                case 2:
                  field_7D0 = 20;
                  field_194 = 1;
                  field_7DC = 20.0;
                  field_7D2 = 27;
                  dash_angle = 40.0;
                  field_7E4 = 5.0;
                  field_7D4 = 150;
                  break;
                case 3:
                  field_7D0 = 10;
                  field_194 = 1;
                  field_7DC = 30.0;
                  field_7D2 = 35;
                  dash_angle = 45.0;
                  field_7E4 = 3.0;
                  field_7D4 = 220;
                  break;
                default:
                  break;
              }
              /*
              v1001 = 0;
              if ( field_7D2 > 0 )
              {
                do
                {
                  *(float *)&v1457 = get_next_ranged(2 * (unsigned __int64)(signed __int64)dash_angle) + 45.0 - dash_angle;
                  v1458 = get_next_ranged(field_7D4) * 0.1000000014901161 + field_7E4;
                  v1459 = (double)(v1001 % 7 + 5);
                  v1002 = dir;
                  v1003 = get_pframe();
                  v1004 = y - (double)v1003->extra1[5];
                  v1005 = v1004;
                  v1006 = (double)(v1003->extra1[4] * (char)v1002) + x;
                  addbullet(this, NULL, 900, v1006, v1005, v1002, 1, (int)&v1457, 3);
                  ++v1001;
                }
                while ( v1001 < field_7D2 );
              }
              */
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
            {
              play_sfx(9);
              h_inerc = /*get_next_ranged(50)*/50.0 * 0.1000000014901161 + (enemy->x - x) * (double)dir / 100.0;
              if ( /*get_next_ranged(100)*/100.0 <= 0x32 )
                h_inerc = 2.0;
              v_inerc = 22.5;
              v_force = 0.75;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 900, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_subseq() == 3 && v_inerc < 0.0 )
            {
              play_sfx(10);
              next_subseq();
            }
            return;
          case 712:
            if ( get_subseq() == 3 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                v_inerc = 0.0;
                v_force = 0.0;
                y = getlvl_height();
                set_subseq(4);
                return;
              }
            }
            else
            {
              sub10func();
            }
            if ( !get_subseq() && !(get_elaps_frames() % 2) )
            {
              t[0] = /*get_next_ranged(360)*/360.0;
              t[1] = /*get_next_ranged(400)*/400.0 + 200.0;
              t[2] = (double)(/*get_next_ranged(100)*/100.0 >= 0x32);
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_subseq() != 1 )
              goto LABEL_2477;
            if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
            {
              t[0] = /*get_next_ranged(360)*/360.0;
              t[1] = /*get_next_ranged(400)*/400.0 + 200.0;
              t[2] = (double)(/*get_next_ranged(100)*/100.0 >= 0x32);
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_elaps_frames() >= field_7D0 )
            {
LABEL_2224:
              next_subseq();
              flip_with_force();
            }
            else
            {
LABEL_2477:
              if ( get_subseq() == 3 )
              {
                if ( field_190 )
                {
                  if ( ++field_7D8 >= 4 )
                  {
                    field_7D8 = 0;
                    field_190 = 0;
                  }
                }
              }
              if ( get_subseq() == 4 )
              {
                h_inerc = h_inerc - 1.0;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                    field_7DC = 15.0;
                    field_7D0 = 120;
                    field_194 = 4;
                    goto LABEL_2277;
                  case 1:
                    field_7DC = 25.0;
                    field_7D0 = 90;
                    field_194 = 5;
LABEL_2277:
                    field_7D2 = 0;
                    dash_angle = 4.0;
                    field_7E4 = 1.0;
                    goto LABEL_2278;
                  case 2:
                    field_7D0 = 60;
                    field_194 = 6;
                    field_7DC = 30.0;
                    field_7D2 = 5;
                    dash_angle = 20.0;
                    field_7E4 = 2.0;
                    goto LABEL_2278;
                  case 3:
                    field_7D0 = 60;
                    field_194 = 7;
                    field_7DC = 30.0;
                    field_7D2 = 2;
                    dash_angle = 40.0;
                    field_7E4 = 3.0;
LABEL_2278:
                    break;
                  default:
                    break;
                }
              }
              if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
              {
                tt[0] = 0.0;
                tt[1] = 0.0;
                tt[2] = 0.0;
                tt[3] = field_7E4;
                addbullet(this, NULL, 901, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, tt, 4);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                play_sfx(6);
                h_inerc = field_7DC;
                v_inerc = 4.0;
                v_force = 0.40000001;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 9.0;
                addbullet(this, NULL, 901, x, y, dir, 1, t, 3);
                scene_add_effect(this, 127, x, y, dir, -1);
              }
            }
            return;
          case 720:
            if ( get_subseq() <= 2 || get_subseq() == 6 )
            {
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( get_subseq() <= 3 && v_inerc <= 1.0 )
                v_inerc = 1.0;
              if ( char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
                set_subseq(6);
                return;
              }
            }
            if ( !get_subseq() && !(get_elaps_frames() % 2) )
            {
              t[0] = /*get_next_ranged(360)*/360.0;
              t[1] = /*get_next_ranged(400)*/400.0 + 200.0;
              t[2] = (double)(/*get_next_ranged(100)*/100.0 >= 0x32);
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_subseq() != 1 )
              goto LABEL_2478;
            if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
            {
              t[0] = /*get_next_ranged(360)*/360.0;
              t[1] = /*get_next_ranged(400)*/400.0 + 200.0;
              t[2] = (double)(/*get_next_ranged(100)*/100.0 >= 0x32);
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_elaps_frames() >= field_7D0 )
            {
LABEL_1609:
              next_subseq();
            }
            else
            {
LABEL_2478:
              if ( get_subseq() == 3 )
              {
                if ( dir == 1 )
                {
                  if ( h_inerc > 0.0 && get_border_near() == -1 )
                    h_inerc = -h_inerc;
                  if ( h_inerc < 0.0 && get_border_near() == 1 )
                    h_inerc = -h_inerc;
                }
                if ( dir == -1 )
                {
                  if ( h_inerc > 0.0 && get_border_near() == 1 )
                    h_inerc = -h_inerc;
                  if ( h_inerc < 0.0 && get_border_near() == -1 )
                    h_inerc = -h_inerc;
                }
                field_7DC = field_7DC + 1.0;
                if ( field_7E8 < (double)field_7DC )
                  field_7DC = field_7E8;
                if ( get_elaps_frames() <= field_7D6 )
                {
                  if ( !(get_elaps_frames() % field_7D2) )
                  {
                    /*
                    v1055 = 0;
                    if ( field_7D4 > 0 )
                    {
                      do
                      {
                        *(float *)&v1227 = get_next_ranged(2 * (unsigned __int64)(signed __int64)field_7DC) - field_7DC + 90.0;
                        v1056 = get_next_ranged((signed __int64)field_7E4) * 0.1000000014901161;
                        v1228 = v1056 + dash_angle;
                        v1229 = get_next_ranged(7);
                        v1057 = dir;
                        v1058 = -*(float *)&v1227;
                        v1059 = sin_deg(v1058);
                        v1060 = v1059 * (v1228 * 8.0) + y - (double)get_pframe()->extra1[5];
                        v1061 = v1060;
                        v1062 = -*(float *)&v1227;
                        v1063 = cos_deg(v1062);
                        v1064 = (v1063 * (v1228 * 8.0) + (double)get_pframe()->extra1[4]) * (double)dir + x;
                        addbullet(this, NULL, 910, v1064, v1061, v1057, 1, (int)&v1227, 3);
                        ++v1055;
                      }
                      while ( v1055 < field_7D4 );
                    }
                    */
                  }
                  if ( get_elaps_frames() == field_7D6 )
                  {
                    if ( settings_get()->get_difficulty() == 3 )
                    {
                      /*
                      v1170 = 0.0;
                      do
                      {
                        *(float *)&v1233 = get_next_ranged(6) + v1170 * 12.0;
                        v1234 = get_next_ranged(20) * 0.1000000014901161 + 2.0;
                        v1235 = (double)(v1170 % 7);
                        v1066 = dir;
                        v1067 = -*(float *)&v1233;
                        v1068 = sin_deg(v1067);
                        v1069 = v1068 * (v1234 * 8.0) + y - (double)get_pframe()->extra1[5];
                        v1070 = v1069;
                        v1071 = -*(float *)&v1233;
                        v1072 = cos_deg(v1071);
                        v1073 = (v1072 * (v1234 * 8.0) + (double)get_pframe()->extra1[4]) * (double)dir + x;
                        addbullet(this, NULL, 910, v1073, v1070, v1066, 1, (int)&v1233, 3);
                        v1170 = v1170 + 1.0;
                      }
                      while ( v1170 < 30.0 );
                      */
                    }
                    if ( settings_get()->get_difficulty() == 2 || settings_get()->get_difficulty() == 3 )
                    {
                      /*
                      v1171 = 0.0;
                      do
                      {
                        *(float *)&v1239 = get_next_ranged(6) + v1171 * 12.0;
                        v1240 = get_next_ranged(45) * 0.1000000014901161 + 9.0;
                        v1241 = (double)(v1171 % 7);
                        v1074 = dir;
                        v1075 = -*(float *)&v1239;
                        v1076 = sin_deg(v1075);
                        v1077 = v1076 * (v1240 * 8.0) + y - (double)get_pframe()->extra1[5];
                        v1078 = v1077;
                        v1079 = -*(float *)&v1239;
                        v1080 = cos_deg(v1079);
                        v1081 = (v1080 * (v1240 * 8.0) + (double)get_pframe()->extra1[4]) * (double)dir + x;
                        addbullet(this, NULL, 910, v1081, v1078, v1074, 1, (int)&v1239, 3);
                        v1171 = v1171 + 1.0;
                      }
                      while ( v1171 < 30.0 );
                      */
                    }
                  }
                }
                if ( get_elaps_frames() >= field_7D6 + field_7D8 )
                {
                  next_subseq();
                  v_force = 0.15000001;
                }
              }
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  switch ( settings_get()->get_difficulty() )
                  {
                    case 0:
                      field_7D0 = 75;
                      field_7D2 = 4;
                      field_7D4 = 2;
                      field_7D6 = 180;
                      field_7D8 = 0;
                      field_7DC = 20.0;
                      dash_angle = 6.0;
                      field_7E4 = 20.0;
                      field_7E8 = 45.0;
                      goto LABEL_2347;
                    case 1:
                      field_7D0 = 60;
                      field_7D2 = 3;
                      field_7D4 = 2;
                      field_7D6 = 210;
                      field_7D8 = 0;
                      field_7DC = 25.0;
                      dash_angle = 5.0;
                      field_7E4 = 40.0;
                      field_7E8 = 75.0;
                      goto LABEL_2347;
                    case 2:
                      field_7D0 = 45;
                      field_7D2 = 3;
                      field_7D4 = 2;
                      field_7D6 = 210;
                      field_7D8 = 0;
                      field_7DC = 30.0;
                      dash_angle = 4.0;
                      field_7E4 = 60.0;
                      field_7E8 = 90.0;
                      goto LABEL_2347;
                    case 3:
                      field_7D0 = 45;
                      field_7D2 = 3;
                      field_7D4 = 3;
                      field_7D6 = 240;
                      field_7D8 = 0;
                      field_7DC = 35.0;
                      dash_angle = 3.0;
                      field_7E4 = 80.0;
                      field_7E8 = 120.0;
LABEL_2347:
                      break;
                    default:
                      break;
                  }
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                {
                  flip_with_force();
                  play_sfx(102);
                  h_inerc = /*get_next_ranged(30)*/30.0 * 0.1000000014901161 + 2.0;
                  v_inerc = 7.5;
                  v_force = 0.5;
                }
              }
            }
            return;
          case 721:
            sub10func();
            if ( !get_subseq() && !(get_elaps_frames() % 2) )
            {
              t[0] = /*get_next_ranged(360)*/360.0;
              t[0] = /*get_next_ranged(400)*/400.0 + 200.0;
              t[0] = (double)(/*get_next_ranged(100)*/100.0 >= 0x32);
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_subseq() != 1 )
              goto LABEL_2479;
            if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
            {
              t[0] = /*get_next_ranged(360)*/360.0;
              t[1] = /*get_next_ranged(400)*/400.0 + 200.0;
              t[2] = (double)(/*get_next_ranged(100)*/100.0 >= 0x32);
              addbullet(this, NULL, 970, (cos_deg(-t[0]) * t[1] + (double)get_pframe()->extra1[4]) * (double)dir + x, sin_deg(-t[0]) * t[1] + y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_elaps_frames() >= field_7D0 )
            {
LABEL_663:
              next_subseq();
            }
            else
            {
LABEL_2479:
              if ( get_subseq() == 3 )
              {
                if ( dir == 1 )
                {
                  if ( h_inerc > 0.0 && get_border_near() == -1 )
                    h_inerc = -h_inerc;
                  if ( h_inerc < 0.0 && get_border_near() == 1 )
                    h_inerc = -h_inerc;
                }
                if ( dir == -1 )
                {
                  if ( h_inerc > 0.0 && get_border_near() == 1 )
                    h_inerc = -h_inerc;
                  if ( h_inerc < 0.0 && get_border_near() == -1 )
                    h_inerc = -h_inerc;
                }
                field_7DC = field_7DC + 1.0;
                if ( field_7E8 < (double)field_7DC )
                  field_7DC = field_7E8;
                if ( get_elaps_frames() <= field_7D6 )
                {
                  if ( !(get_elaps_frames() % field_7D2) )
                  {
                    /*
                    v1101 = 0;
                    if ( field_7D4 > 0 )
                    {
                      do
                      {
                        *(float *)&v1257 = get_next_ranged(2 * (unsigned __int64)(signed __int64)field_7DC) - field_7DC - 90.0;
                        v1102 = get_next_ranged((signed __int64)field_7E4) * 0.1000000014901161;
                        v1258 = v1102 + dash_angle;
                        v1259 = get_next_ranged(7);
                        v1103 = dir;
                        v1104 = -*(float *)&v1257;
                        v1105 = sin_deg(v1104);
                        v1106 = v1105 * (v1258 * 8.0) + y - (double)get_pframe()->extra1[5];
                        v1107 = v1106;
                        v1108 = -*(float *)&v1257;
                        v1109 = cos_deg(v1108);
                        v1110 = (v1109 * (v1258 * 8.0) + (double)get_pframe()->extra1[4]) * (double)dir + x;
                        addbullet(this, NULL, 910, v1110, v1107, v1103, 1, (int)&v1257, 3);
                        ++v1101;
                      }
                      while ( v1101 < field_7D4 );
                    }
                    */
                  }
                  if ( get_elaps_frames() == field_7D6 )
                  {
                    if ( settings_get()->get_difficulty() == 3 )
                    {
                      /*
                      v1172 = 0.0;
                      do
                      {
                        *(float *)&v1263 = get_next_ranged(6) + v1172 * 12.0;
                        v1264 = get_next_ranged(20) * 0.1000000014901161 + 2.0;
                        v1265 = (double)(v1172 % 7);
                        v1112 = dir;
                        v1113 = -*(float *)&v1263;
                        v1114 = sin_deg(v1113);
                        v1115 = v1114 * (v1264 * 8.0) + y - (double)get_pframe()->extra1[5];
                        v1116 = v1115;
                        v1117 = -*(float *)&v1263;
                        v1118 = cos_deg(v1117);
                        v1119 = (v1118 * (v1264 * 8.0) + (double)get_pframe()->extra1[4]) * (double)dir + x;
                        addbullet(this, NULL, 910, v1119, v1116, v1112, 1, (int)&v1263, 3);
                        v1172 = v1172 + 1.0;
                      }
                      while ( v1172 < 30.0 );
                      */
                    }
                    if ( settings_get()->get_difficulty() == 2 || settings_get()->get_difficulty() == 3 )
                    {
                      /*
                      v1173 = 0.0;
                      do
                      {
                        *(float *)&v1269 = get_next_ranged(6) + v1173 * 12.0;
                        v1270 = get_next_ranged(45) * 0.1000000014901161 + 9.0;
                        v1271 = (double)(v1173 % 7);
                        v1120 = dir;
                        v1121 = -*(float *)&v1269;
                        v1122 = sin_deg(v1121);
                        v1123 = v1122 * (v1270 * 8.0) + y - (double)get_pframe()->extra1[5];
                        v1124 = v1123;
                        v1125 = -*(float *)&v1269;
                        v1126 = cos_deg(v1125);
                        v1127 = (v1126 * (v1270 * 8.0) + (double)get_pframe()->extra1[4]) * (double)dir + x;
                        addbullet(this, NULL, 910, v1127, v1124, v1120, 1, (int)&v1269, 3);
                        v1173 = v1173 + 1.0;
                      }
                      while ( v1173 < 30.0 );
                      */
                    }
                  }
                }
                if ( get_elaps_frames() >= field_7D6 + field_7D8 )
                {
                  next_subseq();
                  v_force = 0.15000001;
                }
              }
              if ( get_subseq() == 4 )
              {
                if ( h_inerc > 0.0 )
                {
                  h_inerc = h_inerc - 0.25;
                  if ( h_inerc < 0.0 )
                    h_inerc = 0.0;
                }
                if ( h_inerc < 0.0 )
                {
                  h_inerc = h_inerc + 0.25;
                  if ( h_inerc > 0.0 )
                    h_inerc = 0.0;
                }
              }
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                    field_7D0 = 75;
                    field_7D2 = 4;
                    field_7D4 = 2;
                    field_7D6 = 180;
                    field_7D8 = 90;
                    field_7DC = 20.0;
                    dash_angle = 6.0;
                    field_7E4 = 20.0;
                    field_7E8 = 45.0;
                    break;
                  case 1:
                    field_7D0 = 60;
                    field_7D2 = 3;
                    field_7D4 = 2;
                    field_7D6 = 210;
                    field_7D8 = 90;
                    field_7DC = 25.0;
                    dash_angle = 5.0;
                    field_7E4 = 40.0;
                    field_7E8 = 75.0;
                    break;
                  case 2:
                    field_7D0 = 45;
                    field_7D2 = 3;
                    field_7D4 = 2;
                    field_7D6 = 210;
                    field_7D8 = 60;
                    field_7DC = 30.0;
                    dash_angle = 4.0;
                    field_7E4 = 60.0;
                    field_7E8 = 90.0;
                    break;
                  case 3:
                    field_7D0 = 45;
                    field_7D2 = 3;
                    field_7D4 = 3;
                    field_7D6 = 240;
                    field_7D8 = 60;
                    field_7DC = 35.0;
                    dash_angle = 3.0;
                    field_7E4 = 80.0;
                    field_7E8 = 120.0;
                    break;
                  default:
                    break;
                }
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                flip_with_force();
                play_sfx(102);
                h_inerc = /*get_next_ranged(50)*/50.0 * 0.1000000014901161 + 2.0;
              }
            }
            return;
          case 770:
            if ( process() )
              set_seq(700);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              field_6F5 = 1;
              sub_4685C0(-1);
              sub_46AB50(0, -1);
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
            return;
          case 788:
            if ( get_subseq() == 7 )
            {
              dir = 1;
              h_inerc = 5.0;
              if ( (double)field_7D0 < x )
                goto LABEL_2480;
            }
            if ( get_subseq() == 8 && (dir = -1, h_inerc = 5.0, --field_7D0, field_7D0 <= 0) || get_subseq() == 11 && (dir = 1, h_inerc = 5.0, --field_7D0, field_7D0 <= 0) )
            {
LABEL_2480:
              set_subseq(1);
              h_inerc = 0.0;
            }
            else if ( get_subseq() != 12 || (dir = -1, h_inerc = 5.0, (double)field_7D0 <= x) )
            {
              if ( process() || !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 4 || !get_frame_time() && !get_frame() && get_subseq() == 5) )
                goto LABEL_2448;
              if ( get_subseq() == 4 && !get_frame_time() && get_frame() == 4 )
              {
                play_sfx(1);
                //shake_camera(5.0);
                scene_add_effect(this, 58, (double)(72 * (char)dir) + x, y, dir, -1);
              }
            }
            else
            {
              x = (double)field_7D0;
              set_subseq(1);
              h_inerc = 0.0;
            }
            return;
          case 795:
            if ( get_subseq() )
              goto LABEL_2447;
            v_inerc = v_inerc - 0.300000011920929;
            if ( !char_on_ground_down() )
              goto LABEL_2447;
            move_val = 1;
LABEL_152:
            set_subseq(move_val);
LABEL_153:
            y = getlvl_height();
            reset_forces();
            return;
          case 797:
            if ( !get_subseq() )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_2451;
              
            }
            if ( get_subseq() == 1 )
            {
              h_inerc = h_inerc - 0.75;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
              if ( x > 480.0 )
                x = 480.0;
            }
            if ( process() )
              set_seq(0);
            return;
          case 798:
            if ( get_subseq() )
              goto LABEL_2463;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_2451:
              next_subseq();
              y = getlvl_height();
              v_inerc = 0.0;
            }
            else
            {
              
LABEL_2463:
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
              if ( (get_subseq() == 2 || get_subseq() == 3) && (v_inerc = v_inerc - 0.25, char_on_ground_down()) )
              {
                reset_forces();
                y = getlvl_height();
                set_subseq(4);
                scene_play_sfx(30);
                x = 800.0;
              }
              else
              {
LABEL_2447:
                if ( process() )
LABEL_2448:
                  set_seq(700);
              }
            }
            return;
          default:
LABEL_2471:
            char_c::func10();
            return;
        }
      }
      else if (get_seq()== 560 )
      {
        sub10func();
        field_18C = 3;
        if ( field_7D0 )
        {
          if ( field_7D0 % 7 == 1 && field_7D0 <= 15 )
          {
            play_sfx(17);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            if ( skills_1[3] >= 2 )
              t[2] = 1.0;
            if ( skills_1[3] >= 4 )
              t[2] = 2.0;
            addbullet(this, NULL, 825, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
          }
          ++field_7D0;
        }
        if ( process() )
          set_seq(0);
        if ( !get_subseq() )
        {
          if ( get_frame() || skills_1[3] < 1 || get_frame_time() < 2 )
          {
            if ( !get_frame_time() && get_frame() == 8 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              field_7D0 = 1;
              field_190 = 1;
            }
            if ( get_frame() == 15 )
            {
              v581 = 10;
              if ( skills_1[3] < 1 )
                v581 = (double)(get_pframe()->extra1[4] * (char)dir) + x;
              if ( skills_1[3] >= 3 )
                v581 = 5;
              if ( get_frame_time() >= v581 )
                next_frame();
            }
          }
          else
          {
LABEL_1645:
            next_frame();
          }
        }
      }
      else
      {
        switch (get_seq())
        {
          case 301:
            sub10func();
            if ( true/*!get_true(0)*/)
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
              else if ( get_frame() >= 3 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                set_seq(0);
              if ( !get_frame_time() )
              {
                if ( get_frame() == 1 )
                  h_inerc = 7.5;
                if ( !get_frame_time() && get_frame() == 3 )
                {
                  h_inerc = 3.0;
                  scene_play_sfx(29);
                }
              }
            }
            return;
          case 302:
            sub10func();
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            if ( process() )
              goto LABEL_108;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              set_seq(0);
              return;
            }
            if ( get_subseq() )
            {
              
            }
            else
            {
              if ( !get_frame_time() )
              {
                if ( get_frame() == 1 )
                  h_inerc = 10.0;
                if ( !get_frame_time() && get_frame() == 5 )
                {
                  if ( not_charge_attack )
                  {
                    /*
                    v212 = y + 53.0;
                    a2 = dir;
                    y = v212;
                    v213 = x - (double)(44 * (char)a2);
                    v214 = v213;
                    goto LABEL_662;
                    */
                    return; //TODO: change
                  }
                  h_inerc = 17.5;
                  scene_play_sfx(29);
                }
              }
              
              if ( h_inerc > 0.0 )
              {
                h_inerc = h_inerc - 1.0;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
            }
            if ( get_subseq() != 1 )
              return;
            if ( !get_frame_time() && get_frame() == 1 )
            {
              h_inerc = 18.5;
              scene_play_sfx(29);
              
            }
            if ( 0.0 >= h_inerc )
              return;
            v219 = h_inerc - 1.0;
            goto LABEL_675;
          case 303:
            sub10func();
            if ( true/*!get_true(0)*/)
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
                scene_play_sfx(27);
            }
            return;
          case 304:
            sub10func();
            if ( false /*get_true(1)*/)
              return;
            if ( h_inerc > 0.0 )
            {
              h_inerc = h_inerc - 0.300000011920929;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( !keyDown(INP_A) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(2);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
LABEL_95:
              set_seq(2);
              return;
            }
            if ( get_subseq() || get_frame_time() || get_frame() != 3 )
              goto LABEL_704;
            if ( not_charge_attack == 1 )
            {
              next_subseq();
              scene_add_effect(this, 62, x - (double)(33 * (char)dir), y + 23.0, dir, 1);
            }
            else
            {
              h_inerc = 5.0;
              scene_play_sfx(29);
LABEL_704:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 1 )
              {
                h_inerc = 6.0;
                scene_play_sfx(29);
              }
            }
            return;
          case 305:
            sub10func();
            if ( true/*!get_true(1)*/)
            {
              if ( get_frame() >= 3 )
              {
                h_inerc = h_inerc - 1.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                set_seq(0);
              if ( !get_frame_time() && get_frame() == 2 )
              {
                scene_play_sfx(28);
                h_inerc = 15.0;
              }
            }
            return;
          case 306:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_293;
            if ( process() )
              set_seq(9);
            if ( !get_subseq() && get_frame() == 2 && !get_frame_time() )
              scene_play_sfx(28);
            return;
          case 307:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_151:
              move_val = 10;
              goto LABEL_152;
            }
            if ( get_frame() >= 6 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 3.0 )
                h_inerc = 3.0;
            }
            if ( process() )
              set_seq(9);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_962;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 5 )
              {
                scene_play_sfx(29);
                h_inerc = 15.0;
                v_inerc = 7.5;
                v_force = 0.5;
              }
              if ( !get_frame_time() && get_frame() == 8 )
                v_force = 0.5;
            }
            return;
          case 308:
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_293:
              set_seq(10);
              goto LABEL_153;
            }
            if ( process() )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 4 )
                  scene_play_sfx(29);
                if ( !get_frame_time() && get_frame() == 7 )
                {
                  field_194 = 1;
                  field_190 = 0;
                  scene_play_sfx(29);
                }
              }
            }
            return;
          case 309:
            v_inerc = v_inerc - v_force;
            h_inerc = h_inerc - 0.300000011920929;
            if ( h_inerc < 2.0 )
              h_inerc = 2.0;
            if ( char_on_ground_down() )
            {
LABEL_543:
              set_seq(10);
              goto LABEL_153;
            }
            if ( process() )
              set_seq(9);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                scene_play_sfx(29);
                h_inerc = 8.0;
                v_inerc = 14.5;
                v_force = 0.85000002;
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 7 )
                  v_force = 0.1;
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 8 )
                  {
                    field_194 = 1;
                    field_190 = 0;
                    scene_play_sfx(29);
                  }
                  if ( !get_frame_time() && get_frame() == 10 )
                    v_force = 0.5;
                }
              }
            }
            return;
          case 310:
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 1.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
              sub10func();
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_subseq(2);
                y = getlvl_height();
                v_inerc = 0.0;
                v_force = 0.0;
                field_190 = 1;
              }
            }
            if ( process() )
            {
              if ( dY() <= 0 )
                set_seq(3);
              else
                set_seq(2);
            }
            else if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
            {
              scene_play_sfx(29);
            }
            return;
          case 320:
            sub10func();
            if ( true/*!get_true(0)*/)
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
            if ( true/*!get_true(1)*/)
            {
              if ( get_frame() <= 1 ) //reversed condition
              {
                h_inerc = h_inerc - 2.0;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( get_frame() >= 3 )
              {
                h_inerc = h_inerc - 1.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                set_seq(0);
              if ( !get_frame_time() && get_frame() == 2 )
              {
                scene_play_sfx(28);
                h_inerc = 10.0;
              }
            }
            return;
          case 322:
            sub10func();
            if ( true/*!get_true(0)*/)
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
              else if ( get_frame() >= 3 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                set_seq(0);
              if ( !get_frame_time() )
              {
                if ( get_frame() == 1 )
                  h_inerc = 10.0;
                if ( !get_frame_time() && get_frame() == 3 )
                {
                  h_inerc = 3.0;
                  scene_play_sfx(29);
                }
              }
            }
            return;
          case 323:
            sub10func();
            h_inerc = h_inerc - 0.8999999761581421;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              play_sfx(15);
              //shake_camera(5.0);
              scene_add_effect(this, 58, (double)(72 * (char)dir) + x, y, dir, -1);
            }
            return;
          case 324:
            sub10func();
            if ( true/*!get_true(1)*/)
            {
              if ( h_inerc > 0.0 )
              {
                h_inerc = h_inerc - 0.300000011920929;
                if ( h_inerc < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                set_seq(2);
              if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
              {
                h_inerc = 5.0;
                scene_play_sfx(29);
              }
            }
            return;
          case 330:
            goto LABEL_622;
          case 400:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(0);
            if ( get_subseq() || get_frame_time() )
              goto LABEL_857;
            if ( get_frame() == 3 && not_charge_attack )
            {
              /*
              a2 = dir;
              v244 = y + 133.0;
              y = v244;
              v245 = x - (double)(30 * (char)a2);
              v214 = v245;
              goto LABEL_662;
              */
              return; //TODO: change
            }
            if ( get_frame() == 4 )
            {
              play_sfx(0);
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(105 * (char)dir) + x, y + 93.0, dir, 1, t, 3);
              spell_energy_spend(200, 45);
              add_card_energy(30);
            }
LABEL_857:
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 2 )
              return;
            play_sfx(1);
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 1.0;
            addbullet(this, NULL, 800, (double)(105 * (char)dir) + x, y + 93.0, dir, 1, t, 3);
            goto LABEL_861;
          case 401:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_frame_time() || get_frame() != 5 )
              return;
            sub_486FD0(20.0, -20.0);
            /*
            dY()7 = 0.0;
            v254 = (float)0.0;
            do
            {
              *(float *)&v1329 = 30.0 - 10.0 * v254 + field_7F0;
              v255 = v254 - 3.0;
              v256 = sub_715B70(v255);
              v1330 = 23.0 - (v256 + v256);
              v1331 = dY()7;
              v257 = dir;
              v258 = -*(float *)&v1329;
              v259 = sin_deg(v258) * 100.0 + y + 100.0;
              v260 = v259;
              a3 = -*(float *)&v1329;
              v262 = cos_deg(a3) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 801, v262, v260, v257, 1, (int)&v1329, 3);
              dY()7 = dY()7 + 1.0;
              v254 = dY()7;
            }
            while ( dY()7 < 7.0 );
            */
            play_sfx(2);
            goto LABEL_861;
          case 402:
            sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(2);
            if ( get_frame_time() || get_frame() != 3 )
              return;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 802, (double)(140 * dir) + x, y, dir, 1, t, 3);
            play_sfx(3);
            goto LABEL_861;
          case 404:
            if ( get_subseq() == 2 )
              sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
            {
              set_subseq(2);
              air_dash_cnt = 0;
              goto LABEL_153;
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
            if ( get_subseq() || get_frame_time() )
              goto LABEL_904;
            if ( get_frame() == 3 && not_charge_attack )
            {
              /*
              a2 = dir;
              v264 = y + 161.0;
              y = v264;
              v265 = x - (double)(23 * (char)a2);
              v214 = v265;
              goto LABEL_662;
              */
              return; //TODO: change
            }
            if ( get_frame() == 4 )
            {
              play_sfx(0);
              t[0] = 15.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 800, (double)(79 * (char)dir) + x, y + 121.0, dir, 1, t, 3);
              v_inerc = 8.0;
              h_inerc = -6.0;
              v_force = 0.75;
              spell_energy_spend(200, 45);
              add_card_energy(30);
            }
LABEL_904:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
            {
              play_sfx(1);
              t[0] = 15.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 800, (double)(79 * (char)dir) + x, y + 121.0, dir, 1, t, 3);
              v_inerc = 8.0;
              h_inerc = -6.0;
              v_force = 0.75;
LABEL_861:
              spell_energy_spend(200, 45);
              add_card_energy(30);
            }
            return;
          case 405:
            v_inerc = v_inerc - v_force;
            if ( !get_subseq() && char_on_ground_down() )
              goto LABEL_910;
            if ( get_subseq() == 1 )
              sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_922;
            if ( !get_frame_time() )
            {
              if ( !get_frame() && get_subseq() == 1 )
                set_seq(9);
LABEL_922:
              if ( !get_frame_time() )
              {
                if ( get_frame() == 5 )
                {
                  sub_486FD0(20.0, -20.0);
                  /*
                  dY()8 = 0.0;
                  v274 = (float)0.0;
                  do
                  {
                    *(float *)&v1332 = 30.0 - 10.0 * v274 + field_7F0;
                    v275 = v274 - 3.0;
                    v276 = sub_715B70(v275);
                    v1333 = 23.0 - (v276 + v276);
                    v1334 = dY()8;
                    v277 = dir;
                    v278 = -*(float *)&v1332;
                    v279 = sin_deg(v278) * 100.0 + y + 140.0;
                    v280 = v279;
                    v281 = -*(float *)&v1332;
                    v282 = cos_deg(v281) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 801, v282, v280, v277, 1, (int)&v1332, 3);
                    dY()8 = dY()8 + 1.0;
                    v274 = dY()8;
                  }
                  while ( dY()8 < 7.0 );
                  */
                  play_sfx(2);
                  spell_energy_spend(200, 45);
                  add_card_energy(30);
                }
                if ( !get_frame_time() && get_frame() == 9 )
                  v_force = 0.5;
              }
            }
            return;
          case 406:
            v_inerc = v_inerc - v_force;
            if ( !get_subseq() && char_on_ground_down() )
            {
LABEL_910:
              reset_forces();
              y = getlvl_height();
              set_subseq(1);
              return;
            }
            if ( get_subseq() == 1 )
              sub10func();
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_943;
            if ( !get_frame_time() )
            {
              if ( !get_frame() && get_subseq() == 1 )
                set_seq(9);
LABEL_943:
              if ( !get_frame_time() )
              {
                if ( get_frame() == 5 )
                {
                  sub_486FD0(50.0, 30.0);
                  /*
                  dY()9 = 0.0;
                  v283 = (float)0.0;
                  do
                  {
                    *(float *)&v1344 = 30.0 - 10.0 * v283 + field_7F0;
                    v284 = v283 - 3.0;
                    v285 = sub_715B70(v284);
                    v1345 = 23.0 - (v285 + v285);
                    v1346 = dY()9;
                    v286 = dir;
                    v287 = -*(float *)&v1344;
                    v288 = sin_deg(v287) * 100.0 + y + 140.0;
                    v289 = v288;
                    v290 = -*(float *)&v1344;
                    v291 = cos_deg(v290) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 801, v291, v289, v286, 1, (int)&v1344, 3);
                    dY()9 = dY()9 + 1.0;
                    v283 = dY()9;
                  }
                  while ( dY()9 < 7.0 );
                  */
                  play_sfx(2);
                  spell_energy_spend(200, 45);
                  add_card_energy(30);
                }
                if ( !get_frame_time() && get_frame() == 9 )
                  v_force = 0.5;
              }
            }
            return;
          case 408:
            sub10func();
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              play_sfx(15);
              //shake_camera(5.0);
              scene_add_effect(this, 58, (double)(72 * (char)dir) + x, y, dir, -1);
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
LABEL_962:
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
              set_seq(0);
            if ( get_subseq() || get_frame_time() )
              goto LABEL_979;
            if ( get_frame() == 2 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(10 * (char)dir) + x, y + 94.0, dir, 1);
              return;
            }
            if ( get_frame() == 4 )
            {
              t[0] = 0.0;
              t[1] = 16.0;
              t[2] = 0.0;
              addbullet(this, NULL, 805, x, y, dir, 1, t, 3);
              play_sfx(4);
              spell_energy_spend(200, 60);
              add_card_energy(50);
            }
LABEL_979:
            if ( get_subseq() != 1 || get_frame_time() || get_frame() != 3 )
              return;
            t[0] = 0.0;
            t[1] = 20.0;
            t[2] = 6.0;
            addbullet(this, NULL, 805, x, y, dir, 1, t, 3);
            play_sfx(4);
            goto LABEL_983;
          case 411:
            sub10func();
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              set_seq(0);
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1001;
            if ( get_frame() == 2 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(20 * (char)dir) + x,  y + 111.0, dir, 1);
            }
            else
            {
              if ( get_frame() == 4 )
              {
                add_card_energy(50);
                sub_486FD0(10.0, -10.0);
                play_sfx(5);
                spell_energy_spend(200, 60);
                tt[0] = field_7F0;
                tt[1] = 10.0;
                tt[2] = 0.0;
                tt[3] = 1.0;
                addbullet(this, NULL, 806, (double)(123 * (char)dir) + x, y + 105.0, dir, 1, tt, 4);
              }
LABEL_1001:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 8 )
              {
                add_card_energy(50);
                sub_486FD0(10.0, -10.0);
                play_sfx(5);
                spell_energy_spend(200, 60);
                tt[0] = field_7F0;
                tt[1] = 17.5;
                tt[2] = 0.0;
                tt[3] = 2.0;
                addbullet(this, NULL, 806, (double)(123 * (char)dir) + x, y + 105.0, dir, 1, tt, 4);
              }
            }
            return;
          case 412:
            if ( get_subseq() == 3 )
              sub10func();
            if ( get_subseq() == 1 || get_subseq() == 2 )
            {
              v_inerc =  v_inerc - v_force;
              if ( get_subseq() == 1 && get_frame() < 9 && v_inerc < 2.0 )
                v_inerc = 2.0;
              if ( char_on_ground_down() && get_subseq() < 3 )
              {
                set_subseq(3);
                goto LABEL_153;
              }
            }
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1025;
            if ( get_subseq() == 1 )
            {
              h_inerc = 10.0;
              v_inerc = 15.0;
              v_force = 0.75;
LABEL_1025:
              if ( get_subseq() == 1 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc < 2.0 )
                  h_inerc = 2.0;
                if ( !get_frame_time() && get_frame() == 2 )
                {
                  t[0] = -30.0;
                  t[1] = 16.0;
                  t[2] = 3.0;
                  addbullet(this, NULL, 805, x, y + 60.0, dir, 1, t, 3);
                  play_sfx(4);
LABEL_983:
                  spell_energy_spend(200, 60);
LABEL_984:
                  add_card_energy(50);
                }
              }
            }
            return;
          case 414:
            if ( get_subseq() == 2 )
              sub10func();
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
            {
              set_subseq(2);
              air_dash_cnt = 0;
              goto LABEL_153;
            }
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
              goto LABEL_1060;
            if ( get_frame_time() )
              goto LABEL_1057;
            if ( get_frame() == 2 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(10 * (char)dir) + x, y + 94.0, dir, 1);
            }
            else
            {
              if ( get_frame() == 3 )
              {
                t[0] = 0.0;
                t[1] = 16.0;
                t[2] = 3.0;
                addbullet(this, NULL, 805, x, y + 60.0, dir, 1, t, 3);
                play_sfx(4);
                spell_energy_spend(200, 60);
                add_card_energy(50);
              }
LABEL_1057:
              if ( !get_frame_time() && get_frame() == 7 )
                v_force = 0.5;
LABEL_1060:
              if ( get_subseq() == 1 && !get_frame_time() )
              {
                if ( get_frame() == 1 )
                {
                  t[0] = 0.0;
                  t[1] = 20.0;
                  t[2] = 9.0;
                  addbullet(this, NULL, 805, x, y, dir, 1, t, 3);
                  play_sfx(4);
                  spell_energy_spend(200, 60);
                  add_card_energy(50);
                }
                if ( !get_frame_time() && get_frame() == 5 )
                  v_force = 0.5;
              }
            }
            return;
          case 415:
            if ( get_subseq() == 2 )
              sub10func();
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
              goto LABEL_1071;
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
              goto LABEL_1096;
            if ( get_frame_time() )
              goto LABEL_1093;
            if ( get_frame() == 2 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(20 * (char)dir) + x, y + 111.0, dir, 1);
            }
            else
            {
              if ( get_frame() == 4 )
              {
                add_card_energy(50);
                sub_486FD0(10.0, -10.0);
                play_sfx(5);
                spell_energy_spend(200, 60);
                tt[0] = field_7F0;
                tt[1] = 10.0;
                tt[2] = 0.0;
                tt[3] = 1.0;
                addbullet(this, NULL, 806, (double)(123 * (char)dir) + x, y + 105.0, dir, 1,tt, 4);
              }
LABEL_1093:
              if ( !get_frame_time() && get_frame() == 13 )
                v_force = 0.5;
LABEL_1096:
              if ( get_subseq() == 1 && !get_frame_time() )
              {
                if ( get_frame() == 8 )
                {
                  add_card_energy(50);
                  sub_486FD0(10.0, -10.0);
                  play_sfx(5);
                  spell_energy_spend(200, 60);
                  tt[0] = field_7F0;
                  tt[1] = 17.5;
                  tt[2] = 0.0;
                  tt[3] = 2.0;
                  addbullet(this, NULL, 806, (double)(123 * (char)dir) + x, y + 105.0, dir, 1, tt, 4);
                }
                if ( !get_frame_time() && get_frame() == 18 )
                  v_force = 0.5;
              }
            }
            return;
          case 416:
            if ( get_subseq() == 2 )
              sub10func();
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() && get_subseq() < 2 )
            {
LABEL_1071:
              set_subseq(2);
              air_dash_cnt = 0;
              goto LABEL_153;
            }
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
              goto LABEL_1131;
            if ( get_frame_time() )
              goto LABEL_1128;
            if ( get_frame() == 4 && not_charge_attack )
            {
              next_subseq();
              scene_add_effect(this, 62, (double)(36 * (char)dir) + x, y + 95.0, dir, 1);
            }
            else
            {
              if ( get_frame() == 6 )
              {
                t[0] = 45.0;
                t[1] = 16.0;
                t[2] = 3.0;
                addbullet(this, NULL, 805, x, y + 60.0, dir, 1, t, 3);
                play_sfx(4);
                spell_energy_spend(200, 60);
                add_card_energy(50);
              }
LABEL_1128:
              if ( !get_frame_time() && get_frame() == 9 )
                v_force = 0.5;
LABEL_1131:
              if ( get_subseq() == 1 && !get_frame_time() )
              {
                if ( get_frame() == 3 )
                {
                  t[0] = 45.0;
                  t[1] = 16.0;
                  t[2] = 3.0;
                  addbullet(this, NULL, 805, x, y + 60.0, dir, 1, t, 3);
                  play_sfx(4);
                  spell_energy_spend(200, 60);
                  add_card_energy(50);
                }
                if ( !get_frame_time() && get_frame() == 6 )
                  v_force = 0.5;
              }
            }
            return;
          case 418:
            sub10func();
            if ( get_frame() >= 4 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 4 )
            {
              scene_play_sfx(29);
              field_49A = 0;
            }
            return;
          case 500:
            if ( (!get_subseq() || get_subseq() == 3) && get_frame() < 7 || get_subseq() == 2 )
            {
              sub10func();
              
            }
            field_18C = 0;
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 2.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_subseq(2);
                goto LABEL_1154;
              }
              if ( get_elaps_frames() >= 60 )
              {
                v_force = 0.5;
                set_seq(9);
                return;
              }
              
            }
            if ( (!get_subseq() || get_subseq() == 3) && !get_frame_time() )
            {
              if ( get_frame() == 2 )
                h_inerc = 0.0;
              if ( !get_frame_time() && get_frame() == 3 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_subseq(1);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              set_seq(0);
            if ( get_subseq() && get_subseq() != 3 )
              goto LABEL_1190;
            if ( !get_frame_time() )
            {
              if ( get_frame() == 2 )
                h_inerc = 48.0;
              if ( !get_frame_time() && get_frame() == 3 )
                h_inerc = 48.0;
            }
            if ( get_frame_time() )
              goto LABEL_1190;
            if ( get_frame() == 6 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 810, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_frame_time() || get_frame() != 7 )
              goto LABEL_1190;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 9.0;
            addbullet(this, NULL, 810, x, y, dir, 1, t, 3);
            v348 = 10.0;
            goto LABEL_1189;
          case 501:
            if ( (!get_subseq() || get_subseq() == 3) && get_frame() < 7 || get_subseq() == 2 )
            {
              sub10func();
              
            }
            field_18C = 0;
            if ( get_subseq() == 2 )
            {
              h_inerc =  h_inerc - 2.0;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            else
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_subseq(2);
LABEL_1154:
                v_inerc = 0.0;
                v_force = 0.0;
                y = getlvl_height();
                return;
              }
              if ( get_elaps_frames() >= 60 )
              {
                v_force = 0.5;
LABEL_1204:
                set_seq(9);
                return;
              }
              
            }
            if ( (!get_subseq() || get_subseq() == 3) && !get_frame_time() )
            {
              if ( get_frame() == 2 )
                h_inerc = 0.0;
              if ( !get_frame_time() && get_frame() == 3 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_subseq(1);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              set_seq(0);
            if ( !get_subseq() || get_subseq() == 3 )
            {
              if ( !get_frame_time() )
              {
                if ( get_frame() == 2 )
                  h_inerc = 48.0;
                if ( !get_frame_time() && get_frame() == 3 )
                  h_inerc = 48.0;
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 6 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 0.0;
                  addbullet(this, NULL, 810, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
                }
                if ( !get_frame_time() && get_frame() == 7 )
                {
                  t[0] = 0.0;
                  t[1] = 0.0;
                  t[2] = 9.0;
                  addbullet(this, NULL, 810, x, y, dir, 1, t, 3);
                  v348 = 20.0;
LABEL_1189:
                  h_inerc = v348;
                  v_inerc = 4.0;
                  v_force = 0.40000001;
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  play_sfx(6);
                }
              }
            }
LABEL_1190:
            if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 6 )
            {
              field_194 = 1;
              field_190 = 0;
            }
            return;
          case 505:
            sub10func();
            field_18C = 4;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1245;
            if ( get_subseq() == 1 )
            {
              add_card_energy(50);
              scene_add_effect(this, 127, x + 0.0, y, dir, -1);
              spell_energy_spend(200, 120);
              field_7D0 = 4;
              if ( skills_1[4] >= 3 )
                field_7D0 = 3;
LABEL_1245:
              if ( get_subseq() == 1 )
              {
                if ( !(get_elaps_frames() % field_7D0) )
                {
                  play_sfx(7);
                  /*
                  t[0] = sin_deg(field_7DC * 25.0) * 45.0;
                  t[1] = 20.0;
                  t[2] = (double)(field_7DC % 7);
                  addbullet(this, NULL, 811, (cos_deg(-t[0]) * 60.0 + 40.0) * (double)dir + x, sin_deg(-t[0]) * 60.0 + y + 115.0, dir, 1, t, 3);
                  t[0] = sin_deg(field_7DC * 25.0) * -45.0;
                  addbullet(this, NULL, 811, (cos_deg(-t[0]) * 60.0 + 40.0) * (double)dir + x, sin_deg(-t[0]) * 60.0 + y + 115.0, dir, 1, t, 3);
                  */
                  field_7DC = field_7DC + 1.0;
                }
                if ( get_elaps_frames() >= 21 )
                {
                  next_subseq();
                  field_194 = 1;
                  field_190 = 0;
                }
              }
            }
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 14.0;
              addbullet(this, NULL, 811, (double)(192 * (char)dir) + x, y + 115.0, dir, 1, t, 3);
              //shake_camera(5.0);
              play_sfx(8);
            }
            return;
          case 506:
            sub10func();
            field_18C = 4;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1262;
            if ( get_subseq() == 1 )
            {
              add_card_energy(50);
              scene_add_effect(this, 127, x + 0.0, y, dir, -1);
              spell_energy_spend(200, 120);
              field_7D0 = 4;
              if ( skills_1[4] >= 3 )
                field_7D0 = 3;
LABEL_1262:
              if ( get_subseq() == 1 )
              {
                if ( !(get_elaps_frames() % field_7D0) )
                {
                  play_sfx(7);
                  /*
                  t[0] = sin_deg(field_7DC * 25.0) * 45.0;
                  t[1] = 30.0;
                  t[2] = (double)(field_7DC % 7);
                  addbullet(this, NULL, 811, (cos_deg(-t[0]) * 60.0 + 40.0) * (double)dir + x, sin_deg(-t[0]) * 60.0 + y + 115.0, dir, 1, t, 3);
                  t[0] = sin_deg(field_7DC * 25.0) * -45.0;
                  addbullet(this, NULL, 811, (cos_deg(-t[0]) * 60.0 + 40.0) * (double)dir + x, sin_deg(-t[0]) * 60.0 + y + 115.0, dir, 1, t, 3);
                  */
                  field_7DC = field_7DC + 1.0;
                }
                if ( get_elaps_frames() >= 21 )
                {
                  next_subseq();
                  field_194 = 1;
                  field_190 = 0;
                }
              }
            }
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 0.75;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
              if ( !get_frame_time() )
              {
                if ( get_frame() == 1 )
                  h_inerc = 15.0;
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 2 )
                  {
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 14.0;
                    addbullet(this, NULL, 811, (double)(192 * (char)dir) + x, y + 115.0, dir, 1, t, 3);
                    play_sfx(8);
                    //shake_camera(5.0);
                  }
                  if ( !get_frame_time() && get_frame() == 3 )
                    h_inerc = 0.0;
                }
              }
            }
            return;
          case 510:
            field_18C = 8;
            if ( get_subseq() == 2 )
            {
              sub10func();
            }
            else if ( get_subseq() == 1 || !get_subseq() && get_frame() >= 6 )
            {
              h_inerc = h_inerc - 0.75;
              if ( h_inerc < 1.0 )
                h_inerc = 1.0;
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1305;
            }
            if ( process() )
              set_seq(0);
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() == 5 )
            {
              t[0] = 0.0;
              t[0] = 0.0;
              t[0] = 1.0;
              addbullet(this, NULL, 812, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_frame_time() )
              return;
            if ( get_frame() == 6 )
            {
              play_sfx(9);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              h_inerc = 20.0;
              v_inerc = 10.0;
              v_force = 0.75;
            }
            if ( get_frame_time() )
              return;
            if ( get_frame() != 10 )
              goto LABEL_1295;
            play_sfx(10);
            /*
            *(float *)&v1496 = 0.0;
            v404 = &v1496;
            v1497 = 0.0;
            v1498 = 0.0;
            goto LABEL_1293;
            */
            return; //TODO: change
          case 511:
            field_18C = 8;
            if ( get_subseq() == 2 )
            {
              sub10func();
            }
            else if ( get_subseq() == 1 || !get_subseq() && get_frame() >= 6 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 1.0 )
                h_inerc = 1.0;
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1305;
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 5 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                addbullet(this, NULL, 812, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 6 )
                {
                  play_sfx(9);
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  h_inerc = 10.0;
                  v_inerc = 25.0;
                  v_force = 1.25;
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 10 )
                  {
                    play_sfx(10);
                    /*
                    v1484 = 0.0;
                    v404 = (int *)&v1484;
                    v1485 = 0.0;
                    v1486 = 0.0;
LABEL_1293:
                    addbullet(this, NULL, 812, x, y, dir, 1, (int)v404, 3);
                    */
                    LABEL_1293://TODO: change
                    if ( skills_1[8] >= 3 )
                      field_194 = 1;
                  }
LABEL_1295:
                  if ( !get_frame_time() )
                  {
                    v405 = get_frame() == 11;
                    goto LABEL_1297;
                  }
                }
              }
            }
            return;
          case 512:
            field_18C = 8;
            if ( get_subseq() == 2 )
            {
              sub10func();
            }
            else
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 1.0 )
                h_inerc = 1.0;
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1305;
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              set_seq(9);
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() == 1 )
            {
              play_sfx(9);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              h_inerc = 15.0;
              v_inerc = 10.0;
              v_force = 0.5;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 1.0;
              addbullet(this, NULL, 812, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            }
            if ( get_frame_time() )
              return;
            if ( get_frame() != 5 )
              goto LABEL_1347;
            play_sfx(10);
            /*
            *(float *)&v1502 = 0.0;
            v420 = &v1502;
            v1503 = 0.0;
            v1504 = 0.0;
            goto LABEL_1345;
            */
            return; //TODO: change
          case 513:
            field_18C = 8;
            if ( get_subseq() == 2 )
            {
              sub10func();
            }
            else
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 1.0 )
                h_inerc = 1.0;
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1305:
                reset_forces();
                y = getlvl_height();
                set_subseq(2);
                return;
              }
            }
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              set_seq(9);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                play_sfx(9);
                spell_energy_spend(200, 120);
                add_card_energy(50);
                h_inerc = 10.0;
                v_inerc = 25.0;
                v_force = 1.25;
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 1.0;
                addbullet(this, NULL, 812, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              }
              if ( !get_frame_time() )
              {
                if ( get_frame() == 5 )
                {
                  play_sfx(10);
                  /*
                  v1490 = 0.0;
                  v420 = (int *)&v1490;
                  v1491 = 0.0;
                  v1492 = 0.0;
LABEL_1345:
                  addbullet(this, NULL, 812, x, y, dir, 1, (int)v420, 3);
                  */
                  LABEL_1345://TODO: change
                  if ( skills_1[8] >= 3 )
                    field_194 = 1;
                }
LABEL_1347:
                if ( !get_frame_time() )
                {
                  v405 = get_frame() == 6;
LABEL_1297:
                  if ( v405 )
                    field_194 = 1;
                }
              }
            }
            return;
          case 520:
            sub10func();
            field_18C = 1;
            if ( process() )
              set_seq(0);
            if ( get_frame_time() || get_frame() != 5 )
              return;
            /*
            *(float *)&v1184 = -85.0;
            v1185 = 0.0;
            if ( skills_1[1] >= 1 )
            {
              v1186 = 0.0;
              if ( skills_1[1] >= 3 )
                v1186 = 5.0;
              v427 = dir;
              v428 = get_pframe();
              v429 = y - (double)v428->extra1[5];
              v430 = v429;
              v431 = (double)(v428->extra1[4] * (char)v427) + x;
              addbullet(this, NULL, 815, v431, v430, v427, 1, (int)&v1184, 3);
            }
            v1186 = 1.0;
            v432 = dir;
            v433 = get_pframe();
            v434 = y - (double)v433->extra1[5];
            v435 = v434;
            v436 = (double)(v433->extra1[4] * (char)v432) + x;
            addbullet(this, NULL, 815, v436, v435, v432, 1, (int)&v1184, 3);
            v1186 = 2.0;
            v437 = dir;
            v438 = get_pframe();
            v439 = y - (double)v438->extra1[5];
            v440 = v439;
            v441 = (double)(v438->extra1[4] * (char)v437) + x;
            addbullet(this, NULL, 815, v441, v440, v437, 1, (int)&v1184, 3);
            v1186 = 3.0;
            v442 = dir;
            v443 = get_pframe();
            v444 = y - (double)v443->extra1[5];
            v445 = v444;
            v446 = (double)(v443->extra1[4] * (char)v442) + x;
            addbullet(this, NULL, 815, v446, v445, v442, 1, (int)&v1184, 3);
            scene_add_effect(this, 127, x, y, dir, -1);
            v1151 = 0.0;
            do
            {
              *(float *)&v1184 = get_next_ranged(25) + v1151 * 45.0;
              v1185 = get_next_ranged(40) * 0.1000000014901161 + 11.0;
              v1186 = 2.0;
              v447 = -*(float *)&v1184;
              v448 = sin_deg(v447) >= 0.0;
              addbullet(this, NULL, 848, x, y, dir, (1 - 2 * v448), (int)&v1184, 3);
              v1151 = v1151 + 1.0;
            }
            while ( v1151 < 8.0 );
            */
            play_sfx(11);
            spell_energy_spend(200, 120);
            goto LABEL_984;
          case 521:
            sub10func();
            field_18C = 1;
            if ( process() )
              set_seq(0);
            if ( get_frame_time() )
              return;
            if ( get_frame() == 4 )
              h_inerc = 30.0;
            if ( get_frame_time() || get_frame() != 5 )
              return;
            h_inerc = 0.0;
            /*
            *(float *)&v1187 = -85.0;
            v1188 = 0.0;
            if ( skills_1[1] >= 1 )
            {
              v1189 = 0.0;
              if ( skills_1[1] >= 3 )
                v1189 = 5.0;
              v449 = dir;
              v450 = get_pframe();
              v451 = y - (double)v450->extra1[5];
              v452 = v451;
              v453 = (double)(v450->extra1[4] * (char)v449) + x;
              addbullet(this, NULL, 815, v453, v452, v449, 1, (int)&v1187, 3);
            }
            v1189 = 1.0;
            v454 = dir;
            v455 = get_pframe();
            v456 = y - (double)v455->extra1[5];
            v457 = v456;
            v458 = (double)(v455->extra1[4] * (char)v454) + x;
            addbullet(this, NULL, 815, v458, v457, v454, 1, (int)&v1187, 3);
            v1189 = 2.0;
            v459 = dir;
            v460 = get_pframe();
            v461 = y - (double)v460->extra1[5];
            v462 = v461;
            v463 = (double)(v460->extra1[4] * (char)v459) + x;
            addbullet(this, NULL, 815, v463, v462, v459, 1, (int)&v1187, 3);
            v1189 = 3.0;
            v464 = dir;
            v465 = get_pframe();
            v466 = y - (double)v465->extra1[5];
            v467 = v466;
            v468 = (double)(v465->extra1[4] * (char)v464) + x;
            addbullet(this, NULL, 815, v468, v467, v464, 1, (int)&v1187, 3);
            scene_add_effect(this, 127, x, y, dir, -1);
            v1152 = 0.0;
            do
            {
              *(float *)&v1187 = get_next_ranged(25) + v1152 * 45.0;
              v1188 = get_next_ranged(40) * 0.1000000014901161 + 11.0;
              v1189 = 2.0;
              v469 = -*(float *)&v1187;
              v470 = sin_deg(v469) >= 0.0;
              addbullet(this, NULL, 848, x, y, dir, (1 - 2 * v470), (int)&v1187, 3);
              v1152 = v1152 + 1.0;
            }
            while ( v1152 < 8.0 );
            */
            play_sfx(11);
            spell_energy_spend(200, 120);
            goto LABEL_984;
          case 525:
            sub10func();
            field_18C = 5;
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 1 )
              play_sfx(12);
            if ( get_frame() == 2 )
            {
              v630 = 20;
              if ( skills_1[5] >= 2 )
                v630 = 17;
              if ( skills_1[5] >= 3 )
                v630 = 15;
              if ( skills_1[5] >= 4 )
                v630 = 10;
              if ( get_frame_time() >= v630 )
                next_frame();
            }
            if ( get_frame_time() || get_frame() != 3 )
              return;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 816, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            t[2] = 1.0;
            addbullet(this, NULL, 816, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            t[2] = 2.0;
            addbullet(this, NULL, 816, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
            t[2] = 3.0;
            /*
            v488 = 10;
            do
            {
              *(float *)&v1178 = /*get_next_ranged(360)*//*360.0;
              v1179 = get_next_ranged(20) + 10.0;
              v489 = dir;
              v490 = get_pframe();
              v491 = y - (double)v490->extra1[5];
              v492 = v491;
              v493 = (double)(v490->extra1[4] * (char)v489) + x;
              addbullet(this, NULL, 816, v493, v492, v489, 1, (int)&v1178, 3);
              --v488;
            }
            while ( v488 );
            v1153 = 0.0;
            do
            {
              *(float *)&v1178 = get_next_ranged(25) + v1153 * 36.0;
              v1179 = get_next_ranged(40) * 0.1000000014901161 + 16.0;
              v1180 = 2.0;
              v494 = -*(float *)&v1178;
              v495 = sin_deg(v494) >= 0.0;
              addbullet(this, NULL, 848, x, y, dir, (1 - 2 * v495), (int)&v1178, 3);
              v1153 = v1153 + 1.0;
            }
            while ( v1153 < 10.0 );
            */
            goto LABEL_1413;
          case 526:
            sub10func();
            field_18C = 5;
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 1 )
              play_sfx(12);
            if ( get_frame() == 2 )
            {
              v630 = 50;
              if ( skills_1[5] >= 2 )
                v630 = 45;
              if ( skills_1[5] >= 3 )
                v630 = 40;
              if ( skills_1[5] >= 4 )
                v630 = 30;
              if ( get_frame_time() >= v630 )
                next_frame();
            }
            if ( !get_frame_time() && get_frame() == 3 )
            {
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              addbullet(this, NULL, 816, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              t[2] = 1.0;
              addbullet(this, NULL, 816, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              t[2] = 2.0;
              addbullet(this, NULL, 816, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1, t, 3);
              t[2] = 3.0;
              /*
              v513 = 10;
              do
              {
                *(float *)&v1181 = /*get_next_ranged(360)*//*360.0;
                v1182 = get_next_ranged(20) + 10.0;
                v514 = dir;
                v515 = get_pframe();
                v516 = y - (double)v515->extra1[5];
                v517 = v516;
                v518 = (double)(v515->extra1[4] * (char)v514) + x;
                addbullet(this, NULL, 816, v518, v517, v514, 1, (int)&v1181, 3);
                --v513;
              }
              while ( v513 );
              v1154 = 0.0;
              do
              {
                *(float *)&v1181 = get_next_ranged(25) + v1154 * 36.0;
                v1182 = get_next_ranged(40) * 0.1000000014901161 + 16.0;
                v1183 = 2.0;
                v519 = -*(float *)&v1181;
                v520 = sin_deg(v519) >= 0.0;
                addbullet(this, NULL, 848, x, y, dir, (1 - 2 * v520), (int)&v1181, 3);
                v1154 = v1154 + 1.0;
              }
              while ( v1154 < 10.0 );
LABEL_1413:
*/            LABEL_1413://TODO: change
              scene_add_effect(this, 127, x, y, dir, -1);
              play_sfx(13);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              //shake_camera(8.0);
            }
            return;
          case 530:
            sub10func();
            field_18C = 9;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_2481;
            if ( get_frame_time() )
              goto LABEL_2481;
            if ( get_frame() )
              goto LABEL_2481;
            if ( get_subseq() != 1 )
              goto LABEL_2481;
            play_sfx(14);
            scene_add_effect(this, 127, x, y, dir, -1);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            field_190 = 1;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 817, x, y, dir, -1, t, 3);
            t[2] = 2.0;
            addbullet(this, NULL, 817, x, y, dir, 1, t, 3);
            if ( field_1A2 <= 1 ) //reversed condition
            {
LABEL_2481:
              field_1A2 = 1;
              field_890 = 60 * ((char)skills_1[9] + 4);
              field_7FC = 0.0;
            }
            if ( get_subseq() != 1 || get_elaps_frames() % 10 )
              return;
            /*
            *(float *)&v1454 = 0.0;
            v522 = &v1454;
            v1455 = 0.0;
            v1456 = 1.0;
            goto LABEL_1447;
            */
            return;//TODO: change
          case 531:
            sub10func();
            field_18C = 9;
            if ( process() )
              set_seq(0);
            if ( get_elaps_frames() )
              goto LABEL_2482;
            if ( get_frame_time() )
              goto LABEL_2482;
            if ( get_frame() )
              goto LABEL_2482;
            if ( get_subseq() != 1 )
              goto LABEL_2482;
            play_sfx(14);
            scene_add_effect(this, 127, x, y, dir, -1);
            spell_energy_spend(200, 120);
            add_card_energy(50);
            field_190 = 1;
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 0.0;
            addbullet(this, NULL, 817, x, y, dir, -1, t, 3);
            t[2] = 2.0;
            addbullet(this, NULL, 817, x, y, dir, 1, t, 3);
            if ( field_1A2 <= 1 ) //reversed condition
            {
LABEL_2482:
              field_1A2 = 1;
              field_890 = 90 * ((char)skills_1[9] + 4);
              field_7FC = 0.0;
            }
            /*
            if ( get_subseq() == 1 && !(get_elaps_frames() % 10) )
            {
              v1379 = 0.0;
              v522 = (int *)&v1379;
              v1380 = 0.0;
              v1381 = 1.0;
LABEL_1447:
              addbullet(this, NULL, 817, x, y, dir, 1, (int)v522, 3);
            }
            */
            LABEL_1447://TODO: change
            return;
          case 540:
            sub10func();
            field_18C = 2;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_108;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1479;
            if ( get_frame() == 3 && not_charge_attack )
            {
              /*
              a2 = dir;
              v524 = y + 73.0;
              y = v524;
              v525 = x - (double)(9 * (char)a2);
              v214 = v525;
              goto LABEL_662;
              */
              return; //TODO: change
            }
            if ( get_frame() == 4 )
            {
              play_sfx(15);
              //shake_camera(5.0);
              scene_add_effect(this, 58, (double)(72 * (char)dir) + x, y, dir, -1);
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              if ( skills_1[2] >= 1 )
                t[2] = 2.0;
              if ( skills_1[2] >= 4 )
                t[2] = 4.0;
              addbullet(this, NULL, 820, (double)(72 * (char)dir) + x, y, dir, -1, t, 3);
            }
LABEL_1479:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
            {
              play_sfx(15);
              //shake_camera(7.0);
              scene_add_effect(this, 58, (double)(72 * (char)dir) + x, y, dir, -1);
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 1.0;
              if ( skills_1[2] >= 1 )
                t[2] = 3.0;
              if ( skills_1[2] >= 4 )
                t[2] = 5.0;
              addbullet(this, NULL, 820, (double)(72 * (char)dir) + x, y, dir, -1, t, 3);
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
              goto LABEL_108;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1506;
            if ( get_frame() == 3 && not_charge_attack )
            {
              /*
              a2 = dir;
              v534 = y + 73.0;
              y = v534;
              v535 = x - (double)(9 * (char)a2);
              v214 = v535;
              goto LABEL_662;
              */
              return; //TODO: change
            }
            if ( get_frame() == 4 )
            {
              play_sfx(15);
              //shake_camera(5.0);
              scene_add_effect(this, 58, (double)(72 * (char)dir) + x, y, dir, -1);
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 0.0;
              if ( skills_1[2] >= 1 )
                t[2] = 2.0;
              if ( skills_1[2] >= 4 )
                t[2] = 4.0;
              addbullet(this, NULL, 820, (double)(72 * (char)dir) + x, y, dir, -1, t, 3);
            }
LABEL_1506:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
            {
              play_sfx(15);
              //shake_camera(7.0);
              scene_add_effect(this, 58, (double)(72 * (char)dir) + x, y, dir, -1);
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 1.0;
              if ( skills_1[2] >= 1 )
                t[2] = 3.0;
              if ( skills_1[2] >= 4 )
                t[2] = 5.0;
              addbullet(this, NULL, 820, (double)(72 * (char)dir) + x, y, dir, -1, t, 3);
            }
            return;
          case 545:
            sub10func();
            field_18C = 6;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_108;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1533;
            if ( get_frame() == 3 && not_charge_attack )
            {
              /*
              a2 = dir;
              v544 = y + 73.0;
              y = v544;
              v545 = x - (double)(9 * (char)a2);
              v214 = v545;
              goto LABEL_662;
              */
              return; //TODO: change
            }
            if ( get_frame() == 4 )
            {
              play_sfx(16);
              //shake_camera(5.0);
              scene_add_effect(this, 58, (double)(72 * (char)dir) + x, y, dir, -1);
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 10.0;
              t[2] = 0.0;
              if ( skills_1[6] >= 3 )
                t[2] = 2.0;
              if ( skills_1[6] >= 4 )
                t[2] = 3.0;
              addbullet(this, NULL, 821, (double)(72 * (char)dir) + x, y, dir, 1, t, 3);
            }
LABEL_1533:
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
            {
              play_sfx(16);
              //shake_camera(7.0);
              scene_add_effect(this, 58, (double)(72 * (char)dir) + x, y, dir, -1);
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              t[0] = 0.0;
              t[1] = 10.0;
              t[2] = 0.0;
              if ( skills_1[6] >= 3 )
                t[2] = 2.0;
              if ( skills_1[6] >= 4 )
                t[2] = 3.0;
              addbullet(this, NULL, 821, (double)(72 * (char)dir) + x, y, dir, 1, t, 3);
              addbullet(this, NULL, 821, (double)(72 * dir) + x, y, -dir, 1, t, 3);
            }
            return;
          case 546:
            sub10func();
            field_18C = 6;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_108;
            if ( get_subseq() || get_frame_time() )
              goto LABEL_1560;
            if ( get_frame() != 3 || !not_charge_attack )
            {
              if ( get_frame() == 4 )
              {
                play_sfx(16);
                //shake_camera(5.0);
                scene_add_effect(this, 58, (double)(72 * (char)dir) + x, y, dir, -1);
                add_card_energy(50);
                spell_energy_spend(200, 120);
                field_190 = 1;
                t[0] = 0.0;
                t[1] = 22.5;
                t[2] = 0.0;
                if ( skills_1[6] >= 3 )
                  t[2] = 2.0;
                if ( skills_1[6] >= 4 )
                  t[2] = 3.0;
                addbullet(this, NULL, 821, (double)(72 * (char)dir) + x, y, dir, 1, t, 3);
              }
LABEL_1560:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 2 )
              {
                play_sfx(16);
                //shake_camera(7.0);
                scene_add_effect(this, 58, (double)(72 * (char)dir) + x, y, dir, -1);
                add_card_energy(50);
                spell_energy_spend(200, 120);
                field_190 = 1;
                t[0] = 0.0;
                t[1] = 22.5;
                t[2] = 0.0;
                if ( skills_1[6] >= 3 )
                  t[2] = 2.0;
                if ( skills_1[6] >= 4 )
                  t[2] = 3.0;
                addbullet(this, NULL, 821, (double)(72 * (char)dir) + x, y, dir, 1, t, 3);
                addbullet(this, NULL, 821, (double)(72 * dir) + x, y, -dir, 1, t, 3);
              }
              return;
            }
            /*
            a2 = dir;
            v556 = y + 73.0;
            y = v556;
            v557 = x - (double)(9 * (char)a2);
            v214 = v557;
LABEL_662:
            x = v214;
            scene_add_effect(this, 62, x, y, a2, 1);
            goto LABEL_663;
            */
            LABEL_662: //TODO: change
            return; //TODO: change
          case 550:
            if ( get_subseq() && get_subseq() != 6 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
                set_subseq(6);
                return;
              }
            }
            else
            {
              sub10func();
            }
            if ( get_subseq() == 2 )
            {
              field_7DC = field_7DC - 1.25;
              if ( field_7DC <= 3.0 )
                field_7DC = 3.0;
              //WHATIS?
            //set_vec_speed((render_class *)&cEffectSprite, -25.0, field_7DC);
              if ( get_elaps_frames() >= 20 )
                goto LABEL_2031;
            }
            field_18C = 10;
            if ( process() )
              set_seq(0);
            if ( get_subseq() != 4 )
              goto LABEL_1587;
            if ( get_elaps_frames() )
              goto LABEL_1584;
            if ( get_frame_time() )
              goto LABEL_1587;
            if ( !get_frame() && skills_1[10] >= 4 )
              goto LABEL_663;
LABEL_1584:
            if ( !get_frame_time() && get_frame() == 2 && skills_1[10] >= 3 )
              goto LABEL_663;
LABEL_1587:
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                play_sfx(20);
                //WHATIS?
            //set_vec_speed((render_class *)&cEffectSprite, -25.0, field_7DC);
                add_card_energy(50);
                spell_energy_spend(200, 120);
                scene_add_effect(this, 127, x, y, dir, -1);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 822, x, y, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 822, x, y, dir, 1, t, 3);
              }
            }
            return;
          case 551:
            if ( get_subseq() && get_subseq() != 6 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
LABEL_1602:
                set_subseq(6);
                return;
              }
            }
            else
            {
              sub10func();
            }
            if ( get_subseq() == 2 )
            {
              field_7DC = field_7DC - 0.75;
              if ( field_7DC <= 3.0 )
                field_7DC = 3.0;
              //WHATIS?
            //set_vec_speed((render_class *)&cEffectSprite, -25.0, field_7DC);
              if ( get_elaps_frames() >= 20 )
              {
                v_force = 0.5;
                goto LABEL_1609;
              }
            }
            field_18C = 10;
            if ( process() )
              set_seq(0);
            if ( get_subseq() != 4 )
              goto LABEL_1620;
            if ( get_elaps_frames() )
              goto LABEL_1617;
            if ( !get_frame_time() )
            {
              if ( !get_frame() && skills_1[10] >= 4 )
                goto LABEL_1609;
LABEL_1617:
              if ( !get_frame_time() && get_frame() == 2 && skills_1[10] >= 3 )
                goto LABEL_1609;
            }
LABEL_1620:
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                play_sfx(20);
                //WHATIS?
            //set_vec_speed((render_class *)&cEffectSprite, -25.0, field_7DC);
                add_card_energy(50);
                spell_energy_spend(200, 120);
                scene_add_effect(this, 127, x, y, dir, -1);
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              {
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 822, x, y, dir, 1, t, 3);
                t[2] = 1.0;
                addbullet(this, NULL, 822, x, y, dir, 1, t, 3);
              }
            }
            break;
          default:
            goto LABEL_2471;
        }
      }
    }
    else if (get_seq()== 300 )
    {
LABEL_622:
      sub10func();
      if ( true/*!get_true(0)*/)
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
        if ( !get_frame_time() && get_frame() == 1 )
        {
          scene_play_sfx(27);
          field_49A = 0;
        }
      }
    }
    else
    {
      switch (get_seq())
      {
        case 0:
          sub10func();
          
          if ( 0.0 == h_inerc )
            field_49A = 0;
          if ( !field_49A )
            goto LABEL_78;
          goto LABEL_79;
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
            goto LABEL_95;
          return;
        case 2:
          sub10func();
          if ( field_49A )
          {
            
LABEL_79:
            if ( 0.0 < h_inerc )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
              {
                reset_forces();
                
                field_49A = 0;
              }
            }
            if ( 0.0 <= h_inerc || (h_inerc + 0.5, h_inerc = h_inerc, h_inerc <= 0.0) )
            {
LABEL_154:
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
LABEL_78:
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
            goto LABEL_108;
          return;
        case 4:
          sub10func();
          char_h_move(7.0);
          process();
          return;
        case 5:
          sub10func();
          char_h_move(-7.0);
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
              goto LABEL_151;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v41 = 0.0;
          goto LABEL_123;
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
              goto LABEL_151;
          }
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v41 = 6.0;
          goto LABEL_123;
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
              goto LABEL_151;
          }
          process();
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            v41 = -6.0;
LABEL_123:
            char_h_move(v41);
            v_inerc = 17.5;
            v_force = 0.85000002;
            field_49A = 0;
          }
          return;
        case 9:
          if ( 0.0 == v_force )
            v_force = 0.60000002;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_151;
          goto LABEL_154;
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
            goto LABEL_170;
          if ( controlling_type == 2 )
          {
LABEL_166:
            set_seq(700);
            goto LABEL_167;
          }
          set_seq(0);
          if ( dY() > 0 )
            set_seq(1);
LABEL_170:
          if ( get_subseq() == 3 && get_frame() == 1 && !get_frame_time() )
          {
            if ( enemy->x < (double)x )
              dir = -1;
            if ( enemy->x > (double)x )
              dir = 1;
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          v_inerc = 6.0;
          v52 = 14.5;
          goto LABEL_182;
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
            goto LABEL_193;
          if ( controlling_type == 2 )
          {
            set_seq(700);
LABEL_167:
            field_51C = 3;
            field_520 = 3;
          }
          else
          {
            set_seq(0);
            if ( dY() > 0 )
              set_seq(1);
LABEL_193:
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
              v52 = -14.5;
LABEL_182:
              h_inerc = v52;
              v_force = 0.5;
            }
          }
          return;
        case 199:
          sub10func();
          if ( !process() )
            goto LABEL_209;
          if ( controlling_type == 2 )
            goto LABEL_166;
          set_seq(0);
          if ( dY() > 0 )
            set_seq(1);
LABEL_209:
          if ( !get_subseq() && get_frame() == 7 && !get_frame_time() )
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
          if ( h_inerc > 13.5 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 13.5 )
              h_inerc = 13.5;
          }
          process();
          if ( get_subseq() != 1 )
            goto LABEL_230;
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          if ( dY() >= 0 )
          {
            if ( (dX(dir) > 0 || ++field_7D0 <= 5) && ++field_7D0 <= 45 )
            {
LABEL_230:
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
            if ( dX(dir) < 0 | dX(dir) == 0 )
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
              goto LABEL_246;
          }
          if ( process() )
            goto LABEL_249;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            char_h_move(-15.0);
            v_inerc = 5.0;
            v_force = 0.5;
            scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
            scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
            scene_play_sfx(31);
          }
          return;
        case 202:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_256;
          if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
          }
          process();
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              field_7D0 = 0;
              char_h_move(10.0);
              v_inerc = 4.0;
              v_force = 0.44999999;
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
                char_h_move(-10.0);
                v_inerc = 4.0;
                v_force = 0.44999999;
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
            goto LABEL_293;
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
          v100 = 0.0;
          goto LABEL_308;
        case 209:
        case 221:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_293;
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
          v106 = 10.0;
          goto LABEL_329;
        case 210:
        case 222:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_293;
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
          v106 = -10.0;
LABEL_329:
          char_h_move(v106);
          v102 = 18.0;
          goto LABEL_309;
        case 211:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_293;
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
          v100 = 3.0;
LABEL_308:
          char_h_move(v100);
          v102 = 22.5;
LABEL_309:
          v_inerc = v102;
          v103 = 0.80000001;
          goto LABEL_310;
        case 212:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_293;
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
            char_h_move(10.0);
            v_inerc = 17.5;
            v103 = 0.85000002;
LABEL_310:
            v_force = v103;
            field_49A = 0;
            scene_add_effect(this, 63, x, y, dir, 1);
          }
          return;
        case 214:
          if ( process() )
            goto LABEL_962;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            scene_play_sfx(31);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
            goto LABEL_962;
          if ( (dY() < 0) | dX(dir) == 0 )
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
          if ( get_subseq() <= 0 || get_subseq() >= 5 )
            goto LABEL_470;
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
          if ( (keyDown(INP_D) || field_7D6 <= 10) && spell_energy > 0 )
            goto LABEL_470;
          if ( keyDown(INP_D) )
            goto LABEL_452;
          /*
          v138 = __OFSUB__(field_7D6, 10);
          v136 = field_7D6 == 10;
          v137 = (signed __int16)(field_7D6 - 10) < 0;
          goto LABEL_451;
          */
          return; //TODO: change
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
            goto LABEL_1204;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            scene_play_sfx(31);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
            goto LABEL_1204;
          field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
          if ( get_subseq() == 5 || get_subseq() == 6 )
            v_inerc = v_inerc - v_force;
          if ( get_subseq() <= 0 || get_subseq() >= 5 )
            goto LABEL_470;
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
          if ( field_7DC > 14.5 )
            field_7DC = 14.5;
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
          if ( (keyDown(INP_D) || field_7D6 <= 20) && spell_energy > 0 )
            goto LABEL_470;
          if ( !keyDown(INP_D) )
          {
            /*
            v138 = __OFSUB__(field_7D6, 20);
            v136 = field_7D6 == 20;
            v137 = (signed __int16)(field_7D6 - 20) < 0;
LABEL_451:
            if ( !((v137 ^ v138) | v136) )
              goto LABEL_453;
          }
          */
            LABEL_451://TODO: change
LABEL_452:
          if ( spell_energy > 0 )
          {
LABEL_470:
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
LABEL_453:
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
                  goto LABEL_1602;
                dir = -dir;
                h_inerc = -h_inerc;
                set_subseq(5);
              }
            }
          }
          break;
        case 220:
          if ( !get_subseq() )
            sub10func();
          if ( char_on_ground_down() )
            goto LABEL_543;
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
            v_force = 0.80000001;
            field_49A = 0;
            scene_add_effect(this, 63, x, y, dir, 1);
          }
          return;
        case 223:
          sub10func();
          field_49A = 1;
          process();
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
            goto LABEL_564;
          if ( get_subseq() == 1 )
          {
            if ( !field_7D0 )
            {
              char_h_move(7.5);
              scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, dir, 1);
              scene_play_sfx(31);
            }
LABEL_564:
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
              }
              if ( dX(dir) <= 0 && ++field_7D0 > 15 || ++field_7D0 > 45 )
                set_seq(204);
            }
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
          if ( get_subseq() < 3 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_246;
          }
          if ( process() )
          {
            set_seq(0);
            h_inerc = 0.0;
            v_force = 0.0;
          }
          else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_7D0 )
          {
            field_7D0 = 1;
            char_h_move(-15.0);
            v_inerc = 5.0;
            v_force = 0.5;
            scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
            scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
            scene_play_sfx(31);
          }
          return;
        case 225:
          if ( get_subseq() >= 1 )
            v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_256;
          if ( get_subseq() >= 2 && !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
          }
          if ( process() )
            set_seq(9);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            char_h_move(-10.0);
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
LABEL_256:
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
                char_h_move(10.0);
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
          goto LABEL_2471;
      }
    }
  }
}
}

// note: taken from alice.cpp
void char_meiling::func20()
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

void char_meiling::set_seq_params()
{
  if ( get_seq() <= 214 )
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
    goto LABEL_70;
  }
  if ( get_seq() > 501 )
  {
    if ( get_seq() > 797 )
    {
      if ( get_seq() != 798 )
      {
LABEL_70:
        char_c::set_seq_params();
        return;
      }
      play_sfx(5);
      reset_forces();
      h_inerc = 15.0;
      field_7D0 = 0;
      v_inerc = 0.0;
      v_force = 0.5;
    }
    else if ( get_seq() == 797 )
    {
      field_7D0 = 0;
      play_sfx(5);
    }
    else
    {
      switch ( get_seq() )
      {
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
          field_7DC = 0.0;
          field_194 = 0;
          field_49A = 0;
          field_190 = 1;
          return;
        case 510:
        case 511:
        case 512:
        case 513:
          field_18C = 8;
          field_190 = 0;
          field_194 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 520:
        case 521:
          field_18C = 1;
          goto LABEL_45;
        case 525:
        case 526:
          field_18C = 5;
LABEL_45:
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_194 = 1;
          return;
        case 530:
        case 531:
          field_18C = 9;
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          return;
        case 540:
        case 541:
          field_18C = 2;
          goto LABEL_49;
        case 545:
        case 546:
          field_18C = 6;
LABEL_49:
          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 550:
        case 551:
          field_7DC = 25.0;
          field_18C = 10;
          field_190 = 0;
          reset_forces();
          field_194 = 1;
          return;
        case 560:
        case 561:
          field_7D0 = 0;
          field_18C = 3;
          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 565:
        case 566:
          field_18C = 7;
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          not_charge_attack = 1;
          return;
        case 567:
        case 568:
          field_18C = 7;
          field_190 = 0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
LABEL_30:
          goto LABEL_31;
        case 570:
        case 571:
          field_18C = 11;
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7DC = 0.0;
          field_7D2 = 0;
          not_charge_attack = 1;
          return;
        case 572:
        case 573:
          field_7DC = 0.0;
          field_18C = 11;
          field_190 = 0;
          field_7D0 = 0;
          field_7D2 = 0;
LABEL_31:
          v_force = 0.0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 599:
          field_190 = 1;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          return;
        case 600:
          field_190 = 0;
          field_7D0 = 0;
          field_194 = 1;
          reset_forces();
          return;
        case 601:
          field_7DC = 0.0;
          field_190 = 0;
          dash_angle = 0.0;
          field_7D0 = 0;
          field_7E4 = 0.0;
          field_194 = 1;
          reset_forces();
          return;
        case 602:
        case 603:
        case 608:
        case 611:
          field_190 = 0;
          reset_forces();
          return;
        case 604:
        case 605:
          field_190 = 0;
          field_194 = 1;
          reset_forces();
          return;
        case 606:
          field_7D0 = 0;
          goto LABEL_63;
        case 607:
          field_7D0 = 0;
          field_7D2 = 0;
LABEL_63:
          field_190 = 0;
          field_7DC = 0.0;
          field_194 = 1;
          reset_forces();
          break;
        case 609:
          field_194 = 1;
          field_190 = 0;
          reset_forces();
          field_7DC = 0.0;
          dash_angle = 0.0;
          break;
        case 710:
        case 711:
        case 720:
        case 721:
          field_190 = 0;
          reset_forces();
          field_194 = 0;
          break;
        case 712:
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_7D8 = 0;
          break;
        default:
          goto LABEL_70;
      }
    }
  }
  else
  {
    if ( get_seq() < 500 )
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
        case 323:
        case 324:
        case 330:
          goto LABEL_33;
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
          h_inerc = 15.0;
          field_49A = 0;
          field_190 = 0;
          v_inerc = 0.0;
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
          field_194 = 1;
          field_190 = 0;
          not_charge_attack = 1;
          return;
        case 309:
          field_194 = 1;
          field_190 = 0;
          not_charge_attack = 1;
          reset_forces();
          return;
        case 310:
          field_7D0 = 0;
          v_force = 0.5;
          field_190 = 0;
          field_194 = 1;
          return;
        case 320:
          field_49A = 0;
          field_190 = 0;
          field_194 = 1;
          return;
        case 400:
        case 401:
        case 410:
        case 411:
          field_190 = 1;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 402:
          field_190 = 1;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          not_charge_attack = 1;
          return;
        case 404:
          field_190 = 1;
          not_charge_attack = 1;
          return;
        case 405:
        case 406:
          field_190 = 1;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          v_force = 0.0;
          return;
        case 408:
          h_inerc = 15.0;
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
          field_190 = 1;
          reset_forces();
          return;
        case 414:
        case 416:
          field_190 = 1;
          v_force = 0.0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 415:
          field_190 = 1;
          goto LABEL_30;
        case 418:
          h_inerc = 15.0;
LABEL_33:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_194 = 1;
          return;
        default:
          goto LABEL_70;
      }
      goto LABEL_70;
    }
    field_18C = 0;
    reset_forces();
    /*
    v7 = __OFSUB__(skills_1[0], 3);
    v6 = (char)(skills_1[0] - 3) < 0;
    field_194 = 1;
    field_190 = 0;
    field_49A = 0;
    if ( !((unsigned __int8)v6 ^ v7) )
      vtbl->set_subseq_func3(&meta, 3);
      */
  }
}
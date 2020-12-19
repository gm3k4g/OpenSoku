#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "namazu.h"
#include <math.h>

#include <iostream>

char_namazu::char_namazu(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_NAMAZU;
	pgp->load_dat("namazu",pal);
	char_loadsfx("namazu");
	cards_load_cards(&chr_cards,"namazu");
	load_face("namazu");
	load_spells("namazu");
	stand_gfx->init(this,"namazu");
}

void char_namazu::init_vars()
{
	field_138 = -6.0;
	field_890 = 0;
	field_894 = 0;
	field_898 = 0;
	field_89C = 0;
	char_c::init_vars();
}

/*
c_bullet *char_namazu::new_bullet()
{
    c_bullet *tmp = new namazu_bullets();
    return tmp;
}*/

////sub_5586E0()
/* void //sub_5586E0() {
  v1 = this;
  v2 = *(_DWORD **)(this + 340);
  if ( v2 )
  {
    v3 = *(void **)(this + 340);
    *v2 = &IColor::`vftable';
    j__free(v3);
    *(_DWORD *)(v1 + 340) = 0;
  }
}
 */

// TODO: can't land normally from neutral jumps/airdashes
void char_namazu::func10()
{
  double v2 = 0.0;
  int v495 = 0;
  int32_t sq = get_seq();
  bool v267 = false;
  double v1459 = 0.0;
  double v285 = 0.0;
  double v1460 = 0.0;
  double v348 = 0.0;
  double v399 = 0.0;
  bool v462 = false;
  bool v537 = false;
  double v1157 = 0.0;
  
  double v996 = 0.0;
  double v1191 = 0.0;
  double v1195 = 0.0;
  double v1268 = 0.0;
  double v1272 = 0.0;
  double v1346 = 0.0;
  double v36 = 0.0;
  double v121 = 0.0;
  double v123 = 0.0;
  double v126 = 0.0;

  double move_val = 0.0;
  double move_vala = 0.0;
  double move_valb = 0.0;

   std::cout<<"GET_SEQ(): "<<sq<<endl;

  x_delta = 0;
  y_delta = 90;
  if ( char_is_shock() )
    //sub_5586E0();
  if ( controlling_type == 2 )
  {
    field_4AA = 2;
    field_534 = 0.25;
    field_55C = 2.0;
    field_538 = 0.0;
    field_86A = 0;
    if ( cards_added >= 1 )
    {
      switch ( cards_active[0]->id )
      {
        case 0:
        case 1:
        case 2:
        case 3:
          field_4AA = 2;
          field_534 = 0.1;
          field_55C = 5.0;
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] == 1 )
          {
            field_86A = 3;
            field_55C = 7.5;
          }
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_55C = 15.0;
          }
          break;
        case 4:
        case 5:
        case 6:
        case 7:
          field_4AA = 2;
          field_534 = 0.1;
          field_55C = 5.0;
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] == 1 )
          {
            field_86A = 3;
            field_55C = 10.0;
          }
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_55C = 20.0;
          }
          break;
        case 8:
        case 9:
        case 10:
        case 11:
          field_4AA = 2;
          field_534 = 0.1;
          v2 = 3.0;
          goto LABEL_15;
        case 12:
        case 13:
        case 14:
        case 15:
          field_4AA = 2;
          field_534 = 0.1;
          v2 = 2.5;
LABEL_15:
          field_55C = v2;
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] == 1 )
          {
            field_86A = 3;
            field_55C = 5.0;
          }
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_55C = 10.0;
          }
          break;
        case 16:
        case 17:
        case 18:
        case 19:
          field_4AA = 2;
          field_534 = 0.1;
          field_55C = 2.5;
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] == 1 )
          {
            field_86A = 3;
            field_534 = 0.2;
          }
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_534 = 0.30000001;
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
            //v5 = byte_7E98AC[v4];
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
LABEL_42:
          field_86A = 0;
          goto LABEL_43;
        }
        float t[3];
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
      goto LABEL_42;
  }
LABEL_43:
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
        if (process() )
          set_seq(0);
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
        {
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            v495 = 0;
            if ( skills_1[0]< 4 )
            {
              if ( skills_1[0] < 1 )
              {
                do
                {
                  float t[3];
                  t[0] = -20.0 - v495;
                  t[1] = 6.0;
                  t[2] = 12.0;
                  addbullet(this, NULL, 810, (double)(38 * (char)dir) + x, y + 177.0, dir, 1, t, 3);
                  v495 += 10;
                }
                while ( v495 < 40 );
              }
              else
              {
                do
                {
                  float t[3];
                  t[0] = -20.0 - v495;
                  t[1] = 6.0;
                  t[2] = 12.0;
                  addbullet(this, NULL, 810, (double)(38 * (char)dir) + x, y + 177.0, dir, 1, t, 3);
                  v495 += 10;
                }
                while ( v495 < 50 );
              }
            }
            else
            {
              do
              {
                float t[3];
                t[0] = -20.0 - v495;
                t[1] = 6.0;
                t[2] = 12.0;
                addbullet(this, NULL, 810, (double)(38 * (char)dir) + x, y + 177.0, dir, 1, t, 3);
                v495 += 10;
              }
              while ( v495 < 60 );
            }
LABEL_1355:
            add_card_energy(50);
            spell_energy_spend(200, 120);
            play_sfx(10);
          }
          return;
        }
LABEL_499:
        set_seq(0);
        return;
      }
      switch ( sq )
      {
        case 301:
          sub10func();
          if ( true /*get_true(0)*/ )
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
          if (process() )
            set_seq(0);
          if ( get_frame_time() )
            return;
          if ( get_frame() == 2 )
          {
            h_inerc = 4.0;
            field_49A = 0;
            float t[3];
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 3.0;
            addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
          }
          goto LABEL_684;
        case 302:
          sub10func();
          if ( true /*get_true(1)*/ )
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
          if (process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_92;
          if ( get_subseq() )
            goto LABEL_711;
          if ( get_frame_time() )
            goto LABEL_708;
          if ( get_frame() != 4 )
            goto LABEL_705;
          if ( not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(43 * (char)dir), y + 162.0, dir, 1);
          }
          else
          {
            float t[3];
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 4.0;
            addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            h_inerc = 10.0;
            field_49A = 0;
LABEL_705:
            if ( !get_frame_time() && get_frame() == 5 )
              play_sfx(0);
LABEL_708:
            if ( get_frame() >= 6 ) //reversed condition
            {
LABEL_711:
              h_inerc = h_inerc - 1.200000047683716;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( get_subseq() == 1 )
            {
              if ( !get_frame_time() )
              {
                if ( get_frame() == 1 )
                {
                  h_inerc = 10.0;
                  field_49A = 0;
                  float t[3];
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
              if ( get_frame() >= 3 )
              {
                h_inerc = h_inerc - 1.200000047683716;
                if ( h_inerc < 0.0 )
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
            if (process() )
              set_seq(2);
            if ( !get_frame_time() && get_frame() == 1 )
            {
              scene_play_sfx(28);
              float t[3];
              t[0] = 0.0;
              t[1] = 0.0;
              t[2] = 2.0;
              addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
            }
          }
          return;
        case 304:
          sub10func();
          if ( true /*get_true(1)*/ )
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
          if (process() )
            set_seq(2);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
LABEL_79:
            set_seq(2);
            return;
          }
          if ( get_subseq() )
            goto LABEL_756;
          if ( get_frame_time() )
            goto LABEL_753;
          if ( get_frame() == 3 )
          {
            float t[3];
            t[0] = 0.0;
            t[1] = 0.0;
            t[2] = 5.0;
            addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
          }
          if ( get_frame_time() || get_frame() != 3 )
            goto LABEL_753;
          if ( not_charge_attack )
          {
            next_subseq();
            scene_add_effect(this, 62, x - (double)(20 * (char)dir), y + 50.0, dir, 1);
          }
          else
          {
            h_inerc = 2.0;
            scene_play_sfx(29);
LABEL_753:
            if ( get_frame() >= 5 ) //reversed condition
LABEL_756:
            {
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
                  float t[3];
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
          if ( true /*!get_true(1)*/ )
          {
            h_inerc = h_inerc - 0.2000000029802322;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
            if (process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                float t[3];
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 10.0;
                addbullet(this, NULL, 848, x - (double)(40 * (char)dir),  y + 120.0, dir, 1, t, 3);
              }
              if ( !get_frame_time() && get_frame() == 2 )
                scene_play_sfx(28);
            }
          }
          return;
        case 306:
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_582;
          if (process() )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 2 )
              scene_play_sfx(28);
            if ( !get_frame_time() && get_frame() == 2 )
            {
              float t[3];
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
            goto LABEL_282;
          if (process() )
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
            float t[3];
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
          v267 = get_frame() == 8;
          goto LABEL_807;
        case 308:
          if ( !keyDown(INP_A) )
            not_charge_attack = 0;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_582:
            set_seq(10);
            goto LABEL_140;
          }
          if (process() )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 4 )
            {
              float t[3];
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
LABEL_282:
            set_seq(10);
            goto LABEL_140;
          }
          if (process() )
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
            goto LABEL_857;
          v_inerc = v_inerc - v_force;
          if ( !char_on_ground_down() )
            goto LABEL_857;
          v_inerc = 0.0;
          y = getlvl_height();
LABEL_856:
          set_seq(9);
          return;
        case 320:
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
            if ( get_frame() >= 5 )
            {
              h_inerc = h_inerc - 0.1500000059604645;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if (process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                h_inerc = 4.0;
                field_49A = 0;
                float t[3];
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 3.0;
                addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
              }
LABEL_684:
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
          if ( true /*!get_true(1)*/ )
          {
            if ( get_frame() > 3 )
            {
              h_inerc = h_inerc - 0.300000011920929;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if (process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 2 )
                h_inerc = 4.5;
              if ( !get_frame_time() && get_frame() == 3 )
              {
                play_sfx(0);
                field_49A = 0;
                float t[3];
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
          if ( true /*!get_true(1)*/ )
          {
            if ( get_frame() >= 4 )
            {
              h_inerc = h_inerc - 0.2000000029802322;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if (process() )
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
          goto LABEL_659;
        case 400:
          sub10func();
          if ( get_subseq() < 2 && !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 <= 0 )
            goto LABEL_912;
          field_7D0 = field_7D0 + 1;
          if ( get_subseq() )
          {
            if ( (field_7D0 % 10) == 1 && field_7D2 < 4 )
            {
              field_190 = 1;
              add_card_energy(10);
              v495 = 0;
              do
              {
                float t[3];
                t[0] = (double)(field_7D4 + 5 * v495 * (field_7D2 + 2)) - (double)(10 * (field_7D2 + 2));
                t[1] = 1.0;
                t[2] = (double)field_7D2;
                addbullet(this, NULL, 800, (double)(60 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
                ++v495;
              }
              while ( v495 < 5 );
              //v1473 = &v1743;
              //v1745 = (double)field_7D2 + 16.0;
              x = dir;
              v1459 = y + 160.0;
              v285 = (double)(60 * (char)x) + x;
              goto LABEL_911;
            }
          }
          else if ( (field_7D0 % 10) == 1 && field_7D2 < 3 )
          {
            field_190 = 1;
            add_card_energy(10);
            v495 = 0;
            do
            {
              float t[3];
              t[0] = (double)(field_7D4 + 5 * v495 * (field_7D2 + 3)) - (double)(10 * (field_7D2 + 3));
              t[1] = 1.0;
              t[2] = (double)field_7D2;
              addbullet(this, NULL, 800, (double)(60 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
              ++v495;
            }
            while ( v495 < 5 );
            //v1473 = &v1734;
            //v1736 = (double)field_7D2 + 16.0;
            x = dir;
            /*
            v1459 = y + 160.0;
            v285 = (double)(60 * (char)x) + x;
            */
LABEL_911:
            //addbullet(this, NULL, 800, v285, v1459, x, 1, 473, 3);
            play_sfx(1);
            ++field_7D2;
            goto LABEL_912;
          }
LABEL_912:
          if (process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_499;
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
          move_vala = (enemy->x - x) * (double)dir;
          goto LABEL_934;
        case 401:
          sub10func();
          if ( get_subseq() < 2 && !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( field_7D0 <= 0 )
            goto LABEL_954;
          field_7D0 = field_7D0 + 1;
          if ( get_subseq() )
          {
            if ( (field_7D0 % 10) == 1 && field_7D2 < 3 )
            {
              field_190 = 1;
              add_card_energy(10);
              /*
              v314 = 0;
              do
              {
                v1821 = (double)(field_7D4 + 5 * v314 * (field_7D2 + 2)) - (double)(10 * (field_7D2 + 2));
                v1822 = 1.0;
                v1823 = (double)field_7D2;
                v315 = dir;
                v316 = y + 160.0;
                v317 = v316;
                v318 = (double)(60 * (char)v315) + x;
                addbullet(this, NULL, 800, v318, v317, v315, 1, (int)&v1821, 3);
                ++v314;
              }
              while ( v314 < 5 );
              */
              goto LABEL_953;
            }
          }
          else if ( (field_7D0 % 10) == 1 && field_7D2 < 3 )
          {
            field_190 = 1;
            add_card_energy(10);
            /*
            v309 = 0;
            do
            {
              v1905 = (double)(field_7D4 + 5 * v309 * (field_7D2 + 3)) - (double)(10 * (field_7D2 + 3));
              v1906 = 1.0;
              v1907 = (double)field_7D2;
              v310 = dir;
              v311 = y + 160.0;
              v312 = v311;
              v313 = (double)(60 * (char)v310) + x;
              addbullet(this, NULL, 800, v313, v312, v310, 1, (int)&v1905, 3);
              ++v309;
            }
            while ( v309 < 5 );
            */
LABEL_953:
            play_sfx(1);
            ++field_7D2;
            goto LABEL_954;
          }
LABEL_954:
          if (process() )
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
                field_7D4 = -atan2_deg( enemy->y - y, (enemy->x - x) * (double)dir);
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
            move_vala = (enemy->x - x) * (double)dir;
LABEL_934:
            field_7D4 = -atan2_deg(enemy->y - y, move_vala);
            if ( field_7D4 < -20 )
              field_7D4 = -20;
            if ( field_7D4 > 20 )
              field_7D4 = 20;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
            return;
          }
          goto LABEL_499;
        case 402:
          if ( get_frame() <= 1 || get_frame() >= 7 )
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
              v495 = 0;
              do
              {
                float t[3];
                t[0] = (double)(-20 * field_7D4);
                t[1] = (double)v495 + 10.0;
                t[2] = (double)field_7D4 + 12.0;
                addbullet(this, NULL, 800, x, sin_deg((double)(20 * field_7D4)) * 150.0 + y + 50.0, dir, 1, t, 3);
                v495 += 10;
              }
              while ( v495 < 30 );
              v495 = 4;
              do
              {
                float t[3];
                t[0] = 360.0;
                t[1] = 50.0 * 0.1000000014901161 + 5.0;
                t[2] = (double)field_7D4 + 4.0;
                addbullet(this, NULL, 800, x, sin_deg((double)(20 * field_7D4)) * 150.0 + y + 50.0, dir, 1, t, 3);
                --v495;
              }
              while ( v495 );
              */
              ++field_7D4;
            }
            ++field_7D2;
          }
          if (process() )
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
            air_dash_cnt = 0;
            goto LABEL_140;
          }
          if ( field_7D0 <= 0 )
            goto LABEL_1021;
          field_7D0 = field_7D0 + 1;
          if ( get_subseq() )
          {
            if ( (field_7D0 % 10) == 1 && field_7D2 < 4 )
            {
              field_190 = 1;
              add_card_energy(10);
              /*
              v495 = 0;
              do
              {
                float t[3];
                t[0] = (double)(field_7D4 + 5 * (field_7D2 + 2) * v495) - (double)(10 * (field_7D2 + 2))
                t[1] = 1.0;
                t[2] = (double)field_7D2;
                addbullet(this, NULL, 800, (double)(60 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
                ++v495;
              }
              while ( v495 < 5 );
              //v1474 = &v1746;
              //v1748 = (double)field_7D2 + 16.0;
              xa = dir;
              v1460 = y + 160.0;
              v348 = (double)(60 * (char)xa) + x;
              */
              goto LABEL_1020;
            }
          }
          else if ( (field_7D0 % 10) == 1 && field_7D2 < 3 )
          {
            field_190 = 1;
            add_card_energy(10);
            /*
            v495 = 0;
            do
            {
              float t[3];
              t[0] = (double)(field_7D4 + 5 * (field_7D2 + 3) * v341) - (double)(10 * (field_7D2 + 3));
              t[1] = 1.0;
              t[2] = (double)field_7D2;
              addbullet(this, NULL, 800, (double)(60 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
              ++v495;
            }
            while ( v495 < 5 );
            //v1474 = &v1737;
            //v1739 = (double)field_7D2 + 16.0;
            xa = dir;
            v1460 = y + 160.0;
            v348 = (double)(60 * (char)xa) + x;
            */
LABEL_1020:
            //addbullet(this, NULL, 800, v348, v1460, xa, 1, 474, 3);
            play_sfx(1);
            ++field_7D2;
            goto LABEL_1021;
          }
LABEL_1021:
          if (process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_1884;
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
            goto LABEL_1054;
          move_valb = (enemy->x - x) * (double)dir;
          goto LABEL_1049;
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
            air_dash_cnt = 0;
            goto LABEL_140;
          }
          if ( field_7D0 <= 0 )
            goto LABEL_1076;
          field_7D0 = field_7D0 + 1;
          if ( get_subseq() )
          {
            if ( (field_7D0 % 10) == 1 && field_7D2 < 4 )
            {
              field_190 = 1;
              add_card_energy(10);
              v495 = 0;
              do
              {
                float t[3];
                t[0] = (double)(field_7D4 + 5 * (field_7D2 + 2) * v495) - (double)(10 * (field_7D2 + 2));
                t[1] = 1.0;
                t[2] = (double)field_7D2;
                addbullet(this, NULL, 800, (double)(60 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
                ++v495;
              }
              while ( v495 < 5 );
              //v1475 = &v1749;
              //v1751 = (double)field_7D2 + 16.0;
              //xb = dir;
              //v1461 = y + 160.0;
              //v379 = (double)(60 * (char)xb) + x;
              goto LABEL_1075;
            }
          }
          else if ( (field_7D0 % 10) == 1 && field_7D2 < 3 )
          {
            field_190 = 1;
            add_card_energy(10);
            /*
            v495 = 0;
            do
            {
              float t[3];
              t[0] = (double)(field_7D4 + 5 * (field_7D2 + 3) * v495) - (double)(10 * (field_7D2 + 3));
              t[1] = 1.0;
              t[2] = (double)field_7D2;
              addbullet(this, NULL, 800, (double)(60 * (char)dir) + x, y + 160.0, dir, 1, t, 3);
              ++v495;
            }
            while ( v495 < 5 );
            //v1475 = &v1752;
            //v1754 = (double)field_7D2 + 16.0;
            xb = dir;
            */
LABEL_1075:
            //addbullet(this, NULL, 800, (double)(60 * (char)xb) + x, y + 160.0, xb, 1, 475, 3);
            play_sfx(1);
            ++field_7D2;
            goto LABEL_1076;
          }
LABEL_1076:
          if (process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
          {
LABEL_1884:
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
            move_valb = (enemy->x - x) * (double)dir;
LABEL_1049:
            field_7D4 = -atan2_deg(enemy->y - y, move_valb);
            if ( field_7D4 < -20 )
              field_7D4 = -20;
            if ( field_7D4 > 20 )
              field_7D4 = 20;
            field_7D0 = 1;
            spell_energy_spend(200, 45);
          }
LABEL_1054:
          if ( !get_frame_time() )
          {
            v267 = get_frame() == 12;
LABEL_807:
            if ( v267 )
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
          if (process() )
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
              float t[3];
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
          v399 = h_inerc - 1.0;
          goto LABEL_1119;
        case 409:
          v_inerc = v_inerc - v_force;
          if ( getlvl_height() < (v_inerc + y) || v_inerc >= 0.0 )
          {
LABEL_857:
            if (process() )
              set_seq(9);
          }
          else
          {
            set_seq(10);
            reset_forces();
            y = getlvl_height();
          }
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
              float t[3];
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
            if ( !(field_7D2 % 3) && field_7D4 <= 8 )
            {
              play_sfx(2);
              field_190 = 1;
              add_card_energy(10);
              float t[3];
              t[0] = (double)(-120 - 7 * field_7D4);
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
          if (process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_499;
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
          if (process() )
            set_seq(0);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          {
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              add_card_energy(50);
              play_sfx(3);
              field_190 = 1;
              spell_energy_spend(200, 60);
              float t[3];
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
              float t[3];
              t[0] = 0.0;
              t[1] = 15.0;
              t[2] = 3.0;
              addbullet(this, NULL, 801, (double)(120 * (char)dir) + x, y + 150.0, dir, 1, t, 3);
            }
          }
          else
          {
            set_seq(0);
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
            if (process() )
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
                  v495 = 0.0;
                  do
                  {
                    float t[3];
                    t[0] = v495 * 60.0;
                    t[1] = 6.0;
                    t[2] = 1.0;
                    addbullet(this, NULL, 801, cos_deg(-(sin_deg(v495 * 60.0) * 100.0 + y + 100.0)) * 100.0 * (double)dir + x, sin_deg(v495 * 60.0) * 100.0 + y + 100.0, dir, 1, t, 3);
                    t[0] = 0.0;
                    t[1] = 0.0;
                    t[2] = 0.0;
                    addbullet(this, NULL, 801, cos_deg(-(t[0])) * 100.0 * (double)dir + x, sin_deg(0.0) * 100.0 + y + 100.0, dir, 1, (int)&v1571, 3);
                    v495 = v495 + 1; //1.0
                  }
                  while ( v495 < 6/*6.0 );
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
            goto LABEL_1203;
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( !get_subseq() && field_7D0 == 1 )
          {
            if ( !(field_7D2 % 5) && field_7D4 <= 5 )
            {
              play_sfx(2);
              field_190 = 1;
              add_card_energy(10);
              /*
              v1602 = (double)(-135 - 10 * field_7D4);
              v1603 = 8.0;
              v1604 = 1.0;
              v445 = dir;
              v446 = y + 200.0;
              v447 = v446;
              v448 = (double)(57 * (char)v445) + x;
              addbullet(this, NULL, 801, v448, v447, v445, 1, (int)&v1602, 3);
              v1602 = 0.0;
              v1603 = 0.0;
              v1604 = 0.0;
              v449 = dir;
              v450 = y + 200.0;
              v451 = v450;
              v452 = (double)(57 * (char)v449) + x;
              addbullet(this, NULL, 801, v452, v451, v449, 1, (int)&v1602, 3);
              */
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( get_subseq() == 1 && field_7D0 == 1 )
          {
            if ( !(field_7D2 % 3) && field_7D4 <= 10 )
            {
              play_sfx(2);
              field_190 = 1;
              add_card_energy(10);
              /*
              v1686 = (double)(-120 - 7 * field_7D4);
              v1687 = 8.0;
              v1688 = 1.0;
              v453 = dir;
              v454 = y + 200.0;
              v455 = v454;
              v456 = (double)(57 * (char)v453) + x;
              addbullet(this, NULL, 801, v456, v455, v453, 1, (int)&v1686, 3);
              v1686 = 0.0;
              v1687 = 0.0;
              v1688 = 0.0;
              v457 = dir;
              v458 = y + 200.0;
              v459 = v458;
              v460 = (double)(57 * (char)v457) + x;
              addbullet(this, NULL, 801, v460, v459, v457, 1, (int)&v1686, 3);
              */
              ++field_7D4;
            }
            ++field_7D2;
          }
          if (process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_1884;
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
          goto LABEL_1242;
        case 415:
          if ( get_subseq() == 2 )
            sub10func();
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 2 )
          {
            set_subseq(2);
            v_force = 0.0;
            air_dash_cnt = 0;
            goto LABEL_140;
          }
          if (process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            set_seq(9);
            return;
          }
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 6 )
            {
              add_card_energy(50);
              play_sfx(3);
              field_190 = 1;
              spell_energy_spend(200, 60);
              /*
              v1608 = 0.0;
              v1609 = 15.0;
              v1610 = 3.0;
              v463 = dir;
              v464 = y + 150.0;
              v465 = v464;
              v466 = (double)(120 * (char)v463) + x;
              addbullet(this, NULL, 801, v466, v465, v463, 1, (int)&v1608, 3);
              v1608 = 0.0;
              v1609 = 0.0;
              v1610 = 0.0;
              v467 = dir;
              v468 = y + 150.0;
              v469 = v468;
              v470 = (double)(120 * (char)v467) + x;
              addbullet(this, NULL, 801, v470, v469, v467, 1, (int)&v1608, 3);
              */
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
            /*
            v1911 = 0.0;
            v1912 = 15.0;
            v1913 = 3.0;
            v471 = dir;
            v472 = y + 150.0;
            v473 = v472;
            v474 = (double)(120 * (char)v471) + x;
            addbullet(this, NULL, 801, v474, v473, v471, 1, (int)&v1911, 3);
            */
          }
          goto LABEL_1242;
        case 416:
          if ( get_subseq() == 2 )
            sub10func();
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() && get_subseq() < 2 )
          {
LABEL_1203:
            set_subseq(2);
            v_force = 0.0;
            air_dash_cnt = 0;
            goto LABEL_140;
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
              /*
              v1668 = (double)(10 * (field_7D4 + 12));
              v1669 = 8.0;
              v1670 = 1.0;
              v475 = dir;
              v476 = y + 200.0;
              v477 = v476;
              v478 = (double)(57 * (char)v475) + x;
              addbullet(this, NULL, 801, v478, v477, v475, 1, (int)&v1668, 3);
              v1668 = 0.0;
              v1669 = 0.0;
              v1670 = 0.0;
              v479 = dir;
              v480 = y + 200.0;
              v481 = v480;
              v482 = (double)(57 * (char)v479) + x;
              addbullet(this, NULL, 801, v482, v481, v479, 1, (int)&v1668, 3);
              */
              ++field_7D4;
            }
            ++field_7D2;
          }
          if ( get_subseq() == 1 && field_7D0 == 1 )
          {
            if ( !(field_7D2 % 3) && field_7D4 <= 10 )
            {
              play_sfx(2);
              field_190 = 1;
              add_card_energy(10);
              /*
              v1614 = (double)(7 * (-30 - field_7D4));
              v1615 = 8.0;
              v1616 = 1.0;
              v483 = dir;
              v484 = y + 200.0;
              v485 = v484;
              v486 = (double)(57 * (char)v483) + x;
              addbullet(this, NULL, 801, v486, v485, v483, 1, (int)&v1614, 3);
              v1614 = 0.0;
              v1615 = 0.0;
              v1616 = 0.0;
              v487 = dir;
              v488 = y + 200.0;
              v489 = v488;
              v490 = (double)(57 * (char)v487) + x;
              addbullet(this, NULL, 801, v490, v489, v487, 1, (int)&v1614, 3);
              */
              ++field_7D4;
            }
            ++field_7D2;
          }
          if (process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
            goto LABEL_1884;
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
          if ( get_subseq() != 1 || get_frame_time() )
            return;
          if ( get_frame() == 3 )
          {
            field_7D0 = 1;
            spell_energy_spend(200, 60);
            add_card_energy(30);
          }
LABEL_1242:
          if ( get_frame_time() )
            return;
          v462 = get_frame() == 13;
          goto LABEL_1244;
        case 418:
          if ( get_subseq() == 1 || !get_subseq() && get_frame() >= 3 )
          {
            v_inerc = v_inerc - v_force;
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
              h_inerc = 0.0;
            if ( char_on_ground_down() )
            {
              move_val = 2;
LABEL_139:
              set_seq(move_val);
              goto LABEL_140;
            }
          }
          if ( !get_subseq() && get_frame() <= 2 || get_subseq() == 2 )
            sub10func();
          if (process() )
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
                float t[3];
                t[0] = 0.0;
                t[1] = 0.0;
                t[2] = 0.0;
                addbullet(this, NULL, 848, x, y, dir, 1, t, 3);
              }
            }
          }
          return;
        default:
          goto LABEL_2803;
      }
    }
    if ( sq <= 750 )
    {
      if ( sq != 750 )
      {
        switch ( sq )
        {
          case 501:
            sub10func();
            field_18C = 0;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_92;
            if ( get_subseq() || get_frame_time() || get_frame() != 4 )
              return;
            v495 = 0;
            if ( skills_1[0] < 4 )
            {
              if ( skills_1[0] < 1 )
              {
                v495 = 0;
                do
                {
                  float t[3];
                  t[0] = -110.0 - (double)v495;
                  t[1] = 6.0;
                  t[2] = 12.0;
                  addbullet(this, NULL, 810, (double)(38 * (char)dir) + x, y + 177.0, dir, 1, t, 3);
                  v495 += 10;
                }
                while ( v495 < 40 );
              }
              else
              {
                v495 = 0;
                do
                {
                  float t[3];
                  t[0] = -110.0 - (double)v495;
                  t[1] = 6.0;
                  t[2] = 12.0;
                  addbullet(this, NULL, 810, (double)(38 * (char)dir) + x, y + 177.0, dir, 1, t, 3);
                  v495 += 10;
                }
                while ( v495 < 50 );
              }
            }
            else
            {
              v495 = 0;
              do
              {
                float t[3];
                t[0] = -110.0 - (double)v495;
                t[1] = 6.0;
                t[2] = 12.0;
                addbullet(this, NULL, 810, (double)(38 * (char)dir) + x, y + 177.0, dir, 1, t, 3);
                v495 += 10;
              }
              while ( v495 < 60 );
            }
            goto LABEL_1355;
          case 502:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 0;
            if ( get_subseq() < 2 )
              v_inerc = v_inerc - v_force;
            if ( !get_subseq() && get_frame() >= 11 && char_on_ground_down() || get_subseq() == 1 && get_frame() >= 11 && char_on_ground_down() )
              goto LABEL_1386;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_1884;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() != 4 )
              goto LABEL_1415;
            //v523 = 0;
            //v1675 = 6.0;
            //v1676 = 12.0;
            /*
            if ( skills_1[0] < 4 )
            {
              if ( skills_1[0] < 1 )
              {
                v1502 = 0;
                do
                {
                  v1674 = -20.0 - (double)v1502;
                  v533 = dir;
                  v534 = y + 177.0;
                  v535 = v534;
                  v536 = (double)(38 * (char)v533) + x;
                  addbullet(this, NULL, 810, v536, v535, v533, 1, (int)&v1674, 3);
                  v523 += 10;
                  v1502 = v523;
                }
                while ( v523 < 40 );
              }
              else
              {
                v1501 = 0;
                do
                {
                  v1674 = -20.0 - (double)v1501;
                  v529 = dir;
                  v530 = y + 177.0;
                  v531 = v530;
                  v532 = (double)(38 * (char)v529) + x;
                  addbullet(this, NULL, 810, v532, v531, v529, 1, (int)&v1674, 3);
                  v523 += 10;
                  v1501 = v523;
                }
                while ( v523 < 50 );
              }
            }
            else
            {
              v1500 = 0;
              do
              {
                v1674 = -20.0 - (double)v1500;
                v525 = dir;
                v526 = y + 177.0;
                v527 = v526;
                v528 = (double)(38 * (char)v525) + x;
                addbullet(this, NULL, 810, v528, v527, v525, 1, (int)&v1674, 3);
                v523 += 10;
                v1500 = v523;
              }
              while ( v523 < 60 );
            }
            */
            goto LABEL_1414;
          case 503:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 0;
            if ( get_subseq() < 2 )
              v_inerc = v_inerc - v_force;
            if ( !get_subseq() && get_frame() >= 11 && char_on_ground_down() || get_subseq() == 1 && get_frame() >= 11 && char_on_ground_down() )
              goto LABEL_1386;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_1884;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() == 4 )
            {
              /*
              v538 = 0;
              v1588 = 6.0;
              v1589 = 12.0;
              if ( skills_1[0] < 4 )
              {
                if ( skills_1[0] < 1 )
                {
                  v1505 = 0;
                  do
                  {
                    v1587 = -110.0 - (double)v1505;
                    v548 = dir;
                    v549 = y + 177.0;
                    v550 = v549;
                    v551 = (double)(38 * (char)v548) + x;
                    addbullet(this, NULL, 810, v551, v550, v548, 1, (int)&v1587, 3);
                    v538 += 10;
                    v1505 = v538;
                  }
                  while ( v538 < 40 );
                }
                else
                {
                  v1504 = 0;
                  do
                  {
                    v1587 = -110.0 - (double)v1504;
                    v544 = dir;
                    v545 = y + 177.0;
                    v546 = v545;
                    v547 = (double)(38 * (char)v544) + x;
                    addbullet(this, NULL, 810, v547, v546, v544, 1, (int)&v1587, 3);
                    v538 += 10;
                    v1504 = v538;
                  }
                  while ( v538 < 50 );
                }
              }
              else
              {
                v1503 = 0;
                do
                {
                  v1587 = -110.0 - (double)v1503;
                  v540 = dir;
                  v541 = y + 177.0;
                  v542 = v541;
                  v543 = (double)(38 * (char)v540) + x;
                  addbullet(this, NULL, 810, v543, v542, v540, 1, (int)&v1587, 3);
                  v538 += 10;
                  v1503 = v538;
                }
                while ( v538 < 60 );
              }
              */
LABEL_1414:
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(10);
            }
            goto LABEL_1415;
          case 505:
            sub10func();
            field_18C = 4;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_499;
            if ( get_subseq() || get_frame_time() || get_frame() != 4 )
              return;
            /*
            v1954 = 6.0;
            v1476 = &v1953;
            v1955 = 12.0;
            v1953 = -60.0;
            xc = dir;
            v552 = y + 177.0;
            v1462 = v552;
            v553 = (double)(38 * dir) + x;
            v554 = v553;
            */
            goto LABEL_1462;
          case 506:
            sub10func();
            field_18C = 4;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_499;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              /*
              v1840 = 6.0;
              v1476 = (int *)&v1839;
              v1841 = 12.0;
              v1839 = -45.0;
              xc = dir;
              v556 = y + 177.0;
              v1462 = v556;
              v557 = (double)(38 * dir) + x;
              v554 = v557;
//LABEL_1462:
              v555 = v554;
              addbullet(this, NULL, 811, v555, v1462, xc, 1, 476, 3);
              */
LABEL_1462:
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(6);
            }
            return;
          case 507:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 4;
            if ( get_subseq() < 2 )
              v_inerc = v_inerc - v_force;
            if ( !get_subseq() && get_frame() >= 11 && char_on_ground_down() || get_subseq() == 1 && get_frame() >= 11 && char_on_ground_down() )
              goto LABEL_1386;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_1884;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() != 4 )
              goto LABEL_1415;
            /*
            v1918 = 6.0;
            v1477 = &v1917;
            v1919 = 12.0;
            v1917 = -60.0;
            xd = dir;
            v558 = y + 177.0;
            v1463 = v558;
            v559 = (double)(38 * dir) + x;
            v560 = v559;
            */
            goto LABEL_1496;
          case 508:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 4;
            if ( get_subseq() < 2 )
              v_inerc = v_inerc - v_force;
            if ( !get_subseq() && get_frame() >= 11 && char_on_ground_down() || get_subseq() == 1 && get_frame() >= 11 && char_on_ground_down() )
            {
LABEL_1386:
              set_subseq(2);
              goto LABEL_1387;
            }
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_1884;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() == 4 )
            {
              /*
              v1846 = 6.0;
              v1477 = (int *)&v1845;
              v1847 = 12.0;
              v1845 = -45.0;
              xd = dir;
              v562 = y + 177.0;
              v1463 = v562;
              v563 = (double)(38 * dir) + x;
              v560 = v563;
LABEL_1496:
              v561 = v560;
              addbullet(this, NULL, 811, v561, v1463, xd, 1, 477, 3);
              */
LABEL_1496:
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(6);
            }
LABEL_1415:
            if ( get_frame_time() )
              return;
            v537 = get_frame() == 11;
            goto LABEL_1417;
          case 510:
            sub10func();
            field_18C = 8;
            if ( field_7D0 != 1 )
              goto LABEL_1525;
            if ( dash_angle >= 16.0 )
              goto LABEL_1524;
            /*
            v1771 = 80.0 - dash_angle * 9.0;
            v564 = dash_angle * 12.0;
            v1478 = &v1771;
            v1772 = sin_deg(v564) * 16.0 + 2.0;
            v1773 = 0.0;
            v1774 = dash_angle;
            xe = dir;
            v565 = -v1771;
            v566 = sin_deg(v565) * 40.0 + y + 120.0;
            v1464 = v566;
            v567 = -v1771;
            v568 = (cos_deg(v567) * 100.0 + dash_angle * 5.0 - 85.0) * (double)dir + x;
            v569 = v568;
            */
            goto LABEL_1523;
          case 511:
            sub10func();
            field_18C = 8;
            if ( field_7D0 == 1 )
            {
              /*
              if ( dash_angle < 30.0 )
              {
                v1759 = 80.0 - dash_angle * 9.0;
                v571 = dash_angle * 10.0;
                v1478 = (int *)&v1759;
                v1760 = sin_deg(v571) * 20.0 + 2.0;
                v1761 = 0.0;
                v1762 = dash_angle;
                xe = dir;
                v572 = -v1759;
                v573 = sin_deg(v572) * 40.0 + y + 120.0;
                v1464 = v573;
                v574 = -v1759;
                v575 = (cos_deg(v574) * 100.0 + dash_angle * 5.0 - 85.0) * (double)dir + x;
                v569 = v575;
LABEL_1523:
                v570 = v569;
                addbullet(this, NULL, 812, v570, v1464, xe, 1, 478, 4);
              }
              */
LABEL_1523: //TODO
LABEL_1524:
              dash_angle = dash_angle + 1.0;
            }
LABEL_1525:
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_499;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(10);
              field_7D0 = 1;
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
            if ( field_7D0 != 1 )
              goto LABEL_1548;
            if ( dash_angle >= 16.0 )
              goto LABEL_1547;
            /*
            v1767 = 80.0 - dash_angle * 9.0;
            v576 = dash_angle * 12.0;
            v1479 = &v1767;
            v1768 = sin_deg(v576) * 16.0 + 2.0;
            v1769 = 0.0;
            v1770 = dash_angle;
            xf = dir;
            v577 = -v1767;
            v578 = sin_deg(v577) * 40.0 + y + 120.0;
            v1465 = v578;
            v579 = -v1767;
            v580 = (cos_deg(v579) * 100.0 + dash_angle * 5.0 - 85.0) * (double)dir + x;
            v581 = v580;
            */
            goto LABEL_1546;
          case 513:
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
              /*
              if ( dash_angle < 30.0 )
              {
                v1775 = 80.0 - dash_angle * 9.0;
                v583 = dash_angle * 10.0;
                v1479 = (int *)&v1775;
                v1776 = sin_deg(v583) * 20.0 + 2.0;
                v1777 = 0.0;
                v1778 = dash_angle;
                xf = dir;
                v584 = -v1775;
                v585 = sin_deg(v584) * 40.0 + y + 120.0;
                v1465 = v585;
                v586 = -v1775;
                v587 = (cos_deg(v586) * 100.0 + dash_angle * 5.0 - 85.0) * (double)dir + x;
                v581 = v587;
LABEL_1546:
                v582 = v581;
                addbullet(this, NULL, 812, v582, v1465, xf, 1, 479, 4);
              }
              */
LABEL_1546: //TODO
LABEL_1547:
              dash_angle = dash_angle + 1.0;
            }
LABEL_1548:
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1884;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                add_card_energy(50);
                spell_energy_spend(200, 120);
                play_sfx(10);
                field_7D0 = 1;
              }
              if ( !get_frame_time() )
              {
                v462 = get_frame() == 11;
LABEL_1244:
                if ( v462 )
                  v_force = 0.5;
              }
            }
            return;
          case 520:
            sub10func();
            field_18C = 1;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_499;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              field_190 = 1;
              /*
              v1722 = 0.0;
              v1723 = 0.0;
              v1724 = 0.0;
              v588 = dir;
              v589 = y + 150.0;
              v590 = v589;
              v591 = (double)(95 * (char)v588) + x;
              addbullet(this, NULL, 815, v591, v590, v588, 1, (int)&v1722, 3);
              v592 = 0;
              v1724 = 1.0;
              v1506 = 0;
              do
              {
                v1722 = (double)v1506 - 10.0;
                v593 = dir;
                v594 = y + 150.0;
                v595 = v594;
                v596 = (double)(95 * (char)v593) + x;
                addbullet(this, NULL, 815, v596, v595, v593, 1, (int)&v1722, 3);
                v592 += 5;
                v1506 = v592;
              }
              while ( v592 < 25 );
              */
              add_card_energy(50);
              play_sfx(12);
              spell_energy_spend(200, 120);
            }
            return;
          case 521:
            sub10func();
            field_18C = 1;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_499;
            if ( get_subseq() || get_frame_time() || get_frame() != 6 )
              return;
            field_190 = 1;
            /*
            v1704 = 0.0;
            v1705 = 0.0;
            v1706 = 0.0;
            v597 = dir;
            v598 = y + 150.0;
            v599 = v598;
            v600 = (double)(95 * (char)v597) + x;
            addbullet(this, NULL, 815, v600, v599, v597, 1, (int)&v1704, 3);
            v601 = 0;
            v1706 = 1.0;
            v1507 = 0;
            do
            {
              v1704 = (double)v1507 - 16.0;
              v602 = dir;
              v603 = y + 150.0;
              v604 = v603;
              v605 = (double)(95 * (char)v602) + x;
              addbullet(this, NULL, 815, v605, v604, v602, 1, (int)&v1704, 3);
              v601 += 8;
              v1507 = v601;
            }
            while ( v601 < 40 );
            */
            play_sfx(12);
            goto LABEL_1592;
          case 522:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 1;
            if ( get_subseq() <= 1 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_1597;
            }
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_1884;
            if ( get_subseq() || get_frame_time() )
              return;
            if ( get_frame() == 6 )
            {
              field_190 = 1;
              /*
              v1707 = 0.0;
              v1708 = 0.0;
              v1709 = 0.0;
              v606 = dir;
              v607 = y + 150.0;
              v608 = v607;
              v609 = (double)(95 * (char)v606) + x;
              addbullet(this, NULL, 815, v609, v608, v606, 1, (int)&v1707, 3);
              v610 = 0;
              v1709 = 1.0;
              v1508 = 0;
              do
              {
                v1707 = (double)v1508 - 10.0;
                v611 = dir;
                v612 = y + 150.0;
                v613 = v612;
                v614 = (double)(95 * (char)v611) + x;
                addbullet(this, NULL, 815, v614, v613, v611, 1, (int)&v1707, 3);
                v610 += 5;
                v1508 = v610;
              }
              while ( v610 < 25 );
              */
              play_sfx(12);
              add_card_energy(50);
              spell_energy_spend(200, 120);
            }
            if ( get_frame_time() )
              return;
            v537 = get_frame() == 17;
            goto LABEL_1417;
          case 523:
            if ( get_subseq() == 2 )
              sub10func();
            field_18C = 1;
            if ( get_subseq() <= 1 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_1597:
                set_subseq(2);
                goto LABEL_140;
              }
            }
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
              goto LABEL_1884;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 6 )
              {
                field_190 = 1;
                /*
                v1713 = 0.0;
                v1714 = 0.0;
                v1715 = 0.0;
                v615 = dir;
                v616 = y + 150.0;
                v617 = v616;
                v618 = (double)(95 * (char)v615) + x;
                addbullet(this, NULL, 815, v618, v617, v615, 1, (int)&v1713, 3);
                v619 = 0;
                v1715 = 1.0;
                v1509 = 0;
                do
                {
                  v1713 = (double)v1509 - 16.0;
                  v620 = dir;
                  v621 = y + 150.0;
                  v622 = v621;
                  v623 = (double)(95 * (char)v620) + x;
                  addbullet(this, NULL, 815, v623, v622, v620, 1, (int)&v1713, 3);
                  v619 += 8;
                  v1509 = v619;
                }
                while ( v619 < 40 );
                */
                play_sfx(12);
                add_card_energy(50);
                spell_energy_spend(200, 120);
              }
              if ( !get_frame_time() )
              {
                v537 = get_frame() == 17;
LABEL_1417:
                if ( v537 )
                  v_force = 0.40000001;
              }
            }
            return;
          case 525:
            sub10func();
            field_18C = 5;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_499;
            if ( get_subseq() || get_frame_time() || get_frame() != 6 )
              return;
            field_190 = 1;
            /*
            v1779 = 0.0;
            v1780 = 20.0;
            v1781 = 12.0;
            v624 = dir;
            v625 = y + 145.0;
            v626 = v625;
            v627 = (double)(95 * (char)v624) + x;
            addbullet(this, NULL, 816, v627, v626, v624, 1, (int)&v1779, 3);
            v1781 = 1.0;
            */
            play_sfx(16);
            goto LABEL_1592;
          case 526:
            sub10func();
            field_18C = 5;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_499;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 6 )
            {
              /*
              field_190 = 1;
              v1785 = 0.0;
              v1786 = 20.0;
              v1787 = 12.0;
              v628 = dir;
              v629 = y + 145.0;
              v630 = v629;
              v631 = (double)(95 * (char)v628) + x;
              addbullet(this, NULL, 816, v631, v630, v628, 1, (int)&v1785, 3);
              v1787 = 1.0;
              */
              play_sfx(16);
LABEL_1592:
              add_card_energy(50);
              spell_energy_spend(200, 120);
            }
            return;
          case 540:
            sub10func();
            field_18C = 2;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(13);
              //v632 = 0;
              field_190 = 1;
              /*
              v1510 = 0;
              v1486 = 0;
              do
              {
                v1983 = (double)v1486;
                v1984 = 300.0;
                v1985 = 4.0;
                v633 = dir;
                v634 = (double)v1510;
                v635 = v634 - 6.0;
                v636 = sin_deg(v635) * 300.0 + y + 170.0;
                v637 = v636;
                v638 = v634 * 60.0;
                v639 = (cos_deg(v638) * 300.0 + 50.0) * (double)dir + x;
                addbullet(this, NULL, 820, v639, v637, v633, 1, (int)&v1983, 3);
                ++v1510;
                v632 += 60;
                v1486 = v632;
              }
              while ( v632 < 360 );
              */
            }
            return;
          case 541:
            sub10func();
            field_18C = 2;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(13);
              //v640 = 0;
              field_190 = 1;
              /*
              v1511 = 0;
              v1487 = 0;
              do
              {
                v1851 = (double)v1487;
                v1852 = 300.0;
                v1853 = 0.0;
                v641 = dir;
                v642 = (double)v1511;
                v643 = v642 - 6.0;
                v644 = sin_deg(v643) * 300.0 + y + 170.0;
                v645 = v644;
                v646 = v642 * 60.0;
                v647 = (cos_deg(v646) * 300.0 + 50.0) * (double)dir + x;
                addbullet(this, NULL, 820, v647, v645, v641, 1, (int)&v1851, 3);
                ++v1511;
                v640 += 60;
                v1487 = v640;
              }
              while ( v640 < 360 );
              */
            }
            return;
          case 545:
            sub10func();
            field_18C = 6;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if (process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1687;
            if ( get_subseq() != 1 )
              return;
            add_card_energy(50);
            spell_energy_spend(200, 120);
            play_sfx(18);
            field_190 = 1;
            /*
            v1923 = 0.0;
            v1924 = 10.0;
            v1925 = 0.0;
            v648 = dir;
            v649 = y + 180.0;
            v650 = v649;
            v651 = (double)(55 * (char)v648) + x;
            addbullet(this, NULL, 821, v651, v650, v648, 1, (int)&v1923, 3);
            */
            goto LABEL_1687;
          case 546:
            sub10func();
            field_18C = 6;
            if ( !keyDown(INP_C) )
              not_charge_attack = 0;
            if (process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() )
              goto LABEL_1687;
            if ( get_subseq() == 1 )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              play_sfx(18);
              field_190 = 1;
              /*
              v1857 = -90.0;
              v1858 = 10.0;
              v1859 = 0.0;
              v653 = dir;
              v654 = y + 180.0;
              v655 = v654;
              v656 = (double)(55 * (char)v653) + x;
              addbullet(this, NULL, 821, v656, v655, v653, 1, (int)&v1857, 3);
              */
LABEL_1687:
              if ( get_subseq() == 1 )
              {
                if ( (get_elaps_frames() >= 24) && !not_charge_attack || get_elaps_frames() >= 20 * ((char)skills_1[6] + 3) )
                  next_subseq();
              }
            }
            return;
          case 560:
            sub10func();
            field_18C = 3;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_1712;
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 9.0 )
              h_inerc = 9.0;
            if ( get_elaps_frames() >= 25 || (enemy->x - x) * (double)dir <= 120.0 )
              goto LABEL_2148;
            /*
            v660 = get_elaps_frames() & 0x80000001;
            v659 = v660 == 0;
            if ( v660 < 0 )
              v659 = (((_BYTE)v660 - 1) | 0xFFFFFFFE) == -1;
            if ( v659 )
            {
              v1959 = (double)(unsigned int)get_MT_range(360);
              v1960 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 5.0;
              v1961 = 1.0;
              v661 = dir;
              v662 = x + 50.0;
              v663 = (double)(unsigned int)get_MT_range(200) + y;
              v664 = v663;
              v665 = v662 - (double)(unsigned int)get_MT_range(100);
              addbullet(this, NULL, 825, v665, v664, v661, 1, (int)&v1959, 3);
            }
            */
LABEL_1712:
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
              if ( get_frame() <= 4 && !(get_elaps_frames() % 4) )
              {
                /*
                v1863 = 0.0;
                v1864 = 0.0;
                v1865 = 0.0;
                v667 = dir;
                v668 = y + 127.0;
                v669 = v668;
                v670 = (double)(56 * (char)v667) + x;
                addbullet(this, NULL, 825, v670, v669, v667, 1, (int)&v1863, 3);
                */
              }
            }
            if (process() )
              set_seq(0);
            if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
              goto LABEL_1726;
            h_inerc = 15.0;
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(14);
            goto LABEL_1725;
          case 561:
            sub10func();
            field_18C = 3;
            if ( !keyDown(INP_B) )
              not_charge_attack = 0;
            if ( get_subseq() != 1 )
              goto LABEL_1741;
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 11.0 )
              h_inerc = 11.0;
            if ( get_elaps_frames() >= 40 || (enemy->x - x) * (double)dir <= 120.0 )
              goto LABEL_2148;
            /*
            v674 = get_elaps_frames() & 0x80000001;
            v673 = v674 == 0;
            if ( v674 < 0 )
              v673 = (((_BYTE)v674 - 1) | 0xFFFFFFFE) == -1;
            if ( v673 )
            {
              v1791 = (double)(unsigned int)get_MT_range(360);
              v1792 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 5.0;
              v1793 = 1.0;
              v675 = dir;
              v676 = x + 50.0;
              v677 = (double)(unsigned int)get_MT_range(200) + y;
              v678 = v677;
              v679 = v676 - (double)(unsigned int)get_MT_range(100);
              addbullet(this, NULL, 825, v679, v678, v675, 1, (int)&v1791, 3);
            }
            */
LABEL_1741:
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
              /*
              if ( get_frame() <= 4 && !(get_elaps_frames() % 4) )
              {
                v1869 = 0.0;
                v1870 = 0.0;
                v1871 = 0.0;
                v681 = dir;
                v682 = y + 127.0;
                v683 = v682;
                v684 = (double)(56 * (char)v681) + x;
                addbullet(this, NULL, 825, v684, v683, v681, 1, (int)&v1869, 3);
              }
              */
            }
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              h_inerc = 15.0;
              play_sfx(14);
              spell_energy_spend(200, 120);
              add_card_energy(50);
LABEL_1725:
              scene_add_effect(this, 127, x, y, dir, -1);
            }
LABEL_1726:
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
              play_sfx(11);
            return;
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
              goto LABEL_140;
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
                  /*
                  v689 = enemy;
                  v690 = (v689->x - x) * (double)dir;
                  v691 = v690;
                  v692 = v689->y - y;
                  v693 = -atan2_deg(v692, v691);
                  field_7D4 = v693;
                  if ( v693 < -10 )
                    field_7D4 = -10;
                  if ( field_7D4 > 10 )
                    field_7D4 = 10;
                    */
                  play_sfx(9);
                  /*
                  if ( field_7D8 == 1 )
                  {
                    v694 = (double)field_7D4 + 30.0;
                    v1977 = v694 - (double)(MT_getnext() % 0x3Cu);
                    v1978 = 15.0;
                    v1979 = (double)(unsigned int)get_MT_range(4);
                    v1480 = (int *)&v1977;
                  }
                  else
                  {
                    v699 = (double)field_7D4 + 30.0;
                    v1875 = v699 - (double)(MT_getnext() % 0x3Cu);
                    v1876 = 15.0;
                    v1877 = (double)(unsigned int)get_MT_range(4);
                    v1480 = &v1875;
                  }
                  v695 = dir;
                  v696 = y + 85.0;
                  v697 = v696;
                  v698 = (double)(44 * (char)v695) + x;
                  addbullet(this, NULL, 808, v698, v697, v695, 1, 480, 3);
                  */
                }
                ++field_7D0;
              }
            }
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            {
LABEL_372:
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
              /*
              v1935 = 0.0;
              v1936 = 0.0;
              v1937 = 4.0;
              v705 = dir;
              v706 = y + 107.0;
              v707 = v706;
              v708 = x - (double)(23 * (char)v705);
              addbullet(this, NULL, 808, v708, v707, v705, 1, (int)&v1935, 3);
              */
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
            if ( get_subseq() != 4 || get_frame_time() )
              return;
            v267 = get_frame() == 5;
            goto LABEL_807;
          case 565:
            if ( get_frame() >= 7 )
              sub10func();
            field_18C = 7;
            h_inerc = h_inerc + 0.5;
            if ( h_inerc > 0.0 )
              h_inerc = 0.0;
            if (process() )
              set_seq(0);
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
                  /*
                  v1881 = (double)(unsigned int)get_MT_range(360);
                  v1882 = 0.0;
                  v1883 = 0.0;
                  v711 = dir;
                  v712 = y + 26.0;
                  v713 = v712;
                  v714 = (double)(45 * (char)v711) + x;
                  addbullet(this, NULL, 826, v714, v713, v711, 1, (int)&v1881, 3);
                  */
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 3 )
                  {
                    /*
                    v1965 = (double)(unsigned int)get_MT_range(360);
                    v1966 = 0.0;
                    v1967 = 0.0;
                    v715 = dir;
                    v716 = y + 217.0;
                    v717 = v716;
                    v718 = (double)(58 * (char)v715) + x;
                    addbullet(this, NULL, 826, v718, v717, v715, 1, (int)&v1965, 3);
                    */
                  }
                  if ( !get_frame_time() )
                  {
                    if ( get_frame() == 4 )
                    {
                      /*
                      v1887 = (double)(unsigned int)get_MT_range(360);
                      v1888 = 0.0;
                      v1889 = 0.0;
                      v719 = dir;
                      v720 = y + 266.0;
                      v721 = v720;
                      v722 = (double)(5 * (char)v719) + x;
                      addbullet(this, NULL, 826, v722, v721, v719, 1, (int)&v1887, 3);
                      */
                    }
                    if ( !get_frame_time() )
                    {
                      if ( get_frame() == 5 )
                      {
                        /*
                        v1941 = (double)(unsigned int)get_MT_range(360);
                        v1942 = 0.0;
                        v1943 = 0.0;
                        v723 = dir;
                        v724 = y + 234.0;
                        v725 = v724;
                        v726 = x - (double)((char)v723 << 6);
                        addbullet(this, NULL, 826, v726, v725, v723, 1, (int)&v1941, 3);
                        */
                      }
                      if ( !get_frame_time() && get_frame() == 6 )
                      {
                        /*
                        v1893 = (double)(unsigned int)get_MT_range(360);
                        v1894 = 0.0;
                        v1895 = 0.0;
                        v727 = dir;
                        v728 = y + 132.0;
                        v729 = v728;
                        v730 = x - (double)(90 * (char)v727);
                        addbullet(this, NULL, 826, v730, v729, v727, 1, (int)&v1893, 3);
                        */
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
            if (process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 1 )
                h_inerc = -20.0;
              if ( !get_frame_time() )
              {
                /*
                if ( get_frame() == 2 )
                {
                  play_sfx(17);
                  spell_energy_spend(200, 120);
                  add_card_energy(50);
                  v1794 = (double)(unsigned int)get_MT_range(360);
                  v1795 = 0.0;
                  v1796 = 0.0;
                  v732 = dir;
                  v733 = y + 26.0;
                  v734 = v733;
                  v735 = (double)(45 * (char)v732) + x;
                  addbullet(this, NULL, 826, v735, v734, v732, 1, (int)&v1794, 3);
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 3 )
                  {
                    v1800 = (double)(unsigned int)get_MT_range(360);
                    v1801 = 0.0;
                    v1802 = 0.0;
                    v736 = dir;
                    v737 = y + 217.0;
                    v738 = v737;
                    v739 = (double)(58 * (char)v736) + x;
                    addbullet(this, NULL, 826, v739, v738, v736, 1, (int)&v1800, 3);
                  }
                  if ( !get_frame_time() )
                  {
                    if ( get_frame() == 4 )
                    {
                      v1806 = (double)(unsigned int)get_MT_range(360);
                      v1807 = 0.0;
                      v1808 = 0.0;
                      v740 = dir;
                      v741 = y + 266.0;
                      v742 = v741;
                      v743 = (double)(5 * (char)v740) + x;
                      addbullet(this, NULL, 826, v743, v742, v740, 1, (int)&v1806, 3);
                    }
                    if ( !get_frame_time() )
                    {
                      if ( get_frame() == 5 )
                      {
                        v1812 = (double)(unsigned int)get_MT_range(360);
                        v1813 = 0.0;
                        v1814 = 0.0;
                        v744 = dir;
                        v745 = y + 234.0;
                        v746 = v745;
                        v747 = x - (double)((char)v744 << 6);
                        addbullet(this, NULL, 826, v747, v746, v744, 1, (int)&v1812, 3);
                      }
                      if ( !get_frame_time() && get_frame() == 6 )
                      {
                        v1818 = (double)(unsigned int)get_MT_range(360);
                        v1819 = 0.0;
                        v1820 = 0.0;
                        v748 = dir;
                        v749 = y + 132.0;
                        v750 = v749;
                        v751 = x - (double)(90 * (char)v748);
                        addbullet(this, NULL, 826, v751, v750, v748, 1, (int)&v1818, 3);
                      }
                    }
                  }
                }
                */
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
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              goto LABEL_1884;
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
                /*
                v1824 = (double)(unsigned int)get_MT_range(360);
                v1825 = 0.0;
                v1826 = 0.0;
                v753 = dir;
                v754 = y + 40.0;
                v755 = v754;
                v756 = (double)(80 * (char)v753) + x;
                addbullet(this, NULL, 826, v756, v755, v753, 1, (int)&v1824, 3);
                */
              }
              /*
              if ( !get_frame_time() )
              {
                if ( get_frame() == 3 )
                {
                  v1830 = (double)(unsigned int)get_MT_range(360);
                  v1831 = 0.0;
                  v1832 = 0.0;
                  v757 = dir;
                  v758 = y + 230.0;
                  v759 = v758;
                  v760 = (double)(95 * (char)v757) + x;
                  addbullet(this, NULL, 826, v760, v759, v757, 1, (int)&v1830, 3);
                }
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 4 )
                  {
                    v1836 = (double)(unsigned int)get_MT_range(360);
                    v1837 = 0.0;
                    v1838 = 0.0;
                    v761 = dir;
                    v762 = y + 290.0;
                    v763 = v762;
                    v764 = (double)(20 * (char)v761) + x;
                    addbullet(this, NULL, 826, v764, v763, v761, 1, (int)&v1836, 3);
                  }
                  if ( !get_frame_time() )
                  {
                    if ( get_frame() == 5 )
                    {
                      v1842 = (double)(unsigned int)get_MT_range(360);
                      v1843 = 0.0;
                      v1844 = 0.0;
                      v765 = dir;
                      v766 = y + 250.0;
                      v767 = v766;
                      v768 = x - (double)(80 * (char)v765);
                      addbullet(this, NULL, 826, v768, v767, v765, 1, (int)&v1842, 3);
                    }
                    if ( !get_frame_time() && get_frame() == 6 )
                    {
                      v1848 = (double)(unsigned int)get_MT_range(360);
                      v1849 = 0.0;
                      v1850 = 0.0;
                      v769 = dir;
                      v770 = y + 160.0;
                      v771 = v770;
                      v772 = x - (double)(110 * (char)v769);
                      addbullet(this, NULL, 826, v772, v771, v769, 1, (int)&v1848, 3);
                    }
                  }
                }
              }
              */
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 50 )
              goto LABEL_1884;
            return;
          case 599:
            if ( field_7D0 > 0 && get_frame() < 7 && field_7D0 < 12 )
            {
              /*
              v774 = MT_getnext() % 0x23u;
              field_7D4 = v774;
              v1698 = (double)(-20 - v774);
              v1699 = (double)(MT_getnext() % 5u + 10);
              v1700 = 0.0;
              v775 = dir;
              v776 = (double)(20 * (char)v775 * (field_7D0 + 1)) + x;
              addbullet(this, NULL, 807, v776, y, v775, 1, (int)&v1698, 3);
              v1698 = (double)(MT_getnext() % 0x168u);
              v1699 = 0.0;
              v1700 = 1.0;
              v777 = dir;
              v778 = (double)(20 * (char)v777 * (field_7D0 + 1)) + x;
              addbullet(this, NULL, 801, v778, y, v777, 1, (int)&v1698, 3);
              */
              if ( field_7D0 == 1 )
              {
                play_sfx(0);
                spell_energy_spend(200, 120);
              }
              ++field_7D0;
            }
            if (process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 5 )
              field_7D0 = 1;
            return;
          case 600:
            sub10func();
            sub_46AB50(2, 2);
            if ( get_subseq() == 2 && get_elaps_frames() >= 48 )
              goto LABEL_2148;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              //get_elaps_frames() = 0;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x, y + 125.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 4 )
              {/*
                v1512 = 0.0;
                v780 = (float)0.0;
                do
                {
                  v781 = v780 * 30.0;
                  v1586 = v781;
                  v782 = v781;
                  v1544 = v782;
                  v1545 = 4.0;
                  v1546 = 0.0;
                  v783 = dir;
                  v784 = -v782;
                  v785 = sin_deg(v784) * 100.0 + y + 100.0;
                  v786 = v785;
                  v787 = -v1544;
                  v788 = cos_deg(v787) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 850, v788, v786, v783, 1, (int)&v1544, 3);
                  v1544 = v782;
                  v1545 = 4.0;
                  v1546 = 0.0;
                  v789 = x;
                  v790 = -dir;
                  v791 = -v1544;
                  v792 = sin_deg(v791) * 100.0 + y + 100.0;
                  v793 = v792;
                  v794 = -v1544;
                  v795 = v789 - cos_deg(v794) * 100.0 * (double)dir;
                  addbullet(this, NULL, 850, v795, v793, v790, 1, (int)&v1544, 3);
                  v789 = v1586 + 15.0;
                  v1544 = SLODWORD(v789);
                  v1545 = 7.0;
                  v1546 = 2.0;
                  v796 = dir;
                  v797 = -v789;
                  v798 = sin_deg(v797) * 100.0 + y + 100.0;
                  v799 = v798;
                  v800 = -v1544;
                  v801 = cos_deg(v800) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 850, v801, v799, v796, 1, (int)&v1544, 3);
                  v1544 = SLODWORD(v789);
                  v1545 = 7.0;
                  v1546 = 2.0;
                  v802 = -dir;
                  v1586 = x;
                  v803 = v802;
                  v804 = -v789;
                  v805 = sin_deg(v804) * 100.0 + y + 100.0;
                  v806 = v805;
                  v807 = -v1544;
                  v808 = cos_deg(v807);
                  v809 = v1586 - v808 * 100.0 * (double)dir;
                  addbullet(this, NULL, 850, v809, v806, v803, 1, (int)&v1544, 3);
                  v1512 = v1512 + 1.0;
                  v780 = v1512;
                }
                while ( v1512 < 12.0 );
                */
                play_sfx(50);
              }
            }
            return;
          case 601:
            sub10func();
            sub_46AB50(2, 2);
            if ( get_subseq() == 1 && get_elaps_frames() >= 48 )
              goto LABEL_170;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              /*
              v1854 = 0.0;
              v1855 = 0.0;
              v1856 = 4.0;
              v810 = dir;
              v811 = y + 146.0;
              v812 = v811;
              v813 = (double)(105 * (char)v810) + x;
              addbullet(this, NULL, 851, v813, v812, v810, 1, (int)&v1854, 3);
              */
              play_sfx(51);
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
            {
              sub_4834E0(40);
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
            if (process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 7 )
              {
                /*
                v1866 = 0.0;
                v1867 = 25.0;
                v1868 = 0.0;
                v827 = dir;
                v828 = y + 140.0;
                v829 = v828;
                v830 = (double)(85 * (char)v827) + x;
                addbullet(this, NULL, 852, v830, v829, v827, 1, (int)&v1866, 3);
                */
                play_sfx(52);
              }
              if ( !get_frame_time() && get_frame() == 2 )
              {
                sub_4834E0(40);
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
            if ( get_subseq() == 2 && field_7D2 >= 60 )
              goto LABEL_170;
            if ( field_7D0 == 1 )
            {
              if ( !(field_7D2 % 30) && dash_angle < 6.0 )
              {
                /*
                v1513 = 0.0;
                v835 = (float)0.0;
                do
                {
                  v836 = v835 * 30.0;
                  v837 = v836;
                  v838 = v836;
                  v1547 = v838;
                  v1548 = dash_angle + 4.0;
                  v1549 = 0.0;
                  v839 = dir;
                  v840 = -v838;
                  v841 = sin_deg(v840) * 100.0 + y + 100.0;
                  v842 = v841;
                  v843 = -v1547;
                  v844 = cos_deg(v843) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 853, v844, v842, v839, 1, (int)&v1547, 3);
                  v1547 = v838;
                  v1548 = dash_angle + 4.0;
                  v1549 = 0.0;
                  v845 = -dir;
                  v1586 = x;
                  v846 = v845;
                  v847 = -v838;
                  v848 = sin_deg(v847) * 100.0 + y + 100.0;
                  v849 = v848;
                  v850 = -v1547;
                  v851 = cos_deg(v850);
                  v852 = v1586 - v851 * 100.0 * (double)dir;
                  addbullet(this, NULL, 853, v852, v849, v846, 1, (int)&v1547, 3);
                  v853 = v837 + 15.0;
                  v1547 = v853;
                  v1548 = dash_angle + 7.0;
                  v1549 = 2.0;
                  v854 = dir;
                  v855 = -v853;
                  v856 = sin_deg(v855) * 100.0 + y + 100.0;
                  v857 = v856;
                  v858 = -v1547;
                  v859 = cos_deg(v858) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 853, v859, v857, v854, 1, (int)&v1547, 3);
                  v1547 = v853;
                  v1548 = dash_angle + 7.0;
                  v1549 = 2.0;
                  v860 = x;
                  v861 = -dir;
                  v862 = -v853;
                  v863 = sin_deg(v862) * 100.0 + y + 100.0;
                  v864 = v863;
                  v865 = -v1547;
                  v866 = v860 - cos_deg(v865) * 100.0 * (double)dir;
                  addbullet(this, NULL, 853, v866, v864, v861, 1, (int)&v1547, 3);
                  v1513 = v1513 + 1.0;
                  v835 = v1513;
                }
                while ( v1513 < 12.0 );
                */
                play_sfx(50);
                dash_angle = dash_angle + 5.0;
              }
              ++field_7D2;
            }
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              //get_elaps_frames() = 0;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                sub_4834E0(40);
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
              goto LABEL_170;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              /*
              v1872 = 0.0;
              v1873 = 0.0;
              v1874 = 4.0;
              addbullet(this, NULL, 854, enemy->x, 0.0, dir, 1, (int)&v1872, 3);
              */
              play_sfx(54);
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
            {
              sub_4834E0(40);
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
            if (process() )
              set_seq(0);
            if ( !get_frame_time() )
            {
              if ( get_frame() == 7 )
              {
                /*
                v1878 = 0.0;
                v1879 = 25.0;
                v1880 = 0.0;
                v872 = dir;
                v873 = y + 140.0;
                v874 = v873;
                v875 = (double)(85 * (char)v872) + x;
                addbullet(this, NULL, 855, v875, v874, v872, 1, (int)&v1878, 3);
                */
                play_sfx(52);
              }
              if ( !get_frame_time() && get_frame() == 2 )
              {
                sub_4834E0(40);
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
              goto LABEL_170;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              //get_elaps_frames() = 0;
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x, y + 125.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
              if ( !get_frame_time() && get_frame() == 4 )
              {
                /*
                v1514 = 0.0;
                v881 = 12.0;
                v882 = (float)0.0;
                do
                {
                  v1740 = v882 * 30.0;
                  v1741 = 4.0;
                  v1742 = v881;
                  v883 = dir;
                  v884 = -v1740;
                  v885 = sin_deg(v884) * 100.0 + y + 100.0;
                  v886 = v885;
                  v887 = -v1740;
                  v888 = cos_deg(v887) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 856, v888, v886, v883, 1, (int)&v1740, 3);
                  v1514 = v1514 + 1.0;
                  v881 = 12.0;
                  v882 = v1514;
                }
                while ( v1514 < 12.0 );
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
              if ( !(get_elaps_frames() % 15) && field_7D0 <= 3 )
              {
                /*
                v889 = (double)(unsigned int)get_MT_range(125) + 50.0;
                v890 = (double)field_7D0 * 60.0 + 100.0;
                v1782 = 5.0 - (double)(unsigned int)get_MT_range(10);
                v1783 = 35.0;
                v1784 = 12.0;
                v891 = dir;
                v892 = (double)(char)v891 * v889 + x;
                addbullet(this, NULL, 857, v892, v890, v891, -1, (int)&v1782, 3);
                v893 = dir;
                v894 = x - (double)(char)v893 * v889;
                addbullet(this, NULL, 857, v894, v890, v893, 1, (int)&v1782, 3);
                */
                play_sfx(16);
                ++field_7D0;
              }
              if ( get_elaps_frames() >= 60 )
                goto LABEL_2148;
            }
            if ( get_subseq() == 2 && get_elaps_frames() >= 0 )
              goto LABEL_2148;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              //get_elaps_frames() = 0;
            if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, x - (double)(40 * (char)dir), y + 153.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              /*
              v1884 = 0.0;
              v1885 = 0.0;
              v1886 = 14.0;
              v899 = dir;
              v900 = x - (double)(20 * (char)v899);
              addbullet(this, NULL, 857, v900, y, v899, -1, (int)&v1884, 3);
              */
            }
            return;
          case 608:
            sub10func();
            sub_46AB50(2, 2);
            if ( get_subseq() == 2 && get_elaps_frames() >= 32 )
              goto LABEL_2148;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(13);
              //v918 = 0;
              field_190 = 1;
              /*
              v1488 = 0;
              do
              {
                v1896 = (double)v1488;
                v1897 = 600.0;
                v1898 = 1.0;
                v919 = enemy;
                v920 = v919->y + 100.0;
                addbullet(this, NULL, 858, v919->x, v920, dir, 1, (int)&v1896, 3);
                v918 += 40;
                v1488 = v918;
              }
              while ( v918 < 360 );
              */
            }
            if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 150.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
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
LABEL_239:
                reset_forces();
                y = getlvl_height();
                set_subseq(4);
                return;
              }
            }
            if ( get_subseq() == 1 && get_elaps_frames() >= 48 )
              goto LABEL_170;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              /*
              v1860 = 0.0;
              v1861 = 0.0;
              v1862 = 4.0;
              v819 = dir;
              v820 = y + 146.0;
              v821 = v820;
              v822 = (double)(105 * (char)v819) + x;
              addbullet(this, NULL, 851, v822, v821, v819, 1, (int)&v1860, 3);
              */
              play_sfx(51);
            }
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 2 )
              {
                field_7DC = h_inerc;
                dash_angle = v_inerc;
                reset_forces();
                sub_4834E0(40);
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
LABEL_1387:
                reset_forces();
                goto LABEL_1388;
              }
            }
            if ( get_subseq() != 1 )
              goto LABEL_2806;
            if ( !(get_elaps_frames() % 15) && field_7D0 <= 3 )
            {
              /*
              v902 = (double)(unsigned int)get_MT_range(125) + 50.0;
              v903 = (double)field_7D0 * 60.0 + 100.0;
              v1788 = 5.0 - (double)(unsigned int)get_MT_range(10);
              v1789 = 35.0;
              v1790 = 12.0;
              v904 = dir;
              v905 = v903 + y;
              v906 = v905;
              v907 = (double)(char)v904 * v902 + x;
              addbullet(this, NULL, 857, v907, v906, v904, -1, (int)&v1788, 3);
              v908 = dir;
              v909 = v903 + y;
              v910 = v909;
              v911 = x - (double)(char)v908 * v902;
              addbullet(this, NULL, 857, v911, v910, v908, 1, (int)&v1788, 3);
              */
              play_sfx(16);
              ++field_7D0;
            }
            if ( get_elaps_frames() < 60 )
            {
LABEL_2806:
              if ( get_subseq() != 2 || get_elaps_frames() < 0 )
              {
                if (process() )
                  set_seq(0);
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                  //get_elaps_frames() = 0;
                if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
                {
                  sub_4834E0(40);
                  scene_play_sfx(23);
                  scene_add_effect(this, 115, x - (double)(40 * (char)dir), y + 153.0, dir, 1);
                  sub_469450(0, 0, 60);
                  sub_483570();
                  weather_forecast_next();
                  /*
                  v1890 = 0.0;
                  v1891 = 0.0;
                  v1892 = 14.0;
                  v916 = dir;
                  v917 = x - (double)(20 * (char)v916);
                  addbullet(this, NULL, 857, v917, y, v916, -1, (int)&v1890, 3);
                  */
                }
                if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 2 )
                  v_force = 0.25;
                return;
              }
            }
            goto LABEL_2148;
          case 695:
            sub10func();
            if (process() )
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
            if (process() )
              set_seq(0);
            if ( get_subseq() )
              return;
            if ( !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                /*
                v1902 = 0.0;
                v1903 = 0.0;
                v1904 = 4.0;
                addbullet(this, NULL, 848, x, y, dir, 1, (int)&v1902, 3);
                */
                h_inerc = 10.0;
                field_49A = 0;
              }
              if ( !get_frame_time() && get_frame() == 5 )
                play_sfx(0);
            }
            if ( get_frame() < 6 )
              return;
            v399 = h_inerc - 1.200000047683716;
            goto LABEL_1119;
          case 707:
            if ( h_inerc > 12.0 )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc < 12.0 )
                h_inerc = 12.0;
            }
            if (process() )
              goto LABEL_2787;
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
                goto LABEL_170;
            }
            if ( get_subseq() == 2 )
            {
              v399 = h_inerc - 0.5;
LABEL_1119:
              h_inerc = v399;
              if ( v399 < 0.0 )
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
            if (process() )
              goto LABEL_2787;
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
                goto LABEL_2138;
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
            if ( get_subseq() == 2 || get_subseq() == 3 )
            {
              v_inerc = v_inerc - 0.25;
              if ( getlvl_height() >= (v_inerc + y) && v_inerc < 0.0 )
              {
                reset_forces();
                y = getlvl_height();
                goto LABEL_2148;
              }
            }
            if (process() )
              set_seq(700);
            return;
          case 710:
            if ( get_subseq() <= 2 || get_subseq() == 5 || get_subseq() == 6 || get_subseq() == 8 || get_subseq() == 10 )
              sub10func();
            if ( !get_subseq() && !(get_elaps_frames() % 2) )
            {
              /*
              v1632 = (double)(unsigned int)get_MT_range(360);
              v1633 = (double)(unsigned int)get_MT_range(400) + 200.0;
              v1634 = (double)((unsigned int)get_MT_range(100) >= 0x32);
              v957 = dir;
              v958 = -v1632;
              v959 = sin_deg(v958);
              v960 = v959 * v1633 + y - (double)get_pframe()->extra_24byte[5];
              v961 = v960;
              v962 = -v1632;
              v963 = cos_deg(v962);
              v964 = (v963 * v1633 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
              addbullet(this, NULL, 970, v964, v961, v957, 1, (int)&v1632, 3);
              */
            }
            if ( get_subseq() == 1 )
            {
              /*
              if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
              {
                v1689 = (double)(unsigned int)get_MT_range(360);
                v1690 = (double)(unsigned int)get_MT_range(400) + 200.0;
                v1691 = (double)((unsigned int)get_MT_range(100) >= 0x32);
                v965 = dir;
                v966 = -v1689;
                v967 = sin_deg(v966);
                v968 = v967 * v1690 + y - (double)get_pframe()->extra_24byte[5];
                v969 = v968;
                v970 = -v1689;
                v971 = cos_deg(v970);
                v972 = (v971 * v1690 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
                addbullet(this, NULL, 970, v972, v969, v965, 1, (int)&v1689, 3);
              }
              */
              if ( get_elaps_frames() >= field_7D0 )
                goto LABEL_2165;
            }
            if ( get_subseq() == 3 )
            {
              v_inerc = v_inerc - 0.2000000029802322;
              if ( v_inerc < 0.0 )
                h_inerc = 0.0;
              h_inerc = h_inerc * 0.9599999785423279;
              if ( get_elaps_frames() >= field_7D0 )
              {
                field_190 = 0;
                field_194 = 1;
                v_inerc = -25.0;
                play_sfx(2);
                if ( settings_get()->get_difficulty() == 2 )
                  goto LABEL_2385;
                if ( settings_get()->get_difficulty() == 3 )
                {
                  set_subseq(9);
                  return;
                }
                goto LABEL_171;
              }
            }
            if ( get_subseq() == 4 || get_subseq() == 7 || get_subseq() == 9 )
            {
              v_inerc = v_inerc - 1.25;
              if ( char_on_ground_down() )
              {
                play_sfx(1);
                y = getlvl_height();
                reset_forces();
                /*
                v1515 = 0.0;
                do
                {
                  v1535 = (double)(unsigned int)get_MT_range(10) + v1515 * 18.0;
                  v1536 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
                  v1537 = 0.0;
                  v975 = -v1535;
                  v976 = (1 - 2 * (sin_deg(v975) > 0.0));
                  v977 = dir;
                  v978 = -v1535;
                  v979 = sin_deg(v978) * 20.0 + y;
                  v980 = v979;
                  v981 = -v1535;
                  v982 = cos_deg(v981) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 971, v982, v980, v977, v976, (int)&v1535, 3);
                  v1515 = v1515 + 1.0;
                }
                while ( v1515 < 20.0 );
                v1536 = 0.40000001;
                v1537 = 0.0;
                addbullet(this, NULL, 900, x, y, dir, 1, (int)&v1535, 3);
                v1536 = 0.30000001;
                v1537 = 1.0;
                addbullet(this, NULL, 900, x, y, dir, -1, (int)&v1535, 3);
                v1516 = 0.0;
                if ( field_7DC > 0.0 )
                {
                  do
                  {
                    v1535 = -(double)(unsigned int)get_MT_range(140) - 20.0;
                    v1536 = (double)(unsigned int)get_MT_range(80) * 0.1000000014901161 + 10.0;
                    if ( settings_get()->get_difficulty() == 2 )
                      v1536 = (double)(unsigned int)get_MT_range(100) * 0.1000000014901161 + 10.0;
                    if ( settings_get()->get_difficulty() == 3 )
                      v1536 = (double)(unsigned int)get_MT_range(120) * 0.1000000014901161 + 10.0;
                    v1537 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 4.0;
                    v983 = dir;
                    v984 = -v1535;
                    v985 = sin_deg(v984) * 20.0 + y;
                    v986 = v985;
                    v987 = -v1535;
                    v988 = cos_deg(v987) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 900, v988, v986, v983, 1, (int)&v1535, 3);
                    v1516 = v1516 + 1.0;
                  }
                  while ( field_7DC > (double)v1516 );
                }
                v989 = 12;
                do
                {
                  v1535 = -10.0 - (double)(unsigned int)get_MT_range(160);
                  v1536 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
                  v1537 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 2.0;
                  v990 = dir;
                  v991 = -v1535;
                  v992 = sin_deg(v991) * 20.0 + y;
                  v993 = v992;
                  v994 = -v1535;
                  v995 = cos_deg(v994) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 900, v995, v993, v990, 1, (int)&v1535, 3);
                  --v989;
                }
                while ( v989 );
                */
                goto LABEL_2187;
              }
            }
            if ( get_subseq() == 6 && get_elaps_frames() >= 60 )
              goto LABEL_92;
            if (process() )
              set_subseq(6);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 7 )
                set_seq(0);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 9 )
                  set_subseq(6);
                if ( !get_elaps_frames() )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  {
                    switch ( settings_get()->get_difficulty() )
                    {
                      case 0:
                        v996 = 0.0;
                        field_7D0 = 120;
                        field_7D2 = 180;
                        goto LABEL_2212;
                      case 1:
                        v996 = 3.0;
                        field_7D0 = 90;
                        field_7D2 = 150;
                        goto LABEL_2212;
                      case 2:
                        v996 = 10.0;
                        field_7D0 = 90;
                        field_7D2 = 150;
                        goto LABEL_2212;
                      case 3:
                        v996 = 20.0;
                        field_7D0 = 60;
                        field_7D2 = 120;
LABEL_2212:
                        field_7DC = v996;
                        break;
                      default:
                        break;
                    }
                  }
                  if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                  {
                    v_inerc = 15.0;
                    h_inerc = /*(double)(unsigned int)get_MT_range(250)*/250.0 * 0.1000000014901161 + 12.5;
                  }
                }
              }
            }
            return;
          case 720:
            has_shadow = getlvl_height() <= y;
            if ( get_subseq() == 3 )
            {
              v_inerc = v_inerc - 0.2000000029802322;
              if ( !field_7D0 && v_inerc < 0.0 )
              {
                //sub_465E50(995);
                //field_154->field_F8 = 20.0;
                //field_154->field_FC = 20.0;
                //field_154->field_E8 = x;
                //field_154->field_EC = getlvl_height();
                //field_154->field_104 = dir; //LOBYTE(//field_154->field_104) = dir;
                field_7D0 = 1;
              }
              if ( field_7D0 == 1 )
              {
                if ( getlvl_height() >= y )
                {
                  field_51C = 180;
                  field_520 = 180;
                  ++field_7D0;
                  /*
                  v1908 = 0.0;
                  v1909 = 0.0;
                  v1910 = 1.0;
                  addbullet(this, NULL, 910, x, y, dir, 1, (int)&v1908, 3);
                  */
                  play_sfx(3);
                }
              }
              if ( field_7D0 >= 2 && y <= -320.0 )
              {
                set_subseq(4);
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                    field_7D0 = 180;
                    field_7D2 = 60;
                    field_7D4 = 120;
                    goto LABEL_2235;
                  case 1:
                    field_7D0 = 120;
                    field_7D2 = 60;
                    field_7D4 = 180;
                    goto LABEL_2235;
                  case 2:
                    field_7D0 = 90;
                    field_7D2 = 50;
                    field_7D4 = 210;
                    goto LABEL_2235;
                  case 3:
                    field_7D0 = 60;
                    field_7D2 = 40;
                    field_7D4 = 240;
LABEL_2235:
                    field_7D6 = 3.0;//get_MT_range(3);
                    break;
                  default:
                    break;
                }
LABEL_1388:
                y = getlvl_height();
                return;
              }
            }
            if ( get_subseq() == 4 )
            {
              v_inerc = 0.0;
              if ( --field_7D2 <= 0 )
              {
                switch ( field_7D6 )
                {
                  case 0:
                    next_subseq();
                    switch ( settings_get()->get_difficulty() )
                    {
                      case 0:
                        field_7D0 = 1;
                        field_7D2 = 6;
                        field_7D4 = 180;
                        field_7D6 = 60;
                        return;
                      case 1:
                        field_7D0 = 2;
                        field_7D2 = 8;
                        goto LABEL_2242;
                      case 2:
                        field_7D0 = 2;
                        goto LABEL_2241;
                      case 3:
                        field_7D0 = 3;
LABEL_2241:
                        field_7D2 = 10;
LABEL_2242:
                        field_7D4 = 180;
                        field_7D6 = 50;
                        break;
                      default:
                        return;
                    }
                    return;
                  case 1:
                    set_subseq(9);
                    y = getlvl_height() - 340.0;
                    //sub_465E50(995);
                    //field_154->field_F8 = 20.0;
                    //field_154->field_FC = 20.0;
                    //field_154->field_E8 = x;
                    //field_154->field_EC = getlvl_height();
                    //field_154->field_104 = dir;//LOBYTE(//field_154->field_104) = dir;
                    switch ( settings_get()->get_difficulty() )
                    {
                      case 0:
                        field_7D0 = 1;
                        field_7D2 = 3;
                        goto LABEL_2252;
                      case 1:
                        field_7D0 = 2;
                        field_7D2 = 5;
                        field_7D4 = 40;
                        field_7D6 = 0;
                        break;
                      case 2:
                        field_7D0 = 2;
                        field_7D2 = 8;
                        field_7D4 = 30;
                        field_7D6 = 0;
                        break;
                      case 3:
                        field_7D0 = 3;
                        field_7D2 = 10;
LABEL_2252:
                        field_7D4 = 20;
                        field_7D6 = 0;
                        break;
                      default:
                        return;
                    }
                    return;
                  case 2:
                    switch ( settings_get()->get_difficulty() )
                    {
                      case 0:
                        field_7D0 = 0;
                        field_7D2 = 3;
                        goto LABEL_2259;
                      case 1:
                        field_7D0 = 0;
                        field_7D2 = 5;
                        goto LABEL_2259;
                      case 2:
                        field_7D0 = 1;
                        field_7D2 = 8;
LABEL_2259:
                        field_7D4 = 60;
                        goto LABEL_2260;
                      case 3:
                        field_7D0 = 2;
                        field_7D2 = 10;
                        field_7D4 = 40;
LABEL_2260:
                        field_7D6 = 0;
                        break;
                      default:
                        break;
                    }
                    set_subseq(8);
                    field_194 = 1;
                    field_190 = 0;
                    flip_with_force();
                    return;
                }
              }
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            {
              /*
              v1638 = 0.0;
              v1639 = 0.0;
              v1640 = 1.0;
              v1002 = dir;
              v1003 = getlvl_height();
              addbullet(this, NULL, 910, x, v1003, v1002, 1, (int)&v1638, 3);
              v1638 = 0.0;
              v1639 = 0.0;
              v1640 = 5.0;
              v1004 = dir;
              v1005 = getlvl_height();
              addbullet(this, NULL, 910, x, v1005, v1004, 1, (int)&v1638, 3);
              */
            }
            if ( get_subseq() == 5 )
            {
              h_inerc = h_inerc - 0.2000000029802322;
              if ( h_inerc < 3.0 )
                h_inerc = 3.0;
            }
            if ( get_subseq() == 6 )
            {
              v_inerc = 0.0;
              if ( get_elaps_frames() % field_7D6 == 1 && field_7D0 > 0 )
              {
                play_sfx(3);
                /*v1007 = 0;
                if ( field_7D2 > 0 )
                {
                  do
                  {
                    v1731 = -(double)(unsigned int)get_MT_range(80) - 95.0;
                    v1732 = (double)(unsigned int)get_MT_range(100) * 0.1000000014901161 + 10.0;
                    v1733 = 4.0;
                    v1008 = -v1731;
                    v1009 = sin_deg(v1008);
                    v1010 = dir;
                    v1011 = getlvl_height() + v1009 * 20.0;
                    v1012 = v1011;
                    v1013 = -v1731;
                    v1014 = cos_deg(v1013) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 910, v1014, v1012, v1010, 1, (int)&v1731, 3);
                    ++v1007;
                  }
                  while ( v1007 < field_7D2 );
                }
                */
                --field_7D0;
              }
              if ( field_7D4 <= 0 )
              {
                if ( field_7D0 <= 0 )
                  goto LABEL_170;
                field_7D0 = field_7D0 - 1;
              }
              else
              {
                field_7D4 = field_7D4 - 1;
              }
            }
            if ( get_subseq() == 7 )
            {
              h_inerc = h_inerc + 0.2000000029802322;
              if ( h_inerc > 6.0 )
                h_inerc = 6.0;
            }
            if ( get_subseq() != 8 )
              goto LABEL_2309;
            v_inerc = 0.0;
            if ( get_frame() < 4 )
            {
              h_inerc = h_inerc + 0.5;
              if ( h_inerc >= 12.5 )
                h_inerc = 12.5;
            }
            else
            {
              h_inerc = h_inerc - 0.25;
              if ( h_inerc < 0.0 )
                h_inerc = 0.0;
            }
            if ( !get_frame_time() && get_frame() == 1 )
            {
              /*
              v1914 = 0.0;
              v1915 = 0.0;
              v1916 = 1.0;
              addbullet(this, NULL, 910, x, y, dir, 1, (int)&v1914, 3);
              */
              play_sfx(3);
            }
            if ( get_frame_time() )
              goto LABEL_2298;
            if ( get_frame() == 2 )
            {
              field_194 = 1;
              field_190 = 0;
            }
            if ( get_frame_time() )
              goto LABEL_2298;
            if ( get_frame() == 9 )
            {
              flip_with_force();
LABEL_2298:
              if ( get_frame() == 9 )
              {
                h_inerc = h_inerc + 0.5;
                if ( h_inerc >= 12.5 )
                  h_inerc = 12.5;
                if ( ++field_7D6 > field_7D4 )
                {
                  if ( field_7D0 <= 0 )
                  {
                    h_inerc = 6.0;
                    set_subseq(4);
                    y = getlvl_height();
                    switch ( settings_get()->get_difficulty() )
                    {
                      case 0:
                        goto LABEL_2307;
                      case 1:
                        goto LABEL_2306;
                      case 2:
                        goto LABEL_2318;
                      case 3:
                        goto LABEL_2305;
                      default:
                        return;
                    }
                  }
                  else
                  {
                    field_7D0 = field_7D0 - 1;
                    set_subseq(8);
                    field_7D6 = 0;
                  }
                  return;
                }
              }
            }
LABEL_2309:
            if ( get_subseq() == 9 )
            {
              //field_154->field_E8 = x;
              if ( getlvl_height() >= y )
              {
                field_51C = 3;
                field_520 = 3;
              }
              if ( getlvl_height() - 340.0 >= y )
              {
                y = getlvl_height() - 340.0;
                v_inerc = 0.0;
                if ( ++field_7D6 >= field_7D4 )
                {
                  if ( field_7D0 <= 0 )
                  {
                    set_subseq(4);
                    y = getlvl_height();
                    //sub_5586E0();
                    switch ( settings_get()->get_difficulty() )
                    {
                      case 0:
LABEL_2307:
                        field_7D0 = 180;
                        field_7D2 = 60;
                        field_7D4 = 120;
                        goto LABEL_2308;
                      case 1:
LABEL_2306:
                        field_7D0 = 120;
                        field_7D2 = 60;
                        field_7D4 = 180;
                        goto LABEL_2308;
                      case 2:
LABEL_2318:
                        field_7D0 = 90;
                        field_7D2 = 50;
                        field_7D4 = 210;
                        goto LABEL_2308;
                      case 3:
LABEL_2305:
                        field_7D0 = 60;
                        field_7D2 = 40;
                        field_7D4 = 240;
LABEL_2308:
                        field_7D6 = 3.0;//get_MT_range(3);
                        break;
                      default:
                        return;
                    }
                    return;
                  }
                  play_sfx(3);
                  /*
                  v1920 = 0.0;
                  v1921 = 0.0;
                  v1922 = 1.0;
                  v1026 = dir;
                  v1027 = getlvl_height();
                  addbullet(this, NULL, 910, x, v1027, v1026, 1, (int)&v1920, 3);
                  */
                  --field_7D0;
                  field_7D8 = 0;
                  v_inerc = 15.0;
                  v_force = 0.25;
                  if ( field_7D0 <= 0 )
                  {
                    v_inerc = 20.0;
                    v_force = 0.25;
                  }
                }
              }
              if ( field_7D6 >= field_7D4 )
              {
                v_inerc = v_inerc - v_force;
                if ( !field_7D8 && v_inerc < 0.0 )
                {
                  if ( getlvl_height() >= y )
                  {
                    play_sfx(3);
                    /*
                    v1562 = 0.0;
                    v1563 = 0.0;
                    v1564 = 1.0;
                    v1031 = dir;
                    v1032 = getlvl_height();
                    addbullet(this, NULL, 910, x, v1032, v1031, 1, (int)&v1562, 3);
                    v1033 = 0;
                    field_7D8 = 1;
                    if ( field_7D0 <= 0 )
                    {
                      if ( 2 * field_7D2 > 0 )
                      {
                        do
                        {
                          v1562 = -(double)(unsigned int)get_MT_range(20) - 80.0;
                          v1563 = (double)(unsigned int)get_MT_range(150) * 0.1000000014901161 + 9.0;
                          v1564 = 4.0;
                          v1041 = -v1562;
                          v1042 = sin_deg(v1041);
                          v1043 = dir;
                          v1044 = getlvl_height() + v1042 * 20.0;
                          v1045 = v1044;
                          v1046 = -v1562;
                          v1047 = cos_deg(v1046) * 100.0 * (double)dir + x;
                          addbullet(this, NULL, 910, v1047, v1045, v1043, 1, (int)&v1562, 3);
                          ++v1033;
                        }
                        while ( v1033 < 2 * field_7D2 );
                      }
                    }
                    else if ( field_7D2 > 0 )
                    {
                      do
                      {
                        v1562 = -(double)(unsigned int)get_MT_range(20) - 80.0;
                        v1563 = (double)(unsigned int)get_MT_range(150) * 0.1000000014901161 + 6.0;
                        v1564 = 4.0;
                        v1034 = -v1562;
                        v1035 = sin_deg(v1034);
                        v1036 = dir;
                        v1037 = getlvl_height() + v1035 * 20.0;
                        v1038 = v1037;
                        v1039 = -v1562;
                        v1040 = cos_deg(v1039) * 100.0 * (double)dir + x;
                        addbullet(this, NULL, 910, v1040, v1038, v1036, 1, (int)&v1562, 3);
                        ++v1033;
                      }
                      while ( v1033 < field_7D2 );
                    }
                    */
                  }
                }
              }
            }
            if ( h_inerc > 0.0 && dir == 1 && x > 1480.0 )
              dir = -1;
            if ( h_inerc > 0.0 && dir == -1 && x < -200.0 )
              dir = 1;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                field_7D0 = 0;
                field_572 = 0;
                field_571 = 0;
                v_inerc = 7.5;
                v_force = 0.5;
                h_inerc = 6.0;
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 8 )
              {
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                    field_7D0 = 180;
                    field_7D2 = 45;
                    field_7D4 = 120;
                    goto LABEL_2353;
                  case 1:
                    field_7D0 = 120;
                    field_7D2 = 30;
                    field_7D4 = 180;
                    goto LABEL_2353;
                  case 2:
                    field_7D0 = 90;
                    field_7D2 = 20;
                    field_7D4 = 210;
                    goto LABEL_2353;
                  case 3:
                    field_7D0 = 60;
                    field_7D2 = 20;
                    field_7D4 = 240;
LABEL_2353:
                    field_7D6 = 3.0;//get_MT_range(3);
                    break;
                  default:
                    break;
                }
                set_subseq(4);
              }
            }
            return;
          case 730:
            if ( !get_subseq() && !(get_elaps_frames() % 2) )
            {
              /*
              v1683 = (double)(unsigned int)get_MT_range(360);
              v1684 = (double)(unsigned int)get_MT_range(400) + 200.0;
              v1685 = (double)((unsigned int)get_MT_range(100) >= 0x32);
              v1048 = dir;
              v1049 = -v1683;
              v1050 = sin_deg(v1049);
              v1051 = v1050 * v1684 + y - (double)get_pframe()->extra_24byte[5];
              v1052 = v1051;
              v1053 = -v1683;
              v1054 = cos_deg(v1053);
              v1055 = (v1054 * v1684 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
              addbullet(this, NULL, 970, v1055, v1052, v1048, 1, (int)&v1683, 3);
              */
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
              {
                /*
                v1644 = (double)(unsigned int)get_MT_range(360);
                v1645 = (double)(unsigned int)get_MT_range(400) + 200.0;
                v1646 = (double)((unsigned int)get_MT_range(100) >= 0x32);
                v1056 = dir;
                v1057 = -v1644;
                v1058 = sin_deg(v1057);
                v1059 = v1058 * v1645 + y - (double)get_pframe()->extra_24byte[5];
                v1060 = v1059;
                v1061 = -v1644;
                v1062 = cos_deg(v1061);
                v1063 = (v1062 * v1645 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
                addbullet(this, NULL, 970, v1063, v1060, v1056, 1, (int)&v1644, 3);
                */
              }
              if ( get_elaps_frames() >= field_7D0 )
              {
LABEL_2165:
                next_subseq();
                flip_with_force();
                return;
              }
            }
            if ( get_subseq() != 3 )
              goto LABEL_2807;
            if ( !get_frame() && !get_frame_time() )
              field_190 = 0;
            if ( (dir != 1 || get_border_near() != -1) && (dir != -1 || get_border_near() != 1) )
            {
LABEL_2807:
              if ( get_subseq() == 4 )
              {
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                {
                  y = getlvl_height();
                  play_sfx(0);
                  field_7DC = h_inerc;
                  dash_angle = v_inerc;
                  reset_forces();
                  //shake_camera(10.0);
                  /*
                  v1518 = 0.0;
                  do
                  {
                    v1719 = (double)(unsigned int)get_MT_range(10) + v1518 * 24.0;
                    v1720 = (double)(unsigned int)get_MT_range(20) * 0.1000000014901161 + 10.0;
                    v1721 = 0.0;
                    v1074 = -v1719;
                    v1075 = (1 - 2 * (sin_deg(v1074) > 0.0));
                    v1076 = dir;
                    v1077 = -v1719;
                    v1078 = sin_deg(v1077) * 20.0 + y;
                    v1079 = v1078;
                    v1080 = -v1719;
                    v1081 = cos_deg(v1080) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 971, v1081, v1079, v1076, v1075, (int)&v1719, 3);
                    v1518 = v1518 + 1.0;
                  }
                  while ( v1518 < 15.0 );
                  */
                  set_subseq(5);
                  return;
                }
              }
              if ( get_subseq() != 6 )
                goto LABEL_2808;
              v_inerc = v_inerc - 0.2000000029802322;
              h_inerc = h_inerc + 0.1000000014901161;
              if ( h_inerc > 0.0 )
                h_inerc = 0.0;
              if ( char_on_ground_down() )
              {
                y = getlvl_height();
                play_sfx(0);
                reset_forces();
                //shake_camera(2.0);
LABEL_2385:
                set_subseq(7);
              }
              else
              {
LABEL_2808:
                if ( get_subseq() == 8 && get_elaps_frames() >= field_7D2 )
                  goto LABEL_170;
                if (process() )
                  set_seq(0);
                if ( !get_elaps_frames() )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  {
                    switch ( settings_get()->get_difficulty() )
                    {
                      case 0:
                        field_7D0 = 150;
                        field_7D2 = 180;
                        field_7E4 = 10.0;
                        field_7E8 = 4.0;
                        field_7D6 = 40;
                        field_7EC = 27.5;
                        field_194 = 2;
                        break;
                      case 1:
                        field_7D0 = 90;
                        field_7D2 = 120;
                        field_7E4 = 20.0;
                        field_7E8 = 3.0;
                        field_7D6 = 100;
                        field_7EC = 30.0;
                        field_194 = 4;
                        break;
                      case 2:
                        field_7D0 = 60;
                        field_7D2 = 90;
                        field_7E4 = 30.0;
                        field_7E8 = 2.0;
                        field_7D6 = 160;
                        field_7EC = 32.5;
                        field_194 = 5;
                        break;
                      case 3:
                        field_7D0 = 40;
                        field_7D2 = 60;
                        field_7E4 = 40.0;
                        field_7E8 = 1.0;
                        field_7D6 = 180;
                        field_7EC = 35.0;
                        field_194 = 6;
                        break;
                      default:
                        break;
                    }
                  }
                  if ( !get_elaps_frames() )
                  {
                    if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
                      h_inerc = /*(double)(unsigned int)get_MT_range(50)*/50.0 * 0.1000000014901161 + field_7EC;
                    if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
                    {
                      h_inerc = field_7DC * 0.2000000029802322;
                      v_inerc = 0.2000000029802322 * -dash_angle;
                      v_force = 0.2;
                    }
                  }
                }
              }
            }
            else
            {
              play_sfx(1);
              //shake_camera(10.0);
              h_inerc = -3.0;
              v_inerc = 10.0;
              v_force = 0.2;
              next_subseq();
              if ( field_7E4 > 0.0 )
              {
                /*
                v1517 = 0.0;
                if ( field_7E4 > 0.0 )
                {
                  do
                  {
                    v1695 = (double)(unsigned int)get_MT_range(110) - 190.0;
                    v1696 = (double)(unsigned int)get_MT_range(field_7D6) * 0.1000000014901161 + field_7E8;
                    v1697 = 0.0;
                    v1066 = dir;
                    v1067 = -v1695;
                    v1068 = sin_deg(v1067);
                    v1069 = v1068 * (v1696 * 10.0) + y;
                    v1070 = v1069;
                    v1071 = -v1695;
                    v1072 = cos_deg(v1071);
                    v1073 = v1072 * (v1696 * 10.0) * (double)dir + x;
                    addbullet(this, NULL, 920, v1073, v1070, v1066, 1, (int)&v1695, 3);
                    v1517 = v1517 + 1.0;
                  }
                  while ( field_7E4 > (double)v1517 );
                }
                */
              }
            }
            return;
          case 731:
            if ( get_subseq() <= 2 || get_subseq() >= 5 )
              sub10func();
            if ( !get_subseq() && !(get_elaps_frames() % 2) )
            {
              /*
              v1650 = (double)(unsigned int)get_MT_range(360);
              v1651 = (double)(unsigned int)get_MT_range(400) + 200.0;
              v1652 = (double)((unsigned int)get_MT_range(100) >= 0x32);
              v1084 = dir;
              v1085 = -v1650;
              v1086 = sin_deg(v1085);
              v1087 = v1086 * v1651 + y - (double)get_pframe()->extra_24byte[5];
              v1088 = v1087;
              v1089 = -v1650;
              v1090 = cos_deg(v1089);
              v1091 = (v1090 * v1651 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
              addbullet(this, NULL, 970, v1091, v1088, v1084, 1, (int)&v1650, 3);
              */
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
              {
                /*
                v1677 = (double)(unsigned int)get_MT_range(360);
                v1678 = (double)(unsigned int)get_MT_range(400) + 200.0;
                v1679 = (double)((unsigned int)get_MT_range(100) >= 0x32);
                v1092 = dir;
                v1093 = -v1677;
                v1094 = sin_deg(v1093);
                v1095 = v1094 * v1678 + y - (double)get_pframe()->extra_24byte[5];
                v1096 = v1095;
                v1097 = -v1677;
                v1098 = cos_deg(v1097);
                v1099 = (v1098 * v1678 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
                addbullet(this, NULL, 970, v1099, v1096, v1092, 1, (int)&v1677, 3);
                */
              }
              if ( get_elaps_frames() >= field_7D0 )
                goto LABEL_2420;
            }
            if ( get_subseq() == 3 )
            {
              v_inerc = v_inerc - v_force;
              if ( v_inerc < 0.0 )
                goto LABEL_2148;
            }
            if ( get_subseq() == 4 )
            {
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                play_sfx(1);
                y = getlvl_height();
                reset_forces();
                /*
                v1519 = 0.0;
                do
                {
                  v1550 = (double)(unsigned int)get_MT_range(10) + v1519 * 18.0;
                  v1551 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
                  v1552 = 0.0;
                  v1101 = -v1550;
                  v1102 = (1 - 2 * (sin_deg(v1101) > 0.0));
                  v1103 = dir;
                  v1104 = -v1550;
                  v1105 = sin_deg(v1104) * 20.0 + y;
                  v1106 = v1105;
                  v1107 = -v1550;
                  v1108 = cos_deg(v1107) * 100.0 * (double)dir + x;
                  addbullet(this, NULL, 971, v1108, v1106, v1103, v1102, (int)&v1550, 3);
                  v1519 = v1519 + 1.0;
                }
                while ( v1519 < 20.0 );
                v1551 = 0.40000001;
                v1552 = 0.0;
                addbullet(this, NULL, 900, x, y, dir, 1, (int)&v1550, 3);
                v1551 = 0.30000001;
                v1552 = 1.0;
                addbullet(this, NULL, 900, x, y, dir, -1, (int)&v1550, 3);
                if ( field_7E4 > 0.0 )
                {
                  v1520 = 0.0;
                  if ( field_7E4 > 0.0 )
                  {
                    do
                    {
                      v1550 = -(double)(unsigned int)get_MT_range(180);
                      v1551 = (double)(unsigned int)get_MT_range(field_7D6) * 0.1000000014901161 + field_7E8;
                      v1552 = 0.0;
                      v1109 = dir;
                      v1110 = -v1550;
                      v1111 = sin_deg(v1110);
                      v1112 = v1111 * (v1551 * 10.0) + y;
                      v1113 = v1112;
                      v1114 = -v1550;
                      v1115 = cos_deg(v1114);
                      v1116 = v1115 * (v1551 * 10.0) * (double)dir + x;
                      addbullet(this, NULL, 920, v1116, v1113, v1109, 1, (int)&v1550, 3);
                      v1520 = v1520 + 1.0;
                    }
                    while ( field_7E4 > (double)v1520 );
                  }
                }
                */
LABEL_2187:
                next_subseq();
                goto LABEL_2188;
              }
            }
            if ( get_subseq() == 6 && get_elaps_frames() >= 60 )
              goto LABEL_92;
            if (process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                    field_7D0 = 120;
                    field_7D2 = 180;
                    field_7E4 = 15.0;
                    dash_angle = 45.0;
                    field_7E8 = 4.0;
                    field_7D6 = 40;
                    goto LABEL_2445;
                  case 1:
                    field_7D0 = 90;
                    field_7D2 = 150;
                    field_7E4 = 25.0;
                    dash_angle = 45.0;
                    field_7E8 = 3.0;
                    field_7D6 = 100;
LABEL_2445:
                    field_194 = 0;
                    goto LABEL_2446;
                  case 2:
                    field_7D0 = 90;
                    field_7D2 = 150;
                    field_7E4 = 40.0;
                    dash_angle = 45.0;
                    field_7E8 = 2.0;
                    field_7D6 = 160;
                    field_194 = 1;
                    goto LABEL_2446;
                  case 3:
                    field_7D0 = 60;
                    field_7D2 = 120;
                    field_7E4 = 50.0;
                    dash_angle = 45.0;
                    field_7E8 = 1.0;
                    field_7D6 = 180;
                    field_194 = 1;
LABEL_2446:
                    field_190 = 0;
                    break;
                  default:
                    break;
                }
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                v_inerc = dash_angle;
                h_inerc = 0.0;
                v_force = 1.0;
              }
            }
            return;
          case 740:
            if ( !get_subseq() && !(get_elaps_frames() % 2) )
            {
              /*
              v1656 = (double)(unsigned int)get_MT_range(360);
              v1657 = (double)(unsigned int)get_MT_range(400) + 200.0;
              v1658 = (double)((unsigned int)get_MT_range(100) >= 0x32);
              v1117 = dir;
              v1118 = -v1656;
              v1119 = sin_deg(v1118);
              v1120 = v1119 * v1657 + y - (double)get_pframe()->extra_24byte[5];
              v1121 = v1120;
              v1122 = -v1656;
              v1123 = cos_deg(v1122);
              v1124 = (v1123 * v1657 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
              addbullet(this, NULL, 970, v1124, v1121, v1117, 1, (int)&v1656, 3);
              */
            }
            if ( get_subseq() == 1 )
            {
              if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
              {
                /*
                v1590 = (double)(unsigned int)get_MT_range(360);
                v1591 = (double)(unsigned int)get_MT_range(400) + 200.0;
                v1592 = (double)((unsigned int)get_MT_range(100) >= 0x32);
                v1125 = dir;
                v1126 = -v1590;
                v1127 = sin_deg(v1126);
                v1128 = v1127 * v1591 + y - (double)get_pframe()->extra_24byte[5];
                v1129 = v1128;
                v1130 = -v1590;
                v1131 = cos_deg(v1130);
                v1132 = (v1131 * v1591 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
                addbullet(this, NULL, 970, v1132, v1129, v1125, 1, (int)&v1590, 3);
                */
              }
              if ( get_elaps_frames() >= field_7D0 )
                goto LABEL_2420;
            }
            /*
            v1135 = __OFSUB__(get_subseq(), 3);
            v1133 = get_subseq() == 3;
            v1134 = (get_subseq() - 3) < 0;
            */
            if ( get_subseq() != 3 )
              goto LABEL_2475;
            if ( field_7DC > 0.0 )
            {
              /*
              if ( !(get_elaps_frames() % 2) && get_elaps_frames() >= field_7D2 - 120 )
              {
                v1593 = (double)(unsigned int)get_MT_range(360);
                v1594 = (double)(unsigned int)get_MT_range(400) + 200.0;
                v1595 = (double)((unsigned int)get_MT_range(100) >= 0x32);
                v1136 = dir;
                v1137 = -v1593;
                v1138 = sin_deg(v1137);
                v1139 = v1138 * v1594 + y - (double)get_pframe()->extra_24byte[5];
                v1140 = v1139;
                v1141 = -v1593;
                v1142 = cos_deg(v1141);
                v1143 = (v1142 * v1594 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
                addbullet(this, NULL, 970, v1143, v1140, v1136, 1, (int)&v1593, 3);
              }
              if ( !(get_elaps_frames() % field_7D4) && get_elaps_frames() <= field_7D2 - 120 )
              {
                v1763 = (double)(unsigned int)get_MT_range(360);
                v1764 = 7.5;
                v1765 = 6.0;
                v1766 = dash_angle;
                v1144 = dir;
                v1145 = -v1763;
                v1146 = sin_deg(v1145) * 300.0 + y + 100.0;
                v1147 = v1146;
                v1148 = -v1763;
                v1149 = cos_deg(v1148) * 300.0 * (double)dir + x;
                addbullet(this, NULL, 930, v1149, v1147, v1144, 1, (int)&v1763, 4);
              }
              */
            }
            if ( get_elaps_frames() < field_7D2 )
            {
              /*
              v1135 = __OFSUB__(get_subseq(), 3);
              v1133 = get_subseq() == 3;
              v1134 = (get_subseq() - 3) < 0;
              
LABEL_2475:
              if ( (v1134 ^ v1135) | v1133 && (unsigned int)get_MT_range(100) <= 4 )
                play_sfx(5);
              */
LABEL_2475://TODO              
              if ( get_subseq() == 5 && get_elaps_frames() >= field_7D6 )
              {
LABEL_92:
                set_seq(0);
              }
              else
              {
                if (process() )
                  set_seq(0);
                if ( !get_elaps_frames() )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  {
                    switch ( settings_get()->get_difficulty() )
                    {
                      case 0:
                        field_7D0 = 120;
                        field_7DC = 8.0;
                        field_7D2 = 300;
                        dash_angle = 120.0;
                        field_7D4 = 40;
                        v1157 = 0.0;
                        field_7D6 = 240;
                        goto LABEL_2491;
                      case 1:
                        field_7D0 = 120;
                        field_7DC = 9.0;
                        field_7D2 = 300;
                        dash_angle = 180.0;
                        field_7D4 = 35;
                        v1157 = 6.0;
                        field_7D6 = 210;
                        goto LABEL_2491;
                      case 2:
                        field_7D0 = 90;
                        field_7DC = 12.0;
                        field_7D2 = 360;
                        dash_angle = 210.0;
                        field_7D4 = 28;
                        v1157 = 8.0;
                        field_7D6 = 180;
                        goto LABEL_2491;
                      case 3:
                        field_7D0 = 60;
                        field_7DC = 15.0;
                        field_7D2 = 360;
                        dash_angle = 240.0;
                        field_7D4 = 22;
                        v1157 = 10.0;
                        field_7D6 = 180;
LABEL_2491:
                        field_7E4 = v1157;
                        break;
                      default:
                        break;
                    }
                  }
                  if ( !get_elaps_frames() )
                  {
                    if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
                    {
                      flip_with_force();
                      h_inerc = /*(double)(unsigned int)get_MT_range(30)*/30.0 * 0.1000000014901161;
                    }
                    if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
                    {
                      h_inerc = field_7DC * 0.2000000029802322;
                      v_inerc = 0.2000000029802322 * -dash_angle;
                      v_force = 0.2;
                    }
                  }
                }
              }
            }
            else
            {
              if ( field_7E4 > 0.0 )
              {
                /*
                v1484 = (double)(unsigned int)get_MT_range(360);
                v1521 = 0.0;
                if ( field_7E4 > 0.0 )
                {
                  v1150 = v1521;
                  do
                  {
                    v1755 = v1150 * 360.0 / field_7E4 + v1484;
                    v1756 = 17.5;
                    v1757 = 4.0;
                    v1758 = dash_angle;
                    v1151 = dir;
                    v1152 = -v1755;
                    v1153 = sin_deg(v1152) * 100.0 + y + 100.0;
                    v1154 = v1153;
                    v1155 = -v1755;
                    v1156 = cos_deg(v1155) * 100.0 * (double)dir + x;
                    addbullet(this, NULL, 930, v1156, v1154, v1151, 1, (int)&v1755, 4);
                    play_sfx(4);
                    v1521 = v1521 + 1.0;
                    v1150 = v1521;
                  }
                  while ( field_7E4 > (double)v1521 );
                }
                */
              }
              set_subseq(5);
            }
            return;
          default:
            goto LABEL_2803;
        }
      }
      if ( !get_subseq() && !(get_elaps_frames() % 2) )
      {
        /*
        v1599 = (double)(unsigned int)get_MT_range(360);
        v1600 = (double)(unsigned int)get_MT_range(400) + 200.0;
        v1601 = (double)((unsigned int)get_MT_range(100) >= 0x32);
        v1158 = dir;
        v1159 = -v1599;
        v1160 = sin_deg(v1159);
        v1161 = v1160 * v1600 + y - (double)get_pframe()->extra_24byte[5];
        v1162 = v1161;
        v1163 = -v1599;
        v1164 = cos_deg(v1163);
        v1165 = (v1164 * v1600 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
        addbullet(this, NULL, 970, v1165, v1162, v1158, 1, (int)&v1599, 3);
        */
      }
      if ( get_subseq() == 1 || get_subseq() == 2 )
      {
        v_inerc = v_inerc - 0.300000011920929;
        if ( !(get_elaps_frames() % 2) )
        {
          /*
          v1605 = (double)(unsigned int)get_MT_range(360);
          v1606 = (double)(unsigned int)get_MT_range(400) + 200.0;
          v1607 = (double)((unsigned int)get_MT_range(100) >= 0x32);
          v1167 = dir;
          v1168 = -v1605;
          v1169 = sin_deg(v1168);
          v1170 = v1169 * v1606 + y - (double)get_pframe()->extra_24byte[5];
          v1171 = v1170;
          v1172 = -v1605;
          v1173 = cos_deg(v1172);
          v1174 = (v1173 * v1606 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
          addbullet(this, NULL, 970, v1174, v1171, v1167, 1, (int)&v1605, 3);
          */
        }
        if ( char_on_ground_down() )
        {
          field_190 = 0;
          field_194 = 1;
          play_sfx(1);
          y = getlvl_height();
          reset_forces();
          /*
          v1522 = 0.0;
          do
          {
            v1553 = (double)(unsigned int)get_MT_range(10) + v1522 * 18.0;
            v1554 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
            v1555 = 0.0;
            v1175 = -v1553;
            v1176 = (1 - 2 * (sin_deg(v1175) > 0.0));
            v1177 = dir;
            v1178 = -v1553;
            v1179 = sin_deg(v1178) * 20.0 + y;
            v1180 = v1179;
            v1181 = -v1553;
            v1182 = cos_deg(v1181) * 100.0 * (double)dir + x;
            addbullet(this, NULL, 971, v1182, v1180, v1177, v1176, (int)&v1553, 3);
            v1522 = v1522 + 1.0;
          }
          while ( v1522 < 20.0 );
          v1554 = 0.40000001;
          v1555 = 0.0;
          addbullet(this, NULL, 940, x, y, dir, 1, (int)&v1553, 3);
          v1554 = 0.30000001;
          v1555 = 1.0;
          addbullet(this, NULL, 940, x, y, dir, -1, (int)&v1553, 3);
          v1183 = 12;
          do
          {
            v1553 = -10.0 - (double)(unsigned int)get_MT_range(160);
            v1554 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
            v1555 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 2.0;
            v1184 = dir;
            v1185 = -v1553;
            v1186 = sin_deg(v1185) * 20.0 + y;
            v1187 = v1186;
            v1188 = -v1553;
            v1189 = cos_deg(v1188) * 100.0 * (double)dir + x;
            addbullet(this, NULL, 940, v1189, v1187, v1184, 1, (int)&v1553, 3);
            --v1183;
          }
          while ( v1183 );
          */
          set_subseq(3);
LABEL_2188:
          //shake_camera(10.0);
          return;
        }
      }
      if (process() )
      {
        if ( field_888 > 10 )
        {
          set_seq(751);
          flip_with_force();
        }
        else
        {
          set_seq(756);
          /*
          v1926 = 0.0;
          v1927 = 0.0;
          v1928 = 1.0;
          addbullet(this, NULL, 944, x, y, dir, 1, (int)&v1926, 3);
          */
          play_sfx(6);
        }
      }
      if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
        return;
      v_inerc = /*(double)(unsigned int)get_MT_range(30)*/30.0 * 0.1000000014901161 + 10.0;
      if ( x >= 400.0 )
      {
        if ( x <= 880.0 )
        {
          v1191 = 3.0 - /*(double)(unsigned int)get_MT_range(60)*/60.0 * 0.1000000014901161;
          goto LABEL_2536;
        }
        flip_with_force();
        if ( dir == -1 )
        {
          if ( /*get_MT_range(40)*/40 < 0 )
          {
            v1191 = (/*get_MT_range(40)*/40 + 4294967300.0) * 0.1000000014901161 + 2.0;
            goto LABEL_2536;
          }
          goto LABEL_2526;
        }
        if ( /*get_MT_range(40)*/40 < 0 )
        {
          v1191 = -2.0 - (/*get_MT_range(40)*/40 + 4294967300.0) * 0.1000000014901161;
          goto LABEL_2536;
        }
      }
      else
      {
        flip_with_force();
        if ( dir == 1 )
        {
          v1191 = /*(double)(unsigned int)get_MT_range(40)*/40.0 * 0.1000000014901161 + 2.0;
LABEL_2526:
LABEL_2536:
          h_inerc = v1191;
          switch ( settings_get()->get_difficulty() )
          {
            case 0:
              field_7D0 = 120;
              field_7DC = 6.0;
              field_7D2 = 210;
              dash_angle = 240.0;
              field_7D4 = 30;
              v1195 = 0.0;
              field_7D6 = 150;
              goto LABEL_2541;
            case 1:
              field_7D0 = 120;
              field_7DC = 8.0;
              field_7D2 = 240;
              dash_angle = 240.0;
              field_7D4 = 30;
              v1195 = 6.0;
              field_7D6 = 120;
              goto LABEL_2541;
            case 2:
              field_7D0 = 90;
              field_7DC = 12.0;
              field_7D2 = 270;
              dash_angle = 240.0;
              field_7D4 = 20;
              v1195 = 8.0;
              field_7D6 = 90;
              goto LABEL_2541;
            case 3:
              field_7D0 = 60;
              field_7DC = 15.0;
              field_7D2 = 300;
              dash_angle = 270.0;
              field_7D4 = 14;
              v1195 = 10.0;
              field_7D6 = 60;
LABEL_2541:
              field_7E4 = v1195;
              break;
            default:
              break;
          }
          if ( (double)health / (double)max_health <= 0.6600000262260437 )
          {
            //WHATIS?
            ////((void (__thiscall *)(char_namazu *, signed int, signed int))set_seq_subseq_func1)(v1, 752, 1);
            /*
            v1580 = 0.0;
            v1581 = 0.0;
            v1582 = 0.0;
            addbullet(this, NULL, 944, x, y, dir, 1, (int)&v1580, 3);
            */
            play_sfx(6);
            /*
            v1523 = 0.0;
            do
            {
              v1580 = (double)(unsigned int)get_MT_range(10) + v1523 * 18.0;
              v1581 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
              v1582 = 0.0;
              v1196 = -v1580;
              v1197 = (1 - 2 * (sin_deg(v1196) > 0.0));
              v1198 = dir;
              v1199 = -v1580;
              v1200 = sin_deg(v1199) * 20.0 + y;
              v1201 = v1200;
              v1202 = -v1580;
              v1203 = cos_deg(v1202) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 971, v1203, v1201, v1198, v1197, (int)&v1580, 3);
              v1523 = v1523 + 1.0;
            }
            while ( v1523 < 20.0 );
            */
          }
          return;
        }
      }
      v1191 = -2.0 - /*(double)(unsigned int)get_MT_range(40)*/40.0 * 0.1000000014901161;
      goto LABEL_2536;
    }
    switch ( sq )
    {
      case 751:
        if ( !get_subseq() && !(get_elaps_frames() % 2) )
        {
          /*
          v1611 = (double)(unsigned int)get_MT_range(360);
          v1612 = (double)(unsigned int)get_MT_range(400) + 200.0;
          v1613 = (double)((unsigned int)get_MT_range(100) >= 0x32);
          v1204 = dir;
          v1205 = -v1611;
          v1206 = sin_deg(v1205);
          v1207 = v1206 * v1612 + y - (double)get_pframe()->extra_24byte[5];
          v1208 = v1207;
          v1209 = -v1611;
          v1210 = cos_deg(v1209);
          v1211 = (v1210 * v1612 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
          addbullet(this, NULL, 970, v1211, v1208, v1204, 1, (int)&v1611, 3);
          */
        }
        if ( get_subseq() == 1 )
        {
          if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
          {
            /*
            v1617 = (double)(unsigned int)get_MT_range(360);
            v1618 = (double)(unsigned int)get_MT_range(400) + 200.0;
            v1619 = (double)((unsigned int)get_MT_range(100) >= 0x32);
            v1212 = dir;
            v1213 = -v1617;
            v1214 = sin_deg(v1213);
            v1215 = v1214 * v1618 + y - (double)get_pframe()->extra_24byte[5];
            v1216 = v1215;
            v1217 = -v1617;
            v1218 = cos_deg(v1217);
            v1219 = (v1218 * v1618 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
            addbullet(this, NULL, 970, v1219, v1216, v1212, 1, (int)&v1617, 3);
            */
          }
          if ( get_elaps_frames() >= field_7D0 )
            goto LABEL_170;
        }
        if ( get_subseq() == 3 )
        {
          if ( !(get_elaps_frames() % 6) && field_7E4 > 0.0 )
          {
            /*
            v1568 = -90.0;
            v1569 = 40.0;
            v1570 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 4.0;
            v1220 = field_7D4;
            v1221 = dir;
            v1222 = x + (double)v1220;
            v1223 = y - 100.0;
            v1224 = v1223;
            v1225 = get_MT_range(v1220);
            v1226 = v1222 - ((double)(unsigned int)v1225 + (double)(unsigned int)v1225);
            addbullet(this, NULL, 940, v1226, v1224, v1221, 1, (int)&v1568, 3);
            */
            field_7E4 = field_7E4 - 1.0;
            /*
            v1524 = 0.0;
            do
            {
              v1568 = (double)(unsigned int)get_MT_range(360);
              v1569 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
              v1570 = 0.0;
              v1227 = -v1568;
              v1228 = (1 - 2 * (sin_deg(v1227) > 0.0));
              v1229 = dir;
              v1230 = -v1568;
              v1231 = sin_deg(v1230) * 20.0 + y;
              v1232 = v1231;
              v1233 = -v1568;
              v1234 = cos_deg(v1233) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 971, v1234, v1232, v1229, v1228, (int)&v1568, 3);
              v1524 = v1524 + 1.0;
            }
            while ( v1524 < 2.0 );
            //shake_camera(3.0);
            */
          }
          if ( get_elaps_frames() >= field_7D2 )
            goto LABEL_2148;
        }
        if (process() )
        {
          if ( field_888 > 10 )
          {
            set_seq(750);
          }
          else
          {
            set_seq(756);
            /*
            v1932 = 0.0;
            v1933 = 0.0;
            v1934 = 1.0;
            addbullet(this, NULL, 944, x, y, dir, 1, (int)&v1932, 3);
            */
            play_sfx(6);
          }
        }
        if ( !get_elaps_frames() )
        {
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            switch ( settings_get()->get_difficulty() )
            {
              case 0:
                field_7D0 = 150;
                field_7D2 = 300;
                field_7E4 = 10.0;
                field_7D4 = 150;
                break;
              case 1:
                field_7D0 = 120;
                field_7D2 = 270;
                field_7E4 = 16.0;
                field_7D4 = 200;
                break;
              case 2:
                field_7D0 = 120;
                field_7D2 = 240;
                field_7E4 = 22.0;
                field_7D4 = 300;
                break;
              case 3:
                field_7D0 = 90;
                field_7D2 = 210;
                field_7E4 = 30.0;
                field_7D4 = 400;
                break;
              default:
                break;
            }
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
          {
            //shake_camera(15.0);
            play_sfx(9);
          }
        }
        return;
      case 752:
        if ( !get_subseq() && !(get_elaps_frames() % 2) )
        {
          /*
          v1623 = (double)(unsigned int)get_MT_range(360);
          v1624 = (double)(unsigned int)get_MT_range(400) + 200.0;
          v1625 = (double)((unsigned int)get_MT_range(100) >= 0x32);
          v1235 = dir;
          v1236 = -v1623;
          v1237 = sin_deg(v1236);
          v1238 = v1237 * v1624 + y - (double)get_pframe()->extra_24byte[5];
          v1239 = v1238;
          v1240 = -v1623;
          v1241 = cos_deg(v1240);
          v1242 = (v1241 * v1624 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
          addbullet(this, NULL, 970, v1242, v1239, v1235, 1, (int)&v1623, 3);
          */
        }
        if ( get_subseq() == 1 || get_subseq() == 2 )
        {
          v_inerc = v_inerc - 0.300000011920929;
          if ( !(get_elaps_frames() % 2) )
          {
            /*
            v1629 = (double)(unsigned int)get_MT_range(360);
            v1630 = (double)(unsigned int)get_MT_range(400) + 200.0;
            v1631 = (double)((unsigned int)get_MT_range(100) >= 0x32);
            v1244 = dir;
            v1245 = -v1629;
            v1246 = sin_deg(v1245);
            v1247 = v1246 * v1630 + y - (double)get_pframe()->extra_24byte[5];
            v1248 = v1247;
            v1249 = -v1629;
            v1250 = cos_deg(v1249);
            v1251 = (v1250 * v1630 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
            addbullet(this, NULL, 970, v1251, v1248, v1244, 1, (int)&v1629, 3);
            */
          }
          if ( char_on_ground_down() )
          {
            field_190 = 0;
            field_194 = 1;
            play_sfx(1);
            y = getlvl_height();
            reset_forces();
            /*
            v1525 = 0.0;
            do
            {
              v1556 = (double)(unsigned int)get_MT_range(10) + v1525 * 18.0;
              v1557 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
              v1558 = 0.0;
              v1252 = -v1556;
              v1253 = (1 - 2 * (sin_deg(v1252) > 0.0));
              v1254 = dir;
              v1255 = -v1556;
              v1256 = sin_deg(v1255) * 20.0 + y;
              v1257 = v1256;
              v1258 = -v1556;
              v1259 = cos_deg(v1258) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 971, v1259, v1257, v1254, v1253, (int)&v1556, 3);
              v1525 = v1525 + 1.0;
            }
            while ( v1525 < 20.0 );
            v1557 = 0.40000001;
            v1558 = 0.0;
            addbullet(this, NULL, 940, x, y, dir, 1, (int)&v1556, 3);
            v1557 = 0.30000001;
            v1558 = 1.0;
            addbullet(this, NULL, 940, x, y, dir, -1, (int)&v1556, 3);
            v1260 = 12;
            do
            {
              v1556 = -10.0 - (double)(unsigned int)get_MT_range(160);
              v1557 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
              v1558 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 2.0;
              v1261 = dir;
              v1262 = -v1556;
              v1263 = sin_deg(v1262) * 20.0 + y;
              v1264 = v1263;
              v1265 = -v1556;
              v1266 = cos_deg(v1265) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 940, v1266, v1264, v1261, 1, (int)&v1556, 3);
              --v1260;
            }
            while ( v1260 );
            */
            set_subseq(3);
            goto LABEL_2188;
          }
        }
        if (process() )
        {
          if ( field_888 > 10 )
          {
            set_seq(753);
            flip_with_force();
          }
          else
          {
            set_seq(756);
            /*
            v1938 = 0.0;
            v1939 = 0.0;
            v1940 = 1.0;
            addbullet(this, NULL, 944, x, y, dir, 1, (int)&v1938, 3);
            */
            play_sfx(6);
          }
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          return;
        v_inerc = /*(double)(unsigned int)get_MT_range(30)*/30.0 * 0.1000000014901161 + 10.0;
        if ( x >= 400.0 )
        {
          if ( x <= 880.0 )
          {
            v1268 = 3.0 - /*(double)(unsigned int)get_MT_range(60)*/60.0 * 0.1000000014901161;
            goto LABEL_2614;
          }
          flip_with_force();
          if ( dir == -1 )
          {
            if (  /*get_MT_range(40)*/40.0 >= 0 )
              goto LABEL_2604;
            v1268 = ((double)/*get_MT_range(40)*/40.0 + 4294967300.0) * 0.1000000014901161 + 2.0;
LABEL_2614:
            h_inerc = v1268;
            switch ( settings_get()->get_difficulty() )
            {
              case 0:
                field_7D0 = 120;
                field_7DC = 6.0;
                field_7D2 = 210;
                dash_angle = 240.0;
                field_7D4 = 30;
                v1272 = 0.0;
                field_7D6 = 150;
                goto LABEL_2619;
              case 1:
                field_7D0 = 120;
                field_7DC = 8.0;
                field_7D2 = 240;
                dash_angle = 240.0;
                field_7D4 = 30;
                v1272 = 6.0;
                field_7D6 = 120;
                goto LABEL_2619;
              case 2:
                field_7D0 = 90;
                field_7DC = 12.0;
                field_7D2 = 270;
                dash_angle = 240.0;
                field_7D4 = 20;
                v1272 = 8.0;
                field_7D6 = 90;
                goto LABEL_2619;
              case 3:
                field_7D0 = 60;
                field_7DC = 15.0;
                field_7D2 = 300;
                dash_angle = 270.0;
                field_7D4 = 14;
                v1272 = 10.0;
                field_7D6 = 60;
LABEL_2619:
                field_7E4 = v1272;
                break;
              default:
                break;
            }
            if ( (double)health / (double)max_health <= 0.3300000131130219 )
            {
              //WHATIS?
              //((void (__thiscall *)(char_namazu *, signed int, signed int))set_seq_subseq_func1)(v1, 754, 1);
              /*
              v1577 = 0.0;
              v1578 = 0.0;
              v1579 = 1.0;
              addbullet(this, NULL, 944, x, y, dir, 1, (int)&v1577, 3);
              */
              play_sfx(6);
              /*
              v1526 = 0.0;
              do
              {
                v1577 = (double)(unsigned int)get_MT_range(10) + v1526 * 18.0;
                v1578 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 20.0;
                v1579 = 0.0;
                v1273 = -v1577;
                v1274 = (1 - 2 * (sin_deg(v1273) > 0.0));
                v1275 = dir;
                v1276 = -v1577;
                v1277 = sin_deg(v1276) * 20.0 + y;
                v1278 = v1277;
                v1279 = -v1577;
                v1280 = cos_deg(v1279) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 971, v1280, v1278, v1275, v1274, (int)&v1577, 3);
                v1526 = v1526 + 1.0;
              }
              while ( v1526 < 20.0 );
              */
            }
            return;
          }
          if ( /*get_MT_range(40)*/40.0 < 0 )
          {
            v1268 = -2.0 - ((double)/*get_MT_range(40)*/40.0 + 4294967300.0) * 0.1000000014901161;
            goto LABEL_2614;
          }
        }
        else
        {
          flip_with_force();
          if ( dir == 1 )
          {
            v1268 =/* (double)(unsigned int)get_MT_range(40)*/40.0 * 0.1000000014901161 + 2.0;
LABEL_2604:
            goto LABEL_2614;
          }
          v1268 = -2.0 - /* (double)(unsigned int)get_MT_range(40)*/40.0 * 0.1000000014901161;
        }
        goto LABEL_2614;
      case 753:
        if ( !get_subseq() && !(get_elaps_frames() % 2) )
        {
          /*
          v1635 = (double)(unsigned int)get_MT_range(360);
          v1636 = (double)(unsigned int)get_MT_range(400) + 200.0;
          v1637 = (double)((unsigned int)get_MT_range(100) >= 0x32);
          v1281 = dir;
          v1282 = -v1635;
          v1283 = sin_deg(v1282);
          v1284 = v1283 * v1636 + y - (double)get_pframe()->extra_24byte[5];
          v1285 = v1284;
          v1286 = -v1635;
          v1287 = cos_deg(v1286);
          v1288 = (v1287 * v1636 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
          addbullet(this, NULL, 970, v1288, v1285, v1281, 1, (int)&v1635, 3);
          */
        }
        if ( get_subseq() != 1 )
          goto LABEL_2809;
        if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
        {
          /*
          v1641 = (double)(unsigned int)get_MT_range(360);
          v1642 = (double)(unsigned int)get_MT_range(400) + 200.0;
          v1643 = (double)((unsigned int)get_MT_range(100) >= 0x32);
          v1289 = dir;
          v1290 = -v1641;
          v1291 = sin_deg(v1290);
          v1292 = v1291 * v1642 + y - (double)get_pframe()->extra_24byte[5];
          v1293 = v1292;
          v1294 = -v1641;
          v1295 = cos_deg(v1294);
          v1296 = (v1295 * v1642 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
          addbullet(this, NULL, 970, v1296, v1293, v1289, 1, (int)&v1641, 3);
          */
        }
        if ( get_elaps_frames() >= field_7D0 )
        {
LABEL_170:
LABEL_171:
          next_subseq();
        }
        else
        {
LABEL_2809:
          if ( get_subseq() == 3 )
          {
            if ( !(get_elaps_frames() % 6) && field_7E4 > 0.0 )
            {
              /*
              v1583 = -90.0;
              v1584 = 40.0;
              v1585 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 4.0;
              v1297 = field_7D4;
              v1298 = dir;
              v1299 = x + (double)v1297;
              v1300 = y - 100.0;
              v1301 = v1300;
              v1302 = get_MT_range(v1297);
              v1303 = v1299 - ((double)(unsigned int)v1302 + (double)(unsigned int)v1302);
              addbullet(this, NULL, 941, v1303, v1301, v1298, 1, (int)&v1583, 3);
              */
              field_7E4 = field_7E4 - 1.0;
              /*
              v1527 = 0.0;
              do
              {
                v1583 = (double)(unsigned int)get_MT_range(360);
                v1584 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
                v1585 = 0.0;
                v1304 = -v1583;
                v1305 = (1 - 2 * (sin_deg(v1304) > 0.0));
                v1306 = dir;
                v1307 = -v1583;
                v1308 = sin_deg(v1307) * 20.0 + y;
                v1309 = v1308;
                v1310 = -v1583;
                v1311 = cos_deg(v1310) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 971, v1311, v1309, v1306, v1305, (int)&v1583, 3);
                v1527 = v1527 + 1.0;
              }
              while ( v1527 < 2.0 );
              //shake_camera(3.0);
              */
            }
            if ( get_elaps_frames() >= field_7D2 )
              goto LABEL_2148;
          }
          if (process() )
          {
            if ( field_888 > 10 )
            {
              set_seq(752);
            }
            else
            {
              set_seq(756);
              /*
              v1944 = 0.0;
              v1945 = 0.0;
              v1946 = 1.0;
              addbullet(this, NULL, 944, x, y, dir, 1, (int)&v1944, 3);
              */
              play_sfx(6);
            }
          }
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  field_7D0 = 150;
                  field_7D2 = 300;
                  field_7E4 = 10.0;
                  field_7D4 = 150;
                  break;
                case 1:
                  field_7D0 = 120;
                  field_7D2 = 270;
                  field_7E4 = 16.0;
                  field_7D4 = 200;
                  break;
                case 2:
                  field_7D0 = 120;
                  field_7D2 = 240;
                  field_7E4 = 22.0;
                  field_7D4 = 300;
                  break;
                case 3:
                  field_7D0 = 90;
                  field_7D2 = 210;
                  field_7E4 = 30.0;
                  field_7D4 = 400;
                  break;
                default:
                  break;
              }
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            {
              //shake_camera(15.0);
              play_sfx(10);
            }
          }
        }
        return;
      case 754:
        if ( !get_subseq() && !(get_elaps_frames() % 2) )
        {
          /*
          v1647 = (double)(unsigned int)get_MT_range(360);
          v1648 = (double)(unsigned int)get_MT_range(400) + 200.0;
          v1649 = (double)((unsigned int)get_MT_range(100) >= 0x32);
          v1312 = dir;
          v1313 = -v1647;
          v1314 = sin_deg(v1313);
          v1315 = v1314 * v1648 + y - (double)get_pframe()->extra_24byte[5];
          v1316 = v1315;
          v1317 = -v1647;
          v1318 = cos_deg(v1317);
          v1319 = (v1318 * v1648 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
          addbullet(this, NULL, 970, v1319, v1316, v1312, 1, (int)&v1647, 3);
          */
        }
        if ( get_subseq() == 1 || get_subseq() == 2 )
        {
          v_inerc = v_inerc - 0.300000011920929;
          if ( !(get_elaps_frames() % 2) )
          {
            /*
            v1653 = (double)(unsigned int)get_MT_range(360);
            v1654 = (double)(unsigned int)get_MT_range(400) + 200.0;
            v1655 = (double)((unsigned int)get_MT_range(100) >= 0x32);
            v1321 = dir;
            v1322 = -v1653;
            v1323 = sin_deg(v1322);
            v1324 = v1323 * v1654 + y - (double)get_pframe()->extra_24byte[5];
            v1325 = v1324;
            v1326 = -v1653;
            v1327 = cos_deg(v1326);
            v1328 = (v1327 * v1654 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
            addbullet(this, NULL, 970, v1328, v1325, v1321, 1, (int)&v1653, 3);
            */
          }
          if ( char_on_ground_down() )
          {
            field_190 = 0;
            field_194 = 1;
            play_sfx(1);
            y = getlvl_height();
            reset_forces();
            /*
            v1528 = 0.0;
            do
            {
              v1559 = (double)(unsigned int)get_MT_range(10) + v1528 * 18.0;
              v1560 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
              v1561 = 0.0;
              v1329 = -v1559;
              v1330 = (1 - 2 * (sin_deg(v1329) > 0.0));
              v1331 = dir;
              v1332 = -v1559;
              v1333 = sin_deg(v1332) * 20.0 + y;
              v1334 = v1333;
              v1335 = -v1559;
              v1336 = cos_deg(v1335) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 971, v1336, v1334, v1331, v1330, (int)&v1559, 3);
              v1528 = v1528 + 1.0;
            }
            while ( v1528 < 20.0 );
            v1560 = 0.40000001;
            v1561 = 0.0;
            addbullet(this, NULL, 940, x, y, dir, 1, (int)&v1559, 3);
            v1560 = 0.30000001;
            v1561 = 1.0;
            addbullet(this, NULL, 940, x, y, dir, -1, (int)&v1559, 3);
            v1337 = 12;
            do
            {
              v1559 = -10.0 - (double)(unsigned int)get_MT_range(160);
              v1560 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
              v1561 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 2.0;
              v1338 = dir;
              v1339 = -v1559;
              v1340 = sin_deg(v1339) * 20.0 + y;
              v1341 = v1340;
              v1342 = -v1559;
              v1343 = cos_deg(v1342) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 940, v1343, v1341, v1338, 1, (int)&v1559, 3);
              --v1337;
            }
            while ( v1337 );
            */
            set_subseq(3);
            goto LABEL_2188;
          }
        }
        if (process() )
        {
          if ( field_888 > 10 )
            set_seq(755);
          else
            set_seq(756);
        }
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          return;
        v_inerc = /*(double)(unsigned int)get_MT_range(30)*/30.0 * 0.1000000014901161 + 10.0;
        if ( x < 400.0 )
        {
          flip_with_force();
          if ( dir == 1 )
          {
LABEL_2681:
            v1346 = /* (double)(unsigned int)get_MT_range(40)*/40.0 * 0.1000000014901161 + 2.0;
            goto LABEL_2691;
          };
          goto LABEL_2683;
        }
        if ( x <= 880.0 )
        {
          v1346 = 3.0 - /*(double)(unsigned int)get_MT_range(60)*/60.0 * 0.1000000014901161;
        }
        else
        {
          flip_with_force();
          if ( dir == -1 )
          {
            if ( /*get_MT_range(40)*/40.0 >= 0 )
              goto LABEL_2681;
            v1346 = ((double)/*get_MT_range(40)*/40.0 + 4294967300.0) * 0.1000000014901161 + 2.0;
          }
          else
          {
            if ( /*get_MT_range(40)*/40.0 >= 0 )
            {
LABEL_2683:
              v1346 = -2.0 - (double)/*get_MT_range(40)*/40.0 * 0.1000000014901161;
              goto LABEL_2691;
            }
            v1346 = -2.0 - ((double)/*get_MT_range(40)*/40.0 + 4294967300.0) * 0.1000000014901161;
          }
        }
LABEL_2691:
        h_inerc = v1346;
        switch ( settings_get()->get_difficulty() )
        {
          case 0:
            field_7D0 = 120;
            field_7DC = 6.0;
            field_7D2 = 210;
            dash_angle = 240.0;
            field_7D4 = 30;
            field_7D6 = 150;
            field_7E4 = 0.0;
            break;
          case 1:
            field_7D0 = 120;
            field_7DC = 8.0;
            field_7D2 = 240;
            dash_angle = 240.0;
            field_7D4 = 30;
            field_7D6 = 120;
            field_7E4 = 6.0;
            break;
          case 2:
            field_7D0 = 90;
            field_7DC = 12.0;
            field_7D2 = 270;
            dash_angle = 240.0;
            field_7D4 = 20;
            field_7D6 = 90;
            field_7E4 = 8.0;
            break;
          case 3:
            field_7D0 = 60;
            field_7DC = 15.0;
            field_7D2 = 300;
            dash_angle = 270.0;
            field_7D4 = 14;
            field_7D6 = 60;
            field_7E4 = 10.0;
            break;
          default:
            return;
        }
        return;
      case 755:
        if ( !get_subseq() && !(get_elaps_frames() % 2) )
        {
          /*
          v1659 = (double)(unsigned int)get_MT_range(360);
          v1660 = (double)(unsigned int)get_MT_range(400) + 200.0;
          v1661 = (double)((unsigned int)get_MT_range(100) >= 0x32);
          v1350 = dir;
          v1351 = -v1659;
          v1352 = sin_deg(v1351);
          v1353 = v1352 * v1660 + y - (double)get_pframe()->extra_24byte[5];
          v1354 = v1353;
          v1355 = -v1659;
          v1356 = cos_deg(v1355);
          v1357 = (v1356 * v1660 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
          addbullet(this, NULL, 970, v1357, v1354, v1350, 1, (int)&v1659, 3);
          */
        }
        if ( get_subseq() != 1 )
          goto LABEL_2810;
        if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
        {
          /*
          v1665 = (double)(unsigned int)get_MT_range(360);
          v1666 = (double)(unsigned int)get_MT_range(400) + 200.0;
          v1667 = (double)((unsigned int)get_MT_range(100) >= 0x32);
          v1358 = dir;
          v1359 = -v1665;
          v1360 = sin_deg(v1359);
          v1361 = v1360 * v1666 + y - (double)get_pframe()->extra_24byte[5];
          v1362 = v1361;
          v1363 = -v1665;
          v1364 = cos_deg(v1363);
          v1365 = (v1364 * v1666 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
          addbullet(this, NULL, 970, v1365, v1362, v1358, 1, (int)&v1665, 3);
          */
        }
        if ( get_elaps_frames() >= field_7D0 )
        {
LABEL_2420:
          next_subseq();
          flip_with_force();
        }
        else
        {
          if ( get_subseq() != 3 )
            goto LABEL_2811;
LABEL_2810:
          if ( !(get_elaps_frames() % 6) && field_7E4 > 0.0 )
          {
            /*
            v1574 = -90.0;
            v1575 = 40.0;
            v1576 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 4.0;
            v1366 = field_7D4;
            v1367 = dir;
            v1368 = x + (double)v1366;
            v1369 = y - 100.0;
            v1370 = v1369;
            v1371 = get_MT_range(v1366);
            v1372 = v1368 - ((double)(unsigned int)v1371 + (double)(unsigned int)v1371);
            addbullet(this, NULL, 942, v1372, v1370, v1367, 1, (int)&v1574, 3);
            */
            field_7E4 = field_7E4 - 1.0;
            /*
            v1529 = 0.0;
            do
            {
              v1574 = (double)(unsigned int)get_MT_range(360);
              v1575 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
              v1576 = 0.0;
              v1373 = -v1574;
              v1374 = (1 - 2 * (sin_deg(v1373) > 0.0));
              v1375 = dir;
              v1376 = -v1574;
              v1377 = sin_deg(v1376) * 20.0 + y;
              v1378 = v1377;
              v1379 = -v1574;
              v1380 = cos_deg(v1379) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 971, v1380, v1378, v1375, v1374, (int)&v1574, 3);
              v1529 = v1529 + 1.0;
            }
            while ( v1529 < 2.0 );
            */
            //shake_camera(3.0);
          }
          if ( get_elaps_frames() >= field_7D2 )
          {
LABEL_2148:
            next_subseq();
          }
          else
          {
LABEL_2811:
            if (process() )
            {
              if ( field_888 > 10 )
                set_seq(754);
              else
                set_seq(756);
            }
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                switch ( settings_get()->get_difficulty() )
                {
                  case 0:
                    field_7D0 = 150;
                    field_7D2 = 300;
                    field_7E4 = 10.0;
                    field_7D4 = 150;
                    break;
                  case 1:
                    field_7D0 = 120;
                    field_7D2 = 270;
                    field_7E4 = 16.0;
                    field_7D4 = 200;
                    break;
                  case 2:
                    field_7D0 = 120;
                    field_7D2 = 240;
                    field_7E4 = 22.0;
                    field_7D4 = 300;
                    break;
                  case 3:
                    field_7D0 = 90;
                    field_7D2 = 210;
                    field_7E4 = 30.0;
                    field_7D4 = 400;
                    break;
                  default:
                    break;
                }
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
                //shake_camera(15.0);
                play_sfx(11);
              }
            }
          }
        }
        return;
      case 756:
        if ( !get_subseq() && !(get_elaps_frames() % 2) )
        {
          /*
          v1671 = (double)(unsigned int)get_MT_range(360);
          v1672 = (double)(unsigned int)get_MT_range(400) + 200.0;
          v1673 = (double)((unsigned int)get_MT_range(100) >= 0x32);
          v1382 = dir;
          v1383 = -v1671;
          v1384 = sin_deg(v1383);
          v1385 = v1384 * v1672 + y - (double)get_pframe()->extra_24byte[5];
          v1386 = v1385;
          v1387 = -v1671;
          v1388 = cos_deg(v1387);
          v1389 = (v1388 * v1672 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
          addbullet(this, NULL, 970, v1389, v1386, v1382, 1, (int)&v1671, 3);
          */
        }
        if ( get_subseq() != 1 )
          goto LABEL_2812;
        if ( !(get_elaps_frames() % 180) )
          play_sfx(7);
        /*
        if ( (unsigned int)get_MT_range(100) <= 0xA )
        {
          //shake_camera(2.0);
          v1390 = 12;
          do
          {
            v1565 = -10.0 - (double)(unsigned int)get_MT_range(160);
            v1566 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 4.0;
            v1567 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 2.0;
            v1391 = dir;
            v1392 = x + 400.0;
            v1393 = -v1565;
            v1394 = sin_deg(v1393) * 20.0 + y;
            v1395 = v1394;
            v1396 = v1392 - (double)(unsigned int)get_MT_range(800);
            addbullet(this, NULL, 940, v1396, v1395, v1391, 1, (int)&v1565, 3);
            --v1390;
          }
          while ( v1390 );
        }
        */
        if ( !(get_elaps_frames() % 2) )
        {
          /*
          v1565 = (double)(unsigned int)get_MT_range(360);
          v1566 = (double)(unsigned int)get_MT_range(400) + 200.0;
          v1567 = (double)((unsigned int)get_MT_range(100) >= 0x32);
          v1397 = dir;
          v1398 = -v1565;
          v1399 = sin_deg(v1398);
          v1400 = v1399 * v1566 + y - (double)get_pframe()->extra_24byte[5];
          v1401 = v1400;
          v1402 = -v1565;
          v1403 = cos_deg(v1402);
          v1404 = (v1403 * v1566 + (double)get_pframe()->extra_24byte[4]) * (double)dir + x;
          addbullet(this, NULL, 970, v1404, v1401, v1397, 1, (int)&v1565, 3);
          */
        }
        if ( field_888 > 0 )
        {
LABEL_2812:
          if ( get_subseq() == 3 )
          {
            enemy->hit_stop = 10;
            if ( !(get_elaps_frames() % 20) )
            {
              //shake_camera(30.0);
              /*
              v1530 = 0.0;
              do
              {
                v1725 = (double)(unsigned int)get_MT_range(10) + v1530 * 18.0;
                v1726 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 30.0;
                v1727 = 0.0;
                v1405 = -v1725;
                v1406 = (1 - 2 * (sin_deg(v1405) > 0.0));
                v1407 = dir;
                v1408 = -v1725;
                v1409 = sin_deg(v1408) * 20.0 + y;
                v1410 = v1409;
                v1411 = -v1725;
                v1412 = cos_deg(v1411) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 971, v1412, v1410, v1407, v1406, (int)&v1725, 3);
                v1530 = v1530 + 1.0;
              }
              while ( v1530 < 20.0 );
              */
            }
          }
          if (process() )
            set_seq(752);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              switch ( settings_get()->get_difficulty() )
              {
                case 0:
                  field_7D0 = 150;
                  field_7D2 = 300;
                  field_7E4 = 10.0;
                  field_7D4 = 150;
                  break;
                case 1:
                  field_7D0 = 120;
                  field_7D2 = 270;
                  field_7E4 = 16.0;
                  field_7D4 = 200;
                  break;
                case 2:
                  field_7D0 = 120;
                  field_7D2 = 240;
                  field_7E4 = 22.0;
                  field_7D4 = 300;
                  break;
                case 3:
                  field_7D0 = 90;
                  field_7D2 = 210;
                  field_7E4 = 30.0;
                  field_7D4 = 400;
                  break;
                default:
                  break;
              }
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            {
              /*
              v1538 = 2.0;
              v1539 = 0.0;
              v1540 = 0.0;
              addbullet(this, NULL, 1250, 0.0, 0.0, 1, 2, (int)&v1538, 3);
              */
              //sub_43D38(3000, 0);
              enemy->win_count = 0;
              enemy->field_574 = 3;
              enemy->health = 0;
              enemy->field_1A4 = 2.0;
              enemy->field_1A8 = 80.0;
              set_seq(77);
              enemy->field_4BA = 6000;
              //shake_camera(30.0);
              play_sfx(8);
              /*
              v1531 = 0.0;
              do
              {
                v1538 = (double)(unsigned int)get_MT_range(10) + v1531 * 18.0;
                v1539 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 30.0;
                v1540 = 0.0;
                v1413 = -v1538;
                v1414 = (1 - 2 * (sin_deg(v1413) > 0.0));
                v1415 = dir;
                v1416 = -v1538;
                v1417 = sin_deg(v1416) * 20.0 + y;
                v1418 = v1417;
                v1419 = -v1538;
                v1420 = cos_deg(v1419) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 971, v1420, v1418, v1415, v1414, (int)&v1538, 3);
                v1531 = v1531 + 1.0;
              }
              while ( v1531 < 20.0 );
              v1539 = 0.40000001;
              v1540 = 0.0;
              addbullet(this, NULL, 943, x, y, dir, 1, (int)&v1538, 3);
              v1539 = 0.30000001;
              v1540 = 1.0;
              addbullet(this, NULL, 943, x, y, dir, -1, (int)&v1538, 3);
              v1532 = 0.0;
              do
              {
                v1538 = -(double)(unsigned int)get_MT_range(70) - 20.0;
                v1539 = (double)(unsigned int)get_MT_range(80) * 0.1000000014901161 + 10.0;
                v1540 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 4.0;
                v1421 = dir;
                v1422 = y;
                v1423 = v1422 - (double)(unsigned int)get_MT_range(200);
                v1424 = v1423;
                v1425 =/* (double)(unsigned int)get_MT_range(40)*//*40.0 + v1532 * 85.0;
                addbullet(this, NULL, 900, v1425, v1424, v1421, 1, (int)&v1538, 3);
                v1532 = v1532 + 1.0;
              }
              while ( v1532 < 15.0 );
              v1426 = 12;
              do
              {
                v1538 = -10.0 - (double)(unsigned int)get_MT_range(160);
                v1539 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
                v1540 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 2.0;
                v1427 = dir;
                v1428 = -v1538;
                v1429 = sin_deg(v1428) * 20.0 + y;
                v1430 = v1429;
                v1431 = -v1538;
                v1432 = cos_deg(v1431) * 100.0 * (double)dir + x;
                addbullet(this, NULL, 943, v1432, v1430, v1427, 1, (int)&v1538, 3);
                --v1426;
              }
              while ( v1426 );
              */
            }
          }
        }
        else
        {
          field_6F5 = 0;
          next_subseq();
        }
        return;
      case 770:
        if (process() )
          set_seq(700);
        if ( get_elaps_frames() >= 110 )
          goto LABEL_499;
        if ( get_elaps_frames() == 20 )
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
          field_818 = 0;
          scene_play_sfx(23);
          field_882 = 1;
          field_86A = 1;
          /*
          v1728 = 0.0;
          v1729 = 0.0;
          v1730 = 0.0;
          addbullet(this, NULL, 1201, 180.0, 130.0, 1, 2, (int)&v1728, 3);
          v1730 = 1.0;
          v1434 = y + 100.0;
          addbullet(this, NULL, 1202, x, v1434, dir, -1, (int)&v1728, 3);
          */
        }
        return;
      case 771:
       process();
        if ( get_elaps_frames() < 170 )
        {
          if ( get_elaps_frames() == 80 )
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
            field_818 = 0;
            scene_play_sfx(23);
            field_86A = 1;
            field_888 = 60;
            field_88A = 60;
            /*
            v1956 = 0.0;
            v1957 = 0.0;
            v1958 = 0.0;
            addbullet(this, NULL, 1203, 180.0, 130.0, 1, 2, (int)&v1956, 3);
            */
          }
        }
        else
        {
          set_seq(0);
          /*
          v1950 = 0.0;
          v1951 = 0.0;
          v1952 = 0.0;
          addbullet(this, NULL, 949, x, y, dir, -1, (int)&v1950, 3);
          */
        }
        return;
      case 780:
        if ( !get_subseq() )
        {
          v_inerc = v_inerc - 1.25;
          if ( char_on_ground_down() )
          {
            play_sfx(1);
            y = getlvl_height();
            reset_forces();
            /*
            v1533 = 0.0;
            do
            {
              v1541 = (double)(unsigned int)get_MT_range(10) + v1533 * 18.0;
              v1542 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
              v1543 = 0.0;
              v1436 = -v1541;
              v1437 = (1 - 2 * (sin_deg(v1436) > 0.0));
              v1438 = dir;
              v1439 = -v1541;
              v1440 = sin_deg(v1439) * 20.0 + y;
              v1441 = v1440;
              v1442 = -v1541;
              v1443 = cos_deg(v1442) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 971, v1443, v1441, v1438, v1437, (int)&v1541, 3);
              v1533 = v1533 + 1.0;
            }
            while ( v1533 < 20.0 );
            v1542 = 0.40000001;
            v1543 = 0.0;
            addbullet(this, NULL, 900, x, y, dir, 1, (int)&v1541, 3);
            v1542 = 0.30000001;
            v1543 = 1.0;
            addbullet(this, NULL, 900, x, y, dir, -1, (int)&v1541, 3);
            v1534 = 0.0;
            do
            {
              v1541 = -(double)(unsigned int)get_MT_range(140) - 20.0;
              v1542 = (double)(unsigned int)get_MT_range(80) * 0.1000000014901161 + 10.0;
              v1543 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 4.0;
              v1444 = dir;
              v1445 = -v1541;
              v1446 = sin_deg(v1445) * 20.0 + y;
              v1447 = v1446;
              v1448 = -v1541;
              v1449 = cos_deg(v1448) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 981, v1449, v1447, v1444, 1, (int)&v1541, 3);
              v1534 = v1534 + 1.0;
            }
            while ( v1534 < 6.0 );
            v1450 = 12;
            do
            {
              v1541 = -10.0 - (double)(unsigned int)get_MT_range(160);
              v1542 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
              v1543 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 2.0;
              v1451 = dir;
              v1452 = -v1541;
              v1453 = sin_deg(v1452) * 20.0 + y;
              v1454 = v1453;
              v1455 = -v1541;
              v1456 = cos_deg(v1455) * 100.0 * (double)dir + x;
              addbullet(this, NULL, 981, v1456, v1454, v1451, 1, (int)&v1541, 3);
              --v1450;
            }
            while ( v1450 );
            */
            next_subseq();
            //shake_camera(10.0);
          }
        }
        goto LABEL_2786;
      case 795:
        if ( get_subseq() )
          goto LABEL_2786;
        v_inerc = v_inerc - 0.300000011920929;
        if ( !char_on_ground_down() )
          goto LABEL_2786;
        set_subseq(1);
        scene_play_sfx(30);
LABEL_140:
        y = getlvl_height();
        reset_forces();
        return;
      case 797:
        if ( get_subseq() <= 1 )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_2793;
        }
LABEL_144:
LABEL_145:
        if ( process() )
          set_seq(0);
        return;
      case 798:
        if ( get_subseq() <= 1 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
        {
LABEL_2793:
          set_subseq(2);
          scene_play_sfx(30);
LABEL_2138:
          y = getlvl_height();
          v_inerc = 0.0;
        }
        else
        {
          if ( get_subseq() == 2 )
          {
            h_inerc = h_inerc - 0.75;
            if ( h_inerc >= 0.0 )
            {
              x = 800.0;
            }
            else
            {
              h_inerc = 0.0;
              x = 800.0;
            }
            if ( x < 800.0 )
              x = 800.0;
          }
LABEL_2786:
          if (process() )
LABEL_2787:
            set_seq(700);
        }
        return;
      default:
LABEL_2803:
        char_c::func10();
        return;
    }
  }
  if ( sq == 300 )
  {
LABEL_659:
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
      if (process() )
        set_seq(0);
      if ( !get_frame_time() )
      {
        if ( get_frame() == 2 )
        {
          /*
          v1962 = 0.0;
          v1963 = 0.0;
          v1964 = 1.0;
          addbullet(this, NULL, 848, x, y, dir, 1, (int)&v1962, 3);
          */
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
    switch ( sq )
    {
      case 0:
        sub10func();
        if ( 0.0 == h_inerc )
          field_49A = 0;
        if ( !field_49A )
          goto LABEL_62;
        goto LABEL_63;
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
        if (process() && !get_frame() )
          goto LABEL_79;
        return;
      case 2:
        sub10func();
        if ( field_49A )
        {
LABEL_63:
          if ( 0.0 < h_inerc )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc < 0.0 )
            {
              reset_forces();
              field_49A = 0;
            }
          }
          if ( 0.0 <= h_inerc || (h_inerc = (h_inerc + 0.5), h_inerc <= 0.0) )
          {
LABEL_141:
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
LABEL_62:
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
        if (process() && !get_frame() )
          goto LABEL_92;
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
          sub10func();
        if ( !get_subseq() )
        {
          if ( !field_49A )
            reset_forces();
        }
        if ( !(get_subseq() < 0 | get_subseq() == 0) )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_138;
        }
       process();
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          h_inerc = field_85C;
          v_inerc = field_860;
          v_force = field_864;
          goto LABEL_121; //allows to do neutral jump!
        }
        return;
      case 7:
        if ( !get_subseq() )
          sub10func();
        if ( !get_subseq() )
        {
          if ( !field_49A )
            reset_forces();
        }
        if ( !(get_subseq() < 0 | get_subseq() == 0) )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_138;
        }
       process();
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          return;
        v36 = 4.0;
        goto LABEL_121;
      case 8:
        if ( !get_subseq() )
          sub10func();
        if ( !get_subseq() )
        {
          if ( !field_49A )
            reset_forces();
        }
        if ( !(get_subseq() < 0 | get_subseq() == 0) )
        {
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_138;
        }
       process();
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          v36 = -4.0;
LABEL_121:
          char_h_move(v36);
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
          goto LABEL_141;
LABEL_138:
        move_val = 10;
        goto LABEL_139;
      case 10:
        sub10func();
        reset_forces();
        goto LABEL_144;
      case 50:
      case 51:
      case 52:
      case 53:
      case 54:
      case 55:
      case 56:
      case 57:
      case 58:
      case 59:
      case 60:
      case 61:
      case 62:
      case 63:
      case 64:
      case 65:
      case 66:
      case 67:
        v_inerc = v_inerc - 0.3499999940395355;
        h_inerc = h_inerc + 0.1000000014901161;
        if ( h_inerc > -1.0 )
          h_inerc = -1.0;
        if ( !has_shadow )
          has_shadow = 1;
        if ( !char_on_ground_down() )
          goto LABEL_145;
        play_sfx(0);
        reset_forces();
        y = getlvl_height();
        //shake_camera(2.0);
        /*
        v1489 = 0.0;
        do
        {
          a4 = (double)(unsigned int)get_MT_range(10) + v1489 * 24.0;
          v1702 = (double)(unsigned int)get_MT_range(20) * 0.1000000014901161 + 10.0;
          v1703 = 0.0;
          v45 = -a4;
          y = (1 - 2 * (sin_deg(v45) > 0.0));
          v47 = dir;
          v48 = -a4;
          v49 = sin_deg(v48) * 20.0 + y;
          v50 = v49;
          a3 = -a4;
          v52 = cos_deg(a3) * 100.0 * (double)dir + x;
          addbullet(this, NULL, 971, v52, v50, v47, y, (int)&a4, 3);
          v1489 = v1489 + 1.0;
        }
        while ( v1489 < 15.0 );
        */
        set_seq(10);
        return;
      case 70:
      case 71:
      case 72:
      case 73:
      case 74:
      case 75:
      case 76:
      case 77:
      case 78:
      case 79:
      case 80:
      case 81:
      case 82:
      case 83:
      case 84:
      case 85:
      case 86:
      case 87:
      case 88:
        v_inerc = v_inerc - 0.300000011920929;
        h_inerc = h_inerc + 0.1000000014901161;
        if ( h_inerc > -1.0 )
          h_inerc = -1.0;
        if ( !has_shadow )
          has_shadow = 1;
        if ( char_on_ground_down() )
        {
          y = getlvl_height();
          play_sfx(0);
          field_7DC = h_inerc;
          dash_angle = v_inerc;
          reset_forces();
          //shake_camera(10.0);
          /*
          v1490 = 0.0;
          do
          {
            a1a = (double)(unsigned int)get_MT_range(10) + v1490 * 24.0;
            v1717 = (double)(unsigned int)get_MT_range(20) * 0.1000000014901161 + 10.0;
            v1718 = 0.0;
            v54 = -a1a;
            v55 = (1 - 2 * (sin_deg(v54) > 0.0));
            v56 = dir;
            v57 = -a1a;
            v58 = sin_deg(v57) * 20.0 + y;
            v59 = v58;
            v60 = -a1a;
            v61 = cos_deg(v60) * 100.0 * (double)dir + x;
            addbullet(this, NULL, 971, v61, v59, v56, v55, (int)&a1a, 3);
            v1490 = v1490 + 1.0;
          }
          while ( v1490 < 15.0 );
          */
          set_seq(96);
        }
        else if (process() )
        {
          set_seq(199);
        }
        return;
      case 96:
        if ( get_subseq() == 1 )
        {
          v_inerc = v_inerc - 0.2000000029802322;
          h_inerc = h_inerc + 0.1000000014901161;
          if ( h_inerc > 0.0 )
            h_inerc = 0.0;
          if ( char_on_ground_down() )
          {
            y = getlvl_height();
            play_sfx(0);
            reset_forces();
            //shake_camera(2.0);
            set_seq(99);
            goto LABEL_170;
          }
        }
        else
        {
          sub10func();
        }
        if (process() )
          set_seq(0);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
        {
          h_inerc = field_7DC * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * -dash_angle;
          v_force = 0.2;
        }
        return;
      case 99:
        sub10func();
        if ( get_subseq() == 3 )
        {
          has_shadow = 0;
          /*
          if ( color_A <= 3u )
            color_A = 0;
          else
            color_A = color_A - 3;
          */
        }
        if ( health <= 0 )
        {
          field_51C = 3;
          field_520 = 3;
        }
       process();
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
        {
          if ( !field_576 && !field_880 )
          {
            if ( cards_added > 0 && controlling_type == 2 && cards_active[0]->id >= 248 )
            {
              health_to_max();
              field_868 = 0;
            }
            field_51C = 3;
            field_520 = 3;
            set_seq(199);
            field_574 = 0;
            field_577 = 1;
          }
          field_880 = 0;
        }
        return;
      case 149:
        if ( v_inerc <= 0.0 )
          v_inerc = v_inerc - v_force * 0.25;
        else
          v_inerc = v_inerc - v_force;
        if ( !char_on_ground_down() )
          goto LABEL_142;
        play_sfx(0);
        field_7DC = h_inerc;
        dash_angle = v_inerc;
        y = getlvl_height();
        reset_forces();
        //shake_camera(10.0);
        /*
        v1491 = 0.0;
        do
        {
          v1710 = (double)(unsigned int)get_MT_range(10) + v1491 * 24.0;
          v1711 = (double)(unsigned int)get_MT_range(20) * 0.1000000014901161 + 10.0;
          v1712 = 0.0;
          v69 = -v1710;
          v70 = (1 - 2 * (sin_deg(v69) > 0.0));
          v71 = dir;
          v72 = -v1710;
          v73 = sin_deg(v72) * 20.0 + y;
          v74 = v73;
          v75 = -v1710;
          v76 = cos_deg(v75) * 100.0 * (double)dir + x;
          addbullet(this, NULL, 971, v76, v74, v71, v70, (int)&v1710, 3);
          v1491 = v1491 + 1.0;
        }
        while ( v1491 < 15.0 );
        */
        set_seq(96);
        angZ = 0.0;
        //shake_camera(2.0);
        reset_ofs();
        return;
      case 199:
        sub10func();
        if ( health <= 0 )
        {
          field_51C = 3;
          field_520 = 3;
        }
        if (process() )
        {
          field_51C = 3;
          field_520 = 3;
          set_seq(0);
          if ( enemy->x < (double)x )
            dir = -1;
          if ( enemy->x > (double)x )
            dir = 1;
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
          goto LABEL_226;
        if ( !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
        }
        if ( dY() >= 0 )
        {
          if ( (dX(dir) > 0 || ++field_7D0 <= 5) && ++field_7D0 <= 60 )
          {
LABEL_226:
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
            goto LABEL_239;
        }
        if (process() )
          goto LABEL_241;
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
          goto LABEL_248;
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
        if (process() )
        {
          set_seq(0);
          field_49A = 0;
        }
        return;
      case 208:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_282;
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
        v121 = 0.0;
        goto LABEL_297;
      case 209:
      case 212:
      case 221:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_282;
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
        v126 = 10.0;
        goto LABEL_317;
      case 210:
      case 222:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_282;
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
        v126 = -10.0;
LABEL_317:
        char_h_move(v126);
        v_inerc = 13.5;
        v123 = 0.5;
        goto LABEL_298;
      case 211:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_282;
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
          v121 = 2.0;
LABEL_297:
          char_h_move(v121);
          v_inerc = 18.5;
          v123 = 0.55000001;
LABEL_298:
          v_force = v123;
          field_49A = 0;
          scene_add_effect(this, 63, x, y, dir, 1);
        }
        return;
      case 214:
        if (process() )
          goto LABEL_856;
        if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          goto LABEL_363;
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
LABEL_363:
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 9 )
          set_subseq(5);
        if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 10 || !get_frame_time() && !get_frame() && get_subseq() == 11) )
          goto LABEL_372;
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
        if ( get_subseq() == 9 || get_subseq() == 10 || get_subseq() == 11 )
          v_inerc = v_inerc - v_force;
        if ( get_subseq() <= 0 || get_subseq() >= 9 )
          goto LABEL_488;
        ++field_7D6;
        field_7D4 = field_7D2 - dash_angle;
        if ( field_7D2 > 180 )
          field_7D4 = field_7D2 - 360; //7d2 or 7d4?
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
        {
          set_subseq(3);
          return;
        }
        if ( get_subseq() == 4 || get_subseq() == 5 )
        {
          if ( dash_angle <= 45.0 && dash_angle >= -45.0 )
          {
            set_subseq(1);
            return;
          }
          if ( dash_angle >= 135.0 || dash_angle <= -135.0 )
            goto LABEL_486;
        }
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
            goto LABEL_458;
          field_7D0 = get_frame();
          if ( dir == 1 )
          {
            if ( enemy->x < x )
            {
              dir = -1;
LABEL_453:
              h_inerc = -h_inerc;
              set_subseq(9);
              set_frame(field_7D0);
              goto LABEL_458;
            }
          }
          else
          {
            if ( enemy->x > x )
            {
              dir = -dir;
              goto LABEL_453;
            }
          }
          set_subseq(9);
          set_frame(field_7D0);
LABEL_458:
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
LABEL_488:
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
LABEL_490:
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
        if (process() )
          goto LABEL_499;
        return;
      case 217:
        if (process() )
          goto LABEL_1884;
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          scene_play_sfx(31);
        if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
          goto LABEL_1884;
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
                else if ( enemy->x <= x )
                {
LABEL_486:
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
        goto LABEL_490;
      case 220:
        if ( !get_subseq() )
          sub10func();
        if ( char_on_ground_down() )
          goto LABEL_582;
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
          goto LABEL_2813;
        if ( !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
        }
        if ( ((++field_7D0, dX(dir) > 0) || field_7D0 <= 15) && field_7D0 <= 60 )
        {
LABEL_2813:
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
            goto LABEL_239;
        }
        if (process() )
        {
LABEL_241:
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
          goto LABEL_248;
        if ( get_subseq() < 3 && !(get_elaps_frames() % 5) )
        {
          scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, -dir, 1);
        }
        if (process() )
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
        {
LABEL_248:
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
          if (process() )
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
        }
        return;
      default:
        goto LABEL_2803;
    }
  }
}

void char_namazu::func20()
{
  uint16_t cprior = get_cprior();
  uint32_t fflags = get_pframe()->fflags;
  bool cc = (fflags & FF_CANCELLEABLE) != 0;
  bool cu = (fflags & FF_HJC) != 0;
  if ( check_AB_pressed() )
    return;
  if ( cc || cu )
  {
    /*
    v4 = pres_comb;
    if ( v4 >= 0x2BC && v4 < 0x320 )
    {
      vtbl->set_seq(LOWORD(pres_comb));
      input_push_pressed_to_buf((Character *)v1);
      return;
    }*/
    if ( cc || cu )
    {
      if ( char_on_ground() && field_4C4 == 0 )
      {
        if ( cu && cprior >= 10 && hi_jump_after_move() || border_escape_ground() || hi_jump(cprior, cu) || fw_bk_dash_ground(cprior, cu) )
          return;
      }
      else
      {
        if ( border_escape_air() )
          return;
        int8_t mx = (weather_id == WEATHER_TEMPEST) + 2;
        if ( fwd_dash_air(cprior, cu, mx, 2) || bkg_dash_air(cprior, cu, mx, 1) || flying_air(cprior, cu, mx) )
          return;
      }
    }
  }
  if ( field_84C || !cc )
    return;
  if ( !field_524 ) //reversed condition
  {
    if ( char_on_ground_flag() == 0 )
    {
      if ( (keyDown(INP_BC) && keyDown(INP_BC) < 3 || keyHit(INP_BC) && sub_468660(0) && !field_836 ))
      {
        if ( cards_active[0]->id >= 100 || cards_active[0]->id <= 199 ) //reversed condition
        {
          if ( cprior <= 50 )
          {
            if ( (get_seq() > 299) && (field_190 != 3) && field_190 || get_seq() < 300 )
            {
              switch ( cards_active[0]->id )
              {
                case 100:
                  if ( !field_800 )
                  {
                    ++field_4C8;
                    field_800 = 1;
                  }
                  sub_4834F0();
                  sub_488E70();
                  sub_4873B0(502, cprior);
                  break;
                case 101:
                  if ( !field_801 )
                  {
                    ++field_4C8;
                    field_801 = 1;
                  }
                  sub_4834F0();
                  sub_488E70();
                  sub_4873B0(522, cprior);
                  break;
                case 104:
                  if ( !field_800 )
                  {
                    ++field_4C8;
                    field_800 = 1;
                  }
                  sub_4834F0();
                  sub_488E70();
                  sub_4873B0(507, cprior);
                  break;
                case 108:
                  if ( !field_800 )
                  {
                    ++field_4C8;
                    field_800 = 1;
                  }
                  sub_4834F0();
                  sub_488E70();
                  sub_4873B0(512, cprior);
                  break;
                default:
                  goto LABEL_262;
              }
              return;
            }
          }
        }
LABEL_262:
        if ( cprior <= 100 && cards_active[0]->id >= 200 && cards_active[0]->id <= 299 && !keyDown(INP_X_AXIS) )
        {
          if ( (get_seq() > 299) && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
          {
            if ( !(cards_active[0]->id - 201) )
            {
              sub_487370(651, cprior);
              return;
            }
            if ( (cards_active[0]->id - 201) == 6 )
            {
              sub_487370(657, cprior);
              return;
            }
          }
        }
      }
      if ( spell200_seq299_300_field190_0_3() )
      {
        if ( pres_comb & 0x40 )
        {
          if ( skills_1[8] >= 1 )
          {
            if ( cprior <= get_prior(513) || (get_seq() >= 500) && get_seq() <= 599 && !field_800 )
            {
              if ( !field_800 )
              {
                ++field_4C8;
                field_800 = 1;
              }
              sub_4834F0();
              sub_4873B0(513, cprior);
              return;
            }
          }
          if ( skills_1[4] >= 1 )
          {
            if ( cprior <= get_prior(508) || (get_seq() >= 500) && get_seq() <= 599 && !field_800 )
            {
              if ( !field_800 )
              {
                ++field_4C8;
                field_800 = 1;
              }
              sub_4834F0();
              sub_4873B0(508, cprior);
              return;
            }
          }
          if ( cprior <= get_prior(503) || (get_seq() >= 500) && get_seq() <= 599 && !field_800 )
          {
            if ( !field_800 )
            {
              ++field_4C8;
              field_800 = 1;
            }
            sub_4834F0();
            sub_4873B0(503, cprior);
            return;
          }
        }
        if ( pres_comb & 0x20 )
        {
          if ( skills_1[8] >= 1 )
          {
            if ( cprior <= get_prior(512) || (get_seq() >= 500) && get_seq() <= 599 && !field_800 )
            {
              if ( !field_800 )
              {
                ++field_4C8;
                field_800 = 1;
              }
              sub_4834F0();
              sub_4873B0(512, cprior);
              return;
            }
          }
          if ( skills_1[4] >= 1 )
          {
            if ( cprior <= get_prior(507) || (get_seq() >= 500) && get_seq() <= 599 && !field_800 )
            {
              if ( !field_800 )
              {
                ++field_4C8;
                field_800 = 1;
              }
              sub_4834F0();
              sub_4873B0(507, cprior);
              return;
            }
          }
          if ( cprior <= get_prior(502) || (get_seq() >= 500) && get_seq() <= 599 && !field_800 )
          {
            if ( !field_800 )
            {
              ++field_4C8;
              field_800 = 1;
            }
            sub_4834F0();
            sub_4873B0(502, cprior);
            return;
          }
        }
        if ( pres_comb & 4 )
        {
          if ( !skills_1[5] && !skills_1[9] )
          {
            if ( cprior <= get_prior(523) || (get_seq() >= 500) && get_seq() <= 599 && !field_801 )
            {
              if ( !field_801 )
              {
                ++field_4C8;
                field_801 = 1;
              }
              sub_4834F0();
              sub_4873B0(523, cprior);
              return;
            }
          }
        }
        if ( pres_comb & 2 )
        {
          if ( !skills_1[5] && !skills_1[9] )
          {
            if ( cprior <= get_prior(522) || (get_seq() >= 500) && get_seq() <= 599 && !field_801 )
            {
              if ( !field_801 )
              {
                ++field_4C8;
                field_801 = 1;
              }
              sub_4834F0();
              sub_4873B0(522, cprior);
              return;
            }
          }
        }
      }
    }
    else
    {
      if ( (keyDown(INP_BC) && keyDown(INP_BC) < 3 || keyHit(INP_BC) && sub_468660(0) && !field_836 ))
      {
        if ( sub_489F10(cprior) )
          return;
        if ( cards_active[0]->id >= 100 && cards_active[0]->id <= 199 && cprior <= 50 )
        {
          if ( (get_seq() > 299) && (field_190 != 3) && field_190 || get_seq() < 300 )
          {
            switch ( cards_active[0]->id )
            {
              case 100:
                if ( !field_800 )
                {
                  ++field_4C8;
                  field_800 = 1;
                }
                sub_4834F0();
                sub_488E70();
                sub_4873B0(500, cprior);
                break;
              case 101:
                if ( !field_801 )
                {
                  ++field_4C8;
                  field_801 = 1;
                }
                sub_4834F0();
                sub_488E70();
                sub_4873B0(520, cprior);
                break;
              case 102:
                if ( !field_802 )
                {
                  ++field_4C8;
                  field_802 = 1;
                }
                sub_4834F0();
                sub_488E70();
                sub_4873B0(540, cprior);
                break;
              case 103:
                if ( !field_803 )
                {
                  ++field_4C8;
                  field_803 = 1;
                }
                sub_4834F0();
                sub_488E70();
                sub_4873B0(560, cprior);
                break;
              case 104:
                if ( !field_800 )
                {
                  ++field_4C8;
                  field_800 = 1;
                }
                sub_4834F0();
                sub_488E70();
                sub_4873B0(505, cprior);
                break;
              case 105:
                if ( !field_801 )
                {
                  ++field_4C8;
                  field_801 = 1;
                }
                sub_4834F0();
                sub_488E70();
                sub_4873B0(525, cprior);
                break;
              case 106:
                if ( !field_802 )
                {
                  ++field_4C8;
                  field_802 = 1;
                }
                sub_4834F0();
                sub_488E70();
                sub_4873B0(545, cprior);
                break;
              case 107:
                if ( !field_803 )
                {
                  ++field_4C8;
                  field_803 = 1;
                }
                sub_4834F0();
                sub_488E70();
                sub_4873B0(565, cprior);
                break;
              case 108:
                if ( !field_800 )
                {
                  ++field_4C8;
                  field_800 = 1;
                }
                sub_4834F0();
                sub_488E70();
                sub_4873B0(510, cprior);
                break;
              default:
                goto LABEL_68;
            }
            return;
          }
        }
LABEL_68:
        if ( cprior <= 100 && cards_active[0]->id >= 200 && cards_active[0]->id <= 299 && !keyDown(INP_X_AXIS) )
        {
          if ( (get_seq() > 299) && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
          {
            switch ( cards_active[0]->id )
            {
              case 200:
                sub_487370(600, cprior);
                break;
              case 201:
                sub_487370(601, cprior);
                break;
              case 202:
                sub_487370(602, cprior);
                break;
              case 203:
                sub_487370(603, cprior);
                break;
              case 204:
                sub_487370(604, cprior);
                break;
              case 205:
                sub_487370(605, cprior);
                break;
              case 206:
                sub_487370(606, cprior);
                break;
              case 207:
                sub_487370(607, cprior);
                break;
              case 208:
                sub_487370(608, cprior);
                break;
              default:
                goto LABEL_87;
            }
            return;
          }
        }
      }
LABEL_87:
      if ( spell200_seq299_300_field190_0_3() )
      {
        if ( pres_comb & 0x400 )
        {
          if ( skills_1[7] >= 1 )
          {
            if ( cprior <= get_prior(566) || (get_seq() >= 500) && get_seq() <= 599 && !field_803 )
            {
              if ( !field_803 )
              {
                ++field_4C8;
                field_803 = 1;
              }
              sub_4834F0();
              sub_4873B0(566, cprior);
              return;
            }
          }
          if ( cprior <= get_prior(561) || (get_seq() >= 500) && get_seq() <= 599 && !field_803 )
          {
            if ( !field_803 )
            {
              ++field_4C8;
              field_803 = 1;
            }
            sub_4834F0();
            sub_4873B0(561, cprior);
            return;
          }
        }
        if ( pres_comb & 0x200 )
        {
          if ( skills_1[7] >= 1 )
          {
            if ( cprior <= get_prior(565) || (get_seq() >= 500) && get_seq() <= 599 && !field_803 )
            {
              if ( !field_803 )
              {
                ++field_4C8;
                field_803 = 1;
              }
              sub_4834F0();
              sub_4873B0(565, cprior);
              return;
            }
          }
          if ( cprior <= get_prior(560) || (get_seq() >= 500) && get_seq() <= 599 && !field_803 )
          {
            if ( !field_803 )
            {
              ++field_4C8;
              field_803 = 1;
            }
            sub_4834F0();
            sub_4873B0(560, cprior);
            return;
          }
        }
        if ( pres_comb & 0x4000 )
        {
          if ( skills_1[6] >= 1 )
          {
            if ( cprior <= get_prior(546) || (get_seq() >= 500) && get_seq() <= 599 && !field_802 )
            {
              if ( !field_802 )
              {
                ++field_4C8;
                field_802 = 1;
              }
              sub_4834F0();
              sub_4873B0(546, cprior);
              return;
            }
          }
          if ( cprior <= get_prior(541) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_802 )
          {
            if ( !field_802 )
            {
              ++field_4C8;
              field_802 = 1;
            }
            sub_4834F0();
            sub_4873B0(541, cprior);
            return;
          }
        }
        if ( pres_comb & 0x2000 )
        {
          if ( skills_1[6] >= 1 )
          {
            if ( cprior <= get_prior(545) || (get_seq() >= 500) && get_seq() <= 599 && !field_802 )
            {
              if ( !field_802 )
              {
                ++field_4C8;
                field_802 = 1;
              }
              sub_4834F0();
              sub_4873B0(545, cprior);
              return;
            }
          }
          if ( cprior <= get_prior(540) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_802 )
          {
            if ( !field_802 )
            {
              ++field_4C8;
              field_802 = 1;
            }
            sub_4834F0();
            sub_4873B0(540, cprior);
            return;
          }
        }
        if ( pres_comb & 0x40 )
        {
          if ( skills_1[8] >= 1 )
          {
            if ( cprior <= get_prior(511) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_800 )
            {
              if ( !field_800 )
              {
                ++field_4C8;
                field_800 = 1;
              }
              sub_4834F0();
              sub_4873B0(511, cprior);
              return;
            }
          }
          if ( skills_1[4] >= 1 )
          {
            if ( cprior <= get_prior(506) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_800 )
            {
              if ( !field_800 )
              {
                ++field_4C8;
                field_800 = 1;
              }
              sub_4834F0();
              sub_4873B0(506, cprior);
              return;
            }
          }
          if ( cprior <= get_prior(501) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_800 )
          {
            if ( !field_800 )
            {
              ++field_4C8;
              field_800 = 1;
            }
            sub_4834F0();
            sub_4873B0(501, cprior);
            return;
          }
        }
        if ( pres_comb & 0x20 )
        {
          if ( skills_1[8] >= 1 )
          {
            if ( cprior <= get_prior(510) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_800 )
            {
              if ( !field_800 )
              {
                ++field_4C8;
                field_800 = 1;
              }
              sub_4834F0();
              sub_4873B0(510, cprior);
              return;
            }
          }
          if ( skills_1[4] >= 1 )
          {
            if ( cprior <= get_prior(505) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_800 )
            {
              if ( !field_800 )
              {
                ++field_4C8;
                field_800 = 1;
              }
              sub_4834F0();
              sub_4873B0(505, cprior);
              return;
            }
          }
          if ( cprior <= get_prior(500) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_800 )
          {
            if ( !field_800 )
            {
              ++field_4C8;
              field_800 = 1;
            }
            sub_4834F0();
            sub_4873B0(500, cprior);
            return;
          }
        }
        if ( pres_comb & 4 )
        {
          if ( skills_1[5] >= 1 )
          {
            if ( cprior <= get_prior(525) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_801 )
            {
              if ( !field_801 )
              {
                ++field_4C8;
                field_801 = 1;
              }
              sub_4834F0();
              sub_4873B0(525, cprior);
              return;
            }
          }
          if ( !skills_1[5] && !skills_1[9] )
          {
            if ( cprior <= get_prior(521) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_801 )
            {
              if ( !field_801 )
              {
                ++field_4C8;
                field_801 = 1;
              }
              sub_4834F0();
              sub_4873B0(521, cprior);
              return;
            }
          }
        }
        if ( pres_comb & 2 )
        {
          if ( skills_1[5] >= 1 )
          {
            if ( cprior <= get_prior(525) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_801 )
            {
              if ( !field_801 )
              {
                ++field_4C8;
                field_801 = 1;
              }
              sub_4834F0();
              sub_4873B0(525, cprior);
              return;
            }
          }
          if ( !skills_1[5] && !skills_1[9] )
          {
            if ( cprior <= get_prior(520) || (get_seq(), get_seq() >= 500) && get_seq() <= 599 && !field_801 )
            {
              if ( !field_801 )
              {
                ++field_4C8;
                field_801 = 1;
              }
              sub_4834F0();
              sub_4873B0(520, cprior);
              return;
            }
          }
        }
      }
    }
  }
  if ( keyUp(INP_A) && keyUp(INP_A) < 3 || keyDown(INP_A) == 2 || keyHit(INP_A) )
  {
    if ( char_on_ground_flag() )
    {
      if ( get_seq() == 200 && !dY() )
      {
        if ( (dX(dir) > 0 || dX(dir) > 0) && cprior <= get_prior(305) )
        {
          angZ = 0.0;
          set_seq(305);
          goto LABEL_366;
        }
      }
      if ( get_seq() > 299 && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
      {
        if ( dY() > 0 || /*keyhit_Y ?*/dY() > 0 )
        {
          // || keyhit_X == dX(dir)?
          if ( (dX(dir) > 0 || dX(dir) > 0) && cprior <= get_prior(304) )
          {
            angZ = 0.0;set_seq(304);
LABEL_377:
            input->zero_keyhit();
            return;
          }
        }
        if ( (dY() > 0 || /*keyhit_Y ?*/dY() > 0) && cprior <= get_prior(303) )
        {
          angZ = 0.0;
          set_seq(303);
          goto LABEL_377;
        }
        if ( !dY() )
        {

          if ( (dX(dir) > 0 || dX(dir) > 0) && cprior <= get_prior(302) )
          {

            angZ = 0.0;
            set_seq(302);
            goto LABEL_377;
          }
        }
      }
      if ( get_seq() > 299 && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
      {
        if ( dY() >= 0 )
        {
          if ( (dX(dir) < 0 || dX(dir) < 0) && cprior <= get_prior(330) )
          {
            angZ = 0.0;
            set_seq(330);
            goto LABEL_377;
          }
        }
      }
      if ( field_190 && field_190 != 3 )
      {
        if ( get_seq() == 320 )
        {
          angZ = 0.0;
          set_seq(321);
          goto LABEL_377;
        }
        if ( get_seq() == 300 )
        {
          angZ = 0.0;
          set_seq(320);
          goto LABEL_377;
        }
      }
      if ( fabs(x - enemy->x) > 180.0 && cprior <= get_prior(301) && ((get_seq() > 299) && (field_190) != 0 && field_190 != 3 || get_seq() < 300) )
      {
        angZ = 0.0;
        set_seq(301);
      }
      else
      {
        if ( cprior > get_prior(300) )
          goto LABEL_349;
        if ( get_seq() <= 299 || (field_190) == 0 || field_190 == 3 )
        {
          if ( get_seq() >= 300 )
            goto LABEL_349;
        }
        angZ = 0.0;
        set_seq(300);
      }
    }
    else
    {
      if ( get_seq() <= 299 || (field_190) == 0 || field_190 == 3 )
      {
        if ( get_seq() >= 300 )
          goto LABEL_349;
      }
      if ( dY() >= 0 && /*keyhit_Y ?*/dY() >= 0 || keyDown(INP_X_AXIS) || cprior > get_prior(309) )
      {
        if ( dY() <= 0 && /*keyhit_Y ?*/dY() <= 0 || cprior > get_prior(308) )
        {
          if ( !dY() )
          {
            if ( (dX(dir) > 0 || dX(dir) > 0) && cprior <= get_prior(307) )
            {
              angZ = 0.0;
              set_seq(307);
              input->zero_keyhit();
              return;
            }
          }
          if ( cprior <= get_prior(306) )
          {
            if ( (get_seq() > 299) && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
            {
              angZ = 0.0;
              set_seq(306);
              input->zero_keyhit();
              return;
            }
          }
          goto LABEL_349;
        }
        angZ = 0.0;
        set_seq(308);
      }
      else
      {
        angZ = 0.0;
        set_seq(309);
      }
    }
LABEL_366:
    input->zero_keyhit();
    return;
  }
LABEL_349:
  if ( keyUp(INP_B) && keyUp(INP_B) < 3 || keyDown(INP_B) == 2 || keyHit(INP_B) )
  {
    if ( char_on_ground_flag() )
    {
      if ( get_seq() == 200 && !dY() )
      {
        if (dX(dir) > 0 || dX(dir) > 0 )
        {
          angZ = 0.0;
          set_seq(408);
          input->zero_keyhit();
          return;
        }
      }
      if ( get_seq() > 299 && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
      {
        if ( (dY() > 0 || /*keyhit_Y ?*/dY() > 0) && ((dX(dir) > 0) || dX(dir) > 0) && spell_energy >= 200 && cprior <= get_prior(402) || (dY() > 0 || /*keyhit_Y ?*/dY() > 0) && spell_energy >= 200 && cprior <= get_prior(402) )
        {
          angZ = 0.0;
          set_seq(402);
          input->zero_keyhit();
          return;
        }
        if ( dY() || (dX(dir) <= 0) && dX(dir) <= 0 )
        {
LABEL_459:
          if ( spell_energy >= 200 && cprior <= get_prior(400) )
          {
            if ( get_seq() > 299 )
            {
              if ( field_190 )
              {
                if ( field_190 != 3 )
                  goto LABEL_465;
              }
            }
            if ( get_seq() < 300 )
              goto LABEL_465;
          }
          goto LABEL_482;
        }
        if ( spell_energy >= 200 )
        {
          if ( cprior <= get_prior(400) )
          {
LABEL_465:
            angZ = 0.0;
            set_seq(400);
            input->zero_keyhit();
            return;
          }
          goto LABEL_459;
        }
      }
    }
    else if ( get_seq() > 299 && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
    {
      if ( dY() > 0 || /*keyhit_Y ?*/dY() > 0 )
      {
        if ( spell_energy < 200 )
          goto LABEL_482;
        if ( cprior <= get_prior(406) )
        {
          angZ = 0.0;
          set_seq(406);
          input->zero_keyhit();
          return;
        }
      }
      if ( spell_energy >= 200 && cprior <= get_prior(404) )
      {
        if ( (get_seq() > 299) && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
        {
          angZ = 0.0;
          set_seq(404);
          input->zero_keyhit();
          return;
        }
      }
    }
  }
LABEL_482:
  if ( keyUp(INP_C) && keyUp(INP_C) < 3 || keyDown(INP_C) == 2 || keyHit(INP_C) )
  {
    if ( char_on_ground_flag() )
    {
      if ( get_seq() == 200 && !dY() )
      {
        if (dX(dir) > 0 ||dX(dir) > 0 )
        {
          angZ = 0.0;
          set_seq(418);
          input->zero_keyhit();
          return;
        }
      }
      if ( get_seq() > 299 && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
      {
        if ( (dY() > 0 || /*keyhit_Y ?*/dY() > 0) && ((dX(dir) > 0) || dX(dir) > 0) && spell_energy >= 200 && cprior <= get_prior(412) || (dY() > 0 || /*keyhit_Y ?*/dY() > 0) && spell_energy >= 200 && cprior <= get_prior(412) )
        {
          angZ = 0.0;
          set_seq(412);
          input->zero_keyhit();
          return;
        }
        if ( !dY() )
        {
          if (dX(dir) > 0 ||dX(dir) > 0 )
          {
            if ( spell_energy < 200 )
              return;
            if ( cprior <= get_prior(411) )
            {
              angZ = 0.0;
              set_seq(411);
              input->zero_keyhit();
              return;
            }
          }
        }
        if ( spell_energy >= 200 && cprior <= get_prior(410) )
        {
          if ( (get_seq() > 299) && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
          {
            angZ = 0.0;
            set_seq(410);
            input->zero_keyhit();
          }
        }
      }
    }
    else
    {
      if ( get_seq() > 299 && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
      {
        if ( dY() > 0 )
          goto LABEL_543;
        if ( (dX(dir) > 0 || dX(dir) > 0) && spell_energy >= 200 && cprior <= get_prior(415) )
        {
          angZ = 0.0;
          set_seq(415);
          input->zero_keyhit();
          return;
        }
        if ( dY() > 0 )
        {
LABEL_543:
          if ( spell_energy < 200 )
            return;
          if ( cprior <= get_prior(416) )
          {
            angZ = 0.0;
            set_seq(416);
            input->zero_keyhit();
            return;
          }
        }
      }
      if ( spell_energy >= 200 && cprior <= get_prior(414) )
      {
        if ( (get_seq() > 299) && (field_190) != 0 && field_190 != 3 || get_seq() < 300 )
        {
          angZ = 0.0;
          set_seq(414);
          input->zero_keyhit();
        }
      }
    }
  }
}


void char_namazu::func24(int a2)
{
  /*
  if ( a2 > 400 )
  {
    if ( a2 == 401 )
LABEL_22:
      //v11 = get_seq() < 0x2BCu;
  }*/
  /*else*/ if ( a2 == 400 )
  {
    play_sfx(2);
    x = 800.0;
    y = 960.0;
    set_seq(780);
    v_inerc = -15.0;
  }
  else
  {
    switch ( a2 )
    {
      case 1:
        field_7D0 = 640;
        x = 100.0;
        field_7D2 = 0;
        goto LABEL_5;
      case 2:
      case 11:
LABEL_5:
        //WHATIS?
        //sub_429040(&camera_transform, ...)
        //etc..
        //sub_429040(&camera_transform, 1, 640.0);
        //sub_429060(&camera_transform, 1, 0.0);
        //sub_429080(&camera_transform, 1, 1.0);
        //sub_4290A0(&camera_transform);
        break;
      case 3:
        //sub_429040(&camera_transform, 0, 640.0);
        //sub_429060(&camera_transform, 0, 0.0);
        //sub_429080(&camera_transform, 0, 1.0);
        break;
      case 4:
        //sub_429040(&camera_transform, 1, 640.0);
        //sub_429060(&camera_transform, 1, 0.0);
        //sub_429080(&camera_transform, 1, 1.0);
        break;
      case 5:
        x = 0.0;
        y = 0.0;
        reset_forces();
        set_seq(0);
        break;
      case 6:
        set_seq(790);
        set_subseq(2);
        x = 480.0;
        y = 800.0;
        h_inerc = 0.0;
        v_inerc = 0.0;
        v_force = 0.25;
        break;
      case 7:
      case 51:
        //v3 = __SETP__(get_seq(), 0);
        break;
      case 8:
        set_seq(139);
        float t[3];
        t[0] = 0.0;
        t[1] = 0.0;
        t[2] = 0.0;
        addbullet(this, NULL,999, x, y, 1, 1, t, 3);
        break;
      case 9:
        set_seq(795);
        x = 70.0;
        y = 240.0;
        reset_forces();
        h_inerc = 15.0;
        v_inerc = 0.0;
        v_force = 0.5;
        break;
      case 50:
        x = 480.0;
        y = 960.0;
        v_force = 0.1;
        set_seq(797);
        break;
      case 101:
        x = 800.0;
        y = 960.0;
        v_force = 0.1;
        set_seq(798);
        break;
      case 102:
      case 106:
      case 111:
      case 121:
        //goto LABEL_22;
      case 103:
        weather_setted_change(WEATHER_SNOW);
        field_80D = 1;
        field_810 = 0;
        field_814 = 180;
        break;
      case 105:
        y = 960.0;
        x = (double)(250 * dir) + x;
        dir = -dir;
        set_seq(795);
        break;
      case 110:
        set_seq(796);
        break;
      case 113:
        weather_setted_change(WEATHER_SNOW);
        break;
      case 120:
        set_seq(796);
        x = 100.0;
        dir = 1;
        y = 0.0;
        h_inerc = 7.0;
        v_inerc = 15.0;
        v_force = 0.30000001;
        break;
      default:
        return;
    }
  }
}


void char_namazu::set_seq_params()
{
  if ( get_seq() <= 330 )
  {
    if ( get_seq() == 330 )
    {
LABEL_30:
      if ( !field_49A )
        reset_forces();
      field_190 = 0;
      field_194 = 1;
      return;
    }
    if ( get_seq() <= 79 )
    {
      if ( get_seq() >= 70 )
      {
LABEL_10:
        field_571 = 1;
        field_572 = 1;
        field_7D0 = 0;
        h_inerc = -field_1A4;
        v_inerc = field_1A8 * 0.5;
        v_force = 0.2;
        if ( -field_1A4 > 0.0 )
          field_7D0 = 1;
        if ( -field_1A4 < 0.0 )
          field_7D0 = -1;
        angZ = 0.0;
      }
      else
      {
        switch ( get_seq() )
        {
          case 4:
            h_inerc = 4.0;
            break;
          case 5:
            h_inerc = -4.0;
            break;
          case 50:
          case 51:
          case 52:
          case 53:
          case 54:
          case 55:
          case 56:
          case 57:
          case 58:
          case 59:
          case 60:
          case 61:
          case 62:
          case 63:
          case 64:
          case 65:
          case 66:
          case 67:
            field_1A4 = 0.0;
            field_7D0 = 0;
            field_1A8 = 0.0;
            field_7D2 = 0;
            angZ = 0.0;
            field_571 = 1;
            field_572 = 1;
            h_inerc = -6.0;
            v_inerc = 6.0;
            v_force = 0.2;
            break;
          default:
            goto LABEL_87;
        }
      }
      return;
    }
    switch ( get_seq() )
    {
      case 88:
      case 89:
        goto LABEL_10;
      case 214:
        goto LABEL_16;
      case 217:
        reset_ofs();
LABEL_16:
        field_7D6 = 0;
        h_inerc = 0.0;
        v_inerc = 0.0;
        v_force = 0.60000002;
        x_off = 0.0;
        y_off = 95.0;
        field_7DC = 9.0;
        field_7EC = 0.0;
        return;
      case 300:
      case 301:
      case 303:
      case 322:
        goto LABEL_30;
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
        goto LABEL_24;
      case 308:
        field_194 = 4;
        goto LABEL_24;
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
        reset_forces();
        field_190 = 0;
        field_194 = 1;
        return;
      case 321:
        reset_forces();
        goto LABEL_29;
      default:
        break;
    }
LABEL_87:
    char_c::set_seq_params();
    return;
  }
  if ( get_seq() <= 657 )
  {
    if ( get_seq() == 657 )
    {
LABEL_73:
      field_190 = 1;
      reset_forces();
      field_7D0 = 0;
      field_7D2 = 0;
      return;
    }
    switch ( get_seq() )
    {
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
        goto LABEL_62;
      case 408:
        h_inerc = 14.5;
        v_inerc = 0.0;
        goto LABEL_39;
      case 409:
        v_force = 0.34999999;
LABEL_39:
        field_49A = 0;
        field_7D0 = 0;
        field_190 = 0;
        field_194 = 1;
        return;
      case 414:
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
      case 415:
        field_7D4 = 0;
        goto LABEL_63;
      case 418:
        h_inerc = 15.0;
LABEL_29:
        field_194 = 1;
        field_190 = 0;
        return;
      case 500:
      case 501:
        field_18C = 0;
        reset_forces();
        goto LABEL_45;
      case 502:
      case 503:
        field_18C = 0;
        h_inerc = h_inerc * 0.2000000029802322;
        v_inerc = 0.2000000029802322 * v_inerc;
        v_force = 0.0;
        goto LABEL_45;
      case 505:
      case 506:
        field_18C = 4;
        reset_forces();
        goto LABEL_45;
      case 507:
      case 508:
        field_18C = 4;
        h_inerc = h_inerc * 0.2000000029802322;
        v_inerc = 0.2000000029802322 * v_inerc;
        v_force = 0.0;
LABEL_45:
        field_49A = 0;
        field_7D0 = 0;
        field_190 = 1;
        return;
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
        h_inerc = h_inerc* 0.2000000029802322;
        v_inerc = 0.2000000029802322 * v_inerc;
        v_force = 0.0;
        dash_angle = 0.0;
        return;
      case 520:
      case 521:
        field_18C = 1;
        goto LABEL_52;
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
LABEL_52:
        reset_forces();
        field_190 = 0;
        field_49A = 0;
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
      case 545:
      case 546:
        field_18C = 6;
        field_190 = 0;
        reset_forces();
        goto LABEL_57;
      case 547:
        field_190 = 0;
        not_charge_attack = 0;
        field_18C = 2;
        field_194 = 1;
        return;
      case 560:
      case 561:
        field_18C = 3;
        goto LABEL_60;
      case 562:
        field_18C = 3;
LABEL_62:
        field_7D6 = 0;
LABEL_63:
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
      case 567:
        field_18C = 7;
LABEL_60:
        field_194 = 1;
        field_190 = 0;
        reset_forces();
        not_charge_attack = 1;
        return;
      case 599:
        field_190 = 1;
        reset_forces();
        goto LABEL_66;
      case 600:
      case 602:
      case 605:
      case 606:
        goto LABEL_68;
      case 601:
      case 604:
      case 608:
      case 610:
      case 611:
        field_7D0 = 0;
        field_7D2 = 0;
LABEL_68:
        field_190 = 1;
        goto LABEL_69;
      case 603:
        field_7D0 = 0;
        dash_angle = 0.0;
        field_7D2 = 0;
        field_190 = 1;
        reset_forces();
        return;
      case 607:
        goto LABEL_73;
      case 612:
      case 615:
        field_190 = 1;
        reset_forces();
LABEL_57:
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        field_7D8 = 0;
        not_charge_attack = 1;
        return;
      case 613:
LABEL_24:
        field_190 = 0;
        not_charge_attack = 1;
        return;
      case 651:
        v_force = 0.0;
        field_7D0 = 0;
        field_7D2 = 0;
        field_190 = 1;
        v_inerc = v_inerc * 0.2000000029802322;
        h_inerc = 0.2000000029802322 * h_inerc;
        return;
      default:
        goto LABEL_87;
    }
    goto LABEL_87;
  }
  switch ( get_seq() )
  {
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
    case 740:
LABEL_69:
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
      goto LABEL_80;
    case 709:
LABEL_80:
      field_7D0 = 0;
      break;
    case 710:
    case 720:
      field_190 = 0;
      reset_forces();
LABEL_66:
      field_7D0 = 0;
      field_7D2 = 0;
      field_7D6 = 0;
      field_7D8 = 0;
      break;
    case 725:
      field_7D0 = 0;
      h_inerc = 4.0;
      break;
    case 726:
      field_7D0 = 0;
      h_inerc = -4.0;
      break;
    case 730:
    case 731:
      field_190 = 0;
      reset_forces();
      break;
    case 797:
    case 798:
      field_7D0 = 0;
      play_sfx(50);
      break;
    default:
      goto LABEL_87;
  }
}
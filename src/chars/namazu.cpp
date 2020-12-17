#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "namazu.h"
#include <math.h>

#include <iostream>

//"Constructor" ?
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

//Initialize some variables
void char_namazu::init_vars()
{
	field_138 = -6.0;
	field_890 = 0;
	field_894 = 0;
	field_898 = 0;
	field_89C = 0;
	char_c::init_vars();
}

//Associated with bullets
/*
c_bullet *char_namazu::new_bullet()
{
    c_bullet *tmp = new namazu_bullets();
    return tmp;
}*/

//sub_5586E0()
/* void sub_5586E0() {
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

void char_namazu::func10() {
  
}

//Func20
void char_namazu::func20()
{
	//pre switch statements

    //note: taken from marisa.cpp
    //main big switch statement
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
                if ( border_escape_air() )
                  return;

                int8_t mx = (weather_id == WEATHER_TEMPEST) + 2;
                if ( fwd_dash_air(cprior, cu, mx, 2)
                        || bkg_dash_air(cprior, cu, mx, 1)
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
                                //namazu has no more cases?
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
                                case 101:
                                    if( field_800 == 0)
                                    {
                                      field_4C8++;
                                      field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(520, cprior);
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
                                    if ( field_800 == 0)
                                    {
                                      field_4C8++;
                                      field_800 = 1;
                                    }
                                    sub_4834F0();
                                    sub_488E70();
                                    sub_4873B0(525, cprior);
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
                            if ( skills_1[7] >= 1 )
                            {
                                if ( cprior <= get_prior(566) || (sq >= 500 && sq <= 599 && field_803 == 0))
                                {
                                    if ( field_803 == 0 )
                                    {
                                        field_4C8++;
                                        field_803 = 1;
                                    }
                                    sub_4834F0();
                                    sub_4873B0( 566, cprior);
                                    return;
                                }
                            }
                            if (cprior <= get_prior(561) || (sq >= 500 && sq <= 599 && field_803 == 0) )
                            {
                                if( field_803 == 0)
                                {
                                  field_4C8++;
                                  field_803 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0(561, cprior);
                                return;
                            }
                          }
                          if ( pres_comb & PCOMB_623B )
                          {
                            if( skills_1[7] >= 1)
                            {
                              if ( cprior <= get_prior(565) || (sq >= 500 && sq <= 599 && field_803 == 0))
                              {
                                if ( field_803 == 0)
                                {
                                  field_4C8++;
                                  field_803 = 1;
                                }
                                sub_4834F0();
                                sub_4873B0(565, cprior);
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
                              sub_4873B0(560, cprior);
                              return;
                            }
                          }
                          /*if ( pres_comb & 0x4000 ) //what is 0x4000?
                          {
                              if ( skills_1[6] >= 1)
                              {
                                if ( cprior <= get_prior(546) || (sq >= 500 && sq <= 599 && field_802 == 0))
                                {
                                  if ( field_802 == 0)  
                                  {
                                    field_4C8++;
                                    field_802 = 1;
                                  }  
                                sub_4834F0();
                                sub_4873B0(546, cprior);
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
                            sub_4873B0(541, cprior);
                            return;
                          }
                        }*/

                        //if ( pres_comb & 0x2000) //what is 0x2000?

                        if ( pres_comb & PCOMB_214C )
                        {
                          if ( skills_1[8] >= 1)
                          {
                            if ( cprior <= get_prior(511) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                              if ( field_800 == 0)
                              {
                                field_4C8++;
                                field_800 =1;
                              }
                              sub_4834F0();
                              sub_4873B0(511, cprior);
                              return;
                            }
                          }
                          if ( skills_1[4] >= 1)
                          {
                            if ( cprior <= get_prior(506) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                              if ( field_800 == 0)
                              {
                                field_4C8++;
                                field_800 = 1;
                              }
                              sub_4834F0();
                              sub_4873B0(506, cprior);
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
                            sub_4873B0(501, cprior);
                            return;
                          }
                        }
                        if ( pres_comb & PCOMB_214B)
                        {
                          if ( skills_1[8] >= 1)
                          {
                            if ( cprior <= get_prior(510) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                              if ( field_800 == 0)
                              {
                                field_4C8++;
                                field_800 = 1;
                              }
                              sub_4834F0();
                              sub_4873B0(510, cprior);
                              return;
                            }
                          }
                          if ( skills_1[4] >= 1)
                          {
                            if ( cprior <= get_prior(505) || (sq >= 500 && sq <= 599 && field_800 == 0))
                            {
                              if ( field_800 == 0)
                              {
                                field_4C8++;
                                field_800 = 1;
                              }
                              sub_4834F0();
                              sub_4873B0(505, cprior);
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
                            sub_4873B0(500, cprior);
                            return;
                          }
                        }
                        if ( pres_comb & PCOMB_236C )
                        {
                          if ( skills_1[5] >= 1)
                          {
                            if ( cprior <= get_prior(525) || (sq >= 500 && sq <= 599 && field_801 == 0))
                            {
                              if ( field_801 == 0)
                              {
                                field_4C8++;
                                field_801 = 1;
                              }
                              sub_4834F0();
                              sub_4873B0(525, cprior);
                              return;
                            }
                          }
                          if ( skills_1[5] == 0 && skills_1[9] == 0)
                          {
                            if ( cprior <= get_prior(521) || (sq >= 500 && sq <= 599 && field_801 == 0))
                            {
                              if ( field_801 == 0)
                              {
                                field_4C8++;
                                field_801 = 1;
                              }
                              sub_4834F0();
                              sub_4873B0(521, cprior);
                              return;
                            }
                          }
                        }

                        if ( pres_comb & PCOMB_236B )
                        {
                          if (skills_1[5] >= 1)
                          {
                            if ( cprior <= get_prior(525) || (sq >= 500 && sq <= 599 && field_801 == 0))
                            {
                              if ( field_801 == 0)
                              {
                                field_4C8++;
                                field_801 =1;
                              }
                              sub_4834F0();
                              sub_4873B0(525, cprior);
                              return;
                            }
                          }
                          if ( skills_1[5] == 0 && skills_1[9] == 0)
                          {
                            if ( cprior <= get_prior(520) || (sq >= 500 && sq <= 599 && field_801 == 0))
                            {
                              if ( field_801 == 0)
                              {
                                field_4C8++;
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
                  if ((keyUp(INP_A) && keyUp(INP_A) < 3) || keyDown(INP_A) == 2 || keyHit(INP_A))
                  {
                    if (char_on_ground_flag()) // On Ground
                    {
                      if ( sq == 200 && dY() == 0 &&
                             dX(dir) > 0 &&
                             cprior <= get_prior(305) )  // 66A
                      {
                          angZ = 0.0;
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

/*
void char_namazu::func24() {
	if (  )
}  */


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
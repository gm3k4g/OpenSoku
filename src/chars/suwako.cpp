#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "suwako.h"
#include <math.h>

//"Constructor" ?
char_suwako::char_suwako(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_SUWAKO;
	pgp->load_dat("suwako",pal);
	char_loadsfx("suwako");
	cards_load_cards(&chr_cards,"suwako");
	load_face("suwako");
	load_spells("suwako");
	stand_gfx->init(this,"suwako");
}

void char_suwako::init_vars()
{
  field_138 = -6.0;
  char_c::init_vars();
  float t[3];
  t[0] = 0.0;
  t[1] = 0.0;
  t[2] = 4.0;
  field_890 = 0;
  field_891 = 0;
  field_894 = 0;
  field_898 = 0;
  field_89C = 0;
  field_89D = 0;
  field_8A0 = 0;
  field_8A4 = 0;
  addbullet(this, NULL, 990, x, y, dir, -1, t, 3);
}
/*
c_bullet *char_suwako::new_bullet()
{
    c_bullet *tmp = new suwako_bullets();
    return tmp;
}
*/
void char_suwako::func10()
{

}

void char_suwako::func20()
{

}

void char_suwako::set_seq_params()
{
  double v9 = 0.0;

  if ( get_seq() > 501 )
  {
    if ( get_seq() > 771 )
    {
      if ( (get_seq() - 772) )
      {
        if ( !((get_seq() - 772) - 25) )
        {
          field_7D0 = 0;
          play_sfx(5);
          return;
        }
        if ( ((get_seq() - 772) - 25) == 1 )
        {
          play_sfx(5);
          reset_forces();
          h_inerc = 15.0;
          field_7D0 = 0;
          v_inerc = 0.0;
          v_force = 0.5;
          return;
        }
        goto LABEL_102;
      }
    }
    else if ( get_seq() != 771 )
    {
      switch ( get_seq() )
      {
        case 502:
        case 503:
          field_18C = 0;
          field_7D0 = 0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.5;
          field_190 = 1;
          v_inerc = v_inerc * 0.2000000029802322;
          v_force = 0.0;
          return;
        case 505:
        case 506:
          not_charge_attack = 0;
          field_18C = 4;
          reset_forces();
          field_49A = 0;
          field_7D0 = 0;
          field_194 = 1;
          field_190 = 1;
          return;
        case 510:
        case 511:
        case 512:
        case 513:
          field_7DC = 0.0;
          field_18C = 8;
          field_7D0 = 0;
          not_charge_attack = 1;
          reset_forces();
          field_194 = 0;
          field_190 = 0;
          field_49A = 0;
          return;
        case 520:
        case 522:
          not_charge_attack = 0;
          field_18C = 1;
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_7D0 = 0;
          field_194 = 4;
          return;
        case 521:
          not_charge_attack = 0;
          field_18C = 1;
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_7D0 = 0;
          field_194 = 99;
          return;
        case 525:
        case 526:
          not_charge_attack = 0;
          field_18C = 5;
          reset_forces();
          //v12 = __OFSUB__(skills_1[5], 3);
          //v11 = (char)(skills_1[5] - 3) < 0;
          field_194 = 10;
          field_190 = 0;
          field_49A = 0;
          field_7D0 = 0;
          if ( (skills_1[5] - 3) < 0/*!((unsigned __int8)v11 ^ v12)*/ )
            field_51C = 2;
          return;
        case 527:
        case 528:
          v_force = 0.0;
          not_charge_attack = 0;
          field_190 = 0;
          field_49A = 0;
          field_7D0 = 0;
          field_18C = 5;
          field_194 = 10;
          v_inerc = v_inerc * 0.2000000029802322;
          return;
        case 530:
        case 531:
          not_charge_attack = 0;
          field_18C = 9;
          reset_forces();
          goto LABEL_60;
        case 532:
        case 533:
          v_force = 0.0;
          not_charge_attack = 0;
          field_18C = 9;
          v_inerc = v_inerc * 0.2000000029802322;
          h_inerc = 0.2000000029802322 * h_inerc;
LABEL_60:
          field_194 = 0;
          field_190 = 0;
          field_49A = 0;
          field_7D0 = 0;
          return;
        case 540:
        case 541:
          field_18C = 2;
          field_190 = 0;
          field_194 = 1;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 542:
        case 543:
          field_18C = 2;
          field_190 = 0;
          field_194 = 1;
          not_charge_attack = 1;
          return;
        case 545:
        case 546:
          field_18C = 6;
          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 547:
        case 548:
          field_18C = 6;
          field_7DC = 0.0;
          field_190 = 0;
          v_force = 0.0;
          v9 = 0.2000000029802322;
LABEL_45:
          not_charge_attack = 1;
          h_inerc = h_inerc * v9;
          v_inerc = v9 * v_inerc;
          return;
        case 550:
        case 551:
          field_18C = 10;
          field_7D0 = 0;
          field_7D2 = 0;
          field_194 = 3;
          if ( skills_1[10] >= 2 )
            field_194 = 4;
          if ( skills_1[10] >= 3 )
            field_194 = 5;
          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 552:
        case 553:
          field_18C = 10;
          field_7D0 = 0;
          field_7D2 = 0;
          field_194 = 3;
          if ( skills_1[10] >= 2 )
            field_194 = 4;
          if ( skills_1[10] >= 3 )
            field_194 = 5;
          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 560:
        case 561:
        case 562:
        case 563:
          field_18C = 3;
          goto LABEL_77;
        case 565:
        case 566:
        case 567:
        case 568:
          field_18C = 7;
          goto LABEL_77;
        case 570:
        case 571:
          field_18C = 11;
LABEL_77:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          not_charge_attack = 1;
          return;
        case 600:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 0;
          reset_forces();
          return;
        case 601:
          field_190 = 0;
          field_7D0 = 0;
          reset_forces();
          return;
        case 602:
        case 652:
          field_7DC = 300.0;
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 0;
          dash_angle = -350.0;
          reset_forces();
          return;
        case 603:
        case 653:
          field_7DC = 0.0;
          field_7D0 = 0;
          dash_angle = 0.0;
          field_7D2 = 0;
          goto LABEL_84;
        case 604:
        case 654:
          field_7D0 = 0;
          field_190 = 0;
          reset_forces();
          return;
        case 605:
        case 655:
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_194 = 1;
          return;
        case 606:
        case 656:
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          return;
        case 608:
          field_7D0 = 0;
          goto LABEL_47;
        case 609:
        case 659:
          field_7D0 = 0;
          field_7D2 = 0;
          field_188 = 0;
          field_190 = 1;
          reset_forces();
          return;
        case 610:
        case 611:
          field_7D0 = 0;
          field_7D2 = 0;
LABEL_84:
          field_190 = 1;
          reset_forces();
          return;
        case 612:
          field_190 = 1;
          reset_forces();
          field_7DC = 0.0;
          return;
        case 613:
          field_190 = 0;
          not_charge_attack = 1;
          return;
        case 615:
          field_190 = 1;
          reset_forces();
          field_7D0 = 0;
          field_7D2 = 0;
          field_7D6 = 0;
          field_7D8 = 0;
          not_charge_attack = 1;
          return;
        case 619:
          field_7D0 = 0;
          field_7D2 = 0;
          reset_forces();
          return;
        case 651:
LABEL_40:
          v_force = 0.0;
          field_190 = 0;
          field_7D0 = 0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          return;
        case 657:
          field_7D0 = 0;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          dash_angle = v_inerc;
          field_7DC = h_inerc;
          v_force = 0.0;
          return;
        case 707:
LABEL_27:
LABEL_28:
          reset_forces();
          return;
        case 708:
          reset_forces();
          field_7D0 = 0;
          return;
        case 710:
        case 711:
        case 720:
        case 721:
        case 730:
        case 731:
        case 740:
        case 741:
        case 742:
          field_190 = 0;
          reset_forces();
          return;
        default:
          goto LABEL_102;
      }
      goto LABEL_102;
    }
    field_7D0 = 0;
    field_7DC = 0.0;
    reset_forces();
    return;
  }
  if ( get_seq() < 500 )
  {
    if ( get_seq() > 207 )
    {
      switch ( get_seq() )
      {
        case 214:
          return;
        case 217:
          reset_ofs();
          h_inerc = 0.0;
          field_7D6 = 0;
          v_inerc = 0.0;
          v_force = 0.60000002;
          x_off = 0.0;
          y_off = 95.0;
          field_7DC = 11.5;
          field_7EC = 0.0;
          return;
        case 218:
        case 219:
          goto LABEL_28;
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
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_194 = 1;
          return;
        case 304:
          field_49A = 0;
          field_194 = 1;
          goto LABEL_22;
        case 305:
          field_194 = 4;
          h_inerc = 9.0;
          field_190 = 0;
          return;
        case 306:
          field_194 = 4;
          field_190 = 0;
          return;
        case 307:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 0;
          field_194 = 4;
          h_inerc = h_inerc * 0.2000000029802322;
          v_inerc = 0.2000000029802322 * v_inerc;
          v_force = 0.0;
          return;
        case 308:
          play_sfx(0);
          field_194 = 1;
          field_190 = 0;
          goto LABEL_27;
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
        case 321:
          if ( !field_49A )
            reset_forces();
          field_190 = 0;
          field_194 = 4;
          return;
        case 322:
          reset_forces();
          field_194 = 1;
          field_190 = 0;
          return;
        case 331:
        case 332:
          field_49A = 0;
          field_190 = 0;
          field_194 = 1;
          reset_forces();
          return;
        case 400:
        case 402:
LABEL_22:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          not_charge_attack = 1;
          return;
        case 401:
        case 403:
        case 410:
        case 411:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          not_charge_attack = 1;
          return;
        case 404:
          v_force = 0.0;
          field_190 = 0;
          field_7D0 = 0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.300000011920929;
          v_inerc = 0.300000011920929 * v_inerc;
          return;
        case 405:
        case 406:
        case 415:
          goto LABEL_40;
        case 408:
        case 418:
          field_190 = 0;
          h_inerc = 9.0;
          field_49A = 0;
          field_194 = 1;
          not_charge_attack = 1;
          return;
        case 412:
          field_190 = 0;
          reset_forces();
          field_7D0 = 0;
          field_891 = 0;
          not_charge_attack = 1;
          return;
        case 414:
          v_force = 0.0;
          field_190 = 0;
          field_7D0 = 0;
          field_891 = 0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.1000000014901161;
          v_inerc = 0.1000000014901161 * v_inerc;
          return;
        case 416:
          v_force = 0.0;
          field_190 = 0;
          field_7D0 = 0;
          v9 = 0.1000000014901161;
          goto LABEL_45;
        default:
          break;
      }
    }
    else
    {
      if ( get_seq() >= 206 )
      {
        reset_forces();
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D4 = 0;
        return;
      }
      if ( !(get_seq() - 4) || (get_seq() - 4) == 1 )
      {
        h_inerc = 0.0;
        return;
      }
    }
LABEL_102:
    char_c::set_seq_params();
    return;
  }
  not_charge_attack = 0;
  field_18C = 0;
LABEL_47:
  reset_forces();
  field_190 = 0;
  field_49A = 0;
}
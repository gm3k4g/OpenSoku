#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "reimu.h"
#include <math.h>

//"Constructor" ?
char_reimu::char_reimu(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_REIMU;
	pgp->load_dat("reimu",pal);
	char_loadsfx("reimu");
	cards_load_cards(&chr_cards,"reimu");
	load_face("reimu");
	load_spells("reimu");
	stand_gfx->init(this,"reimu");
}

//Initialize some variables
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
void char_reimu::func10()
{

}
/*
void char_reimu::func20()
{

}
*/

void char_reimu::set_seq_params()
{
  if ( get_seq() <= 300 )
  {
    if ( get_seq() == 300 )
    {

      if ( !field_49A )
        reset_forces();
      field_190 = 0;
      field_8B8 = 0;
      field_194 = 1;
    }
    else
    {
      int v_scene = 5;
      uint32_t sq = get_seq();
      switch (sq)
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
          v_inerc = field_1A8;
          field_7D0 = 7;
          v_force = 0.5;
          field_572 = 1;
          angZ = 0.0;
          field_571 = 1;
          return;
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
          field_7D0 = 7;
          v_force = 0.80000001;
          field_572 = 1;
          angZ = 0.0;
          field_571 = 1;
          return;
        case 74:
        case 75:
          h_inerc = -field_1A4;
          v_inerc = field_1A8;
          v_force = 0.80000001;
          field_572 = 1;
          angZ = 0.0;
          field_571 = 1;
          return;
        case 76:
          field_571 = 1;
          field_572 = 1;
          weather_forecast_next();
          v_scene = 5;
          do
          {
            scene_add_effect(this, 201, x, y + 100.0, dir, 1);
            --v_scene;
          }
          while(v_scene);
          ++field_7D0;
          y = y + 100.0;
          hit_stop = 5;
          x_delta = 0;
          y_delta = 85;
          scene_add_effect(this, 38, x - ((double)50 * (char)dir), y, dir, 1);
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
          field_571 = 1;
          h_inerc = -field_1A4;
          field_572 = 1;
          x_delta = 0;
          v_inerc = field_1A8;
          y_delta = 85;
          v_force = 0.80000001;
          x_off = 0.0;
          y_off = 85.0;
          angZ = 0.0;
          break;
        case 78:
          field_571 = 1;
          field_572 = 1;
          weather_forecast_next();
          v_scene = 5;
          do
          {
            scene_add_effect(this, 201, x, y + 100.0, dir, 1);
            --v_scene;
          }
          while(v_scene);
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
          v_scene = 5;
          do
          {
            scene_add_effect(this, 201, x, y + 100.0, dir, 1);
            --v_scene;
          }
          while(v_scene);
          if ( !field_890 )
          {
            x = dir;
            field_890 = 1;
            //addbullet(this, 951, x, y, x, 1, 0, 0);
          }
          scene_add_effect(this, 58, x, 0.0, dir, -1);
          angZ = 0.0;
          return;
        case 145:
          h_inerc = -10.0;
          v_inerc = 14.0;
          field_7D0 = 7;
          v_force = 0.5;
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
              char_c::set_seq_params();
    return;
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
      uint32_t sq = get_seq();
      switch (sq)
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
        field_7D0 = 0;
        field_7D2 = 0;
        field_190 = 1;
        reset_forces();
        field_8B8 = 1;
        return;
      case 604:
        field_190 = 1;
        reset_forces();
        field_8B8 = 1;
        return;
      case 607:
      case 657:
        field_7DC = 0.0;
        field_190 = 0;
        reset_forces();
        field_8B8 = 1;
        return;
      case 608:
      case 658:
        field_7D4 = 0;
        field_7D0 = 0;
        field_7D2 = 0;
        field_190 = 1;
        reset_forces();
        field_8B8 = 1;
        return;
      case 609:
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D8 = 0;
        field_190 = 1;
        reset_forces();
        /*
        sub_469450(this, 0, 0, 60);
        sub_483570();
        */
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
        /*
        sub_469450(this, 0, 0, 60);
        sub_483570();
        */
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
        field_7D0 = 0;
        field_7D2 = 0;
        field_190 = 1;
        reset_forces();
        field_8B8 = 1;
        return;
      case 695:
      case 696:
      case 697:
      case 698:
        field_8B8 = 0;
            char_c::set_seq_params();
    return;
      case 710:
      case 711:
      case 730:
      case 731:
      case 740:
        reset_forces();
                field_7D0 = 0;
        return;
      case 720:
      case 721:
        reset_forces();
        return;
      case 760:
        reset_forces();
        field_7D0 = 0;
        /*
        sub_4685C0(this, -1);
        */
        field_6F5 = 1;
        //sub_46AB50(this, 6, -1);
        health_to_max();
        scene_play_sfx(23);
        return;
      case 797:

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
            char_c::set_seq_params();
    return;
    }
        char_c::set_seq_params();
    return;
  }
  if ( get_seq() < 560 )
  {
      uint32_t sq = get_seq();
      switch (sq)
    {
      case 301:
      case 320:
      case 330:
        if ( !field_49A )
          reset_forces();
          field_190 = 0;
          field_8B8 = 0;
          field_194 = 1;
        return;
      case 302:
        if ( !field_49A )
          reset_forces();
        not_charge_attack = 1;
                field_194 = 1;
                field_49A = 0;
        field_190 = 0;
        field_8B8 = 0;
        return;
      case 303:
        if ( !field_49A )
          reset_forces();
        field_190 = 0;
        field_8B8 = 0;
        field_194 = 6;
        return;
      case 304:
        reset_forces();
        not_charge_attack = 1;
                field_194 = 1;
                field_49A = 0;
        field_190 = 0;
        field_8B8 = 0;
        return;
      case 305:
        h_inerc = 15.0;
        if ( field_49A )
        {
          field_7D8 = 0;
        }
        else
        {
          reset_forces();
          field_7D8 = 0;
        }
                field_194 = 1;
                field_49A = 0;
        field_190 = 0;
        field_8B8 = 0;
        return;
      case 306:
        field_7D0 = 0;
        field_190 = 0;
        field_8B8 = 0;
        field_194 = 1;
        return;
      case 307:
        reset_forces();
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
                field_194 = 1;
                field_49A = 0;
        field_190 = 0;
        field_8B8 = 0;
        return;
      case 322:
        if ( field_49A )
        {
          field_7D8 = 0;
        }
        else
        {
          reset_forces();
          field_7D8 = 0;
        }
                field_194 = 1;
                field_49A = 0;
        field_190 = 0;
        field_8B8 = 0;
        return;
      case 400:
      case 401:
      case 410:
      case 412:
        field_190 = 0;
        reset_forces();
        field_7D8 = 0;
                field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        not_charge_attack = 1;
        field_8B8 = 1;
        return;
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
                field_190 = 0;
        h_inerc = h_inerc * 0.2000000029802322;
        v_inerc = 0.2000000029802322 * v_inerc;
        field_7D8 = 0;
                field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        not_charge_attack = 1;
        field_8B8 = 1;
        return;
      case 408:
        h_inerc = 14.0;
        v_inerc = 0.0;
        v_force = 0.0;
                field_194 = 1;
                field_49A = 0;
        field_190 = 0;
        field_8B8 = 0;
        return;
      case 414:
      case 416:
        field_190 = 0;
        h_inerc = h_inerc * 0.25;
        v_inerc = 0.25 * v_inerc;
        field_7D8 = 0;
                field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        not_charge_attack = 1;
        field_8B8 = 1;
        return;
      case 418:
        h_inerc = 8.5;
        v_inerc = 0.0;
        v_force = 0.0;
                field_194 = 1;
                field_49A = 0;
        field_190 = 0;
        field_8B8 = 0;
        return;
      case 500:
      case 501:
        field_18C = 0;
        field_190 = 0;
        reset_forces();
                field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        not_charge_attack = 1;
        field_8B8 = 1;
        return;
      case 502:
      case 503:
      case 512:
      case 513:
        field_18C = 0;
        field_190 = 0;
        h_inerc = h_inerc * 0.25;
        v_inerc = 0.25 * v_inerc;
                field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        not_charge_attack = 1;
        field_8B8 = 1;
        return;
      case 505:
      case 506:
        field_18C = 4;
        field_190 = 0;
        reset_forces();
                field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        not_charge_attack = 1;
        field_8B8 = 1;
        return;
      case 507:
      case 508:
        field_18C = 4;
        field_190 = 0;
        h_inerc = h_inerc * 0.25;
        v_inerc = 0.25 * v_inerc;
                field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        not_charge_attack = 1;
        field_8B8 = 1;
        return;
      case 510:
      case 511:
        field_18C = 8;
        field_190 = 0;
        reset_forces();

        field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        not_charge_attack = 1;
        field_8B8 = 1;
        return;
      case 520:
      case 521:
        field_18C = 1;
                field_190 = 0;
        reset_forces();
        field_8B8 = 1;
        return;
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
        v58 = 0.0;
        v59 = 8.0;
        */
        //addbullet(this, 816, x, y, dir, -1, (int)0.0, 3);
        return;
      case 530:
      case 531:
        field_18C = 9;
                field_190 = 0;
        reset_forces();
        field_8B8 = 1;
        return;
      case 540:
        field_18C = 2;
        reset_forces();
        field_194 = 1;
                field_49A = 0;
        field_190 = 0;
        field_8B8 = 0;
        return;
      case 541:
        field_18C = 2;
        reset_forces();
        field_194 = 99;
        field_7D0 = 0;
        field_7D4 = 0;
                field_49A = 0;
        field_190 = 0;
        field_8B8 = 0;
        return;
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
        break;
      default:
        break;
    }
    char_c::set_seq_params();
    return;
  }
  /*
  v47 = __OFSUB__(skills_1[3], 4);
  v46 = (char)(skills_1[3] - 4) < 0;
  h_inerc = 0.0;
  v_inerc = 0.0;
  field_18C = 3;
  v_force = 0.0;
  field_194 = 1;
  field_190 = 0;
  field_8B8 = 0;
  if ( !(v46 ^ v47) && get_seq() == 560 )
    field_51C = 2;
  */
}
#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "aya.h"
#include <math.h>

//"Constructor" ?
char_aya::char_aya(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_AYA;
	pgp->load_dat("aya",pal);
	char_loadsfx("aya");
	cards_load_cards(&chr_cards,"aya");
	load_face("aya");
	load_spells("aya");
	stand_gfx->init(this,"aya");
}

//Initialize some variables
void char_aya::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_aya::new_bullet()
{
    c_bullet *tmp = new aya_bullets();
    return tmp;
}
*/
void char_aya::func10()
{

}
/*
void char_aya::func20()
{

}
*/
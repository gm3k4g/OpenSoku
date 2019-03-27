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

//Initialize some variables
void char_suwako::init_vars()
{
	char_c::init_vars();
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
/*
void char_suwako::func20()
{

}
*/
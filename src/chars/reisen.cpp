#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "reisen.h"
#include <math.h>

//"Constructor" ?
char_reisen::char_reisen(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_REISEN;
	pgp->load_dat("reisen",pal);
	char_loadsfx("reisen");
	cards_load_cards(&chr_cards,"reisen");
	load_face("reisen");
	load_spells("reisen");
	stand_gfx->init(this,"reisen");
}

//Initialize some variables
void char_reisen::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_reisen::new_bullet()
{
    c_bullet *tmp = new reisen_bullets();
    return tmp;
}
*/
void char_reisen::func10()
{

}
/*
void char_reisen::func20()
{

}
*/
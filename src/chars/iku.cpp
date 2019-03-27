#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "iku.h"
#include <math.h>

//"Constructor" ?
char_iku::char_iku(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_IKU;
	pgp->load_dat("iku",pal);
	char_loadsfx("iku");
	cards_load_cards(&chr_cards,"iku");
	load_face("iku");
	load_spells("iku");
	stand_gfx->init(this,"iku");
}

//Initialize some variables
void char_iku::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_iku::new_bullet()
{
    c_bullet *tmp = new iku_bullets();
    return tmp;
}
*/
void char_iku::func10()
{

}
/*
void char_iku::func20()
{

}
*/
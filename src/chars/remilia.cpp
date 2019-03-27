#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "remilia.h"
#include <math.h>

//"Constructor" ?
char_remilia::char_remilia(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_REMI;
	pgp->load_dat("remilia",pal);
	char_loadsfx("remilia");
	cards_load_cards(&chr_cards,"remilia");
	load_face("remilia");
	load_spells("remilia");
	stand_gfx->init(this,"remilia");
}

//Initialize some variables
void char_remilia::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_remilia::new_bullet()
{
    c_bullet *tmp = new remilia_bullets();
    return tmp;
}
*/
void char_remilia::func10()
{

}
/*
void char_remilia::func20()
{

}
*/
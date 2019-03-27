#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "youmu.h"
#include <math.h>

//"Constructor" ?
char_youmu::char_youmu(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_YOUMU;
	pgp->load_dat("youmu",pal);
	char_loadsfx("youmu");
	cards_load_cards(&chr_cards,"youmu");
	load_face("youmu");
	load_spells("youmu");
	stand_gfx->init(this,"youmu");
}

//Initialize some variables
void char_youmu::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_youmu::new_bullet()
{
    c_bullet *tmp = new youmu_bullets();
    return tmp;
}
*/
void char_youmu::func10()
{

}
/*
void char_youmu::func20()
{

}
*/
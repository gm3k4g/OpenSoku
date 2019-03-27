#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "tenshi.h"
#include <math.h>

//"Constructor" ?
char_tenshi::char_tenshi(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_TENSHI;
	pgp->load_dat("tenshi",pal);
	char_loadsfx("tenshi");
	cards_load_cards(&chr_cards,"tenshi");
	load_face("tenshi");
	load_spells("tenshi");
	stand_gfx->init(this,"tenshi");
}

//Initialize some variables
void char_tenshi::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_tenshi::new_bullet()
{
    c_bullet *tmp = new tenshi_bullets();
    return tmp;
}
*/
void char_tenshi::func10()
{

}
/*
void char_tenshi::func20()
{

}
*/
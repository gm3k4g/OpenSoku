#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "yuyuko.h"
#include <math.h>

//"Constructor" ?
char_yuyuko::char_yuyuko(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_YUYUKO;
	pgp->load_dat("yuyuko",pal);
	char_loadsfx("yuyuko");
	cards_load_cards(&chr_cards,"yuyuko");
	load_face("yuyuko");
	load_spells("yuyuko");
	stand_gfx->init(this,"yuyuko");
}

//Initialize some variables
void char_yuyuko::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_yuyuko::new_bullet()
{
    c_bullet *tmp = new yuyuko_bullets();
    return tmp;
}
*/
void char_yuyuko::func10()
{

}
/*
void char_yuyuko::func20()
{

}
*/
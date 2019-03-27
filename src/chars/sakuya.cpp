#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "sakuya.h"
#include <math.h>

//"Constructor" ?
char_sakuya::char_sakuya(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_SAKUYA;
	pgp->load_dat("sakuya",pal);
	char_loadsfx("sakuya");
	cards_load_cards(&chr_cards,"sakuya");
	load_face("sakuya");
	load_spells("sakuya");
	stand_gfx->init(this,"sakuya");
}

//Initialize some variables
void char_sakuya::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_sakuya::new_bullet()
{
    c_bullet *tmp = new sakuya_bullets();
    return tmp;
}
*/
void char_sakuya::func10()
{

}
/*
void char_sakuya::func20()
{

}
*/
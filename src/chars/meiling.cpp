#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "meiling.h"
#include <math.h>

//"Constructor" ?
char_meiling::char_meiling(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_MEILING;
	pgp->load_dat("meiling",pal);
	char_loadsfx("meiling");
	cards_load_cards(&chr_cards,"meiling");
	load_face("meiling");
	load_spells("meiling");
	stand_gfx->init(this,"meiling");
}

//Initialize some variables
void char_meiling::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_meiling::new_bullet()
{
    c_bullet *tmp = new meiling_bullets();
    return tmp;
}
*/
void char_meiling::func10()
{

}
/*
void char_meiling::func20()
{

}
*/
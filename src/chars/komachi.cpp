#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "komachi.h"
#include <math.h>

//"Constructor" ?
char_komachi::char_komachi(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_KOMACHI;
	pgp->load_dat("komachi",pal);
	char_loadsfx("komachi");
	cards_load_cards(&chr_cards,"komachi");
	load_face("komachi");
	load_spells("komachi");
	stand_gfx->init(this,"komachi");
}

//Initialize some variables
void char_komachi::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_komachi::new_bullet()
{
    c_bullet *tmp = new komachi_bullets();
    return tmp;
}
*/
void char_komachi::func10()
{

}
/*
void char_komachi::func20()
{

}
*/
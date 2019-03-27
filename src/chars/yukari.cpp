#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "yukari.h"
#include <math.h>

//"Constructor" ?
char_yukari::char_yukari(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_YUKARI;
	pgp->load_dat("yukari",pal);
	char_loadsfx("yukari");
	cards_load_cards(&chr_cards,"yukari");
	load_face("yukari");
	load_spells("yukari");
	stand_gfx->init(this,"yukari");
}

//Initialize some variables
void char_yukari::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_yukari::new_bullet()
{
    c_bullet *tmp = new yukari_bullets();
    return tmp;
}
*/
void char_yukari::func10()
{

}
/*
void char_yukari::func20()
{

}
*/
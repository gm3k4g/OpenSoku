#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "reimu.h"
#include <math.h>

//"Constructor" ?
char_reimu::char_reimu(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_REIMU;
	pgp->load_dat("reimu",pal);
	char_loadsfx("reimu");
	cards_load_cards(&chr_cards,"reimu");
	load_face("reimu");
	load_spells("reimu");
	stand_gfx->init(this,"reimu");
}

//Initialize some variables
void char_reimu::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_reimu::new_bullet()
{
    c_bullet *tmp = new reimu_bullets();
    return tmp;
}
*/
void char_reimu::func10()
{

}
/*
void char_reimu::func20()
{

}
*/
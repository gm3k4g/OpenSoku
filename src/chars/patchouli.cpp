#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "patchouli.h"
#include <math.h>

//"Constructor" ?
char_patchouli::char_patchouli(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_PACHOU;
	pgp->load_dat("patchouli",pal);
	char_loadsfx("patchouli");
	cards_load_cards(&chr_cards,"patchouli");
	load_face("patchouli");
	load_spells("patchouli");
	stand_gfx->init(this,"patchouli");
}

//Initialize some variables
void char_patchouli::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_patchouli::new_bullet()
{
    c_bullet *tmp = new patchouli_bullets();
    return tmp;
}
*/
void char_patchouli::func10()
{

}
/*
void char_patchouli::func20()
{

}
*/
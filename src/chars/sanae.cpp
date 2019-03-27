#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "sanae.h"
#include <math.h>

//"Constructor" ?
char_sanae::char_sanae(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_SANAE;
	pgp->load_dat("sanae",pal);
	char_loadsfx("sanae");
	cards_load_cards(&chr_cards,"sanae");
	load_face("sanae");
	load_spells("sanae");
	stand_gfx->init(this,"sanae");
}

//Initialize some variables
void char_sanae::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_sanae::new_bullet()
{
    c_bullet *tmp = new sanae_bullets();
    return tmp;
}
*/
void char_sanae::func10()
{

}
/*
void char_sanae::func20()
{

}
*/
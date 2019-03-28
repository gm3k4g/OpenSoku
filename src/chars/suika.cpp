#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "suika.h"
#include <math.h>

//"Constructor" ?
char_suika::char_suika(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_SUIKA;
	pgp->load_dat("suika",pal);
	char_loadsfx("suika");
	cards_load_cards(&chr_cards,"suika");
	load_face("suika");
	load_spells("suika");
	stand_gfx->init(this,"suika");
}

//Initialize some variables
void char_suika::init_vars()
{
	char_c::init_vars();
}
/*
c_bullet *char_suika::new_bullet()
{
    c_bullet *tmp = new suika_bullets();
    return tmp;
}
*/
void char_suika::func10()
{
	x_delta = 0;
	y_delta = 80;

	/*
	if ( v2 > 0) {
		field_890 = v2 - 1;
		if (health <= 0 || field_890 = 0) {
			char_c::spell_energy_spend(enemy,2,30);
		}
	}
	*/
}
/*
void char_suika::func20()
{

}
*/
#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "udonge.h"
#include <math.h>

char_udonge::char_udonge(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_UDONGE;
	pgp->load_dat("udonge",pal);
	char_loadsfx("udonge");
	cards_load_cards(&chr_cards,"udonge");
	load_face("udonge");
	load_spells("udonge");
	stand_gfx->init(this,"udonge");
}

void char_udonge::init_vars()
{
  field_138 = -6.0;
  field_890 = 0;
  field_892 = 255;
  field_894 = 1.0;
  field_8A0 = 0;
  field_8A4 = 0;
  field_89C = 0.0;
  field_898 = 0;
  field_89A = 0;
  field_8AC = 200.0;
  field_8A8 = 0;
  field_8B0 = 0;
  field_8B2 = 0;
  field_8B4 = 0;
  char_c::init_vars();
}
/*
c_bullet *char_udonge::new_bullet()
{
    c_bullet *tmp = new udonge_bullets();
    return tmp;
}
*/
void char_udonge::func10()
{

}

void char_udonge::func20()
{

}

void char_udonge::set_seq_params()
{

}
#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../bullets.h"
#include "../scene.h"
#include "../character_def.h"
#include "namazu_bullets.h"
#include "namazu.h"
#include <math.h>

//Bullet func10
void namazu_bullets::func10() {
	int32_t sq = get_seq();

	switch (sq) {
		case 800:
			if (field_190 != 5) {
				switch (get_subseq()) {
					case 0:
					case 1:
					case 2:
					case 3:
					/*
						if (sub_48C6A0(sq, 0, 0, 4)) {
							//goto LABEL_41
							//--v1->is_active;
							//end of LABEL 41
						}*/
						//break; //return;
						if (field_190 && get_elaps_frames() < 120) {
							if (scaleX >= 1.0) {
								scaleX += 0.009; //0.009999999776482582;
							} else {
								scaleX += 0.019; //0.01999999955296516;
								if (scaleX > 1.0)
									scaleX = 1.0;
							}
							scaleY = scaleX;
							//v6 = v5[1] + 0.2000000029802322;
              				//v7 = v6;
              				//goto LABEL_14
              				//_meta::set_vec_speed((render_class *)&v1->meta.cEffectSprite, *v5, a3);
              				//angZ = *additional_vars;
              				//end of LABEL_14

              				/*

							

              				*/

              				//LABEL_32
              				if (x <= 1380.0 && 
              					x >= -100.0 &&
              					y <= 1060.0 &&
              					y >= -100.0) {
              					//goto LABEL_37
              					x += dir * h_inerc; //v19 = (double)v1->meta.cEffectSprite.dir;
              					y += v_inerc;
              					//end of LABEL_37
              					//LABEL_38
              					//a1 = v1;
              					//end of LABEL_38
              					//LABEL_39
              					//if (process())
              						//is_active();
              						//break; //return;
              				}
              				//end of LABEL_32
              				//LABEL_82
              				//set_vec_speed(this, *additional_vars, additional_vars[1]);
              				//end?
              				break; //return;
						}
					//case 4: 

				}
			}
	}
}

void namazu_bullets::set_seq_params() {
	h_inerc = 0.0;
	v_inerc = 0.0;
	field_378 = 0.0;
	field_37C = 0.0;
	field_380 = 0.0;
	field_384 = 0.0;
	field_394 = 0;
	field_388 = 0.0;
	field_396 = 0;
	field_194 = 0;
	field_198 = 1.0;
	field_36C = 0;
	field_36E = 0;
	field_370 = 0;
	field_372 = 0;
	field_374 = 0;
	field_1A2 = 0;

	int32_t sq = get_seq();

	switch (sq) {
		/*Unknown:
			get_MT_range();
			set_vec_speed();
		*/
		case 800:
			field_194 = 1;
			//angZ = *additional_vars;
			//v3 = this->additional_vars;
			//((void (__stdcall *)(signed int))v4->set_subseq_func3)((signed int)v3[2]);
			if ( get_subseq() >= 0 && get_subseq() <= 3) {
				scaleX = 0.1;
				scaleY = 0.1;
				//  ((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v8)(v1, 800, v1->meta.cEffectSprite.x, v1->meta.cEffectSprite.y, v6, -1, &v294, 3);
			}/*
			if ( get_subseq() >= 4 && get_subseq() <= 7) {
				//v10 = (double)(unsigned int)get_MT_range(100);
				// v12 = v10 * 0.1000000014901161;
				//field_378 = get_MT_range(100) * 0.10; //0.1000000014901161;
				//set_vec_speed(this, *additional_vars, additional_vars[1]);
				//scaleX = get_MT_range(10) * 0.10 + 0.5; //0.1000000014901161 + 0.5;
				//scaleY = get_MT_range(10) * 0.10 + 0.5; //0.1000000014901161 + 0.5;
			}
			/*if ( get_subseq() >= 12 && get_subseq() <= 15) {
				
				v15 = (unsigned __int8)v1->meta.cEffectSprite.dir;
        		v16 = v1->meta.vtbl;
        		v294 = 0.0;
        		v17 = (void (__thiscall *)(bullet_class *, signed int, float, float, int, signed int, float *, signed int))v16->func18__or_addbullet_w_parent;
        		v295 = 0.0;
        		v296 = (double)(v14 - 4);
        		((void (__thiscall *)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))v17)(v1, 800, v1->meta.cEffectSprite.x, v1->meta.cEffectSprite.y, v15, -1, &v294, 3);
      			}
				
			}*/
			break; //return;
			case 801:/*
				//      ((void (__stdcall *)(signed int))this->meta.vtbl->set_subseq_func3)((signed int)this->additional_vars[2]);
				if ( get_subseq() == 1 ) {
					set_vec_speed(this, *additional_vars, additional_vars[1]);
					field_194 = 1;
				}*/
				if ( get_subseq() == 2 ) {
					v_inerc = y;
					h_inerc = 0.0;
				}
				if ( get_subseq() == 3 ) {
					field_194 = 3;
				}
				if ( get_subseq() == 4 ) {
					v_inerc = 2.0;
				}/*
				if ( get_subseq() == 5 ) {
					set_vec_speed(this, *additional_vars, additional_vars[1]);
					field_194 = 1;
				}*/
				break; //return;
			//case 810:
	}
}
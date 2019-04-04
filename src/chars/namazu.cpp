#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "namazu.h"
#include <math.h>

//"Constructor" ?
char_namazu::char_namazu(inp_ab *func,uint8_t pal):
	char_c::char_c(func)
{
	char_id = CHAR_ID_NAMAZU;
	pgp->load_dat("namazu",pal);
	char_loadsfx("namazu");
	cards_load_cards(&chr_cards,"namazu");
	load_face("namazu");
	load_spells("namazu");
	stand_gfx->init(this,"namazu");
}

//Initialize some variables
void char_namazu::init_vars()
{
	field_138 = -6.0;
	field_890 = 0;
	field_894 = 0;
	field_898 = 0;
	field_89C = 0;
	char_c::init_vars();
}

//Associated with bullets
c_bullet *char_namazu::new_bullet()
{
    c_bullet *tmp = new namazu_bullets();
    return tmp;
}

/*
  v1 = this;
  v2 = *(_DWORD **)(this + 340);
  if ( v2 )
  {
    v3 = *(void **)(this + 340);
    *v2 = &IColor::`vftable';
    j__free(v3);
    *(_DWORD *)(v1 + 340) = 0;
  }
}
 */

void char_namazu::func10()
{
	//Deltas
	x_delta = 0;
	y_delta = 90;

/*
	if ( char_c::char_is_shock() )
		sub_5586E0(); //???
*/

	/* Rewrite IF PC STORY statement */

	if ( hit_stop || enemy->time_stop )
    return;

	int32_t sq = get_seq();
	if (sq > 300) {
		if (sq <= 500) {
			if (sq == 500) {
				sub10func();
				field_18C = 0;
				if (process())
					set_seq(0);
				if ( get_elaps_frames() ||
						get_frame_time() ||
						get_frame() ||
						get_subseq() != 1) {
					if (get_subseq() && 
						get_frame_time() == 0 &&
						get_frame() == 4) {
						int16_t v495 = 0;
						float v1693 = 6.0;
						float v1694 = 12.0;
						if ( skills_1[0] < 4 ) {
							if ( skills_1[0] < 1 ) {
								int16_t v1496 = 0;
								do {
									//float* v1692 = -20.0 - (double)v1496;
									addbullet(this, NULL, 810, x + (38 * dir), y + 177.0, dir, 1, (float*)-20, 3); //(int)v1692
									v495 += 10;
									v1496 = v495;
								}
								while ( v495 < 40);
							} else {
								int16_t v1495 = 0;
								do {
									//float* v1692 = -20.0 - (double)v1495;
									addbullet(this, NULL, 810, x + (38 * dir), y + 177.0, dir, 1, (float*)-20, 3);
									v495 += 10;
									v1495 = v495;
								}
								while (v495 < 50 );
							}
						} else {
							int16_t v1494 = 0;
							do { 
								//float* v1692 = -20.0 - (double)v1494;
								addbullet(this, NULL, 810, x + (38 * dir), y + 177.0, dir, 1, (float*)-20, 3);
								v495 += 10;
								v1494 = v495;
							}
							while (v495 < 60);
						}
						add_card_energy(50);
						spell_energy_spend(200,120);
						play_sfx(10);
					}
					return; //break;
				}
				set_seq(0);
				return;
			}
			switch(sq) {
				case 301:
					sub10func();
					/* if (get_true(0) return;*/
					if (field_49A) {
						h_inerc -= 0.5;
						if ( h_inerc <0.0) {
							h_inerc = 0.0;
							field_49A = 0;
						}
					} //else { v240 = 0.0; }
					if (get_frame() >= 5) {
						h_inerc -= 0.15; //0.1500000059604645;
						if (h_inerc < 0.0) 
							h_inerc = 0.0;
					}
					if (process())
						set_seq(0);
					if (get_frame_time())
						return;
					if (get_frame() == 2) {
						h_inerc = 4.0;
						field_49A = 0;
						//float* v1968 = 0.0;
						addbullet(this, NULL, 848, x, y, dir, 1, (float*)0, 3); //(int)v1968
					}
					//goto LABEL_684
					//end of LABEL_684
				//case 302:
			}
		}
	}

	if (sq == 300) {
		//LABEL_659:
		sub10func();
		/* if (!get_true(0))*/
		if (field_49A) {
			h_inerc -= 0.5;
			if (h_inerc< 0.0) {
				h_inerc = 0.0;
				field_49A = 0;
			}
		}
		if ( process() )
			set_seq(0);
		if ( get_frame_time() == 0) {
			if ( get_frame() == 2) {
				//float* v1962 = 0.0;
				addbullet(this, NULL, 848, x, y, dir, 1, (float*)-20, 3);
			}
			if (get_frame_time() == 0 && get_frame() == 3) {
				scene_play_sfx(28);
				field_49A = 0;
			}
		}
	}
	//1 bracket missing due to if (get_true(0))
	else {
		//is this character stuff :thonk:
		switch(sq) {
			case 0:
				sub10func();
				if (0.0 == h_inerc) 
					field_49A = 0;
				if (field_49A == 0) {
					//goto LABEL_62
					reset_forces();
					process();
				} return;
					//goto LABEL_63
					if ( 0.0 < h_inerc ) {
						h_inerc -= 0.5;
						if ( h_inerc < 0.0) {
							reset_forces();
							field_49A = 0;
						}
					} return;
					/*if ( 0.0 <= h_inerc || (h_inerc <= 0.0)) {
						process();
					} else {
						reset_forces();
						field_49A = 0;
						process();
					}
		} else {
			reset_forces();
			process();
		}
		return; */
			case 1:
				sub10func();
				if (field_49A) {
					if (h_inerc > 0.0) {
						h_inerc -= 0.5;
						if ((h_inerc -= 0.5) < 0.0) {
							reset_forces();
							field_49A = 0;
						}
					}
					if ( 0.0 > h_inerc ) {
						h_inerc += 0.5;
						if ( (h_inerc += 0.5 ) > 0.0 ) {
							reset_forces();
							field_49A = 0;
						}
					}
				} else {
					reset_forces();
				} if (process() && !get_frame() ) {
					//goto LABEL_79
					set_seq(2);
					return;
					//end
				}
				return;
			case 2:
				sub10func();
				if (field_49A) {
					if ( 0.0 < h_inerc ) {
						h_inerc -= 0.5;
						if ( (h_inerc -= 0.5) < 0.0 ) {
							reset_forces();
							field_49A = 0;
						}
					}
					if ( 0.0 <= h_inerc || (h_inerc+=0.5) <= 0.0 ) {
						process();
					} else {
						reset_forces();
						field_49A = 0;
						process();
					}
				}
				else {
					reset_forces();
					process();
				}
				return;
			case 3:
				sub10func();
				if (field_49A) {
					if(h_inerc > 0.0) {
						h_inerc -= 0.5;
						if ( (h_inerc -=0.5) < 0.0 ) {
							reset_forces();
							field_49A = 0;
						}
					}
					if ( 0.0 > h_inerc ) {
						h_inerc += 0.5;
						if ( (h_inerc += 0.5 ) > 0.0 ) {
							reset_forces();
							field_49A = 0;
						}
					}
				} else {
					reset_forces();
				}
				if ( process() && !get_frame() ) {
					//goto LABEL_92;
					if ( get_subseq() == 5 && get_elaps_frames() >= field_7D6 ) {
						set_seq(0);
					} else {
						if (process()) 
							set_seq(0);
						if ( !get_elaps_frames() ) {
							if ( !get_frame_time() &&  !get_frame() && get_subseq() == 1 ) {
								switch ( GAME_DIFF_HARD ) {
									case 0 :
										field_7D0 = 120;
										field_7DC = 8.0;
										field_7D2 = 300;
										dash_angle = 120.0;
										field_7D4 = 40;
										field_7D6 = 240;
										//goto LABEL_2491;
										field_7E4 = 0.0;
										break;
									default:
										break;
								}
							}
							if ( !get_elaps_frames() ) {
								if ( !get_frame_time() && !get_frame() && get_subseq() == 3) {
									flip_with_force();
									//h_inerc = (double)get_MT_range(30) * 0.10; //0.1000000014901161;
								}
								if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 ) {
									h_inerc = field_7DC * 0.20; //0.2000000029802322;
									v_inerc = 0.20 * -dash_angle; //0.2000000029802322
									v_force = 0.2;
								}	
							}
						}
					}
					return;
				}
			case 4: 
				sub10func();
				char_h_move(4.0);
				process();
				return;
			case 5:
				sub10func();
				char_h_move(-4.0);
				process();
				return;
			case 6:
				if ( !get_subseq() )
					sub10func();
				if ( !get_subseq() ) {
					if (!field_49A )
						reset_forces();
				}
				if ( get_subseq() != 0 || get_subseq() < 0) {
					v_inerc -= v_force;
					if (char_on_ground_down() ) {
						//goto LABEL_138;
						//int16_t move_val = 10;
						//goto LABEL_139;
						set_seq(10);
						//goto LABEL_140;
						y = getlvl_height();
						reset_forces();
						return;
						}
					}
					process();
					if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 ) {
						h_inerc = field_85C;
						v_inerc = field_860;
						v_force = field_864;
					}
					return;
			case 7:
				if ( !get_subseq() )
					sub10func();
				if ( !get_subseq() ) {
					if ( !field_49A )
						reset_forces();
					}
					if ( !(get_subseq() < 0) | get_subseq() == 0 ) {
						v_inerc -= v_force;
						if (char_on_ground_down() ) {
						//goto LABEL_138;
						//int16_t move_val = 10;
						//goto LABEL_139;
						set_seq(10);
						//goto LABEL_140;
						y = getlvl_height();
						reset_forces();
						return;
						}
						process();
						if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1)
							return;
						//v36 = 4.0;
						//goto LABEL_121;
						char_h_move(4.0);
						v_inerc = 12.0;
						v_force = 0.40; //0.40000001;
						field_49A = 0;
					}
					return;
				case 8:
					if ( !get_subseq() )
						sub10func();
					if ( !get_subseq() ) {
						if ( !field_49A )
							reset_forces();
					}
					if ( !(get_subseq() < 0) | get_subseq() == 0) {
						v_inerc -= v_force;
						if (char_on_ground_down() ) {
						//goto LABEL_138;
						//int16_t move_val = 10;
						//goto LABEL_139;
						set_seq(10);
						//goto LABEL_140;
						y = getlvl_height();
						reset_forces();
						return;
						}
					}
						process();
						if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 ) {
							//goto LABEL_121;
							char_h_move(-4.0);
							v_inerc = 12.0;
							v_force = 0.40; //0.40000001;
							field_49A = 0;
						}
						return;
				case 9:
					if ( 0.0 == v_force )
						v_force = 0.60; //0.60000002;
					v_inerc -= v_force;
					if ( !char_on_ground_down() ) {
						//goto LABEL_141;
						if ( 0.0 <= h_inerc || (h_inerc += 0.5) <= 0.0 ) {
						//goto LABEL_142;
						process();
					} else {
						reset_forces();
						field_49A = 0;
						process();
					}
				} else {
					//LABEL 62
					reset_forces();
					process();
					return;
				}
					//LABEL_138
					//int16_t move_val = 10;
					//goto LABEL_139;
					set_seq(10);
					//goto LABEL_140;
					y = getlvl_height();
					reset_forces();
					return;
				case 10:
					sub10func();
					reset_forces();
					//LABEL_144
					//LABEL_145
					if ( process() )
						set_seq(0);
					return;
				case 50:
			    case 51:
			    case 52:
			    case 53:
			    case 54:
			    case 55:
			    case 56:
			    case 57:
			    case 58:
			    case 59:
			    case 60:
			    case 61:
			    case 62:
			    case 63:
			    case 64:
			    case 65:
			    case 66:
			    case 67:
			    	v_inerc -= 0.34; //0.3499999940395355
			    	h_inerc += 0.10; //0.1000000014901161
			    	if ( (h_inerc += 0.10 ) > -1.0 )
			    		h_inerc = -1.0;

			    	//What shadow?
			    	/*if ( !has_shadow() )
			    	has_shadow() = 1; */

			    	if ( !char_on_ground_down() ) {
			    		//goto LABEL_145;
			    		if (process())
			    			set_seq(0);
			    		return;
			    	}			    	 

			    	play_sfx(0);
			    	reset_forces();
			    	y = getlvl_height();
			    	//shake_camera(2.0);
			    	/*
			        v1489 = 0.0;
			        do
			        {
			          a4 = (double)(unsigned int)get_MT_range(10) + v1489 * 24.0;
			          v1702 = (double)(unsigned int)get_MT_range(20) * 0.1000000014901161 + 10.0;
			          v1703 = 0.0;
			          v45 = -a4;
			          y = (unsigned __int8)(1 - 2 * (sinus(v45) > 0.0));
			          v47 = (unsigned __int8)v1->char_c.meta.cEffectSprite.dir;
			          v48 = -a4;
			          v49 = sinus(v48) * 20.0 + v1->char_c.meta.cEffectSprite.y;
			          v50 = v49;
			          a3 = -a4;
			          v52 = cosinus(a3) * 100.0 * (double)v1->char_c.meta.cEffectSprite.dir + v1->char_c.meta.cEffectSprite.x;
			          addbullet(&v1->char_c, 971, v52, v50, v47, y, (int)&a4, 3);
			          v1489 = v1489 + 1.0;
			        }
			        while ( v1489 < 15.0 );
						    	}*/
			    	set_seq(10);
			    	return;
			    case 70:
				case 71:
				case 72:
				case 73:
				case 74:
			    case 75:
				case 76:
				case 77:
				case 78:
				case 79:
				case 80:
				case 81:
				case 82:
				case 83:
				case 84:
				case 85:
				case 86:
				case 87:
				case 88:
					v_inerc -= 0.30; //0.300000011920929;
					h_inerc += 0.10; //0.1000000014901161;
					if ( (h_inerc += 0.10 ) > -1.0 )
						h_inerc = -1.0;
				/*	if ( !has_shadow )
						has_shadow = 1; */
					if (char_on_ground_down() ) {
						y = getlvl_height();
						play_sfx(0);
						field_7DC = h_inerc;
						dash_angle = v_inerc;
						reset_forces();
						//shake_camera(10.0);
						/*
						v1490 = 0.0;
				        do
				        {
				        a1a = (double)(unsigned int)get_MT_range(10) + v1490 * 24.0;
				        v1717 = (double)(unsigned int)get_MT_range(20) * 0.1000000014901161 + 10.0;
				        v1718 = 0.0;
				        v54 = -a1a;
				        v55 = (unsigned __int8)(1 - 2 * (sinus(v54) > 0.0));
				        v56 = (unsigned __int8)v1->char_c.meta.cEffectSprite.dir;
				        v57 = -a1a;
				        v58 = sinus(v57) * 20.0 + v1->char_c.meta.cEffectSprite.y;
				        v59 = v58;
				        v60 = -a1a;
				        v61 = cosinus(v60) * 100.0 * (double)v1->char_c.meta.cEffectSprite.dir + v1->char_c.meta.cEffectSprite.x;
				        addbullet(&v1->char_c, 971, v61, v59, v56, v55, (int)&a1a, 3);
				        v1490 = v1490 + 1.0;
				        }
				        while ( v1490 < 15.0 );
						*/
						set_seq(96);
					} else if ( process() ) {
						set_seq(199);
					}
					return;
				case 96:
					if (get_subseq() == 1 ) {
						v_inerc -= 0.20; //0.2000000029802322;
						h_inerc += 0.10; //0.1000000014901161;
						if ( (h_inerc + 0.10 ) > 0.0 )
							h_inerc = 0.0;
						if ( char_on_ground_down() ) {
							y = getlvl_height();
							play_sfx(0);
							reset_forces();
							//shake_camera(2.0);
							set_seq(99);
							//goto LABEL_170;
							//goto LABEL_171;
							if (get_elaps_frames() >= field_7D0 ) {
								next_subseq();
							} else {
								//LABEL_2807
								if ( get_subseq() == 3 ) {
									//Commented out because of unknown conversions
									//
									//if ( !(get_elaps_frames() % 6) && field_7E4 > 0.0 ) {
									/*
							            *(float *)&v1583 = -90.0;
							            v1584 = 40.0;
							            v1585 = (double)((unsigned int)get_MT_range(100) >= 0x32) + 4.0;
							            v1297 = v1->char_c.field_7D4;
							            v1298 = (unsigned __int8)v1->char_c.meta.cEffectSprite.dir;
							            v1299 = v1->char_c.meta.cEffectSprite.x + (double)v1297;
							            v1300 = v1->char_c.meta.cEffectSprite.y - 100.0;
							            v1301 = v1300;
							            v1302 = get_MT_range(v1297);
							            v1303 = v1299 - ((double)(unsigned int)v1302 + (double)(unsigned int)v1302);
							            addbullet(&v1->char_c, 941, v1303, v1301, v1298, 1, (int)&v1583, 3);
							            v1->char_c.field_7E4 = v1->char_c.field_7E4 - 1.0;
							            v1527 = 0.0;
							            do
							            {
							              *(float *)&v1583 = (double)(unsigned int)get_MT_range(360);
							              v1584 = (double)(unsigned int)get_MT_range(50) * 0.1000000014901161 + 15.0;
							              v1585 = 0.0;
							              v1304 = -*(float *)&v1583;
							              v1305 = (unsigned __int8)(1 - 2 * (sinus(v1304) > 0.0));
							              v1306 = (unsigned __int8)v1->char_c.meta.cEffectSprite.dir;
							              v1307 = -*(float *)&v1583;
							              v1308 = sinus(v1307) * 20.0 + v1->char_c.meta.cEffectSprite.y;
							              v1309 = v1308;
							              v1310 = -*(float *)&v1583;
							              v1311 = cosinus(v1310) * 100.0 * (double)v1->char_c.meta.cEffectSprite.dir + v1->char_c.meta.cEffectSprite.x;
							              addbullet(&v1->char_c, 971, v1311, v1309, v1306, v1305, (int)&v1583, 3);
							              v1527 = v1527 + 1.0;
							            }
							            while ( v1527 < 2.0 );
										*/
										//shake_camera(3.0);
										//}
										//goto LABEL_2148;	
										if (get_elaps_frames() >= field_7D2 )
										next_subseq();
									} else {
										//LABEL_2809
										if (process() ) {
											if ( field_888 > 10 )
												set_seq(754);
											else
												set_seq(756);
										}
										if ( !get_elaps_frames() ) {
											if ( !get_frame_time() && 
													!get_frame() && 
													get_subseq() == 1) {
												switch ( GAME_DIFF_HARD ) {
													case 0:
														field_7D0 = 150;
														field_7D2 = 300;
														field_7E4 = 10.0;
														field_7D4 = 150;
														break;
													case 1:
														field_7D0 = 120;
														field_7D2 = 270;
														field_7E4 = 16.0;
														field_7D4 = 200;
														break;
													case 2:
														field_7D0 = 120;
														field_7D2 = 240;
														field_7E4 = 22.0;
														field_7D4 = 300;
													case 3:
														field_7D0 = 90;
														field_7D2 = 210;
														field_7E4 = 30.0;
														field_7D4 = 400;
														break;
													default:
														break;
												}
											}
											if ( !get_elaps_frames() && 
													get_frame_time() &&
													get_frame() &&
													get_subseq() == 3) {
												//shake_camera(15.0);
												play_sfx(11);
											//} commented out because Unknown is inactive
										}
									}
								}
								return;
							}

						}
					} else {
						sub10func();
					} if (process())
						set_seq(0);
					if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 ) {
						h_inerc = field_7DC * 0.20; //0.2000000029802322;
						v_inerc = dash_angle * 0.20; //0.2000000029802322
						v_force = 0.2;
					}
					return;
				case 99:
					sub10func();
					if (get_subseq() == 3) {
						//has_shadow = 0;
						/*if ( color_A <= 3u)
							color_A = 0;
						else
							color_A -= 3;*/
					}
					if ( health <= 0) {
						field_51C = 3;
						field_520 = 3;
					}
					process();
					if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2) {
						if ( !field_576 && !field_880 ) {
							/*if (cards_added > 0 && LOBYTE(controlling_type) == 2 && cards_active[0]->id >= 248) {
								health_to_max();
								field_868 = 0;
							} */
							field_51C = 3;
							field_520 = 3;
							set_seq(199);
							field_574 = 0;
							field_577 = 1;
						}
						field_880 = 0;
					}
					return;
				case 149:

				default:
					break;
		}
	}
}

//Func20
void char_namazu::func20()
{
	//???
	uint16_t cprior = get_cprior();
	uint32_t fflags = get_pframe()->fflags;

	bool cc = (fflags && FF_CANCELLEABLE) != 0;
	bool cu = (fflags && FF_HJC) != 0;
	int32_t sq = get_seq();

	if ( check_AB_pressed() )
		return;

	if ( cc || cu ) {
		
	}
}


void char_namazu::set_seq_params() {
	if ( get_seq() <= 330 ) {
		if (get_seq() == 330 ) {
			//LABEL_30
			if (field_49A == 0)
				reset_forces();
			field_190 = 0;
			field_194 = 1;
			return;
		}
		if (get_seq() <= 79 ) {
			if (get_seq() >= 70 ) {
				//LABEL_10
				//v3 = this->char_c.meta.field_1A4;
				field_571 = 1;
				field_572 = 1;
				field_1A4 = -field_1A4; //v11 = -v3;
				field_7D0 = 0;
				h_inerc = field_1A4;
				v_inerc = field_1A8 * 0.5;
				v_force = 0.2;
				if ( field_1A4 > 0.0)
					field_7D0 = 1;
				if ( field_1A4 < 0.0)
					field_7D0 = -1;
				angZ = 0.0;
			} else {
				int32_t sq = get_seq();

				switch (sq) {
					case 4:
						h_inerc = 4.0;
						break;
					case 5:
						h_inerc = -4.0;
						break;
			        case 50:
			        case 51:
			        case 52:
			        case 53:
			        case 54:
			        case 55:
			        case 56:
			        case 57:
			        case 58:
			        case 59:
			        case 60:
			        case 61:
			        case 62:
			        case 63:
			        case 64:
			        case 65:
			        case 66:
			        case 67:
			        	field_1A4 = 0.0;
			        	field_7D0 = 0;
			        	field_1A8 = 0.0;
			        	field_7D2 = 0;
			        	angZ = 0.0;
			        	field_571 = 1;
			        	field_572 = 1;
			        	h_inerc = -6.0;
			        	v_inerc = 6.0;
			        	v_force = 0.2;
			        	break;
			        case 88:
			        case 89:
			        	//goto LABEL_10 
			        	break;
			        	//end of LABEL_10 
			        case 214:
			        	//goto LABEL_16
			        	//end of LABEL_16
			        case 217:
			        	//CEffectSprite::init(); //what is this?
			        	//LABEL_16
			        	field_7D6 = 0;
			        	h_inerc = 0.0;
			        	v_inerc = 0.0;
			        	v_force = 0.60; // 0.60000002;
			        	x_off = 0.0;
			        	y_off = 95.0;
			        	field_7DC = 9.0;
			        	field_7EC = 0.0;
			        	break; //return;
			        	//end of LABEL_16
			        case 300:
			        case 301:
			        case 303:
			        case 322:
			        	//goto LABEL_30;
			        	if (field_49A)
			        		reset_forces();
			        	field_190 = 0;
			        	field_194 = 1;
			        	break; //return;
			        	//end of LABEL_30;
			        case 302:
			        	if (field_49A)
			        		reset_forces();
			        	field_190 = 0;
			        	field_194 = 1;
			        	not_charge_attack = 1;
			        	break; //return
			        case 304:
			        	field_49A = 0;
			        	field_194 = 1;
			        	field_190 = 0;
			        	reset_forces();
			        	not_charge_attack = 1;
			        	break; //return;
			        case 305:
			        	v_inerc = 0.0;
			        	field_49A = 0;
			        	field_190 = 0;
			        	h_inerc = 12.0;
			        	field_194 = 1;
			        	v_force = 0.0;
			        	break; //return;
			        case 306:
			        	field_7D0 = 0;
			        	field_190 = 0;
			        	field_194 = 1;
			        	break; //return;
			        case 307:
			        case 309:
			        	field_194 = 1;
			        	//goto LABEL_24;
			        	field_190 = 0;
			        	not_charge_attack = 1;
			        	break; //return;
			        	//end of LABEL_24
			        case 308:
			        	field_194 = 4;
			        	//goto LABEL_24
			        	field_190 = 0;
			        	not_charge_attack = 1;
			        	break; //return;
			        	//end of LABEL_24
			        case 310:
			        	h_inerc = 0.0;
			        	field_7D0 = 0;
			        	v_inerc = 0.0;
			        	field_190 = 0;
			        	field_194 = 99;
			        	v_force = 0.5;
			        	break; //return;
			        case 320:
			        	field_49A = 0;
			        	reset_forces();
			        	field_190 = 0;
			        	field_194 = 1;
			        	break; //return;
			        case 321:
			        	reset_forces();
			        	//goto LABEL_29
			        	field_194 = 1;
			        	field_190 = 0;
			        	break; //return;
			        	//end of LABEL_29
			        default:
			        	//goto LABEL_87
			        	char_c::set_seq_params();
			        	break; //return
			        	//end of LABEL_87
				}	
			}

		}
	}
}
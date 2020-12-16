#include "../global_types.h"
#include "../framedata.h"
#include "../input.h"
#include "../character_def.h"
#include "../scene.h"
#include "../bullets.h"
#include "../file_read.h"
#include "../archive.h"
#include "utsuho.h"
#include <math.h>
/* ============================================= */

//Utsuho's cape shader
const char *utsuho_ps = "\
uniform sampler2D base;\
uniform sampler2D tex;\
void main()\
{\
    vec4 color = texture2D(base, gl_TexCoord[0].xy);\
    if (color.xyz == vec3(1,0,1))\
        gl_FragColor = texture2D(tex, gl_TexCoord[1].xy) * gl_Color;\
    else\
        gl_FragColor = texture2D(base, gl_TexCoord[0].xy) * gl_Color;\
}";

const char *utsuho_vs = "\
uniform vec2 pos;\
void main()\
{\
    gl_Position = ftransform();\
    gl_TexCoord[0] = gl_TextureMatrix[0] * gl_MultiTexCoord0;\
    gl_TexCoord[1].xy = gl_Position.xy * vec2(320.0/256.0,240.0/256.0) + pos.xy;\
    gl_FrontColor = gl_Color;\
}";

char_utsuho::char_utsuho(inp_ab *func, uint8_t pal):
    char_c::char_c(func)
{
    char_id = CHAR_ID_UTSUHO;
    pgp->load_dat("utsuho",pal);
    char_loadsfx("utsuho");

    /*
     * Experimental!
     */
    cards_load_cards(&chr_cards,"utsuho");
    load_face("utsuho");
    load_spells("utsuho");
    stand_gfx->init(this,"utsuho");

 /* ============================================= */

    filehandle *f = arc_get_file("data/character/utsuho/backA000.cv2");

    if (f)
    {
        backtex = gr_load_cv2(f,NULL);
        gr_set_repeate(backtex, true);
        delete f;

        shader = new gr_shader;
        gr_load_shader_from_mem(shader, utsuho_vs, utsuho_ps);
        gr_shader_set_texture(shader,"tex",backtex);
    }
    shd_p = 0;

    load_face("utsuho");
}

void char_utsuho::draw(gr_shader *_shader)
{
    if (!_shader)
    {
        shd_p+=0.5;
        if (shd_p >= 512)
            shd_p = 0;
        gr_shader_set_texture(shader,"base",NULL);
        gr_shader_set(shader,"pos",(x-shd_p)/512.0,(y-shd_p)/512.0);

        char_c::draw(shader);
    }
    else
        char_c::draw(_shader);

}

void char_utsuho::draw_shadow(shd_trans *trans, gr_shader *_shader)
{
    if (!_shader)
    {
        gr_shader_set_texture(shader,"base",NULL);
        gr_shader_set(shader,"pos",(x-shd_p)/512.0,(y-shd_p)/512.0);

        char_c::draw_shadow(trans,shader);
    }
    else
        char_c::draw(_shader);
}

// WIP + needs clearing up
void char_utsuho::func10()
{
    int32_t sq = get_seq();

    // etc
    double v1283 = 0.0;
    int move_val = 0;

    double v274, v275 = 0.0;
    double move_vala = 0.0;

    double v304, v305 = 0.0;
    double move_valb = 0.0;

    double v3 = 0.0;

    bool v306 = false;

    bool v431 = false;

    double v757 = 0.0;

    double v737 = 0.0;

    bool v848 = false;

    double v40 = 0.0;
    double v99 = 0.0;
    double v101 = 0.0;
    double v104 = 0.0;

    double a2 = 0.0;
    double v129 = 0.0;
    double v182 = 0.0;

    // for an addbullet?
    double  v276 = y + 181.0;
    int a2a = dir;
    double ya = v276;
    double v277 = (double)(53 * (char)a2a) + x;
    double v271 = v277;
  
  if ( enemy->time_stop <= 0 )
    field_898 = field_898 + 0.25;
  if ( field_898 > 255.0 )
    field_898 = field_898 - 255.0;
  
  x_delta = 0;
  y_delta = 106;
  if ( controlling_type == 2 )
  {
    if ( cards_added >= 1 )
    {
      switch (cards_active[0]->id)
      {
        case 0:
        case 1:
        case 2:
        case 3:
          field_4AA = 2;
          field_534 = 0.25;
          field_55C = 2.0;
          
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] == 1 )
          {
            field_86A = 3;
            field_55C = 4.0;
          }
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_55C = 8.0;
          }
          break;
        case 4:
        case 5:
        case 6:
        case 7:
          field_4AA = 2;
          field_534 = 0.25;
          field_55C = 1.5;
          
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] != 1 )
            goto LABEL_15;
          v3 = 3.0;
          goto LABEL_14;
        case 8:
        case 9:
        case 10:
        case 11:
          field_4AA = 2;
          field_534 = 0.25;
          field_55C = 1.0;
          
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] == 1 )
          {
            field_86A = 3;
            field_55C = 3.0;
          }
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_55C = 6.0;
          }
          break;
        case 12:
        case 13:
        case 14:
        case 15:
          field_4AA = 2;
          field_534 = 0.25;
          field_55C = 1.0;
          
          field_538 = 0.0;
          field_86A = 1;
          if ( get_pframe()->extra1[4] == 1 )
          {
            v3 = 6.0;
LABEL_14:
            field_86A = 3;
            field_55C = v3;
          }
LABEL_15:
          if ( get_pframe()->extra1[4] == 2 )
          {
            field_86A = 3;
            field_55C = 9.0;
          }
          break;
        default:
          
          break;
      }
    }
    if ( field_882 == 1 )
    {
      if ( field_188 >= max_health && !field_574 )
      {
        field_86A = 2;
        field_882 = 2;
        flip_with_force();
        set_seq(149);
        scene_add_effect(this, 53, x,  y + 100.0, dir, 1);
        if ( cards_added >= 1 )
        {
          if ( cards_active[0]->id <= 0xF )
          {
            //v6 = byte_7B46D4[cards_active[0]->id];
            field_884 = 300;
            field_886 = 300;
          }
        }
        
      }
      if ( health <= 0 )
        field_882 = 2;
    }
    if ( field_884 > 0 )
    {
      
      if ( damage_limit > 0 && damage_limit < 100 )
        damage_limit = 0;
      if ( field_884 == 1 || health <= 0 )
      {
        field_4AA = 0;
        field_884 = 0;
        field_4BA = 0;
        field_188 = 0;
        field_81E = 1;
        field_81A = 0;
        field_81C = 0;
        field_818 = 0;
        field_882 = 1;
        if ( health <= 0 )
        {
LABEL_43:
          field_86A = 0;
          goto LABEL_44;
        }
        /*
        *(float *)&a7 = 0.0;
        v1664 = 0.0;
        v1665 = 0.0;
        addbullet(, 1201, 180.0, 130.0, 1, 2, (int)&a7, 3);
        */
        
      }
      else
      {
        field_86A = 2;
        field_4AA = 2;
        field_538 = 1.0;
        field_534 = 1.0;
        --field_884;
        field_4BA = 6000;
      }
    }
    if ( health <= 0 )
      goto LABEL_43;
  }
LABEL_44:
  if ( !field_84E && !field_852 )
  {
    /*
    v8 = shader_type;
    if ( field_8A4 <= 0 )
    {
      if ( LODWORD(v8) != 1 && v8 != 0.0 )
        shader_type = 0.0;
    }
    else if ( LODWORD(v8) != 1 )
    {
      if ( v8 == 0.0 )
        LODWORD(shader_type) = 3;
      shader_cB = 0;
      v9 = field_8A4;
      shader_cR = v9;
      shader_cG = v9;
    }
    */
  }
  if ( field_8A0 > 0 )
  {
    field_8A0 = field_8A0 - 1;
    field_4AA = 2;
    if ( get_seq() >= 600 && get_seq() <= 689 && get_seq() != 616 )
      field_8A0 = 0;
    if ( get_seq() == 616 && !get_subseq() && !get_frame() )
      field_8A0 = 0;
    if ( health <= 0 || enemy->health <= 0 )
      field_8A0 = 0;
    if ( field_8A0 <= 0 )
      field_4AA = 0;
  }
  
  if ( get_seq() > 149 && get_seq() < 159 && !bbarrier_show )
  {
    bbarrier_show = 1;
    
    if ( get_seq() > 149 && get_seq() < 154 )
    {
      /*
      v14 = dir;
      v15 = y + 94.0;
      v16 = v15;
      v17 = (double)(57 * (char)v14) + x;
      addbullet(, 998, v17, v16, v14, 1, 0, 0);
      */
    }
    if ( get_seq() > 153 && get_seq() < 158 )
    {
      /*
      v19 = dir;
      v20 = y + 60.0;
      v21 = v20;
      v22 = (double)(57 * (char)v19) + x;
      addbullet(, 998, v22, v21, v19, 1, 0, 0);
      */
      
    }
    if ( get_seq() == 158 )
    {
      /*
      v23 = dir;
      v24 = y + 100.0;
      v25 = v24;
      v26 = (double)(57 * (char)v23) + x;
      addbullet(, 998, v26, v25, v23, 1, 0, 0);
      */
      
    }
  }
  if ( !hit_stop )
  {
    if ( !enemy->time_stop )
    {
      if ( get_seq() <= 300 )
      {
        if ( get_seq() == 300 )
        {
LABEL_698:
          sub10func();
          if ( false)//!get_true(0) )
          {
            if ( field_49A )
            {
              h_inerc = h_inerc - 0.5;
              if ( h_inerc - 0.5 < 0.0 )
              {
                h_inerc = 0.0;
                field_49A = 0;
              }
            }
            else
            {
            }
            if ( 0.0 < h_inerc && get_frame() >= 2 )
            {
              h_inerc = h_inerc - 0.75;
              if ( h_inerc - 0.75 < 0.0 )
                h_inerc = 0.0;
            }
            if ( process() )
              set_seq(0);
            if ( !get_frame_time() && get_frame() == 2 )
            {
              h_inerc = 10.0;
              scene_play_sfx(28);
              field_49A = 0;
            }
          }
        }
        else
        {
          switch (sq)
          {
            case 0:
              sub10func();
              if ( 0.0 == h_inerc )
                field_49A = 0;
              if ( !field_49A )
                goto LABEL_87;
              goto LABEL_88;
            case 1:
              sub10func();
              if ( field_49A )
              {
                if ( h_inerc > 0.0 )
                {
                  h_inerc = h_inerc - 0.5;
                  if ( h_inerc - 0.5 < 0.0 )
                  {
                    reset_forces();
                    field_49A = 0;
                  }
                }
                if ( 0.0 > h_inerc )
                {
                  h_inerc = h_inerc + 0.5;
                  if ( h_inerc + 0.5 > 0.0 )
                  {
                    reset_forces();
                    field_49A = 0;
                  }
                }
              }
              else
              {
                reset_forces();
              }
              if ( process() && !get_frame() )
                set_seq(2);
              return;
            case 2:
              sub10func();
              if ( field_49A )
              {
LABEL_88:
                if ( 0.0 < h_inerc )
                {
                  h_inerc = h_inerc - 0.5;
                  if ( h_inerc - 0.5 < 0.0)
                  {
                    reset_forces();
                    field_49A = 0;
                  }
                }
                if ( 0.0 <= h_inerc || (h_inerc + 0.5 <= 0.0) )
                {
LABEL_163:
                  process();
                }
                else
                {
                  reset_forces();
                  field_49A = 0;
                  process();
                }
              }
              else
              {
LABEL_87:
                reset_forces();
                process();
              }
              return;
            case 3:
              sub10func();
              if ( field_49A )
              {
                if ( h_inerc > 0.0 )
                {
                  h_inerc = h_inerc - 0.5;
                  if ( h_inerc - 0.5 < 0.0 )
                  {
                    reset_forces();
                    field_49A = 0;
                  }
                }
                if ( 0.0 > h_inerc )
                {
                  h_inerc = h_inerc + 0.5;
                  if ( h_inerc + 0.5 > 0.0 )
                  {
                    reset_forces();
                    field_49A = 0;
                  }
                }
              }
              else
              {
                reset_forces();
              }
              if ( process() && !get_frame() )
                goto LABEL_117;
              return;
            case 4:
              sub10func();
              char_h_move(3.0);
              process();
              return;
            case 5:
              sub10func();
              char_h_move(-3.0);
              process();
              return;
            case 6:
              if ( !get_subseq() )
              {
                sub10func();
                if ( !get_subseq() )
                {
                  if ( !field_49A )
                    reset_forces();
                }
              }
              if ( !(get_subseq() < 0 | get_subseq() == 0) )
              {
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                  goto LABEL_160;
              }
              process();
              if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
                return;
              v40 = 0.0;
              goto LABEL_132;
            case 7:
              if ( !get_subseq() )
              {
                sub10func();
                if ( !get_subseq() )
                {
                  if ( !field_49A )
                    reset_forces();
                }
              }
              if ( !(get_subseq() < 0 | get_subseq() == 0) )
              {
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                  goto LABEL_160;
              }
              process();
              if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
                return;
              v40 = 3.0;
              goto LABEL_132;
            case 8:
              if ( !get_subseq() )
              {
                sub10func();
                if ( !get_subseq() )
                {
                  if ( !field_49A )
                    reset_forces();
                }
              }
              if ( !(get_subseq() < 0 | get_subseq() == 0) )
              {
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                  goto LABEL_160;
              }
              process();
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                v40 = -3.0;
LABEL_132:
                char_h_move(v40);
                v_inerc = 13.0;
                v_force = 0.30000001;
                field_49A = 0;
              }
              return;
            case 9:
              if ( 0.0 == v_force )
                v_force = 0.60000002;
              v_inerc = v_inerc - v_force;
              if ( !char_on_ground_down() )
               goto LABEL_163;
LABEL_160:
              move_val = 10;
              goto LABEL_161;
            case 10:
              sub10func();
              reset_forces();
              if ( !process() )
                return;
              if ( dY() )
                goto LABEL_167;
              set_seq(0);
              return;
            case 197:
              sub10func();
              if ( process() )
              {
                set_seq(0);
                if ( dY() > 0 )
                  set_seq(1);
              }
              if ( get_elaps_frames() )
                return;
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                h_inerc = 15.0;
              if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 2 )
                return;
              h_inerc = 0.0;
              goto LABEL_181;
            case 198:
              sub10func();
              if ( process() )
              {
                set_seq(0);
                if ( dY() > 0 )
                  set_seq(1);
              }
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  h_inerc = -15.0;
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                {
                  h_inerc = 0.0;
                  if ( enemy->x < (double)x )
                    dir = -1;
                  if ( enemy->x > (double)x )
                    dir = 1;
                }
              }
              return;
            case 199:
              sub10func();
              if ( !process() )
                goto LABEL_206;
              if ( controlling_type == 2 )
              {
                set_seq(700);
                field_51C = 3;
                field_520 = 3;
              }
              else
              {
                set_seq(0);
                if ( dY() > 0 )
                  set_seq(1);
LABEL_206:
                if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
                {
LABEL_181:
                  if ( enemy->x < (double)x )
                    dir = -1;
                  if ( enemy->x > (double)x )
                    dir = 1;
                }
              }
              return;
            case 200:
              sub10func();
              field_49A = 1;
              if ( h_inerc > 12.0 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc - 0.5 < 12.0 )
                  h_inerc = 12.0;
              }
              process();
              if ( get_subseq() != 1 )
                goto LABEL_224;
              if ( !(get_elaps_frames() % 5) )
              {

                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50.0, (scene_rand() % 200) + y, dir, 1);
              }
              if ( dY() >= 0 )
              {
                if ( (dX(dir) > 0 || ++field_7D0 <= 20) && ++field_7D0 <= 45 )
                {
LABEL_224:
                  if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  {
                    char_h_move(18.5);
                    scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
                    scene_add_effect(this, 126, x, y + 80.0, dir, 1);
                    scene_play_sfx(31);
                  }
                }
                else
                {
                  set_seq(204);
                }
              }
              else
              {
                if ( dX(dir) < 0 | dX(dir) == 0 )
                  set_seq(211);
                else
                  set_seq(212);
              }
              return;
            case 201:
              if ( !get_subseq() || get_subseq() == 3 )
              {
                sub10func();
                
              }
              if ( get_subseq() == 3 )
              {
                h_inerc = h_inerc + 2.0;
                if ( h_inerc + 2.0 > 0.0 )
                  h_inerc = 0.0;
              }
              if ( !char_on_ground_flag() )
              {
                if ( !(get_elaps_frames() % 5) )
                {
                  scene_add_effect(this, 124, x - (scene_rand() % 100) + 50.0, (scene_rand() % 200) + y, -dir, 1);
                }
                if ( h_inerc < -12.0 )
                {
                  h_inerc = h_inerc + 0.5;
                  if ( h_inerc + 0.5 > -12.0 )
                    h_inerc = -12.0;
                }
              }
              if ( get_subseq() < 3 )
              {
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                  goto LABEL_243;
              }
              if ( process() )
              {
                set_seq(0);
                reset_forces();
              }
              else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                char_h_move(-18.5);
                v_inerc = 4.0;
                v_force = 0.25;
                /*
                v73 = y + 80.0;
                scene_add_effect(this, 125, x, v73, -dir, 1);
                v74 = y + 80.0;
                scene_add_effect(this, 126, x, v74, -dir, 1);
                */
                scene_play_sfx(31);
              }
              return;
            case 202:
              if ( h_inerc > 12.0 )
              {
                h_inerc = h_inerc - 0.3499999940395355;
                if ( h_inerc - 0.3499999940395355 < 12.0 )
                  h_inerc = 12.0;
              }
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_255;
              if ( (get_subseq() == 1 || get_subseq() == 2) && !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50.0, (scene_rand() % 200) + y, dir, 1);
              }
              process();
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                field_7D0 = 0;
                char_h_move(18.5);
                v_inerc = 6.0;
                v_force = 0.5;
                scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
                scene_add_effect(this, 126, x, y + 110.0, dir, 1);
                scene_play_sfx(31);
              }
              if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
                flip_with_force();
              return;
            case 203:
              v_inerc = v_inerc - v_force;
              if ( h_inerc < -12.0 )
              {
                h_inerc = h_inerc + 0.5;
                if ( h_inerc + 0.5 > -12.0 )
                  h_inerc = -12.0;
              }
              if ( char_on_ground_down() )
              {
                reset_forces();
                y = getlvl_height();
                set_seq(10);
              }
              else
              {
                if ( get_subseq() < 3 && !(get_elaps_frames() % 5) )
                {
                  scene_add_effect(this, 124, x - (scene_rand() % 100) + 50.0, (scene_rand() % 200) + y, -dir, 1);
                }
                process();
                if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
                {
                  char_h_move(-18.5);
                  v_inerc = 6.0;
                  v_force = 0.5;
                  scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
                  scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
                  scene_play_sfx(31);
                }
                if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
                  flip_with_force();
              }
              return;
            case 204:
              sub10func();
              h_inerc = h_inerc - 0.5;
              if ( h_inerc - 0.5 < 0.0 )
              {
                h_inerc = 0.0;
                field_49A = 0;
              }
              if ( process() )
              {
                set_seq(0);
                field_49A = 0;
              }
              return;
            case 208:
              if ( !get_subseq() )
                sub10func();
              if ( char_on_ground_down() )
                goto LABEL_292;
              if ( char_on_ground_flag() || v_inerc > 0.0 )
                field_522 = 2;
              if ( get_subseq() > 0 )
              {
                v_inerc = v_inerc - v_force;
                if ( v_inerc - v_force < -20.0 )
                  v_inerc = -20.0;
              }
              if ( get_subseq() == 1 && v_inerc < 4.0 )
                set_subseq(2);
              process();
              if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
                return;
              v99 = 0.0;
              goto LABEL_307;
            case 209:
            case 212:
              if ( !get_subseq() )
                sub10func();
              if ( char_on_ground_down() )
                goto LABEL_292;
              if ( char_on_ground_flag() || v_inerc > 0.0 )
                field_522 = 2;
              if ( get_subseq() > 0 )
              {
                v_inerc = v_inerc - v_force;
                if ( v_inerc - v_force < -20.0 )
                  v_inerc = -20.0;
              }
              if ( get_subseq() == 1 && v_inerc < 4.0 )
                set_subseq(2);
              process();
              if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
                return;
              v104 = 10.0;
              goto LABEL_327;
            case 210:
              if ( !get_subseq() )
                sub10func();
              if ( char_on_ground_down() )
                goto LABEL_292;
              if ( char_on_ground_flag() || v_inerc > 0.0 )
                field_522 = 2;
              if ( get_subseq() > 0 )
              {
                v_inerc = v_inerc - v_force;
                if ( v_inerc - v_force < -20.0 )
                  v_inerc = -20.0;
              }
              if ( get_subseq() == 1 && v_inerc < 4.0 )
                set_subseq(2);
              process();
              if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
                return;
              v104 = -10.0;
LABEL_327:
              char_h_move(v104);
              v_inerc = 16.0;
              v101 = 0.5;
              goto LABEL_308;
            case 211:
              if ( !get_subseq() )
                sub10func();
              if ( char_on_ground_down() )
                goto LABEL_292;
              if ( char_on_ground_flag() || v_inerc > 0.0 )
                field_522 = 2;
              if ( get_subseq() > 0 )
              {
                v_inerc = v_inerc - v_force;
                if ( v_inerc - v_force < -20.0 )
                  v_inerc = -20.0;
              }
              if ( get_subseq() == 1 && v_inerc < 4.0 )
                set_subseq(2);
              process();
              if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
                return;
              v99 = 3.0;
LABEL_307:
              char_h_move(v99);
              v_inerc = 17.5;
              v101 = 0.40000001;
              goto LABEL_308;
            case 214:
              if ( process() )
                goto LABEL_1039;
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                scene_play_sfx(31);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
                goto LABEL_1039;
              if ( dY() < 0 | dY() == 0 )
              {
                if ( dY() < 0 )
                {
                  if ( dX(dir) <= 0 )
                    field_7D2 = dX(dir) >= 0 ? 90 : 135;
                  else
                    field_7D2 = 45;
                }
                else
                {
                  if ( dX(dir) <= 0 )
                  {
                    if ( dX(dir) < 0 )
                      field_7D2 = 180;
                  }
                  else
                  {
                    field_7D2 = 0;
                  }
                }
              }
              else
              {
                if ( dX(dir) <= 0 )
                  field_7D2 = dX(dir) >= 0 ? -90 : -135;
                else
                  field_7D2 = -45;
              }
              if ( get_subseq() == 5 || get_subseq() == 6 )
                v_inerc = v_inerc - v_force;
              if ( get_subseq() <= 0 || get_subseq() >= 5 )
                goto LABEL_453;
              ++field_7D6;
              field_7D4 = field_7D2 - dash_angle;
              if ( field_7D2 - dash_angle > 180 )
                field_7D4 = field_7D2 - dash_angle - 360;
              if ( field_7D4 < -180 )
                field_7D4 = field_7D4 + 360;
              if ( field_7D4 > 0 )
              {
                if ( weather_id )
                  dash_angle = dash_angle + 0.5;
                else
                  dash_angle = dash_angle + 1.5;
              }
              if ( field_7D4 < 0 )
              {
                if ( weather_id )
                   dash_angle = dash_angle - 0.5;
                else
                   dash_angle = dash_angle - 1.5;
              }
              h_inerc = cos_deg(dash_angle) * field_7DC;
              v_inerc = sin_deg(dash_angle) * field_7DC;
              if ( y > 680.0 && sin_deg(dash_angle) * field_7DC > 0.0 )
                v_inerc = 0.0;
              field_7DC = field_7DC + 0.300000011920929;
              if ( field_7DC + 0.300000011920929 > 12.0 )
                field_7DC = 12.0;
              if ( weather_id )
                spell_energy_spend(10, 1);
              else
                spell_energy_spend(5, 1);
              angZ = -dash_angle;
              if ( h_inerc < 0.0 )
                angZ = 180.0 - dash_angle;
              if ( h_inerc < 0.0 && get_subseq() == 1 )
              {
                set_subseq(3);
              }
              if ( 0.0 <= h_inerc && get_subseq() == 3 )
              {
                set_subseq(1);
              }
              if ( 0.0 > h_inerc && get_subseq() == 2 )
              {
                set_subseq(4);
              }
              if ( 0.0 <= h_inerc && get_subseq() == 4 )
                set_subseq(2);
              if ( get_elaps_frames() % 5 != 1 )
                goto LABEL_428;
              a2 = dir;
              y = sin_deg(dash_angle) * 100.0 + y + 100.0;
              v129 = cos_deg(dash_angle) * 100.0 * (double)dir + x;
              goto LABEL_427;
            case 215:
              sub10func();
              if ( h_inerc > 0.0 )
              {
                h_inerc = h_inerc - 0.75;
                if ( h_inerc - 0.75 < 0.0 )
                  h_inerc = 0.0;
              }
              if ( h_inerc < 0.0 )
              {
                h_inerc = h_inerc + 0.75;
                if ( h_inerc + 0.75 > 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                goto LABEL_464;
              return;
            case 216:
              if ( process() )
                goto LABEL_1116;
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                scene_play_sfx(31);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
                goto LABEL_1116;
              field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
              if ( get_subseq() == 5 || get_subseq() == 6 )
                v_inerc = v_inerc - v_force;
              if ( get_subseq() > 0 && get_subseq() < 5 )
              {
                ++field_7D6;
                field_7D4 = field_7D2 - dash_angle;
                if ( field_7D2 - dash_angle > 180 )
                  field_7D4 = field_7D2 - dash_angle - 360;
                if ( field_7D4 < -180 )
                  field_7D4 = field_7D4 + 360;
                if ( field_7D4 > 0 )
                {
                  if ( weather_id )
                    dash_angle = dash_angle + 0.5;
                  else
                    dash_angle = dash_angle + 1.5;
                }
                if ( field_7D4 < 0 )
                {
                  if ( weather_id )
                    dash_angle = dash_angle - 0.5;
                  else
                    dash_angle = dash_angle - 1.5;
                }
                h_inerc = cos_deg(dash_angle) * field_7DC;
                v_inerc = sin_deg(dash_angle) * field_7DC;
                if ( y > 680.0 && sin_deg(dash_angle) * field_7DC > 0.0 )
                  v_inerc = 0.0;
                field_7DC = field_7DC + 0.300000011920929;
                if ( field_7DC + 0.300000011920929 > 12.0 )
                  field_7DC = 12.0;
                if ( weather_id )
                  spell_energy_spend(10, 1);
                else
                  spell_energy_spend(5, 1);
                angZ = -dash_angle;
                if ( h_inerc < 0.0 )
                  angZ = 180.0 - dash_angle;
                if ( h_inerc < 0.0 && get_subseq() == 1 )
                {
                  set_subseq(3);
                }
                if ( 0.0 <= h_inerc && get_subseq() == 3 )
                {
                  set_subseq(1);
                }
                if ( 0.0 > h_inerc && get_subseq() == 2 )
                {
                  set_subseq(4);
                }
                if ( 0.0 <= h_inerc && get_subseq() == 4 )
                  set_subseq(2);
                if ( get_elaps_frames() % 5 == 1 )
                {
                  a2 = dir;
                  y = sin_deg(dash_angle) * 100.0 + y + 100.0;
                  v129 = cos_deg(dash_angle) * 100.0 * (double)dir + x;
LABEL_427:
                  scene_add_effect(this, 125, v129, y, a2, 1);
                }
LABEL_428:
                if ( !keyDown(INP_D) && field_7D6 > 10 )
                  goto LABEL_3213;
                if ( spell_energy <= 0 )
                {
LABEL_3213:
                  if ( !keyDown(INP_D) && field_7D6 > 10 || spell_energy <= 0 )
                  {
                    reset_ofs();
                    goto LABEL_435;
                  }
                }
              }
LABEL_453:
              if ( !char_on_ground_down() )
                return;
              y = getlvl_height();
              v_force = 0.0;
              v_inerc = 0.0;
              if ( get_subseq() < 5 )
                goto LABEL_455;
              set_seq(10);
              reset_forces();
              return;
            case 217:
              if ( process() )
                goto LABEL_1116;
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                scene_play_sfx(31);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 6 )
                goto LABEL_1116;
              field_7D2 = atan2_deg(enemy->y + 100.0 - y, (enemy->x - x) * (double)dir);
              if ( get_subseq() == 5 || get_subseq() == 6 )
                v_inerc = v_inerc - v_force;
              if ( get_subseq() <= 0 || get_subseq() >= 5 )
                goto LABEL_3214;
              ++field_7D6;
              field_7D4 = field_7D2 - dash_angle;
              if ( field_7D2 - dash_angle > 180 )
                field_7D4 = field_7D2 - dash_angle - 360;
              if ( field_7D4 < -180 )
                field_7D4 = field_7D4 + 360;
              if ( field_7D4 > 0 )
              {
                if ( weather_id )
                  dash_angle = dash_angle + 0.25;
                else
                  dash_angle = dash_angle + 1.5;
              }
              if ( field_7D4 < 0 )
              {
                if ( weather_id )
                  dash_angle = dash_angle - 0.25;
                else
                  dash_angle = dash_angle - 1.5;
              }
              h_inerc = cos_deg(dash_angle) * field_7DC;
              v_inerc = sin_deg(dash_angle) * field_7DC;
              if ( y > 680.0 && sin_deg(dash_angle) * field_7DC > 0.0 )
                v_inerc = 0.0;
              field_7DC = field_7DC + 0.300000011920929;
              if ( field_7DC + 0.300000011920929 > 14.5 )
                field_7DC = 14.5;
              if ( weather_id )
                spell_energy_spend(15, 60);
              else
                spell_energy_spend(10, 1);
              angZ = -dash_angle;
              if ( h_inerc < 0.0 )
                angZ = 180.0 - dash_angle;
              if ( h_inerc < 0.0 && get_subseq() == 1 )
              {
                set_subseq(3);
              }
              if ( 0.0 <= h_inerc && get_subseq() == 3 )
              {
                set_subseq(1);
              }
              if ( 0.0 > h_inerc && get_subseq() == 2 )
              {
                set_subseq(4);
              }
              if ( 0.0 <= h_inerc && get_subseq() == 4 )
                set_subseq(2);
              if ( get_elaps_frames() % 5 == 1 )
              {
                scene_add_effect(this, 125, cos_deg(dash_angle) * 100.0 * (double)dir + x, sin_deg(dash_angle) * 100.0 + y + 100.0, dir, 1);
              }
              if ( ((keyDown(INP_D)) != 0 || field_7D6 <= 20) && spell_energy > 0 || (keyDown(INP_D) || field_7D6 <= 20) && spell_energy > 0 )
              {
LABEL_3214:
                if ( char_on_ground_down() )
                {
                  y = getlvl_height();
                  v_force = 0.0;
                  v_inerc = 0.0;
                  if ( get_subseq() < 5 )
                  {
LABEL_455:
                    reset_ofs();
                    set_seq(215);
                  }
                  else
                  {
                    set_seq(10);
                    reset_forces();
                  }
                }
              }
              else
              {
                reset_ofs();
LABEL_435:
                if (get_subseq() == 1 || get_subseq() == 2 )
                {
                  if ( dir == 1 )
                  {
                    if ( enemy->x >= x )
                    {
                      set_subseq(5);
                    }
                    else
                    {
                      dir = -1;
                      h_inerc = -h_inerc;
                      set_subseq(6);
                    }
                  }
                  else if ( enemy->x <= x )
                  {
                    set_subseq(5);
                  }
                  else
                  {
                    dir = -dir;
                    h_inerc = -h_inerc;
                    set_subseq(6);
                  }
                }
                if ( get_subseq() == 3 || get_subseq() == 4 )
                {
                  if ( dir == 1 )
                  {
                    if ( enemy->x >= x )
                    {
                      set_subseq(6);
                    }
                    else
                    {
                      dir = -1;
                      h_inerc = -h_inerc;
                      set_subseq(5);
                    }
                  }
                  else if ( enemy->x <= x )
                  {
                    set_subseq(6);
                  }
                  else
                  {
                    dir = -dir;
                    h_inerc = -h_inerc;
                    set_subseq(5);
                  }
                }
              }
              return;
            case 220:
              if ( !get_subseq() )
                sub10func();
              if ( char_on_ground_down() )
              {
                set_seq(10);
                goto LABEL_162;
              }
              if ( char_on_ground_flag() || v_inerc > 0.0 )
                field_522 = 2;
              if ( get_subseq() > 0 )
              {
                v_inerc = v_inerc - v_force;
                if ( v_inerc - v_force < -20.0 )
                  v_inerc = -20.0;
              }
              if ( get_subseq() == 1 && v_inerc < 4.0 )
                set_subseq(2);
              process();
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                char_h_move(0.0);
                v_inerc = 22.5;
                v_force = 0.85000002;
                field_49A = 0;
                scene_add_effect(this, 63, x, y, dir, 1);
              }
              break;
            case 221:
              if ( !get_subseq() )
                sub10func();
              if ( char_on_ground_down() )
                goto LABEL_292;
              if ( char_on_ground_flag() || v_inerc > 0.0 )
                field_522 = 2;
              if ( get_subseq() > 0 )
              {
                v_inerc = v_inerc - v_force;
                if ( v_inerc - v_force < -20.0 )
                  v_inerc = -20.0;
              }
              if ( get_subseq() == 1 && v_inerc < 4.0 )
                set_subseq(2);
              process();
              if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
                return;
              v182 = 10.0;
              goto LABEL_616;
            case 222:
              if ( !get_subseq() )
                sub10func();
              if ( char_on_ground_down() )
                goto LABEL_292;
              if ( char_on_ground_flag() || v_inerc > 0.0 )
                field_522 = 2;
              if ( get_subseq() > 0 )
              {
                v_inerc = v_inerc - v_force;
                if ( v_inerc - v_force < -20.0 )
                  v_inerc = -20.0;
              }
              if ( get_subseq() == 1 && v_inerc < 4.0 )
                set_subseq(2);
              process();
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                v182 = -10.0;
LABEL_616:
                char_h_move(v182);
                v_inerc = 18.0;
                v101 = 0.85000002;
LABEL_308:
                v_force = v101;
                field_49A = 0;
                scene_add_effect(this, 63, x, y, dir, 1);
              }
              return;
            case 223:
              sub10func();
              field_49A = 1;
              process();
              if ( get_elaps_frames() || get_frame_time() || get_frame() )
                goto LABEL_640;
              if ( get_subseq() == 1 )
              {
                if ( !field_7D0 )
                {
                  char_h_move(7.5);
                  scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
                  scene_add_effect(this, 126, x, y + 80.0, dir, 1);
                  scene_play_sfx(31);
                }
LABEL_640:
                if ( get_subseq() == 1 )
                {
                  if ( !(get_elaps_frames() % 5) )
                  {
                    scene_add_effect(this, 124, x - (scene_rand() % 100) + 50, (scene_rand() % 200) + y, dir, 1);
                  }
                  if ( dX(dir) <= 0 && ++field_7D0 > 15 || ++field_7D0 > 45 )
                    set_seq(204);
                }
              }
              return;
            case 224:
              if ( !get_subseq() || get_subseq() == 3 )
              {
                sub10func();
                
              }
              if ( get_subseq() == 3 )
              {
                h_inerc = h_inerc + 2.0;
                if ( h_inerc + 2.0 > 0.0 )
                  h_inerc = 0.0;
              }
              if ( !char_on_ground_flag() && !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50.0, (scene_rand() % 200) + y, -dir, 1);
              }
              if ( get_subseq() < 3 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
              {
LABEL_243:
                v_inerc = 0.0;
                v_force = 0.0;
                y = getlvl_height();
                set_subseq(3);
              }
              else if ( process() )
              {
                set_seq(0);
                h_inerc = 0.0;
                v_force = 0.0;
              }
              else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 && !field_7D0 )
              {
                field_7D0 = 1;
                char_h_move(-14.0);
                v_inerc = 4.0;
                v_force = 0.5;
                scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
                scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
                scene_play_sfx(31);
              }
              return;
            case 225:
              if ( get_subseq() >= 1 )
                v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_255;
              if ( get_subseq() >= 2 && !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50.0,  (scene_rand() % 200) + y, -dir, 1);
              }
              if ( process() )
                set_seq(9);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                char_h_move(-11.0);
                v_inerc = 4.0;
                v_force = 0.5;
                scene_add_effect(this, 125, x, y + 120.0, -dir, 1);
                scene_add_effect(this, 126, x, y + 120.0, -dir, 1);
                scene_play_sfx(31);
              }
              return;
            case 226:
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_255;
              if ( get_subseq() == 1 && !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 124, x - (scene_rand() % 100) + 50.0, (scene_rand() % 200) + y, dir, 1);
              }
              if ( process() )
                set_seq(9);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  field_7D0 = 0;
                  char_h_move(11.0);
                  v_inerc = 4.0;
                  v_force = 0.5;
                  scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 110.0, dir, 1);
                  scene_add_effect(this, 126, x, y + 110.0, dir, 1);
                  scene_play_sfx(31);
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                  flip_with_force();
              }
              return;
            default:
              char_c::func10();
              return;
          }
        }
        return;
      }
      if ( get_seq() <= 500 )
      {
        if ( get_seq() == 500 )
        {
          sub10func();
          field_18C = 0;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            field_190 = 1;
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 5 )
            {
              /*
              double v1325 = 120.0;
              if ( skills_1[0] >= 2 )
                v1325 = 150.0;
              if ( skills_1[0] >= 4 )
                v1325 = 180.0;
              float v1410 = 0.0;
              double v1411 = v1325;
              double v1412 = 4.0;
              double v393 = 0.0;
              if ( skills_1[0] < 3 )
              {
                v393 = v1325;
              }
              else
              {
                v393 = v1325;
                v1412 = 0.0;
              }
              //v1413 = 40.0;
              v394 = dir;
              v395 = y + 100.0;
              v396 = v395;
              v397 = v393 * (double)(char)v394 + x;
              addbullet(, 810, v397, v396, v394, 1, (int)v1410, 4);
              v1410 = 180.0;
              v1411 = v1325;
              addbullet(, 810, x - v1325 * (double)(char)dir, y + 100.0, dir, 1, (int)v1410, 4);
              v1412 = 3.0;
              addbullet(, 810, x, getlvl_height(), dir, -1, (int)v1410, 4);
              */
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(20);
            }
            if ( !get_frame_time() && get_frame() == 7 && skills_1[0] >= 3 )
            {
              /*
              *(float *)&v1645 = 0.0;
              v1646 = 0.0;
              a2c = &v1645;
              v1647 = 6.0;
              a1a = dir;
              v404 = y + 140.0;
              a4a = v404;
              v405 = (double)(7 * (char)a1a) + x;
              v406 = v405;
LABEL_1364:
              v407 = v406;
              addbullet(, 810, v407, a4a, a1a, 1, (int)a2c, 3);
              */
            }
          }
LABEL_1365:
          if ( get_subseq() == 1 && get_elaps_frames() >= 20 )
          {
LABEL_965:
            next_subseq();
          }
          else if ( get_subseq() == 3 && !get_frame_time() && !get_frame() )
          {
            set_seq(0);
          }
        }
        else
        {
          switch (sq)
          {
            case 301:
              sub10func();
              if (false /*get_true(0)*/ )
                return;
              if ( field_49A )
              {
                h_inerc = h_inerc - 0.5;

                if ( h_inerc - 0.5 < 0.0 )
                {
                  h_inerc = 0.0;
                  field_49A = 0;
                }
              }

              if ( !keyDown(INP_A) )
                not_charge_attack = 0;
              if ( get_frame() > 4 )
              {
                h_inerc = h_inerc - 1.5;
                if ( h_inerc - 1.5 < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                goto LABEL_117;
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                set_seq(0);
                return;
              }
              if ( get_subseq() )
                goto LABEL_740;
              if ( get_frame_time() )
                goto LABEL_737;
              if ( get_frame() != 2 )
                goto LABEL_734;
              if ( not_charge_attack == 1 )
              {
                next_subseq();
                scene_add_effect(this, 62, x - (double)(55 * (char)dir), y + 97.0, dir, 1);
              }
              else
              {
                h_inerc = 15.0;
LABEL_734:
                if ( !get_frame_time() && get_frame() == 4 )
                {
                  h_inerc = 10.0;
                  play_sfx(10);
                  field_49A = 0;
                }
LABEL_737:
                
LABEL_740:
                if ( get_frame() > 3 )
                {
                  h_inerc = h_inerc - 0.5;

                  if ( h_inerc - 0.5 < 0.0 )
                    h_inerc = 0.0;
                }
                if ( get_subseq() == 1 )
                {
                  if ( !get_frame_time() )
                  {
                    if ( get_frame() == 1 )
                      h_inerc = 17.5;
                    if ( !get_frame_time() && get_frame() == 3 )
                    {
                      h_inerc = 10.0;
                      scene_play_sfx(29);

                      field_49A = 0;
                    }
                  }
                  if ( get_frame() > 2 )
                  {
                    h_inerc = h_inerc - 0.5;
                    if ( h_inerc - 0.5 < 0.0  )
                      h_inerc = 0.0;
                  }
                }
              }
              return;
            case 302:
              sub10func();
              if (false /*get_true(1)*/ )
                return;
              if ( field_49A )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc - 0.5 < 0.0 )
                {
                  h_inerc = 0.0;
                  field_49A = 0;
                }
              }
              if ( !keyDown(INP_A) )
                not_charge_attack = 0;
              if ( process() || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                goto LABEL_117;
              if ( get_subseq() || get_frame_time() )
                goto LABEL_771;
              if ( get_frame() != 3 )
                goto LABEL_768;
              if ( not_charge_attack == 1 )
              {
                next_subseq();
                scene_add_effect(this, 62, (double)(42 * (char)dir) + x, y + 84.0, dir, 1);
              }
              else
              {
                h_inerc = 15.0;
LABEL_768:
                if ( !get_frame_time() && get_frame() == 4 )
                {
                  play_sfx(11);
                  scene_add_effect(this, 58, (double)(57 * (char)dir) + x, y, dir, -1);
                  //shake_camera(4.0);
                  field_49A = 0;
                  h_inerc = 0.0;
                }
LABEL_771:
                if ( get_subseq() == 1 && !get_frame_time() )
                {
                  if ( get_frame() == 1 )
                    h_inerc = 15.0;
                  if ( !get_frame_time() && get_frame() == 2 )
                  {
                    play_sfx(11);
                    scene_add_effect(this, 58, (double)(57 * (char)dir) + x, y, dir, -1);
                    //shake_camera(8.0);
                    field_49A = 0;
                    h_inerc = 0.0;
                  }
                }
              }
              return;
            case 303:
              sub10func();
              if (false /*!get_true(0)*/ )
              {
                if ( field_49A > 0 )
                {
                  h_inerc = h_inerc - 0.6000000238418579;
                  if ( h_inerc - 0.6000000238418579 < 0.0 )
                  {
                    h_inerc = 0.0;
                    field_49A = 0;
                  }
                }
                if ( process() )
                  set_seq(2);
                if ( !get_frame_time() && get_frame() == 2 )
                  scene_play_sfx(28);
              }
              return;
            case 304:
              sub10func();
              if (false /*get_true(0)*/ )
                return;
              if ( h_inerc > 0.0 )
              {
                h_inerc = h_inerc - 2.0;
                if ( h_inerc - 2.0 < 0.0 )
                  h_inerc = 0.0;
              }
              if ( !keyDown(INP_A) )
                not_charge_attack = 0;
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                set_seq(0);
                return;
              }
              if ( get_subseq() || get_frame_time() || get_frame() != 3 )
                goto LABEL_806;
              if ( not_charge_attack == 1 )
              {
                next_subseq();
                scene_add_effect(this, 62, x, y + 95.0, dir, 1);
              }
              else
              {
                h_inerc = 8.0;
                scene_play_sfx(29);
LABEL_806:
                if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 1 )
                {
                  h_inerc = 8.0;
                  scene_play_sfx(29);
                }
              }
              return;
            case 305:
              sub10func();
              if (false /*!get_true(1)*/ )
              {
                if ( get_frame() >= 4 )
                {
                  h_inerc = h_inerc - 1.5;
                  if ( h_inerc - 1.5 < 0.0 )
                    h_inerc = 0.0;
                }
                if ( process() )
                  set_seq(0);
                if ( !get_frame_time() && get_frame() == 4 )
                  scene_play_sfx(29);
              }
              return;
            case 306:
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_292;
              if ( process() )
                set_seq(9);
              if ( !get_frame_time() && get_frame() == 3 )
              {
                /*
                play_sfx(10);
                *(float *)&v1654 = 0.0;
                v1655 = 0.0;
                v1656 = 1.0;
                addbullet(, 848, x, y, dir, 1, (int)&v1654, 3);
                */
              }
              return;
            case 307:
              if ( get_subseq() == 1 )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc - 0.5 < 12.5 )
                  h_inerc = 12.5;
              }
              if ( get_subseq() < 3 )
              {
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                {
                  set_subseq(3);
                  goto LABEL_162;
                }
              }
              if ( process() )
                set_seq(0);
              if ( !get_subseq() && !get_frame_time() && get_frame() == 2 )
                reset_forces();
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
                  set_seq(9);
                if ( !get_elaps_frames() )
                {
                  if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  {
                    h_inerc = 20.0;
                    v_inerc = 0.0;
                    play_sfx(12);
                    /*
                    *(float *)&v1660 = 0.0;
                    v1661 = 0.0;
                    v1662 = 3.0;
                    addbullet(, 848, x, y, dir, 1, (int)&v1660, 3);
                    */
                  }
                  if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                  {
                    h_inerc = h_inerc * 0.5;
                    v_force = 0.5;
                  }
                }
              }
              return;
            case 308:
              if ( !keyDown(INP_A) )
                not_charge_attack = 0;
              if ( get_subseq() == 2 || get_subseq() == 6 )
                v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
                goto LABEL_292;
              if ( process() )
                set_seq(9);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                  scene_play_sfx(29);
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                  v_force = 0.5;
              }
              if ( get_elaps_frames() )
                goto LABEL_879;
              if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
                goto LABEL_1039;
              if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
                play_sfx(10);
LABEL_879:
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
              {
                /*
                *(float *)&v1666 = 0.0;
                v1667 = 0.0;
                v1668 = 4.0;
                addbullet(, 848, x, y, dir, 1, (int)&v1666, 3);
                */
                //shake_camera(5.0);
                play_sfx(10);
                h_inerc = -4.0;
                v_inerc = 10.0;
                v_force = 0.75;
              }
              if ( !get_subseq() && !get_frame_time() && get_frame() == 3 && not_charge_attack == 1 )
              {
                scene_add_effect(this, 62, x - (double)(79 * (char)dir), y + 178.0, dir, 1);
                set_subseq(3);
              }
              return;
            case 309:
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
LABEL_292:
                set_seq(10);
                goto LABEL_162;
              }
              if ( process() )
                set_seq(9);
              if ( !get_frame_time() && get_frame() == 2 )
              {
                scene_play_sfx(29);
                v_inerc = 12.5;
                v_force = 0.60000002;
              }
              return;
            case 310:
              if ( get_subseq() == 2 )
              {
                h_inerc = h_inerc - 1.0;
                if ( h_inerc - 1.0 < 0.0 )
                  h_inerc = 0.0;
                sub10func();
              }
              else
              {
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                {
                  set_subseq(2);
                  y = getlvl_height();
                  v_inerc = 0.0;
                  v_force = 0.0;
                  field_190 = 1;
                }
              }
              if ( process() )
              {
                if ( dY() > 0 )
LABEL_167:
                  set_seq(2);
                else
                  set_seq(3);
              }
              else if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
              {
                scene_play_sfx(29);
              }
              return;
            case 320:
              sub10func();
              if (true /*!get_true(0)*/ )
              {
                if ( get_frame() >= 4 )
                {
                  h_inerc = h_inerc - 0.75;
                  if ( h_inerc - 0.75 < 0.0 )
                    h_inerc = 0.0;
                }
                if ( process() )
                  set_seq(0);
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 2 )
                  {
                    h_inerc = 10.0;
                    field_49A = 0;
                  }
                  if ( !get_frame_time() && get_frame() == 3 )
                    play_sfx(10);
                }
              }
              return;
            case 321:
              sub10func();
              if (false /*!get_true(1)*/ )
              {
                if ( get_frame() > 3 )
                {
                  h_inerc = h_inerc - 0.5;
                  if ( h_inerc - 0.5 < 0.0 )
                    h_inerc = 0.0;
                }
                if ( process() )
                  set_seq(0);
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 3 )
                  {
                    h_inerc = 15.0;
                    field_49A = 0;
                  }
                  if ( !get_frame_time() && get_frame() == 4 )
                  {
                    h_inerc = 0.0;
                    play_sfx(11);
                    scene_add_effect(this, 58, (double)(57 * (char)dir) + x, y,dir, -1);
                    //shake_camera(8.0);
                  }
                }
              }
              return;
            case 322:
              sub10func();
              if (false /*get_true(1)*/ )
                return;
              if ( h_inerc > 0.0 )
              {
                h_inerc = h_inerc - 2.0;
                if ( h_inerc - 2.0 < 0.0 )
                  h_inerc = 0.0;
              }
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                goto LABEL_117;
              if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
              {
                h_inerc = 8.0;
                scene_play_sfx(29);
              }
              return;
            case 330:
              goto LABEL_698;
            case 400:
              sub10func();
              if ( !keyDown(INP_B) )
                not_charge_attack = 0;
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                set_seq(0);
                return;
              }
              if ( get_subseq() )
                goto LABEL_968;
              if ( !get_frame_time() && get_frame() == 1 )
              {
                /*
                *(float *)&v1672 = 0.0;
                v1673 = 0.0;
                v1674 = 5.0;
                v264 = dir;
                v265 = get_pframe();
                v266 = y - (double)v265->extra1[5];
                v267 = v266;
                v268 = (double)(v265->extra1[4] * (char)v264) + x;
                addbullet(, 800, v268, v267, v264, 1, (int)&v1672, 3);
                */
              }
              if ( get_frame_time() )
                goto LABEL_968;
              if ( get_frame() == 4 && not_charge_attack )
              {
                a2a = dir;
                ya = y + 181.0;
                v271 = (double)(53 * (char)a2a) + x;
                goto LABEL_964;
              }
              if ( get_frame() == 7 )
              {
                field_89C = 1;
                sub_486FD0(20.0, -20.0);
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(30);
              }
LABEL_968:
              if ( get_subseq() == 1 )
              {
                if ( ++field_7D0 > 15 && !not_charge_attack )
                  goto LABEL_965;
                if ( ++field_7D0 >= 60 )
                  goto LABEL_965;
              }
              if ( get_subseq() != 2 || get_frame_time() || get_frame() != 3 )
                return;
              move_vala = -20.0;
              v274 = 20.0;
              goto LABEL_976;
            case 401:
              sub10func();
              if ( !keyDown(INP_B) )
                not_charge_attack = 0;
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                set_seq(0);
                return;
              }
              if ( get_subseq() || get_frame_time() )
                goto LABEL_993;
              if ( get_frame() == 4 && not_charge_attack )
              {
                v276 = y + 181.0;
                a2a = dir;
                ya = v276;
                v277 = (double)(53 * (char)a2a) + x;
                v271 = v277;
                goto LABEL_964;
              }
              if ( get_frame() == 7 )
              {
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(30);
                play_sfx(2);
                /*
                *(float *)&v1678 = 0.0;
                v1679 = 16.0;
                v1680 = 0.0;
                v278 = dir;
                v279 = y + 181.0;
                v280 = v279;
                v281 = (double)(53 * (char)v278) + x;
                addbullet(, 801, v281, v280, v278, 1, (int)&v1678, 3);
                */
              }
LABEL_993:
              if ( get_subseq() == 1 && get_elaps_frames() > 15 )
                goto LABEL_1450;
              if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 3 )
              {
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(30);
                play_sfx(2);
                /*
                *(float *)&v1684 = 0.0;
                v1685 = 16.0;
                v1686 = 0.0;
                v283 = dir;
                v284 = y + 181.0;
                v285 = v284;
                v286 = (double)(53 * (char)v283) + x;
                addbullet(, 801, v286, v285, v283, 1, (int)&v1684, 3);
                */
              }
              return;
            case 402:
              sub10func();
              if ( !keyDown(INP_B) )
                not_charge_attack = 0;
              if ( process() )
                set_seq(2);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                set_seq(2);
                return;
              }
              if ( get_subseq() )
                goto LABEL_1018;
              if ( !get_frame_time() && get_frame() == 1 )
              {
                /*
                *(float *)&v1690 = 0.0;
                v1691 = 0.0;
                v1692 = 5.0;
                v287 = dir;
                v288 = get_pframe();
                v289 = y - (double)v288->extra1[5];
                v290 = v289;
                v291 = (double)(v288->extra1[4] * (char)v287) + x;
                addbullet(, 800, v291, v290, v287, 1, (int)&v1690, 3);
                */
              }
              if ( get_frame_time() )
                goto LABEL_1018;
              if ( get_frame() == 4 && not_charge_attack )
              {
                a2a = dir;
                ya = y + 126.0;
                v271 = (double)(33 * (char)a2a) + x;
                goto LABEL_964;
              }
              if ( get_frame() == 6 )
              {
                field_89C = 1;
                sub_486FD0(-70.0, -90.0);
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(30);
              }
LABEL_1018:
              if ( get_subseq() == 1 )
              {
                if ( ++field_7D0 > 15 && !not_charge_attack )
                  goto LABEL_965;
                if ( ++field_7D0 >= 60 )
                  goto LABEL_965;
              }
              if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
              {
                move_vala = -90.0;
                v274 = -70.0;
LABEL_976:
                v275 = v274;
                field_89C = 1;
                sub_486FD0(v275, move_vala);
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(30);
              }
              return;
            case 404:
              if ( get_subseq() == 3 )
                sub10func();
              if ( !keyDown(INP_B) )
                not_charge_attack = 0;
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() && get_subseq() < 3 )
                goto LABEL_1032;
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                goto LABEL_1039;
              if ( get_subseq() )
                goto LABEL_1057;
              if ( !get_frame_time() && get_frame() == 1 )
              {
                /*
                *(float *)&v1696 = 0.0;
                v1697 = 0.0;
                v1698 = 5.0;
                v296 = dir;
                v297 = get_pframe();
                v298 = y - (double)v297->extra1[5];
                v299 = v298;
                v300 = (double)(v297->extra1[4] * (char)v296) + x;
                addbullet(, 800, v300, v299, v296, 1, (int)&v1696, 3);
                */
              }
              if ( get_frame_time() )
                goto LABEL_1054;
              if ( get_frame() == 4 && not_charge_attack )
              {
                a2a = dir;
                ya = y + 185.0;
                v271 = (double)(53 * (char)a2a) + x;
                goto LABEL_964;
              }
              if ( get_frame() == 7 )
              {
                field_89C = 1;
                sub_486FD0(20.0, -20.0);
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(30);
              }
LABEL_1054:
              if ( !get_frame_time() && get_frame() == 14 )
                v_force = 0.5;
LABEL_1057:
              if ( get_subseq() == 1 )
              {
                if ( ++field_7D0 > 15 && !not_charge_attack )
                  goto LABEL_965;
                if ( ++field_7D0 >= 60 )
                  goto LABEL_965;
              }
              if ( get_subseq() != 2 || get_frame_time() )
                return;
              if ( get_frame() != 3 )
                goto LABEL_1066;
              move_valb = -20.0;
              v304 = 20.0;
              goto LABEL_1065;
            case 405:
              if ( get_subseq() == 3 )
                sub10func();
              if ( !keyDown(INP_B) )
                not_charge_attack = 0;
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() && get_subseq() < 3 )
              {
LABEL_1032:
                set_subseq(3);
                air_dash_cnt = 0;
                goto LABEL_162;
              }
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                set_seq(9);
                return;
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
              {
LABEL_1039:
                set_seq(9);
                return;
              }
              if ( get_subseq() )
                goto LABEL_1097;
              if ( get_frame_time() )
                goto LABEL_1094;
              if ( get_frame() == 4 && not_charge_attack )
              {
                a2a = dir;
                ya = y + 181.0;
                v271 = (double)(53 * (char)a2a) + x;
                goto LABEL_964;
              }
              if ( get_frame() == 7 )
              {
                /*
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(30);
                play_sfx(2);
                *(float *)&v1702 = 0.0;
                v1703 = 16.0;
                v1704 = 0.0;
                v310 = dir;
                v311 = y + 148.0;
                v312 = v311;
                v313 = (double)(71 * (char)v310) + x;
                addbullet(, 801, v313, v312, v310, 1, (int)&v1702, 3);
                */
              }
LABEL_1094:
              if ( !get_frame_time() && get_frame() == 14 )
                v_force = 0.5;
LABEL_1097:
              if ( get_subseq() == 1 && get_elaps_frames() > 15 )
                goto LABEL_1450;
              if ( get_subseq() != 2 || get_frame_time() )
                return;
              if ( get_frame() == 3 )
              {
                /*
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(30);
                play_sfx(2);
                *(float *)&v1708 = 0.0;
                v1709 = 16.0;
                v1710 = 0.0;
                v315 = dir;
                v316 = y + 148.0;
                v317 = v316;
                v318 = (double)(71 * (char)v315) + x;
                addbullet(, 801, v318, v317, v315, 1, (int)&v1708, 3);
                */
              }
              goto LABEL_1066;
            case 406:
              if ( get_subseq() == 3 )
                sub10func();
              if ( !keyDown(INP_B) )
                not_charge_attack = 0;
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() && get_subseq() < 3 )
              {
                set_subseq(3);
                air_dash_cnt = 0;
                goto LABEL_162;
              }
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                goto LABEL_1116;
              if ( get_subseq() )
                goto LABEL_1134;
              if ( !get_frame_time() && get_frame() == 1 )
              {
                /*
                *(float *)&v1714 = 0.0;
                v1715 = 0.0;
                v1716 = 5.0;
                v320 = dir;
                v321 = get_pframe();
                v322 = y - (double)v321->extra1[5];
                v323 = v322;
                v324 = (double)(v321->extra1[4] * (char)v320) + x;
                addbullet(, 800, v324, v323, v320, 1, (int)&v1714, 3);
                */
              }
              if ( get_frame_time() )
                goto LABEL_1131;
              if ( get_frame() == 4 && not_charge_attack )
              {
                a2a = dir;
                ya = y + 181.0;
                v271 = (double)(53 * (char)a2a) + x;
                goto LABEL_964;
              }
              if ( get_frame() == 7 )
              {
                field_89C = 1;
                sub_486FD0(70.0, 30.0);
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(30);
              }
LABEL_1131:
              if ( !get_frame_time() && get_frame() == 14 )
                v_force = 0.5;
LABEL_1134:
              if ( get_subseq() == 1 && get_elaps_frames() > 15 )
                goto LABEL_965;
              if ( get_subseq() != 2 || get_frame_time() )
                return;
              if ( get_frame() == 3 )
              {
                move_valb = 30.0;
                v304 = 70.0;
LABEL_1065:
                v305 = v304;
                field_89C = 1;
                sub_486FD0(v305, move_valb);
                spell_energy_spend(200, 45);
                field_190 = 1;
                add_card_energy(30);
              }
              goto LABEL_1066;
            case 408:
              if ( !get_subseq() || get_subseq() == 3 )
              {
                sub10func();
                
              }
              if ( !get_subseq() )
              {
                h_inerc = h_inerc - 0.5;
                if ( h_inerc - 0.5 < 0.0 )
                  h_inerc = 0.0;
              }
              if ( get_subseq() == 1 || get_subseq() == 2 )
              {
                v_inerc = v_inerc - v_force;
                h_inerc = h_inerc + 0.75;
                if ( h_inerc + 0.75 >= -3.0 )
                  h_inerc = -3.0;
                if ( char_on_ground_down() )
                {
                  
                  move_val = 3;
                  goto LABEL_161;
                }
              }
              if ( process() )
                set_seq(0);
              if ( get_subseq() == 1 && !get_frame_time() )
              {
                if ( !get_frame() )
                {
                  h_inerc = -17.5;
                  v_inerc = 6.0;
                  v_force = 0.30000001;
                }
                if ( !get_frame_time() && get_frame() == 1 )
                {
                  play_sfx(10);
                  /*
                  v1720 = 0.0;
                  v1721 = 0.0;
                  v1722 = 1.0;
                  addbullet(, 848, x, y, dir, 1, (int)&v1720, 3);
                  */
                }
              }
              return;
            case 409:
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() )
              {
                set_seq(10);
                goto LABEL_1163;
              }
              if ( process() )
                set_seq(9);
              return;
            case 410:
              sub10func();
              if ( !keyDown(INP_C) )
                not_charge_attack = 0;
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
                goto LABEL_464;
              if ( get_subseq() || get_frame_time() )
                goto LABEL_1182;
              if ( get_frame() == 5 && not_charge_attack )
              {
                a2a = dir;
                ya = y + 120.0;
                v271 = (double)(6 * (char)a2a) + x;
                goto LABEL_964;
              }
              if ( get_frame() == 6 )
              {
                add_card_energy(50);
                spell_energy_spend(200, 60);
                play_sfx(3);
                /*
                *(float *)&v1750 = 0.0;
                v1751 = 5.0;
                v1752 = 0.0;
                v1753 = 0.0;
                v334 = dir;
                v335 = y + 137.0;
                v336 = v335;
                v337 = (double)(26 * (char)v334) + x;
                addbullet(, 802, v337, v336, v334, 1, (int)&v1750, 4);
                */
              }
LABEL_1182:
              if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 4 )
              {
                add_card_energy(50);
                spell_energy_spend(200, 60);
                play_sfx(3);
                /*
                *(float *)&v1770 = 0.0;
                v1771 = 5.0;
                v1772 = 0.0;
                v1773 = 1.0;
                v338 = dir;
                v339 = y + 137.0;
                v340 = v339;
                v341 = (double)(26 * (char)v338) + x;
                addbullet(, 802, v341, v340, v338, 1, (int)&v1770, 4);
                */
              }
              return;
            case 411:
              sub10func();
              if ( !keyDown(INP_C) )
                not_charge_attack = 0;
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                set_seq(0);
                return;
              }
              if ( !get_subseq() && !get_frame_time() && get_frame() == 7 )
              {
                field_190 = 1;
                spell_energy_spend(200, 60);
                add_card_energy(50);
                play_sfx(4);
                /*
                *(float *)&v1726 = 0.0;
                v1727 = 0.0;
                v1728 = 1.0;
                v342 = dir;
                v343 = y + 136.0;
                v344 = v343;
                v345 = (double)(137 * (char)v342) + x;
                addbullet(, 803, v345, v344, v342, 1, (int)&v1726, 3);
                */
              }
              if ( get_subseq() == 1 && get_elaps_frames() > 15 )
                goto LABEL_1450;
              if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
              {
                field_190 = 1;
                spell_energy_spend(200, 60);
                add_card_energy(50);
                play_sfx(4);
                /*
                *(float *)&v1501 = 0.0;
                v1502 = 0.0;
                v1503 = 1.0;
                v347 = dir;
                v348 = y + 136.0;
                v349 = v348;
                v350 = (double)(137 * (char)v347) + x;
                addbullet(, 803, v350, v349, v347, 1, (int)&v1501, 3);
                */
              }
              return;
            case 412:
              sub10func();
              if ( !keyDown(INP_C) )
                not_charge_attack = 0;
              if ( process() )
                set_seq(2);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                set_seq(2);
                return;
              }
              if ( get_subseq() || get_frame_time() )
                goto LABEL_1221;
              if ( get_frame() == 5 && not_charge_attack )
              {
                a2a = dir;
                ya = y + 256.0;
                v271 = x;
                goto LABEL_964;
              }
              if ( get_frame() == 7 )
              {
                field_190 = 1;
                spell_energy_spend(200, 60);
                add_card_energy(50);
                play_sfx(4);
                /*
                v1745 = 0.0;
                v1746 = 1.0;
                v352 = dir;
                v353 = y + 161.0;
                v354 = v353;
                v355 = (double)(106 * (char)v352) + x;
                addbullet(, 803, v355, v354, v352, 1, (int)-30.0, 3);
                */
              }
LABEL_1221:
              if ( get_subseq() == 1 && get_elaps_frames() > 15 )
                goto LABEL_1450;
              if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
              {
                field_190 = 1;
                spell_energy_spend(200, 60);
                add_card_energy(50);
                play_sfx(4);
                /*
                *(float *)&v1507 = -30.0;
                v1508 = 0.0;
                v1509 = 1.0;
                v357 = dir;
                v358 = y + 161.0;
                v359 = v358;
                v360 = (double)(106 * (char)v357) + x;
                addbullet(, 803, v360, v359, v357, 1, (int)&v1507, 3);
                */
              }
              return;
            case 414:
              if ( get_subseq() == 2 )
                sub10func();
              v_inerc = v_inerc - v_force;
              if ( char_on_ground_down() && get_subseq() < 2 )
              {
                set_subseq(2);
                air_dash_cnt = 0;
                goto LABEL_162;
              }
              if ( !keyDown(INP_C) )
                not_charge_attack = 0;
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 1 || !get_frame_time() && !get_frame() && get_subseq() == 2) )
                goto LABEL_1116;
              if ( get_subseq() )
                goto LABEL_1253;
              if ( get_frame_time() )
                goto LABEL_1250;
              if ( get_frame() == 5 && not_charge_attack )
              {
                a2a = dir;
                ya = y + 128.0;
                v271 = (double)(4 * (char)a2a) + x;
LABEL_964:
                scene_add_effect(this, 62, v271, ya, a2a, 1);
                goto LABEL_965;
              }
              if ( get_frame() == 6 )
              {
                /*
                add_card_energy(50);
                spell_energy_spend(200, 60);
                play_sfx(3);
                *(float *)&v1762 = 0.0;
                v1763 = 5.0;
                v1764 = 0.0;
                v1765 = 0.0;
                v363 = dir;
                v364 = y + 150.0;
                v365 = v364;
                v366 = (double)(30 * (char)v363) + x;
                addbullet(, 802, v366, v365, v363, 1, (int)&v1762, 4);
                */
              }
LABEL_1250:
              if ( !get_frame_time() && get_frame() == 14 )
                v_force = 0.5;
LABEL_1253:
              if ( get_subseq() == 1 && !get_frame_time() )
              {
                if ( get_frame() == 4 )
                {
                  add_card_energy(50);
                  spell_energy_spend(200, 60);
                  play_sfx(3);
                  /*
                  *(float *)&v1754 = 0.0;
                  v1755 = 5.0;
                  v1756 = 0.0;
                  v1757 = 1.0;
                  v367 = dir;
                  v368 = y + 150.0;
                  v369 = v368;
                  v370 = (double)(30 * (char)v367) + x;
                  addbullet(, 802, v370, v369, v367, 1, (int)&v1754, 4);
                  */
                }
                if ( !get_frame_time() )
                {
                  v306 = get_frame() == 12;
                  goto LABEL_1068;
                }
              }
              return;
            case 415:
              if ( get_subseq() == 3 )
                sub10func();
              v_inerc = v_inerc - v_force;
              if ( get_subseq() < 3 && char_on_ground_down() )
                goto LABEL_1263;
              if ( !keyDown(INP_C) )
                not_charge_attack = 0;
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                set_seq(9);
                return;
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                goto LABEL_1116;
              if ( !get_subseq() && !get_frame_time() )
              {
                if ( get_frame() == 7 )
                {
                  field_190 = 1;
                  spell_energy_spend(200, 60);
                  add_card_energy(50);
                  play_sfx(4);
                  /*
                  *(float *)&v1639 = 0.0;
                  v1640 = 0.0;
                  v1641 = 1.0;
                  v372 = dir;
                  v373 = y + 149.0;
                  v374 = v373;
                  v375 = (double)(137 * (char)v372) + x;
                  addbullet(, 803, v375, v374, v372, 1, (int)&v1639, 3);
                  */
                }
                if ( !get_frame_time() && get_frame() == 18 )
                  v_force = 0.5;
              }
              if ( get_subseq() == 1 && get_elaps_frames() > 15 )
                goto LABEL_1450;
              if ( get_subseq() != 2 || get_frame_time() )
                return;
              if ( get_frame() != 2 )
                goto LABEL_1291;
              field_190 = 1;
              spell_energy_spend(200, 60);
              add_card_energy(50);
              play_sfx(4);
              /*
              *(float *)&v1513 = 0.0;
              v1514 = 0.0;
              a2b = &v1513;
              v1515 = 1.0;
              a1 = dir;
              v377 = y + 149.0;
              a4 = v377;
              v378 = (double)(137 * dir) + x;
              v379 = v378;
              */
              //goto LABEL_1290;
              return; // TODO: change!
            case 416:
              if ( get_subseq() == 3 )
                sub10func();
              v_inerc = v_inerc - v_force;
              if ( get_subseq() < 3 && char_on_ground_down() )
              {
LABEL_1263:
                set_subseq(3);
                air_dash_cnt = 0;
                goto LABEL_162;
              }
              if ( !keyDown(INP_C) )
                not_charge_attack = 0;
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                set_seq(9);
                return;
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                goto LABEL_1116;
              if ( !get_subseq() && !get_frame_time() )
              {
                if ( get_frame() == 7 )
                {
                  field_190 = 1;
                  spell_energy_spend(200, 60);
                  add_card_energy(50);
                  play_sfx(4);
                  /*
                  *(float *)&v1705 = 45.0;
                  v1706 = 0.0;
                  v1707 = 1.0;
                  v382 = dir;
                  v383 = y + 43.0;
                  v384 = v383;
                  v385 = (double)(65 * (char)v382) + x;
                  addbullet(, 803, v385, v384, v382, 1, (int)&v1705, 3);
                  */
                }
                if ( !get_frame_time() && get_frame() == 18 )
                  v_force = 0.5;
              }
              if ( get_subseq() == 1 && get_elaps_frames() > 15 )
                goto LABEL_1450;
              if ( get_subseq() == 2 && !get_frame_time() )
              {
                if ( get_frame() == 2 )
                {
                  field_190 = 1;
                  spell_energy_spend(200, 60);
                  add_card_energy(50);
                  play_sfx(4);
                  /*
                  v1519 = 45.0;
                  v1520 = 0.0;
                  a2b = (int *)&v1519;
                  v1521 = 1.0;
                  a1 = dir;
                  v387 = y + 43.0;
                  a4 = v387;
                  v388 = (double)(65 * (char)a1) + x;
                  v379 = v388;
LABEL_1290:
                  a3 = v379;
                  addbullet(, 803, a3, a4, a1, 1, (int)a2b, 3);
                  */
                }
LABEL_1291:
                if ( !get_frame_time() )
                {
                  v306 = get_frame() == 13;
                  goto LABEL_1068;
                }
              }
              return;
            case 418:
              if ( !get_subseq() || get_subseq() == 3 )
              {
                sub10func();
                
              }
              if ( !get_subseq() )
              {
                h_inerc = h_inerc - 0.75;
                if ( h_inerc - 0.75 < 0.0 )
                  h_inerc = 0.0;
              }
              if ( get_subseq() == 1 || get_subseq() == 2 )
              {
                v_inerc = v_inerc - v_force;
                if ( char_on_ground_down() )
                {
                  set_subseq(3);
                  goto LABEL_162;
                }
              }
              if ( process() )
                set_seq(0);
              if ( get_subseq() == 1 && !get_frame_time() )
              {
                if ( !get_frame() )
                {
                  scene_play_sfx(29);
                  h_inerc = 12.5;
                  v_inerc = 15.0;
                  v_force = 0.5;
                }
                if ( !get_frame_time() && get_frame() == 6 )
                {
                  scene_play_sfx(29);
                  field_190 = 0;
                  field_194 = 1;
                }
              }
              break;
            default:
                char_c::func10();
                return;
          }
        }
        return;
      }
      switch (sq)
      {
        case 501:
          sub10func();
          field_18C = 0;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            field_190 = 1;
          if ( process() )
            set_seq(0);
          if ( get_subseq() || get_frame_time() )
            goto LABEL_1365;
          if ( get_frame() == 5 )
          {
            /*
            v409 = ;
            v1326 = 180.0;
            if ( skills_1[0] >= 2 )
              v1326 = 230.0;
            if ( skills_1[0] >= 4 )
              v1326 = 280.0;
            *(float *)&v1406 = 0.0;
            v1407 = v1326;
            v1408 = 0.0;
            if ( skills_1[0] >= 3 )
              v1408 = 5.0;
            v1409 = 240.0;
            v410 = dir;
            v411 = y + 100.0;
            v412 = v411;
            v413 = v1326 * (double)(char)v410 + x;
            addbullet(, 810, v413, v412, v410, 1, (int)&v1406, 4);
            *(float *)&v1406 = 180.0;
            v1407 = v1326;
            v414 = dir;
            v415 = y + 100.0;
            v416 = v415;
            v417 = x - v1326 * (double)(char)v414;
            addbullet(, 810, v417, v416, v414, 1, (int)&v1406, 4);
            v1408 = 3.0;
            v418 = dir;
            v419 = getlvl_height();
            addbullet(, 810, x, v419, v418, -1, (int)&v1406, 4);
            */
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(20);
          }
          if ( get_frame_time() || get_frame() != 7 || skills_1[0] < 3 )
            goto LABEL_1365;
          /*
          v1525 = 0.0;
          v1526 = 0.0;
          a2c = (int *)&v1525;
          v1527 = 6.0;
          a1a = dir;
          v420 = y + 140.0;
          a4a = v420;
          v421 = (double)(7 * (char)a1a) + x;
          v406 = v421;
          */
          //goto LABEL_1364;
          return; //TODO: change!
        case 505:
          field_18C = 4;
          if ( get_subseq() >= 2 || get_subseq() <= 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1396;
          }
          if ( get_subseq() == 1 )
          {
            h_inerc = h_inerc + 1.5;
            if ( field_190 )
              field_7D2 = 1;
            if ( dir * get_border_near() < 0 )
            {
              field_190 = 0;
              field_51C = 2;
              field_520 = 2;
              if ( x > 2080.0 || x < -800.0 )
              {
                h_inerc = -17.5;
                v_inerc = 2.0;
                next_subseq();
                field_7D0 = 0;
              }
              return;
            }
          }

          if ( get_subseq() == 2 )
          {
            if ( dir * get_border_near() >= 0 )
            {
              field_571 = 1;

              h_inerc = h_inerc * 0.949999988079071;
              v_inerc = v_inerc * 0.949999988079071;
              if ( ++field_7D0 >= 10 )
                goto LABEL_2592;
              if ( field_7D2 )
                field_190 = 1;
            }
            else
            {

              field_190 = 0;
              field_51C = 2;
              field_520 = 2;
              field_571 = 0;
            }
          }
          if ( get_subseq() == 3 && get_frame() <= 3 )
          {
            h_inerc *= 0.949999988079071;
            v_inerc *= 0.949999988079071;
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 1 )
            {
              /*
              *(float *)&v1738 = 0.0;
              v1739 = 0.0;
              v1740 = 2.0;
              v425 = y + 120.0;
              addbullet(, 811, x, v425, dir, 1, (int)&v1738, 3);
              */
            }
            if ( !get_frame_time() && get_frame() == 3 )
            {
              field_571 = 0;
              h_inerc = 3.0;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(26);
            }
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            /*
            *(float *)&v1388 = 90.0;
            v1389 = 0.0;
            v1390 = 1.0;
            v426 = y + 100.0;
            addbullet(, 811, x, v426, dir, 1, (int)&v1388, 3);
            *(float *)&v1388 = -90.0;
            v1389 = 0.0;
            v1390 = 1.0;
            v427 = y + 100.0;
            addbullet(, 811, x, v427, dir, 1, (int)&v1388, 3);
            *(float *)&v1388 = 0.0;
            v1389 = 0.0;
            v1390 = 0.0;
            a2d = &v1388;
            a1b = dir;
            v428 = y + 100.0;
            v429 = v428;
            */
            //goto LABEL_1427;
            return; //TODO: change!
          }
          goto LABEL_1428;
        case 506:
          field_18C = 4;
          if ( get_subseq() >= 2 || get_subseq() <= 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1436;
          }
          if ( get_subseq() != 1 )
            goto LABEL_3215;
          h_inerc = h_inerc + 3.0;
          if ( field_190 )
            field_7D2 = 1;
          if ( dir * get_border_near() >= 0 )
          {
LABEL_3215:

            if ( get_subseq() == 2 )
            {
              if ( dir * get_border_near() >= 0 )
              {
                field_571 = 1;

                h_inerc = h_inerc * 0.949999988079071;
                v_inerc = v_inerc * 0.949999988079071;
                if ( ++field_7D0 >= 10 )
                  goto LABEL_1450;
                if ( field_7D2 )
                  field_190 = 1;
              }
              else
              {

                field_190 = 0;
                field_51C = 2;
                field_520 = 2;
              }
            }
            if ( get_subseq() == 3 && get_frame() <= 3 )
            {
              h_inerc *= 0.949999988079071;
              v_inerc *= 0.949999988079071;
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                /*
                *(float *)&v1531 = 0.0;
                v1532 = 0.0;
                v1533 = 2.0;
                v436 = y + 120.0;
                addbullet(, 811, x, v436, dir, 1, (int)&v1531, 3);
                */
              }
              if ( !get_frame_time() && get_frame() == 3 )
              {
                field_571 = 0;
                h_inerc = 3.0;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                play_sfx(26);
              }
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              /*
              *(float *)&v1391 = 90.0;
              v1392 = 0.0;
              v1393 = 1.0;
              v437 = y + 100.0;
              addbullet(, 811, x, v437, dir, 1, (int)&v1391, 3);
              *(float *)&v1391 = -90.0;
              v1392 = 0.0;
              v1393 = 1.0;
              v438 = y + 100.0;
              addbullet(, 811, x, v438, dir, 1, (int)&v1391, 3);
              *(float *)&v1391 = 0.0;
              v1392 = 0.0;
              v1393 = 0.0;
              a2d = &v1391;
              a1b = dir;
              v439 = y + 100.0;
              v429 = v439;
LABEL_1427:
              v430 = v429;
              addbullet(, 811, x, v430, a1b, 1, (int)a2d, 3);
              */
            }
LABEL_1428:
            if ( get_subseq() == 3 )
            {
              v431 = get_frame_time() == 0;
              goto LABEL_1430;
            }
          }
          else
          {
            field_190 = 0;
            field_51C = 2;
            field_520 = 2;
            if ( x > 2080.0 || x < -800.0 )
            {
              h_inerc = -17.5;
              v_inerc = 2.0;
              next_subseq();
              field_7D0 = 0;
              if ( y < 160.0 )
                y = 160.0;
            }
          }
          return;
        case 507:
          field_18C = 4;
          if ( get_subseq() >= 2 || get_subseq() <= 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1396;
          }
          if ( get_subseq() == 1 )
          {
            h_inerc = h_inerc + 1.5;
            if ( dir * get_border_near() < 0 )
            {
              field_190 = 0;
              ++field_7D0;
              field_51C = 2;
              field_520 = 2;
              if ( field_7D0 >= 30 )
              {
                h_inerc = -12.5;
                v_inerc = 2.0;
                v_force = 0.5;
                next_subseq();
                field_7D0 = 0;
              }
              return;
            }
          }
          if ( get_subseq() == 2 )
          {
            if ( dir * get_border_near() >= 0 )
            {
              field_571 = 1;
              h_inerc = h_inerc * 0.9800000190734863;
              scaleY = scaleY * 0.9800000190734863;
              if ( ++field_7D0 >= 10 )
                goto LABEL_2592;
            }
            else
            {
              field_190 = 0;
              field_51C = 2;
              field_520 = 2;
            }
          }
          if ( get_subseq() == 3 && get_frame() <= 3 )
          {
            h_inerc *= 0.9800000190734863;
            scaleY *= 0.9800000190734863;
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 1 )
            {
              /*
              *(float *)&v1651 = 0.0;
              v1652 = 0.0;
              v1653 = 2.0;
              v443 = y + 120.0;
              addbullet(, 811, x, v443, dir, 1, (int)&v1651, 3);
              */
            }
            if ( !get_frame_time() && get_frame() == 3 )
            {
              field_571 = 0;
              h_inerc = 3.0;
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(26);
            }
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            /*
            *(float *)&v1400 = 90.0;
            v1401 = 0.0;
            v1402 = 1.0;
            v444 = y + 100.0;
            addbullet(, 811, x, v444, dir, 1, (int)&v1400, 3);
            *(float *)&v1400 = -90.0;
            v1401 = 0.0;
            v1402 = 1.0;
            v445 = y + 100.0;
            addbullet(, 811, x, v445, dir, 1, (int)&v1400, 3);
            *(float *)&v1400 = 0.0;
            v1401 = 0.0;
            v1402 = 0.0;
            a2e = &v1400;
            a1c = dir;
            v446 = y + 100.0;
            v447 = v446;
            */
            //goto LABEL_1498;
            return; //TODO: change!
          }
          goto LABEL_1499;
        case 508:
          field_18C = 4;
          if ( get_subseq() >= 2 ||get_subseq() <= 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1436;
          }
          if ( get_subseq() != 1 || (h_inerc = h_inerc + 1.5, dir * get_border_near() >= 0) )
          {

            if ( get_subseq() == 2 )
            {
              if ( dir * get_border_near() >= 0 )
              {
                field_571 = 1;

                h_inerc = h_inerc * 0.9800000190734863;
                scaleY = scaleY * 0.9800000190734863;
                if ( ++field_7D0 >= 10 )
                  goto LABEL_1450;
              }
              else
              {

                field_190 = 0;
                field_51C = 2;
                field_520 = 2;
              }
            }
            if ( get_subseq() == 3 && get_frame() <= 3 )
            {
              h_inerc *= 0.9800000190734863;
              scaleY *= 0.9800000190734863;
            }
            if ( process() )
              set_seq(0);
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                /*
                *(float *)&v1537 = 0.0;
                v1538 = 0.0;
                v1539 = 2.0;
                v452 = y + 120.0;
                addbullet(, 811, x, v452, dir, 1, (int)&v1537, 3);
                */
              }
              if ( !get_frame_time() && get_frame() == 3 )
              {
                field_571 = 0;
                h_inerc = 3.0;
                spell_energy_spend(200, 120);
                add_card_energy(50);
                play_sfx(26);
              }
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              /*
              *(float *)&v1394 = 90.0;
              v1395 = 0.0;
              v1396 = 1.0;
              v453 = y + 100.0;
              addbullet(, 811, x, v453, dir, 1, (int)&v1394, 3);
              *(float *)&v1394 = -90.0;
              v1395 = 0.0;
              v1396 = 1.0;
              v454 = y + 100.0;
              addbullet(, 811, x, v454, dir, 1, (int)&v1394, 3);
              *(float *)&v1394 = 0.0;
              v1395 = 0.0;
              v1396 = 0.0;
              a2e = &v1394;
              a1c = dir;
              v455 = y + 100.0;
              v447 = v455;
LABEL_1498:
              v448 = v447;
              addbullet(, 811, x, v448, a1c, 1, (int)a2e, 3);
              */
            }
LABEL_1499:
            if ( get_subseq() == 3 )
            {
              v431 = get_frame_time() == 0;
LABEL_1430:
              if ( v431 && get_frame() == 4 )
              {
                flip_with_force();
                v_force = 0.5;
              }
            }
          }
          else
          {
            field_190 = 0;
            ++field_7D0;
            field_51C = 2;
            field_520 = 2;
            if ( field_7D0 >= 30 )
            {
              h_inerc = -12.5;
              v_inerc = 2.0;
              v_force = 0.5;
              next_subseq();
              field_7D0 = 0;
            }
          }
          return;
        case 510:
          field_18C = 8;
          if ( get_subseq() )
            goto LABEL_1538;
          sub10func();
          
          if ( get_subseq() )
            goto LABEL_1538;
          if ( getlvl_height() < enemy->y )
            field_194 = 0;
          else
            //field_194 = sub_4634E0(enemy, 1) != 0;
          if ( field_190 == 1 || field_190 == 7 )
          {
            next_subseq();
            set_seq(get_pframe()->extra1[4]);
            reset_forces();
            enemy->field_571 = 0;
            enemy->field_572 = 0;
            enemy->dir = -dir;
            return;
          }
          
LABEL_1538:
          if ( 0.0 < h_inerc )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc - 0.5 < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() )
          {
            if ( !get_frame() )
            {
              if ( (skills_1[8] >= 4) && get_frame_time() >= 4 || skills_1[8] >= 3 && get_frame_time() >= 6 || skills_1[8] >= 2 && get_frame_time() >= 8 )
                next_frame();
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 1 )
              {
                /*
                *(float *)&v1711 = 0.0;
                v1712 = 0.0;
                v1713 = 0.0;
                v461 = dir;
                v462 = get_pframe();
                v463 = (double)v462->extra1[1] + y;
                v464 = v463;
                v465 = (double)(v462->extra1[0] * (char)v461) + x;
                addbullet(, 812, v465, v464, v461, 1, (int)&v1711, 3);
                */
                h_inerc = 15.0;
                play_sfx(30);
              }
              if ( !get_frame_time() && get_frame() == 7 )
              {
                h_inerc = 0.0;
                scene_add_effect(this, 58, x, y, dir, -1);
                //shake_camera(4.0);
                scene_play_sfx(22);
              }
            }
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
          {
            if ( get_subseq() == 1 )
            {
              if ( !get_frame_time() )
              {
                set_seq(get_pframe()->extra1[4]);
                if ( !get_frame_time() && get_frame() == 3 )
                {
                  scene_add_effect(this, 58, (double)(get_pframe()->extra1[4] * (char)dir) + x, y, dir, -1);
                  scene_add_effect(this, 4, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
                  //shake_camera(8.0);
                  h_inerc = 0.0;
                  scene_play_sfx(4);
                }
              }
              enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
              enemy->y = y;
            }
          }
          else if ( get_subseq() == 1 )
          {
            set_seq(199);
            return;
          }
          if ( get_subseq() == 2 )
          {
            enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
            enemy->y = y;
            if ( get_elaps_frames() >= 30 )
              goto LABEL_1450;
          }
          if ( get_subseq() == 3 )
          {
            if ( get_elaps_frames() <= 60 )
            {
              if ( !(get_elaps_frames() % 5) )
              {
                scene_add_effect(this, 58, (double)(get_pframe()->extra1[4] * (char)dir) + x, y, dir, -1);
                scene_add_effect(this, 3, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
                //shake_camera(4.0);
                scene_play_sfx(3);
                set_seq(get_pframe()->extra1[4]);
                if ( weather_id == 4 && !field_526 )
                  sub_464110(((double)(char)skills_1[8] * 0.1000000014901161 + 1.0) * 62.5, 990, 1, 1);
                else
                  sub_464110(((double)(char)skills_1[8] * 0.1000000014901161 + 1.0) * 50.0, 990, 1, 1);
              }
              if ( !(get_elaps_frames() % 10) )
                play_sfx(31);
            }
            enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
            enemy->y = y;
            if ( get_elaps_frames() >= 90 )
              goto LABEL_1450;
          }
          if ( get_subseq() == 4 )
          {
            if ( !get_frame_time() && get_frame() == 2 )
            {
              scene_add_effect(this, 4, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
              //shake_camera(10.0);
              scene_play_sfx(4);
              enemy->field_4BA = 6000;
              if ( weather_id == 4 && !field_526 )
                sub_464110(((double)(char)skills_1[8] * 0.1000000014901161 + 1.0) * 1562.5, 800, 1, 1);
              else
                sub_464110(((double)(char)skills_1[8] * 0.1000000014901161 + 1.0) * 1250.0, 800, 1, 1);
              enemy->dir = -dir;
              enemy->field_1A4 = 24.5;
              enemy->field_1A8 = 12.5;
              enemy->damage_limit = 100;
              set_seq(get_pframe()->extra1[4]);
              play_sfx(32);
              //shake_camera(10.0);
              enemy->field_571 = 1;
              enemy->field_572 = 1;
            }
            if ( get_frame() <= 1 )
            {
              enemy->x = (double)(get_pframe()->extra1[4] * dir) + x;
              enemy->y = y;
            }
          }
          return;
        case 520:
          sub10func();
          field_18C = 1;
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            field_190 = 1;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            field_190 = 1;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
          {
LABEL_117:
            set_seq(0);
            return;
          }
          if ( !get_subseq() && !get_frame_time() && get_frame() == 5 && not_charge_attack )
          {
            /*
            a2f = dir;
            v495 = y + 300.0;
            yb = v495;
            v496 = x - (double)(6 * (char)a2f);
            v497 = v496;
            goto LABEL_1613;
            */
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(40);
            /*
            *(float *)&v1543 = 80.0;
            v1544 = 0.0;
            v1545 = 5.0;
            v499 = dir;
            v500 = y + 136.0;
            v501 = v500;
            v502 = (double)(137 * (char)v499) + x;
            addbullet(, 815, v502, v501, v499, 1, (int)&v1543, 3);
            */
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
          {
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(40);
            /*
            *(float *)&v1657 = 80.0;
            v1658 = 0.0;
            v1659 = 5.0;
            v503 = dir;
            v504 = y + 136.0;
            v505 = v504;
            v506 = (double)(137 * (char)v503) + x;
            addbullet(, 815, v506, v505, v503, 1, (int)&v1657, 3);
            */
          }
          return;
        case 521:
          sub10func();
          field_18C = 1;
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            field_190 = 1;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            field_190 = 1;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
            goto LABEL_464;
          if ( get_subseq() || get_frame_time() || get_frame() != 5 || !not_charge_attack )
          {
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(40);
              /*
              *(float *)&v1549 = 80.0;
              v1550 = 0.0;
              v1551 = 5.0;
              v511 = dir;
              v512 = y + 136.0;
              v513 = v512;
              v514 = (double)(137 * (char)v511) + x;
              addbullet(, 815, v514, v513, v511, 1, (int)&v1549, 3);
              */
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(40);
              /*
              *(float *)&v1732 = 80.0;
              v1733 = 0.0;
              v1734 = 5.0;
              v515 = dir;
              v516 = y + 136.0;
              v517 = v516;
              v518 = (double)(137 * (char)v515) + x;
              addbullet(, 815, v518, v517, v515, 1, (int)&v1732, 3);
              */
            }
          }
          else
          {
            /*
            a2f = dir;
            v509 = y + 300.0;
            yb = v509;
            v510 = x - (double)(6 * (char)a2f);
            v497 = v510;
LABEL_1613:
            v498 = v497;
            scene_add_effect(this, 62, v498, yb, a2f, 1);
            */
            set_subseq(4);
          }
          return;
        case 522:
          if ( get_subseq() == 9 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1667;
          }
          field_18C = 1;
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            field_190 = 1;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            field_190 = 1;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && (!get_frame_time() && !get_frame() && get_subseq() == 4 || !get_frame_time() && !get_frame() && get_subseq() == 9) )
            goto LABEL_1116;
          if ( get_subseq() || get_frame_time() || get_frame() != 5 || !not_charge_attack )
          {
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(40);
              /*
              *(float *)&v1555 = 80.0;
              v1556 = 0.0;
              v1557 = 5.0;
              v525 = dir;
              v526 = y + 146.0;
              v527 = v526;
              v528 = (double)(137 * (char)v525) + x;
              addbullet(, 815, v528, v527, v525, 1, (int)&v1555, 3);
              */
            }
            if ( (get_subseq() == 3 || get_subseq() == 8) && !get_frame_time() && get_frame() == 4 )
              v_force = 0.5;
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(40);
              /*
              *(float *)&v1495 = 80.0;
              v1496 = 0.0;
              v1497 = 5.0;
              v530 = dir;
              v531 = y + 146.0;
              v532 = v531;
              v533 = (double)(137 * (char)v530) + x;
              addbullet(, 815, v533, v532, v530, 1, (int)&v1495, 3);
              */
            }
          }
          else
          {
            scene_add_effect(this, 62, x - (double)(6 * (char)dir), y + 310.0, dir, 1);
            set_subseq(4);
          }
          return;
        case 523:
          if ( get_subseq() == 9 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_1667:
              set_subseq(9);
LABEL_162:
              y = getlvl_height();
              reset_forces();
              return;
            }
          }
          field_18C = 1;
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            field_190 = 1;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
            field_190 = 1;
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() || (get_frame_time() || get_frame() || get_subseq() != 4) && (get_frame_time() || get_frame() || get_subseq() != 9) )
          {
            if ( get_subseq() || get_frame_time() || get_frame() != 5 || !not_charge_attack )
            {
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                spell_energy_spend(200, 120);
                add_card_energy(50);
                play_sfx(40);
                /*
                *(float *)&v1561 = 80.0;
                v1562 = 0.0;
                v1563 = 5.0;
                v540 = dir;
                v541 = y + 146.0;
                v542 = v541;
                v543 = (double)(137 * (char)v540) + x;
                addbullet(, 815, v543, v542, v540, 1, (int)&v1561, 3);
                */
              }
              if ( (get_subseq() == 3 || get_subseq() == 8) && !get_frame_time() && get_frame() == 4 )
                v_force = 0.5;
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 5 )
              {
                spell_energy_spend(200, 120);
                add_card_energy(50);
                play_sfx(40);
                /*
                *(float *)&v1717 = 80.0;
                v1718 = 0.0;
                v1719 = 5.0;
                v545 = dir;
                v546 = y + 146.0;
                v547 = v546;
                v548 = (double)(137 * (char)v545) + x;
                addbullet(, 815, v548, v547, v545, 1, (int)&v1717, 3);
                */
              }
            }
            else
            {
              scene_add_effect(this, 62, x - (double)(6 * (char)dir), y + 310.0, dir, 1);
              set_subseq(4);
            }
            return;
          }
          goto LABEL_1116;
        case 525:
          sub10func();
          field_18C = 5;
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          {
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                x = 0.0;
                /*
                v1568 = 0.0;
                v1569 = 9.0;
                v549 = dir;
                v550 = (double)(125 * dir) + x;
                v551 = get_level_height__by_x(v550);
                v552 = (double)(125 * dir) + x;
                addbullet(, 816, v552, v551, v549, 1, (int)&x, 3);
                */
                play_sfx(41);
                //shake_camera(5.0);
              }
              if ( !get_frame_time() && get_frame() == 7 )
              {
                /*
                *(float *)&v1449 = 45.0;
                v1450 = 0.0;
                v1451 = 0.0;
                v553 = dir;
                v554 = (double)(125 * dir) + x;
                v555 = get_level_height__by_x(v554);
                v556 = (double)(125 * dir) + x;
                addbullet(, 816, v556, v555, v553, 1, (int)&v1449, 3);
                *(float *)&v1449 = 0.0;
                v1451 = 6.0;
                addbullet(, 816, x, y, dir, -1, (int)&v1449, 3);
                */
                spell_energy_spend(200, 120);
                add_card_energy(50);
                field_190 = 1;
              }
            }
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 5 )
            {
              /*
              *(float *)&v1455 = 45.0;
              v1456 = 0.0;
              v1457 = 0.0;
              v557 = dir;
              v558 = (double)(125 * dir) + x;
              v559 = get_level_height__by_x(v558);
              v560 = (double)(125 * dir) + x;
              addbullet(, 816, v560, v559, v557, 1, (int)&v1455, 3);
              *(float *)&v1455 = 0.0;
              v1457 = 6.0;
              addbullet(, 816, x, y, dir, -1, (int)&v1455, 3);
              */
              play_sfx(41);
              //shake_camera(5.0);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              field_190 = 1;
            }
          }
          else
          {
            set_seq(0);
          }
          return;
        case 526:
          sub10func();
          field_18C = 5;
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
          {
            if ( !get_subseq() && !get_frame_time() )
            {
              if ( get_frame() == 4 )
              {
                /*
                *(float *)&v1669 = 0.0;
                v1670 = 0.0;
                v1671 = 9.0;
                v561 = dir;
                v562 = (double)(500 * dir) + x;
                v563 = get_level_height__by_x(v562);
                v564 = (double)(500 * dir) + x;
                addbullet(, 816, v564, v563, v561, 1, (int)&v1669, 3);
                */
                play_sfx(41);
                //shake_camera(5.0);
              }
              if ( !get_frame_time() && get_frame() == 7 )
              {
                /*
                *(float *)&v1446 = -45.0;
                v1447 = 0.0;
                v1448 = 3.0;
                v565 = dir;
                v566 = (double)(500 * dir) + x;
                v567 = get_level_height__by_x(v566);
                v568 = (double)(500 * dir) + x;
                addbullet(, 816, v568, v567, v565, 1, (int)&v1446, 3);
                *(float *)&v1446 = 0.0;
                v1448 = 6.0;
                addbullet(, 816, x, y, dir, -1, (int)&v1446, 3);
                */
                spell_energy_spend(200, 120);
                add_card_energy(50);
                field_190 = 1;
              }
            }
            if ( get_subseq() == 1 && !get_frame_time() && get_frame() == 5 )
            {
              /*
              *(float *)&v1452 = -45.0;
              v1453 = 0.0;
              v1454 = 3.0;
              v569 = dir;
              v570 = (double)(500 * dir) + x;
              v571 = get_level_height__by_x(v570);
              v572 = (double)(500 * dir) + x;
              addbullet(, 816, v572, v571, v569, 1, (int)&v1452, 3);
              *(float *)&v1452 = 0.0;
              v1454 = 6.0;
              addbullet(, 816, x, y, dir, -1, (int)&v1452, 3);
              */
              play_sfx(41);
              //shake_camera(5.0);
              spell_energy_spend(200, 120);
              add_card_energy(50);
              field_190 = 1;
            }
          }
          else
          {
            set_seq(0);
          }
          return;
        case 530:
          sub10func();
          field_18C = 9;
          if ( get_subseq() == 1 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc - 0.5 < 7.0 )
              h_inerc = 7.0;
            if ( get_elaps_frames() >= 4 )
            {
              if ( fabs(x - enemy->x) < 200.0 && (enemy->x < (double)x && dir == -1 || enemy->x > (double)x && dir == 1) )
                goto LABEL_1450;
              if ( get_elaps_frames() >= 12 )
                goto LABEL_1450;
            }
          }
          if ( get_subseq() == 2 && get_frame() <= 1 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc - 0.5 < 7.0 )
              h_inerc = 7.0;
          }
          if ( get_subseq() != 3 )
            goto LABEL_1800;
          h_inerc = h_inerc + 0.75;
          if ( h_inerc + 0.75 > -2.0 )
            goto LABEL_1450;
          if ( get_elaps_frames() == 8 )
            field_190 = 1;
LABEL_1800:
          if ( get_subseq() == 4 )
          {
            h_inerc = h_inerc + 0.4000000059604645;
            if ( h_inerc + 0.4000000059604645 > 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
          {
            play_sfx(42);
            h_inerc = 15.0;
            spell_energy_spend(200, 120);
            add_card_energy(50);
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            /*
            *(float *)&v1573 = 0.0;
            v1574 = 0.0;
            v1575 = 0.0;
            addbullet(, 817, x, y, dir, 1, (int)&v1573, 3);
            */
          }
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
          {
            /*
            *(float *)&v1470 = 0.0;
            v1471 = 15.0;
            v1472 = 4.0;
            if ( skills_1[9] >= 3 )
              v1472 = 5.0;
            if ( skills_1[9] >= 4 )
              v1472 = 6.0;
            v580 = dir;
            v581 = get_pframe();
            v582 = y - (double)v581->extra1[5];
            v583 = v582;
            v584 = (double)(v581->extra1[4] * (char)v580) + x;
            addbullet(, 817, v584, v583, v580, 1, (int)&v1470, 3);
            */
            play_sfx(43);
            h_inerc = -15.0;
          }
          return;
        case 531:
          sub10func();
          field_18C = 9;
          if ( get_subseq() == 1 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc - 0.5 < 7.0 )
              h_inerc = 7.0;
            if ( get_elaps_frames() >= 4 )
            {
              if ( fabs(x - enemy->x) < 200.0 && (enemy->x < (double)x && dir == -1 || enemy->x > (double)x && dir == 1) )
                goto LABEL_965;
              if ( get_elaps_frames() >= 20 )
                goto LABEL_965;
            }
          }
          if ( get_subseq() == 2 && get_frame() <= 1 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc - 0.5 < 7.0 )
              h_inerc = 7.0;
          }
          if ( get_subseq() == 3 )
          {
            h_inerc = h_inerc + 0.75;
            if ( h_inerc + 0.75 > -2.0 )
              goto LABEL_965;
          }
          if ( get_subseq() == 4 )
          {
            h_inerc = h_inerc + 0.4000000059604645;
            if ( h_inerc + 0.4000000059604645 > 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
          {
            play_sfx(42);
            h_inerc = 20.0;
            spell_energy_spend(200, 120);
            add_card_energy(50);
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            /*
            *(float *)&v1735 = 0.0;
            v1736 = 0.0;
            v1737 = 0.0;
            addbullet(, 817, x, y, dir, 1, (int)&v1735, 3);
            */
          }
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
          {
            /*
            *(float *)&v1458 = 0.0;
            v1459 = 15.0;
            v1460 = 4.0;
            if ( skills_1[9] >= 3 )
              v1460 = 5.0;
            if ( skills_1[9] >= 4 )
              v1460 = 6.0;
            v592 = dir;
            v593 = get_pframe();
            v594 = y - (double)v593->extra1[5];
            v595 = v594;
            v596 = (double)(v593->extra1[4] * (char)v592) + x;
            addbullet(, 817, v596, v595, v592, 1, (int)&v1458, 3);
            */
            play_sfx(43);
            field_190 = 1;
            h_inerc = -15.0;
          }
          return;
        case 540:
          sub10func();
          field_18C = 2;
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( get_subseq() == 1 )
          {
            if ( !get_frame_time() && !get_frame() && !get_elaps_frames() )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              /*
              *(float *)&v1579 = 0.0;
              v1580 = 0.0;
              v1581 = 0.0;
              v597 = dir;
              v598 = y + 294.0;
              v599 = v598;
              v600 = (double)(38 * (char)v597) + x;
              addbullet(, 820, v600, v599, v597, 1, (int)&v1579, 3);
              */
              play_sfx(50);
            }
            if ( get_elaps_frames() >= 20 && (!not_charge_attack || get_elaps_frames() >= 150) )
              goto LABEL_1872;
          }
          return;
        case 541:
          sub10func();
          field_18C = 2;
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( get_subseq() == 1 )
          {
            if ( !get_frame_time() && !get_frame() && !get_elaps_frames() )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              /*
              field_190 = 1;
              *(float *)&v1675 = 0.0;
              v1676 = 0.0;
              v1677 = 0.0;
              v602 = dir;
              v603 = y + 294.0;
              v604 = v603;
              v605 = (double)(38 * (char)v602) + x;
              addbullet(, 820, v605, v604, v602, 1, (int)&v1675, 3);
              */
              play_sfx(50);
            }
            if ( get_elaps_frames() >= 20 && (!not_charge_attack || get_elaps_frames() >= 150) )
            {
              play_sfx(51);
              next_subseq();
            }
          }
          return;
        case 542:
          field_18C = 2;
          v_inerc = v_inerc - v_force;
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(9);
          if ( get_subseq() != 1 )
            goto LABEL_1899;
          if ( get_frame_time() || get_frame() || get_elaps_frames() )
            goto LABEL_1896;
          add_card_energy(50);
          spell_energy_spend(200, 120);
          field_190 = 1;
          /*
          *(float *)&v1585 = 0.0;
          v1586 = 0.0;
          v1587 = 0.0;
          a2g = &v1585;
          v607 = y + 294.0;
          a1d = dir;
          a4b = v607;
          v608 = (double)(38 * (char)a1d) + x;
          v609 = v608;
          */
          //goto LABEL_1895;
          return; //TODO: change!
        case 543:
          field_18C = 2;
          v_inerc = v_inerc - v_force;
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(9);
          if ( get_subseq() == 1 )
          {
            if ( !get_frame_time() && !get_frame() && !get_elaps_frames() )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              /*
              v1723 = 0.0;
              v1724 = 0.0;
              v1725 = 0.0;
              a2g = (int *)&v1723;
              v612 = y + 294.0;
              a1d = dir;
              a4b = v612;
              v613 = (double)(38 * (char)a1d) + x;
              v609 = v613;
LABEL_1895:
              v610 = v609;
              addbullet(, 820, v610, a4b, a1d, 1, (int)a2g, 3);
              */
              play_sfx(50);
            }
LABEL_1896:
            if ( get_elaps_frames() >= 20 && (!not_charge_attack || get_elaps_frames() >= 180) )
            {
LABEL_1872:
              play_sfx(51);
              next_subseq();
              return;
            }
          }
LABEL_1899:
          if ( get_subseq() != 2 || get_frame_time() )
            return;
          v306 = get_frame() == 7;
          goto LABEL_1068;
        case 545:
          sub10func();
          field_18C = 6;
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( get_subseq() != 1 )
            goto LABEL_1924;
          if ( get_frame_time() || get_frame() || get_elaps_frames() )
            goto LABEL_1921;
          add_card_energy(50);
          spell_energy_spend(200, 120);
          field_190 = 1;
          /*
          *(float *)&v1591 = 0.0;
          v1592 = 0.0;
          v1593 = 0.0;
          a2h = &v1591;
          v614 = y + 294.0;
          a1e = dir;
          a4c = v614;
          v615 = (double)(38 * (char)a1e) + x;
          v616 = v615;
          */
          //goto LABEL_1920;
          return; //TODO: change!
        case 546:
          sub10func();
          field_18C = 6;
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(0);
          if ( get_subseq() == 1 )
          {
            if ( !get_frame_time() && !get_frame() && !get_elaps_frames() )
            {
              add_card_energy(50);
              spell_energy_spend(200, 120);
              field_190 = 1;
              /*
              v1681 = 0.0;
              v1682 = 0.0;
              v1683 = 0.0;
              a2h = (int *)&v1681;
              v619 = y + 294.0;
              a1e = dir;
              a4c = v619;
              v620 = (double)(38 * (char)a1e) + x;
              v616 = v620;
LABEL_1920:
              v617 = v616;
              addbullet(, 821, v617, a4c, a1e, 1, (int)a2h, 3);
              */
              play_sfx(50);
            }
LABEL_1921:
            if ( get_elaps_frames() >= 4 && (!not_charge_attack || get_elaps_frames() >= 150) )
              goto LABEL_1450;
          }
LABEL_1924:
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
            play_sfx(52);
          return;
        case 547:
          if ( get_subseq() == 2 )
            sub10func();
          field_18C = 2;
          if ( get_subseq() < 2 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              reset_forces();
              set_subseq(2);
              y = getlvl_height();
              return;
            }
          }
          if ( get_subseq() <= 1 && !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( process() )
            set_seq(9);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            goto LABEL_1116;
          if ( get_subseq() || get_frame_time() )
            return;
          if ( get_frame() == 8 && not_charge_attack == 1 )
            goto LABEL_1450;
          if ( get_frame() == 6 )
          {
            field_190 = 1;
            play_sfx(7);
            h_inerc = -4.0;
            v_inerc = 8.0;
            v_force = 0.5;
            /*
            v621 = dir;
            v622 = y + 62.0;
            v623 = v622;
            v624 = (double)(30 * (char)v621) + x;
            addbullet(, 816, v624, v623, v621, 1, 0, 0);
            */
            spell_energy_spend(200, 120);
            add_card_energy(50);
          }
          return;
        case 550:
          sub10func();
          field_18C = 10;
          if ( get_subseq() <= 1 && !keyDown(INP_B) )
            not_charge_attack = 0;
          field_7D0 = 20 * (7 - (char)skills_1[10]);
          if ( get_subseq() == 1 )
          {
            if ( get_elaps_frames() >= 12 && !not_charge_attack )
              goto LABEL_965;
            if ( get_elaps_frames() >= 20 * (7 - (char)skills_1[10]) )
              goto LABEL_965;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            field_190 = 1;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(63);
            /*
            v1376 = 1.0;
            *(float *)&v1374 = 2.0;
            v1375 = 1.5;
            v1377 = 0.0;
            v628 = dir;
            v629 = y + 176.0;
            v630 = v629;
            v631 = (double)(55 * (char)v628) + x;
            addbullet(, 822, v631, v630, v628, 1, (int)&v1374, 4);
            *(float *)&v1374 = 2.0;
            v1375 = -1.5;
            v1377 = 0.0;
            v632 = dir;
            v633 = y + 176.0;
            v634 = v633;
            v635 = (double)(55 * (char)v632) + x;
            addbullet(, 822, v635, v634, v632, 1, (int)&v1374, 4);
            *(float *)&v1374 = 1.0;
            v1375 = 3.0;
            v1377 = -15.0;
            v636 = dir;
            v637 = y + 176.0;
            v638 = v637;
            v639 = (double)(55 * (char)v636) + x;
            addbullet(, 822, v639, v638, v636, 1, (int)&v1374, 4);
            *(float *)&v1374 = 1.0;
            v1375 = -3.0;
            v1377 = 15.0;
            v640 = dir;
            v641 = y + 176.0;
            v642 = v641;
            v643 = (double)(55 * (char)v640) + x;
            addbullet(, 822, v643, v642, v640, 1, (int)&v1374, 4);
            */
          }
          return;
        case 551:
          sub10func();
          field_18C = 10;
          if ( get_subseq() <= 1 && !keyDown(INP_C) )
            not_charge_attack = 0;

          field_7D0 = 20 * (7 - (char)skills_1[10]);

          if ( get_subseq() == 1 )
          {

            if ( get_elaps_frames() >= 12 && !not_charge_attack )
              goto LABEL_965;
            if ( get_elaps_frames() >= 20 * (7 - (char)skills_1[10]) )
              goto LABEL_965;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            field_190 = 1;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            spell_energy_spend(200, 120);
            add_card_energy(50);
            play_sfx(63);
            /*
            v1372 = 1.0;
            *(float *)&v1370 = 2.0;
            v1371 = 1.5;
            v1373 = -10.0;
            v647 = dir;
            v648 = y + 176.0;
            v649 = v648;
            v650 = (double)(55 * (char)v647) + x;
            addbullet(, 822, v650, v649, v647, 1, (int)&v1370, 4);
            *(float *)&v1370 = 2.0;
            v1371 = -1.5;
            v1373 = 10.0;
            v651 = dir;
            v652 = y + 176.0;
            v653 = v652;
            v654 = (double)(55 * (char)v651) + x;
            addbullet(, 822, v654, v653, v651, 1, (int)&v1370, 4);
            *(float *)&v1370 = 1.0;
            v1371 = 3.0;
            v1373 = -45.0;
            v655 = dir;
            v656 = y + 176.0;
            v657 = v656;
            v658 = (double)(55 * (char)v655) + x;
            addbullet(, 822, v658, v657, v655, 1, (int)&v1370, 4);
            *(float *)&v1370 = 1.0;
            v1371 = -3.0;
            v1373 = 45.0;
            v659 = dir;
            v660 = y + 176.0;
            v661 = v660;
            v662 = (double)(55 * (char)v659) + x;
            addbullet(, 822, v662, v661, v659, 1, (int)&v1370, 4);
            */
          }
          return;
        case 552:
          if ( get_subseq() == 3 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_2026;
          }
          field_18C = 10;
          if ( get_subseq() <= 1 && !keyDown(INP_B) )
            not_charge_attack = 0;
          field_7D0 = 20 * (7 - (char)skills_1[10]);
          if ( get_subseq() == 1 )
          {
            if ( get_elaps_frames() >= 12 && !not_charge_attack )
              goto LABEL_965;
            if ( get_elaps_frames() >= 20 * (7 - (char)skills_1[10]) )
              goto LABEL_965;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            field_190 = 1;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              set_seq(9);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(63);
              /*
              v1380 = 1.0;
              *(float *)&v1378 = 2.0;
              v1379 = 1.5;
              v1381 = 0.0;
              v666 = dir;
              v667 = y + 176.0;
              v668 = v667;
              v669 = (double)(55 * (char)v666) + x;
              addbullet(, 822, v669, v668, v666, 1, (int)&v1378, 4);
              *(float *)&v1378 = 2.0;
              v1379 = -1.5;
              v1381 = 0.0;
              v670 = dir;
              v671 = y + 176.0;
              v672 = v671;
              v673 = (double)(55 * (char)v670) + x;
              addbullet(, 822, v673, v672, v670, 1, (int)&v1378, 4);
              *(float *)&v1378 = 1.0;
              v1379 = 3.0;
              v1381 = -15.0;
              v674 = dir;
              v675 = y + 176.0;
              v676 = v675;
              v677 = (double)(55 * (char)v674) + x;
              addbullet(, 822, v677, v676, v674, 1, (int)&v1378, 4);
              *(float *)&v1378 = 1.0;
              v1379 = -3.0;
              a2i = &v1378;
              v1381 = 15.0;
              a1f = dir;
              v678 = y + 176.0;
              a4d = v678;
              v679 = (double)(55 * dir) + x;
              v680 = v679;
              */
              //goto LABEL_2021;
              return; //TODO: change!
            }
          }
          goto LABEL_2022;
        case 553:
          if ( get_subseq() == 3 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_2026:
              reset_forces();
              y = getlvl_height();
              set_subseq(3);
              return;
            }
          }
          field_18C = 11;
          if ( get_subseq() <= 1 && !keyDown(INP_C) )
            not_charge_attack = 0;
          field_7D0 = 20 * (7 - (char)skills_1[10]);
          if ( get_subseq() == 1 )
          {
            if ( get_elaps_frames() >= 12 && !not_charge_attack )
              goto LABEL_965;
            if ( get_elaps_frames() >= 20 * (7 - (char)skills_1[10]) )
              goto LABEL_965;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            field_190 = 1;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              set_seq(9);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(63);
              /*
              v1368 = 1.0;
              *(float *)&v1366 = 2.0;
              v1367 = 1.5;
              v1369 = -10.0;
              v685 = dir;
              v686 = y + 176.0;
              v687 = v686;
              v688 = (double)(55 * (char)v685) + x;
              addbullet(, 822, v688, v687, v685, 1, (int)&v1366, 4);
              *(float *)&v1366 = 2.0;
              v1367 = -1.5;
              v1369 = 10.0;
              v689 = dir;
              v690 = y + 176.0;
              v691 = v690;
              v692 = (double)(55 * (char)v689) + x;
              addbullet(, 822, v692, v691, v689, 1, (int)&v1366, 4);
              *(float *)&v1366 = 1.0;
              v1367 = 3.0;
              v1369 = -45.0;
              v693 = dir;
              v694 = y + 176.0;
              v695 = v694;
              v696 = (double)(55 * (char)v693) + x;
              addbullet(, 822, v696, v695, v693, 1, (int)&v1366, 4);
              *(float *)&v1366 = 1.0;
              v1367 = -3.0;
              a2i = &v1366;
              v1369 = 45.0;
              a1f = dir;
              v697 = y + 176.0;
              a4d = v697;
              v698 = (double)(55 * dir) + x;
              v680 = v698;
LABEL_2021:
              v681 = v680;
              addbullet(, 822, v681, a4d, a1f, 1, (int)a2i, 4);
              */
            }
          }
LABEL_2022:
          if ( get_subseq() == 2 && !get_frame_time() )
          {
            v306 = get_frame() == 11;
            goto LABEL_1068;
          }
          return;
        case 560:
          field_18C = 3;
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( get_subseq() == 1 )
          {
            if ( !field_7D0 )
            {
              field_7DC = field_7DC * 0.9300000071525574;
              field_7E4 = field_7E4 * 0.8500000238418579;
              if ( field_7E4 * 0.8500000238418579 <= 4.0 )
                field_7D0 = 1;
              field_7EC = field_7DC - 10.0;
              //WHATIS?
              //set_vec_speed((render_class *)&cEffectSprite, field_7DC - 10.0, dash_angle + field_7E4);
            }
            if ( field_7D0 == 1 )
            {
              field_7DC = field_7DC * 0.949999988079071;
              dash_angle = dash_angle + 0.75;
              field_7E4 = field_7E4 * 0.8500000238418579;
              if ( dash_angle >= 15.0 )
                dash_angle = 15.0;
              if ( field_7E4 <= 0.05000000074505806 )
                field_7D0 = 1;
              field_7EC = field_7DC - 10.0;
              //WHATIS?
              //set_vec_speed((render_class *)&cEffectSprite, field_7DC - 10.0, field_7E4 + dash_angle);
            }
          }
          if ( get_subseq() == 2 )
          {
            field_7E8 = field_7E8 - 0.2000000029802322;
            dash_angle = dash_angle * 0.9800000190734863;
            if ( dash_angle * 0.9800000190734863 < 3.0 )
              dash_angle = 3.0;
            field_7EC = field_7DC - 10.0;
            //set_vec_speed((render_class *)&cEffectSprite, field_7DC - 10.0, dash_angle);
            v_inerc = field_7E8 + v_inerc;
          }
          if ( get_subseq() == 3 || get_subseq() == 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_1436:

LABEL_1437:
              y = getlvl_height();
              reset_forces();
              set_seq(10);
              return;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && skills_1[3] >= 1 )
            process();
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              spell_energy_spend(200, 120);
              play_sfx(60);
              add_card_energy(50);
              /*
              *(float *)&v1464 = 0.0;
              v1465 = 0.0;
              v1466 = 0.0;
              v707 = dir;
              v708 = get_pframe();
              v709 = y - (double)v708->extra1[5];
              v710 = v709;
              v711 = (double)(v708->extra1[4] * (char)v707) + x;
              addbullet(, 825, v711, v710, v707, 1, (int)&v1464, 3);
              *(float *)&v1464 = 180.0;
              v712 = dir;
              v713 = get_pframe();
              v714 = y - (double)v713->extra1[5];
              v715 = v714;
              v716 = (double)(v713->extra1[4] * (char)v712) + x;
              addbullet(, 825, v716, v715, v712, 1, (int)&v1464, 3);
              */
              field_7DC = -70.0;
              dash_angle = 2.0;
              field_7E4 = 20.0;
              field_190 = 1;
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
              flip_with_force();
          }
          
          if ( get_subseq() == 1 )
          {
            if ( get_elaps_frames() >= 40 && !not_charge_attack )
              goto LABEL_965;
            if ( get_elaps_frames() >= 80 )
              goto LABEL_965;
          }
          goto LABEL_2093;
        case 561:
          field_18C = 3;
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( get_subseq() == 1 )
          {
            if ( !field_7D0 )
            {
              field_7DC = field_7DC * 0.9300000071525574;
              field_7E4 = field_7E4 * 0.8500000238418579;
              if ( field_7E4 * 0.8500000238418579 <= 4.0 )
                field_7D0 = 1;
              field_7EC = -170.0 - field_7DC;
              //set_vec_speed((render_class *)&cEffectSprite, -170.0 - field_7DC, dash_angle + field_7E4);
            }
            if ( field_7D0 == 1 )
            {
              field_7DC = field_7DC * 0.949999988079071;
              dash_angle = dash_angle + 0.75;
              field_7E4 = field_7E4 * 0.8500000238418579;
              if ( dash_angle >= 15.0 )
                dash_angle = 15.0;
              if ( field_7E4 <= 0.05000000074505806 )
                field_7D0 = 1;
              field_7EC = -170.0 - field_7DC;
              //set_vec_speed((render_class *)&cEffectSprite, -170.0 - field_7DC, field_7E4 + dash_angle);
            }
          }
          if ( get_subseq() == 2 )
          {
            field_7E8 = field_7E8 - 0.2000000029802322;
            dash_angle = dash_angle * 0.9800000190734863;
            if ( dash_angle * 0.9800000190734863 < 3.0 )
              dash_angle = 3.0;
            field_7EC = -170.0 - field_7DC;
            //set_vec_speed((render_class *)&cEffectSprite, -170.0 - field_7DC, dash_angle);
            v_inerc = field_7E8 + v_inerc;
          }
          if ( get_subseq() == 3 || get_subseq() == 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1396;
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && skills_1[3] >= 1 )
            process();
          if ( get_elaps_frames() )
            goto LABEL_2132;
          if ( get_frame_time() || get_frame() || get_subseq() != 1 )
            goto LABEL_2127;
          spell_energy_spend(200, 120);
          add_card_energy(50);
          play_sfx(60);
          /*
          *(float *)&v1461 = 0.0;
          v1462 = 0.0;
          v1463 = 0.0;
          v727 = dir;
          v728 = get_pframe();
          v729 = y - (double)v728->extra1[5];
          v730 = v729;
          v731 = (double)(v728->extra1[4] * (char)v727) + x;
          addbullet(, 825, v731, v730, v727, 1, (int)&v1461, 3);
          *(float *)&v1461 = 180.0;
          v732 = dir;
          v733 = get_pframe();
          v734 = y - (double)v733->extra1[5];
          v735 = v734;
          v736 = (double)(v733->extra1[4] * (char)v732) + x;
          addbullet(, 825, v736, v735, v732, 1, (int)&v1461, 3);
          */
          field_7DC = -70.0;
          dash_angle = 2.0;
          v737 = 20.0;
          goto LABEL_2126;
        case 562:
          field_18C = 3;
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          if ( get_subseq() == 1 )
          {
            if ( !field_7D0 )
            {
              field_7DC = field_7DC * 0.9300000071525574;
              field_7E4 = field_7E4 * 0.8999999761581421;
              if ( field_7E4 * 0.8999999761581421 <= 4.0 )
                field_7D0 = 1;
              field_7EC = field_7DC - 10.0;
              //set_vec_speed((render_class *)&cEffectSprite, field_7DC - 10.0, dash_angle + field_7E4);
            }
            if ( field_7D0 == 1 )
            {
              field_7DC = field_7DC * 0.949999988079071;
              dash_angle = dash_angle + 0.75;
              field_7E4 = field_7E4 * 0.8999999761581421;
              if ( dash_angle >= 15.0 )
                dash_angle = 15.0;
              if ( field_7E4 <= 0.05000000074505806 )
                field_7D0 = 1;
              field_7EC = field_7DC - 10.0;
              //set_vec_speed((render_class *)&cEffectSprite, field_7DC - 10.0, field_7E4 + dash_angle);
            }
          }
          if ( get_subseq() == 2 )
          {
            field_7E8 = field_7E8 - 0.2000000029802322;
            dash_angle = dash_angle * 0.9800000190734863;
            if ( dash_angle * 0.9800000190734863 < 3.0 )
              dash_angle = 3.0;
            field_7EC = field_7DC - 10.0;
            //set_vec_speed((render_class *)&cEffectSprite, field_7DC - 10.0, dash_angle);
            v_inerc = field_7E8 + v_inerc;
          }
          if ( get_subseq() == 3 || get_subseq() == 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_1396;
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && skills_1[3] >= 1 && get_frame() <= 3 )
            process();
          if ( get_elaps_frames() )
            goto LABEL_2132;
          if ( get_frame_time() || get_frame() || get_subseq() != 1 )
            goto LABEL_2127;
          spell_energy_spend(200, 120);
          add_card_energy(50);
          play_sfx(60);
          /*
          *(float *)&v1467 = 0.0;
          v1468 = 0.0;
          v1469 = 0.0;
          v747 = dir;
          v748 = get_pframe();
          v749 = y - (double)v748->extra1[5];
          v750 = v749;
          v751 = (double)(v748->extra1[4] * (char)v747) + x;
          addbullet(, 825, v751, v750, v747, 1, (int)&v1467, 3);
          *(float *)&v1467 = 180.0;
          v752 = dir;
          v753 = get_pframe();
          v754 = y - (double)v753->extra1[5];
          v755 = v754;
          v756 = (double)(v753->extra1[4] * (char)v752) + x;
          addbullet(, 825, v756, v755, v752, 1, (int)&v1467, 3);
          */
          v757 = 70.0;
          goto LABEL_2168;
        case 563:
          field_18C = 3;
          if ( !keyDown(INP_C) )
            not_charge_attack = 0;
          if ( get_subseq() == 1 )
          {
            if ( !field_7D0 )
            {
              field_7DC = field_7DC * 0.9300000071525574;
              field_7E4 = field_7E4 * 0.8999999761581421;
              if ( field_7E4 * 0.8999999761581421 <= 4.0 )
                field_7D0 = 1;
              field_7EC = field_7DC - 170.0;
              //set_vec_speed((render_class *)&cEffectSprite, field_7DC - 170.0, dash_angle + field_7E4);
            }
            if ( field_7D0 == 1 )
            {
              field_7DC = field_7DC * 0.949999988079071;
              dash_angle = dash_angle + 0.75;
              field_7E4 = field_7E4 * 0.8999999761581421;
              if ( dash_angle >= 15.0 )
                dash_angle = 15.0;
              if ( field_7E4 <= 0.05000000074505806 )
                field_7D0 = 1;
              field_7EC = field_7DC - 170.0;
              //set_vec_speed((render_class *)&cEffectSprite, field_7DC - 170.0, field_7E4 + dash_angle);
            }
          }
          if ( get_subseq() == 2 )
          {
            field_7E8 = field_7E8 - 0.2000000029802322;
            dash_angle = dash_angle * 0.9800000190734863;
            if ( dash_angle * 0.9800000190734863 < 3.0 )
              dash_angle = 3.0;
            field_7EC = field_7DC - 170.0;
            //set_vec_speed((render_class *)&cEffectSprite, field_7DC - 170.0, dash_angle);
            v_inerc = field_7E8 + v_inerc;
          }
          if ( get_subseq() == 3 || get_subseq() == 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_1396:
              y = getlvl_height();
              reset_forces();
              set_seq(10);
              return;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && skills_1[3] >= 1 && get_frame() <= 3 )
            process();
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              spell_energy_spend(200, 120);
              add_card_energy(50);
              play_sfx(60);
              /*
              *(float *)&v1473 = 0.0;
              v1474 = 0.0;
              v1475 = 0.0;
              v766 = dir;
              v767 = get_pframe();
              v768 = y - (double)v767->extra1[5];
              v769 = v768;
              v770 = (double)(v767->extra1[4] * (char)v766) + x;
              addbullet(, 825, v770, v769, v766, 1, (int)&v1473, 3);
              *(float *)&v1473 = 180.0;
              v771 = dir;
              v772 = get_pframe();
              v773 = y - (double)v772->extra1[5];
              v774 = v773;
              v775 = (double)(v772->extra1[4] * (char)v771) + x;
              addbullet(, 825, v775, v774, v771, 1, (int)&v1473, 3);
              */
              v757 = -70.0;
LABEL_2168:
              field_7DC = v757;
              dash_angle = 2.0;
              v737 = 15.0;
LABEL_2126:
              field_7E4 = v737;
              field_190 = 1;
            }
LABEL_2127:
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
              flip_with_force();
          }
LABEL_2132:
          
          if ( get_subseq() != 1 )
            goto LABEL_2093;
          if ( get_elaps_frames() >= 40 && !not_charge_attack )
            goto LABEL_965;
          if ( get_elaps_frames() < 80 )
          {
LABEL_2093:
            if ( get_subseq() == 2 && get_elaps_frames() >= 16 )
            {
              next_subseq();
              v_force = 0.5;
            }
          }
          else
          {
            next_subseq();
          }
          return;
        case 565:
          sub10func();
          field_18C = 7;
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 1 )
            {
              /*
              *(float *)&v1597 = 0.0;
              v1598 = 0.0;
              v1599 = 3.0;
              v776 = y + 125.0;
              addbullet(, 826, x, v776, dir, -1, (int)&v1597, 3);
              */
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 4 && skills_1[7] >= 4 )
                set_frame(7);
              if ( !get_frame_time() )
              {
                if ( get_frame() == 5 && skills_1[7] >= 3 )
                  set_frame(7);
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 6 && skills_1[7] >= 2 )
                    set_frame(7);
                  if ( !get_frame_time() && get_frame() == 8 )
                  {
                    add_card_energy(50);
                    play_sfx(62);
                    field_190 = 1;
                    spell_energy_spend(200, 120);
                    /*
                    *(float *)&v1385 = 0.0;
                    v1386 = 0.0;
                    v1387 = 0.0;
                    v777 = y + 125.0;
                    addbullet(, 826, x, v777, dir, 1, (int)&v1385, 3);
                    v778 = 10;
                    do
                    {
                      *(float *)&v1385 = 360.0;
                      v1386 = (double)(unsigned int)get_MT_range(12) + 6.0;
                      v1387 = 2.0;
                      v779 = dir;
                      v780 = -*(float *)&v1385;
                      v781 = sin_deg(v780);
                      v782 = v781 * v1386 + y + 125.0;
                      v783 = v782;
                      v784 = -*(float *)&v1385;
                      v785 = cos_deg(v784);
                      v786 = v785 * (v1386 + v1386) * (double)dir + x;
                      addbullet(, 826, v786, v783, v779, 1, (int)&v1385, 3);
                      --v778;
                    }
                    while ( v778 );
                    */
                  }
                }
              }
            }
          }
          return;
        case 566:
          sub10func();
          field_18C = 7;
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 1 )
            {
              /*
              *(float *)&v1741 = 0.0;
              v1742 = 0.0;
              v1743 = 3.0;
              v787 = y + 125.0;
              addbullet(, 826, x, v787, dir, -1, (int)&v1741, 3);
              */
            }
            if ( !get_frame_time() && get_frame() == 14 )
            {
              add_card_energy(50);
              play_sfx(62);
              field_190 = 1;
              spell_energy_spend(200, 120);
              /*
              *(float *)&v1360 = 0.0;
              v1361 = 0.0;
              v1362 = 0.0;
              v788 = y + 125.0;
              addbullet(, 826, x, v788, dir, 1, (int)&v1360, 3);
              if ( skills_1[7] > 3 )
              {
                v1361 = 120.0;
                v789 = y + 125.0;
                addbullet(, 826, x, v789, dir, 1, (int)&v1360, 3);
                v1361 = 240.0;
                v1320 = y + 125.0;
                a1g = dir;
              }
              else
              {
                v1361 = 180.0;
                a1g = dir;
                v1320 = y + 125.0;
              }
              addbullet(, 826, x, v1320, a1g, 1, (int)&v1360, 3);
              v790 = 10;
              do
              {
                *(float *)&v1360 = 360.0;
                v1361 = (double)(unsigned int)get_MT_range(12) + 6.0;
                v1362 = 2.0;
                v791 = dir;
                v792 = -*(float *)&v1360;
                v793 = sin_deg(v792);
                v794 = v793 * v1361 + y + 125.0;
                v795 = v794;
                v796 = -*(float *)&v1360;
                v797 = cos_deg(v796);
                v798 = v797 * (v1361 + v1361) * (double)dir + x;
                addbullet(, 826, v798, v795, v791, 1, (int)&v1360, 3);
                --v790;
              }
              while ( v790 );
              */
            }
          }
          return;
        case 567:
          if ( get_subseq() == 3 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_2271;
          }
          field_18C = 7;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 1 )
            {
              /*
              *(float *)&v1603 = 0.0;
              v1604 = 0.0;
              v1605 = 3.0;
              v799 = y + 125.0;
              addbullet(, 826, x, v799, dir, -1, (int)&v1603, 3);
              */
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 4 && skills_1[7] >= 4 )
                set_frame(7);
              if ( !get_frame_time() )
              {
                if ( get_frame() == 5 && skills_1[7] >= 3 )
                  set_frame(7);
                if ( !get_frame_time() )
                {
                  if ( get_frame() == 6 && skills_1[7] >= 2 )
                    set_frame(7);
                  if ( !get_frame_time() && get_frame() == 8 )
                  {
                    add_card_energy(50);
                    play_sfx(62);
                    field_190 = 1;
                    spell_energy_spend(200, 120);
                    /*
                    *(float *)&v1382 = 0.0;
                    v1383 = 0.0;
                    v1384 = 0.0;
                    v800 = y + 125.0;
                    addbullet(, 826, x, v800, dir, 1, (int)&v1382, 3);
                    v801 = 10;
                    do
                    {
                      *(float *)&v1382 = 360.0;
                      v1383 = (double)(unsigned int)get_MT_range(12) + 6.0;
                      v1384 = 2.0;
                      v802 = dir;
                      v803 = -*(float *)&v1382;
                      v804 = sin_deg(v803);
                      v805 = v804 * v1383 + y + 125.0;
                      v806 = v805;
                      v807 = -*(float *)&v1382;
                      v808 = cos_deg(v807);
                      v809 = v808 * (v1383 + v1383) * (double)dir + x;
                      addbullet(, 826, v809, v806, v802, 1, (int)&v1382, 3);
                      --v801;
                    }
                    while ( v801 );
                    */
                  }
                }
              }
            }
          }
          goto LABEL_2266;
        case 568:
          if ( get_subseq() == 3 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_2271:
              y = getlvl_height();
              set_subseq(3);
              reset_forces();
              return;
            }
          }
          field_18C = 7;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 1 )
            {
              /*
              *(float *)&v1687 = 0.0;
              v1688 = 0.0;
              v1689 = 3.0;
              v810 = y + 125.0;
              addbullet(, 826, x, v810, dir, -1, (int)&v1687, 3);
              */
            }
            if ( !get_frame_time() && get_frame() == 14 )
            {
              add_card_energy(50);
              play_sfx(62);
              field_190 = 1;
              spell_energy_spend(200, 120);
              /*
              *(float *)&v1354 = 0.0;
              v1355 = 0.0;
              v1356 = 0.0;
              v811 = y + 125.0;
              addbullet(, 826, x, v811, dir, 1, (int)&v1354, 3);
              if ( skills_1[7] > 3 )
              {
                v1355 = 120.0;
                v812 = y + 125.0;
                addbullet(, 826, x, v812, dir, 1, (int)&v1354, 3);
                v1355 = 240.0;
                v1321 = y + 125.0;
                a1h = dir;
              }
              else
              {
                v1355 = 180.0;
                a1h = dir;
                v1321 = y + 125.0;
              }
              addbullet(, 826, x, v1321, a1h, 1, (int)&v1354, 3);
              v813 = 10;
              do
              {
                *(float *)&v1354 = 360.0;
                v1355 = (double)(unsigned int)get_MT_range(12) + 6.0;
                v1356 = 2.0;
                v814 = dir;
                v815 = -*(float *)&v1354;
                v816 = sin_deg(v815);
                v817 = v816 * v1355 + y + 125.0;
                v818 = v817;
                v819 = -*(float *)&v1354;
                v820 = cos_deg(v819);
                v821 = v820 * (v1355 + v1355) * (double)dir + x;
                addbullet(, 826, v821, v818, v814, 1, (int)&v1354, 3);
                --v813;
              }
              while ( v813 );
              */
            }
          }
LABEL_2266:
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
            v_force = 0.25;
          return;
        case 570:
          sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          field_18C = 11;
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
          {
            /*
            *(float *)&v1609 = 0.0;
            v1610 = 0.0;
            v1611 = 4.0;
            v822 = dir;
            v823 = get_pframe();
            v824 = y - (double)v823->extra1[5];
            v825 = v824;
            v826 = (double)(v823->extra1[4] * (char)v822) + x;
            addbullet(, 827, v826, v825, v822, 1, (int)&v1609, 3);
            */
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            play_sfx(65);
            spell_energy_spend(200, 60);
            field_190 = 1;
            add_card_energy(30);
            /*
            *(float *)&v1729 = 0.0;
            v1730 = 0.0;
            v1731 = 0.0;
            v827 = dir;
            v828 = get_pframe();
            v829 = y - (double)v828->extra1[5];
            v830 = v829;
            v831 = (double)(v828->extra1[4] * (char)v827) + x;
            addbullet(, 827, v831, v830, v827, 1, (int)&v1729, 3);
            */
          }
          return;
        case 571:
          sub10func();
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          field_18C = 11;
          if ( process() )
            set_seq(0);
          if ( get_subseq() != 1 )
            goto LABEL_2317;
          if ( get_elaps_frames() == 1 )
            field_190 = 1;
          if ( get_elaps_frames() >= 8 )
            goto LABEL_965;
          if ( get_elaps_frames() % 10 == 1 )
          {
            /*
            *(float *)&v1615 = 0.0;
            v1616 = 0.25;
            v1617 = 5.0;
            v833 = dir;
            v834 = get_pframe();
            v835 = y - (double)v834->extra1[5];
            v836 = v835;
            v837 = (double)(v834->extra1[4] * (char)v833) + x;
            addbullet(, 827, v837, v836, v833, 1, (int)&v1615, 3);
            */
          }
LABEL_2317:
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            spell_energy_spend(200, 120);
            add_card_energy(30);
          }
          return;
        case 572:
          if ( get_subseq() == 4 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
              goto LABEL_2349;
          }
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          field_18C = 11;
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
          {
            /*
            *(float *)&v1693 = 0.0;
            v1694 = 0.0;
            v1695 = 4.0;
            v838 = dir;
            v839 = get_pframe();
            v840 = y - (double)v839->extra1[5];
            v841 = v840;
            v842 = (double)(v839->extra1[4] * (char)v838) + x;
            addbullet(, 827, v842, v841, v838, 1, (int)&v1693, 3);
            */
          }
          if ( get_elaps_frames() )
            return;
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            play_sfx(65);
            spell_energy_spend(200, 120);
            field_190 = 1;
            add_card_energy(30);
            /*
            *(float *)&v1621 = 0.0;
            v1622 = 0.0;
            v1623 = 0.0;
            v843 = dir;
            v844 = get_pframe();
            v845 = y - (double)v844->extra1[5];
            v846 = v845;
            v847 = (double)(v844->extra1[4] * (char)v843) + x;
            addbullet(, 827, v847, v846, v843, 1, (int)&v1621, 3);
            */
          }
          if ( get_elaps_frames() )
            return;
          if ( !get_frame_time() && !get_frame() )
          {
            v848 = get_subseq() == 3;
            goto LABEL_2341;
          }
          goto LABEL_2343;
        case 573:
          if ( get_subseq() == 3 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              y = getlvl_height();
              reset_forces();
              set_subseq(3);
              return;
            }
          }
          if ( !keyDown(INP_B) )
            not_charge_attack = 0;
          field_18C = 11;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            field_190 = 1;
          if ( process() )
            set_seq(0);
          if ( get_subseq() != 1 )
            goto LABEL_2367;
          if ( get_elaps_frames() >= 8 )
            goto LABEL_965;
          if ( get_elaps_frames() % 10 == 1 )
          {
            /*
            *(float *)&v1747 = 0.0;
            v1748 = 0.25;
            v1749 = 5.0;
            v850 = dir;
            v851 = get_pframe();
            v852 = y - (double)v851->extra1[5];
            v853 = v852;
            v854 = (double)(v851->extra1[4] * (char)v850) + x;
            addbullet(, 827, v854, v853, v850, 1, (int)&v1747, 3);
            */
          }
LABEL_2367:
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            spell_energy_spend(200, 120);
            add_card_energy(30);
          }
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 3 )
            v_force = 0.5;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            set_seq(9);
          return;
        case 599:
          if ( field_7D0 > 0 && get_frame() < 7 && field_7D0 < 12 )
          {
            /*
            v856 = MT_getnext() % 0x23u;
            field_7D4 = v856;
            *(float *)&v1423 = (double)(-20 - v856);
            v1424 = (double)(signed __int16)(MT_getnext() % 5u + 10);
            v1425 = 0.0;
            v857 = dir;
            v858 = (double)(20 * (char)v857 * (field_7D0 + 1)) + x;
            addbullet(, 807, v858, y, v857, 1, (int)&v1423, 3);
            *(float *)&v1423 = (double)(MT_getnext() % 0x168u);
            v1424 = 0.0;
            v1425 = 1.0;
            v859 = dir;
            v860 = (double)(20 * (char)v859 * (field_7D0 + 1)) + x;
            addbullet(, 801, v860, y, v859, 1, (int)&v1423, 3);
            */
            if ( field_7D0 == 1 )
            {
              play_sfx(0);
              spell_energy_spend(200, 120);
            }
            ++field_7D0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() && get_frame() == 5 )
            field_7D0 = 1;
          return;
        case 600:
          sub10func();
          sub_46AB50(0, 2);
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            sub_4834E0(60);
            scene_play_sfx(23);
            scene_add_effect(this, 115, (double)(3 * (char)dir) + x, y + 120.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
            /*
            *(float *)&v1350 = 0.0;
            v1351 = 1.0;
            v1352 = 3.0;
            v1353 = 60.0;
            addbullet(, 970, 0.0, 64.0, 1, 1, (int)&v1350, 4);
            v1352 = 2.0;
            addbullet(, 970, 0.0, 64.0, 1, 1, (int)&v1350, 4);
            v1352 = 3.0;
            addbullet(, 970, 0.0, 416.0, 1, 1, (int)&v1350, 4);
            v1352 = 2.0;
            addbullet(, 970, 0.0, 416.0, 1, 1, (int)&v1350, 4);
            *(float *)&v1350 = 240.0;
            v1351 = 1.0;
            v1352 = 5.0;
            addbullet(, 970, 320.0, 242.0, 1, 1, (int)&v1350, 4);
            v1352 = 4.0;
            addbullet(, 970, 320.0, 240.0, 1, 1, (int)&v1350, 4);
            v1352 = 5.0;
            addbullet(, 970, 0.0, 242.0, 1, 1, (int)&v1350, 4);
            v1352 = 4.0;
            addbullet(, 970, 0.0, 240.0, 1, 1, (int)&v1350, 4);
            v1352 = 5.0;
            addbullet(, 970, 640.0, 242.0, 1, 1, (int)&v1350, 4);
            v1352 = 4.0;
            addbullet(, 970, 640.0, 240.0, 1, 1, (int)&v1350, 4);
            v1352 = 5.0;
            addbullet(, 970, 960.0, 242.0, 1, 1, (int)&v1350, 4);
            v1352 = 4.0;
            addbullet(, 970, 960.0, 240.0, 1, 1, (int)&v1350, 4);
            v1353 = 120.0;
            v1352 = 6.0;
            addbullet(, 970, 960.0, 240.0, 1, 1, (int)&v1350, 4);
            */
          }
          if ( get_subseq() != 2 || get_frame_time() || get_frame() != 1 )
            return;
          /*
          *(float *)&v1479 = 0.0;
          v1480 = 0.0;
          v1481 = 7.0;
          v865 = dir;
          v866 = y + 136.0;
          v867 = v866;
          v868 = (double)(85 * (char)v865) + x;
          addbullet(, 850, v868, v867, v865, 1, (int)&v1479, 3);
          v1481 = 6.0;
          v869 = dir;
          v870 = y + 136.0;
          v871 = v870;
          v872 = (double)(23 * (char)v869) + x;
          addbullet(, 850, v872, v871, v869, 1, (int)&v1479, 3);
          */
          play_sfx(100);
          goto LABEL_2403;
        case 601:
          sub10func();
          sub_46AB50(0, 2);
          if ( get_subseq() != 2 )
            goto LABEL_3216;
          h_inerc = h_inerc + 0.5;
          if ( h_inerc + 0.5 > -1.0 )
            h_inerc = -1.0;
          if ( !(get_elaps_frames() % 5) )
          {
            /*
            *(float *)&v1627 = 0.0;
            v1628 = 0.0;
            v1629 = 6.0;
            v886 = dir;
            v887 = get_pframe();
            v888 = y - (double)v887->extra1[5];
            v889 = v888;
            v890 = (double)(v887->extra1[4] * (char)v886) + x;
            addbullet(, 851, v890, v889, v886, 1, (int)&v1627, 3);
            */
          }
          if ( !(get_elaps_frames() % 3) )
          {
            /*
            *(float *)&v1699 = (double)(unsigned int)get_MT_range(160) - 80.0;
            v1700 = (double)(unsigned int)get_MT_range(45) + 20.0;
            v1701 = 11.0;
            v891 = dir;
            v892 = get_pframe();
            v893 = y - (double)v892->extra1[5];
            v894 = v893;
            v895 = (double)(v892->extra1[4] * (char)v891) + x;
            addbullet(, 851, v895, v894, v891, 1, (int)&v1699, 3);
            */
          }
          if ( get_elaps_frames() < 120 )
          {
LABEL_3216:
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                sub_4834E0(60);
                play_sfx(101);
                scene_play_sfx(23);
                scene_add_effect(this, 115, (double)(114 * (char)dir) + x, y + 137.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
                /*
                *(float *)&v1342 = 0.0;
                v1343 = 1.0;
                v1344 = 3.0;
                v1345 = 60.0;
                addbullet(, 970, 0.0, 64.0, 1, 1, (int)&v1342, 4);
                v1344 = 2.0;
                addbullet(, 970, 0.0, 64.0, 1, 1, (int)&v1342, 4);
                v1344 = 3.0;
                addbullet(, 970, 0.0, 416.0, 1, 1, (int)&v1342, 4);
                v1344 = 2.0;
                addbullet(, 970, 0.0, 416.0, 1, 1, (int)&v1342, 4);
                *(float *)&v1342 = 240.0;
                v1343 = 1.0;
                v1344 = 5.0;
                addbullet(, 970, 320.0, 242.0, 1, 1, (int)&v1342, 4);
                v1344 = 4.0;
                addbullet(, 970, 320.0, 240.0, 1, 1, (int)&v1342, 4);
                v1344 = 5.0;
                addbullet(, 970, 0.0, 242.0, 1, 1, (int)&v1342, 4);
                v1344 = 4.0;
                addbullet(, 970, 0.0, 240.0, 1, 1, (int)&v1342, 4);
                v1344 = 5.0;
                addbullet(, 970, 640.0, 242.0, 1, 1, (int)&v1342, 4);
                v1344 = 4.0;
                addbullet(, 970, 640.0, 240.0, 1, 1, (int)&v1342, 4);
                v1344 = 5.0;
                addbullet(, 970, 960.0, 242.0, 1, 1, (int)&v1342, 4);
                v1344 = 4.0;
                addbullet(, 970, 960.0, 240.0, 1, 1, (int)&v1342, 4);
                v1345 = 120.0;
                v1344 = 6.0;
                addbullet(, 970, 960.0, 240.0, 1, 1, (int)&v1342, 4);
                *(float *)&v1342 = 0.0;
                v1343 = 0.0;
                v1344 = 7.0;
                v901 = dir;
                v902 = get_pframe();
                v903 = y - (double)v902->extra1[5];
                v904 = v903;
                v905 = (double)(v902->extra1[4] * (char)v901) + x;
                addbullet(, 851, v905, v904, v901, 1, (int)&v1342, 3);
                */
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
              {
                play_sfx(102);
                h_inerc = -10.0;
              }
            }
          }
          else
          {
            h_inerc = 0.0;
            next_subseq();
          }
          return;
        case 602:
          sub10func();
          sub_46AB50(0, 2);
          if ( get_subseq() == 1 )
          {
            if ( !(get_elaps_frames() % 10) && get_elaps_frames() <= 90 )
            {
              /*
              *(float *)&v1633 = 0.0;
              v1634 = 0.0;
              v1635 = 5.0;
              v906 = dir;
              v907 = y + 150.0;
              v908 = v907;
              v909 = (double)(25 * (char)v906) + x;
              addbullet(, 852, v909, v908, v906, 1, (int)&v1633, 3);
              */
              scene_add_effect(this, 127, x - (double)(100 * (char)dir), y, dir, -1);
            }
            if ( get_elaps_frames() > 120 )
              goto LABEL_965;
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && get_frame() == 3 && !get_frame_time() )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, (double)(18 * (char)dir) + x, y + 83.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            /*
            v916 = dir;
            v917 = y + 130.0;
            v918 = v917;
            v919 = x - (double)(80 * (char)v916);
            addbullet(, 990, v919, v918, v916, 1, 0, 0);
            */
            play_sfx(11);
            /*
            *(float *)&v1429 = 0.0;
            v1430 = 0.0;
            v1431 = 0.0;
            v920 = dir;
            v921 = y + 150.0;
            v922 = v921;
            v923 = (double)(25 * (char)v920) + x;
            addbullet(, 852, v923, v922, v920, 1, (int)&v1429, 3);
            v1431 = 2.0;
            v924 = dir;
            v925 = y + 150.0;
            v926 = v925;
            v927 = (double)(25 * (char)v924) + x;
            addbullet(, 852, v927, v926, v924, 1, (int)&v1429, 3);
            v1431 = 4.0;
            v928 = dir;
            v929 = y + 150.0;
            v930 = v929;
            v931 = (double)(25 * (char)v928) + x;
            addbullet(, 852, v931, v930, v928, 1, (int)&v1429, 3);
            */
          }
          return;
        case 603:
          sub10func();
          sub_46AB50(0, 2);
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
            scene_add_effect(this, 115, (double)(get_pframe()->extra1[4] * (char)dir) + x, y - (double)get_pframe()->extra1[5], dir, 1);
            /*
            *(float *)&v1498 = 0.0;
            v1499 = 0.0;
            v1500 = 0.0;
            v937 = dir;
            v938 = y + 320.0;
            v939 = v938;
            v940 = (double)(40 * (char)v937) + x;
            addbullet(, 853, v940, v939, v937, 1, (int)&v1498, 3);
            */
            play_sfx(117);
          }
          if ( get_subseq() == 3 && !get_frame_time() && get_frame() == 2 )
            play_sfx(103);
          return;
        case 604:
          sub10func();
          sub_46AB50(0, 2);
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 4 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 111.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() && get_frame() == 5 )
            {
              /*
              *(float *)&v1476 = 0.0;
              v1477 = 0.0;
              v1478 = 2.0;
              v951 = y + 100.0;
              addbullet(, 854, x, v951, dir, -1, (int)&v1476, 3);
              v1478 = 3.0;
              v952 = y + 100.0;
              addbullet(, 854, x, v952, dir, -1, (int)&v1476, 3);
              */
            }
          }
          if ( get_subseq() == 1 && !get_frame_time() && !get_frame() )
          {
            play_sfx(104);
            /*
            *(float *)&v1397 = 0.0;
            v1398 = 0.0;
            v1399 = 4.0;
            v953 = y + 100.0;
            addbullet(, 854, x, v953, dir, 1, (int)&v1397, 3);
            v954 = 0.0;
            v1329 = 0.0;
            v955 = (float)0.0;
            while ( 1 )
            {
              *(float *)&v1397 = v955 * 72.0;
              v1398 = v954;
              v1399 = v954;
              v956 = y + 100.0;
              addbullet(, 854, x, v956, dir, 1, (int)&v1397, 3);
              v1329 = v1329 + 1.0;
              v957 = 5.0;
              v955 = v1329;
              if ( v1329 >= 5.0 )
                break;
              v954 = 0.0;
            }
            v1330 = 0.0;
            v958 = (float)0.0;
            do
            {
              *(float *)&v1397 = v958 * 72.0;
              v1398 = 0.0;
              v1399 = v957;
              v959 = y + 100.0;
              addbullet(, 854, x, v959, dir, 1, (int)&v1397, 3);
              v1330 = v1330 + 1.0;
              v957 = 5.0;
              v958 = v1330;
            }
            while ( v1330 < 5.0 );
            */
          }
          return;
        case 605:
          sub10func();
          sub_46AB50(0, 2);
          if ( get_subseq() == 2 && get_elaps_frames() >= 120 )
            goto LABEL_965;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              CharFrameData *frm = get_pframe();
              scene_add_effect(this, 115, (double)(frm->extra1[4] * (char)dir) + x, y - (double)frm->extra1[5], dir, 1);
              /*
              *(float *)&v1510 = 0.0;
              v1511 = 0.0;
              v1512 = 4.0;
              v965 = dir;
              v966 = y + 220.0;
              v967 = v966;
              v968 = (double)(40 * (char)v965) + x;
              addbullet(, 855, v968, v967, v965, 1, (int)&v1510, 3);
              */
              play_sfx(105);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
                /*
              *(float *)&v1516 = 0.0;
              v1517 = 0.40000001;
              v1518 = 0.0;
              v969 = dir;
              v970 = get_pframe();
              v971 = y - (double)v970->extra1[5];
              v972 = v971;
              v973 = (double)(v970->extra1[4] * (char)v969) + x;
              addbullet(, 855, v973, v972, v969, 1, (int)&v1516, 3);
              */
            }
          }
          return;
        case 606:
          sub10func();
          if ( get_subseq() < 4 )
            sub_46AB50(0, 2);
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 1 )
          {
            /*
            *(float *)&v1534 = 0.0;
            v1535 = 0.0;
            v1536 = 4.0;
            v988 = dir;
            v989 = y + 220.0;
            v990 = v989;
            v991 = (double)(40 * (char)v988) + x;
            addbullet(, 856, v991, v990, v988, 1, (int)&v1534, 3);
            */
          }
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              CharFrameData *frm = get_pframe();
              scene_add_effect(this, 115, (double)(frm->extra1[4] * (char)dir) + x, y - (double)frm->extra1[5], dir, 1);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            {
              play_sfx(107);
              /*
              *(float *)&v1540 = 0.0;
              v1541 = 0.0;
              v1542 = 0.0;
              v997 = dir;
              v998 = get_pframe();
              v999 = y - (double)v998->extra1[5];
              v1000 = v999;
              v1001 = (double)(v998->extra1[4] * (char)v997) + x;
              addbullet(, 856, v1001, v1000, v997, 1, (int)&v1540, 3);
              */
            }
          }
          return;
        case 607:
          sub10func();
          if ( get_subseq() < 4 )
            sub_46AB50(0, 2);
          if ( get_subseq() == 3 && get_elaps_frames() >= 90 )
            goto LABEL_965;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              scene_add_effect(this, 115, (double)(17 * (char)dir) + x, y + 297.0, dir, 1);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
            {
                /*
              *(float *)&v1546 = 0.0;
              v1547 = 0.0;
              v1548 = 8.0;
              v1006 = dir;
              v1007 = (double)(82 * (char)v1006) + x;
              addbullet(, 857, v1007, y, v1006, 1, (int)&v1546, 3);
              */
            }
          }
          return;
        case 608:
          sub10func();
          sub_46AB50(0, 2);
          if ( get_subseq() != 1 )
            goto LABEL_3217;
          if ( field_190 )
          {
            if ( ++field_7D0 >= 5 )
            {
              field_7D0 = 0;
              field_190 = 0;
              field_194 = 1;
            }
          }
          if ( get_elaps_frames() < 6 )
          {
LABEL_3217:
            if ( get_subseq() == 2 )
            {
              h_inerc = h_inerc - 0.1000000014901161;
              if ( h_inerc - 0.1000000014901161 < 0.0 )
                h_inerc = 0.0;
            }
            if ( get_subseq() != 3 )
              goto LABEL_3218;
            h_inerc = h_inerc - 0.5;
            if ( h_inerc - 0.5 < -3.0 )
              h_inerc = -3.0;
            if ( get_elaps_frames() < 45 )
            {
LABEL_3218:
              if ( get_subseq() == 4 )
              {
                h_inerc = h_inerc + 0.1000000014901161;
                if ( h_inerc + 0.1000000014901161 > 0.0 )
                  h_inerc = h_inerc + 0.1000000014901161;
              }
              if ( process() )
                set_seq(0);
              if ( !get_subseq() && !get_frame_time() )
              {
                if ( get_frame() == 3 )
                {
                  sub_4834E0(40);
                  scene_play_sfx(23);
                  sub_469450(0, 0, 60);
                  sub_483570();
                  weather_forecast_next();
                  scene_add_effect(this, 115, (double)(3 * (char)dir) + x, y + 120.0, dir, 1);
                }
                if ( !get_frame_time() && get_frame() == 15 )
                {
                  play_sfx(42);
                  h_inerc = 17.5;
                }
              }
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                /*
                *(float *)&v1552 = 0.0;
                v1553 = 0.0;
                v1554 = 0.0;
                addbullet(, 858, x, y, dir, 1, (int)&v1552, 3);
                */
              }
              if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 2 )
              {
                play_sfx(110);
                /*
                *(float *)&v1558 = 0.0;
                v1559 = 15.0;
                v1560 = 3.0;
                v1017 = dir;
                v1018 = get_pframe();
                v1019 = y - (double)v1018->extra1[5];
                v1020 = v1019;
                v1021 = (double)(v1018->extra1[4] * (char)v1017) + x;
                addbullet(, 858, v1021, v1020, v1017, 1, (int)&v1558, 3);
                */
              }
            }
            else
            {
LABEL_2592:
              next_subseq();
            }
          }
          else
          {
            h_inerc = h_inerc * 0.5;
            next_subseq();
          }
          return;
        case 609:
          if ( get_subseq() == 4 )
          {
            sub10func();
            h_inerc = h_inerc - 2.0;
            if ( h_inerc - 2.0 < 0.0 )
              h_inerc = 0.0;
          }
          else if (get_subseq() >= 1 )
          {
            sub_46AB50(0, 2);
          }
          if ( !get_subseq() )
            v_inerc = v_inerc - v_force;
          if ( get_subseq() != 2 && get_subseq() != 3 )
            goto LABEL_2632;
          if ( char_on_ground_down() )
            goto LABEL_2624;
          if ( field_190 )
          {
            if ( field_190 != 3 && field_194 > 0 && ++field_7D0 >= 2 )
            {
              field_7D0 = 0;
              field_190 = 0;
            }
          }
          h_inerc = field_7DC * 18.0;
          v_inerc = field_7DC * -10.0;
          field_7DC = field_7DC + 0.2000000029802322;
          if ( field_7DC + 0.2000000029802322 > 1.0 )
            field_7DC = 1.0;
LABEL_2632:
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 2 )
            {
              v_inerc = 13.5;
              v_force = 0.30000001;
            /*
              v1331 = 0.0;
              do
              {
                *(float *)&v1492 = (double)(unsigned int)get_MT_range(10) + v1331 * 24.0;
                v1493 = (double)(unsigned int)get_MT_range(4) + 12.5;
                v1494 = 3.0;
                v1027 = -*(float *)&v1492;
                v1028 = sin_deg(v1027) > 0.0;
                addbullet(, 859, x, y, dir, (1 - 2 * v1028), (int)&v1492, 3);
                v1331 = v1331 + 1.0;
              }
              while ( v1331 < 15.0 );
              */
            }
            if ( !get_frame_time() )
            {
              if ( get_frame() == 3 )
              {
                sub_469450(0, 0, 60);
                sub_483570();
              }
              if ( !get_frame_time() && get_frame() == 5 )
                field_190 = 0;
            }
          }
          if ( get_elaps_frames() )
            goto LABEL_2655;
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            weather_forecast_next();
            scene_add_effect(this, 115, (double)(6 * (char)dir) + x, y + 135.0, dir, 1);
            reset_forces();
            field_190 = 0;
            field_194 = 7;
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
            goto LABEL_2655;
          if ( get_subseq() == 2 )
          {
            play_sfx(111);
LABEL_2655:
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
            {
                /*
              *(float *)&v1414 = 0.0;
              v1415 = 0.0;
              v1416 = 0.0;
              addbullet(, 859, x, y, dir, 1, (int)&v1414, 3);
              v1416 = 1.0;
              addbullet(, 859, x, y, dir, -1, (int)&v1414, 3);
              v1416 = 2.0;
              addbullet(, 859, x, y, dir, -1, (int)&v1414, 3);
              */
            }
          }
          return;
        case 610:
          sub_46AB50(0, 2);
          if (get_subseq() >= 3 || get_subseq() <= 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              y = getlvl_height();
              reset_forces();
              set_seq(9);
              return;
            }
          }
          if ( get_subseq() != 1 )
            goto LABEL_2752;
          h_inerc = h_inerc + 3.0;
          if ( h_inerc + 3.0 > 75.0 )
            h_inerc = 75.0;
          field_571 = 0;
          field_572 = 0;
          if ( dir * get_border_near() >= 0 )
          {
            v_inerc = 0.0;
          }
          else
          {
            field_51C = 2;
            field_520 = 2;
            if ( x > 2280.0 && dir > 0 || x < -800.0 && dir < 0 )
            {
              if ( field_7D0 >= 3 )
              {
                next_subseq();
                v_inerc = 1.0;
                h_inerc = -h_inerc * 0.25;
                return;
              }
              play_sfx(112);
              ++field_7D0;
              field_194 = 4;
              field_190 = 0;
              dir = -dir;
            }
            if ( field_7D0 < 4 )
            {
              if ( enemy->y - y <= 50.0 )
                v_inerc = enemy->y - y >= -50.0 ? 0.0 : -10.0;
              else
                v_inerc = 10.0;
              if ( y > 480.0 && v_inerc > 0.0 )
                v_inerc = 0.0;
            }
          }
          if ( field_190 )
          {
            if ( field_190 != 3 && ++field_7D4 >= 2 )
            {
              field_7D4 = 0;
              field_190 = 0;
            }
          }
LABEL_2752:
          if ( get_subseq() != 2 )
            goto LABEL_2758;
          if ( dir * get_border_near() >= 0 )
          {
            v_force = 0.25;
            v_inerc = v_inerc - 0.25;
            if ( v_inerc - 0.25 < 1.0 )
              v_inerc = 1.0;
            h_inerc = h_inerc * 0.949999988079071;
            field_571 = 1;
            field_572 = 1;
            if ( ++field_7D2 >= 20 )
              goto LABEL_965;
          }
          else
          {
            field_51C = 2;
            field_520 = 2;
          }
LABEL_2758:
          if ( get_subseq() == 3 || get_subseq() == 4 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              reset_forces();
              set_seq(10);
              goto LABEL_1164;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 1 )
            {
                /*
              *(float *)&v1564 = 0.0;
              v1565 = 0.0;
              v1566 = 5.0;
              v1059 = y + 120.0;
              addbullet(, 860, x, v1059, dir, 1, (int)&v1564, 3);
              */
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 120.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() && get_frame() == 3 )
              h_inerc = 3.0;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            play_sfx(112);
            /*
            *(float *)&v1363 = 90.0;
            v1364 = 0.0;
            v1365 = 0.0;
            v1061 = y + 100.0;
            addbullet(, 860, x, v1061, dir, 1, (int)&v1363, 3);
            *(float *)&v1363 = -90.0;
            v1364 = 0.0;
            v1365 = 0.0;
            v1062 = y + 100.0;
            addbullet(, 860, x, v1062, dir, 1, (int)&v1363, 3);
            *(float *)&v1363 = 0.0;
            v1364 = 0.0;
            v1365 = 3.0;
            v1063 = y + 100.0;
            addbullet(, 860, x, v1063, dir, 1, (int)&v1363, 3);
            v1365 = 4.0;
            v1064 = y + 100.0;
            addbullet(, 860, x, v1064, dir, 1, (int)&v1363, 3);
            */
          }
          return;
        case 611:
          sub10func();
          sub_46AB50(0, 2);
          if ( get_subseq() == 1 && get_elaps_frames() >= 20 )
            goto LABEL_1450;
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, x - 0.0, y + 110.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            /*
            *(float *)&v1570 = 0.0;
            v1571 = 25.0;
            v1572 = 0.0;
            v1068 = y + 150.0;
            v1069 = v1068;
            v1070 = x + 0.0;
            addbullet(, 861, v1070, v1069, dir, -1, (int)&v1570, 3);
            */
            play_sfx(113);
          }
          return;
        case 612:
          sub10func();
          sub_46AB50(0, 2);
          if ( process() )
            set_seq(0);
          if ( get_subseq() || get_frame_time() )
            return;
          if ( get_frame() == 4 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, x, y + 111.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( get_frame_time() || get_frame() != 7 )
            return;
          play_sfx(114);
          /*
          v1072 = 0.0;
          *(float *)&v1576 = 0.0;
          v1073 = &v1576;
          v1577 = 0.0;
          v1578 = 5.0;
          */
          //goto LABEL_2798;
          return; //TODO: change!
        case 613:
          sub10func();
          sub_46AB50(0, 2);
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, (double)(3 * (char)dir) + x, y + 120.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( get_subseq() == 2 && !get_frame_time() && !get_frame() )
          {
            /*
            *(float *)&v1588 = 0.0;
            v1589 = 10.0;
            v1590 = 0.0;
            v1081 = dir;
            v1082 = y + 136.0;
            v1083 = v1082;
            v1084 = (double)(20 * (char)v1081) + x;
            addbullet(, 863, v1084, v1083, v1081, 1, (int)&v1588, 3);
            */
LABEL_2403:
            //shake_camera(5.0);
            return;
          }
          return;
        case 614:
          sub_46AB50(0, 2);
          if ( !get_subseq() )
            sub10func();
          if ( get_subseq() == 5 || get_subseq() == 6 )
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_255:
              reset_forces();
              y = getlvl_height();
              set_seq(10);
              return;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            /*
            v1086 = dir;
            v1087 = get_pframe();
            v1088 = y - (double)v1087->extra1[5];
            v1089 = v1088;
            v1090 = (double)(v1087->extra1[4] * (char)v1086) + x;
            scene_add_effect(this, 115, v1090, v1089, v1086, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
            *(float *)&v1594 = 0.0;
            v1595 = 0.0;
            v1596 = 4.0;
            v1091 = y + 100.0;
            addbullet(, 864, x, v1091, dir, -1, (int)&v1594, 3);
            */
          }
          if ( get_elaps_frames() )
            goto LABEL_2839;
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
LABEL_464:
            set_seq(0);
            return;
          }
          if ( !get_frame_time() && !get_frame() && get_subseq() == 2 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            /*
            v1092 = dir;
            v1093 = get_pframe();
            v1094 = y - (double)v1093->extra1[5];
            v1095 = v1094;
            v1096 = (double)(v1093->extra1[4] * (char)v1092) + x;
            scene_add_effect(this, 115, v1096, v1095, v1092, 1);
            *(float *)&v1600 = 0.0;
            v1601 = 2.0;
            v1602 = 3.0;
            v1097 = y + 100.0;
            addbullet(, 864, x, v1097, dir, -1, (int)&v1600, 3);
            */
          }
LABEL_2839:
          if ( get_subseq() == 2 && get_elaps_frames() >= 60 )
          {
LABEL_1450:
            next_subseq();
            return;
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
          {
            /*
            *(float *)&v1482 = 0.0;
            v1483 = 0.0;
            v1484 = 0.0;
            v1099 = dir;
            v1100 = get_pframe();
            v1101 = y - (double)v1100->extra1[5];
            v1102 = v1101;
            v1103 = (double)(v1100->extra1[4] * (char)v1099) + x;
            addbullet(, 864, v1103, v1102, v1099, -1, (int)&v1482, 3);
            v1484 = 10.0;
            v1104 = dir;
            v1105 = get_pframe();
            v1106 = y - (double)v1105->extra1[5];
            v1107 = v1106;
            v1108 = (double)(v1105->extra1[4] * (char)v1104) + x;
            addbullet(, 864, v1108, v1107, v1104, -1, (int)&v1482, 3);
            */
            play_sfx(116);
          }
          if ( get_subseq() == 4 )
          {
            field_8A4 -= 5;
            if ( field_8A4 - 5 < 0 )
              field_8A4 = 0;
            if ( get_elaps_frames() >= 150 )
              goto LABEL_965;
          }
          if ( get_subseq() == 5 && !get_frame_time() && get_frame() == 7 )
            v_force = 0.30000001;
          return;
        case 616:
          if ( field_8A0 )
            field_8A0 = 600;
          sub10func();
          sub_46AB50(0, 2);
          if ( get_subseq() == 1 && get_elaps_frames() >= 20 )
            goto LABEL_965;
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            sub_4834E0(40);
            scene_play_sfx(23);
            scene_add_effect(this, 115, x - 0.0, y + 110.0, dir, 1);
            sub_469450(0, 0, 60);
            sub_483570();
            weather_forecast_next();
          }
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            play_sfx(16);
            /*
            *(float *)&v1606 = 0.0;
            v1607 = 25.0;
            v1608 = 0.0;
            v1112 = y + 150.0;
            v1113 = v1112;
            v1114 = x + 0.0;
            addbullet(, 866, v1114, v1113, dir, -1, (int)&v1606, 3);
            */
            field_8A0 = 600;
          }
          return;
        case 650:
          if ( get_subseq() == 3 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              set_subseq(3);
              goto LABEL_1163;
            }
          }
          sub_46AB50(0, 2);
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
              set_seq(9);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              sub_4834E0(60);
              scene_play_sfx(23);
              scene_add_effect(this, 115, (double)(3 * (char)dir) + x, y + 120.0,dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              /*
              *(float *)&v1346 = 0.0;
              v1347 = 1.0;
              v1348 = 3.0;
              v1349 = 60.0;
              addbullet(, 970, 0.0, 64.0, 1, 1, (int)&v1346, 4);
              v1348 = 2.0;
              addbullet(, 970, 0.0, 64.0, 1, 1, (int)&v1346, 4);
              v1348 = 3.0;
              addbullet(, 970, 0.0, 416.0, 1, 1, (int)&v1346, 4);
              v1348 = 2.0;
              addbullet(, 970, 0.0, 416.0, 1, 1, (int)&v1346, 4);
              *(float *)&v1346 = 240.0;
              v1347 = 1.0;
              v1348 = 5.0;
              addbullet(, 970, 320.0, 242.0, 1, 1, (int)&v1346, 4);
              v1348 = 4.0;
              addbullet(, 970, 320.0, 240.0, 1, 1, (int)&v1346, 4);
              v1348 = 5.0;
              addbullet(, 970, 0.0, 242.0, 1, 1, (int)&v1346, 4);
              v1348 = 4.0;
              addbullet(, 970, 0.0, 240.0, 1, 1, (int)&v1346, 4);
              v1348 = 5.0;
              addbullet(, 970, 640.0, 242.0, 1, 1, (int)&v1346, 4);
              v1348 = 4.0;
              addbullet(, 970, 640.0, 240.0, 1, 1, (int)&v1346, 4);
              v1348 = 5.0;
              addbullet(, 970, 960.0, 242.0, 1, 1, (int)&v1346, 4);
              v1348 = 4.0;
              addbullet(, 970, 960.0, 240.0, 1, 1, (int)&v1346, 4);
              v1349 = 120.0;
              v1348 = 6.0;
              addbullet(, 970, 960.0, 240.0, 1, 1, (int)&v1346, 4);
              */
            }
          }
          if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
          {
            /*
            *(float *)&v1485 = 45.0;
            v1486 = 0.0;
            v1487 = 7.0;
            v877 = dir;
            v878 = y + 108.0;
            v879 = v878;
            v880 = (double)(51 * (char)v877) + x;
            addbullet(, 850, v880, v879, v877, 1, (int)&v1485, 3);
            v1487 = 6.0;
            v881 = dir;
            v882 = y + 108.0;
            v883 = v882;
            v884 = (double)(51 * (char)v881) + x;
            addbullet(, 850, v884, v883, v881, 1, (int)&v1485, 3);
            */
            play_sfx(100);
            //shake_camera(5.0);
            h_inerc = -5.0;
            v_inerc = 12.5;
            v_force = 0.30000001;
          }
          return;
        case 653:
          sub_46AB50(0, 2);
          if ( get_subseq() == 4 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
              y = getlvl_height();
              reset_forces();
              set_subseq(4);
              return;
            }
          }
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 4 )
              set_seq(9);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              /*
              v941 = dir;
              v942 = get_pframe();
              v943 = y - (double)v942->extra1[5];
              v944 = v943;
              v945 = (double)(v942->extra1[4] * (char)v941) + x;
              scene_add_effect(this, 115, v945, v944, v941, 1);
              *(float *)&v1504 = 0.0;
              v1505 = 0.0;
              v1506 = 0.0;
              v946 = dir;
              v947 = y + 320.0;
              v948 = v947;
              v949 = (double)(40 * (char)v946) + x;
              addbullet(, 853, v949, v948, v946, 1, (int)&v1504, 3);
              */
            }
          }
          if ( get_subseq() == 3 && !get_frame_time() )
          {
            if ( get_frame() == 2 )
              play_sfx(103);
LABEL_1066:
            if ( !get_frame_time() )
            {
              v306 = get_frame() == 10;
LABEL_1068:
              if ( v306)
                v_force = 0.5;
            }
          }
          return;
        case 655:
          if ( get_subseq() == 4 )
          {
            sub10func();
          }
          else
          {
            v_inerc = v_inerc - v_force;
            if ( char_on_ground_down() )
            {
LABEL_2349:
              y = getlvl_height();
              reset_forces();
              set_subseq(4);
              return;
            }
          }
          sub_46AB50(0, 2);
          if ( get_subseq() == 2 && get_elaps_frames() >= 120 )
            goto LABEL_965;
          if ( process() )
            set_seq(0);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
              /*
              v974 = dir;
              v975 = get_pframe();
              v976 = y - (double)v975->extra1[5];
              v977 = v976;
              v978 = (double)(v975->extra1[4] * (char)v974) + x;
              scene_add_effect(this, 115, v978, v977, v974, 1);
              *(float *)&v1522 = 0.0;
              v1523 = 0.0;
              v1524 = 4.0;
              v979 = dir;
              v980 = y + 220.0;
              v981 = v980;
              v982 = (double)(40 * (char)v979) + x;
              addbullet(, 855, v982, v981, v979, 1, (int)&v1522, 3);
              */
              play_sfx(105);
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
            {
                /*
              *(float *)&v1528 = 0.0;
              v1529 = 0.40000001;
              v1530 = 0.0;
              v983 = dir;
              v984 = get_pframe();
              v985 = y - (double)v984->extra1[5];
              v986 = v985;
              v987 = (double)(v984->extra1[4] * (char)v983) + x;
              addbullet(, 855, v987, v986, v983, 1, (int)&v1528, 3);
              */
            }
          }
          if ( get_subseq() == 3 && !get_frame_time() )
          {
            v848 = get_frame() == 10;
LABEL_2341:
            if ( get_frame() == v848 )
              v_force = 0.5;
          }
LABEL_2343:
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
            set_seq(9);
          return;
        case 658:
          if ( get_subseq() == 5 )
            sub10func();
          else
            sub_46AB50(0, 2);
          if ( field_7D0 > 0 )
          {
            if ( get_subseq() <= 3 && field_7D0 % 4 == 1 )
            {
              play_sfx(19);
              /*
              *(float *)&v1758 = 40.0 - 20.0;
              v1759 = 10.0;
              v1760 = (double)(unsigned int)get_MT_range(4);
              v1761 = 0.0;
              v1034 = dir;
              v1035 = y + 107.0;
              v1036 = v1035;
              v1037 = (double)(25 * (char)v1034) + x;
              addbullet(, 859, v1037, v1036, v1034, 1, (int)&v1758, 4);
              */
            }
            ++field_7D0;
          }
          if ( get_subseq() == 1 && get_elaps_frames() > 40 || get_subseq() == 3 && get_elaps_frames() > 40 )
            goto LABEL_1450;
          if ( get_subseq() == 4 && (v_inerc = v_inerc - v_force, char_on_ground_down()) )
          {
            set_subseq(5);
LABEL_1163:
            reset_forces();
LABEL_1164:
            y = getlvl_height();
          }
          else
          {
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() )
            {
              if ( !get_frame_time() && !get_frame() && get_subseq() == 5 )
              {
LABEL_1116:
                set_seq(9);
                return;
              }
              if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
              {
                sub_4834E0(40);
                scene_play_sfx(23);
                scene_add_effect(this, 115, x - (double)(23 * (char)dir), y + 106.0, dir, 1);
                sub_469450(0, 0, 60);
                sub_483570();
                weather_forecast_next();
              }
            }
            if ( get_subseq() == 2 && get_frame() == 2 && !get_frame_time() )
              field_7D0 = 1;
            if ( get_subseq() == 4 && !get_frame_time() && get_frame() == 5 )
              v_force = 0.30000001;
          }
          return;
        case 659:
          if ( get_subseq() == 4 )
          {
            sub10func();
            h_inerc = h_inerc - 2.0;
            if ( h_inerc - 2.0 < 0.0 )
              h_inerc = 0.0;
          }
          else if ( get_subseq() >= 1 )
          {
            sub_46AB50(0, 2);
          }
          if ( get_subseq() != 2 && get_subseq() != 3 )
            goto LABEL_2707;
          if ( char_on_ground_down() )
          {
LABEL_2624:
            set_subseq(4);
            y = getlvl_height();
            v_inerc = 0.0;
            v_force = 0.0;
            return;
          }
          if ( field_190 )
          {
            if ( field_190 != 3 && field_194 > 0 && ++field_7D0 >= 2 )
            {
              field_7D0 = 0;
              field_190 = 0;
            }
          }
          h_inerc = field_7DC * 18.0;
          v_inerc = field_7DC * -10.0;
          field_7DC = field_7DC + 0.2000000029802322;
          if ( field_7DC + 0.2000000029802322 > 1.0 )
            field_7DC = 1.0;
LABEL_2707:
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() )
            goto LABEL_2719;
          if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            sub_469450(0, 0, 60);
            sub_483570();
            sub_4834E0(40);
            scene_play_sfx(23);
            weather_forecast_next();
            scene_add_effect(this, 115, (double)(6 * (char)dir) + x, y + 135.0, dir, 1);
            reset_forces();
            field_190 = 0;
            field_194 = 7;
          }
          if ( get_elaps_frames() || get_frame_time() || get_frame() )
            goto LABEL_2719;
          if ( get_subseq() == 2 )
          {
            play_sfx(111);
LABEL_2719:
            if ( get_subseq() == 2 && !get_frame_time() && get_frame() == 1 )
            {
                /*
              *(float *)&v1420 = 0.0;
              v1421 = 0.0;
              v1422 = 0.0;
              addbullet(, 859, x, y, dir, 1, (int)&v1420, 3);
              v1422 = 1.0;
              addbullet(, 859, x, y, dir, -1, (int)&v1420, 3);
              v1422 = 2.0;
              addbullet(, 859, x, y, dir, -1, (int)&v1420, 3);
              */
            }
          }
          return;
        case 662:
          sub_46AB50(0, 2);
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down())
            goto LABEL_1437;
          if ( process() )
            set_seq(9);
          if ( !get_subseq() && !get_frame_time() )
          {
            if ( get_frame() == 5 )
            {
              sub_4834E0(40);
              scene_play_sfx(23);
              scene_add_effect(this, 115, x, y + 111.0, dir, 1);
              sub_469450(0, 0, 60);
              sub_483570();
              weather_forecast_next();
            }
            if ( !get_frame_time() && get_frame() == 8 )
            {
            /*
              play_sfx(114);
              v1072 = 0.0;
              v1582 = 0.0;
              v1073 = (int *)&v1582;
              v1583 = 0.0;
              v1584 = 5.0;
LABEL_2798:
              v1074 = v1072;
              addbullet(, 862, 640.0, v1074, dir, -1, (int)v1073, 3);
              */
            }
          }
          return;
        case 695:
          sub10func();
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 4 )
          {
            scene_play_sfx(55);
            scene_add_effect(this, 140, x, y + 100.0, dir, 1);
            scene_add_effect(this, 140, x, y + 100.0, dir, 1);
            scene_add_effect(this, 140, x, y + 100.0, dir, 1);
            scene_add_effect(this, 141, x, y + 100.0, dir, -1);
            scene_add_effect(this, 142, x, y, dir, -1);
          }
          return;
        case 696:
          sub10func();
          if ( get_frame() > 5 )
          {
            h_inerc = h_inerc - 3.0;
            if ( h_inerc - 3.0 < 0.0 )
              h_inerc = 0.0;
          }
          if ( process() )
            set_seq(0);
          if ( !get_frame_time() )
          {
            if ( get_frame() == 4 )
            {
                /*
              h_inerc = 15.0;
              *(float *)&v1612 = 0.0;
              v1613 = 0.0;
              v1614 = 0.0;
              addbullet(, 848, x, y, dir, 1, (int)&v1612, 3);
              */
            }
            if ( !get_frame_time() && get_frame() == 5 )
            {
              scene_play_sfx(29);
              field_49A = 0;
            }
          }
          return;
        case 707:
          sub10func();
          if ( h_inerc > 12.0 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc - 0.5 < 12.0 )
              h_inerc = 12.0;
          }
          if ( process() )
            goto LABEL_3165;
          if ( !get_subseq() && !get_frame_time() && get_frame() == 3 )
          {
            h_inerc = 15.0;
            scene_add_effect(this, 125, (double)(80 * (char)dir) + x, y + 80.0, dir, 1);
            scene_add_effect(this, 126, x, y + 80.0, dir, 1);
            scene_play_sfx(31);
          }
          if ( get_subseq() == 1 )
          {
            if ( !(get_elaps_frames() % 5) )
            {
              scene_add_effect(this, 124, x + 50.0 - x - (scene_rand() % 100) + 50.0, (scene_rand() % 200) + y, dir, 1);
            }
            if ( get_elaps_frames() > 30 )
              goto LABEL_965;
          }
          if ( get_subseq() == 2 )
          {
            h_inerc = h_inerc - 0.5;
            if ( h_inerc - 0.5 < 0.0 )
              h_inerc = 0.0;
          }
          return;
        case 708:
          if ( !get_subseq() || get_subseq() == 2 )
          {
            sub10func();
            
          }
          if ( get_subseq() == 2 )
          {
            h_inerc = h_inerc + 2.0;
            if ( h_inerc + 2.0 > 0.0 )
              h_inerc = 0.0;
          }
          if ( char_on_ground_flag() )
            goto LABEL_3219;
          if ( !(get_elaps_frames() % 5) )
          {
            scene_add_effect(this, 124, x - (scene_rand() % 100) + 50.0, (scene_rand() % 200) + y, -dir, 1);
          }
          v_inerc = v_inerc - 0.5;
          if ( getlvl_height() < v_inerc - 0.5 + y|| v_inerc >= 0.0 )
          {
LABEL_3219:
            if ( process() )
            {
LABEL_3165:
              set_seq(700);
            }
            else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              h_inerc = -14.0;
              v_inerc = 4.0;
              scene_add_effect(this, 125, x, y + 80.0, -dir, 1);
              scene_add_effect(this, 126, x, y + 80.0, -dir, 1);
              scene_play_sfx(31);
            }
          }
          else
          {
            v_inerc = 0.0;
            y = getlvl_height();
            set_subseq(2);
          }
          return;
        case 710:
          sub10func();
          if ( get_subseq() == 1 )
          {
            if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
            {
                /*
              *(float *)&v1432 = 360.0;
              v1433 = (double)(unsigned int)get_MT_range(400) + 200.0;
              v1434 = (double)(unsigned int)get_MT_range(2);
              v1143 = dir;
              v1144 = -*(float *)&v1432;
              v1145 = sin_deg(v1144);
              v1146 = v1145 * v1433 + y - (double)get_pframe()->extra1[5];
              v1147 = v1146;
              v1148 = -*(float *)&v1432;
              v1149 = cos_deg(v1148);
              v1150 = (v1149 * v1433 + (double)get_pframe()->extra1[4]) * (double)dir + x;
              addbullet(, 970, v1150, v1147, v1143, 1, (int)&v1432, 3);
              */
            }
            if ( !(get_elaps_frames() % 4) )
            {
              /*
              v1152 = get_elaps_frames() & 0x80000007;
              v1151 = v1152 == 0;
              if ( v1152 < 0 )
                v1151 = (((_BYTE)v1152 - 1) | 0xFFFFFFF8) == -1;
             */
              if (get_elaps_frames() & 0x80000007 == 0)
                play_sfx(1);
              //v1332 = 0.0;
              if ( field_7DC > 0.0 )
              {
                /*
                v1153 = v1332;
                do
                {
                  *(float *)&v1442 = v1153 * 360.0 / field_7DC + dash_angle;
                  v1443 = 10.0;
                  v1444 = 5.0;
                  v1445 = 3.0;
                  v1154 = dir;
                  v1155 = get_pframe();
                  v1156 = y - (double)v1155->extra1[5];
                  v1157 = v1156;
                  v1158 = (double)(v1155->extra1[4] * (char)v1154) + x;
                  addbullet(, 900, v1158, v1157, v1154, 1, (int)&v1442, 4);
                  v1332 = v1332 + 1.0;
                  v1153 = v1332;
                }
                while ( field_7DC > (double)v1332 );
                */
              }
              //v1333 = 0.0;
              if ( field_7DC > 0.0 )
              {
                /*
                v1159 = v1333;
                do
                {
                  *(float *)&v1442 = v1159 * 360.0 / field_7DC + dash_angle;
                  v1443 = 10.0;
                  v1444 = 5.0;
                  v1445 = -3.0;
                  v1160 = dir;
                  v1161 = get_pframe();
                  v1162 = y - (double)v1161->extra1[5];
                  v1163 = v1162;
                  v1164 = (double)(v1161->extra1[4] * (char)v1160) + x;
                  addbullet(, 900, v1164, v1163, v1160, 1, (int)&v1442, 4);
                  v1333 = v1333 + 1.0;
                  v1159 = v1333;
                }
                while ( field_7DC > (double)v1333 );
                */
              }
            }
            if ( get_elaps_frames() >= field_7D0 )
            {
                /*
              *(float *)&v1618 = 0.0;
              v1619 = 0.40000001;
              v1620 = 3.0;
              v1165 = dir;
              v1166 = get_pframe();
              v1167 = y - (double)v1166->extra1[5];
              v1168 = v1167;
              v1169 = (double)(v1166->extra1[4] * (char)v1165) + x;
              addbullet(, 900, v1169, v1168, v1165, 1, (int)&v1618, 3);
              */
              next_subseq();
              play_sfx(8);
              return;
            }
          }
          if ( get_subseq() != 3 )
            goto LABEL_3220;
          if ( !(get_elaps_frames() % 4) )
        {
            /*
            v1171 = get_elaps_frames() & 0x80000007;
            v1170 = v1171 == 0;
            if ( v1171 < 0 )
              v1170 = (((_BYTE)v1171 - 1) | 0xFFFFFFF8) == -1;
          */
            if (get_elaps_frames() & 0x80000007 == 0)
              play_sfx(40);
            /*
            v1334 = 0.0;
            if ( field_7DC > 0.0 )
            {
              v1172 = v1334;
              do
              {
                *(float *)&v1438 = v1172 * 360.0 / field_7DC + dash_angle;
                v1439 = 10.0;
                v1440 = 0.0;
                v1441 = 3.0;
                v1173 = dir;
                v1174 = get_pframe();
                v1175 = y - (double)v1174->extra1[5];
                v1176 = v1175;
                v1177 = (double)(v1174->extra1[4] * (char)v1173) + x;
                addbullet(, 900, v1177, v1176, v1173, 1, (int)&v1438, 4);
                v1334 = v1334 + 1.0;
                v1172 = v1334;
              }
              while ( field_7DC > (double)v1334 );
            }
            v1335 = 0.0;
            if ( field_7DC > 0.0 )
            {
              v1178 = v1335;
              do
              {
                *(float *)&v1438 = v1178 * 360.0 / field_7DC + dash_angle;
                v1439 = 10.0;
                v1440 = 0.0;
                v1441 = -3.0;
                v1179 = dir;
                v1180 = get_pframe();
                v1181 = y - (double)v1180->extra1[5];
                v1182 = v1181;
                v1183 = (double)(v1180->extra1[4] * (char)v1179) + x;
                addbullet(, 900, v1183, v1182, v1179, 1, (int)&v1438, 4);
                v1335 = v1335 + 1.0;
                v1178 = v1335;
              }
              while ( field_7DC > (double)v1335 );
            }
            */
        }
          if ( get_elaps_frames() < field_7D2 )
          {
LABEL_3220:
            if ( process() )
              set_seq(0);
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
                /*
              *(float *)&v1630 = 0.0;
              v1631 = 0.0;
              v1632 = 2.0;
              v1189 = dir;
              v1190 = get_pframe();
              v1191 = y - (double)v1190->extra1[5];
              v1192 = v1191;
              v1193 = (double)(v1190->extra1[4] * (char)v1189) + x;
              addbullet(, 900, v1193, v1192, v1189, 1, (int)&v1630, 3);
              */
              switch (settings_get()->get_difficulty())
              {
                // is in reverse order?
                case GAME_DIFF_LUNA:
                  field_7D0 = 180;
                  field_7D2 = 120;
                  field_7DC = 4.0;
                  dash_angle = 360.0;
                  field_7E4 = 0.0;
                  break;
                case GAME_DIFF_HARD:
                  field_7D0 = 180;
                  field_7D2 = 120;
                  field_7DC = 6.0;
                  dash_angle = 360.0;
                  field_7E4 = 10.0;
                  break;
                case GAME_DIFF_NORMAL:
                  field_7D0 = 180;
                  field_7D2 = 120;
                  field_7DC = 6.0;
                  dash_angle = 360.0;
                  field_7E4 = 30.0;
                  break;
                case GAME_DIFF_EASY:
                  field_7D0 = 180;
                  field_7D2 = 120;
                  field_7DC = 8.0;
                  dash_angle = 360.0;
                  field_7E4 = 60.0;
                  break;
                default:
                  return;
              }
            }
          }
          else
          {
            /*
            v1336 = 0.0;
            if ( field_7E4 <= 0.0 )
              goto LABEL_965;
            do
            {
              *(float *)&v1624 = 360.0;
              v1625 = 40.0 * 0.1000000014901161 + 3.0;
              v1626 = 4.0;
              v1184 = dir;
              v1185 = get_pframe();
              v1186 = y - (double)v1185->extra1[5];
              v1187 = v1186;
              v1188 = (double)(v1185->extra1[4] * (char)v1184) + x;
              addbullet(, 900, v1188, v1187, v1184, 1, (int)&v1624, 3);
              v1336 = v1336 + 1.0;
            }
            while ( field_7E4 > (double)v1336 );
            */
            next_subseq();
          }
          return;
        case 720:
          //v1194 = 0.9800000190734863;
          if ( !get_subseq() )
          {
            h_inerc = h_inerc * 0.9800000190734863;
            v_inerc = v_inerc * 0.9800000190734863;
          }
          if ( get_subseq() != 1 )
            goto LABEL_2971;
          h_inerc = h_inerc * 0.9800000190734863;
          v_inerc = v_inerc * 0.9800000190734863;
          field_7D0 = field_7D0;
          
          if ( get_elaps_frames() >= field_7D0 )
          {
            next_subseq();
            return;
          }
          if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
          {
            /*
            *(float *)&v1426 = 360.0;
            v1427 = (double)(unsigned int)get_MT_range(400) + 200.0;
            v1428 = (double)(unsigned int)get_MT_range(2);
            v1197 = dir;
            v1198 = -*(float *)&v1426;
            v1199 = sin_deg(v1198);
            v1200 = v1199 * v1427 + y - (double)get_pframe()->extra1[5];
            v1201 = v1200;
            v1202 = -*(float *)&v1426;
            v1203 = cos_deg(v1202);
            v1204 = (v1203 * v1427 + (double)get_pframe()->extra1[4]) * (double)dir + x;
            addbullet(, 970, v1204, v1201, v1197, 1, (int)&v1426, 3);
            
            v1194 = 0.9800000190734863;
            */
          }
LABEL_2971:
          if ( get_subseq() < 4 || get_subseq() > 6 )
            goto LABEL_2995;
          if ( get_subseq() != 4 )
            goto LABEL_2978;
          if ( dir * get_border_near() >= 0 )
          {
            field_571 = 1;
            field_572 = 1;
            if ( get_elaps_frames() >= 30 )
              goto LABEL_965;
          }
          else
          {
            field_51C = 2;
            field_520 = 2;
            
          }
          //v1194 = 0.9800000190734863;
          
LABEL_2978:
          if ( get_subseq() >= 5 )
          {
            h_inerc = h_inerc * 0.9800000190734863;//v1194;
            v_inerc = /*v1194*/ 0.9800000190734863 * v_inerc;
          }
          if ( y > 480.0 && 0.0 < v_inerc )
            v_inerc = -v_inerc;
          if ( char_on_ground_down() )
            v_inerc = v_inerc * -0.5;
          if ( dir * get_border_near() > 0 && h_inerc < 0.0 )
            h_inerc = -h_inerc;
          if ( dir * get_border_near() < 0 && h_inerc > 0.0 )
            h_inerc = -h_inerc;
          if ( get_subseq() == 6 && get_elaps_frames() >= 90 && enemy->health > 0 )
          {
            field_7E4 = 0.0;
            field_7D8 = 0;
            set_subseq(0);
            flip_with_force();
            return;
          }
LABEL_2995:
          if ( get_subseq() != 3 )
            goto LABEL_3029;
          h_inerc = h_inerc + 1.5;
          if ( h_inerc + 1.5 > 60.0 )
            h_inerc = 60.0;
          field_571 = 0;
          field_572 = 0;
          if ( dir * get_border_near() >= 0 )
          {
            /*
            v1213 = field_7D6;
            if ( v1213 && !(get_elaps_frames() % v1213) )
            {
              *(float *)&v1766 = 360.0;
              v1767 = (double)(unsigned int)get_MT_range(10);
              v1768 = 0.0;
              v1769 = field_7DC;
              v1214 = dir;
              v1215 = get_pframe();
              v1216 = y - (double)v1215->extra1[5];
              v1217 = v1216;
              v1218 = (double)(v1215->extra1[4] * (char)v1214) + x;
              addbullet(, 911, v1218, v1217, v1214, 1, (int)&v1766, 4);
            }
            */
            if ( field_7D4 > 0 )
            {
              if ( enemy->y - y <= 50.0 )
              {
                if ( enemy->y - y >= -50.0 )
                {
                  //v1207 = 0.0;
                  v_inerc = 0.0;
                }
                else
                {
                  v_inerc = -dash_angle;
                  //v1207 = 0.0;
                }
              }
              else
              {
                v_inerc = dash_angle;
                //v1207 = 0.0;
              }
              if ( y > 480.0 && 0.0/*v1207*/ < v_inerc )
                v_inerc = 0.0;//v1207;
LABEL_3012:
              if ( field_190 )
              {
                if ( field_190 != 3 )
                {
                  field_7E4 = field_7E4 + 1.0;
                  if ( field_7E4 + 1.0 >= 2.0 )
                  {
                    field_7E4 = 0.0;//v1207;
                    field_190 = 0;
                  }
                }
              }
LABEL_3029:
              if ( process() )
                set_seq(0);
              if ( !get_elaps_frames() )
              {
                if ( !get_frame_time() && !get_frame() && get_subseq() == 1 )
                {
                  switch (settings_get()->get_difficulty())
                  {
                    case GAME_DIFF_LUNA:
                      field_7D0 = 180;
                      field_7D2 = 90;
                      field_7D4 = 3;
                      field_7DC = 120.0;
                      //v1220 = 0.0;
                      goto LABEL_3040;
                    case GAME_DIFF_HARD:
                      field_7D0 = 180;
                      field_7D2 = 90;
                      field_7D4 = 2;
                      field_7D6 = 3;
                      field_7DC = 100.0;
                      //v1220 = 1.0;
                      goto LABEL_3040;
                    case GAME_DIFF_NORMAL:
                      field_7D0 = 120;
                      field_7D2 = 60;
                      field_7D4 = 3;
                      field_7D6 = 2;
                      field_7DC = 180.0;
                      //v1220 = 2.0;
                      goto LABEL_3040;
                    case GAME_DIFF_EASY:
                      field_7D0 = 120;
                      field_7D2 = 60;
                      field_7D4 = 4;
                      field_7D6 = 1;
                      field_7DC = 240.0;
                      //v1220 = 3.0;
LABEL_3040:
                      dash_angle = 1.0;//v1220;
                      break;
                    default:
                      break;
                  }
                }
                if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 3 )
                {
                  play_sfx(112);
                  /*
                  *(float *)&v1357 = 0.0;
                  v1358 = 0.0;
                  v1359 = 5.0;
                  v1221 = y + 120.0;
                  addbullet(, 910, x, v1221, dir, 1, (int)&v1357, 3);
                  *(float *)&v1357 = 90.0;
                  v1358 = 0.0;
                  v1359 = 0.0;
                  v1222 = y + 100.0;
                  addbullet(, 910, x, v1222, dir, 1, (int)&v1357, 3);
                  *(float *)&v1357 = -90.0;
                  v1358 = 0.0;
                  v1359 = 0.0;
                  v1223 = y + 100.0;
                  addbullet(, 910, x, v1223, dir, 1, (int)&v1357, 3);
                  *(float *)&v1357 = 0.0;
                  v1358 = 0.0;
                  v1359 = 3.0;
                  v1224 = y + 100.0;
                  addbullet(, 910, x, v1224, dir, 1, (int)&v1357, 3);
                  v1359 = 4.0;
                  v1225 = y + 100.0;
                  addbullet(, 910, x, v1225, dir, 1, (int)&v1357, 3);
                  */
                }
              }
              return;
            }
          }
          else
          {
            field_51C = 2;
            field_520 = 2;
            if ( x > 2280.0 && dir > 0 || x < -800.0 && dir < 0 )
            {
              ++field_7D8;
              //v1207 = 0.0;
              h_inerc = 0.0;
              v_inerc = 0.0;
              /*
              if ( field_7D8 == field_7D2 - 45 && field_7D4 > 0 )
              {
                v1208 = enemy->y;
                y = v1208;
                if ( v1208 > 480.0 )
                  y = 480.0;
                *(float *)&v1488 = 0.0;
                v1489 = (double)dir;
                v1490 = 7.0;
                v1491 = 60.0;
                v1209 = y + 100.0;
                addbullet(, 910, 0.0, v1209, 1, 1, (int)&v1488, 4);
                v1490 = 6.0;
                v1210 = y + 100.0;
                addbullet(, 910, 0.0, v1210, 1, 1, (int)&v1488, 4);
                v1207 = 0.0;
              }
              */
              if ( field_7D8 > field_7D2 )
              {
                if ( field_7D4 <= 0 )
                {
                  next_subseq();
                  v_inerc = 5.0 - 3.0;
                  h_inerc = -20.0;
                  return;
                }
                h_inerc = 60.0;
                play_sfx(112);
                --field_7D4;
                field_7D8 = 0;
                field_194 = 4;
                field_190 = 0;
                dir = -dir;
                goto LABEL_3011;
              }
              goto LABEL_3012;
            }
          }
LABEL_3011:
          //v1207 = 0.0;
          goto LABEL_3012;
        case 730:
          if ( get_subseq() <= 1 )
          {
            h_inerc = h_inerc * 0.9800000190734863;
            v_inerc = 0.9800000190734863 * v_inerc;
            if ( get_subseq() == 1 )
            {
                /*
              if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
              {
                *(float *)&v1435 = 360.0;
                v1436 = (double)(unsigned int)get_MT_range(400) + 200.0;
                v1437 = (double)(unsigned int)get_MT_range(2);
                v1226 = dir;
                v1227 = -*(float *)&v1435;
                v1228 = sin_deg(v1227);
                v1229 = v1228 * v1436 + y - (double)get_pframe()->extra1[5];
                v1230 = v1229;
                v1231 = -*(float *)&v1435;
                v1232 = cos_deg(v1231);
                v1233 = (v1232 * v1436 + (double)get_pframe()->extra1[4]) * (double)dir + x;
                addbullet(, 970, v1233, v1230, v1226, 1, (int)&v1435, 3);
              }
              */
              if ( get_elaps_frames() >= field_7D0 )
                goto LABEL_965;
            }
          }
          if ( get_subseq() == 3 && get_elaps_frames() >= field_7D2 )
            goto LABEL_965;
          if ( process() )
            set_seq(732);
          if ( !get_elaps_frames() )
          {
            if ( !get_frame_time() && !get_frame() && get_subseq() == 3 )
            {
              sub_486FD0(180.0, -180.0);
              /*
              if ( GAME_HARDNESS == 2 || GAME_HARDNESS == 3 )
              {
                v1403 = SLODWORD(field_7F0);
                v1404 = 3.0;
                v1405 = 8.0;
                v1234 = dir;
                v1235 = get_pframe();
                v1236 = y - (double)v1235->extra1[5];
                v1237 = v1236;
                v1238 = (double)(v1235->extra1[4] * (char)v1234) + x;
                addbullet(, 920, v1238, v1237, v1234, 1, (int)&v1403, 3);
                if ( GAME_HARDNESS == 3 )
                {
                  *(float *)&v1403 = field_7F0 + 15.0;
                  v1404 = 2.0;
                  v1405 = 8.0;
                  v1239 = dir;
                  v1240 = get_pframe();
                  v1241 = y - (double)v1240->extra1[5];
                  v1242 = v1241;
                  v1243 = (double)(v1240->extra1[4] * (char)v1239) + x;
                  addbullet(, 920, v1243, v1242, v1239, 1, (int)&v1403, 3);
                  *(float *)&v1403 = field_7F0 - 15.0;
                  v1404 = 2.0;
                  v1405 = 8.0;
                  v1244 = dir;
                  v1245 = get_pframe();
                  v1246 = y - (double)v1245->extra1[5];
                  v1247 = v1246;
                  v1248 = (double)(v1245->extra1[4] * (char)v1244) + x;
                  addbullet(, 920, v1248, v1247, v1244, 1, (int)&v1403, 3);
                }
              }
              */
            }
            if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            {
              play_sfx(117);
              switch ( settings_get()->get_difficulty() )
              {
                case GAME_DIFF_LUNA:
                  field_7D0 = 150;
                  field_7D2 = 120;
                  field_7DC = 6.0;
                  dash_angle = 360.0;
                  //v1249 = 0.0;
                  goto LABEL_3073;
                case GAME_DIFF_HARD:
                  field_7D0 = 120;
                  field_7D2 = 90;
                  field_7DC = 8.0;
                  dash_angle = 360.0;
                  //v1249 = 10.0;
                  goto LABEL_3073;
                case GAME_DIFF_NORMAL:
                  field_7D0 = 90;
                  field_7D2 = 90;
                  field_7DC = 10.0;
                  dash_angle = 360.0;
                  //v1249 = 30.0;
                  goto LABEL_3073;
                case GAME_DIFF_EASY:
                  field_7D0 = 90;
                  field_7D2 = 60;
                  field_7DC = 12.0;
                  dash_angle = 360.0;
                  //v1249 = 60.0;
LABEL_3073:
                  field_7E4 = 10.0;//v1249;
                  break;
                default:
                  break;
              }
              /*
              //v1337 = 0.0;
              if ( field_7DC > 0.0 )
              {
                v1250 = v1337;
                do
                {
                  *(float *)&v1636 = v1250 * 360.0 / field_7DC;
                  v1637 = 20.0;
                  v1638 = 6.0;
                  v1251 = dir;
                  v1252 = get_pframe();
                  v1253 = y - (double)v1252->extra1[5];
                  v1254 = v1253;
                  v1255 = (double)(v1252->extra1[4] * (char)v1251) + x;
                  addbullet(, 920, v1255, v1254, v1251, 1, (int)&v1636, 3);
                  v1337 = v1337 + 1.0;
                  v1250 = v1337;
                }
                while ( field_7DC > (double)v1337 );
              }
              */
            }
          }
          return;
        case 731:
          if ( process() )
            set_seq(730);
          if ( get_subseq() == 1 )
            v_inerc = v_inerc - v_force;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            h_inerc = 40.0 * 0.1000000014901161 - 2.0;
            v_inerc = 13.0;
            v_force = 0.34999999;
          }
          return;
        case 732:
          if ( get_subseq() == 1 )
          {
            //WHATIS?
            //set_vec_speed((render_class *)&cEffectSprite, dash_angle, field_7DC);
            field_7DC = field_7DC * 0.9800000190734863;
            if ( field_7DC * 0.9800000190734863 > -1.0 )
              field_7DC = -1.0;
            if ( get_elaps_frames() >= 60 )
            {
              set_seq(730);
              return;
            }
          }
          if ( process() )
            set_seq(0);
          if ( get_elaps_frames() || get_frame_time() || get_frame() || get_subseq() != 1 )
            return;
          if ( y <= 240.0 )
            dash_angle = 20.0 + 10.0;
          else
            dash_angle = -10.0 - 20.0;
          if ( x <= 640.0 )
          {
            dir = -1;
            //v1259 = 7.0;
          }
          else
          {
            dir = 1;
            //v1258 = get_MT_range(7)
            if ( false/*7.0 < 0*/ )
            {
              field_7DC = -10.0 - (7.0 + 4294967300.0);
              return;
            }
          }
          field_7DC = -10.0 - 7.0;//v1259
          return;
        case 740:
          dir = -1;
          h_inerc = (640.0 - x) * -0.05000000074505806;
          v_inerc = (240.0 - y) * 0.05000000074505806;
          if ( get_subseq() <= 1 )
          {
            h_inerc = h_inerc * 0.9800000190734863;
            v_inerc = 0.9800000190734863 * v_inerc;
            if ( get_subseq() == 1 )
            {
                /*
              if ( !(get_elaps_frames() % 2) && get_elaps_frames() <= field_7D0 - 30 )
              {
                *(float *)&v1417 = 360.0;
                v1418 = (double)(unsigned int)get_MT_range(400) + 200.0;
                v1419 = (double)(unsigned int)get_MT_range(2);
                v1260 = dir;
                v1261 = -*(float *)&v1417;
                v1262 = sin_deg(v1261);
                v1263 = v1262 * v1418 + y - (double)get_pframe()->extra1[5];
                v1264 = v1263;
                v1265 = -*(float *)&v1417;
                v1266 = cos_deg(v1265);
                v1267 = (v1266 * v1418 + (double)get_pframe()->extra1[4]) * (double)dir + x;
                addbullet(, 970, v1267, v1264, v1260, 1, (int)&v1417, 3);
              }
              */
              if ( get_elaps_frames() >= field_7D0 )
                goto LABEL_1450;
            }
          }
          if ( get_subseq() == 3 )
          {
            if ( !(get_elaps_frames() % field_7D4) )
            {
                /*
              *(float *)&v1774 = 360.0;
              v1775 = 0.0;
              v1776 = 0.0;
              v1777 = field_7DC;
              v1268 = y + 110.0;
              addbullet(, 930, x, v1268, dir, -1, (int)&v1774, 4);
              */
              field_7DC = -field_7DC;
              play_sfx(20);
            }
            if ( get_elaps_frames() >= field_7D2 )
              goto LABEL_965;
          }
          if ( get_subseq() == 4 && get_elaps_frames() >= field_7D6 )
            goto LABEL_965;
          if ( process() )
          {
            set_subseq(0);
          }
          else if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            switch (settings_get()->get_difficulty())
            {
              case GAME_DIFF_LUNA:
                field_7D0 = 120;
                field_7D2 = 360;
                goto LABEL_3129;
              case GAME_DIFF_HARD:
                field_7D0 = 120;
                field_7D2 = 480;
LABEL_3129:
                field_7D4 = 120;
                field_7D6 = 240;
                field_7DC = 1.5;
                break;
              case GAME_DIFF_NORMAL:
                field_7D0 = 120;
                field_7D2 = 600;
                field_7D4 = 120;
                field_7D6 = 240;
                field_7DC = 1.5;
                dash_angle = 5.0;
                break;
              case GAME_DIFF_EASY:
                field_7D0 = 120;
                field_7D2 = 720;
                field_7D4 = 120;
                field_7D6 = 240;
                field_7DC = 1.5;
                dash_angle = 10.0;
                break;
              default:
                return;
            }
          }
          return;
        case 770:
          if ( process() )
            set_seq(0);
          if ( !get_subseq() && !get_frame_time() && get_frame() == 5 )
          {
            field_6F5 = 1;
            sub_4685C0(-1);
            sub_46AB50(0, -1);
            field_188 = 0;
            health_to_max();
            field_868 = 1;
            field_820 = 0;
            field_81E = 1;
            field_81A = 0;
            field_81C = 0;
            field_818 = 0;
            scene_play_sfx(23);
            field_882 = 1;
            field_86A = 1;
            /*
            *(float *)&v1338 = 0.0;
            v1339 = 0.0;
            v1340 = 0.0;
            addbullet(, 1201, 180.0, 130.0, 1, 2, (int)&v1338, 3);
            v1340 = 1.0;
            v1269 = y + 100.0;
            addbullet(, 1202, x, v1269, dir, -1, (int)&v1338, 3);
            *(float *)&v1338 = 0.0;
            v1339 = 1.0;
            v1340 = 3.0;
            v1341 = 90.0;
            addbullet(, 970, 0.0, 64.0, 1, 1, (int)&v1338, 4);
            v1340 = 2.0;
            addbullet(, 970, 0.0, 64.0, 1, 1, (int)&v1338, 4);
            v1340 = 3.0;
            addbullet(, 970, 0.0, 416.0, 1, 1, (int)&v1338, 4);
            v1340 = 2.0;
            addbullet(, 970, 0.0, 416.0, 1, 1, (int)&v1338, 4);
            *(float *)&v1338 = 240.0;
            v1339 = 1.0;
            v1340 = 5.0;
            addbullet(, 970, 320.0, 242.0, 1, 1, (int)&v1338, 4);
            v1340 = 4.0;
            addbullet(, 970, 320.0, 240.0, 1, 1, (int)&v1338, 4);
            v1340 = 5.0;
            addbullet(, 970, 0.0, 242.0, 1, 1, (int)&v1338, 4);
            v1340 = 4.0;
            addbullet(, 970, 0.0, 240.0, 1, 1, (int)&v1338, 4);
            v1340 = 5.0;
            addbullet(, 970, 640.0, 242.0, 1, 1, (int)&v1338, 4);
            v1340 = 4.0;
            addbullet(, 970, 640.0, 240.0, 1, 1, (int)&v1338, 4);
            v1340 = 5.0;
            addbullet(, 970, 960.0, 242.0, 1, 1, (int)&v1338, 4);
            v1340 = 4.0;
            addbullet(, 970, 960.0, 240.0, 1, 1, (int)&v1338, 4);
            v1341 = 120.0;
            v1340 = 6.0;
            addbullet(, 970, 960.0, 240.0, 1, 1, (int)&v1338, 4);
            */
          }
          return;
        case 780:
          //uint32_t ssq = get_subseq();
          switch (get_subseq())
          {
            case 0:
            /*
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && !get_subseq() )
              {
                v1271 = (v27->x - x) * (double)dir;
                v1272 = v1271;
                v1273 = v27->y - y - 100.0;
                v1274 = -atan2_deg(v1273, v1272);
                field_7F0 = v1274;
                *(float *)&v1642 = v1274;
                v1643 = 25.0;
                v1644 = 0.0;
                v1275 = y + 100.0;
                addbullet(, 809, x, v1275, dir, 1, (int)&v1642, 3);
              }
              */
              v_inerc = v_inerc - v_force;
              if ( !char_on_ground_down() )
                goto LABEL_3160;
              v_inerc = 0.0;
              v_force = 0.0;
              y = getlvl_height();
              next_subseq();
              h_inerc = h_inerc * 0.5;
              return;
            case 1:
              h_inerc = h_inerc - 0.5;
              if ( h_inerc - 0.5 < 0.0 )
                h_inerc = 0.0;
              if ( x < 800.0 )
                x = 800.0;
              goto LABEL_3160;
            case 2:
              if ( !field_7D0 )
              {
                field_7D0 = 1;
                /*
                v1277 = enemy;
                v1278 = (v1277->x - x) * (double)dir;
                v1279 = v1278;
                v1280 = v1277->y - y - 100.0;
                v1281 = -atan2_deg(v1280, v1279);
                field_7F0 = v1281;
                *(float *)&v1648 = v1281;
                v1649 = 25.0;
                v1650 = 0.0;
                v1282 = y + 100.0;
                addbullet(, 809, x, v1282, dir, 1, (int)&v1648, 3);
                */
              }
              v_inerc = v_inerc * 0.9700000286102295;
              goto LABEL_3160;
            case 3:
            case 4:
              if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 4 )
              {
                h_inerc = 1.0;
                dir = -1;
                v_force = 0.25;
              }
              //v1283 = v_inerc - v_force;
              goto LABEL_3157;
            case 5:
              v_force = 0.25;
              //v1283 = v_inerc - 0.25;
LABEL_3157:
              v_inerc = v_inerc - v_force;//v1283;
              if ( !char_on_ground_down() )
                goto LABEL_3160;
              reset_forces();
              y = getlvl_height();
              x = 800.0;
              set_seq(10);
              return;
            default:
LABEL_3160:
              if ( process() || !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 2 )
                goto LABEL_3165;
              break;
          }
          return;
        case 788:
          field_74C = 0.0;
          if ( process() )
            goto LABEL_3165;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
            set_seq(700);
          return;
        case 791:
          v_inerc = v_inerc - v_force;
          if ( v_inerc - v_force < 0.0 )
            v_inerc = 0.0;
          if ( process() )
            goto LABEL_3165;
          if ( !get_elaps_frames() && !get_frame_time() && !get_frame() && get_subseq() == 1 )
          {
            scene_add_effect(this, 63, x, y, dir, 1);
            field_571 = 0;
            h_inerc = 10.0;
            v_inerc = 15.0;
            v_force = 0.1;
          }
          return;
        case 795:
          if ( get_subseq() )
            goto LABEL_3183;
          v_inerc = v_inerc - 0.300000011920929;
          if ( !char_on_ground_down() )
            goto LABEL_3183;
          
          move_val = 1;
LABEL_161:
          set_subseq(move_val);
          goto LABEL_162;
        case 797:
          if ( get_subseq() )
            goto LABEL_3189;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
            goto LABEL_3187;
          
LABEL_3189:
          if ( get_subseq() == 1 )
          {
            h_inerc = h_inerc - 0.75;
            if ( h_inerc - 0.75 <= 0.0 )
            {
              h_inerc = 0.0;
              if ( ++field_7D0 >= 2 )
              {
                next_subseq();
                h_inerc = -5.0;
                v_inerc = 5.0;
              }
            }
          }
          if ( (get_subseq() == 2 || get_subseq() == 3) && (v_inerc = v_inerc - 0.25, char_on_ground_down()) )
          {
            reset_forces();
            y = getlvl_height();
            set_subseq(4);
            scene_play_sfx(30);
            x = 480.0;
          }
          else if ( process() )
          {
            set_seq(0);
          }
          return;
        case 798:
          if ( get_subseq() )
            goto LABEL_3202;
          v_inerc = v_inerc - v_force;
          if ( char_on_ground_down() )
          {
LABEL_3187:
            next_subseq();
            y = getlvl_height();
            v_inerc = 0.0;
          }
          else
          {
            
LABEL_3202:
            if ( get_subseq() == 1 )
            {
              h_inerc = h_inerc - 0.75;
              if ( h_inerc - 0.75 <= 0.0 )
              {
                h_inerc = 0.0;
                if ( ++field_7D0 >= 2 )
                {
                  next_subseq();
                  h_inerc = -5.0;
                  v_inerc = 5.0;
                }
              }
            }
            if ( (get_subseq() == 2 || get_subseq() == 3) && (v_inerc = v_inerc - 0.25, char_on_ground_down()) )
            {
              reset_forces();
              y = getlvl_height();
              set_subseq(4);
              scene_play_sfx(30);
              x = 800.0;
            }
            else
            {
LABEL_3183:
              if ( process() )
                set_seq(700);
            }
          }
          return;
        default:
          char_c::func10();
          return;
      }
    }
  }
}


void char_utsuho::func20()
{


    /*v1 = a1;
      v2 = a1->current_frame_params;
      v3 = v2->fflags;
      v147 = a1->current_seq_frames_vector->cprior;
      v4 = v2->fflags & FF_CANCELLEABLE;
      v148 = v2->fflags & FF_CANCELLEABLE;
      v5 = v3 & FF_UNK200000;*/

    uint16_t cprior = get_cprior();
    uint32_t fflags = get_pframe()->fflags;

    bool cc = (fflags & FF_CANCELLEABLE) != 0;
    bool cu = (fflags & FF_HJC) != 0;
    //int32_t sq = get_seq();

    if ( !check_AB_pressed() )
    {
        if ( cc || cu )
        {
            /*
             if ( pres_comb >= 700 && pres_comb < 800 )
             {
               //v1->class->func2_set_seq(v1, LOWORD(v1->pressed_combination));
               return;
             }
             else*/
            if ( char_on_ground_flag() )
            {
                if ( (cu && cprior >= 10 && hi_jump_after_move())
                        || border_escape_ground()
                        || hi_jump(cprior, cu)
                        || fw_bk_dash_ground(cprior, cu) )
                    return;
            }
            else
            {
                int8_t mx = (weather_id == WEATHER_TEMPEST) + 2;
                if ( border_escape_air()
                        || fwd_dash_air(cprior, cu, mx, 2)
                        || bkg_dash_air(cprior, cu, mx, 2)
                        || flying_air(cprior, cu, mx) )
                    return;
            }
        }
        if ( field_84C == 0 && cc )
        {
            
        }
    }
}

void char_utsuho::set_seq_params()
{
  uint32_t sq = get_seq();
  field_571 = 1;
  if ( sq > 501 )
  {
    if ( sq <= 797 )
    {
      if ( sq == 797 )
      {
        field_7D0 = 0;
        play_sfx(5);
        return;
      }
      switch ( sq )
      {
        case 505:
        case 506:
        case 507:
        case 508:
          field_18C = 4;
          field_7D0 = 0;
          field_7D2 = 0;
          reset_forces();
          field_194 = 1;
          field_190 = 0;
          field_49A = 0;
          play_sfx(25);
          not_charge_attack = 0;
          return;
        case 510:
        case 512:
          field_18C = 8;
          reset_forces();
          field_7DC = 0.0;
          field_194 = 0;
          field_190 = 0;
          field_49A = 0;
          not_charge_attack = 0;
          return;
        case 520:
        case 521:
        case 522:
        case 523:
          field_18C = 1;
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_7D0 = 0;
          not_charge_attack = 0;
          field_194 = 99;
          return;
        case 525:
        case 526:
          field_18C = 5;
          reset_forces();
              field_49A = 0;
    field_190 = 0;
    not_charge_attack = 0;
    return;
        case 530:
        case 531:
          field_18C = 9;
          reset_forces();
              field_49A = 0;
    field_190 = 0;
    not_charge_attack = 0;
    return;
        case 540:
        case 541:
          field_18C = 2;
                    field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 542:
        case 543:
          field_18C = 2;
          field_190 = 0;
          not_charge_attack = 1;
          h_inerc = h_inerc * 0.1000000014901161;
          v_inerc = 0.1000000014901161 * v_inerc;
          v_force = 0.0099999998;
          return;
        case 545:
        case 546:
          field_18C = 6;
                    field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 550:
        case 551:
          field_18C = 11;

          field_190 = 0;
          reset_forces();
          not_charge_attack = 1;
          return;
        case 552:
        case 553:
          field_18C = 11;
          v_force = 0.0;
          field_190 = 0;
          not_charge_attack = 1;
          h_inerc *= 0.1000000014901161;
          v_inerc *= 0.1000000014901161;
        case 560:
        case 561:
        case 562:
        case 563:
          field_18C = 3;
          field_190 = 0;
          reset_forces();
          field_7DC = 0.0;
          dash_angle = 0.0;
          field_7E4 = 0.0;
          field_7E8 = 0.0;

          field_7D0 = 0;
          field_7D2 = 0;
          not_charge_attack = 1;
          return;
        case 565:
        case 566:
          field_18C = 7;
          field_190 = 0;
          reset_forces();
          not_charge_attack = 0;
          return;
        case 567:
        case 568:
          field_18C = 7;
          field_190 = 0;
          not_charge_attack = 1;

          field_7D6 = 0;
          v_force = 0.0;
          field_7D2 = 0;
          field_7D0 = 0;
          h_inerc *= 0.2000000029802322;
          v_inerc *= 0.2000000029802322;
          return;
        case 570:
        case 571:
          field_18C = 11;
          field_190 = 0;
          reset_forces();
          not_charge_attack = 0;
          return;
        case 572:
        case 573:
          v_force = 0.0;
          field_190 = 0;
          not_charge_attack = 0;
          field_18C = 11;
          h_inerc *= 0.1000000014901161;
          v_inerc *= 0.1000000014901161;
        case 600:
        case 601:
        case 605:
        case 606:
        case 607:
        case 650:
        case 655:
        case 707:
        case 722:
        case 731:
  reset_forces();
          return;
        case 602:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 1;

          reset_forces();
          return;
        case 603:
        case 604:
        case 653:
          field_190 = 1;
          reset_forces();
          return;
        case 608:
          reset_forces();
          field_190 = 0;
          field_49A = 0;
          field_194 = 1;
          return;
        case 609:
        case 659:
          field_7D0 = 0;
          field_7DC = 0.0;
          field_190 = 0;
          field_194 = 9;
          reset_forces();
          return;
        case 610:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 0;
          field_194 = 4;
          reset_forces();
          return;
        case 611:
        case 616:
          field_7D0 = 0;
          field_7D2 = 0;
          field_190 = 0;
          reset_forces();
          return;
        case 612:
        case 613:
        case 614:
        case 662:
          field_190 = 0;
          reset_forces();
          return;
        case 708:
          reset_forces();
          field_7D0 = 0;
          return;
        case 710:
          reset_forces();
          flip_with_force();
          return;
        case 720:
          field_7D8 = 0;
          field_7E4 = 0.0;
          field_190 = 0;
          field_194 = 4;
          reset_forces();
          return;
        case 721:
          reset_forces();
          field_7D2 = 0;
          field_7D8 = 0;
          field_7D6 = 0;
          return;
        case 730:
        case 732:
          return;
        case 733:
          field_7D0 = 0;
          field_7DC = 0.0;
          field_7D2 = 0;
          reset_forces();
          return;
        case 740:
          reset_forces();
          if ( !field_868 )
          {
            field_6F5 = 1;
            sub_4685C0(-1);
            sub_46AB50( 2, -1);
            field_188 = 0;
            health_to_max();
            field_868 = 1;
            field_820 = 0;
            field_81E = 1;
            field_81A = 0;
            field_81C = 0;
            field_818 = 0;
            scene_play_sfx(23);
            /*
            *(float *)&a7 = 0.0;
            v15 = 0.0;
            v16 = 0.0;
            */
            field_882 = 1;
            field_86A = 1;
            /*
            addbullet(&char_c, 1201, 180.0, 130.0, 1, 2, (int)&a7, 3);
            v12 = (unsigned __int8)dir;
            v16 = 1.0;
            a4 = y + 100.0;
            addbullet(&char_c, 1202, x, a4, v12, -1, (int)&a7, 3);
            *(float *)&a7 = 0.0;
            v15 = 1.0;
            v16 = 3.0;
            v17 = 90.0;
            addbullet(&char_c, 970, 0.0, 64.0, 1, 1, (int)&a7, 4);
            v16 = 2.0;
            addbullet(&char_c, 970, 0.0, 64.0, 1, 1, (int)&a7, 4);
            v16 = 3.0;
            addbullet(&char_c, 970, 0.0, 416.0, 1, 1, (int)&a7, 4);
            v16 = 2.0;
            addbullet(&char_c, 970, 0.0, 416.0, 1, 1, (int)&a7, 4);
            *(float *)&a7 = 240.0;
            v15 = 1.0;
            v16 = 5.0;
            addbullet(&char_c, 970, 320.0, 242.0, 1, 1, (int)&a7, 4);
            v16 = 4.0;
            addbullet(&char_c, 970, 320.0, 240.0, 1, 1, (int)&a7, 4);
            v16 = 5.0;
            addbullet(&char_c, 970, 0.0, 242.0, 1, 1, (int)&a7, 4);
            v16 = 4.0;
            addbullet(&char_c, 970, 0.0, 240.0, 1, 1, (int)&a7, 4);
            v16 = 5.0;
            addbullet(&char_c, 970, 640.0, 242.0, 1, 1, (int)&a7, 4);
            v16 = 4.0;
            addbullet(&char_c, 970, 640.0, 240.0, 1, 1, (int)&a7, 4);
            v16 = 5.0;
            addbullet(&char_c, 970, 960.0, 242.0, 1, 1, (int)&a7, 4);
            v16 = 4.0;
            addbullet(&char_c, 970, 960.0, 240.0, 1, 1, (int)&a7, 4);
            v17 = 120.0;
            v16 = 6.0;
            addbullet(&char_c, 970, 960.0, 240.0, 1, 1, (int)&a7, 4);
            */
          }
          return;
        default:
              char_c::set_seq_params();
    return;
      }
          char_c::set_seq_params();
    return;
    }
    if ( sq == 798 )
    {
      play_sfx(5);
      reset_forces();
      h_inerc = 15.0;
      field_7D0 = 0;
      v_inerc = 0.0;
      v_force = 0.5;
      return;
    }
    char_c::set_seq_params();
    return;
  }
  if ( sq >= 500 )
  {
    field_18C = 0;
    reset_forces();

    field_49A = 0;
    field_190 = 0;
    not_charge_attack = 0;
    return;
  }
  if ( sq > 214 )
  {
    switch ( sq )
    {
      case 216:
        reset_ofs();
        h_inerc = 0.0;
        v_inerc = 0.0;
        v_force = 0.60000002;
        x_off = 0.0;
        y_off = 95.0;
  field_7DC = 14.0;
  field_7D6 = 0;
  field_7EC = 0.0;
      case 217:
        reset_ofs();
        h_inerc = 0.0;
        v_inerc = 0.0;
        v_force = 0.60000002;
        x_off = 0.0;
        y_off = 95.0;
  field_7DC = 13.5;
  field_7D6 = 0;
  field_7EC = 0.0;
      case 300:
      case 303:
      case 330:
        if ( !field_49A )
          reset_forces();
        field_190 = 0;
        field_194 = 1;
        return;
      case 301:
      case 302:
        if ( !field_49A )
          reset_forces();
        field_190 = 0;
        field_194 = 1;
        not_charge_attack = 1;
        return;
      case 304:
        field_49A = 0;
        field_194 = 1;
        field_190 = 0;
        reset_forces();
        not_charge_attack = 1;
        return;
      case 305:
        v_inerc = 0.0;
        field_49A = 0;
        field_190 = 0;
        h_inerc = 15.0;
        field_194 = 1;
        v_force = 0.0;
        return;
      case 306:
        field_7D0 = 0;
        field_190 = 0;
        field_194 = 1;
        return;
      case 307:
      case 308:
        field_194 = 1;
        field_190 = 0;
        not_charge_attack = 1;
        h_inerc *= 0.2000000029802322;
        v_inerc *= 0.2000000029802322;
        v_force = 0.0;
        return;
      case 309:
        field_194 = 1;
        field_190 = 0;
        not_charge_attack = 1;
        return;
      case 310:
        field_7D0 = 0;
        v_force = 0.5;
        field_190 = 0;
        field_194 = 1;
        return;
      case 320:
        reset_forces();
        field_49A = 0;
        field_190 = 0;
        field_194 = 1;
        return;
      case 321:
      case 322:
        reset_forces();
        field_194 = 1;
        field_190 = 0;
        return;
      case 400:
        field_190 = 1;
        reset_forces();
        field_89C = 0;
        field_7D6 = 0;
    field_7D0 = 0;
    field_7D2 = 0;
    not_charge_attack = 1;
    return;
      case 401:
        field_190 = 1;
        reset_forces();
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        not_charge_attack = 0;
        return;
      case 402:
        field_190 = 1;
        reset_forces();
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        field_89C = 0;
        not_charge_attack = 1;
        return;
      case 404:
      case 406:
        field_89C = 0;
        not_charge_attack = 1;
                field_190 = 1;
          field_7D6 = 0;
          v_force = 0.0;
          field_7D2 = 0;
          field_7D0 = 0;
          h_inerc *= 0.2000000029802322;
          v_inerc *= 0.2000000029802322;
      case 405:
        not_charge_attack = 0;

        field_190 = 1;
          field_7D6 = 0;
          v_force = 0.0;
          field_7D2 = 0;
          field_7D0 = 0;
          h_inerc *= 0.2000000029802322;
          v_inerc *= 0.2000000029802322;
      case 408:
        h_inerc = 15.0;
        field_49A = 0;
        field_7D0 = 0;
        field_190 = 0;
        v_inerc = 0.0;
        field_194 = 1;
        return;
      case 409:
        field_49A = 0;
        v_force = 0.34999999;
        field_7D0 = 0;
        field_190 = 0;
        field_194 = 1;
        return;
      case 410:
        field_190 = 1;
        reset_forces();
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        field_7D8 = 0;
        not_charge_attack = 1;
        return;
      case 411:
        field_190 = 1;
        reset_forces();
        field_7D6 = 0;
field_7D0 = 0;
field_7D2 = 0;
not_charge_attack = 1;
return;
      case 412:
        field_190 = 1;
        reset_forces();
        field_7D0 = 0;
        field_7D2 = 0;
        field_7D6 = 0;
        field_7D8 = 0;
        not_charge_attack = 0;
        return;
      case 414:
        v_force = 0.0;
        field_190 = 1;
        field_7D8 = 0;
        h_inerc *= 0.2000000029802322;
        v_inerc *= 0.2000000029802322;
        field_7D6 = 0;
        field_7D0 = 0;
field_7D2 = 0;
not_charge_attack = 1;
return;
      case 415:
      case 416:
        field_190 = 1;
        not_charge_attack = 1;
          field_7D6 = 0;
          v_force = 0.0;
          field_7D2 = 0;
          field_7D0 = 0;
          h_inerc *= 0.2000000029802322;
          v_inerc *= 0.2000000029802322;
      case 418:
        field_49A = 0;
        h_inerc = 15.0;
        field_190 = 0;
        field_194 = 2;
        return;
      default:
            char_c::set_seq_params();
    return;
    }
        char_c::set_seq_params();
    return;
  }
  if ( sq != 214 )
  {
    if ( !(sq - 4) )
    {
      h_inerc = 6.0;
      return;
    }
    if ( (sq - 4) == 1 )
    {
      h_inerc = -5.0;
      return;
    }
        char_c::set_seq_params();
    return;
  }
  reset_ofs();
  h_inerc = 0.0;
  v_inerc = 0.0;
  v_force = 0.60000002;
  x_off = 0.0;
  y_off = 95.0;
  field_7DC = 12.0;
  field_7D6 = 0;
  field_7EC = 0.0;
}
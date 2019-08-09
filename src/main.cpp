#include "global_types.h"


#include "archive.h"
#include "file_read.h"
#include "graph.h"
#include "framedata.h"
#include "input.h"
#include "character_def.h"
#include "chars.h"
#include "background.h"
#include "music.h"
#include "scene.h"
#include <math.h>
#include <unistd.h>
#include "gui.h"
#include "profile.h"
#include "menu/menus.h"
#include "battle_ui.h"
#include "weather.h"
#include "bullets.h"

#include <iostream>


int main(int argc, char *argv[])
{

    //Creating the main window and initializing everything
    FILE *dats = NULL;
    const char *path = ".";
    char buf[256];

    /* Doing some checks to see if stuff is present */
    if (argc == 2)
    {
        path = argv[1];
        sprintf(buf,"%s/%s",path,"dat_files.txt");
        dats = fopen(buf,"rb");
    }

    if (argc != 2 || !dats )
        dats = fopen("dat_files.txt","rb");

    if (!dats)
    {
        printf("No dat_files.txt found!\n");
        exit(-1);
    }


    while(!feof(dats))
    {
        char rbuf[256];
        fgets(rbuf,255,dats);

        char *trimed = TrimRight(TrimLeft(rbuf));
        if (strlen(trimed) > 0)
        {
            sprintf(buf,"%s/%s",path,trimed);

            if (!arc_add_dat(buf))
                if (!arc_add_dat(trimed))
                    printf("Can't load %s, ignore.\n",trimed);
        }
    }

    fclose(dats);


    // Start the game loop
    /*
    arc_add_dat("th105a.dat");
    arc_add_dat("th105b.dat");
    arc_add_dat("th105c.dat");
    arc_add_dat("th123a.dat");
    arc_add_dat("th123b.dat");
    arc_add_dat("th123c.dat");
    

    /*
     * All the necessary initializations
     */
    key_matrix_init();

    gr_events pollers;
    pollers.keyb_events = key_matrix_set;

    gr_init(640,480,"OpenSoku", pollers);
    sfx_init();
    scene_load_sounds();

    /*
     * Play music
     */
    //playmusic();

    bullets_init_common();

    /* Setting the characters */

    /* Player 1 */
    char_c *player1 = new char_suika(inp_createinput(INP_TYPE_BOTH));

    /* Set profiles here */
    sprintf(buf,"%s/profile/profile1p.pf",path);
    s_profile *prof = profile_load_from_file(buf);
    sprintf(buf,"%s/profile/profile2p.pf",path);
    s_profile *prof2 = profile_load_from_file(buf);
    if (prof)
    {
        player1->set_input_profile(prof);
        player1->set_cards_deck(prof,0);
    }

    /* Player2 */
    char_c *player2 = new char_cirno(inp_createinput(INP_TYPE_KB));

    if (prof2)
    {
        player2->set_cards_deck(prof2,0);
        player2->set_input_profile(prof2);
    }

    uint32_t i = 0;
//

    inp_both *inp = get_global_input();

    player1->set_seq(0);
    player2->set_seq(0);
    srand(time(NULL));
    background  *bkg = bkg_create(17);

    scene_new_scene(bkg,player1,player2);

//    int32_t ii = 0;
    int32_t aa = 0;
    int32_t bb = 0;

    weather_change(WEATHER_CLEAR,1);
    weather_time_set(0);

    /* Give player 1 some cards */
    player1->add_card(107);
    player1->add_card(108);
    player1->add_card(111);
    player1->add_card(105);
    player1->add_card(106);

    player2->add_card();
    player2->add_card();


    //The screen initialization
    screen *scr = NULL;

    /*  Experimental ! */
    //Menus here

    id_screen scr_id = SCREEN_UNK;
    id_screen scr_next_id = SCREEN_GAMEPLAY;
    //id_screen scr_next_id = SCREEN_TITLE; //starting the game with title instead here
    

    fader       glob_fader;
    menu_fader  *loc_fader = menu_get_fader();

    bool game_run = true;

/* =================================================== */
// Main loop
    while(game_run)
    {
        //Poll stuff
        gr_poll_events();

        inp->update(true);

        /*
         * Press F1 to close the game
         */
        if (inp->rawPressed(kC_F1))
            game_run = false;

        aa++;
        if (aa > 10 && inp->rawPressed(kC_Q))
        {
            aa = 0;
            player1->add_card(bb+100);
            //weather_time_set(999);
            //weather_change((WEATHER_ID)bb,true);

            bb++;
            bb %= 12;
        }


        if (scr_id == scr_next_id)
        {
            loc_fader->update();
            glob_fader.fade_in();

            if (scr)
                scr_next_id = scr->update();
        }

        if (scr_next_id != SCREEN_UNK)
        {
            if (scr_id != scr_next_id)
            if (glob_fader.fade_out())
            {
                if (scr)
                {
                    scr->onExit();
                    delete scr;
                }
                scr = screen_create(scr_next_id);
                scr_id = scr_next_id;
                scr->onStart();
            }

            bool scr_drawed = false;

            if (scr)
                scr_drawed = scr->draw();

            loc_fader->draw();

            if (scr_drawed)
                glob_fader.draw();
        }
        else
        {
            game_run = false;
            continue;
        }

        gr_flip();
    }
/* =================================================== */

    delete bkg;


    return EXIT_SUCCESS;
}


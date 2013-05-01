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


int main(int argc, char *argv[])
{
    // Create the main window

    //Nyan Shinki, nyan

    FILE *dats = NULL;
    const char *path = ".";
    char buf[256];

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
    //arc_add_dat("th105a.dat");
    //arc_add_dat("th105b.dat");
    //arc_add_dat("th105c.dat");
    //arc_add_dat("th123a.dat");
    //arc_add_dat("th123b.dat");
    //arc_add_dat("th123c.dat");

    gr_init(640,480,"OpenSoku");
    sfx_init();
    scene_load_sounds();


     //playmusic();

    char_c *marisa = new char_marisa(inp_createinput(INP_TYPE_BOTH));

    sprintf(buf,"%s/profile/Zidane.pf",path);
    s_profile *prof = profile_load_from_file(buf);
    if (prof)
    {
        marisa->set_input_profile(prof);
        marisa->set_cards_deck(prof,0);
        marisa->add_card();
        marisa->add_card();
        marisa->add_card();
        marisa->add_card();
        marisa->add_card();
    }


    char_c *alice = new char_alice(inp_createinput(INP_TYPE_NONE));

    if (prof)
    {
        alice->set_cards_deck(prof,0);
        alice->add_card();
        alice->add_card();
        alice->add_card();
        alice->add_card();
        alice->add_card();
    }

//    uint32_t i = 0;
//

    inp_kb kb;

    marisa->set_seq(0);
    alice->set_seq(0);
    srand(time(NULL));
    background  *bkg = bkg_create(38);



    c_scene *scn = new c_scene(bkg,marisa,alice);

    int32_t ii = 0;


    gui_holder gui;

   // gui.load_dat("data/battle","battleUnder.dat");

    gui_holder gui2;

    //gui2.load_dat("data/battle","battleUpper.dat");

    gui_holder gui3;

   // gui3.load_dat("data/battle","combo.dat");

    while(!kb.rawPressed(kC_Escape))
    {

        if (kb.rawPressed(kC_Q))
            ii++;

        kb.update();

        gr_clear(126,206,244);

        scn->players_input();

        bkg->update();

        //scn.players_collisions();
        scn->update();

        scn->draw_scene();

        scn->update_char_anims();

        //gui.draw_all(0);
        //gui2.draw_all(0);
        //gui3.draw_all(0);

        //menu_call();

        for(uint32_t i=0; i < marisa->cards_active.size(); i++)
        {
            if (i == 0)
                cards_draw_card(marisa->cards_active[i],10 + i*50, 400, 1, 0 );
            else
                cards_draw_card(marisa->cards_active[i],32+i*25, 430, 0.5, 0 );

        }

        for(uint32_t i=0; i < alice->cards_active.size(); i++)
        {
            if (i == 0)
                cards_draw_card(alice->cards_active[i],600 - (10 + i*50), 400, 1, 0 );
            else
                cards_draw_card(alice->cards_active[i],600 -(10+i*25), 430, 0.5, 0 );

        }

        //debug_str(100,100,"фы");

        gr_flip();

        //scene_add_effect(marisa,103,marisa->x,marisa->y,marisa->dir,1);

    }

    delete bkg;


    return EXIT_SUCCESS;
}

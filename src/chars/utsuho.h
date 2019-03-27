#ifndef UTSUHO_CPP_INCLUDED
#define UTSUHO_CPP_INCLUDED

class char_utsuho: public char_c
{
private:
	//Shader stuff
    gr_tex  *backtex;
    gr_shader *shader;
    float      shd_p;

public:
	/* Experimental! */
	int16_t field_890;
	int16_t field_892;
	//__int16 field_895;
	float 	field_898;
	float 	field_89C;
	float 	field_8A0;
	float	field_8A4;
	int8_t	field_894;
	int8_t field_8A8;
	/*
	int8_t	field_8A9;
	int8_t	field_8AA;
	int8_t	field_8AB;
	*/


    char_utsuho(inp_ab *func,uint8_t pal = 0);

    void func10();
    void func20();
    //void func24();
    //void init_vars();
    /* c_bullet *new bullet(); */
    void set_seq_params();

    //Shader
    void draw(gr_shader *shader = NULL);
    void draw_shadow(shd_trans *trans, gr_shader *shader = NULL);
};

#endif // UTSUHO_CPP_INCLUDED

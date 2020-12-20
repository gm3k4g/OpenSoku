#ifndef MEILING_CPP_INCLUDED
#define MEILING_CPP_INCLUDED

class char_meiling: public char_c
{
public:
	int16_t field_890;
	float field_138;

	//from alice.h
	int16_t field_891[4];
	int16_t field_892;

	char_meiling(inp_ab *func,uint8_t pal = 0);

	void func10();
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // MEILING_CPP_INCLUDED
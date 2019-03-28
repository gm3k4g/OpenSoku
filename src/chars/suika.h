#ifndef SUIKA_CPP_INCLUDED
#define SUIKA_CPP_INCLUDED

class char_suika: public char_c
{
public:
	float field_138;
	int16_t field_890;
	int16_t field_892;
	int16_t field_894;

	char_suika(inp_ab *func,uint8_t pal = 0);

	void func10(); //Number of variables detected: 1882
	//void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // SUIKA_CPP_INCLUDED
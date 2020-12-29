#ifndef REMILIA_CPP_INCLUDED
#define REMILIA_CPP_INCLUDED

class char_remilia: public char_c
{
public:
	//TODO: value types were guessed, needs confirmation..
	int16_t field_890;
  	float field_138;

  	//from marisa.h
  	int16_t field_892;
	int8_t  field_8A8;

	char_remilia(inp_ab *func,uint8_t pal = 0);

	void func10(); //Number of variables detected: 1882
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // REMILIA_CPP_INCLUDED
#ifndef YUYUKO_CPP_INCLUDED
#define YUYUKO_CPP_INCLUDED

class char_yuyuko: public char_c
{
public:

	// TODO: value types were guessed, confirmation?
	float field_138;
	int16_t field_890;
	int16_t field_894;
	int16_t field_898;
	int16_t field_89C;
	int16_t field_8A0;
	int16_t field_8A4;
	int16_t field_8A8;

	//from marisa.h
	int16_t field_892;


	char_yuyuko(inp_ab *func,uint8_t pal = 0);

	void sub_6E28C0();

	void func10();
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // YUYUKO_CPP_INCLUDED
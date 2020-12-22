#ifndef PACHOU_CPP_INCLUDED
#define PACHOU_CPP_INCLUDED

class char_pachou: public char_c
{
public:

	// TODO: values were guessed, needs confirmation
	double field_138;
	int16_t field_890;
	int16_t field_892;
	double field_8A4;
	int16_t field_894;
	int16_t field_896;
	int16_t field_898;
	int16_t field_89A;
	int16_t field_89C;
	int16_t field_89E;
	int16_t field_8A0;
	int16_t field_8A2;

	// from alice.h
	int16_t field_891[4];

	char_pachou(inp_ab *func,uint8_t pal = 0);

	void func10();
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // PACHOU_CPP_INCLUDED
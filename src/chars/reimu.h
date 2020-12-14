#ifndef REIMU_CPP_INCLUDED
#define REIMU_CPP_INCLUDED

class char_reimu: public char_c
{
public:
	// TODO: value types were guessed, needs confirmation
	float field_138;
	int16_t field_890;
	int16_t field_8BA;
	float field_894;
	int16_t field_8B4;
	float field_898;
	int16_t field_8B6;
	float field_89C;
	int16_t field_8B8;
	float field_8A0;
	float field_8A4;
	float field_8A8;
	float field_8AC;
	float field_8B0;

	char_reimu(inp_ab *func,uint8_t pal = 0);

	void func10(); //Number of variables detected: 1882
	//void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // REIMU_CPP_INCLUDED
#ifndef YUKARI_CPP_INCLUDED
#define YUKARI_CPP_INCLUDED

class char_yukari: public char_c
{
public:
	// TODO: variable types were guessed, needs confirmation
	float field_138;
	float field_898;
	float field_8A0;
	float field_89C;
	float field_8A4;
	int16_t field_8A8;
	int16_t field_8AA;
	int16_t field_8AC;
	int16_t field_8B2;
	int16_t field_8AE;
	int16_t field_8B0;
	int16_t field_8D0;
	int16_t field_890;
	int16_t field_892;
	int16_t field_894;
	int16_t field_895;
	int16_t field_8B4;
	float field_8B8;
	float field_8C4;
	float field_8BC;
	float field_8C8;
	float field_8C0;
	float field_8CC;

	char_yukari(inp_ab *func,uint8_t pal = 0);

	void func10();
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // YUKARI_CPP_INCLUDED
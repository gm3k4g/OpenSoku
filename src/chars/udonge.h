#ifndef UDONGE_CPP_INCLUDED
#define UDONGE_CPP_INCLUDED

class char_udonge: public char_c
{
public:
	//TODO: value types were guessed, needs confirmation
	float field_138;
	int16_t field_890;
	int16_t field_892;
	float field_894;
	int16_t field_8A0;
	int16_t field_8A4;
	float field_89C;
	int16_t field_898;
	int16_t field_89A;
	float field_8AC;
	int16_t field_8A8;
	int16_t field_8B0;
	int16_t field_8B2;
	int16_t field_8B4;

	char_udonge(inp_ab *func,uint8_t pal = 0);

	void func10();
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // UDONGE_CPP_INCLUDED
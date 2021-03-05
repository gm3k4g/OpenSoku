#ifndef SUWAKO_CPP_INCLUDED
#define SUWAKO_CPP_INCLUDED

class char_suwako: public char_c
{
public:
	//TODO: value types were guessed, needs confirmation
	float field_138;
	int16_t field_890;
	int16_t field_891;
	int16_t field_894;
	int16_t field_898;
	int16_t field_89C;
	int16_t field_89D;
	int16_t field_8A0;
	int16_t field_8A4;

	char_suwako(inp_ab *func,uint8_t pal = 0);

	void func10(); //Number of variables detected: 1882
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // SUWAKO_CPP_INCLUDED
#ifndef SAKUYA_CPP_INCLUDED
#define SAKUYA_CPP_INCLUDED

class char_sakuya: public char_c
{
public:
	//TODO: value types were guessed, needs confirmation
	float field_138;
	int16_t field_892;
	int16_t field_890;
	int16_t field_894;
	int16_t field_896;
	int16_t field_898;
	int16_t field_89A;
	int16_t field_89C;

	// from marisa.h
	int8_t  field_8A8;


	char_sakuya(inp_ab *func,uint8_t pal = 0);

	void func10();
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // SAKUYA_CPP_INCLUDED
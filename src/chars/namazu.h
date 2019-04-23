#ifndef NAMAZU_CPP_INCLUDED
#define NAMAZU_CPP_INCLUDED
//is this character possible :thonk:

class char_namazu: public char_c
{
public:
	//Variables to initialize
	int16_t field_890;
	int16_t field_894;
	int16_t field_898;
	int16_t field_89C;
	float field_138;

	char_namazu(inp_ab *func,uint8_t pal = 0);

	//void sub_5586E0();
	void func10();
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	c_bullet *new_bullet();
};

#endif // NAMAZU_CPP_INCLUDED
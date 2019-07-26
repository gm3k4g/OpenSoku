#ifndef AYA_CPP_INCLUDED
#define AYA_CPP_INCLUDED

class char_aya: public char_c
{
public:
	/* fields */
	char_aya(inp_ab *func,uint8_t pal = 0);
	int16_t		field_890;
	int16_t 	field_892;
	int16_t 	field_894;
	int16_t 	field_896;

	float 	field_8A0;
	float 	field_8A4;
	int8_t	field_8A8;





	/* functions */
	void func10();
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // AYA_CPP_INCLUDED
#ifndef YOUMU_CPP_INCLUDED
#define YOUMU_CPP_INCLUDED

class char_youmu: public char_c
{
public:
	
	// TODO: value types were guessed, needs confirmation
    float field_138;
	int16_t mion_pframe;
	int16_t field_8B9;
	float field_8DC;
	int16_t field_8D0;
	float field_8E0;
	int16_t field_8D1;
	float field_8E4;
	int16_t field_8D2;
	int16_t field_8D4;
	int16_t field_8D6;
	int16_t field_8D8;
	int16_t field_8E8;

	char_youmu(inp_ab *func,uint8_t pal = 0);

	void func10();
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	////// from set_seq_params()
		/*
		sub_469450(this, 0, 0, 60);
	    sub_483570();
		*/
	
	//c_bullet *new_bullet();
};

#endif // YOUMU_CPP_INCLUDED
#ifndef YOUMU_CPP_INCLUDED
#define YOUMU_CPP_INCLUDED

class char_youmu: public char_c
{
public:


	char_youmu(inp_ab *func,uint8_t pal = 0);

	void func10(); //Number of variables detected: 1882
	//void func20();
	//void func24();
	void init_vars();
	//void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // YOUMU_CPP_INCLUDED
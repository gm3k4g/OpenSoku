#ifndef SAKUYA_CPP_INCLUDED
#define SAKUYA_CPP_INCLUDED

class char_sakuya: public char_c
{
public:


	char_sakuya(inp_ab *func,uint8_t pal = 0);

	void func10(); //Number of variables detected: 1882
	//void func20();
	//void func24();
	void init_vars();
	//void set_seq_params();
	//c_bullet *new_bullet();
};

#endif // SAKUYA_CPP_INCLUDED
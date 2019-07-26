#ifndef YUYUKO_CPP_INCLUDED
#define YUYUKO_CPP_INCLUDED

class char_yuyuko: public char_c
{
public:

	int32_t field_890;

	char_yuyuko(inp_ab *func,uint8_t pal = 0);

	void sub_6E28C0();

	void func10(); //Number of variables detected: 1882
	void func20();
	//void func24();
	void init_vars();
	void set_seq_params();
	c_bullet *new_bullet();
};

#endif // YUYUKO_CPP_INCLUDED
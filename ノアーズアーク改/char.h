#ifndef ANIMAL
#define ANIMAL

#define CHESTNUT_W 52.f
#define CHESTNUT_H 52.f


struct Animal {
	float x;      //�����W
	float y;      //y���W
	bool Clear;   //�N���A���Ă��邩�ǂ���
	bool Active;  //�\�����邩���Ȃ���
	bool Move;    //�����Ă邩�ǂ���
	bool Dead;	  //�����Ă��邩�ǂ���
	bool Push;    //���ډ����ꂽ��
	int  Skip;    //���C�I�����������ꂽ���ǂ���
	float movement; //�����̈ړ�����
};
struct mob
{
	float x;      //x���W
	float y;      //y���W
	bool Active;  //�\�����邩���Ȃ���
};




#endif

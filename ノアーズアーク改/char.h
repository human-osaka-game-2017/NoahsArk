#ifndef ANIMAL
#define ANIMAL

#define CHESTNUT_W 52.f
#define CHESTNUT_H 52.f


struct Animal {
	float x;      //ｘ座標
	float y;      //y座標
	bool Clear;   //クリアしているかどうか
	bool Active;  //表示するかしないか
	bool Move;    //動いてるかどうか
	bool Dead;	  //生きているかどうか
	bool Push;    //一回目押された時
	bool Skip;    //ライオンに抜かされたかどうか
};
struct mob
{
	float x;      //x座標
	float y;      //y座標
	bool Active;  //表示するかしないか
};




#endif

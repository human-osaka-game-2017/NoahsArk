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
	int  Skip;    //ライオンが抜かされたかどうか
	float movement; //動物の移動距離
};
struct mob
{
	float x;      //x座標
	float y;      //y座標
	bool Active;  //表示するかしないか
};




#endif

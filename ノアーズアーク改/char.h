#ifndef ANIMAL
#define ANIMAL

#define MOVESPEEDLION 5.f
#define MOVESPEEDELEPHANT 3.f

#define LION_W 78.f
#define LION_H 78.f
#define TREE_W 52.f
#define TREE_H 104.f
#define ALLIGATOR_W 78.f
#define ALLIGATOR_H 52.f
#define ELEPHANT_W 104.f
#define ELEPHANT_H 104.f
#define CHESTNUT_W 52.f
#define CHESTNUT_H 52.f

struct Animal {
	float x;
	float y;
	bool movecheck;
	bool hitcheck;
};
struct mob
{
	float x;
	float y;
	bool movecheck;
	bool hitcheck;
};




#endif

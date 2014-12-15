#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Entity
{
private:
	int maxHp;
	int hp;
	int atk;
	int x;
	int y;
	int AIAggroRange;
	bool has;
	bool canAtk;
	bool traversable;
	bool player;
	bool haskey;
	bool door;
public:

	Entity();
	Entity(int, int, int, int, int, bool, bool, bool, bool, bool, bool);
	//~Entity();
	int gethp();
	int getMaxHP()
	int getatk();
	int getx();
	int gety();
	bool isPlayer();
	bool isActor();
	bool isTraversable();
	void update();
	void sethp(int);
	void setatk(int);
	void setx(int);
	void sety(int);
	void moveup(vector< vector<Entity> > &vec);
	void movedown(vector< vector<Entity> > &vec);
	void moveleft(vector< vector<Entity> > &vec);
	void moveright(vector< vector<Entity> > &vec);

};
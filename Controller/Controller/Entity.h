#include <iostream>

using namespace std;

class Entity
{
	int hp;
	int atk;
	int x;
	int y;
	bool hasActed;
	bool canAtk;
	bool traversable;
	bool player;
	bool haskey;
	bool door;
public:

	Entity(int, int, int, int, bool, bool, bool, bool, bool, bool);
	int gethp();
	int getatk();
	int getx();
	int gety();
	void update();
	void sethhp(int);
	void setatk(int);
	void setx(int);
	void sety(int);
	void moveup(vector< vector<Entity> > &vec);
	void movedown(vector< vector<Entity> > &vec);
	void moveleft(vector< vector<Entity> > &vec);
	void moveright(vector< vector<Entity> > &vec);

};
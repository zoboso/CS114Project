#include <iostream>
#include "Entity.h"
#include <vector>

using namespace std;


	int Entity::gethp()
	{
		return this->hp;

	}
	int Entity::getatk()
	{
		return this->atk;

	}
	int Entity::getx()
	{
		return this->x;
	}
	int Entity::gety()
	{
		return this->y;
	}
	void Entity::sethhp(int a)
	{
		this->hp = a;
	}
	void Entity::setatk(int a)
	{
		this->atk = a;
	}
	void Entity::setx(int a)
	{

		this->x = a;

		/*int x = vec.capacity;
		for (int i = 0; i <= x; i++)
		{

		}*/
	}
	void Entity::sety(int a)
	{
		this->y = a;
	}
	void Entity::moveup(vector< vector<Entity> > &vec)
	{
		int a = this->getx;
		int b = this->gety;
		if (a>=1)
		{
			vec[a - 1][b] = vec[a][b];
		}

		
	}
	void Entity::movedown(vector< vector<Entity> > &vec)
	{

	}
	void Entity::moveleft(vector< vector<Entity> > &vec)
	{

	}
	void Entity::moveright(vector< vector<Entity> > &vec)
	{

	}

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
	void Entity::update()
	{
		/*
			first check canAtk
			Second check player
			if door
			door test
			draw
			player control
			else
			enemy AI*/

			if ((door == true) && (haskey == true))
			{
				// load level code
				// break
			}
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
		if (a >= 1 && vec[a - 1][b].traversable == true) //checks to make sure it will stay in the play area and is traverable
		{
			vec[a - 1][b] = vec[a][b]; //updates location in array
			this->setx(a - 1); //updates location for object
		}

		
	}
	void Entity::movedown(vector< vector<Entity> > &vec)
	{
		int a = this->getx;
		int b = this->gety;
		if (a >= 1 && vec[a + 1][b].traversable == true) //checks to make sure it will stay in the play area and is traverable
		{
			vec[a + 1][b] = vec[a][b]; //updates location in array
			this->setx(a + 1); //updates location for object
		}
	}
	void Entity::moveleft(vector< vector<Entity> > &vec)
	{
		int a = this->getx;
		int b = this->gety;
		if (a >= 1 && vec[a][b-1].traversable == true) //checks to make sure it will stay in the play area and is traverable
		{
			vec[a][b-1] = vec[a][b]; //updates location in array
			this->sety(b-1); //updates location for object
		}
	}
	void Entity::moveright(vector< vector<Entity> > &vec)
	{
		int a = this->getx;
		int b = this->gety;
		if (a >= 1 && vec[a][b + 1].traversable == true) //checks to make sure it will stay in the play area and is traverable
		{
			vec[a][b + 1] = vec[a][b]; //updates location in array
			this->sety(b + 1); //updates location for object
		}
	}
	Entity::Entity(int h, int a, int cX, int cY, int t, bool hasA, bool canA, bool trav, bool p, bool hasK, bool d)
	{
		hp = h;
		atk = a;
		x = cX;
		y = cY;
		team = t;
		hasActed = hasA;
		canAtk = canA;
		traversable = trav;
		player = p;
		haskey = hasK;
		door = d;
	}

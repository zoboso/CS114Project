#include <iostream>
#include "Entity.h"
#include <vector>

using namespace std;

Entity::Entity(int h, int a, int cX, int cY, bool hasA, bool canA, bool trav, bool p, bool hasK, bool d)
{
	hp = h;
	atk = a;
	x = cX;
	y = cY;
	hasActed = hasA;
	canAtk = canA;
	traversable = trav;
	player = p;
	haskey = hasK;
	door = d;
}
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

		if (vec[a - 1][b].canAtk = true)//checks to see if entity is attackable
		{
			this->sethhp = (this->gethp - vec[a - 1][b].getatk);//sets new hp for object
			vec[a - 1][b].sethhp = (vec[a - 1][b].gethp - this->getatk);//sets new hp for attacked object
			
			if (this->gethp <= 0)
			{
				/*delete object*/
				if (this->player = true)
				{
					/*display game over*/
				}

				else if (vec[a - 1][b].gethp <= 0)// checks to see if attacked object has died
				{
					vec[a - 1][b] = vec[a][b]; //updates location in array
					vec[a][b] = Entity(1, 0, a, b, false, false, true, false, false, false);//replaces old location with blank tile
					this->setx(a - 1); //updates location for object
				}
			}

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

		if (vec[a + 1][b].canAtk = true)//checks to see if entity is attackable
		{
			this->sethhp = (this->gethp - vec[a + 1][b].getatk);//sets new hp for player
			vec[a + 1][b].sethhp = (vec[a + 1][b].gethp - this->getatk);//sets new hp for enemy

			if (vec[a + 1][b].gethp <= 0)// checks to see if enemy has died
			{
				vec[a + 1][b] = vec[a][b]; //updates location in array
				this->setx(a - 1); //updates location for object
			}
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

		if (vec[a][b-1].canAtk = true)//checks to see if entity is attackable
		{
			this->sethhp = (this->gethp - vec[a][b-1].getatk);//sets new hp for player
			vec[a][b-1].sethhp = (vec[a][b-1].gethp - this->getatk);//sets new hp for enemy

			if (vec[a][b-1].gethp <= 0)// checks to see if enemy has died
			{
				vec[a][b-1] = vec[a][b]; //updates location in array
				this->sety(b - 1); //updates location for object
			}
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

		if (vec[a][b + 1].canAtk = true)//checks to see if entity is attackable
		{
			this->sethhp = (this->gethp - vec[a][b + 1].getatk);//sets new hp for player
			vec[a][b + 1].sethhp = (vec[a][b + 1].gethp - this->getatk);//sets new hp for enemy

			if (vec[a][b + 1].gethp <= 0)// checks to see if enemy has died
			{
				vec[a][b + 1] = vec[a][b]; //updates location in array
				this->sety(b + 1); //updates location for object
			}

		}
	}

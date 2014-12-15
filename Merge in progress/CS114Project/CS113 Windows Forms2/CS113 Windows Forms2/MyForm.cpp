#include "MyForm.h"
#include <iostream>
#include <vector>
#include "Entity.h"
#include "input.h"



using namespace WinFormsProjectTemplate; //name of project
using namespace std;
vector<vector<Entity>> world;

void populate(int lvl)
{
	ifstream myFile;
	int level = lvl;
	myFile.open("level" + to_string(level) + ".txt");
	string line;
	int row = 0;
	while (getline(myFile, line)){
		int count = 0;
		for (int column = 0; column < line.length(); column++){
			char square = line[column];
			count++;
			switch (square){
			case ' ':
			{
						Entity blank = Entity(0, 0, row, column, 0, false, false, true, false, false, false);
						world[row][column] = blank;
						break;
			}
			case '1':
			{
						Entity wall = Entity(0, 0, row, column, 0, false, false, false, false, false, false);
						world[row][column] = wall;
						break;
			}
			case '2':
			{
						Entity Player = Entity(12, 2, row, column, 0, false, true, false, true, false, false);
						world[row][column] = Player;
						break;
			}
			case '3':
			{
						Entity Enemy = Entity(1, 1, row, column, 0, false, true, false, false, false, false);
						world[row][column] = Enemy;
						break;
			}
			case '4':
			{
						Entity Door = Entity(0, 0, row, column, 0, false, false, false, false, false, true);
						world[row][column] = Door;
						break;
			}

			}
		}
		row++;
		cout << endl;
	}
	myFile.close();
}

void draw()
 {
	
	for (int x = 0; world[][]; x++)
		{
			for (int y = 0; world[][]; y++)
				{
					
				}
		}
	
}

char AI(Entity actor)
{
	// find and determine closest player
	Entity target, location;
	int x, y;
	bool agro = false;
	double AgroRange = 4;
	char goal1, goal2, output;

	// determining the target
	std::vector< std::vector<Entity> >::const_iterator row;
	std::vector<Entity>::const_iterator col;

	for (row = world.begin(); row != world.end(); ++row)
	{
		for (col = row->begin(); col != row->end(); ++col)
		{
			location = *col;
			double num = sqrt(pow(location.getx() - actor.getx(), 2) + pow(location.gety() - actor.gety(), 2));
			if (location.isPlayer() && (AgroRange > num)){
				agro = true;
				AgroRange = num;
				x = location.getx();
				y = location.gety();
			}
		}
	}
	target = world[x][y];

	// x (and y) are only set while the AI is aggroed; the test below tests true if the value is set.	
	if (agro)
	{
		if (abs(location.getx() - actor.getx()) > abs(location.gety() - actor.gety()))
		{
			if (location.getx() - actor.getx() > 0)
				goal1 = '>';
			else
				goal1 = '<';
			if (location.gety() - actor.gety() > 0)
				goal2 = '^';
			else
				goal2 = 'v';
		}
		else
		{
			if (location.gety() - actor.gety() > 0)
				goal1 = '^';
			else
				goal1 = 'v';
			if (location.getx() - actor.getx() > 0)
				goal2 = '^';
			else
				goal2 = 'v';
		}
		if (actor.getMaxHP() <  3 * actor.gethp())
		{
			// this if statement causes weakened enemies to run away. this might not be needed.
			switch (goal1){
			case 'v':
				goal1 = '^';
				break;
			case '^':
				goal1 = 'v';
				break;
			case '<':
				goal1 = '>';
				break;
			case '>':
				goal1 = '<';
				break;
			}
			switch (goal2){
			case 'v':
				goal2 = '^';
				break;
			case '^':
				goal2 = 'v';
				break;
			case '<':
				goal2 = '>';
				break;
			case '>':
				goal2 = '<';
				break;
			}
		}
	}
	else
	{
		// Probably move random
	}

	//obstacles test
	bool goalFine = false;
	output = goal1;
	while (!goalFine){
		int dx, dy;
		switch (output){
		case 'v':
			dx = actor.getx();
			dy = actor.gety() - 1;
			break;
		case '^':
			dx = actor.getx();
			dy = actor.gety() + 1;
			break;
		case '<':
			dx = actor.getx() - 1;
			dy = actor.gety();
			break;
		case '>':
			dx = actor.getx() + 1;
			dy = actor.gety();
			break;
		}

		// what is in where we are going target:go, other attackable entity: no go, wall: no go, ooher go;
	
		if (!(dx == target.getx() && dy == target.gety())){
			if (world[dx][dy].isActor() || world[dx][dy].isTraversable())
			{
				if (output == goal1)
					output = goal2;
				else if (output == goal2)
				{
					switch (output){
					case 'v':
						output = '^';
						break;
					case '^':
						output = 'v';
						break;
					case '<':
						output = '>';
						break;
					case '>':
						output = '<';
						break;
					}
				}
				else
				{
					switch (goal1){
					case 'v':
						goal1 = '^';
						break;
					case '^':
						goal1 = 'v';
						break;
					case '<':
						goal1 = '>';
						break;
					case '>':
						goal1 = '<';
						break;
					}
				}
			}
			else
			{
				goalFine = true;
			}
		}
		else
		{
			goalFine = true;
		}
	}

	return output;
}


[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	// Enabling Windows visual effects
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew MyForm());
	


	return 0;
	
	
}

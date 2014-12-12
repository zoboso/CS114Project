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

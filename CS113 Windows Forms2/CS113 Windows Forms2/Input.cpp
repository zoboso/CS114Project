// This program is designed to take input from a text file to set up the game
// The program will include a section where it outouts to the console as a test
// Code Started on 11/1/2014
// Written by Joseph Cole,
// for Pre-alpha update 0.0

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "C:\Users\Joseph\Documents\GitHub\CS114Project\Controller\Controller\Entity.h"
#include "C:\Users\Joseph\Documents\GitHub\CS114Project\Controller\Controller\Entity.cpp"

using namespace std;

const int LEVELS = 2;
const int TILES = 0;

void input(std::vector< std::vector<Entity>> &cell, int level){

	int level = 0;
	//this while loop is for testing purposes to run different levels without stopping the program
	bool run = true;
	
	// actual program
	ifstream myFile;
	myFile.open("level" + to_string(level) + ".txt");
	string line;
	int row = 0;
	std::vector< std::vector<Entity>> output;
	while (getline(myFile, line)){
		std::vector<Entity> vectorColumn;
		for (int column = 0; column < line.length(); column++){
			char square = line[column];
			Entity unit ;
			switch (square){	
			case ' ':
				cout << ' ';
				break;
			case '1':
				cout << '#';
				break;
			case '2':
				cout << 'P';
				break;
			case '3':
				cout << 'E';
				break;
			case '4':
				cout << 'D';
				break;
			// The following are for tiles
			case 'q':
			case 'w':
			case 'e':
			case 'r':
			case 't':
			case 'y':
				// create randomly generated tile's data 
				// add tile to array
				//  
			}
		}
		row++;
		cout << endl;
	}
	myFile.close();


	
}
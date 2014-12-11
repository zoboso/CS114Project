// This program is designed to take input from a text file to set up the game
// The program will include a section where it outouts to the console as a test
// Code Started on 11/1/2014
// Written by Joseph Cole,
// for Pre-alpha update 0.0

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "Entity.h"

using namespace std;

const int LEVELS = 2;
const int TILES = 0;

void input(std::vector< std::vector<Entity>> &cell, int level){

	 level = 0;
	//this while loop is for testing purposes to run different levels without stopping the program
	bool run = true;
	// actual program
	ifstream myFile;
	myFile.open("level" + to_string(level) + ".txt");
	string line;
	int row = 0;
	while (getline(myFile, line)){
		for (int column = 0; column < line.length(); column++){
			char square = line[column];
		
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
	
			}
		}
		row++;
		cout << endl;
	}
	myFile.close();


	
}
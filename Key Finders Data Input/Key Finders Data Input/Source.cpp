// This program is designed to take input from a text file to set up the game
// The program will include a section where it outouts to the console as a test
// Code Started on 11/1/2014
// Written by Joseph Cole,
// for Pre-alpha update 0.0

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const int LEVELS = 2;
const int TILES = 0;

int main(){
	//main function will probably become a function later

	int level = 0;
	//this while loop is for testing purposes to run different levels without stopping the program
	bool run = true;
	while (run){
		// to make sure any 
		int choice;
		cout << "next level: (1), choose level: (2), same level: (3) ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			level++;
			if (level > LEVELS){
				level = 1;
			}
			break;
		case 2:
			do{
				cout << "enter level: ";
				cin >> level;
			} while (level > 0 && level <= LEVELS);
			break;
		default:
			break;
		}

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

		// loop termination for testing purposes
		char terminus;
		cout << "run again (y/n) ";
		cin >> terminus;
		if (terminus == 'n'){
			run = false;
		}
	}
}
// creates a tile class for inputing a tile as a unit

#include <fstream>
#include <string>
using namespace std;

class tile{
private:
	const static int TILESIZE = 6;
	char holding[TILESIZE][TILESIZE];
	int x;
	int y;
	int tilenum;
	int orientation;
public:
	tile(int xStart, int yStart, int TileNumber, int position)
		: x{ xStart }, y{ yStart }, tilenum{ TileNumber }, orientation{position}
	{
		fstream myFile;
		myFile.open("level" + to_string(tilenum) + ".txt");
		
		myFile.close();
	}

	bool CellInTile(int cellx, int celly){
		return ((cellx >= x && cellx < x + 6) && (celly >= x && celly < y + 6));
	}

};
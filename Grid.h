#include <iostream>
#include <fstream>
#include "File.h"

using namespace std;

class Grid{
public:
  Grid();
  Grid(int row, int column);
  Grid(int row, int column, string filename);
  ~Grid();

  void printGrid(string fileName);
  void printGrid();
  void insertPoints(int x, int y);
  char** returnMyGrid();
  int getRow();
  int getColumn();
  void fileOp(string filename);


  int inRow;
  int inColumn;
  int linelength;
  int intial_x;
  int intial_y;
  int goal_x;
  int goal_y;
  string line;
  string fileName;
  ifstream inFile;

  char **myGrid;

  File a(string name);

};

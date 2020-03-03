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
  int i_x;
  int i_y;
  int gl_x;
  int gl_y;
  string line;
  string fileName;
  ifstream inFile;

  char **myGrid;

  File a(string name);

};

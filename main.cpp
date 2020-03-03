#include<iostream>
#include<fstream>
#include "Grid.h"

using namespace std;

int main(int argc, char** argv)
{
  File a("test1.txt");
  a.getFile();

  int row = a.getFileRow();
  int column = a.getFileColum();

  Grid g(row, column);
  g.fileOp("test1.txt");
}

#include "Grid.h"
#include<iostream>
#include<fstream>

using namespace std;

//default constructor
Grid::Grid()
{

  inRow = 5;
  inColumn = 5;//default grid would be 5 by 5
  myGrid = new char*[inRow];//create an 1-D array first


  for(int i=0; i<inRow; ++i)
  {
    myGrid[i] = new char[inColumn];
    //for each cell in the 1-D array, we point another 1-D array in there to make a 2-D array
  }
  for(int i=0; i<inRow; ++i)
  {
  }

  for(int i=0; i<inRow; ++i)
  {
    for(int j=0; j<inColumn; ++j)
    {
      myGrid[i][j] = '-';
      //initialize the grid with all '-'

    }
  }
}

Grid::Grid(int row, int column)
{

  inRow = row;
  inColumn = column;//default grid would be 5 by 5
  myGrid = new char*[inRow];//create an 1-D array first


  for(int i=0; i<inRow; ++i)
  {
    myGrid[i] = new char[inColumn];
    //for each cell in the 1-D array, we point another 1-D array in there to make a 2-D array
  }
  for(int i=0; i<inRow; ++i)
  {
  }

  for(int i=0; i<inRow; ++i)
  {
    for(int j=0; j<inColumn; ++j)
    {
      myGrid[i][j] = '-';
      //initialize the grid with all '-'

    }
  }
}


//destructor
Grid::~Grid()
{
  delete myGrid;
}

//print out the grid in the terminal
void Grid::printGrid()
{
  cout << "myGrid" << endl;
  for(int i=0; i<inRow; ++i)
  {
    if(to_string(i).length() == 1)
    {
      cout << i;
      cout << "     ";
    }
    else if(to_string(i).length() == 2)
    {
      cout << i;
      cout << "    ";
    }
    else if(to_string(i).length() == 3)
    {
      cout << i;
      cout << "   ";
    }
    else if (to_string(i).length() == 4)
    {
      cout << i;
      cout << "  ";
    }
    for (int j=0; j<inColumn; ++j)
    {
      cout << myGrid[i][j];
      cout << "  ";
    }
    cout << "\n";
  }
}



void Grid::insertPoints(int x, int y) //to insert the x
{
  myGrid[x][y] = 'X';
}

char** Grid::returnMyGrid() //grid 1
{
  return myGrid;
}

int Grid::getRow() //the rows
{
  return inRow;
}

int Grid::getColumn() //the columns
{
  return inColumn;
}

void Grid::fileOp(string filename)
{
  if (!inFile)
  {
    cout << "there are some problems.";
    exit(1); //if the file is not there, return an error
  }

  inFile.open(filename);

  int linenumber = 0;
  getline(inFile, line); //read the first line from the file, which is the row numebr
  inRow = stoi(line);  //parse string to int
  inColumn = inRow;

  while (getline(inFile, line)) //while there is a line in the file
  {
    for (int i = 0; i < inColumn; ++i)
    {
      myGrid[linenumber][i] = line[i];
    }
    linenumber++;
  }
  for(int i=0; i <inRow; i++){
    for (int j=0; j <inColumn; j++){
      if(myGrid[i][j] == 'i'){
        i_x = i;
        i_y = j;
        cout<< "Inital State: ("<< i_x<< ", " <<i_y << ")" <<endl;
      }
      else if(myGrid[i][j] == 'g'){
        gl_x =i;
        gl_y =j;
        cout<< "glState: ("<< gl_x<< ", "<< gl_y << ")" <<endl;
      }
    }
  }

  inFile.close();

  printGrid();
}

#include <fstream>
#include <iostream>
#include "Grid.h"
#include "Search.h"

using namespace std;

Search::Search()
{
  eucliDist = 1000.0;
  manhatDist = 1000.0;
  cost =0;
  row =0;
  column =0;
}
Search::~Search()
{

}

void evalDist()

}
void Search::Euclidian()
{
  cin>>fileName;
  file f(fileName)
  f.getFile();
  cost = 0;

  row = f.getFileRow();
  column = f.getFileColumn();

  Grid g(row,column);
  g.fileOp(fileName);

  while(g.intial_x != g.goal_x && g.intial_y != g.goal_y){
    //check where it can go in it's position
    double tempDis =0;
    int pos = 0;

  }

}

//formulas for Euclidian and Manhattan distance
double Search:: getEcliDist(int intial_x, int intial_y,int goal_x, int goal_y);
{
  return sqr((intial_x - goal_x)(intial_x - goal_x)+(intial_y - goal_y)(intial_y- goal_y));
}
double Search::getManhatDist(int intial_x, int intial_y, int goal_x, int goal_y);)
{
  return abs((intial_x - goal_x)+ (intial_y - goal_y))

}

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
  node =0
}
Search::~Search()
{

}

void evalDist()

}
void Search::Euclidian() //stratagy 1
{
  cin>>fileName;
  file f(fileName)
  f.getFile();
  cost = 0;
  node =0

  row = f.getFileRow();
  column = f.getFileColumn();

  Grid g(row,column);
  g.fileOp(fileName);

  while(g.intial_x != g.goal_x && g.intial_y != g.goal_y){
    //check where it can go in it's pos
    double tempDis =0;
    int pos = -1;
    eucliDist = 1000.0;
    if (g.intial_x - 1 > -1 && (g.myGrid[g.intial_x - 1][g.intial_y] == '.' || g.myGrid[g.intial_x - 1][g.intial_y] == 'g'))
       {
           cout << "Up" << endl;
           node++;
           tempDis = getEucliDist(g.intial_x - 1, g.intial_y, g.goal_x, g.goal_y);
           if(tempDis <= eucliDist)
           {
               eucliDist = tempDis;
               pos = 0;
           }
       }
       if (g.intial_x + 1 < row && (g.myGrid[g.intial_x + 1][g.intial_y] == '.' || g.myGrid[g.intial_x + 1][g.intial_y] == 'g'))
      {
          cout << "Down" << endl;
          node++;
          tempDis = getEucliDist(g.intial_x + 1, g.intial_y, g.goal_x, g.goal_y);
          if (tempDis <= eucliDist)
          {
              eucliDist = tempDis;
              pos = 1;
          }
      }
      if (g.intial_y - 1 > -1 && (g.myGrid[g.intial_x][g.intial_y - 1] == '.' || g.myGrid[g.intial_x][g.intial_y - 1] == 'g'))
      {
          cout << "Left" << endl;
          node++;
          tempDis = getEucliDist(g.intial_x, g.intial_y - 1, g.goal_x, g.goal_y);
          if (tempDis <= eucliDist)
          {
              eucliDist = tempDis;
              pos = 2;
          }
      }
      if (g.intial_y + 1 < row && (g.myGrid[g.intial_x][g.intial_y + 1] == '.' || g.myGrid[g.intial_x][g.intial_y + 1] == 'g'))
      {
          cout << "Right" << endl;
          node++;
          tempDis = getEucliDist(g.intial_x, g.intial_y + 1, g.goal_x, g.goal_y);
          if (tempDis <= eucliDist)
          {
              eucliDist = tempDis;
              pos = 3;
          }
      }
      if (pos == 0)
       {
           g.myGrid[g.intial_x][g.intial_y] = 'O';
           g.myGrid[g.intial_x - 1][g.intial_y] = 'i';
           g.intial_x = g.intial_x - 1;
       }
       else if (pos == 1)
       {
           g.myGrid[g.intial_x][g.intial_y] = 'O';
           g.myGrid[g.intial_x + 1][g.intial_y] = 'i';
           g.intial_x = g.intial_x + 1;
       }
       else if (pos == 2)
       {
           g.myGrid[g.intial_x][g.intial_y] = 'O';
           g.myGrid[g.intial_x][g.intial_y - 1] = 'i';
           g.intial_y = g.intial_y - 1;
       }
       else if (pos == 3)
       {
           g.myGrid[g.intial_x][g.intial_y] = 'O';
           g.myGrid[g.intial_x][g.intial_y + 1] = 'i';
           g.intial_y = g.intial_y + 1;
       }

       g.printGrid();
       cost++;
       cout << "Cost: " << cost << endl;
       cout << "Node: " << node << endl;
   }

}

void Search::Manhattan(){ //stratgy 3
  cin >> fileName;
  file f(fileName);
  f.getFile();
  cost =0;
  node =0;

  Grid g(row,column);
  g.fileOp(fileName);

  double tempDis =0;
  int pos = -1;
  manhatDist = 1000.0;

  if (g.intial_x - 1 > -1 && (g.myGrid[g.intial_x - 1][g.intial_y] == '.' || g.myGrid[g.intial_x - 1][g.intial_y] == 'g'))
       {
           cout << "Up" << endl;
           node++;
           tempDis = getManhatDist(g.intial_x - 1, g.intial_y, g.final_x, g.final_y);
           if (tempDis <= manhatDist)
           {
               manhatDist = tempDis;
               pos = 0;
           }
       }
       if (g.intial_x + 1 < row && (g.myGrid[g.intial_x + 1][g.intial_y] == '.' || g.myGrid[g.intial_x + 1][g.intial_y] == 'g'))
       {
           cout << "Down" << endl;
           node++;
           tempDis = getManhatDist(g.intial_x + 1, g.intial_y, g.final_x, g.final_y);
           if (tempDis <= manhatDist)
           {
               manhatDist = tempDis;
               pos = 1;
           }
       }
       if (g.intial_y - 1 > -1 && (g.myGrid[g.intial_x][g.intial_y - 1] == '.' || g.myGrid[g.intial_x][g.intial_y - 1] == 'g'))
       {
           cout << "Left" << endl;
           node++;
           tempDis = getManhatDist(g.intial_x, g.intial_y - 1, g.final_x, g.final_y);
           if (tempDis <= manhatDist)
           {
               manhatDist = tempDis;
               pos = 2;
           }
       }
       if (g.intial_y + 1 < row && (g.myGrid[g.intial_x][g.intial_y + 1] == '.' || g.myGrid[g.intial_x][g.intial_y + 1] == 'g'))
       {
           cout << "Right" << endl;
           node++;
           tempDis = getManhatDist(g.intial_x, g.intial_y + 1, g.final_x, g.final_y);
           if (tempDis <= manhatDist)
           {
               manhatDist = tempDis;
               pos = 3;
           }
       }

       if (pos == 0)
       {
           g.myGrid[g.intial_x][g.intial_y] = 'O';
           g.myGrid[g.intial_x - 1][g.intial_y] = 'i';
           g.intial_x = g.intial_x - 1;
       }
       else if (pos == 1)
       {
           g.myGrid[g.intial_x][g.intial_y] = 'O';
           g.myGrid[g.intial_x + 1][g.intial_y] = 'i';
           g.intial_x = g.intial_x + 1;
       }
       else if (pos == 2)
       {
           g.myGrid[g.intial_x][g.intial_y] = 'O';
           g.myGrid[g.intial_x][g.intial_y - 1] = 'i';
           g.intial_y = g.intial_y - 1;
       }
       else if (pos == 3)
       {
           g.myGrid[g.intial_x][g.intial_y] = 'O';
           g.myGrid[g.intial_x][g.intial_y + 1] = 'i';
           g.intial_y = g.intial_y + 1;
       }

       g.printGrid();
       cost++;
       cout << "Cost: " << cost << endl;
       cout << "Node: " << node << endl;
   }
}

void Search::A

//formulas for Euclidian and Manhattan distance
double Search:: getEcliDist(int intial_x, int intial_y,int goal_x, int goal_y);
{
  return sqr((intial_x - goal_x)(intial_x - goal_x)+(intial_y - goal_y)(intial_y- goal_y));
}
double Search::getManhatDist(int intial_x, int intial_y, int goal_x, int goal_y);)
{
  return abs((intial_x - goal_x)+ (intial_y - goal_y))

}

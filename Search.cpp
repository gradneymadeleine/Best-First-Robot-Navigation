#include <fstream>
#include <iostream>
#include <math.h>
#include "Search.h"

using namespace std;

Search::Search()
{
  eucliDist = 1000.0;
  manhatDist = 1000.0;
  cost =0;
  row =0;
  column =0;
  node =0;
}
Search::~Search()
{

}

void Search::Euclidian() //stratagy 1
{

  cin>>fileName;
  File f(fileName);
  f.getFile();
  cost = 0;
  row = f.getFileRow();
  column = f.getFileColum();
  Grid g(row,column);
  g.fileOp(fileName);

  while (g.i_x != g.gl_x || g.i_y != g.gl_y){
    //check where it can go in it's pos
    double tempDis =0;
    int pos = -1;
    eucliDist = 1000.0;
    if (g.i_x - 1 > -1)
       {
          if (g.myGrid[g.i_x - 1][g.i_y] == '.' || g.myGrid[g.i_x - 1][g.i_y] == 'g')
         {
           cout << "Up" << endl;
           tempDis = getEucliDist(g.i_x - 1, g.i_y, g.gl_x, g.gl_y);
           if(tempDis <= eucliDist)
           {
               eucliDist = tempDis;
               g.myGrid[g.i_x][g.i_y] = 'O';
               g.myGrid[g.i_x - 1][g.i_y] = 'i';
               g.i_x = g.i_x - 1;
           }
         }
       }
       if (g.i_x + 1 < row)
      {
        if(g.myGrid[g.i_x + 1][g.i_y] == '.' || g.myGrid[g.i_x + 1][g.i_y] == 'g')
        {
          cout << "Down" << endl;
          tempDis = getEucliDist(g.i_x + 1, g.i_y, g.gl_x, g.gl_y);
          if (tempDis <= eucliDist)
          {
              eucliDist = tempDis;
              g.myGrid[g.i_x][g.i_y] = 'O';
              g.myGrid[g.i_x + 1][g.i_y] = 'i';
              g.i_x = g.i_x + 1;
          }
        }
      }
      if (g.i_y - 1 > -1)
      {
        if(g.myGrid[g.i_x][g.i_y - 1] == '.' || g.myGrid[g.i_x][g.i_y - 1] == 'g')
        {
          cout << "Left" << endl;
          tempDis = getEucliDist(g.i_x, g.i_y - 1, g.gl_x, g.gl_y);
          if (tempDis <= eucliDist)
          {
              eucliDist = tempDis;
              g.myGrid[g.i_x][g.i_y] = 'O';
              g.myGrid[g.i_x][g.i_y - 1] = 'i';
              g.i_y = g.i_y - 1;
          }
        }
      }
      if (g.i_y + 1 < row)
      {
        if(g.myGrid[g.i_x][g.i_y + 1] == '.' || g.myGrid[g.i_x][g.i_y + 1] == 'g')
        {
          cout << "Right" << endl;
          tempDis = getEucliDist(g.i_x, g.i_y + 1, g.gl_x, g.gl_y);
          if (tempDis <= eucliDist)
          {
              eucliDist = tempDis;
              g.myGrid[g.i_x][g.i_y] = 'O';
              g.myGrid[g.i_x][g.i_y + 1] = 'i';
              g.i_y = g.i_y + 1;
          }
        }
      }
       cost++;
   }
   g.printGrid();
   cout << "The cost would be: " << cost << endl;

}

void Search::Mahattan(){ //stratgy 3
  cout << " Stratagy 2: Manhattan Distance" << endl;
  cin >> fileName;
  File f(fileName);
  f.getFile();
  cost =0;
  Grid g(row,column);
  g.fileOp(fileName);
  while (g.i_x != g.gl_x || g.i_y != g.gl_y){
    //check where it can go in it's pos
    double tempDis =0;
    int pos = -1;
    manhatDist = 1000.0;

    if (g.i_x - 1 > -1)
         {
           if(g.myGrid[g.i_x - 1][g.i_y] == '.' || g.myGrid[g.i_x - 1][g.i_y] == 'g')
           {
             cout << "Up" << endl;
             tempDis = getManhatDist(g.i_x - 1, g.i_y, g.gl_x, g.gl_y);
             if (tempDis <= manhatDist)
             {
                 manhatDist = tempDis;
                 pos = 0;
             }
           }
         }
         if (g.i_x + 1 < row)
         {
           if (g.myGrid[g.i_x + 1][g.i_y] == '.' || g.myGrid[g.i_x + 1][g.i_y] == 'g')
           {
             cout << "Down" << endl;
             tempDis = getManhatDist(g.i_x + 1, g.i_y, g.gl_x, g.gl_y);
             if (tempDis <= manhatDist)
             {
                 manhatDist = tempDis;
                 pos = 1;
             }
           }
         }
         if (g.i_y - 1 > -1 )
         {
           if (g.myGrid[g.i_x][g.i_y - 1] == '.' || g.myGrid[g.i_x][g.i_y - 1] == 'g'){
             cout << "Left" << endl;
             tempDis = getManhatDist(g.i_x, g.i_y - 1, g.gl_x, g.gl_y);
             if (tempDis <= manhatDist)
             {
                 manhatDist = tempDis;
                 pos = 2;
             }
           }

         }
         if (g.i_y + 1 < row)
         {
           if (g.myGrid[g.i_x][g.i_y + 1] == '.' || g.myGrid[g.i_x][g.i_y + 1] == 'g')
           {
             cout << "Right" << endl;
             tempDis = getManhatDist(g.i_x, g.i_y + 1, g.gl_x, g.gl_y);
             if (tempDis <= manhatDist)
             {
                 manhatDist = tempDis;
                 pos = 3;
             }
           }

         }

         if (pos == 0)
         {
             g.myGrid[g.i_x][g.i_y] = 'O';
             g.myGrid[g.i_x - 1][g.i_y] = 'i';
             g.i_x = g.i_x - 1;
         }
         else if (pos == 1)
         {
             g.myGrid[g.i_x][g.i_y] = 'O';
             g.myGrid[g.i_x + 1][g.i_y] = 'i';
             g.i_x = g.i_x + 1;
         }
         else if (pos == 2)
         {
             g.myGrid[g.i_x][g.i_y] = 'O';
             g.myGrid[g.i_x][g.i_y - 1] = 'i';
             g.i_y = g.i_y - 1;
         }
         else if (pos == 3)
         {
             g.myGrid[g.i_x][g.i_y] = 'O';
             g.myGrid[g.i_x][g.i_y + 1] = 'i';
             g.i_y = g.i_y + 1;
         }

         cost++;
     }
     g.printGrid();
     cout << "The cost would be: " << cost << endl;
}

void Search::AstarE(){
  cout<< "Stratagy 3: A* Euclidian " << endl;
  cin >> fileName;
  File f(fileName);
  f.getFile();
  cost =0;
  row = f.getFileRow();
  column = f.getFileColum();
  Grid g(row,column);
  g.fileOp(fileName);

  while (g.i_x != g.gl_x || g.i_y != g.gl_y){
    //check where it can go in it's pos
    double tempDis =0;
    int pos = -1;
    eucliDist = 1000.0;
    if (g.i_x - 1 > -1 )
       {
         if (g.myGrid[g.i_x - 1][g.i_y] == '.' || g.myGrid[g.i_x - 1][g.i_y] == 'g')
         {
           cout << "Up" << endl;
           tempDis = getEucliDist(g.i_x - 1, g.i_y, g.gl_x, g.gl_y) + cost;
           if(tempDis <= eucliDist)
           {
               eucliDist = tempDis;
               g.myGrid[g.i_x][g.i_y] = 'O';
               g.myGrid[g.i_x - 1][g.i_y] = 'i';
               g.i_x = g.i_x - 1;
            }
         }
      }
      if (g.i_x + 1 < row)
     {
       if(g.myGrid[g.i_x + 1][g.i_y] == '.' || g.myGrid[g.i_x + 1][g.i_y] == 'g')
         cout << "Down" << endl;
         node++;
         tempDis = getEucliDist(g.i_x + 1, g.i_y, g.gl_x, g.gl_y)+ cost;
         if (tempDis <= eucliDist)
         {
             eucliDist = tempDis;
             g.myGrid[g.i_x][g.i_y] = 'O';
             g.myGrid[g.i_x + 1][g.i_y] = 'i';
             g.i_x = g.i_x + 1;
         }
     }
     if (g.i_y - 1 > -1 )
     {
       if (g.myGrid[g.i_x][g.i_y - 1] == '.' || g.myGrid[g.i_x][g.i_y - 1] == 'g'){
         cout << "Left" << endl;
         node++;
         tempDis = getEucliDist(g.i_x, g.i_y - 1, g.gl_x, g.gl_y) + cost;
         if (tempDis <= eucliDist)
         {
             eucliDist = tempDis;
             g.myGrid[g.i_x][g.i_y] = 'O';
             g.myGrid[g.i_x][g.i_y - 1] = 'i';
             g.i_y = g.i_y - 1;
         }
       }

     }
     if (g.i_y + 1 < row)
     {
       if(g.myGrid[g.i_x][g.i_y + 1] == '.' || g.myGrid[g.i_x][g.i_y + 1] == 'g')
       {
         cout << "Right" << endl;
         node++;
         tempDis = getEucliDist(g.i_x, g.i_y + 1, g.gl_x, g.gl_y)+ cost;
         if (tempDis <= eucliDist)
         {
             eucliDist = tempDis;
             g.myGrid[g.i_x][g.i_y] = 'O';
             g.myGrid[g.i_x][g.i_y + 1] = 'i';
             g.i_y = g.i_y + 1;
         }
       }

     }

      cost++;
  }
  g.printGrid();
  cout << "The cost would be: " << cost << endl;
}

void Search::AstarM(){
  cout << " Stratagy 4: A* Manhattan Distance" << endl;
  cin >> fileName;
  File f(fileName);
  f.getFile();
  cost =0;
  Grid g(row,column);
  g.fileOp(fileName);
  double tempDis =0;
  int pos = -1;
  manhatDist = 1000.0;

  while (g.i_x != g.gl_x || g.i_y != g.gl_y){
    //check where it can go in it's pos
  if (g.i_x - 1 > -1)
       {
         if (g.myGrid[g.i_x - 1][g.i_y] == '.' || g.myGrid[g.i_x - 1][g.i_y] == 'g')
         {
           cout << "Up" << endl;
           node++;
           tempDis = getManhatDist(g.i_x - 1, g.i_y, g.gl_x, g.gl_y) + cost;
           if (tempDis <= manhatDist)
           {
               manhatDist = tempDis;
               g.myGrid[g.i_x][g.i_y] = 'O';
               g.myGrid[g.i_x - 1][g.i_y] = 'i';
               g.i_x = g.i_x - 1;
           }
         }

       }
       if (g.i_x + 1 < row)
       {
         if(g.myGrid[g.i_x + 1][g.i_y] == '.' || g.myGrid[g.i_x + 1][g.i_y] == 'g')
         {

         }
           cout << "Down" << endl;
           node++;
           tempDis = getManhatDist(g.i_x + 1, g.i_y, g.gl_x, g.gl_y) +cost;
           if (tempDis <= manhatDist)
           {
               manhatDist = tempDis;
               g.myGrid[g.i_x][g.i_y] = 'O';
               g.myGrid[g.i_x + 1][g.i_y] = 'i';
               g.i_x = g.i_x + 1;
           }
       }
       if (g.i_y - 1 > -1 && (g.myGrid[g.i_x][g.i_y - 1] == '.' || g.myGrid[g.i_x][g.i_y - 1] == 'g'))
       {
           cout << "Left" << endl;
           node++;
           tempDis = getManhatDist(g.i_x, g.i_y - 1, g.gl_x, g.gl_y)+ cost;
           if (tempDis <= manhatDist)
           {
               manhatDist = tempDis;
               g.myGrid[g.i_x][g.i_y] = 'O';
               g.myGrid[g.i_x][g.i_y - 1] = 'i';
               g.i_y = g.i_y - 1;
           }
       }
       if (g.i_y + 1 < row)
       {
         if(g.myGrid[g.i_x][g.i_y + 1] == '.' || g.myGrid[g.i_x][g.i_y + 1] == 'g')
         {
           cout << "Right" << endl;
           node++;
           tempDis = getManhatDist(g.i_x, g.i_y + 1, g.gl_x, g.gl_y)+ cost;
           if (tempDis <= manhatDist)
           {
               manhatDist = tempDis;
               g.myGrid[g.i_x][g.i_y] = 'O';
               g.myGrid[g.i_x][g.i_y + 1] = 'i';
               g.i_y = g.i_y + 1;
           }
         }
       }

       cost++;
   }
   g.printGrid();
   cout << "The cost would be: " << cost << endl;
}

void Search::AllStratagies(){
  this->Search::Euclidian();
  this->Search::Mahattan();
  this->Search::AstarE();
  this->Search::AstarM();
}

//formulas for Euclidian and Manhattan distance
double Search::getEucliDist(int i_x, int i_y,int gl_x, int gl_y)
{
  return sqrt((i_x - gl_x)*(i_x - gl_x)+(i_y - gl_y)*(i_y- gl_y));
}
double Search::getManhatDist(int i_x, int i_y, int gl_x, int gl_y)
{
  return abs((i_x - gl_x)+ (i_y - gl_y));

}

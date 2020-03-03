#include <fstream>
#include <iostream>
#include "Grid.h"

using namespace std;

class Search{
public:
  Search();
  ~Search();




  double getEucliDist(int i_x, int i_y,int gl_x, int gl_y);
  double getManhatDist(int i_x, int i_y, int gl_x, int gl_y);
  void evalDist(double EuclidDist, double ManhatDist);
  void Euclidian();
  void Mahattan();
  void AstarE();
  void AstarM();
  void nameOfFile();
  void AllStratagies();

  string fileName;
  int row;
  int column;
  Grid g;
  File f;
  int cost;
  int node;
  double eucliDist;
  double manhatDist;

};

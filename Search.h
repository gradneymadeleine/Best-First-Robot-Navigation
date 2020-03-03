#include <fstream>
#include <iostream>
#include "Grid.h"

using namespace std;

class Search{
public:
  Search();
  ~Search();



  double eucliDist();
  double manhatDist();
  double getEucliDist(int intial_x, int intial_y,int goal_x, int goal_y);
  double getManhatDist(int intial_y, int intial_y, int goal_x, int goal_y);
  void evalDist(double EuclidDist, double ManhatDist);
  void Euclidian();
  void Mahattan();
  
  string fileName;
  int row;
  int column;
  Grid g;
  File f;
  int cost;




}

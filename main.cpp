#include<iostream>
#include<fstream>
#include "Search.h"
#include

using namespace std;

int main(int argc, char** argv)
{
  Search s;
  cout << "What is the name of your file?" << endl;
  s.Euclidian();
  s.Mahattan();
  s.AstarE();
  s.AstarM();
}

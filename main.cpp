#include<iostream>
#include<fstream>
#include "Search.h"

using namespace std;

int main(int argc, char** argv)
{
  Search s;
  s.Euclidian();

  cout<<"\n\n\n\n\n\n" <<endl;
  s.Mahattan();

  cout<<"\n\n\n\n\n\n" <<endl;
  s.AstarE();

  cout<<"\n\n\n\n\n\n" <<endl;
  s.AstarM();
}

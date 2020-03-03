#include <iostream>
#include <fstream>

using namespace std;

class File{
public:
  File(); //default constructor
  File(string filename);


  string readLine(); //reads readLine
  void getFile();
  int getFileRow();
  int getFileColum();

  ifstream inFile;
  int fileRow;
  int fileColumn;
  string fileName;
  string line;
};

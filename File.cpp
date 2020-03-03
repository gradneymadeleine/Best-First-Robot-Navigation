#include "File.h"
#include <iostream>
#include <fstream>

using namespace std;
File::File(){
   fileRow =0;
   fileColumn=0;
   fileName = "";
   line ="";
   fileName ="name.txt";
   ifstream inFile(fileName);

 }

 File::File(string filename){
   fileRow =0;
   fileColumn=0;
   fileName = filename;
   line ="";
   fileName = filename;
   ifstream inFile(fileName);

 }

 void File::getFile(){
   if(!inFile){
     cout<<"File does not exist." << endl;
     exit(0);
   }
   inFile.open(fileName);
   getline(inFile,line);
   fileRow = stoi(line); //siting to int is parsed
 }

 int File::getFileRow(){
   return fileRow;
 }

 int File::getFileColum(){
   return fileColumn;
 }

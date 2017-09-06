#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#include "../../HashTable.h"

int getSizeFromFilename(string filename) {
#define SMALL_SIZE 20
#define MEDIUM_SIZE 60
#define LARGE_SIZE 130
  if( !filename.compare("input_small.txt") ) 
    return SMALL_SIZE;
  if( !filename.compare("input_medium.txt") ) 
    return MEDIUM_SIZE;
  if( !filename.compare("input_large.txt") ) 
    return LARGE_SIZE;
}

int main(int argc, char *argv[]) {
  string filename;
  cout << "Enter input filename: ";
  cin >> filename;
  cout << endl;
  ifstream file (filename.c_str());
  if (!file.is_open()) {
    cout << "Unable to open file " << filename;
    return -1;    
  }
  int size = getSizeFromFilename(filename);
  HashTable table(size), t1, t2;
  
  int i=0; 
  while ( !file.eof() ) {
    string word;
    file >> word;    
    table << word;
  }  
  table.print();
  t1 = t2 = table;
  cout << "#######################" << endl;
  t1.print();
  cout << "#######################" << endl;
  t2.print();
}
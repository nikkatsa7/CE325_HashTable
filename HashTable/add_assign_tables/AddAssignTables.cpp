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
  string filename1, filename2;
  cout << "Enter input filename1: ";
  cin >> filename1;
  cout << "Enter input filename2: ";
  cin >> filename2;
  cout << endl;
  ifstream file1 (filename1.c_str());
  if (!file1.is_open()) {
    cout << "Unable to open file " << filename1;
    return -1;    
  }
  int size = getSizeFromFilename(filename1);
  HashTable table1(size);
  ifstream file2 (filename2.c_str());
  if (!file2.is_open()) {
    cout << "Unable to open file " << filename2;
    return -1;    
  }
  size = getSizeFromFilename(filename2);
  HashTable table2(size), table3;
  
  int i=0; 
  while ( !file1.eof() ) {
    string word;
    file1 >> word;    
    table1 << word;
  }  
  table1.print();
  cout << "#######################" << endl;
  while ( !file2.eof() ) {
    string word;
    file2 >> word;    
    table2 << word;
  }  
  table2.print();
  cout << "#######################" << endl;
  table1 += table2;
  table1.print();  
}
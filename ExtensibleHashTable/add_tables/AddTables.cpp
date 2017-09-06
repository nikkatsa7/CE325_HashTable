#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#include "../../ExtensibleHashTable.h"

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
  
  ExtensibleHashTable table1;
  ifstream file2 (filename2.c_str());
  if (!file2.is_open()) {
    cout << "Unable to open file " << filename2;
    return -1;    
  }
  
  ExtensibleHashTable table2, table3;
  
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
  table3 = table1 + table2;
  table3.print();
  
}
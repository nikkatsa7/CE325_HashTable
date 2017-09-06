#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <ctype.h>
#include <algorithm>
using namespace std;
#include "../../ExtensibleHashTable.h"

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
  ExtensibleHashTable table; 
  
  while ( !file.eof() ) {
    string word;
    file >> word;    
    table << word;
  }  
  table.print();  
}
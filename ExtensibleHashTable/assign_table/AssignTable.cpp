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
  ExtensibleHashTable table, t1, t2;
  
  int i=0; 
  while ( !file.eof() ) {
    string word;
    file >> word;    
    table << word;
  }
  table.print();
  
  while(true) {
    string word;
    cout << "Enter word to search for (or \"quit\" to exit): ";
    cin >> word;    
    if(!word.compare("quit") )
      break;
    if( table >> word ) 
      cout << "Word: \"" << word << "\" removed :)" << endl;
    else
      cout << "Word: \"" << word << "\" not found :(" << endl;
  }
  cout << endl;
  table.print();
  
  t1 = t2 = table;
  cout << "#######################" << endl;
  t1.print();
  cout << "#######################" << endl;
  t2.print();
}
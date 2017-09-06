
#ifndef __EXTENSIBLE_HASHTABLE_H__
#define __EXTENSIBLE_HASHTABLE_H__

#include "HashTable.h"

#include <string>
using namespace std;

class ExtensibleHashTable: public HashTable {
private:
  double upper_bound_ratio, lower_bound_ratio;
  void rehash();
  void rehash(int newcapacity);
  
public:
  ExtensibleHashTable(double upper_bound_ratio=0.5, 
                      double lower_bound_ratio=0.125, 
                      int size=8);  
  ExtensibleHashTable(const ExtensibleHashTable &t); 
  bool add(const string &str);
  bool remove(const string &str);  
  //bool operator << (string str);
  //bool operator >> (string str);
  ExtensibleHashTable operator+(const ExtensibleHashTable &t) const;
  ExtensibleHashTable &operator+=(const ExtensibleHashTable &t);
  ExtensibleHashTable &operator=(const ExtensibleHashTable &t);
  
};

#endif

#ifndef __EXTENSIBLE_HASHTABLE_H__
#define __EXTENSIBLE_HASHTABLE_H__

#include "HashTable.h"

#include <string>
using namespace std;

class ExtensibleHashTable: public HashTable {
private:
  double upper_bound_ratio, lower_bound_ratio;
  void rehash();
  
public:
  ExtensibleHashTable(double upper_bound_ratio=0.5, 
                      double lower_bound_ratio=0.125, 
                      int size=8);  
  ExtensibleHashTable(const ExtensibleHashTable &t); 
  bool add(const string &str);
  bool remove(const string &str);  
  bool operator << (string str);
  bool operator >> (string str);
  ExtensibleHashTable operator+(const ExtensibleHashTable &t) const;
  // ExtensibleHashTable &operator+=(const ExtensibleHashTable &t);
  // ExtensibleHashTable &operator=(const ExtensibleHashTable &t);
  
};

ExtensibleHashTable::ExtensibleHashTable(double upper_bound_ratio,double lower_bound_ratio,int size):
  HashTable(size),upper_bound_ratio(upper_bound_ratio),lower_bound_ratio(lower_bound_ratio){} 

ExtensibleHashTable::ExtensibleHashTable(const ExtensibleHashTable &t):
HashTable(t),upper_bound_ratio(upper_bound_ratio),lower_bound_ratio(lower_bound_ratio){}

void ExtensibleHashTable::rehash(){
  
  if((size/capacity)>this->upper_bound_ratio){
    // cout << "upper! hit" << endl;
    string *buffer;
    buffer = new string[this->capacity];

    for(int i=0;i<this->capacity;i++){
      buffer[i] = this->table[i];
    }

    this->capacity = capacity*2;
    delete []this->table;
    this->size=0;
    this->table = new string[this->capacity];

    for(int i=0;i<this->capacity/2;i++){
      HashTable::add(buffer[i]);
    }

  } else if((size/capacity)<this->lower_bound_ratio){
    // cout << "lower! hit" << endl;

    string *buffer;
    buffer = new string[this->capacity];

    for(int i=0;i<this->capacity;i++){
      buffer[i] = this->table[i];
    }

    this->capacity = capacity/2;
    delete []this->table;
    this->size=0;
    this->table = new string[this->capacity];

    for(int i=0;i<this->capacity*2;i++){
      HashTable::add(buffer[i]);
    }
  }
}

bool ExtensibleHashTable::add(const string &str){
  HashTable::add(str);
  rehash();
}

bool ExtensibleHashTable::remove(const string &str){
  HashTable::remove(str);
  rehash();
}

bool ExtensibleHashTable::operator>>(string str){
  return  add(str);
}

bool ExtensibleHashTable::operator<<(string str){
  return  remove(str);
}
 
ExtensibleHashTable ExtensibleHashTable::operator+(const ExtensibleHashTable &t) const{
  ExtensibleHashTable ht(upper_bound_ratio,lower_bound_ratio,capacity+t.capacity);

  cout << "new HashTable capacity " << ht.HashTable::capacity << endl;

  for(int i = 0;i<this->capacity;i++){
    ht.add(this->table[i]);
    cout << "now adding from the first " << this->table[i] << endl;
  }
  for(int i = 0;i<t.capacity;i++){
    ht.add(t.table[i]);
    cout << "now adding from the second " << t.table[i] << endl;

  }
  return ht;
}

#endif
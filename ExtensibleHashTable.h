
#ifndef __EXTENSIBLE_HASHTABLE_H__
#define __EXTENSIBLE_HASHTABLE_H__

#include "HashTable.h"

#include <string>
using namespace std;

class ExtensibleHashTable: public HashTable {
private:
  double upper_bound_ratio, lower_bound_ratio;
  void rehash();
  bool hitUpper();
  bool hitLower();

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
  ExtensibleHashTable &operator+=(const ExtensibleHashTable &t);
  ExtensibleHashTable &operator=(const ExtensibleHashTable &t);

};

ExtensibleHashTable::ExtensibleHashTable(double upper_bound_ratio,double lower_bound_ratio,int size):
  HashTable(size),upper_bound_ratio(upper_bound_ratio),lower_bound_ratio(lower_bound_ratio){}

ExtensibleHashTable::ExtensibleHashTable(const ExtensibleHashTable &t):
HashTable(t),upper_bound_ratio(upper_bound_ratio),lower_bound_ratio(lower_bound_ratio){}

bool ExtensibleHashTable::hitUpper(){
  return(((double(this->size)/double(this->capacity)))>this->upper_bound_ratio);
}

bool ExtensibleHashTable::hitLower(){
  return(((double(this->size)/double(this->capacity)))<this->lower_bound_ratio);
}

void ExtensibleHashTable::rehash(){
  ExtensibleHashTable rht;
  int newCapacity;

  if(hitUpper()){
    newCapacity = this->capacity*2;

  }else if(hitLower()){
    newCapacity = this->capacity/2;

  } else{
    return;
  }

  rht.capacity = newCapacity;
  rht.table = new string [rht.capacity];
  rht.size = 0;

  for(int i=0; i<this->capacity; i++){
    rht.HashTable::add(this->table[i]);
  }
  
  this->capacity = rht.capacity;

  if(this->table!=nullptr) {
    delete[] this->table;
  }
  this->table = new string [this->capacity];
  for(int i=0; i<this->capacity;i++){
    this->table[i] = rht.table[i];
  }
}

bool ExtensibleHashTable::add(const string &str){
  if(this->HashTable::add(str)){
    this->rehash();
    return true;
  }else{
    return false;
  }
}

bool ExtensibleHashTable::remove(const string &str){
  if(this->HashTable::remove(str)){
    this->rehash();
    return true;
  }else{
    return false;
  }
}

bool ExtensibleHashTable::operator<<(string str){
  return this->add(str);
}

bool ExtensibleHashTable::operator>>(string str){
  return this->remove(str);
}

ExtensibleHashTable ExtensibleHashTable::operator+(const ExtensibleHashTable &t) const{
  ExtensibleHashTable ht;

  for(int i = 0;i<this->capacity;i++){
    ht.add(this->table[i]);
  }
  ht.print();

  cout << endl;

  for(int i = 0;i<t.capacity;i++){
    ht.add(t.table[i]);
  }

  ht.print();

  return ht;
}

ExtensibleHashTable &ExtensibleHashTable::operator+=(const ExtensibleHashTable &t){
  for(int i=0;i<t.capacity;i++){
    this->add(t.table[i]);
  }
  return *this;
}


ExtensibleHashTable &ExtensibleHashTable::operator=(const ExtensibleHashTable &t){
  this->capacity = t.capacity;
  this->size = t.size;
  delete []this->table;
  this->table = new string[this->capacity];
  for(int i=0;i<t.capacity;i++)
    this->table[i] = t.table[i];

  return *this;
}

#endif

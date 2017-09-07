
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
  static bool checkDeadOrEmpty(const string &s);
  static bool checkDeadOrEmpty(const char * s);

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

bool ExtensibleHashTable::hitUpper(){
  return(((this->size/this->capacity))>this->upper_bound_ratio);
}

bool ExtensibleHashTable::hitLower(){
  return(((this->size/this->capacity))<this->lower_bound_ratio);
}

void ExtensibleHashTable::rehash(){
  //tou gamietai i poutana h mana
  ExtensibleHashTable rht;
  int newCapacity;

  if(hitUpper()){
    cout << "Upper bound hit!" << endl;

    newCapacity = this->capacity*2;
    
  }else if(hitLower()){
    cout << "Lower bound hit!" << endl;

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

  rht.print();

  this->size = rht.size;
  this->capacity = rht.capacity;

  if(this->table!=nullptr) {
    delete[] this->table;
  }  
  for(int i=0; i<this->capacity;i++){
    this->table[i] = rht.table[i]; 
  }
}


bool ExtensibleHashTable::checkDeadOrEmpty(const string &s){
  if(s == "" || s == "##tomb##")
    return true;
  else
    return false;
}

bool ExtensibleHashTable::checkDeadOrEmpty(const char *s){
  if(s == "" || s == "##tomb##")
    return true;
  else
    return false;
}

bool ExtensibleHashTable::add(const string &str){
  if(HashTable::add(str)){
    rehash();
    return true;
  }else{
    return false;
  }
} 

bool ExtensibleHashTable::remove(const string &str){
  if(HashTable::remove(str)){
    rehash();
    return true;
  }else{
    return false;
  }
}

bool ExtensibleHashTable::operator<<(string str){
  return add(str);
}

bool ExtensibleHashTable::operator>>(string str){
  return  remove(str);
}
 
ExtensibleHashTable ExtensibleHashTable::operator+(const ExtensibleHashTable &t) const{
  ExtensibleHashTable ht(upper_bound_ratio,lower_bound_ratio,capacity+t.capacity);

  cout << "new HashTable capacity " << ht.HashTable::capacity << endl;

  for(int i = 0;i<this->capacity;i++){
    if(ht.add(this->table[i]))
      cout << "now adding from the first " << this->table[i] << endl;
  }
  for(int i = 0;i<t.capacity;i++){
    if(ht.add(t.table[i]))
      cout << "now adding from the second " << t.table[i] << endl;

  }
  return ht;
}

#endif
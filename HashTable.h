
#ifndef __HASHTABLE_H__
#define __HASHTABLE_H__

//#include "HashTableIterator.h"
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class HashTable {
 
protected:
  unsigned int size;
  unsigned int capacity;
  string *table;
  static int getHashCode(const char *str);
  static bool checkDeadOrEmpty(const string &s);
  static bool checkDeadOrEmpty(const char * s);

public:
  class Iterator;
  
  HashTable(int size=8);
  HashTable(const HashTable &ht);
  int getSize();
  int getCapacity();
  bool isEmpty(int pos);
  bool isTomb(int pos);
  bool isAvailable(int pos);
  bool contains(const string &s);
  bool contains(const char *s);
  virtual bool add(const string &s);
  virtual bool add(const char *s);
  virtual bool remove(const string &s);
  virtual bool remove(const char *s);
  Iterator begin() const;
  Iterator end() const; 
  void print() ;
  
  virtual bool operator << (string str);
  virtual bool operator >> (string str);
  HashTable operator+(const HashTable &ht);
  HashTable &operator+=(const HashTable &t);
  HashTable &operator=(const HashTable &t);
  
  class Iterator {
    string *p, *end;    
  public:    
    Iterator operator++();
    Iterator operator--();
    Iterator operator++(int a);
    Iterator operator--(int a);
    bool operator<(Iterator it);
    string &operator*();
    friend Iterator HashTable::begin() const;
    friend Iterator HashTable::end() const;
  };
};

HashTable::HashTable(int size){
  this->size = 0;
  capacity = size;
  table = new string[capacity];
}

HashTable::HashTable(const HashTable &ht){
  this->size = ht.size;
  this->capacity = ht.capacity;
  this->table = new string[ht.capacity];
}

void HashTable::print() {
  for(int i=0;i<capacity;i++){
    if(!isAvailable(i)){
      cout << i << " : " << table[i]<< endl;
    }
  }
  cout << "# capacity: " << capacity << "\n# size: " << size << endl;
}

int HashTable::getHashCode(const char *str){
  int hash = 0;
  for(int i=0;i<strlen(str);i++){
    char c = str[i];
    hash += int(c);
  }
  #ifdef DEBUG
    cout << "Computed hash " << hash << " for word " << str << endl;
  #endif

  return(hash);
}

bool HashTable::checkDeadOrEmpty(const string &s){
  if(s == "" || s == "##tomb##")
    return true;
  else
    return false;
}

bool HashTable::checkDeadOrEmpty(const char *s){
  if(s == "" || s == "##tomb##")
    return true;
  else
    return false;
}

int HashTable::getSize(){
  return(size);
}

int HashTable::getCapacity(){
  return(capacity);
}

bool HashTable::isEmpty(int pos){
  if(pos>= capacity){
    return(false);
  }else if(table[pos] == ""){
    return(true);
  }else{
    return(false);
  }
}

bool HashTable::isTomb(int pos){
  if(pos>= capacity){
    return(false);
  }else if(table[pos] == "##tomb##"){
    return(true);
  }
  return(false);
}

bool HashTable::isAvailable(int pos){
  if(isEmpty(pos) || isTomb(pos)){
    return (true);
  } 
  return(false);
}

bool HashTable::contains(const string &s){
	for(int i=0;i<capacity;i++){
    #ifdef DEBUG
    cout << "checking " << s << " with " << table[i] << endl;
    #endif
		if(s == table[i]){
			return(true);
		}
	}
	return(false);
}

bool HashTable::contains(const char *s){
  for(int i=0;i<capacity;i++){
    #ifdef DEBUG
    cout << "checking " << s << " with " << table[i] << endl;
    #endif
		if(s == table[i]){
      return(true);
		}
	}
	return(false);
}

bool HashTable::add(const string & s){
  int hash = getHashCode(s.c_str()) % capacity;
  if(contains(s) && checkDeadOrEmpty(s)){
    return false;
  } else{
    for (int i=0; i<capacity;i++){
      if(isAvailable((hash+i)%capacity)){
        table[(hash+i)%capacity] = s;
        size++;
        return true;
      }
    }
    return false;
  }
}

bool HashTable::add(const char * s){
  int hash = getHashCode(s) % capacity;
  if(contains(s) && checkDeadOrEmpty(s)){
    return false;
  } else{
    for (int i=0; i<capacity;i++){
      if(isAvailable((hash+i)%capacity)){
        table[(hash+i)%capacity] = s;
        size++;
        return true;
      }
    }
    return false;
  }
}

bool HashTable::remove(const string & s){
  if(!contains(s)){
    return false;
  } else{
    for (int i=0; i<capacity;i++){
      if(table[i] == s){
        table[i] = "##tomb##";
        size--;
        return true;
      }
    }
    return false;
  }
}

bool HashTable::remove(const char * s){
  if(!contains(s)){
    return false;
  } else{
    for (int i=0; i<capacity;i++){
      if(table[i] == s){
        table[i] = "##tomb##";
        size--;
        return true;
      }
    }
    return false;
  }
}

bool HashTable::operator << (string str){
  return add(str);
}

bool HashTable::operator >> (string str){
  return remove(str);
}

HashTable HashTable::operator+(const HashTable &ht){
  HashTable newHt(this->capacity + ht.capacity);
  // newHt.capacity = this->capacity + ht.capacity;
  // newHt.size = 0;
  // newHt.table = new (nothrow) string[newHt.capacity];
  
  if(newHt.table == nullptr){
    cerr << "memory allocation problem" << endl;
    exit(-1);
  }
  for(int i=0;i<capacity;i++){
    newHt.add(table[i]);
  }
  for(int i=0;i<ht.capacity;i++){
    newHt.add(ht.table[i]);
  }
  
  return newHt;
}

HashTable &HashTable::operator+=(const HashTable &t){
  string *tableBuffer;
  tableBuffer = new string[capacity];
  if(tableBuffer == nullptr){
    cerr << "memory allocation problem" << endl;
    exit(-1);
  }
  for(int i=0;i<capacity;i++){
    tableBuffer[i] = this->table[i];
  }
  delete []this->table;
  this->capacity = capacity+t.capacity;
  this->size = 0;
  this->table = new string[capacity];
  if(this->table == nullptr){
    cerr << "memory allocation problem" << endl;
    exit(-1);
  }

  for(int i=0;i<capacity-t.capacity;i++){
    add(tableBuffer[i]);
  }
    cout << "here" << endl;

  for(int i=0;i<t.capacity;i++){    
    add(t.table[i]);
  }
}

HashTable &HashTable::operator=(const HashTable &t){
  delete []this->table;
  this->capacity = t.capacity;
  this->size = 0;
  this->table = new string[t.capacity];
  if(this->table == nullptr){
    cerr << "memory allocation problem" << endl;
    exit(-1);
  }
  for(int i=0;i<this->capacity;i++){
    add(t.table[i]);
  }
  return *this;
}


#endif
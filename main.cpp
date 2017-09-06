#include <iostream>
#include <string.h>
#include <string>
#include "HashTable.h"

// #define DEBUG

using namespace std;

int main() {

	HashTable ht1(10);
    ht1.add("o");
    ht1.add("leonidas");
    ht1.add("bgazei");
    ht1.add("lefta");
    
    ht1.print();

    HashTable ht2(12);
    ht2.add("kai");
    ht2.add("o");
    ht2.add("Nikos");
    ht2.print();

    ht1 = ht2;
    ht1.print();
    ht1.add("bgazei");
    ht1.print();



	return 0;
}
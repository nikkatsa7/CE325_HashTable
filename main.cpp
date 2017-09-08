#include <iostream>
#include <string.h>
#include <string>
// #include "HashTable.h"
#include "ExtensibleHashTable.h"

// #define DEBUG
// #define CHECK_HASH

#ifndef CHECK_HASH
#define CHECK_EXTENTED_HASH
#endif

using namespace std;

int main() {

#ifdef CHECK_HASH
	HashTable ht1(10);
    ht1.add("o");
    ht1.add("leonidas");
    ht1.add("bgazei");
    ht1 << "lefta";
    ht1.print();

    ht1 >> "bgazei";
    ht1.remove("lefta");
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
#endif

#ifdef CHECK_EXTENTED_HASH

    ExtensibleHashTable eht;
    // ExtensibleHashTable ht1(0.8,0.3,10);
    // ExtensibleHashTable ht2;
		cout << "Here" << endl;
    eht.add("a");
    eht.add("b");
    eht.add("c");
    eht.add("d");
		eht.add("g");
    eht.add("e");
    eht.add("f");
		eht << "nikos";
		eht.add("r");
    eht.print();

    // ht1.add("ena");
    // ht1.add("duo");
    // ht1.add("tria");
    // ht1.add("tessera");
    // ht1.add("pente");
    // ht1.add("eksi");
    // ht1.print();

    // ht2 = ht+ht1;
    // ht2.print();
#endif
    return 0;
}

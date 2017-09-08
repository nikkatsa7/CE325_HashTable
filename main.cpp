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

    ExtensibleHashTable eht,eht1,eht2,eht3;

		eht << "a";
		eht << "b";
		eht << "c";
		eht << "d";
		eht << "e";
		eht << "f";
		eht << "h";
		eht << "j";
		eht << "k";
		eht << "l";

		eht.print();

		eht >> "c";
		eht >> "d";
		eht >> "b";
		eht >> "k";
		eht >> "l";
		eht >> "j";
		eht >> "c";
		eht >> "d";
		eht >> "a";
		eht.print();

#endif
    return 0;
}

#include <iostream>
#include <string.h>
#include <string>
// #include "HashTable.h"
#include "ExtensibleHashTable.h"

// #define DEBUG

using namespace std;

int main() {

	// HashTable ht1(10);
 //    ht1.add("o");
 //    ht1.add("leonidas");
 //    ht1.add("bgazei");
 //    ht1.add("lefta");
    
 //    ht1.print();

 //    HashTable ht2(12);
 //    ht2.add("kai");
 //    ht2.add("o");
 //    ht2.add("Nikos");
 //    ht2.print();

 //    ht1 = ht2;
 //    ht1.print();
 //    ht1.add("bgazei");
 //    ht1.print();


    ExtensibleHashTable ht(0.8,0.2,5);
    ExtensibleHashTable ht1(0.8,0.2,10);
    ExtensibleHashTable ht2;
    // for (int i=0;i<16;i++){
    //     ht.add("str no: " + to_string(i));
    //     ht.print();
    // }

    ht.add("ena");
    ht.add("duo");
    ht.add("tria");
    ht.print();

    ht1.add("ena");
    ht1.add("duo");
    ht1.add("tria");
    ht1.add("tessera");
    ht1.add("pente");
    ht1.add("eksi");
    ht1.print();

    // ht2 = ht+ht1;
    // ht2.print();
    	
    return 0;
}
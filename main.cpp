#include "LinkedList.h"
#include <iostream>
#define printLine(x) std::cout << x << std::endl;



int main() {
    LinkedList numbers;

    printLine("Appending 10, 20, and 30");
    numbers.append(10);
    numbers.append(20);
    numbers.append(30);
    numbers.print();

    printLine("Inserting 15 at position 0");
    numbers.insert(15, 0);
    numbers.print();

    printLine("Destroying node at position 2");
    numbers.destroy(2);
    numbers.print();

    return 0;
}

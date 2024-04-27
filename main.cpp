#include <iostream>
#include "dictionary.h"
using namespace std;
int main(int argc, char **argv) {
    Dictionary d = Dictionary();

    d.insert(31, "Nuno");
    std::cout << "Inserted 1st item" << std::endl;
    d.insert(24, "Amalio");
    std::cout << "Inserted 2nd item" << std::endl;

    std::cout << "The item with key 1 is " << *(d.lookup(31)) << std::endl;
    std::cout << "The item with key 2 is " << *(d.lookup(24)) << std::endl;

    d.insert(24, "Rodrigues");

    std::cout << "The item with key 2 is " << *(d.lookup(24)) << std::endl;

    d.insert(37, "Nottingham");

    std::cout << "The item with key 3 is " << *(d.lookup(37)) << std::endl;

 //   d.remove(3);

  //  d.rotateright(2);

    d.displayTree();
//    d.remove(3);

//    d.displayTree();

//    d.insert(3, "Nottingham");

//    d.displayTree();

//    d.remove(2);

//    d.displayTree();

//    d.insert(2, "Amalio");

//    d.displayTree();

//    d.remove(1);

//    d.displayTree();
//    d.remove(2);
//    d.remove(3);
//    d.displayTree();

//    d.insert(31,"Anne");
//    d.insert(7,"John");
//    d.insert(42,"Elizabeth");
//    d.displayTree();
//    d.remove(31);
//    d.displayTree();

    return 0;
}

#include "class.h"

int main() {
    Time t1(16, 18, 3);
    t1.printFormat1(); 
    t1.printFormat2(); 

    Time t2;
    t2.setTime(9, 45, 30);
    t2.printFormat1(); 
    t2.printFormat2(); 

    return 0;
}
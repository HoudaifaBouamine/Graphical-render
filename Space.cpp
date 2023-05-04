#include <iostream>
#include "clsSpace.h"
#include "clsCube.h"
using namespace std;

int main(){
    
    //clsCube c(space(50,50,50),15);
    clsCube c(space(100, 100, 100), 30);
    //clsCube c(space(250, 250, 250), 70);

    c.print();

    system("pause>0");
    
    c.move(-1, 5,5,5);
   

    return 0;
}

#include <iostream>
#include "clsSpace.h"
#include "clsCube.h"
using namespace std;

int main(){
    
    clsCube c(space(90,90,90),35);
    //clsCube c(space(100, 100, 100), 30);
    //clsCube c(space(250, 250, 250), 70);

    c.print();

    system("pause>0");
    
    c.move(-1, 3,3,3);
   

    return 0;
}

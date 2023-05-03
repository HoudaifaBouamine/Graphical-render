#include <iostream>
#include "cls2dScreen.h"


int main() {

	cls2dScreen screen(32);

	while (true) {
		screen.print();
		screen.angle_oz += 0.001;
		//system("pause>1");
	}


	return 0;
}
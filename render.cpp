#include <iostream>
#include "cls2dScreen.h"
using namespace std;

int main() {

	cls2dScreen screen(32);

	while (true) {
		screen.print();
		screen.angle_oz += 0.1;
	}

	return 0;
}
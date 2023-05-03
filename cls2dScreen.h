#pragma once
#include <iostream>
#define ll int
using namespace std;

class cls2dScreen
{

private:

	ll* _ptr = nullptr;
	char _length = 0;

	

public :

	void clear() {
		char length = _length;
		while (length--)
			_ptr[length] = 0;
	}

	cls2dScreen(char length) {
		_length = length;
		_ptr = new ll[_length];
		clear();
	}
	
	void draw_point(char x,char y) {

		ll pos_x = 1 << x;
		_ptr[y] = _ptr[y] | pos_x;
	}

	char eye_x = 20, eye_y = 20, eye_z = -30;

	pair<char,char> from_3d_to_2d(char x,char y,char z) {

		routate(x,y,z);

		pair<char, char> p;

		p.first = eye_x + (float)(-eye_z) * ((float)(x - eye_x)) / ((float)(z - eye_z));
		p.second = eye_y +  (float)(-eye_z) * ((float)(y - eye_y)) / ((float)(z -eye_z));

		return p;
	}

	void draw_cube() {
		char d = 30;

		pair<char, char> p[8];

		p[0] = from_3d_to_2d(10, 30, d);
		p[1] = from_3d_to_2d(30, 30, d);
		p[2] = from_3d_to_2d(10, 30, d + 20);
		p[3] = from_3d_to_2d(30, 30, d + 20);

		p[4] = from_3d_to_2d(10, 10, d);
		p[5] = from_3d_to_2d(30, 10, d);
		p[6] = from_3d_to_2d(10, 10, d + 20);
		p[7] = from_3d_to_2d(30, 10, d + 20);

		d = 8;

		while (d--)
			draw_point(p[d].first,p[d].second);
	}


	float angle_ox = 0;
	float angle_oy = 0;
	float angle_oz = 0;

	void routate(char& x,char& y,char& z) {

		char X = (x - 15) * cos(angle_oz) - (y - 15) * sin(angle_oz);
		char Y = (y - 15) * cos(angle_oz) + (x - 15) * sin(angle_oz);

		x = X + 15;
		y = Y + 15;
	}

	void print() {
		
		clear();
		draw_cube();

		string show = "";	

		for (char i = 0; i < _length; i++) {

			for (ll j = 1; j != 0; j = j << 1) {
				show += ((_ptr[i] & j) == j) ? '#' : ' ';
				show += ' ';
			}
			
			show += '\n';
		}
		system("cls");
		cout << show << endl;

		//char* ptr = &show;
		//copy(_ptr, _ptr + _length - 1, ostream_iterator<ll>(cout, "\n"));

	}
};


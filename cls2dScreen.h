#pragma once
#include <iostream>
#define ll int
using namespace std;

class cls2dScreen
{

private:

	ll* _ptr = nullptr;
	char _length = 0;

	float angle_ox = 0;
	float angle_oy = 0;
	float angle_oz = 0;


public :

	cls2dScreen(char length) {
		_length = length;
		_ptr = new ll[_length];
		while (length--)
			_ptr[length] = 0;
	}
	
	void draw_point(char x,char y) {

		ll pos_x = 1 << x;
		_ptr[y] = _ptr[y] | pos_x;
	}

	char eye_x = 30, eye_y = 30, eye_z = -40;

	pair<char,char> from_3d_to_2d(char x,char y,char z) {

		char des = eye_z * -1;

		float alpha = (float)(des) * ((float)(abs(eye_x - x))) / ((float)(z + des));
		float beta = (float)(des) * ((float)(abs(eye_y - y))) / ((float)(z + des));
		pair<char, char> p;
		p.first = x - des * tan(alpha);
		p.second = y - des * tan(beta);

		return p;
	}

	void draw_cube() {
		char d = 100;

		pair<char, char> p[8];

		p[0] = from_3d_to_2d(10, 30, d);
		p[1] = from_3d_to_2d(30, 30, d);
		p[2] = from_3d_to_2d(10, 30, d + 20);
		p[3] = from_3d_to_2d(30, 30, d + 20);

		p[4] = from_3d_to_2d(10, 10, d);
		p[5] = from_3d_to_2d(30, 10, d);
		p[6] = from_3d_to_2d(10, 10, d + 20);
		p[7] = from_3d_to_2d(30, 10, d + 20);

		d = 7;

		while (d--)
			draw_point(p[d].first,p[d].second);
	}

	void routate(char& x,char& y,char& z) {

		char X = x * cos(angle_oz) - y * sin(angle_oz);
		char Y = y * cos(angle_oz) + x * sin(angle_oz);

		x = X;
		y = Y;
	}

	void print() {
		
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


#pragma once
#include <iostream>
using namespace std;
#define ll int

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

	char _get_y(pair<char, char> pt1, pair<char, char> pt2,char x) {

		return ((pt1.second - pt2.second)*(pt1.first + x) / ((pt1.first - pt2.first == 0) ? 1 : pt1.first - pt2.first));
	}

	void link2points(pair<char, char> pt1, pair<char, char> pt2) {

		float a = ((float)pt2.second - pt1.second) / (float)(pt2.first - pt1.first);

		for (char i = 0; (i <pt2.first - pt1.first - 1); i++)
		{
			draw_point(pt1.first + i,pt1.second + i * a );
		}
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
			draw_point(p[d].first, p[d].second);

	/*	link2points(p[0], p[1]);
		link2points(p[0], p[4]);
		link2points(p[0], p[2]);

		link2points(p[3], p[2]);
		link2points(p[3], p[7]);
		link2points(p[3], p[1]);

		link2points(p[6], p[4]);
		link2points(p[6], p[2]);
		link2points(p[6], p[7]);

		link2points(p[5], p[7]);
		link2points(p[5], p[4]);
		link2points(p[5], p[1]); */
	}


	float angle_ox = 0;
	float angle_oy = 0;
	float angle_oz = 0;

	void routate(char& x,char& y,char& z) {

		char X = (x - 15) * cos(angle_oz) - (y - 15) * sin(angle_oz);
		char Y = (y - 15) * cos(angle_oz) + (x - 15) * sin(angle_oz);

		x = X + 15;
		y = Y + 15;

		char Z = (z - 15) * cos(angle_ox) - (y - 15) * sin(angle_ox);
		Y = (y - 15) * cos(angle_ox) + (z - 15) * sin(angle_ox);

		x = X + 15;
		y = Y + 15;

		/*char X = (x - 15) * cos(angle_oz) - (y - 15) * sin(angle_oz);
		char Y = (y - 15) * cos(angle_oz) + (x - 15) * sin(angle_oz);

		x = X + 15;
		y = Y + 15;*/
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
		cout << show << endl;

		
		
		//char* ptr = &show;
		//copy(_ptr, _ptr + _length - 1, ostream_iterator<ll>(cout, "\n"));

	}
};


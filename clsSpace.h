#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
#include <conio.h> 

using namespace std;
char _pointer = '+';

class space
{
private:

	vector <vector<vector<char>>> _space;
	short _rows = 0, _colms = 0, _layers = 0;
	string _sSpace = "";

	void _generatespace() {

		_space.clear();
		vector<char> vLayers;

		for (short i = 0; i < _layers; i++)
		{
			vLayers.push_back(' ');
		}

		vector<vector<char>> vColmsAndLayers;

		for (short i = 0; i < _colms; i++)
		{
			vColmsAndLayers.push_back(vLayers);
		}

		for (short i = 0; i < _rows; i++)
		{
			_space.push_back(vColmsAndLayers);
		}

		/*for (short row = 0; row < _rows; row++)
		{
			_space.push_back(ColmsAndLayers);
			for (short colm = 0; colm < _colms; colm++)
			{

				for (short layer = 0; layer < _layers; layer++)
				{

				}

			}

		}*/
	}

	string _generateString2D(short layer = 0) {

		string sSpace;

		for (size_t row = 0; row < _rows; row++)
		{
			for (size_t colm = 0; colm < _colms; colm++)
			{
				sSpace += _space[row][colm][layer];
			}
			sSpace += "\n";
		}

		return sSpace;
	}

	string _generateString3D() {

		string sSpace = "";
		short layer = 0;

		for (short row = 0; row < _rows - layer / 3; row++)
		{
			for (short colm = _layers / 4; colm < _colms; colm++)
			{
				for (layer = 0; layer < _layers; layer++)
				{
					if (_space[row + layer / 3][colm - layer / 6][layer] == _pointer) {

						sSpace += " " + show;
						break;

					}

					if (layer == _layers - 1)
						sSpace += "  ";
				}
			}
			sSpace += "\n";
		}

		return sSpace;
	}

	void _save() {

		_sSpace = _generateString3D();
	}

public:

	string show = "$";
	float angleOZ = 0, angleOY = 0, angleOX = 0;


	space() {

	}

	space(short rows, short colms, short layers) {

		_rows = rows;
		_colms = colms;
		_layers = layers;

		_generatespace();
	}


	string print() {

		_save();
		
		//system("pause>0");
		return  _sSpace;
	}



	void print(short layer) {

		string sSpace = _generateString2D(layer);
		//system("cls");
		Sleep(50);
		cout << sSpace;
	}

private:

	bool _isPointValied(short row, short colm, short layer) {

		return (abs(row) <= _rows / 2) && (abs(colm) <= _colms / 2) && (abs(layer) <= _layers / 2);
	}

	bool _isvaliedPos(short row, short colm, short layer) {

		return (abs(row) < _rows) && (abs(colm) < _colms) && (abs(layer) < _layers);

	}

	void _coordenate(short& row, short& colm, short& layer) {


		short suprow = sin(angleOX) * layer + cos(angleOX) * row;
		short suplayer = cos(angleOX) * layer - sin(angleOX) * row;

		row = suprow;
		layer = suplayer;

		suprow = sin(angleOZ) * colm + cos(angleOZ) * row;
		short supcolm = cos(angleOZ) * colm - sin(angleOZ) * row;

		row = suprow;
		colm = supcolm;

		suplayer = sin(angleOY) * colm + cos(angleOY) * layer;
		supcolm = cos(angleOY) * colm - sin(angleOY) * layer;

		layer = suplayer;
		colm = supcolm;

	}

	void _drawpoint(short row, short colm, short layer, char pointer = _pointer) {

		_coordenate(row, colm, layer);
		_space[_rows / 2 - row][_colms / 2 + colm][_layers / 2 - layer] = pointer;
	}



public:bool point(short colm, short row, short layer, char pointer = _pointer) {

	if (!_isPointValied(row, colm, layer))
		return false;


	_drawpoint(row, colm, layer, pointer);

	return true;
}


public: void drawPer(short Oy = 0, short Ox = 0, short Oz = 0) {

	for (short row = -_rows / 2 + 1; row < _rows / 2; row++)
	{
		point(Ox, row, Oz);
	}

	for (short colm = -_colms / 2 + 1; colm < _colms / 2; colm++)
	{
		point(colm, Oy, Oz);
	}

	for (short layer = -_layers / 2 + 1; layer < _layers / 2; layer++)
	{
		point(Ox, Oy, layer);
	}

}

	  void clear() {
		  for (size_t i = 0; i < _rows; i++)
		  {
			  for (size_t j = 0; j < _colms; j++)
			  {
				  for (size_t k = 0; k < _layers; k++)
				  {
					  _space[i][j][k] = ' ';
				  }
			  }
		  }
	  }

	  void clear(short Layer) {
		  for (size_t i = 0; i < _rows; i++)
		  {
			  for (size_t j = 0; j < _colms; j++)
			  {
				  for (size_t k = 0; k < _layers; k++)
				  {
					  _space[i][j][Layer] = ' ';
				  }
			  }
		  }
	  }

	  void routate(float angleOX, float angleOY, float angleOZ) {

		  this->angleOZ -= 6.28 * angleOZ / 360;
		  this->angleOX += 6.28 * angleOX / 360;
		  this->angleOY -= 6.28 * angleOY / 360;
	  }

	  void set(short colm, short row, short layer, char pointer) {

		  _coordenate(row, colm, layer);

		  short tmplayer = _layers / 2 - layer;

		  if (_layers == 2 && layer == 0) {
			  tmplayer = 0;
		  }

		  if (_layers == 2 && layer == 1) {
			  tmplayer = 1;
		  }


		  if (_isvaliedPos(_rows / 2 - row, _colms / 2 + colm, tmplayer))
			  _space[_rows / 2 - row][_colms / 2 + colm][tmplayer] = pointer;

	  }

	  char get(short colm, short row, short layer) {

		  _coordenate(row, colm, layer);

		  short tmplayer = _layers / 2 - layer;

		  if (_layers == 2 && layer == 0) {
			  tmplayer = 0;
		  }

		  if (_layers == 2 && layer == 1) {
			  tmplayer = 1;
		  }


		  if (_isvaliedPos(_rows / 2 - row, _colms / 2 + colm, tmplayer))
			  return _space[_rows / 2 - row][_colms / 2 + colm][tmplayer];
		  else
			  return ' ';
	  }

	  void move(short x, short y, short z, bool isCircle = false, short layer = -1) {



		  y = -y;
		  space tmp(_rows, _colms, _layers);

		  for (short row = -_rows / 2 + 1; row < _rows / 2; row++)
		  {
			  for (short colm = -_colms / 2 + 1; colm < _colms / 2; colm++)
			  {
				  if (_layers == 1) {
					  tmp.set(colm, row, 0, this->get(colm, row, 0));
					  continue;
				  }

				  if (layer == -1) {
					  for (short layer = -_layers / 2 + 1; layer < _layers / 2; layer++)
					  {
						  tmp.set(colm, row, layer, this->get(colm, row, layer));
					  }
				  }
				  else {
					  tmp.set(colm, row, layer, this->get(colm, row, layer));

				  }


			  }
		  }

		  for (short row = -_rows / 2 + 1; row < _rows / 2; row++)
		  {
			  for (short colm = -_colms / 2 + 1; colm < _colms / 2; colm++)
			  {


				  if (_layers == 1) {
					  this->set(colm + x, row + y, 0 + z, tmp.get(colm, row, 0));
					  continue;
				  }

				  if (layer == -1) {
					  for (short layer = -_layers / 2 + 1; layer < _layers / 2; layer++)
					  {
						  this->set(colm + x, row + y, layer + z, tmp.get(colm, row, layer));
					  }
				  }
				  else {
					  this->set(colm + x, row + y, layer + z, tmp.get(colm, row, layer));

				  }


			  }

		  }


		  if (isCircle) {

			  z = 1;

			  for (short i = -10; i < -7; i++)
			  {
				  this->set(_colms / 2 - 1, i, z, tmp.get(-_colms / 2 + 1, i, z));
			  }

		  }

	  }



	  void drawString(string s, short x, short y, short z) {

		  if (z == 1)
			  clear(z - 1);

		  short tmpX = x, tmpY = y;

		  for (size_t i = 0; i < s.length(); i++)
		  {
			  if (s[i] == '\n')
			  {
				  tmpY--;
				  tmpX = x;
				  continue;
			  }

			  if (s[i] != ' ') {

				  point(tmpX, tmpY, z);
			  }

			  tmpX++;



		  }

	  }

	  long long int counter = 0;

};


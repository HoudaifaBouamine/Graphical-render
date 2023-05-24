

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "clsSpace.h"
using namespace std;

class clsCube
{

private:

    space _space;
    short _a = 0;
    

        void _draw() {

            short a = _a;

            for (size_t i = 0; i < a; i++)
            {


                _space.point(-a / 2 + i, -a / 2, a / 2);
                _space.point(-a / 2, -a / 2 + i, a / 2);
                _space.point(a / 2 - i, a / 2, a / 2);
                _space.point(a / 2, a / 2 - i, a / 2);
                _space.point(-a / 2 + i, -a / 2, -a / 2);
                _space.point(-a / 2, -a / 2 + i, -a / 2);
                _space.point(a / 2 - i, a / 2, -a / 2);
                _space.point(a / 2, a / 2 - i, -a / 2);
                _space.point(-a / 2, -a / 2, i - a / 2);
                _space.point(a / 2, a / 2, i - a / 2);
                _space.point(-a / 2, a / 2, i - a / 2);
                _space.point(a / 2, -a / 2, i - a / 2);
            }

            /*short s = 1;

            for (size_t i = 0; i < a; i++)
            {


                _space.point(-a / 2 + i + s, -a / 2, a / 2);
                _space.point(-a / 2 + s, -a / 2 + i, a / 2);
                _space.point(a / 2 - i + s, a / 2, a / 2);
                _space.point(a / 2 + s, a / 2 - i, a / 2);
                _space.point(-a / 2 + i + s, -a / 2, -a / 2);
                _space.point(-a / 2 + s, -a / 2 + i, -a / 2);
                _space.point(a / 2 - i+s, a / 2, -a / 2);
                _space.point(a / 2+s, a / 2 - i, -a / 2);
                _space.point(-a / 2+s, -a / 2, i - a / 2);
                _space.point(a / 2+s, a / 2, i - a / 2);
                _space.point(-a / 2+s, a / 2, i - a / 2);
                _space.point(a / 2+s, -a / 2, i - a / 2);
            }*/

        }

      
    

public:


    clsCube(space space, short a) {

        _a = a;
        _space = space;
    }

    string print() {
        _space.clear();
        _draw();
        return _space.print();
    }

private:



public: void routate(float angleOX, float angleOY, float angleOZ) {

    _space.routate(angleOX, angleOY, angleOZ);

}

      void move(short steps, float angleOX, float angleOY, float angleOZ) {

          for (size_t i = 0; i < steps; i++)
          {
              print();
              routate(angleOX, angleOY, angleOZ);

          }
      }
};


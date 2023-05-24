#include <iostream>
#include "clsSpace.h"
#include "clsCube.h"
#include "clsHiper_Cube.h"
using namespace std;

static vector<string> Split(string S1, string Delim)
{

    vector<string> vString;

    short pos = 0;
    string sWord; // define a string variable  

    // use find() function to get the position of the delimiters  
    while ((pos = S1.find(Delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word   
        // if (sWord != "")
        // {
        vString.push_back(sWord);
        //}

        S1.erase(0, pos + Delim.length());  /* erase() until positon and move to next word. */
    }

    if (S1 != "")
    {
        vString.push_back(S1); // it adds last word of the string.
    }

    return vString;

}

static void clear_screen()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
}


int main(){
    
    clsTriangle triangle(space(90,90,90),30);
    clsCube cube(space(90, 90, 90), 30);

    triangle.print();
    system("pause>0");

    while (true) {

        string s1 = triangle.print();
        string s2 = cube.print();

        vector<string> t = Split(s1, "\n");
     
        vector<string> c = Split(s2, "\n");

        for (size_t i = 0; i < t.size(); i++)
        {
            cout << t[i] << c[i] << "\n";
        }

        
        triangle.routate(3, 3, 3);
        cube.routate(-3, 2, 5);
        clear_screen();
    }
    //triangle.move(-1, 3, 3,3);

    //clsCube c(space(90,90,90),35);
    ////clsCube c(space(100, 100, 100), 30);
    ////clsCube c(space(250, 250, 250), 70);
    
    //c.print();

    //system("pause>0");
    //
    //c.move(-1, 3,3,3);
   

    return 0;
}

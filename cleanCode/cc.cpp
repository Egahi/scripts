/**
 * cc.cpp
 *
 * generates clean code from a source file
 *
 * @s_egahi
 *
 * this was clean code!
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: ./cc sourcefile.cpp\n";
        return 1;
    }

    cout << argv[1] << endl;

    return 0;
}
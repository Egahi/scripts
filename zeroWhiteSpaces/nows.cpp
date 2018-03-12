/**
 * nows.cpp
 *
 * removes all whitespaces from a file
 *
 * @s_egahi
 *
 * this was no white space!
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        cout << "Usage: ./cc sourcefile.cpp\n";
        return 1;
    }

    // open file to read
    ifstream input (argv[1]);
    if (!input)
    {
        cout << "Could not open " << argv[1] << endl;
        return 2;
    }

    // length of file name
    int length = 0;
    while(argv[1][length] != '\0')
        length++;

    char newName[4 + length];
    strcpy(newName, "new_");
    strcat(newName, argv[1]);

    // open file to write
    ofstream output (newName);
    if (!output)
    {
        cout << "Could not open sourcefile.cpp" << endl;
        return 3;
    }

    // temporary character buffer
    char c;
    // read from file one character at a time, skipping whitespaces
    while (input >> skipws >> c)
    {
        // write to outfile
        output << c;
    }

    output.close();
    input.close();

    // success
    return 0;
}
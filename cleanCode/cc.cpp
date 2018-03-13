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
#include <cstring>

using namespace std;

/**
 * calculates and returns the length of a string
 */
inline int stringlength(char *word);

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        cout << "Usage: ./cc sourcefile.cpp\n";
        return 1;
    }

    ifstream input (argv[1]);
    if (!input)
    {
        cout << "Could not open " << argv[1] << endl;
        return 2;
    }

    int length = stringlength(argv[1]);

    char newName[4 + length];
    strcpy(newName, "new_");
    strcat(newName, argv[1]);

    ofstream output (newName);
    if (!output)
    {
        cout << "Could not open outfile\n";
        return 3;
    }

    // temporary character buffer
    char line;
    int counter = 0;

    // read one character at a time
    while (input >> line)
    {
        if (counter >= 80)
        {
            output << "\n";
            counter = 0;
        }

        output << line;
        counter++;
    }

    input.close();
    output.close();

    // success
    return 0;
}

/**
 * calculates and returns the length of a string
 */
inline int stringlength(char *word)
{
    int length = 0;

    while (word[length] != '\0')
        length++;

    return length;
}
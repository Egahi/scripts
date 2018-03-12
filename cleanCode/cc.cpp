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

    int length = stringlength(agrv[1]);

    char newName[4 + length];
    strcpy(newName, "new_");
    strcat(newName, agrv[1]);

    ofstream output (newName);
    if (!output)
    {
        cout << "Could not open outfile\n";
        return 3;
    }

    char line[80];

    while (infile >> line)
        outfile << line;

    infile.close();
    outfile.close();

    // success
    return 0;
}

inline int stringlength(char *word)
{
    int length = 0;

    while (word[length] != '\0')
        length++;

    return length;
}
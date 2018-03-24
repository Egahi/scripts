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
    char c;
    int counter = 0;
    int tab = 0;

    // read one character at a time
    while (input >> c)
    {
        if (counter >= 80 || c == '#')
        {
            output << "\n";
            output << c;
            counter = 0;
        }

        else if (c == '{' || c == '}')
        {
            if (c == '{')
            {
                output << "\n";
                tab++;
            }

            else
            {
                tab--;
            }

            output << c;
            output << "\n";

            for (int i = 0, j = tab * 4; i < j; i++)
            {
                output << " ";
            }

            counter = 0;
        }

        else if (c == '>' || c == ';')
        {
            output << c;
            output << "\n";

            if (c == ';')
            {
                for (int i = 0, j = tab * 4; i < j; i++)
                {
                    output << " ";
                }
            }

            counter = 0;
        }

        else if (c == '/')
        {
            char temp = c;
            input >> c;
            if (c == '/')
            {
                output << "\n";
                output << temp << c << " ";
            }

            else if (c == '*')
            {
                output << "\n";
                output << temp << c << " \n" << "* ";
            }

            else
            {
                output << c;
            }

            counter = 0;
        }

        else if (c == '*')
        {
            char temp = c;
            input >> c;
            if (c == '/')
            {
                output << "\n";
                output << temp << c << "\n";
            }

            else
            {
                output << c;
            }

            counter = 0;
        }

        else if (isspace(c))
        {
            output << "ws";
        }

        else
        {
            output << c;
        }

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
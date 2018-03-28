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
#include <cctype>

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

    // length of file name
    int length = stringlength(argv[1]);
    char newName[4 + length];

    // append "new_" to beginning of original file name
    strcpy(newName, "new_");
    strcat(newName, argv[1]);

    // open outfile with new name
    ofstream output (newName);
    if (!output)
    {
        cout << "Could not open outfile\n";
        return 3;
    }

    // temporary character buffer
    char c;

    // track no of characters read
    int counter = 0;

    // value to indent blocks of code
    // int tab = 0;

    // read one character at a time
    while (input >> c)
    {
        // only 80 charachters per line
        // only one include or define statement per line
        if (counter >= 80 || c == '#')
        {
            output << "\n";
            output << c;
            counter = 0;
        }

        // opening and closing curly braces on new lines
        else if (c == '{' || c == '}')
        {
            if (c == '{')
            {
                output << "\n";
                // tab++;
            }
/*
            else
            {
                tab--;
            }*/

            output << c;
            output << "\n";
/*
            // indent blocks of code
            for (int i = 0, j = tab * 4; i < j; i++)
            {
                output << " ";
            }*/

            counter = 0;
        }

        // only one statement per line
        else if (c == '>' || c == ';')
        {
            output << c;
            output << "\n";
/*
            if (c == ';')
            {
                indent(output);
            }*/

            counter = 0;
        }

        // comments
        else if (c == '/')
        {
            char temp = c;
            input >> c;
            if (c == '/')
            {
                output << "\n";

                // space first character after comments indicator "//"
                output << temp << c << " ";
            }

            else if (c == '*')
            {
                output << "\n";

                // begin multi-line comments on separte line from indicator "/*"
                output << temp << c << " \n";
                counter ++;
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

                // close muti-line comments with indicator on new line
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

        else if (isoperator(c))
        {
            cout << " " << c << " ";
            counter += 2;
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
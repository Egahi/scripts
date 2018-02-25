/**
 * default.cpp
 *
 * opens a new .cpp file wtih default syntax
 *
 * @s_egahi
 *
 * this is default.cpp
 */

 #include <iostream>
 #include <fstream>
 #include <cstring>

 using namespace std;

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        cout << "Usage: ./default sourceFile.cpp\n";
        return 1;
    }

    ofstream cppFile (argv[1], ios::app);
    if (cppFile == NULL)
    {
        cout << "Could not open " << argv[1] << endl;
        return 2;
    }

    cppFile << "#include <iostream>\n" << endl
            << "using namespace std;\n" << endl
            << "int main(void)\n"
            << "{\n"
            << "    return 0;\n"
            << "}" << endl;

    cppFile.close();

    return 0;
}
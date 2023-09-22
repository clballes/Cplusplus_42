#include "sed.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    if (argc == 4)
    {
        std::ifstream inputFile;
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        inputFile.open(filename);
        if (!inputFile.is_open())
        {
            std::cerr << "Failed to open the file for reading." << std::endl;
            return 1; // Return an error code
        }
        std::ofstream Ouputfile(filename + ".replace");
        std::string line;
        while (std::getline(inputFile, line))
        {
            std::string modifiedLine;
            size_t pos = 0;
            while (pos < line.length()) {
                size_t foundPos = line.find(s1, pos);
                if (foundPos == std::string::npos) {
                    modifiedLine += line.substr(pos);
                    break;
                }
                modifiedLine += line.substr(pos, foundPos - pos);
                modifiedLine += s2;
                pos = foundPos + s1.length();
                }
                Ouputfile << modifiedLine << '\n';
            }
            inputFile.close(); // Close the file when done reading
        }
        else
            return 0;
}
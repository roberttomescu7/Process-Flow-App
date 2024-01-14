#ifndef FILE_MANAGER_HPP
#define FILE_MANAGER_HPP

#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class FileManager
{
public:
    // Static method to read and print the content of a file to the provided output stream
    static void readAndPrint(string path, ostream &output)
    {
        // Extract file extension
        string extension = getExtension(path);

        // Open the file for reading
        ifstream fin(path, ios::in);

        // Check the file extension and process accordingly
        if (extension == "txt") {
            string line;
            // Read and print each line for text files
            while (getline(fin, line)) {
                output << line << "\n";
            }
        }
        else if (extension == "csv") {
            string line;
            // Read and print each line, parsing CSV fields and printing with tabs
            while (getline(fin, line)) {
                istringstream ss(line);

                vector<string> row;

                std::string field;
                while (std::getline(ss, field, ',')) {
                    row.push_back(field);
                }

                for (string element : row) {
                    output << "\t" << element << "\t";
                }
                output << "\n";
            }
        }
        fin.close(); // Close the file
    }

    // Static method to get the extension of a file from its path
    static string getExtension(string path)
    {
        // Find the last occurrence of '.' in the file path
        size_t dotPos = path.find_last_of('.');

        // Extract and return the extension
        string extension = path.substr(dotPos + 1);

        return extension;
    }
};

#endif

/* Date: 07/03/2023
   Authors: Hemant Yadav
            Piyush Patel
            Sumit Choudhary
    Sucessfull Execution: 07/03/2023
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

// raw pointer to point to buffer
char *raw;
void readin(char *file);
bool readfile(std::fstream &input);

int main(int argc, char *argv[])
{
    // Checking wheather argument is more than 2 or not
    if (argc != 2)
    {
        std::cerr << "Usage : cpp file.cpp" << std::endl;
        exit(1);
    }

    readin(argv[1]);

    return 0;
}

// Readin in function to check wheather program can read input file or not
void readin(char *file)
{
    int fd = -1;
    struct stat st;

    // Checking for '.' character
    if (strrchr(file, '.') == NULL)
        std::cerr << "File must end with .cpp " << std::endl;

    // Checking wheather file has appropriate extension or not
    if (!!strcmp(strrchr(file, '.'), ".cpp"))
        std::cout << "File must end with .cpp " << std::endl;

    // sfile is used to print our file named 'file'
    std::fstream sfile;

    sfile.open(file, std::ios::in | std::ios::binary);

    // To check wheather file is opened or not
    if (sfile.is_open() == false)
        std::cerr << "Couldn't open file " << std::endl;

    // seekg is used to get certain position in a file , here we are at 0th position
    sfile.seekg(0, std::ios::end);

    // tellg is used to get the size of file
    fd = sfile.tellg();
    if (fd == -1)
        std::cerr << "Couldn't get file size" << std::endl;

    // Allocating buffer memeory to program which is pointed by raw
    raw = new char[fd + 1];

    if (raw == NULL)
        std::cerr << "Could'nt allocate the memory " << std::endl;

    // Calling readfile function
    if (readfile(sfile) == false)
        std::cerr << "Couldn't read  file" << std::endl;

    raw[fd] = '\0';
    sfile.close();
}

// Function to check wheather is file readable or not
bool readfile(std::fstream &input)
{
    if (input.is_open())
    {
        std::string line;
        while (getline(input, line))
        {
        }
        return true;
    }
    else
    {
        return false;
    }
}

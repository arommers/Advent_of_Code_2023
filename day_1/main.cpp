#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

//  What is the sum of all calibration values?

//  How do i open and read a file and store the string

//  how do recognize and store the numbers from the read line 

//  how do I recognize and extract the first and the last digit

//  how add them together

//  How do I keep track of sum.

std::string firstAndLast(std::string& string)
{
    std::string  first(1, string.front());
    std::string  last(1, string.back());

    return (first + last);
}

int readFile(std::string& fileName, int sum)
{
    std::string input;
    std::string tmp;
    int         i;
    
    std::ifstream inFile(fileName);
    if(!inFile)
    {
        std::cerr << "Something went wrong with trying to open " << fileName << std::endl;
        return (1);
    }
    while (std::getline(inFile, input))
    {
        i = 0;
        while(i < input.length())
        {
            if (isdigit(input[i]))
                tmp += input[i++];
            else
                i++;
        }
        if (!tmp.empty())
        {
            tmp = firstAndLast(tmp);
            sum += std::stoi(tmp);
        }
        tmp.clear();
    }
    return (sum);
}



int main(int argc, char **argv)
{
    std::string fileName;
    int sum = 0;

    if (argc != 2)
        std::cerr << "ERROR. Please provide: <./a.out> <inFile>" << std::endl;
    fileName = argv[1];
    sum = readFile(fileName, sum);
    std::cout << "Sum: " << sum << std::endl;
    return (0);
}
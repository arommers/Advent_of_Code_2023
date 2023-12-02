#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

// Using stream extraction to tokenize the line

// Keep loop going as long as there is a istringstream

// checking the tokens

int     solveGame(std::string& input)
{
    std::fstream    infile(input);
    std::string     line;
    size_t sum         = 0;

    while(getline(infile, line))
    {
        std::istringstream str(line);   // Create a string stream for tokenizing the current line
        std::string game, color;        // Create the various tokens we are going to extract
        size_t id = 0, num = 0;
        char colon = ':';
        bool valid = true;              // Keep track of valid lines

        str >> game >> id >> colon;     // Tokenize the initial part of each string to store the id and move to the number /olor pairs
        while (str >> num >> color)     // Keep reading the string stream as long as we have a number/color pair
        {
            if (color.back() == ',' || color.back() == ';' ) // Delete chars we don't need
                color.pop_back();
            if (color == "red")
            {
                if (num > 12)
                    valid = false;
            }
            if (color == "green")
            {
                if (num > 13)
                    valid = false;
            }
            if (color == "blue")
            {
                if (num > 14)
                    valid = false;
            }
        }
        if(valid)
            sum += id;
    }
    return (sum);
}

int main(int argc, char **argv)
{
    std::string input = argv[1];

    size_t answer = solveGame(input);
    std::cout << "The answer is: " << answer << std::endl;
}
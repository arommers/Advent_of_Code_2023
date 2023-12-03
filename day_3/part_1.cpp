#include <iostream>>
#include <fstream>
#include <sstream>
#include <vector>
#include <string> 

bool    check_sides(std::vector<std::string>& engine, size_t y, size_t x)
{
    if (y > 0 && engine[y - 1][x] != '.' && !isdigit(engine[y - 1][x]))                         // check above number
        return (true);
    else if (y < engine.size() - 1 && engine[y + 1][x] != '.' && !isdigit(engine[y + 1][x]))    // check below number
        return (true);
    else if (x > 0 && engine[y][x - 1] != '.' && !isdigit(engine[y][x - 1]))                    // check left of number
        return (true);
    else if (x < engine[y].size() - 1 && engine[y][x + 1] != '.' && !isdigit(engine[y][x + 1])) // check right of numer
        return (true);
    else if (y > 0 && x > 0 && engine[y - 1][x - 1] != '.' && !isdigit(engine[y - 1][x - 1]))   // check up and left of number
        return (true);

    
    return (false);
}

size_t  findParts(std::string& input)
{
    std::ifstream                infile(input);
    std::string                 line;
    std::vector<std::string>    engine;
    size_t                      number;
    size_t                      sum = 0;
    bool                        valid;

    while (getline(infile, line))                               // Store the engine schematic into the engine vector line by line
        engine.push_back(line);
    for (size_t y = 0; y < engine.size(); y++)                  // Iterate through the schematic one line/row one by one
    {
        number = 0;
        valid = false;
        for (size_t x = 0; x < engine[y].size(); x++)           // loop throught the characters of a line/row one by one
        {
            if (isdigit(engine[y][x]))                          
            {
                number = number * 10 + (engine[y][x] - '0');    //  Store the found digit and move up one decimal
                if (check_sides(engine, y, x))                  //  Check if an adjacent symbol is found
                    valid = true;
                else
                    valid = false;
                if (x == engine[y].size() - 1)                  // If the last index in the current line/row
                {
                    if (valid)                                  // Add the number to the sum
                        sum += number;
                    number = 0;                                 // Reset for new line check
                    valid = false;
                }
            }
            else if (!isdigit(engine[y][x]))                    // If the current index is not a number
            {
                if (valid)                                      // if previous index is part of a valid number add it to the sum
                        sum += number;
                number = 0;
                valid = false;
            }
        }

    }
    return (sum);
}

int main(int argc, char **argv)
{
    std::string input = argv[1];

    size_t answer = findParts(input);
    std::cout << "The answer is: " << answer << std::endl;
    return (0);
}
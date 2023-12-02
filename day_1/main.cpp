#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

//  Part 1

//  What is the sum of all calibration values?

//  How do i open and read a file and store the string

//  how do recognize and store the numbers from the read line 

//  how do I recognize and extract the first and the last digit

//  how add them together

//  How do I keep track of sum.

//  Part 2

//  How to find the numbers as words

//  How to extract these string and turn them into numbers

//  How do I cut of after reading number in characters << most annoying

//  How to properly keep iterating

// std::string firstAndLast(std::string& string)
// {
//     std::string  first(1, string.front());
//     std::string  last(1, string.back());

//     return (first + last);
// }

// std::string wordToNumber(const std::string &word)
// {
//     std::unordered_map<std::string, std::string>wordMap =
//     {
//         {"one", "1"},
//         {"two", "2"},
//         {"three", "3"},
//         {"four", "4"},
//         {"five", "5"},
//         {"six", "6"},
//         {"seven", "7"},
//         {"eight", "8"},
//         {"nine", "9"}
//     };
//     auto i = wordMap.find(word);
//     if (i != wordMap.end())
//         return (i->second);
//     else
//         return ("");
// }

// std::string findFirstNumberWord(std::string& input) {
    
//     size_t  found;
//     const   std::string numberWords[] = 
//     {
//         "one",
//         "two", 
//         "three", 
//         "four", 
//         "five", 
//         "six", 
//         "seven", 
//         "eight", 
//         "nine"
//     };
//     for (const std::string& word : numberWords)
//     {
//         found = input.find(word);
//         if (found != std::string::npos)
//         {
//             input.erase(0, found);
//             return word;
//         }
//     }
//     return "";
// }

// int readFile(std::string& fileName, int sum)
// {
//     std::string input;
//     std::string word;
//     std::string tmp;
//     int         i;
//     int         j;
    
//     std::ifstream inFile(fileName);
//     if(!inFile)
//     {
//         std::cerr << "Something went wrong with trying to open " << fileName << std::endl;
//         return (1);
//     }
//     while (std::getline(inFile, input))
//     {
//         i = 0;
//         while(i < input.length())
//         {
//             if (isalpha(input[i]))
//             {
//                 j = i;
//                 while (isalpha(input[j]))
//                     word += input[j++];
//                 word = findFirstNumberWord(word);
//                 std::cout << word << std::endl;
//                 std::cout << word.length() << std::endl;
//                 i = j;
//                 tmp += wordToNumber(word);
//                 word.clear();
//             }
//             else if (isdigit(input[i]))
//                 tmp += input[i++];
//             else
//                 i++;
//         }
//         if (!tmp.empty())
//         {
//             tmp = firstAndLast(tmp);
//             sum += std::stoi(tmp);
//         }
//         tmp.clear();
//     }
//     return (sum);
// }

std::vector<std::string> spelled = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

static int  getNumber(const std::string& line, int i)
{
    if (isdigit(line[i]))
        return (line[i] - '0');
    for (int j = 0; j < spelled.size(); j++)
    {
        const auto& numbers = spelled[j];
        if (i + numbers.size() > line.size())
            continue;
        if (line.substr(i, numbers.size()) == numbers)
            return(j);
    }
    return (-1);
}

int main(int argc, char **argv)
{
    std::string fileIn;
    std::string line;
    int         num1;
    int         num2;
    int         digit;
    int         sum = 0;

    fileIn = argv[1];
    std::ifstream inFile(fileIn);
    while (getline(inFile, line))
    {
        num1 = -1;
        num2 = -1;
        for(int i = 0; i < line.size(); i++)
        {
            digit = getNumber(line, i);
            if (digit == -1)
                continue;
            if (num1 == -1)
                num1 = digit;
            else
                num2 = digit;
        }
        if (num2 == -1)
            num2 = num1;
        sum += 10 * num1 + num2;
    }
    std::cout << "Sum: " << sum << std::endl;
    return (0);
}


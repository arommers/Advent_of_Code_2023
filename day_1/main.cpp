#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <unordered_map>

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

// int main(int argc, char **argv)
// {
//     std::string fileName;
//     int sum = 0;

//     if (argc != 2)
//         std::cerr << "ERROR. Please provide: <./a.out> <fileName>" << std::endl;
//     fileName = argv[1];
//     sum = readFile(fileName, sum);
//     std::cout << "Sum: " << sum << std::endl;
//     return (0);
// }

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>

// Function to convert word representations of numbers to numerical values
int wordToNumber(const std::string& word) {
    // Create a mapping of word representations to numerical values
    std::unordered_map<std::string, int> wordToNumMap = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}
    };

    // Try to find the word in the map
    auto it = wordToNumMap.find(word);
    if (it != wordToNumMap.end()) {
        // If found, return the corresponding numerical value
        return it->second;
    } else {
        // If not found, try to convert it to a number
        try {
            return std::stoi(word);
        } catch (const std::invalid_argument&) {
            // Conversion failed, return 0 or handle it as needed
            return 0;
        }
    }
}

// Function to calculate the sum of calibration values
int calculateSum(const std::string& fileName) {
    std::ifstream inFile(fileName);
    if (!inFile) {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return 0;
    }

    int sum = 0;
    std::string line;
    while (std::getline(inFile, line)) {
        // Find the first and last digits in the line
        size_t firstDigitPos = line.find_first_of("123456789");
        size_t lastDigitPos = line.find_last_of("123456789");

        // Extract the substring containing the digits
        std::string digitsSubstring = line.substr(firstDigitPos, lastDigitPos - firstDigitPos + 1);

        // Convert the substring to the numerical value
        int numericalValue = wordToNumber(digitsSubstring);

        // Add the numerical value to the sum
        sum += numericalValue;
    }

    inFile.close();
    return sum;
}

int main() {
    std::string fileName = "./test";
    int sum = calculateSum(fileName);

    std::cout << "Sum of calibration values: " << sum << std::endl;

    return 0;
}

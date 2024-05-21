#include <iostream>
#include <vector>
#include <cmath>

#include "knapsackDynamicProgramming.h"
#include "knapsackBruteForce.h"
#include "menuFunctions.h"

#define PLACEHOLDER 0
#define GENERATE 1
#define READ_FILE 2

int inputMode = PLACEHOLDER;

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        if (!std::strcmp(argv[1], "--generate") || !std::strcmp(argv[1], "-g"))
            inputMode = GENERATE;
        else if (!std::strcmp(argv[1], "--read-file") || !std::strcmp(argv[1], "-rf"))
            inputMode = READ_FILE;
        else
        {
            std::cerr << "You incorrect specified the input mode.\n";
            return 1;
        }
    }
    else
    {
        std::cerr << "You did not specify the input mode.\n"
                  << std::endl;
        return 1;
    }

    // some important stuff for now here
    int capacity = 0;
    std::vector<int> values;
    std::vector<int> weights;
    const std::string filePath = "test.txt";

    // handle diffrent inputs
    if (inputMode == GENERATE)
    {
        int count;
        int maxValues;
        int maxWeights;
        std::cout << "Provide capacity" << std::endl;
        std::cin >> capacity;
        std::cout << "Provide number of items" << std::endl;
        std::cin >> count;
        std::cout << "Provide maximum value" << std::endl;
        std::cin >> maxValues;
        std::cout << "Provide maximum weight" << std::endl;
        std::cin >> maxWeights;
        generateInputValues(count, maxValues, maxWeights, values, weights);
    }
    else if (inputMode == READ_FILE)
    {
        capacity = readFromFile(filePath, values, weights);
    }

    // menu
    while (true)
    {
        std::string option;
        std::cout << "\naction> ";
        std::getline(std::cin, option);

        if (option == "brute-force" || option == "bf")
        {
            printResults(knapsackBruteForce(values, weights, capacity));
        }
        else if (option == "dynamic-programming" || option == "dp")
        {
            printResults(knapsackDynamicProgramming(values, weights, capacity));
        }
        else if (option == "exit")
        {
            break;
        }
        else
        {
            std::cout << "This command does not exist." << std::endl;
        }
    }
    return 0;
}
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
            std::cout << "You incorrect specified the input mode.\n";
            return 1;
        }
    }
    else
    {
        std::cout << "You did not specify the input mode.\n"
                  << std::endl;
        return 1;
    }

    std::vector<int> values;
    std::vector<int> weights;

    if (inputMode == GENERATE)
    {
        int count;
        int maxValues;
        int maxWeights;
        std::cout << "Provide number of items" << std::endl;
        std::cin >> count;
        std::cout << "Provide maximum value" << std::endl;
        std::cin >> maxValues;
        std::cout << "Provide maximum weight" << std::endl;
        std::cin >> maxWeights;
        generateInputValues(count, maxValues, maxWeights, values, weights);
    }
    else
    {
        // read from file
    }

    while (true)
    {
        std::string option;
        std::cout << "\naction> ";
        std::getline(std::cin, option);

        if (option == "brute-force" || option == "bf")
        {
            auto result = knapsackBruteForce(values, weights, 200);

            int max = result.first;
            std::vector<int> resultItems = result.second;

            std::cout << "Maximum value: " << max << std::endl;
            std::cout << "Items indexes: ";
            for (int idx : resultItems)
            {
                std::cout << idx << " ";
            }
            std::cout << std::endl;
        }
        else if (option == "dynamic-programming" || option == "dp")
        {
            auto result = knapsackDynamicProgramming(values, weights, 200);
            // print
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
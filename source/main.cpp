#include <iostream>
#include <vector>
#include <cmath>

#include "knapsackBruteForce.h"

#define PLACEHOLDER 0
#define GENERATE 1
#define USER_PROVIDED 2

int inputMode = PLACEHOLDER;

int main(int argc, char *argv[])
{
    if (argc >= 2)
    {
        if (!std::strcmp(argv[1], "--generate") || !std::strcmp(argv[1], "-g"))
            inputMode = GENERATE;
        else if (!std::strcmp(argv[1], "--user-provided") || !std::strcmp(argv[1], "-up"))
            inputMode = USER_PROVIDED;
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

    // tutaj bedzie generowanie danych badz obsluga wpisywania

    while (true)
    {
        std::string option;
        std::cout << "\naction> ";
        std::getline(std::cin, option);

        if (option == "brute-force" || option == "bf")
        {
            // bf solution
        }
        else if (option == "dynamic-programming" || option == "dp")
        {
            // dp solution
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
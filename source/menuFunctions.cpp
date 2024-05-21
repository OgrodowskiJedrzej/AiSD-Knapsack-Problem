#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <random>

void generateInputValues(int count, int maxValue, int maxWeight, std::vector<int> &values, std::vector<int> &weights)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> valueDistribution(1, maxValue);
    std::uniform_int_distribution<> weightDistribution(1, maxWeight);

    for (int i = 0; i < count; ++i)
    {
        int pi = valueDistribution(gen);
        int wi = weightDistribution(gen);
        values.push_back(pi);
        weights.push_back(wi);
    }
}

int readFromFile(const std::string filename, std::vector<int> &values, std::vector<int> &weights)
{
    std::ifstream inputFile(filename);

    if (!inputFile)
    {
        std::cerr << "Error file opening!" << std::endl;
        return 1;
    }
    std::string line;
    if (!getline(inputFile, line))
    {
        std::cerr << "Error no capacity value!" << std::endl;
        return 1;
    }
    int c = 0;
    std::istringstream issC(line);
    if (!(issC >> c))
    {
        std::cerr << "Error with reading capacity" << std::endl;
        return 1;
    }
    int i;
    if (!(inputFile >> i))
    {
        std::cerr << "Error no count value!" << std::endl;
        return 1;
    }
    for (int j = 0; j < i; ++j)
    {
        int pi, wi;
        if (!(inputFile >> pi >> wi))
        {
            std::cerr << "Error not enough of pi wi values!" << std::endl;
            return 1;
        }
        values.push_back(pi);
        weights.push_back(wi);
    }

    inputFile.close();
    return c;
}

void printResults(std::pair<int, std::vector<int>> algorithm)
{
    auto result = algorithm;
    int maximumValue = result.first;
    std::vector<int> resultItems = result.second;
    std::cout << "Maximum value: " << maximumValue << std::endl;
    std::cout << "Items indexes: ";
    for (int idx : resultItems)
    {
        std::cout << idx << " ";
    }
    std::cout << std::endl;
}
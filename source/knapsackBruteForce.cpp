#include <iostream>
#include <vector>
#include <knapsackBruteForce.h>

std::pair<int, std::vector<int>> knapsackBruteForce(std::vector<int> &values, std::vector<int> &weights, int capacity)
{
    int sizeOfValuesVector = values.size();
    int maxValue = 0;
    std::vector<int> result;

    for (int i = 0; i < (1 << sizeOfValuesVector); ++i)
    {
        int totalWeight = 0;
        int totalValue = 0;
        std::vector<int> actualCombination;

        for (int j = 0; j < sizeOfValuesVector; ++j)
        {
            if (i & (1 << j))
            {
                totalWeight += weights[j];
                totalValue += values[j];
                actualCombination.push_back(j);
            }
        }
        if (totalWeight <= capacity && totalValue > maxValue)
        {
            maxValue = totalValue;
            result = actualCombination;
        }
    }

    return {maxValue, result};
}
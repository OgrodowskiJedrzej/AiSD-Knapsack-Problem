#include <iostream>
#include <vector>
#include <algorithm>
#include "knapsackDynamicProgramming.h"

std::pair<int, std::vector<int>> knapsackDynamicProgramming(std::vector<int> &values, std::vector<int> &weight, int capacity)
{
    int sizeOfValuesVector = values.size();
    std::vector<std::vector<int>> matrixForDP(sizeOfValuesVector + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= sizeOfValuesVector; ++i)
    {
        for (int currentCapacity = 0; currentCapacity <= capacity; currentCapacity++)
        {
            if (weight[i - 1] <= currentCapacity)
            {
                matrixForDP[i][currentCapacity] = std::max(matrixForDP[i - 1][currentCapacity], matrixForDP[i - 1][currentCapacity - weight[i - 1]] + values[i - 1]);
            }
            else
            {
                matrixForDP[i][currentCapacity] = matrixForDP[i - 1][currentCapacity];
            }
        }
    }

    std::vector<int> result;
    int currentCapacity = capacity;
    for (int i = sizeOfValuesVector; i > 0 && currentCapacity > 0; --i)
    {
        if (matrixForDP[i][currentCapacity] != matrixForDP[i - 1][currentCapacity])
        {
            result.push_back(i - 1);
            currentCapacity -= weight[i - 1];
        }
    }

    return {matrixForDP[sizeOfValuesVector][capacity], result};
}
#include <vector>
#include <string>
#include <fstream>
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
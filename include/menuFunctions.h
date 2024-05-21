#pragma once
#include <vector>

void generateInputValues(int count, int maxValue, int maxWeight, std::vector<int> &values, std::vector<int> &weights);
int readFromFile(const std::string filename, std::vector<int> &values, std::vector<int> &weights);
void printResults(std::pair<int, std::vector<int>> algorithm);
void printItems(std::vector<int> &values, std::vector<int> &weights);
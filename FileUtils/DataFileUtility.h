//
// Created by lukas on 01.04.2023.
//

#ifndef SDIZO_PROJECT_1_DATAFILEUTILITY_H
#define SDIZO_PROJECT_1_DATAFILEUTILITY_H

#include "iostream"
#include "list"

class DataFileUtility {
private:
    std::list<int> dataList;
public:
    int *tab = nullptr;

    void test(const std::string &FileName);

    std::list<int> *readData(const std::string &FileName);

    static bool saveData(std::list<int> &outputList, const std::string &FileName);

    static bool
    saveResultsMicroseconds(const std::string &FileName, std::list<double> &results, const std::string &headline);

    static bool saveResults2DMicroseconds(const std::string &FileName, std::list<std::list<double>> &results,
                                          const std::string &headline);
};

#endif //SDIZO_PROJECT_1_DATAFILEUTILITY_H

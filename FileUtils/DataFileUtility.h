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

    std::list<int> *readData(const std::string &FileName);

    static bool saveData(std::list<int> &outputList, const std::string &FileName);

    static bool
    saveTimerResults(const std::string &FileName, std::list<double> &results);

    static bool saveResultsHeadline(const std::string &FileName, const std::string &headline);

    static bool saveTimerResults2D(const std::string &FileName, std::list<std::list<double>> &results,
                                   const std::string &headline);
};

#endif //SDIZO_PROJECT_1_DATAFILEUTILITY_H

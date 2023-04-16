//
// Created by lukas on 01.04.2023.
//

#include "fstream"
#include "DataFileUtility.h"
#include "iostream"

using namespace std;

list<int> *DataFileUtility::readData(const string &FileName) {
    ifstream file;
    file.open(FileName, ios::in);
    int size;
    int val;

    if (file.is_open()) {
        file >> size;
        if (file.fail()) {
            cout << "File error - READ SIZE" << endl;
        } else {
            // tab = new int[size];
            for (int i = 0; i < size; i++) {
                file >> val;
                if (file.fail()) {
                    cout << "File error - READ DATA" << endl;
                    break;
                } else {
                    // tab[i] = val;
                    dataList.push_back(val);
                }
            }
            file.close();
        }
    } else {
        cout << "File error - OPEN" << endl;
    }
    return &dataList;
}

bool DataFileUtility::saveData(list<int> &outputList, const string &FileName) {
    ofstream file;
    file.open(FileName, ios::out);
    int size = (int) outputList.size();

    if (file.is_open()) {
        file << size << endl;
        if (file.fail()) {
            cout << "File error - SAVE SIZE" << endl;
            return false;
        } else {
            auto l_front = outputList.begin();
            for (int i = 0; i < size; i++) {
                file << *l_front << endl;
                advance(l_front, 1);
            }
            file.close();
        }
    } else {
        cout << "File error - OPEN" << endl;
        return false;
    }
    return true;
}

bool DataFileUtility::saveResultsHeadline(const string &FileName, const string &headline) {
    ofstream file;
    file.open(FileName, ios_base::app);
    if (file.is_open()) {
        file << headline << endl;
        if (file.fail()) {
            cout << "File error - SAVE HEADLINE" << endl;
            return false;
        }
    } else {
        cout << "File error - OPEN" << endl;
        return false;
    }
    return true;
}

bool
DataFileUtility::saveTimerResults(const string &FileName, list<double> &results) {
    ofstream file;
    file.open(FileName, ios_base::app);
    int size = (int) results.size();
    if (file.is_open()) {
        if (file.fail()) {
            cout << "File error" << endl;
            return false;
        } else {
            auto l_front = results.begin();
            for (int i = 0; i < size; i++) {
                file << *l_front << ",";
                advance(l_front, 1);
            }
            file << endl;
            file.close();
        }
    } else {
        cout << "File error - OPEN" << endl;
        return false;
    }
    return true;
}

bool DataFileUtility::saveTimerResults2D(const string &FileName, list<std::list<double>> &results,
                                         const string &headline) {
    ofstream file;
    file.open(FileName, ios::out);
    if (file.is_open()) {
        file << headline << endl;
        if (file.fail()) {
            cout << "File error - SAVE HEADLINE" << endl;
            return false;
        } else {

            for (auto l_front = results.begin(); l_front != results.end();
                 ++l_front) {
                for (auto inner_front = l_front->begin(); inner_front != l_front->end(); ++inner_front) {
                    file << *inner_front << ",";
                }
                file << endl;
            }
            file.close();

        }
    } else {
        cout << "File error - OPEN" << endl;
        return false;
    }
    return true;
}

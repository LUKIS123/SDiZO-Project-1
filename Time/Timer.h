//
// Created by lukas on 07.04.2023.
//

#ifndef SDIZO_PROJECT_1_TIMER_H
#define SDIZO_PROJECT_1_TIMER_H

#include "windows.h"
#include "iostream"
#include "iomanip"

class Timer {
public:
    long long int timerStart = 0;
    long long int timerStop = 0;
    long long int frequencyPerf = 0;

    static long long int read_QPC();

    static float getSeconds(long long int start, long long int end);

    static double getMilliSeconds(long long int start, long long int end);

    static double getMicroSeconds(long long int start, long long int end);

    static double getMicroSecondsAndPrint(long long int start, long long int end);

    void startTimer();

    double stopTimerAndGetMicroSecondsElapsed();

    void stopTimer();

    double getMicroSecondsElapsed();

    double getNanoSecondsElapsed();
};

#endif //SDIZO_PROJECT_1_TIMER_H

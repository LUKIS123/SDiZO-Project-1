//
// Created by lukas on 07.04.2023.
//

#include "iostream"
#include "Timer.h"
#include <limits>

using namespace std;

long long int Timer::read_QPC() {
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return ((long long int) count.QuadPart);
}

float Timer::getSeconds(long long int start, long long int end) {
    long long int frequency, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequency);
    elapsed = end - start;

    cout.precision(dbl::max_digits10);
    cout << "Time [s] = " << fixed << setprecision(3) << (float) elapsed / frequency << endl;
    return (float) (elapsed / frequency);
}

double Timer::getMilliSeconds(long long int start, long long int end) {
    long long int frequency, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequency);
    elapsed = end - start;

    cout.precision(dbl::max_digits10);
    cout << "Time [ms] = " << setprecision(0) << (1000.0 * elapsed) / frequency << endl;
    return ((1000.0 * elapsed) / frequency);
}

double Timer::getMicroSeconds(long long int start, long long int end) {
    long long int frequency, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequency);
    elapsed = end - start;

    cout.precision(dbl::max_digits10);
    cout << "Time [us] = " << setprecision(0) << (1000000.0 * elapsed) / frequency << endl << endl;
    return ((1000000.0 * elapsed) / frequency);
}

double Timer::stopTimerAndGetMicroSecondsElapsed() {
    timerStop = read_QPC();
    long long int frequency, elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequency);
    elapsed = timerStop - timerStart;
    return ((1000000.0 * elapsed) / frequency);
}

void Timer::startTimer() {
    timerStart = read_QPC();
}

void Timer::stopTimer() {
    timerStop = read_QPC();
}

double Timer::getMicroSecondsElapsed() {
    long long int elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequencyPerf);
    elapsed = timerStop - timerStart;
    return ((1000000.0 * elapsed) / frequencyPerf);
}

double Timer::getNanoSecondsElapsed() {
    long long int elapsed;
    QueryPerformanceFrequency((LARGE_INTEGER *) &frequencyPerf);
    elapsed = timerStop - timerStart;
    return ((1000000000.0 * elapsed) / frequencyPerf);
}

#ifndef WORK_H
#define WORK_H

#include <iostream>
#include <string>

#include "Task.h"

using namespace std;

class Work : public Task {
    private: 
        int shiftLength;
        double endBreak;
        int vacation;
        // string TYPE;
    public:
        Work(string, string, int, string, string, int, double, int);
        void setBreak(double);
        double getBreak();
        int getVacation();
        int getShiftLength();
        void print();
        void setVacation(int);
        void setShiftLength(int);
        virtual void displayAll();
        // string getType();
        void printMe();
};

#endif
#ifndef GROCERY_H
#define GROCERY_H

#include <iostream>
#include <string>
#include <vector>

#include "../header/Task.h"

using namespace std;

class Grocery : public Task {
    private: 
        vector<string>grocery_list;
        // string TYPE;
    public:
        Grocery(string, string, int, string, string);
        virtual void displayAll();
        void addItem(string);
        void delItem(string);
        string getItem(int);
        // string getType();
        void printMe();
};

#endif
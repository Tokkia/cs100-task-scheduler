
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <string>
#include <iostream>

#include "../header/Task.h"

using namespace std;

class TaskManager {
    private:
        vector<Task*> task;
    public:
        void addTask(Task *);
        void prioritySort();
        void deleteTask(int);
        void editTask(int);
        void changePriority(int, int);
        void displayAll();
        void findPrint(int);
        int size();
        Task *find(int);
        ~TaskManager();
};

#endif
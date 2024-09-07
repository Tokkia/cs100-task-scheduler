#ifndef TASK_H 
#define TASK_H 

#include <iostream>
#include <string>

using namespace std;

class Task {
    protected:
        string taskName;
        string description;
        int priority;
        string dueDate;
        string TYPE;
    public:
        Task(string, string, int, string, string);
        void setTaskName(string);
        void setDescription(string);
        void setPriority(int);
        void setDueDate(string);
        string getTaskName();
        string getDescription();
        string getDueDate();
        int getPrio();
        virtual void displayAll();
        void printMe();
        string getType();
        
};


#endif
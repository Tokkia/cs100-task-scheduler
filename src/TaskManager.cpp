#include <iostream>
#include <vector>
#include <string>

#include "../header/TaskManager.h"
#include "../header/Grocery.h"
#include "../header/Work.h"
#include "../header/Social.h"
#include "../header/School.h"

using namespace std;

int TaskManager::size() {
    return this->task.size();
}

Task* TaskManager::find(int in) {
    return task.at(in);
}

void TaskManager::editTask(int inNum) {
            
        string nName, nDesc, nDate;

        string t = task.at(inNum)->getType();

            if (t == "SCHOOL") {
                string nProf;
                string nSub;
                int nRoom;
                int nDur;

                cout << "Enter new professor: ";
                getline(cin, nProf);
                cout << endl;
                dynamic_cast<School*>(task.at(inNum))->setProfessor(nProf);
                
                cout << "Enter new Subject: ";
                getline(cin, nSub);
                cout << endl;
                dynamic_cast<School*>(task.at(inNum))->setSubject(nSub);
 
                cout << "Enter new classroom #: ";
                cin >> nRoom;
                cout << endl;
                dynamic_cast<School*>(task.at(inNum))->setClassroomNumber(nRoom);

                cout << "Enter new duration: ";
                cin >> nDur;
                cout << endl;
                dynamic_cast<School*>(task.at(inNum))->setDuration(nDur);
            }
            else if (t == "SOCIAL") {
                string dGuest;
                string nGuest;

                cout << "Enter guest name to be added: ";
                getline(cin, nGuest);
                cout << endl;
                dynamic_cast<Social*>(task.at(inNum))->addGuest(nGuest);

                cout << "Enter guest name to be removed: ";
                getline(cin, dGuest);
                cout << endl;
                dynamic_cast<Social*>(task.at(inNum))->delGuest(dGuest);

            }
            else if (t == "GROCERY") {
                string dItem;
                string nItem;

                cout << "Enter grocery item to be added: ";
                getline(cin, nItem);
                cout << endl;
                dynamic_cast<Grocery*>(task.at(inNum))->addItem(nItem);

                cout << "Enter grocery item name to be removed: ";
                getline(cin, dItem);
                cout << endl;
                dynamic_cast<Grocery*>(task.at(inNum))->delItem(dItem);
            }
            else if (t == "WORK") {
                int shiftLength;
                double nBreak;
                int vacation;

                cout << "Enter new shift length (in Hours): ";
                cin >> shiftLength;
                cout << endl;
                dynamic_cast<Work*>(task.at(inNum))->setShiftLength(shiftLength);

                cout << "Enter new break time: ";
                cin >> nBreak;
                cout << endl;
                dynamic_cast<Work*>(task.at(inNum))->setBreak(nBreak);

                cout << "Enter new vacation time period (in Days): ";
                cin >> vacation;
                cout << endl;
                dynamic_cast<Work*>(task.at(inNum))->setVacation(vacation);
            }
            else {
                cout << "Enter new task name: ";
                getline(cin, nName);
                cout << endl;
                task.at(inNum)->setTaskName(nName);

                cout << "Enter new description: ";
                getline(cin, nDesc);
                cout << endl;
                task.at(inNum)->setDescription(nDesc);

                cout << "Enter new due date: ";
                getline(cin, nDate);
                cout << endl;
                task.at(inNum)->setDueDate(nDate);
                
            }
}

void TaskManager::deleteTask(int x) {
    Task* tmp = nullptr;
    if((x - 1) == task.size()) {
        tmp = task.at(task.size()-1);
        task.pop_back();
    }
    else {
        for(unsigned i = 0; i < task.size(); ++i)  {
            if(i == x) {
                tmp = task.at(i);
                task.erase(task.begin() + i);
            }
        }
    }
    delete tmp;
}

void TaskManager::displayAll() {
    for(unsigned i = 0; i < task.size(); ++i) {
            task.at(i)->displayAll();
    }
}

void TaskManager::findPrint(int x) {
    if((x - 1) < 0 || (x - 1) > task.size()) {
        cout << "Invalid Task Number" << endl;
    }
    else {
        task.at(x - 1)->displayAll();
    }
}


void TaskManager::addTask(Task *inObj) {
    task.push_back(inObj);
}

void TaskManager::changePriority(int prioOne, int prioTwo) {
    int locationOne;

    task.at(prioOne)->setPriority(prioTwo);
    task.at(prioTwo)->setPriority(prioOne);

    Task *temp = task.at(prioOne);
    
    task.at(prioOne) = task.at(prioTwo);
    task.at(prioTwo) = temp;
}  

// void TaskManager::prioritySort() {
//     int key;
//     unsigned i, j;
//     for (i = 1; i < task.size(); i++) {
//         key = task.at(i)->getPrio();
//         j = i - 1;
 
//         while (j >= 0 && task.at(j)->getPrio() > key)
//         {
//             task.at(j + 1) = task.at(j);
//             j = j - 1;
//         }
//         task.at(j + 1) = task.at(i);
//     }
// }

TaskManager::~TaskManager(){
    for ( unsigned int i = 0; i < task.size(); i++){
        delete task.at(i);
    }
    
   
}

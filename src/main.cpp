#include "../header/TaskManager.h"
#include "../header/Grocery.h"
#include "../header/Work.h"
#include "../header/Social.h"
#include "../header/School.h"
#include "../header/Task.h"

#include <vector>
#include <string>
#include <iostream>

using namespace std;


void miniMenu(string &nName, string &nDesc, int &nPrio, string& nDue) {
            cout << "enter task name: " << endl;
            cin.ignore(1000,'\n');
            getline(cin, nName);
            cout << "enter task description: " << endl;
            getline(cin, nDesc);
            cout << "enter task priority: " << endl;
            cin >> nPrio;
            cout << "enter due date: " << endl;
            cin.ignore(1000,'\n');
            getline(cin, nDue);
}

void menu() {
    cout << "-------------TASK MANAGER-------------" << endl;
    cout << "A - Add Task" << endl;
    cout << "D - Delete Task" << endl;
    cout << "E - Edit Task" << endl;
    cout << "C - Change Priority" << endl;
    cout << "P - Display Chosen" << endl;
    cout << "O - Display All Tasks" << endl;
    cout << "q - Quit" << endl;
    cout << "--------------------------------------" << endl;
}

void TaskMenu() {
    cout << "1 - School Task" << endl;
    cout << "2 - Social Task" << endl;
    cout << "3 - Grocery Task" << endl;
    cout << "4 - Work Task" << endl;
    cout << "5 - Custom" << endl;
}

void BasicMenu() {
    cout << "1 - School Task" << endl;
    cout << "2 - Social Task" << endl;
    cout << "3 - Grocery Task" << endl;
    cout << "4 - Work Task" << endl;
    cout << "5 - Custom" << endl;
}

int main() {
    TaskManager taskNum;
    char option = ' ';

    string nTaskName, nTaskDesc, nDueDate;
    int nPriority;
    int input, numberTwo;
    int number = 1;

 while(option != 'q') {

        menu();
        cin >> option;

        if (option == 'A' || option == 'a') {
            TaskMenu();
            cin >> input;
            if (input == 1) {
                string nProf, nSub;
                int nRoom, nDur;

                miniMenu(nTaskName, nTaskDesc, nPriority, nDueDate);
                cout << "Enter Professor's Name: ";
                //cin.ignore('\n', 1000);
                getline(cin, nProf);
                cout << endl;

                cout << "Enter Subject: ";
                getline(cin, nSub);
                cout << endl;

                cout << "Enter Room Number: ";
                cin >> nRoom;
                cout << endl;

                cout << "Enter Duration (in Hours): ";
                cin >> nDur;
                cout << endl;

                School* obj = new School(nTaskName, nTaskDesc, nPriority, nDueDate, "SCHOOL", nProf, nRoom, nSub, nDur);
                taskNum.addTask(obj);
                
            }
            else if (input == 2) {
                string nGuest;
                string dGuest;
                int nDur;

                miniMenu(nTaskName, nTaskDesc, nPriority, nDueDate);

                cout << endl;

                Social* obj2 = new Social(nTaskName, nTaskDesc, nPriority, nDueDate, "SOCIAL", nDur);
                cout << "Enter guest names to be added, press q to end: ";
                while (cin >> nGuest && nGuest != "q") {
                    obj2->addGuest(nGuest);
                }
                
                getline(cin, nGuest);
                cout << endl;

                // cout << "Enter guest name to be removed: ";
                //  getline(cin, dGuest);
                // cout << endl;

                cout << "Enter duration of the event (in Hours): ";
                cin >> nDur;
                cout << endl;

                taskNum.addTask(obj2);
                
            }
            
            else if (input == 3) {
                string nItem;
                string dItem;
       

                miniMenu(nTaskName, nTaskDesc, nPriority, nDueDate);

                cout << endl;

             
                // cout << "Enter grocery item to be removed off list: ";
                // getline(cin, dItem);
                // cout << endl;

                Grocery* obj3 = new Grocery(nTaskName, nTaskDesc, nPriority, nDueDate, "GROCERY");
                cout << "Enter grocery items to be added, press q to end: ";
                    while (cin >> nItem && nItem != "q") {
                               obj3->addItem(nItem);
                    }
                getline(cin, nItem);
                cout << endl;
                 taskNum.addTask(obj3);
                 
            }
            else if (input == 4) {
                int shiftLength;
                double nBreak;
                int vacation;

                miniMenu(nTaskName, nTaskDesc, nPriority, nDueDate);
                
                cout << endl;

                cout << "Enter Shift length (in Hours): ";
                cin >> shiftLength;
                cout << endl;

                cout << "Enter Break Time: ";
                cin >> nBreak;
                cout << endl;

                cout << "Enter Vacation period (in Days): ";
                cin >> vacation;
                cout << endl;
                Work* obj4 = new Work(nTaskName, nTaskDesc, nPriority, nDueDate, "WORK", shiftLength, nBreak, vacation);
                taskNum.addTask(obj4);
              
            }
            else if (input == 5) {
                miniMenu(nTaskName, nTaskDesc, nPriority, nDueDate);

                Task* obj5 = new Task(nTaskName, nTaskDesc, nPriority, nDueDate, "CUSTOM");
                taskNum.addTask(obj5);
                
            }
        }
        else if(option == 'D' || option == 'd') {
            int input = 0;
            while((input - 1) < 0 || (input -1) > taskNum.size()) {
                cout << "Enter priority to be deleted: " << endl;
                cin >> input;
                if ( input > 0){
                    break;
                }
                if((input - 1) < 0 || (input -1) > taskNum.size()) {
                    cout << "Invalid Task Number" << endl;
                }
                
            }
            taskNum.deleteTask(input-1);
        }
        else if(option == 'E' || option == 'e') {
            taskNum.displayAll();

            while((number - 1) <= 0 || (number -1) > taskNum.size()) {
                cout << "Enter task to be edited: " << endl;
                cin >> number;
                cin.ignore();
                if ( number == 0){
                    break;
                }
                if((number - 1) < 0 || (number -1) > taskNum.size()) {
                    cout << "Invalid Task Number" << endl;
                }
                taskNum.editTask(number-1);
            }
               // taskNum.editTask(number); 
        }
        else if(option == 'C' || option == 'c') {
            cout << "Enter priority to be changed: " << endl;
            cin >> number;
            cout << endl;

            cout << "What you would like to change the priority to: ";
            cin >> numberTwo;
            cout << endl;

            taskNum.changePriority(number, numberTwo);
        }
        else if(option == 'P' || option == 'p') {
            cout << "Enter priority to be displayed: " << endl;
            cin >> nPriority;
            taskNum.findPrint(nPriority);
        }
        else if(option == 'O' || option == 'o') {
            taskNum.displayAll();
        }
        else if(option == 'q' || option == 'Q') {
            cout << endl;
            cout << "Quitting..." << endl;
            taskNum.~TaskManager(); 
            exit(1);
        }
        else {
            cout << "---Invalid Option---" << endl;
        }
    }
    return 0;

}

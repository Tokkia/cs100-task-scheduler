#include "../header/Task.h"

Task::Task(string name, string desc, int prio, string date, string t) {
    this->taskName = name;
    this->description = desc;
    this->priority = prio;
    this->dueDate = date;
    this->TYPE = t;
}

void Task::setTaskName(string N) {
    this->taskName = N;
}

void Task::setDescription(string D) {
    this->description = D;
}

void Task::setPriority(int P) {
    this->priority = P;
}

void Task::setDueDate(string DD) {
    this->dueDate = DD;
}

string Task::getTaskName() {
    return this->taskName;
}

string Task::getDescription() {
    return this->description;
}

int Task::getPrio() {
    return this->priority;
}

string Task::getDueDate() {
    return this->dueDate;
}

 void Task::displayAll() {
    cout << "| " << taskName << " |" << " - " << dueDate << endl;
    cout << "- " << description << endl;
 }

void Task::printMe() {
    displayAll();
}

string Task::getType() {
    return this->TYPE;
}


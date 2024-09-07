#include "../header/Work.h"


Work::Work(string name, string d, int p, string date, string t, int shiftLen, double endB, int vaca) : Task(name, d, p, date, t), endBreak(endB), shiftLength(shiftLen), vacation(vaca) {};

void Work::setBreak(double inBreak){
    this->endBreak = inBreak;
    // cout << "Type the date and the length of the break in minutes" << endl;
    // getline(cin, date);
    // cin >> endBreak;
    // cout << "At " << date << " you have " << endBreak << " minutes for break" << endl;

}

void Work::setVacation(int inVac){
    this->vacation = inVac;
    // cout << "Type the date and the length of the vacation in days" << endl;
    // getline(cin, date);
    // cin >> vacation;
    // cout << "At " << date << " you have " << vacation << " days for vacation" << endl;

}

void Work::setShiftLength(int inShift){
    this->shiftLength = inShift;
    // cout << "Type the date and the length of the shift in hours" << endl;
    // getline(cin, date);
    // cin >> shiftLength;
    // cout << "The shift length is " << shiftLength << "minutes" << endl;
}

double Work::getBreak() {
    return endBreak;
}

int Work::getVacation() {
    return vacation;
}

int Work::getShiftLength() {
    return shiftLength;
}

void Work::displayAll() {
    Task::displayAll();
    cout << "Break is " << endBreak << " minutes." << endl;
    cout << "Vacation is " << vacation << " days." << endl;
    cout << "Shiftlength is " << shiftLength << " hours." << endl;
}

// string Work::getType() {
//     return this->TYPE;
// }

void Work::printMe() {
    Task::printMe();
}







// #include "../header/Work.h"

// #include <string>

// Work::Work() {
//     Task::Task();
//     this->endBreak = 0;
//     this->shiftLength = 0;
//     this->vacation = 0;
// }

// Work::Work(string name, string d, int p, string date, doble endBreak, int shiftLength, int vacation){
//     Task::Task(name, d, p, date);
//     this->endBreak = endBreak;
//     this->shiftLength = shiftLength;
//     this->vacation = vacation;
// }

// void Work::setBreak(){
//     cout << "Type the date and the length of the break in minutes" << endl;
//     getline(cin, date);
//     cin >> endBreak;
//     cout << "At " << date << " you have " << endBreak << " minutes for break" << endl;

// }

// void Work::setVacation(){
//     cout << "Type the date and the length of the vacation in days" << endl;
//     getline(cin, date);
//     cin >> vacation;
//     cout << "At " << date << " you have " << vacation << " days for vacation" << endl;

// }

// void Work::setShiftLength(){
//     cout << "Type the date and the length of the shift in hours" << endl;
//     getline(cin, date);
//     cin >> shiftLength;
//     cout << "The shift length is " << shiftLength << "minutes" << endl;
// }

// void Work::DisplayAll() override{
//     Task::DisplayAll();

//     cout << "Break is " << endBreak << " minutes on" << date << endl;
//     cout << "Vacation is " << vacation << " days on " << date << endl;
//     cout << "Shiftlength is " Shiftlength << " hours on " << date << endl;
// }
#include <iostream>
#include <vector>
#include <string>

#include "../header/Social.h"

using namespace std;

// string Social::getType() {
//     return this->TYPE;
// }

Social::Social(string tN, string tD, int tP, string tDate, string t, int dur) : Task(tN, tD, tP, tDate, t), duration(dur) {};

void Social::addGuest(string g) {
    guestList.push_back(g);
}

void Social::delGuest(string guestName) {
    for (int i = 0; i < guestList.size(); i++) {
        if (guestList.at(i) == guestName) {
            guestList.erase(guestList.begin() + i);
            break;
        }
    }
}

string Social::getGuest(int x) {
    return guestList.at(x);
}

int Social::getDuration() {
    return this->duration;
}

void Social::displayAll() {
    Task::displayAll();
    int count = 1;

    cout << "Guest List:" << endl;
    for (int i = 0; i < guestList.size(); i++) {
        cout << count << ") " << guestList.at(i) << endl;
        count++;
    }

    cout << endl << "Event Length: " << duration << endl << endl;
}

void Social::printMe() {
    Task::printMe();
}
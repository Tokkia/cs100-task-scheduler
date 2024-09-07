#include "../header/Grocery.h"

Grocery::Grocery(string name, string desc, int pri, string due, string t) : Task(name, desc, pri, due, t) {};

// string Grocery::getType() {
//     return this->TYPE;
// }

void Grocery::displayAll() {
    Task::displayAll();
    cout << "--------Grocery List--------" << endl;
    for(unsigned i = 0; i < grocery_list.size(); ++i) {
        cout << "- " << grocery_list.at(i) << endl;
   }
}

void Grocery::addItem(string grocItem) {
    
    grocery_list.push_back(grocItem);
    cout << "succesfully added item to list" << endl;
    }

void Grocery::delItem(string itemToDelete) { ///
    for (int i = 0; i < grocery_list.size(); i ++ ) {
        if (grocery_list.at(i) == itemToDelete) {
            grocery_list.erase(grocery_list.begin() + i);
            cout << "succesfully deleted item" << itemToDelete << endl;
            break;
        }
    }
}

string Grocery::getItem(int x) {
    return grocery_list.at(x);
}

void Grocery::printMe() {
    Task::printMe();
}
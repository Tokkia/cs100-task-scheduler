#ifndef SOCIAL_HPP
#define SOCIAL_HPP

#include "../header/Task.h"

class Social : public Task {
    private:
        vector<string> guestList;
        int duration;
        // string TYPE;
    public:
        Social(string, string, int, string, string, int);
        // string getType();
        void addGuest(string);
        void delGuest(string);
        string getGuest(int x);
        int getDuration();
        virtual void displayAll();
        void printMe();
};

#endif
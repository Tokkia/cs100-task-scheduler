#ifndef SCHOOL_H
#define SCHOOL_H

#include <iostream>
#include <string>

#include "../header/Task.h"

using namespace std;

    class School : public Task {
        private:
            string professor;
            int classroomNumber;
            string subject;
            int duration;
            // string TYPE;
        public:
            School(string, string, int, string, string, string, int, string, int);
            virtual void displayAll();
            void setProfessor(string);
            void setClassroomNumber(int);
            void setSubject(string);
            void setDuration(int);
            string getProfessor();
            int getClassroomNumber();
            string getSubject();
            int getDuration();
            // string getType();
            void printMe();
    };



#endif
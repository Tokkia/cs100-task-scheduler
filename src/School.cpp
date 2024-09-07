#include "../header/School.h"

School::School(string name, string d, int p, string date, string t, string prof, int roomNumber, string sub, int dur) : Task(name, d, p, date, t), professor(prof), classroomNumber(roomNumber), subject(sub), duration(dur) {};

// string School::getType() {
//     return this->TYPE;
// }

void School::displayAll()  {
    Task::displayAll();
    
    cout << "Professor: " << getProfessor() << endl;
    cout << "Classroom: " << getClassroomNumber() << endl;
    cout << "Subject: " << getSubject() << endl;
    cout << "Duration: " << getDuration() << " hours" << endl;
}

void School::setProfessor(string P) {
    this->professor = P;
}

void School::setClassroomNumber(int N) {
     this->classroomNumber = N;
}

void School::setSubject(string S) { 
    this->subject = S;
}

void School::setDuration(int D) {
     this->duration = D;
}

string School::getProfessor() {
    return this->professor;
}

int School::getClassroomNumber() {
    return this->classroomNumber;
}
string School::getSubject() {
    return this->subject;
}
int School::getDuration() {
    return this->duration;
}
void School::printMe() {
    Task::printMe();
}
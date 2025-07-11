#include "Staff.h"

Staff::Staff() : Person(), post(""), workSchedule("") {}
Staff::Staff(const string& firstName, const string& lastName, int age, const string& p, const string& post, const string& workSchedule)
    : Person(firstName, lastName, age, p), post(post), workSchedule(workSchedule) {}

string Staff::getPost() const 
{
    return post; 
}

string Staff::getWorkSchedule() const 
{
    return workSchedule; 
}

void Staff::setPost(const string& post)
{
    this->post = post; 
}

void Staff::setWorkSchedule(const string& workSchedule) 
{
    this->workSchedule = workSchedule; 
}

void Staff::display() const 
{
    Person::display();
    cout << "Должность: " << post << endl;
    cout << "График работы: " << workSchedule << endl;
}
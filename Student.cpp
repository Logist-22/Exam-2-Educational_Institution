#include "Student.h"




Student::Student() : Person(), studentId(""), course(0), averageGrade(0.0) {}
Student::Student(const string& firstName, const string& lastName, int age, const string& phone, const string& studentId, int course, double averageGrade) 
    : Person(firstName, lastName, age, phone), studentId(studentId), course(course), averageGrade(averageGrade) {}

string Student::getStudentId() const 
{
    return studentId; 
}

int Student::getCourse() const
{
    return course; 
}

double Student::getAverageGrade() const
{
    return averageGrade; 
}

void Student::setStudentId(const string& studentId)
{
    this->studentId = studentId; 
}

void Student::setCourse(int course)
{
    this->course = course; 
}

void Student::setAverageGrade(double averageGrade)
{
    this->averageGrade = averageGrade; 
}

void Student::display() const 
{
    Person::display();
    cout << "Студенческий билет: " << studentId << endl;
    cout << "Курс: " << course << endl;
    cout << "Средний балл: " << averageGrade << endl;
    cout << endl;
}
#include "Student.h"




Student::Student() : Person(), studentId(""), year(0), averageGrade(0.0) {}

Student::Student(const string& firstName, const string& lastName, int age, const string& phone, string studentId, int year, double averageGrade)
    : Person(firstName, lastName, age, phone), studentId(studentId), year(year), averageGrade(averageGrade) {}



string Student::getStudentId() const 
{
    return studentId; 
}

int Student::getCourse() const
{
    return year;
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
    this->year = course;
}

void Student::setAverageGrade(double averageGrade)
{
    this->averageGrade = averageGrade; 
}

void Student::display() const 
{
    Person::display();
    cout << "Студенческий билет: " << studentId << endl;
    cout << "Курс: " << year << endl;
    cout << "Средний балл: " << averageGrade << endl;
    cout << endl;
}



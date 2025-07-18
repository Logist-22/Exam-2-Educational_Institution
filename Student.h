#pragma once
#include "Person.h"


class Student : public Person
{

private:

   
    string studentId;   
    int year;            //  курс 
    double averageGrade;   // средн€€ оценка 

public:
    Student();   
    Student(const string& firstName, const string& lastName, int age, const string& phone, string studentId, int year, double averageGrade);
    ~Student() override {};
    
    string getStudentId() const;
    int getCourse() const;
    double getAverageGrade() const;

    void setStudentId(const string& studentId);
    void setCourse(int year);
    void setAverageGrade(double averageGrade);

    void display() const override;
    
};











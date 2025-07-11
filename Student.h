#pragma once
#include "Person.h"
//#include<iostream>
//#include<string>



class Student : public Person
{

private:
    string studentId;
    int course;            //  курс 
    double averageGrade;   // средн€€ оценка 

public:
    Student();
    Student(const string& firstName, const string& lastName, int age, const string& phone, const string& studentId, int course, double averageGrade);
    ~Student() override {};
    
    string getStudentId() const;
    int getCourse() const;
    double getAverageGrade() const;

    void setStudentId(const string& studentId);
    void setCourse(int course);
    void setAverageGrade(double averageGrade);

    void display() const override;
};











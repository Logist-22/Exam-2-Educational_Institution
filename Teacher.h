#pragma once
#include "Person.h"
#include "Student.h"

class Teacher : public Person
{
private:
    string academicDegree;          //ученая степень
    int experience;                 //стаж
    vector<string> taughtCourses;   //преподаваемые дисциплины

public:
    Teacher();
    Teacher(const string& firstName, const string& lastName, int age, const string& phone, const string& academicDegree, int experience);
    ~Teacher() override {};

    string getAcademicDegree() const;
    int getExperience() const;
    const vector<string>& getTaughtCourses() const;

    void setAcademicDegree(const string& academicDegree);
    void setExperience(int experience);

    void addCourse(const string& course);       //добавление преподаваемой дисциплины
    void removeCourse(const string& course);    //удаление преподаваемой дисциплины
    void display() const override;    
};










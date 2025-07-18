#pragma once
#include <iomanip>
#include<vector>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"


class Course
{
private:
    string courseName;          // наименование курса
    string code;                // код курса
    Teacher* teacher;           //учитель курса
    vector<Student*> students;  // студенты курса
    void addPerson();
public:
    Course(const string& courseName, const string& code);

    string getCourseName() const;
    string getCode() const;
    Teacher* getTeacher() const;
    const vector<Student*>& getStudents() const;

    void setCourseName(const string& courseName);
    void setCode(const string& code);
    void setTeacher(Teacher* teacher);

    void addStudent(Student* student);
    void removeStudent(Student* student);
    double calculateAverageGrade() const;            //средняя оценка  

    void display() const;
   
};












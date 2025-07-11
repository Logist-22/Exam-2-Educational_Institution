#pragma once
#include <iomanip>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Course.h"
#include "Department.h"

class EducationalInstitution
{
private:
    string nameInstitution;
    vector<Department*> departments;
    vector<Person*> allStaff;

public:
    EducationalInstitution(const string& nameInstitution);   

    string getNameInstitution() const;
    int getAllStudents() const;          // общее количество студентов в учебном заведении
    int getAllTeachers() const;          // общее количество учителей в учебном заведении
    double getInstitutionAverageGrade() const;          // общий средний балл по институту
    const vector<Department*>& getDepartments() const;
    const vector<Person*>& getAllStaff() const;

    void addDepartment(Department* department);
    void removeDepartment(Department* department);
    void addStaff(Person* person);
    void removeStaff(Person* person);
    void displayStatistics() const;
};


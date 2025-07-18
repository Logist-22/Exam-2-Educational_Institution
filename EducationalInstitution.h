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
    vector <Person*> allPerson;
   

public:
    EducationalInstitution(const string& nameInstitution);  
    ~EducationalInstitution();

    string getNameInstitution() const;

    int getAllStudents() const;          // общее количество студентов в учебном заведении
    int getAllTeachers() const;          // общее количество учителей в учебном заведении
    int getAllStaff() const;            // общее количество административных сотрудников в учебном заведении
    double getInstitutionAverageGrade() const;          // общий средний балл по институту
    const vector<Department*>& getDepartments() const;
    const vector<Person*>& getAllPerson() const;   

    void addDepartment(Department* department);
    void removeDepartment(Department* department);
    void addPerson(Person* person);
    void removePerson(Person* person);

    void displayAllTeachers() const;

    void displayStatistics() const;
};


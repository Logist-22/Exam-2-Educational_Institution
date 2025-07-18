#pragma once
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Course.h"


class Department
{    
private:
    string departmentName;      //�������� �������
    Teacher* headDepartment;    //���������� ��������
    vector<Teacher*> teachers;  // ������������� �������
    vector<Course*> courses;    // ����� �������

public:
    Department(const string& departmentName);
    ~Department();
    
    string getDepartmentName() const;
    Teacher* getHeadDepartment() const;
    const vector<Teacher*>& getTeachers() const;
    const vector<Course*>& getCourses() const;
    
    void setDepartmentName(const string& departmentName);
    void setHeadDepartment(Teacher* headDepartment);
    
    void addTeacher(Teacher* teacher);
    void removeTeacher(Teacher* teacher);
    void addCourse(Course* course);
    void removeCourse(Course* course);
    void display() const;
};


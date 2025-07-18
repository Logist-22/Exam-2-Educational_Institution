#pragma once
#include "Person.h"
#include "Student.h"

class Teacher : public Person
{
private:
    string academicDegree;          //������ �������
    int experience;                 //����
    vector<string> taughtCourses;   //������������� ����������

public:
    Teacher();
    Teacher(const string& firstName, const string& lastName, int age, const string& phone, const string& academicDegree, int experience);
    ~Teacher() override {};

    string getAcademicDegree() const;
    int getExperience() const;
    const vector<string>& getTaughtCourses() const;

    void setAcademicDegree(const string& academicDegree);
    void setExperience(int experience);

    void addCourse(const string& course);       //���������� ������������� ����������
    void removeCourse(const string& course);    //�������� ������������� ����������
    void display() const override;    
};










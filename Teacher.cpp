#include "Teacher.h"


Teacher::Teacher() : Person(), academicDegree(""), experience(0) {}
Teacher::Teacher(const string& firstName, const string& lastName, int age, const string& phone, const string& academicDegree, int experience)
    : Person(firstName, lastName, age, phone), academicDegree(academicDegree), experience(experience) {}

string Teacher::getAcademicDegree() const   
{ 
    return academicDegree; 
}

int Teacher::getExperience() const      
{ 
    return experience; 
}

const vector<string>& Teacher::getTaughtCourses() const     
{
    return taughtCourses; 
}

void Teacher::setAcademicDegree(const string& academicDegree)
{
    this->academicDegree = academicDegree; 
}

void Teacher::setExperience(int experience)
{
    this->experience = experience; 
}

void Teacher::addCourse(const string& course)
{
    taughtCourses.push_back(course);        //���������� ������������� ����������
}

void Teacher::removeCourse(const string& course)                                         ////�������� ������������� ����������
{
    taughtCourses.erase(remove(taughtCourses.begin(), taughtCourses.end(), course), taughtCourses.end()); 
}

void Teacher::display() const 
{
    Person::display();
    cout << "������ �������: " << academicDegree << endl;
    cout << "���� ������: " << experience << " ���� (���)" << endl;
    cout << "������������� ����������: ";
    for (const auto& course : taughtCourses)
    {
        cout << course << ", ";
    }
    cout << endl<<endl;
}
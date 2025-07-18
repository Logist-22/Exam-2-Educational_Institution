#include "Department.h"

Department::Department(const string& departmentName) : departmentName(departmentName), headDepartment(nullptr) {}
Department::~Department()
{
    for (Course* course : courses) 
    {
        delete course; 
    }
    courses.clear();
}


string Department::getDepartmentName() const 
{
    return departmentName; 
}

Teacher* Department::getHeadDepartment() const 
{
    return headDepartment; 
}

const vector<Teacher*>& Department::getTeachers() const 
{
    return teachers; 
}

const vector<Course*>& Department::getCourses() const 
{
    return courses; 
}

void Department::setDepartmentName(const string& departmentName) 
{
    this->departmentName = departmentName; 
}

void Department::setHeadDepartment(Teacher* headDepartment) 
{
    this->headDepartment = headDepartment; 
}

void Department::addTeacher(Teacher* teacher)
{
    teachers.push_back(teacher);
}

void Department::removeTeacher(Teacher* teacher)
{
    teachers.erase(remove(teachers.begin(), teachers.end(), teacher), teachers.end());
    if (headDepartment == teacher)
    {
        headDepartment = nullptr;
    }
}

void Department::addCourse(Course* course)
{
    courses.push_back(course);
}

void Department::removeCourse(Course* course)
{
    courses.erase(remove(courses.begin(), courses.end(), course), courses.end());
}

void Department::display() const {
    cout << "�������: " << departmentName << endl;
    if (headDepartment) {
        cout << "���������� ��������: " << headDepartment->getFirstName() << " " << headDepartment->getLastName() << endl;
    }
    else
    {
        cout << "���������� �� ��������" << endl;
    }
    cout << "���� ��������: " << teachers.size() << endl;
    cout << endl;
    if (teachers.empty()) 
    {
        cout << "��� ������������ �������� �� ��������" << endl;        
    }
    else
    {
        cout << "������ ��������������:" << endl;
        cout << "------------------------------------------------------" << endl;
        int num1 = 1;
        for (const auto& teacher : teachers) 
        {
            cout << num1++ << ". ";
            teacher->display();
            cout << "--------------------------------------------------" << endl;
        }
    }
    cout << endl;
    cout << "����� ������: " << courses.size() << endl;
    if (courses.empty())
    {
        cout << "�� �������� ��� ������������ ������" << endl;
    }
    else
    {
        cout << "������ ������:" << endl;
        cout << "-----------------------------------------------------" << endl;
        int num2 = 1;
        for (const auto& course : courses) 
        {
            cout << num2++ << ". ";
            course->display();
            cout << "-------------------------------------------------" << endl;
        }
    }
    cout << endl;
}
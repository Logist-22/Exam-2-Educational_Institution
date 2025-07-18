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
    cout << "Кафедра: " << departmentName << endl;
    if (headDepartment) {
        cout << "Заведующий кафедрой: " << headDepartment->getFirstName() << " " << headDepartment->getLastName() << endl;
    }
    else
    {
        cout << "Заведующий не назначен" << endl;
    }
    cout << "Штат учителей: " << teachers.size() << endl;
    cout << endl;
    if (teachers.empty()) 
    {
        cout << "Нет закрепленных учителей за кафедрой" << endl;        
    }
    else
    {
        cout << "Список преподавателей:" << endl;
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
    cout << "Всего курсов: " << courses.size() << endl;
    if (courses.empty())
    {
        cout << "За кафедрой нет закретленных курсов" << endl;
    }
    else
    {
        cout << "Список курсов:" << endl;
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
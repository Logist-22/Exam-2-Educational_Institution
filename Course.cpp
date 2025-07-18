#include "Course.h"
#include "Student.h"


Course::Course(const string& courseName, const string& code) : courseName(courseName), code(code), teacher(nullptr) {}

string Course::getCourseName() const
{
    return courseName; 
}

string Course::getCode() const
{
    return code; 
}

Teacher* Course::getTeacher() const
{
    return teacher; 
}

const vector<Student*>& Course::getStudents() const
{
    return students; 
}

void Course::setCourseName(const string& courseName)
{
    this->courseName = courseName; 
}

void Course::setCode(const string& code)
{
    this->code = code; 
}

void Course::setTeacher(Teacher* teacher) 
{
    this->teacher = teacher; 
}

void Course::addStudent(Student* student)
{
    students.push_back(student);    
}

void Course::removeStudent(Student* student)
{
    students.erase(remove(students.begin(), students.end(), student), students.end());
}

double Course::calculateAverageGrade() const            //средняя оценка
{
    if (students.empty())
    {
        return 0.0;
    }
    double sum = 0.0;
    for (const auto& student : students)
    {
        sum += student->getAverageGrade();
    }
    return sum / students.size();
}

void Course::display() const
{
    cout << "Наименование курса: " << courseName << " (" << code << ")" << endl;
    if (teacher)
    {
        cout << "Преподаватель: " << teacher->getFirstName() << " " << teacher->getLastName() << endl;
    }
    cout << "Количество студентов на курсе: " << students.size() << endl;
    cout << "Средняя оценка на курсе: " << fixed << setprecision(2) << calculateAverageGrade() << endl;
}
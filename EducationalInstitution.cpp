#include "EducationalInstitution.h"



EducationalInstitution::EducationalInstitution(const string& nameInstitution) : nameInstitution(nameInstitution) {}

string EducationalInstitution::getNameInstitution() const 
{
    return nameInstitution; 
}

const vector<Department*>& EducationalInstitution::getDepartments() const
{
    return departments; 
}
const vector<Person*>& EducationalInstitution::getAllStaff() const
{
    return allStaff; 
}

void EducationalInstitution::addDepartment(Department* department)
{
    departments.push_back(department);
}

void EducationalInstitution::removeDepartment(Department* department)
{
    departments.erase(remove(departments.begin(), departments.end(), department), departments.end());
}

void EducationalInstitution::addStaff(Person* person)
{
    allStaff.push_back(person);
}

void EducationalInstitution::removeStaff(Person* person)
{
    allStaff.erase(remove(allStaff.begin(), allStaff.end(), person), allStaff.end());
}

int EducationalInstitution::getAllStudents() const          // общее количество студентов в учебном заведении
{
    int count = 0;
    for (const auto& department : departments) {
        for (const auto& course : department->getCourses()) {
            count += course->getStudents().size();
        }
    }
    return count;
}

int EducationalInstitution::getAllTeachers() const          // общее количество учителей в учебном заведении
{
    int count = 0;
    for (const auto& department : departments) {
        count += department->getTeachers().size();
    }
    return count;
}

double EducationalInstitution::getInstitutionAverageGrade() const           // общий средний балл по институту
{
    double sum = 0.0;
    for (const auto& department : departments)
    {
        for (const auto& course : department->getCourses())
        {
            for (const auto& student : course->getStudents())
            {
                sum += student->getAverageGrade();
            }
        }
    }
    return sum / getAllStudents();
}

void EducationalInstitution::displayStatistics() const 
{
    cout << "Наименование учреждения: " << nameInstitution << endl;
    cout << "Всего кафедр: " << departments.size() << endl;
    cout << "Всего студентов: " << getAllStudents() << endl;
    cout << "Штат учителей: " << getAllTeachers() << endl;
    cout << "Штат административного персонала: " << allStaff.size() << endl;
    cout << "Средний балл по учебному заведению: " << fixed << setprecision(2) << getInstitutionAverageGrade() << endl;
}





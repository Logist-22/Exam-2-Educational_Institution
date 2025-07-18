#include "EducationalInstitution.h"



EducationalInstitution::EducationalInstitution(const string& nameInstitution) : nameInstitution(nameInstitution) {}
EducationalInstitution::~EducationalInstitution()
{
    for (Person* person : allPerson) 
    {
        delete person;
    }    
    for (Department* dept : departments) 
    {
        delete dept;
    }
    allPerson.clear();
    departments.clear();
}


string EducationalInstitution::getNameInstitution() const 
{
    return nameInstitution; 
}

const vector<Department*>& EducationalInstitution::getDepartments() const
{
    return departments; 
}
const vector<Person*>& EducationalInstitution::getAllPerson() const
{
    return allPerson;
}

void EducationalInstitution::addDepartment(Department* department)
{
    departments.push_back(department);
}

void EducationalInstitution::removeDepartment(Department* department)
{
    departments.erase(remove(departments.begin(), departments.end(), department), departments.end());
}

void EducationalInstitution::addPerson(Person* person)
{
    allPerson.push_back(person);
}

void EducationalInstitution::removePerson(Person* person)
{
    allPerson.erase(remove(allPerson.begin(), allPerson.end(), person), allPerson.end());
}

int EducationalInstitution::getAllStudents() const          // ����� ���������� ��������� � ������� ���������
{
    int count = 0;
    for (const auto& person : allPerson)
    {
        if (dynamic_cast<Student*>(person))
        {
            count++;
        }
    }
    return count;
}

int EducationalInstitution::getAllTeachers() const          // ����� ���������� �������� � ������� ���������
{
    int count = 0;
    for (const auto& person : allPerson)
    {
        if (dynamic_cast<Teacher*>(person))
        {
            count++;
        }
    }
    return count;
}


int EducationalInstitution::getAllStaff() const
{
    int count = 0;
    for (const auto& person : allPerson)
    {
        if (dynamic_cast<Staff*>(person))
        {
            count++;
        }
    }
    return count;
}


double EducationalInstitution::getInstitutionAverageGrade() const           // ����� ������� ���� �� ���������
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
    return sum>0?sum / getAllStudents():0.0;
}


void EducationalInstitution::displayAllTeachers() const 
{
    if (getAllTeachers() == 0)
    {
        cout << "� ������� ��������� ��� ��������������." << endl;
        return;
    }    
    cout << "\n--- ������ ���� ��������������, �����: " << getAllTeachers() << " ---\n";
    int counter = 0;
    for (const auto& person : allPerson) 
    {
        if (auto teacher = dynamic_cast<Teacher*>(person))
        {
            cout << counter + 1 << ". " << teacher->getFirstName() << " " << teacher->getLastName()<<endl;
            counter++;
        }
    }
}





void EducationalInstitution::displayStatistics() const 
{
    cout << "������������ ����������: " << nameInstitution << endl;
    cout << "����� ������: " << departments.size() << endl;
    cout << "����� ���������: " << getAllStudents() << endl;
    cout << "���� ��������: " << getAllTeachers() << endl;
    cout << "���� ����������������� ���������: " << getAllStaff() << endl;
    cout << "������� ���� �� �������� ���������: " << fixed << setprecision(2) << getInstitutionAverageGrade() << endl;
}





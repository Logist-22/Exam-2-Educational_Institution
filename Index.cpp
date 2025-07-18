#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Course.h"
#include "EducationalInstitution.h"

using namespace std;

class Person;           //������� �����
class Student;          //����� �������, ����������� ����� �� Person
class Teacher;         //����� �������, ����������� ����� �� Person
class Staff;            // ����� ����������������� ���������, ����������� ����� �� Person
class Course;              // ����� ����
class Department;                //����� �������
class EducationalInstitution;   //����� �������� ����������


void PersonData(string& firstName, string& lastName, int& age, string& phone)
{
    cout << "������� ���: ";
    getline(cin, firstName);
    cout << "������� �������: ";
    getline(cin, lastName);
    cout << "������� �������: ";
    cin >> age;
    cin.ignore();
    cout << "������� ����� ��������: ";
    getline(cin, phone);
}


bool departmentSelection(EducationalInstitution& EducationalInstitution, int& depIndex)
{
    if (EducationalInstitution.getDepartments().empty())
    {
        cout << "� ������� ���������� ��� ��������� ������, �������� �������." << endl;
        return false;
    }
    int num = 1;
    cout << "������ ������: " << endl;
    for (const auto& dep : EducationalInstitution.getDepartments())
    {
        cout << num++ << ". " << dep->getDepartmentName() << endl;
    }
    cout << "�������� ���������� ����� �������: ";
    cin >> depIndex;
    cin.ignore();
    depIndex--;
    if (depIndex < 0 || depIndex >= EducationalInstitution.getDepartments().size())
    {
        cout << "������ ��� ������ �������." << endl;
        return false;
    }
    return true;
}


bool courseSelection(Department* department, int& courseIndex)
{
    if (department->getCourses().empty())
    {
        cout << "�� ���� ������� ��� ������. �������� ����." << endl;
        return false;
    }
    int num = 1;
    cout << "����� ������� " << department->getDepartmentName() << ": " << endl;
    for (const auto& course : department->getCourses())
    {
        cout << num++ << ". " << course->getCourseName() << " (��� " << course->getCode() << ")" << endl;
    }
    cout << "�������� ���� (������� ���������� �����): ";
    cin >> courseIndex;
    cin.ignore();
    courseIndex--;
    if (courseIndex < 0 || courseIndex >= department->getCourses().size())
    {
        cout << "������ ��� ������ �����." << endl;
        return false;
    }
    return true;
}


int main()
{
    setlocale(LC_ALL, "RU");
    string firstName, lastName, phone;
    int age;

    //������� ����������
    EducationalInstitution Academy("���");

    Department programming("����������������");

    Academy.addDepartment(&programming);        //���������� ������� � ����������

    //�������
     Teacher teacher1("�����", "�������", 35, "+79233330101", "���", 15);
     Teacher teacher2("����", "�������", 42, "+79234540202", "���", 18);
     Teacher teacher3("����������", "������", 51, "+79293977305", "������", 30);

     Academy.addPerson(&teacher1);
     Academy.addPerson(&teacher2);
     Academy.addPerson(&teacher3);

    
 //��������   

    Student student1("����", "��������", 20, "23-45-54","��-001", 1, 4.5);
    Student student2("�������", "�������", 21, "22-55-44", "��-002", 1, 4.0);
    Student student3("������", "ĸ���", 18, "12-78-67", "��-003", 1, 4.9);

    Academy.addPerson(&student1);
    Academy.addPerson(&student2);
    Academy.addPerson(&student3);

       //�������������
    Staff rector("��������", "������", 58, "69-69-69", "������", "��-��");
    Staff buhg("�������", "������", 49, "22-69-73", "���������", "��-��");

    Academy.addPerson(&rector);      //���������� ���������������� ����������� � ����������
    Academy.addPerson(&buhg);

       //�������   

    programming.setHeadDepartment(&teacher1);   //���������� ����������� ��������
    programming.addTeacher(&teacher2);          //���������� �������� �� �������
    programming.addTeacher(&teacher3);
    programming.addTeacher(&teacher1);

    Course Cplus("C++", "���411");     // �������� ������
  
    programming.addCourse(&Cplus);      //���������� ������ �� �������
   
    Cplus.addStudent(&student1);        //��������� ��������� �� ���� � �������������
    Cplus.addStudent(&student2);
    Cplus.addStudent(&student3);
    Cplus.setTeacher(&teacher2);
    

    int ch;
    do
    {
        cout << "\n=== ������� ���������� ������������� ===" << endl;
        cout << "1. ���������� ����������" << endl;
        cout << "2. ���������� ���������" << endl;
        cout << "3. ���������� �������" << endl;
        cout << "4. �������� ����������" << endl;
        cout << "0. �����" << endl;
        cout << "�������� ��������: ";
        cin >> ch;
        cin.ignore();        
        switch (ch)
        {
            case 1:
            {
                int ch1;
                do
                {
                    cout << "\n=== ���������� ���������� ===" << endl;
                    cout << "1. �������� ��������" << endl;
                    cout << "2. �������� �������������" << endl;
                    cout << "3. ������� �������������" << endl;
                    cout << "4. �������� ����������������� ����������" << endl;
                    cout << "5. �������� ����� ���������" << endl;
                    cout << "0. ����� � ������� ����" << endl;
                    cout << "�������� ��������: ";
                    cin >> ch1;
                    cin.ignore();
                    cout << endl;
                    switch (ch1)
                    {
                        case 1:
                        {
                            string studentId;
                            int year;
                            double averageGrade;
                            PersonData(firstName, lastName, age, phone);
                            cout << "������� ����� ������������� ������: ";
                            getline(cin, studentId);
                            cout << "������� ���� ��������: ";
                            cin >> year;
                            cin.ignore();
                            cout << "������� ������� ���� ��������: ";
                            cin >> averageGrade;                            
                            Student* newStudent = new Student(firstName, lastName, age, phone, studentId, year, averageGrade);
                            Academy.addPerson(newStudent);
                            cout << "\n������� ��������!" << endl;
                            break;
                        }
                        case 2:
                        {
                            string academicDegree;
                            int experience;
                            PersonData(firstName, lastName, age, phone);
                            cout << "������� ������ �������: ";
                            getline(cin, academicDegree);
                            cout << "������� ���� ������: ";
                            cin >> experience;
                            cin.ignore();                           
                            Teacher* newTeacher = new Teacher(firstName, lastName, age, phone, academicDegree, experience);
                            Academy.addPerson(newTeacher);
                            cout << "\n������������� ��������!" << endl;
                            break;
                        }
                        case 3:
                        {
                            int teachIndex;
                            int tmpIndex = 0;
                            cout << "�������������: " << endl;
                            Academy.displayAllTeachers();
                            cout << "�������� ������������� (������� ���������� �����): ";
                            cin >> teachIndex;
                            cin.ignore();
                            teachIndex--;
                            if (teachIndex < 0 || teachIndex >= Academy.getAllTeachers())
                            {
                                cout << "������ ��� ������ �������������." << endl;
                                break;
                            }
                            Teacher* selectTeacher = nullptr;
                            for (const auto& person : Academy.getAllPerson())
                            {
                                if (auto teacher = dynamic_cast<Teacher*>(person))
                                {
                                    if (tmpIndex == teachIndex)
                                    {
                                        selectTeacher = teacher;
                                        break;
                                    }
                                }
                                tmpIndex++;
                            }
                            Academy.removePerson(selectTeacher);                           
                            cout << "\n������������� ������!" << endl;
                            break;
                        }
                        case 4:
                        {
                            string post, workSchedule;
                            PersonData(firstName, lastName, age, phone);
                            cout << "������� ���������: ";
                            getline(cin, post);
                            cout << "������� ������ ������: ";
                            getline(cin, workSchedule);
                            Staff* newStaff = new Staff(firstName, lastName, age, phone, post, workSchedule);
                            Academy.addPerson(newStaff);
                            cout << "\n��������� ��������!" << endl;
                            break;
                        }
                        case 5:
                        {
                            cout << "\n-----\t ���� �������� \t-----\n\n";
                            for (const auto& person : Academy.getAllPerson())
                            {
                                person->display();
                                cout << "_____________________________________" << endl;
                            }
                            break;
                        }
                        case 0:                    
                            break;                   
                        default:                    
                            cout << "������ ������, ���������� �����." << endl;                   
                    }
                } while (ch1 != 0);
                break;
            }
            case 2:
            {
                int ch2;
                do
                {
                    cout << "\n=== ���������� ��������� ===" << endl;
                    cout << "1. �������� �������" << endl;
                    cout << "2. �������� ������������� �� �������" << endl;
                    cout << "3. ��������� ����������� ��������" << endl;
                    cout << "4. �������� ���� ������" << endl;
                    cout << "0. ����� � ������� ����" << endl;
                    cout << "�������� ��������: ";
                    cin >> ch2;
                    cin.ignore();   
                    cout << endl;
                    switch (ch2)
                    {
                        case 1:
                        {
                            string departmentName;
                            cout << "������� �������� �������: ";
                            getline(cin, departmentName);
                            Department* newDepartment = new Department(departmentName);
                            Academy.addDepartment(newDepartment);
                            cout << "\n������� ���������!" << endl;
                            break;
                        }
                        case 2:
                        {
                            int num = 1;
                            int depIndex, teachIndex;
                            int tmpIndex = 0;                           
                            if (!departmentSelection(Academy, depIndex))
                            {
                                break;
                            }                           
                            cout << "�������������: " << endl;
                            Academy.displayAllTeachers();
                            cout << "�������� ������������� (������� ���������� �����): ";                            
                            cin >> teachIndex;
                            cin.ignore();
                            teachIndex--;
                            if (teachIndex < 0 || teachIndex >= Academy.getAllTeachers())
                            {
                                cout << "������ ��� ������ �������������." << endl;
                                break;                                    
                            }
                            Teacher* selectTeacher = nullptr;                           
                            for (const auto& person : Academy.getAllPerson()) 
                            {
                                if (auto teacher = dynamic_cast<Teacher*>(person)) 
                                {
                                    if (tmpIndex == teachIndex)
                                    {
                                        selectTeacher= teacher;
                                        break;
                                    }                                        
                                }
                                tmpIndex++;
                            }                                            
                            Academy.getDepartments()[depIndex]->addTeacher(selectTeacher);
                            cout << "\n������������� �������� �� �������!" << endl;
                            break;
                        }
                        case 3:
                        {
                            int num = 1;
                            int depIndex, teachIndex;
                            if (!departmentSelection(Academy, depIndex))
                            {
                                break;
                            }
                            Department* selectDept = Academy.getDepartments()[depIndex];
                            if (selectDept->getTeachers().empty())
                            {
                                cout << "�� ������� ��� ��������������. �������� ��������������"<<endl;
                                break;
                            }
                            cout << "������������� ������� " << selectDept->getDepartmentName()<<":"<<endl;
                            const auto& teachers = selectDept->getTeachers();
                            for (size_t i = 0; i < teachers.size(); ++i) 
                            {
                                cout << i + 1 << ". " << teachers[i]->getFirstName()<< " " << teachers[i]->getLastName() << endl;
                            }
                            cout << "�������� ����������� �������� (������� ���������� �����): ";
                            cin >> teachIndex;
                            cin.ignore();
                            teachIndex--;
                            if (teachIndex < 0 || teachIndex >= selectDept->getTeachers().size());
                            {
                                cout << "������ ������ �������������"<<endl;
                                break;
                            }
                            selectDept->setHeadDepartment(teachers[teachIndex]);
                            cout << "���������� �������� ��������" << endl;
                            break;
                        }
                        case 4:
                        {
                            int num = 1;
                            cout << "\n---\t��� �������\t---\n";
                            if (Academy.getDepartments().empty())
                            {
                                cout << "� ������� ���������� ��� ��������� ������, �������� �������." << endl;
                                break;
                            }                           
                            for (const auto& dep : Academy.getDepartments())
                            {
                                cout << num++ << ". " << dep->getDepartmentName()<< endl;
                                dep->display();
                                cout << "-------------------------------------------------" << endl;
                            }
                        }
                        case 0:
                            break;
                        default:                        
                            cout << "������ ������, ���������� �����." << endl;
                    }
                } while (ch2!=0);
            }
            case 3:
            {
                int ch3;
                do
                {
                    cout << "\n=== ���������� ������� ===" << endl;
                    cout << "1. �������� ����" << endl;
                    cout << "2. ������� ����" << endl;
                    cout << "3. ��������� ������������� �� ����" << endl;                    
                    cout << "4. �������� �������� �� ����" << endl;
                    cout << "5. ������� �������� � �����" << endl;
                    cout << "6. ������� ���� �� �����" << endl;
                    cout << "7. �������� ���� ������" << endl;
                    cout << "0. ����� � ������� ����" << endl;
                    cout << "������� ��� �����: ";
                    cin >> ch3;
                    cin.ignore(); 
                    cout << endl;
                    switch (ch3)
                    {
                        case 1:
                        {
                            string courseName, code;
                            int depIndex;
                            if (!departmentSelection(Academy, depIndex))
                            {
                                break;
                            }
                            cout << "������� �������� �����: ";
                            getline(cin, courseName);
                            cout << "������� ��� �����: ";
                            getline(cin, code);
                            Course* newCourse = new Course(courseName, code);                           
                            Academy.getDepartments()[depIndex]->addCourse(newCourse);
                            cout << "���� ��������." << endl;
                            break;
                        }
                        case 2:
                        {
                            int depIndex, courseIndex, teachIndex;
                            int tmpIndex = 0;
                            int num = 1;
                            if (!departmentSelection(Academy, depIndex))
                            {
                                break;
                            }
                            Department* selectDept = Academy.getDepartments()[depIndex];
                            if (!courseSelection(selectDept, courseIndex))
                            {
                                break;
                            }
                            Academy.getDepartments()[depIndex]->removeCourse(selectDept->getCourses()[courseIndex]);
                            cout << "���� ������" << endl;                           
                            break;   
                        }
                        case 3:
                        {
                            int depIndex, courseIndex, teachIndex;
                            int num = 1;
                            if (!departmentSelection(Academy, depIndex))
                            {
                                break;
                            }
                            Department* selectDept = Academy.getDepartments()[depIndex];
                            if (!courseSelection(selectDept, courseIndex))
                            {
                                break;
                            }
                            Course* selectCourse = selectDept->getCourses()[courseIndex];                            
                            cout << "������������� ������� " << selectDept->getDepartmentName() << ":" << endl;
                            const auto& teachers = selectDept->getTeachers();
                            for (size_t i = 0; i < teachers.size(); ++i)
                            {
                                cout << i + 1 << ". " << teachers[i]->getFirstName() << " " << teachers[i]->getLastName() << endl;
                            }
                            cout << "�������� ������������� (������� ���������� �����):";
                            cin >> teachIndex;
                            cin.ignore();
                            teachIndex--;
                            if (teachIndex < 0 || teachIndex >= selectDept->getTeachers().size())
                            {
                                cout << "������ ��� ������ �������������." << endl;
                                break;
                            }
                            selectCourse->setTeacher(selectDept->getTeachers()[teachIndex]);
                            cout << "������������� �������� �� ����" << endl;
                            break;
                        }
                        case 4:
                        {
                            int depIndex, courseIndex, studIndex;
                            int num=1;
                            int count = 0;
                            int tmpIndex = 0;
                            if (!departmentSelection(Academy, depIndex))
                            {
                                break;
                            }
                            Department* selectDept = Academy.getDepartments()[depIndex];
                            if (!courseSelection(selectDept, courseIndex))
                            {
                                break;
                            }
                            Course* selectCourse = selectDept->getCourses()[courseIndex];
                            cout << "��� ��������: " << endl;
                            for (const auto& person : Academy.getAllPerson())
                            {
                                Student* student = dynamic_cast<Student*>(person);
                                if (student)
                                {
                                    cout << count + 1 << ". " << student->getFirstName() << " " << student->getLastName() << " (������������ ����� � " << student->getStudentId() << ")" << endl;
                                    count++;
                                }
                            }
                            if (count == 0)
                            {
                                cout << "��� ��������� � ����������. ���������� ��������";
                                break;
                            }
                            cout << "�������� �������� (������� ���������� �����):";
                            cin >> studIndex;
                            cin.ignore();
                            studIndex--;
                            Student* selectStudent = nullptr;
                            for (const auto& person : Academy.getAllPerson())
                            {
                                if (auto student = dynamic_cast<Student*>(person))
                                {
                                    if (tmpIndex == studIndex)
                                    {
                                        selectStudent = student;
                                        break;
                                    }
                                }
                                tmpIndex++;
                            }
                            if (selectStudent)
                            {
                                selectCourse->addStudent(selectStudent);
                                cout<<"������� �������� �� ����"<<endl;
                            }
                            else
                            {
                                cout << "������ ������ ��������"<<endl;
                            }
                            break;
                        }
                        case 5:
                        {
                            int depIndex, courceIndex, studIndex;
                            int num = 1;
                            int count = 0;
                            int tmpIndex = 0;
                            if (!departmentSelection(Academy, depIndex))
                            {
                                break;
                            }
                            Department* selectDept = Academy.getDepartments()[depIndex];
                            if (selectDept->getCourses().empty())
                            {
                                cout << "�� ���� ������� ��� ������. �������� ����." << endl;
                                break;
                            }
                            cout << "����� ������� " << selectDept->getDepartmentName() << ": " << endl;

                            for (const auto& course : selectDept->getCourses())
                            {
                                cout << num++ << ". " << course->getCourseName() << " (��� " << course->getCode() << ")" << endl;
                            }
                            cout << "�������� ���� (������� ���������� �����): ";
                            cin >> courceIndex;
                            cin.ignore();
                            courceIndex--;
                            if (courceIndex < 0 || courceIndex >= selectDept->getCourses().size())
                            {
                                cout << "������ ��� ������ �����." << endl;
                                break;
                            }
                            Course* selectCourse = selectDept->getCourses()[courceIndex];

                            cout << "��� ��������: " << endl;
                            for (const auto& person : Academy.getAllPerson())
                            {
                                Student* student = dynamic_cast<Student*>(person);
                                if (student)
                                {
                                    cout << count + 1 << ". " << student->getFirstName() << " " << student->getLastName() << " (������������ ����� � " << student->getStudentId() << ")" << endl;
                                    count++;
                                }
                            }
                            if (count == 0)
                            {
                                cout << "��� ��������� � ����������. ���������� ��������";
                                break;
                            }
                            cout << "�������� �������� (������� ���������� �����):";
                            cin >> studIndex;
                            cin.ignore();
                            studIndex--;

                            Student* selectStudent = nullptr;
                            for (const auto& person : Academy.getAllPerson())
                            {
                                if (auto student = dynamic_cast<Student*>(person))
                                {
                                    if (tmpIndex == studIndex)
                                    {
                                        selectStudent = student;
                                        break;
                                    }
                                }
                                tmpIndex++;
                            }
                            if (selectStudent)
                            {
                                selectCourse->removeStudent(selectStudent);
                                cout << "������� ������ � �����" << endl;
                            }
                            else
                            {
                                cout << "������ ������ ��������" << endl;
                            }
                            break;
                        }
                        case 6:
                        {
                            int depIndex, courseIndex;
                            int num = 1;
                            if (!departmentSelection(Academy, depIndex))
                            {
                                break;
                            }
                            Department* selectDept = Academy.getDepartments()[depIndex];                            
                            if (!courseSelection(selectDept, courseIndex))
                            {
                                break;
                            }
                            Course* selectCourse = selectDept->getCourses()[courseIndex];
                            cout<<"������� ���� �� ����� ����������: "<<selectCourse->calculateAverageGrade()<<endl;
                            break;
                        }
                        case 7:
                        {
                            cout << "\n---\t��� �����\t---\n";
                            for (const auto& dep : Academy.getDepartments())
                            {
                                cout << "�������: " << dep->getDepartmentName() << endl;
                                for (const auto& course : dep->getCourses())
                                {
                                    course->display();
                                    cout << "----------------------------------------------------" << endl;
                                }
                            }
                            break;
                        }
                        case 0:
                            break;
                        default:
                            cout << "������ ������, ���������� �����." << endl;
                    }
                } while (ch3!=0);
            }
            case 4:
                Academy.displayStatistics();
                break;
            case 0:
                cout << "���������� ������..." << endl;
                break;
            default:
                cout << "������ ������..." << endl;
        }    
    } while (ch!=0);
    return 0;
}
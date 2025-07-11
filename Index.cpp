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
class Staff;      //���������������� ��������, ����������� ����� �� Person
class Course;              // ����� ����
class Department;                //����� �������
class EducationalInstitution;   //����� �������� ����������


int main()
{
    setlocale(LC_ALL, "RU");

        //������� ����������
    EducationalInstitution Academy("���");        

        //�������
    Teacher teacher1("�����", "�������", 35, "+79233330101", "���", 15);
    Teacher teacher2("����", "�������", 42, "+79234540202", "���", 18);
    Teacher teacher3("����������", "������", 51, "+79293977305", "������", 30);

    teacher1.addCourse("C++");
    teacher2.addCourse("C#");
    teacher2.addCourse("Java");


        //��������
    Student student1("����", "��������", 20, "23-45-54", "��-001", 1, 4.5);
    Student student2("�������", "�������", 21, "22-55-44", "��-002", 1, 4.0);
    Student student3("������", "ĸ���", 18, "12-78-67", "��-003", 1, 4.9);
    Student student4("�����", "���������", 19, "48-98-11", "��-004", 2, 3.8);

        //�������������
    Staff rector("��������", "������", 58, "69-69-69", "������", "��-��");
    Staff buhg("�������", "������", 49, "22-69-73", "���������", "��-��");

    Academy.addStaff(&rector);      //���������� ���������������� ����������� � ����������
    Academy.addStaff(&buhg);

        //�������
    Department programming("����������������");

    Academy.addDepartment(&programming);        //���������� ������� � ����������

    programming.setHeadDepartment(&teacher1);   //���������� ����������� ��������
    programming.addTeacher(&teacher2);          //���������� �������� �� �������
    programming.addTeacher(&teacher3);
    programming.addTeacher(&teacher1);

    Course Cplus("C++", "���411");     // �������� ������
    Course Java("Java", "���522");


    programming.addCourse(&Cplus);      //���������� ������ �� �������
    programming.addCourse(&Java);

    Cplus.addStudent(&student1);        //��������� ��������� �� ���� � �������������
    Cplus.addStudent(&student2);
    Cplus.addStudent(&student3);
    Cplus.setTeacher(&teacher2);

    Java.addStudent(&student4);
    Java.setTeacher(&teacher1);


  //  teacher2.display();

   

   // student1.display();
    Academy.displayStatistics();

    programming.display();




	return 0;
}
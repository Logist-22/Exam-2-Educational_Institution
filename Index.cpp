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

class Person;           //Базовый класс
class Student;          //класс студент, производный класс от Person
class Teacher;         //класс учитель, производный класс от Person
class Staff;      //административный персонал, производный класс от Person
class Course;              // класс курс
class Department;                //класс кафедры
class EducationalInstitution;   //класс базового учреждения


int main()
{
    setlocale(LC_ALL, "RU");

        //базовое учреждение
    EducationalInstitution Academy("ТОП");        

        //учителя
    Teacher teacher1("Мария", "Иванова", 35, "+79233330101", "КТН", 15);
    Teacher teacher2("Иван", "Сергеев", 42, "+79234540202", "КТН", 18);
    Teacher teacher3("Константин", "Петров", 51, "+79293977305", "Доктор", 30);

    teacher1.addCourse("C++");
    teacher2.addCourse("C#");
    teacher2.addCourse("Java");


        //студенты
    Student student1("Петр", "Смоляков", 20, "23-45-54", "СБ-001", 1, 4.5);
    Student student2("Алексей", "Сидоров", 21, "22-55-44", "СБ-002", 1, 4.0);
    Student student3("Сергей", "Дёмин", 18, "12-78-67", "СБ-003", 1, 4.9);
    Student student4("Алина", "Степанова", 19, "48-98-11", "СБ-004", 2, 3.8);

        //Администрация
    Staff rector("Владимир", "Гуняев", 58, "69-69-69", "Ректор", "Пн-Пт");
    Staff buhg("Татьяна", "Жилина", 49, "22-69-73", "Бухгалтер", "Пн-Пт");

    Academy.addStaff(&rector);      //Добавление административных сотрудников в учреждение
    Academy.addStaff(&buhg);

        //кафедра
    Department programming("Программирование");

    Academy.addDepartment(&programming);        //добавление кафедры в учреждение

    programming.setHeadDepartment(&teacher1);   //назначение заведующего кафедрой
    programming.addTeacher(&teacher2);          //добавление учителей на кафедру
    programming.addTeacher(&teacher3);
    programming.addTeacher(&teacher1);

    Course Cplus("C++", "СПД411");     // создание курсов
    Course Java("Java", "СПД522");


    programming.addCourse(&Cplus);      //добавление курсов на кафедру
    programming.addCourse(&Java);

    Cplus.addStudent(&student1);        //добавляем студентов на курс и преподавателя
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
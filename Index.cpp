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
class Staff;            // класс административного персонала, производный класс от Person
class Course;              // класс курс
class Department;                //класс кафедры
class EducationalInstitution;   //класс базового учреждения


void PersonData(string& firstName, string& lastName, int& age, string& phone)
{
    cout << "Введите имя: ";
    getline(cin, firstName);
    cout << "Введите фамилию: ";
    getline(cin, lastName);
    cout << "Введите возраст: ";
    cin >> age;
    cin.ignore();
    cout << "Введите номер телефона: ";
    getline(cin, phone);
}


bool departmentSelection(EducationalInstitution& EducationalInstitution, int& depIndex)
{
    if (EducationalInstitution.getDepartments().empty())
    {
        cout << "В учебном учреждении нет доступных кафедр, создайте кафедру." << endl;
        return false;
    }
    int num = 1;
    cout << "Список кафедр: " << endl;
    for (const auto& dep : EducationalInstitution.getDepartments())
    {
        cout << num++ << ". " << dep->getDepartmentName() << endl;
    }
    cout << "Выберите порядковый номер кафедры: ";
    cin >> depIndex;
    cin.ignore();
    depIndex--;
    if (depIndex < 0 || depIndex >= EducationalInstitution.getDepartments().size())
    {
        cout << "Ошибка при выборе кафедры." << endl;
        return false;
    }
    return true;
}


bool courseSelection(Department* department, int& courseIndex)
{
    if (department->getCourses().empty())
    {
        cout << "На этой кафедре нет курсов. Добавьте крус." << endl;
        return false;
    }
    int num = 1;
    cout << "Курсы кафедры " << department->getDepartmentName() << ": " << endl;
    for (const auto& course : department->getCourses())
    {
        cout << num++ << ". " << course->getCourseName() << " (код " << course->getCode() << ")" << endl;
    }
    cout << "Выберите курс (укажите порядковый номер): ";
    cin >> courseIndex;
    cin.ignore();
    courseIndex--;
    if (courseIndex < 0 || courseIndex >= department->getCourses().size())
    {
        cout << "Ошибка при выборе курса." << endl;
        return false;
    }
    return true;
}


int main()
{
    setlocale(LC_ALL, "RU");
    string firstName, lastName, phone;
    int age;

    //базовое учреждение
    EducationalInstitution Academy("ТОП");

    Department programming("Программирование");

    Academy.addDepartment(&programming);        //добавление кафедры в учреждение

    //учителя
     Teacher teacher1("Мария", "Иванова", 35, "+79233330101", "КТН", 15);
     Teacher teacher2("Иван", "Сергеев", 42, "+79234540202", "КТН", 18);
     Teacher teacher3("Константин", "Петров", 51, "+79293977305", "Доктор", 30);

     Academy.addPerson(&teacher1);
     Academy.addPerson(&teacher2);
     Academy.addPerson(&teacher3);

    
 //студенты   

    Student student1("Петр", "Смоляков", 20, "23-45-54","СБ-001", 1, 4.5);
    Student student2("Алексей", "Сидоров", 21, "22-55-44", "СБ-002", 1, 4.0);
    Student student3("Сергей", "Дёмин", 18, "12-78-67", "СБ-003", 1, 4.9);

    Academy.addPerson(&student1);
    Academy.addPerson(&student2);
    Academy.addPerson(&student3);

       //Администрация
    Staff rector("Владимир", "Гуняев", 58, "69-69-69", "Ректор", "Пн-Пт");
    Staff buhg("Татьяна", "Жилина", 49, "22-69-73", "Бухгалтер", "Пн-Пт");

    Academy.addPerson(&rector);      //Добавление административных сотрудников в учреждение
    Academy.addPerson(&buhg);

       //кафедра   

    programming.setHeadDepartment(&teacher1);   //назначение заведующего кафедрой
    programming.addTeacher(&teacher2);          //добавление учителей на кафедру
    programming.addTeacher(&teacher3);
    programming.addTeacher(&teacher1);

    Course Cplus("C++", "СПД411");     // создание курсов
  
    programming.addCourse(&Cplus);      //добавление курсов на кафедру
   
    Cplus.addStudent(&student1);        //добавляем студентов на курс и преподавателя
    Cplus.addStudent(&student2);
    Cplus.addStudent(&student3);
    Cplus.setTeacher(&teacher2);
    

    int ch;
    do
    {
        cout << "\n=== Система управления университетом ===" << endl;
        cout << "1. Управление персоналом" << endl;
        cout << "2. Управление кафедрами" << endl;
        cout << "3. Управление курсами" << endl;
        cout << "4. Просмотр статистики" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> ch;
        cin.ignore();        
        switch (ch)
        {
            case 1:
            {
                int ch1;
                do
                {
                    cout << "\n=== Управление персоналом ===" << endl;
                    cout << "1. Добавить студента" << endl;
                    cout << "2. Добавить преподавателя" << endl;
                    cout << "3. Удалить преподавателя" << endl;
                    cout << "4. Добавить административного сотрудника" << endl;
                    cout << "5. Просмотр всего персонала" << endl;
                    cout << "0. Назад в главное меню" << endl;
                    cout << "Выберите действие: ";
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
                            cout << "Введите номер студенческого билета: ";
                            getline(cin, studentId);
                            cout << "Введите курс студента: ";
                            cin >> year;
                            cin.ignore();
                            cout << "Введите средний балл студента: ";
                            cin >> averageGrade;                            
                            Student* newStudent = new Student(firstName, lastName, age, phone, studentId, year, averageGrade);
                            Academy.addPerson(newStudent);
                            cout << "\nСтудент добавлен!" << endl;
                            break;
                        }
                        case 2:
                        {
                            string academicDegree;
                            int experience;
                            PersonData(firstName, lastName, age, phone);
                            cout << "Введите ученую степень: ";
                            getline(cin, academicDegree);
                            cout << "Введите стаж работы: ";
                            cin >> experience;
                            cin.ignore();                           
                            Teacher* newTeacher = new Teacher(firstName, lastName, age, phone, academicDegree, experience);
                            Academy.addPerson(newTeacher);
                            cout << "\nПреподаватель добавлен!" << endl;
                            break;
                        }
                        case 3:
                        {
                            int teachIndex;
                            int tmpIndex = 0;
                            cout << "Преподаватели: " << endl;
                            Academy.displayAllTeachers();
                            cout << "Выберите преподавателя (укажите порядковый номер): ";
                            cin >> teachIndex;
                            cin.ignore();
                            teachIndex--;
                            if (teachIndex < 0 || teachIndex >= Academy.getAllTeachers())
                            {
                                cout << "Ошибка при выборе преподавателя." << endl;
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
                            cout << "\nПреподаватель удален!" << endl;
                            break;
                        }
                        case 4:
                        {
                            string post, workSchedule;
                            PersonData(firstName, lastName, age, phone);
                            cout << "Введите должность: ";
                            getline(cin, post);
                            cout << "Введите график работы: ";
                            getline(cin, workSchedule);
                            Staff* newStaff = new Staff(firstName, lastName, age, phone, post, workSchedule);
                            Academy.addPerson(newStaff);
                            cout << "\nСотрудник добавлен!" << endl;
                            break;
                        }
                        case 5:
                        {
                            cout << "\n-----\t Весь персонал \t-----\n\n";
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
                            cout << "Ошибка выбора, попробуйте снова." << endl;                   
                    }
                } while (ch1 != 0);
                break;
            }
            case 2:
            {
                int ch2;
                do
                {
                    cout << "\n=== Управление кафедрами ===" << endl;
                    cout << "1. Добавить кафедру" << endl;
                    cout << "2. Добавить преподавателя на кафедру" << endl;
                    cout << "3. Назначить заведующего кафедрой" << endl;
                    cout << "4. Просмотр всех кафедр" << endl;
                    cout << "0. Назад в главное меню" << endl;
                    cout << "Выберите действие: ";
                    cin >> ch2;
                    cin.ignore();   
                    cout << endl;
                    switch (ch2)
                    {
                        case 1:
                        {
                            string departmentName;
                            cout << "Введите название кафедры: ";
                            getline(cin, departmentName);
                            Department* newDepartment = new Department(departmentName);
                            Academy.addDepartment(newDepartment);
                            cout << "\nКафедра добавлена!" << endl;
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
                            cout << "Преподаватели: " << endl;
                            Academy.displayAllTeachers();
                            cout << "Выберите преподавателя (укажите порядковый номер): ";                            
                            cin >> teachIndex;
                            cin.ignore();
                            teachIndex--;
                            if (teachIndex < 0 || teachIndex >= Academy.getAllTeachers())
                            {
                                cout << "Ошибка при выборе преподавателя." << endl;
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
                            cout << "\nПреподаватель добавлен на кафедру!" << endl;
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
                                cout << "На кафедре нет преподавателей. Добавьте преподавателей"<<endl;
                                break;
                            }
                            cout << "Преподаватели кафедры " << selectDept->getDepartmentName()<<":"<<endl;
                            const auto& teachers = selectDept->getTeachers();
                            for (size_t i = 0; i < teachers.size(); ++i) 
                            {
                                cout << i + 1 << ". " << teachers[i]->getFirstName()<< " " << teachers[i]->getLastName() << endl;
                            }
                            cout << "Выберите заведующего кафедрой (укажите порядковый номер): ";
                            cin >> teachIndex;
                            cin.ignore();
                            teachIndex--;
                            if (teachIndex < 0 || teachIndex >= selectDept->getTeachers().size());
                            {
                                cout << "Ошибка выбора преподавателя"<<endl;
                                break;
                            }
                            selectDept->setHeadDepartment(teachers[teachIndex]);
                            cout << "Заведующий кафедрой назначен" << endl;
                            break;
                        }
                        case 4:
                        {
                            int num = 1;
                            cout << "\n---\tВсе кафедры\t---\n";
                            if (Academy.getDepartments().empty())
                            {
                                cout << "В учебном учреждении нет доступных кафедр, создайте кафедру." << endl;
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
                            cout << "Ошибка выбора, попробуйте снова." << endl;
                    }
                } while (ch2!=0);
            }
            case 3:
            {
                int ch3;
                do
                {
                    cout << "\n=== Управление курсами ===" << endl;
                    cout << "1. Добавить курс" << endl;
                    cout << "2. Удалить курс" << endl;
                    cout << "3. Назначить преподавателя на курс" << endl;                    
                    cout << "4. Добавить студента на курс" << endl;
                    cout << "5. Удалить студента с курса" << endl;
                    cout << "6. Средний балл по курсу" << endl;
                    cout << "7. Просмотр всех курсов" << endl;
                    cout << "0. Назад в главное меню" << endl;
                    cout << "Введите ваш выбор: ";
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
                            cout << "Введите название курса: ";
                            getline(cin, courseName);
                            cout << "Введите код курса: ";
                            getline(cin, code);
                            Course* newCourse = new Course(courseName, code);                           
                            Academy.getDepartments()[depIndex]->addCourse(newCourse);
                            cout << "Курс добавлен." << endl;
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
                            cout << "Курс удален" << endl;                           
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
                            cout << "Преподаватели кафедры " << selectDept->getDepartmentName() << ":" << endl;
                            const auto& teachers = selectDept->getTeachers();
                            for (size_t i = 0; i < teachers.size(); ++i)
                            {
                                cout << i + 1 << ". " << teachers[i]->getFirstName() << " " << teachers[i]->getLastName() << endl;
                            }
                            cout << "Выберите преподавателя (укажите порядковый номер):";
                            cin >> teachIndex;
                            cin.ignore();
                            teachIndex--;
                            if (teachIndex < 0 || teachIndex >= selectDept->getTeachers().size())
                            {
                                cout << "Ошибка при выборе преподавателя." << endl;
                                break;
                            }
                            selectCourse->setTeacher(selectDept->getTeachers()[teachIndex]);
                            cout << "Преподаватель назначен на курс" << endl;
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
                            cout << "Все студенты: " << endl;
                            for (const auto& person : Academy.getAllPerson())
                            {
                                Student* student = dynamic_cast<Student*>(person);
                                if (student)
                                {
                                    cout << count + 1 << ". " << student->getFirstName() << " " << student->getLastName() << " (студенческий билет № " << student->getStudentId() << ")" << endl;
                                    count++;
                                }
                            }
                            if (count == 0)
                            {
                                cout << "Нет студентов в учреждении. необходимо добавить";
                                break;
                            }
                            cout << "Выберите студента (укажите порядковый номер):";
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
                                cout<<"Студент добавлен на курс"<<endl;
                            }
                            else
                            {
                                cout << "Ошибка выбора студента"<<endl;
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
                                cout << "На этой кафедре нет курсов. Добавьте крус." << endl;
                                break;
                            }
                            cout << "Курсы кафедры " << selectDept->getDepartmentName() << ": " << endl;

                            for (const auto& course : selectDept->getCourses())
                            {
                                cout << num++ << ". " << course->getCourseName() << " (код " << course->getCode() << ")" << endl;
                            }
                            cout << "Выберите курс (укажите порядковый номер): ";
                            cin >> courceIndex;
                            cin.ignore();
                            courceIndex--;
                            if (courceIndex < 0 || courceIndex >= selectDept->getCourses().size())
                            {
                                cout << "Ошибка при выборе курса." << endl;
                                break;
                            }
                            Course* selectCourse = selectDept->getCourses()[courceIndex];

                            cout << "Все студенты: " << endl;
                            for (const auto& person : Academy.getAllPerson())
                            {
                                Student* student = dynamic_cast<Student*>(person);
                                if (student)
                                {
                                    cout << count + 1 << ". " << student->getFirstName() << " " << student->getLastName() << " (студенческий билет № " << student->getStudentId() << ")" << endl;
                                    count++;
                                }
                            }
                            if (count == 0)
                            {
                                cout << "Нет студентов в учреждении. необходимо добавить";
                                break;
                            }
                            cout << "Выберите студента (укажите порядковый номер):";
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
                                cout << "Студент удален с курса" << endl;
                            }
                            else
                            {
                                cout << "Ошибка выбора студента" << endl;
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
                            cout<<"Средний балл по курсу составляет: "<<selectCourse->calculateAverageGrade()<<endl;
                            break;
                        }
                        case 7:
                        {
                            cout << "\n---\tВсе курсы\t---\n";
                            for (const auto& dep : Academy.getDepartments())
                            {
                                cout << "Кафедра: " << dep->getDepartmentName() << endl;
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
                            cout << "Ошибка выбора, попробуйте снова." << endl;
                    }
                } while (ch3!=0);
            }
            case 4:
                Academy.displayStatistics();
                break;
            case 0:
                cout << "Завершение работы..." << endl;
                break;
            default:
                cout << "Ошибка выбора..." << endl;
        }    
    } while (ch!=0);
    return 0;
}
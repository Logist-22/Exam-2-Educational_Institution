#include "Person.h"


Person::Person() : firstName(""), lastName(""), age(0), phone("") {}
Person::Person(const string& firstName, const string& lastName, int age, const string& phone) : firstName(firstName), lastName(lastName), age(age), phone(phone) {}

string Person::getFirstName() const
{
    return firstName; 
}

string Person::getLastName() const
{
    return lastName; 
}

int Person::getAge() const
{
    return age; 
}

string Person::getPhone() const
{
    return phone; 
}

void Person::setFirstName(const string& firstName)
{
    this->firstName = firstName; 
}

void Person::setLastName(const string& lastName)
{
    this->lastName = lastName; 
}

void Person::setAge(int age)
{
    this->age = age;
}

void Person::setPhone(const string& phone)
{
    this->phone = phone; 
}

void Person::display() const       // Виртуальный метод display() для вывода информации
{
    cout << "Фамилия, Имя: " << lastName << " " << firstName << endl;
    cout << "Возраст: " << age << endl;
    cout << "Телефон: " << phone << endl;
}
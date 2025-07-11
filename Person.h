#pragma once
#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Person
{
protected:
    string firstName;
    string lastName;
    int age;
    string phone;

public:
    Person();
    Person(const string& firstName, const string& lastName, int age, const string& phone);
    virtual ~Person() {};

    string getFirstName() const;
    string getLastName() const;
    int getAge() const;
    string getPhone() const;
   
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    void setAge(int age);
    void setPhone(const string& phone);

    virtual void display() const;       // Виртуальный метод display() для вывода информации
};


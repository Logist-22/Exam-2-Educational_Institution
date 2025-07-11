#pragma once
#include "Person.h"
#include "Student.h"
#include "Teacher.h"


class Staff : public Person
{
private:
    string post;            // ���������
    string workSchedule;    // ������ ������

public:
    Staff();
    Staff(const string& firstName, const string& lastName, int age, const string& p, const string& post, const string& workSchedule);
    ~Staff() override {};
   
    string getPost() const;
    string getWorkSchedule() const;

    void setPost(const string& post);
    void setWorkSchedule(const string& workSchedule);

    void display() const override;
};


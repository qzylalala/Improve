#include <iostream>
#include <stdlib.h>
#include "student.h"

Student::Student()
{
    age = 18;
    name = "??";
    score = 0;
}

Student::Student(const std::string &name1, int age1, int score1)
{
    name = name1;
    score = score1;
    age = age1;
}

void Student::showInfo() const
{
    std::cout << name << "  " << age << "  " << score << std::endl;
}

const Student &Student::compare(const Student &s) const
{
    if (s.score >= score)
        return s;
    else
    {
        return *this;
    }
}

int main()
{
    Student s[4] =
        {
            Student("qzy", 18, 100),
            Student("xy", 18, 100),
            Student("lhj", 18, 100),
            Student("sky", 18, 100)
        };
    s[0].showInfo();
    Student temp = s[1].compare(s[0]);
    std::cout << "the higher score:" << std::endl;
    temp.showInfo();
    
    system("pause");
    return 0;
}

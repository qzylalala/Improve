#ifndef STUDENT_H_
#define STUDENT_H_
#include<string>

class Student
{
    private:
        int age;
        int score;
        std::string name;
    
    public:
        Student();
        Student(const std::string & name1, int age1, int score1);
        void showInfo() const; //这个函数会承诺不会改变任何的值,在相应的函数定义和声明的后面直接加上const
        const Student & compare(const Student & s) const; // 可以返回类成员的引用，但最好是const。这条原则可以参照Effective C++[1]的Item 30。
};
#endif

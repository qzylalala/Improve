#ifndef _TIME_H_
#define _TIME_H_

class Time{

private:
    int hour;
    int minute;
    int seconds;

public:
    Time(); // 如果自己定义了构造函数，则必须要有默认构造函数
    Time(int hour1, int minute1, int second1);
    void show() const;
    Time operator +(Time &t);
    Time add(Time &t);
};
#endif
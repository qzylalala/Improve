#include <iostream>
#include <stdlib.h>
#include "time.h"

Time::Time()
{
    hour = 0;
    minute = 0;
    seconds = 0;
}


Time::Time(int hour1, int minute1, int second1)
{
    hour = hour1;
    minute = minute1;
    seconds = second1;
}


void Time::show() const
{
    std::cout << hour << ":" << minute << ":" << seconds << std::endl;
}

Time Time::operator +(Time &t)
{
    Time sum = *this;
    sum.seconds += t.seconds;
    sum.minute += t.minute + sum.seconds / 60;
    sum.hour += t.hour + sum.minute / 60;
    sum.minute %= 60;
    sum.seconds %= 60;
    return sum;
}

int main()
{
    Time t1(1, 22, 40);
    Time t2(2, 23, 50);
    Time total;
    t1.show();
    t2.show();
    total = t1.operator +(t2);
    total.show();
    total = t1 + t2;
    total.show();
    
    system("pause");
    return 0;
}
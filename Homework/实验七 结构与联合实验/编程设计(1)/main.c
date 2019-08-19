#include<stdio.h>
struct bits{
    unsigned int bit0:1,bit1:1, bit2:1, bit3:1, bit4:1, bit5:1, bit6:1, bit7:1;
};
union w{
    unsigned char x;
    struct bits a;
}m;
void f0(struct bits b)
{
    printf("the function 1 is called! %d\n",b.bit0);
}
void f1(struct bits b)
{
    printf("the function 2 is called! %d\n",b.bit1);
}
void f2(struct bits b)
{
    printf("the function 3 is called! %d\n",b.bit2);
}
void f3(struct bits b)
{
    printf("the function 4 is called! %d\n",b.bit3);
}
void f4(struct bits b)
{
    printf("the function 5 is called! %d\n",b.bit4);
}
void f5(struct bits b)
{
    printf("the function 6 is called! %d\n",b.bit5);
}
void f6(struct bits b)
{
    printf("the function 7 is called! %d\n",b.bit6);
}
void f7(struct bits b)
{
    printf("the function 8 is called! %d\n",b.bit7);
}
int main()
{
    void (*p_fun[8])(struct bits b);
    unsigned char n;
    printf("Pleas enter a char:");
    scanf("%c",&n);
    m.x=n;//将其存进联合中
    p_fun[0]=f0;//分别使函数指针指向不同字段
    p_fun[1]=f1;
    p_fun[2]=f2;
    p_fun[3]=f3;
    p_fun[4]=f4;
    p_fun[5]=f5;
    p_fun[6]=f6;
    p_fun[7]=f7;
    if(m.a.bit0)
        p_fun[0](m.a);
    if(m.a.bit1)
        p_fun[1](m.a);
    if(m.a.bit2)
        p_fun[2](m.a);
    if(m.a.bit3)
        p_fun[3](m.a);
    if(m.a.bit4)
        p_fun[4](m.a);
    if(m.a.bit5)
        p_fun[5](m.a);
    if(m.a.bit6)
        p_fun[6](m.a);
    if(m.a.bit7)
        p_fun[7](m.a);
    printf("\nPress any key to quit...");
    getchar();
    return 0;
}

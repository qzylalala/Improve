#ifndef __ZYRANDOM__
#define __ZYRANDOM__

#ifndef __ZYLIB__
#include "zylib.h"
#endif



/*****************************************************************************/
/*  随机数功能  */
/*****************************************************************************/

/* 
    函数名称：Randomize
    函数功能：初始化伪随机数发生器
    参    数：无
    返 回 值：无
    使用说明：在每次程序执行前，调用此函数初始化伪随机数库。注意，此函数只应执行一次
*/
void Randomize();

/* 
    函数名称：GenerateRandomNumber
    函数功能：随机生成介于low和high之间（闭区间）的整数
    参    数：low和high分别表示区间下界和上界；确保low不大于high，否则程序终止执行
    返 回 值：伪随机数
*/
int GenerateRandomNumber(int low, int high);

/* 
    函数名称：GenerateRandomReal
    函数功能：随机生成介于low和high之间（闭区间）的浮点数
    参    数：low和high分别表示区间下界和上界；确保low不大于high，否则程序终止执行
    返 回 值：伪随机数
*/
double GenerateRandomReal(double low, double high);


#endif

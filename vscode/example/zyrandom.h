#ifndef __ZYRANDOM__
#define __ZYRANDOM__

#ifndef __ZYLIB__
#include "zylib.h"
#endif



/*****************************************************************************/
/*  ���������  */
/*****************************************************************************/

/* 
    �������ƣ�Randomize
    �������ܣ���ʼ��α�����������
    ��    ������
    �� �� ֵ����
    ʹ��˵������ÿ�γ���ִ��ǰ�����ô˺�����ʼ��α������⡣ע�⣬�˺���ֻӦִ��һ��
*/
void Randomize();

/* 
    �������ƣ�GenerateRandomNumber
    �������ܣ�������ɽ���low��high֮�䣨�����䣩������
    ��    ����low��high�ֱ��ʾ�����½���Ͻ磻ȷ��low������high�����������ִֹ��
    �� �� ֵ��α�����
*/
int GenerateRandomNumber(int low, int high);

/* 
    �������ƣ�GenerateRandomReal
    �������ܣ�������ɽ���low��high֮�䣨�����䣩�ĸ�����
    ��    ����low��high�ֱ��ʾ�����½���Ͻ磻ȷ��low������high�����������ִֹ��
    �� �� ֵ��α�����
*/
double GenerateRandomReal(double low, double high);


#endif

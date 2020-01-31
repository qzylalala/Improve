#ifndef __ZYLIB__
#define __ZYLIB__

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



/*****************************************************************************/
/*  �����������Ͷ���  */
/*****************************************************************************/

/*  ��������  */
typedef  enum { FALSE, TRUE }  BOOL;

/*  �����ַ�������  */
typedef  char *  STRING;
typedef  const char *  CSTRING;

/*  ������������  */
typedef  void *  ADT;
typedef  const void *  CADT;



/*****************************************************************************/
/*  ���볣������  */
/*****************************************************************************/

/*  �޶������  */
extern  CADT  undefined_object;

/*  �����±겻���ڳ���  */
extern  const unsigned int  inexistent_index;



/*****************************************************************************/
/*  ʱ�䴦��  */
/*****************************************************************************/

/*  ������STRING  TimeToString( const struct tm * t )  */
/*  ��ʱ������ת��Ϊ�ַ�����*/
/*  �ַ����ĸ�ʽΪ��YYYY-MM-DD HH:MM:SS��*/
/*  ʹ�÷�����time_t t0; struct tm* t1; STRING s; t0 = time(NULL); t1 = localtime(&t0); s = TimeToString(t1);  */
STRING  TimeToString( const struct tm * t );

/*  ������STRING  CurrentTimeToString()  */
/*  ����ǰʱ��ת��Ϊ�ַ�����*/
/*  �ַ����ĸ�ʽΪ��YYYY-MM-DD HH:MM:SS��*/
STRING  CurrentTimeToString();



/*****************************************************************************/
/*  ������  */
/*****************************************************************************/

/*  ������void  PrintErrorMessage( CSTRING fmt, ... )  */
/*  ������*/
/*  ���׼�����������������Ϣ��ʹ�÷�ʽ���Ʊ�׼�⺯��printf()��*/
/*  on��TRUE��ʾ����������У�FALSE��ʾ������ֹ��*/
void  PrintErrorMessage( BOOL on, CSTRING fmt, ... );

/*  ������void  PrintErrorMessageToFile( FILE * fp, CSTRING fmt, ... )  */
/*  ������*/
/*  ���ļ���д�������Ϣ��ʹ�÷�ʽ���Ʊ�׼�⺯��fprintf()��*/
/*  on��TRUE��ʾ����������У�FALSE��ʾ������ֹ��*/
void  PrintErrorMessageToFile( FILE * fp, BOOL on, CSTRING fmt, ... );



/*****************************************************************************/
/*  ��̬�ڴ���������  */
/*****************************************************************************/

/*  �꣺NewObject(T)  */
/*  ����Ŀ�����ݶ��󣬷���ָ������ָ�롣*/
/*  ʹ�÷�����T* p; p = NewObject(T); */
#define  NewObject(T)         (T*)malloc(sizeof(T))

/*  �꣺CreateObjects(T, n)  */
/*  �����������Ŀ�����ݶ������飩������ָ�������һ��Ԫ�ص�ָ�롣*/
/*  ʹ�÷�����T* p; int n = 10; p = CreateObjects(T, n); */
#define  CreateObjects(T, n)  (T*)malloc((n)*sizeof(T))

/*  �꣺CreateObject(T, n)  */
/*  �����������Ŀ�����ݶ��󣬷���ָ���һ��Ԫ�ص�ָ�롣�����������Ķ��Ŀ�����ݶ���������Ϊ���忼��ĳ��ϣ����紴��10���ַ�����Ŀ�����ݶ������Ǳ���Ϊ�ַ������������鴦��*/
/*  ʹ�÷�����char* p; int n = 10; p = CreateObject(char, n); */
#define  CreateObject(T, n)   (T*)malloc((n)*sizeof(T))

/*  �꣺DestroyObject(p)  */
/*  ����ָ����ָ���Ŀ�����ݶ���*/
/*  ʹ�÷�����T* p; ...; DestroyObject(p); */
#define  DestroyObject(p)     free(p), p = NULL

/*  �꣺DestroyObjects(p)  */
/*  ����ָ����ָ���Ŀ�����ݶ���*/
/*  ʹ�÷�����T* p; ...; DestroyObjects(p); */
#define  DestroyObjects(p)    free(p), p = NULL



/*****************************************************************************/
/*  �ַ�������  */
/*****************************************************************************/

/*  ������int  GetIntegerFromKeyboard() */
/*  �Ӽ��̻�ȡ������*/
int  GetIntegerFromKeyboard();

/*  ������double  GetRealFromKeyboard() */
/*  �Ӽ��̻�ȡ��������*/
double  GetRealFromKeyboard();

/*  ������STRING  GetStringFromKeyboard() */
/*  �Ӽ��̻�ȡ�ַ�����*/
/*  ʹ�÷�����STRING s; s = GetStringFromKeyboard(); ...; DestroyObject(s); */
STRING  GetStringFromKeyboard();

/*  ������STRING  GetLineFromFile(FILE* fp) */
/*  ���ļ��л�ȡһ����Ϣ����'\n'�ָ����ļ���β����*/
/*  ʹ�÷�����STRING s; FILE* fp; fp = fopen(...); s = GetLineFromFile(fp); ...; DestroyObject(s); */
STRING  GetLineFromFile( FILE * fp );

/*  ������STRING  DuplicateString( CSTRING s ) */
/*  �����ַ�����*/
STRING  DuplicateString( CSTRING s );

/*  ������STRING  ConcatenateString( CSTRING s1, CSTRING s2 ) */
/*  �ϲ������ַ����������ؽ����*/
STRING  ConcatenateString( CSTRING s1, CSTRING s2 );

/*  ������int  CompareString( CSTRING s1, CSTRING s2 ) */
/*  �ַ����Ƚϡ��������ֵ�˳��s1��s2֮ǰ�����أ�1��s1��s2��ȣ�����0�����򷵻�1��*/
int  CompareString( CSTRING s1, CSTRING s2 );

/*  ������BOOL  IsStringEqual( CSTRING s1, CSTRING s2 ) */
/*  �ж������ַ����Ƿ���ȣ���Сд���С�*/
BOOL  IsStringEqual( CSTRING s1, CSTRING s2 );

/*  ������BOOL  IsStringEqualWithoutCase( CSTRING s1, CSTRING s2 ) */
/*  �ж������ַ����Ƿ���ȣ����Դ�Сд��*/
BOOL  IsStringEqualWithoutCase( CSTRING s1, CSTRING s2 );

/*  ������unsigned int  GetStringLength( CSTRING s ) */
/*  ��ȡ�ַ����ĳ��ȡ�*/
unsigned int  GetStringLength( CSTRING s );

/*  ������char  GetIthChar( CSTRING s, unsigned int pos ) */
/*  ��ȡ�ַ����ĵ�pos���ַ���pos��0��ʼ��š�*/
/*  ʹ�÷������ַ��������ַ�ʹ��0��Ϊ������*/
char  GetIthChar( CSTRING s, unsigned int pos );

/*  ������STRING  GetSubString( CSTRING s, unsigned int pos, unsigned int length ) */
/*  ��ȡ�ַ������Ӵ����Ӵ�λ�ô�pos����ʼ��������n���ַ���*/
/*  ���pos�����ַ������ȷ�Χ0��GetStringLength(s)-1�ڣ��򷵻ؿ��ַ��������򷵻ش�posλ�ÿ�ʼ��n���ַ����������ַ������ȣ���ֻ�������ַ���β����*/
STRING  GetSubString( CSTRING s, unsigned int pos, unsigned int n );

/*  ������STRING  TransformStringIntoUpperCase( CSTRING s ) */
/*  ���ַ�����ȫ���ַ�ת��Ϊ��д��ĸ��*/
STRING  TransformStringIntoUpperCase( CSTRING s );

/*  ������STRING  TransformStringIntoLowerCase( CSTRING s ) */
/*  ���ַ�����ȫ���ַ�ת��ΪСд��ĸ��*/
STRING  TransformStringIntoLowerCase( CSTRING s );

/*  ������STRING  TransformCharIntoString( char c ) */
/*  ��һ���ַ�ת��Ϊ�ַ�����*/
STRING  TransformCharIntoString( char c );

/*  ������STRING  TransformIntegerIntoString( int n ) */
/*  ������ת��Ϊ�ַ�����*/
STRING  TransformIntegerIntoString( int n );

/*  ������int  TransformStringIntoInteger( CSTRING s ) */
/*  ���ַ���ת��Ϊ������*/
int  TransformStringIntoInteger( CSTRING s );

/*  ������STRING  TransformRealIntoString( double d ) */
/*  ��������ת��Ϊ�ַ�����*/
STRING  TransformRealIntoString( double d );

/*  ������double  TransformStringIntoReal( CSTRING s ) */
/*  ���ַ���ת��Ϊ��������*/
double  TransformStringIntoReal( CSTRING s );

/*  ������unsigned int  FindCharFirst( char key, CSTRING s ) */
/*  �����ַ���s�е�ָ���ַ�key���������һ�β��ҵ��������±ꡣ�������ڣ��򷵻�inexistent_index��*/
unsigned int  FindCharFirst( char key, CSTRING s );

/*  ������unsigned int  FindCharNext( char key, CSTRING s, int pos ) */
/*  ��ָ��λ��pos��ʼ�������ַ���s�е�ָ���ַ�key�����شӴ�λ�ÿ�ʼ�׸����ҵ��������±ꡣ�������ڣ��򷵻�inexistent_index��*/
unsigned int  FindCharNext( char key, CSTRING s, unsigned int pos );

/*  ������unsigned int  FindSubStringFirst( CSTRING key, CSTRING s ) */
/*  �����ַ���s�е�ָ���Ӵ�key���������һ�β��ҵ��������±ꡣ�������ڣ��򷵻�inexistent_index��*/
unsigned int  FindSubStringFirst( CSTRING key, CSTRING s );

/*  ������unsigned int  FindSubStringNext( CSTRING key, CSTRING s, int pos ) */
/*  ��ָ��λ��pos��ʼ�������ַ���s�е�ָ���Ӵ�key�����شӴ�λ�ÿ�ʼ�׸����ҵ��������±ꡣ�������ڣ��򷵻�inexistent_index��*/
unsigned int  FindSubStringNext( CSTRING key, CSTRING s, unsigned int pos );



#endif

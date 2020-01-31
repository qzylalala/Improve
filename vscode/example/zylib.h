#ifndef __ZYLIB__
#define __ZYLIB__

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



/*****************************************************************************/
/*  基本数据类型定义  */
/*****************************************************************************/

/*  布尔类型  */
typedef  enum { FALSE, TRUE }  BOOL;

/*  抽象字符串类型  */
typedef  char *  STRING;
typedef  const char *  CSTRING;

/*  抽象数据类型  */
typedef  void *  ADT;
typedef  const void *  CADT;



/*****************************************************************************/
/*  宏与常量定义  */
/*****************************************************************************/

/*  无定义对象  */
extern  CADT  undefined_object;

/*  索引下标不存在常量  */
extern  const unsigned int  inexistent_index;



/*****************************************************************************/
/*  时间处理  */
/*****************************************************************************/

/*  函数：STRING  TimeToString( const struct tm * t )  */
/*  将时间数据转换为字符串。*/
/*  字符串的格式为：YYYY-MM-DD HH:MM:SS。*/
/*  使用方法：time_t t0; struct tm* t1; STRING s; t0 = time(NULL); t1 = localtime(&t0); s = TimeToString(t1);  */
STRING  TimeToString( const struct tm * t );

/*  函数：STRING  CurrentTimeToString()  */
/*  将当前时间转换为字符串。*/
/*  字符串的格式为：YYYY-MM-DD HH:MM:SS。*/
STRING  CurrentTimeToString();



/*****************************************************************************/
/*  错误处理  */
/*****************************************************************************/

/*  函数：void  PrintErrorMessage( CSTRING fmt, ... )  */
/*  错误处理。*/
/*  向标准错误流中输出错误信息，使用方式类似标准库函数printf()。*/
/*  on：TRUE表示程序继续运行，FALSE表示程序终止。*/
void  PrintErrorMessage( BOOL on, CSTRING fmt, ... );

/*  函数：void  PrintErrorMessageToFile( FILE * fp, CSTRING fmt, ... )  */
/*  错误处理。*/
/*  向文件中写入错误信息，使用方式类似标准库函数fprintf()。*/
/*  on：TRUE表示程序继续运行，FALSE表示程序终止。*/
void  PrintErrorMessageToFile( FILE * fp, BOOL on, CSTRING fmt, ... );



/*****************************************************************************/
/*  动态内存分配与管理  */
/*****************************************************************************/

/*  宏：NewObject(T)  */
/*  创建目标数据对象，返回指向它的指针。*/
/*  使用方法：T* p; p = NewObject(T); */
#define  NewObject(T)         (T*)malloc(sizeof(T))

/*  宏：CreateObjects(T, n)  */
/*  创建连续多个目标数据对象（数组），返回指向数组第一个元素的指针。*/
/*  使用方法：T* p; int n = 10; p = CreateObjects(T, n); */
#define  CreateObjects(T, n)  (T*)malloc((n)*sizeof(T))

/*  宏：CreateObject(T, n)  */
/*  创建连续多个目标数据对象，返回指向第一个元素的指针。用于所创建的多个目标数据对象总是作为整体考察的场合，例如创建10个字符，但目标数据对象总是被作为字符串而不是数组处理。*/
/*  使用方法：char* p; int n = 10; p = CreateObject(char, n); */
#define  CreateObject(T, n)   (T*)malloc((n)*sizeof(T))

/*  宏：DestroyObject(p)  */
/*  销毁指针所指向的目标数据对象。*/
/*  使用方法：T* p; ...; DestroyObject(p); */
#define  DestroyObject(p)     free(p), p = NULL

/*  宏：DestroyObjects(p)  */
/*  销毁指针所指向的目标数据对象。*/
/*  使用方法：T* p; ...; DestroyObjects(p); */
#define  DestroyObjects(p)    free(p), p = NULL



/*****************************************************************************/
/*  字符串功能  */
/*****************************************************************************/

/*  函数：int  GetIntegerFromKeyboard() */
/*  从键盘获取整数。*/
int  GetIntegerFromKeyboard();

/*  函数：double  GetRealFromKeyboard() */
/*  从键盘获取浮点数。*/
double  GetRealFromKeyboard();

/*  函数：STRING  GetStringFromKeyboard() */
/*  从键盘获取字符串。*/
/*  使用方法：STRING s; s = GetStringFromKeyboard(); ...; DestroyObject(s); */
STRING  GetStringFromKeyboard();

/*  函数：STRING  GetLineFromFile(FILE* fp) */
/*  从文件中获取一行信息（以'\n'分隔或到文件结尾）。*/
/*  使用方法：STRING s; FILE* fp; fp = fopen(...); s = GetLineFromFile(fp); ...; DestroyObject(s); */
STRING  GetLineFromFile( FILE * fp );

/*  函数：STRING  DuplicateString( CSTRING s ) */
/*  拷贝字符串。*/
STRING  DuplicateString( CSTRING s );

/*  函数：STRING  ConcatenateString( CSTRING s1, CSTRING s2 ) */
/*  合并两个字符串，并返回结果。*/
STRING  ConcatenateString( CSTRING s1, CSTRING s2 );

/*  函数：int  CompareString( CSTRING s1, CSTRING s2 ) */
/*  字符串比较。若按照字典顺序，s1在s2之前，返回－1，s1与s2相等，返回0；否则返回1。*/
int  CompareString( CSTRING s1, CSTRING s2 );

/*  函数：BOOL  IsStringEqual( CSTRING s1, CSTRING s2 ) */
/*  判断两个字符串是否相等，大小写敏感。*/
BOOL  IsStringEqual( CSTRING s1, CSTRING s2 );

/*  函数：BOOL  IsStringEqualWithoutCase( CSTRING s1, CSTRING s2 ) */
/*  判断两个字符串是否相等，忽略大小写。*/
BOOL  IsStringEqualWithoutCase( CSTRING s1, CSTRING s2 );

/*  函数：unsigned int  GetStringLength( CSTRING s ) */
/*  获取字符串的长度。*/
unsigned int  GetStringLength( CSTRING s );

/*  函数：char  GetIthChar( CSTRING s, unsigned int pos ) */
/*  获取字符串的第pos个字符，pos从0开始编号。*/
/*  使用方法：字符串的首字符使用0作为参数。*/
char  GetIthChar( CSTRING s, unsigned int pos );

/*  函数：STRING  GetSubString( CSTRING s, unsigned int pos, unsigned int length ) */
/*  获取字符串的子串，子串位置从pos处开始，最多包含n个字符。*/
/*  如果pos不在字符串长度范围0～GetStringLength(s)-1内，则返回空字符串，否则返回从pos位置开始的n个字符，若超出字符串长度，则只截至到字符串尾部。*/
STRING  GetSubString( CSTRING s, unsigned int pos, unsigned int n );

/*  函数：STRING  TransformStringIntoUpperCase( CSTRING s ) */
/*  将字符串的全部字符转换为大写字母。*/
STRING  TransformStringIntoUpperCase( CSTRING s );

/*  函数：STRING  TransformStringIntoLowerCase( CSTRING s ) */
/*  将字符串的全部字符转换为小写字母。*/
STRING  TransformStringIntoLowerCase( CSTRING s );

/*  函数：STRING  TransformCharIntoString( char c ) */
/*  将一个字符转换为字符串。*/
STRING  TransformCharIntoString( char c );

/*  函数：STRING  TransformIntegerIntoString( int n ) */
/*  将整数转换为字符串。*/
STRING  TransformIntegerIntoString( int n );

/*  函数：int  TransformStringIntoInteger( CSTRING s ) */
/*  将字符串转换为整数。*/
int  TransformStringIntoInteger( CSTRING s );

/*  函数：STRING  TransformRealIntoString( double d ) */
/*  将浮点数转换为字符串。*/
STRING  TransformRealIntoString( double d );

/*  函数：double  TransformStringIntoReal( CSTRING s ) */
/*  将字符串转换为浮点数。*/
double  TransformStringIntoReal( CSTRING s );

/*  函数：unsigned int  FindCharFirst( char key, CSTRING s ) */
/*  查找字符串s中的指定字符key。返回其第一次查找到的索引下标。若不存在，则返回inexistent_index。*/
unsigned int  FindCharFirst( char key, CSTRING s );

/*  函数：unsigned int  FindCharNext( char key, CSTRING s, int pos ) */
/*  从指定位置pos开始，查找字符串s中的指定字符key。返回从此位置开始首个查找到的索引下标。若不存在，则返回inexistent_index。*/
unsigned int  FindCharNext( char key, CSTRING s, unsigned int pos );

/*  函数：unsigned int  FindSubStringFirst( CSTRING key, CSTRING s ) */
/*  查找字符串s中的指定子串key。返回其第一次查找到的索引下标。若不存在，则返回inexistent_index。*/
unsigned int  FindSubStringFirst( CSTRING key, CSTRING s );

/*  函数：unsigned int  FindSubStringNext( CSTRING key, CSTRING s, int pos ) */
/*  从指定位置pos开始，查找字符串s中的指定子串key。返回从此位置开始首个查找到的索引下标。若不存在，则返回inexistent_index。*/
unsigned int  FindSubStringNext( CSTRING key, CSTRING s, unsigned int pos );



#endif

#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#pragma warning( disable:4996 )

#ifndef __ZYLIB__
#include "zylib.h"
#endif



/*****************************************************************************/
/*  宏与常量定义  */
/*****************************************************************************/

/*extern*/  CADT  undefined_object = ( CADT )&undefined_object;

/*extern*/  const unsigned int  inexistent_index = 0xFFFFFFFF;



/*****************************************************************************/
/*  时间处理  */
/*****************************************************************************/

STRING  TimeToString( const struct tm * t )
{
  STRING  _s;
  _s = CreateObject( char, 20 );
  if( !strftime( _s, 20, "%Y-%m-%d %H:%M:%S", t ) )
  {
    DestroyObject( _s );
    return NULL;
  }
  return _s;
}

STRING  CurrentTimeToString()
{
  time_t  _t0 = time( NULL );
  struct tm *  _t1 = localtime( &_t0 );
  return TimeToString( _t1 );
}



/*****************************************************************************/
/*  错误处理  */
/*****************************************************************************/

#define  EXITCODE  (-1)

void  PrintErrorMessage( BOOL on, CSTRING fmt, ... )
{
  va_list  _args;
  if( fmt )
  {
    va_start( _args, fmt );
    fprintf( stderr, "[%s] ", CurrentTimeToString() );
    vfprintf( stderr, fmt, _args );
    fprintf( stderr, "\n" );
    va_end( _args );
  }
  if( !on )
    exit( EXITCODE );
}


void  PrintErrorMessageToFile( FILE * fp, BOOL on, CSTRING fmt, ... )
{
  va_list  _args;
  if( fp && fmt )
  {
    va_start( _args, fmt );
    fprintf( fp, "[%s] ", CurrentTimeToString() );
    vfprintf( fp, fmt, _args );
    fprintf( fp, "\n" );
    va_end( _args );
  }
  if( !on )
    exit( EXITCODE );
}



/*****************************************************************************/
/*  动态内存分配与管理  */
/*****************************************************************************/



/*****************************************************************************/
/*  字符串功能  */
/*****************************************************************************/

int  GetIntegerFromKeyboard()
{
  while( TRUE )
  {
    int  _n;
    char  _junk;
    STRING  _s = GetStringFromKeyboard();
    switch( sscanf( _s, " %d %c", &_n, &_junk ) )
    {
    case 1:
      DestroyObject( _s );
      return _n;
    case 2:
      printf( "Unexpected character '%c'.\n", _junk );
      break;
    default:
      printf( "An integer expected...\n" );
      break;
    }
    DestroyObject( _s );
    printf( "Retry: " );
  }
}

double  GetRealFromKeyboard()
{
  while( TRUE )
  {
    double  _d;
    char  _junk;
    STRING  _s = GetStringFromKeyboard();
    switch( sscanf( _s, " %lf %c", &_d, &_junk ) )
    {
    case 1:
      DestroyObject( _s );
      return _d;
    case 2:
      printf( "Unexpected character '%c'.\n", _junk );
      break;
    default:
      printf( "A real number expected...\n" );
      break;
    }
    DestroyObject( _s );
    printf( "Retry: " );
  }
}

STRING  GetStringFromKeyboard()
{
  fflush( stdin );
  return GetLineFromFile( stdin );
}

STRING  GetLineFromFile( FILE * fp )
{
  int  _n = 0, _c = 0, _size = BUFSIZ;
  STRING  _s = CreateObject( char, _size ), _t = NULL;
  while( ( _c = getc( fp ) ) != '\n' && _c != EOF )
  {
    if( _n >= _size - 1 )
    {
      _size <<= 1;
      _t = CreateObject( char, _size );
      strncpy( _t, _s, _n );
      DestroyObject( _s );
      _s = _t;
    }
    _s[_n++] = ( char )_c;
  }
  if( _n == 0 && _c == EOF )
  {
    DestroyObject( _s );
    return NULL;
  }
  _s[_n] = '\0';
  _t = CreateObject( char, _n + 1 );
  strcpy( _t, _s );
  DestroyObject( _s );
  return _t;
}

STRING  DuplicateString( CSTRING s )
{
  unsigned int  _n, _i;
  STRING  _s;
  if( !s )
    PrintErrorMessage( FALSE, "DuplicateString: Illegal string parameter.\n" );
  _n = strlen( s );
  _s = CreateObject( char, _n + 1 );
  /* while( *_s++ = *s++ ); */
  for( _i = 0; _i < _n; _i++ )
    _s[_i] = s[_i];
  _s[_n] = '\0';
  return _s;
}

STRING  ConcatenateString( CSTRING s1, CSTRING s2 )
{
  STRING  _s;
  unsigned int  _n1, _n2;
  if( !s1 || !s2 )
    PrintErrorMessage( FALSE, "ConcatenateString: Illegal string parameter(s).\n" );
  _n1 = strlen( s1 );
  _n2 = strlen( s2 );
  _s = CreateObject( char, _n1 + _n2 + 1 );
  strcpy( _s, s1 );
  strcpy( _s + _n1, s2 );
  return _s;
}

int  CompareString( CSTRING s1, CSTRING s2 )
{
  if( !s1 || !s2 )
    PrintErrorMessage( FALSE, "CompareString: Illegal string parameter(s).\n" );
  return strcmp( s1, s2 );
}

BOOL  IsStringEqual( CSTRING s1, CSTRING s2 )
{
  BOOL  _r;
  if( !s1 || !s2 )
    PrintErrorMessage( FALSE, "IsStringEqual: Illegal string parameter(s).\n" );
  _r = ( BOOL )( strcmp( s1, s2 ) == 0 );
  return _r;
}

BOOL  IsStringEqualWithoutCase( CSTRING s1, CSTRING s2 )
{
  STRING  _s1, _s2;
  BOOL  _r;
  if( !s1 || !s2 )
    PrintErrorMessage( FALSE, "IsStringEqualWithoutCase: Illegal string parameter(s).\n" );
  _s1 = TransformStringIntoUpperCase( s1 );
  _s2 = TransformStringIntoUpperCase( s2 );
  _r = ( BOOL )( strcmp( _s1, _s2 ) == 0 );
  DestroyObject( _s1 );
  DestroyObject( _s2 );
  return _r;
}

unsigned int  GetStringLength( CSTRING s )
{
  if( !s )
    PrintErrorMessage( FALSE, "GetStringLength: Illegal string parameter(s).\n" );
  return strlen( s );
}

char  GetIthChar( CSTRING s, unsigned int pos )
{
  unsigned int  _n;
  if( !s )
    PrintErrorMessage( FALSE, "GetIthChar: Illegal string parameter(s).\n" );
  _n = strlen( s );
  if( pos >= _n )
    PrintErrorMessage( FALSE, "GetIthChar: Index %d out of range.\n", pos );
  return s[pos];
}

STRING  GetSubString( CSTRING s, unsigned int pos, unsigned int n )
{
  unsigned int  _n;
  if( !s )
    PrintErrorMessage( FALSE, "GetSubString: Illegal string parameter.\n" );
  _n = strlen( s );
  if( pos >= _n )
  {
    PrintErrorMessage( FALSE, "GetSubString: Index %d out of range.\n", pos );
    return NULL;
  }
  else
  {
    unsigned int  _m = n < _n - pos ? n : _n - pos;
    STRING _s = CreateObject( char, _m + 1 );
    unsigned int  _i;
    for( _i = 0; _i < _m; _i++ )
      _s[_i] = s[pos + _i];
    _s[_m] = '\0';
    return _s;
  }
}

STRING  TransformStringIntoUpperCase( CSTRING s )
{
  unsigned int  _n, _i;
  STRING  _s;
  if( !s )
    PrintErrorMessage( FALSE, "TransformStringIntoUpperCase: Illegal string parameter.\n" );
  _n = strlen( s );
  _s = CreateObject( char, _n + 1 );
  for( _i = 0; _i < _n; _i++ )
    _s[_i] = toupper( s[_i] );
  _s[_n] = '\0';
  return _s;
}


STRING  TransformStringIntoLowerCase( CSTRING s )
{
  unsigned int  _n, _i;
  STRING  _s;
  if( !s )
    PrintErrorMessage( FALSE, "TransformStringIntoLowerCase: Illegal string parameter.\n" );
  _n = strlen( s );
  _s = CreateObject( char, _n + 1 );
  for( _i = 0; _i < _n; _i++ )
    _s[_i] = tolower( s[_i] );
  _s[_n] = '\0';
  return _s;
}

STRING  TransformCharIntoString( char c )
{
  STRING  _s = CreateObject( char, 2 );
  _s[0] = c;
  _s[1] = '\0';
  return _s;
}

STRING  TransformIntegerIntoString( int n )
{
  char  _s[BUFSIZ];
  sprintf( _s, "%d", n );
  return DuplicateString( _s );
}

int  TransformStringIntoInteger( CSTRING s )
{
  int  _n;
  char  _junk;
  if( !s )
    PrintErrorMessage( FALSE, "TransformStringIntoInteger: Illegal string parameter.\n" );
  if( sscanf( s, " %d %c", &_n, &_junk ) != 1 )
    PrintErrorMessage( FALSE, "TransformStringIntoInteger: %s is not a number.\n", s );
  return _n;
}

STRING  TransformRealIntoString( double d )
{
  char  _s[BUFSIZ];
  sprintf( _s, "%G", d );
  return DuplicateString( _s );
}

double  TransformStringIntoReal( CSTRING s )
{
  double  _d;
  char  _junk;
  if( !s )
    PrintErrorMessage( FALSE, "TransformStringIntoReal: Illegal string parameter.\n" );
  if( sscanf( s, " %lg %c", &_d, &_junk ) != 1 )
    PrintErrorMessage( FALSE, "TransformStringIntoReal: %s is not a real number.\n", s );
  return _d;
}

unsigned int  FindCharFirst( char key, CSTRING s )
{
  unsigned int  _i;
  if( !s )
    PrintErrorMessage( FALSE, "FindCharFirst: Illegal string parameter.\n" );
  for( _i = 0; s[_i] != '\0'; _i++ )
  {
    if( s[_i] == key )
      return _i;
  }
  return inexistent_index;
}

unsigned int  FindCharNext( char key, CSTRING s, unsigned int pos )
{
  unsigned int  _i;
  if( !s )
    PrintErrorMessage( FALSE, "FindCharNext: Illegal string parameter.\n" );
  if( pos >= strlen( s ) )
    return inexistent_index;
  for( _i = pos; s[_i] != '\0'; _i++ )
  {
    if( s[_i] == key )
      return _i;
  }
  return inexistent_index;
}

unsigned int  FindSubStringFirst( CSTRING key, CSTRING s )
{
  CSTRING  _s;
  if( !s || !key )
    PrintErrorMessage( FALSE, "FindSubStringFirst: Illegal string parameter.\n" );
  _s = strstr( s, key );
  if( !_s )
    return inexistent_index;
  else
    return _s - s;
}

unsigned int  FindSubStringNext( CSTRING key, CSTRING s, unsigned int pos )
{
  CSTRING  _s;
  if( !s || !key )
    PrintErrorMessage( FALSE, "FindSubStringNext: Illegal string parameter.\n" );
  if( pos >= strlen(s) )
    return inexistent_index;
  _s = strstr( s + pos, key );
  if( !_s )
    return inexistent_index;
  else
    return _s - s;
}



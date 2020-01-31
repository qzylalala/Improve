//#include <stddef.h>
//#include <stdarg.h>
//#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#include <time.h>

#ifndef __ZYRANDOM__
#include "zyrandom.h"
#endif

#ifndef __ZYLIB__
#include "zylib.h"
#endif



/*****************************************************************************/
/*  随机数功能  */
/*****************************************************************************/

void Randomize()
{
//  srand((int)time(NULL));
  const int _upper_bound = sizeof( int ) * 8;
  int _t, _n, _i;
  _t = 0;
  _n = ( int )time( NULL );
  for( _i = 0; _i < _upper_bound; _i++ ){
	_t += ( _n % 2 ) << ( _upper_bound - _i - 1 );
	_n /= 2;
  }
  srand( _t );  
}

int GenerateRandomNumber(int low, int high)
{
  double _d;
  if( low > high )
    PrintErrorMessage( FALSE, "GenerateRandomNumber: Make sure low <= high.\n" );
  _d = (double)rand() / ((double)RAND_MAX + 1.0);
  return (low + (int)(_d * (high - low + 1)));
}

double GenerateRandomReal(double low, double high)
{
  double _d;
  if( low > high )
    PrintErrorMessage( FALSE, "GenerateRandomReal: Make sure low <= high.\n" );
  _d = (double)rand() / ((double)RAND_MAX + 1.0);
  return (low + _d * (high - low));
}

BOOL SimulateEventWithProbability(double prob)
{
  if( prob < 0 || prob > 1 )
    PrintErrorMessage( FALSE, "SimulateEventWithProbability: Make sure 0 <= prob <= 1.\n" );
  return GenerateRandomReal(0.0, 1.0) > prob;
}

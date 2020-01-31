#include <stdio.h>
#include "zylib.h"
int main()
{
    printf("This program is to find  position the first vowel in the string you input.\n");
    STRING s, b, a, e, i, o, u;
    a="a", e="e", i="i", o="o", u="u";
    int n, pos;
    s=GetStringFromKeyboard();
    n=GetStringLength(s);
    printf("%d", n);
   for( pos=0; pos<n; pos++)
   {
    b[0] = GetIthChar( s, pos );
    if(IsStringEqualWithoutCase( b, a)||IsStringEqualWithoutCase( b, e)||IsStringEqualWithoutCase( b, i)||IsStringEqualWithoutCase( b, o)||IsStringEqualWithoutCase( b, u))
    {
     printf("%d", pos);
     break;
    }
   }

   system("pause");
   return 0;
}
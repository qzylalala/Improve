#include<stdio.h>
int main()
{
    printf("Input your char x:\n");
    char x;
    scanf("%c",&x);
if(x>='a'&&x<='z')
printf(" %c\n",x);
else if(x>='A'&&x<='Z')
printf(" %c\n",x-'A'+'a');
else
printf("Please input the right char.");

return 0;
}

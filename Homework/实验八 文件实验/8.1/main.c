#include <stdio.h>
int main(void)
{
	short a=0x253f,b=0x7b7d;
	char ch;
	FILE *fp1,*fp2;
	fp1=fopen("d:\\abc1.bin","wb+");
    fp2=fopen("d:\\abc2.txt","w+");
	fwrite(&a,sizeof(short),1,fp1);//fwrite函数参数含义  从&a处开始取1个sizeof(?)写到fp1里面
    fwrite(&b,sizeof(short),1,fp1);
	fprintf(fp2,"%d %d",a,b);

    rewind(fp1); rewind(fp2);//rewind函数将文件的读写指针stream重新指向文件的起始位置
	while((ch = fgetc(fp1)) != EOF)
		putchar(ch);
	putchar('\n');

	while((ch = fgetc(fp2)) != EOF)
		putchar(ch);
	putchar('\n');

	fclose(fp1);
	fclose(fp2);
 return 0;
}

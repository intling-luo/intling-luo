//2.有一段文本，统计其中的单词数。
//例如： As a technology , "HailStorm" is so new that it is still only known by its code name. 
//注意：单词间的间隔不一定是一个空格。
#include<stdio.h>
int main()
{
	int a=0,i=0;
	char b[1000];
	gets(b);
	do
	{
	
		if(b[i]>'z'||b[i]<'A') 
		{
			if(b[i-1]<='z'&&b[i-1]>='A')
			a++;
		}
		i++;
}while(b[i]!='\0');
	printf("%d",a+1);
 } 

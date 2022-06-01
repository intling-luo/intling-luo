//4.给定一个正整数?n，请你求出1～n?中质数的个数。
#include<stdio.h>
int main()
{
	int a=0,i,j,h=0;
	scanf("%d",&a);
	h=a;
	for(i=1;i<=a;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0&&i!=j)
			{
			h--;	
			break;
		}
		}
	}
	printf("%d",h-1);
}

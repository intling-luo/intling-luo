//4.����һ��������?n���������1��n?�������ĸ�����
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

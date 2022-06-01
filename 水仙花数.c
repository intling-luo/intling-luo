//1.输入一个数n，编程打印出1~n之间的水仙花数
//（水仙花数就是这个数的每一位的三次方和等于该数本身的数）
#include<stdio.h>
int main()
{
	int a,n[100],d,e=0,p=0;
	int i,j,g;
	scanf("%d",&a);	
	for(i=1;i<a;i++)
	{ 
	p=i;
		for(j=0;j<10;j++)
		{
			if(p==0)
			break;	
			n[j]=p%10;
			p=p/10;
			d=j;
			e+=n[j]*n[j]*n[j];
		}
	if(e==i)
		printf("%d\n",e);
		e=0;
	}
	
}

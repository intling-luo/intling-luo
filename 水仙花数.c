//1.����һ����n����̴�ӡ��1~n֮���ˮ�ɻ���
//��ˮ�ɻ��������������ÿһλ�����η��͵��ڸ������������
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

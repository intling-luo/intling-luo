//3.设编号为 1，2，… n 的 n 个人围坐一圈，约定编号为 k（1<=k<=n）的人从 1 开始报数，
//数到 m 的那个人出列，它的下一位又从 1 开始报数，数到 m 的那个 人又出列，依次类推，
//直到所有人出列为止，由此产生一个出队编号的序列。
#include<stdio.h>
int main()
{
int m,n,k,a[1000];
int j,i,c,g,p,s=1;
printf("请输入m n k:");
scanf("%d %d %d",&m,&n,&k);
for(j=0;j<n;j++)
{
	a[j]=j+1;
}
k=k-1;
p=n;
 for(i=0;i<p;i++)
 {
 	for(c=m;c>0;c--)
 	{
 		if(k>=n-1)
	 {
	 k=0;
	 }	
	 else if(s!=1)
 	k++;
 	s=-1;
	 
}
 printf("%d ",a[k]);
 for(g=k;g<n;g++)
	 {
	 	a[g]=a[g+1]; 
	 	if(k>=g-1)
		 k--; 
	 }
	 n--; 	
 }
}

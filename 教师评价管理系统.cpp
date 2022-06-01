#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
#include<unistd.h>
const char* pic = "|/-\\"; //简单动画特效
void csh();//初始化 
void menu();//菜单_初始界面
void menu_jwc();//菜单_教务处-登入时界面 
void menu_jwc2();//菜单_教务处-真正的管理界面 
void menu_js();//菜单_教师
void menu_xs();//菜单_学生-登入界面 
void menu_xs2();//菜单_学生-真正的界面 
void jwc_xj();//功能-新建
void jwc_xg();//功能-修改 
void jwc_sc();//功能-删除 
void jwc_menu();//功能-打印成绩菜单 
void sc_hg();//功能-输出合格 
void sc_sy();//功能-输出所有 
void sc_bhg();//功能-输出不合格 
void js_cx();// 功能-教师查询 
void js_xx();//功能-教师信息 
void xs_dr();//功能-学生登入 
void xs_zc();//功能-学生注册 
void pj_xj();//功能-学生评价 
struct teacher//教师内容的结构体 
{
	char name[20];//名字 
	char gh[20];//工号 
	char sex[20];//性别
	char tel[20]; //联系方式
	char kc[20];//教学课程 
	double rs;//评价人数
	double av;//平均分数
	double sum;//总分数 
};
typedef struct student//学生注册个人信息
{
	char name[20];//名字 
	char gh[20];//学号 
	char sex;//性别
	char tel[20]; //联系方式
	char pwd[20];//学生密码 
	int pj; 
}students;
students xs;//预设学生，用于传递登入信息 
int main()
{
	csh();
	menu();
	return 0;
} 
void csh()
{
	int i=0,num=1;
	printf(" 系统正在初始化,请稍后\n");
	for(i=0;i<=100;i++)
	{
		Sleep(25);
		for(int nx=0;nx<=114;nx++)
		{
			printf("\b");
		} 
		for(int nx=0;nx<=10;nx++)
		{
			if(nx<=i/10)
			{
				printf("-");
			}
			else
			{
				printf(">");
			}
		}
	    printf("当前进度：");
		num++;
		printf("%-3d%%",i);// \b作用为退格 -3d向左靠齐，不足3位补空格
		printf("%c",pic[num%4]);//播放小动画 	
	}
	printf("\n  初始化成功!\n");
	printf("欢迎使用学生评教系统\n");	
	system("pause");//暂停，摁任意键继续 
}
void menu()
{
	system("cls") ;//清屏函数
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|------欢迎进入教师评价管理系统-------|\n");
	printf("\t\t\t\t|------------选择你的身份-------------|\n");
	printf("\t\t\t\t|------------1.教务处-----------------|\n");
	printf("\t\t\t\t|------------2.教师-------------------|\n");
	printf("\t\t\t\t|------------3.学生-------------------|\n");
	printf("\t\t\t\t|------------0.退出-------------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	int num_menu=0;
	scanf("%d",&num_menu);//输入数字，不属于0~3则提示后返回原菜单 
	switch(num_menu)
	{
		case 1:menu_jwc();break;
		case 2:menu_js();break;
		case 3:menu_xs();break;
		case 0:break;
		default:
			printf("输入有误，将在3s后返回主菜单!\n");
			Sleep(3000);//睡眠，让后面的动作晚运行，3000=3s 
			menu();
			break;
	} 
}
void menu_jwc()//表层-未登入界面 
{
	system("cls") ;//清屏函数
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|------欢迎进入教师评价管理系统-------|\n");
	printf("\t\t\t\t|---------------教务处----------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|--------------请先登入---------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("账号:");
	int zh=0,mm=0;
	scanf("%d",&zh); 
	printf("密码:");
	scanf("%d",&mm);
	//账号密码正确后进入教务处管理系统，不正确则在提示后返回主菜单
	struct A
	{
		int zh1;
		int mm1;
	};
		struct A a = {0};
		FILE* pf = fopen("jwc.txt", "r");//读文件
		for(int p=0;p<20;p++)    //测试20行检查账号密码库有无对应 
	{
		fscanf(pf,"%d %d",&a.zh1,&a.mm1);//从文件中读取格式化数据到结构体中
		if(zh==a.zh1&&mm==a.mm1)
		{
			printf("登录成功，正在进入系统");	//检索到正确的账号密码进入系统跳出循环 
			
			menu_jwc2();	//进入教务处系统函数 
			fclose(pf);
			break;
		}
		else if(p==19)
		{
			printf("账号或密码错误，将在3s后返回主菜单");
			fclose(pf);
			Sleep(3000);
	    	menu(); 		//未检索到返回主菜单 
		}
	
	} 
}
void menu_jwc2()
{
	system("cls") ;//清屏函数
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|------欢迎进入教师评价管理系统-------|\n");
	printf("\t\t\t\t|---------------教务处----------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|---------1.新建教职工信息------------|\n");
	printf("\t\t\t\t|---------2.修改教职工信息------------|\n");
	printf("\t\t\t\t|---------3.删除教职工信息------------|\n");
	printf("\t\t\t\t|---------4.输出教职工信息------------|\n");
	printf("\t\t\t\t|---------0.返回主菜单----------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	int num_menu=0;
	scanf("%d",&num_menu);//输入数字，不属于0~3则提示后返回原菜单 
	switch(num_menu)
	{
		case 1:jwc_xj();break;
		case 2:jwc_xg();break;
		case 3:jwc_sc();break;
		case 4:jwc_menu();break;
		case 0:menu();break;
		default:
			printf("输入有误，将在3s后返回菜单!\n");
			Sleep(3000);//睡眠，让后面的动作晚运行，3000=3s 
			menu_jwc2();
			break;
	}  
}
void jwc_xj()//新建 
{
	struct teacher linshi={0};
	printf("请依次输入姓名，工号，性别，联系方式，教学课程，以空格分隔\n");
	scanf("%s %s %s %s %s",linshi.name,linshi.gh,linshi.sex,linshi.tel,linshi.kc);
	FILE* pf = fopen("jwcdata.txt", "a");
	fprintf(pf,"%s %s %s %s %s %lf %lf %lf\n",linshi.name,linshi.gh,linshi.sex,linshi.tel,linshi.kc,linshi.rs,linshi.av,linshi.sum);
 	printf("新建完毕，三秒后返回教务处系统菜单");	
 	Sleep(3000);
	menu_jwc2();
	fclose(pf); 
}
void jwc_xg()//修改 
{
	int k=0; 
	struct teacher linshi={0};
	printf("请输入需要修改的信息!\n");
	printf("依次输入姓名，工号，性别，联系方式，教学课程，以空格分隔\n系统会匹配工号来修改此人数据\n");
	scanf("%s %s %s %s %s",linshi.name,linshi.gh,linshi.sex,linshi.tel,linshi.kc);
	FILE *fp=fopen("jwcdata.txt","r");
	FILE *fpt=fopen("temp.tmp", "w");//创建临时文件来保存修改信息 
	if(fp<0)
	{
		printf("教师信息文件不存在！\n");
		printf("三秒后返回教务处系统菜单!");	
		Sleep(3000);
		menu_jwc2();
	}
	struct teacher th2={};
	while(fscanf(fp,"%s %s %s %s %s %lf %lf %lf",th2.name,th2.gh,th2.sex,th2.tel,th2.kc,&th2.rs,&th2.av,&th2.sum)!=EOF)//当读到底时退出循环 
	{
		if(strcmp(th2.gh,linshi.gh)==0)
		{
			fprintf(fpt,"%s %s %s %s %s %lf %lf %lf\n",linshi.name,linshi.gh,linshi.sex,linshi.tel,linshi.kc,th2.rs,th2.av,th2.sum);//符合工号条件时，输入的信息为修改后的 
			k+=1;
		}
		else
		{
			fprintf(fpt,"%s %s %s %s %s %lf %lf %lf\n",th2.name,th2.gh,th2.sex,th2.tel,th2.kc,th2.rs,th2.av,th2.sum);//不符合时，输入原信息 
		}
	}
	if(k!=0)
	{
		fclose(fp);
		fclose(fpt);
		remove("jwcdata.txt");//先移除原文件 
	    rename("temp.tmp","jwcdata.txt");//将新文件改名 
		printf("信息已修改！\n"); 
	}
	else if(k==0)
	{
		fclose(fp);
		fclose(fpt);
		printf("查无此工号！三秒后返回菜单\n") ;
		Sleep(3000);
			menu_jwc2();
			return;
	 } 
		printf("三秒后返回教务处系统菜单!");
		Sleep(3000);
		menu_jwc2(); 
	}
void jwc_sc()//删除 
{
	struct teacher linshi={0};
	printf("请输入需要删除的工号!\n");
	scanf("%s",linshi.gh);
	FILE *fp=fopen("jwcdata.txt","r");
	FILE *fpt=fopen("temp.tmp", "w");//创建临时文件来保存修改信息 
	if(fp<0)
	{
		printf("教师信息文件不存在！\n");
		printf("三秒后返回教务处系统菜单!");	
		Sleep(3000);
		menu_jwc2();
	}
	struct teacher th2={};
	while(fscanf(fp,"%s %s %s %s %s %lf %lf %lf",th2.name,th2.gh,th2.sex,th2.tel,th2.kc,&th2.rs,&th2.av,&th2.sum)!=EOF)//当读到底时退出循环 
	{
		if(strcmp(th2.gh,linshi.gh)!=0)
		{
			fprintf(fpt,"%s %s %s %s %s %lf %lf %lf\n",th2.name,th2.gh,th2.sex,th2.tel,th2.kc,th2.rs,th2.av,th2.sum);//不符合时，输入原信息
		}//符合时不输入信息 
	}
	fclose(fp);
	fclose(fpt);
	remove("jwcdata.txt");//先移除原文件 
    rename("temp.tmp","jwcdata.txt");//将新文件改名 
	printf("信息已修改！\n"); 
	printf("三秒后返回教务处系统菜单!");
	Sleep(3000);
	menu_jwc2(); 
}
void jwc_menu()//输出菜单 
{
	system("cls") ;//清屏函数
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|------欢迎进入教师评价管理系统-------|\n");
	printf("\t\t\t\t|---------------教务处----------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|---------1.输出合格教师信息----------|\n");
	printf("\t\t\t\t|---------2.输出所有教师信息----------|\n");
	printf("\t\t\t\t|---------3.输出不合格教师信息--------|\n");
	printf("\t\t\t\t|---------0.返回上级菜单--------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	int num_menu=0;
	scanf("%d",&num_menu);//输入数字，不属于0~3则提示后返回原菜单 
	switch(num_menu)
	{
		case 1:sc_hg();break;
		case 2:sc_sy();break;
		case 3:sc_bhg();break;
		case 0:menu_jwc2();break;
		default:
			printf("输入有误，将在3s后返回菜单!\n");
			Sleep(3000);//睡眠，让后面的动作晚运行，3000=3s 
			jwc_menu();
			break;
	}  
}
void sc_hg(){
	int i=0,j=0;
	FILE*fp;
	struct teacher lingshi[100] ;
	if((fp = fopen("jwcdata.txt","r"))==NULL){//打开文件 
		printf("File open error!/n");
		exit(0);
	}
		fscanf(fp,"%s%s%s%s%s%lf%lf%lf",&lingshi[i].name,&lingshi[i].gh,&lingshi[i].sex,&lingshi[i].tel,&lingshi[i].kc,&lingshi[i].rs,&lingshi[i].av,&lingshi[i].sum);
		
	while(lingshi[i].sum!=0){//从文件中将数据读到结构体里 
    	i++;
		fscanf(fp,"%s%s%s%s%s%lf%lf%lf",&lingshi[i].name,&lingshi[i].gh,&lingshi[i].sex,&lingshi[i].tel,&lingshi[i].kc,&lingshi[i].rs,&lingshi[i].av,&lingshi[i].sum);
	    j++;
	   
	}
	if(i==1){
		j=0;
	}
	for(i=0;i<j;i++){//输出教师数据 
		if(lingshi[i].av>=60){
			printf("名字:%s 工号:%s 性别:%s 联系电话:%s 课程:%s 评价人数:%.0lf 平均分数:%.2lf 分数总和:%.0lf\n",lingshi[i].name,lingshi[i].gh,lingshi[i].sex,lingshi[i].tel,lingshi[i].kc,lingshi[i].rs,lingshi[i].av,lingshi[i].sum);
		}
	}
	if(fclose(fp)){//关闭文件 
		printf("Can't not close the file'");
		exit(0);
	}
	system("pause");
	jwc_menu(); 
}
void sc_sy(){
	int i=0,j=0;
	FILE*fp;
	struct teacher lingshi[100] ;
	if((fp = fopen("jwcdata.txt","r"))==NULL){//打开文件 
		printf("File open error!/n");
		exit(0);
	}
		fscanf(fp,"%s%s%s%s%s%lf%lf%lf",&lingshi[i].name,&lingshi[i].gh,&lingshi[i].sex,&lingshi[i].tel,&lingshi[i].kc,&lingshi[i].rs,&lingshi[i].av,&lingshi[i].sum);
		
	while(lingshi[i].sum!=0){//从文件中将数据读到结构体里 
    	i++;
		fscanf(fp,"%s%s%s%s%s%lf%lf%lf",&lingshi[i].name,&lingshi[i].gh,&lingshi[i].sex,&lingshi[i].tel,&lingshi[i].kc,&lingshi[i].rs,&lingshi[i].av,&lingshi[i].sum);
	    j++;
	   
	}
	if(i==1){
		j=0;
	}
	for(i=0;i<j;i++){//输出教师数据 
		
			printf("名字:%s 工号:%s 性别:%s 联系电话:%s 课程:%s 评价人数:%.0lf 平均分数:%.2lf 分数总和:%.0lf\n",lingshi[i].name,lingshi[i].gh,lingshi[i].sex,lingshi[i].tel,lingshi[i].kc,lingshi[i].rs,lingshi[i].av,lingshi[i].sum);
		
	}
	if(fclose(fp)){//关闭文件 
		printf("Can't not close the file'");
		exit(0);
	}
	system("pause");
	jwc_menu();
}
void sc_bhg(){
	int i=0,j=0;
	FILE*fp;
	struct teacher lingshi[100] ;
	if((fp = fopen("jwcdata.txt","r"))==NULL){//打开文件 
		printf("File open error!/n");
		exit(0);
	}
		fscanf(fp,"%s%s%s%s%s%lf%lf%lf",&lingshi[i].name,&lingshi[i].gh,&lingshi[i].sex,&lingshi[i].tel,&lingshi[i].kc,&lingshi[i].rs,&lingshi[i].av,&lingshi[i].sum);
		
	while(lingshi[i].sum!=0){//从文件中将数据读到结构体里 
    	i++;
		fscanf(fp,"%s%s%s%s%s%lf%lf%lf",&lingshi[i].name,&lingshi[i].gh,&lingshi[i].sex,&lingshi[i].tel,&lingshi[i].kc,&lingshi[i].rs,&lingshi[i].av,&lingshi[i].sum);
	    j++;
	   
	}
	if(i==1){
		j=0;
	}
	for(i=0;i<j;i++){//输出教师数据 
		if(lingshi[i].av<60){
			printf("名字:%s 工号:%s 性别:%s 联系电话:%s 课程:%s 评价人数:%.0lf 平均分数:%.2lf 分数总和:%.0lf\n",lingshi[i].name,lingshi[i].gh,lingshi[i].sex,lingshi[i].tel,lingshi[i].kc,lingshi[i].rs,lingshi[i].av,lingshi[i].sum);
		}
	}
	if(fclose(fp)){//关闭文件 
		printf("Can't not close the file'");
		exit(0);
	}
	system("pause");
	jwc_menu();
}
void menu_js()
{
	system("cls") ;//清屏函数
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|------欢迎进入教师评价管理系统-------|\n");
	printf("\t\t\t\t|---------------教师端----------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|-------------1.查询成绩--------------|\n");
	printf("\t\t\t\t|-------------2.检查个人信息----------|\n");
	printf("\t\t\t\t|-------------0.返回主菜单------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	int num_menu=0;
	scanf("%d",&num_menu);//输入数字，不属于0~3则提示后返回原菜单 
	switch(num_menu)
	{
		case 1:js_cx();break;
		case 2:js_xx();break;
		case 0:menu();break;
		default:
			printf("输入有误，将在3s后返回菜单!\n");
			Sleep(3000);//睡眠，让后面的动作晚运行，3000=3s 
			menu_js();
			break;
	}  
}
void js_cx()//输入工号查询教师成绩 
{
	system("cls") ;//清屏函数
	struct teacher linshi={0};
    printf("请输入你要查询的教师工号是:\n");
    scanf("%s",linshi.gh);
    FILE *fp=fopen("jwcdata.txt","r");
	FILE *fpt=fopen("temp.tmp", "w");
	struct teacher th2={};
	int no=0;
	while(fscanf(fp,"%s %s %s %s %s %lf %lf %lf",th2.name,th2.gh,th2.sex,th2.tel,th2.kc,&th2.rs,&th2.av,&th2.sum)!=EOF) //当读到底时退出循环 
	{
		if(!strcmp(linshi.gh,th2.gh))//查询的工号有对应老师 
		{
			printf("名字：%s 平均分数：%.2lf\n",th2.name,th2.av);
			no+=1;
		}
    }
	if(no==0)//输入工号错误或系统中无此工号
	{
	 printf("系统中无此教师信息!\n");	
	} 
    fclose(fp);
	fclose(fpt);
	system("pause");
	menu_js();
} 
void js_xx()//输入工号查询教师个人信息 
{
	system("cls") ;//清屏函数
	struct teacher linshi={0};
    printf("请输入你要查询的教师工号是:\n");
    scanf("%s",linshi.gh);
    FILE *fp=fopen("jwcdata.txt","r");
	FILE *fpt=fopen("temp.tmp", "w");
	struct teacher th2={};
	int no=0;
	while(fscanf(fp,"%s %s %s %s %s %lf %lf %lf",th2.name,th2.gh,th2.sex,th2.tel,th2.kc,&th2.rs,&th2.av,&th2.sum)!=EOF) //当读到底时退出循环 
    {
		if(!strcmp(linshi.gh,th2.gh))//查询的工号有对应老师 
		{
			printf("名字：%s 工号：%s 性别：%s 联系电话：%s 课程：%s 评价人数：%.0lf 分数总和：%.2lf\n",th2.name,th2.gh,th2.sex,th2.tel,th2.kc,th2.rs,th2.sum);
			no+=1;
		}
   }
	if(no==0)//输入工号错误或系统中无此工号
	{
	 printf("系统中无此教师信息!\n");	
	} 
    fclose(fp);
	fclose(fpt);
	system("pause");
	menu_js();
}
void menu_xs()//学生端登入菜单
{
	system("cls") ;//清屏函数
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|------欢迎进入教师评价管理系统-------|\n");
	printf("\t\t\t\t|---------------学生端----------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|-------------1.账号登入--------------|\n");
	printf("\t\t\t\t|-------------2.账号注册--------------|\n");
	printf("\t\t\t\t|-------------0.返回主菜单------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	int num_menu=0;
	scanf("%d",&num_menu);//输入数字，不属于0~3则提示后返回原菜单 
	switch(num_menu)
	{
		case 1:xs_dr();break;
		case 2:xs_zc();break;
		case 0:menu();break;
		default:
			printf("输入有误，将在3s后返回菜单!\n");
			Sleep(3000);//睡眠，让后面的动作晚运行，3000=3s 
			menu_xs();
			break;
	}  
}
/*创建储存用户账号密码的文件*/ 
void Create_File()
{
    FILE *fp;
    if ((fp = fopen("users.txt","rb"))==NULL)                 /*如果此文件不存在*/
    {
        if ((fp = fopen("users.txt","wb+"))==NULL)
        {
            printf("无法建立文件！\n");
            exit(0);
            
        }
    }
}

void xs_dr()//功能-学生登入 
{/*登录系统*/ 
    system("cls") ;//清屏函数
    students a,b;//定义结构体The_users别名
    FILE *fp;
    printf("欢迎来到登录界面！\n");
    Sleep(1000);
    fp = fopen("users.txt","ab+");
    fread(&b, sizeof(struct student), 1, fp); //读入一个结构体字符块 写入b
    printf("请输入账号\n");
    scanf("%s",&a.gh);   
             while (1)
           {   
	           if (strcmp(a.gh, b.gh)==0)         //如果有此用户名
	           {
	               break;       
	           }
	           else 
	           {
	               if (!feof(fp))  //如果文件没有读完                            
	            
	               {
	                   fread(&b, sizeof(struct student), 1, fp);
	               }
	               else
	               {
	                   printf("此用户名不存在，请重新输入！\n");
					   Sleep(500); 
					   printf("请输入账号\n");
					   scanf("%s",&a.gh);         
	               }
	           }
       }
       printf("请输入密码\n");
       	scanf("%s",&a.pwd); 
    do{   
	       
		if (strcmp(a.pwd, b.pwd)==0)            /*如果密码匹配*/
	           
	       {  
	          fclose(fp);
	          xs=b;
	          printf("登录成功,欢迎使用!");
	          Sleep(200);
	          menu_xs2();
	          return;
	          }
	       else  
	       {    printf("密码不正确!请重新输入密码\n");
	       		scanf("%s",&a.pwd);         
	       }
	}while(strcmp(a.pwd, b.pwd)==0);
} 
void xs_zc()//功能-学生注册 
{/*注册账号*/   
         students a,b;//结构体 The_users 重命名定义
         FILE *fp;
         char temp[20];
         int count = 0;
         printf("欢迎来到注册界面！\n");
         Sleep(1000);
         fp = fopen("users.txt","ab+");
         fread(&b, sizeof(struct student), 1, fp); //读入一个结构体字符块 到b
          printf("请输入账号\n");
         scanf("%s",&a.gh);
         while (1)
         {    
             if (strcmp(a.gh, b.gh)) /*如果两串不相等*/
             {
                 if (!feof(fp))    /*如果未到文件尾*/                                        
                 {
                     fread(&b, sizeof(struct student), 1, fp);
                 }
                 else
                     break;
             }
             else
             {   
                 printf("此用户名已存在！请重新注册！\n"); 
                 Sleep(1000);
                 fclose(fp);
                 xs_zc();   
             }
         }
         printf("请输入姓名：\n");
         scanf("%s",&a.name);
         printf("请输入性别(f(女)/m(男))：\n");
         scanf(" %c",&a.sex);
         do{
         	if(a.sex != 'f' && a.sex != 'm'){
			 	printf("性别输入错误！请重新输入！\n");
		        scanf("%c",&a.sex);
			 }
		 }while(a.sex != 'f' && a.sex != 'm');
		 getchar();
         printf("请输入电话号码：\n");
         scanf("%ld",&a.tel);
         printf("请输入密码\n");
         scanf(" %s",&a.pwd);
         printf("请确认密码\n");
         scanf(" %s",&temp);
		 do{
         	if(!strcmp(a.pwd,temp)){
         		fp = fopen("users.txt","ab+");
         		 a.pj=0;
		         fwrite(&a, sizeof(struct student), 1, fp);
		         printf("账号注册成功，三秒后进入登录界面\n"); 
		         fclose(fp);
		         Sleep(3000);//睡眠，让后面的动作晚运行，3000=3s 
			     break;
			 }else{
			 	printf("两次密码不匹配！请重新输入！\n");
		         scanf("%s",&a.pwd);
		         printf("请确认密码\n");
		         scanf("%s",&temp);
			 }
		 }while(1);
		 xs_dr();
}
void menu_xs2()//学生端菜单 
{
	system("cls") ;//清屏函数
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|------欢迎进入教师评价管理系统-------|\n");
	printf("\t\t\t\t|---------------学生端----------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|---------1.进行教师评价--------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	printf("\t\t\t\t|---------0.返回主菜单----------------|\n");
	printf("\t\t\t\t|-------------------------------------|\n");
	int num_menu=0;
	scanf("%d",&num_menu);//输入数字，不属于0~3则提示后返回原菜单 
	switch(num_menu)
	{
		case 1:pj_xj();break;
		case 0:menu();break;
		default:
			printf("输入有误，将在3s后返回菜单!\n");
			Sleep(3000);//睡眠，让后面的动作晚运行，3000=3s 
			menu_xs2();
			break;
	} 
}
void pj_xj()//功能-学生评价 
{
	system("cls"); 
	if(xs.pj==0)
	{
		printf("请学生公正评价！\n");
		printf("评价仅一次！不允许更改！\n");
		printf("2s后依次对教师进行评价！\n");
		Sleep(2000);
		FILE *fp=fopen("jwcdata.txt","r");//打开教师文件 
		FILE *fpt=fopen("temp.tmp", "w");//创建临时文件来保存修改信息 
		FILE *fp2=fopen("users.txt","rb");//打开学生文件 
		FILE *fpt2=fopen("user.tmp","wb");//创建临时文件来保存修改信息 
		struct teacher th2={};
		while(fscanf(fp,"%s %s %s %s %s %lf %lf %lf",th2.name,th2.gh,th2.sex,th2.tel,th2.kc,&th2.rs,&th2.av,&th2.sum)!=EOF)//当读到底时退出循环 
		{
			printf("%s老师：",th2.name);
			int pj_num=0;
			scanf("%d",&pj_num);
			printf("\n");
			th2.rs+=1;
			th2.sum+=pj_num;
			th2.av=th2.sum/th2.rs;
			fprintf(fpt,"%s %s %s %s %s %lf %lf %lf\n",th2.name,th2.gh,th2.sex,th2.tel,th2.kc,th2.rs,th2.av,th2.sum);
		}
		xs.pj=1;
		students xs2={};
		while(!feof(fp2))//当读到底时退出循环 
		{
			fread(&xs2, sizeof(struct student),1, fp2); 
			if(strcmp(xs.gh,xs2.gh)==0)
			{
				fwrite(&xs, sizeof(struct student),1, fpt2);//符合工号条件时，输入的信息为修改后的 
			}
			else
			{
				fwrite(&xs2, sizeof(struct student),6, fpt2);//不符合时，输入原信息 
			}
		}
		fclose(fp);
		fclose(fpt);
		fclose(fp2);
		fclose(fpt2);
		remove("jwcdata.txt");//先移除原文件 
	    rename("temp.tmp","jwcdata.txt");//将新文件改名 
	    remove("users.txt");//先移除原文件 
	    rename("user.tmp","users.txt");//将新文件改名 
		printf("评价已完成！\n"); 
		printf("三秒后返回菜单!");
		Sleep(3000);
		menu_xs2(); 
	}
	else
	{
		printf("你已进行过评价！\n");
		printf("三秒后返回菜单!");
		Sleep(3000);
		menu_xs2(); 
	}
} 

#include <stdio.h>   
#include <math.h>   
#include <stdlib.h>
#include <time.h> 
#include <string.h>
#include <ctype.h>
#define MAX 20 

//不同人员的教务系统界面 
void student();
void teacher();
void manager();

//学生的教务系统功能
void show(char* sno); 
void passwordchanges(char* sno);    
void showct(char* sno);   
void gradesearch(char* sno);  
void currsearch(char* sno); 
void currselect(char* sno);
void currdelete(char* sno);    

//教师的教务系统功能
void showt(char* tno); 
void passwordchanget(char* tno);    
void curradd(char* tno);   
void showctt(char* tno);  
void gradein(char* tno); 

//管理员的教务系统功能
void studentin(); 
void teacherin();   
void studentshow();
void teachershow(); 
void studentchange(); 
void teacherchange();
void gradecheck();
                
struct tm *current_date;
time_t seconds;
time(&seconds); 
current_date = localtime(&seconds);//时间

int main(void)
{ 
   int No;
   while(1)  
        {  
                //登录界面   
                printf("\n");
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n");  
                printf ("┇                 教务系统登录                 ┇\n"); 
                printf ("┇                         %d-%d-%d %02d:%02d       ┇\n",current_date->tm_mon+1,current_date->tm_mday, current_date->tm_year,current_date->tm_hour, current_date->tm_min); 
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
                printf ("┇  学生登录_1    教师登录_2    管理员登录_3    ┇\n");
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
                printf ("请选择:");  
                scanf ("%d",&No); 
                if (No == 1)  
                {    
                   student(); 
                }  
                else if (No == 2)  
                {   
                   teacher();  
                }  
                else if (No == 3)  
                {   
                   manager();
                }  
                else  
                {  
                        //        输入的选项不对   
                        printf("  请输入1-3的数字。\n\n");  
                }
                system ("pause");        //按任意键继续   
                system ("cls");                //清屏   
        }  
        return 0;  
        getchar();     
}
	
void student()
{
     int No;
     char[MAX] sno,password;
			while(1){
			//登录界面   
                printf("\n");
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n");  
                printf ("┇                 教务系统登录                 ┇\n"); 
                printf ("┇                         %d-%d-%d %02d:%02d       ┇\n",current_date->tm_mon+1,current_date->tm_mday, current_date->tm_year,current_date->tm_hour, current_date->tm_min); 
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
                printf ("┇输入学号:\n");scanf ("%s",sno); 
		    	printf ("┇输入密码:\n");scanf ("%s",password);    
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
           //密码正确 
           if();
           {
                while(1){  
                //学生界面   
                printf("\n");
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n");  
                printf ("┇                   教务系统                   ┇\n"); 
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
				printf ("┇请选择你要进行的操作:                         ┇\n");
				printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");  
                printf ("┇  学籍卡片_1           密码修改_2             ┇\n");  
                printf ("┇  个人课表_3           成绩查询_4             ┇\n");  
                printf ("┇  课程查询_5           选课_6                 ┇\n");  
                printf ("┇  撤课_7               退出_0                 ┇\n"); 
            	printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
				printf ("┇                         %d-%d-%d %02d:%02d       ┇\n",current_date->tm_mon+1,current_date->tm_mday, current_date->tm_year,current_date->tm_hour, current_date->tm_min);  
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
                printf ("请选择操作:");  
                scanf ("%d",&No); 
                if (No == 1)  
                {    
                   show(sno); 
                }  
                else if (No == 2)  
                {   
                   passwordchanges(sno);   
                }  
                else if (No == 3)  
                {   
                   showct(sno);
                }  
                else if (No == 4)  
                {    
                   gradesearch(sno); 
                }  
                else if (No == 5)  
                {   
                   currsearch(sno); 
                }  
                else if (No == 6)  
                {  
                  currselect(sno);
                }  
                else if (No == 7)  
                {  
                  currdelete(sno);
                } 
                else if (No == 0)  
                {  
                       //        退出程序   
                        break;  
                }  
                else  
                {   
                        printf("  请输入0-7的数字。\n\n");  
                }  
                system ("pause");        //按任意键继续   
                system ("cls");                //清屏   
        }    
        getchar();  
    }  
	else  
    {   
        printf("  用户名或密码错误\n\n");  
     }  
     system ("pause");        //按任意键继续   
     system ("cls");                //清屏   
    }    
        getchar();   
}

void teacher()
{
     int No;
     char[MAX]tno,password;
			//登录界面 
			while(1){  
                printf("\n");
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n");  
                printf ("┇                 教务系统登录                 ┇\n"); 
                printf ("┇                         %d-%d-%d %02d:%02d       ┇\n",current_date->tm_mon+1,current_date->tm_mday, current_date->tm_year,current_date->tm_hour, current_date->tm_min); 
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
                printf ("┇输入工号:\n");scanf ("%s",tno); 
		    	printf ("┇输入密码:\n");scanf ("%s",password);    
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
           //密码正确 
           if();
           {
                while(1){  
                //教师界面   
                printf("\n");
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n");  
                printf ("┇                   教务系统                   ┇\n"); 
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
				printf ("┇请选择你要进行的操作:                         ┇\n");
				printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");  
                printf ("┇  教师卡片_1           密码修改_2             ┇\n");  
                printf ("┇  创建课程_3           个人课表_4             ┇\n");  
                printf ("┇  成绩录入_5           退出_0                 ┇\n"); 
            	printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
				printf ("┇                         %d-%d-%d %02d:%02d       ┇\n",current_date->tm_mon+1,current_date->tm_mday, current_date->tm_year,current_date->tm_hour, current_date->tm_min);  
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
                printf ("请选择操作:");  
                scanf ("%d",&No); 
                if (No == 1)  
                {    
                   showt(tno); 
                }  
                else if (No == 2)  
                {   
                   passwordchanget(tno);   
                }  
                else if (No == 3)  
                {   
                   curradd(tno);
                }  
                else if (No == 4)  
                {    
                   showctt(tno); 
                }  
                else if (No == 5)  
                {   
                   gradein(tno); 
                }  
                else if (No == 0)  
                {  
                       //        退出程序   
                        break;  
                }  
                else  
                {   
                        printf("  请输入0-5的数字。\n\n");  
                }  
                system ("pause");        //按任意键继续   
                system ("cls");                //清屏   
        }    
        getchar();  
    }
	else  
    {   
        printf("  用户名或密码错误\n\n");  
     }  
     system ("pause");        //按任意键继续   
     system ("cls");                //清屏   
    }    
        getchar();   
}


void manager()
{
     int No;
     char[MAX] mno,password;
			//登录界面
			while(1){    
                printf("\n");
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n");  
                printf ("┇                 教务系统登录                 ┇\n"); 
                printf ("┇                         %d-%d-%d %02d:%02d       ┇\n",current_date->tm_mon+1,current_date->tm_mday, current_date->tm_year,current_date->tm_hour, current_date->tm_min); 
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
                printf ("┇输入学号:\n");scanf ("%s",mno); 
		    	printf ("┇输入密码:\n");scanf ("%s",password);    
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
           //密码正确 
           if();
           {
                while(1){  
                //管理员界面   
                printf("\n");
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n");  
                printf ("┇                   教务系统                   ┇\n"); 
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
				printf ("┇请选择你要进行的操作:                         ┇\n");
				printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");  
                printf ("┇  学生信息录入_1       教师信息录入_2         ┇\n");  
                printf ("┇  学生信息查询_3       教师信息查询_4         ┇\n");  
                printf ("┇  学生信息修改_5       教师信息修改_6         ┇\n");  
                printf ("┇  成绩审核_7           退出_0                 ┇\n"); 
            	printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
				printf ("┇                         %d-%d-%d %02d:%02d       ┇\n",current_date->tm_mon+1,current_date->tm_mday, current_date->tm_year,current_date->tm_hour, current_date->tm_min);  
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
                printf ("请选择操作:");  
                scanf ("%d",&No); 
                if (No == 1)  
                {    
                   studentin(); 
                }  
                else if (No == 2)  
                {   
                   teacherin();   
                }  
                else if (No == 3)  
                {   
                   studentshow();
                }  
                else if (No == 4)  
                {    
                   teachershow(); 
                }  
                else if (No == 5)  
                {   
                   studentchange(); 
                }  
                else if (No == 6)  
                {  
                   teacherchange();
                }  
                else if (No == 7)  
                {  
                   gradecheck();
                } 
                else if (No == 0)  
                {  
                       //        退出程序   
                        break;  
                }  
                else  
                {   
                        printf("  请输入0-7的数字。\n\n");  
                }  
                system ("pause");        //按任意键继续   
                system ("cls");                //清屏   
        }    
        getchar();  
    }  
	else  
    {   
        printf("  用户名或密码错误\n\n");  
     }  
     system ("pause");        //按任意键继续   
     system ("cls");                //清屏   
    }    
        getchar();   
}}

//学生的教务系统功能
void show(char* sno)
{
      printf ("-----学生信息-----"); 
      printf ("学号：%s",sno);
      printf ("姓名：%s",sname);
      printf ("地址：%s",address);
      printf ("身份证号：%s",idcardnum);
      printf ("班级号：%d",classin);
      //根据sno访问数据库 S输出对应内容 
} 
void passwordchanges(char* sno)
{
     char[MAX] password;
     printf ("请输入新密码:");
     scanf ("%s",password);
     //用新密码替代数据库S中原密码 
}   
void showct(char* sno)
{
    //for(i=0,i<‘SC中该学生课程数’,i++)
     {
        printf ("-----课程信息-----"); 
        printf("课程号：%s  课程名：%s  教师名：%s  课程时间：%s",cno,cname,tname,ctime);
     } 
	//根据sno访问数据库 SC输出课程号，访问数据库C输出课程信息  按时间升序 
}  
void gradesearch(char* sno)
{
	printf ("-----课程信息-----"); 
     //for(i=0,i<‘SC中该学生课程数’,i++)
     {
     	if(check==1)
		{ 
        printf("课程号：%s  课程名：%s  成绩：%d",cno,cname,grade);
     }
    } 
   //根据sno访问数据库 SC输出课程号  输出成绩
} 
void currsearch(char* sno)
{
     //for(i=0,i<‘SC中课程数’,i++)
     {
        printf ("-----课程信息-----"); 
        printf("课程号：%s  课程名：%s  教师名：%s  课程时间：%s",cno,cname,tname,ctime);
     } 
	//根据sno访问数据库 SC输出课程号，访问数据库C输出课程信息  按时间升序
} 
void currselect(char* sno)
{
     char[MAX] cno;
     printf ("请输入你要选择的课程号:");
     scanf ("%s",cno);
     //并在SC中添加该学生 
} 
void currdelete(char* sno)
{
     char[MAX] cno;
     while(1)
     {
     printf ("请输入你要删除的课程号:");
     scanf ("%s",cno);
     if()
     {
         
          }//若该课程属于已选课程则删除，在SC中删除该学生 
     else 
     {   
         printf("  请输入已选课程的课程号\n\n");  
     } 
     } 
}   
 
//教师的教务系统功能
void showt(char* tno)
{
      printf ("-----教师信息-----"); 
      printf ("工号：%s",tno);
      printf ("姓名：%s",tname);
      printf ("地址：%s",address);
      printf ("身份证号：%s",idcardnum);
     //根据tno访问数据库 T输出对应内容 
}  
void passwordchanget(char* tno); 
{    char[MAX] password;
     printf ("请输入新密码:");
     scanf ("%s",password);
     //用新密码替代数据库T中原密码 
}  
void curradd(char* tno)
{
     char[MAX]  cno,cname,ctime;
     printf ("-----请输入新课程信息-----");
     printf ("课程号：");scanf ("%s",cno);
     printf ("课程名：");scanf ("%s",cname);
     printf ("课程时间：");scanf ("%s",ctime);
     //将新课程信息加入C 
}   
void showctt(char* tno)
{
     //for(i=0,i<‘C中该教师课程数’,i++)
     {
        printf ("-----课程信息-----"); 
        printf("课程号：%s  课程名：%s   课程时间：%s",cno,cname,ctime);
     } 
	  //根据tno访问数据库C输出课程信息 
} 
void gradein(char* tno)
{
     char[MAX]  cno;int grade; 
     printf ("-----请输入要录入成绩的课程号-----");
     printf ("课程号：");scanf ("%s",cno);
     //for(i=0,i<‘SC中该课程人数’,i++)
     {
        printf("请输入学号为%s的学生成绩：",！sno);scanf ("%d",&grade);
        //修改SC中该学生成绩 
     }   
}

//管理员的教务系统功能
void studentin() 
{
      char[MAX] sno,sname,address,idcardnum; 
      int classin;
      printf ("-----添加学生信息-----"); 
      printf ("学号：");scanf ("%s",sno);
      printf ("姓名：");scanf ("%s",sname);
      printf ("地址：");scanf ("%s",address);
      printf ("身份证号：");scanf ("%s",idcardnum);
      printf ("班级号：");scanf ("%d",classin);
      //数据库S添加一条 
} 
void teacherin()
{
     char[MAX] tno,tname,address,idcardnum; 
      printf ("-----添加教师信息-----"); 
      printf ("工号：");scanf ("%s",tno);
      printf ("姓名：");scanf ("%s",tname);
      printf ("地址：");scanf ("%s",address);
      printf ("身份证号：");scanf ("%s",idcardnum);
      //数据库T添加一条 
     }  
void studentshow()
{
     char[MAX] sno; 
     printf ("请输入要查询学生信息的学号：");scanf ("%s",sno);
     show(sno); 
}
void teachershow()
{
     char[MAX] tno; 
     printf ("请输入要查询教师信息的工号：");scanf ("%s",tno);
     showt(tno); 
}
void studentchange()
{
     char[MAX] sno; 
     printf ("请输入要修改学生信息的学号：");scanf ("%s",sno);
     char[MAX] sname,address,idcardnum; 
      int classin;
      printf ("-----修改学生信息-----"); 
      printf ("学号：");scanf ("%s",sno);
      printf ("姓名：");scanf ("%s",sname);
      printf ("地址：");scanf ("%s",address);
      printf ("身份证号：");scanf ("%s",idcardnum);
      printf ("班级号：");scanf ("%d",classin);
      //修改数据库S中sno对应信息 
}
void teacherchange()
{
      char[MAX] tno,tname,address,idcardnum; 
      printf ("-----修改教师信息-----"); 
      printf ("工号：");scanf ("%s",tno);
      printf ("姓名：");scanf ("%s",tname);
      printf ("地址：");scanf ("%s",address);
      printf ("身份证号：");scanf ("%s",idcardnum);
      //修改数据库T中tno对应信息 
} 
void gradecheck()
{
     int check; 
      //for(i=0,i<‘SC中数目’,i++)
     {
        if//如果成绩未被审核过，输出该课程成绩信息
        {
         printf("课程号：%s  课程名：%s  学号: %s  成绩：%d",cno,cname,sno,grade);         	
         printf ("输出审核结果：");scanf ("%d",check);//修改SC中check值 
        } 
     }                
     } 

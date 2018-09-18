#include <stdio.h>   
#include <math.h>   
#include <stdlib.h>
#include <time.h> 
#include <string.h>
#include <ctype.h>
#define MAX 20 
//定义文件名 
#define Student "Student"
#define Teacher "Teacher"
#define Course  "Course"
#define STUC "STUC"
//文件类型 
typedef struct  student0
{ 
 int classin;
 char sno[MAX],sname[MAX],address[MAX],idcardnum[MAX],password[MAX];  
}S0;
typedef struct  teacher0
{ 
 char tno[MAX],tname[MAX],address[MAX],idcardnum[MAX],password[MAX];  
}T0;
typedef struct  course0
{ 
 int check;
 char cno[MAX],cname[MAX],ctime[MAX],tno[MAX],tname[MAX];  
}C0;
typedef struct  studentC0
{ 
 int check,grade;
 char sno[MAX],cno[MAX],cname[MAX];  
}SC0;

//链表节点类型
typedef struct  student
{ 
 int classin;
 char sno[MAX],sname[MAX],address[MAX],idcardnum[MAX],password[MAX]; 
 struct student *next;  
}S;
typedef struct  teacher
{ 
 char tno[MAX],tname[MAX],address[MAX],idcardnum[MAX],password[MAX];
 struct teacher *next;  
}T;
typedef struct  course
{ 
 int check;
 char cno[MAX],cname[MAX],ctime[MAX],tno[MAX],tname[MAX];
 struct course *next;  
}C;
typedef struct  studentC
{ 
 int check,grade;
 char sno[MAX],cno[MAX],cname[MAX]; 
 struct studentC *next; 
}SC; 

//不同数据表
typedef S *S_LIST;//学生表
typedef T *T_LIST; //教师表
typedef C *C_LIST; //课程表
typedef SC *SC_LIST; //学生课程关系表

//不同人员的教务系统界面 
void student();
void teacher();
void manager();
//录入及存储信息 
S_LIST loads(void) //读取学生表 
{ 
 S_LIST p,q,head;  
 S0  per;  
 FILE *fp;  
 q = head = NULL;  
 if ((fp=fopen(Student,"rb")) == NULL)
 {  
  printf("Can not open file %s\n", Student);         
  return head; 
  }   
else  
 {  
  while (!feof(fp))     
  if(fread(&per,sizeof(S0),1,fp) == 1) 
  {   
    p = (S_LIST)malloc(sizeof(S));
	p->classin = per.classin;          
	strcpy(p->sname,per.sname);
	strcpy(p->sno,per.sno); 
	strcpy(p->address,per.address);
	strcpy(p->idcardnum,per.idcardnum);
	strcpy(p->password,per.password);   
	head = p;      
	p->next = q;      
	q = head;             
  }             
  fclose(fp);         
  return(head);      
  } 
}     /*end load*/ 

T_LIST loadt(void) //读取教师表 
{ 
 T_LIST p,q,head;  
 T0  per;  
 FILE *fp;  
 q = head = NULL;  
 if ((fp=fopen(Teacher,"rb")) == NULL)
 {  
  printf("Can not open file %s\n", Teacher);         
  return head; 
  }   
else  
 {  
  while (!feof(fp))     
  if(fread(&per,sizeof(T0),1,fp) == 1) 
  {   
    p = (T_LIST)malloc(sizeof(T));        
	strcpy(p->tname,per.tname);
	strcpy(p->tno,per.tno); 
	strcpy(p->address,per.address);
	strcpy(p->idcardnum,per.idcardnum);
	strcpy(p->password,per.password);   
	head = p;      
	p->next = q;      
	q = head;             
  }             
  fclose(fp);         
  return(head);      
  } 
}     /*end load*/
C_LIST loadc(void) //读取课程表 
{ 
 C_LIST p,q,head;  
 C0  per;  
 FILE *fp;  
 q = head = NULL;  
 if ((fp=fopen(Course,"rb")) == NULL)
 {  
  printf("Can not open file %s\n", Course);         
  return head; 
  }   
else  
 {  
  while (!feof(fp))     
  if(fread(&per,sizeof(C0),1,fp) == 1) 
  {   
    p = (C_LIST)malloc(sizeof(C)); 
	p->check=per.check;      
	strcpy(p->tname,per.tname);
	strcpy(p->tno,per.tno); 
	strcpy(p->ctime,per.ctime);
	strcpy(p->cno,per.cno);
	strcpy(p->cname,per.cname);   
	head = p;      
	p->next = q;      
	q = head;             
  }             
  fclose(fp);         
  return(head);      
  } 
}  

SC_LIST loadsc(void) //读取学生课程表  
{ 
 SC_LIST p,q,head;  
 SC0  per;  
 FILE *fp;  
 q = head = NULL;  
 if ((fp=fopen(STUC,"rb")) == NULL)
 {  
  printf("Can not open file %s\n",STUC);         
  return head; 
  }   
else  
 {  
  while (!feof(fp))     
  if(fread(&per,sizeof(SC0),1,fp) == 1) 
  {   
    p = (SC_LIST)malloc(sizeof(SC));
	p->check=per.check;  
	p->grade=per.grade;    
	strcpy(p->sno,per.sno); 
	strcpy(p->cno,per.cno);
	strcpy(p->cname,per.cname);   
	head = p;      
	p->next = q;      
	q = head;             
  }             
  fclose(fp);         
  return(head);      
  } 
}  

void saves(S_LIST head)//保存学生表 
 { 
  S_LIST s;  
  FILE *fp;  
  S0  ser;  
  if ((fp = fopen(Student,"wb")) == NULL)
  {  
   printf("Can not open file %s\n",Student);         
   return ;  
   } 
  else    
  { 
    s = head;   
	while(s != NULL)
	{   
	 ser.classin = s->classin;          
	 strcpy(ser.sname,s->sname);
	 strcpy(ser.sno,s->sno); 
	 strcpy(ser.address,s->address);
	 strcpy(ser.idcardnum,s->idcardnum);
  	 strcpy(ser.password,s->password);               
	  if(fwrite(&ser,sizeof(S0),1,fp) != 1)     
	  printf("File write error.\n");      
	   s = s->next;  
	    }  
	 fclose(fp);  
	 } 
	 }   
	 
void savet(T_LIST head)//保存教师表 
 { 
  T_LIST t;  
  FILE *fp;  
  T0  ter;  
  if ((fp = fopen(Teacher,"wb")) == NULL)
  {  
   printf("Can not open file %s\n",Teacher);         
   return ;  
   } 
  else    
  { 
    t = head;   
	while(t != NULL)
	{           
	 strcpy(ter.tname,t->tname);
	 strcpy(ter.tno,t->tno); 
	 strcpy(ter.address,t->address);
	 strcpy(ter.idcardnum,t->idcardnum);
  	 strcpy(ter.password,t->password);               
	  if(fwrite(&ter,sizeof(T0),1,fp) != 1)     
	  printf("File write error.\n");      
	   t = t->next;  
	    }  
	 fclose(fp);  
	 } 
}  
	 
void savec(C_LIST head)//保存课程表 
 { 
  C_LIST c;  
  FILE *fp;  
  C0  cer;  
  if ((fp = fopen(Course,"wb")) == NULL)
  {  
   printf("Can not open file %s\n",Course);         
   return ;  
   } 
  else    
  { 
    c = head;   
	while(c != NULL)
	{   
	 cer.check=c->check;      
	 strcpy(cer.tname,c->tname);
	 strcpy(cer.tno,c->tno); 
	 strcpy(cer.ctime,c->ctime);
	 strcpy(cer.cno,c->cno);
  	 strcpy(cer.cname,c->cname);               
	  if(fwrite(&cer,sizeof(C0),1,fp) != 1)     
	  printf("File write error.\n");      
	   c = c->next;  
	    }  
	 fclose(fp);  
	 } 
	 }   
void savesc(SC_LIST head)//保存学生课程表 
 { 
  SC_LIST sc;  
  FILE *fp;  
  SC0  scer;  
  if ((fp = fopen(STUC,"wb")) == NULL)
  {  
   printf("Can not open file %s\n",STUC);         
   return ;  
   } 
  else    
  { 
    sc = head;   
	while(sc != NULL)
	{   
	scer.check=sc->check; 
	scer.grade=sc->grade;     
	 strcpy(scer.cno,sc->cno); 
	 strcpy(scer.sno,sc->sno);
  	 strcpy(scer.cname,sc->cname);               
	  if(fwrite(&scer,sizeof(SC0),1,fp) != 1)     
	  printf("File write error.\n");      
	   sc = sc->next;  
	    }  
	 fclose(fp);  
	 } 
	 }  
	  
//学生的教务系统功能
void show(char* sno,S_LIST  p);
S_LIST passwordchanges(char* sno,S_LIST  heads);
void showct(char* sno,SC_LIST  p,C_LIST  headc);
void gradesearch(char* sno,SC_LIST  p);
void currsearch(C_LIST  headc);
SC_LIST currselect(char* sno,SC_LIST  p,C_LIST  q);
SC_LIST currdelete(char* sno,SC_LIST  head);    

//教师的教务系统功能
C_LIST curradd(char* tno,char* tname,C_LIST p);
SC_LIST gradein(char* tno,SC_LIST head,C_LIST p); 
void showctt(char* tno,C_LIST q);  
T_LIST passwordchanget(char* tno,T_LIST headt); 
T_LIST showt(char* tno,T_LIST p);

//管理员的教务系统功能
S_LIST studentchange(S_LIST heads);
T_LIST teacherchange(T_LIST headt);
SC_LIST gradecheck(SC_LIST head);
C_LIST currcheck(C_LIST head);
void studentshow(S_LIST heads);
void teachershow(T_LIST headt);
T_LIST teacherin(T_LIST headt);
S_LIST studentin(S_LIST heads);
                


int main(void)
{ 
   int No;
   while(1)  
        {  
            struct tm *current_date;
            time_t seconds;
            time(&seconds); 
            current_date = localtime(&seconds);//时间
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
            struct tm *current_date;
            time_t seconds;
            time(&seconds); 
            current_date = localtime(&seconds);//时间	
     int No,access=0;
     char sno[MAX],password[MAX];
	 S_LIST  heads,p; heads=loads();
	 SC_LIST  headsc; headsc= loadsc();
	 C_LIST  headc; headc= loadc();
			while(1){
			//登录界面   
                printf("\n");
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n");  
                printf ("┇                 教务系统登录                 ┇\n"); 
                printf ("┇                         %d-%d-%d %02d:%02d       ┇\n",current_date->tm_mon+1,current_date->tm_mday, current_date->tm_year,current_date->tm_hour, current_date->tm_min); 
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
                printf ("┇输入学号:");scanf ("%s",sno); 
		    	printf ("┇输入密码:");scanf ("%s",password);    
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
		   access=0;p=heads; 
		   while(p!= NULL)
           { 
           if(strcmp(p->sno,sno) ==0&&strcmp(p->password,password) ==0 )
            access=1; 
			p = p->next;
           } 
		   //密码正确 
           if(access==1)
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
                   show(sno,heads); 
                }  
                else if (No == 2)  
                {   
                   heads=passwordchanges(sno,heads); 
				   saves(heads);  
                }  
                else if (No == 3)  
                {   
                   showct(sno,headsc,headc);
                }  
                else if (No == 4)  
                {    
                   gradesearch(sno,headsc); 
                }  
                else if (No == 5)  
                {   
                   currsearch(headc); 
                }  
                else if (No == 6)  
                {  
                  headsc=currselect(sno,headsc,headc);
                  savesc(headsc);
                }  
                else if (No == 7)  
                {  
                  headsc=currdelete(sno,headsc);
                  savesc(headsc);
                } 
                else if (No == 0)  
                {  
                       //        退出程序   
                        return;  
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
            struct tm *current_date;
            time_t seconds;
            time(&seconds); 
            current_date = localtime(&seconds);//时间
			     int No,access=0;
     char tno[MAX],password[MAX],tname[MAX];
    T_LIST  headt,p; headt = loadt( );
    SC_LIST  headsc; headsc= loadsc( );
	C_LIST  headc; headc= loadc( );
			//登录界面 
			while(1){  
                printf("\n");
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n");  
                printf ("┇                 教务系统登录                 ┇\n"); 
                printf ("┇                         %d-%d-%d %02d:%02d       ┇\n",current_date->tm_mon+1,current_date->tm_mday, current_date->tm_year,current_date->tm_hour, current_date->tm_min); 
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
                printf ("┇输入工号:");scanf ("%s",tno); 
		    	printf ("┇输入密码:");scanf ("%s",password);    
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
           access=0;p=headt; 
		   while(p!= NULL)
           { 
           if(strcmp(p->tno,tno) ==0 &&strcmp(p->password,password) ==0 )
            {
			   access=1;
			   strcpy(tname,p->tname);
			} 
			p = p->next;
           } 
		   //密码正确 
           if(access==1)
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
                   showt(tno,headt); 
                }  
                else if (No == 2)  
                {   
                  headt=passwordchanget(tno,headt); 
				   savet(headt);   
                }  
                else if (No == 3)  
                {   
                   headc=curradd(tno,tname,headc);savec(headc);
                }  
                else if (No == 4)  
                {    
                   showctt(tno,headc); 
                }  
                else if (No == 5)  
                {   
                   headsc=gradein(tno,headsc,headc); savesc(headsc);
                }  
                else if (No == 0)  
                {  
                       //        退出程序   
                        return;  
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
            struct tm *current_date;
            time_t seconds;
            time(&seconds); 
            current_date = localtime(&seconds);//时间
     int No;
     char mno[MAX],password[MAX];
     T_LIST headt;headt=loadt();
     S_LIST heads;heads=loads();
     SC_LIST  headsc; headsc= loadsc( );
	 C_LIST  headc; headc= loadc( );
			//登录界面
			while(1){    
                printf("\n");
                printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n");  
                printf ("┇                 教务系统登录                 ┇\n"); 
                printf ("┇                         %d-%d-%d %02d:%02d       ┇\n",current_date->tm_mon+1,current_date->tm_mday, current_date->tm_year,current_date->tm_hour, current_date->tm_min); 
                printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
                printf ("┇输入登录号:");scanf ("%s",mno); 
		    	printf ("┇输入密码:");scanf ("%s",password);    
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
           //密码正确 
           if(strcmp(password,"000000")==0)
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
                printf ("┇  成绩审核_7           课程审核_8             ┇\n"); 
                printf ("┇                       退出_0                 ┇\n"); 
            	printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
				printf ("┇                         %d-%d-%d %02d:%02d       ┇\n",current_date->tm_mon+1,current_date->tm_mday, current_date->tm_year,current_date->tm_hour, current_date->tm_min);  
                printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
                printf ("请选择操作:");  
                scanf ("%d",&No); 
                if (No == 1)  
                {    
                   heads=studentin(heads);
				   saves(heads); 
                }  
                else if (No == 2)  
                {   
                   headt=teacherin(headt);
				   savet(headt);   
                }  
                else if (No == 3)  
                {   
                   studentshow(heads);
                }  
                else if (No == 4)  
                {    
                   teachershow(headt); 
                }  
                else if (No == 5)  
                {   
                   heads=studentchange(heads); 
                   saves(heads);
                }  
                else if (No == 6)  
                {  
                   headt=teacherchange(headt);
				   savet(headt);
                }  
                else if (No == 7)  
                {  
                   headsc=gradecheck(headsc);
                   savesc(headsc);
                } 
                else if (No == 8)  
                {  
                   headc=currcheck(headc);
                   savec(headc);
                } 
                else if (No == 0)  
                {  
                       //        退出程序   
                       return; 
                }  
                else  
                {   
                        printf("  请输入0-8的数字。\n\n");  
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


//学生的教务系统功能
void show(char* sno,S_LIST  p)
{
	 while(p!= NULL)
           { 
           if(strcmp(p->sno,sno)==0)
            {
            	printf ("-----学生信息-----\n"); 
                printf ("学号：%s\n",p->sno);
                printf ("姓名：%s\n",p->sname);
                printf ("地址：%s\n",p->address);
                printf ("身份证号：%s\n",p->idcardnum);
                printf ("班级号：%d\n",p->classin);
                printf ("密码：%s\n",p->password);
                        //根据sno访问数据库 S输出对应内容
			}
			p = p->next;
           } 
} 

S_LIST passwordchanges(char* sno,S_LIST  heads)
{
     S_LIST p=heads;
	 char password[MAX];
     printf ("请输入新密码:");
     scanf ("%s",password);
      while(p!= NULL)
           { 
           if(strcmp(p->sno,sno)==0)
            {
            	strcpy(p->password,password);
			}
			p = p->next;
           } 
      return heads;
     //用新密码替代数据库S中原密码 
}   
void showct(char* sno,SC_LIST  p,C_LIST  headc)
{
    C_LIST q;int flag=0;
	printf ("                           课程信息                               \n"); 
	printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┓\n"); 
	printf("┇课程号\t┇课程名\t┇教师名\t┇课程时间\t┇\n");
	printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┅ ┅ ┅ ┅ ┫\n");
	while(p!= NULL)
    { 
       if(strcmp(p->sno,sno)==0)
       {
       	q=headc;
       	while(q!= NULL)
        { 
         if(strcmp(q->cno,p->cno)==0)
            { 
			printf("┇%-6s\t┇%-6s\t┇%-6s\t┇%-10s\t┇\n",q->cno,q->cname,q->tname,q->ctime);
            flag=1; 
			} 
	   	q = q->next;
       }    
	   }
	 p = p->next;
    } //根据sno访问数据库 SC输出课程号，访问数据库C输出课程信息    
    if(flag!=1)   printf("\t还没有课程 快去选课叭~\n"); 
	printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┅ ┅ ┅ ┅ ┅ ┛\n"); 
}  

void gradesearch(char* sno,SC_LIST  p)
{
	int flag=0;
	printf ("                       成绩查询                             \n"); 
	printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n"); 
	printf("┇课程号\t┇课程名\t┇成绩\t\n");
	printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
     while(p!= NULL)
    { 
       if(strcmp(p->sno,sno)==0&&p->check==2)
         {
		 printf("┇%-6s\t┇%-6s\t┇%-10d\t\n",p->cno,p->cname,p->grade); flag=1; 
		 }  
	 p = p->next;
    }  //根据sno访问数据库 SC输出课程号  输出成绩
    if(flag!=1)   printf("\t暂无成绩 请耐心等待哦\n");
   	printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n"); 
} 
void currsearch(C_LIST  headc)
{
	int flag=0; 
	printf ("                           全部课程                               \n"); 
	printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┓\n"); 
	printf("┇课程号\t┇课程名\t┇教师名\t┇课程时间\t┇\n");
	printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┅ ┅ ┅ ┅ ┫\n");
   while(headc!=NULL)
     {
     	if(headc->check==1)
          {
		  printf("┇%-6s\t┇%-6s\t┇%-6s\t┇%-10s\t┇\n",headc->cno,headc->cname,headc->tname,headc->ctime);
          flag=1;
		}
		headc=headc->next;
     } //访问数据库C输出课程信息  
   if(flag==0)  printf ("\t\t暂无课程可选\n"); 
	printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
} 
SC_LIST currselect(char* sno,SC_LIST  p,C_LIST  q)
{
      SC_LIST SCC,sc,scer;int flag=0;
	  scer = p; SCC=p; 
      sc = (SC_LIST)malloc(sizeof(SC));
      char cno[MAX];
      printf ("\t请输入你要选择的课程号:");
      scanf ("%s",cno);fflush(stdin); //并在SC中添加该学生
      strcpy(sc->cno,cno);
      strcpy(sc->sno,sno);
      sc->check=0;
      while(SCC!= NULL)//在SC中查找该课程是否已选 
        { 
         if(strcmp(SCC->cno,cno)==0&&strcmp(SCC->sno,sno)==0)
            flag=2;
	   	SCC = SCC->next;
	   }
	if(flag!=2) 
    {  while(q!= NULL)//在C中查找该课程名 
        { 
         if(strcmp(q->cno,cno)==0&&q->check==1)
           {
			   strcpy(sc->cname,q->cname);flag=1;}
	   	q = q->next;
	   }
	 if(flag!=1)  printf ("\t\t选课失败！不存在此课程\n");   
	 else         
	 {
	  printf ("\t\t选课成功~ o(*￣▽￣*)ブ\n"); 
      p = sc;  
      sc->next = scer;} 
   }
   else printf ("\t\t选课失败！此课程已选过\n"); 
      return p;	
} 

SC_LIST currdelete(char* sno,SC_LIST  head)
{
     char cno[MAX];
     int flag;
     printf ("\t请输入你要删除的课程号:");
     scanf ("%s",cno);
     SC_LIST p,q;
	 p=q=head;
	 while(p != NULL) 
     { 
     if (strcmp(p->sno,sno) ==0 &&strcmp(p->cno,cno) ==0 ) 
	  {   
	    if (head == p)
	    head = p->next;
	    else
	    q->next = p->next;
	    free(p);   
         p = q->next;  
        flag = 1; 
    } 
    else 
    {
      q = p;p = p->next;
    } 
   }  
if (flag == 0)  printf("\t\t请输入已选课程的课程号\n\n");
else       printf ("\t\t撤课成功~ o(*￣▽￣*)ブ\n\n");   
return head;

}
   

T_LIST showt(char* tno,T_LIST p)
{
	while(p!= NULL)
           { 
           if(strcmp(p->tno,tno)==0)
            {
                printf ("\n-----教师信息-----\n"); 
                printf ("工号：%s\n",p->tno);
                printf ("姓名：%s\n",p->tname);
                printf ("地址：%s\n",p->address);
                printf ("身份证号：%s\n",p->idcardnum);
                printf ("密码：%s\n\n",p->password);
     //根据tno访问数据库 T输出对应内容 
			}
			p = p->next;
           } 
      
}

T_LIST passwordchanget(char* tno,T_LIST headt)
{   
     T_LIST p=headt;
	 char password[MAX];
     printf ("\t请输入新密码:");
     scanf ("%s",password);
      while(p!= NULL)
           { 
           if(strcmp(p->tno,tno)==0)
            {
            	strcpy(p->password,password);
			}
			p = p->next;
           } 
      return headt;//用新密码替代数据库T中原密码 
}
C_LIST curradd(char* tno,char* tname,C_LIST p)
{
	  C_LIST c,cer;
	  cer = p;  
      c = (C_LIST)malloc(sizeof(C));
      strcpy(c->tno,tno);    
	  strcpy(c->tname,tname);
	  c->check=0;  
	  printf ("\n-----请输入新课程信息-----\n");
      printf ("课程号：");scanf ("%s",c->cno);fflush(stdin);
      printf ("课程名：");scanf ("%s",c->cname);fflush(stdin);
      printf ("课程时间：");scanf ("%s",c->ctime);fflush(stdin);
	  p = c;  
      c->next = cer;  
      return p; 
//将新课程信息加入C 
} 
 
void showctt(char* tno,C_LIST q)
{
    int flag=0; 
	printf ("                   课程信息                     \n"); 
	printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┓\n"); 
	printf("┇课程号\t┇课程名\t┇课程时间\t┇\n");
	printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
    while(q!= NULL)
    { 
        if(strcmp(q->tno,tno)==0)
         {
			   printf("┇%-6s\t┇%-6s\t┇%-10s\t┇\n",q->cno,q->cname,q->ctime);flag=1;
	   	}
		   q = q->next;
       } 
    if(flag==0)    printf("\t暂无课程 快去创建新课程叭~\n"); 
	printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");     
} 

SC_LIST gradein(char* tno,SC_LIST head,C_LIST p)
{
     SC_LIST q=head;int flag=0; 
	 char cno[MAX];   
     printf ("\n-----请选择要录入成绩的课程号-----\n");
     printf ("课程号：");scanf ("%s",cno);
     while(p!= NULL)
    { 
        if(strcmp(p->tno,tno)==0&&strcmp(p->cno,cno)==0)
         {
			 flag=1;
	   	}
		   p = p->next;
       }
    if(flag==1) 
    {
	  while(q!= NULL)
     { 
        if(strcmp(q->cno,cno)==0)
          {
          	printf("\t请输入学号为%s的学生成绩：",q->sno);scanf ("%d",&q->grade);
          	q->check=1;flag=2; 
		   } 
	   	q = q->next;
       }
       if(flag!=2)   printf("\t\t该课程暂无选课学生\n");
	    
   }
   else printf ("\t请检查输入的课程号是否正确\n"); 
     return head; 
}

//管理员的教务系统功能

S_LIST studentin(S_LIST heads) 
{
	  S_LIST s,ser;
	  ser = heads;  
      s = (S_LIST)malloc(sizeof(S));
      printf ("\n-----添加学生信息-----\n"); 
      printf ("学号：");scanf ("%s",s->sno);fflush(stdin);
      printf ("姓名：");scanf ("%s",s->sname);fflush(stdin);
      printf ("地址：");scanf ("%s",s->address);fflush(stdin);
      printf ("身份证号：");scanf ("%s",s->idcardnum);fflush(stdin);
      printf ("班级号：");scanf ("%d",&s->classin);fflush(stdin);
      printf ("密码：");scanf ("%s",s->password);fflush(stdin);
      heads = s;  
      s->next = ser;  
}

T_LIST teacherin(T_LIST headt)
{
      T_LIST t,ter;
	  ter = headt;  
      t = (T_LIST)malloc(sizeof(T));
      printf ("\n-----添加教师信息-----\n"); fflush(stdin);
      printf ("工号：");scanf ("%s",t->tno);fflush(stdin);
      printf ("姓名：");scanf ("%s",t->tname);fflush(stdin);
      printf ("地址：");scanf ("%s",t->address);fflush(stdin);
      printf ("身份证号：");scanf ("%s",t->idcardnum);fflush(stdin);
      printf ("密码：");scanf ("%s",t->password);fflush(stdin);
      headt = t;  
      t->next = ter;  
      return headt;
      //数据库T添加一条 
     }  

void studentshow(S_LIST heads)
{
     char sno[MAX]; 
     printf ("\t请输入要查询学生信息的学号：");scanf ("%s",sno);
     show(sno,heads); 
}
void teachershow(T_LIST headt)
{
     char tno[MAX]; 
     printf ("\t请输入要查询教师信息的工号：");scanf ("%s",tno);
     showt(tno,headt); 
}

S_LIST studentchange(S_LIST heads)
{
      S_LIST s,p,q;
      p=q=heads;
      s = (S_LIST)malloc(sizeof(S));
      printf ("\n-----修改学生信息-----\n"); fflush(stdin);
      printf ("学号：");scanf ("%s",s->sno);fflush(stdin);
      printf ("姓名：");scanf ("%s",s->sname);fflush(stdin);
      printf ("地址：");scanf ("%s",s->address);fflush(stdin);
      printf ("身份证号：");scanf ("%s",s->idcardnum);fflush(stdin);
      printf ("班级号：");scanf ("%d",&s->classin);fflush(stdin);
      printf ("密码：");scanf ("%s",s->password);fflush(stdin);
      while(p != NULL)
        { 
          if(strcmp(s->sno,p->sno) == 0)
            {
            	s->next=p->next; 
            	if (heads == p)
	               heads = s;
	            else
	               q->next = s;
	            free(p);
			} 
		  else 
           {
              q = p;
              p = p->next;
           }
       
}
return heads; 
}//修改数据库S中sno对应信息

T_LIST teacherchange(T_LIST headt)
{
	  T_LIST t,p,q;
      p=q=headt;
      t = (T_LIST)malloc(sizeof(T));
      printf ("\n-----修改教师信息-----\n"); fflush(stdin);
      printf ("工号：");scanf ("%s",t->tno);fflush(stdin);
      printf ("姓名：");scanf ("%s",t->tname);fflush(stdin);
      printf ("地址：");scanf ("%s",t->address);fflush(stdin);
      printf ("身份证号：");scanf ("%s",t->idcardnum);fflush(stdin);
      printf ("密码：");scanf ("%s",t->password);fflush(stdin);
      while(p != NULL)
        { 
          if(strcmp(t->tno,p->tno) == 0)
            {
            	t->next=p->next; 
            	if (headt == p)
	               headt = t;
	            else
	               q->next = t;
	            free(p);
			} 
		  else 
           {
              q = p;
              p = p->next;
           }
       }
      return headt; 
      //修改数据库T中tno对应信息 
} 

C_LIST currcheck(C_LIST head)
{
    C_LIST p=head;int flag=0;
	printf ("                           课程审核                              \n"); 
	printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┓\n"); 
	printf("┇课程号\t┇课程名\t┇教工号\t┇课程时间\t┇\n");
	printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
        while(p!=NULL)
     {
        if(p->check==0)
        {
         printf("┇%-6s\t┇%-6s\t┇%-6s\t┇%-10s\t┇",p->cno,p->cname,p->tno,p->ctime);         	
         printf ("输出审核结果：[1通过 0不通过]");scanf ("%d",&p->check);//修改SC中check值 
        flag=1; 
		} 
        p=p->next;
     }    
	if(flag==0)    printf ("                      无待审核课程                   \n");                   
	printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n");  
    return head;           
     } 
SC_LIST gradecheck(SC_LIST head)
{
     SC_LIST p=head; 
    int flag=0;
    printf ("                           课程审核                              \n"); 
	printf ("┏ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┓\n"); 
	printf("┇课程号\t┇课程名\t┇学号\t┇成绩\t┇\n");
	printf ("┣ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┅ ┅ ┅ ┅ ┅ ┫\n");
        while(p!=NULL)
     {
        if(p->check==1)
        {
         printf("┇%-6s\t┇%-6s\t┇%-6s\t┇%-10d\t┇",p->cno,p->cname,p->sno,p->grade);         	
         printf ("输出审核结果：[2通过 0不通过]");scanf ("%d",&p->check);//修改SC中check值 
         flag=1;
        } 
        p=p->next;
     }
	 if(flag==0)    printf ("                      无待审核课程                   \n");                   
	printf ("┗ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┅  ┅ ┅ ┅ ┅ ┅ ┅ ┅ ┛\n"); 
    return head;           
 } 
     
     

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>
#define M 30
#define N 7

typedef struct student /*定义学生的所有信息的结构变量*/
{
int studentID;/*学号*/
char studentname[10];/*姓名*/
float score[7];
int sum;
float aver;
}STU;

STU stu1[30];

typedef struct afterstudent /*定义学生的所有信息的结构变量*/
{
int studentID;/*学号*/
char studentname[10];/*姓名*/
int score[4];/*4科成绩（可以更改）*/
double totalscore;
double average;
}afterSTU;

void menu();/*菜单*/
void fun (int numb,STU stu1[30],int i,int j);/*对目录的详细操作*/
void gun (int numb,STU stu1[30],int i,int j);/*对非法输入的修改*/
void luruxinxi (STU stu1[30],int numb,int i,int j);/*录入学生信息的两种方式*/
void ReadfromFile(STU stu1[30],int i,int j);/*从文件中读取学生的信息到结构体数组stu1中*/
void Inputscore (STU stu1[30],int y,int x);/*从键盘输入N个学生的学号姓名以及四门学科成绩到结构数组stu1中*/
void research(STU stu1[30],int i,int j);/*重复查询。*/
void kechengfen (int numb,STU stu1[30],int i,int j);/*计算每门课程的总分和平均分。*/
void studentzongfen (int numb,STU stu1[30],int i,int j); /*计算每个学生的总分和平均分。*/
void hightolow (int numb,STU stu1[30],int i,int j);/*按每个学生的总分由高到低排出名次表。*/
void lowtohigh (int numb,STU stu1[30],int i,int j);/*按每个学生的总分由低到高排出名次表。*/
void xhhightolow (int numb,STU stu1[30],int k,int t);/*按学号由大到小排出成绩表。*/
void zidianpaixu (int numb,STU stu1[30],int p,int q);/*按姓名的字典顺序排出成绩表。*/
void xuehao(int numb,STU stu1[30],int i,int j);/*按学号查询学生排名及其考试成绩。*/
void name (int numb,STU stu1[30],int i,int j);/*按姓名查询学生排名及其考试成绩。*/
void baifenbi (int numb,STU stu1[30],int p,int q); /*按优秀、良好、中等、及格、不及格5个类别，对每门课程分别统计每个类别分人数以及所占百分比。*/
void output (STU stu1[30],int i,int j);/*输出每个学生的学号、姓名、各科成绩，以及每门课程的总分和平均分。*/
void readtofile (STU stu1[30],int i,int j);/*将每个学生的记录信息写入文件。*/
void readed (STU stu1[30],int i,int j);/*从文件中读出每个学生的记录并显示。*/

    /*-------------------------------------------------------------主函数------------------------------------------------------*/
int main()
{
    int numb,ren,kemu;

    //ReadfromFile(stu1);
    menu ();
    //printf("请录入三个学生的学号、姓名和各科考试成绩。(按0结束)\n");/*读取文件时该应该省略*/
    //Inputscore(stu1);
    printf ("请先输入学生数，科目数。\n");
    scanf("%d%d",&ren,&kemu);
    printf ("开始查询，请输入：\n");
    printf ("请先执行菜单一，进行信息录入！！！\n");
    scanf("%d",&numb);/*搜索查询*/
    if (numb>=1&&numb<=13)
    {
       fun(numb,stu1,ren,kemu);
    }
    else if (numb==0);
    else
    {
       gun(numb,stu1,ren,kemu);
    }

    return 0;
}

/*-------------------------------------------------------------主函数------------------------------------------------------*/

void menu()/*菜单*/
{
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("**   学生成绩管理系统主菜单（请输入序号进行查询）。    **\n");
    printf("**                                                     **\n");
    printf("**   00.结束程序。                                     **\n");
    printf("**                                                     **\n");
    printf("**   01.录入每个学生的学号、姓名、各科考试成绩。       **\n");
    printf("**                                                     **\n");
    printf("**   02.计算每门课程的总分和平均分。                   **\n");
    printf("**                                                     **\n");
    printf("**   03.计算每个学生的总分和平均分。                   **\n");
    printf("**                                                     **\n");
    printf("**   04.按每个学生的总分由高到低排出名次表。           **\n");
    printf("**                                                     **\n");
    printf("**   05.按每个学生的总分由低到高排出名次表。           **\n");
    printf("**                                                     **\n");
    printf("**   06.按学号由大到小排出成绩表。                     **\n");
    printf("**                                                     **\n");
    printf("**   07.按姓名的字典顺序排出成绩表。                   **\n");
    printf("**                                                     **\n");
    printf("**   08.按学号查询学生排名及其考试成绩。               **\n");
    printf("**                                                     **\n");
    printf("**   09.按姓名查询学生排名及其考试成绩。               **\n");
    printf("**                                                     **\n");
    printf("**   10.按优秀、良好、中等、及格、不及格5个类别，      **\n");
    printf("**     对每门课程分别统计每个类别分人数以及所占百分比。**\n");
    printf("**   11.输出每个学生的学号、姓名、各科成绩，           **\n");
    printf("**     以及每门课程的总分和平均分。                    **\n");
    printf("**   12.将每个学生的记录信息写入文件。                 **\n");
    printf("**                                                     **\n");
    printf("**   13.从文件中读出每个学生的记录并显示。             **\n");
    printf("**                                                     **\n");
    printf("*********************************************************\n");
    printf("**********************黄树勤*****************************\n");
    printf("*********************************************************\n");


}

void fun (int numb,STU stu1[30],int i,int j)/*对目录的详细操作*/
{
    if (numb==1)/*录入每个学生的学号、姓名、各科考试成绩。*/
    {
      luruxinxi (stu1,numb,i,j);
      research(stu1,i,j);
    }

    else if (numb==2)
    {
      kechengfen (numb,stu1,i,j);    /*计算每门课程的总分和平均分。*/
      research(stu1,i,j);
    }
    else if (numb==3)
    {
      studentzongfen (numb,stu1,i,j); /*计算每个学生的总分和平均分。*/
      research(stu1,i,j);
    }
    else if (numb==4)
    {
      hightolow (numb,stu1,i,j);/*菜单4  按每个学生的总分由高到低排出名次表。 */
      research(stu1,i,j);
    }
    else if (numb==5)
    {
      lowtohigh (numb,stu1,i,j);/*菜单5  按每个学生的总分由低到高排出名次表。 */
      research(stu1,i,j);
    }
    else if (numb==6)
    {
      xhhightolow (numb,stu1,i,j);/*菜单6  按学号由大到小排出成绩表。 */
      research(stu1,i,j);
    }
    else if (numb==7)
    {
      zidianpaixu (numb,stu1,i,j);/*菜单7  按姓名的字典顺序排出成绩表。*/
      research(stu1,i,j);
    }
    else if (numb==8)
    {
      xuehao(numb,stu1,i,j);/*菜单8   按学号查询学生排名及其考试成绩。*/
      research(stu1,i,j);
    }
    else if (numb==9)/*学号查询*/
    {
      name (numb,stu1,i,j);/*菜单9   按姓名查询学生排名及其考试成绩。*/
      research(stu1,i,j);
    }
    else if (numb==10)
    {
      baifenbi (numb,stu1,i,j); /*菜单10   按优秀、良好、中等、及格、不及格5个类别，对每门课程分别统计每个类别分人数以及所占百分比。*/
      research(stu1,i,j);
    }
    else if (numb==11) /*菜单11  输出每个学生的学号、姓名、各科成绩，以及每门课程的总分和平均分。*/
    {
        output (stu1,i,j);
        research(stu1,i,j);
    }
    else if (numb==12)/*菜单12  将每个学生的记录信息写入文件。*/
    {
         readtofile (stu1,i,j);
         research(stu1,i,j);
    }
    else if (numb==13)/*菜单13   从文件中读出每个学生的记录并显示。 */
    {

         research(stu1,i,j);
    }
}

void gun (int numb,STU stu1[30],int i,int j)/*对非法输入的修改*/
{
 int numb1;
 printf("您输入的数字不正确。\n");
 //system("color 04");
 printf("请重新输入。\n");
 system("color 04");
 scanf("%d",&numb1);
 system("color 07");
 if (numb1>=1&&numb1<=13)
    {
       fun(numb1,stu1,i,j);
    }
    else
    {
       gun(numb1,stu1,i,j);
    }

}


void Inputscore(STU stu1[],int y,int x)/*从键盘输入N个学生的学号姓名以及四门学科成绩到结构数组stu1中*/
{
    int i,j;
        printf("学号\t姓名\t");
    for(i=0; i<x; i++)
    {
        printf("科目%d\t",i+1);
    }
        printf("\n");
    for(i=0;i<y;i++)
    {

        scanf("%d",&stu1[i].studentID);
        scanf("%s",stu1[i].studentname);
        for(j=0;j<x;j++)
        {
            scanf("%f",&stu1[i].score[j]);
        }
    }
    for(i=0; i<y; i++)
    {
        stu1[i].sum=0;
        for(j=0; j<x; j++)
        {
            stu1[i].sum+=stu1[i].score[j];
        }
        stu1[i].aver=(float)stu1[i].sum/x;
    }

    printf("信息录入成功!\n");
    system("color 06");
}

void kechengfen (int numb,STU stu1[30],int i,int j)/*菜单2   计算每门课程的总分和平均分。*/
{
    int k,t;
    float s[7];
    printf ("菜单2   计算每门课程的总分和平均分:\n");
    for (k=0;k<j;k++)
    {
        s[k]=0;
        for (t=0;t<i;t++)
        s[k]=s[k]+stu1[t].score[k];
    }
    printf ("      每门课程的总分分别为：\n");
    for (k=0;k<j;k++)
        printf ("      %f   ",s[k]);
    printf ("\n");
    printf ("      每门课程的平均分分别为：\n");
    for (k=0;k<j;k++)
        printf ("      %.2lf   ",s[k]/i);
    printf ("\n");
}

void studentzongfen (int numb,STU stu1[30],int i,int j) /*菜单3   计算每个学生的总分和平均分。*/
{
double s[N]={0};
int k,t;
printf ("菜单3   计算每个学生的总分和平均分:\n");
for (k=0;k<i;k++)
    for (t=0;t<j;t++)
{
   s[k]=s[k]+stu1[k].score[t];
}
for (k=0;k<i;k++)
{
    printf ("      学生的姓名  总分   平均分：\n");
    printf ("    %s    ",stu1[k].studentname);
    printf ("   %.lf     %.2lf\n",s[k],s[k]/j);
}

}

void hightolow (int numb,STU stu1[30],int i,int j)/*菜单4  按每个学生的总分由高到低排出名次表。 */
{
int sum[30];
int b;
int k,t,r;
printf ("菜单4  按每个学生的总分由高到低排出名次表:\n");
for (k=0;k<i;k++)
{
    sum[k]=stu1[k].sum;
}
for (k=0;k<i-1;k++)
{
    for (t=k+1;t<i;t++)
    {
         if (sum[k]<sum[t])
        {
        b=sum[k];
        sum[k]=sum[t];
        sum[t]=b;
        }
    }
}
   //printf ("%d,%d\n",sum[0],sum[1]);
for (k=0,t=0;t<i;)
{
    if(sum[t]==stu1[k].sum)
    {
        printf ("      %d   ",stu1[k].studentID);
        printf ("   %s   ",stu1[k].studentname);
        for (r=0;r<j;r++)
        {
            printf ("  %f  ",stu1[k].score[r]);
        }
            printf ("\n");
        t++;
        k=0;
    }
    else
        k++;
}
}

void lowtohigh (int numb,STU stu1[30],int i,int j)/*菜单5  按每个学生的总分由低到高排出名次表。 */
{
int sum[30];
int b;
printf ("菜单5  按每个学生的总分由低到高排出名次表:\n");
int k,t,r;
for (k=0;k<i;k++)
{
    sum[k]=stu1[k].sum;
}
for (k=0;k<i-1;k++)
{
    for (t=k+1;t<i;t++)
    {
         if (sum[k]>sum[t])
        {
        b=sum[k];
        sum[k]=sum[t];
        sum[t]=b;
        }
    }
}
   //printf ("%d,%d\n",sum[0],sum[1]);
for (k=0,t=0;t<i;)
{
    if(sum[t]==stu1[k].sum)
    {
        printf ("       %d   ",stu1[k].studentID);
        printf ("   %s   ",stu1[k].studentname);
        for (r=0;r<j;r++)
        {
            printf ("  %f  ",stu1[k].score[r]);
        }
            printf ("\n");
        t++;
        k=0;
    }
    else
        k++;
}
}

void xhhightolow (int numb,STU stu1[30],int k,int t)/*菜单6  按学号由大到小排出成绩表。 */
{
 int i,j,b[9],r;
 printf ("菜单6  按学号由大到小排出成绩表:\n");
 for (i=0;i<k;i++)
{
    b[i]=stu1[i].studentID;
}
//printf ("  %f  ",stu1[0].score[0]);
for (i=0;i<k-1;i++)
{
    for (j=i+1;j<k;j++)
    {
         if (b[i]<b[j])
        {
        r=b[i];
        b[i]=b[j];
        b[j]=r;
        }
    }
}
//printf ("  %f  ",stu1[0].score[0]);
//printf ("%d %d\n",b[0],b[1]);
 for (i=0,j=0;j<k;)
{
    if(b[j]==stu1[i].studentID)
    {
        printf ("       %d   ",stu1[i].studentID);
        printf ("   %s   ",stu1[i].studentname);
        for (r=0;r<t;r++)
        {
            printf ("  %f  ",stu1[i].score[r]);
        }
            printf ("\n");
        j++;
        i=0;
    }
    else
        i++;
}
}

void zidianpaixu (int numb,STU stu1[30],int p,int q)/*菜单7  按姓名的字典顺序排出成绩表。*/
{
  int i,j,a,n,r;
  float b[4];
  int x,y,k;
  printf ("菜单7  按姓名的字典顺序排出成绩表:\n");
  char c[10];
  //char t[30]={'\0'};
  for (i=0;i-1<p;i++)
    for (j=i+1;j<p;j++)
  {
       x=strlen(stu1[i].studentname);
       y=strlen(stu1[j].studentname);
       if (x<=y)
        k=x;
       else
        k=y;
       n=strncmp (stu1[i].studentname,stu1[j].studentname,k);/*K值是比较字符串不多于k个字符,覆盖型名字*/
       if (n>0)
       {
           a=stu1[i].studentID;
         strcpy(c,stu1[i].studentname);
         for (r=0;r<q;r++)
         {
             b[r]=stu1[i].score[r];
         }


        stu1[i].studentID=stu1[j].studentID;
        strcpy(stu1[i].studentname,stu1[j].studentname);
        for (r=0;r<q;r++)
        {
            stu1[i].score[r]=stu1[j].score[r];
        }


        stu1[j].studentID=a;
        strcpy(stu1[j].studentname,c);
         for (r=0;r<q;r++)
         {
             stu1[j].score[r]=b[r];
         }

       }
  }
  for (i=0;i<p;i++)
  {
      printf ("     %d ",stu1[i].studentID);
      printf (" %s ",stu1[i].studentname);
      for (j=0;j<q;j++)
        {
            printf (" %f ",stu1[i].score[j]);
        }
      printf ("\n");
  }

}

void xuehao(int numb,STU stu1[30],int i,int j)/*菜单8   按学号查询学生排名及其考试成绩。*/
{
int numb2,r,t=0;
printf ("菜单8   按学号查询学生排名及其考试成绩:\n");
printf("     请输入学生的学号进行查询\n");
scanf("%d",&numb2);
for(r=0;r<i;r++)
    if (numb2==stu1[r].studentID)
{
    printf ("      %d  ",stu1[r].studentID);
    printf ("  %s  ",stu1[r].studentname);
    for (t=0;t<j;t++)
    {
      printf ("  %f  ",stu1[r].score[t]);
    }
    printf ("\n");
    //printf("%d%s%d%d%d%d",&stu1[r].studentID,&stu1[r].studentname,&stu1[r].score[0],&stu1[r].score[1],&stu1[r].score[3],&stu1[r].score[4]);
    break;
    t=100;
}
    if (t==0)
        {
            printf("你输入的学号不存在！！！请确认下是否有误：\n");
            system("color 04");
        }
}

void name (int numb,STU stu1[30],int i,int j)/*菜单9   按姓名查询学生排名及其考试成绩。*/
{
char mingzi[10];
int r,t=0;
printf ("菜单9   按姓名查询学生排名及其考试成绩:\n");
printf("      请输入学生姓名进行查询\n");
scanf("%s",mingzi);
//printf ("%s",mingzi);
for (r=0;r<i;r++)
if (strcmp(mingzi,stu1[r].studentname)==0)
{
    printf ("     %d  ",stu1[r].studentID);
    printf ("  %s  ",stu1[r].studentname);
    for (t=0;t<j;t++)
    {
      printf ("  %f  ",stu1[r].score[t]);
    }
    printf ("\n");
    //printf("%d%s%d%d%d%d",&stu1[r].studentID,&stu1[r].studentname,&stu1[r].score[0],&stu1[r].score[1],&stu1[r].score[3],&stu1[r].score[4]);
    break;
}
if (t==0)
        {
            printf("你输入的姓名不存在！！！请确认下是否有误：\n");
            system("color 04");
        }
}

void baifenbi (int numb,STU stu1[30],int p,int q) /*菜单10  按优秀、良好、中等、及格、不及格5个类别，对每门课程分别统计每个类别分人数以及所占百分比。*/
{
  int i,j,a[5]={0},k;
  double b[5]={0};
  printf ("菜单10  按优秀、良好、中等、及格、不及格5个类别，对每门课程分别统计每个类别分人数以及所占百分比:\n");
  for (j=0;j<q;j++)
  {
      a[0]=0;a[1]=0;a[2]=0;a[3]=0;a[4]=0;
      for (i=0;i<p;i++)
      {
          if (stu1[i].score[j]>=90)
               a[0]++;
          else if (stu1[i].score[j]>=80)
          {
               a[1]=a[1]+1;
          }
          else if (stu1[i].score[j]>=70)
           {
               a[2]=a[2]+1;
          }
          else if (stu1[i].score[j]>=60)
           {
               a[3]=a[3]+1;
          }
          else
           {
               a[4]=a[4]+1;
          }

      }
      //a[1]=a[1]+a[0];
      //a[2]=a[2]+a[1];
      a[3]=a[3]+a[2]+a[1]+a[0];
      for (k=0;k<5;k++)
        b[k]=(float)a[k]/p;
      printf ("     课程  优秀人数 百分比 良好人数 百分比 中等人数 百分比 及格总人数 百分比 不及格人数 百分比\n");
      printf ("      %d      %d       %.2lf     %d      %.2lf      %d     %.2lf    %d        %.2lf      %d      %2lf\n",j+1,a[0],b[0],a[1],b[1],a[2],b[2],a[3],b[3],a[4],b[4]);

  }
}

void output (STU stu1[30],int x,int y)/*菜单11  输出每个学生的学号、姓名、各科成绩，以及每门课程的总分和平均分。*/
{
int i,j;
    printf("名次\t学号\t  姓名\t");
    for(i=1; i<=y; i++)
    {
        printf("\t科目%d\t",i);
    }
    printf("\t平均分\t\t总分\t\n");
    for(i=0; i<x; i++)
    {
        printf("%-d\t",i+1);
        printf("%-d\t %-1s\t",stu1[i].studentID,stu1[i].studentname);
        for(j=0; j<y; j++)
        {
            printf("\t%-1.2f\t",stu1[i].score[j]);
        }
        printf("\t%-1.2f\t\t%-d\n",stu1[i].aver,stu1[i].sum);
    }
}

void readtofile (STU stu1[30],int n,int m)/*菜单12  将每个学生的记录信息写入文件。*/
{
FILE *fp;
    int i,j;
    if((fp=fopen("student.txt","w"))==NULL)
    {
        printf("打开失败！\n");
        exit(0);
    }
    //fprintf(fp,"学生人数: ");
    fprintf(fp,"%d%d",n,m);
    fprintf(fp,"序号\t学号\t\t姓名\t\t");
    for(i=1; i<=m; i++)
    {
        fprintf(fp,"科目%d\t\t",i);
    }
    fprintf(fp,"平均分\t\t总分\t\n");
    for(i=0; i<n; i++)
    {
        fprintf(fp,"%-d\t",i+1);
        fprintf(fp,"%-d\t%-1s\t",stu1[i].studentID,stu1[i].studentname);
        for(j=0; j<m; j++)
        {
            fprintf(fp,"%-1.2f\t\t",stu1[i].score[j]);
        }
        fprintf(fp,"%-1.2f\t\t-%d\n",stu1[i].aver,stu1[i].sum);
    }
    fclose(fp);
    printf ("记入文件成功！！！\n");
}

void readed (STU stu1[30],int i,int j)/*菜单13  从文件中读出每个学生的记录并显示。*/
{
   printf("此选项有待升级，敬请期待!!!\n");
}

void ReadfromFile(STU stu1[30],int i,int j)/*从文件中读取学生的信息到结构体数组stu1中*/
{
    int k;
    FILE *fp;
    if ((fp=fopen("test1.txt","r"))==NULL)/*以读的方式打开文本文件*/
    {
        printf("Failure to open test1.txt!\n");
        exit(0);
    }
    for (k=0;!feof(fp);k++)
    {
        fread(&stu1[k],sizeof(STU),1,fp);
    }
    printf("信息录入成功!\n");
    system("color 06");
    fclose(fp);
}

void research(STU stu1[30],int i,int j)/*重复查询*/
{
    int numb;
    printf ("是否继续查询。是请按1，否请按任意键退出程序。\n");
    scanf("%d",&numb);
    if (numb==1)
    {
        system("cls");
        system("color 07");
        menu();
        printf ("开始查询，请输入：\n");
        scanf("%d",&numb);
        if (numb>=1&&numb<=13)
        {
          fun(numb,stu1,i,j);
        }
        else
        {
          gun(numb,stu1,i,j);
        }


    }
    else
        exit(0);
}

void luruxinxi (STU stu1[],int numb,int i,int j)/*录入每个学生的学号、姓名、各科考试成绩。*/
{
    int n;
    printf ("按1进行手动录入，按2进行文件录入。\n");
    scanf ("%d",&n);
    //printf ("kaishi.\n");
    if (n==1)
    {
        Inputscore (stu1,i,j);
    }
    else if (n==2)
    {
        ReadfromFile(stu1,i,j);
    }
    else if (n==0)
        exit (0);
    else
    {
        printf ("您的输入有误，请重新输入。\n");
        system("color 04");
        luruxinxi(stu1,n,i,j);
    }

}

void swap(STU stu1[30],afterSTU stu2[30],int k,int t)/*实现学生 总分 平均分的统计*/
{
  int i,r,s;
  for (i=0;i<k;i++)
    {
    stu2[i].studentID=stu1[i].studentID;
    for (r=0;r<t;r++)
    {
      stu2[i].score[r]=stu1[i].score[r];
    }
    for (r=0,s=0;r<t;r++)
    {
       s=s+stu1[i].score[r];
    }
    stu2[i].totalscore=s;
    stu2[i].average=stu2[i].totalscore/(t);
    strcpy(stu2[i].studentname,stu1[i].studentname);
    }

}

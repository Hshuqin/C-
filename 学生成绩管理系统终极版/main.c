#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <windows.h>
#include <mmsystem.h>
#define M 30
#define N 7

typedef struct student /*����ѧ����������Ϣ�Ľṹ����*/
{
int studentID;/*ѧ��*/
char studentname[10];/*����*/
float score[7];
int sum;
float aver;
}STU;

STU stu1[30];

typedef struct afterstudent /*����ѧ����������Ϣ�Ľṹ����*/
{
int studentID;/*ѧ��*/
char studentname[10];/*����*/
int score[4];/*4�Ƴɼ������Ը��ģ�*/
double totalscore;
double average;
}afterSTU;

void menu();/*�˵�*/
void fun (int numb,STU stu1[30],int i,int j);/*��Ŀ¼����ϸ����*/
void gun (int numb,STU stu1[30],int i,int j);/*�ԷǷ�������޸�*/
void luruxinxi (STU stu1[30],int numb,int i,int j);/*¼��ѧ����Ϣ�����ַ�ʽ*/
void ReadfromFile(STU stu1[30],int i,int j);/*���ļ��ж�ȡѧ������Ϣ���ṹ������stu1��*/
void Inputscore (STU stu1[30],int y,int x);/*�Ӽ�������N��ѧ����ѧ�������Լ�����ѧ�Ƴɼ����ṹ����stu1��*/
void research(STU stu1[30],int i,int j);/*�ظ���ѯ��*/
void kechengfen (int numb,STU stu1[30],int i,int j);/*����ÿ�ſγ̵��ֺܷ�ƽ���֡�*/
void studentzongfen (int numb,STU stu1[30],int i,int j); /*����ÿ��ѧ�����ֺܷ�ƽ���֡�*/
void hightolow (int numb,STU stu1[30],int i,int j);/*��ÿ��ѧ�����ܷ��ɸߵ����ų����α�*/
void lowtohigh (int numb,STU stu1[30],int i,int j);/*��ÿ��ѧ�����ܷ��ɵ͵����ų����α�*/
void xhhightolow (int numb,STU stu1[30],int k,int t);/*��ѧ���ɴ�С�ų��ɼ���*/
void zidianpaixu (int numb,STU stu1[30],int p,int q);/*���������ֵ�˳���ų��ɼ���*/
void xuehao(int numb,STU stu1[30],int i,int j);/*��ѧ�Ų�ѯѧ���������俼�Գɼ���*/
void name (int numb,STU stu1[30],int i,int j);/*��������ѯѧ���������俼�Գɼ���*/
void baifenbi (int numb,STU stu1[30],int p,int q); /*�����㡢���á��еȡ����񡢲�����5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�ٷֱȡ�*/
void output (STU stu1[30],int i,int j);/*���ÿ��ѧ����ѧ�š����������Ƴɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ���֡�*/
void readtofile (STU stu1[30],int i,int j);/*��ÿ��ѧ���ļ�¼��Ϣд���ļ���*/
void readed (STU stu1[30],int i,int j);/*���ļ��ж���ÿ��ѧ���ļ�¼����ʾ��*/

    /*-------------------------------------------------------------������------------------------------------------------------*/
int main()
{
    int numb,ren,kemu;

    //ReadfromFile(stu1);
    menu ();
    //printf("��¼������ѧ����ѧ�š������͸��ƿ��Գɼ���(��0����)\n");/*��ȡ�ļ�ʱ��Ӧ��ʡ��*/
    //Inputscore(stu1);
    printf ("��������ѧ��������Ŀ����\n");
    scanf("%d%d",&ren,&kemu);
    printf ("��ʼ��ѯ�������룺\n");
    printf ("����ִ�в˵�һ��������Ϣ¼�룡����\n");
    scanf("%d",&numb);/*������ѯ*/
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

/*-------------------------------------------------------------������------------------------------------------------------*/

void menu()/*�˵�*/
{
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("*********************************************************\n");
    printf("**   ѧ���ɼ�����ϵͳ���˵�����������Ž��в�ѯ����    **\n");
    printf("**                                                     **\n");
    printf("**   00.��������                                     **\n");
    printf("**                                                     **\n");
    printf("**   01.¼��ÿ��ѧ����ѧ�š����������ƿ��Գɼ���       **\n");
    printf("**                                                     **\n");
    printf("**   02.����ÿ�ſγ̵��ֺܷ�ƽ���֡�                   **\n");
    printf("**                                                     **\n");
    printf("**   03.����ÿ��ѧ�����ֺܷ�ƽ���֡�                   **\n");
    printf("**                                                     **\n");
    printf("**   04.��ÿ��ѧ�����ܷ��ɸߵ����ų����α�           **\n");
    printf("**                                                     **\n");
    printf("**   05.��ÿ��ѧ�����ܷ��ɵ͵����ų����α�           **\n");
    printf("**                                                     **\n");
    printf("**   06.��ѧ���ɴ�С�ų��ɼ���                     **\n");
    printf("**                                                     **\n");
    printf("**   07.���������ֵ�˳���ų��ɼ���                   **\n");
    printf("**                                                     **\n");
    printf("**   08.��ѧ�Ų�ѯѧ���������俼�Գɼ���               **\n");
    printf("**                                                     **\n");
    printf("**   09.��������ѯѧ���������俼�Գɼ���               **\n");
    printf("**                                                     **\n");
    printf("**   10.�����㡢���á��еȡ����񡢲�����5�����      **\n");
    printf("**     ��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�ٷֱȡ�**\n");
    printf("**   11.���ÿ��ѧ����ѧ�š����������Ƴɼ���           **\n");
    printf("**     �Լ�ÿ�ſγ̵��ֺܷ�ƽ���֡�                    **\n");
    printf("**   12.��ÿ��ѧ���ļ�¼��Ϣд���ļ���                 **\n");
    printf("**                                                     **\n");
    printf("**   13.���ļ��ж���ÿ��ѧ���ļ�¼����ʾ��             **\n");
    printf("**                                                     **\n");
    printf("*********************************************************\n");
    printf("**********************������*****************************\n");
    printf("*********************************************************\n");


}

void fun (int numb,STU stu1[30],int i,int j)/*��Ŀ¼����ϸ����*/
{
    if (numb==1)/*¼��ÿ��ѧ����ѧ�š����������ƿ��Գɼ���*/
    {
      luruxinxi (stu1,numb,i,j);
      research(stu1,i,j);
    }

    else if (numb==2)
    {
      kechengfen (numb,stu1,i,j);    /*����ÿ�ſγ̵��ֺܷ�ƽ���֡�*/
      research(stu1,i,j);
    }
    else if (numb==3)
    {
      studentzongfen (numb,stu1,i,j); /*����ÿ��ѧ�����ֺܷ�ƽ���֡�*/
      research(stu1,i,j);
    }
    else if (numb==4)
    {
      hightolow (numb,stu1,i,j);/*�˵�4  ��ÿ��ѧ�����ܷ��ɸߵ����ų����α� */
      research(stu1,i,j);
    }
    else if (numb==5)
    {
      lowtohigh (numb,stu1,i,j);/*�˵�5  ��ÿ��ѧ�����ܷ��ɵ͵����ų����α� */
      research(stu1,i,j);
    }
    else if (numb==6)
    {
      xhhightolow (numb,stu1,i,j);/*�˵�6  ��ѧ���ɴ�С�ų��ɼ��� */
      research(stu1,i,j);
    }
    else if (numb==7)
    {
      zidianpaixu (numb,stu1,i,j);/*�˵�7  ���������ֵ�˳���ų��ɼ���*/
      research(stu1,i,j);
    }
    else if (numb==8)
    {
      xuehao(numb,stu1,i,j);/*�˵�8   ��ѧ�Ų�ѯѧ���������俼�Գɼ���*/
      research(stu1,i,j);
    }
    else if (numb==9)/*ѧ�Ų�ѯ*/
    {
      name (numb,stu1,i,j);/*�˵�9   ��������ѯѧ���������俼�Գɼ���*/
      research(stu1,i,j);
    }
    else if (numb==10)
    {
      baifenbi (numb,stu1,i,j); /*�˵�10   �����㡢���á��еȡ����񡢲�����5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�ٷֱȡ�*/
      research(stu1,i,j);
    }
    else if (numb==11) /*�˵�11  ���ÿ��ѧ����ѧ�š����������Ƴɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ���֡�*/
    {
        output (stu1,i,j);
        research(stu1,i,j);
    }
    else if (numb==12)/*�˵�12  ��ÿ��ѧ���ļ�¼��Ϣд���ļ���*/
    {
         readtofile (stu1,i,j);
         research(stu1,i,j);
    }
    else if (numb==13)/*�˵�13   ���ļ��ж���ÿ��ѧ���ļ�¼����ʾ�� */
    {

         research(stu1,i,j);
    }
}

void gun (int numb,STU stu1[30],int i,int j)/*�ԷǷ�������޸�*/
{
 int numb1;
 printf("����������ֲ���ȷ��\n");
 //system("color 04");
 printf("���������롣\n");
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


void Inputscore(STU stu1[],int y,int x)/*�Ӽ�������N��ѧ����ѧ�������Լ�����ѧ�Ƴɼ����ṹ����stu1��*/
{
    int i,j;
        printf("ѧ��\t����\t");
    for(i=0; i<x; i++)
    {
        printf("��Ŀ%d\t",i+1);
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

    printf("��Ϣ¼��ɹ�!\n");
    system("color 06");
}

void kechengfen (int numb,STU stu1[30],int i,int j)/*�˵�2   ����ÿ�ſγ̵��ֺܷ�ƽ���֡�*/
{
    int k,t;
    float s[7];
    printf ("�˵�2   ����ÿ�ſγ̵��ֺܷ�ƽ����:\n");
    for (k=0;k<j;k++)
    {
        s[k]=0;
        for (t=0;t<i;t++)
        s[k]=s[k]+stu1[t].score[k];
    }
    printf ("      ÿ�ſγ̵��ֱַܷ�Ϊ��\n");
    for (k=0;k<j;k++)
        printf ("      %f   ",s[k]);
    printf ("\n");
    printf ("      ÿ�ſγ̵�ƽ���ֱַ�Ϊ��\n");
    for (k=0;k<j;k++)
        printf ("      %.2lf   ",s[k]/i);
    printf ("\n");
}

void studentzongfen (int numb,STU stu1[30],int i,int j) /*�˵�3   ����ÿ��ѧ�����ֺܷ�ƽ���֡�*/
{
double s[N]={0};
int k,t;
printf ("�˵�3   ����ÿ��ѧ�����ֺܷ�ƽ����:\n");
for (k=0;k<i;k++)
    for (t=0;t<j;t++)
{
   s[k]=s[k]+stu1[k].score[t];
}
for (k=0;k<i;k++)
{
    printf ("      ѧ��������  �ܷ�   ƽ���֣�\n");
    printf ("    %s    ",stu1[k].studentname);
    printf ("   %.lf     %.2lf\n",s[k],s[k]/j);
}

}

void hightolow (int numb,STU stu1[30],int i,int j)/*�˵�4  ��ÿ��ѧ�����ܷ��ɸߵ����ų����α� */
{
int sum[30];
int b;
int k,t,r;
printf ("�˵�4  ��ÿ��ѧ�����ܷ��ɸߵ����ų����α�:\n");
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

void lowtohigh (int numb,STU stu1[30],int i,int j)/*�˵�5  ��ÿ��ѧ�����ܷ��ɵ͵����ų����α� */
{
int sum[30];
int b;
printf ("�˵�5  ��ÿ��ѧ�����ܷ��ɵ͵����ų����α�:\n");
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

void xhhightolow (int numb,STU stu1[30],int k,int t)/*�˵�6  ��ѧ���ɴ�С�ų��ɼ��� */
{
 int i,j,b[9],r;
 printf ("�˵�6  ��ѧ���ɴ�С�ų��ɼ���:\n");
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

void zidianpaixu (int numb,STU stu1[30],int p,int q)/*�˵�7  ���������ֵ�˳���ų��ɼ���*/
{
  int i,j,a,n,r;
  float b[4];
  int x,y,k;
  printf ("�˵�7  ���������ֵ�˳���ų��ɼ���:\n");
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
       n=strncmp (stu1[i].studentname,stu1[j].studentname,k);/*Kֵ�ǱȽ��ַ���������k���ַ�,����������*/
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

void xuehao(int numb,STU stu1[30],int i,int j)/*�˵�8   ��ѧ�Ų�ѯѧ���������俼�Գɼ���*/
{
int numb2,r,t=0;
printf ("�˵�8   ��ѧ�Ų�ѯѧ���������俼�Գɼ�:\n");
printf("     ������ѧ����ѧ�Ž��в�ѯ\n");
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
            printf("�������ѧ�Ų����ڣ�������ȷ�����Ƿ�����\n");
            system("color 04");
        }
}

void name (int numb,STU stu1[30],int i,int j)/*�˵�9   ��������ѯѧ���������俼�Գɼ���*/
{
char mingzi[10];
int r,t=0;
printf ("�˵�9   ��������ѯѧ���������俼�Գɼ�:\n");
printf("      ������ѧ���������в�ѯ\n");
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
            printf("����������������ڣ�������ȷ�����Ƿ�����\n");
            system("color 04");
        }
}

void baifenbi (int numb,STU stu1[30],int p,int q) /*�˵�10  �����㡢���á��еȡ����񡢲�����5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�ٷֱȡ�*/
{
  int i,j,a[5]={0},k;
  double b[5]={0};
  printf ("�˵�10  �����㡢���á��еȡ����񡢲�����5����𣬶�ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�ٷֱ�:\n");
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
      printf ("     �γ�  �������� �ٷֱ� �������� �ٷֱ� �е����� �ٷֱ� ���������� �ٷֱ� ���������� �ٷֱ�\n");
      printf ("      %d      %d       %.2lf     %d      %.2lf      %d     %.2lf    %d        %.2lf      %d      %2lf\n",j+1,a[0],b[0],a[1],b[1],a[2],b[2],a[3],b[3],a[4],b[4]);

  }
}

void output (STU stu1[30],int x,int y)/*�˵�11  ���ÿ��ѧ����ѧ�š����������Ƴɼ����Լ�ÿ�ſγ̵��ֺܷ�ƽ���֡�*/
{
int i,j;
    printf("����\tѧ��\t  ����\t");
    for(i=1; i<=y; i++)
    {
        printf("\t��Ŀ%d\t",i);
    }
    printf("\tƽ����\t\t�ܷ�\t\n");
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

void readtofile (STU stu1[30],int n,int m)/*�˵�12  ��ÿ��ѧ���ļ�¼��Ϣд���ļ���*/
{
FILE *fp;
    int i,j;
    if((fp=fopen("student.txt","w"))==NULL)
    {
        printf("��ʧ�ܣ�\n");
        exit(0);
    }
    //fprintf(fp,"ѧ������: ");
    fprintf(fp,"%d%d",n,m);
    fprintf(fp,"���\tѧ��\t\t����\t\t");
    for(i=1; i<=m; i++)
    {
        fprintf(fp,"��Ŀ%d\t\t",i);
    }
    fprintf(fp,"ƽ����\t\t�ܷ�\t\n");
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
    printf ("�����ļ��ɹ�������\n");
}

void readed (STU stu1[30],int i,int j)/*�˵�13  ���ļ��ж���ÿ��ѧ���ļ�¼����ʾ��*/
{
   printf("��ѡ���д������������ڴ�!!!\n");
}

void ReadfromFile(STU stu1[30],int i,int j)/*���ļ��ж�ȡѧ������Ϣ���ṹ������stu1��*/
{
    int k;
    FILE *fp;
    if ((fp=fopen("test1.txt","r"))==NULL)/*�Զ��ķ�ʽ���ı��ļ�*/
    {
        printf("Failure to open test1.txt!\n");
        exit(0);
    }
    for (k=0;!feof(fp);k++)
    {
        fread(&stu1[k],sizeof(STU),1,fp);
    }
    printf("��Ϣ¼��ɹ�!\n");
    system("color 06");
    fclose(fp);
}

void research(STU stu1[30],int i,int j)/*�ظ���ѯ*/
{
    int numb;
    printf ("�Ƿ������ѯ�����밴1�����밴������˳�����\n");
    scanf("%d",&numb);
    if (numb==1)
    {
        system("cls");
        system("color 07");
        menu();
        printf ("��ʼ��ѯ�������룺\n");
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

void luruxinxi (STU stu1[],int numb,int i,int j)/*¼��ÿ��ѧ����ѧ�š����������ƿ��Գɼ���*/
{
    int n;
    printf ("��1�����ֶ�¼�룬��2�����ļ�¼�롣\n");
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
        printf ("���������������������롣\n");
        system("color 04");
        luruxinxi(stu1,n,i,j);
    }

}

void swap(STU stu1[30],afterSTU stu2[30],int k,int t)/*ʵ��ѧ�� �ܷ� ƽ���ֵ�ͳ��*/
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

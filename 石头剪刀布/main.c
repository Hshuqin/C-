#include <stdio.h>
#include <stdlib.h>
void stjdb()
{
    printf ("********************************************\n");
    printf ("***********ʯͷ��������Ϸ*******************\n");
    printf ("********************************************\n");
    printf ("***           1����                      ***\n");
    printf ("***           2ʯͷ                      ***\n");
    printf ("***           3��                        ***\n");
    printf ("***           0����                      ***\n");
    printf ("********************************************\n");
    printf ("********************************************\n");
    printf ("***��Ϸ˵��������ս���ǵ��ԣ�����׼��Ŷ��***\n");
}
int main()
{
    int i,numb;
    while (1)
    {
        stjdb();
        printf("��Ϸ��ʼ��\n");
        scanf("%d",&i);
        numb=rand() %3;/*���������*/
        if (i==0)
        break;
        else if (i==1)
        {
          if (numb==1)
            printf ("��������ƽ��\n");
          else if (numb==2)
          printf ("��ǸŶ��������\n");
          else
            printf ("�����ˣ���Ӯ��\n");
        }
        else if (i==2)
        {
             if (numb==1)
            printf ("�����ˣ���Ӯ��\n");
          else if (numb==2)
          printf ("��������ƽ��\n");
          else
            printf ("��ǸŶ��������\n");
        }
        else if (i==3)
        {
            if (numb==1)
            printf ("��ǸŶ��������\n");
          else if (numb==2)
          printf ("�����ˣ���Ӯ��\n");
          else
            printf ("��������ƽ��\n");
        }
        else
        {
            printf ("����������������������");
            break;
        }

    }
    return 0;
}

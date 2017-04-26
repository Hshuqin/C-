#include <stdio.h>
#include <stdlib.h>
void stjdb()
{
    printf ("********************************************\n");
    printf ("***********石头剪刀布游戏*******************\n");
    printf ("********************************************\n");
    printf ("***           1剪刀                      ***\n");
    printf ("***           2石头                      ***\n");
    printf ("***           3布                        ***\n");
    printf ("***           0结束                      ***\n");
    printf ("********************************************\n");
    printf ("********************************************\n");
    printf ("***游戏说明：您对战的是电脑，做好准备哦。***\n");
}
int main()
{
    int i,numb;
    while (1)
    {
        stjdb();
        printf("游戏开始：\n");
        scanf("%d",&i);
        numb=rand() %3;/*随机数产生*/
        if (i==0)
        break;
        else if (i==1)
        {
          if (numb==1)
            printf ("不赖啊，平局\n");
          else if (numb==2)
          printf ("抱歉哦，您输了\n");
          else
            printf ("棒极了，您赢了\n");
        }
        else if (i==2)
        {
             if (numb==1)
            printf ("棒极了，您赢了\n");
          else if (numb==2)
          printf ("不赖啊，平局\n");
          else
            printf ("抱歉哦，您输了\n");
        }
        else if (i==3)
        {
            if (numb==1)
            printf ("抱歉哦，您输了\n");
          else if (numb==2)
          printf ("棒极了，您赢了\n");
          else
            printf ("不赖啊，平局\n");
        }
        else
        {
            printf ("您的输入有误，请重启电脑");
            break;
        }

    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "datadefine.h"

void fresh(double qucan)
{
    indent *x;
    stu *y;
    char queren;
    double xuehao,ph;
    int jishu,confirm;
    x=head_indent;
    y=head_stu;
    system("cls");
    printf("ȷ����Ĳ˵�\n");
    while(x->next!=NULL)
    {
        if(x->yz==qucan&&x->condi==0)
        {
            printf("%s\n",x->name);
            xuehao=x->num;
            jishu++;
        }
        x=x->next;
    }
   while(y->next!=NULL)
   {
        if(y->num==xuehao)
        {
            cur_stu=y;
            break;
        }
        y=y->next;
    }
    if(jishu!=0)
    {
        confirm=yanzhen();
        if(confirm=1)
        {
        getchar();
        getchar();
        printf("����y or Yȷ��ȡ��\n");
        scanf("%c",&queren);
        if(queren=='y'||queren=='Y')
            {
                x=head_indent;
                while(x->next!=NULL)
                {
                    if(x->yz==qucan&&x->condi==0)
                    {
                        x->condi=1;
                        x->yz=0;
                    }
                    x=x->next;
                }
                y=head_stu;
                while(y->next!=NULL)
                {
                    if(y->num==xuehao)
                    {
                        y->exist=0;
                        y->yanzhen=0;
                        break;
                    }
                    y=y->next;
                }
                //savedata_stu(head_stu);
                //savedata_indent(head_indent);
                printf("ȡ�ͳɹ�");
                sleep(3);
            }
        }
    }
    else
    {
        system("cls");
        printf("��������֤��Ϊ%.0lf�Ķ���\n",qucan);
        sleep(2);
    }
}

void take()
{
   time_t rawtime;
   struct tm *info;
   time(&rawtime);
   info = gmtime(&rawtime);
   double qucan;
   printf("%2d:%02d\n", (info->tm_hour+8)%24, info->tm_min);
   printf("��ӭȡ��\n������ȡ����֤��\n");
   scanf("%lf",&qucan);
   fresh(qucan);
}

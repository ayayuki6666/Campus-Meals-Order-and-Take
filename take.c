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
    printf("确认你的菜单\n");
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
        printf("输入y or Y确认取餐\n");
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
                printf("取餐成功");
                sleep(3);
            }
        }
    }
    else
    {
        system("cls");
        printf("不存在验证码为%.0lf的订单\n",qucan);
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
   printf("欢迎取餐\n请输入取餐验证码\n");
   scanf("%lf",&qucan);
   fresh(qucan);
}

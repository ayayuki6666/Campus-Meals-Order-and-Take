#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "datadefine.h"
indent *additon_in(indent *head)
{
    int i,h;
    double price,sum;
    sum=0;
    i=gen_yanzhen();
    indent *p,*q,*s;
    menu *d;
    char c;
    d=head_menu;
    q=NULL;
    do {
        /*if()
        p=head;
        else*/
        p=s;
        s=malloc(sizeof(indent));
        printf("输入你想添加的菜品的编号输入-1结束\n");
        scanf("%d",&h);
        s->amt=1;
        s->condi=0;
        s->num=cur_stu->num;
        cur_stu->yanzhen=i;
        s->phone=cur_stu->phone;
        s->yz=i;
        while(d->next!=NULL)
        {
            if(d->num==h)
            {
                sum=sum+d->price;
                strcpy(s->name,d->name);
                break;
            }
            else
                d=d->next;
        }
        if(h!=-1)
        {
        p->next=s;
        s->next=NULL;
        }
        else
        s->next=NULL;
        }while(h!=-1);
    system("cls");
    printf("总价是%.2lf元是否支付(Y or N)\n",sum);
    if(sum!=0)
    {
        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y')
        {
            if(sum<=cur_stu->yue)
            {
            cur_stu->yue=cur_stu->yue-sum;
            cur_stu->exist=1;
            return(head);
            }
            else
            printf("余额不足 请充值");
        }
    }
}

void order()
{
   time_t rawtime;
   struct tm *info;
   double sum;
   time(&rawtime);
   info = gmtime(&rawtime);
   login_stu(head_stu);
   system("cls");
   printf("欢迎点餐%s 当前余额:%.2lf\n",cur_stu->name,cur_stu->yue);
   printf("%2d:%02d\n", (info->tm_hour+8)%24, info->tm_min);
   print_menu(head_menu);
   additon_in(head_indent);
   savedata_indent(head_indent);
   savedata_stu(head_stu);
   sleep(1);
   printf("下单成功你的取餐验证码为%.0lf",cur_stu->yanzhen);
   sleep(3);
}

#include "datadefine.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_menu(menu *head)
{
    //system("cls");
    menu *p;
    p=head;
    printf("序号\t\t菜品\t\t\t价格\n");
    while(p!=NULL)
    {
        printf("%2d\t\t%s\t\t%-0.2lf\n",p->num,p->name,p->price);
        p=p->next;
    }
    printf("\n");
}

void print_stu(stu *head)
{
    //system("cls");
    stu *p;
    p=head;
    printf("学号\t\t手机号\t\t姓名\t余额\t\t验证码\t订单状态\n");
    while(p!=NULL)
    {
        printf("%.0lf\t%.0lf\t%s\t%.2lf\t\t%.0lf\t%d\n",p->num,p->phone,p->name,p->yue,p->yanzhen,p->exist);
        p=p->next;
    }
    printf("\n");
}

void print_indent(stu *head)
{
    //system("cls");
    indent *p;
    p=head;
    printf("学号\t\t手机号\t\t\t菜品\t\t状态\t\t数量\t\t验证码\n");
    while(p!=NULL)
    {
        printf("%.0lf\t%.0lf\t\t%s\t%d\t\t%d\t\t%d\n",p->num,p->phone,p->name,p->condi,p->amt,p->yz);
        p=p->next;
    }
    printf("\n");
}

stu *change(stu *head)
{
   int x=0;
   double n=0;
   stu *p;
   p=head;
   printf("输入想要调整的学生的学号\t");
   scanf("%lf",&n);
   while(p!=NULL)
   {
       if(p->num==n)
        {
            x=1;
            printf("查询成功，输入该学生的余额");
            scanf("%lf",&p->yue);
            break;
        }
        else
            p=p->next;
   }
   if(x==0)
        printf("未查询到学号为%.0lf的学生",n);
   return(head);
}

menu *tiaozhen(stu *head)
{
    int i,n=0;
    printf("输入要调整的菜品序号\n");
    menu *p;
    p=head;
    scanf("%d",&i);
    while(p!=NULL)
    {
        if(p->num==i)
        {
            n=1;
            printf("查找成功，输入该菜品的新价格");
            scanf("%lf",&p->price);
            break;
        }
        else
            p=p->next;
    }
    if(n==0)
        printf("未查询到序号为%d的菜品"),i;
    return(head);
}

menu *del(menu *head)
{
    menu *p,*q;
    int n,x=0;
    p=head;
    q=NULL;
    printf("输入被删菜品编号");
    scanf("%d",&n);
    while(p!=NULL)
    {
        if(p->num==n)
        {
            x=1;
            break;
        }
        else
        {
            q=p;
            p=p->next;
        }
    }
    if(x==1)
    {
        if(p==head)
            head=p->next;
        else
            q->next=p->next;
        free(p);
    }
    else
        printf("未找到编号为%d的菜品",n);
    return(head);
}

menu *additon(menu *head)
{
    int i;
    char a1[20];
    double price;
    menu *p,*q,*s;
    p=head,q=NULL;
    s=malloc(sizeof(menu));
    printf("输入你想添加的菜品的编号 品名 价格\n");
    scanf("%d%s%lf",&i,&a1,&price);
    s->num=i;
    s->price=price;
    strcpy(s->name,a1);
    while(p->next!=NULL)
        p=p->next;
    p->next=s;
    s->next=NULL;
    return(head);
}

int gen_yanzhen()
{
    double c=0;
    int n,m,i=amount;
    srand(time(NULL));
    for(i;i>0;i--)
        {
            srand(time(NULL));
            n=pow(10,i);
            m=pow(10,i-1);
            c=c+m+rand()%n+rand()%2+rand()%3+rand()%5+rand()%7;
        }
    if(c>(pow(10,amount)-1))
    {
        c=(int)(c/10);
    }
   /* while(head_stu!=NULL)
    {
        if
    }*/
    //printf("%lf\n",c);
    return (int)c;
}

void login_stu(stu *head)
{
    stu *p;
    p=head;
    double s;
    char pas[20];
    int n,l;
    printf("请输入学号\n");
    scanf("%lf",&s);
    while(p!=NULL)
    {
        if(s==p->num)
        {
            n=0,l=0;
            while(1)
            {   printf("请输入密码\n");
                scanf("%s",&pas);
                if(strcmp(p->pas,pas)==0)
                    {
                        printf("登录成功\n");
                        l=1;
                        cur_stu=p;
                        sleep(1);
                        break;
                    }
                else
                {
                    printf("密码错误 请重新输入\n");
                    n++;
                }
                if(n==3)
                    break;
            }
        }
        else
        p=p->next;
        if(l==1)
        break;
        if(n==3)
        {
            break;
            printf("密码输入次数已达上限，请稍后再试或联系管理员\n");
            sleep(2);
        }
    }
    printf("\n");
}

void change_weishu()
{
    printf("输入新的验证码位数\n");
    scanf("%d",&amount);
    printf("修改成功");
    sleep(1);
}

void change_gailv()
{
    printf("输入新的二次验证概率（0-100整数）");
    scanf("%d",&odds);
    printf("修改成功");
    sleep(1);
}

int yanzhen()
{
    int i,n;
    srand(time(NULL));
    i=rand()%100;
    double x;
    if(i>=(100-odds))
       {
           srand(time(NULL));
           n=rand()%2;
           if(n==0)
           {
               printf("请输入手机号码以确认身份\n");
               scanf("%lf",&x);
               if(x==cur_stu->phone)
               return 1;
               else
               return 0;
           }
           if(n==1)
           {
               printf("请输入学号以确认身份\n");
               scanf("%lf",&x);
               if(x==cur_stu->num)
               return 1;
               else
               return 0;
           }
       }
    else
        return 1;
}

void chaxun()
{
    login_stu(head_stu);
    if(cur_stu->exist!=0)
    {
    printf("欢迎%s 你的当前订单验证码为%.0lf\n",cur_stu->name,cur_stu->yanzhen);
    getchar();
    printf("输入任意字符(可为空)继续");
    getchar();
    }
    else
    {
    printf("不存在订单");
    sleep(2);
    }
}

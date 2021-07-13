#include "datadefine.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_menu(menu *head)         //菜单展示
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

void print_stu(stu *head)           //学生展示
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

void print_indent(stu *head)        //订单展示
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

stu *change(stu *head)              //学生余额更改
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

menu *tiaozhen(stu *head)           //菜品价格调整
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

menu *del(menu *head)               //菜品删除
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

menu *additon(menu *head)           //菜品添加
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

int gen_yanzhen()                   //验证码的生成(基于随机数 缺点：短时间内验证码相差不大)
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

int login_stu(stu *head)            //订餐时的登录系统
{
    stu *p;
    p=head;
    double s;
    char pas[20];
    int n,l,fanhui,m=0;
    printf("请输入学号\n");
    scanf("%lf",&s);
    getchar();
    while(p!=NULL)
    {
        if(s==p->num)
        {
            n=0,l=0,m=1;
            while(1)
            {   printf("请输入密码\n");
                scanf("%s",&pas);
                if(strcmp(p->pas,pas)==0)
                    {
                        printf("登录成功\n");
                        l=1;
                        fanhui=1;
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
        {
            p=p->next;
        }
        if(m!=1)
        {
            printf("学号为%.0lf的账号不存在",s);
            sleep(1);
            fanhui=0;
            break;
        }
        if(l==1)
            break;
        if(n==3)
        {
            printf("密码输入次数已达上限，请稍后再试或联系管理员\n");
            fanhui=0;
            sleep(2);
            break;
        }
    }
    printf("\n");
    return(fanhui);
}

void change_weishu()                //验证码位数的改变
{
    printf("输入新的验证码位数\n");
    scanf("%d",&amount);
    printf("修改成功");
    sleep(1);
}

void change_gailv()                 //二次验证概率调整
{
    printf("输入新的二次验证概率（0-100整数）");
    scanf("%d",&odds);
    printf("修改成功");
    sleep(1);
}

int yanzhen()                       //二次验证
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

indent *additon_in(indent *head)    //订单添加
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
    p=head_indent;
    while(p->next!=NULL)
        p=p->next;
    do {
        s=malloc(sizeof(indent));
        printf("输入你想添加的菜品的编号输入-1结束\n");
        scanf("%d",&h);
        s->amt=1;
        s->condi=0;
        s->num=cur_stu->num;
        cur_stu->yanzhen=i;
        s->phone=cur_stu->phone;
        s->yz=i;
        while(d!=NULL)
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
        p=s;
        }
        else
        s->next=NULL;
        }while(h!=-1);
    system("cls");

    if(sum!=0)
    {
        printf("总价是%.2lf元是否支付(Y or N)\n",sum);
        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y')
        {
            if(sum<=cur_stu->yue)
            {
            cur_stu->yue=cur_stu->yue-sum;
            cur_stu->exist=1;
            sleep(1);
            printf("下单成功你的取餐验证码为%.0lf",cur_stu->yanzhen);
            sleep(2);
            }
            else
            printf("余额不足 请充值");
        }
    }
}

void order()                        //订餐
{
   time_t rawtime;
   struct tm *info;
   double sum;
   int i;
   time(&rawtime);
   info = gmtime(&rawtime);
   i=login_stu(head_stu);
   if(i==1)
   {
   system("cls");
   if(cur_stu->exist==0)
   {
        printf("欢迎点餐%s 当前余额:%.2lf\n",cur_stu->name,cur_stu->yue);
        printf("%2d:%02d\n", (info->tm_hour+8)%24, info->tm_min);
        print_menu(head_menu);
        additon_in(head_indent);
   }
   else
   {
       printf("有未领取的订单,请先领取");
       sleep(2);
   }
   }
}

void fresh(double qucan)            //取餐时的数据更新
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
    while(x!=NULL)
    {
        if(x->yz==qucan&&x->condi==0)
        {
            printf("%s\n",x->name);
            xuehao=x->num;
            jishu++;
        }
        x=x->next;
    }
   while(y!=NULL)
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
        printf("输入y or Y确认取餐\n");
        scanf("%c",&queren);
        if(queren=='y'||queren=='Y')
            {
                x=head_indent;
                while(x!=NULL)
                {
                    if(x->yz==qucan&&x->condi==0)
                    {
                        x->condi=1;
                        x->yz=0;
                    }
                    x=x->next;
                }
                y=head_stu;
                while(y!=NULL)
                {
                    if(y->num==xuehao)
                    {
                        y->exist=0;
                        y->yanzhen=0;
                        break;
                    }
                    y=y->next;
                }
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

void take()                         //取餐
{
   time_t rawtime;
   struct tm *info;
   time(&rawtime);
   info = gmtime(&rawtime);
   double qucan;
   system("cls");
   printf("%02d:%02d\n", (info->tm_hour+8)%24, info->tm_min);
   printf("欢迎取餐\n请输入取餐验证码\n");
   scanf("%lf",&qucan);
   fresh(qucan);
}

void chaxun()                       //验证码查询(未做验证)
{
    stu *p;
    p=head_stu;
    double chaxun_shouji;
    printf("输入手机\n");
    scanf("%lf",&chaxun_shouji);
    while(p!=NULL)
    {
        if(p->num==chaxun_shouji)
        {
            cur_stu=p;
            break;
        }
        else
            p=p->next;
    }
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

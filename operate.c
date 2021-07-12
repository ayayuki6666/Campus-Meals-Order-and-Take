#include "datadefine.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_menu(menu *head)
{
    //system("cls");
    menu *p;
    p=head;
    printf("���\t\t��Ʒ\t\t\t�۸�\n");
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
    printf("ѧ��\t\t�ֻ���\t\t����\t���\t\t��֤��\t����״̬\n");
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
    printf("ѧ��\t\t�ֻ���\t\t\t��Ʒ\t\t״̬\t\t����\t\t��֤��\n");
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
   printf("������Ҫ������ѧ����ѧ��\t");
   scanf("%lf",&n);
   while(p!=NULL)
   {
       if(p->num==n)
        {
            x=1;
            printf("��ѯ�ɹ��������ѧ�������");
            scanf("%lf",&p->yue);
            break;
        }
        else
            p=p->next;
   }
   if(x==0)
        printf("δ��ѯ��ѧ��Ϊ%.0lf��ѧ��",n);
   return(head);
}

menu *tiaozhen(stu *head)
{
    int i,n=0;
    printf("����Ҫ�����Ĳ�Ʒ���\n");
    menu *p;
    p=head;
    scanf("%d",&i);
    while(p!=NULL)
    {
        if(p->num==i)
        {
            n=1;
            printf("���ҳɹ�������ò�Ʒ���¼۸�");
            scanf("%lf",&p->price);
            break;
        }
        else
            p=p->next;
    }
    if(n==0)
        printf("δ��ѯ�����Ϊ%d�Ĳ�Ʒ"),i;
    return(head);
}

menu *del(menu *head)
{
    menu *p,*q;
    int n,x=0;
    p=head;
    q=NULL;
    printf("���뱻ɾ��Ʒ���");
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
        printf("δ�ҵ����Ϊ%d�Ĳ�Ʒ",n);
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
    printf("����������ӵĲ�Ʒ�ı�� Ʒ�� �۸�\n");
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
    printf("������ѧ��\n");
    scanf("%lf",&s);
    while(p!=NULL)
    {
        if(s==p->num)
        {
            n=0,l=0;
            while(1)
            {   printf("����������\n");
                scanf("%s",&pas);
                if(strcmp(p->pas,pas)==0)
                    {
                        printf("��¼�ɹ�\n");
                        l=1;
                        cur_stu=p;
                        sleep(1);
                        break;
                    }
                else
                {
                    printf("������� ����������\n");
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
            printf("������������Ѵ����ޣ����Ժ����Ի���ϵ����Ա\n");
            sleep(2);
        }
    }
    printf("\n");
}

void change_weishu()
{
    printf("�����µ���֤��λ��\n");
    scanf("%d",&amount);
    printf("�޸ĳɹ�");
    sleep(1);
}

void change_gailv()
{
    printf("�����µĶ�����֤���ʣ�0-100������");
    scanf("%d",&odds);
    printf("�޸ĳɹ�");
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
               printf("�������ֻ�������ȷ�����\n");
               scanf("%lf",&x);
               if(x==cur_stu->phone)
               return 1;
               else
               return 0;
           }
           if(n==1)
           {
               printf("������ѧ����ȷ�����\n");
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
    printf("��ӭ%s ��ĵ�ǰ������֤��Ϊ%.0lf\n",cur_stu->name,cur_stu->yanzhen);
    getchar();
    printf("���������ַ�(��Ϊ��)����");
    getchar();
    }
    else
    {
    printf("�����ڶ���");
    sleep(2);
    }
}

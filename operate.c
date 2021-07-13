#include "datadefine.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void print_menu(menu *head)         //�˵�չʾ
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

void print_stu(stu *head)           //ѧ��չʾ
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

void print_indent(stu *head)        //����չʾ
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

stu *change(stu *head)              //ѧ��������
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

menu *tiaozhen(stu *head)           //��Ʒ�۸����
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

menu *del(menu *head)               //��Ʒɾ��
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

menu *additon(menu *head)           //��Ʒ���
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

int gen_yanzhen()                   //��֤�������(��������� ȱ�㣺��ʱ������֤������)
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

int login_stu(stu *head)            //����ʱ�ĵ�¼ϵͳ
{
    stu *p;
    p=head;
    double s;
    char pas[20];
    int n,l,fanhui,m=0;
    printf("������ѧ��\n");
    scanf("%lf",&s);
    getchar();
    while(p!=NULL)
    {
        if(s==p->num)
        {
            n=0,l=0,m=1;
            while(1)
            {   printf("����������\n");
                scanf("%s",&pas);
                if(strcmp(p->pas,pas)==0)
                    {
                        printf("��¼�ɹ�\n");
                        l=1;
                        fanhui=1;
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
        {
            p=p->next;
        }
        if(m!=1)
        {
            printf("ѧ��Ϊ%.0lf���˺Ų�����",s);
            sleep(1);
            fanhui=0;
            break;
        }
        if(l==1)
            break;
        if(n==3)
        {
            printf("������������Ѵ����ޣ����Ժ����Ի���ϵ����Ա\n");
            fanhui=0;
            sleep(2);
            break;
        }
    }
    printf("\n");
    return(fanhui);
}

void change_weishu()                //��֤��λ���ĸı�
{
    printf("�����µ���֤��λ��\n");
    scanf("%d",&amount);
    printf("�޸ĳɹ�");
    sleep(1);
}

void change_gailv()                 //������֤���ʵ���
{
    printf("�����µĶ�����֤���ʣ�0-100������");
    scanf("%d",&odds);
    printf("�޸ĳɹ�");
    sleep(1);
}

int yanzhen()                       //������֤
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

indent *additon_in(indent *head)    //�������
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
        printf("����������ӵĲ�Ʒ�ı������-1����\n");
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
        printf("�ܼ���%.2lfԪ�Ƿ�֧��(Y or N)\n",sum);
        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y')
        {
            if(sum<=cur_stu->yue)
            {
            cur_stu->yue=cur_stu->yue-sum;
            cur_stu->exist=1;
            sleep(1);
            printf("�µ��ɹ����ȡ����֤��Ϊ%.0lf",cur_stu->yanzhen);
            sleep(2);
            }
            else
            printf("���� ���ֵ");
        }
    }
}

void order()                        //����
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
        printf("��ӭ���%s ��ǰ���:%.2lf\n",cur_stu->name,cur_stu->yue);
        printf("%2d:%02d\n", (info->tm_hour+8)%24, info->tm_min);
        print_menu(head_menu);
        additon_in(head_indent);
   }
   else
   {
       printf("��δ��ȡ�Ķ���,������ȡ");
       sleep(2);
   }
   }
}

void fresh(double qucan)            //ȡ��ʱ�����ݸ���
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
        printf("����y or Yȷ��ȡ��\n");
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

void take()                         //ȡ��
{
   time_t rawtime;
   struct tm *info;
   time(&rawtime);
   info = gmtime(&rawtime);
   double qucan;
   system("cls");
   printf("%02d:%02d\n", (info->tm_hour+8)%24, info->tm_min);
   printf("��ӭȡ��\n������ȡ����֤��\n");
   scanf("%lf",&qucan);
   fresh(qucan);
}

void chaxun()                       //��֤���ѯ(δ����֤)
{
    stu *p;
    p=head_stu;
    double chaxun_shouji;
    printf("�����ֻ�\n");
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

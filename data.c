#include "datadefine.h"
#include <stdio.h>
#include <stdlib.h>
menu *load_menu()                   //�˵���Ϣ��ȡ
{
    menu *head=NULL,*p,*rear=NULL;
    p=malloc(sizeof(menu));
    FILE *fp1;
    fp1=fopen("menu.txt","r");
    fscanf(fp1,"%d%s%lf",&p->num,&p->name,&p->price);
    while(!feof(fp1))
    {
        if(head == NULL)
            head=p;
        else
            rear->next=p;
        rear=p;
        p=malloc(sizeof(menu));
        fscanf(fp1,"%d%s%lf",&p->num,&p->name,&p->price);
    }
    rear->next=NULL;
    fclose(fp1);
    return(head);
}

stu *stu_load()                     //ѧ����Ϣ��ȡ
{
    stu *head=NULL,*p,*rear=NULL;
    p=malloc(sizeof(stu));
    FILE *fp1;
    fp1=fopen("student.txt","r");
    fscanf(fp1,"%lf%lf%s%lf%s%lf%d",&p->num,&p->phone,&p->name,&p->yue,&p->pas,&p->yanzhen,&p->exist);
    while(!feof(fp1))
    {
        if(head == NULL)
            head=p;
        else
            rear->next=p;
        rear=p;
        p=malloc(sizeof(stu));
        fscanf(fp1,"%lf%lf%s%lf%s%lf%d",&p->num,&p->phone,&p->name,&p->yue,&p->pas,&p->yanzhen,&p->exist);
    }
    rear->next=NULL;
    fclose(fp1);
    return(head);
}

indent *indent_load()               //������Ϣ��ȡ
{
    indent *head=NULL,*p,*rear=NULL;
    p=malloc(sizeof(indent));
    FILE *fp1;
    fp1=fopen("indent.txt","r");
    fscanf(fp1,"%lf%lf%d%d%d%s",&p->num,&p->phone,&p->condi,&p->amt,&p->yz,&p->name);
    while(!feof(fp1))
    {
        if(head == NULL)
            head=p;
        else
            rear->next=p;
        rear=p;
        p=malloc(sizeof(indent));
        fscanf(fp1,"%lf%lf%d%d%d%s",&p->num,&p->phone,&p->condi,&p->amt,&p->yz,&p->name);
    }
    rear->next=NULL;
    fclose(fp1);
    return(head);
}

void load_yanzhen()                 //��֤��Ϣ��ȡ
{
    FILE *fp;
    fp=fopen("yanzhen.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%d%d",&amount,&odds);
    }
}

void savedata_menu(stu *head)       //��Ʒ��Ϣ����
{
    menu *p;
    p=head;
    FILE *fp2;
    fp2=fopen("menu.txt","w");
    while(p!=NULL)
    {
        fprintf(fp2,"%d %s %lf\n",p->num,p->name,p->price);
        p=p->next;
    }
    fclose(fp2);
}

void savedata_stu(stu *head)        //ѧ����Ϣ����
{
    stu *p;
    p=head;
    FILE *fp2;
    fp2=fopen("student.txt","w");
    while(p!=NULL)
    {
        fprintf(fp2,"%lf %lf %s %lf %s %lf %d\n",p->num,p->phone,p->name,p->yue,p->pas,p->yanzhen,p->exist);
        p=p->next;
    }
    fclose(fp2);
}

void savedata_indent(stu *head)     //������Ϣ����
{
    indent *p;
    p=head;
    FILE *fp2;
    fp2=fopen("indent.txt","w");
    while(p!=NULL)
    {
        fprintf(fp2,"%lf %lf %d %d %d %s\n",p->num,p->phone,p->condi,p->amt,p->yz,p->name);
        p=p->next;
    }
    fclose(fp2);
}

void savedata_yanhen()              //��֤ϵͳ��������
{
    FILE *fp;
    fp=fopen("yanzhen.txt","w");
    fprintf(fp,"%d %d\n",amount,odds);
}

void load_all()                     //��ȡ��������
{
    head_menu=load_menu();
    head_stu=stu_load();
    head_indent=indent_load();
    load_yanzhen();
}

void save_all()                     //�����������ݵ�txt
{
    savedata_indent(head_indent);
    savedata_stu(head_stu);
    savedata_menu(head_menu);
    savedata_yanhen();
}

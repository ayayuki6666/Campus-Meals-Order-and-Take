/*******************************************
��ͷ�ļ����ڴ����ṹ���Լ���������
Author����ѽ� Date��2021/07/10
Mail��yaolin6666@gmail.com
********************************************/
#ifndef DATADEFINE_H_INCLUDED
#define DATADEFINE_H_INCLUDED
typedef struct caidan
{
    int num;
    char name[20];
    double price;
    struct caidan *next;
}menu;
typedef struct dindan
{
    double num;                  //ѧ��
    double phone;
    int condi;                  //״̬1(1���0δ���)
    int amt;                    //����
    int yz;                     //��֤
    char name[20];
    struct dindan *next;
}indent;
typedef struct stu
{
    double num;                //ѧ��
    double phone;              //�绰����
    char name[20];             //����
    double yue;                //���
    char pas[20];              //����
    double yanzhen;            //������֤
    int exist;                 //�Ƿ���δ��ɵĶ���
    struct stu *next;
}stu;
menu *head_menu;
indent *head_indent;
stu *head_stu;
stu *cur_stu;
stu *cur_ind;
int amount;
int odds;
#endif // DATADEFINE_H_INCLUDED

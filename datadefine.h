/*******************************************
本头文件用于创建结构体以及部分数据
Author：徐佳杰 Date：2021/07/10
Mail：yaolin6666@gmail.com
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
    double num;                  //学号
    double phone;
    int condi;                  //状态1(1完成0未完成)
    int amt;                    //数量
    int yz;                     //验证
    char name[20];
    struct dindan *next;
}indent;
typedef struct stu
{
    double num;                //学号
    double phone;              //电话号码
    char name[20];             //姓名
    double yue;                //余额
    char pas[20];              //密码
    double yanzhen;            //订单验证
    int exist;                 //是否有未完成的订单
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

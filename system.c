#include <stdio.h>
#include <stdlib.h>
#include "datadefine.h"
void system_main()//Finished
{
    int s_1;
    while(1)
    {
        system("cls");
        printf("\t\t********************\n");
        printf("\t\t*  选择进入的系统  *\n");
        printf("\t\t*  1.管理员系统    *\n");
        printf("\t\t*  2.用 户 系 统   *\n");
        printf("\t\t*  0.退       出   *\n");
        printf("\t\t********************\n");
        printf("\t\t输入所选择的系统\n");
        scanf("%d",&s_1);
        if(s_1==1)
            {
            system_admin();                   //进入管理员系统
            }
        else if(s_1==2)
            {
            system_user();                   //进入用户系统
            }
        else if(s_1==0)
            break;                             //退出
        else
            {
                printf("输入无效\n");        //无效输入输出
                sleep(1);
            }
    }
}

void system_admin()//Finished
{
    int s_2;
    char password_admin[20];
    printf("输入管理员密码\n");
    scanf("%s",&password_admin);
    if(strcmp(password_admin,"admin")==0)
        while(1)
        {
        system("cls");
        printf("\t\t*********************\n");
        printf("\t\t*   选择使用的功能  *\n");
        printf("\t\t*   1.学生信息管理  *\n");
        printf("\t\t*   2.菜单信息管理  *\n");
        printf("\t\t*   3.验证系统管理  *\n");
        printf("\t\t*   0.退       出   *\n");
        printf("\t\t*********************\n");
        printf("\t\t输入所要使用功能的编号\n");
        scanf("%d",&s_2);
        if(s_2==1)
            man_stu();                              //学生信息(包括余额订单)
        else if(s_2==2)
            man_menu();                             //菜单调整
        else if(s_2==3)
            man_yanzhen();                          //验证调整
        else if(s_2==0)
            break;                                  //退出管理系统
        else
            {
            printf("输入无效\n");                   //无效输入输出
            sleep(1);
            }
        }
    else
    {
        printf("密码错误,返回菜单选择");
        sleep(1);
    }
}

void system_user()//Finished
{
    int s_3;
    while(1)
    {
        system("cls");
        printf("\t\t****************************\n");
        printf("\t\t*     选择使用的功能       *\n");
        printf("\t\t*     1.点          餐     *\n");
        printf("\t\t*     2.取          餐     *\n");
        printf("\t\t*     3.查 询 取 餐 码     *\n");
        printf("\t\t*     0.退          出     *\n");
        printf("\t\t****************************\n");
        printf("\t\t输入所要使用功能的编号\n");
        scanf("%d",&s_3);
        if(s_3==1)
            order();                            //点餐
        else if(s_3==2)
            take();                             //取餐
        else if(s_3==3)
            chaxun();
        else if(s_3==0)
            break;                              //退出用户系统
        else
            {
                printf("输入无效\n");           //无效输入的反馈
                sleep(1);
            }
        }
}

void man_stu()//Finished
{
        int s_4;
        system("cls");
        while(1)
        {
        printf("\t\t**********************\n");
        printf("\t\t*   选择使用的功能   *\n");
        printf("\t\t*   1.查看学生信息   *\n");
        printf("\t\t*   2.学生余额调整   *\n");
        printf("\t\t*   3.历史订单查看   *\n");
        printf("\t\t*   0.返        回   *\n");
        printf("\t\t**********************\n");
        printf("\t\t输入所要使用功能的编号\n");
        scanf("%d",&s_4);
        if(s_4==1)
            print_stu(head_stu);                    //学生信息显示
        else if(s_4==2)
             {
                 head_stu=change(head_stu);
                 system("cls");
                 print_stu(head_stu);
             }                                      //学生余额调整
        else if(s_4==3)
            {
                print_indent(head_indent);
                getchar();
            }                                       //查看学生的历史订单(单项列出)
        else if(s_4==0)
            break;
        else
            {
                printf("输入无效\n");           //无效输入的反馈
                sleep(1);
            }
        }
}

void man_menu()//Finished
{
        int s_5;
        system("cls");
        while(1)
        {
        print_menu(head_menu);
        printf("\t\t**********************\n");
        printf("\t\t*   选择使用的功能   *\n");
        printf("\t\t*   1.修改菜单信息   *\n");
        printf("\t\t*   2. 删 除 菜 品   *\n");
        printf("\t\t*   3. 添 加 菜 品   *\n");
        printf("\t\t*   0. 退       出   *\n");
        printf("\t\t**********************\n");
        printf("\t\t输入所要使用功能的编号\n");
        scanf("%d",&s_5);
        if(s_5==1)
                {
                 head_menu=tiaozhen(head_menu);         //修改菜单价格
                 system("cls");
                }
        else if(s_5==2)
             {
                 head_menu=del(head_menu);              //删除菜品
             }
        else if(s_5==3)
            {
                head_menu=additon(head_menu);           //添加菜品
            }
        else if(s_5==0)
            break;
        else
            {
                printf("输入无效\n");           //无效输入的反馈
                sleep(1);
            }
        }
}

void man_yanzhen()//Finished
{
    int s_6;
    while(1)
    {
        system("cls");
        printf("\t\t*************************\n");
        printf("\t\t*   选择调整类型        *\n");
        printf("\t\t*   1.调整验证码位数    *\n");
        printf("\t\t*   2.调整二次验证概率  *\n");
        printf("\t\t*   0.退       出       *\n");
        printf("\t\t*************************\n");
        printf("\t\t输入所要使用功能的编号\n");
        scanf("%d",&s_6);
        if(s_6==1)
            {
                change_weishu();                //验证码位数调整
            }
        else if(s_6==2)
            {
                change_gailv();                 //二级验证概率调整
            }
        else if(s_6==0)
            break;
        else
            {
                printf("输入无效\n");           //无效输入的反馈
                sleep(1);
            }
        }
}

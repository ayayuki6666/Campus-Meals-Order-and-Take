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
        printf("\t\t*  ѡ������ϵͳ  *\n");
        printf("\t\t*  1.����Աϵͳ    *\n");
        printf("\t\t*  2.�� �� ϵ ͳ   *\n");
        printf("\t\t*  0.��       ��   *\n");
        printf("\t\t********************\n");
        printf("\t\t������ѡ���ϵͳ\n");
        scanf("%d",&s_1);
        if(s_1==1)
            {
            system_admin();                   //�������Աϵͳ
            }
        else if(s_1==2)
            {
            system_user();                   //�����û�ϵͳ
            }
        else if(s_1==0)
            break;                             //�˳�
        else
            {
                printf("������Ч\n");        //��Ч�������
                sleep(1);
            }
    }
}

void system_admin()//Finished
{
    int s_2;
    char password_admin[20];
    printf("�������Ա����\n");
    scanf("%s",&password_admin);
    if(strcmp(password_admin,"admin")==0)
        while(1)
        {
        system("cls");
        printf("\t\t*********************\n");
        printf("\t\t*   ѡ��ʹ�õĹ���  *\n");
        printf("\t\t*   1.ѧ����Ϣ����  *\n");
        printf("\t\t*   2.�˵���Ϣ����  *\n");
        printf("\t\t*   3.��֤ϵͳ����  *\n");
        printf("\t\t*   0.��       ��   *\n");
        printf("\t\t*********************\n");
        printf("\t\t������Ҫʹ�ù��ܵı��\n");
        scanf("%d",&s_2);
        if(s_2==1)
            man_stu();                              //ѧ����Ϣ(��������)
        else if(s_2==2)
            man_menu();                             //�˵�����
        else if(s_2==3)
            man_yanzhen();                          //��֤����
        else if(s_2==0)
            break;                                  //�˳�����ϵͳ
        else
            {
            printf("������Ч\n");                   //��Ч�������
            sleep(1);
            }
        }
    else
    {
        printf("�������,���ز˵�ѡ��");
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
        printf("\t\t*     ѡ��ʹ�õĹ���       *\n");
        printf("\t\t*     1.��          ��     *\n");
        printf("\t\t*     2.ȡ          ��     *\n");
        printf("\t\t*     3.�� ѯ ȡ �� ��     *\n");
        printf("\t\t*     0.��          ��     *\n");
        printf("\t\t****************************\n");
        printf("\t\t������Ҫʹ�ù��ܵı��\n");
        scanf("%d",&s_3);
        if(s_3==1)
            order();                            //���
        else if(s_3==2)
            take();                             //ȡ��
        else if(s_3==3)
            chaxun();
        else if(s_3==0)
            break;                              //�˳��û�ϵͳ
        else
            {
                printf("������Ч\n");           //��Ч����ķ���
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
        printf("\t\t*   ѡ��ʹ�õĹ���   *\n");
        printf("\t\t*   1.�鿴ѧ����Ϣ   *\n");
        printf("\t\t*   2.ѧ��������   *\n");
        printf("\t\t*   3.��ʷ�����鿴   *\n");
        printf("\t\t*   0.��        ��   *\n");
        printf("\t\t**********************\n");
        printf("\t\t������Ҫʹ�ù��ܵı��\n");
        scanf("%d",&s_4);
        if(s_4==1)
            print_stu(head_stu);                    //ѧ����Ϣ��ʾ
        else if(s_4==2)
             {
                 head_stu=change(head_stu);
                 system("cls");
                 print_stu(head_stu);
             }                                      //ѧ��������
        else if(s_4==3)
            {
                print_indent(head_indent);
                getchar();
            }                                       //�鿴ѧ������ʷ����(�����г�)
        else if(s_4==0)
            break;
        else
            {
                printf("������Ч\n");           //��Ч����ķ���
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
        printf("\t\t*   ѡ��ʹ�õĹ���   *\n");
        printf("\t\t*   1.�޸Ĳ˵���Ϣ   *\n");
        printf("\t\t*   2. ɾ �� �� Ʒ   *\n");
        printf("\t\t*   3. �� �� �� Ʒ   *\n");
        printf("\t\t*   0. ��       ��   *\n");
        printf("\t\t**********************\n");
        printf("\t\t������Ҫʹ�ù��ܵı��\n");
        scanf("%d",&s_5);
        if(s_5==1)
                {
                 head_menu=tiaozhen(head_menu);         //�޸Ĳ˵��۸�
                 system("cls");
                }
        else if(s_5==2)
             {
                 head_menu=del(head_menu);              //ɾ����Ʒ
             }
        else if(s_5==3)
            {
                head_menu=additon(head_menu);           //��Ӳ�Ʒ
            }
        else if(s_5==0)
            break;
        else
            {
                printf("������Ч\n");           //��Ч����ķ���
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
        printf("\t\t*   ѡ���������        *\n");
        printf("\t\t*   1.������֤��λ��    *\n");
        printf("\t\t*   2.����������֤����  *\n");
        printf("\t\t*   0.��       ��       *\n");
        printf("\t\t*************************\n");
        printf("\t\t������Ҫʹ�ù��ܵı��\n");
        scanf("%d",&s_6);
        if(s_6==1)
            {
                change_weishu();                //��֤��λ������
            }
        else if(s_6==2)
            {
                change_gailv();                 //������֤���ʵ���
            }
        else if(s_6==0)
            break;
        else
            {
                printf("������Ч\n");           //��Ч����ķ���
                sleep(1);
            }
        }
}

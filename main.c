/*******************************************************
Author:�ѩ  Date��2021.07.12
У԰���ܵ�ȡ��ϵͳV5.2
Email��yaolin6666@gmail.com
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "datadefine.h"
int main()
{
    system("title У԰���ܵ�ȡ��ϵͳV5.2 Author:�ѩ Email:yaolin6666@gmail.com");
    head_menu=load_menu();
    head_stu=stu_load();
    head_indent=indent_load();
    load_yanzhen();
    system_main();
}

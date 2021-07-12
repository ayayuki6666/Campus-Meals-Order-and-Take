/*******************************************************
Author:绫雪  Date：2021.07.12
校园智能点取餐系统V5.2
Email：yaolin6666@gmail.com
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "datadefine.h"
int main()
{
    system("title 校园智能点取餐系统V5.2 Author:绫雪 Email:yaolin6666@gmail.com");
    head_menu=load_menu();
    head_stu=stu_load();
    head_indent=indent_load();
    load_yanzhen();
    system_main();
}

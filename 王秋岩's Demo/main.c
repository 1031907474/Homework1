#include <stdio.h>
#include <stdlib.h>
#include <string.h>//支持字符串操作
#define MAX 8//常量MAX表示系统要求的最大妃子数量

int main()
{   //使用字符数组表示字符串
    char emperorName[50];   //皇帝的名号
    int i, j, k, temp;                  //循环变量  临时变量
    int count = 7;          //当前未打入冷宫的嫔妃个数
    int lovebreak = 0;      //用来存放好感度低于60的妃嫔数量
    int choice;             //皇帝的选择1-4之间
    int searchIndex;    //用来存放查找到元素的下标
    char tempName[10];//用来存放临时字符串的字符数组
    char names[MAX][20] = {"貂蝉", "小乔", "不知火舞", "妲己", "王昭君", "孙尚香", "甄姬"};//嫔妃的姓名数组
    char levelNames[5][10] = {"答应", "常在", "贵妃", "皇贵妃", "皇后"};//妃嫔的级别数组
    int levels[MAX] = {2, 1, 0, 0, 3, 0, 0, -1};                                   //每个数组元素对应每个妃子的当前级别
    int loves[MAX] = {100, 100, 100, 100, 100, 100, 100, -1};                          //对应每个妃子的好感度，初始值为100


    printf("小游戏--刷皇上\n");
    printf("游戏提示：\n");
    printf("1、若同时有3个或以上的妃嫔好感度不大于60\n");
    printf("2、若后宫人数少于5人\n");
    printf("则后宫暴乱，皇帝卒\n");
    printf("想办法保住自己的皇位吧！\n\n");


    printf("\n****************************************************\n");
    printf("查看当前嫔妃的状态\n");
    printf("%-12s级别\t好感度\n", "姓名");
    for(i = 0; i < count; i++)
    {
        printf("%-12s%s\t%d\n", names[i], levelNames[levels[i]], loves[i]);
    }
    printf("****************************************************\n\n");


    printf("请输入当前登基的皇帝名号：");
    scanf("%s", emperorName);       //录入字符串，不需要&符号
    printf("\n");


    for(k = 0;; k++)//设置死循环
{

    printf("登基第%d天\n\n", k + 1);
    printf("皇帝（%s）驾临：“有事启奏，无事退朝！”\n", emperorName);

    printf("1、皇帝下旨选妃：\n");
    printf("2、翻牌宠幸：\n");
    printf("3、打入冷宫：\n");
    printf("4、单独召见\n");
    printf("陛下请选择今天要做的事：");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1://皇帝下旨选妃：（增加功能）
        //1.增加前需要判断数组有没有空间
        //2.增加数组元素（names、loves、 levels）
        if(count < MAX)
        {   //执行添加操作
            printf("\n请输入娘娘的名讳：");
            scanf("%s", names[count]);
            printf("\n");
            //将第count个元素的状态初始化
            levels[count] = 0;
            loves[count] = 100;
            for(i = 0; i < count; i++)
            {
                loves[i] -= 15;
            }
            count++;//添加完元素后，记得增加计数器
            printf("皇上又添新欢，（%s）入驻后宫，其他妃嫔好感度-15\n", names[count - 1]);
        }
        else
        {
            printf("陛下要注意身体呀，后宫已经人满为患啦！\n添加失败!\n");
        }
        break;
    case 2://翻牌宠幸（修改状态功能）
           //1.找到要宠幸妃子的下标
           //2.修改这个妃子的状态 好感度+10 ， 级别升一级 ， 如果最高级就不再升级
           //3.修改其他妃子的状态 好感度-10
           //需要解决的bug ：不支持姓名不存在的情况，请自行脑补完成
           printf("\n请输入今天要翻牌的妃子：");
           scanf("%s", tempName);
           printf("\n");
           //字符串的查找strcmp, 需要引入头文件<string.h>
           for(i = 0; i < count; i++)
           {
               if(strcmp(tempName, names[i]) ==0)//如果输入的名字刚好等于数组中的某个名字
               {
                   loves[i] += 10;
                   levels[i] = levels[i] >= 4 ? 4 : levels[i] + 1;//级别在0-4之间
               }
               else
               {
                   loves[i] -= 10;
               }
            }
            printf("\n都说了要雨露均沾，（%s）好感度+10、升级，其他妃子好感度-10\n", tempName);
        break;
    case 3://打入冷宫：（删除功能）
           //1.查找
           //2.后面一个赋值给前面一个元素
           //3.总数--
           //4.其他妃子 好感度+10
            searchIndex = -1;       //重置
            printf("\n请输入要打入冷宫的妃子：");
            scanf("%s", tempName);
            printf("\n");
            //循环查找
            for(i = 0; i < count; i++)
            {
                if(strcmp(tempName, names[i]) ==0)  //比较字符串是否相等
                {
                    searchIndex = i;
                    break;
                }
            }
            if(searchIndex == -1)//没有找到
            {
                printf("皇上，后宫并无此人\n");
                printf("虚惊一场，无人打入冷宫\n");
            }
            else
            {
                for(i = searchIndex; i < count - 1; i++)
                {
                    //names[i] = names[i + 1];是字符数组，C语言不支持数组的直接赋值
                    //我们需要使用strcpy函数实现数组的赋值
                    strcpy(names[i], names[i + 1]);

                }
                count--;
                for(i = 0; i < count; i++)
                {
                    loves[i] += 10;
                }
                printf("\n（%s）被打入冷宫，后宫又少了一条杂鱼，其他妃子好感度+10\n", tempName);
            }
        break;
    case 4://1.查找
           //2.增加好感度
            searchIndex = -1;       //重置
            printf("\n请输入召见的妃子：");
            scanf("%s", tempName);
            printf("\n");
           for(i = 0; i < count; i++)
            {
                if(strcmp(tempName, names[i]) ==0)  //比较字符串是否相等
                {
                    searchIndex = i;
                    break;
                }
            }
             if(-1 == searchIndex)//没有找到
            {
                printf("没有找到陛下要召见的妃子\n");
            }
            else
            {
                loves[searchIndex] += 5;
                printf("（%s）好感度+5，然而其他妃子并不知道\n", tempName);
            }
        break;
    default:
        printf("君无戏言，陛下明日请再次确认！\n");
        break;
    }
    //最后打印所以妃子状态前，以级别进行排序。使用冒泡排序
    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(levels[j] < levels[j + 1])
            {
                //需要交换姓名、级别、好感度
                temp = levels[j];
                levels[j] = levels[j + 1];
                levels[j + 1] = temp;
                temp = loves[j];
                loves[j] = loves[j + 1];
                loves[j + 1] = temp;
                strcpy(tempName, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], tempName);
            }
        }
    }
    printf("\n****************************************************\n");
    printf("查看当前嫔妃的状态\n");
    printf("%-12s级别\t好感度\n", "姓名");
    for(i = 0; i < count; i++)
    {
        printf("%-12s%s\t%d\n", names[i], levelNames[levels[i]], loves[i]);
    }
    printf("****************************************************\n\n");


    for(i = 0;i < count; i++)
    {
        if(loves[i] <= 60)       //如果好感度低于60
        lovebreak++;
    }
    if(lovebreak >= 3 || count <= 4)
    {
        printf("在位第%d天\n", k);
        printf("后宫暴乱\n皇帝（%s）卒\n", emperorName);
        printf("Game Over.");
        break;
    }
}
    printf("/n*****按任意键关闭程序*****");
    getchar();
    return 0;
}

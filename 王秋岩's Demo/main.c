#include <stdio.h>
#include <stdlib.h>
#include <string.h>//֧���ַ�������
#define MAX 8//����MAX��ʾϵͳҪ��������������

int main()
{   //ʹ���ַ������ʾ�ַ���
    char emperorName[50];   //�ʵ۵�����
    int i, j, k, temp;                  //ѭ������  ��ʱ����
    int count = 7;          //��ǰδ�����乬����������
    int lovebreak = 0;      //������źøжȵ���60����������
    int choice;             //�ʵ۵�ѡ��1-4֮��
    int searchIndex;    //������Ų��ҵ�Ԫ�ص��±�
    char tempName[10];//���������ʱ�ַ������ַ�����
    char names[MAX][20] = {"����", "С��", "��֪����", "槼�", "���Ѿ�", "������", "�缧"};//��������������
    char levelNames[5][10] = {"��Ӧ", "����", "����", "�ʹ���", "�ʺ�"};//���ɵļ�������
    int levels[MAX] = {2, 1, 0, 0, 3, 0, 0, -1};                                   //ÿ������Ԫ�ض�Ӧÿ�����ӵĵ�ǰ����
    int loves[MAX] = {100, 100, 100, 100, 100, 100, 100, -1};                          //��Ӧÿ�����ӵĺøжȣ���ʼֵΪ100


    printf("С��Ϸ--ˢ����\n");
    printf("��Ϸ��ʾ��\n");
    printf("1����ͬʱ��3�������ϵ����ɺøжȲ�����60\n");
    printf("2��������������5��\n");
    printf("��󹬱��ң��ʵ���\n");
    printf("��취��ס�Լ��Ļ�λ�ɣ�\n\n");


    printf("\n****************************************************\n");
    printf("�鿴��ǰ������״̬\n");
    printf("%-12s����\t�øж�\n", "����");
    for(i = 0; i < count; i++)
    {
        printf("%-12s%s\t%d\n", names[i], levelNames[levels[i]], loves[i]);
    }
    printf("****************************************************\n\n");


    printf("�����뵱ǰ�ǻ��Ļʵ����ţ�");
    scanf("%s", emperorName);       //¼���ַ���������Ҫ&����
    printf("\n");


    for(k = 0;; k++)//������ѭ��
{

    printf("�ǻ���%d��\n\n", k + 1);
    printf("�ʵۣ�%s�����٣����������࣬�����˳�����\n", emperorName);

    printf("1���ʵ���ּѡ����\n");
    printf("2�����Ƴ��ң�\n");
    printf("3�������乬��\n");
    printf("4�������ټ�\n");
    printf("������ѡ�����Ҫ�����£�");
    scanf("%d", &choice);

    switch(choice)
    {
    case 1://�ʵ���ּѡ���������ӹ��ܣ�
        //1.����ǰ��Ҫ�ж�������û�пռ�
        //2.��������Ԫ�أ�names��loves�� levels��
        if(count < MAX)
        {   //ִ����Ӳ���
            printf("\n��������������䣺");
            scanf("%s", names[count]);
            printf("\n");
            //����count��Ԫ�ص�״̬��ʼ��
            levels[count] = 0;
            loves[count] = 100;
            for(i = 0; i < count; i++)
            {
                loves[i] -= 15;
            }
            count++;//�����Ԫ�غ󣬼ǵ����Ӽ�����
            printf("���������»�����%s����פ�󹬣��������ɺøж�-15\n", names[count - 1]);
        }
        else
        {
            printf("����Ҫע������ѽ�����Ѿ�����Ϊ������\n���ʧ��!\n");
        }
        break;
    case 2://���Ƴ��ң��޸�״̬���ܣ�
           //1.�ҵ�Ҫ�������ӵ��±�
           //2.�޸�������ӵ�״̬ �øж�+10 �� ������һ�� �� �����߼��Ͳ�������
           //3.�޸��������ӵ�״̬ �øж�-10
           //��Ҫ�����bug ����֧�����������ڵ�������������Բ����
           printf("\n���������Ҫ���Ƶ����ӣ�");
           scanf("%s", tempName);
           printf("\n");
           //�ַ����Ĳ���strcmp, ��Ҫ����ͷ�ļ�<string.h>
           for(i = 0; i < count; i++)
           {
               if(strcmp(tempName, names[i]) ==0)//�����������ָպõ��������е�ĳ������
               {
                   loves[i] += 10;
                   levels[i] = levels[i] >= 4 ? 4 : levels[i] + 1;//������0-4֮��
               }
               else
               {
                   loves[i] -= 10;
               }
            }
            printf("\n��˵��Ҫ��¶��մ����%s���øж�+10���������������Ӻøж�-10\n", tempName);
        break;
    case 3://�����乬����ɾ�����ܣ�
           //1.����
           //2.����һ����ֵ��ǰ��һ��Ԫ��
           //3.����--
           //4.�������� �øж�+10
            searchIndex = -1;       //����
            printf("\n������Ҫ�����乬�����ӣ�");
            scanf("%s", tempName);
            printf("\n");
            //ѭ������
            for(i = 0; i < count; i++)
            {
                if(strcmp(tempName, names[i]) ==0)  //�Ƚ��ַ����Ƿ����
                {
                    searchIndex = i;
                    break;
                }
            }
            if(searchIndex == -1)//û���ҵ�
            {
                printf("���ϣ��󹬲��޴���\n");
                printf("�龪һ�������˴����乬\n");
            }
            else
            {
                for(i = searchIndex; i < count - 1; i++)
                {
                    //names[i] = names[i + 1];���ַ����飬C���Բ�֧�������ֱ�Ӹ�ֵ
                    //������Ҫʹ��strcpy����ʵ������ĸ�ֵ
                    strcpy(names[i], names[i + 1]);

                }
                count--;
                for(i = 0; i < count; i++)
                {
                    loves[i] += 10;
                }
                printf("\n��%s���������乬����������һ�����㣬�������Ӻøж�+10\n", tempName);
            }
        break;
    case 4://1.����
           //2.���Ӻøж�
            searchIndex = -1;       //����
            printf("\n�������ټ������ӣ�");
            scanf("%s", tempName);
            printf("\n");
           for(i = 0; i < count; i++)
            {
                if(strcmp(tempName, names[i]) ==0)  //�Ƚ��ַ����Ƿ����
                {
                    searchIndex = i;
                    break;
                }
            }
             if(-1 == searchIndex)//û���ҵ�
            {
                printf("û���ҵ�����Ҫ�ټ�������\n");
            }
            else
            {
                loves[searchIndex] += 5;
                printf("��%s���øж�+5��Ȼ���������Ӳ���֪��\n", tempName);
            }
        break;
    default:
        printf("����Ϸ�ԣ������������ٴ�ȷ�ϣ�\n");
        break;
    }
    //����ӡ��������״̬ǰ���Լ����������ʹ��ð������
    for(i = 0; i < count - 1; i++)
    {
        for(j = 0; j < count - i - 1; j++)
        {
            if(levels[j] < levels[j + 1])
            {
                //��Ҫ�������������𡢺øж�
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
    printf("�鿴��ǰ������״̬\n");
    printf("%-12s����\t�øж�\n", "����");
    for(i = 0; i < count; i++)
    {
        printf("%-12s%s\t%d\n", names[i], levelNames[levels[i]], loves[i]);
    }
    printf("****************************************************\n\n");


    for(i = 0;i < count; i++)
    {
        if(loves[i] <= 60)       //����øжȵ���60
        lovebreak++;
    }
    if(lovebreak >= 3 || count <= 4)
    {
        printf("��λ��%d��\n", k);
        printf("�󹬱���\n�ʵۣ�%s����\n", emperorName);
        printf("Game Over.");
        break;
    }
}
    printf("/n*****��������رճ���*****");
    getchar();
    return 0;
}

#define __CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAXSIZE 100

//定义学生住宿信息类
typedef struct
{
    long long stuID;
    char name[MAXSIZE];
    int roomID;
    long long stuCode;
} Stutype;

//定义学生结构体类
typedef struct
{
    Stutype S[MAXSIZE];
    int stunum;
} Student;

//定义模式串和匹配串的结构体
typedef struct
{
    char classID[MAXSIZE];
    int length;
} SqString;

//函数声明区域
void menu();                            //目录
void ReadInfo(Student *);               // 从文件中读入信息
void WriteInfo(Student *);              // 写入文件
void ShowAll(Student Stu);              // 展示文件信息
void stuID_Sort(Student *);             // 按照学号排序
void AddInfo(Student *);                //   增加信息
void DelInfo(Student *);                // 删除信息
void roomID_Sort(Student *);            // 按照宿舍号排序
void nameChange(Student *);             // 对姓名进行更改编码
void tenthCode(Student *);              //按照转换后的编码对姓名进行排序
void search_by_stuID(Student *);        //按照学号搜索
void search_by_roomID(Student *);       //按照宿舍号搜索
void search_by_nameCode(Student *);     //按照姓名搜索
void ChangeInfo(Student *);             //更改信息
void search_by_tenthname(Student *);    //按照姓名编码进行搜索
void search_again(int, int, Student *); //对宿舍信息重新搜一遍
void judgeRequire(Student *);           //判断是否需要进行班级匹配
int KMPIndex(SqString, SqString);       //KMP
void GetNext(SqString, int[]);          //next数组
void checkClass(Student *);             // 输出班级信息

//进入主函数
int main(void)
{
    Student stu;
    int a = 1;
    ReadInfo(&stu);
    printf("当前共有数据条数\n");
    printf("%d", stu.stunum);
    printf("\n");
    //初始时按照学号进行排序
    stuID_Sort(&stu);
    WriteInfo(&stu);
    printf("请输入需要进行操作的序号\n");
    while (a > 0)
    {
        menu();
        int i;
        scanf("%d", &i);
        switch (i)
        {

        case 0:
            exit(1);
        case 1:
            stuID_Sort(&stu);
            WriteInfo(&stu);
            search_by_stuID(&stu);
            break;
        case 2:
            nameChange(&stu);
            search_by_tenthname(&stu);
            break;
        case 3:
            roomID_Sort(&stu);
            WriteInfo(&stu);
            search_by_roomID(&stu);

            break;
        case 4:
            stuID_Sort(&stu);
            WriteInfo(&stu);
            ShowAll(stu);
            break;
        case 5:
            nameChange(&stu);
            tenthCode(&stu);
            WriteInfo(&stu);
            ShowAll(stu);
            break;
        case 6:
            roomID_Sort(&stu);
            WriteInfo(&stu);
            ShowAll(stu);
            break;
        case 7:
            AddInfo(&stu);
            break;
        case 8:
            DelInfo(&stu);
            break;
        case 9:
            ChangeInfo(&stu);
            break;
        default:
            printf("请正确输入");
            continue;
        }
    }

    return 0;
}
//函数定义区域
void menu()
{
    printf("***********学生住宿信息管理页面***************\n");
    printf("               请选择需要进行的功能           \n");
    printf("               1、根据学号查找学生            \n");
    printf("               2、根据姓名查找学生            \n");
    printf("               3、根据房号查找学生            \n");
    printf("               4、按照学号排序                \n");
    printf("               5、按照姓名排序                \n");
    printf("               6、按照房号排序                \n");
    printf("               7、增加信息                    \n");
    printf("               8、删除信息                    \n");
    printf("               9、编辑信息                    \n");
    printf("               0、退出                       \n");
    printf("**********************************************\n");
    printf("**********************************************\n");
}
//实现将文件内现有的信息进行读入(test)
void ReadInfo(Student *fstu)
{
    FILE *fp = fopen("studentInfo.txt", "r");
    int i = 0;
    if (fp == NULL)
    {
        printf("ERROR");
        exit(1);
    }
    while (1)
    {
        int n = fscanf(fp, "%lld %s %d\n", &fstu->S[i].stuID, fstu->S[i].name, &fstu->S[i].roomID);
        if (n == EOF)
        {
            break;
        }
        fstu->stunum = i + 1;
        i++;
    }
    fclose(fp);
}

//实现输入信息至文件
void WriteInfo(Student *fstu)
{
    FILE *fp = fopen("studentInfo.txt", "w");
    if (fp == NULL)
    {
        printf("ERROR");
        exit(1);
    }
    else
    {
        printf("successful");
        printf("\n");
    }
    for (int i = 0; i < fstu->stunum; i++)
    {
        fprintf(fp, "%lld\t%s\t%d\n", fstu->S[i].stuID, fstu->S[i].name, fstu->S[i].roomID);
    }
    fclose(fp);
}

//打印学生信息
void ShowAll(Student Stu)
{
    printf("学号\t\t姓名\t房号\n");
    for (int i = 0; i < Stu.stunum; i++)
    {
        printf("%lld\t%s\t%d\n", Stu.S[i].stuID, Stu.S[i].name, Stu.S[i].roomID);
    }
}
//按照学号排序(第四题按学号已实现)
void stuID_Sort(Student *fstu)
{
    int len = fstu->stunum;
    int i, j;
    Stutype temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if ((fstu->S[j].stuID) - (fstu->S[j + 1].stuID) > 0)
            {
                temp = (fstu->S[j]);
                (fstu->S[j]) = (fstu->S[j + 1]);
                (fstu->S[j + 1]) = temp;
            }
}
//增添学生信息
void AddInfo(Student *fstu)
{
    long long stuID;
    char name[MAXSIZE];
    int roomID;
    printf("请输入需要添加的学生信息（学号 姓名 宿舍号）");
    scanf("%lld %s %d", &stuID, name, &roomID);
    fstu->S[fstu->stunum].stuID = stuID;
    strcpy(fstu->S[fstu->stunum].name, name);
    fstu->S[fstu->stunum].roomID = roomID;
    fstu->stunum++;
    stuID_Sort(fstu);
    WriteInfo(fstu);
    printf("添加之后的排序情况\n"); //测试
    ShowAll(*fstu);
}
//删除学生信息
void DelInfo(Student *fstu)
{
    long long delID;
    printf("请输入需要删除的学生学号"); //使用查询学号匹配需要删除的数据记录
    scanf("%lld", &delID);
    int flag = 0;
    for (int i = 0; i < fstu->stunum; i++)
    {
        if (delID == fstu->S[i].stuID)
        {
            printf("找到对应记录，需要删除的学生是%s,住在%d房间", fstu->S[i].name, fstu->S[i].roomID);
            flag = 1;
            for (int k = i; k < fstu->stunum - 1; k++)
            {
                fstu->S[k] = fstu->S[k + 1];
            }
            fstu->stunum--;
        }
    }
    if (flag != 1)
    {
        printf("查无此人");
        printf("\n");
        return;
    }
    stuID_Sort(fstu);
    WriteInfo(fstu);
    ShowAll(*fstu);
}
//按照宿舍号排序(test已实现)
void roomID_Sort(Student *fstu)
{
    int len = fstu->stunum;
    int i, j;
    Stutype temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if ((fstu->S[j].roomID) - (fstu->S[j + 1].roomID) > 0)
            {
                temp = (fstu->S[j]);
                (fstu->S[j]) = (fstu->S[j + 1]);
                (fstu->S[j + 1]) = temp;
            }
}
//对姓名进行高八位和低八位转换
void nameChange(Student *fstu)
{
    for (int i = 0; i < fstu->stunum; i++)
    {
        char changebuf[MAXSIZE];
        strcpy(changebuf, fstu->S[i].name);
        int len = strlen(changebuf);
        if (len == 4)
        {
            fstu->S[i].stuCode = (unsigned char)changebuf[0] * 256 + (unsigned char)changebuf[1] + (unsigned char)changebuf[2] * 256 + (unsigned char)changebuf[3];
            //printf("\n");
            //  printf("%lld", fstu->S[i].stuCode);
        }
        else if (len == 6)
        {
            fstu->S[i].stuCode = (unsigned char)changebuf[0] * 256 + (unsigned char)changebuf[1] + (unsigned char)changebuf[2] * 256 + (unsigned char)changebuf[3] + (unsigned char)changebuf[4] * 256 + (unsigned char)changebuf[5];
            //printf("\n");
            //printf("%lld", fstu->S[i].stuCode);
        }
    }
    /*for (int i = 0; i < fstu->stunum; i++)
    {
        printf("%lld", fstu->S[i].stuCode);
        printf("\n");
    }*/
}
//按照学生的十六进制码进行排序(按照姓名排序已实现)
void tenthCode(Student *fstu)
{
    int len = fstu->stunum;
    int i, j;
    Stutype temp;
    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1 - i; j++)
            if ((fstu->S[j].stuCode) - (fstu->S[j + 1].stuCode) > 0)
            {
                temp = (fstu->S[j]);
                (fstu->S[j]) = (fstu->S[j + 1]);
                (fstu->S[j + 1]) = temp;
            }
}
//对学号进行二分查找
void search_by_stuID(Student *fstu)
{

    printf("请输入该学生的学号\n");
    long long key;
    scanf("%lld", &key);
    int resultnum = 0;
    int low, high, mid;
    low = 1;
    high = fstu->stunum;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (key == fstu->S[mid].stuID)
        {
            resultnum = mid;
            break;
        }
        else if (key < fstu->S[mid].stuID)
            high = mid - 1;
        else
            low = mid + 1;
    }
    printf("查询成功");
    printf("学号:%lld,姓名:%s,房号:%d\n", fstu->S[resultnum].stuID, fstu->S[resultnum].name, fstu->S[resultnum].roomID);
}
//对房号进行二分查找
//二分法查找房间号的过程中，如果出现同一宿舍号的现象，不会将所有人员信息全部显示出来
void search_by_roomID(Student *fstu)
{
    printf("请输入该学生的房号\n");
    int key;
    scanf("%d", &key);
    int resultnum = 0;
    int low, high, mid;
    low = 1;
    high = fstu->stunum;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (key == fstu->S[mid].roomID)
        {
            resultnum = mid;
            break;
        }
        else if (key < fstu->S[mid].roomID)
            high = mid - 1;
        else
        {
            low = mid + 1;
        }
    }
    printf("查询成功\n");
    printf("学号:%lld,姓名:%s,房号:%d\n", fstu->S[resultnum].stuID, fstu->S[resultnum].name, fstu->S[resultnum].roomID);
    search_again(fstu->S[resultnum].roomID, fstu->S[resultnum].stuID, fstu);
    judgeRequire(fstu);
}

//对姓名进行查找
//利用strcmp查找
void search_by_nameCode(Student *fstu)
{
    printf("请输入需要查找的学生姓名");
    char ch[MAXSIZE];
    scanf("%s", ch);
    int flag = 0;
    for (int i = 0; i < fstu->stunum; i++)
    {
        if (strcmp(ch, fstu->S[i].name) == 0)
        {
            printf("查找成功");
            printf("学号:%lld，姓名:%s,房号:%d\n", fstu->S[i].stuID, fstu->S[i].name, fstu->S[i].roomID);
            flag = 1;
            break;
        }
    }
    if (flag != 1)
    {
        printf("查无此人");
        printf("\n");
        return;
    }
}
//修改信息
void ChangeInfo(Student *fstu)
{
    printf("请输入该学生的学号\n");
    long long key;
    scanf("%lld", &key);
    int i;
    int flag = 0;
    for (i = 0; i < fstu->stunum; i++)
        if (fstu->S[i].stuID == key)
        {
            flag = 1;
            break;
        }
    if (flag == 0)
    {
        printf("查无此人");
        printf("\n");
        return;
    }
    printf("请依次输入修改后的学号\t姓名\t房号:\n");
    scanf("%lld %s %d", &fstu->S[i].stuID, fstu->S[i].name, &fstu->S[i].roomID);
    stuID_Sort(fstu);
    WriteInfo(fstu);
    printf("修改成功\n");
}
//对姓名进行查找(十进制编码查找）
void search_by_tenthname(Student *fstu)
{
    long long tenthcode;
    printf("请输入需要查找的学生姓名");
    char ch[MAXSIZE];
    scanf("%s", ch);
    int flag = 0;
    char temp[MAXSIZE];
    strcpy(temp, ch);
    int lnum = strlen(temp);
    for (int i = 0; i < fstu->stunum; i++)
    {
        if (lnum == 4)
        {
            tenthcode = (unsigned char)temp[0] * 256 + (unsigned char)temp[1] + (unsigned char)temp[2] * 256 + (unsigned char)temp[3];
        }
        else if (lnum == 6)
        {
            tenthcode = (unsigned char)temp[0] * 256 + (unsigned char)temp[1] + (unsigned char)temp[2] * 256 + (unsigned char)temp[3] + (unsigned char)temp[4] * 256 + (unsigned char)temp[5];
        }

        //printf("%lld", fstu->S[i].stuCode);
        if (tenthcode == fstu->S[i].stuCode)
        {
            printf("查找成功\n");
            printf("学号:%lld，姓名:%s,房号:%d\n", fstu->S[i].stuID, fstu->S[i].name, fstu->S[i].roomID);
            flag = 1;
        }
    }

    if (flag != 1)
    {
        printf("查无此人");
        printf("\n");
        return;
    }
}
//重新搜一遍，保证同一房间的全部搜出来
void search_again(int roomIDactual, int stuIDactual, Student *fstu)
{
    int len = fstu->stunum;
    for (int i = 0; i < len; i++)
    {
        if (fstu->S[i].roomID == roomIDactual && fstu->S[i].stuID != stuIDactual)
        {
            printf("学号:%lld，姓名:%s,房号:%d\n", fstu->S[i].stuID, fstu->S[i].name, fstu->S[i].roomID);
        }
    }
}
//查看某个班级的全部宿舍
void judgeRequire(Student *fstu)
{
    printf("是否需要求出班级宿舍的分配情况？Y/N\n");
    char choose[MAXSIZE];
    scanf("%s", choose);
    if (strcmp(choose, "Y") == 0)
    {
        checkClass(fstu);
    }
    else if (strcmp(choose, "N") == 0)
    {
        printf("no\n");
    }
}

//匹配班级
int KMPIndex(SqString s, SqString t) //KMP算法
{

    int next[MAXSIZE], i = 0, j = 0;
    GetNext(t, next);
    while (i < s.length && j < t.length)
    {
        if (j == -1 || s.classID[i] == t.classID[j])
        {
            i++;
            j++; //i,j各增1
        }
        else
            j = next[j];
    }
    if (j >= t.length)
        return (120); //返回匹配时标志
    else
        return (-1); //返回不匹配标志
}

void GetNext(SqString t, int next[]) //由模式串t求出next值
{
    int j, k;
    j = 0;
    k = -1;
    next[0] = -1; //第一个字符前无字符串，给值-1
    while (j < t.length - 1)

    {
        if (k == -1 || t.classID[j] == t.classID[k])
        {
            j++;
            k++;
            next[j] = k;
        }
        else
        {
            k = next[k];
        }
    }
}
void checkClass(Student *fstu)
{
    printf("请输入班号");
    //暂时将学号转换为字符串
    SqString sq;
    scanf("%s", sq.classID);
    sq.length = strlen(sq.classID);
    for (int i = 0; i < fstu->stunum; i++)
    {
        char classarray[MAXSIZE];
        itoa(fstu->S[i].stuID, classarray, 10);
        SqString eq;
        strcpy(eq.classID, classarray);
        eq.length = strlen(classarray);
        int res = KMPIndex(eq, sq);
        if (res == 120)
        {
            printf("学号:%lld,姓名:%s,房号:%d\n", fstu->S[i].stuID, fstu->S[i].name, fstu->S[i].roomID);
        }
    }
}
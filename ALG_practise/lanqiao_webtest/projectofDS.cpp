#define __CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <Windows.h>
#define MAXSIZE 100

//����ѧ��ס����Ϣ��
typedef struct
{
    long long stuID;
    char name[MAXSIZE];
    int roomID;
    long long stuCode;
} Stutype;

//����ѧ���ṹ����
typedef struct
{
    Stutype S[MAXSIZE];
    int stunum;
} Student;

//����ģʽ����ƥ�䴮�Ľṹ��
typedef struct
{
    char classID[MAXSIZE];
    int length;
} SqString;

//������������
void menu();                            //Ŀ¼
void ReadInfo(Student *);               // ���ļ��ж�����Ϣ
void WriteInfo(Student *);              // д���ļ�
void ShowAll(Student Stu);              // չʾ�ļ���Ϣ
void stuID_Sort(Student *);             // ����ѧ������
void AddInfo(Student *);                //   ������Ϣ
void DelInfo(Student *);                // ɾ����Ϣ
void roomID_Sort(Student *);            // �������������
void nameChange(Student *);             // ���������и��ı���
void tenthCode(Student *);              //����ת����ı����������������
void search_by_stuID(Student *);        //����ѧ������
void search_by_roomID(Student *);       //�������������
void search_by_nameCode(Student *);     //������������
void ChangeInfo(Student *);             //������Ϣ
void search_by_tenthname(Student *);    //�������������������
void search_again(int, int, Student *); //��������Ϣ������һ��
void judgeRequire(Student *);           //�ж��Ƿ���Ҫ���а༶ƥ��
int KMPIndex(SqString, SqString);       //KMP
void GetNext(SqString, int[]);          //next����
void checkClass(Student *);             // ����༶��Ϣ

//����������
int main(void)
{
    Student stu;
    int a = 1;
    ReadInfo(&stu);
    printf("��ǰ������������\n");
    printf("%d", stu.stunum);
    printf("\n");
    //��ʼʱ����ѧ�Ž�������
    stuID_Sort(&stu);
    WriteInfo(&stu);
    printf("��������Ҫ���в��������\n");
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
            printf("����ȷ����");
            continue;
        }
    }

    return 0;
}
//������������
void menu()
{
    printf("***********ѧ��ס����Ϣ����ҳ��***************\n");
    printf("               ��ѡ����Ҫ���еĹ���           \n");
    printf("               1������ѧ�Ų���ѧ��            \n");
    printf("               2��������������ѧ��            \n");
    printf("               3�����ݷ��Ų���ѧ��            \n");
    printf("               4������ѧ������                \n");
    printf("               5��������������                \n");
    printf("               6�����շ�������                \n");
    printf("               7��������Ϣ                    \n");
    printf("               8��ɾ����Ϣ                    \n");
    printf("               9���༭��Ϣ                    \n");
    printf("               0���˳�                       \n");
    printf("**********************************************\n");
    printf("**********************************************\n");
}
//ʵ�ֽ��ļ������е���Ϣ���ж���(test)
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

//ʵ��������Ϣ���ļ�
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

//��ӡѧ����Ϣ
void ShowAll(Student Stu)
{
    printf("ѧ��\t\t����\t����\n");
    for (int i = 0; i < Stu.stunum; i++)
    {
        printf("%lld\t%s\t%d\n", Stu.S[i].stuID, Stu.S[i].name, Stu.S[i].roomID);
    }
}
//����ѧ������(�����ⰴѧ����ʵ��)
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
//����ѧ����Ϣ
void AddInfo(Student *fstu)
{
    long long stuID;
    char name[MAXSIZE];
    int roomID;
    printf("��������Ҫ��ӵ�ѧ����Ϣ��ѧ�� ���� ����ţ�");
    scanf("%lld %s %d", &stuID, name, &roomID);
    fstu->S[fstu->stunum].stuID = stuID;
    strcpy(fstu->S[fstu->stunum].name, name);
    fstu->S[fstu->stunum].roomID = roomID;
    fstu->stunum++;
    stuID_Sort(fstu);
    WriteInfo(fstu);
    printf("���֮����������\n"); //����
    ShowAll(*fstu);
}
//ɾ��ѧ����Ϣ
void DelInfo(Student *fstu)
{
    long long delID;
    printf("��������Ҫɾ����ѧ��ѧ��"); //ʹ�ò�ѯѧ��ƥ����Ҫɾ�������ݼ�¼
    scanf("%lld", &delID);
    int flag = 0;
    for (int i = 0; i < fstu->stunum; i++)
    {
        if (delID == fstu->S[i].stuID)
        {
            printf("�ҵ���Ӧ��¼����Ҫɾ����ѧ����%s,ס��%d����", fstu->S[i].name, fstu->S[i].roomID);
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
        printf("���޴���");
        printf("\n");
        return;
    }
    stuID_Sort(fstu);
    WriteInfo(fstu);
    ShowAll(*fstu);
}
//�������������(test��ʵ��)
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
//���������и߰�λ�͵Ͱ�λת��
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
//����ѧ����ʮ���������������(��������������ʵ��)
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
//��ѧ�Ž��ж��ֲ���
void search_by_stuID(Student *fstu)
{

    printf("�������ѧ����ѧ��\n");
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
    printf("��ѯ�ɹ�");
    printf("ѧ��:%lld,����:%s,����:%d\n", fstu->S[resultnum].stuID, fstu->S[resultnum].name, fstu->S[resultnum].roomID);
}
//�Է��Ž��ж��ֲ���
//���ַ����ҷ���ŵĹ����У��������ͬһ����ŵ����󣬲��Ὣ������Ա��Ϣȫ����ʾ����
void search_by_roomID(Student *fstu)
{
    printf("�������ѧ���ķ���\n");
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
    printf("��ѯ�ɹ�\n");
    printf("ѧ��:%lld,����:%s,����:%d\n", fstu->S[resultnum].stuID, fstu->S[resultnum].name, fstu->S[resultnum].roomID);
    search_again(fstu->S[resultnum].roomID, fstu->S[resultnum].stuID, fstu);
    judgeRequire(fstu);
}

//���������в���
//����strcmp����
void search_by_nameCode(Student *fstu)
{
    printf("��������Ҫ���ҵ�ѧ������");
    char ch[MAXSIZE];
    scanf("%s", ch);
    int flag = 0;
    for (int i = 0; i < fstu->stunum; i++)
    {
        if (strcmp(ch, fstu->S[i].name) == 0)
        {
            printf("���ҳɹ�");
            printf("ѧ��:%lld������:%s,����:%d\n", fstu->S[i].stuID, fstu->S[i].name, fstu->S[i].roomID);
            flag = 1;
            break;
        }
    }
    if (flag != 1)
    {
        printf("���޴���");
        printf("\n");
        return;
    }
}
//�޸���Ϣ
void ChangeInfo(Student *fstu)
{
    printf("�������ѧ����ѧ��\n");
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
        printf("���޴���");
        printf("\n");
        return;
    }
    printf("�����������޸ĺ��ѧ��\t����\t����:\n");
    scanf("%lld %s %d", &fstu->S[i].stuID, fstu->S[i].name, &fstu->S[i].roomID);
    stuID_Sort(fstu);
    WriteInfo(fstu);
    printf("�޸ĳɹ�\n");
}
//���������в���(ʮ���Ʊ�����ң�
void search_by_tenthname(Student *fstu)
{
    long long tenthcode;
    printf("��������Ҫ���ҵ�ѧ������");
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
            printf("���ҳɹ�\n");
            printf("ѧ��:%lld������:%s,����:%d\n", fstu->S[i].stuID, fstu->S[i].name, fstu->S[i].roomID);
            flag = 1;
        }
    }

    if (flag != 1)
    {
        printf("���޴���");
        printf("\n");
        return;
    }
}
//������һ�飬��֤ͬһ�����ȫ���ѳ���
void search_again(int roomIDactual, int stuIDactual, Student *fstu)
{
    int len = fstu->stunum;
    for (int i = 0; i < len; i++)
    {
        if (fstu->S[i].roomID == roomIDactual && fstu->S[i].stuID != stuIDactual)
        {
            printf("ѧ��:%lld������:%s,����:%d\n", fstu->S[i].stuID, fstu->S[i].name, fstu->S[i].roomID);
        }
    }
}
//�鿴ĳ���༶��ȫ������
void judgeRequire(Student *fstu)
{
    printf("�Ƿ���Ҫ����༶����ķ��������Y/N\n");
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

//ƥ��༶
int KMPIndex(SqString s, SqString t) //KMP�㷨
{

    int next[MAXSIZE], i = 0, j = 0;
    GetNext(t, next);
    while (i < s.length && j < t.length)
    {
        if (j == -1 || s.classID[i] == t.classID[j])
        {
            i++;
            j++; //i,j����1
        }
        else
            j = next[j];
    }
    if (j >= t.length)
        return (120); //����ƥ��ʱ��־
    else
        return (-1); //���ز�ƥ���־
}

void GetNext(SqString t, int next[]) //��ģʽ��t���nextֵ
{
    int j, k;
    j = 0;
    k = -1;
    next[0] = -1; //��һ���ַ�ǰ���ַ�������ֵ-1
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
    printf("��������");
    //��ʱ��ѧ��ת��Ϊ�ַ���
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
            printf("ѧ��:%lld,����:%s,����:%d\n", fstu->S[i].stuID, fstu->S[i].name, fstu->S[i].roomID);
        }
    }
}
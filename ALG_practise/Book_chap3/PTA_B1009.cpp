//����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������
//�����������һ��������������һ���ڸ����ܳ��Ȳ����� 80 ���ַ������ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣���ɵ��ַ���������֮���� 1 ���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�
//���㷨�ʼǡ�3.6   �ַ�������
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 90;
int main(void)
{
    char str[MAX]; //���޶����ַ����ȶ�һЩ
    //fgets(str, MAX, stdin);
    //gets_s(str, MAX);
    cin.getline(str, MAX);
    int len = strlen(str);
    char array[MAX][MAX];
    int r = 0;
    int h = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] != ' ')
        {
            array[r][h++] = str[i];
        }
        else
        {
            array[r][h] = '\0';
            r++;
            h = 0;
        }
    }
    for (int i = r; i >= 0; i--)
    {
        printf("%s", array[i]);
        if (i > 0)
        {
            printf(" ");
        }
    }
    return 0;
}

//给定一句英语，要求你编写程序，将句中所有单词的顺序颠倒输出。
//测试输入包含一个测试用例，在一行内给出总长度不超过 80 的字符串。字符串由若干单词和若干空格组成，其中单词是由英文字母（大小写有区分）组成的字符串，单词之间用 1 个空格分开，输入保证句子末尾没有多余的空格。
//《算法笔记》3.6   字符串处理
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 90;
int main(void)
{
    char str[MAX]; //比限定的字符长度多一些
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

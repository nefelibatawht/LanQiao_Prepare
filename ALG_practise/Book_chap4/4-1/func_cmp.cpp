#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool cmp(int, int);
int main(void)
{
    /*
    �ȽϺ������÷�
    �ȽϺ�������ȷ��һ�����򷽷����������
    */
    int a[6] = {6, 2, 9, -1, 3, 4};
    sort(a, a + 6, cmp);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
        // ��������9 6 4 3 2 -1
    }
    int b[6] = {6, 2, 9, -1, 3, 4};
    sort(b, b + 4, cmp); //����ǰ4��Ԫ��
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", b[i]);
        // ��������9 6 2 -1    δ���򲿷֣� 3 4
    }
    return 0;
}

bool cmp(int m, int n)
{
    return m > n; //�ȽϹ���Ϊ�Ӵ�С
}
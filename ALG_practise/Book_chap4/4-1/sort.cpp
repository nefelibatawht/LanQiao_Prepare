#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(void)
{
    int a[6] = {6, 2, 9, -1, 3, 4};
    sort(a, a + 6);
    //sort()�������÷���
    //sort(��Ԫ�صĵ�ַ������)����Ҫ�����βԪ�ص���һ���ַ��������ȽϺ���(ѡ��))��Ĭ�ϴ�С����
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
        // ��������-1 2 3 4 6 9
    }
    int b[6] = {6, 2, 9, -1, 3, 4};
    sort(b, b + 4); //����ǰ4��Ԫ��
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", b[i]);
        // ��������-1 2 6 9    δ���򲿷֣� 3 4
    }
    return 0;
}
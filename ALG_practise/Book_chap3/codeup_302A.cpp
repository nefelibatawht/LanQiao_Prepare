// ��������������ɲ���������ÿ�����������ĸ�ʽΪ
// ��1�У�N
// ��2�У�N��ѧ���ĳɼ���������������һ���ո����� ��3�У���������
// ������N = 0ʱ�������������N������1000���ɼ�����Ϊ��������0��100֮���һ��������
#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n, i, a[1000], score, count;
    while (cin >> n)
    {
        if (n == 0)
            return 0;
        memset(a, 0, sizeof(a));
        for (i = 0; i < n; i++)
            cin >> a[i];
        cin >> score;
        count = 0;
        for (i = 0; i < n; i++)
            if (score == a[i])
                count++;
        cout << count << endl;
    }
    return 0;
}

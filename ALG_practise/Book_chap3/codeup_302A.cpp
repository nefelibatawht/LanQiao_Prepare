// 测试输入包含若干测试用例，每个测试用例的格式为
// 第1行：N
// 第2行：N名学生的成绩，相邻两数字用一个空格间隔。 第3行：给定分数
// 当读到N = 0时输入结束。其中N不超过1000，成绩分数为（包含）0到100之间的一个整数。
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

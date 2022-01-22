#include <bits/stdc++.h>
#include <iostream>
using namespace std;
bool cmp(int, int);
int main(void)
{
    /*
    比较函数的用法
    比较函数用于确定一种排序方法的排序规则
    */
    int a[6] = {6, 2, 9, -1, 3, 4};
    sort(a, a + 6, cmp);

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
        // 输出结果：9 6 4 3 2 -1
    }
    int b[6] = {6, 2, 9, -1, 3, 4};
    sort(b, b + 4, cmp); //排序前4个元素
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", b[i]);
        // 输出结果：9 6 2 -1    未排序部分： 3 4
    }
    return 0;
}

bool cmp(int m, int n)
{
    return m > n; //比较规则为从大到小
}
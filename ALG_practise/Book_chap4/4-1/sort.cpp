#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(void)
{
    int a[6] = {6, 2, 9, -1, 3, 4};
    sort(a, a + 6);
    //sort()函数的用法：
    //sort(首元素的地址（必填)，需要排序的尾元素的下一块地址（必填），比较函数(选填))，默认从小到大
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", a[i]);
        // 输出结果：-1 2 3 4 6 9
    }
    int b[6] = {6, 2, 9, -1, 3, 4};
    sort(b, b + 4); //排序前4个元素
    for (int i = 0; i < 6; i++)
    {
        printf("%d ", b[i]);
        // 输出结果：-1 2 6 9    未排序部分： 3 4
    }
    return 0;
}
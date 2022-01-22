//对输入的n个数进行排序并输出。
//输入的第一行包括一个整数n(1<=n<=100)。 接下来的一行包括n个整数。
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int a[110];
    while (scanf("%d", &n) != EOF)
    {

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++)
        {
            printf("%d", a[i]);
            if (i < n - 1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

/*输入一个数n，然后输入n个数值各不相同，再输入一个值x，输出这个值在这个数组中的下标（从0开始，若不在数组中则输出-1）。*/
#include <iostream>
using namespace std;
const int MAX = 100010;
int main(void)
{
    int num;
    int array[MAX];
    while (scanf("%d", &num) != EOF)
    {
        for (int i = 0; i < num; i++)
        {
            scanf("%d", &array[i]);
        }

        int x, j;
        scanf("%d", &x);
        for (j = 0; j < num; j++)
        {
            if (x == array[j])
            {
                printf("%d\n", j);
                break;
            }
        }
        if (j == num)
        {
            printf("-1\n");
        }
    }
    return 0;
}
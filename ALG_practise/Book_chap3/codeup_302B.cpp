/*����һ����n��Ȼ������n����ֵ������ͬ��������һ��ֵx��������ֵ����������е��±꣨��0��ʼ�������������������-1����*/
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
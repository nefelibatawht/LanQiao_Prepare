#include <bits/stdc++.h> 
using namespace std;
int main(void)
{
    int N;
    scanf("%d", &N);
    int array[110] = {0};
    for (int j = 0; j < N; j++)
    {
        scanf("%d", &array[j]);
    }
    sort(array, array + N);
    for (int j = 0; j < N; j++)
    {
        printf("%d ", array[j]);
    }
    return 0;
}
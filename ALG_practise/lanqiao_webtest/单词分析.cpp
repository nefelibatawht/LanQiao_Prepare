#include <iostream>
using namespace std;
int main()
{
    int count[26] = { 0 };
    int max = 0, a;
    char ch;
    while ((ch = getchar()) != '\n') {
        count[ch - 'a']++;
    }
    for (a = 1; a < 26; a++) {
        if (count[a] > count[max]) {
            max = a;
        }
    }
    printf("%c\n%d", max + 'a', count[max]);
    return 0;
}
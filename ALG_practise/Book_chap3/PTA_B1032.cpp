#define __CRT_SECURE_NO_WARNINGS 
#pragma warning (disable:4996)
/*为了用事实说明挖掘机技术到底哪家强，PAT 组织了一场挖掘机技能大赛。现请你根据比赛结果统计出技术最强的那个学校。

输入格式：
输入在第 1 行给出不超过 10
5
的正整数 N，即参赛人数。随后 N 行，每行给出一位参赛者的信息和成绩，包括其所代表的学校的编号（从 1 开始连续编号）、及其比赛成绩（百分制），中间以空格分隔。

输出格式：
在一行中给出总得分最高的学校的编号、及其总分，中间以空格分隔。题目保证答案唯一，没有并列。*/
#include <iostream>
using namespace std;
const int maxn = 100010;
int schoolnum[maxn] = { 0 };
int main(void) {
	int num; int schoolID; int schoolScore;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d %d", &schoolID, &schoolScore);
		schoolnum[schoolID] += schoolScore;
	}
	int point = 1;//记录最高分数的学校 
	int MAX = -1;
	for (int i = 1; i <= num; i++)  //千万注意，这里下标是从1开始的 
	{
		if (schoolnum[i] > MAX) {
			MAX = schoolnum[i];
			point = i;
		}
	}
	printf("%d %d", point, MAX);
	return 0;
}

/*

Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (��100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (��300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:
For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.
��n��������ÿ���������������ɵĿ������������������Ŀ�����׼��֤�źͷ�����Ҫ�����п����ķ����������У�������˳�����������׼��֤�ţ����������������Լ������ڵ�����
*/
/**
 * �ύPATϵͳʱ��Ҫ��ͷ�ļ��ĳ�iostream��cstring��algorithm����ʽ 
*/
#include <bits/stdc++.h>
using namespace std;
struct Student
{
    char idnum[15];
    int score;
    int test_location;
    int location_rank;
} stu[30010];
bool cmp(Student, Student);
int main(void)
{
    int N, K;
    int num = 0; //���忼������,���ܹ���ѧ����
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {

        scanf("%d", &K);
        for (int j = 0; j < K; j++)
        {
            scanf("%s %d", stu[num].idnum, &stu[num].score);
            stu[num].test_location = i;
            num++;
        }
        sort(stu + num - K, stu + num, cmp);
        stu[num - K].location_rank = 1;
        for (int j = num - K + 1; j < num; j++)
        {
            if (stu[j].score == stu[j - 1].score)
            {
                stu[j].location_rank = stu[j - 1].location_rank;
            }
            else
            {
                stu[j].location_rank = j + 1 - (num - K);
            }
        }
    }
    sort(stu, stu + num, cmp);
    printf("%d\n", num);
    int r = 1;
    for (int j = 0; j < num; j++)
    {

        if (j > 0 && stu[j].score != stu[j - 1].score)
        {
            r = j + 1;
        }
        printf("%s ", stu[j].idnum);
        printf("%d %d %d\n", r, stu[j].test_location, stu[j].location_rank);
    }
    return 0;
}

//��׼��֤�Ž��еĽ�������
bool cmp(Student a, Student b)
{
    if (a.score != b.score)
    {
        return a.score > b.score;
    }
    else
    {
        return (strcmp(a.idnum, b.idnum) < 0);
    }
}
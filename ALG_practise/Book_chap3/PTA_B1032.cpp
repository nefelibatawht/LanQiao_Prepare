#define __CRT_SECURE_NO_WARNINGS 
#pragma warning (disable:4996)
/*Ϊ������ʵ˵���ھ�����������ļ�ǿ��PAT ��֯��һ���ھ�����ܴ�������������ݱ������ͳ�Ƴ�������ǿ���Ǹ�ѧУ��

�����ʽ��
�����ڵ� 1 �и��������� 10
5
�������� N����������������� N �У�ÿ�и���һλ�����ߵ���Ϣ�ͳɼ����������������ѧУ�ı�ţ��� 1 ��ʼ������ţ�����������ɼ����ٷ��ƣ����м��Կո�ָ���

�����ʽ��
��һ���и����ܵ÷���ߵ�ѧУ�ı�š������ܷ֣��м��Կո�ָ�����Ŀ��֤��Ψһ��û�в��С�*/
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
	int point = 1;//��¼��߷�����ѧУ 
	int MAX = -1;
	for (int i = 1; i <= num; i++)  //ǧ��ע�⣬�����±��Ǵ�1��ʼ�� 
	{
		if (schoolnum[i] > MAX) {
			MAX = schoolnum[i];
			point = i;
		}
	}
	printf("%d %d", point, MAX);
	return 0;
}

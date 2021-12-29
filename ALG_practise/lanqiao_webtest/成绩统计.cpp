#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char info[20];
    int grade[2];
    struct node* link;
};
int main()
{
    struct node* creat(struct node* head, int n);
    void print(struct node* head);
    struct node* h, * p, * q;
    int n;
    h = NULL;
    p = h;
    q = h;
    scanf_s("%d", &n);
    h = creat(h, n);
    print(h);
    printf("\n");
    return 0;
}
struct node* creat(struct node* head, int n)
{
    struct node* p, * q;
    p = (struct node*)malloc(sizeof(struct node));
    scanf_s("%s%d%d", p->info ,20,&p->grade[0], &p->grade[1]);
    head = p;
    q = p;
    for (int i = 1; i < n; i++)
    {
        p = (struct node*)malloc(sizeof(struct node));
        scanf_s("%s%d%d", p->info,20, &p->grade[0], &p->grade[1]);
        q->link = p;
        q = p;
    }
    q->link = NULL;
    return head;
}
void print(struct node* head)
{
    struct node* p;
    for (p = head; p != NULL; p = p->link)
    {
        printf("%s: %d %d\n", p->info,20, p->grade[0], p->grade[1]);
    }
}

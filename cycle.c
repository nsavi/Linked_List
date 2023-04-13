#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    int visit;
}*first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->visit = 1;
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->visit = i+1;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
int cycle()
{
    struct Node *y =first;
    struct Node *e =first;
    while(e && e->next)
    {
        y=y->next;
        e=e->next->next;
        if(e==y)
        {
            return 1;
        }
    }
    return 2;
}
int main()
{
    struct Node *temp;
    int A[] = {1,4,6,8};
    create(A, 4);
    Display(first);
    first->next->next->next->next=first->next;
    if(cycle()==1)
        printf("\nloop exist");
    else if(cycle()==2)
        printf("\nloop doesnt exist");
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for(i=1; i<n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
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

int count(struct Node *p)
{
    int l=0;//length
    while(p!=NULL)
    {
        l++;
        p=p->next;
    }
    return l;
}

int Rcount(struct Node *p)//recursive count function
{
    if(p==0)//if p=NULL
        return 0;
    else
        return Rcount(p->next)+1;
}

int sum(struct Node *p)
{
    int s=0;
    while(p!= NULL)
    {
        s=s+p->data;
        p=p->next;
    }
    return s;
}
int Rsum(struct Node *p)//recursive sum function
{
    if(p==0)
        return 0;
    else
        return Rsum(p->next)+p->data;
}

int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    Display(first);
    printf("\nLength is %d",count(first));
    printf("\nLength is %d",Rcount(first));
    printf("\nSum is %d",sum(first));
    printf("\nSum is %d",Rsum(first));
    return 0;
}

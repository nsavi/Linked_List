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
void firsttolast()
{
    if(first == NULL || first->next == NULL)
        return;
    struct Node *temp = first;
    first = first->next;

    struct Node *p = first;
    while(p->next != NULL)
        p = p->next;

    p->next = temp;
    temp->next = NULL;
}

int main()
{
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    Display(first);
    printf("\n");
    firsttolast();
    Display(first);
    return 0;
}

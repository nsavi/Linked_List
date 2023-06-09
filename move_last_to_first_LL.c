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
void lasttofirst()
{
    if(first == NULL || first->next == NULL) // if the list is empty or has only one node
        return;

    struct Node *p = first;
    struct Node *last = NULL;
    while(p->next != NULL)
    {
        last = p;
        p = p->next;
    }

    last->next = NULL;
    p->next = first;
    first = p;
}

int main()
{
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    Display(first);
    printf("\n");
    lasttofirst();
    Display(first);
    return 0;
}

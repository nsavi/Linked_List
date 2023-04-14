#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*head;

void create(int a[], int n)
{
    int i;
    struct Node *t, *last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = a[0];
    head->next = head;
    last = head;
    
    for(i = 1; i < n; i++)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = a[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while(h != head);
    printf("\n");
}

int length(struct Node *p)
{
    int len = 0;
    do
    {
        len++;
        p = p->next;
    } while(p != head);
    return len;
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if(index < 0 || index > length(head))
        return;
    if(index == 0)
    {
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        if(head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while(p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for(i = 0; i < index-1; i++)
        {
            p = p->next;
        }
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
int delete(struct Node *p,int index)
{
    struct Node *q;
    int i,x;
    
    if(index < 0 || index  > length(head))
        return -1;
    if(index == 1)
    {
        while(p->next!=head)
        {
            p = p->next;
        }
        x=head->data;
        if(head == p)//if head is the only node
        {
            free(head);
            head = NULL;
        }
        else
        {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    }
    else
    {
        for(i=0;i<index-2;i++)
            p=p->next;
        q=p->next;
        p->next = q->next;
        x=q->data;
        free(q);
    }
    return x;
}
int main() 
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(head);
    printf("\n");
    insert(head,5,10);
    display(head);
    printf("\n");
    delete(head,2);
    display(head);
    return 0;
}

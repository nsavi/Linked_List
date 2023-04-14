#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
}*head;

void create(int a[],int  n)
{
    int i;
    struct Node *t,*last;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data=a[0];
    head->next=head;
    last = head;
    
    for(i=1;i<n;i++)
    {
        t  = (struct Node  *)malloc(sizeof(struct Node));
        t->data=a[i];
        t->next=last->next;
        last->next =t;
        last =  t;
    }
}
void display(struct Node *h)
{
    do
    {
        printf("%d ",h->data);
        h=h->next;
    }while(h!=head);
    printf("\n");
}

int main() 
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(head);
    return 0;
}
    

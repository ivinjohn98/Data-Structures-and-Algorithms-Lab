#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define MAX 100
struct node
{
    long long int data;
    struct node *next;
};
typedef struct node NODE;
struct Queue
{
    NODE *head,*tail;
};
typedef struct Queue QUE;
QUE *createQueue()
{
    QUE *Q=(QUE*)malloc(sizeof(QUE));
    Q->head=Q->tail=NULL;
    return Q;
}
NODE* newnode(long long int k)
{
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->data=k;
    temp->next=NULL;
    return temp;
}
void enqueue(QUE *Q)
{
    long long int k;
    scanf("%lld",&k);
    NODE *temp=newnode(k);
    if((Q->tail)==NULL)
    {
        Q->tail=temp;
        Q->head=temp;
    }
    else
    {
        Q->tail->next=temp;
        Q->tail=temp;
    }
}
void dequeue(QUE *Q)
{
    NODE *temp;
    if(Q->head==NULL)
    {
        printf("-1");
        return;
    }
    if(Q->head!=Q->tail)
    {
        temp=Q->head;
        Q->head=Q->head->next;
        temp->next=NULL;
        printf("%lld",temp->data);
    }
    else
    {
        temp=Q->head;
        Q->head=NULL;
        Q->tail=NULL;
        printf("%lld",temp->data);
    }
}
void display(QUE *Q)
{
    NODE *temp=Q->head;
    while(temp!=NULL)
    {
        printf("%lld ",temp->data);
        temp=temp->next;
    }
}
main()
{
    char choice;
    QUE *Q=createQueue();
    while(1)
    {
        scanf("%c",&choice);
        switch(choice)
        {
            case 'e':
            enqueue(Q);
            break;
            case 'd':
            dequeue(Q);
            break;
            case 'p':
            display(Q);
            break;
            case 's':
            return;
        }
    }
}

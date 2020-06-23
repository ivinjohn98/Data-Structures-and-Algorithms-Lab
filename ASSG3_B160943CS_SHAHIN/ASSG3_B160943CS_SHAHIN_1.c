#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    long long int data;
    struct node *next;
};
typedef struct node NODE;
NODE* reverse(NODE *head)
{
    NODE *cur=head;
    NODE *pre=NULL;
    NODE *nex;
    while(cur!=NULL)
    {
        nex=cur->next;
        cur->next=pre;
        pre=cur;
        cur=nex;
    }
    head=pre;
    return head;
}
void printlinked_list(NODE *head)
{
    NODE *temp=head;
    while(temp!=NULL)
    {
        printf("%lld ",temp->data);
        temp=temp->next;
    }
}
NODE* getlinked_list(int c)
{
    NODE *head,*first=NULL,*temp=NULL;
    long long int b;
    char nl;
    do
    {
        head=(NODE*)malloc(sizeof(NODE));
        scanf("%lld",&b);
        nl=getchar();
        head->data=b;
        if(first!=NULL)
        {
            temp->next=head;
            temp=head;
        }
        else
        {
            temp=head;
            first=temp;
        }

    } while(nl!='\n');
    temp->next=NULL;
    return first;
}
int main()
{
    NODE *head = NULL;
    printf("Given linked list\n");
    head=getlinked_list(0);
    head=reverse(head);
    printf("\nReversed Linked list \n");
    printlinked_list(head);
}

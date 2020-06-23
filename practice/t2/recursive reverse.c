#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *fir,*ptr;
int r=0;
NODE* get_linked_list()
{
    int b;
    char c;
    scanf("%d",&b);
    c=getchar();
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->data=b;
    if (c=='\n')
        temp->next=NULL;
    else
        temp->next=get_linked_list();
    return temp;
}
NODE* reverse_linked_list(NODE* head)
{
    if(head->next==NULL)
    {
        fir=head;
        return head;
    }
    reverse_linked_list(head->next)->next=head;
    return head;
}
void print_linked_list(NODE* head)
{
    if (head==NULL)
        return;
    printf("%d ",head->data);
    print_linked_list(head->next);
}
main()
{
    printf("Enter the data of linked list");
    fir=get_linked_list();
    reverse_linked_list(fir)->next=NULL;
    print_linked_list(fir);
}

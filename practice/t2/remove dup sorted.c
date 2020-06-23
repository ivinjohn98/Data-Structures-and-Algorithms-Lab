#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *p=NULL,*q;
NODE* get_linked_list()
{
    int b;
    b=getchar();
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    if (b=='\n')
        return NULL;
    b=b-'0';
    temp->data=b;
    temp->next=get_linked_list();
    return temp;
}
NODE* remove_dup_sorted(NODE *p)
{
    if (p->next==NULL || p==NULL)
        return p;
    if ((p->next->data)==(p->data))
        return remove_dup_sorted(p->next);
    p->next=remove_dup_sorted(p->next);
    return p;
}
void print_linked_list(NODE* head)
{
    if (head==NULL)
        return;
    printf("%d",head->data);
    print_linked_list(head->next);
}
main()
{
    printf("Enter the data of linked list");
    p=get_linked_list();
    p=remove_dup_sorted(p);
    print_linked_list(p);
}

#include<stdio.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
typedef struct node NODE;
struct double_linked_list
{
    NODE *start,*end;
}dl;
NODE *ptr=NULL;
NODE* get_double_linked_list()
{
    int b;
    b=getchar();
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->prev=ptr;
    ptr=temp;
    if (b=='\n')
        return NULL;
    b=b-'0';
    temp->data=b;
    temp->next=get_double_linked_list();
    //if(temp->prev==NULL)
    //    ql->start=temp;
    if(temp->next==NULL)
        dl.end=temp;
    return temp;
}
void print_double_linked_list_end(NODE *temp)
{
    if (temp==NULL)
        return;
    printf("%d",temp->data);
    print_double_linked_list_end(temp->prev);
}
void print_double_linked_list_start(NODE *temp)
{
    if (temp==NULL)
        return;
    printf("%d",temp->data);
    print_double_linked_list_start(temp->next);
}
main()
{
    NODE *head;
    dl.start=get_double_linked_list();
    print_double_linked_list_end(dl.end);
    printf(" ");
    print_double_linked_list_start(dl.start);
}

#include<stdio.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE *fir,*sec,*thi,*last;
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
void divide()
{
    if (last->next==NULL)
        return;
    if ((r%3)>-1)
        last=last->next;
    if ((r%3)>0)
        thi=thi->next;
    if ((r%3)>1)
        sec=sec->next;
    if (last->next==NULL)
    {
        last=sec->next;
        sec->next=NULL;
        sec=last;
        last=thi->next;
        thi->next=NULL;
        thi=last;
        return;
    }
    r++;
    divide();
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
    last=thi=sec=fir;
    divide();
    print_linked_list(fir);
    printf("\n");
    print_linked_list(sec);
    printf("\n");
    print_linked_list(thi);
}

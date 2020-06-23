#include<stdio.h>
struct node
{
    int data;
    struct node *l;
    struct node *r;
};
typedef struct node NODE;
NODE *p=NULL,*q=NULL,*y=NULL;
NODE *pr=NULL;
NODE *pl=NULL;
NODE* get_linked_list()
{
    int b;
    b=getchar();
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    if (b==' ')
        return NULL;
    b=b-'0';
    temp->data=b;
    temp->l=get_linked_list();
    temp->r=get_linked_list();
    return temp;
}
NODE* mergesort(NODE* pl,NODE* pr)
{
    if (pr==NULL)
        return pl;
    if (pl==NULL)
        return pr;
    NODE *q;
    if (((pl->data)<(pr->data)))
    {
        q=pl;
        q->l=mergesort(pl->l,pr);
    }
    else
    {
        q=pr;
        q->l=mergesort(pl,pr->l);
    }
    return q;
}
NODE* sort(NODE* y)
{
    if((y==NULL)||(y->r==NULL))
        return y;
    return mergesort(y,sort(y->r));
}
void print_linked_list(NODE* head)
{
    if (head==NULL)
        return;
    printf("%d",head->data);
    print_linked_list(head->l);
    //print_linked_list(head->r);
}
main()
{
    printf("Enter the data of linked list");
    p=get_linked_list();
    y=sort(p);
    print_linked_list(y);
}

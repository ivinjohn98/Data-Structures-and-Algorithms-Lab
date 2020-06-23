#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int val;
    struct node *next;
};
typedef struct node NODE;
NODE* reverse(NODE *h)
{
    NODE *c=h;
    NODE *p=NULL;
    NODE *n;
    while(c!=NULL)
    {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    h=p;
    return h;
}
NODE* removezero(NODE *h)
{
    if (h->val==0)
        return removezero(h->next);
    else
        return h;
}
int greatest(NODE *n1,NODE *n2)
{
	if(n1==NULL)
		return 0;
	if((n1->val)>(n2->val))
		return 1;
	if((n1->val)<(n2->val))
		return 2;
	return greatest(n1->next,n2->next);
}
NODE* difference(NODE *n1,NODE *n2)
{
    if((n1)==NULL)
		return n2;
    (n1->val)=(n1->val)-(n2->val);
    if((n1->val)>=0)
        return difference(n1->next,n2->next);
    if((n1->val)<0)
    {
        (n1->val)+=10;
        (n1->next)->val-=1;
        return difference(n1->next,n2->next);
    }
}
void printing(NODE *head)
{
    NODE *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->val);
        temp=temp->next;
    }
}
NODE* get_list()
{
    NODE *h,*f=NULL,*t=NULL;
    int e;
    while(1)
    {
        h=(NODE*)malloc(sizeof(NODE));
        e=getchar();
        if (e=='\n')
            break;
        e=e-'0';
        h->val=e;
        if(f!=NULL)
        {
            t->next=h;
            t=h;
        }
        else
        {
            t=h;
            f=t;
        }
    }
    t->next=NULL;
    return f;
}
int main()
{
    NODE *num1,*num2,*res;
    int n1,n2;
    char s;
    printf("Given linked list\n");
    num1=get_list();
    num2=get_list();
    if(greatest(num1,num2)==1)
    {
        num1=reverse(num1);
        num2=reverse(num2);
        res=difference(num1,num2);
        num1=reverse(num1);
        num1=removezero(num1);
        printing(num1);
    }
    else if(greatest(num1,num2)==2)
    {
        num1=reverse(num1);
        num2=reverse(num2);
        res=difference(num2,num1);
        num2=reverse(num2);
        num2=removezero(num2);
        printing(num2);
    }
    else
    {
        printf("0");
        return;
    }
}

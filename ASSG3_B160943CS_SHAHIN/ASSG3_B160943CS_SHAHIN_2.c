#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE* removezero(NODE *head)
{
    if (head->data==0)
        return removezero(head->next);
    else
        return head;
}
int greatest(NODE *fir,NODE *sec)
{
	if(fir==NULL)
		return 0;
	if((fir->data)>(sec->data))
		return 1;
	if((fir->data)<(sec->data))
		return 2;
	return greatest(fir->next,sec->next);
}
NODE* difference_of_digits(NODE *fir,NODE *sec)
{
    if (fir->next==NULL)
    {
        (fir->data)-=(sec->data);
        return fir;
    }
    fir->next=difference_of_digits(fir->next,sec->next);
    fir->data-=sec->data;
    if ((fir->next->data)<0)
    {
        (fir->next->data)+=10;
        (fir->data)-=1;
    }
    return fir;
}
void printlinked_list(NODE *head)
{
    NODE *temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
}
NODE* getlinked_list()
{
    NODE *head,*first=NULL,*temp=NULL;
    int b;
    while(1)
    {
        head=(NODE*)malloc(sizeof(NODE));
        b=getchar();
        if (b=='\n')
            break;
        b=b-'0';
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
    }
    temp->next=NULL;
    return first;
}
int main()
{
    NODE *inp1,*inp2,*res;
    int n1,n2;
    char s;
    inp1=getlinked_list();
    inp2=getlinked_list();
    if(greatest(inp1,inp2)==1)
        res=difference_of_digits(inp1,inp2);
    else if(greatest(inp1,inp2)==2)
        res=difference_of_digits(inp2,inp1);
    else
    {
        printf("0");
        return;
    }
    res=removezero(res);
    printlinked_list(res);
}

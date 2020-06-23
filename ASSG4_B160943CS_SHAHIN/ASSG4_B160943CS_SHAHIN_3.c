#include<stdio.h>
#include<malloc.h>
int f0=0,f1=0,f2=0,f3=0,t=0;
struct node
{
    int data;
    int rank;
    struct node *parent;
};
typedef struct node NODE;
NODE *db[10001],*db1[10001],*db2[10001],*db3[10001];
NODE* createnode(int e,int count)
{
    NODE *temp;
    temp=(NODE*)malloc(sizeof(NODE));
    temp->parent=NULL;
    temp->data=e;
    temp->rank=0;
    if (count==0)
        db[e]=temp;
    else if (count==1)
        db1[e]=temp;
    else if (count==2)
        db2[e]=temp;
    else if (count==3)
        db3[e]=temp;
    return temp;
}
void makeset(int x)
{
    int count=0;
    NODE *p=NULL;
    while(count<4)
    {
        if (count==0)
            p=db[x];
        else if (count==1)
            p=db1[x];
        else if (count==2)
            p=db2[x];
        else if (count==3)
            p=db3[x];
        if (p!=NULL)
            printf("PRESENT\n");
        else
        {
            p=createnode(x,count);
            p->parent=p;
        }
        count++;
    }
    printf("%d\n",p->data);
}
NODE* find(NODE* p,int count)
{
    if (count==2)
        f2++;
    if (count==3)
        f3++;
    if ((p->parent)!=p)
        p->parent=find(p->parent,count);
    return p->parent;
}
NODE* find_set(int x,int count)
{
    NODE *p;
    if (count==0)
    {
        p=db[x];
        f0++;
    }
    else if (count==1)
    {
        p=db1[x];
        f1++;
    }
    else if (count==2)
    {
        p=db2[x];
        f2++;
    }
    else if (count==3)
    {
        p=db3[x];
        f3++;
    }
    if (p==NULL)
        return NULL;
    else
    {
        while((p->parent)!=p)
        {
            if (count==0)
                f0++;
            else if (count==1)
                f1++;
            if(count==2 || count==3)
            {
                p->parent=find(p->parent,count);
                return p->parent;
            }
            else
            {
                p=p->parent;
            }
        }
        return p;
    }
}
void findset(int x)
{
    int count=0;
    while(count<4)
    {
        NODE* p;
        p=find_set(x,count);
        if(p==NULL)
            printf("NOT FOUND\n");
        else
            printf("%d ",p->data);
        count++;
    }
    printf("\n");
}
void Union(int x,int y)
{
    int count=0;
    NODE *p,*q;
    while(count<4)
    {
        if (count==0)
        {
            p=db[x];
            q=db[y];
        }
        else if (count==1)
        {
            p=db1[x];
            q=db1[y];
        }
        else if (count==2)
        {
            p=db2[x];
            q=db2[y];
        }
        else if (count==3)
        {
            p=db3[x];
            q=db3[y];
        }
        if(p==NULL || q==NULL)
        {
            printf("ERROR");
            return;
        }
        p=find_set(x,count);
        q=find_set(y,count);
        if (count==1 || count==3)
        {
            if ((p->rank)>=(q->rank))
                q->parent=p;
            else
                p->parent=q;
            if (p->rank==q->rank)
                p->rank+=1;
            printf("%d ",p->parent->data);
        }
        if (count==0 || count==2)
        {
            if (p!=q)
            {
                q->parent=p;
                printf("%d ",p->data);
            }
            else
                printf("%d ",p->data);
        }
        count++;
    }
    printf("\n");
};
main()
{
    int num,num1;
    char choice;
    for(num=0;num<10001;num++)
        db[num]=NULL;
    for(num=0;num<10001;num++)
        db1[num]=NULL;
    for(num=0;num<10001;num++)
        db2[num]=NULL;
    for(num=0;num<10001;num++)
        db3[num]=NULL;
    while(1)
    {
        scanf("%c",&choice);
        switch(choice)
        {
            case 'm':
                {
                    scanf("%d",&num);
                    makeset(num);
                }
            break;
            case 'f':
                {
                    scanf("%d",&num);
                    findset(num);
                }
            break;
            case 'u':
                {
                    scanf("%d %d",&num,&num1);
                    Union(num,num1);
                }
            break;
            case 's':
                {
                    printf("%d %d %d %d",f0,f1,f2,f3);
                }
            return;
        }
    }
}

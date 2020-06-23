#include<stdio.h>
#include<malloc.h>
#include<limits.h>
int n,x,y=0;
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE **G;
struct edge
{
    int s,d,w;
};
typedef struct edge EDGE;
EDGE **E;
EDGE* createedge(int k,int m,int h)
{
    EDGE *p;
    p=(EDGE*)malloc(sizeof(EDGE));
    p->s=k;
    p->d=m;
    p->w=h;
    return p;
}
NODE* createnode(int k)
{
    NODE *p;
    p=(NODE*)malloc(sizeof(NODE));
    p->data=k;
    p->next=NULL;
    return p;
}
struct snode
{
    int data;
    int rank;
    struct snode *parent;
};
typedef struct snode SNODE;
SNODE **S;
SNODE* createsnode(int e)
{
    SNODE *temp;
    temp=(SNODE*)malloc(sizeof(SNODE));
    temp->parent=NULL;
    temp->data=e;
    temp->rank=0;
    S[e]=temp;
    return temp;
}
SNODE* makeset(int x)
{
    SNODE *p=NULL;
    p=S[x];
    p=createsnode(x);
    p->parent=p;
    return p;
}
SNODE* find(SNODE* p)
{
    if((p->parent)!=p)
    {
        p->parent=find(p->parent);
        return p->parent;
    }
    return p->parent;
}
SNODE* findset(int x)
{
    SNODE *p;
    p=S[x];
    if (p==NULL)
        return NULL;
    else
        return find(p);
}
void Union(int x,int y)
{
    SNODE *p,*q;
    p=S[x];
    q=S[y];
    p=findset(x);
    q=findset(y);
    if ((p->rank)>=(q->rank))
        q->parent=p;
    else
        p->parent=q;
    if (p->rank==q->rank)
        p->rank+=1;
}
void MST_kruskal()
{
    int i,j;
    for(i=0;i<n;i++)
        S[i]=makeset(i);
    for(i=0;i<x;i++)
    {
        for(j=i+1;j<x;j++)
        {
            if((E[i]->w)>(E[j]->w))
            {
                EDGE *p;
                p=E[i];
                E[i]=E[j];
                E[j]=p;
            }
        }
    }
    for(i=0;i<x;i++)
    {
        if(findset(E[i]->s)!=findset(E[i]->d))
        {
            y+=(E[i]->w);
            Union((E[i]->s),(E[i]->d));
        }
    }
}
main()
{
    char s;
    scanf("%d",&n);
    int num,u,b=0,j=1;
    s=getchar();
    G=malloc(n*sizeof(NODE*));
    for(u=0;u<n;u++)
        G[u]=NULL;
    u=0;
    x=0;
    while(u<n)
    {
        num=0;
        if(b==0)
        {
            s=getchar();
        }
        while(s!='\n')
        {
            if(b==1)
                s=getchar();
            if(s==' ' || s=='\n')
            {
                NODE *p;
                x++;
                p=G[u];
                if(G[u]==NULL)
                {
                    G[u]=createnode(num);
                }
                else
                {
                    while(p->next!=NULL)
                    {
                        p=p->next;
                    }
                    NODE *q=createnode(num);
                    p->next=q;
                }
                num=0;
                if(s=='\n')
                    break;
            }
            else
                num=num*10+s-'0';
            b=1;
        }
        u++;
        b=0;
    }
    E=malloc(x*sizeof(EDGE*));
    for(u=0;u<x;u++)
        E[u]=NULL;
    u=0;
    x=0;
    NODE *r=NULL;
    while(u<n)
    {
        num=0;
        if(b==0)
            s=getchar();
        while(s!='\n')
        {
            if(b==1)
                s=getchar();
            if(s=='-')
            {
                j=-1;
                continue;
            }
            if(s==' ' || s=='\n')
            {
                if(j==-1)
                    num=-num;
                if(r==NULL)
                    r=G[u];
                E[x]=createedge(u,r->data,num);
                x++;
                r=r->next;
                num=0;
                if(s=='\n')
                    break;
            }
            else
                num=num*10+s-'0';
            b=1;
        }
        j=1;
        u++;
        b=0;
    }
    S=malloc(n*sizeof(SNODE*));
    for(u=0;u<n;u++)
        S[u]=NULL;
    MST_kruskal();
    printf("%d\n",y);
}

#include<stdio.h>
#include<malloc.h>
#include<limits.h>
int n,m,x;
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
struct snode
{
    int data,key;
    struct snode *pi;
};
typedef struct snode SNODE;
SNODE **S;
SNODE* createsnode(int e)
{
    SNODE *temp;
    temp=(SNODE*)malloc(sizeof(SNODE));
    temp->pi=NULL;
    temp->data=e;
    temp->key=INT_MAX;
    S[e]=temp;
    return temp;
}
void RELAX(SNODE *u,SNODE *v,int w)
{
    if((u->key)==INT_MAX)
        return;
    if((v->key)>((u->key)+w))
    {
        (v->key)=(u->key) + w;
        (v->pi)=u;
    }
}
int BELLMAN_FORD()
{
    int i,j;
    for(i=0;i<n;i++)
        S[i]=createsnode(i);
    S[0]->key=0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            RELAX(S[E[j]->s],S[E[j]->d],E[j]->w);
    for(j=0;j<m;j++)
    {
        if((S[E[j]->d]->key)>((S[E[j]->s]->key)+(E[j]->w)))
            return 1;
    }
    return -1;
}
main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    int u,x,a,b,c;
    E=malloc(m*sizeof(EDGE*));
    for(u=0;u<x;u++)
        E[u]=NULL;
    u=0;
    while(u<m)
    {
        scanf("%d %d %d",&a,&b,&c);
        E[u]=createedge(a,b,c);
        u++;
    }
    S=malloc(n*sizeof(SNODE*));
    for(u=0;u<n;u++)
        S[u]=NULL;
    printf("%d\n",BELLMAN_FORD());
}

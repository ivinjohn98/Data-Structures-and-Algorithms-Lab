#include<stdio.h>
#include<malloc.h>
#include<limits.h>
int n,x;
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
struct qnode
{
    SNODE *sp;
    struct qnode *next;
};
typedef struct qnode QNODE;
struct queue
{
    QNODE *head,*tail;
}QUE;
void p_enqueue(SNODE *q)
{
    QNODE *p;
    p=(QNODE*)malloc(sizeof(QNODE));
    p->sp=q;
    p->next=NULL;
    if(QUE.head==NULL)
    {
        QUE.head=p;
        QUE.tail=p;
    }
    else
    {
        QNODE *r,*k;
        r=QUE.head;
        k=NULL;
        while((r)!=NULL)
        {
            if ((r->sp->key)<=(p->sp->key))
            {
                k=r;
                r=r->next;
            }
            else
                break;
        }
        if(k==NULL)
        {
            QUE.head=p;
            p->next=r;
        }
        else
        {
            k->next=p;
            p->next=r;
        }
        if(r==NULL)
        {
            QUE.tail=p;
        }

    }
}
void priority(SNODE *q)
{
    QNODE *r=NULL,*p=QUE.head;
    while((p->sp)!=q)
    {
        r=p;
        p=p->next;
    }
    if(r==NULL)
    {
        QUE.head=QUE.head->next;
        p->next=NULL;
    }
    else
    {
        r->next=r->next->next;
        p->next=NULL;
    }
    p_enqueue(p->sp);
}
SNODE* p_dequeue()
{
    QNODE *p;
    p=QUE.head;
    QUE.head=QUE.head->next;
    return p->sp;
}
int index(int k,int m)
{
    int i=0;
    while(1)
    {
        if((k==(E[i]->d))&&(m==(E[i]->s)))
            return i;
        i++;
    }
    return i;
}
void RELAX(SNODE *u,SNODE *v,int w)
{
    if((u->key)==INT_MAX)
        return;
    if((v->key)>((u->key)+w))
    {
        (v->key)=(u->key) + w;
        (v->pi)=u;
        priority(v);
    }
}
void DIJKSTRA(int sta,int des)
{
    int i;
    for(i=0;i<n;i++)
        S[i]=createsnode(i);
    S[sta]->key=0;
    QUE.head=NULL;
    QUE.tail=NULL;
    for(i=0;i<n;i++)
        p_enqueue(S[i]);
    while(QUE.head!=NULL)
    {
        SNODE *u;
        u=p_dequeue();
        if((u->data)==des)
        {
            if((u->key)==INT_MAX)
                printf("INF");
            else
                printf("%d",u->key);
        }
        NODE *h;
        h=G[u->data];
        while(h!=NULL)
        {
            SNODE *v;
            v=S[h->data];
            RELAX(u,v,(E[index(h->data,u->data)]->w));
            h=h->next;
        }
    }
}
main()
{
    char s,choice[5];
    scanf("%d",&n);
    int num,u,b=0;
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
            if(s==' ' || s=='\n')
            {
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
        u++;
        b=0;
    }
    S=malloc(n*sizeof(SNODE*));
    for(u=0;u<n;u++)
        S[u]=NULL;
    u=0;
    while(1)
    {
        scanf("%s",&choice);
        if(strcmp(choice,"stop")==0)
            return;
        else if(strcmp(choice,"apsp")==0)
        {
            scanf("%d",&num);
            for(u=0;u<n;u++)
            {
                DIJKSTRA(num,u);
                if((u+1)==n)
                    printf("\n");
                else
                    printf(" ");
            }
        }
        else if(strcmp(choice,"sssp")==0)
        {
            scanf("%d %d",&num,&u);
            DIJKSTRA(num,u);
            printf("\n");
        }
    }
}

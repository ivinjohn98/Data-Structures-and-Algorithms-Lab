#include<stdio.h>
#include<malloc.h>
#include<limits.h>
int n,time=0,flag=10;
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE **G;
struct dnode
{
    NODE *dp;
    int data;
    char color;
    int st;
    int ft;
    struct dnode *pi;
};
typedef struct dnode DNODE;
DNODE **Gd;
DNODE* creatednode(NODE *k,int r)
{
    DNODE *p;
    p=(DNODE*)malloc(sizeof(DNODE));
    p->dp=k;
    p->data=r;
    p->color='w';
    p->ft=INT_MAX;
    p->st=INT_MAX;
    p->pi=NULL;
    return p;
}
struct stnode
{
    DNODE *p;
    struct stnode *next;
};
typedef struct stnode STNODE;
STNODE *St=NULL;
void push(DNODE *q)
{
    STNODE *r,*f;
    r=(STNODE*)malloc(sizeof(STNODE));
    r->next=NULL;
    r->p=q;
    f=St;
    St=r;
    St->next=f;
}
DNODE* pop()
{
    STNODE *r,*f;
    r=St;
    if(St==NULL)
        return NULL;
    St=St->next;
    r->next=NULL;
    return r->p;
}
void dfs_visit(DNODE *u,int key)
{
    u->color='g';
    u->st=time;
    time++;
    DNODE *v;
    NODE *h;
    h=u->dp;
    v=u;
    while(h!=NULL)
    {
        v=Gd[h->data];
        push(v);
        h=h->next;
    }
    while(1)
    {
        v=pop();
        if(v==NULL)
            break;
        if(key==(v->data) && (v->color)!='b')
        {
            printf("%d\n",key);
            v->pi=u;
            v->ft=time;
            time++;
            v->color='b';
            flag=1;
            return;
        }
        if(v->color=='w')
        {
            v->pi=u;
            printf("%d ",v->data);
            dfs_visit(v,key);
            if (flag==1)
                return;
        }
    }
    u->ft=time;
    time++;
    u->color='b';
}
void dfs(int start,int key)
{
    int i=0;
    if (start==key)
    {
        printf("%d\n",start);
        return;
    }
    printf("%d ",start);
    for(i=0;i<n;i++)
        Gd[i]=creatednode(G[i],i);
    dfs_visit(Gd[start],key);
}
struct cnode
{
    NODE *np;
    char color;
    int d;
    struct cnode *pi;
};
typedef struct cnode CNODE;
CNODE **Gb;
struct qnode
{
    CNODE *cp;
    struct qnode *next;
};
typedef struct qnode QNODE;
struct Queue
{
    QNODE *head,*tail;
};
typedef struct Queue QUE;
QUE *createQueue()
{
    QUE *Q=(QUE*)malloc(sizeof(QUE));
    Q->head=Q->tail=NULL;
    return Q;
}
QNODE* newnode(CNODE *k)
{
    QNODE *temp=(QNODE*)malloc(sizeof(QNODE));
    temp->cp=k;
    temp->next=NULL;
    return temp;
}
void enqueue(QUE *Q,CNODE *k)
{
    QNODE *temp=newnode(k);
    if((Q->tail)==NULL)
    {
        Q->tail=temp;
        Q->head=temp;
    }
    else
    {
        Q->tail->next=temp;
        Q->tail=temp;
    }
}
CNODE* dequeue(QUE *Q)
{
    QNODE *temp;
    if(Q->head==NULL)
        return NULL;
    if(Q->head!=Q->tail)
    {
        temp=Q->head;
        Q->head=Q->head->next;
        temp->next=NULL;
    }
    else
    {
        temp=Q->head;
        Q->head=NULL;
        Q->tail=NULL;
    }
    return temp->cp;
}
NODE* createnode(int k)
{
    NODE *p;
    p=(NODE*)malloc(sizeof(NODE));
    p->data=k;
    p->next=NULL;
    return p;
}
CNODE* createcnode(NODE *k)
{
    CNODE *p;
    p=(CNODE*)malloc(sizeof(CNODE));
    p->np=k;
    p->color='w';
    p->d=INT_MAX;
    p->pi=NULL;
    return p;
}
void bfs(int start,int key)
{
    int i=0;
    if(start==key)
    {
        printf("%d",key);
        return;
    }
    printf("%d ",start);
    for(i=0;i<n;i++)
    {
        Gb[i]=createcnode(G[i]);
        if (i==start)
        {
            Gb[i]->color='g';
            Gb[i]->d=0;
        }
    }
    CNODE *s=Gb[start];
    QUE *Q;
    Q=createQueue();
    enqueue(Q,s);
    while(Q!=NULL)
    {
        CNODE *u,*v;
        u=dequeue(Q);
        if(u==NULL)
        {
            printf("\n");
            return;
        }
        NODE *h;
        h=u->np;
        v=u;
        while(h!=NULL)
        {
            v=Gb[h->data];
            if(key==(h->data) && (v->color)!='b')
            {
                printf("%d\n",key);
                v->color='b';
                v->pi=u;
                return;
            }
            if(v->color=='w')
            {
                v->color='g';
                v->d=(u->d)+1;
                v->pi=u;
                enqueue(Q,v);
                printf("%d ",h->data);
            }
            h=h->next;
        }
        u->color='b';
    }
}
main()
{
    char choice[4],s;
    int b=0;
    scanf("%d",&n);
    s=getchar();
    int num,u,i;
    G=malloc(n*sizeof(NODE*));
    for(u=0;u<n;u++)
        G[u]=NULL;
    u=0;
    while(u<n)
    {
        num=0;
        i=0;
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
            i++;
            b=1;
        }
        u++;
        b=0;
    }
    u=0;
    while(1)
    {
        scanf("%s",&choice);
        if(strcmp(choice,"stp")==0)
            return;
        else if(strcmp(choice,"bfs")==0)
        {
            scanf("%d %d",&num,&u);
            Gb=malloc(n*sizeof(CNODE*));
            for(i=0;i<n;i++)
                Gb[i]=NULL;
            bfs(num,u);
        }
        else if(strcmp(choice,"dfs")==0)
        {
            scanf("%d %d",&num,&u);
            Gd=malloc(n*sizeof(DNODE*));
            for(i=0;i<n;i++)
                Gd[i]=NULL;
            dfs(num,u);
        }
    }
}

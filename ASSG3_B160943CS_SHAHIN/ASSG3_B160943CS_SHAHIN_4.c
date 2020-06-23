#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
long long int heap_size=0;
int parent(int i)
{
        return (i-1)/2;
}
int leftchild(int i)
{
        return 2*i+1;
}
int rightchild(int i)
{
        return 2*i+2;
}
struct priority_Queue
{
    long long int data;
    long long int priority;
};
typedef struct priority_Queue PQ;
void min_Heapify(PQ *pq,long long int i)
{
    long long int large=i;
    if ((pq[i].priority>pq[leftchild(i)].priority)&&(leftchild(i)<heap_size))
        large=leftchild(i);
    if ((pq[large].priority>pq[rightchild(i)].priority)&&(rightchild(i)<heap_size))
        large=rightchild(i);
    if(large!=i)
    {
        PQ temp;
        temp=pq[large];
        pq[large]=pq[i];
        pq[i]=temp;
        min_Heapify(pq,large);
    }
}
PQ* insert(PQ *pq,long long int elem,long long int pr)
{
    if(pq==NULL)
        pq=(PQ*)malloc(sizeof(PQ));
    else
        pq=(PQ*)realloc(pq,(heap_size+1)*sizeof(PQ));
    pq[heap_size].data=elem;
    pq[heap_size].priority=pr;
    long long int j=heap_size;
    while((j>0) && ((pq[parent(j)].priority)>(pq[j].priority)))
    {
        PQ temp;
        temp=pq[parent(j)];
        pq[parent(j)]=pq[j];
        pq[j]=temp;
        j=parent(j);
    }
    heap_size++;
    return pq;
}
PQ* extract_min(PQ *pq)
{
    if (heap_size==0)
    {
        printf("EMPTY");
        return pq;
    }
    printf("%lld(%lld)",pq[0].data,pq[0].priority);
    PQ x;
    x=pq[0];
    pq[0]=pq[heap_size-1];
    heap_size-=1;
    min_Heapify(pq,0);
    pq=(PQ*)realloc(pq,(heap_size)*sizeof(PQ));
    return pq;
}
void get_min(PQ *pq)
{
    if (heap_size==0)
        printf("EMPTY");
    else
        printf("%lld(%lld)",pq[0].data,pq[0].priority);
}
void decrease_priority(PQ *pq,int elem,int newpr)
{
    long long int i=0;
    while((pq[i].data)!=elem && i<heap_size)
        i++;
    if (pq[i].priority>newpr)
    {
        pq[i].priority=newpr;
        while(i>0 && (pq[parent(i)].priority)>pq[i].priority)
        {
            PQ temp;
            temp=pq[parent(i)];
            pq[parent(i)]=pq[i];
            pq[i]=temp;
            i=parent(i);
        }
    }
}
main()
{
    char choice;
    long long int elem,pr,newpr;
    PQ *pq=NULL;
    while(1)
    {
        scanf("%c",&choice);
        switch(choice)
        {
            case 'a':
            {
                scanf("%lld %lld",&elem,&pr);
                pq=insert(pq,elem,pr);
            }
            break;
            case 'e':
            pq=extract_min(pq);
            break;
            case 'g':
            get_min(pq);
            break;
            case 'd':
            {
                scanf("%lld %lld",&elem,&newpr);
                decrease_priority(pq,elem,newpr);
            }
            break;
            case 's':
            return;
        }
    }
}

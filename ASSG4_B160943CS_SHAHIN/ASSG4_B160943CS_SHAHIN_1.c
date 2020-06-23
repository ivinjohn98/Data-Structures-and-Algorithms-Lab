#include<stdio.h>
long long int m,*p,R;
char c;
struct node
{
    int data;
    struct node *next;
};
typedef struct node NODE;
NODE **chain,*temp,*b;
int hi(long int k,long long int i)
{
    if (c=='c')
        return k%m;
    if (c=='l')
        return (k%m+i)%m;
    if (c=='q')
        return (k%m+i*i)%m;
    if (c=='d')
    {
        int x,y,flag;
        for(x=(m-1);x>0;x--)
        {
            y=2;
            flag=0;
            while(y<x)
            {
                if (x%y==0)
                {
                    flag=1;
                    break;
                }
                else
                    y++;
            }
            if (flag==0)
            {
                R=x;
                break;
            }
        }
        return ((k%m)+i*(R-(k%R)))%m;
    }
}
void insert(int k)
{
    int i=0;
    if(c!='c')
    {
        while(i<m)
        {
            if(p[hi(k,i)]==0)
            {
                p[hi(k,i)]=k;
                break;
            }
            else
                i++;
        }
    }
    else
    {
        temp=(NODE*)malloc(sizeof(NODE));
        temp->data=k;
        temp->next=NULL;
        if (chain[hi(k,0)]==NULL)
        {
            chain[hi(k,0)]=temp;
            temp->next=NULL;
        }
        else
        {
            b=chain[hi(k,0)];
            while((b->next)!=NULL)
                b=b->next;
            b->next=temp;
        }
    }
}
void search(int k)
{
    int i=0;
    if(c!='c')
    {
        while(i<m)
        {
            if(p[hi(k,i)]==k)
            {
                printf("1\n");
                return;
            }
            else
                i++;
        }
        printf("-1\n");
    }
    else
    {
        b=chain[hi(k,0)];
        while(b!=NULL)
        {
            if ((b->data)==k)
                break;
            else
                b=b->next;
        }
        if(b==NULL)
            printf("-1\n");
        else
            printf("1\n");
    }
}
void delete(int k)
{
    int i=0;
    if(c!='c')
    {
        while(i<m)
        {
            if(p[hi(k,i)]==k)
            {
                p[hi(k,i)]=0;
                return;
            }
            else
                i++;
        }
    }
    else
    {
        b=chain[hi(k,0)];
        if((b->data)==k)
            chain[hi(k,0)]=b->next;
        while((b->next->data)!=k)
            b=b->next;
        b->next=b->next->next;
    }

}
void print()
{
    int i=0;
    if(c!='c')
    {
        while(i<m)
        {
            if(p[i]!=0)
                printf("%d(%d)\n",i,p[i]);
            else
                printf("%d()\n",i);
            i++;
        }
    }
    else
    {
        for(i=0;i<m;i++)
        {
            b=chain[i];
            printf("%d (",i);
            while(b!=NULL)
            {
                printf("%d ",b->data);
                b=b->next;
            }
            printf(")\n");
        }
    }

}
void hash_table(int m)
{
    int i;
    if (c!='c')
    {
        p=(long long int*)malloc(m*sizeof(long long int));
        for(i=0;i<m;i++)
            p[i]=0;
    }
    else
    {
        chain=malloc(m*sizeof(NODE*));
        for(i=0;i<m;i++)
            chain[i]=NULL;
    }
}
main()
{
    char choice,inchoice;
    int num;
    while(1)
    {
        scanf("%c",&choice);
        switch(choice)
        {
            case 'a':
            c='l';
            break;
            case 'b':
            c='q';
            break;
            case 'c':
            c='d';
            break;
            case 'd':
            c='c';
            break;
        }
        scanf("%d",&m);
        hash_table(m);
        while(1)
        {
            scanf("%c",&inchoice);
            switch(inchoice)
            {
                case 'i':
                {
                    scanf("%d",&num);
                    insert(num);
                }
                break;
                case 's':
                {
                    scanf("%d",&num);
                    search(num);
                }
                break;
                case 'd':
                {
                    scanf("%d",&num);
                    delete(num);
                }
                break;
                case 'p':
                    print();
                    break;
                case 't':
                return;
            }
        }

    }
}

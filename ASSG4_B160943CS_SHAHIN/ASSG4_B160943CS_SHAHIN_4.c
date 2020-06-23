#include<stdio.h>
#include<malloc.h>
int n,*pr,*in,i;
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
NODE *root=NULL,*p=NULL,*temp;
NODE* createnode(int key)
{
    temp=(NODE*)malloc(sizeof(NODE));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=key;
    return temp;
}
int index(int x)
{
    int f;
    for(f=0;f<n;f++)
    {
        if(in[f]==x)
            return f;
    }
}
NODE* create_tree(int l,int h)
{
    NODE* p;
    if(h<l)
        return NULL;
    else
    {
        int k;
        k=pr[i];
        p=createnode(k);
        i++;
        p->left=create_tree(l,(index(k)-1));
        p->right=create_tree((index(k)+1),h);
        return p;
    }
}
void print_scheme(NODE* p)
{
    if (p==NULL)
        printf("()");
    else
    {
        printf("(%d",p->data);
        print_scheme(p->left);
        print_scheme(p->right);
        printf(")");
    }
}
main()
{
    char y;
    scanf("%d",&n);
    pr=(int*)malloc(n*sizeof(int));
    in=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",(pr+i));
    for(i=0;i<n;i++)
        scanf("%d",(in+i));
    i=0;
    root=create_tree(0,n-1);
    printf("\n");
    print_scheme(root);
}

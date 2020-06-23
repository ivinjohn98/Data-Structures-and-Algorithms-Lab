#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node NODE;
NODE *root=NULL,*p,*q,*temp,*r,*x;
NODE* createnode(int k)
{
    temp=(NODE*)malloc(sizeof(NODE));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=k;
    return temp;
}
void findMin(NODE* root)
{
    p=root;
    while(p!=NULL)
    {
        if((p->left)==NULL)
        {
            printf("%d\n",p->data);
            return;
        }
        else
            p=p->left;
    }
    printf("NIL\n");
}
void findMax(NODE* root)
{
    p=root;
    while(p!=NULL)
    {
        if((p->right)==NULL)
        {
            printf("%d\n",p->data);
            return;
        }
        else
            p=p->right;
    }
    printf("NIL\n");
}
void inorder(NODE* p)
{
    if (p!=NULL)
    {
        inorder(p->left);
        printf("%d ",p->data);
        inorder(p->right);
    }
}
void postorder(NODE* p)
{
    if (p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("%d ",p->data);
    }
}
void preorder(NODE* p)
{
    if (p!=NULL)
    {
        printf("%d ",p->data);
        preorder(p->left);
        preorder(p->right);
    }
}
void search(NODE* root,int k)
{
    p=root;
    while(p!=NULL)
    {
        if((p->data)==k)
        {
            printf("FOUND\n");
            return;
        }
        if((p->data)<k)
            p=p->right;
        else
            p=p->left;
    }
    printf("NOT FOUND\n");
}
void predecessor(NODE* root,int k)
{
    if(root==NULL)
    {
        printf("NOT FOUND\n");
        return;
    }
    if((root->data)==k)
    {
        if((root->left)==NULL)
        {
            printf("NIL\n");
            return;
        }
        else
        {
            findMax(root->left);
            return;
        }
    }
    else
    {
        p=root;
        q=NULL;
        while(p!=NULL)
        {
            if((p->data)==k)
            {
                if((p->left)==NULL)
                {
                    if(q==NULL)
                        printf("NIL\n");
                    else
                        printf("%d\n",q->data);
                    return;
                }
                else
                {
                    findMax(p->left);
                    return;
                }
            }
            if((p->data)<k)
            {
                q=p;
                p=p->right;
            }
            else
                p=p->left;
        }
    }
    printf("NOT FOUND\n");
}
void successor(NODE* root,int k)
{
    if(root==NULL)
    {
        printf("NOT FOUND\n");
        return;
    }
    if((root->data)==k)
    {
        if((root->right)==NULL)
        {
            printf("NIL\n");
            return;
        }
        else
        {
            findMin(root->right);
            return;
        }
    }
    else
    {
        p=root;
        q=NULL;
        while(p!=NULL)
        {
            if((p->data)==k)
            {
                if((p->right)==NULL)
                {
                    if(q==NULL)
                        printf("NIL\n");
                    else
                        printf("%d\n",q->data);
                    return;
                }
                else
                {
                    findMin(p->right);
                    return;
                }
            }
            if((p->data)<k)
                p=p->right;
            else
            {
                q=p;
                p=p->left;
            }
        }
    }
    printf("NOT FOUND\n");
}
NODE* insert(NODE* root,int k)
{
    p=root;
    if (root==NULL)
    {
        root=createnode(k);
        return root;
    }
    while(1)
    {
        if((p->data)<k)
        {
            if ((p->right)==NULL)
            {
                p->right=createnode(k);
                return root;
            }
            else
                p=p->right;
        }
        else
        {
            if ((p->left)==NULL)
            {
                p->left=createnode(k);
                return root;
            }
            else
                p=p->left;
        }
    }
}
NODE* bst_delete(NODE* r,NODE* p)
{
    if (r==p)
    {
        if ((r->right)==NULL)
        {
            q=r->left;
            r->left=NULL;
            return q;
        }
        else if ((r->left)==NULL)
        {
            q=r->right;
            r->right=NULL;
            return q;
        }
        else
        {
            q=r->right;
            if((q->left)==NULL)
            {
                x=r->left;
                r->left=NULL;
                q->left=x;
                return q;
            }
            else
            {
                x=q->left;
                while((x->left)!=NULL)
                {
                    q=x;
                    x=x->left;
                }
                x->left=r->left;
                r->left=NULL;
                x=r->right;
                r->right=NULL;
                return x;
            }
        }
    }
    else
    {
        if((r->data)<(p->data))
        {
            r->right=bst_delete(r->right,p);
            return r;
        }
        else
        {
            r->left=bst_delete(r->left,p);
            return r;
        }

    }
}
NODE* delete(NODE* root,int k)
{
    p=root;
    while(p!=NULL)
    {
        if((p->data)==k)
            break;
        if((p->data)<k)
            p=p->right;
        else
            p=p->left;
    }
    if(p!=NULL)
        return bst_delete(root,p);
    else
        return root;
}
main()
{
    char a[5];
    int num;
    while(1)
    {
        scanf("%s",&a);
        if(strcmp(a,"stop")==0)
            return;
        else if(strcmp(a,"insr")==0)
        {
            scanf("%d",&num);
            root=insert(root,num);
        }
        else if(strcmp(a,"srch")==0)
        {
            scanf("%d",&num);
            search(root,num);
        }
        else if(strcmp(a,"minm")==0)
            findMin(root);
        else if(strcmp(a,"maxm")==0)
            findMax(root);
        else if(strcmp(a,"pred")==0)
        {
            scanf("%d",&num);
            predecessor(root,num);
        }
        else if(strcmp(a,"succ")==0)
        {
            scanf("%d",&num);
            successor(root,num);
        }
        else if(strcmp(a,"delt")==0)
        {
            scanf("%d",&num);
            root=delete(root,num);
        }
        else if(strcmp(a,"inor")==0)
            inorder(root);
        else if(strcmp(a,"prer")==0)
            preorder(root);
        else if(strcmp(a,"post")==0)
            postorder(root);
    }
}

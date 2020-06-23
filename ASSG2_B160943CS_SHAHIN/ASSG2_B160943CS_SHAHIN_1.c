#include<stdio.h>
#include<malloc.h>
#include<limits.h>
typedef long int dtype;
void merge(int* a,int p,int q,int r,int s)
{
    int b[30],d[30],c[30],i,j,k,m;
    if(s==(p+1))
        r=s;
    for(i=p;i<q;i++)
        b[i-p]=a[i];
    b[i]=INT_MAX;
    for(i=q;i<r;i++)
        c[i-q]=a[i];
    c[i-q]=INT_MAX;
    for(i=r;i<s;i++)
        d[i-r]=a[i];
    d[i-r]=INT_MAX;
    i=0;
    j=0;
    k=0;
    for (m=p;m<s;m++)
    {
        if ((b[i]<c[j])&&(b[i]<d[k]))
        {
            a[m]=b[i];
            i++;
        }
        else if((c[j]<b[i])&&(c[j]<d[k]))
        {
            a[m]=c[j];
            j++;
        }
        else
        {
            a[m]=d[k];
            k++;
        }
    }
}
void mergesort(int *a,int p,int q)
{
    int r;
    if (p<(q-3))
    {
        r=(q-p)/3;
        mergesort(a,p,r+p);
        mergesort(a,r+p,p+2*r);
        mergesort(a,p+2*r,q);
        merge(a,p,r+p,p+2*r,q);
    }
    else
    {
        merge(a,p,p+1,p+2,q);
    }
}
main()
{
    int *a,n,i;
    printf("Enter the size of the string");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    mergesort(a,0,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

#include<stdio.h>
#include<limits.h>
void merge(int *a,int p,int r,int q)
{
    int b[30],c[30],j=0,k=0,i;
    for(i=p;i<=r;i++)
        b[i-p]=a[i];
    b[i-p]=INT_MAX;
    for(i=(r+1);i<=q;i++)
        c[i-(r+1)]=a[i];
    c[i-(r+1)]=INT_MAX;
    for(i=p;i<=q;i++)
    {
        if(b[k]>c[j])
        {
            a[i]=c[j];
            j++;
        }
        else
        {
            a[i]=b[k];
            k++;
        }
    }
}
void mergesort(int *a,int p,int q)
{
    int r=(q-p)/2;
    if (p<q)
    {
        mergesort(a,p,p+r);
        mergesort(a,p+r+1,q);
        merge(a,p,p+r,q);
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
    mergesort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}

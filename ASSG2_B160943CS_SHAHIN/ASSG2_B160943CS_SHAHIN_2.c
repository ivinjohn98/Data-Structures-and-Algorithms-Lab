#include<stdio.h>
int median(int* a,low,high)
void Quicksort(int* a,int p,int r)
{
    int q,i;
    if(p<r)
    {
        q=Partition(a,p,r);
        Quicksort(a,p,q-1);
        Quicksort(a,q+1,r);
        printf("%d\n",a[q]);
        for(i=p;i<=r;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
}
int Partition(int* a,int low,int high)
{
    int pivot,i,j,m,k;
    median(a,low,high)
    m=(high+low+1);
    if((m%2)==0)
        m=(m/2)-1;
    else
        m=m/2;
    pivot=a[m];
    i=low-1;
    for (j=low;j<=high;j++)
    {
        if (a[j] < pivot)
        {
            i++;
            if(i==m)
                m=j;
            if(a[i]!=a[j])
            {
                a[i]+=a[j];
                a[j]=a[i]-a[j];
                a[i]-=a[j];
            }
        }
    }
    i++;
    if(a[m]!=a[i])
    {
        a[i]=a[i]+a[m];
        a[m]=a[i]-a[m];
        a[i]=a[i]-a[m];
    }
    return i;
}
main()
{
    int n,*a,i;
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    for (i=0;i<n;i++)
        scanf("%d",&a[i]);
    Quicksort(a,0,n-1);
    for (i=0;i<n;i++)
        printf("%d ",a[i]);
}

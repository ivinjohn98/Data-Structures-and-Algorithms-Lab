#include<stdio.h>
#include<string.h>
void swap(int *p, int *q)
{
   int temp;
   temp = *p;
   *p = *q;
   *q = temp;
}
int partition(int *a,int p,int r)
{
    int x=a[r],i,j=p;
    for(i=p;i<r;i++)
    {
        if (a[i]<x)
            j++;
        else
            swap((a+i),(a+j));
    }
    swap((a+r),(a+j));
    return j;
}
void quicksort(int *a,int p,int r)
{
    if (p<r)
    {
        int q=partition(a,p,r);
        quicksort(a,p,q-1);
        quicksort(a,q+1,r);
    }

}
main()
{
    int *a,n,i;
    printf("Enter the length of the string");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    quicksort(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

#include<stdio.h>
#include<limits.h>
#include<string.h>
void swap(int *p, int *q)
{
   int temp;
   temp = *p;
   *p = *q;
   *q = temp;
}
void heapify(int *a,int i,int n)
{
    int large=i;
    if ((a[i-1]<a[2*i-1])&&((2*i-1)<n))
        large=2*i;
    if ((a[large-1]<a[2*i])&&((2*i)<n))
        large=2*i+1;
    if(large!=i)
    {
        swap((a+large-1),(a+i-1));
        heapify(a,large,n);
    }
}
void buildmaxheap(int *a,int n)
{
    int i;
    for(i=(n/2);i>0;i--)
        heapify(a,i,n);
}
void heapsort(int *a,int n)
{
    int i;
    buildmaxheap(a,n);
    for(i=n;i>0;i--)
    {
        swap((a+i-1),a);
        n=n-1;
        heapify(a,1,n);
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
    heapsort(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}

#include<stdio.h>
#include<stdlib.h>
int heapify(int *a,int n,int i)
{
	int large,l,r;
	large=i;
	l=2*i+1;
	r=2*i+2;
	if((l<n)&&(a[large]<a[l]))
		large=l;
	if((r<n)&&(a[large]<a[r]))
		large=r;
	if(large!=i)
	{
		*(a+i)+=*(a+large);
		*(a+large)=*(a+i)-*(a+large);
		*(a+i)-=*(a+large);
		heapify(a,n,large);
	}
}
int heapsort(int *a,int n,int k)
{
    int c,i;
    c=0;
	for(i=(n/2)-1;i>=0;--i)
		heapify(a,n,i);
	for(i=n-1;i>=0;--i)
	{	c++;
		if(c==k)
		{
			printf("%d",a[0]);
			return 0;
		}
		*(a+0)+=*(a+i);
		*(a+i)=*(a+0)-*(a+i);
		*(a+0)-=*(a+i);
		heapify(a,i,0);
	}
}
void main()
{
	int n,k,i;
	scanf("%d",&n);
    int *a;
    a=(int *)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
    scanf("%d",(a+i));
        scanf("%d",&k);
    heapsort(a,n,k);
}



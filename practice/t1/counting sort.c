#include<stdio.h>
void countingsort(int *a,int n)
{
    int c[30],i,*b;
    b=(int*)malloc(n*sizeof(int));
    for(i=0;i<30;i++)
        c[i]=0;
    for(i=0;i<n;i++)
        c[a[i]]=c[a[i]]+1;
    for(i=1;i<30;i++)
        c[i]+=c[i-1];
    for(i=0;i<n;i++)
    {
        b[c[a[i]]]=a[i];
        c[a[i]]-=1;
    }
    for(i=1;i<=n;i++)
        printf("%d ",b[i]);
}
main()
{
    int *a,n,i;
    printf("Enter the size of the string");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    countingsort(a,n);
}

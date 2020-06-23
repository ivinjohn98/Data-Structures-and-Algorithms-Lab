#include<stdio.h>
int binary(int *a,int num,int l,int h)
{
    int mid=((h-l)/2)+l;
    if (l>h)
        return -1;
    if (num==a[mid])
        return mid;
    if (num<a[mid])
        return binary(a,num,l,mid-1);
    if (num>a[mid])
        return binary(a,num,mid+1,h);
}
main()
{
    int *a,i,n,num;
    printf("Enter the size of the array");
    scanf("%d",&n);
    printf("Enter the element to be found");
    scanf("%d",&num);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    i=binary(a,num,0,n-1);
    printf("%d",i);
}

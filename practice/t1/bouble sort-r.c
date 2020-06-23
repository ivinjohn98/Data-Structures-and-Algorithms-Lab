#include<stdio.h>
#include<string.h>
void Swap(int *p, int *q)
{
   int temp;
   temp = *p;
   *p = *q;
   *q = temp;
}
void bouble(int *a,int i,int n)
{
    if (n<1)
        return;
    if (i>(n-1))
    {
        n=n-1;
        i=0;
        bouble(a,i,n);

    }
    else
    {
        if (a[i]>a[i+1])
            Swap((a+i),(a+i+1));
        i++;
        bouble(a,i,n);
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
    bouble(a,0,n-1);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

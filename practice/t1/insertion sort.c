#include<stdio.h>
#include<string.h>
void insertion(int *a,int n)
{
    int j,i,k;
    for(i=1;i<n;i++)
    {
        k=a[i];
        j=i-1;
        while((a[j]>k)&&(j>=0))
        {
            a[j+1]=a[j];
            j=j-1;
        }
        a[j+1]=k;
    }
}
main()
{
    int *a,i,n;
    printf("Enter the size of the array");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    insertion(a,n);
    for(i=0;i<n;i++)
        printf("%d ",a[i]);

}

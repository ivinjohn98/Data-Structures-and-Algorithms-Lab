#include<stdio.h>
main()
{
    int *a,n,m,k,i,j;
    scanf("%d",&m);
    scanf("%d",&n);
    a=(int*)malloc(n*m*sizeof(int));
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            scanf("%d",(a+i*n+j));
    scanf("%d",&k);
    i=0;
    j=n-1;
    while((*(a+i*n+j)!=k)&&(i<m)&&(j<n))
    {
        if (*(a+i*n+j)<k)
            i++;
        else
            j--;
    }
    if (*(a+i*n+j)==k)
        printf("1");
    else
        printf("-1");
    free(a);
}

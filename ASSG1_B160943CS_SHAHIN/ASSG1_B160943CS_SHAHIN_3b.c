#include<stdio.h>
void tran(int *a,int n,int i,int j)
{
    *(a + i*n + j)=*(a + i*n + j)+*(a + j*n + i);
    *(a + j*n + i)=*(a + i*n + j)-*(a + j*n + i);
    *(a + i*n + j)=*(a + i*n + j)-*(a + j*n + i);
    if (i>(j+1))
        tran(a,n,i,++j);
    else if((i+1)<n)
        tran(a,n,++i,0);
    else
        return 0;
}
main()
{
    int *a,i,n,m,h,j,k=0,l=0;
    scanf("%d",&n);
    *a = (int *)malloc(n * n * sizeof(int));
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",(a + i*n + j));
    tran(a,n,1,0);
    m=n;
    h=n;
    while (k < m && l < n)
    {
        for(i=l;i<n;++i)
            printf("%d ", *(a + k*h + i));
        k++;
        for (i = k; i < m; ++i)
            printf("%d ", *(a + i*h + n-1));
        n--;
        if(k<m)
        {
            for(i=n-1;i>=l;--i)
                printf("%d ", *(a + (m-1)*h + i));
            m--;
        }
        if(l<n)
        {
            for(i=m-1;i>=k;--i)
                printf("%d ", *(a + i*h + l));
            l++;
        }
    }
    free(a);
}

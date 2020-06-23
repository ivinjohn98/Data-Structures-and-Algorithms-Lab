#include <stdio.h>
int binSearch(int* a,int l,int h,int k)
{
    int m;
    if (h<l)
        return -1;
    m=(l+h)/2;
    if (k==a[m])
        return m;
    if (k>a[m])
        return binSearch(a,(m+1),h,k);
    return binSearch(a,l,(m-1),k);
}
int findp(int* a,int l,int h)
{
    int m;
    if (h==l)
        return l;
    if (h<l)
        return -1;
    m=(l+h)/2;
    if ((m<h)&&(a[m]>a[m+1]))
        return m;
    if ((m>l)&&(a[m]<a[m-1]))
        return (m-1);
    if (a[l]>=a[m])
        return findp(a,l,m-1);
    return findp(a,m+1,h);
}
int Search(int* a,int n,int k)
{
    int p;
    p=findp(a,0,n-1);
    if (p==-1)
        return binSearch(a,0,n-1,k);
    if (a[p]==k)
        return p;
    if (a[0]<=k)
        return binSearch(a,0,p-1,k);
    return binSearch(a,p+1,n-1,k);
}
int main()
{
    int *a,n,i,k;
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",(a+i));
    scanf("%d",&k);
    printf("%d",Search(a,n,k));
    return 0;
}
